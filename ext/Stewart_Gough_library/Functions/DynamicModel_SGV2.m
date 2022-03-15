function [aSi,d,Efector,Time] = DynamicModel_SGV2 (Trajectory,SGin,varargin)
% Position analysis
%TRAJECTORY


if (isfield(Trajectory,'Circle'))
    [aPb,aRb,aVp,aWb,aVpP,aWbP,Angles,Time] = Circle_Primitive (Trajectory.Circle,Trajectory.Zs(1),Trajectory.IniAngle,Trajectory.Zs(2),Trajectory.FinalAngle,Trajectory.Time,Trajectory.samTime);    
else
    [aPb,aRb,aVp,aWb,aVpP,aWbP,Angles,Time] = TrajectoryGeneratorSG( Trajectory.IniPos,Trajectory.IniAngle,Trajectory.FinalPos,Trajectory.FinalAngle, Trajectory.Time,Trajectory.samTime,Trajectory.interpolation);
end
nSamples=size(Time,2);
Efector.aPb=aPb;
Efector.aRb=aRb;
Efector.aVp=aVp;
Efector.aWb=aWb;
Efector.aVpP=aVpP;
Efector.aWbP=aWbP;
Efector.Angles=Angles;
%Graficas angulos posicion final, trayectoria en el espacio
%clear tmp* i;
%TEST
% for i=1:nSamples
%     hV1 = plotVector([0;0;0],aPb(:,i),'g',2.0);
%     hV1 = plotVector(aPb(:,i),aVp(:,i),'r',2.0);
% end
%% PARAMETERS
%SGin.A1=SGin.A1/2;          %Angle between joints from equi distant point between them
%SGin.A2=SGin.A2/2;          %Angle between joints from equi distant point between them

tmpAngl=[SGin.A1;120-SGin.A1;120+SGin.A1;240-SGin.A1;240+SGin.A1;360-SGin.A1]*pi/180; %Angular arrangement of joints
%tmpAngl=[10;110;130;230;250;350]*pi/180;
tmpRadBase=SGin.RadBase;

aA(3,6)=0;
for i=1:6
    aA(:,i)=[sin(tmpAngl(i))*tmpRadBase;cos(tmpAngl(i))*tmpRadBase; SGin.L1];
end
Efector.ai=aA;


tmpAngl=[60-SGin.A2;60+SGin.A2;180-SGin.A2;180+SGin.A2;300-SGin.A2;300+SGin.A2]*pi/180;
%tmpAngl=[45;75;165;195;285;315]*pi/180;

tmpRadBase=SGin.RadMovile;
bB(3,6)=0;
for i=1:6
    bB(:,i)=[sin(tmpAngl(i))*tmpRadBase;cos(tmpAngl(i))*tmpRadBase; -SGin.L2]; %Distance from frame B to joint bi. From reference frame B       
end
Efector.bi=bB;
%clear tmp* i;
%% Position analysis
for j=1:nSamples
    tmpMovingT=[aRb(:,:,j) aPb(:,j); 0 0 0 1];
    %set(SG(12),'matrix',tmpMovingT);  
    % Calculate d, aSi and the rotation matrix for each limb
    d(6,nSamples)=0;
    aSi(3,6,nSamples)=0;
    aRci(3,3,6,nSamples)=0;
    for i=1:6        
        d(i,j)=norm(aA(:,i)-aPb(:,j)-aRb(:,:,j)*bB(:,i),2);
        aSi(:,i,j)=-(aA(:,i)-aPb(:,j)-aRb(:,:,j)*bB(:,i))/d(i,j);
        W=aSi(:,i,j);
        V=cross([0;0;1],W);
        V=V/norm(V);
        U=cross(V,W);
        aRci(:,:,i,j)=[U V W];
    end
    e2=(169.19+17+38)*1e-3; %Distance from B to center of mass piston along S axis
    e1=(151.32+17+38)*1e-3; %Distance from A to center of mass cylinder along S axis
end

%%
% %% Velocity analysis
% for j=1:nSamples
%     for i=1:6
%         ciSi=[0;0;1];
%         aVbi(:,i,j)=aVp(:,j)+cross(aWb(:,j),aRb(:,:,j)*bB(:,i));
%         ciRa(:,:,i,j)=aRci(:,:,i,j)';
%         ciVbi(:,i,j)=ciRa(:,:,i,j)*aVbi(:,i,j);
%         dP(i,j)=ciVbi(3,i,j);                       %% Actuator velocity
%         ciWi(:,i,j)=cross(ciSi,ciVbi(:,i,j))/d(i,j);
%         ciV1(:,i,j)=e1*cross(ciWi(:,i,j),ciSi);
%         ciV2(:,i,j)=(d(i,j)-e2)*cross(ciWi(:,i,j),ciSi)+dP(i,j)*ciSi;
%     end
% end
% 
% %% Acceleration analysis   
% for j=1:nSamples
%     for i=1:6
%         aVbiP(:,i,j)=aVpP(:,j)+cross(aWbP(:,j),aRb(:,:,j)*bB(:,i))+cross(aWb(:,j),cross(aWb(:,j),aRb(:,:,j)*bB(:,i)));
%         ciVbiP(:,i,j)=ciRa(:,:,i,j)*aVbiP(:,i,j);
%         dPP(i,j)=ciVbiP(3,i,j)+(ciVbi(1,i,j)^2+ciVbi(2,i,j)^2)/d(i,j);
%         ciWiP(:,i,j)=cross(ciSi,ciVbiP(:,i,j))/d(i,j)-(2*dP(i,j)/d(i,j))*ciWi(:,i,j);
%         ciV1P(:,i,j)=e1*cross(ciWiP(:,i,j),ciSi)+e1*cross(ciWi(:,i,j),cross(ciWi(:,i,j),ciSi));
%         ciV2P(:,i,j)=dPP(i,j)*ciSi+(d(i,j)-e2)*cross(ciWiP(:,i,j),ciSi)+(d(i,j)-e2)*cross(ciWi(:,i,j),cross(ciWi(:,i,j),ciSi))+2*dP(i,j)*cross(ciWi(:,i,j),ciSi);
%     end
% end
% %% Jerk
% for j=1:nSamples
%     for i=1:6
%         if j==1
%             dPPP(:,j)=zeros(6,1);
%         else
%             dPPP(i,j)=(dPP(i,j)-dPP(i,j-1))/Trajectory.samTime;
%         end
%         
%     end
% end

%% Plot: Length, Velocity and aceleration of each actuador
% close all
% figure
% hold on, grid on
% title(['Efector´s position (Max length: 0.5080+?? Mts)'])
% plot(Time,aPb(1,:),'r');
% plot(Time,aPb(2,:),'g');
% plot(Time,aPb(3,:),'b');
% legend('x', 'y' ,'z')
% xlabel('Time(s)')
% ylabel('Mts')
% 
% figure
% title(['Efector´s velocity. (Max Speed: 0.0508 Mts/S)'])
% hold on, grid on
% plot(Time,aVp(1,:),'r');
% plot(Time,aVp(2,:),'g');
% plot(Time,aVp(3,:),'b');
% legend('x', 'y' ,'z')
% xlabel('Time(s)')
% ylabel('Mts/Sec')
% 
% figure
% hold on, grid on
% title(['Efector´s acceleration'])
% plot(Time,aVpP(1,:),'r');
% plot(Time,aVpP(2,:),'g');
% plot(Time,aVpP(3,:),'b');
% legend('x', 'y' ,'z')
% xlabel('Time(s)')
% ylabel('Mts/Sec^2')
% 
% for i=1:6
%     figure
%     set(gcf,'windowstyle','docked');
%     subplot(3,1,1)
%     hold on, grid on
%     title(['Analysis actuator ',int2str(i)])
%     plot(Time,d(i,:),'r');
%     legend('Length')
%     xlabel('Time(s)')
%     ylabel('Mts')
% 
%     subplot(3,1,2)
%     hold on, grid on,
%     plot(Time,dP(i,:),'g');
%     plot(Time,0.0508,'r')
%     plot(Time,-0.0508,'r')
%     legend('Velocity')
%     xlabel('Time (s)')
%     ylabel('Mts/Sec')
% 
%     subplot(3,1,3)
%     hold on, grid on,
%     plot(Time,dPP(i,:),'b');
%     legend('Acceleration')
%     xlabel('Time (s)')
%     ylabel('Mts/Sec^2')
% end
% %% Inertia tensors
% %Inertia tensor - actuator cylinder
% tmpI1= 90167.100126;   % 	 g-cm^2
% tmpI2= 86370.188459;   %	 g-cm^2 
% tmpI3= 6117.167940; 	%    g-cm^2
% tmpIe1=[tmpI1 0 0;
%        0 tmpI2 0;
%        0 0 tmpI3]/10000/1000; %New units Kg M2
% tmpSRP=[0 0.074561 0.997216; 1 0 0; 0 0.997216 -0.074561];   
% tmpCiRs=[0 0 -1; -1 0 0; 0 1 0]';
% tmpCiRP=tmpCiRs*tmpSRP;
% ciIe1=tmpCiRP*tmpIe1*tmpCiRP';  %Review page 383 for further explanation on transformation of inertia matrix
% 
% %Inertia tensor - actuator rod
% tmpI1= 0.003268;    % 	 Kg-m^2
% tmpI2= 0.003268;    %	 Kg-m^2 
% tmpI3= 0.000015; 	%    Kg-m^2
% tmpIe2=[tmpI1 0 0;
%        0 tmpI2 0;
%        0 0 tmpI3]; % units Kg M2
% tmpSRP=[0 0 1; 1 0 0; 0 1 0];   
% tmpCiRs=[0 0 -1; -1 0 0; 0 1 0]';
% tmpCiRP=tmpCiRs*tmpSRP;
% ciIe2=tmpCiRP*tmpIe2*tmpCiRP';
% 
% %clear tmp*;
% %% Dynamic analysis
% % m2=0.304942;            %Kg
% % m1= 1010.189514/1000;   %Kg 
% % aG=[0;0;-9.8];          %m/s^2
% % j=500;
% % for i=1:6
% %     %Angular momentum derivative
% %     ciHaDt(:,i,j)=m1*e1*cross(ciSi,ciV1P(:,i,j))+m2*dP(i,j)*cross(ciSi,ciV1(:,i,j))...
% %                 +m2*(d(i,j)-e2)*cross(ciSi,ciV2P(:,i,j))+ciIe1*ciWiP(:,i,j)...
% %                 +cross(ciWi(:,i,j),(ciIe1*ciWi(:,i,j)))+ciIe2*ciWiP(:,i,j)...
% %                 +cross(ciWi(:,i,j),(ciIe2*ciWi(:,i,j)));
% %     tmpA=(m1*e1+m2*(d(i,j)-e2))*cross(ciSi,ciRa(:,:,i,j)*aG);
% %     %Limb forces except Z
% %     ciFbiy(i,j)=ciHaDt(1,i,j)/d(i,j);
% %     ciFbix(i,j)=(ciHaDt(2,i,j)-tmpA(2))/-d(i,j);
% % end
% % % Z Component
% % syms ciFbiz_1 ciFbiz_2 ciFbiz_3 ciFbiz_4 ciFbiz_5 ciFbiz_6
% % ciFbiz=[ciFbiz_1 ciFbiz_2 ciFbiz_3 ciFbiz_4 ciFbiz_5 ciFbiz_6];
% % ciFb=zeros(3,1);
% % ciFbz(3,1)=zeros(3,1);
% % for i=1:6
% %     ciFbz(3,1)=ciFbz(3,1)+ciFbiz(i);
% %     ciFb(1,1)=ciFb(1,1)+ciFbix(i,j);
% %     ciFb(2,1)=ciFb(2,1)+ciFbiy(i,j);    
% % end
% % ciFbi=[ciFb(1) ciFb(2) ciFbz(3)];
% 
% 
% 
% 




