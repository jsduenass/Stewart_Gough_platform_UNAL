% Build PCM Operating System 

tgs = xpctarget.targets;
tgs.makeDefault('TargetPC1');
env= tgs.Item('TargetPC1')
env.TcpIpTargetAddress = '192.168.0.12';
env.TcpIpSubNetMask = '255.255.255.0';
env.TcpIpTargetPort='22222'

env.TargetBoot='StandAlone'

env.TargetBoot='StandAlone'
env.TargetBoot='DOSLoader'

dirName='../bin/PCM-4153-SBC-OS'
set(env, 'DOSLoaderLocation',dirName)
xpcbootdisk

%xpcnetboot 


