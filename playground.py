# constans port numbers, import module 


import numpy as np



q_ref=np.zeros(6)
q_sensor=np.zeros(6)

print(q_ref)
isUP= np.sign(q_ref)>0
magnitude= abs(q_ref)

print(isUP)

previus=isUP
print(type(previus))
isUP=np.array([True, False, True, False, False, False ])
update= isUP!= previus

for k in range(6):
    if (update[k]):
        # flip  
        print(k, " fliped")
        # turn off the other PWM

previus=isUP