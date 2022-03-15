/*
 * IdentificationMotor2Order_data.c
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
#include "IdentificationMotor2Order_private.h"

/* Block parameters (auto storage) */
Parameters_IdentificationMotor2Order IdentificationMotor2Order_P = {
  /*  Computed Parameter: FIFOwrite1_P1_Size
   * Referenced by: '<S17>/FIFO write 1'
   */
  { 1.0, 1.0 },
  1024.0,                              /* Expression: size
                                        * Referenced by: '<S17>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P2_Size
   * Referenced by: '<S17>/FIFO write 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputtype
                                        * Referenced by: '<S17>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P3_Size
   * Referenced by: '<S17>/FIFO write 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S17>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P4_Size
   * Referenced by: '<S17>/FIFO write 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: present
                                        * Referenced by: '<S17>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P5_Size
   * Referenced by: '<S17>/FIFO write 1'
   */
  { 1.0, 20.0 },

  /*  Computed Parameter: FIFOwrite1_P5
   * Referenced by: '<S17>/FIFO write 1'
   */
  { 82.0, 67.0, 86.0, 32.0, 99.0, 104.0, 97.0, 110.0, 110.0, 101.0, 108.0, 32.0,
    49.0, 44.0, 32.0, 73.0, 82.0, 81.0, 32.0, 52.0 },

  /*  Computed Parameter: FIFOread1_P1_Size
   * Referenced by: '<S19>/FIFO read 1'
   */
  { 1.0, 1.0 },
  60.0,                                /* Expression: maxsize
                                        * Referenced by: '<S19>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P2_Size
   * Referenced by: '<S19>/FIFO read 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: minsize
                                        * Referenced by: '<S19>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P3_Size
   * Referenced by: '<S19>/FIFO read 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: usedelimiter
                                        * Referenced by: '<S19>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P4_Size
   * Referenced by: '<S19>/FIFO read 1'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: delimiter
                                        * Referenced by: '<S19>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P5_Size
   * Referenced by: '<S19>/FIFO read 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: outputtype
                                        * Referenced by: '<S19>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P6_Size
   * Referenced by: '<S19>/FIFO read 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S19>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P7_Size
   * Referenced by: '<S19>/FIFO read 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: enable
                                        * Referenced by: '<S19>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P8_Size
   * Referenced by: '<S19>/FIFO read 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: enableout
                                        * Referenced by: '<S19>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOwrite2_P1_Size
   * Referenced by: '<S18>/FIFO write 2'
   */
  { 1.0, 1.0 },
  1024.0,                              /* Expression: size
                                        * Referenced by: '<S18>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P2_Size
   * Referenced by: '<S18>/FIFO write 2'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputtype
                                        * Referenced by: '<S18>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P3_Size
   * Referenced by: '<S18>/FIFO write 2'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S18>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P4_Size
   * Referenced by: '<S18>/FIFO write 2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: present
                                        * Referenced by: '<S18>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P5_Size
   * Referenced by: '<S18>/FIFO write 2'
   */
  { 1.0, 20.0 },

  /*  Computed Parameter: FIFOwrite2_P5
   * Referenced by: '<S18>/FIFO write 2'
   */
  { 82.0, 67.0, 86.0, 32.0, 99.0, 104.0, 97.0, 110.0, 110.0, 101.0, 108.0, 32.0,
    50.0, 44.0, 32.0, 73.0, 82.0, 81.0, 32.0, 52.0 },

  /*  Computed Parameter: FIFOread2_P1_Size
   * Referenced by: '<S20>/FIFO read 2'
   */
  { 1.0, 1.0 },
  60.0,                                /* Expression: maxsize
                                        * Referenced by: '<S20>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P2_Size
   * Referenced by: '<S20>/FIFO read 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: minsize
                                        * Referenced by: '<S20>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P3_Size
   * Referenced by: '<S20>/FIFO read 2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: usedelimiter
                                        * Referenced by: '<S20>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P4_Size
   * Referenced by: '<S20>/FIFO read 2'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: delimiter
                                        * Referenced by: '<S20>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P5_Size
   * Referenced by: '<S20>/FIFO read 2'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: outputtype
                                        * Referenced by: '<S20>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P6_Size
   * Referenced by: '<S20>/FIFO read 2'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S20>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P7_Size
   * Referenced by: '<S20>/FIFO read 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: enable
                                        * Referenced by: '<S20>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P8_Size
   * Referenced by: '<S20>/FIFO read 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: enableout
                                        * Referenced by: '<S20>/FIFO read 2'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P1_Size
   * Referenced by: '<S2>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: firstChan
                                        * Referenced by: '<S2>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P2_Size
   * Referenced by: '<S2>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  12.0,                                /* Expression: numChans
                                        * Referenced by: '<S2>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P3_Size
   * Referenced by: '<S2>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  6.0,                                 /* Expression: range
                                        * Referenced by: '<S2>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P4_Size
   * Referenced by: '<S2>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S2>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P5_Size
   * Referenced by: '<S2>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  768.0,                               /* Expression: baseDec
                                        * Referenced by: '<S2>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: DiscreteStateSpace6_A
   * Referenced by: '<S21>/Discrete State-Space6'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace6_B
   * Referenced by: '<S21>/Discrete State-Space6'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace6_C
   * Referenced by: '<S21>/Discrete State-Space6'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace6_D
                                        * Referenced by: '<S21>/Discrete State-Space6'
                                        */

  /*  Expression: IniStates(1,:)
   * Referenced by: '<S21>/Discrete State-Space6'
   */
  { 0.0, 0.0 },
  -67.813,                             /* Expression: -67.813
                                        * Referenced by: '<S21>/Gain'
                                        */
  343.38,                              /* Expression: 343.38
                                        * Referenced by: '<S21>/Constant2'
                                        */

  /*  Computed Parameter: DiscreteStateSpace1_A
   * Referenced by: '<S21>/Discrete State-Space1'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace1_B
   * Referenced by: '<S21>/Discrete State-Space1'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace1_C
   * Referenced by: '<S21>/Discrete State-Space1'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace1_D
                                        * Referenced by: '<S21>/Discrete State-Space1'
                                        */

  /*  Expression: IniStates(2,:)
   * Referenced by: '<S21>/Discrete State-Space1'
   */
  { 0.0, 0.0 },
  -67.813,                             /* Expression: -67.813
                                        * Referenced by: '<S21>/Gain1'
                                        */
  343.38,                              /* Expression: 343.38
                                        * Referenced by: '<S21>/Constant1'
                                        */

  /*  Computed Parameter: DiscreteStateSpace2_A
   * Referenced by: '<S21>/Discrete State-Space2'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace2_B
   * Referenced by: '<S21>/Discrete State-Space2'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace2_C
   * Referenced by: '<S21>/Discrete State-Space2'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace2_D
                                        * Referenced by: '<S21>/Discrete State-Space2'
                                        */

  /*  Expression: IniStates(3,:)
   * Referenced by: '<S21>/Discrete State-Space2'
   */
  { 0.0, 0.0 },
  -67.485,                             /* Expression: -67.485
                                        * Referenced by: '<S21>/Gain8'
                                        */
  338.48,                              /* Expression: 338.48
                                        * Referenced by: '<S21>/Constant3'
                                        */

  /*  Computed Parameter: DiscreteStateSpace3_A
   * Referenced by: '<S21>/Discrete State-Space3'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace3_B
   * Referenced by: '<S21>/Discrete State-Space3'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace3_C
   * Referenced by: '<S21>/Discrete State-Space3'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace3_D
                                        * Referenced by: '<S21>/Discrete State-Space3'
                                        */

  /*  Expression: IniStates(4,:)
   * Referenced by: '<S21>/Discrete State-Space3'
   */
  { 0.0, 0.0 },
  -67.813,                             /* Expression: -67.813
                                        * Referenced by: '<S21>/Gain9'
                                        */
  343.38,                              /* Expression: 343.38
                                        * Referenced by: '<S21>/Constant4'
                                        */

  /*  Computed Parameter: DiscreteStateSpace4_A
   * Referenced by: '<S21>/Discrete State-Space4'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace4_B
   * Referenced by: '<S21>/Discrete State-Space4'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace4_C
   * Referenced by: '<S21>/Discrete State-Space4'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace4_D
                                        * Referenced by: '<S21>/Discrete State-Space4'
                                        */

  /*  Expression: IniStates(5,:)
   * Referenced by: '<S21>/Discrete State-Space4'
   */
  { 0.0, 0.0 },
  -67.813,                             /* Expression: -67.813
                                        * Referenced by: '<S21>/Gain10'
                                        */
  343.38,                              /* Expression: 343.38
                                        * Referenced by: '<S21>/Constant5'
                                        */

  /*  Computed Parameter: DiscreteStateSpace5_A
   * Referenced by: '<S21>/Discrete State-Space5'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace5_B
   * Referenced by: '<S21>/Discrete State-Space5'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace5_C
   * Referenced by: '<S21>/Discrete State-Space5'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace5_D
                                        * Referenced by: '<S21>/Discrete State-Space5'
                                        */

  /*  Expression: IniStates(5,:)
   * Referenced by: '<S21>/Discrete State-Space5'
   */
  { 0.0, 0.0 },
  -67.813,                             /* Expression: -67.813
                                        * Referenced by: '<S21>/Gain11'
                                        */
  343.38,                              /* Expression: 343.38
                                        * Referenced by: '<S21>/Constant6'
                                        */
  3.75,                                /* Expression: 3.75
                                        * Referenced by: '<S21>/Gain2'
                                        */
  3.75,                                /* Expression: 3.75
                                        * Referenced by: '<S21>/Gain3'
                                        */
  3.75,                                /* Expression: 3.75
                                        * Referenced by: '<S21>/Gain4'
                                        */
  3.75,                                /* Expression: 3.75
                                        * Referenced by: '<S21>/Gain5'
                                        */
  3.75,                                /* Expression: 3.75
                                        * Referenced by: '<S21>/Gain6'
                                        */
  3.75,                                /* Expression: 3.75
                                        * Referenced by: '<S21>/Gain7'
                                        */
  2.1216407355021216,                  /* Expression: 100/14.14*0.3
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  80.0,                                /* Expression: Satura
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -80.0,                               /* Expression: -Satura
                                        * Referenced by: '<S1>/Saturation'
                                        */
  80.0,                                /* Expression: Satura
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  -80.0,                               /* Expression: -Satura
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  80.0,                                /* Expression: Satura
                                        * Referenced by: '<S1>/Saturation2'
                                        */
  -80.0,                               /* Expression: -Satura
                                        * Referenced by: '<S1>/Saturation2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  80.0,                                /* Expression: Satura
                                        * Referenced by: '<S1>/Saturation3'
                                        */
  -80.0,                               /* Expression: -Satura
                                        * Referenced by: '<S1>/Saturation3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  80.0,                                /* Expression: Satura
                                        * Referenced by: '<S1>/Saturation4'
                                        */
  -80.0,                               /* Expression: -Satura
                                        * Referenced by: '<S1>/Saturation4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  80.0,                                /* Expression: Satura
                                        * Referenced by: '<S1>/Saturation5'
                                        */
  -80.0,                               /* Expression: -Satura
                                        * Referenced by: '<S1>/Saturation5'
                                        */

  /*  Computed Parameter: ASCIIEncode_P1_Size
   * Referenced by: '<S1>/ASCII Encode '
   */
  { 1.0, 13.0 },

  /*  Computed Parameter: ASCIIEncode_P1
   * Referenced by: '<S1>/ASCII Encode '
   */
  { 115.0, 37.0, 99.0, 37.0, 99.0, 37.0, 99.0, 37.0, 99.0, 37.0, 99.0, 37.0,
    99.0 },

  /*  Computed Parameter: ASCIIEncode_P2_Size
   * Referenced by: '<S1>/ASCII Encode '
   */
  { 1.0, 1.0 },
  9.0,                                 /* Expression: maxlength
                                        * Referenced by: '<S1>/ASCII Encode '
                                        */

  /*  Computed Parameter: ASCIIEncode_P3_Size
   * Referenced by: '<S1>/ASCII Encode '
   */
  { 1.0, 1.0 },
  6.0,                                 /* Expression: nvars
                                        * Referenced by: '<S1>/ASCII Encode '
                                        */

  /*  Computed Parameter: ASCIIEncode_P4_Size
   * Referenced by: '<S1>/ASCII Encode '
   */
  { 1.0, 6.0 },

  /*  Expression: varids
   * Referenced by: '<S1>/ASCII Encode '
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: FIFOwrite1_P1_Size_o
   * Referenced by: '<S3>/FIFO write 1'
   */
  { 1.0, 1.0 },
  1024.0,                              /* Expression: size
                                        * Referenced by: '<S3>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P2_Size_n
   * Referenced by: '<S3>/FIFO write 1'
   */
  { 1.0, 1.0 },
  6.0,                                 /* Expression: inputtype
                                        * Referenced by: '<S3>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P3_Size_p
   * Referenced by: '<S3>/FIFO write 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S3>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P4_Size_k
   * Referenced by: '<S3>/FIFO write 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: present
                                        * Referenced by: '<S3>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P5_Size_e
   * Referenced by: '<S3>/FIFO write 1'
   */
  { 1.0, 20.0 },

  /*  Computed Parameter: FIFOwrite1_P5_c
   * Referenced by: '<S3>/FIFO write 1'
   */
  { 88.0, 77.0, 84.0, 32.0, 99.0, 104.0, 97.0, 110.0, 110.0, 101.0, 108.0, 32.0,
    49.0, 44.0, 32.0, 73.0, 82.0, 81.0, 32.0, 52.0 },

  /*  Computed Parameter: FIFOwrite2_P1_Size_d
   * Referenced by: '<S3>/FIFO write 2'
   */
  { 1.0, 1.0 },
  1024.0,                              /* Expression: size
                                        * Referenced by: '<S3>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P2_Size_f
   * Referenced by: '<S3>/FIFO write 2'
   */
  { 1.0, 1.0 },
  6.0,                                 /* Expression: inputtype
                                        * Referenced by: '<S3>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P3_Size_p
   * Referenced by: '<S3>/FIFO write 2'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S3>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P4_Size_p
   * Referenced by: '<S3>/FIFO write 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: present
                                        * Referenced by: '<S3>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P5_Size_c
   * Referenced by: '<S3>/FIFO write 2'
   */
  { 1.0, 20.0 },

  /*  Computed Parameter: FIFOwrite2_P5_k
   * Referenced by: '<S3>/FIFO write 2'
   */
  { 88.0, 77.0, 84.0, 32.0, 99.0, 104.0, 97.0, 110.0, 110.0, 101.0, 108.0, 32.0,
    50.0, 44.0, 32.0, 73.0, 82.0, 81.0, 32.0, 52.0 },

  /*  Computed Parameter: FIFOread1_P1_Size_k
   * Referenced by: '<S3>/FIFO read 1'
   */
  { 1.0, 1.0 },
  1024.0,                              /* Expression: maxsize
                                        * Referenced by: '<S3>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P2_Size_m
   * Referenced by: '<S3>/FIFO read 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: minsize
                                        * Referenced by: '<S3>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P3_Size_d
   * Referenced by: '<S3>/FIFO read 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: usedelimiter
                                        * Referenced by: '<S3>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P4_Size_m
   * Referenced by: '<S3>/FIFO read 1'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: delimiter
                                        * Referenced by: '<S3>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P5_Size_k
   * Referenced by: '<S3>/FIFO read 1'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: outputtype
                                        * Referenced by: '<S3>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P6_Size_i
   * Referenced by: '<S3>/FIFO read 1'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<S3>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P7_Size_i
   * Referenced by: '<S3>/FIFO read 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: enable
                                        * Referenced by: '<S3>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P8_Size_a
   * Referenced by: '<S3>/FIFO read 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: enableout
                                        * Referenced by: '<S3>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread2_P1_Size_n
   * Referenced by: '<S3>/FIFO read 2'
   */
  { 1.0, 1.0 },
  1024.0,                              /* Expression: maxsize
                                        * Referenced by: '<S3>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P2_Size_i
   * Referenced by: '<S3>/FIFO read 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: minsize
                                        * Referenced by: '<S3>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P3_Size_h
   * Referenced by: '<S3>/FIFO read 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: usedelimiter
                                        * Referenced by: '<S3>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P4_Size_p
   * Referenced by: '<S3>/FIFO read 2'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: delimiter
                                        * Referenced by: '<S3>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P5_Size_m
   * Referenced by: '<S3>/FIFO read 2'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: outputtype
                                        * Referenced by: '<S3>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P6_Size_c
   * Referenced by: '<S3>/FIFO read 2'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<S3>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P7_Size_k
   * Referenced by: '<S3>/FIFO read 2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: enable
                                        * Referenced by: '<S3>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P8_Size_c
   * Referenced by: '<S3>/FIFO read 2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: enableout
                                        * Referenced by: '<S3>/FIFO read 2'
                                        */

  /*  Computed Parameter: Setup1_P1_Size
   * Referenced by: '<S3>/Setup1'
   */
  { 1.0, 1.0 },
  1016.0,                              /* Expression: addr
                                        * Referenced by: '<S3>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P2_Size
   * Referenced by: '<S3>/Setup1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: baud
                                        * Referenced by: '<S3>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P3_Size
   * Referenced by: '<S3>/Setup1'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: width
                                        * Referenced by: '<S3>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P4_Size
   * Referenced by: '<S3>/Setup1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: nstop
                                        * Referenced by: '<S3>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P5_Size
   * Referenced by: '<S3>/Setup1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: parity
                                        * Referenced by: '<S3>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P6_Size
   * Referenced by: '<S3>/Setup1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: fmode
                                        * Referenced by: '<S3>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P7_Size
   * Referenced by: '<S3>/Setup1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: ctsmode
                                        * Referenced by: '<S3>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P8_Size
   * Referenced by: '<S3>/Setup1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: rlevel
                                        * Referenced by: '<S3>/Setup1'
                                        */

  /*  Computed Parameter: Setup2_P1_Size
   * Referenced by: '<S3>/Setup2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: addr
                                        * Referenced by: '<S3>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P2_Size
   * Referenced by: '<S3>/Setup2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: baud
                                        * Referenced by: '<S3>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P3_Size
   * Referenced by: '<S3>/Setup2'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: width
                                        * Referenced by: '<S3>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P4_Size
   * Referenced by: '<S3>/Setup2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: nstop
                                        * Referenced by: '<S3>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P5_Size
   * Referenced by: '<S3>/Setup2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: parity
                                        * Referenced by: '<S3>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P6_Size
   * Referenced by: '<S3>/Setup2'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: fmode
                                        * Referenced by: '<S3>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P7_Size
   * Referenced by: '<S3>/Setup2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: ctsmode
                                        * Referenced by: '<S3>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P8_Size
   * Referenced by: '<S3>/Setup2'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: rlevel
                                        * Referenced by: '<S3>/Setup2'
                                        */
  1U,                                  /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S17>/Constant'
                                        */
  1U,                                  /* Computed Parameter: Constant1_Value_j
                                        * Referenced by: '<S19>/Constant1'
                                        */
  1U,                                  /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S18>/Constant'
                                        */
  1U,                                  /* Computed Parameter: Constant2_Value_c
                                        * Referenced by: '<S20>/Constant2'
                                        */

  /* Start of '<S1>/If Action Subsystem11' */
  {
    150.0,                             /* Expression: 150
                                        * Referenced by: '<S7>/Constant8'
                                        */
    -1.0                               /* Expression: -1
                                        * Referenced by: '<S7>/Gain'
                                        */
  }
  /* End of '<S1>/If Action Subsystem11' */
  ,

  /* Start of '<S1>/If Action Subsystem10' */
  {
    50.0                               /* Expression: 50
                                        * Referenced by: '<S6>/Constant8'
                                        */
  }
  /* End of '<S1>/If Action Subsystem10' */
  ,

  /* Start of '<S1>/If Action Subsystem9' */
  {
    150.0,                             /* Expression: 150
                                        * Referenced by: '<S15>/Constant8'
                                        */
    -1.0                               /* Expression: -1
                                        * Referenced by: '<S15>/Gain'
                                        */
  }
  /* End of '<S1>/If Action Subsystem9' */
  ,

  /* Start of '<S1>/If Action Subsystem8' */
  {
    50.0                               /* Expression: 50
                                        * Referenced by: '<S14>/Constant8'
                                        */
  }
  /* End of '<S1>/If Action Subsystem8' */
  ,

  /* Start of '<S1>/If Action Subsystem7' */
  {
    150.0,                             /* Expression: 150
                                        * Referenced by: '<S13>/Constant8'
                                        */
    -1.0                               /* Expression: -1
                                        * Referenced by: '<S13>/Gain'
                                        */
  }
  /* End of '<S1>/If Action Subsystem7' */
  ,

  /* Start of '<S1>/If Action Subsystem6' */
  {
    50.0                               /* Expression: 50
                                        * Referenced by: '<S12>/Constant8'
                                        */
  }
  /* End of '<S1>/If Action Subsystem6' */
  ,

  /* Start of '<S1>/If Action Subsystem5' */
  {
    150.0,                             /* Expression: 150
                                        * Referenced by: '<S11>/Constant8'
                                        */
    -1.0                               /* Expression: -1
                                        * Referenced by: '<S11>/Gain'
                                        */
  }
  /* End of '<S1>/If Action Subsystem5' */
  ,

  /* Start of '<S1>/If Action Subsystem4' */
  {
    50.0                               /* Expression: 50
                                        * Referenced by: '<S10>/Constant8'
                                        */
  }
  /* End of '<S1>/If Action Subsystem4' */
  ,

  /* Start of '<S1>/If Action Subsystem3' */
  {
    150.0,                             /* Expression: 150
                                        * Referenced by: '<S9>/Constant8'
                                        */
    -1.0                               /* Expression: -1
                                        * Referenced by: '<S9>/Gain'
                                        */
  }
  /* End of '<S1>/If Action Subsystem3' */
  ,

  /* Start of '<S1>/If Action Subsystem2' */
  {
    50.0                               /* Expression: 50
                                        * Referenced by: '<S8>/Constant8'
                                        */
  }
  /* End of '<S1>/If Action Subsystem2' */
  ,

  /* Start of '<S1>/If Action Subsystem1' */
  {
    150.0,                             /* Expression: 150
                                        * Referenced by: '<S5>/Constant8'
                                        */
    -1.0                               /* Expression: -1
                                        * Referenced by: '<S5>/Gain'
                                        */
  }
  /* End of '<S1>/If Action Subsystem1' */
  ,

  /* Start of '<S1>/If Action Subsystem' */
  {
    50.0                               /* Expression: 50
                                        * Referenced by: '<S4>/Constant8'
                                        */
  }
  /* End of '<S1>/If Action Subsystem' */
};
