/*
 * IdentificationMotor2Order_capi.c
 *
 * Code generation for model "IdentificationMotor2Order.mdl".
 *
 * Model version              : 1.118
 * Simulink Coder version : 8.0 (R2011a) 09-Mar-2011
 * C source code generated on : Mon Jan 31 16:04:55 2022
 *
 * Target selection: xpctarget.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IdentificationMotor2Order.h"
#include "rtw_capi.h"
#include "IdentificationMotor2Order_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Velocity reference2",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Gain",
    "ControlSignal2", 0, 0, 0, 0, 0 },

  { 2, 0, "Motors - F4  STM - PWM/Merge",
    "", 0, 0, 0, 0, 0 },

  { 3, 0, "Motors - F4  STM - PWM/Merge1",
    "", 0, 0, 0, 0, 0 },

  { 4, 0, "Motors - F4  STM - PWM/Merge2",
    "", 0, 0, 0, 0, 0 },

  { 5, 0, "Motors - F4  STM - PWM/Merge3",
    "", 0, 0, 0, 0, 0 },

  { 6, 0, "Motors - F4  STM - PWM/Merge4",
    "", 0, 0, 0, 0, 0 },

  { 7, 0, "Motors - F4  STM - PWM/Merge5",
    "", 0, 0, 0, 0, 0 },

  { 8, 0, "Motors - F4  STM - PWM/Saturation",
    "", 0, 0, 0, 0, 0 },

  { 9, 0, "Motors - F4  STM - PWM/Saturation1",
    "", 0, 0, 0, 0, 0 },

  { 10, 0, "Motors - F4  STM - PWM/Saturation2",
    "", 0, 0, 0, 0, 0 },

  { 11, 0, "Motors - F4  STM - PWM/Saturation3",
    "", 0, 0, 0, 0, 0 },

  { 12, 0, "Motors - F4  STM - PWM/Saturation4",
    "", 0, 0, 0, 0, 0 },

  { 13, 0, "Motors - F4  STM - PWM/Saturation5",
    "", 0, 0, 0, 0, 0 },

  { 14, 0, "Motors - F4  STM - PWM/ASCII Encode ",
    "", 0, 1, 1, 0, 0 },

  { 15, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p1",
    "", 0, 0, 0, 0, 0 },

  { 16, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p2",
    "", 1, 0, 0, 0, 0 },

  { 17, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p3",
    "", 2, 0, 0, 0, 0 },

  { 18, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p4",
    "", 3, 0, 0, 0, 0 },

  { 19, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p5",
    "", 4, 0, 0, 0, 0 },

  { 20, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p6",
    "", 5, 0, 0, 0, 0 },

  { 21, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p7",
    "", 6, 0, 0, 0, 0 },

  { 22, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p8",
    "", 7, 0, 0, 0, 0 },

  { 23, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p9",
    "", 8, 0, 0, 0, 0 },

  { 24, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p10",
    "", 9, 0, 0, 0, 0 },

  { 25, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p11",
    "", 10, 0, 0, 0, 0 },

  { 26, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p12",
    "", 11, 0, 0, 0, 0 },

  { 27, 0, "Motors - F4  STM - PWM/Baseboard Serial1/Rate Transition",
    "", 0, 2, 0, 0, 1 },

  { 28, 0, "Motors - F4  STM - PWM/Baseboard Serial1/Rate Transition1",
    "", 0, 2, 0, 0, 0 },

  { 29, 0, "Motors - F4  STM - PWM/Baseboard Serial1/Rate Transition2",
    "", 0, 2, 0, 0, 1 },

  { 30, 0, "Motors - F4  STM - PWM/Baseboard Serial1/Rate Transition3",
    "", 0, 2, 0, 0, 0 },

  { 31, 0, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "", 0, 3, 2, 0, 0 },

  { 32, 0, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "", 0, 3, 2, 0, 0 },

  { 33, 0, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1/p1",
    "", 0, 2, 0, 0, 0 },

  { 34, 0, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1/p2",
    "", 1, 4, 0, 0, 0 },

  { 35, 0, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2/p1",
    "", 0, 2, 0, 0, 0 },

  { 36, 0, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2/p2",
    "", 1, 4, 0, 0, 0 },

  { 37, 0, "Motors - F4  STM - PWM/If Action Subsystem/Rounding Function",
    "", 0, 0, 0, 0, 0 },

  { 38, 6, "Motors - F4  STM - PWM/If Action Subsystem/Sum",
    "", 0, 0, 0, 0, 0 },

  { 39, 7, "Motors - F4  STM - PWM/If Action Subsystem1/Gain",
    "", 0, 0, 0, 0, 0 },

  { 40, 0, "Motors - F4  STM - PWM/If Action Subsystem1/Rounding Function",
    "", 0, 0, 0, 0, 0 },

  { 41, 7, "Motors - F4  STM - PWM/If Action Subsystem1/Sum",
    "", 0, 0, 0, 0, 0 },

  { 42, 0, "Motors - F4  STM - PWM/If Action Subsystem10/Rounding Function",
    "", 0, 0, 0, 0, 0 },

  { 43, 8, "Motors - F4  STM - PWM/If Action Subsystem10/Sum",
    "", 0, 0, 0, 0, 0 },

  { 44, 9, "Motors - F4  STM - PWM/If Action Subsystem11/Gain",
    "", 0, 0, 0, 0, 0 },

  { 45, 0, "Motors - F4  STM - PWM/If Action Subsystem11/Rounding Function",
    "", 0, 0, 0, 0, 0 },

  { 46, 9, "Motors - F4  STM - PWM/If Action Subsystem11/Sum",
    "", 0, 0, 0, 0, 0 },

  { 47, 0, "Motors - F4  STM - PWM/If Action Subsystem2/Rounding Function",
    "", 0, 0, 0, 0, 0 },

  { 48, 10, "Motors - F4  STM - PWM/If Action Subsystem2/Sum",
    "", 0, 0, 0, 0, 0 },

  { 49, 11, "Motors - F4  STM - PWM/If Action Subsystem3/Gain",
    "", 0, 0, 0, 0, 0 },

  { 50, 0, "Motors - F4  STM - PWM/If Action Subsystem3/Rounding Function",
    "", 0, 0, 0, 0, 0 },

  { 51, 11, "Motors - F4  STM - PWM/If Action Subsystem3/Sum",
    "", 0, 0, 0, 0, 0 },

  { 52, 0, "Motors - F4  STM - PWM/If Action Subsystem4/Rounding Function",
    "", 0, 0, 0, 0, 0 },

  { 53, 12, "Motors - F4  STM - PWM/If Action Subsystem4/Sum",
    "", 0, 0, 0, 0, 0 },

  { 54, 13, "Motors - F4  STM - PWM/If Action Subsystem5/Gain",
    "", 0, 0, 0, 0, 0 },

  { 55, 0, "Motors - F4  STM - PWM/If Action Subsystem5/Rounding Function",
    "", 0, 0, 0, 0, 0 },

  { 56, 13, "Motors - F4  STM - PWM/If Action Subsystem5/Sum",
    "", 0, 0, 0, 0, 0 },

  { 57, 0, "Motors - F4  STM - PWM/If Action Subsystem6/Rounding Function",
    "", 0, 0, 0, 0, 0 },

  { 58, 14, "Motors - F4  STM - PWM/If Action Subsystem6/Sum",
    "", 0, 0, 0, 0, 0 },

  { 59, 15, "Motors - F4  STM - PWM/If Action Subsystem7/Gain",
    "", 0, 0, 0, 0, 0 },

  { 60, 0, "Motors - F4  STM - PWM/If Action Subsystem7/Rounding Function",
    "", 0, 0, 0, 0, 0 },

  { 61, 15, "Motors - F4  STM - PWM/If Action Subsystem7/Sum",
    "", 0, 0, 0, 0, 0 },

  { 62, 0, "Motors - F4  STM - PWM/If Action Subsystem8/Rounding Function",
    "", 0, 0, 0, 0, 0 },

  { 63, 16, "Motors - F4  STM - PWM/If Action Subsystem8/Sum",
    "", 0, 0, 0, 0, 0 },

  { 64, 17, "Motors - F4  STM - PWM/If Action Subsystem9/Gain",
    "", 0, 0, 0, 0, 0 },

  { 65, 0, "Motors - F4  STM - PWM/If Action Subsystem9/Rounding Function",
    "", 0, 0, 0, 0, 0 },

  { 66, 17, "Motors - F4  STM - PWM/If Action Subsystem9/Sum",
    "", 0, 0, 0, 0, 0 },

  { 67, 0, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space1",
    "", 0, 0, 0, 0, 0 },

  { 68, 0, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space2",
    "", 0, 0, 0, 0, 0 },

  { 69, 0, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space3",
    "", 0, 0, 0, 0, 0 },

  { 70, 0, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space4",
    "", 0, 0, 0, 0, 0 },

  { 71, 0, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space5",
    "", 0, 0, 0, 0, 0 },

  { 72, 0, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space6",
    "", 0, 0, 0, 0, 0 },

  { 73, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain",
    "", 0, 0, 0, 0, 0 },

  { 74, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain1",
    "", 0, 0, 0, 0, 0 },

  { 75, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain10",
    "", 0, 0, 0, 0, 0 },

  { 76, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain11",
    "", 0, 0, 0, 0, 0 },

  { 77, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain2",
    "", 0, 0, 0, 0, 0 },

  { 78, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain3",
    "", 0, 0, 0, 0, 0 },

  { 79, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain4",
    "", 0, 0, 0, 0, 0 },

  { 80, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain5",
    "", 0, 0, 0, 0, 0 },

  { 81, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain6",
    "", 0, 0, 0, 0, 0 },

  { 82, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain7",
    "", 0, 0, 0, 0, 0 },

  { 83, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain8",
    "", 0, 0, 0, 0, 0 },

  { 84, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain9",
    "", 0, 0, 0, 0, 0 },

  { 85, 0, "SG-ADC Sensors/Signal Filtering and scaling/Sum1",
    "", 0, 0, 0, 0, 0 },

  { 86, 0, "SG-ADC Sensors/Signal Filtering and scaling/Sum2",
    "", 0, 0, 0, 0, 0 },

  { 87, 0, "SG-ADC Sensors/Signal Filtering and scaling/Sum3",
    "", 0, 0, 0, 0, 0 },

  { 88, 0, "SG-ADC Sensors/Signal Filtering and scaling/Sum4",
    "", 0, 0, 0, 0, 0 },

  { 89, 0, "SG-ADC Sensors/Signal Filtering and scaling/Sum5",
    "", 0, 0, 0, 0, 0 },

  { 90, 0, "SG-ADC Sensors/Signal Filtering and scaling/Sum6",
    "", 0, 0, 0, 0, 0 },

  { 91, 5,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Read Int Status FC1/p1",
    "", 0, 5, 0, 0, 1 },

  { 92, 1,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1",
    "", 0, 2, 0, 0, 1 },

  { 93, 1,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/Read HW FIFO1",
    "", 0, 5, 3, 0, 1 },

  { 94, 2,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2",
    "", 0, 2, 0, 0, 1 },

  { 95, 2,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/Read HW FIFO2",
    "", 0, 5, 3, 0, 1 },

  { 96, 3,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1/p1",
    "", 0, 5, 4, 0, 1 },

  { 97, 3,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1/p2",
    "", 1, 5, 0, 0, 1 },

  { 98, 4,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2/p1",
    "", 0, 5, 4, 0, 1 },

  { 99, 4,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2/p2",
    "", 1, 5, 0, 0, 1 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 100, "Constant",
    "Value", 0, 0, 0 },

  { 101, "Constant1",
    "Value", 0, 0, 0 },

  { 102, "Constant2",
    "Value", 0, 0, 0 },

  { 103, "Constant3",
    "Value", 0, 0, 0 },

  { 104, "Constant4",
    "Value", 0, 0, 0 },

  { 105, "Gain",
    "Gain", 0, 0, 0 },

  { 106, "Motors - F4  STM - PWM/Saturation",
    "UpperLimit", 0, 0, 0 },

  { 107, "Motors - F4  STM - PWM/Saturation",
    "LowerLimit", 0, 0, 0 },

  { 108, "Motors - F4  STM - PWM/Saturation1",
    "UpperLimit", 0, 0, 0 },

  { 109, "Motors - F4  STM - PWM/Saturation1",
    "LowerLimit", 0, 0, 0 },

  { 110, "Motors - F4  STM - PWM/Saturation2",
    "UpperLimit", 0, 0, 0 },

  { 111, "Motors - F4  STM - PWM/Saturation2",
    "LowerLimit", 0, 0, 0 },

  { 112, "Motors - F4  STM - PWM/Saturation3",
    "UpperLimit", 0, 0, 0 },

  { 113, "Motors - F4  STM - PWM/Saturation3",
    "LowerLimit", 0, 0, 0 },

  { 114, "Motors - F4  STM - PWM/Saturation4",
    "UpperLimit", 0, 0, 0 },

  { 115, "Motors - F4  STM - PWM/Saturation4",
    "LowerLimit", 0, 0, 0 },

  { 116, "Motors - F4  STM - PWM/Saturation5",
    "UpperLimit", 0, 0, 0 },

  { 117, "Motors - F4  STM - PWM/Saturation5",
    "LowerLimit", 0, 0, 0 },

  { 118, "Motors - F4  STM - PWM/ASCII Encode ",
    "P1", 0, 5, 0 },

  { 119, "Motors - F4  STM - PWM/ASCII Encode ",
    "P2", 0, 0, 0 },

  { 120, "Motors - F4  STM - PWM/ASCII Encode ",
    "P3", 0, 0, 0 },

  { 121, "Motors - F4  STM - PWM/ASCII Encode ",
    "P4", 0, 6, 0 },

  { 122, "SG-ADC Sensors/MM-16-AT Analog Input",
    "P1", 0, 0, 0 },

  { 123, "SG-ADC Sensors/MM-16-AT Analog Input",
    "P2", 0, 0, 0 },

  { 124, "SG-ADC Sensors/MM-16-AT Analog Input",
    "P3", 0, 0, 0 },

  { 125, "SG-ADC Sensors/MM-16-AT Analog Input",
    "P4", 0, 0, 0 },

  { 126, "SG-ADC Sensors/MM-16-AT Analog Input",
    "P5", 0, 0, 0 },

  { 127, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P1", 0, 0, 0 },

  { 128, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P2", 0, 0, 0 },

  { 129, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P3", 0, 0, 0 },

  { 130, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P4", 0, 0, 0 },

  { 131, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P5", 0, 0, 0 },

  { 132, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P6", 0, 0, 0 },

  { 133, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P7", 0, 0, 0 },

  { 134, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P8", 0, 0, 0 },

  { 135, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P1", 0, 0, 0 },

  { 136, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P2", 0, 0, 0 },

  { 137, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P3", 0, 0, 0 },

  { 138, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P4", 0, 0, 0 },

  { 139, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P5", 0, 0, 0 },

  { 140, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P6", 0, 0, 0 },

  { 141, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P7", 0, 0, 0 },

  { 142, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P8", 0, 0, 0 },

  { 143, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1",
    "P1", 0, 0, 0 },

  { 144, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1",
    "P2", 0, 0, 0 },

  { 145, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1",
    "P3", 0, 0, 0 },

  { 146, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1",
    "P4", 0, 0, 0 },

  { 147, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1",
    "P5", 0, 7, 0 },

  { 148, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2",
    "P1", 0, 0, 0 },

  { 149, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2",
    "P2", 0, 0, 0 },

  { 150, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2",
    "P3", 0, 0, 0 },

  { 151, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2",
    "P4", 0, 0, 0 },

  { 152, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2",
    "P5", 0, 7, 0 },

  { 153, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P1", 0, 0, 0 },

  { 154, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P2", 0, 0, 0 },

  { 155, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P3", 0, 0, 0 },

  { 156, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P4", 0, 0, 0 },

  { 157, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P5", 0, 0, 0 },

  { 158, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P6", 0, 0, 0 },

  { 159, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P7", 0, 0, 0 },

  { 160, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P8", 0, 0, 0 },

  { 161, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P1", 0, 0, 0 },

  { 162, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P2", 0, 0, 0 },

  { 163, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P3", 0, 0, 0 },

  { 164, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P4", 0, 0, 0 },

  { 165, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P5", 0, 0, 0 },

  { 166, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P6", 0, 0, 0 },

  { 167, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P7", 0, 0, 0 },

  { 168, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P8", 0, 0, 0 },

  { 169, "Motors - F4  STM - PWM/If Action Subsystem/Constant8",
    "Value", 0, 0, 0 },

  { 170, "Motors - F4  STM - PWM/If Action Subsystem1/Constant8",
    "Value", 0, 0, 0 },

  { 171, "Motors - F4  STM - PWM/If Action Subsystem1/Gain",
    "Gain", 0, 0, 0 },

  { 172, "Motors - F4  STM - PWM/If Action Subsystem10/Constant8",
    "Value", 0, 0, 0 },

  { 173, "Motors - F4  STM - PWM/If Action Subsystem11/Constant8",
    "Value", 0, 0, 0 },

  { 174, "Motors - F4  STM - PWM/If Action Subsystem11/Gain",
    "Gain", 0, 0, 0 },

  { 175, "Motors - F4  STM - PWM/If Action Subsystem2/Constant8",
    "Value", 0, 0, 0 },

  { 176, "Motors - F4  STM - PWM/If Action Subsystem3/Constant8",
    "Value", 0, 0, 0 },

  { 177, "Motors - F4  STM - PWM/If Action Subsystem3/Gain",
    "Gain", 0, 0, 0 },

  { 178, "Motors - F4  STM - PWM/If Action Subsystem4/Constant8",
    "Value", 0, 0, 0 },

  { 179, "Motors - F4  STM - PWM/If Action Subsystem5/Constant8",
    "Value", 0, 0, 0 },

  { 180, "Motors - F4  STM - PWM/If Action Subsystem5/Gain",
    "Gain", 0, 0, 0 },

  { 181, "Motors - F4  STM - PWM/If Action Subsystem6/Constant8",
    "Value", 0, 0, 0 },

  { 182, "Motors - F4  STM - PWM/If Action Subsystem7/Constant8",
    "Value", 0, 0, 0 },

  { 183, "Motors - F4  STM - PWM/If Action Subsystem7/Gain",
    "Gain", 0, 0, 0 },

  { 184, "Motors - F4  STM - PWM/If Action Subsystem8/Constant8",
    "Value", 0, 0, 0 },

  { 185, "Motors - F4  STM - PWM/If Action Subsystem9/Constant8",
    "Value", 0, 0, 0 },

  { 186, "Motors - F4  STM - PWM/If Action Subsystem9/Gain",
    "Gain", 0, 0, 0 },

  { 187, "SG-ADC Sensors/Signal Filtering and scaling/Constant1",
    "Value", 0, 0, 0 },

  { 188, "SG-ADC Sensors/Signal Filtering and scaling/Constant2",
    "Value", 0, 0, 0 },

  { 189, "SG-ADC Sensors/Signal Filtering and scaling/Constant3",
    "Value", 0, 0, 0 },

  { 190, "SG-ADC Sensors/Signal Filtering and scaling/Constant4",
    "Value", 0, 0, 0 },

  { 191, "SG-ADC Sensors/Signal Filtering and scaling/Constant5",
    "Value", 0, 0, 0 },

  { 192, "SG-ADC Sensors/Signal Filtering and scaling/Constant6",
    "Value", 0, 0, 0 },

  { 193, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space1",
    "A", 0, 8, 0 },

  { 194, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space1",
    "B", 0, 9, 0 },

  { 195, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space1",
    "C", 0, 9, 0 },

  { 196, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space1",
    "D", 0, 0, 0 },

  { 197, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space1",
    "X0", 0, 10, 0 },

  { 198, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space2",
    "A", 0, 8, 0 },

  { 199, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space2",
    "B", 0, 9, 0 },

  { 200, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space2",
    "C", 0, 9, 0 },

  { 201, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space2",
    "D", 0, 0, 0 },

  { 202, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space2",
    "X0", 0, 10, 0 },

  { 203, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space3",
    "A", 0, 8, 0 },

  { 204, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space3",
    "B", 0, 9, 0 },

  { 205, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space3",
    "C", 0, 9, 0 },

  { 206, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space3",
    "D", 0, 0, 0 },

  { 207, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space3",
    "X0", 0, 10, 0 },

  { 208, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space4",
    "A", 0, 8, 0 },

  { 209, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space4",
    "B", 0, 9, 0 },

  { 210, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space4",
    "C", 0, 9, 0 },

  { 211, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space4",
    "D", 0, 0, 0 },

  { 212, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space4",
    "X0", 0, 10, 0 },

  { 213, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space5",
    "A", 0, 8, 0 },

  { 214, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space5",
    "B", 0, 9, 0 },

  { 215, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space5",
    "C", 0, 9, 0 },

  { 216, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space5",
    "D", 0, 0, 0 },

  { 217, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space5",
    "X0", 0, 10, 0 },

  { 218, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space6",
    "A", 0, 8, 0 },

  { 219, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space6",
    "B", 0, 9, 0 },

  { 220, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space6",
    "C", 0, 9, 0 },

  { 221, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space6",
    "D", 0, 0, 0 },

  { 222, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space6",
    "X0", 0, 10, 0 },

  { 223, "SG-ADC Sensors/Signal Filtering and scaling/Gain",
    "Gain", 0, 0, 0 },

  { 224, "SG-ADC Sensors/Signal Filtering and scaling/Gain1",
    "Gain", 0, 0, 0 },

  { 225, "SG-ADC Sensors/Signal Filtering and scaling/Gain10",
    "Gain", 0, 0, 0 },

  { 226, "SG-ADC Sensors/Signal Filtering and scaling/Gain11",
    "Gain", 0, 0, 0 },

  { 227, "SG-ADC Sensors/Signal Filtering and scaling/Gain2",
    "Gain", 0, 0, 0 },

  { 228, "SG-ADC Sensors/Signal Filtering and scaling/Gain3",
    "Gain", 0, 0, 0 },

  { 229, "SG-ADC Sensors/Signal Filtering and scaling/Gain4",
    "Gain", 0, 0, 0 },

  { 230, "SG-ADC Sensors/Signal Filtering and scaling/Gain5",
    "Gain", 0, 0, 0 },

  { 231, "SG-ADC Sensors/Signal Filtering and scaling/Gain6",
    "Gain", 0, 0, 0 },

  { 232, "SG-ADC Sensors/Signal Filtering and scaling/Gain7",
    "Gain", 0, 0, 0 },

  { 233, "SG-ADC Sensors/Signal Filtering and scaling/Gain8",
    "Gain", 0, 0, 0 },

  { 234, "SG-ADC Sensors/Signal Filtering and scaling/Gain9",
    "Gain", 0, 0, 0 },

  { 235, "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/Constant",
    "Value", 5, 0, 0 },

  { 236,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1",
    "P1", 0, 0, 0 },

  { 237,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1",
    "P2", 0, 0, 0 },

  { 238,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1",
    "P3", 0, 0, 0 },

  { 239,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1",
    "P4", 0, 0, 0 },

  { 240,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1",
    "P5", 0, 7, 0 },

  { 241, "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/Constant",
    "Value", 5, 0, 0 },

  { 242,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2",
    "P1", 0, 0, 0 },

  { 243,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2",
    "P2", 0, 0, 0 },

  { 244,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2",
    "P3", 0, 0, 0 },

  { 245,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2",
    "P4", 0, 0, 0 },

  { 246,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2",
    "P5", 0, 7, 0 },

  { 247,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/Constant1",
    "Value", 5, 0, 0 },

  { 248,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P1", 0, 0, 0 },

  { 249,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P2", 0, 0, 0 },

  { 250,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P3", 0, 0, 0 },

  { 251,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P4", 0, 0, 0 },

  { 252,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P5", 0, 0, 0 },

  { 253,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P6", 0, 0, 0 },

  { 254,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P7", 0, 0, 0 },

  { 255,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P8", 0, 0, 0 },

  { 256,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/Constant2",
    "Value", 5, 0, 0 },

  { 257,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P1", 0, 0, 0 },

  { 258,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P2", 0, 0, 0 },

  { 259,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P3", 0, 0, 0 },

  { 260,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P4", 0, 0, 0 },

  { 261,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P5", 0, 0, 0 },

  { 262,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P6", 0, 0, 0 },

  { 263,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P7", 0, 0, 0 },

  { 264,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P8", 0, 0, 0 },

  {
    0, NULL, NULL, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, NULL, 0, 0, 0 }
};

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &IdentificationMotor2Order_B.Velocityreference2,/* 0: Signal */
  &IdentificationMotor2Order_B.ControlSignal2,/* 1: Signal */
  &IdentificationMotor2Order_B.Merge,  /* 2: Signal */
  &IdentificationMotor2Order_B.Merge1, /* 3: Signal */
  &IdentificationMotor2Order_B.Merge2, /* 4: Signal */
  &IdentificationMotor2Order_B.Merge3, /* 5: Signal */
  &IdentificationMotor2Order_B.Merge4, /* 6: Signal */
  &IdentificationMotor2Order_B.Merge5, /* 7: Signal */
  &IdentificationMotor2Order_B.Saturation,/* 8: Signal */
  &IdentificationMotor2Order_B.Saturation1,/* 9: Signal */
  &IdentificationMotor2Order_B.Saturation2,/* 10: Signal */
  &IdentificationMotor2Order_B.Saturation3,/* 11: Signal */
  &IdentificationMotor2Order_B.Saturation4,/* 12: Signal */
  &IdentificationMotor2Order_B.Saturation5,/* 13: Signal */
  &IdentificationMotor2Order_B.ASCIIEncode[0],/* 14: Signal */
  &IdentificationMotor2Order_B.MM16ATAnalogInput_o1,/* 15: Signal */
  &IdentificationMotor2Order_B.MM16ATAnalogInput_o2,/* 16: Signal */
  &IdentificationMotor2Order_B.MM16ATAnalogInput_o3,/* 17: Signal */
  &IdentificationMotor2Order_B.MM16ATAnalogInput_o4,/* 18: Signal */
  &IdentificationMotor2Order_B.MM16ATAnalogInput_o5,/* 19: Signal */
  &IdentificationMotor2Order_B.MM16ATAnalogInput_o6,/* 20: Signal */
  &IdentificationMotor2Order_B.MM16ATAnalogInput_o7,/* 21: Signal */
  &IdentificationMotor2Order_B.MM16ATAnalogInput_o8,/* 22: Signal */
  &IdentificationMotor2Order_B.MM16ATAnalogInput_o9,/* 23: Signal */
  &IdentificationMotor2Order_B.MM16ATAnalogInput_o10,/* 24: Signal */
  &IdentificationMotor2Order_B.MM16ATAnalogInput_o11,/* 25: Signal */
  &IdentificationMotor2Order_B.MM16ATAnalogInput_o12,/* 26: Signal */
  &IdentificationMotor2Order_B.RateTransition,/* 27: Signal */
  &IdentificationMotor2Order_B.RateTransition1,/* 28: Signal */
  &IdentificationMotor2Order_B.RateTransition2,/* 29: Signal */
  &IdentificationMotor2Order_B.RateTransition3,/* 30: Signal */
  &IdentificationMotor2Order_B.FIFOread1[0],/* 31: Signal */
  &IdentificationMotor2Order_B.FIFOread2[0],/* 32: Signal */
  &IdentificationMotor2Order_B.FIFOwrite1_o1,/* 33: Signal */
  &IdentificationMotor2Order_B.FIFOwrite1_o2,/* 34: Signal */
  &IdentificationMotor2Order_B.FIFOwrite2_o1,/* 35: Signal */
  &IdentificationMotor2Order_B.FIFOwrite2_o2,/* 36: Signal */
  &IdentificationMotor2Order_B.Merge,  /* 37: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem.Sum,/* 38: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem1.Gain,/* 39: Signal */
  &IdentificationMotor2Order_B.Merge,  /* 40: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem1.Sum,/* 41: Signal */
  &IdentificationMotor2Order_B.Merge5, /* 42: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem10.Sum,/* 43: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem11.Gain,/* 44: Signal */
  &IdentificationMotor2Order_B.Merge5, /* 45: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem11.Sum,/* 46: Signal */
  &IdentificationMotor2Order_B.Merge1, /* 47: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem2.Sum,/* 48: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem3.Gain,/* 49: Signal */
  &IdentificationMotor2Order_B.Merge1, /* 50: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem3.Sum,/* 51: Signal */
  &IdentificationMotor2Order_B.Merge2, /* 52: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem4.Sum,/* 53: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem5.Gain,/* 54: Signal */
  &IdentificationMotor2Order_B.Merge2, /* 55: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem5.Sum,/* 56: Signal */
  &IdentificationMotor2Order_B.Merge3, /* 57: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem6.Sum,/* 58: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem7.Gain,/* 59: Signal */
  &IdentificationMotor2Order_B.Merge3, /* 60: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem7.Sum,/* 61: Signal */
  &IdentificationMotor2Order_B.Merge4, /* 62: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem8.Sum,/* 63: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem9.Gain,/* 64: Signal */
  &IdentificationMotor2Order_B.Merge4, /* 65: Signal */
  &IdentificationMotor2Order_B.IfActionSubsystem9.Sum,/* 66: Signal */
  &IdentificationMotor2Order_B.DiscreteStateSpace1,/* 67: Signal */
  &IdentificationMotor2Order_B.DiscreteStateSpace2,/* 68: Signal */
  &IdentificationMotor2Order_B.DiscreteStateSpace3,/* 69: Signal */
  &IdentificationMotor2Order_B.DiscreteStateSpace4,/* 70: Signal */
  &IdentificationMotor2Order_B.DiscreteStateSpace5,/* 71: Signal */
  &IdentificationMotor2Order_B.DiscreteStateSpace6,/* 72: Signal */
  &IdentificationMotor2Order_B.Gain,   /* 73: Signal */
  &IdentificationMotor2Order_B.Gain1,  /* 74: Signal */
  &IdentificationMotor2Order_B.Gain10, /* 75: Signal */
  &IdentificationMotor2Order_B.Gain11, /* 76: Signal */
  &IdentificationMotor2Order_B.Gain2,  /* 77: Signal */
  &IdentificationMotor2Order_B.Gain3,  /* 78: Signal */
  &IdentificationMotor2Order_B.Gain4,  /* 79: Signal */
  &IdentificationMotor2Order_B.Gain5,  /* 80: Signal */
  &IdentificationMotor2Order_B.Gain6,  /* 81: Signal */
  &IdentificationMotor2Order_B.Gain7,  /* 82: Signal */
  &IdentificationMotor2Order_B.Gain8,  /* 83: Signal */
  &IdentificationMotor2Order_B.Gain9,  /* 84: Signal */
  &IdentificationMotor2Order_B.Sum1,   /* 85: Signal */
  &IdentificationMotor2Order_B.Sum2,   /* 86: Signal */
  &IdentificationMotor2Order_B.Sum3,   /* 87: Signal */
  &IdentificationMotor2Order_B.Sum4,   /* 88: Signal */
  &IdentificationMotor2Order_B.Sum5,   /* 89: Signal */
  &IdentificationMotor2Order_B.Sum6,   /* 90: Signal */
  &IdentificationMotor2Order_B.ReadIntStatusFC1_o2,/* 91: Signal */
  &IdentificationMotor2Order_B.FIFOwrite1,/* 92: Signal */
  &IdentificationMotor2Order_B.ReadHWFIFO1[0],/* 93: Signal */
  &IdentificationMotor2Order_B.FIFOwrite2,/* 94: Signal */
  &IdentificationMotor2Order_B.ReadHWFIFO2[0],/* 95: Signal */
  &IdentificationMotor2Order_B.FIFOread1_o1[0],/* 96: Signal */
  &IdentificationMotor2Order_B.FIFOread1_o2,/* 97: Signal */
  &IdentificationMotor2Order_B.FIFOread2_o1[0],/* 98: Signal */
  &IdentificationMotor2Order_B.FIFOread2_o2,/* 99: Signal */
  &IdentificationMotor2Order_P.Constant_Value,/* 100: Block Parameter */
  &IdentificationMotor2Order_P.Constant1_Value_l,/* 101: Block Parameter */
  &IdentificationMotor2Order_P.Constant2_Value_e,/* 102: Block Parameter */
  &IdentificationMotor2Order_P.Constant3_Value_a,/* 103: Block Parameter */
  &IdentificationMotor2Order_P.Constant4_Value_g,/* 104: Block Parameter */
  &IdentificationMotor2Order_P.Gain_Gain_b,/* 105: Block Parameter */
  &IdentificationMotor2Order_P.Saturation_UpperSat,/* 106: Block Parameter */
  &IdentificationMotor2Order_P.Saturation_LowerSat,/* 107: Block Parameter */
  &IdentificationMotor2Order_P.Saturation1_UpperSat,/* 108: Block Parameter */
  &IdentificationMotor2Order_P.Saturation1_LowerSat,/* 109: Block Parameter */
  &IdentificationMotor2Order_P.Saturation2_UpperSat,/* 110: Block Parameter */
  &IdentificationMotor2Order_P.Saturation2_LowerSat,/* 111: Block Parameter */
  &IdentificationMotor2Order_P.Saturation3_UpperSat,/* 112: Block Parameter */
  &IdentificationMotor2Order_P.Saturation3_LowerSat,/* 113: Block Parameter */
  &IdentificationMotor2Order_P.Saturation4_UpperSat,/* 114: Block Parameter */
  &IdentificationMotor2Order_P.Saturation4_LowerSat,/* 115: Block Parameter */
  &IdentificationMotor2Order_P.Saturation5_UpperSat,/* 116: Block Parameter */
  &IdentificationMotor2Order_P.Saturation5_LowerSat,/* 117: Block Parameter */
  &IdentificationMotor2Order_P.ASCIIEncode_P1[0],/* 118: Block Parameter */
  &IdentificationMotor2Order_P.ASCIIEncode_P2,/* 119: Block Parameter */
  &IdentificationMotor2Order_P.ASCIIEncode_P3,/* 120: Block Parameter */
  &IdentificationMotor2Order_P.ASCIIEncode_P4[0],/* 121: Block Parameter */
  &IdentificationMotor2Order_P.MM16ATAnalogInput_P1,/* 122: Block Parameter */
  &IdentificationMotor2Order_P.MM16ATAnalogInput_P2,/* 123: Block Parameter */
  &IdentificationMotor2Order_P.MM16ATAnalogInput_P3,/* 124: Block Parameter */
  &IdentificationMotor2Order_P.MM16ATAnalogInput_P4,/* 125: Block Parameter */
  &IdentificationMotor2Order_P.MM16ATAnalogInput_P5,/* 126: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P1_b,/* 127: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P2_b,/* 128: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P3_e,/* 129: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P4_e,/* 130: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P5_o,/* 131: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P6_n,/* 132: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P7_o,/* 133: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P8_e,/* 134: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P1_o,/* 135: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P2_m,/* 136: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P3_n,/* 137: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P4_l,/* 138: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P5_h,/* 139: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P6_h,/* 140: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P7_j,/* 141: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P8_l,/* 142: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite1_P1_g,/* 143: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite1_P2_g,/* 144: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite1_P3_i,/* 145: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite1_P4_b,/* 146: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite1_P5_c[0],/* 147: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite2_P1_l,/* 148: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite2_P2_c,/* 149: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite2_P3_d,/* 150: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite2_P4_o,/* 151: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite2_P5_k[0],/* 152: Block Parameter */
  &IdentificationMotor2Order_P.Setup1_P1,/* 153: Block Parameter */
  &IdentificationMotor2Order_P.Setup1_P2,/* 154: Block Parameter */
  &IdentificationMotor2Order_P.Setup1_P3,/* 155: Block Parameter */
  &IdentificationMotor2Order_P.Setup1_P4,/* 156: Block Parameter */
  &IdentificationMotor2Order_P.Setup1_P5,/* 157: Block Parameter */
  &IdentificationMotor2Order_P.Setup1_P6,/* 158: Block Parameter */
  &IdentificationMotor2Order_P.Setup1_P7,/* 159: Block Parameter */
  &IdentificationMotor2Order_P.Setup1_P8,/* 160: Block Parameter */
  &IdentificationMotor2Order_P.Setup2_P1,/* 161: Block Parameter */
  &IdentificationMotor2Order_P.Setup2_P2,/* 162: Block Parameter */
  &IdentificationMotor2Order_P.Setup2_P3,/* 163: Block Parameter */
  &IdentificationMotor2Order_P.Setup2_P4,/* 164: Block Parameter */
  &IdentificationMotor2Order_P.Setup2_P5,/* 165: Block Parameter */
  &IdentificationMotor2Order_P.Setup2_P6,/* 166: Block Parameter */
  &IdentificationMotor2Order_P.Setup2_P7,/* 167: Block Parameter */
  &IdentificationMotor2Order_P.Setup2_P8,/* 168: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem.Constant8_Value,/* 169: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem1.Constant8_Value,/* 170: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem1.Gain_Gain,/* 171: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem10.Constant8_Value,/* 172: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem11.Constant8_Value,/* 173: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem11.Gain_Gain,/* 174: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem2.Constant8_Value,/* 175: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem3.Constant8_Value,/* 176: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem3.Gain_Gain,/* 177: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem4.Constant8_Value,/* 178: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem5.Constant8_Value,/* 179: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem5.Gain_Gain,/* 180: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem6.Constant8_Value,/* 181: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem7.Constant8_Value,/* 182: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem7.Gain_Gain,/* 183: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem8.Constant8_Value,/* 184: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem9.Constant8_Value,/* 185: Block Parameter */
  &IdentificationMotor2Order_P.IfActionSubsystem9.Gain_Gain,/* 186: Block Parameter */
  &IdentificationMotor2Order_P.Constant1_Value,/* 187: Block Parameter */
  &IdentificationMotor2Order_P.Constant2_Value,/* 188: Block Parameter */
  &IdentificationMotor2Order_P.Constant3_Value,/* 189: Block Parameter */
  &IdentificationMotor2Order_P.Constant4_Value,/* 190: Block Parameter */
  &IdentificationMotor2Order_P.Constant5_Value,/* 191: Block Parameter */
  &IdentificationMotor2Order_P.Constant6_Value,/* 192: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace1_A[0],/* 193: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace1_B[0],/* 194: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace1_C[0],/* 195: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace1_D,/* 196: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace1_X0[0],/* 197: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace2_A[0],/* 198: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace2_B[0],/* 199: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace2_C[0],/* 200: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace2_D,/* 201: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace2_X0[0],/* 202: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace3_A[0],/* 203: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace3_B[0],/* 204: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace3_C[0],/* 205: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace3_D,/* 206: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace3_X0[0],/* 207: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace4_A[0],/* 208: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace4_B[0],/* 209: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace4_C[0],/* 210: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace4_D,/* 211: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace4_X0[0],/* 212: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace5_A[0],/* 213: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace5_B[0],/* 214: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace5_C[0],/* 215: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace5_D,/* 216: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace5_X0[0],/* 217: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace6_A[0],/* 218: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace6_B[0],/* 219: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace6_C[0],/* 220: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace6_D,/* 221: Block Parameter */
  &IdentificationMotor2Order_P.DiscreteStateSpace6_X0[0],/* 222: Block Parameter */
  &IdentificationMotor2Order_P.Gain_Gain,/* 223: Block Parameter */
  &IdentificationMotor2Order_P.Gain1_Gain,/* 224: Block Parameter */
  &IdentificationMotor2Order_P.Gain10_Gain,/* 225: Block Parameter */
  &IdentificationMotor2Order_P.Gain11_Gain,/* 226: Block Parameter */
  &IdentificationMotor2Order_P.Gain2_Gain,/* 227: Block Parameter */
  &IdentificationMotor2Order_P.Gain3_Gain,/* 228: Block Parameter */
  &IdentificationMotor2Order_P.Gain4_Gain,/* 229: Block Parameter */
  &IdentificationMotor2Order_P.Gain5_Gain,/* 230: Block Parameter */
  &IdentificationMotor2Order_P.Gain6_Gain,/* 231: Block Parameter */
  &IdentificationMotor2Order_P.Gain7_Gain,/* 232: Block Parameter */
  &IdentificationMotor2Order_P.Gain8_Gain,/* 233: Block Parameter */
  &IdentificationMotor2Order_P.Gain9_Gain,/* 234: Block Parameter */
  &IdentificationMotor2Order_P.Constant_Value_o,/* 235: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite1_P1,/* 236: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite1_P2,/* 237: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite1_P3,/* 238: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite1_P4,/* 239: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite1_P5[0],/* 240: Block Parameter */
  &IdentificationMotor2Order_P.Constant_Value_n,/* 241: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite2_P1,/* 242: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite2_P2,/* 243: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite2_P3,/* 244: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite2_P4,/* 245: Block Parameter */
  &IdentificationMotor2Order_P.FIFOwrite2_P5[0],/* 246: Block Parameter */
  &IdentificationMotor2Order_P.Constant1_Value_j,/* 247: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P1,/* 248: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P2,/* 249: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P3,/* 250: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P4,/* 251: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P5,/* 252: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P6,/* 253: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P7,/* 254: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread1_P8,/* 255: Block Parameter */
  &IdentificationMotor2Order_P.Constant2_Value_c,/* 256: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P1,/* 257: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P2,/* 258: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P3,/* 259: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P4,/* 260: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P5,/* 261: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P6,/* 262: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P7,/* 263: Block Parameter */
  &IdentificationMotor2Order_P.FIFOread2_P8/* 264: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "numeric", "serialfifoptr", 0, 0, sizeof(serialfifoptr), SS_STRUCT, 0, 0 },

  { "unsigned short", "uint16_T", 0, 0, sizeof(uint16_T), SS_UINT16, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 }
};

/* Structure Element Map - use elemMapIndex to access this structure */
static const rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { NULL, 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_VECTOR, 14, 2, 0 },

  { rtwCAPI_VECTOR, 16, 2, 0 },

  { rtwCAPI_VECTOR, 18, 2, 0 },

  { rtwCAPI_VECTOR, 20, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  9,                                   /* 2 */
  1,                                   /* 3 */
  1025,                                /* 4 */
  1,                                   /* 5 */
  65,                                  /* 6 */
  1,                                   /* 7 */
  61,                                  /* 8 */
  1,                                   /* 9 */
  1,                                   /* 10 */
  13,                                  /* 11 */
  1,                                   /* 12 */
  6,                                   /* 13 */
  1,                                   /* 14 */
  20,                                  /* 15 */
  4,                                   /* 16 */
  1,                                   /* 17 */
  2,                                   /* 18 */
  1,                                   /* 19 */
  1,                                   /* 20 */
  2                                    /* 21 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0, -1.0, -2.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[3],
    1, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 100 },

  { rtBlockParameters, 165,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void IdentificationMotor2Order_InitializeDataMapInfo
  (rtModel_IdentificationMotor2Order *IdentificationMotor2Order_rtM
   )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(IdentificationMotor2Order_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(IdentificationMotor2Order_rtM->DataMapInfo.mmi,
                       &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(IdentificationMotor2Order_rtM->DataMapInfo.mmi,
    NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(IdentificationMotor2Order_rtM->DataMapInfo.mmi,
    rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(IdentificationMotor2Order_rtM->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(IdentificationMotor2Order_rtM->DataMapInfo.mmi,
    NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(IdentificationMotor2Order_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(IdentificationMotor2Order_rtM->DataMapInfo.mmi, 0);
}

/* EOF: IdentificationMotor2Order_capi.c */
