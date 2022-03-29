% Build PCM Operating System 

tgs=xpctarget.targets
env= tgs.Item('TargetPC2')
env.TargetBoot='StandAlone'
env.TargetBoot='DOSLoader'

dirName='../bin/PCM-4153-SBC-OS'
set(env, 'DOSLoaderLocation',dirName)
xpcbootdisk

%xpcnetboot 


