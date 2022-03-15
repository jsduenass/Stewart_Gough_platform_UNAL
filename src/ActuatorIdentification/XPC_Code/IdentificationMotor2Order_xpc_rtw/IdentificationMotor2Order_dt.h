/*
 * IdentificationMotor2Order_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(serialfifoptr)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "serialfifoptr"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&IdentificationMotor2Order_B.FIFOwrite1_o1), 14, 0, 8 },

  { (char_T *)(&IdentificationMotor2Order_B.MM16ATAnalogInput_o1), 0, 0, 50 },

  { (char_T *)(&IdentificationMotor2Order_B.ReadIntStatusFC1_o2), 7, 0, 255 },

  { (char_T *)(&IdentificationMotor2Order_B.FIFOread1[0]), 5, 0, 2050 },

  { (char_T *)(&IdentificationMotor2Order_B.ASCIIEncode[0]), 3, 0, 9 },

  { (char_T *)(&IdentificationMotor2Order_B.FIFOwrite1_o2), 8, 0, 2 },

  { (char_T *)(&IdentificationMotor2Order_B.IfActionSubsystem11.Gain), 0, 0, 2 },

  { (char_T *)(&IdentificationMotor2Order_B.IfActionSubsystem10.Sum), 0, 0, 1 },

  { (char_T *)(&IdentificationMotor2Order_B.IfActionSubsystem9.Gain), 0, 0, 2 },

  { (char_T *)(&IdentificationMotor2Order_B.IfActionSubsystem8.Sum), 0, 0, 1 },

  { (char_T *)(&IdentificationMotor2Order_B.IfActionSubsystem7.Gain), 0, 0, 2 },

  { (char_T *)(&IdentificationMotor2Order_B.IfActionSubsystem6.Sum), 0, 0, 1 },

  { (char_T *)(&IdentificationMotor2Order_B.IfActionSubsystem5.Gain), 0, 0, 2 },

  { (char_T *)(&IdentificationMotor2Order_B.IfActionSubsystem4.Sum), 0, 0, 1 },

  { (char_T *)(&IdentificationMotor2Order_B.IfActionSubsystem3.Gain), 0, 0, 2 },

  { (char_T *)(&IdentificationMotor2Order_B.IfActionSubsystem2.Sum), 0, 0, 1 },

  { (char_T *)(&IdentificationMotor2Order_B.IfActionSubsystem1.Gain), 0, 0, 2 },

  { (char_T *)(&IdentificationMotor2Order_B.IfActionSubsystem.Sum), 0, 0, 1 }
  ,

  { (char_T *)(&IdentificationMotor2Order_DWork.DiscreteStateSpace6_DSTATE[0]),
    0, 0, 14 },

  { (char_T *)(&IdentificationMotor2Order_DWork.Velocityreference2_PWORK.TimePtr),
    11, 0, 6 },

  { (char_T *)(&IdentificationMotor2Order_DWork.MM16ATAnalogInput_IWORK), 10, 0,
    26 },

  { (char_T *)(&IdentificationMotor2Order_DWork.RS232ISR_SubsysRanBC), 2, 0, 5 },

  { (char_T *)
    (&IdentificationMotor2Order_DWork.IfActionSubsystem11.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&IdentificationMotor2Order_DWork.IfActionSubsystem10.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&IdentificationMotor2Order_DWork.IfActionSubsystem9.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&IdentificationMotor2Order_DWork.IfActionSubsystem8.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&IdentificationMotor2Order_DWork.IfActionSubsystem7.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&IdentificationMotor2Order_DWork.IfActionSubsystem6.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&IdentificationMotor2Order_DWork.IfActionSubsystem5.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&IdentificationMotor2Order_DWork.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&IdentificationMotor2Order_DWork.IfActionSubsystem3.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&IdentificationMotor2Order_DWork.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&IdentificationMotor2Order_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&IdentificationMotor2Order_DWork.IfActionSubsystem.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  34U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&IdentificationMotor2Order_P.FIFOwrite1_P1_Size[0]), 0, 0, 426 },

  { (char_T *)(&IdentificationMotor2Order_P.Constant_Value_o), 7, 0, 4 },

  { (char_T *)(&IdentificationMotor2Order_P.IfActionSubsystem11.Constant8_Value),
    0, 0, 2 },

  { (char_T *)(&IdentificationMotor2Order_P.IfActionSubsystem10.Constant8_Value),
    0, 0, 1 },

  { (char_T *)(&IdentificationMotor2Order_P.IfActionSubsystem9.Constant8_Value),
    0, 0, 2 },

  { (char_T *)(&IdentificationMotor2Order_P.IfActionSubsystem8.Constant8_Value),
    0, 0, 1 },

  { (char_T *)(&IdentificationMotor2Order_P.IfActionSubsystem7.Constant8_Value),
    0, 0, 2 },

  { (char_T *)(&IdentificationMotor2Order_P.IfActionSubsystem6.Constant8_Value),
    0, 0, 1 },

  { (char_T *)(&IdentificationMotor2Order_P.IfActionSubsystem5.Constant8_Value),
    0, 0, 2 },

  { (char_T *)(&IdentificationMotor2Order_P.IfActionSubsystem4.Constant8_Value),
    0, 0, 1 },

  { (char_T *)(&IdentificationMotor2Order_P.IfActionSubsystem3.Constant8_Value),
    0, 0, 2 },

  { (char_T *)(&IdentificationMotor2Order_P.IfActionSubsystem2.Constant8_Value),
    0, 0, 1 },

  { (char_T *)(&IdentificationMotor2Order_P.IfActionSubsystem1.Constant8_Value),
    0, 0, 2 },

  { (char_T *)(&IdentificationMotor2Order_P.IfActionSubsystem.Constant8_Value),
    0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  14U,
  rtPTransitions
};

/* [EOF] IdentificationMotor2Order_dt.h */
