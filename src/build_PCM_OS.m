% Build PCM Operating System 

tgs = xpctarget.targets;
env= tgs.Item('TargetPC1')
env.TcpIpTargetAddress = '192.168.0.12';
env.TcpIpGateway = '192.168.0.1';
env.TcpIpSubNetMask = '255.255.255.0';
env.TcpIpTargetPort='22222'

env.TargetBoot = 'BootFloppy';
env.TargetBoot = 'CDBoot';
env.TargetBoot = 'DOSLoader';


dirName='../bin/PCM-4153-SBC-OS';
env.DOSLoaderLocation=dirName;

getxpcenv                               % Enviroment properties

xpcbootdisk

%xpcnetboot 


