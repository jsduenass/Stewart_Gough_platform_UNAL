--------------This folder includes the source code and explanation for the dynamic modeling for a Linear Actuator-------------


-- 1	Open the folder "\potenti2position\" to identify the relation among measured voltage at the motor's potentiometer and linear position of the actuator's rod.

-- 2	Use the values you have found on the previous steps for identification.
	2.1	Open the file "\XPC_Code\IdentificationMotor2Order.mdl".
	2.2	Right-click the red block "SG-ADC Sensors", click "look under mask".
	2.3	Double-click the block "Signal Filtering and scaling".
	2.4	Modify the values you have measured for the specific channel you are measuring. For instance, if your actuator is connected to channel 3, modify the values of "Gain8" and "Constan3".

-- 3	Get ready for the identification algorithm to build and execute.
	3.1	Set your local IP address to ensure a connection to your target PC, test it with the command "!ping " at the command prompt in matlab.
	3.2	Open the electric panel and set motor position manually, set motor position to approximately half its length.
	3.3	Make sure your Current Folder in matlab is located at "...\ActuatorIdentification\".
	3.4	Deactivate Dropbox syncing if your folder "...\ActuatorIdentification\" is located within the Dropbox folder.
-- 4	Run the identification algorithm "MainIdentification2Order.m".