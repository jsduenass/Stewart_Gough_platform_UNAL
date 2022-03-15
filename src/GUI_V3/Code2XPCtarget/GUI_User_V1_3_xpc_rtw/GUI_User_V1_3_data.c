/*
 * GUI_User_V1_3_data.c
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
#include "GUI_User_V1_3_private.h"

/* Block parameters (auto storage) */
Parameters_GUI_User_V1_3 GUI_User_V1_3_P = {
  /*  Expression: [0 0 0 0 0 0]
   * Referenced by: '<S1>/Control Signals Set to 0'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant5'
                                        */

  /*  Expression: [0 0 0 0 0 0]
   * Referenced by: '<S3>/ControlSig'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant8'
                                        */
  0.36097042281109215,                 /* Expression: tau(1)/kdc(1)
                                        * Referenced by: '<S8>/FeeedForward Gain5'
                                        */
  0.027982203318689312,                /* Expression: 1/kdc(1)
                                        * Referenced by: '<S8>/FeeedForward Gain6'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain7'
                                        */
  68.317,                              /* Expression: ActLen(1)
                                        * Referenced by: '<S8>/Posi1Free'
                                        */
  2.0,                                 /* Expression: P
                                        * Referenced by: '<S11>/Proportional Gain'
                                        */
  0.001,                               /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S11>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S11>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S11>/Derivative Gain'
                                        */
  0.001,                               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S11>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S11>/Filter'
                                        */
  0.15915494309189535,                 /* Expression: N
                                        * Referenced by: '<S11>/Filter Coefficient'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain8'
                                        */
  0.0,                                 /* Expression: I
                                        * Referenced by: '<S11>/Integral Gain'
                                        */
  40.0,                                /* Expression: 40
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  -40.0,                               /* Expression: -40
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant9'
                                        */
  0.32109880317718814,                 /* Expression: tau(2)/kdc(2)
                                        * Referenced by: '<S8>/FeeedForward Gain3'
                                        */
  0.015363579099386994,                /* Expression: 1/kdc(2)
                                        * Referenced by: '<S8>/FeeedForward Gain4'
                                        */
  68.3214,                             /* Expression: ActLen(2)
                                        * Referenced by: '<S8>/Posi2Free'
                                        */
  2.0,                                 /* Expression: P
                                        * Referenced by: '<S9>/Proportional Gain'
                                        */
  0.001,                               /* Computed Parameter: Integrator_gainval_p
                                        * Referenced by: '<S9>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S9>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S9>/Derivative Gain'
                                        */
  0.001,                               /* Computed Parameter: Filter_gainval_c
                                        * Referenced by: '<S9>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S9>/Filter'
                                        */
  0.15915494309189535,                 /* Expression: N
                                        * Referenced by: '<S9>/Filter Coefficient'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain1'
                                        */
  0.0,                                 /* Expression: I
                                        * Referenced by: '<S9>/Integral Gain'
                                        */
  40.0,                                /* Expression: 40
                                        * Referenced by: '<S8>/Saturation2'
                                        */
  -40.0,                               /* Expression: -40
                                        * Referenced by: '<S8>/Saturation2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant11'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant12'
                                        */
  0.3078936227533387,                  /* Expression: tau(3)/kdc(3)
                                        * Referenced by: '<S8>/FeeedForward Gain1'
                                        */
  0.019243351422083669,                /* Expression: 1/kdc(3)
                                        * Referenced by: '<S8>/FeeedForward Gain2'
                                        */
  68.3123,                             /* Expression: ActLen(3)
                                        * Referenced by: '<S8>/Posi3Free'
                                        */
  2.0,                                 /* Expression: P
                                        * Referenced by: '<S10>/Proportional Gain'
                                        */
  0.001,                               /* Computed Parameter: Integrator_gainval_j
                                        * Referenced by: '<S10>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S10>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S10>/Derivative Gain'
                                        */
  0.001,                               /* Computed Parameter: Filter_gainval_g
                                        * Referenced by: '<S10>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S10>/Filter'
                                        */
  0.15915494309189535,                 /* Expression: N
                                        * Referenced by: '<S10>/Filter Coefficient'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain3'
                                        */
  0.0,                                 /* Expression: I
                                        * Referenced by: '<S10>/Integral Gain'
                                        */
  40.0,                                /* Expression: 40
                                        * Referenced by: '<S8>/Saturation3'
                                        */
  -40.0,                               /* Expression: -40
                                        * Referenced by: '<S8>/Saturation3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant13'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant14'
                                        */
  0.35032358132320696,                 /* Expression: tau(4)/kdc(4)
                                        * Referenced by: '<S8>/FeeedForward Gain7'
                                        */
  0.013371129058137669,                /* Expression: 1/kdc(4)
                                        * Referenced by: '<S8>/FeeedForward Gain8'
                                        */
  68.3123,                             /* Expression: ActLen(4)
                                        * Referenced by: '<S8>/Posi4Free'
                                        */
  2.0,                                 /* Expression: P
                                        * Referenced by: '<S12>/Proportional Gain'
                                        */
  0.001,                               /* Computed Parameter: Integrator_gainval_j4
                                        * Referenced by: '<S12>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S12>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S12>/Derivative Gain'
                                        */
  0.001,                               /* Computed Parameter: Filter_gainval_e
                                        * Referenced by: '<S12>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S12>/Filter'
                                        */
  0.15915494309189535,                 /* Expression: N
                                        * Referenced by: '<S12>/Filter Coefficient'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain4'
                                        */
  0.0,                                 /* Expression: I
                                        * Referenced by: '<S12>/Integral Gain'
                                        */
  40.0,                                /* Expression: 40
                                        * Referenced by: '<S8>/Saturation'
                                        */
  -40.0,                               /* Expression: -40
                                        * Referenced by: '<S8>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant15'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant16'
                                        */
  0.020085161082991888,                /* Expression: 1/kdc(5)
                                        * Referenced by: '<S8>/FeeedForward Gain10'
                                        */
  0.34345625451916129,                 /* Expression: tau(5)/kdc(5)
                                        * Referenced by: '<S8>/FeeedForward Gain9'
                                        */
  68.3214,                             /* Expression: ActLen(5)
                                        * Referenced by: '<S8>/Posi5Free'
                                        */
  2.0,                                 /* Expression: P
                                        * Referenced by: '<S13>/Proportional Gain'
                                        */
  0.001,                               /* Computed Parameter: Integrator_gainval_i
                                        * Referenced by: '<S13>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S13>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S13>/Derivative Gain'
                                        */
  0.001,                               /* Computed Parameter: Filter_gainval_cs
                                        * Referenced by: '<S13>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S13>/Filter'
                                        */
  0.15915494309189535,                 /* Expression: N
                                        * Referenced by: '<S13>/Filter Coefficient'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain5'
                                        */
  0.0,                                 /* Expression: I
                                        * Referenced by: '<S13>/Integral Gain'
                                        */
  40.0,                                /* Expression: 40
                                        * Referenced by: '<S8>/Saturation4'
                                        */
  -40.0,                               /* Expression: -40
                                        * Referenced by: '<S8>/Saturation4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant17'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant18'
                                        */
  0.019445038598401618,                /* Expression: 1/kdc(6)
                                        * Referenced by: '<S8>/FeeedForward Gain11'
                                        */
  0.29556458669570457,                 /* Expression: tau(6)/kdc(6)
                                        * Referenced by: '<S8>/FeeedForward Gain12'
                                        */
  68.317,                              /* Expression: ActLen(6)
                                        * Referenced by: '<S8>/Posi6Free'
                                        */
  2.0,                                 /* Expression: P
                                        * Referenced by: '<S14>/Proportional Gain'
                                        */
  0.001,                               /* Computed Parameter: Integrator_gainval_f
                                        * Referenced by: '<S14>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S14>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S14>/Derivative Gain'
                                        */
  0.001,                               /* Computed Parameter: Filter_gainval_n
                                        * Referenced by: '<S14>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S14>/Filter'
                                        */
  0.15915494309189535,                 /* Expression: N
                                        * Referenced by: '<S14>/Filter Coefficient'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain6'
                                        */
  0.0,                                 /* Expression: I
                                        * Referenced by: '<S14>/Integral Gain'
                                        */
  40.0,                                /* Expression: 40
                                        * Referenced by: '<S8>/Saturation5'
                                        */
  -40.0,                               /* Expression: -40
                                        * Referenced by: '<S8>/Saturation5'
                                        */

  /*  Expression: [0 0 0 0 0 0]
   * Referenced by: '<S4>/Control signal'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
   * Referenced by: '<S4>/ReferenceTrayectory'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: FromFile1_P1_Size
   * Referenced by: '<S17>/From File1'
   */
  { 1.0, 23.0 },

  /*  Computed Parameter: FromFile1_P1
   * Referenced by: '<S17>/From File1'
   */
  { 67.0, 58.0, 92.0, 120.0, 112.0, 99.0, 102.0, 105.0, 108.0, 101.0, 115.0,
    92.0, 84.0, 114.0, 97.0, 106.0, 101.0, 99.0, 50.0, 46.0, 100.0, 97.0, 116.0
  },

  /*  Computed Parameter: FromFile1_P2_Size
   * Referenced by: '<S17>/From File1'
   */
  { 1.0, 1.0 },
  144.0,                               /* Expression: dataSize
                                        * Referenced by: '<S17>/From File1'
                                        */

  /*  Computed Parameter: FromFile1_P3_Size
   * Referenced by: '<S17>/From File1'
   */
  { 1.0, 1.0 },
  1.44E+7,                             /* Expression: bufSize
                                        * Referenced by: '<S17>/From File1'
                                        */

  /*  Computed Parameter: FromFile1_P4_Size
   * Referenced by: '<S17>/From File1'
   */
  { 1.0, 1.0 },
  512.0,                               /* Expression: readSize
                                        * Referenced by: '<S17>/From File1'
                                        */

  /*  Computed Parameter: FromFile1_P5_Size
   * Referenced by: '<S17>/From File1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: EOFOption
                                        * Referenced by: '<S17>/From File1'
                                        */

  /*  Computed Parameter: FromFile1_P6_Size
   * Referenced by: '<S17>/From File1'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampTime
                                        * Referenced by: '<S17>/From File1'
                                        */
  0.3078936227533387,                  /* Expression: 16/51.966
                                        * Referenced by: '<S15>/FeeedForward Gain1'
                                        */
  0.020085161082991888,                /* Expression: 1/49.788
                                        * Referenced by: '<S15>/FeeedForward Gain10'
                                        */
  0.019445038598401618,                /* Expression: 1/51.427
                                        * Referenced by: '<S15>/FeeedForward Gain11'
                                        */
  0.29556458669570457,                 /* Expression: 15.2/51.427
                                        * Referenced by: '<S15>/FeeedForward Gain12'
                                        */
  0.019243351422083669,                /* Expression: 1/51.966
                                        * Referenced by: '<S15>/FeeedForward Gain2'
                                        */
  0.32109880317718814,                 /* Expression: 20.9/65.089
                                        * Referenced by: '<S15>/FeeedForward Gain3'
                                        */
  0.015363579099386994,                /* Expression: 1/65.089
                                        * Referenced by: '<S15>/FeeedForward Gain4'
                                        */
  0.36097042281109215,                 /* Expression: 12.9/35.737
                                        * Referenced by: '<S15>/FeeedForward Gain5'
                                        */
  0.027982203318689312,                /* Expression: 1/35.737
                                        * Referenced by: '<S15>/FeeedForward Gain6'
                                        */
  0.35032358132320696,                 /* Expression: 26.2/74.788
                                        * Referenced by: '<S15>/FeeedForward Gain7'
                                        */
  0.013371129058137669,                /* Expression: 1/74.788
                                        * Referenced by: '<S15>/FeeedForward Gain8'
                                        */
  0.34345625451916129,                 /* Expression: 17.1/49.788
                                        * Referenced by: '<S15>/FeeedForward Gain9'
                                        */
  2.5,                                 /* Expression: P
                                        * Referenced by: '<S18>/Proportional Gain'
                                        */
  0.001,                               /* Computed Parameter: Integrator_gainval_fe
                                        * Referenced by: '<S18>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S18>/Integrator'
                                        */
  0.1,                                 /* Expression: D
                                        * Referenced by: '<S18>/Derivative Gain'
                                        */
  0.001,                               /* Computed Parameter: Filter_gainval_p
                                        * Referenced by: '<S18>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S18>/Filter'
                                        */
  0.015915494309189534,                /* Expression: N
                                        * Referenced by: '<S18>/Filter Coefficient'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain1'
                                        */
  2.5,                                 /* Expression: P
                                        * Referenced by: '<S19>/Proportional Gain'
                                        */
  0.001,                               /* Computed Parameter: Integrator_gainval_c
                                        * Referenced by: '<S19>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S19>/Integrator'
                                        */
  0.1,                                 /* Expression: D
                                        * Referenced by: '<S19>/Derivative Gain'
                                        */
  0.001,                               /* Computed Parameter: Filter_gainval_o
                                        * Referenced by: '<S19>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S19>/Filter'
                                        */
  0.015915494309189534,                /* Expression: N
                                        * Referenced by: '<S19>/Filter Coefficient'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain3'
                                        */
  2.5,                                 /* Expression: P
                                        * Referenced by: '<S21>/Proportional Gain'
                                        */
  0.001,                               /* Computed Parameter: Integrator_gainval_g
                                        * Referenced by: '<S21>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S21>/Integrator'
                                        */
  0.1,                                 /* Expression: D
                                        * Referenced by: '<S21>/Derivative Gain'
                                        */
  0.001,                               /* Computed Parameter: Filter_gainval_m
                                        * Referenced by: '<S21>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S21>/Filter'
                                        */
  0.015915494309189534,                /* Expression: N
                                        * Referenced by: '<S21>/Filter Coefficient'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain4'
                                        */
  2.5,                                 /* Expression: P
                                        * Referenced by: '<S22>/Proportional Gain'
                                        */
  0.001,                               /* Computed Parameter: Integrator_gainval_m
                                        * Referenced by: '<S22>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S22>/Integrator'
                                        */
  0.1,                                 /* Expression: D
                                        * Referenced by: '<S22>/Derivative Gain'
                                        */
  0.001,                               /* Computed Parameter: Filter_gainval_d
                                        * Referenced by: '<S22>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S22>/Filter'
                                        */
  0.015915494309189534,                /* Expression: N
                                        * Referenced by: '<S22>/Filter Coefficient'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain5'
                                        */
  2.5,                                 /* Expression: P
                                        * Referenced by: '<S23>/Proportional Gain'
                                        */
  0.001,                               /* Computed Parameter: Integrator_gainval_d
                                        * Referenced by: '<S23>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S23>/Integrator'
                                        */
  0.1,                                 /* Expression: D
                                        * Referenced by: '<S23>/Derivative Gain'
                                        */
  0.001,                               /* Computed Parameter: Filter_gainval_m1
                                        * Referenced by: '<S23>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S23>/Filter'
                                        */
  0.015915494309189534,                /* Expression: N
                                        * Referenced by: '<S23>/Filter Coefficient'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain6'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain7'
                                        */
  2.5,                                 /* Expression: P
                                        * Referenced by: '<S20>/Proportional Gain'
                                        */
  0.001,                               /* Computed Parameter: Integrator_gainval_l
                                        * Referenced by: '<S20>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S20>/Integrator'
                                        */
  0.1,                                 /* Expression: D
                                        * Referenced by: '<S20>/Derivative Gain'
                                        */
  0.001,                               /* Computed Parameter: Filter_gainval_py
                                        * Referenced by: '<S20>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S20>/Filter'
                                        */
  0.015915494309189534,                /* Expression: N
                                        * Referenced by: '<S20>/Filter Coefficient'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain8'
                                        */
  2.0,                                 /* Expression: I
                                        * Referenced by: '<S18>/Integral Gain'
                                        */
  2.0,                                 /* Expression: I
                                        * Referenced by: '<S19>/Integral Gain'
                                        */
  2.0,                                 /* Expression: I
                                        * Referenced by: '<S20>/Integral Gain'
                                        */
  2.0,                                 /* Expression: I
                                        * Referenced by: '<S21>/Integral Gain'
                                        */
  2.0,                                 /* Expression: I
                                        * Referenced by: '<S22>/Integral Gain'
                                        */
  2.0,                                 /* Expression: I
                                        * Referenced by: '<S23>/Integral Gain'
                                        */

  /*  Computed Parameter: DiscreteZeroPole1_A
   * Referenced by: '<S16>/Discrete Zero-Pole1'
   */
  { 1.8444, -0.91891240061281143, 0.91891240061281143, 1.0, -1.0882430135158827,
    0.69656000000000007, -0.22806619653074414, 0.22806619653074411 },
  1.0,                                 /* Computed Parameter: DiscreteZeroPole1_B
                                        * Referenced by: '<S16>/Discrete Zero-Pole1'
                                        */

  /*  Computed Parameter: DiscreteZeroPole1_C
   * Referenced by: '<S16>/Discrete Zero-Pole1'
   */
  { 2.9617, -3.22304933312999, -1.071483826, 0.33088297483150814 },

  /*  Computed Parameter: DiscreteZeroPole2_A
   * Referenced by: '<S16>/Discrete Zero-Pole2'
   */
  { 1.831, -0.91159201400626577, 0.91159201400626588, 1.0, -1.0969819663131959,
    0.76182, -0.23801599946222105, 0.23801599946222102 },
  1.0,                                 /* Computed Parameter: DiscreteZeroPole2_B
                                        * Referenced by: '<S16>/Discrete Zero-Pole2'
                                        */

  /*  Computed Parameter: DiscreteZeroPole2_C
   * Referenced by: '<S16>/Discrete Zero-Pole2'
   */
  { 3.3372, -3.6608482179803974, -1.0077009119999998, 0.30638349604046211 },

  /*  Computed Parameter: DiscreteZeroPole3_A
   * Referenced by: '<S16>/Discrete Zero-Pole3'
   */
  { 1.8495, -0.92168324276836022, 0.92168324276836022, 1.0, -1.0849714452835317,
    0.65218999999999994, -0.22119537291724706, 0.22119537291724709 },
  1.0,                                 /* Computed Parameter: DiscreteZeroPole3_B
                                        * Referenced by: '<S16>/Discrete Zero-Pole3'
                                        */

  /*  Computed Parameter: DiscreteZeroPole3_C
   * Referenced by: '<S16>/Discrete Zero-Pole3'
   */
  { 2.7876, -3.024466400872373, -1.116182916, 0.34819272617431263 },

  /*  Computed Parameter: DiscreteZeroPole4_A
   * Referenced by: '<S16>/Discrete Zero-Pole4'
   */
  { 1.7872, -0.88724292051275333, 0.88724292051275344, 1.0, -1.1270870433342903,
    0.85096, -0.25132570103353929, 0.25132570103353935 },
  1.0,                                 /* Computed Parameter: DiscreteZeroPole4_B
                                        * Referenced by: '<S16>/Discrete Zero-Pole4'
                                        */

  /*  Computed Parameter: DiscreteZeroPole4_C
   * Referenced by: '<S16>/Discrete Zero-Pole4'
   */
  { 4.4402, -5.0044918898129156, -0.96152530999999963, 0.28635041559476643 },

  /*  Computed Parameter: DiscreteZeroPole5_A
   * Referenced by: '<S16>/Discrete Zero-Pole5'
   */
  { 1.8258, -0.90873538502690643, 0.90873538502690654, 1.0, -1.1004303524181478,
    0.7733, -0.23974361305361191, 0.23974361305361189 },
  1.0,                                 /* Computed Parameter: DiscreteZeroPole5_B
                                        * Referenced by: '<S16>/Discrete Zero-Pole5'
                                        */

  /*  Computed Parameter: DiscreteZeroPole5_C
   * Referenced by: '<S16>/Discrete Zero-Pole5'
   */
  { 3.4633, -3.8111204395297711, -1.0029024140000002, 0.30401346715210009 },

  /*  Computed Parameter: DiscreteZeroPole6_A
   * Referenced by: '<S16>/Discrete Zero-Pole6'
   */
  { 1.8308, -0.91148230920846718, 0.9114823092084674, 1.0, -1.0971139976028734,
    0.76466, -0.23843857070532865, 0.23843857070532862 },
  1.0,                                 /* Computed Parameter: DiscreteZeroPole6_B
                                        * Referenced by: '<S16>/Discrete Zero-Pole6'
                                        */

  /*  Computed Parameter: DiscreteZeroPole6_C
   * Referenced by: '<S16>/Discrete Zero-Pole6'
   */
  { 3.3456, -3.6705045903801734, -1.0035127200000002, 0.30509540493556669 },
  0.3078936227533387,                  /* Expression: 16/51.966
                                        * Referenced by: '<S16>/FeeedForward Gain1'
                                        */
  0.020085161082991888,                /* Expression: 1/49.788
                                        * Referenced by: '<S16>/FeeedForward Gain10'
                                        */
  0.019445038598401618,                /* Expression: 1/51.427
                                        * Referenced by: '<S16>/FeeedForward Gain11'
                                        */
  0.29556458669570457,                 /* Expression: 15.2/51.427
                                        * Referenced by: '<S16>/FeeedForward Gain12'
                                        */
  0.019243351422083669,                /* Expression: 1/51.966
                                        * Referenced by: '<S16>/FeeedForward Gain2'
                                        */
  0.32109880317718814,                 /* Expression: 20.9/65.089
                                        * Referenced by: '<S16>/FeeedForward Gain3'
                                        */
  0.015363579099386994,                /* Expression: 1/65.089
                                        * Referenced by: '<S16>/FeeedForward Gain4'
                                        */
  0.36097042281109215,                 /* Expression: 12.9/35.737
                                        * Referenced by: '<S16>/FeeedForward Gain5'
                                        */
  0.027982203318689312,                /* Expression: 1/35.737
                                        * Referenced by: '<S16>/FeeedForward Gain6'
                                        */
  0.35032358132320696,                 /* Expression: 26.2/74.788
                                        * Referenced by: '<S16>/FeeedForward Gain7'
                                        */
  0.013371129058137669,                /* Expression: 1/74.788
                                        * Referenced by: '<S16>/FeeedForward Gain8'
                                        */
  0.34345625451916129,                 /* Expression: 17.1/49.788
                                        * Referenced by: '<S16>/FeeedForward Gain9'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain1'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain3'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain4'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain5'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain6'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain7'
                                        */
  6.666666666666667,                   /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain8'
                                        */

  /*  Expression: [0 0 0 0 0 0]
   * Referenced by: '<S2>/Control Signals'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant5'
                                        */

  /*  Computed Parameter: FIFOwrite1_P1_Size
   * Referenced by: '<S38>/FIFO write 1'
   */
  { 1.0, 1.0 },
  1024.0,                              /* Expression: size
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P2_Size
   * Referenced by: '<S38>/FIFO write 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputtype
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P3_Size
   * Referenced by: '<S38>/FIFO write 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P4_Size
   * Referenced by: '<S38>/FIFO write 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: present
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P5_Size
   * Referenced by: '<S38>/FIFO write 1'
   */
  { 1.0, 20.0 },

  /*  Computed Parameter: FIFOwrite1_P5
   * Referenced by: '<S38>/FIFO write 1'
   */
  { 82.0, 67.0, 86.0, 32.0, 99.0, 104.0, 97.0, 110.0, 110.0, 101.0, 108.0, 32.0,
    49.0, 44.0, 32.0, 73.0, 82.0, 81.0, 32.0, 52.0 },

  /*  Computed Parameter: FIFOread1_P1_Size
   * Referenced by: '<S40>/FIFO read 1'
   */
  { 1.0, 1.0 },
  60.0,                                /* Expression: maxsize
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P2_Size
   * Referenced by: '<S40>/FIFO read 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: minsize
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P3_Size
   * Referenced by: '<S40>/FIFO read 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: usedelimiter
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P4_Size
   * Referenced by: '<S40>/FIFO read 1'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: delimiter
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P5_Size
   * Referenced by: '<S40>/FIFO read 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: outputtype
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P6_Size
   * Referenced by: '<S40>/FIFO read 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P7_Size
   * Referenced by: '<S40>/FIFO read 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: enable
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P8_Size
   * Referenced by: '<S40>/FIFO read 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: enableout
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOwrite2_P1_Size
   * Referenced by: '<S39>/FIFO write 2'
   */
  { 1.0, 1.0 },
  1024.0,                              /* Expression: size
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P2_Size
   * Referenced by: '<S39>/FIFO write 2'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputtype
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P3_Size
   * Referenced by: '<S39>/FIFO write 2'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P4_Size
   * Referenced by: '<S39>/FIFO write 2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: present
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P5_Size
   * Referenced by: '<S39>/FIFO write 2'
   */
  { 1.0, 20.0 },

  /*  Computed Parameter: FIFOwrite2_P5
   * Referenced by: '<S39>/FIFO write 2'
   */
  { 82.0, 67.0, 86.0, 32.0, 99.0, 104.0, 97.0, 110.0, 110.0, 101.0, 108.0, 32.0,
    50.0, 44.0, 32.0, 73.0, 82.0, 81.0, 32.0, 52.0 },

  /*  Computed Parameter: FIFOread2_P1_Size
   * Referenced by: '<S41>/FIFO read 2'
   */
  { 1.0, 1.0 },
  60.0,                                /* Expression: maxsize
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P2_Size
   * Referenced by: '<S41>/FIFO read 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: minsize
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P3_Size
   * Referenced by: '<S41>/FIFO read 2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: usedelimiter
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P4_Size
   * Referenced by: '<S41>/FIFO read 2'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: delimiter
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P5_Size
   * Referenced by: '<S41>/FIFO read 2'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: outputtype
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P6_Size
   * Referenced by: '<S41>/FIFO read 2'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P7_Size
   * Referenced by: '<S41>/FIFO read 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: enable
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P8_Size
   * Referenced by: '<S41>/FIFO read 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: enableout
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/ControlConstant'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P1_Size
   * Referenced by: '<S6>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: firstChan
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P2_Size
   * Referenced by: '<S6>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  12.0,                                /* Expression: numChans
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P3_Size
   * Referenced by: '<S6>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  6.0,                                 /* Expression: range
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P4_Size
   * Referenced by: '<S6>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: MM16ATAnalogInput_P5_Size
   * Referenced by: '<S6>/MM-16-AT Analog Input'
   */
  { 1.0, 1.0 },
  768.0,                               /* Expression: baseDec
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */

  /*  Computed Parameter: DiscreteStateSpace5_A
   * Referenced by: '<S42>/Discrete State-Space5'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace5_B
   * Referenced by: '<S42>/Discrete State-Space5'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace5_C
   * Referenced by: '<S42>/Discrete State-Space5'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace5_D
                                        * Referenced by: '<S42>/Discrete State-Space5'
                                        */

  /*  Expression: IniStates(5,:)
   * Referenced by: '<S42>/Discrete State-Space5'
   */
  { 0.0, 0.0 },
  -67.813,                             /* Expression: -67.813
                                        * Referenced by: '<S42>/Gain11'
                                        */
  343.38,                              /* Expression: 343.38
                                        * Referenced by: '<S42>/Constant6'
                                        */

  /*  Computed Parameter: DiscreteStateSpace4_A
   * Referenced by: '<S42>/Discrete State-Space4'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace4_B
   * Referenced by: '<S42>/Discrete State-Space4'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace4_C
   * Referenced by: '<S42>/Discrete State-Space4'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace4_D
                                        * Referenced by: '<S42>/Discrete State-Space4'
                                        */

  /*  Expression: IniStates(5,:)
   * Referenced by: '<S42>/Discrete State-Space4'
   */
  { 0.0, 0.0 },
  -67.813,                             /* Expression: -67.813
                                        * Referenced by: '<S42>/Gain10'
                                        */
  343.38,                              /* Expression: 343.38
                                        * Referenced by: '<S42>/Constant5'
                                        */

  /*  Computed Parameter: DiscreteStateSpace3_A
   * Referenced by: '<S42>/Discrete State-Space3'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace3_B
   * Referenced by: '<S42>/Discrete State-Space3'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace3_C
   * Referenced by: '<S42>/Discrete State-Space3'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace3_D
                                        * Referenced by: '<S42>/Discrete State-Space3'
                                        */

  /*  Expression: IniStates(4,:)
   * Referenced by: '<S42>/Discrete State-Space3'
   */
  { 0.0, 0.0 },
  -67.813,                             /* Expression: -67.813
                                        * Referenced by: '<S42>/Gain9'
                                        */
  343.38,                              /* Expression: 343.38
                                        * Referenced by: '<S42>/Constant4'
                                        */

  /*  Computed Parameter: DiscreteStateSpace2_A
   * Referenced by: '<S42>/Discrete State-Space2'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace2_B
   * Referenced by: '<S42>/Discrete State-Space2'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace2_C
   * Referenced by: '<S42>/Discrete State-Space2'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace2_D
                                        * Referenced by: '<S42>/Discrete State-Space2'
                                        */

  /*  Expression: IniStates(3,:)
   * Referenced by: '<S42>/Discrete State-Space2'
   */
  { 0.0, 0.0 },
  -67.485,                             /* Expression: -67.485
                                        * Referenced by: '<S42>/Gain8'
                                        */
  338.48,                              /* Expression: 338.48
                                        * Referenced by: '<S42>/Constant3'
                                        */

  /*  Computed Parameter: DiscreteStateSpace1_A
   * Referenced by: '<S42>/Discrete State-Space1'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace1_B
   * Referenced by: '<S42>/Discrete State-Space1'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace1_C
   * Referenced by: '<S42>/Discrete State-Space1'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace1_D
                                        * Referenced by: '<S42>/Discrete State-Space1'
                                        */

  /*  Expression: IniStates(2,:)
   * Referenced by: '<S42>/Discrete State-Space1'
   */
  { 0.0, 0.0 },
  -67.813,                             /* Expression: -67.813
                                        * Referenced by: '<S42>/Gain1'
                                        */
  343.38,                              /* Expression: 343.38
                                        * Referenced by: '<S42>/Constant1'
                                        */

  /*  Computed Parameter: DiscreteStateSpace6_A
   * Referenced by: '<S42>/Discrete State-Space6'
   */
  { 0.82993828822616533, -0.11512995849846265, 0.11512995849846264,
    0.99275663697014283 },

  /*  Computed Parameter: DiscreteStateSpace6_B
   * Referenced by: '<S42>/Discrete State-Space6'
   */
  { 0.16281834874397741, 0.010243662234016042 },

  /*  Computed Parameter: DiscreteStateSpace6_C
   * Referenced by: '<S42>/Discrete State-Space6'
   */
  { 0.040704587185994359, 0.70454586562804355 },
  0.0036216815149286417,               /* Computed Parameter: DiscreteStateSpace6_D
                                        * Referenced by: '<S42>/Discrete State-Space6'
                                        */

  /*  Expression: IniStates(1,:)
   * Referenced by: '<S42>/Discrete State-Space6'
   */
  { 0.0, 0.0 },
  -67.813,                             /* Expression: -67.813
                                        * Referenced by: '<S42>/Gain'
                                        */
  343.38,                              /* Expression: 343.38
                                        * Referenced by: '<S42>/Constant2'
                                        */

  /*  Expression: [0 0 0 0 0 0]
   * Referenced by: '<Root>/Merge'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  80.0,                                /* Expression: Satura
                                        * Referenced by: '<S5>/Saturation'
                                        */
  -80.0,                               /* Expression: -Satura
                                        * Referenced by: '<S5>/Saturation'
                                        */
  80.0,                                /* Expression: Satura
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  -80.0,                               /* Expression: -Satura
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  80.0,                                /* Expression: Satura
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  -80.0,                               /* Expression: -Satura
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  80.0,                                /* Expression: Satura
                                        * Referenced by: '<S5>/Saturation3'
                                        */
  -80.0,                               /* Expression: -Satura
                                        * Referenced by: '<S5>/Saturation3'
                                        */
  80.0,                                /* Expression: Satura
                                        * Referenced by: '<S5>/Saturation4'
                                        */
  -80.0,                               /* Expression: -Satura
                                        * Referenced by: '<S5>/Saturation4'
                                        */
  80.0,                                /* Expression: Satura
                                        * Referenced by: '<S5>/Saturation5'
                                        */
  -80.0,                               /* Expression: -Satura
                                        * Referenced by: '<S5>/Saturation5'
                                        */

  /*  Computed Parameter: ASCIIEncode_P1_Size
   * Referenced by: '<S5>/ASCII Encode '
   */
  { 1.0, 13.0 },

  /*  Computed Parameter: ASCIIEncode_P1
   * Referenced by: '<S5>/ASCII Encode '
   */
  { 115.0, 37.0, 99.0, 37.0, 99.0, 37.0, 99.0, 37.0, 99.0, 37.0, 99.0, 37.0,
    99.0 },

  /*  Computed Parameter: ASCIIEncode_P2_Size
   * Referenced by: '<S5>/ASCII Encode '
   */
  { 1.0, 1.0 },
  9.0,                                 /* Expression: maxlength
                                        * Referenced by: '<S5>/ASCII Encode '
                                        */

  /*  Computed Parameter: ASCIIEncode_P3_Size
   * Referenced by: '<S5>/ASCII Encode '
   */
  { 1.0, 1.0 },
  6.0,                                 /* Expression: nvars
                                        * Referenced by: '<S5>/ASCII Encode '
                                        */

  /*  Computed Parameter: ASCIIEncode_P4_Size
   * Referenced by: '<S5>/ASCII Encode '
   */
  { 1.0, 6.0 },

  /*  Expression: varids
   * Referenced by: '<S5>/ASCII Encode '
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: FIFOwrite1_P1_Size_j
   * Referenced by: '<S24>/FIFO write 1'
   */
  { 1.0, 1.0 },
  1024.0,                              /* Expression: size
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P2_Size_b
   * Referenced by: '<S24>/FIFO write 1'
   */
  { 1.0, 1.0 },
  6.0,                                 /* Expression: inputtype
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P3_Size_f
   * Referenced by: '<S24>/FIFO write 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P4_Size_o
   * Referenced by: '<S24>/FIFO write 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: present
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */

  /*  Computed Parameter: FIFOwrite1_P5_Size_f
   * Referenced by: '<S24>/FIFO write 1'
   */
  { 1.0, 20.0 },

  /*  Computed Parameter: FIFOwrite1_P5_h
   * Referenced by: '<S24>/FIFO write 1'
   */
  { 88.0, 77.0, 84.0, 32.0, 99.0, 104.0, 97.0, 110.0, 110.0, 101.0, 108.0, 32.0,
    49.0, 44.0, 32.0, 73.0, 82.0, 81.0, 32.0, 52.0 },

  /*  Computed Parameter: FIFOwrite2_P1_Size_j
   * Referenced by: '<S24>/FIFO write 2'
   */
  { 1.0, 1.0 },
  1024.0,                              /* Expression: size
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P2_Size_a
   * Referenced by: '<S24>/FIFO write 2'
   */
  { 1.0, 1.0 },
  6.0,                                 /* Expression: inputtype
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P3_Size_e
   * Referenced by: '<S24>/FIFO write 2'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P4_Size_d
   * Referenced by: '<S24>/FIFO write 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: present
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */

  /*  Computed Parameter: FIFOwrite2_P5_Size_d
   * Referenced by: '<S24>/FIFO write 2'
   */
  { 1.0, 20.0 },

  /*  Computed Parameter: FIFOwrite2_P5_o
   * Referenced by: '<S24>/FIFO write 2'
   */
  { 88.0, 77.0, 84.0, 32.0, 99.0, 104.0, 97.0, 110.0, 110.0, 101.0, 108.0, 32.0,
    50.0, 44.0, 32.0, 73.0, 82.0, 81.0, 32.0, 52.0 },

  /*  Computed Parameter: FIFOread1_P1_Size_n
   * Referenced by: '<S24>/FIFO read 1'
   */
  { 1.0, 1.0 },
  1024.0,                              /* Expression: maxsize
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P2_Size_i
   * Referenced by: '<S24>/FIFO read 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: minsize
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P3_Size_l
   * Referenced by: '<S24>/FIFO read 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: usedelimiter
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P4_Size_c
   * Referenced by: '<S24>/FIFO read 1'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: delimiter
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P5_Size_b
   * Referenced by: '<S24>/FIFO read 1'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: outputtype
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P6_Size_g
   * Referenced by: '<S24>/FIFO read 1'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P7_Size_b
   * Referenced by: '<S24>/FIFO read 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: enable
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread1_P8_Size_p
   * Referenced by: '<S24>/FIFO read 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: enableout
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */

  /*  Computed Parameter: FIFOread2_P1_Size_d
   * Referenced by: '<S24>/FIFO read 2'
   */
  { 1.0, 1.0 },
  1024.0,                              /* Expression: maxsize
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P2_Size_g
   * Referenced by: '<S24>/FIFO read 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: minsize
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P3_Size_f
   * Referenced by: '<S24>/FIFO read 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: usedelimiter
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P4_Size_e
   * Referenced by: '<S24>/FIFO read 2'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: delimiter
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P5_Size_d
   * Referenced by: '<S24>/FIFO read 2'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: outputtype
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P6_Size_p
   * Referenced by: '<S24>/FIFO read 2'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P7_Size_n
   * Referenced by: '<S24>/FIFO read 2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: enable
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */

  /*  Computed Parameter: FIFOread2_P8_Size_k
   * Referenced by: '<S24>/FIFO read 2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: enableout
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */

  /*  Computed Parameter: Setup1_P1_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },
  1016.0,                              /* Expression: addr
                                        * Referenced by: '<S24>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P2_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: baud
                                        * Referenced by: '<S24>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P3_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: width
                                        * Referenced by: '<S24>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P4_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: nstop
                                        * Referenced by: '<S24>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P5_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: parity
                                        * Referenced by: '<S24>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P6_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: fmode
                                        * Referenced by: '<S24>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P7_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: ctsmode
                                        * Referenced by: '<S24>/Setup1'
                                        */

  /*  Computed Parameter: Setup1_P8_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: rlevel
                                        * Referenced by: '<S24>/Setup1'
                                        */

  /*  Computed Parameter: Setup2_P1_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: addr
                                        * Referenced by: '<S24>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P2_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: baud
                                        * Referenced by: '<S24>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P3_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: width
                                        * Referenced by: '<S24>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P4_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: nstop
                                        * Referenced by: '<S24>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P5_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: parity
                                        * Referenced by: '<S24>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P6_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: fmode
                                        * Referenced by: '<S24>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P7_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: ctsmode
                                        * Referenced by: '<S24>/Setup2'
                                        */

  /*  Computed Parameter: Setup2_P8_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: rlevel
                                        * Referenced by: '<S24>/Setup2'
                                        */
  3.75,                                /* Expression: 3.75
                                        * Referenced by: '<S42>/Gain2'
                                        */
  3.75,                                /* Expression: 3.75
                                        * Referenced by: '<S42>/Gain3'
                                        */
  3.75,                                /* Expression: 3.75
                                        * Referenced by: '<S42>/Gain4'
                                        */
  3.75,                                /* Expression: 3.75
                                        * Referenced by: '<S42>/Gain5'
                                        */
  3.75,                                /* Expression: 3.75
                                        * Referenced by: '<S42>/Gain6'
                                        */
  3.75,                                /* Expression: 3.75
                                        * Referenced by: '<S42>/Gain7'
                                        */
  1U,                                  /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S38>/Constant'
                                        */
  1U,                                  /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S40>/Constant1'
                                        */
  1U,                                  /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S39>/Constant'
                                        */
  1U,                                  /* Computed Parameter: Constant2_Value_h
                                        * Referenced by: '<S41>/Constant2'
                                        */

  /* Start of '<S5>/If Action Subsystem11' */
  {
    150.0,                             /* Expression: 150
                                        * Referenced by: '<S28>/Constant8'
                                        */
    -1.0                               /* Expression: -1
                                        * Referenced by: '<S28>/Gain'
                                        */
  }
  /* End of '<S5>/If Action Subsystem11' */
  ,

  /* Start of '<S5>/If Action Subsystem10' */
  {
    50.0                               /* Expression: 50
                                        * Referenced by: '<S27>/Constant8'
                                        */
  }
  /* End of '<S5>/If Action Subsystem10' */
  ,

  /* Start of '<S5>/If Action Subsystem9' */
  {
    150.0,                             /* Expression: 150
                                        * Referenced by: '<S36>/Constant8'
                                        */
    -1.0                               /* Expression: -1
                                        * Referenced by: '<S36>/Gain'
                                        */
  }
  /* End of '<S5>/If Action Subsystem9' */
  ,

  /* Start of '<S5>/If Action Subsystem8' */
  {
    50.0                               /* Expression: 50
                                        * Referenced by: '<S35>/Constant8'
                                        */
  }
  /* End of '<S5>/If Action Subsystem8' */
  ,

  /* Start of '<S5>/If Action Subsystem7' */
  {
    150.0,                             /* Expression: 150
                                        * Referenced by: '<S34>/Constant8'
                                        */
    -1.0                               /* Expression: -1
                                        * Referenced by: '<S34>/Gain'
                                        */
  }
  /* End of '<S5>/If Action Subsystem7' */
  ,

  /* Start of '<S5>/If Action Subsystem6' */
  {
    50.0                               /* Expression: 50
                                        * Referenced by: '<S33>/Constant8'
                                        */
  }
  /* End of '<S5>/If Action Subsystem6' */
  ,

  /* Start of '<S5>/If Action Subsystem5' */
  {
    150.0,                             /* Expression: 150
                                        * Referenced by: '<S32>/Constant8'
                                        */
    -1.0                               /* Expression: -1
                                        * Referenced by: '<S32>/Gain'
                                        */
  }
  /* End of '<S5>/If Action Subsystem5' */
  ,

  /* Start of '<S5>/If Action Subsystem4' */
  {
    50.0                               /* Expression: 50
                                        * Referenced by: '<S31>/Constant8'
                                        */
  }
  /* End of '<S5>/If Action Subsystem4' */
  ,

  /* Start of '<S5>/If Action Subsystem3' */
  {
    150.0,                             /* Expression: 150
                                        * Referenced by: '<S30>/Constant8'
                                        */
    -1.0                               /* Expression: -1
                                        * Referenced by: '<S30>/Gain'
                                        */
  }
  /* End of '<S5>/If Action Subsystem3' */
  ,

  /* Start of '<S5>/If Action Subsystem2' */
  {
    50.0                               /* Expression: 50
                                        * Referenced by: '<S29>/Constant8'
                                        */
  }
  /* End of '<S5>/If Action Subsystem2' */
  ,

  /* Start of '<S5>/If Action Subsystem1' */
  {
    150.0,                             /* Expression: 150
                                        * Referenced by: '<S26>/Constant8'
                                        */
    -1.0                               /* Expression: -1
                                        * Referenced by: '<S26>/Gain'
                                        */
  }
  /* End of '<S5>/If Action Subsystem1' */
  ,

  /* Start of '<S5>/If Action Subsystem' */
  {
    50.0                               /* Expression: 50
                                        * Referenced by: '<S25>/Constant8'
                                        */
  }
  /* End of '<S5>/If Action Subsystem' */
};
