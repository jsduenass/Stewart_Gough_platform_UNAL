% Build PCM Operating System 
tgs = xpctarget.targets;
env = tgs.Item('TargetPC1');
env.TcpIpTargetAddress = '168.176.26.12';
env.TcpIpGateway = '168.176.26.1';
env.TcpIpSubNetMask = '255.255.254.0';
env.TcpIpTargetPort='22222'

env.TargetBoot = 'DOSLoader'; % BootFloppy, CDBoot, DOSLoader, NetworkBoot, StandAlone

dirName='../bin/PCM-4153-SBC-OS';
env.DOSLoaderLocation=dirName;

getxpcenv                               % Enviroment properties

xpcbootdisk
%xpcnetboot 


