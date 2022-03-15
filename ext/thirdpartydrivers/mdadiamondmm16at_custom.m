function [maskdisplay, maskdescription, finalvalue, initValue, basedec] = ...
    mdadiamondmm16at_custom( boardType, channel, baseAddress, finalValuePop, initValue) % #ok

%  Mask Initialization function for Dimaond Systems MM-16-AT driver blocks


    switch boardType
     case 1  
      maskdisplay='disp(''MM-16-AT\nDiamond\n';
      description='MM-16-AT';
      maxChannel=4;      
    end
    maskdisplay=[maskdisplay,'Analog Output'');'];
    for i=1:length(channel)
      maskdisplay=[maskdisplay,'port_label(''input'',',num2str(i),',''',num2str(channel(i)),''');']; %#ok
    end
    maskdescription=[description,10,'Diamond Systems',10,'Analog Output'];
    

    if size(channel,1)~=1
      error('xPCTarget:Diamond:Config',...
            'Channel Vector must be a row vector');
    end
    
    chUsed=zeros(1,4);
    for i=1:length(channel)
      chan=round(channel(i));
      if chan < 1 || chan > maxChannel
        error('xPCTarget:Diamond:Config',...
              ['Channel Vector elements have to be in the range: 1..',num2str(maxChannel)]);
      end
      if chUsed(chan)
        error('xPCTarget:Diamond:Config',...
              ['channel ',num2str(chan),' already in use']);
      else
        chUsed(chan)=1;
      end
    end

  

    %%% check initValue vector parameter
    if ~isa(initValue, 'double')
      error('xPCTarget:Diamond:Config',...
            'Initial value vector parameter must be of class double');
    end
    if size(initValue) == [1 1] %#ok
      initValue = initValue * ones(size(channel));
    elseif ~all(size(initValue) == size(channel))
      error('xPCTarget:Diamond:Config',...
            'Initial value must be a scalar or have the same number of elements as the Channel vector');
    end
    
    switch finalValuePop
        case 1                  %Set all values to 0
            finalvalue=1;
        case 2                  % No modify values
            finalvalue=0;
    end
            
            
    
    switch baseAddress
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
  
  