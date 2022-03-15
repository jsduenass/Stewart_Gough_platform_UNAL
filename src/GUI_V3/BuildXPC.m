function  [Status] = BuildXPC
%BUILD2XPC Summary of this function goes here
%   Detailed explanation goes here

Constant1 = 0;  
%0      0                  DOUBLE    Scalar  Value                         ControlConstant
%222    68.317             DOUBLE    Scalar  Value                         If Action Subsystem5/Set1/FeedForwardController/Posi1Free
%223    68.3214            DOUBLE    Scalar  Value                         If Action Subsystem5/Set1/FeedForwardController/Posi2Free
%224    68.3123            DOUBLE    Scalar  Value                         If Action Subsystem5/Set1/FeedForwardController/Posi3Free
%225    68.3123            DOUBLE    Scalar  Value                         If Action Subsystem5/Set1/FeedForwardController/Posi4Free
%226    68.3214            DOUBLE    Scalar  Value                         If Action Subsystem5/Set1/FeedForwardController/Posi5Free
%227    68.317             DOUBLE    Scalar  Value                         If Action Subsystem5/Set1/FeedForwardController/Posi6Free


tgPC104 = xpctarget.xpc('TCPIP','192.168.1.12','22222')
pause(1);
if (strcmp(tgPC104.targetping,'success'))
    if (strcmp(tgPC104.Application,'loader'))
        msgbox('Building file... please wait','Building Status','help');
        load (tgPC104,'Code2XPCtarget\GUI_User_V1_3')
        tgPC104.setparam(Constant1,0);
        tgPC104.start;
        msgbox('Successful building','Building Status','help','replace');
        Status = 1;
    elseif (strcmp(tgPC104.Status,'stopped'))
        
        msgbox('Building file... please wait','Building Status','help');
        load (tgPC104,'Code2XPCtarget\GUI_User_V1_3')
        tgPC104.setparam(Constant1,0);
        tgPC104.start;
        msgbox('Successful building','Building Status','help','replace');
        Status = 1;
    elseif (strcmp(tgPC104.Status,'running'))
        tgPC104.stop;
        pause(1);
        msgbox('Building file... please wait','Building Status','help');
        load (tgPC104,'Code2XPCtarget\GUI_User_V1_3')
        tgPC104.setparam(Constant1,0);
        tgPC104.start;
        msgbox('Successful building','Building Status','help','replace');
        Status = 1;
    else
        msgbox(['Impossible to build ',FileName],'Building Status','error');
        Status = 0;
    end
else
    msgbox('Check TCP/IP connection','Building Status','error');
    Status = 0;
end

