tg.start;
tg.setparam(id_mode,3);      % enable movement

id_PWM = tg.getparamid('Reference PWM','Value');
y = 'y'; n='n';
while true
    PWM = input('Ingrese el valor de PWM en forma de vector 1x6:\n[Enter para pausar]\n');
    
    if isempty(PWM)
        PWM = zeros(1,6);
        tg.setparam(id_PWM, [0 0 0 0 0 0])
        tg.setparam(id_mode,0);      % stop movement 
        if input('Continuar(y/n)\n') ~= 'y'
            break
        else
            tg.setparam(id_mode,3);  
        end
    end
    tg.setparam(id_PWM, PWM)
    tg.stop
end
