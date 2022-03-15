function [ aPb,aRb,aVp,aWb,aVpP,aWbP,Angles,Time] = TrajectoryGeneratorSG( IniPos,IniAngle,FinalPos,FinalAngle, Time,samTime,Interpolation)
%% Lineal interpolation, neither angular nor lineal acceleration

if (strcmp(Interpolation,'Linear'))    
    nSamples=Time/samTime;
    %nSamples=nSamples-1;
    deltaPhi=(FinalAngle(3)-IniAngle(3))/nSamples;
    deltaTheta=(FinalAngle(2)-IniAngle(2))/nSamples;
    deltaPsi=(FinalAngle(1)-IniAngle(1))/nSamples;
    deltaPos=(FinalPos-IniPos)/nSamples;
    Time(1)=0;
    for i=1:nSamples
        if i==1
        phi(i)=IniAngle(3);
        theta(i)=IniAngle(2);
        psii(i)=IniAngle(1);

        phiP(i)=0;
        thetaP(i)=0;
        psiP(i)=0;

        phiPP(i)=0;
        psiPP(i)=0;
        thetaPP(i)=0;

        aPb(:,i)=IniPos;
        aRb(:,:,i)=[cos(phi(i))*cos(theta(i)) cos(phi(i))*sin(theta(i))*sin(psii(i))-sin(phi(i))*cos(psii(i)) cos(phi(i))*sin(theta(i))*cos(psii(i))+sin(phi(i))*sin(psii(i));...
                    sin(phi(i))*cos(theta(i)) sin(phi(i))*sin(theta(i))*sin(psii(i))+cos(phi(i))*cos(psii(i)) sin(phi(i))*sin(theta(i))*cos(psii(i))-cos(phi(i))*sin(psii(i));...
                    -sin(theta(i)) cos(theta(i))*sin(psii(i)) cos(theta(i))*cos(psii(i));];   %Rotation of reference frame B (Moving platform)
        aVp(:,i)=[0;0;0];  %INITIAL CONDITIONS
        aWb(:,i)=[0;0;0];
        aVpP(:,i)=[0;0;0];
        aWbP(:,i)=[0;0;0];

        else   
            Time(i)=Time(i-1)+samTime;
            phi(i)=phi(i-1)+deltaPhi;
            theta(i)=theta(i-1)+deltaTheta;
            psii(i)=psii(i-1)+deltaPsi;

            phiP(i)=(phi(i)-phi(i-1))/samTime;
            thetaP(i)=(theta(i)-theta(i-1))/samTime;
            psiP(i)=(psii(i)-psii(i-1))/samTime; 

            phiPP(i)=(phiP(i)-phiP(i-1))/samTime;
            thetaPP(i)=(thetaP(i)-thetaP(i-1))/samTime;
            psiPP(i)=(psiP(i)-psiP(i-1))/samTime; 

            aPb(:,i)=aPb(:,i-1)+deltaPos;        
            aRb(:,:,i)=[cos(phi(i))*cos(theta(i)) cos(phi(i))*sin(theta(i))*sin(psii(i))-sin(phi(i))*cos(psii(i)) cos(phi(i))*sin(theta(i))*cos(psii(i))+sin(phi(i))*sin(psii(i));...
                        sin(phi(i))*cos(theta(i)) sin(phi(i))*sin(theta(i))*sin(psii(i))+cos(phi(i))*cos(psii(i)) sin(phi(i))*sin(theta(i))*cos(psii(i))-cos(phi(i))*sin(psii(i));...
                        -sin(theta(i)) cos(theta(i))*sin(psii(i)) cos(theta(i))*cos(psii(i));];  %Rotation of reference frame B (Moving platform)
            aVp(:,i)=(aPb(:,i)-aPb(:,i-1))/samTime;
            aWb(:,i)=[psiP(i); thetaP(i); phiP(i)];
             aVpP(:,i)=(aVp(:,i)-aVp(:,i-1))/samTime;
             aWbP(:,i)=[psiPP(i); thetaPP(i); phiPP(i)];  
        end

    end
    Angles=[psii', theta',phi'];
end
if (strcmp(Interpolation,'Cubic'))    
    nSamples=Time/samTime;
    %nSamples=nSamples-1;    
    tf=Time;
    t0=0;
    T=[1 t0 t0^2 t0^3;
       0 1 2*t0 3*t0^2;
       1 tf tf^2 tf^3;
       0 1 2*tf 3*tf^2];
    T=inv(T);
    %Initial and final conditions for Cubic interpolation
    Phiq=[IniAngle(3);0;FinalAngle(3);0];
    Thetaq=[IniAngle(2);0;FinalAngle(2);0];
    Psiq=[IniAngle(1);0;FinalAngle(1);0];
    PosXq=[IniPos(1);0;FinalPos(1);0];
    PosYq=[IniPos(2);0;FinalPos(2);0];
    PosZq=[IniPos(3);0;FinalPos(3);0];
    PhiA=T*Phiq;
    ThetaA=T*Thetaq;
    PsiA=T*Psiq;
    PosXA=T*PosXq;
    PosYA=T*PosYq;
    PosZA=T*PosZq;
    
    for i=1:nSamples
         if i==1
            Time(i)=0;   
            phi(i)=IniAngle(3);
            theta(i)=IniAngle(2);
            psii(i)=IniAngle(1);

            phiP(i)=0;
            thetaP(i)=0;
            psiP(i)=0;

            phiPP(i)=0;
            psiPP(i)=0;
            thetaPP(i)=0;

            aPb(:,i)=IniPos;
            aRb(:,:,i)=[cos(phi(i))*cos(theta(i)) cos(phi(i))*sin(theta(i))*sin(psii(i))-sin(phi(i))*cos(psii(i)) cos(phi(i))*sin(theta(i))*cos(psii(i))+sin(phi(i))*sin(psii(i));...
                        sin(phi(i))*cos(theta(i)) sin(phi(i))*sin(theta(i))*sin(psii(i))+cos(phi(i))*cos(psii(i)) sin(phi(i))*sin(theta(i))*cos(psii(i))-cos(phi(i))*sin(psii(i));...
                        -sin(theta(i)) cos(theta(i))*sin(psii(i)) cos(theta(i))*cos(psii(i));];   %Rotation of reference frame B (Moving platform)
            aVp(:,i)=[0;0;0];  %INITIAL CONDITIONS
            aWb(:,i)=[0;0;0];
            aVpP(:,i)=[0;0;0];
            aWbP(:,i)=[0;0;0];
            else   
                Time(i)=Time(i-1)+samTime;
                phi(i)=PhiA(1)+PhiA(2)*Time(i)+PhiA(3)*Time(i)^2+PhiA(4)*Time(i)^3;
                theta(i)=ThetaA(1)+ThetaA(2)*Time(i)+ThetaA(3)*Time(i)^2+ThetaA(4)*Time(i)^3;
                psii(i)=PsiA(1)+PsiA(2)*Time(i)+PsiA(3)*Time(i)^2+PsiA(4)*Time(i)^3;
                X=PosXA(1)+PosXA(2)*Time(i)+PosXA(3)*Time(i)^2+PosXA(4)*Time(i)^3;
                Y=PosYA(1)+PosYA(2)*Time(i)+PosYA(3)*Time(i)^2+PosYA(4)*Time(i)^3;
                Z=PosZA(1)+PosZA(2)*Time(i)+PosZA(3)*Time(i)^2+PosZA(4)*Time(i)^3;
                

                phiP(i)=(phi(i)-phi(i-1))/samTime;
                thetaP(i)=(theta(i)-theta(i-1))/samTime;
                psiP(i)=(psii(i)-psii(i-1))/samTime; 

                phiPP(i)=(phiP(i)-phiP(i-1))/samTime;
                thetaPP(i)=(thetaP(i)-thetaP(i-1))/samTime;
                psiPP(i)=(psiP(i)-psiP(i-1))/samTime; 

                aPb(:,i)=[X;Y;Z];        
                aRb(:,:,i)=[cos(phi(i))*cos(theta(i)) cos(phi(i))*sin(theta(i))*sin(psii(i))-sin(phi(i))*cos(psii(i)) cos(phi(i))*sin(theta(i))*cos(psii(i))+sin(phi(i))*sin(psii(i));...
                        sin(phi(i))*cos(theta(i)) sin(phi(i))*sin(theta(i))*sin(psii(i))+cos(phi(i))*cos(psii(i)) sin(phi(i))*sin(theta(i))*cos(psii(i))-cos(phi(i))*sin(psii(i));...
                        -sin(theta(i)) cos(theta(i))*sin(psii(i)) cos(theta(i))*cos(psii(i));];   %Rotation of reference frame B (Moving platform)
                aVp(:,i)=(aPb(:,i)-aPb(:,i-1))/samTime;
                aWb(:,i)=[psiP(i); thetaP(i); phiP(i)];
                aVpP(:,i)=(aVp(:,i)-aVp(:,i-1))/samTime;
                aWbP(:,i)=[psiPP(i); thetaPP(i); phiPP(i)];  
         end
    end
    Angles=[psii', theta',phi'];
end
if (strcmp(Interpolation,'Quintic'))    
    nSamples=Time/samTime;
    %nSamples=nSamples-1;    
    tf=Time;
    t0=0;
    T=[1 t0 t0^2 t0^3 t0^4 t0^5;
       0 1 2*t0 3*t0^2 4*t0^3 5*t0^4;       
       0 0 2 6*t0 12*t0^2 20*t0^3;
       1 tf tf^2 tf^3 tf^4 tf^5;
       0 1 2*tf 3*tf^2 4*tf^3 5*tf^4;       
       0 0 2 6*tf 12*tf^2 20*tf^3];
    T=inv(T);
    Phiq=[IniAngle(3);0;0;FinalAngle(3);0;0];
    Thetaq=[IniAngle(2);0;0;FinalAngle(2);0;0];
    Psiq=[IniAngle(1);0;0;FinalAngle(1);0;0];
    PosXq=[IniPos(1);0;0;FinalPos(1);0;0];
    PosYq=[IniPos(2);0;0;FinalPos(2);0;0];
    PosZq=[IniPos(3);0;0;FinalPos(3);0;0];
    PhiA=T*Phiq;
    ThetaA=T*Thetaq;
    PsiA=T*Psiq;
    PosXA=T*PosXq;
    PosYA=T*PosYq;
    PosZA=T*PosZq;
    
    for i=1:nSamples
         if i==1
            Time(i)=0;   
            phi(i)=IniAngle(3);
            theta(i)=IniAngle(2);
            psii(i)=IniAngle(1);

            phiP(i)=0;
            thetaP(i)=0;
            psiP(i)=0;

            phiPP(i)=0;
            psiPP(i)=0;
            thetaPP(i)=0;

            aPb(:,i)=IniPos;
            aRb(:,:,i)=[cos(phi(i))*cos(theta(i)) cos(phi(i))*sin(theta(i))*sin(psii(i))-sin(phi(i))*cos(psii(i)) cos(phi(i))*sin(theta(i))*cos(psii(i))+sin(phi(i))*sin(psii(i));...
                        sin(phi(i))*cos(theta(i)) sin(phi(i))*sin(theta(i))*sin(psii(i))+cos(phi(i))*cos(psii(i)) sin(phi(i))*sin(theta(i))*cos(psii(i))-cos(phi(i))*sin(psii(i));...
                        -sin(theta(i)) cos(theta(i))*sin(psii(i)) cos(theta(i))*cos(psii(i))];   %Rotation of reference frame B (Moving platform)
            aVp(:,i)=[0;0;0];  %INITIAL CONDITIONS
            aWb(:,i)=[0;0;0];
            aVpP(:,i)=[0;0;0];
            aWbP(:,i)=[0;0;0];
            else   
                Time(i)=Time(i-1)+samTime;
                phi(i)=PhiA(1)+PhiA(2)*Time(i)+PhiA(3)*Time(i)^2+PhiA(4)*Time(i)^3+PhiA(5)*Time(i)^4+PhiA(6)*Time(i)^5;
                theta(i)=ThetaA(1)+ThetaA(2)*Time(i)+ThetaA(3)*Time(i)^2+ThetaA(4)*Time(i)^3+ThetaA(5)*Time(i)^4+ThetaA(6)*Time(i)^5;
                psii(i)=PsiA(1)+PsiA(2)*Time(i)+PsiA(3)*Time(i)^2+PsiA(4)*Time(i)^3+PsiA(5)*Time(i)^4+PsiA(6)*Time(i)^5;
                X=PosXA(1)+PosXA(2)*Time(i)+PosXA(3)*Time(i)^2+PosXA(4)*Time(i)^3+PosXA(5)*Time(i)^4+PosXA(6)*Time(i)^5;
                Y=PosYA(1)+PosYA(2)*Time(i)+PosYA(3)*Time(i)^2+PosYA(4)*Time(i)^3+PosYA(5)*Time(i)^4+PosYA(6)*Time(i)^5;
                Z=PosZA(1)+PosZA(2)*Time(i)+PosZA(3)*Time(i)^2+PosZA(4)*Time(i)^3+PosZA(5)*Time(i)^4+PosZA(6)*Time(i)^5;
                

                phiP(i)=(phi(i)-phi(i-1))/samTime;
                thetaP(i)=(theta(i)-theta(i-1))/samTime;
                psiP(i)=(psii(i)-psii(i-1))/samTime; 

                phiPP(i)=(phiP(i)-phiP(i-1))/samTime;
                thetaPP(i)=(thetaP(i)-thetaP(i-1))/samTime;
                psiPP(i)=(psiP(i)-psiP(i-1))/samTime; 

                aPb(:,i)=[X;Y;Z];        
                aRb(:,:,i)=[cos(phi(i))*cos(theta(i)), cos(phi(i))*sin(theta(i))*sin(psii(i))-sin(phi(i))*cos(psii(i)), cos(phi(i))*sin(theta(i))*cos(psii(i))+sin(phi(i))*sin(psii(i)),;...
                        sin(phi(i))*cos(theta(i)), sin(phi(i))*sin(theta(i))*sin(psii(i))+cos(phi(i))*cos(psii(i)), sin(phi(i))*sin(theta(i))*cos(psii(i))-cos(phi(i))*sin(psii(i)),;...
                        -sin(theta(i)), cos(theta(i))*sin(psii(i)), cos(theta(i))*cos(psii(i)),];   %Rotation of reference frame B (Moving platform)
                aVp(:,i)=(aPb(:,i)-aPb(:,i-1))/samTime;
                aWb(:,i)=[psiP(i); thetaP(i); phiP(i)];
                aVpP(:,i)=(aVp(:,i)-aVp(:,i-1))/samTime;
                aWbP(:,i)=[psiPP(i); thetaPP(i); phiPP(i)];  
         end
    end
     Angles=[psii',theta',phi'];
end



