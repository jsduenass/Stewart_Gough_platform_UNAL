
function [basedec, maskDisplay, maskDescription, reset, initValue] = mdodiamond16at_custom(deviceName, channel, sampleTime, baseAddress2, reset, initValue)

% mdiodsmm - Mask Initialization for Diamond MM-16-AT series digital Input
    maxChan    = 8;
    vendorName = 'Diamond';
        
    portType = 'input';
    description = 'Digital Output';
	
    if ~isa(channel, 'double')
        error('xPCTarget:DiamondMM:Config', 'Channel Vector parameter must be of class double');
    end
	
    if size(channel, 1) > 1
        error('xPCTarget:DiamondMM:Config', 'Channel Vector parameter must be a row vector');
    end
	
    channel = round(channel);
	
    if ~all(ismember(channel, 1:maxChan))
        error('xPCTarget:DiamondMM:Config', ['Channel vector elements must be in the range 1-' num2str(maxChan)]);
    end
	
    
    if ~isa(sampleTime, 'double')
        error('xPCTarget:DiamondMM:Config', 'Sample Time parameter must be of class double');
    end
	
    if size(sampleTime, 1) > 1 || size(sampleTime, 2) > 1
        error('xPCTarget:DiamondMM:Config', 'Sample Time parameter must be a scalar');
    end
    
        
        if ~isa(reset, 'double')
            error('xPCTarget:DiamondMM:Config', 'Reset vector must be of class double');
        end
        if all( size(reset) == 1 )
            reset = reset * ones(size(channel));
        elseif ~all(size(reset) == size(channel))
            error('xPCTarget:DiamondMM:Config', 'Reset vector must be a scalar or have the same number of elements as the Channel vector');
        end
        reset = round(reset);
        if ~all(ismember(reset, [0 1]))
            error('xPCTarget:DiamondMM:Config', 'Reset vector elements must be 0 or 1');
        end
        
        if ~isa(initValue, 'double')
            error('xPCTarget:DiamondMM:Config', 'Initial value vector must be of class double');
        end
        if all( size(initValue) == 1 )
            initValue = initValue * ones(size(channel));
        elseif ~all(size(initValue) == size(channel))
            error('xPCTarget:DiamondMM:Config', 'Initial value vector must be a scalar or have the same number of elements as the Channel vector');
        end
    
    
    maskDisplay = sprintf('disp(''%s\\n%s\\n%s'');', deviceName, vendorName, description);
    for i = 1 : length(channel)
        maskDisplay = sprintf('%s port_label(''%s'', %i, ''%i'');', maskDisplay, portType, i, channel(i));
    end 
    
    maskDescription = [deviceName 10 vendorName 10 description];
    
    switch baseAddress2
        case 1 
            basedec = hex2dec('220');
        case 2 
            basedec = hex2dec('240');
        case 3 
            basedec = hex2dec('250');
        case 4 
            basedec = hex2dec('260');
        case 5 
            basedec = hex2dec('280');
        case 6 
            basedec = hex2dec('290');
        case 7 
            basedec = hex2dec('2A0');
        case 8 
            basedec = hex2dec('2B0');
        case 9 
            basedec = hex2dec('2C0');            
        case 10 
            basedec = hex2dec('2D0');            
        case 11
            basedec = hex2dec('2E0');            
        case 12 
            basedec = hex2dec('300');            
        case 13 
            basedec = hex2dec('330');           
        case 14 
            basedec = hex2dec('340');            
        case 15 
            basedec = hex2dec('350');        
        case 16 
            basedec = hex2dec('360');            
        case 17 
            basedec = hex2dec('380');            
        case 18 
            basedec = hex2dec('390');            
        case 19 
            basedec = hex2dec('3A0');            
        case 20 
            basedec = hex2dec('3C0');            
        case 21 
            basedec = hex2dec('3E0');                    
        otherwise
            disp('xPCTarget:DiamondMM16AT:Config',...
                 'bad configuration value');
    end
