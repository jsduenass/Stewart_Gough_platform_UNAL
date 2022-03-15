/*
 * GUI_User_V1_3_capi.c
 *
 * Code generation for model "GUI_User_V1_3.mdl".
 *
 * Model version              : 1.1042
 * Simulink Coder version : 8.0 (R2011a) 09-Mar-2011
 * C source code generated on : Fri Aug 23 12:32:01 2013
 *
 * Target selection: xpctarget.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GUI_User_V1_3.h"
#include "rtw_capi.h"
#include "GUI_User_V1_3_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Merge",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "If Action Subsystem/Constant",
    "", 0, 0, 0, 0, 0 },

  { 2, 0, "If Action Subsystem/Constant1",
    "", 0, 0, 0, 0, 0 },

  { 3, 0, "If Action Subsystem/Constant2",
    "", 0, 0, 0, 0, 0 },

  { 4, 0, "If Action Subsystem/Constant3",
    "", 0, 0, 0, 0, 0 },

  { 5, 0, "If Action Subsystem/Constant4",
    "", 0, 0, 0, 0, 0 },

  { 6, 0, "If Action Subsystem/Constant5",
    "", 0, 0, 0, 0, 0 },

  { 7, 0, "If Action Subsystem2/Constant",
    "", 0, 0, 0, 0, 0 },

  { 8, 0, "If Action Subsystem2/Constant1",
    "", 0, 0, 0, 0, 0 },

  { 9, 0, "If Action Subsystem2/Constant2",
    "", 0, 0, 0, 0, 0 },

  { 10, 0, "If Action Subsystem2/Constant3",
    "", 0, 0, 0, 0, 0 },

  { 11, 0, "If Action Subsystem2/Constant4",
    "", 0, 0, 0, 0, 0 },

  { 12, 0, "If Action Subsystem2/Constant5",
    "", 0, 0, 0, 0, 0 },

  { 13, 0, "Motors - F4  STM - PWM/Merge",
    "", 0, 0, 1, 0, 0 },

  { 14, 0, "Motors - F4  STM - PWM/Merge1",
    "", 0, 0, 1, 0, 0 },

  { 15, 0, "Motors - F4  STM - PWM/Merge2",
    "", 0, 0, 1, 0, 0 },

  { 16, 0, "Motors - F4  STM - PWM/Merge3",
    "", 0, 0, 1, 0, 0 },

  { 17, 0, "Motors - F4  STM - PWM/Merge4",
    "", 0, 0, 1, 0, 0 },

  { 18, 0, "Motors - F4  STM - PWM/Merge5",
    "", 0, 0, 1, 0, 0 },

  { 19, 0, "Motors - F4  STM - PWM/Saturation",
    "", 0, 0, 1, 0, 0 },

  { 20, 0, "Motors - F4  STM - PWM/Saturation1",
    "", 0, 0, 1, 0, 0 },

  { 21, 0, "Motors - F4  STM - PWM/Saturation2",
    "", 0, 0, 1, 0, 0 },

  { 22, 0, "Motors - F4  STM - PWM/Saturation3",
    "", 0, 0, 1, 0, 0 },

  { 23, 0, "Motors - F4  STM - PWM/Saturation4",
    "", 0, 0, 1, 0, 0 },

  { 24, 0, "Motors - F4  STM - PWM/Saturation5",
    "", 0, 0, 1, 0, 0 },

  { 25, 0, "Motors - F4  STM - PWM/ASCII Encode ",
    "", 0, 1, 2, 0, 0 },

  { 26, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p1",
    "", 0, 0, 1, 0, 0 },

  { 27, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p2",
    "", 1, 0, 1, 0, 0 },

  { 28, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p3",
    "", 2, 0, 1, 0, 0 },

  { 29, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p4",
    "", 3, 0, 1, 0, 0 },

  { 30, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p5",
    "", 4, 0, 1, 0, 0 },

  { 31, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p6",
    "", 5, 0, 1, 0, 0 },

  { 32, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p7",
    "", 6, 0, 1, 0, 0 },

  { 33, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p8",
    "", 7, 0, 1, 0, 0 },

  { 34, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p9",
    "", 8, 0, 1, 0, 0 },

  { 35, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p10",
    "", 9, 0, 1, 0, 0 },

  { 36, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p11",
    "", 10, 0, 1, 0, 0 },

  { 37, 0, "SG-ADC Sensors/MM-16-AT Analog Input/p12",
    "", 11, 0, 1, 0, 0 },

  { 38, 4, "If Action Subsystem6/FeedForwardController/FeeedForward Gain1",
    "", 0, 0, 1, 0, 0 },

  { 39, 4, "If Action Subsystem6/FeedForwardController/FeeedForward Gain10",
    "", 0, 0, 1, 0, 0 },

  { 40, 4, "If Action Subsystem6/FeedForwardController/FeeedForward Gain11",
    "", 0, 0, 1, 0, 0 },

  { 41, 4, "If Action Subsystem6/FeedForwardController/FeeedForward Gain12",
    "", 0, 0, 1, 0, 0 },

  { 42, 4, "If Action Subsystem6/FeedForwardController/FeeedForward Gain2",
    "", 0, 0, 1, 0, 0 },

  { 43, 4, "If Action Subsystem6/FeedForwardController/FeeedForward Gain3",
    "", 0, 0, 1, 0, 0 },

  { 44, 4, "If Action Subsystem6/FeedForwardController/FeeedForward Gain4",
    "", 0, 0, 1, 0, 0 },

  { 45, 4, "If Action Subsystem6/FeedForwardController/FeeedForward Gain5",
    "", 0, 0, 1, 0, 0 },

  { 46, 4, "If Action Subsystem6/FeedForwardController/FeeedForward Gain6",
    "", 0, 0, 1, 0, 0 },

  { 47, 4, "If Action Subsystem6/FeedForwardController/FeeedForward Gain7",
    "", 0, 0, 1, 0, 0 },

  { 48, 4, "If Action Subsystem6/FeedForwardController/FeeedForward Gain8",
    "", 0, 0, 1, 0, 0 },

  { 49, 4, "If Action Subsystem6/FeedForwardController/FeeedForward Gain9",
    "", 0, 0, 1, 0, 0 },

  { 50, 0, "If Action Subsystem6/FeedForwardController/Gain1",
    "", 0, 0, 0, 0, 0 },

  { 51, 0, "If Action Subsystem6/FeedForwardController/Gain3",
    "", 0, 0, 0, 0, 0 },

  { 52, 0, "If Action Subsystem6/FeedForwardController/Gain4",
    "", 0, 0, 0, 0, 0 },

  { 53, 0, "If Action Subsystem6/FeedForwardController/Gain5",
    "", 0, 0, 0, 0, 0 },

  { 54, 0, "If Action Subsystem6/FeedForwardController/Gain6",
    "", 0, 0, 0, 0, 0 },

  { 55, 4, "If Action Subsystem6/FeedForwardController/Gain7",
    "", 0, 0, 1, 0, 0 },

  { 56, 4, "If Action Subsystem6/FeedForwardController/Gain8",
    "", 0, 0, 1, 0, 0 },

  { 57, 4, "If Action Subsystem6/FeedForwardController/Sum1",
    "", 0, 0, 1, 0, 0 },

  { 58, 4, "If Action Subsystem6/FeedForwardController/Sum10",
    "", 0, 0, 1, 0, 0 },

  { 59, 4, "If Action Subsystem6/FeedForwardController/Sum11",
    "", 0, 0, 1, 0, 0 },

  { 60, 4, "If Action Subsystem6/FeedForwardController/Sum12",
    "", 0, 0, 1, 0, 0 },

  { 61, 4, "If Action Subsystem6/FeedForwardController/Sum13",
    "", 0, 0, 1, 0, 0 },

  { 62, 4, "If Action Subsystem6/FeedForwardController/Sum14",
    "", 0, 0, 1, 0, 0 },

  { 63, 4, "If Action Subsystem6/FeedForwardController/Sum15",
    "", 0, 0, 1, 0, 0 },

  { 64, 4, "If Action Subsystem6/FeedForwardController/Sum16",
    "", 0, 0, 1, 0, 0 },

  { 65, 4, "If Action Subsystem6/FeedForwardController/Sum17",
    "", 0, 0, 1, 0, 0 },

  { 66, 4, "If Action Subsystem6/FeedForwardController/Sum18",
    "", 0, 0, 1, 0, 0 },

  { 67, 4, "If Action Subsystem6/FeedForwardController/Sum2",
    "", 0, 0, 1, 0, 0 },

  { 68, 4, "If Action Subsystem6/FeedForwardController/Sum3",
    "", 0, 0, 1, 0, 0 },

  { 69, 4, "If Action Subsystem6/FeedForwardController/Sum4",
    "", 0, 0, 1, 0, 0 },

  { 70, 4, "If Action Subsystem6/FeedForwardController/Sum5",
    "", 0, 0, 1, 0, 0 },

  { 71, 4, "If Action Subsystem6/FeedForwardController/Sum6",
    "", 0, 0, 1, 0, 0 },

  { 72, 4, "If Action Subsystem6/FeedForwardController/Sum7",
    "", 0, 0, 1, 0, 0 },

  { 73, 0, "If Action Subsystem6/FeedForwardController/Sum8",
    "", 0, 0, 0, 0, 0 },

  { 74, 4, "If Action Subsystem6/FeedForwardController/Sum9",
    "", 0, 0, 1, 0, 0 },

  { 75, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole1",
    "", 0, 0, 1, 0, 0 },

  { 76, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole2",
    "", 0, 0, 1, 0, 0 },

  { 77, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole3",
    "", 0, 0, 1, 0, 0 },

  { 78, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole4",
    "", 0, 0, 1, 0, 0 },

  { 79, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole5",
    "", 0, 0, 1, 0, 0 },

  { 80, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole6",
    "", 0, 0, 1, 0, 0 },

  { 81, 4, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain1",
    "", 0, 0, 1, 0, 0 },

  { 82, 4, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain10",
    "", 0, 0, 1, 0, 0 },

  { 83, 4, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain11",
    "", 0, 0, 1, 0, 0 },

  { 84, 4, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain12",
    "", 0, 0, 1, 0, 0 },

  { 85, 4, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain2",
    "", 0, 0, 1, 0, 0 },

  { 86, 4, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain3",
    "", 0, 0, 1, 0, 0 },

  { 87, 4, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain4",
    "", 0, 0, 1, 0, 0 },

  { 88, 4, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain5",
    "", 0, 0, 1, 0, 0 },

  { 89, 4, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain6",
    "", 0, 0, 1, 0, 0 },

  { 90, 4, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain7",
    "", 0, 0, 1, 0, 0 },

  { 91, 4, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain8",
    "", 0, 0, 1, 0, 0 },

  { 92, 4, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain9",
    "", 0, 0, 1, 0, 0 },

  { 93, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Gain1",
    "", 0, 0, 1, 0, 0 },

  { 94, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Gain3",
    "", 0, 0, 1, 0, 0 },

  { 95, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Gain4",
    "", 0, 0, 1, 0, 0 },

  { 96, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Gain5",
    "", 0, 0, 1, 0, 0 },

  { 97, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Gain6",
    "", 0, 0, 1, 0, 0 },

  { 98, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Gain7",
    "", 0, 0, 1, 0, 0 },

  { 99, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Gain8",
    "", 0, 0, 1, 0, 0 },

  { 100, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum1",
    "", 0, 0, 1, 0, 0 },

  { 101, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum10",
    "", 0, 0, 1, 0, 0 },

  { 102, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum11",
    "", 0, 0, 1, 0, 0 },

  { 103, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum12",
    "", 0, 0, 1, 0, 0 },

  { 104, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum13",
    "", 0, 0, 1, 0, 0 },

  { 105, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum14",
    "", 0, 0, 1, 0, 0 },

  { 106, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum15",
    "", 0, 0, 1, 0, 0 },

  { 107, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum16",
    "", 0, 0, 1, 0, 0 },

  { 108, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum17",
    "", 0, 0, 1, 0, 0 },

  { 109, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum18",
    "", 0, 0, 1, 0, 0 },

  { 110, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum2",
    "", 0, 0, 1, 0, 0 },

  { 111, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum3",
    "", 0, 0, 1, 0, 0 },

  { 112, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum4",
    "", 0, 0, 1, 0, 0 },

  { 113, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum5",
    "", 0, 0, 1, 0, 0 },

  { 114, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum6",
    "", 0, 0, 1, 0, 0 },

  { 115, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum7",
    "", 0, 0, 1, 0, 0 },

  { 116, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum8",
    "", 0, 0, 1, 0, 0 },

  { 117, 4, "If Action Subsystem6/Hinf Ganancia Mixta/Sum9",
    "", 0, 0, 1, 0, 0 },

  { 118, 4, "If Action Subsystem6/Referece/From File1",
    "", 0, 1, 3, 0, 0 },

  { 119, 4, "If Action Subsystem6/Referece/Unpack1",
    "", 0, 0, 4, 0, 0 },

  { 120, 0, "Motors - F4  STM - PWM/Baseboard Serial1/Rate Transition",
    "", 0, 2, 1, 0, 1 },

  { 121, 0, "Motors - F4  STM - PWM/Baseboard Serial1/Rate Transition1",
    "", 0, 2, 1, 0, 0 },

  { 122, 0, "Motors - F4  STM - PWM/Baseboard Serial1/Rate Transition2",
    "", 0, 2, 1, 0, 1 },

  { 123, 0, "Motors - F4  STM - PWM/Baseboard Serial1/Rate Transition3",
    "", 0, 2, 1, 0, 0 },

  { 124, 0, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "", 0, 3, 5, 0, 0 },

  { 125, 0, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "", 0, 3, 5, 0, 0 },

  { 126, 0, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1/p1",
    "", 0, 2, 1, 0, 0 },

  { 127, 0, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1/p2",
    "", 1, 4, 1, 0, 0 },

  { 128, 0, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2/p1",
    "", 0, 2, 1, 0, 0 },

  { 129, 0, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2/p2",
    "", 1, 4, 1, 0, 0 },

  { 130, 0, "Motors - F4  STM - PWM/If Action Subsystem/Rounding Function",
    "", 0, 0, 1, 0, 0 },

  { 131, 10, "Motors - F4  STM - PWM/If Action Subsystem/Sum",
    "", 0, 0, 1, 0, 0 },

  { 132, 11, "Motors - F4  STM - PWM/If Action Subsystem1/Gain",
    "", 0, 0, 1, 0, 0 },

  { 133, 0, "Motors - F4  STM - PWM/If Action Subsystem1/Rounding Function",
    "", 0, 0, 1, 0, 0 },

  { 134, 11, "Motors - F4  STM - PWM/If Action Subsystem1/Sum",
    "", 0, 0, 1, 0, 0 },

  { 135, 0, "Motors - F4  STM - PWM/If Action Subsystem10/Rounding Function",
    "", 0, 0, 1, 0, 0 },

  { 136, 12, "Motors - F4  STM - PWM/If Action Subsystem10/Sum",
    "", 0, 0, 1, 0, 0 },

  { 137, 13, "Motors - F4  STM - PWM/If Action Subsystem11/Gain",
    "", 0, 0, 1, 0, 0 },

  { 138, 0, "Motors - F4  STM - PWM/If Action Subsystem11/Rounding Function",
    "", 0, 0, 1, 0, 0 },

  { 139, 13, "Motors - F4  STM - PWM/If Action Subsystem11/Sum",
    "", 0, 0, 1, 0, 0 },

  { 140, 0, "Motors - F4  STM - PWM/If Action Subsystem2/Rounding Function",
    "", 0, 0, 1, 0, 0 },

  { 141, 14, "Motors - F4  STM - PWM/If Action Subsystem2/Sum",
    "", 0, 0, 1, 0, 0 },

  { 142, 15, "Motors - F4  STM - PWM/If Action Subsystem3/Gain",
    "", 0, 0, 1, 0, 0 },

  { 143, 0, "Motors - F4  STM - PWM/If Action Subsystem3/Rounding Function",
    "", 0, 0, 1, 0, 0 },

  { 144, 15, "Motors - F4  STM - PWM/If Action Subsystem3/Sum",
    "", 0, 0, 1, 0, 0 },

  { 145, 0, "Motors - F4  STM - PWM/If Action Subsystem4/Rounding Function",
    "", 0, 0, 1, 0, 0 },

  { 146, 16, "Motors - F4  STM - PWM/If Action Subsystem4/Sum",
    "", 0, 0, 1, 0, 0 },

  { 147, 17, "Motors - F4  STM - PWM/If Action Subsystem5/Gain",
    "", 0, 0, 1, 0, 0 },

  { 148, 0, "Motors - F4  STM - PWM/If Action Subsystem5/Rounding Function",
    "", 0, 0, 1, 0, 0 },

  { 149, 17, "Motors - F4  STM - PWM/If Action Subsystem5/Sum",
    "", 0, 0, 1, 0, 0 },

  { 150, 0, "Motors - F4  STM - PWM/If Action Subsystem6/Rounding Function",
    "", 0, 0, 1, 0, 0 },

  { 151, 18, "Motors - F4  STM - PWM/If Action Subsystem6/Sum",
    "", 0, 0, 1, 0, 0 },

  { 152, 19, "Motors - F4  STM - PWM/If Action Subsystem7/Gain",
    "", 0, 0, 1, 0, 0 },

  { 153, 0, "Motors - F4  STM - PWM/If Action Subsystem7/Rounding Function",
    "", 0, 0, 1, 0, 0 },

  { 154, 19, "Motors - F4  STM - PWM/If Action Subsystem7/Sum",
    "", 0, 0, 1, 0, 0 },

  { 155, 0, "Motors - F4  STM - PWM/If Action Subsystem8/Rounding Function",
    "", 0, 0, 1, 0, 0 },

  { 156, 20, "Motors - F4  STM - PWM/If Action Subsystem8/Sum",
    "", 0, 0, 1, 0, 0 },

  { 157, 21, "Motors - F4  STM - PWM/If Action Subsystem9/Gain",
    "", 0, 0, 1, 0, 0 },

  { 158, 0, "Motors - F4  STM - PWM/If Action Subsystem9/Rounding Function",
    "", 0, 0, 1, 0, 0 },

  { 159, 21, "Motors - F4  STM - PWM/If Action Subsystem9/Sum",
    "", 0, 0, 1, 0, 0 },

  { 160, 0, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space1",
    "", 0, 0, 1, 0, 0 },

  { 161, 0, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space2",
    "", 0, 0, 1, 0, 0 },

  { 162, 0, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space3",
    "", 0, 0, 1, 0, 0 },

  { 163, 0, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space4",
    "", 0, 0, 1, 0, 0 },

  { 164, 0, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space5",
    "", 0, 0, 1, 0, 0 },

  { 165, 0, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space6",
    "", 0, 0, 1, 0, 0 },

  { 166, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain",
    "", 0, 0, 1, 0, 0 },

  { 167, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain1",
    "", 0, 0, 1, 0, 0 },

  { 168, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain10",
    "", 0, 0, 1, 0, 0 },

  { 169, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain11",
    "", 0, 0, 1, 0, 0 },

  { 170, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain2",
    "", 0, 0, 1, 0, 0 },

  { 171, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain3",
    "", 0, 0, 1, 0, 0 },

  { 172, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain4",
    "", 0, 0, 1, 0, 0 },

  { 173, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain5",
    "", 0, 0, 1, 0, 0 },

  { 174, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain6",
    "", 0, 0, 1, 0, 0 },

  { 175, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain7",
    "", 0, 0, 1, 0, 0 },

  { 176, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain8",
    "", 0, 0, 1, 0, 0 },

  { 177, 0, "SG-ADC Sensors/Signal Filtering and scaling/Gain9",
    "", 0, 0, 1, 0, 0 },

  { 178, 0, "SG-ADC Sensors/Signal Filtering and scaling/Sum1",
    "", 0, 0, 1, 0, 0 },

  { 179, 0, "SG-ADC Sensors/Signal Filtering and scaling/Sum2",
    "", 0, 0, 1, 0, 0 },

  { 180, 0, "SG-ADC Sensors/Signal Filtering and scaling/Sum3",
    "", 0, 0, 1, 0, 0 },

  { 181, 0, "SG-ADC Sensors/Signal Filtering and scaling/Sum4",
    "", 0, 0, 1, 0, 0 },

  { 182, 0, "SG-ADC Sensors/Signal Filtering and scaling/Sum5",
    "", 0, 0, 1, 0, 0 },

  { 183, 0, "SG-ADC Sensors/Signal Filtering and scaling/Sum6",
    "", 0, 0, 1, 0, 0 },

  { 184, 3, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain1",
    "", 0, 0, 1, 0, 0 },

  { 185, 3,
    "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain10",
    "", 0, 0, 1, 0, 0 },

  { 186, 3,
    "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain11",
    "", 0, 0, 1, 0, 0 },

  { 187, 3,
    "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain12",
    "", 0, 0, 1, 0, 0 },

  { 188, 3, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain2",
    "", 0, 0, 1, 0, 0 },

  { 189, 3, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain3",
    "", 0, 0, 1, 0, 0 },

  { 190, 3, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain4",
    "", 0, 0, 1, 0, 0 },

  { 191, 3, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain5",
    "", 0, 0, 1, 0, 0 },

  { 192, 3, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain6",
    "", 0, 0, 1, 0, 0 },

  { 193, 3, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain7",
    "", 0, 0, 1, 0, 0 },

  { 194, 3, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain8",
    "", 0, 0, 1, 0, 0 },

  { 195, 3, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain9",
    "", 0, 0, 1, 0, 0 },

  { 196, 3, "If Action Subsystem5/Set1/FeedForwardController/Gain1",
    "", 0, 0, 1, 0, 0 },

  { 197, 3, "If Action Subsystem5/Set1/FeedForwardController/Gain3",
    "", 0, 0, 1, 0, 0 },

  { 198, 3, "If Action Subsystem5/Set1/FeedForwardController/Gain4",
    "", 0, 0, 1, 0, 0 },

  { 199, 3, "If Action Subsystem5/Set1/FeedForwardController/Gain5",
    "", 0, 0, 1, 0, 0 },

  { 200, 3, "If Action Subsystem5/Set1/FeedForwardController/Gain6",
    "", 0, 0, 1, 0, 0 },

  { 201, 3, "If Action Subsystem5/Set1/FeedForwardController/Gain7",
    "", 0, 0, 1, 0, 0 },

  { 202, 3, "If Action Subsystem5/Set1/FeedForwardController/Gain8",
    "", 0, 0, 1, 0, 0 },

  { 203, 0, "If Action Subsystem5/Set1/FeedForwardController/Saturation",
    "", 0, 0, 0, 0, 0 },

  { 204, 0, "If Action Subsystem5/Set1/FeedForwardController/Saturation1",
    "", 0, 0, 0, 0, 0 },

  { 205, 0, "If Action Subsystem5/Set1/FeedForwardController/Saturation2",
    "", 0, 0, 0, 0, 0 },

  { 206, 0, "If Action Subsystem5/Set1/FeedForwardController/Saturation3",
    "", 0, 0, 0, 0, 0 },

  { 207, 0, "If Action Subsystem5/Set1/FeedForwardController/Saturation4",
    "", 0, 0, 0, 0, 0 },

  { 208, 0, "If Action Subsystem5/Set1/FeedForwardController/Saturation5",
    "", 0, 0, 0, 0, 0 },

  { 209, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum1",
    "", 0, 0, 1, 0, 0 },

  { 210, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum10",
    "", 0, 0, 1, 0, 0 },

  { 211, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum11",
    "", 0, 0, 1, 0, 0 },

  { 212, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum12",
    "", 0, 0, 1, 0, 0 },

  { 213, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum13",
    "", 0, 0, 1, 0, 0 },

  { 214, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum14",
    "", 0, 0, 1, 0, 0 },

  { 215, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum15",
    "", 0, 0, 1, 0, 0 },

  { 216, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum16",
    "", 0, 0, 1, 0, 0 },

  { 217, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum17",
    "", 0, 0, 1, 0, 0 },

  { 218, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum18",
    "", 0, 0, 1, 0, 0 },

  { 219, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum2",
    "", 0, 0, 1, 0, 0 },

  { 220, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum3",
    "", 0, 0, 1, 0, 0 },

  { 221, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum4",
    "", 0, 0, 1, 0, 0 },

  { 222, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum5",
    "", 0, 0, 1, 0, 0 },

  { 223, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum6",
    "", 0, 0, 1, 0, 0 },

  { 224, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum7",
    "", 0, 0, 1, 0, 0 },

  { 225, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum8",
    "", 0, 0, 1, 0, 0 },

  { 226, 3, "If Action Subsystem5/Set1/FeedForwardController/Sum9",
    "", 0, 0, 1, 0, 0 },

  { 227, 4, "If Action Subsystem6/FeedForwardController/PID Controller1/Filter",
    "", 0, 0, 1, 0, 0 },

  { 228, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller1/Integrator",
    "", 0, 0, 1, 0, 0 },

  { 229, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller1/Derivative Gain",
    "", 0, 0, 1, 0, 0 },

  { 230, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller1/Filter Coefficient",
    "", 0, 0, 1, 0, 0 },

  { 231, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller1/Integral Gain",
    "", 0, 0, 1, 0, 0 },

  { 232, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller1/Proportional Gain",
    "", 0, 0, 1, 0, 0 },

  { 233, 4, "If Action Subsystem6/FeedForwardController/PID Controller1/Sum",
    "", 0, 0, 1, 0, 0 },

  { 234, 4, "If Action Subsystem6/FeedForwardController/PID Controller1/SumD",
    "", 0, 0, 1, 0, 0 },

  { 235, 4, "If Action Subsystem6/FeedForwardController/PID Controller2/Filter",
    "", 0, 0, 1, 0, 0 },

  { 236, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller2/Integrator",
    "", 0, 0, 1, 0, 0 },

  { 237, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller2/Derivative Gain",
    "", 0, 0, 1, 0, 0 },

  { 238, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller2/Filter Coefficient",
    "", 0, 0, 1, 0, 0 },

  { 239, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller2/Integral Gain",
    "", 0, 0, 1, 0, 0 },

  { 240, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller2/Proportional Gain",
    "", 0, 0, 1, 0, 0 },

  { 241, 4, "If Action Subsystem6/FeedForwardController/PID Controller2/Sum",
    "", 0, 0, 1, 0, 0 },

  { 242, 4, "If Action Subsystem6/FeedForwardController/PID Controller2/SumD",
    "", 0, 0, 1, 0, 0 },

  { 243, 4, "If Action Subsystem6/FeedForwardController/PID Controller3/Filter",
    "", 0, 0, 1, 0, 0 },

  { 244, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller3/Integrator",
    "", 0, 0, 1, 0, 0 },

  { 245, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller3/Derivative Gain",
    "", 0, 0, 1, 0, 0 },

  { 246, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller3/Filter Coefficient",
    "", 0, 0, 1, 0, 0 },

  { 247, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller3/Integral Gain",
    "", 0, 0, 1, 0, 0 },

  { 248, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller3/Proportional Gain",
    "", 0, 0, 1, 0, 0 },

  { 249, 4, "If Action Subsystem6/FeedForwardController/PID Controller3/Sum",
    "", 0, 0, 1, 0, 0 },

  { 250, 4, "If Action Subsystem6/FeedForwardController/PID Controller3/SumD",
    "", 0, 0, 1, 0, 0 },

  { 251, 4, "If Action Subsystem6/FeedForwardController/PID Controller4/Filter",
    "", 0, 0, 1, 0, 0 },

  { 252, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller4/Integrator",
    "", 0, 0, 1, 0, 0 },

  { 253, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller4/Derivative Gain",
    "", 0, 0, 1, 0, 0 },

  { 254, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller4/Filter Coefficient",
    "", 0, 0, 1, 0, 0 },

  { 255, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller4/Integral Gain",
    "", 0, 0, 1, 0, 0 },

  { 256, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller4/Proportional Gain",
    "", 0, 0, 1, 0, 0 },

  { 257, 4, "If Action Subsystem6/FeedForwardController/PID Controller4/Sum",
    "", 0, 0, 1, 0, 0 },

  { 258, 4, "If Action Subsystem6/FeedForwardController/PID Controller4/SumD",
    "", 0, 0, 1, 0, 0 },

  { 259, 4, "If Action Subsystem6/FeedForwardController/PID Controller5/Filter",
    "", 0, 0, 1, 0, 0 },

  { 260, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller5/Integrator",
    "", 0, 0, 1, 0, 0 },

  { 261, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller5/Derivative Gain",
    "", 0, 0, 1, 0, 0 },

  { 262, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller5/Filter Coefficient",
    "", 0, 0, 1, 0, 0 },

  { 263, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller5/Integral Gain",
    "", 0, 0, 1, 0, 0 },

  { 264, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller5/Proportional Gain",
    "", 0, 0, 1, 0, 0 },

  { 265, 4, "If Action Subsystem6/FeedForwardController/PID Controller5/Sum",
    "", 0, 0, 1, 0, 0 },

  { 266, 4, "If Action Subsystem6/FeedForwardController/PID Controller5/SumD",
    "", 0, 0, 1, 0, 0 },

  { 267, 4, "If Action Subsystem6/FeedForwardController/PID Controller6/Filter",
    "", 0, 0, 1, 0, 0 },

  { 268, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller6/Integrator",
    "", 0, 0, 1, 0, 0 },

  { 269, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller6/Derivative Gain",
    "", 0, 0, 1, 0, 0 },

  { 270, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller6/Filter Coefficient",
    "", 0, 0, 1, 0, 0 },

  { 271, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller6/Integral Gain",
    "", 0, 0, 1, 0, 0 },

  { 272, 4,
    "If Action Subsystem6/FeedForwardController/PID Controller6/Proportional Gain",
    "", 0, 0, 1, 0, 0 },

  { 273, 4, "If Action Subsystem6/FeedForwardController/PID Controller6/Sum",
    "", 0, 0, 1, 0, 0 },

  { 274, 4, "If Action Subsystem6/FeedForwardController/PID Controller6/SumD",
    "", 0, 0, 1, 0, 0 },

  { 275, 9,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Read Int Status FC1/p1",
    "", 0, 5, 1, 0, 1 },

  { 276, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Filter",
    "", 0, 0, 1, 0, 0 },

  { 277, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Integrator",
    "", 0, 0, 1, 0, 0 },

  { 278, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Derivative Gain",
    "", 0, 0, 1, 0, 0 },

  { 279, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Filter Coefficient",
    "", 0, 0, 1, 0, 0 },

  { 280, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Integral Gain",
    "", 0, 0, 1, 0, 0 },

  { 281, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Proportional Gain",
    "", 0, 0, 1, 0, 0 },

  { 282, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Sum",
    "", 0, 0, 1, 0, 0 },

  { 283, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/SumD",
    "", 0, 0, 1, 0, 0 },

  { 284, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Filter",
    "", 0, 0, 1, 0, 0 },

  { 285, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Integrator",
    "", 0, 0, 1, 0, 0 },

  { 286, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Derivative Gain",
    "", 0, 0, 1, 0, 0 },

  { 287, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Filter Coefficient",
    "", 0, 0, 1, 0, 0 },

  { 288, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Integral Gain",
    "", 0, 0, 1, 0, 0 },

  { 289, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Proportional Gain",
    "", 0, 0, 1, 0, 0 },

  { 290, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Sum",
    "", 0, 0, 1, 0, 0 },

  { 291, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/SumD",
    "", 0, 0, 1, 0, 0 },

  { 292, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Filter",
    "", 0, 0, 1, 0, 0 },

  { 293, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Integrator",
    "", 0, 0, 1, 0, 0 },

  { 294, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Derivative Gain",
    "", 0, 0, 1, 0, 0 },

  { 295, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Filter Coefficient",
    "", 0, 0, 1, 0, 0 },

  { 296, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Integral Gain",
    "", 0, 0, 1, 0, 0 },

  { 297, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Proportional Gain",
    "", 0, 0, 1, 0, 0 },

  { 298, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Sum",
    "", 0, 0, 1, 0, 0 },

  { 299, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/SumD",
    "", 0, 0, 1, 0, 0 },

  { 300, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Filter",
    "", 0, 0, 1, 0, 0 },

  { 301, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Integrator",
    "", 0, 0, 1, 0, 0 },

  { 302, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Derivative Gain",
    "", 0, 0, 1, 0, 0 },

  { 303, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Filter Coefficient",
    "", 0, 0, 1, 0, 0 },

  { 304, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Integral Gain",
    "", 0, 0, 1, 0, 0 },

  { 305, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Proportional Gain",
    "", 0, 0, 1, 0, 0 },

  { 306, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Sum",
    "", 0, 0, 1, 0, 0 },

  { 307, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/SumD",
    "", 0, 0, 1, 0, 0 },

  { 308, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Filter",
    "", 0, 0, 1, 0, 0 },

  { 309, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Integrator",
    "", 0, 0, 1, 0, 0 },

  { 310, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Derivative Gain",
    "", 0, 0, 1, 0, 0 },

  { 311, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Filter Coefficient",
    "", 0, 0, 1, 0, 0 },

  { 312, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Integral Gain",
    "", 0, 0, 1, 0, 0 },

  { 313, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Proportional Gain",
    "", 0, 0, 1, 0, 0 },

  { 314, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Sum",
    "", 0, 0, 1, 0, 0 },

  { 315, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/SumD",
    "", 0, 0, 1, 0, 0 },

  { 316, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Filter",
    "", 0, 0, 1, 0, 0 },

  { 317, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Integrator",
    "", 0, 0, 1, 0, 0 },

  { 318, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Derivative Gain",
    "", 0, 0, 1, 0, 0 },

  { 319, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Filter Coefficient",
    "", 0, 0, 1, 0, 0 },

  { 320, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Integral Gain",
    "", 0, 0, 1, 0, 0 },

  { 321, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Proportional Gain",
    "", 0, 0, 1, 0, 0 },

  { 322, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Sum",
    "", 0, 0, 1, 0, 0 },

  { 323, 3,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/SumD",
    "", 0, 0, 1, 0, 0 },

  { 324, 5,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1",
    "", 0, 2, 1, 0, 1 },

  { 325, 5,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/Read HW FIFO1",
    "", 0, 5, 6, 0, 1 },

  { 326, 6,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2",
    "", 0, 2, 1, 0, 1 },

  { 327, 6,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/Read HW FIFO2",
    "", 0, 5, 6, 0, 1 },

  { 328, 7,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1/p1",
    "", 0, 5, 7, 0, 1 },

  { 329, 7,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1/p2",
    "", 1, 5, 1, 0, 1 },

  { 330, 8,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2/p1",
    "", 0, 5, 7, 0, 1 },

  { 331, 8,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2/p2",
    "", 1, 5, 1, 0, 1 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 332, "ControlConstant",
    "Value", 0, 1, 0 },

  { 333, "Merge",
    "InitialOutput", 0, 8, 0 },

  { 334, "If Action Subsystem/Control Signals Set to 0",
    "InitialOutput", 0, 8, 0 },

  { 335, "If Action Subsystem/Constant",
    "Value", 0, 1, 0 },

  { 336, "If Action Subsystem/Constant1",
    "Value", 0, 1, 0 },

  { 337, "If Action Subsystem/Constant2",
    "Value", 0, 1, 0 },

  { 338, "If Action Subsystem/Constant3",
    "Value", 0, 1, 0 },

  { 339, "If Action Subsystem/Constant4",
    "Value", 0, 1, 0 },

  { 340, "If Action Subsystem/Constant5",
    "Value", 0, 1, 0 },

  { 341, "If Action Subsystem2/Control Signals",
    "InitialOutput", 0, 8, 0 },

  { 342, "If Action Subsystem2/Constant",
    "Value", 0, 1, 0 },

  { 343, "If Action Subsystem2/Constant1",
    "Value", 0, 1, 0 },

  { 344, "If Action Subsystem2/Constant2",
    "Value", 0, 1, 0 },

  { 345, "If Action Subsystem2/Constant3",
    "Value", 0, 1, 0 },

  { 346, "If Action Subsystem2/Constant4",
    "Value", 0, 1, 0 },

  { 347, "If Action Subsystem2/Constant5",
    "Value", 0, 1, 0 },

  { 348, "If Action Subsystem5/ControlSig",
    "InitialOutput", 0, 8, 0 },

  { 349, "If Action Subsystem6/Control signal",
    "InitialOutput", 0, 8, 0 },

  { 350, "If Action Subsystem6/ReferenceTrayectory",
    "InitialOutput", 0, 9, 0 },

  { 351, "Motors - F4  STM - PWM/Saturation",
    "UpperLimit", 0, 1, 0 },

  { 352, "Motors - F4  STM - PWM/Saturation",
    "LowerLimit", 0, 1, 0 },

  { 353, "Motors - F4  STM - PWM/Saturation1",
    "UpperLimit", 0, 1, 0 },

  { 354, "Motors - F4  STM - PWM/Saturation1",
    "LowerLimit", 0, 1, 0 },

  { 355, "Motors - F4  STM - PWM/Saturation2",
    "UpperLimit", 0, 1, 0 },

  { 356, "Motors - F4  STM - PWM/Saturation2",
    "LowerLimit", 0, 1, 0 },

  { 357, "Motors - F4  STM - PWM/Saturation3",
    "UpperLimit", 0, 1, 0 },

  { 358, "Motors - F4  STM - PWM/Saturation3",
    "LowerLimit", 0, 1, 0 },

  { 359, "Motors - F4  STM - PWM/Saturation4",
    "UpperLimit", 0, 1, 0 },

  { 360, "Motors - F4  STM - PWM/Saturation4",
    "LowerLimit", 0, 1, 0 },

  { 361, "Motors - F4  STM - PWM/Saturation5",
    "UpperLimit", 0, 1, 0 },

  { 362, "Motors - F4  STM - PWM/Saturation5",
    "LowerLimit", 0, 1, 0 },

  { 363, "Motors - F4  STM - PWM/ASCII Encode ",
    "P1", 0, 10, 0 },

  { 364, "Motors - F4  STM - PWM/ASCII Encode ",
    "P2", 0, 1, 0 },

  { 365, "Motors - F4  STM - PWM/ASCII Encode ",
    "P3", 0, 1, 0 },

  { 366, "Motors - F4  STM - PWM/ASCII Encode ",
    "P4", 0, 8, 0 },

  { 367, "SG-ADC Sensors/MM-16-AT Analog Input",
    "P1", 0, 1, 0 },

  { 368, "SG-ADC Sensors/MM-16-AT Analog Input",
    "P2", 0, 1, 0 },

  { 369, "SG-ADC Sensors/MM-16-AT Analog Input",
    "P3", 0, 1, 0 },

  { 370, "SG-ADC Sensors/MM-16-AT Analog Input",
    "P4", 0, 1, 0 },

  { 371, "SG-ADC Sensors/MM-16-AT Analog Input",
    "P5", 0, 1, 0 },

  { 372, "If Action Subsystem6/FeedForwardController/FeeedForward Gain1",
    "Gain", 0, 1, 0 },

  { 373, "If Action Subsystem6/FeedForwardController/FeeedForward Gain10",
    "Gain", 0, 1, 0 },

  { 374, "If Action Subsystem6/FeedForwardController/FeeedForward Gain11",
    "Gain", 0, 1, 0 },

  { 375, "If Action Subsystem6/FeedForwardController/FeeedForward Gain12",
    "Gain", 0, 1, 0 },

  { 376, "If Action Subsystem6/FeedForwardController/FeeedForward Gain2",
    "Gain", 0, 1, 0 },

  { 377, "If Action Subsystem6/FeedForwardController/FeeedForward Gain3",
    "Gain", 0, 1, 0 },

  { 378, "If Action Subsystem6/FeedForwardController/FeeedForward Gain4",
    "Gain", 0, 1, 0 },

  { 379, "If Action Subsystem6/FeedForwardController/FeeedForward Gain5",
    "Gain", 0, 1, 0 },

  { 380, "If Action Subsystem6/FeedForwardController/FeeedForward Gain6",
    "Gain", 0, 1, 0 },

  { 381, "If Action Subsystem6/FeedForwardController/FeeedForward Gain7",
    "Gain", 0, 1, 0 },

  { 382, "If Action Subsystem6/FeedForwardController/FeeedForward Gain8",
    "Gain", 0, 1, 0 },

  { 383, "If Action Subsystem6/FeedForwardController/FeeedForward Gain9",
    "Gain", 0, 1, 0 },

  { 384, "If Action Subsystem6/FeedForwardController/Gain1",
    "Gain", 0, 1, 0 },

  { 385, "If Action Subsystem6/FeedForwardController/Gain3",
    "Gain", 0, 1, 0 },

  { 386, "If Action Subsystem6/FeedForwardController/Gain4",
    "Gain", 0, 1, 0 },

  { 387, "If Action Subsystem6/FeedForwardController/Gain5",
    "Gain", 0, 1, 0 },

  { 388, "If Action Subsystem6/FeedForwardController/Gain6",
    "Gain", 0, 1, 0 },

  { 389, "If Action Subsystem6/FeedForwardController/Gain7",
    "Gain", 0, 1, 0 },

  { 390, "If Action Subsystem6/FeedForwardController/Gain8",
    "Gain", 0, 1, 0 },

  { 391, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole1",
    "A", 0, 11, 0 },

  { 392, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole1",
    "B", 0, 1, 0 },

  { 393, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole1",
    "C", 0, 12, 0 },

  { 394, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole2",
    "A", 0, 11, 0 },

  { 395, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole2",
    "B", 0, 1, 0 },

  { 396, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole2",
    "C", 0, 12, 0 },

  { 397, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole3",
    "A", 0, 11, 0 },

  { 398, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole3",
    "B", 0, 1, 0 },

  { 399, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole3",
    "C", 0, 12, 0 },

  { 400, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole4",
    "A", 0, 11, 0 },

  { 401, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole4",
    "B", 0, 1, 0 },

  { 402, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole4",
    "C", 0, 12, 0 },

  { 403, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole5",
    "A", 0, 11, 0 },

  { 404, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole5",
    "B", 0, 1, 0 },

  { 405, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole5",
    "C", 0, 12, 0 },

  { 406, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole6",
    "A", 0, 11, 0 },

  { 407, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole6",
    "B", 0, 1, 0 },

  { 408, "If Action Subsystem6/Hinf Ganancia Mixta/Discrete Zero-Pole6",
    "C", 0, 12, 0 },

  { 409, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain1",
    "Gain", 0, 1, 0 },

  { 410, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain10",
    "Gain", 0, 1, 0 },

  { 411, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain11",
    "Gain", 0, 1, 0 },

  { 412, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain12",
    "Gain", 0, 1, 0 },

  { 413, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain2",
    "Gain", 0, 1, 0 },

  { 414, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain3",
    "Gain", 0, 1, 0 },

  { 415, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain4",
    "Gain", 0, 1, 0 },

  { 416, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain5",
    "Gain", 0, 1, 0 },

  { 417, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain6",
    "Gain", 0, 1, 0 },

  { 418, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain7",
    "Gain", 0, 1, 0 },

  { 419, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain8",
    "Gain", 0, 1, 0 },

  { 420, "If Action Subsystem6/Hinf Ganancia Mixta/FeeedForward Gain9",
    "Gain", 0, 1, 0 },

  { 421, "If Action Subsystem6/Hinf Ganancia Mixta/Gain1",
    "Gain", 0, 1, 0 },

  { 422, "If Action Subsystem6/Hinf Ganancia Mixta/Gain3",
    "Gain", 0, 1, 0 },

  { 423, "If Action Subsystem6/Hinf Ganancia Mixta/Gain4",
    "Gain", 0, 1, 0 },

  { 424, "If Action Subsystem6/Hinf Ganancia Mixta/Gain5",
    "Gain", 0, 1, 0 },

  { 425, "If Action Subsystem6/Hinf Ganancia Mixta/Gain6",
    "Gain", 0, 1, 0 },

  { 426, "If Action Subsystem6/Hinf Ganancia Mixta/Gain7",
    "Gain", 0, 1, 0 },

  { 427, "If Action Subsystem6/Hinf Ganancia Mixta/Gain8",
    "Gain", 0, 1, 0 },

  { 428, "If Action Subsystem6/Referece/From File1",
    "P1", 0, 13, 0 },

  { 429, "If Action Subsystem6/Referece/From File1",
    "P2", 0, 1, 0 },

  { 430, "If Action Subsystem6/Referece/From File1",
    "P3", 0, 1, 0 },

  { 431, "If Action Subsystem6/Referece/From File1",
    "P4", 0, 1, 0 },

  { 432, "If Action Subsystem6/Referece/From File1",
    "P5", 0, 1, 0 },

  { 433, "If Action Subsystem6/Referece/From File1",
    "P6", 0, 1, 0 },

  { 434, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P1", 0, 1, 0 },

  { 435, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P2", 0, 1, 0 },

  { 436, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P3", 0, 1, 0 },

  { 437, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P4", 0, 1, 0 },

  { 438, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P5", 0, 1, 0 },

  { 439, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P6", 0, 1, 0 },

  { 440, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P7", 0, 1, 0 },

  { 441, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1",
    "P8", 0, 1, 0 },

  { 442, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P1", 0, 1, 0 },

  { 443, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P2", 0, 1, 0 },

  { 444, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P3", 0, 1, 0 },

  { 445, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P4", 0, 1, 0 },

  { 446, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P5", 0, 1, 0 },

  { 447, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P6", 0, 1, 0 },

  { 448, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P7", 0, 1, 0 },

  { 449, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2",
    "P8", 0, 1, 0 },

  { 450, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1",
    "P1", 0, 1, 0 },

  { 451, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1",
    "P2", 0, 1, 0 },

  { 452, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1",
    "P3", 0, 1, 0 },

  { 453, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1",
    "P4", 0, 1, 0 },

  { 454, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1",
    "P5", 0, 14, 0 },

  { 455, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2",
    "P1", 0, 1, 0 },

  { 456, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2",
    "P2", 0, 1, 0 },

  { 457, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2",
    "P3", 0, 1, 0 },

  { 458, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2",
    "P4", 0, 1, 0 },

  { 459, "Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2",
    "P5", 0, 14, 0 },

  { 460, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P1", 0, 1, 0 },

  { 461, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P2", 0, 1, 0 },

  { 462, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P3", 0, 1, 0 },

  { 463, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P4", 0, 1, 0 },

  { 464, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P5", 0, 1, 0 },

  { 465, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P6", 0, 1, 0 },

  { 466, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P7", 0, 1, 0 },

  { 467, "Motors - F4  STM - PWM/Baseboard Serial1/Setup1",
    "P8", 0, 1, 0 },

  { 468, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P1", 0, 1, 0 },

  { 469, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P2", 0, 1, 0 },

  { 470, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P3", 0, 1, 0 },

  { 471, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P4", 0, 1, 0 },

  { 472, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P5", 0, 1, 0 },

  { 473, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P6", 0, 1, 0 },

  { 474, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P7", 0, 1, 0 },

  { 475, "Motors - F4  STM - PWM/Baseboard Serial1/Setup2",
    "P8", 0, 1, 0 },

  { 476, "Motors - F4  STM - PWM/If Action Subsystem/Constant8",
    "Value", 0, 1, 0 },

  { 477, "Motors - F4  STM - PWM/If Action Subsystem1/Constant8",
    "Value", 0, 1, 0 },

  { 478, "Motors - F4  STM - PWM/If Action Subsystem1/Gain",
    "Gain", 0, 1, 0 },

  { 479, "Motors - F4  STM - PWM/If Action Subsystem10/Constant8",
    "Value", 0, 1, 0 },

  { 480, "Motors - F4  STM - PWM/If Action Subsystem11/Constant8",
    "Value", 0, 1, 0 },

  { 481, "Motors - F4  STM - PWM/If Action Subsystem11/Gain",
    "Gain", 0, 1, 0 },

  { 482, "Motors - F4  STM - PWM/If Action Subsystem2/Constant8",
    "Value", 0, 1, 0 },

  { 483, "Motors - F4  STM - PWM/If Action Subsystem3/Constant8",
    "Value", 0, 1, 0 },

  { 484, "Motors - F4  STM - PWM/If Action Subsystem3/Gain",
    "Gain", 0, 1, 0 },

  { 485, "Motors - F4  STM - PWM/If Action Subsystem4/Constant8",
    "Value", 0, 1, 0 },

  { 486, "Motors - F4  STM - PWM/If Action Subsystem5/Constant8",
    "Value", 0, 1, 0 },

  { 487, "Motors - F4  STM - PWM/If Action Subsystem5/Gain",
    "Gain", 0, 1, 0 },

  { 488, "Motors - F4  STM - PWM/If Action Subsystem6/Constant8",
    "Value", 0, 1, 0 },

  { 489, "Motors - F4  STM - PWM/If Action Subsystem7/Constant8",
    "Value", 0, 1, 0 },

  { 490, "Motors - F4  STM - PWM/If Action Subsystem7/Gain",
    "Gain", 0, 1, 0 },

  { 491, "Motors - F4  STM - PWM/If Action Subsystem8/Constant8",
    "Value", 0, 1, 0 },

  { 492, "Motors - F4  STM - PWM/If Action Subsystem9/Constant8",
    "Value", 0, 1, 0 },

  { 493, "Motors - F4  STM - PWM/If Action Subsystem9/Gain",
    "Gain", 0, 1, 0 },

  { 494, "SG-ADC Sensors/Signal Filtering and scaling/Constant1",
    "Value", 0, 1, 0 },

  { 495, "SG-ADC Sensors/Signal Filtering and scaling/Constant2",
    "Value", 0, 1, 0 },

  { 496, "SG-ADC Sensors/Signal Filtering and scaling/Constant3",
    "Value", 0, 1, 0 },

  { 497, "SG-ADC Sensors/Signal Filtering and scaling/Constant4",
    "Value", 0, 1, 0 },

  { 498, "SG-ADC Sensors/Signal Filtering and scaling/Constant5",
    "Value", 0, 1, 0 },

  { 499, "SG-ADC Sensors/Signal Filtering and scaling/Constant6",
    "Value", 0, 1, 0 },

  { 500, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space1",
    "A", 0, 12, 0 },

  { 501, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space1",
    "B", 0, 15, 0 },

  { 502, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space1",
    "C", 0, 15, 0 },

  { 503, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space1",
    "D", 0, 1, 0 },

  { 504, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space1",
    "X0", 0, 16, 0 },

  { 505, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space2",
    "A", 0, 12, 0 },

  { 506, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space2",
    "B", 0, 15, 0 },

  { 507, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space2",
    "C", 0, 15, 0 },

  { 508, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space2",
    "D", 0, 1, 0 },

  { 509, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space2",
    "X0", 0, 16, 0 },

  { 510, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space3",
    "A", 0, 12, 0 },

  { 511, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space3",
    "B", 0, 15, 0 },

  { 512, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space3",
    "C", 0, 15, 0 },

  { 513, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space3",
    "D", 0, 1, 0 },

  { 514, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space3",
    "X0", 0, 16, 0 },

  { 515, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space4",
    "A", 0, 12, 0 },

  { 516, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space4",
    "B", 0, 15, 0 },

  { 517, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space4",
    "C", 0, 15, 0 },

  { 518, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space4",
    "D", 0, 1, 0 },

  { 519, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space4",
    "X0", 0, 16, 0 },

  { 520, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space5",
    "A", 0, 12, 0 },

  { 521, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space5",
    "B", 0, 15, 0 },

  { 522, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space5",
    "C", 0, 15, 0 },

  { 523, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space5",
    "D", 0, 1, 0 },

  { 524, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space5",
    "X0", 0, 16, 0 },

  { 525, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space6",
    "A", 0, 12, 0 },

  { 526, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space6",
    "B", 0, 15, 0 },

  { 527, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space6",
    "C", 0, 15, 0 },

  { 528, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space6",
    "D", 0, 1, 0 },

  { 529, "SG-ADC Sensors/Signal Filtering and scaling/Discrete State-Space6",
    "X0", 0, 16, 0 },

  { 530, "SG-ADC Sensors/Signal Filtering and scaling/Gain",
    "Gain", 0, 1, 0 },

  { 531, "SG-ADC Sensors/Signal Filtering and scaling/Gain1",
    "Gain", 0, 1, 0 },

  { 532, "SG-ADC Sensors/Signal Filtering and scaling/Gain10",
    "Gain", 0, 1, 0 },

  { 533, "SG-ADC Sensors/Signal Filtering and scaling/Gain11",
    "Gain", 0, 1, 0 },

  { 534, "SG-ADC Sensors/Signal Filtering and scaling/Gain2",
    "Gain", 0, 1, 0 },

  { 535, "SG-ADC Sensors/Signal Filtering and scaling/Gain3",
    "Gain", 0, 1, 0 },

  { 536, "SG-ADC Sensors/Signal Filtering and scaling/Gain4",
    "Gain", 0, 1, 0 },

  { 537, "SG-ADC Sensors/Signal Filtering and scaling/Gain5",
    "Gain", 0, 1, 0 },

  { 538, "SG-ADC Sensors/Signal Filtering and scaling/Gain6",
    "Gain", 0, 1, 0 },

  { 539, "SG-ADC Sensors/Signal Filtering and scaling/Gain7",
    "Gain", 0, 1, 0 },

  { 540, "SG-ADC Sensors/Signal Filtering and scaling/Gain8",
    "Gain", 0, 1, 0 },

  { 541, "SG-ADC Sensors/Signal Filtering and scaling/Gain9",
    "Gain", 0, 1, 0 },

  { 542, "If Action Subsystem5/Set1/FeedForwardController/Constant1",
    "Value", 0, 1, 0 },

  { 543, "If Action Subsystem5/Set1/FeedForwardController/Constant10",
    "Value", 0, 1, 0 },

  { 544, "If Action Subsystem5/Set1/FeedForwardController/Constant11",
    "Value", 0, 1, 0 },

  { 545, "If Action Subsystem5/Set1/FeedForwardController/Constant12",
    "Value", 0, 1, 0 },

  { 546, "If Action Subsystem5/Set1/FeedForwardController/Constant13",
    "Value", 0, 1, 0 },

  { 547, "If Action Subsystem5/Set1/FeedForwardController/Constant14",
    "Value", 0, 1, 0 },

  { 548, "If Action Subsystem5/Set1/FeedForwardController/Constant15",
    "Value", 0, 1, 0 },

  { 549, "If Action Subsystem5/Set1/FeedForwardController/Constant16",
    "Value", 0, 1, 0 },

  { 550, "If Action Subsystem5/Set1/FeedForwardController/Constant17",
    "Value", 0, 1, 0 },

  { 551, "If Action Subsystem5/Set1/FeedForwardController/Constant18",
    "Value", 0, 1, 0 },

  { 552, "If Action Subsystem5/Set1/FeedForwardController/Constant8",
    "Value", 0, 1, 0 },

  { 553, "If Action Subsystem5/Set1/FeedForwardController/Constant9",
    "Value", 0, 1, 0 },

  { 554, "If Action Subsystem5/Set1/FeedForwardController/Posi1Free",
    "Value", 0, 1, 0 },

  { 555, "If Action Subsystem5/Set1/FeedForwardController/Posi2Free",
    "Value", 0, 1, 0 },

  { 556, "If Action Subsystem5/Set1/FeedForwardController/Posi3Free",
    "Value", 0, 1, 0 },

  { 557, "If Action Subsystem5/Set1/FeedForwardController/Posi4Free",
    "Value", 0, 1, 0 },

  { 558, "If Action Subsystem5/Set1/FeedForwardController/Posi5Free",
    "Value", 0, 1, 0 },

  { 559, "If Action Subsystem5/Set1/FeedForwardController/Posi6Free",
    "Value", 0, 1, 0 },

  { 560, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain1",
    "Gain", 0, 1, 0 },

  { 561, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain10",
    "Gain", 0, 1, 0 },

  { 562, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain11",
    "Gain", 0, 1, 0 },

  { 563, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain12",
    "Gain", 0, 1, 0 },

  { 564, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain2",
    "Gain", 0, 1, 0 },

  { 565, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain3",
    "Gain", 0, 1, 0 },

  { 566, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain4",
    "Gain", 0, 1, 0 },

  { 567, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain5",
    "Gain", 0, 1, 0 },

  { 568, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain6",
    "Gain", 0, 1, 0 },

  { 569, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain7",
    "Gain", 0, 1, 0 },

  { 570, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain8",
    "Gain", 0, 1, 0 },

  { 571, "If Action Subsystem5/Set1/FeedForwardController/FeeedForward Gain9",
    "Gain", 0, 1, 0 },

  { 572, "If Action Subsystem5/Set1/FeedForwardController/Gain1",
    "Gain", 0, 1, 0 },

  { 573, "If Action Subsystem5/Set1/FeedForwardController/Gain3",
    "Gain", 0, 1, 0 },

  { 574, "If Action Subsystem5/Set1/FeedForwardController/Gain4",
    "Gain", 0, 1, 0 },

  { 575, "If Action Subsystem5/Set1/FeedForwardController/Gain5",
    "Gain", 0, 1, 0 },

  { 576, "If Action Subsystem5/Set1/FeedForwardController/Gain6",
    "Gain", 0, 1, 0 },

  { 577, "If Action Subsystem5/Set1/FeedForwardController/Gain7",
    "Gain", 0, 1, 0 },

  { 578, "If Action Subsystem5/Set1/FeedForwardController/Gain8",
    "Gain", 0, 1, 0 },

  { 579, "If Action Subsystem5/Set1/FeedForwardController/Saturation",
    "UpperLimit", 0, 1, 0 },

  { 580, "If Action Subsystem5/Set1/FeedForwardController/Saturation",
    "LowerLimit", 0, 1, 0 },

  { 581, "If Action Subsystem5/Set1/FeedForwardController/Saturation1",
    "UpperLimit", 0, 1, 0 },

  { 582, "If Action Subsystem5/Set1/FeedForwardController/Saturation1",
    "LowerLimit", 0, 1, 0 },

  { 583, "If Action Subsystem5/Set1/FeedForwardController/Saturation2",
    "UpperLimit", 0, 1, 0 },

  { 584, "If Action Subsystem5/Set1/FeedForwardController/Saturation2",
    "LowerLimit", 0, 1, 0 },

  { 585, "If Action Subsystem5/Set1/FeedForwardController/Saturation3",
    "UpperLimit", 0, 1, 0 },

  { 586, "If Action Subsystem5/Set1/FeedForwardController/Saturation3",
    "LowerLimit", 0, 1, 0 },

  { 587, "If Action Subsystem5/Set1/FeedForwardController/Saturation4",
    "UpperLimit", 0, 1, 0 },

  { 588, "If Action Subsystem5/Set1/FeedForwardController/Saturation4",
    "LowerLimit", 0, 1, 0 },

  { 589, "If Action Subsystem5/Set1/FeedForwardController/Saturation5",
    "UpperLimit", 0, 1, 0 },

  { 590, "If Action Subsystem5/Set1/FeedForwardController/Saturation5",
    "LowerLimit", 0, 1, 0 },

  { 591, "If Action Subsystem6/FeedForwardController/PID Controller1/Filter",
    "gainval", 0, 1, 0 },

  { 592, "If Action Subsystem6/FeedForwardController/PID Controller1/Filter",
    "InitialCondition", 0, 1, 0 },

  { 593, "If Action Subsystem6/FeedForwardController/PID Controller1/Integrator",
    "gainval", 0, 1, 0 },

  { 594, "If Action Subsystem6/FeedForwardController/PID Controller1/Integrator",
    "InitialCondition", 0, 1, 0 },

  { 595,
    "If Action Subsystem6/FeedForwardController/PID Controller1/Derivative Gain",
    "Gain", 0, 1, 0 },

  { 596,
    "If Action Subsystem6/FeedForwardController/PID Controller1/Filter Coefficient",
    "Gain", 0, 1, 0 },

  { 597,
    "If Action Subsystem6/FeedForwardController/PID Controller1/Integral Gain",
    "Gain", 0, 1, 0 },

  { 598,
    "If Action Subsystem6/FeedForwardController/PID Controller1/Proportional Gain",
    "Gain", 0, 1, 0 },

  { 599, "If Action Subsystem6/FeedForwardController/PID Controller2/Filter",
    "gainval", 0, 1, 0 },

  { 600, "If Action Subsystem6/FeedForwardController/PID Controller2/Filter",
    "InitialCondition", 0, 1, 0 },

  { 601, "If Action Subsystem6/FeedForwardController/PID Controller2/Integrator",
    "gainval", 0, 1, 0 },

  { 602, "If Action Subsystem6/FeedForwardController/PID Controller2/Integrator",
    "InitialCondition", 0, 1, 0 },

  { 603,
    "If Action Subsystem6/FeedForwardController/PID Controller2/Derivative Gain",
    "Gain", 0, 1, 0 },

  { 604,
    "If Action Subsystem6/FeedForwardController/PID Controller2/Filter Coefficient",
    "Gain", 0, 1, 0 },

  { 605,
    "If Action Subsystem6/FeedForwardController/PID Controller2/Integral Gain",
    "Gain", 0, 1, 0 },

  { 606,
    "If Action Subsystem6/FeedForwardController/PID Controller2/Proportional Gain",
    "Gain", 0, 1, 0 },

  { 607, "If Action Subsystem6/FeedForwardController/PID Controller3/Filter",
    "gainval", 0, 1, 0 },

  { 608, "If Action Subsystem6/FeedForwardController/PID Controller3/Filter",
    "InitialCondition", 0, 1, 0 },

  { 609, "If Action Subsystem6/FeedForwardController/PID Controller3/Integrator",
    "gainval", 0, 1, 0 },

  { 610, "If Action Subsystem6/FeedForwardController/PID Controller3/Integrator",
    "InitialCondition", 0, 1, 0 },

  { 611,
    "If Action Subsystem6/FeedForwardController/PID Controller3/Derivative Gain",
    "Gain", 0, 1, 0 },

  { 612,
    "If Action Subsystem6/FeedForwardController/PID Controller3/Filter Coefficient",
    "Gain", 0, 1, 0 },

  { 613,
    "If Action Subsystem6/FeedForwardController/PID Controller3/Integral Gain",
    "Gain", 0, 1, 0 },

  { 614,
    "If Action Subsystem6/FeedForwardController/PID Controller3/Proportional Gain",
    "Gain", 0, 1, 0 },

  { 615, "If Action Subsystem6/FeedForwardController/PID Controller4/Filter",
    "gainval", 0, 1, 0 },

  { 616, "If Action Subsystem6/FeedForwardController/PID Controller4/Filter",
    "InitialCondition", 0, 1, 0 },

  { 617, "If Action Subsystem6/FeedForwardController/PID Controller4/Integrator",
    "gainval", 0, 1, 0 },

  { 618, "If Action Subsystem6/FeedForwardController/PID Controller4/Integrator",
    "InitialCondition", 0, 1, 0 },

  { 619,
    "If Action Subsystem6/FeedForwardController/PID Controller4/Derivative Gain",
    "Gain", 0, 1, 0 },

  { 620,
    "If Action Subsystem6/FeedForwardController/PID Controller4/Filter Coefficient",
    "Gain", 0, 1, 0 },

  { 621,
    "If Action Subsystem6/FeedForwardController/PID Controller4/Integral Gain",
    "Gain", 0, 1, 0 },

  { 622,
    "If Action Subsystem6/FeedForwardController/PID Controller4/Proportional Gain",
    "Gain", 0, 1, 0 },

  { 623, "If Action Subsystem6/FeedForwardController/PID Controller5/Filter",
    "gainval", 0, 1, 0 },

  { 624, "If Action Subsystem6/FeedForwardController/PID Controller5/Filter",
    "InitialCondition", 0, 1, 0 },

  { 625, "If Action Subsystem6/FeedForwardController/PID Controller5/Integrator",
    "gainval", 0, 1, 0 },

  { 626, "If Action Subsystem6/FeedForwardController/PID Controller5/Integrator",
    "InitialCondition", 0, 1, 0 },

  { 627,
    "If Action Subsystem6/FeedForwardController/PID Controller5/Derivative Gain",
    "Gain", 0, 1, 0 },

  { 628,
    "If Action Subsystem6/FeedForwardController/PID Controller5/Filter Coefficient",
    "Gain", 0, 1, 0 },

  { 629,
    "If Action Subsystem6/FeedForwardController/PID Controller5/Integral Gain",
    "Gain", 0, 1, 0 },

  { 630,
    "If Action Subsystem6/FeedForwardController/PID Controller5/Proportional Gain",
    "Gain", 0, 1, 0 },

  { 631, "If Action Subsystem6/FeedForwardController/PID Controller6/Filter",
    "gainval", 0, 1, 0 },

  { 632, "If Action Subsystem6/FeedForwardController/PID Controller6/Filter",
    "InitialCondition", 0, 1, 0 },

  { 633, "If Action Subsystem6/FeedForwardController/PID Controller6/Integrator",
    "gainval", 0, 1, 0 },

  { 634, "If Action Subsystem6/FeedForwardController/PID Controller6/Integrator",
    "InitialCondition", 0, 1, 0 },

  { 635,
    "If Action Subsystem6/FeedForwardController/PID Controller6/Derivative Gain",
    "Gain", 0, 1, 0 },

  { 636,
    "If Action Subsystem6/FeedForwardController/PID Controller6/Filter Coefficient",
    "Gain", 0, 1, 0 },

  { 637,
    "If Action Subsystem6/FeedForwardController/PID Controller6/Integral Gain",
    "Gain", 0, 1, 0 },

  { 638,
    "If Action Subsystem6/FeedForwardController/PID Controller6/Proportional Gain",
    "Gain", 0, 1, 0 },

  { 639,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Filter",
    "gainval", 0, 1, 0 },

  { 640,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Filter",
    "InitialCondition", 0, 1, 0 },

  { 641,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Integrator",
    "gainval", 0, 1, 0 },

  { 642,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Integrator",
    "InitialCondition", 0, 1, 0 },

  { 643,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Derivative Gain",
    "Gain", 0, 1, 0 },

  { 644,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Filter Coefficient",
    "Gain", 0, 1, 0 },

  { 645,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Integral Gain",
    "Gain", 0, 1, 0 },

  { 646,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller1/Proportional Gain",
    "Gain", 0, 1, 0 },

  { 647,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Filter",
    "gainval", 0, 1, 0 },

  { 648,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Filter",
    "InitialCondition", 0, 1, 0 },

  { 649,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Integrator",
    "gainval", 0, 1, 0 },

  { 650,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Integrator",
    "InitialCondition", 0, 1, 0 },

  { 651,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Derivative Gain",
    "Gain", 0, 1, 0 },

  { 652,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Filter Coefficient",
    "Gain", 0, 1, 0 },

  { 653,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Integral Gain",
    "Gain", 0, 1, 0 },

  { 654,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller2/Proportional Gain",
    "Gain", 0, 1, 0 },

  { 655,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Filter",
    "gainval", 0, 1, 0 },

  { 656,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Filter",
    "InitialCondition", 0, 1, 0 },

  { 657,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Integrator",
    "gainval", 0, 1, 0 },

  { 658,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Integrator",
    "InitialCondition", 0, 1, 0 },

  { 659,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Derivative Gain",
    "Gain", 0, 1, 0 },

  { 660,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Filter Coefficient",
    "Gain", 0, 1, 0 },

  { 661,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Integral Gain",
    "Gain", 0, 1, 0 },

  { 662,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller3/Proportional Gain",
    "Gain", 0, 1, 0 },

  { 663,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Filter",
    "gainval", 0, 1, 0 },

  { 664,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Filter",
    "InitialCondition", 0, 1, 0 },

  { 665,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Integrator",
    "gainval", 0, 1, 0 },

  { 666,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Integrator",
    "InitialCondition", 0, 1, 0 },

  { 667,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Derivative Gain",
    "Gain", 0, 1, 0 },

  { 668,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Filter Coefficient",
    "Gain", 0, 1, 0 },

  { 669,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Integral Gain",
    "Gain", 0, 1, 0 },

  { 670,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller4/Proportional Gain",
    "Gain", 0, 1, 0 },

  { 671,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Filter",
    "gainval", 0, 1, 0 },

  { 672,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Filter",
    "InitialCondition", 0, 1, 0 },

  { 673,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Integrator",
    "gainval", 0, 1, 0 },

  { 674,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Integrator",
    "InitialCondition", 0, 1, 0 },

  { 675,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Derivative Gain",
    "Gain", 0, 1, 0 },

  { 676,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Filter Coefficient",
    "Gain", 0, 1, 0 },

  { 677,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Integral Gain",
    "Gain", 0, 1, 0 },

  { 678,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller5/Proportional Gain",
    "Gain", 0, 1, 0 },

  { 679,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Filter",
    "gainval", 0, 1, 0 },

  { 680,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Filter",
    "InitialCondition", 0, 1, 0 },

  { 681,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Integrator",
    "gainval", 0, 1, 0 },

  { 682,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Integrator",
    "InitialCondition", 0, 1, 0 },

  { 683,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Derivative Gain",
    "Gain", 0, 1, 0 },

  { 684,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Filter Coefficient",
    "Gain", 0, 1, 0 },

  { 685,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Integral Gain",
    "Gain", 0, 1, 0 },

  { 686,
    "If Action Subsystem5/Set1/FeedForwardController/PID Controller6/Proportional Gain",
    "Gain", 0, 1, 0 },

  { 687, "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/Constant",
    "Value", 5, 1, 0 },

  { 688,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1",
    "P1", 0, 1, 0 },

  { 689,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1",
    "P2", 0, 1, 0 },

  { 690,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1",
    "P3", 0, 1, 0 },

  { 691,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1",
    "P4", 0, 1, 0 },

  { 692,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1",
    "P5", 0, 14, 0 },

  { 693, "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/Constant",
    "Value", 5, 1, 0 },

  { 694,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2",
    "P1", 0, 1, 0 },

  { 695,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2",
    "P2", 0, 1, 0 },

  { 696,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2",
    "P3", 0, 1, 0 },

  { 697,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2",
    "P4", 0, 1, 0 },

  { 698,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2",
    "P5", 0, 14, 0 },

  { 699,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/Constant1",
    "Value", 5, 1, 0 },

  { 700,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P1", 0, 1, 0 },

  { 701,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P2", 0, 1, 0 },

  { 702,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P3", 0, 1, 0 },

  { 703,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P4", 0, 1, 0 },

  { 704,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P5", 0, 1, 0 },

  { 705,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P6", 0, 1, 0 },

  { 706,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P7", 0, 1, 0 },

  { 707,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1",
    "P8", 0, 1, 0 },

  { 708,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/Constant2",
    "Value", 5, 1, 0 },

  { 709,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P1", 0, 1, 0 },

  { 710,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P2", 0, 1, 0 },

  { 711,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P3", 0, 1, 0 },

  { 712,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P4", 0, 1, 0 },

  { 713,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P5", 0, 1, 0 },

  { 714,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P6", 0, 1, 0 },

  { 715,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P7", 0, 1, 0 },

  { 716,
    "Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2",
    "P8", 0, 1, 0 },

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
  &GUI_User_V1_3_B.Merge[0],           /* 0: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 1: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 2: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 3: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 4: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 5: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 6: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 7: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 8: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 9: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 10: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 11: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 12: Signal */
  &GUI_User_V1_3_B.Merge_l,            /* 13: Signal */
  &GUI_User_V1_3_B.Merge1,             /* 14: Signal */
  &GUI_User_V1_3_B.Merge2,             /* 15: Signal */
  &GUI_User_V1_3_B.Merge3,             /* 16: Signal */
  &GUI_User_V1_3_B.Merge4,             /* 17: Signal */
  &GUI_User_V1_3_B.Merge5,             /* 18: Signal */
  &GUI_User_V1_3_B.Saturation,         /* 19: Signal */
  &GUI_User_V1_3_B.Saturation1,        /* 20: Signal */
  &GUI_User_V1_3_B.Saturation2,        /* 21: Signal */
  &GUI_User_V1_3_B.Saturation3,        /* 22: Signal */
  &GUI_User_V1_3_B.Saturation4,        /* 23: Signal */
  &GUI_User_V1_3_B.Saturation5,        /* 24: Signal */
  &GUI_User_V1_3_B.ASCIIEncode[0],     /* 25: Signal */
  &GUI_User_V1_3_B.MM16ATAnalogInput_o1,/* 26: Signal */
  &GUI_User_V1_3_B.MM16ATAnalogInput_o2,/* 27: Signal */
  &GUI_User_V1_3_B.MM16ATAnalogInput_o3,/* 28: Signal */
  &GUI_User_V1_3_B.MM16ATAnalogInput_o4,/* 29: Signal */
  &GUI_User_V1_3_B.MM16ATAnalogInput_o5,/* 30: Signal */
  &GUI_User_V1_3_B.MM16ATAnalogInput_o6,/* 31: Signal */
  &GUI_User_V1_3_B.MM16ATAnalogInput_o7,/* 32: Signal */
  &GUI_User_V1_3_B.MM16ATAnalogInput_o8,/* 33: Signal */
  &GUI_User_V1_3_B.MM16ATAnalogInput_o9,/* 34: Signal */
  &GUI_User_V1_3_B.MM16ATAnalogInput_o10,/* 35: Signal */
  &GUI_User_V1_3_B.MM16ATAnalogInput_o11,/* 36: Signal */
  &GUI_User_V1_3_B.MM16ATAnalogInput_o12,/* 37: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain1,  /* 38: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain10, /* 39: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain11, /* 40: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain12, /* 41: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain2,  /* 42: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain3,  /* 43: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain4,  /* 44: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain5,  /* 45: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain6,  /* 46: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain7,  /* 47: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain8,  /* 48: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain9,  /* 49: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 50: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 51: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 52: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 53: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 54: Signal */
  &GUI_User_V1_3_B.Gain7_m,            /* 55: Signal */
  &GUI_User_V1_3_B.Gain8_p,            /* 56: Signal */
  &GUI_User_V1_3_B.Sum1_k,             /* 57: Signal */
  &GUI_User_V1_3_B.Sum10,              /* 58: Signal */
  &GUI_User_V1_3_B.Sum11,              /* 59: Signal */
  &GUI_User_V1_3_B.Sum12,              /* 60: Signal */
  &GUI_User_V1_3_B.Sum13,              /* 61: Signal */
  &GUI_User_V1_3_B.Sum14,              /* 62: Signal */
  &GUI_User_V1_3_B.Sum15,              /* 63: Signal */
  &GUI_User_V1_3_B.Sum16,              /* 64: Signal */
  &GUI_User_V1_3_B.Sum17,              /* 65: Signal */
  &GUI_User_V1_3_B.Sum18,              /* 66: Signal */
  &GUI_User_V1_3_B.Sum2_i,             /* 67: Signal */
  &GUI_User_V1_3_B.Sum3_o,             /* 68: Signal */
  &GUI_User_V1_3_B.Sum4_o,             /* 69: Signal */
  &GUI_User_V1_3_B.Sum5_h,             /* 70: Signal */
  &GUI_User_V1_3_B.Sum6_c,             /* 71: Signal */
  &GUI_User_V1_3_B.Sum7,               /* 72: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 73: Signal */
  &GUI_User_V1_3_B.Sum9,               /* 74: Signal */
  &GUI_User_V1_3_B.DiscreteZeroPole1,  /* 75: Signal */
  &GUI_User_V1_3_B.DiscreteZeroPole2,  /* 76: Signal */
  &GUI_User_V1_3_B.DiscreteZeroPole3,  /* 77: Signal */
  &GUI_User_V1_3_B.DiscreteZeroPole4,  /* 78: Signal */
  &GUI_User_V1_3_B.DiscreteZeroPole5,  /* 79: Signal */
  &GUI_User_V1_3_B.DiscreteZeroPole6,  /* 80: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain1_m,/* 81: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain10_l,/* 82: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain11_l,/* 83: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain12_g,/* 84: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain2_c,/* 85: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain3_n,/* 86: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain4_i,/* 87: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain5_a,/* 88: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain6_b,/* 89: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain7_c,/* 90: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain8_o,/* 91: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain9_k,/* 92: Signal */
  &GUI_User_V1_3_B.Gain1_p,            /* 93: Signal */
  &GUI_User_V1_3_B.Gain3_k,            /* 94: Signal */
  &GUI_User_V1_3_B.Gain4_g,            /* 95: Signal */
  &GUI_User_V1_3_B.Gain5_o,            /* 96: Signal */
  &GUI_User_V1_3_B.Gain6_h,            /* 97: Signal */
  &GUI_User_V1_3_B.Gain7_j,            /* 98: Signal */
  &GUI_User_V1_3_B.Gain8_f,            /* 99: Signal */
  &GUI_User_V1_3_B.Sum1_e,             /* 100: Signal */
  &GUI_User_V1_3_B.Sum10_l,            /* 101: Signal */
  &GUI_User_V1_3_B.Sum11_f,            /* 102: Signal */
  &GUI_User_V1_3_B.Sum12_d,            /* 103: Signal */
  &GUI_User_V1_3_B.Sum13_d,            /* 104: Signal */
  &GUI_User_V1_3_B.Sum14_i,            /* 105: Signal */
  &GUI_User_V1_3_B.Sum15_f,            /* 106: Signal */
  &GUI_User_V1_3_B.Sum16_i,            /* 107: Signal */
  &GUI_User_V1_3_B.Sum17_b,            /* 108: Signal */
  &GUI_User_V1_3_B.Sum18_c,            /* 109: Signal */
  &GUI_User_V1_3_B.Sum2_im,            /* 110: Signal */
  &GUI_User_V1_3_B.Sum3_l,             /* 111: Signal */
  &GUI_User_V1_3_B.Sum4_c,             /* 112: Signal */
  &GUI_User_V1_3_B.Sum5_l,             /* 113: Signal */
  &GUI_User_V1_3_B.Sum6_d,             /* 114: Signal */
  &GUI_User_V1_3_B.Sum7_i,             /* 115: Signal */
  &GUI_User_V1_3_B.Sum8,               /* 116: Signal */
  &GUI_User_V1_3_B.Sum9_l,             /* 117: Signal */
  &GUI_User_V1_3_B.FromFile1[0],       /* 118: Signal */
  &GUI_User_V1_3_B.Unpack1[0],         /* 119: Signal */
  &GUI_User_V1_3_B.RateTransition,     /* 120: Signal */
  &GUI_User_V1_3_B.RateTransition1,    /* 121: Signal */
  &GUI_User_V1_3_B.RateTransition2,    /* 122: Signal */
  &GUI_User_V1_3_B.RateTransition3,    /* 123: Signal */
  &GUI_User_V1_3_B.FIFOread1[0],       /* 124: Signal */
  &GUI_User_V1_3_B.FIFOread2[0],       /* 125: Signal */
  &GUI_User_V1_3_B.FIFOwrite1_o1,      /* 126: Signal */
  &GUI_User_V1_3_B.FIFOwrite1_o2,      /* 127: Signal */
  &GUI_User_V1_3_B.FIFOwrite2_o1,      /* 128: Signal */
  &GUI_User_V1_3_B.FIFOwrite2_o2,      /* 129: Signal */
  &GUI_User_V1_3_B.Merge_l,            /* 130: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem_h.Sum,/* 131: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem1.Gain,/* 132: Signal */
  &GUI_User_V1_3_B.Merge_l,            /* 133: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem1.Sum,/* 134: Signal */
  &GUI_User_V1_3_B.Merge5,             /* 135: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem10.Sum,/* 136: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem11.Gain,/* 137: Signal */
  &GUI_User_V1_3_B.Merge5,             /* 138: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem11.Sum,/* 139: Signal */
  &GUI_User_V1_3_B.Merge1,             /* 140: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem2_c.Sum,/* 141: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem3.Gain,/* 142: Signal */
  &GUI_User_V1_3_B.Merge1,             /* 143: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem3.Sum,/* 144: Signal */
  &GUI_User_V1_3_B.Merge2,             /* 145: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem4.Sum,/* 146: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem5_i.Gain,/* 147: Signal */
  &GUI_User_V1_3_B.Merge2,             /* 148: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem5_i.Sum,/* 149: Signal */
  &GUI_User_V1_3_B.Merge3,             /* 150: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem6_a.Sum,/* 151: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem7.Gain,/* 152: Signal */
  &GUI_User_V1_3_B.Merge3,             /* 153: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem7.Sum,/* 154: Signal */
  &GUI_User_V1_3_B.Merge4,             /* 155: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem8.Sum,/* 156: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem9.Gain,/* 157: Signal */
  &GUI_User_V1_3_B.Merge4,             /* 158: Signal */
  &GUI_User_V1_3_B.IfActionSubsystem9.Sum,/* 159: Signal */
  &GUI_User_V1_3_B.DiscreteStateSpace1,/* 160: Signal */
  &GUI_User_V1_3_B.DiscreteStateSpace2,/* 161: Signal */
  &GUI_User_V1_3_B.DiscreteStateSpace3,/* 162: Signal */
  &GUI_User_V1_3_B.DiscreteStateSpace4,/* 163: Signal */
  &GUI_User_V1_3_B.DiscreteStateSpace5,/* 164: Signal */
  &GUI_User_V1_3_B.DiscreteStateSpace6,/* 165: Signal */
  &GUI_User_V1_3_B.Gain,               /* 166: Signal */
  &GUI_User_V1_3_B.Gain1,              /* 167: Signal */
  &GUI_User_V1_3_B.Gain10,             /* 168: Signal */
  &GUI_User_V1_3_B.Gain11,             /* 169: Signal */
  &GUI_User_V1_3_B.Gain2,              /* 170: Signal */
  &GUI_User_V1_3_B.Gain3,              /* 171: Signal */
  &GUI_User_V1_3_B.Gain4,              /* 172: Signal */
  &GUI_User_V1_3_B.Gain5,              /* 173: Signal */
  &GUI_User_V1_3_B.Gain6,              /* 174: Signal */
  &GUI_User_V1_3_B.Gain7,              /* 175: Signal */
  &GUI_User_V1_3_B.Gain8,              /* 176: Signal */
  &GUI_User_V1_3_B.Gain9,              /* 177: Signal */
  &GUI_User_V1_3_B.Sum1,               /* 178: Signal */
  &GUI_User_V1_3_B.Sum2,               /* 179: Signal */
  &GUI_User_V1_3_B.Sum3,               /* 180: Signal */
  &GUI_User_V1_3_B.Sum4,               /* 181: Signal */
  &GUI_User_V1_3_B.Sum5,               /* 182: Signal */
  &GUI_User_V1_3_B.Sum6,               /* 183: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain1_j,/* 184: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain10_l0,/* 185: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain11_b,/* 186: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain12_j,/* 187: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain2_a,/* 188: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain3_m,/* 189: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain4_d,/* 190: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain5_n,/* 191: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain6_h,/* 192: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain7_n,/* 193: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain8_d,/* 194: Signal */
  &GUI_User_V1_3_B.FeeedForwardGain9_a,/* 195: Signal */
  &GUI_User_V1_3_B.Gain1_e,            /* 196: Signal */
  &GUI_User_V1_3_B.Gain3_m,            /* 197: Signal */
  &GUI_User_V1_3_B.Gain4_h,            /* 198: Signal */
  &GUI_User_V1_3_B.Gain5_f,            /* 199: Signal */
  &GUI_User_V1_3_B.Gain6_f,            /* 200: Signal */
  &GUI_User_V1_3_B.Gain7_e,            /* 201: Signal */
  &GUI_User_V1_3_B.Gain8_ff,           /* 202: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 203: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 204: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 205: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 206: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 207: Signal */
  &GUI_User_V1_3_B.Merge[0],           /* 208: Signal */
  &GUI_User_V1_3_B.Sum1_n,             /* 209: Signal */
  &GUI_User_V1_3_B.Sum10_i,            /* 210: Signal */
  &GUI_User_V1_3_B.Sum11_i,            /* 211: Signal */
  &GUI_User_V1_3_B.Sum12_j,            /* 212: Signal */
  &GUI_User_V1_3_B.Sum13_g,            /* 213: Signal */
  &GUI_User_V1_3_B.Sum14_k,            /* 214: Signal */
  &GUI_User_V1_3_B.Sum15_p,            /* 215: Signal */
  &GUI_User_V1_3_B.Sum16_l,            /* 216: Signal */
  &GUI_User_V1_3_B.Sum17_k,            /* 217: Signal */
  &GUI_User_V1_3_B.Sum18_j,            /* 218: Signal */
  &GUI_User_V1_3_B.Sum2_f,             /* 219: Signal */
  &GUI_User_V1_3_B.Sum3_oz,            /* 220: Signal */
  &GUI_User_V1_3_B.Sum4_cm,            /* 221: Signal */
  &GUI_User_V1_3_B.Sum5_h2,            /* 222: Signal */
  &GUI_User_V1_3_B.Sum6_o,             /* 223: Signal */
  &GUI_User_V1_3_B.Sum7_m,             /* 224: Signal */
  &GUI_User_V1_3_B.Sum8_h,             /* 225: Signal */
  &GUI_User_V1_3_B.Sum9_lk,            /* 226: Signal */
  &GUI_User_V1_3_B.Filter,             /* 227: Signal */
  &GUI_User_V1_3_B.Integrator,         /* 228: Signal */
  &GUI_User_V1_3_B.DerivativeGain,     /* 229: Signal */
  &GUI_User_V1_3_B.FilterCoefficient,  /* 230: Signal */
  &GUI_User_V1_3_B.IntegralGain,       /* 231: Signal */
  &GUI_User_V1_3_B.ProportionalGain,   /* 232: Signal */
  &GUI_User_V1_3_B.Sum,                /* 233: Signal */
  &GUI_User_V1_3_B.SumD,               /* 234: Signal */
  &GUI_User_V1_3_B.Filter_j,           /* 235: Signal */
  &GUI_User_V1_3_B.Integrator_i,       /* 236: Signal */
  &GUI_User_V1_3_B.DerivativeGain_a,   /* 237: Signal */
  &GUI_User_V1_3_B.FilterCoefficient_n,/* 238: Signal */
  &GUI_User_V1_3_B.IntegralGain_e,     /* 239: Signal */
  &GUI_User_V1_3_B.ProportionalGain_c, /* 240: Signal */
  &GUI_User_V1_3_B.Sum_g,              /* 241: Signal */
  &GUI_User_V1_3_B.SumD_h,             /* 242: Signal */
  &GUI_User_V1_3_B.Filter_b,           /* 243: Signal */
  &GUI_User_V1_3_B.Integrator_m,       /* 244: Signal */
  &GUI_User_V1_3_B.DerivativeGain_ap,  /* 245: Signal */
  &GUI_User_V1_3_B.FilterCoefficient_h,/* 246: Signal */
  &GUI_User_V1_3_B.IntegralGain_p,     /* 247: Signal */
  &GUI_User_V1_3_B.ProportionalGain_k, /* 248: Signal */
  &GUI_User_V1_3_B.Sum_f,              /* 249: Signal */
  &GUI_User_V1_3_B.SumD_fc,            /* 250: Signal */
  &GUI_User_V1_3_B.Filter_n,           /* 251: Signal */
  &GUI_User_V1_3_B.Integrator_p,       /* 252: Signal */
  &GUI_User_V1_3_B.DerivativeGain_p,   /* 253: Signal */
  &GUI_User_V1_3_B.FilterCoefficient_j,/* 254: Signal */
  &GUI_User_V1_3_B.IntegralGain_k,     /* 255: Signal */
  &GUI_User_V1_3_B.ProportionalGain_g, /* 256: Signal */
  &GUI_User_V1_3_B.Sum_p,              /* 257: Signal */
  &GUI_User_V1_3_B.SumD_n,             /* 258: Signal */
  &GUI_User_V1_3_B.Filter_e,           /* 259: Signal */
  &GUI_User_V1_3_B.Integrator_g,       /* 260: Signal */
  &GUI_User_V1_3_B.DerivativeGain_n,   /* 261: Signal */
  &GUI_User_V1_3_B.FilterCoefficient_o,/* 262: Signal */
  &GUI_User_V1_3_B.IntegralGain_k4,    /* 263: Signal */
  &GUI_User_V1_3_B.ProportionalGain_m, /* 264: Signal */
  &GUI_User_V1_3_B.Sum_h,              /* 265: Signal */
  &GUI_User_V1_3_B.SumD_m,             /* 266: Signal */
  &GUI_User_V1_3_B.Filter_i,           /* 267: Signal */
  &GUI_User_V1_3_B.Integrator_gs,      /* 268: Signal */
  &GUI_User_V1_3_B.DerivativeGain_h,   /* 269: Signal */
  &GUI_User_V1_3_B.FilterCoefficient_m,/* 270: Signal */
  &GUI_User_V1_3_B.IntegralGain_b,     /* 271: Signal */
  &GUI_User_V1_3_B.ProportionalGain_e, /* 272: Signal */
  &GUI_User_V1_3_B.Sum_i,              /* 273: Signal */
  &GUI_User_V1_3_B.SumD_f,             /* 274: Signal */
  &GUI_User_V1_3_B.ReadIntStatusFC1_o2,/* 275: Signal */
  &GUI_User_V1_3_B.Filter_h,           /* 276: Signal */
  &GUI_User_V1_3_B.Integrator_iz,      /* 277: Signal */
  &GUI_User_V1_3_B.DerivativeGain_l,   /* 278: Signal */
  &GUI_User_V1_3_B.FilterCoefficient_jw,/* 279: Signal */
  &GUI_User_V1_3_B.IntegralGain_o,     /* 280: Signal */
  &GUI_User_V1_3_B.ProportionalGain_o, /* 281: Signal */
  &GUI_User_V1_3_B.Sum_m,              /* 282: Signal */
  &GUI_User_V1_3_B.SumD_o,             /* 283: Signal */
  &GUI_User_V1_3_B.Filter_f,           /* 284: Signal */
  &GUI_User_V1_3_B.Integrator_h,       /* 285: Signal */
  &GUI_User_V1_3_B.DerivativeGain_kl,  /* 286: Signal */
  &GUI_User_V1_3_B.FilterCoefficient_a,/* 287: Signal */
  &GUI_User_V1_3_B.IntegralGain_ko,    /* 288: Signal */
  &GUI_User_V1_3_B.ProportionalGain_ku,/* 289: Signal */
  &GUI_User_V1_3_B.Sum_n,              /* 290: Signal */
  &GUI_User_V1_3_B.SumD_fx,            /* 291: Signal */
  &GUI_User_V1_3_B.Filter_p,           /* 292: Signal */
  &GUI_User_V1_3_B.Integrator_l,       /* 293: Signal */
  &GUI_User_V1_3_B.DerivativeGain_k,   /* 294: Signal */
  &GUI_User_V1_3_B.FilterCoefficient_i,/* 295: Signal */
  &GUI_User_V1_3_B.IntegralGain_c,     /* 296: Signal */
  &GUI_User_V1_3_B.ProportionalGain_d, /* 297: Signal */
  &GUI_User_V1_3_B.Sum_fe,             /* 298: Signal */
  &GUI_User_V1_3_B.SumD_k,             /* 299: Signal */
  &GUI_User_V1_3_B.Filter_fz,          /* 300: Signal */
  &GUI_User_V1_3_B.Integrator_d,       /* 301: Signal */
  &GUI_User_V1_3_B.DerivativeGain_e,   /* 302: Signal */
  &GUI_User_V1_3_B.FilterCoefficient_f,/* 303: Signal */
  &GUI_User_V1_3_B.IntegralGain_g,     /* 304: Signal */
  &GUI_User_V1_3_B.ProportionalGain_mk,/* 305: Signal */
  &GUI_User_V1_3_B.Sum_pc,             /* 306: Signal */
  &GUI_User_V1_3_B.SumD_d,             /* 307: Signal */
  &GUI_User_V1_3_B.Filter_io,          /* 308: Signal */
  &GUI_User_V1_3_B.Integrator_pa,      /* 309: Signal */
  &GUI_User_V1_3_B.DerivativeGain_klw, /* 310: Signal */
  &GUI_User_V1_3_B.FilterCoefficient_hs,/* 311: Signal */
  &GUI_User_V1_3_B.IntegralGain_h,     /* 312: Signal */
  &GUI_User_V1_3_B.ProportionalGain_mo,/* 313: Signal */
  &GUI_User_V1_3_B.Sum_j,              /* 314: Signal */
  &GUI_User_V1_3_B.SumD_m3,            /* 315: Signal */
  &GUI_User_V1_3_B.Filter_d,           /* 316: Signal */
  &GUI_User_V1_3_B.Integrator_ir,      /* 317: Signal */
  &GUI_User_V1_3_B.DerivativeGain_eo,  /* 318: Signal */
  &GUI_User_V1_3_B.FilterCoefficient_b,/* 319: Signal */
  &GUI_User_V1_3_B.IntegralGain_m,     /* 320: Signal */
  &GUI_User_V1_3_B.ProportionalGain_mm,/* 321: Signal */
  &GUI_User_V1_3_B.Sum_iv,             /* 322: Signal */
  &GUI_User_V1_3_B.SumD_g,             /* 323: Signal */
  &GUI_User_V1_3_B.FIFOwrite1,         /* 324: Signal */
  &GUI_User_V1_3_B.ReadHWFIFO1[0],     /* 325: Signal */
  &GUI_User_V1_3_B.FIFOwrite2,         /* 326: Signal */
  &GUI_User_V1_3_B.ReadHWFIFO2[0],     /* 327: Signal */
  &GUI_User_V1_3_B.FIFOread1_o1[0],    /* 328: Signal */
  &GUI_User_V1_3_B.FIFOread1_o2,       /* 329: Signal */
  &GUI_User_V1_3_B.FIFOread2_o1[0],    /* 330: Signal */
  &GUI_User_V1_3_B.FIFOread2_o2,       /* 331: Signal */
  &GUI_User_V1_3_P.ControlConstant_Value,/* 332: Block Parameter */
  &GUI_User_V1_3_P.Merge_InitialOutput[0],/* 333: Block Parameter */
  &GUI_User_V1_3_P.ControlSignalsSetto0_Y0[0],/* 334: Block Parameter */
  &GUI_User_V1_3_P.Constant_Value,     /* 335: Block Parameter */
  &GUI_User_V1_3_P.Constant1_Value,    /* 336: Block Parameter */
  &GUI_User_V1_3_P.Constant2_Value,    /* 337: Block Parameter */
  &GUI_User_V1_3_P.Constant3_Value,    /* 338: Block Parameter */
  &GUI_User_V1_3_P.Constant4_Value,    /* 339: Block Parameter */
  &GUI_User_V1_3_P.Constant5_Value,    /* 340: Block Parameter */
  &GUI_User_V1_3_P.ControlSignals_Y0[0],/* 341: Block Parameter */
  &GUI_User_V1_3_P.Constant_Value_n,   /* 342: Block Parameter */
  &GUI_User_V1_3_P.Constant1_Value_m,  /* 343: Block Parameter */
  &GUI_User_V1_3_P.Constant2_Value_n,  /* 344: Block Parameter */
  &GUI_User_V1_3_P.Constant3_Value_i,  /* 345: Block Parameter */
  &GUI_User_V1_3_P.Constant4_Value_h,  /* 346: Block Parameter */
  &GUI_User_V1_3_P.Constant5_Value_e,  /* 347: Block Parameter */
  &GUI_User_V1_3_P.ControlSig_Y0[0],   /* 348: Block Parameter */
  &GUI_User_V1_3_P.Controlsignal_Y0[0],/* 349: Block Parameter */
  &GUI_User_V1_3_P.ReferenceTrayectory_Y0[0],/* 350: Block Parameter */
  &GUI_User_V1_3_P.Saturation_UpperSat_j,/* 351: Block Parameter */
  &GUI_User_V1_3_P.Saturation_LowerSat_b,/* 352: Block Parameter */
  &GUI_User_V1_3_P.Saturation1_UpperSat_b,/* 353: Block Parameter */
  &GUI_User_V1_3_P.Saturation1_LowerSat_m,/* 354: Block Parameter */
  &GUI_User_V1_3_P.Saturation2_UpperSat_j,/* 355: Block Parameter */
  &GUI_User_V1_3_P.Saturation2_LowerSat_a,/* 356: Block Parameter */
  &GUI_User_V1_3_P.Saturation3_UpperSat_m,/* 357: Block Parameter */
  &GUI_User_V1_3_P.Saturation3_LowerSat_j,/* 358: Block Parameter */
  &GUI_User_V1_3_P.Saturation4_UpperSat_n,/* 359: Block Parameter */
  &GUI_User_V1_3_P.Saturation4_LowerSat_p,/* 360: Block Parameter */
  &GUI_User_V1_3_P.Saturation5_UpperSat_l,/* 361: Block Parameter */
  &GUI_User_V1_3_P.Saturation5_LowerSat_l,/* 362: Block Parameter */
  &GUI_User_V1_3_P.ASCIIEncode_P1[0],  /* 363: Block Parameter */
  &GUI_User_V1_3_P.ASCIIEncode_P2,     /* 364: Block Parameter */
  &GUI_User_V1_3_P.ASCIIEncode_P3,     /* 365: Block Parameter */
  &GUI_User_V1_3_P.ASCIIEncode_P4[0],  /* 366: Block Parameter */
  &GUI_User_V1_3_P.MM16ATAnalogInput_P1,/* 367: Block Parameter */
  &GUI_User_V1_3_P.MM16ATAnalogInput_P2,/* 368: Block Parameter */
  &GUI_User_V1_3_P.MM16ATAnalogInput_P3,/* 369: Block Parameter */
  &GUI_User_V1_3_P.MM16ATAnalogInput_P4,/* 370: Block Parameter */
  &GUI_User_V1_3_P.MM16ATAnalogInput_P5,/* 371: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain1_Gain_p,/* 372: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain10_Gain_k,/* 373: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain11_Gain_k,/* 374: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain12_Gain_j,/* 375: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain2_Gain_f,/* 376: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain3_Gain_d,/* 377: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain4_Gain_e,/* 378: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain5_Gain_f,/* 379: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain6_Gain_k,/* 380: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain7_Gain_n,/* 381: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain8_Gain_f,/* 382: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain9_Gain_c,/* 383: Block Parameter */
  &GUI_User_V1_3_P.Gain1_Gain_i,       /* 384: Block Parameter */
  &GUI_User_V1_3_P.Gain3_Gain_l,       /* 385: Block Parameter */
  &GUI_User_V1_3_P.Gain4_Gain_e,       /* 386: Block Parameter */
  &GUI_User_V1_3_P.Gain5_Gain_e,       /* 387: Block Parameter */
  &GUI_User_V1_3_P.Gain6_Gain_e,       /* 388: Block Parameter */
  &GUI_User_V1_3_P.Gain7_Gain_l,       /* 389: Block Parameter */
  &GUI_User_V1_3_P.Gain8_Gain_g,       /* 390: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole1_A[0],/* 391: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole1_B,/* 392: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole1_C[0],/* 393: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole2_A[0],/* 394: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole2_B,/* 395: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole2_C[0],/* 396: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole3_A[0],/* 397: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole3_B,/* 398: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole3_C[0],/* 399: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole4_A[0],/* 400: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole4_B,/* 401: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole4_C[0],/* 402: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole5_A[0],/* 403: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole5_B,/* 404: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole5_C[0],/* 405: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole6_A[0],/* 406: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole6_B,/* 407: Block Parameter */
  &GUI_User_V1_3_P.DiscreteZeroPole6_C[0],/* 408: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain1_Gain_l,/* 409: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain10_Gain_e,/* 410: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain11_Gain_b,/* 411: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain12_Gain_h,/* 412: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain2_Gain_i,/* 413: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain3_Gain_c,/* 414: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain4_Gain_i,/* 415: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain5_Gain_n,/* 416: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain6_Gain_h,/* 417: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain7_Gain_l,/* 418: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain8_Gain_m,/* 419: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain9_Gain_b,/* 420: Block Parameter */
  &GUI_User_V1_3_P.Gain1_Gain_p,       /* 421: Block Parameter */
  &GUI_User_V1_3_P.Gain3_Gain_o,       /* 422: Block Parameter */
  &GUI_User_V1_3_P.Gain4_Gain_k,       /* 423: Block Parameter */
  &GUI_User_V1_3_P.Gain5_Gain_i,       /* 424: Block Parameter */
  &GUI_User_V1_3_P.Gain6_Gain_a,       /* 425: Block Parameter */
  &GUI_User_V1_3_P.Gain7_Gain_a,       /* 426: Block Parameter */
  &GUI_User_V1_3_P.Gain8_Gain_l,       /* 427: Block Parameter */
  &GUI_User_V1_3_P.FromFile1_P1[0],    /* 428: Block Parameter */
  &GUI_User_V1_3_P.FromFile1_P2,       /* 429: Block Parameter */
  &GUI_User_V1_3_P.FromFile1_P3,       /* 430: Block Parameter */
  &GUI_User_V1_3_P.FromFile1_P4,       /* 431: Block Parameter */
  &GUI_User_V1_3_P.FromFile1_P5,       /* 432: Block Parameter */
  &GUI_User_V1_3_P.FromFile1_P6,       /* 433: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P1_f,     /* 434: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P2_d,     /* 435: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P3_d,     /* 436: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P4_o,     /* 437: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P5_d,     /* 438: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P6_h,     /* 439: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P7_h,     /* 440: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P8_n,     /* 441: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P1_c,     /* 442: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P2_g,     /* 443: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P3_o,     /* 444: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P4_a,     /* 445: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P5_c,     /* 446: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P6_k,     /* 447: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P7_c,     /* 448: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P8_a,     /* 449: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite1_P1_m,    /* 450: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite1_P2_n,    /* 451: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite1_P3_g,    /* 452: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite1_P4_i,    /* 453: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite1_P5_h[0], /* 454: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite2_P1_c,    /* 455: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite2_P2_n,    /* 456: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite2_P3_e,    /* 457: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite2_P4_i,    /* 458: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite2_P5_o[0], /* 459: Block Parameter */
  &GUI_User_V1_3_P.Setup1_P1,          /* 460: Block Parameter */
  &GUI_User_V1_3_P.Setup1_P2,          /* 461: Block Parameter */
  &GUI_User_V1_3_P.Setup1_P3,          /* 462: Block Parameter */
  &GUI_User_V1_3_P.Setup1_P4,          /* 463: Block Parameter */
  &GUI_User_V1_3_P.Setup1_P5,          /* 464: Block Parameter */
  &GUI_User_V1_3_P.Setup1_P6,          /* 465: Block Parameter */
  &GUI_User_V1_3_P.Setup1_P7,          /* 466: Block Parameter */
  &GUI_User_V1_3_P.Setup1_P8,          /* 467: Block Parameter */
  &GUI_User_V1_3_P.Setup2_P1,          /* 468: Block Parameter */
  &GUI_User_V1_3_P.Setup2_P2,          /* 469: Block Parameter */
  &GUI_User_V1_3_P.Setup2_P3,          /* 470: Block Parameter */
  &GUI_User_V1_3_P.Setup2_P4,          /* 471: Block Parameter */
  &GUI_User_V1_3_P.Setup2_P5,          /* 472: Block Parameter */
  &GUI_User_V1_3_P.Setup2_P6,          /* 473: Block Parameter */
  &GUI_User_V1_3_P.Setup2_P7,          /* 474: Block Parameter */
  &GUI_User_V1_3_P.Setup2_P8,          /* 475: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem_h.Constant8_Value,/* 476: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem1.Constant8_Value,/* 477: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem1.Gain_Gain,/* 478: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem10.Constant8_Value,/* 479: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem11.Constant8_Value,/* 480: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem11.Gain_Gain,/* 481: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem2_c.Constant8_Value,/* 482: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem3.Constant8_Value,/* 483: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem3.Gain_Gain,/* 484: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem4.Constant8_Value,/* 485: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem5_i.Constant8_Value,/* 486: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem5_i.Gain_Gain,/* 487: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem6_a.Constant8_Value,/* 488: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem7.Constant8_Value,/* 489: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem7.Gain_Gain,/* 490: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem8.Constant8_Value,/* 491: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem9.Constant8_Value,/* 492: Block Parameter */
  &GUI_User_V1_3_P.IfActionSubsystem9.Gain_Gain,/* 493: Block Parameter */
  &GUI_User_V1_3_P.Constant1_Value_n,  /* 494: Block Parameter */
  &GUI_User_V1_3_P.Constant2_Value_f,  /* 495: Block Parameter */
  &GUI_User_V1_3_P.Constant3_Value_c,  /* 496: Block Parameter */
  &GUI_User_V1_3_P.Constant4_Value_p,  /* 497: Block Parameter */
  &GUI_User_V1_3_P.Constant5_Value_p,  /* 498: Block Parameter */
  &GUI_User_V1_3_P.Constant6_Value,    /* 499: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace1_A[0],/* 500: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace1_B[0],/* 501: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace1_C[0],/* 502: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace1_D,/* 503: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace1_X0[0],/* 504: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace2_A[0],/* 505: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace2_B[0],/* 506: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace2_C[0],/* 507: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace2_D,/* 508: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace2_X0[0],/* 509: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace3_A[0],/* 510: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace3_B[0],/* 511: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace3_C[0],/* 512: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace3_D,/* 513: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace3_X0[0],/* 514: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace4_A[0],/* 515: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace4_B[0],/* 516: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace4_C[0],/* 517: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace4_D,/* 518: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace4_X0[0],/* 519: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace5_A[0],/* 520: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace5_B[0],/* 521: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace5_C[0],/* 522: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace5_D,/* 523: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace5_X0[0],/* 524: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace6_A[0],/* 525: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace6_B[0],/* 526: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace6_C[0],/* 527: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace6_D,/* 528: Block Parameter */
  &GUI_User_V1_3_P.DiscreteStateSpace6_X0[0],/* 529: Block Parameter */
  &GUI_User_V1_3_P.Gain_Gain,          /* 530: Block Parameter */
  &GUI_User_V1_3_P.Gain1_Gain_g,       /* 531: Block Parameter */
  &GUI_User_V1_3_P.Gain10_Gain,        /* 532: Block Parameter */
  &GUI_User_V1_3_P.Gain11_Gain,        /* 533: Block Parameter */
  &GUI_User_V1_3_P.Gain2_Gain,         /* 534: Block Parameter */
  &GUI_User_V1_3_P.Gain3_Gain_m,       /* 535: Block Parameter */
  &GUI_User_V1_3_P.Gain4_Gain_n,       /* 536: Block Parameter */
  &GUI_User_V1_3_P.Gain5_Gain_d,       /* 537: Block Parameter */
  &GUI_User_V1_3_P.Gain6_Gain_b,       /* 538: Block Parameter */
  &GUI_User_V1_3_P.Gain7_Gain_m,       /* 539: Block Parameter */
  &GUI_User_V1_3_P.Gain8_Gain_e,       /* 540: Block Parameter */
  &GUI_User_V1_3_P.Gain9_Gain,         /* 541: Block Parameter */
  &GUI_User_V1_3_P.Constant1_Value_p,  /* 542: Block Parameter */
  &GUI_User_V1_3_P.Constant10_Value,   /* 543: Block Parameter */
  &GUI_User_V1_3_P.Constant11_Value,   /* 544: Block Parameter */
  &GUI_User_V1_3_P.Constant12_Value,   /* 545: Block Parameter */
  &GUI_User_V1_3_P.Constant13_Value,   /* 546: Block Parameter */
  &GUI_User_V1_3_P.Constant14_Value,   /* 547: Block Parameter */
  &GUI_User_V1_3_P.Constant15_Value,   /* 548: Block Parameter */
  &GUI_User_V1_3_P.Constant16_Value,   /* 549: Block Parameter */
  &GUI_User_V1_3_P.Constant17_Value,   /* 550: Block Parameter */
  &GUI_User_V1_3_P.Constant18_Value,   /* 551: Block Parameter */
  &GUI_User_V1_3_P.Constant8_Value,    /* 552: Block Parameter */
  &GUI_User_V1_3_P.Constant9_Value,    /* 553: Block Parameter */
  &GUI_User_V1_3_P.Posi1Free_Value,    /* 554: Block Parameter */
  &GUI_User_V1_3_P.Posi2Free_Value,    /* 555: Block Parameter */
  &GUI_User_V1_3_P.Posi3Free_Value,    /* 556: Block Parameter */
  &GUI_User_V1_3_P.Posi4Free_Value,    /* 557: Block Parameter */
  &GUI_User_V1_3_P.Posi5Free_Value,    /* 558: Block Parameter */
  &GUI_User_V1_3_P.Posi6Free_Value,    /* 559: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain1_Gain,/* 560: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain10_Gain,/* 561: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain11_Gain,/* 562: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain12_Gain,/* 563: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain2_Gain,/* 564: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain3_Gain,/* 565: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain4_Gain,/* 566: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain5_Gain,/* 567: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain6_Gain,/* 568: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain7_Gain,/* 569: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain8_Gain,/* 570: Block Parameter */
  &GUI_User_V1_3_P.FeeedForwardGain9_Gain,/* 571: Block Parameter */
  &GUI_User_V1_3_P.Gain1_Gain,         /* 572: Block Parameter */
  &GUI_User_V1_3_P.Gain3_Gain,         /* 573: Block Parameter */
  &GUI_User_V1_3_P.Gain4_Gain,         /* 574: Block Parameter */
  &GUI_User_V1_3_P.Gain5_Gain,         /* 575: Block Parameter */
  &GUI_User_V1_3_P.Gain6_Gain,         /* 576: Block Parameter */
  &GUI_User_V1_3_P.Gain7_Gain,         /* 577: Block Parameter */
  &GUI_User_V1_3_P.Gain8_Gain,         /* 578: Block Parameter */
  &GUI_User_V1_3_P.Saturation_UpperSat,/* 579: Block Parameter */
  &GUI_User_V1_3_P.Saturation_LowerSat,/* 580: Block Parameter */
  &GUI_User_V1_3_P.Saturation1_UpperSat,/* 581: Block Parameter */
  &GUI_User_V1_3_P.Saturation1_LowerSat,/* 582: Block Parameter */
  &GUI_User_V1_3_P.Saturation2_UpperSat,/* 583: Block Parameter */
  &GUI_User_V1_3_P.Saturation2_LowerSat,/* 584: Block Parameter */
  &GUI_User_V1_3_P.Saturation3_UpperSat,/* 585: Block Parameter */
  &GUI_User_V1_3_P.Saturation3_LowerSat,/* 586: Block Parameter */
  &GUI_User_V1_3_P.Saturation4_UpperSat,/* 587: Block Parameter */
  &GUI_User_V1_3_P.Saturation4_LowerSat,/* 588: Block Parameter */
  &GUI_User_V1_3_P.Saturation5_UpperSat,/* 589: Block Parameter */
  &GUI_User_V1_3_P.Saturation5_LowerSat,/* 590: Block Parameter */
  &GUI_User_V1_3_P.Filter_gainval_p,   /* 591: Block Parameter */
  &GUI_User_V1_3_P.Filter_IC_p,        /* 592: Block Parameter */
  &GUI_User_V1_3_P.Integrator_gainval_fe,/* 593: Block Parameter */
  &GUI_User_V1_3_P.Integrator_IC_f,    /* 594: Block Parameter */
  &GUI_User_V1_3_P.DerivativeGain_Gain_g,/* 595: Block Parameter */
  &GUI_User_V1_3_P.FilterCoefficient_Gain_bu,/* 596: Block Parameter */
  &GUI_User_V1_3_P.IntegralGain_Gain_n,/* 597: Block Parameter */
  &GUI_User_V1_3_P.ProportionalGain_Gain_d,/* 598: Block Parameter */
  &GUI_User_V1_3_P.Filter_gainval_o,   /* 599: Block Parameter */
  &GUI_User_V1_3_P.Filter_IC_aa,       /* 600: Block Parameter */
  &GUI_User_V1_3_P.Integrator_gainval_c,/* 601: Block Parameter */
  &GUI_User_V1_3_P.Integrator_IC_cd,   /* 602: Block Parameter */
  &GUI_User_V1_3_P.DerivativeGain_Gain_n,/* 603: Block Parameter */
  &GUI_User_V1_3_P.FilterCoefficient_Gain_g,/* 604: Block Parameter */
  &GUI_User_V1_3_P.IntegralGain_Gain_jp,/* 605: Block Parameter */
  &GUI_User_V1_3_P.ProportionalGain_Gain_p,/* 606: Block Parameter */
  &GUI_User_V1_3_P.Filter_gainval_py,  /* 607: Block Parameter */
  &GUI_User_V1_3_P.Filter_IC_o,        /* 608: Block Parameter */
  &GUI_User_V1_3_P.Integrator_gainval_l,/* 609: Block Parameter */
  &GUI_User_V1_3_P.Integrator_IC_dv,   /* 610: Block Parameter */
  &GUI_User_V1_3_P.DerivativeGain_Gain_m,/* 611: Block Parameter */
  &GUI_User_V1_3_P.FilterCoefficient_Gain_a,/* 612: Block Parameter */
  &GUI_User_V1_3_P.IntegralGain_Gain_h,/* 613: Block Parameter */
  &GUI_User_V1_3_P.ProportionalGain_Gain_c5,/* 614: Block Parameter */
  &GUI_User_V1_3_P.Filter_gainval_m,   /* 615: Block Parameter */
  &GUI_User_V1_3_P.Filter_IC_nf,       /* 616: Block Parameter */
  &GUI_User_V1_3_P.Integrator_gainval_g,/* 617: Block Parameter */
  &GUI_User_V1_3_P.Integrator_IC_db,   /* 618: Block Parameter */
  &GUI_User_V1_3_P.DerivativeGain_Gain_ny,/* 619: Block Parameter */
  &GUI_User_V1_3_P.FilterCoefficient_Gain_j,/* 620: Block Parameter */
  &GUI_User_V1_3_P.IntegralGain_Gain_iw,/* 621: Block Parameter */
  &GUI_User_V1_3_P.ProportionalGain_Gain_j,/* 622: Block Parameter */
  &GUI_User_V1_3_P.Filter_gainval_d,   /* 623: Block Parameter */
  &GUI_User_V1_3_P.Filter_IC_m,        /* 624: Block Parameter */
  &GUI_User_V1_3_P.Integrator_gainval_m,/* 625: Block Parameter */
  &GUI_User_V1_3_P.Integrator_IC_dm,   /* 626: Block Parameter */
  &GUI_User_V1_3_P.DerivativeGain_Gain_o,/* 627: Block Parameter */
  &GUI_User_V1_3_P.FilterCoefficient_Gain_ih,/* 628: Block Parameter */
  &GUI_User_V1_3_P.IntegralGain_Gain_ip,/* 629: Block Parameter */
  &GUI_User_V1_3_P.ProportionalGain_Gain_m,/* 630: Block Parameter */
  &GUI_User_V1_3_P.Filter_gainval_m1,  /* 631: Block Parameter */
  &GUI_User_V1_3_P.Filter_IC_nc,       /* 632: Block Parameter */
  &GUI_User_V1_3_P.Integrator_gainval_d,/* 633: Block Parameter */
  &GUI_User_V1_3_P.Integrator_IC_k,    /* 634: Block Parameter */
  &GUI_User_V1_3_P.DerivativeGain_Gain_h,/* 635: Block Parameter */
  &GUI_User_V1_3_P.FilterCoefficient_Gain_dz,/* 636: Block Parameter */
  &GUI_User_V1_3_P.IntegralGain_Gain_he,/* 637: Block Parameter */
  &GUI_User_V1_3_P.ProportionalGain_Gain_i,/* 638: Block Parameter */
  &GUI_User_V1_3_P.Filter_gainval_c,   /* 639: Block Parameter */
  &GUI_User_V1_3_P.Filter_IC_a,        /* 640: Block Parameter */
  &GUI_User_V1_3_P.Integrator_gainval_p,/* 641: Block Parameter */
  &GUI_User_V1_3_P.Integrator_IC_e,    /* 642: Block Parameter */
  &GUI_User_V1_3_P.DerivativeGain_Gain_a,/* 643: Block Parameter */
  &GUI_User_V1_3_P.FilterCoefficient_Gain_i,/* 644: Block Parameter */
  &GUI_User_V1_3_P.IntegralGain_Gain_c,/* 645: Block Parameter */
  &GUI_User_V1_3_P.ProportionalGain_Gain_f,/* 646: Block Parameter */
  &GUI_User_V1_3_P.Filter_gainval_g,   /* 647: Block Parameter */
  &GUI_User_V1_3_P.Filter_IC_b,        /* 648: Block Parameter */
  &GUI_User_V1_3_P.Integrator_gainval_j,/* 649: Block Parameter */
  &GUI_User_V1_3_P.Integrator_IC_n,    /* 650: Block Parameter */
  &GUI_User_V1_3_P.DerivativeGain_Gain_ax,/* 651: Block Parameter */
  &GUI_User_V1_3_P.FilterCoefficient_Gain_d,/* 652: Block Parameter */
  &GUI_User_V1_3_P.IntegralGain_Gain_m,/* 653: Block Parameter */
  &GUI_User_V1_3_P.ProportionalGain_Gain_h,/* 654: Block Parameter */
  &GUI_User_V1_3_P.Filter_gainval,     /* 655: Block Parameter */
  &GUI_User_V1_3_P.Filter_IC,          /* 656: Block Parameter */
  &GUI_User_V1_3_P.Integrator_gainval, /* 657: Block Parameter */
  &GUI_User_V1_3_P.Integrator_IC,      /* 658: Block Parameter */
  &GUI_User_V1_3_P.DerivativeGain_Gain,/* 659: Block Parameter */
  &GUI_User_V1_3_P.FilterCoefficient_Gain,/* 660: Block Parameter */
  &GUI_User_V1_3_P.IntegralGain_Gain,  /* 661: Block Parameter */
  &GUI_User_V1_3_P.ProportionalGain_Gain,/* 662: Block Parameter */
  &GUI_User_V1_3_P.Filter_gainval_e,   /* 663: Block Parameter */
  &GUI_User_V1_3_P.Filter_IC_h,        /* 664: Block Parameter */
  &GUI_User_V1_3_P.Integrator_gainval_j4,/* 665: Block Parameter */
  &GUI_User_V1_3_P.Integrator_IC_c,    /* 666: Block Parameter */
  &GUI_User_V1_3_P.DerivativeGain_Gain_c,/* 667: Block Parameter */
  &GUI_User_V1_3_P.FilterCoefficient_Gain_l,/* 668: Block Parameter */
  &GUI_User_V1_3_P.IntegralGain_Gain_l,/* 669: Block Parameter */
  &GUI_User_V1_3_P.ProportionalGain_Gain_c,/* 670: Block Parameter */
  &GUI_User_V1_3_P.Filter_gainval_cs,  /* 671: Block Parameter */
  &GUI_User_V1_3_P.Filter_IC_i,        /* 672: Block Parameter */
  &GUI_User_V1_3_P.Integrator_gainval_i,/* 673: Block Parameter */
  &GUI_User_V1_3_P.Integrator_IC_g,    /* 674: Block Parameter */
  &GUI_User_V1_3_P.DerivativeGain_Gain_e,/* 675: Block Parameter */
  &GUI_User_V1_3_P.FilterCoefficient_Gain_o,/* 676: Block Parameter */
  &GUI_User_V1_3_P.IntegralGain_Gain_i,/* 677: Block Parameter */
  &GUI_User_V1_3_P.ProportionalGain_Gain_n,/* 678: Block Parameter */
  &GUI_User_V1_3_P.Filter_gainval_n,   /* 679: Block Parameter */
  &GUI_User_V1_3_P.Filter_IC_n,        /* 680: Block Parameter */
  &GUI_User_V1_3_P.Integrator_gainval_f,/* 681: Block Parameter */
  &GUI_User_V1_3_P.Integrator_IC_d,    /* 682: Block Parameter */
  &GUI_User_V1_3_P.DerivativeGain_Gain_k,/* 683: Block Parameter */
  &GUI_User_V1_3_P.FilterCoefficient_Gain_b,/* 684: Block Parameter */
  &GUI_User_V1_3_P.IntegralGain_Gain_j,/* 685: Block Parameter */
  &GUI_User_V1_3_P.ProportionalGain_Gain_e,/* 686: Block Parameter */
  &GUI_User_V1_3_P.Constant_Value_a,   /* 687: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite1_P1,      /* 688: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite1_P2,      /* 689: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite1_P3,      /* 690: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite1_P4,      /* 691: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite1_P5[0],   /* 692: Block Parameter */
  &GUI_User_V1_3_P.Constant_Value_i,   /* 693: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite2_P1,      /* 694: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite2_P2,      /* 695: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite2_P3,      /* 696: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite2_P4,      /* 697: Block Parameter */
  &GUI_User_V1_3_P.FIFOwrite2_P5[0],   /* 698: Block Parameter */
  &GUI_User_V1_3_P.Constant1_Value_k,  /* 699: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P1,       /* 700: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P2,       /* 701: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P3,       /* 702: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P4,       /* 703: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P5,       /* 704: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P6,       /* 705: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P7,       /* 706: Block Parameter */
  &GUI_User_V1_3_P.FIFOread1_P8,       /* 707: Block Parameter */
  &GUI_User_V1_3_P.Constant2_Value_h,  /* 708: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P1,       /* 709: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P2,       /* 710: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P3,       /* 711: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P4,       /* 712: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P5,       /* 713: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P6,       /* 714: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P7,       /* 715: Block Parameter */
  &GUI_User_V1_3_P.FIFOread2_P8        /* 716: Block Parameter */
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
  { rtwCAPI_VECTOR, 0, 2, 0 },

  { rtwCAPI_SCALAR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_VECTOR, 14, 2, 0 },

  { rtwCAPI_VECTOR, 16, 2, 0 },

  { rtwCAPI_VECTOR, 18, 2, 0 },

  { rtwCAPI_VECTOR, 20, 2, 0 },

  { rtwCAPI_VECTOR, 22, 2, 0 },

  { rtwCAPI_VECTOR, 24, 2, 0 },

  { rtwCAPI_VECTOR, 26, 2, 0 },

  { rtwCAPI_VECTOR, 28, 2, 0 },

  { rtwCAPI_VECTOR, 30, 2, 0 },

  { rtwCAPI_VECTOR, 32, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  6,                                   /* 0 */
  1,                                   /* 1 */
  1,                                   /* 2 */
  1,                                   /* 3 */
  9,                                   /* 4 */
  1,                                   /* 5 */
  144,                                 /* 6 */
  1,                                   /* 7 */
  18,                                  /* 8 */
  1,                                   /* 9 */
  1025,                                /* 10 */
  1,                                   /* 11 */
  65,                                  /* 12 */
  1,                                   /* 13 */
  61,                                  /* 14 */
  1,                                   /* 15 */
  1,                                   /* 16 */
  6,                                   /* 17 */
  1,                                   /* 18 */
  12,                                  /* 19 */
  1,                                   /* 20 */
  13,                                  /* 21 */
  8,                                   /* 22 */
  1,                                   /* 23 */
  4,                                   /* 24 */
  1,                                   /* 25 */
  1,                                   /* 26 */
  23,                                  /* 27 */
  1,                                   /* 28 */
  20,                                  /* 29 */
  2,                                   /* 30 */
  1,                                   /* 31 */
  1,                                   /* 32 */
  2                                    /* 33 */
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
  { rtBlockSignals, 332 },

  { rtBlockParameters, 385,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void GUI_User_V1_3_InitializeDataMapInfo(rtModel_GUI_User_V1_3
  *GUI_User_V1_3_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(GUI_User_V1_3_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(GUI_User_V1_3_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(GUI_User_V1_3_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(GUI_User_V1_3_rtM->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(GUI_User_V1_3_rtM->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(GUI_User_V1_3_rtM->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(GUI_User_V1_3_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(GUI_User_V1_3_rtM->DataMapInfo.mmi, 0);
}

/* EOF: GUI_User_V1_3_capi.c */
