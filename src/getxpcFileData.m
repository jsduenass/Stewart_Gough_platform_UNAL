function getxpcFileData(ModelName,OutFilePath,Description)
% getxpcFileData - Retrieve file scope data from target PC
% -------------------------------------------------------------------------
% Abstract: This function retrieves the data from xPC file scopes.  It
% searches the specified model for any xPC Target scopes of type 'file' and
% looks for the target filename specified in each of these scopes.  It
% collects the data on the target PC file system, and saves it on the host
% PC in a .mat file format.  In the .mat file, each target scope will be
% stored in a structure called 'xpcdataN', where N is the scope number.
% Each signal is stored as a field of the structure by its signal name, for
% example 'xpcdata1.signal_name_1'.
%
% Syntax:
%       getxpcFileData;
%       getxpcFileData('ModelName');
%       getxpcFileData('ModelName','OutFilePath','Description');
%
% Inputs:
%           ModelName - name of the Simulink model
%           OutFilePath - output file path
%           Description - description of this data set
%
% Outputs:
%           none
%
% Examples:
%       getxpcFileData('test_model');
%
%       load DataFileName.mat % to load the mat file (or click the link)
%
%       xpcdata1  %to show what is in the structure for this scope
%
%       f = fields(xpcdata1) %to return the field names in this structure
%
%       xpcdata1.signal_name %to return the raw data of a signal
%
%       plot(xpcdata1.time,xpcdata1.signal_name) %to plot a signal
%
% Notes:
%   - You can optionally specify the output file path and description at
%     the command line.  If you do not, a dialog will ask for this info.
%   - Vector signals are not fully supported. If an xPC scope is recording
%     a vector signal, the names and data retrieved will not match correctly.
%   - Signal names will be modified to ensure they are valid MATLAB variable
%     names.
%   - This function assumes you are using the object named 'tg' for the
%     target PC object, and that it exists in the base workspace.  If it
%     does not exist, this function will attempt to search the file system
%     on the default target PC that your host PC is configured to use.
%
% Copyright 2007 - 2009 The MathWorks, Inc.
%
% Auth/Revision:
%   The MathWorks Consulting Group
%   $Author: rjackey $
%   $Revision: 10 $  $Date: 2007-07-26 15:56:29 -0400 (Thu, 26 Jul 2007) $
% -------------------------------------------------------------------------
% Check input arguments

if nargin < 1
    ModelName = bdroot;
    
elseif nargin == 1
    % Prompt the user for the output file name and description
    % Default save file name
    DefaultName = ['xPC_Data_' datestr(now, 'yyyymmdd_HHMMSS') '.mat'];
    % Bring up a dialog asking where to save the file
    [OutFileName,OutPath] = uiputfile('*.mat','Save Target File Scope Data to Host',DefaultName);
    % If the user cancelled, just return
    if isequal(OutFileName,0)
        return;
    end
    % Put together the full path to the output file
    OutFilePath = fullfile(OutPath,OutFileName);
    % Bring up a dialog to get the description
    Answer = inputdlg('Enter a description for all xPC file scope data:',...
        'Description',1,{''},'on');
    if isempty(Answer)
        Description = '';
    else
        Description = Answer{1};
    end
elseif nargin == 3
    
    % Clean up the filename and path info
    [OutPath,OutFileName,OutFileExt] = fileparts(OutFilePath);
    if isempty(OutPath)
        OutPath = pwd;
        OutFilePath = fullfile(OutPath,[OutFileName OutFileExt]);
    end
    
else
    error('Improper input arguments');
end
%% Get info on all file scopes in the model
% Get handles to all xPC file scope blocks
hFileScopes = find_system(ModelName,'LookUnderMasks','all',...
    'FollowLinks','on','MaskType','xpcscopeblock','scopetype','File');
% Get the file name that each scope writes to
ScopeFileNames = get_param(hFileScopes,'filename');
% Get the scope numbers
ScopeNumbers = get_param(hFileScopes,'scopeno');

%ScopeId=tg.Scopes;


% Make a list of variable names (e.g. 'xpcdata1','xpcdata4', where '1','4'
% correspond to the xPC scope numbers
VarNames = strcat({'xpcdata'},ScopeNumbers);
%% Read the data files from the target PC
% Get the name of the xPC target object from RTW options
% get_param(ModelName,'RTWOptions')
% -aRL32ObjectName="tg"
% Start a waitbar, in case the files are large
hWaitbar = waitbar(0,'Opening xPC Target File System');
% Get the xPC Target object from the base workspace
try
    tg = evalin('base','tg');
    % Get a target file system object
    filesys = tg.fs;
    % Make sure the file system is available
    if isempty(filesys)
        error('Unable to access target PC file system.')
    end
catch
    tg = xpctarget.xpc;
    % Get a target file system object
    filesys = tg.fs;
    % Make sure the file system is available
    if isempty(filesys)
        error('Unable to access target PC file system.')
    end
end
% Loop through each data file
NumScopes = length(ScopeFileNames);
for i=1:NumScopes
    % Update the waitbar
    waitbar(i/NumScopes,hWaitbar,['Reading Target File ' int2str(i) '/' int2str(NumScopes)]);
    % Open the file for reading
    fid = filesys.fopen(ScopeFileNames{i});
    % If the file could not be opened, warn and skip to the next iteration
    if isequal(fid,-1)
        warning('getxpcFileData:UnableToOpen',...
            ['Unable to open target file ''' ScopeFileNames{i} '''.']);
        RawData = [];
    else
        % Read the binary contents of the file
        BinaryData = filesys.fread(fid);
        % Close the file
        filesys.fclose(fid);
        % Convert to MATLAB format
        MLData = readxpcfile(BinaryData);
        RawData = MLData.data;
    end
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Change this format into a customized structure array
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Make sure that 'ShowPropagatedSignals' is on for the SrcPort
    try
        hPorts = get_param(hFileScopes{i},'PortHandles');
        hLine = get_param(hPorts.Inport,'Line');
        hSrcPort = get_param(hLine,'SrcPortHandle');
        set_param(hSrcPort,'ShowPropagatedSignals','on');
    catch
    end
    % Get the input signal names for this file scope
    SigNamesStr = get_param(hFileScopes{i},'InputSignalNames');
    if ~isempty(SigNamesStr{1})
        SigNamesCell = textscan(SigNamesStr{1},'%s','whitespace',' \b\t<>','delimiter',',');
        SigNamesCell = strrep(SigNamesCell{1},'>','');
    end
    % Initialize an empty struct into a temp variable
    % It initially has one field called 'time'
    xpcdata_temp = struct('time',[],'description',Description,'signals',{[]},...
        'scopeno',ScopeNumbers{i});
    % Make sure that RawData is not empty
    if ~isempty(RawData)
        % Save the time vector
        xpcdata_temp.time = RawData(:,end);
        % Save the datestamp
        FileInfo = filesys.dir(ScopeFileNames{i});
        xpcdata_temp.datestamp = [FileInfo.date ' ' FileInfo.time];
        % Loop through each signal (each column of data, except the last)
        for j=1:(size(RawData,2)-1)
            % Get the signal name of this data
            try
                % Get this signal name
                SigName = SigNamesCell{j};
                % Replace '%' with 'Pct'
                SigName = regexprep(SigName,'%','Pct');
                % Remove any non alpha/numeric/underscores from the signal name
                SigName = regexprep(SigName,'\W+','_');
                % Remove any underscores from the beginning or end
                SigName = regexprep(SigName,'(^_+)|(_+)$','');
                % Generate a valid variable name from the signal name,
                % excluding variable names that have already been used
                SigName = genvarname(SigName,fields(xpcdata_temp));
            catch
                SigName = ['noname' int2str(j)];
            end
            % Save data column for this signal
            xpcdata_temp.(SigName) = RawData(:,j);
            % Save the signal name
            xpcdata_temp.signals{j} = SigName;
        end
    end
    % Put the temporary structure into the assigned variable name
    eval([VarNames{i} '=xpcdata_temp;']);
end
% Update the waitbar
waitbar(1,hWaitbar,['Saving Output ' OutFileName]);
%% Save the data to the host PC, and clean up
% Save the .mat file
save(OutFilePath,VarNames{:});
% Close Waitbar
delete(hWaitbar);
% Display a success message to the user
cr = sprintf('\n');
disp(['Successfully saved target file scope data to ''' OutFilePath '''. ' cr...
    'Click <a href="matlab: load(''' OutFilePath...
    ''');">here</a> to load this file into the MATLAB workspace.']);

end
