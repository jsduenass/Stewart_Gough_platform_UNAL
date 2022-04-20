function [baseDec, maskDisplay, maskDescription] = maskdiamondmm16(phase, configuration, firstChan, numChans, range, base) %#ok

% maskdiamondmm16 - Mask Initialization function for Diamond Systems MM-16 driver blocks

    
    vendorName   = 'Diamond';
    deviceName   = 'MM-16-AT';
    description  = 'Analog Input';
    maskType     = 'addiamondmm16atcustom';
    
    if phase ~= 2  % assume InitFcn unless phase 2
        base = get_param( gcb, 'base' );
        blocks = find_system(bdroot, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'MaskType', maskType, 'base', base);
        if length(blocks) > 1
            error('xPCTarget:DiamondMM16AT:Block',...
                  'Only one Diamond Systems MM-16-AT A/D block per physical board allowed in a model - each block of this type must have a distinct ISA address.');
        end
        return
    end

    switch configuration
        case 1 % 0-16 SE
            maxChan = 16;
        case 2 % 0-9 DI
            maxChan = 8;
        otherwise
            disp('xPCTarget:DiamondMM16AT:Config',...
                 'bad configuration value');
    end

    %%% check First channel parameter
    if ~isa(firstChan, 'double')
        error('xPCTarget:DiamondMM16AT:Config',...
              'First channel number must be of class double');
    elseif any(size(firstChan, 1) ~= 1)
        error('xPCTarget:DiamondMM16AT:Config',...
              'First channel number must be a scalar');
    elseif ~ismember(firstChan, [1:maxChan]) %#ok
        error('xPCTarget:DiamondMM16AT:Config',...
              ['First channel number must be between 1 and ' num2str(maxChan)]);
    end
    
    %%% check Number of channels parameter
    if ~isa(numChans, 'double')
        error('xPCTarget:DiamondMM16AT:Config',...
              'Number of channels must be of class double');
    elseif any(size(numChans, 1) ~= 1)
        error('xPCTarget:DiamondMM16AT:Config',...
              'Number of channels must be a scalar');
    elseif ~ismember(numChans, [1:maxChan]) %#ok
        error('xPCTarget:DiamondMM16AT:Config',...
              ['Number of channels must be between 1 and ' num2str(maxChan)]);
    end
  
    if firstChan + numChans -1> maxChan
        error('xPCTarget:DiamondMM16AT:Config',...
              ['Selected first channel and number of channels yields a channel number exceeding ' num2str(maxChan)]);
    end

    %%% check base parameter
    
     switch base
        case 1 
            baseDec = hex2dec('220');
        case 2 
            baseDec = hex2dec('240');
        case 3 
            baseDec = hex2dec('250');
        case 4 
            baseDec = hex2dec('260');
        case 5 
            baseDec = hex2dec('280');
        case 6 
            baseDec = hex2dec('290');
        case 7 
            baseDec = hex2dec('2A0');
        case 8 
            baseDec = hex2dec('2B0');
        case 9 
            baseDec = hex2dec('2C0');            
        case 10 
            baseDec = hex2dec('2D0');            
        case 11
            baseDec = hex2dec('2E0');            
        case 12 
            baseDec = hex2dec('300');            
        case 13 
            baseDec = hex2dec('330');           
        case 14 
            baseDec = hex2dec('340');            
        case 15 
            baseDec = hex2dec('350');        
        case 16 
            baseDec = hex2dec('360');            
        case 17 
            baseDec = hex2dec('380');            
        case 18 
            baseDec = hex2dec('390');            
        case 19 
            baseDec = hex2dec('3A0');            
        case 20 
            baseDec = hex2dec('3C0');            
        case 21 
            baseDec = hex2dec('3E0');                    
        otherwise
            disp('xPCTarget:DiamondMM16AT:Config',...
                 'bad configuration value');
    end
    
    
    
    
    % compute maskDisplay and maskDescription
    maskDisplay = sprintf('disp(''%s\\n%s\\n%s'');', deviceName, vendorName, description);
    for i = 1 : numChans
        maskDisplay = sprintf('%s port_label(''output'', %i, ''%i'');', maskDisplay, i, firstChan + i - 1);
    end         
    maskDescription = [deviceName 10 vendorName 10 description];

