-----Identify the relation among measured voltage at the motor's potentiometer and linear position of the actuator's rod-----

Identification of the relation can be done in several ways, the key concept is to gather voltage measurements from the potentiometer and compare them with the actuator position in order to establish a linear function of the two variables.

Voltage measurements can be done with a standard multimeter, however we highly recomend to use the Diamond-MM-16-AT to include wire noise and other posible factors that could modify the expected value at the DAC on the PC-104.

The standard procedure could be resumed as follows.

-- 1 	Open the file "ReadAnalogInput.mdl", buid and run this code in your target PC.
-- 2	Once the code is running, open the electric panel and perform manual motion of the actuator. Make sure to measure its position as accurate as posible.
-- 3	Take at least two diferent measurements, the more data the more accurate will be the fit of your interpolation.
-- 4	Stop the runing code, and extract the measured values of voltage, use the file "GatherData.m" as an example.
-- 5	Interpolate data to a linear function.
-- 6	See file "\Data FA-PO-35-12-12\motor - 2329584.txt" as an example of the results for the actuator with serial number "2329584".