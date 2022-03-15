/*
 * ReadAnalogInput_data.c
 *
 * Code generation for model "ReadAnalogInput.mdl".
 *
 * Model version              : 1.26
 * Simulink Coder version : 8.0 (R2011a) 09-Mar-2011
 * C source code generated on : Wed Jul 24 11:53:35 2013
 *
 * Target selection: xpctarget.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ReadAnalogInput.h"
#include "ReadAnalogInput_private.h"

/* Block parameters (auto storage) */
Parameters_ReadAnalogInput ReadAnalogInput_P = {
  /*  Computed Parameter: MM16ATAnalogInput_P1_Size
   * Referenced by: '<Root>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: firstChan
                                        * Referenced by: '<Root>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P2_Size
   * Referenced by: '<Root>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  12.0,                                /* Expression: numChans
                                        * Referenced by: '<Root>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P3_Size
   * Referenced by: '<Root>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  7.0,                                 /* Expression: range
                                        * Referenced by: '<Root>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P4_Size
   * Referenced by: '<Root>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P5_Size
   * Referenced by: '<Root>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  768.0,                               /* Expression: baseDec
                                        * Referenced by: '<Root>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: DiscreteStateSpace6_A
   * Referenced by: '<Root>/Discrete State-Space6'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace6_B
   * Referenced by: '<Root>/Discrete State-Space6'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace6_C
   * Referenced by: '<Root>/Discrete State-Space6'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace6_D
                                        * Referenced by: '<Root>/Discrete State-Space6'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<Root>/Discrete State-Space6'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: DiscreteStateSpace1_A
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace1_B
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace1_C
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace1_D
                                        * Referenced by: '<Root>/Discrete State-Space1'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: DiscreteStateSpace2_A
   * Referenced by: '<Root>/Discrete State-Space2'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace2_B
   * Referenced by: '<Root>/Discrete State-Space2'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace2_C
   * Referenced by: '<Root>/Discrete State-Space2'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace2_D
                                        * Referenced by: '<Root>/Discrete State-Space2'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<Root>/Discrete State-Space2'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: DiscreteStateSpace3_A
   * Referenced by: '<Root>/Discrete State-Space3'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace3_B
   * Referenced by: '<Root>/Discrete State-Space3'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace3_C
   * Referenced by: '<Root>/Discrete State-Space3'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace3_D
                                        * Referenced by: '<Root>/Discrete State-Space3'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<Root>/Discrete State-Space3'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: DiscreteStateSpace4_A
   * Referenced by: '<Root>/Discrete State-Space4'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace4_B
   * Referenced by: '<Root>/Discrete State-Space4'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace4_C
   * Referenced by: '<Root>/Discrete State-Space4'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace4_D
                                        * Referenced by: '<Root>/Discrete State-Space4'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<Root>/Discrete State-Space4'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: DiscreteStateSpace5_A
   * Referenced by: '<Root>/Discrete State-Space5'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace5_B
   * Referenced by: '<Root>/Discrete State-Space5'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace5_C
   * Referenced by: '<Root>/Discrete State-Space5'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace5_D
                                        * Referenced by: '<Root>/Discrete State-Space5'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<Root>/Discrete State-Space5'
   */
  { 0.0, 0.0 }
};
