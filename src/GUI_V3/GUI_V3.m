function varargout = GUI_V3(varargin)
% GUI_V3 MATLAB code for GUI_V3.fig
%      GUI_V3, by itself, creates a new GUI_V3 or raises the existing
%      singleton*.
%
%      H = GUI_V3 returns the handle to a new GUI_V3 or the handle to
%      the existing singleton*.
%
%      GUI_V3('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI_V3.M with the given input arguments.
%
%      GUI_V3('Property','Value',...) creates a new GUI_V3 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI_V3_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI_V3_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI_V3

% Last Modified by GUIDE v2.5 16-Aug-2013 12:27:02

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI_V3_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI_V3_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUI_V3 is made visible.
function GUI_V3_OpeningFcn(hObject, eventdata, handles, varargin)
clc
% tgPC104 = xpctarget.xpc;
% if (~strcmp(tgPC104.Application,'loader'))    
%     if (strcmp(tgPC104.Status,'running'))
%         tgPC104.stop;
%         pause(1);
%     end
% end

tau(1)=12.9;
tau(2)=20.9;
tau(3)=16;
tau(4)=26.2;
tau(5)=17.1;
tau(6)=15.2;
kdc(1)=35.737;
kdc(2)=65.089;
kdc(3)=51.966;
kdc(4)=74.788;
kdc(5)=49.788;
kdc(6)=51.427;
SG.tau=tau;
SG.kdc=kdc;

assignin('base','SG_Gl',SG);         %Save to base workspace
clear kdc tau SG

set([handles.text_status],'String','Status: Disconnected')
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI_V3 (see VARARGIN)

% Choose default command line output for GUI_V3
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);



% UIWAIT makes GUI_V3 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI_V3_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in TrajectoriesMenu.
function TrajectoriesMenu_Callback(hObject, eventdata, handles)
% hObject    handle to TrajectoriesMenu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns TrajectoriesMenu contents as cell array
%        contents{get(hObject,'Value')} returns selected item from TrajectoriesMenu


% --- Executes during object creation, after setting all properties.
function TrajectoriesMenu_CreateFcn(hObject, eventdata, handles)
% hObject    handle to TrajectoriesMenu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton_6DOFtest.
function pushbutton_6DOFtest_Callback(hObject, eventdata, handles)

ActuatorsIndx = [222; 223; 224; 225; 226; 227];
Constant1 = 0;

%fsys=xpctarget.fs('TCPIP','192.168.1.12','22222');      %Creating an .fs object
tgPC104=xpctarget.xpc('TCPIP','192.168.1.12','22222');
tgPC104.Status %stopped, running

iniCon = handles.iniCon;
for j=1:6
    tgPC104.setparam(ActuatorsIndx(j),iniCon(j));      %set_param('GUI_User_V1_3/If Action Subsystem5/Set1','ActLen',['[',num2str(d'),']']);
end
tgPC104.setparam(Constant1,1);              %set_param('GUI_User_V1_3/Constant1','Value','1');      
pause (10)
% X=-10.6066;
% Y=24.7534;
% Z=700.0000;
% Roll=0;
% Pitch=0;
% Yaw=0;
% MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

%--------------
% sc = evalin('base', 'getscope(tg);');        %To evaluate in base Work Space
% set_param('GUI_User_V1_3/Constant1','Value','5');   %Test PID
% sc(1).trigger;
ConstantControl = 0;
tgPC104.setparam(ConstantControl,2);  %set_param('GUI_User_V1_3/Constant1','Value','2');   %Test trajectory

if isfield(handles,'CurrentPosition') && ~isempty(handles.CurrentPosition)
    CurrentPosition = handles.CurrentPosition;
    CurrentPosition.State = 'Unknown';
else % Set up the results data structure
    CurrentPosition = struct('X',[],'Y',[],...
        'Z',[],'Roll',[],'Pitch',[],'Yaw',[],'State',['Unknown']);    
end

if strcmp(CurrentPosition.State,'Unknown'),
    state='off';
    %--Enable the direction buttons
    set([handles.pushbutton_X],'Enable',state)
    set([handles.pushbutton_MX],'Enable',state)
    set([handles.pushbutton_Y],'Enable',state)
    set([handles.pushbutton_MY],'Enable',state)
    set([handles.pushbutton_Z],'Enable',state)
    set([handles.pushbutton_MZ],'Enable',state)
    set([handles.pushbutton_Roll],'Enable',state)
    set([handles.pushbutton_MRoll],'Enable',state)
    set([handles.pushbutton_Pitch],'Enable',state)
    set([handles.pushbutton_MPitch],'Enable',state)
    set([handles.pushbutton_Yaw],'Enable',state)
    set([handles.pushbutton_MYaw],'Enable',state)
end

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)

% hObject    handle to pushbutton_6DOFtest (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton_STOP.
function pushbutton_STOP_Callback(hObject, eventdata, handles)

tgPC104=xpctarget.xpc('TCPIP','192.168.1.12','22222');
ConstantControl = 0;
tgPC104.setparam(ConstantControl,0);  %set_param('GUI_User_V1_3/Constant1','Value','0');


% hObject    handle to pushbutton_STOP (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton_HOME.
function pushbutton_HOME_Callback(hObject, eventdata, handles)

X=0;
Y=0;
Z=700;
Roll=0;
Pitch=0;
Yaw=0;

MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

if isfield(handles,'CurrentPosition') && ~isempty(handles.CurrentPosition)
    CurrentPosition = handles.CurrentPosition;
    CurrentPosition.State = 'Known';
    CurrentPosition.X=X;
    CurrentPosition.Y=Y;
    CurrentPosition.Z=Z;
    CurrentPosition.Roll=Roll;
    CurrentPosition.Pitch=Pitch;
    CurrentPosition.Yaw=Yaw;
else % Set up the results data structure
    CurrentPosition = struct('X',[X],'Y',[Y],...
        'Z',[Z],'Roll',[Roll],'Pitch',[Pitch],'Yaw',[Yaw],'State',['Known']);
end

if strcmp(CurrentPosition.State,'Known'),
    state='on';
    %--Enable the Plot and Remove buttons
    set([handles.pushbutton_X],'Enable',state)
    set([handles.pushbutton_MX],'Enable',state)
    set([handles.pushbutton_Y],'Enable',state)
    set([handles.pushbutton_MY],'Enable',state)
    set([handles.pushbutton_Z],'Enable',state)
    set([handles.pushbutton_MZ],'Enable',state)
    set([handles.pushbutton_Roll],'Enable',state)
    set([handles.pushbutton_MRoll],'Enable',state)
    set([handles.pushbutton_Pitch],'Enable',state)
    set([handles.pushbutton_MPitch],'Enable',state)
    set([handles.pushbutton_Yaw],'Enable',state)
    set([handles.pushbutton_MYaw],'Enable',state)
end

%---------------------------Update display status
set(handles.edit15_DisX,'String',num2str(X));
set(handles.edit14_DisY,'String',num2str(Y));
set(handles.edit13_DisZ,'String',num2str(Z));
set(handles.edit16_DisRoll,'String',num2str(Roll));
set(handles.edit17_DisPitch,'String',num2str(Pitch));
set(handles.edit18_DisYaw,'String',num2str(Yaw));

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)



% hObject    handle to pushbutton_HOME (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Hint: delete(hObject) closes the figure

tgPC104 = xpctarget.xpc('TCPIP','192.168.1.12','22222');
if (strcmp(tgPC104.targetping,'success'))    
    if (~strcmp(tgPC104.Application,'loader') && strcmp(tgPC104.Status,'running'))
        tgPC104.stop;
    end
end
delete(hObject);





% --- Executes on button press in pushbutton_Reload.
function pushbutton_Reload_Callback(hObject, eventdata, handles)

tgPC104 = xpctarget.xpc('TCPIP','192.168.1.12','22222');
tgPC104.stop;
set([handles.text_status],'String','Status: Disconnected')
pause(1)
tgPC104.start;
set([handles.text_status],'String','Status: Connected')


% hObject    handle to pushbutton_Reload (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function File_Callback(hObject, eventdata, handles)
% hObject    handle to File (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function Untitled_2_Callback(hObject, eventdata, handles)
% hObject    handle to Untitled_2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function uipushtool1_ClickedCallback(hObject, eventdata, handles)
% hObject    handle to uipushtool1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function import_file_Callback(hObject, eventdata, handles)
% hObject    handle to import_file (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton_MY.
function pushbutton_MY_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_MY (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CurrentPosition = handles.CurrentPosition;
CurrentPosition.Y=CurrentPosition.Y-get(handles.slider_StepLinearMotion,'Value');


X=CurrentPosition.X;
Y=CurrentPosition.Y;
Z=CurrentPosition.Z;
Roll=CurrentPosition.Roll;
Pitch=CurrentPosition.Pitch;
Yaw=CurrentPosition.Yaw;

MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)

% --- Executes on button press in pushbutton_Y.
function pushbutton_Y_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_Y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CurrentPosition = handles.CurrentPosition;
CurrentPosition.Y=CurrentPosition.Y+get(handles.slider_StepLinearMotion,'Value');


X=CurrentPosition.X;
Y=CurrentPosition.Y;
Z=CurrentPosition.Z;
Roll=CurrentPosition.Roll;
Pitch=CurrentPosition.Pitch;
Yaw=CurrentPosition.Yaw;

MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)

% --- Executes on button press in pushbutton_X.
function pushbutton_X_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_X (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CurrentPosition = handles.CurrentPosition;
CurrentPosition.X=CurrentPosition.X+get(handles.slider_StepLinearMotion,'Value');


X=CurrentPosition.X;
Y=CurrentPosition.Y;
Z=CurrentPosition.Z;
Roll=CurrentPosition.Roll;
Pitch=CurrentPosition.Pitch;
Yaw=CurrentPosition.Yaw;

MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)

% --- Executes on button press in pushbutton_MX.
function pushbutton_MX_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_MX (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CurrentPosition = handles.CurrentPosition;
CurrentPosition.X=CurrentPosition.X-get(handles.slider_StepLinearMotion,'Value');


X=CurrentPosition.X;
Y=CurrentPosition.Y;
Z=CurrentPosition.Z;
Roll=CurrentPosition.Roll;
Pitch=CurrentPosition.Pitch;
Yaw=CurrentPosition.Yaw;

MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)

% --- Executes on button press in pushbutton_Z.
function pushbutton_Z_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_Z (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CurrentPosition = handles.CurrentPosition;
CurrentPosition.Z=CurrentPosition.Z+get(handles.slider_StepLinearMotion,'Value');


X=CurrentPosition.X;
Y=CurrentPosition.Y;
Z=CurrentPosition.Z;
Roll=CurrentPosition.Roll;
Pitch=CurrentPosition.Pitch;
Yaw=CurrentPosition.Yaw;

MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)



% --- Executes on button press in pushbutton_MZ.
function pushbutton_MZ_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_MZ (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CurrentPosition = handles.CurrentPosition;
CurrentPosition.Z=CurrentPosition.Z-get(handles.slider_StepLinearMotion,'Value');


X=CurrentPosition.X;
Y=CurrentPosition.Y;
Z=CurrentPosition.Z;
Roll=CurrentPosition.Roll;
Pitch=CurrentPosition.Pitch;
Yaw=CurrentPosition.Yaw;

MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)

% --- Executes on button press in pushbutton_Roll.
function pushbutton_Roll_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_Roll (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CurrentPosition = handles.CurrentPosition;
CurrentPosition.Roll=CurrentPosition.Roll+get(handles.slider_StepAngularMotion,'Value');


X=CurrentPosition.X;
Y=CurrentPosition.Y;
Z=CurrentPosition.Z;
Roll=CurrentPosition.Roll;
Pitch=CurrentPosition.Pitch;
Yaw=CurrentPosition.Yaw;

MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)

% --- Executes on button press in pushbutton_MRoll.
function pushbutton_MRoll_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_MRoll (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CurrentPosition = handles.CurrentPosition;
CurrentPosition.Roll=CurrentPosition.Roll-get(handles.slider_StepAngularMotion,'Value');


X=CurrentPosition.X;
Y=CurrentPosition.Y;
Z=CurrentPosition.Z;
Roll=CurrentPosition.Roll;
Pitch=CurrentPosition.Pitch;
Yaw=CurrentPosition.Yaw;

MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)

% --- Executes on button press in pushbutton_Pitch.
function pushbutton_Pitch_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_Pitch (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CurrentPosition = handles.CurrentPosition;
CurrentPosition.Pitch=CurrentPosition.Pitch+get(handles.slider_StepAngularMotion,'Value');


X=CurrentPosition.X;
Y=CurrentPosition.Y;
Z=CurrentPosition.Z;
Roll=CurrentPosition.Roll;
Pitch=CurrentPosition.Pitch;
Yaw=CurrentPosition.Yaw;

MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)

% --- Executes on button press in pushbutton_MPitch.
function pushbutton_MPitch_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_MPitch (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CurrentPosition = handles.CurrentPosition;
CurrentPosition.Pitch=CurrentPosition.Pitch-get(handles.slider_StepAngularMotion,'Value');


X=CurrentPosition.X;
Y=CurrentPosition.Y;
Z=CurrentPosition.Z;
Roll=CurrentPosition.Roll;
Pitch=CurrentPosition.Pitch;
Yaw=CurrentPosition.Yaw;

MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)

% --- Executes on button press in pushbutton_Yaw.
function pushbutton_Yaw_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_Yaw (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CurrentPosition = handles.CurrentPosition;
CurrentPosition.Yaw=CurrentPosition.Yaw+get(handles.slider_StepAngularMotion,'Value');


X=CurrentPosition.X;
Y=CurrentPosition.Y;
Z=CurrentPosition.Z;
Roll=CurrentPosition.Roll;
Pitch=CurrentPosition.Pitch;
Yaw=CurrentPosition.Yaw;

MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)

% --- Executes on button press in pushbutton_MYaw.
function pushbutton_MYaw_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_MYaw (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
CurrentPosition = handles.CurrentPosition;
CurrentPosition.Yaw=CurrentPosition.Yaw-get(handles.slider_StepAngularMotion,'Value');


X=CurrentPosition.X;
Y=CurrentPosition.Y;
Z=CurrentPosition.Z;
Roll=CurrentPosition.Roll;
Pitch=CurrentPosition.Pitch;
Yaw=CurrentPosition.Yaw;

MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)

% --- Executes on selection change in listbox_HistoryCode.
function listbox_HistoryCode_Callback(hObject, eventdata, handles)
% hObject    handle to listbox_HistoryCode (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns listbox_HistoryCode contents as cell array
%        contents{get(hObject,'Value')} returns selected item from listbox_HistoryCode


% --- Executes during object creation, after setting all properties.
function listbox_HistoryCode_CreateFcn(hObject, eventdata, handles)
% hObject    handle to listbox_HistoryCode (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit1_Callback(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit1 as text
%        str2double(get(hObject,'String')) returns contents of edit1 as a double


% --- Executes during object creation, after setting all properties.
function edit1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton17_ExecCode.
function pushbutton17_ExecCode_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton17_ExecCode (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on slider movement.
function slider2_Callback(hObject, eventdata, handles)
% hObject    handle to slider2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function slider2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on slider movement.
function slider_StepAngularMotion_Callback(hObject, eventdata, handles)
% hObject    handle to slider_StepAngularMotion (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider
Position = get(hObject,'Value');
set(handles.edit12_StepAngularDegrees,'String',num2str(Position));

% --- Executes during object creation, after setting all properties.
function slider_StepAngularMotion_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider_StepAngularMotion (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end



function edit2_Callback(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit2 as text
%        str2double(get(hObject,'String')) returns contents of edit2 as a double


% --- Executes during object creation, after setting all properties.
function edit2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit3_Callback(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit3 as text
%        str2double(get(hObject,'String')) returns contents of edit3 as a double


% --- Executes during object creation, after setting all properties.
function edit3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit4_Callback(hObject, eventdata, handles)
% hObject    handle to edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit4 as text
%        str2double(get(hObject,'String')) returns contents of edit4 as a double


% --- Executes during object creation, after setting all properties.
function edit4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function slider_StepLinearMotion_Callback(hObject, eventdata, handles)
% hObject    handle to slider_StepLinearMotion (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider

Position = get(hObject,'Value');
set(handles.edit11_StepLinearmm,'String',num2str(Position));


% --- Executes during object creation, after setting all properties.
function slider_StepLinearMotion_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider_StepLinearMotion (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end



function edit_XGoto_Callback(hObject, eventdata, handles)
% hObject    handle to edit_XGoto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_XGoto as text
%        str2double(get(hObject,'String')) returns contents of edit_XGoto as a double


% --- Executes during object creation, after setting all properties.
function edit_XGoto_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_XGoto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_YGoto_Callback(hObject, eventdata, handles)
% hObject    handle to edit_YGoto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_YGoto as text
%        str2double(get(hObject,'String')) returns contents of edit_YGoto as a double


% --- Executes during object creation, after setting all properties.
function edit_YGoto_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_YGoto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_ZGoto_Callback(hObject, eventdata, handles)
% hObject    handle to edit_ZGoto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_ZGoto as text
%        str2double(get(hObject,'String')) returns contents of edit_ZGoto as a double


% --- Executes during object creation, after setting all properties.
function edit_ZGoto_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_ZGoto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton_Goto.
function pushbutton_Goto_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_Goto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
X=str2double(get(handles.edit_XGoto,'String'));
Y=str2double(get(handles.edit_YGoto,'String'));
Z=str2double(get(handles.edit_ZGoto,'String'));
Roll=str2double(get(handles.edit_RollGoto,'String'));
Pitch=str2double(get(handles.edit_PitchGoto,'String'));
Yaw=str2double(get(handles.edit_YawGoto,'String'));
%[X,Y,Z,Roll,Pitch,Yaw];
MoveSG(X,Y,Z,Roll,Pitch,Yaw,handles);


if isfield(handles,'CurrentPosition') && ~isempty(handles.CurrentPosition)
    CurrentPosition = handles.CurrentPosition;
    CurrentPosition.State = 'Known';
else % Set up the results data structure
    CurrentPosition = struct('X',[],'Y',[],...
        'Z',[],'Roll',[],'Pitch',[],'Yaw',[],'State',['Known']);    
end

if strcmp(CurrentPosition.State,'Known'),
    state='on';
    %--Enable the Plot and Remove buttons
    set([handles.pushbutton_X],'Enable',state)
    set([handles.pushbutton_MX],'Enable',state)
    set([handles.pushbutton_Y],'Enable',state)
    set([handles.pushbutton_MY],'Enable',state)
    set([handles.pushbutton_Z],'Enable',state)
    set([handles.pushbutton_MZ],'Enable',state)
    set([handles.pushbutton_Roll],'Enable',state)
    set([handles.pushbutton_MRoll],'Enable',state)
    set([handles.pushbutton_Pitch],'Enable',state)
    set([handles.pushbutton_MPitch],'Enable',state)
    set([handles.pushbutton_Yaw],'Enable',state)
    set([handles.pushbutton_MYaw],'Enable',state)
end

CurrentPosition.X=X;
CurrentPosition.Y=Y;
CurrentPosition.Z=Z;
CurrentPosition.Roll=Roll;
CurrentPosition.Pitch=Pitch;
CurrentPosition.Yaw=Yaw;

handles.CurrentPosition = CurrentPosition;
guidata(hObject,handles)

function edit_RollGoto_Callback(hObject, eventdata, handles)
% hObject    handle to edit_RollGoto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_RollGoto as text
%        str2double(get(hObject,'String')) returns contents of edit_RollGoto as a double


% --- Executes during object creation, after setting all properties.
function edit_RollGoto_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_RollGoto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_PitchGoto_Callback(hObject, eventdata, handles)
% hObject    handle to edit_PitchGoto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_PitchGoto as text
%        str2double(get(hObject,'String')) returns contents of edit_PitchGoto as a double


% --- Executes during object creation, after setting all properties.
function edit_PitchGoto_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_PitchGoto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_YawGoto_Callback(hObject, eventdata, handles)
% hObject    handle to edit_YawGoto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_YawGoto as text
%        str2double(get(hObject,'String')) returns contents of edit_YawGoto as a double


% --- Executes during object creation, after setting all properties.
function edit_YawGoto_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_YawGoto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit11_StepLinearmm_Callback(hObject, eventdata, handles)
% hObject    handle to edit11_StepLinearmm (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit11_StepLinearmm as text
%        str2double(get(hObject,'String')) returns contents of edit11_StepLinearmm as a double
  %model_open(handles)

  % Get the new value for the Kf Gain
  NewStrVal = get(hObject,'String');
  NewVal = str2double(NewStrVal);
  Max = (get(handles.slider_StepLinearMotion,'Max'));
  Min = (get(handles.slider_StepLinearMotion,'Min'));
 
  
  % Check that the entered value falls within the allowable range
  if  isempty(NewVal) || (NewVal< Min) || (NewVal>Max) || isnan(NewVal),
    % Revert to last value, as indicated by KfValueSlider
    OldVal = get(handles.slider_StepLinearMotion,'Value');
    set(hObject,'String',OldVal)    
  else
      
    % Set the value of the KfValueSlider to the new value
    set(handles.slider_StepLinearMotion,'Value',NewVal) 
  end

% --- Executes during object creation, after setting all properties.
function edit11_StepLinearmm_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit11_StepLinearmm (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit12_StepAngularDegrees_Callback(hObject, eventdata, handles)
% hObject    handle to edit12_StepAngularDegrees (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit12_StepAngularDegrees as text
%        str2double(get(hObject,'String')) returns contents of edit12_StepAngularDegrees as a double
NewStrVal = get(hObject,'String');
NewVal = str2double(NewStrVal);
Max = (get(handles.slider_StepAngularMotion,'Max'));
Min = (get(handles.slider_StepAngularMotion,'Min'));


% Check that the entered value falls within the allowable range
if  isempty(NewVal) || (NewVal< Min) || (NewVal>Max) || isnan(NewVal),
    % Revert to last value, as indicated by KfValueSlider
    OldVal = get(handles.slider_StepAngularMotion,'Value');
    set(hObject,'String',OldVal)
else
    
    % Set the value of the KfValueSlider to the new value
    set(handles.slider_StepAngularMotion,'Value',NewVal)
end

% --- Executes during object creation, after setting all properties.
function edit12_StepAngularDegrees_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit12_StepAngularDegrees (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit13_DisZ_Callback(hObject, eventdata, handles)
% hObject    handle to edit13_DisZ (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit13_DisZ as text
%        str2double(get(hObject,'String')) returns contents of edit13_DisZ as a double


% --- Executes during object creation, after setting all properties.
function edit13_DisZ_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit13_DisZ (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit14_DisY_Callback(hObject, eventdata, handles)
% hObject    handle to edit14_DisY (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit14_DisY as text
%        str2double(get(hObject,'String')) returns contents of edit14_DisY as a double


% --- Executes during object creation, after setting all properties.
function edit14_DisY_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit14_DisY (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit15_DisX_Callback(hObject, eventdata, handles)
% hObject    handle to edit15_DisX (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit15_DisX as text
%        str2double(get(hObject,'String')) returns contents of edit15_DisX as a double


% --- Executes during object creation, after setting all properties.
function edit15_DisX_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit15_DisX (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit16_DisRoll_Callback(hObject, eventdata, handles)
% hObject    handle to edit16_DisRoll (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit16_DisRoll as text
%        str2double(get(hObject,'String')) returns contents of edit16_DisRoll as a double


% --- Executes during object creation, after setting all properties.
function edit16_DisRoll_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit16_DisRoll (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit17_DisPitch_Callback(hObject, eventdata, handles)
% hObject    handle to edit17_DisPitch (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit17_DisPitch as text
%        str2double(get(hObject,'String')) returns contents of edit17_DisPitch as a double


% --- Executes during object creation, after setting all properties.
function edit17_DisPitch_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit17_DisPitch (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit18_DisYaw_Callback(hObject, eventdata, handles)
% hObject    handle to edit18_DisYaw (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit18_DisYaw as text
%        str2double(get(hObject,'String')) returns contents of edit18_DisYaw as a double


% --- Executes during object creation, after setting all properties.
function edit18_DisYaw_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit18_DisYaw (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --------------------------------------------------------------------
function File_Menu_Callback(hObject, eventdata, handles)
% hObject    handle to File_Menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function TargetPC_Menu_Callback(hObject, eventdata, handles)
% hObject    handle to TargetPC_Menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function BuildProgram_Menu_Callback(hObject, eventdata, handles)
% hObject    handle to BuildProgram_Menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (BuildXPC)
    set([handles.text_status],'String','Status: Connected');
    set([handles.pushbutton_Goto],'Enable','on');
    %set([handles.pushbutton_6DOFtest],'Enable','on');
    set([handles.pushbutton_HOME],'Enable','on');
    set([handles.pushbutton_STOP],'Enable','on');
    set([handles.pushbutton_Reload],'Enable','on');
else
    set([handles.text_status],'String','Status: Disconnected');
end


% --------------------------------------------------------------------
function Connect_Menu_Callback(hObject, eventdata, handles)
% hObject    handle to Connect_Menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
tgPC104 = xpctarget.xpc('TCPIP','192.168.1.12','22222');
tgPC104.start;
% set_param('GUI_User_V1_3','SimulationCommand','connect');
% set_param('GUI_User_V1_3','SimulationCommand','start');
set([handles.text_status],'String','Status: Connected')

% --------------------------------------------------------------------
function Disconnect_Menu_Callback(hObject, eventdata, handles)
% hObject    handle to Disconnect_Menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
tgPC104 = xpctarget.xpc('TCPIP','192.168.1.12','22222');
tgPC104.stop;
set([handles.text_status],'String','Status: Disconnected')

% --------------------------------------------------------------------
function Export_Menu_Callback(hObject, eventdata, handles)
% hObject    handle to Export_Menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function File2XPC_Menu_Callback(hObject, eventdata, handles)
% hObject    handle to File2XPC_Menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[FileName,PathName,FilterIndex] = uigetfile('*.dat');

if (FilterIndex == 1) 
    [iniCon] = exportFile2XPc([PathName,FileName]);
    set([handles.pushbutton_6DOFtest],'Enable','on');
end
%set([handles.iniCon],'String','Status: Disconnected')
handles.iniCon = iniCon;
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);



% --- Executes during object deletion, before destroying properties.
function text_status_DeleteFcn(hObject, eventdata, handles)
% hObject    handle to text_status (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function uipushOpen_ClickedCallback(hObject, eventdata, handles)
% hObject    handle to uipushOpen (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function uipushtool5_ClickedCallback(hObject, eventdata, handles)
% hObject    handle to uipushtool5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function Exit_menu_Callback(hObject, eventdata, handles)
% hObject    handle to Exit_menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

figure1_CloseRequestFcn(gcbf, eventdata, handles)


% --------------------------------------------------------------------
function toolButton_Export_ClickedCallback(hObject, eventdata, handles)
% hObject    handle to toolButton_Export (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
File2XPC_Menu_Callback(hObject, eventdata, handles)


% --------------------------------------------------------------------
function toolButton_Build_ClickedCallback(hObject, eventdata, handles)
% hObject    handle to toolButton_Build (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
BuildProgram_Menu_Callback(hObject, eventdata, handles)
