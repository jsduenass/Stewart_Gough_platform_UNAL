/*
 * ReadAnalogInput_capi.c
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
#include "rtw_capi.h"
#include "ReadAnalogInput_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Discrete State-Space1",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Discrete State-Space2",
    "", 0, 0, 0, 0, 0 },

  { 2, 0, "Discrete State-Space3",
    "", 0, 0, 0, 0, 0 },

  { 3, 0, "Discrete State-Space4",
    "", 0, 0, 0, 0, 0 },

  { 4, 0, "Discrete State-Space5",
    "", 0, 0, 0, 0, 0 },

  { 5, 0, "Discrete State-Space6",
    "", 0, 0, 0, 0, 0 },

  { 6, 0, "MM-16-AT Analog Input/p1",
    "", 0, 0, 0, 0, 0 },

  { 7, 0, "MM-16-AT Analog Input/p2",
    "", 1, 0, 0, 0, 0 },

  { 8, 0, "MM-16-AT Analog Input/p3",
    "", 2, 0, 0, 0, 0 },

  { 9, 0, "MM-16-AT Analog Input/p4",
    "", 3, 0, 0, 0, 0 },

  { 10, 0, "MM-16-AT Analog Input/p5",
    "", 4, 0, 0, 0, 0 },

  { 11, 0, "MM-16-AT Analog Input/p6",
    "", 5, 0, 0, 0, 0 },

  { 12, 0, "MM-16-AT Analog Input/p7",
    "", 6, 0, 0, 0, 0 },

  { 13, 0, "MM-16-AT Analog Input/p8",
    "", 7, 0, 0, 0, 0 },

  { 14, 0, "MM-16-AT Analog Input/p9",
    "", 8, 0, 0, 0, 0 },

  { 15, 0, "MM-16-AT Analog Input/p10",
    "", 9, 0, 0, 0, 0 },

  { 16, 0, "MM-16-AT Analog Input/p11",
    "", 10, 0, 0, 0, 0 },

  { 17, 0, "MM-16-AT Analog Input/p12",
    "", 11, 0, 0, 0, 0 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 18, "Discrete State-Space1",
    "A", 0, 1, 0 },

  { 19, "Discrete State-Space1",
    "B", 0, 2, 0 },

  { 20, "Discrete State-Space1",
    "C", 0, 2, 0 },

  { 21, "Discrete State-Space1",
    "D", 0, 0, 0 },

  { 22, "Discrete State-Space1",
    "X0", 0, 3, 0 },

  { 23, "Discrete State-Space2",
    "A", 0, 1, 0 },

  { 24, "Discrete State-Space2",
    "B", 0, 2, 0 },

  { 25, "Discrete State-Space2",
    "C", 0, 2, 0 },

  { 26, "Discrete State-Space2",
    "D", 0, 0, 0 },

  { 27, "Discrete State-Space2",
    "X0", 0, 3, 0 },

  { 28, "Discrete State-Space3",
    "A", 0, 1, 0 },

  { 29, "Discrete State-Space3",
    "B", 0, 2, 0 },

  { 30, "Discrete State-Space3",
    "C", 0, 2, 0 },

  { 31, "Discrete State-Space3",
    "D", 0, 0, 0 },

  { 32, "Discrete State-Space3",
    "X0", 0, 3, 0 },

  { 33, "Discrete State-Space4",
    "A", 0, 1, 0 },

  { 34, "Discrete State-Space4",
    "B", 0, 2, 0 },

  { 35, "Discrete State-Space4",
    "C", 0, 2, 0 },

  { 36, "Discrete State-Space4",
    "D", 0, 0, 0 },

  { 37, "Discrete State-Space4",
    "X0", 0, 3, 0 },

  { 38, "Discrete State-Space5",
    "A", 0, 1, 0 },

  { 39, "Discrete State-Space5",
    "B", 0, 2, 0 },

  { 40, "Discrete State-Space5",
    "C", 0, 2, 0 },

  { 41, "Discrete State-Space5",
    "D", 0, 0, 0 },

  { 42, "Discrete State-Space5",
    "X0", 0, 3, 0 },

  { 43, "Discrete State-Space6",
    "A", 0, 1, 0 },

  { 44, "Discrete State-Space6",
    "B", 0, 2, 0 },

  { 45, "Discrete State-Space6",
    "C", 0, 2, 0 },

  { 46, "Discrete State-Space6",
    "D", 0, 0, 0 },

  { 47, "Discrete State-Space6",
    "X0", 0, 3, 0 },

  { 48, "MM-16-AT Analog Input",
    "P1", 0, 0, 0 },

  { 49, "MM-16-AT Analog Input",
    "P2", 0, 0, 0 },

  { 50, "MM-16-AT Analog Input",
    "P3", 0, 0, 0 },

  { 51, "MM-16-AT Analog Input",
    "P4", 0, 0, 0 },

  { 52, "MM-16-AT Analog Input",
    "P5", 0, 0, 0 },

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
  &ReadAnalogInput_B.DiscreteStateSpace1,/* 0: Signal */
  &ReadAnalogInput_B.DiscreteStateSpace2,/* 1: Signal */
  &ReadAnalogInput_B.DiscreteStateSpace3,/* 2: Signal */
  &ReadAnalogInput_B.DiscreteStateSpace4,/* 3: Signal */
  &ReadAnalogInput_B.DiscreteStateSpace5,/* 4: Signal */
  &ReadAnalogInput_B.DiscreteStateSpace6,/* 5: Signal */
  &ReadAnalogInput_B.MM16ATAnalogInput_o1,/* 6: Signal */
  &ReadAnalogInput_B.MM16ATAnalogInput_o2,/* 7: Signal */
  &ReadAnalogInput_B.MM16ATAnalogInput_o3,/* 8: Signal */
  &ReadAnalogInput_B.MM16ATAnalogInput_o4,/* 9: Signal */
  &ReadAnalogInput_B.MM16ATAnalogInput_o5,/* 10: Signal */
  &ReadAnalogInput_B.MM16ATAnalogInput_o6,/* 11: Signal */
  &ReadAnalogInput_B.MM16ATAnalogInput_o7,/* 12: Signal */
  &ReadAnalogInput_B.MM16ATAnalogInput_o8,/* 13: Signal */
  &ReadAnalogInput_B.MM16ATAnalogInput_o9,/* 14: Signal */
  &ReadAnalogInput_B.MM16ATAnalogInput_o10,/* 15: Signal */
  &ReadAnalogInput_B.MM16ATAnalogInput_o11,/* 16: Signal */
  &ReadAnalogInput_B.MM16ATAnalogInput_o12,/* 17: Signal */
  &ReadAnalogInput_P.DiscreteStateSpace1_A[0],/* 18: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace1_B[0],/* 19: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace1_C[0],/* 20: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace1_D,/* 21: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace1_X0[0],/* 22: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace2_A[0],/* 23: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace2_B[0],/* 24: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace2_C[0],/* 25: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace2_D,/* 26: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace2_X0[0],/* 27: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace3_A[0],/* 28: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace3_B[0],/* 29: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace3_C[0],/* 30: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace3_D,/* 31: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace3_X0[0],/* 32: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace4_A[0],/* 33: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace4_B[0],/* 34: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace4_C[0],/* 35: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace4_D,/* 36: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace4_X0[0],/* 37: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace5_A[0],/* 38: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace5_B[0],/* 39: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace5_C[0],/* 40: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace5_D,/* 41: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace5_X0[0],/* 42: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace6_A[0],/* 43: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace6_B[0],/* 44: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace6_C[0],/* 45: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace6_D,/* 46: Block Parameter */
  &ReadAnalogInput_P.DiscreteStateSpace6_X0[0],/* 47: Block Parameter */
  &ReadAnalogInput_P.MM16ATAnalogInput_P1,/* 48: Block Parameter */
  &ReadAnalogInput_P.MM16ATAnalogInput_P2,/* 49: Block Parameter */
  &ReadAnalogInput_P.MM16ATAnalogInput_P3,/* 50: Block Parameter */
  &ReadAnalogInput_P.MM16ATAnalogInput_P4,/* 51: Block Parameter */
  &ReadAnalogInput_P.MM16ATAnalogInput_P5/* 52: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 }
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

  { rtwCAPI_VECTOR, 6, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  4,                                   /* 2 */
  1,                                   /* 3 */
  2,                                   /* 4 */
  1,                                   /* 5 */
  1,                                   /* 6 */
  2                                    /* 7 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0
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
    0, 0 }
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
  { rtBlockSignals, 18 },

  { rtBlockParameters, 35,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void ReadAnalogInput_InitializeDataMapInfo(rtModel_ReadAnalogInput
  *ReadAnalogInput_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(ReadAnalogInput_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(ReadAnalogInput_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(ReadAnalogInput_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(ReadAnalogInput_rtM->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(ReadAnalogInput_rtM->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(ReadAnalogInput_rtM->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(ReadAnalogInput_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(ReadAnalogInput_rtM->DataMapInfo.mmi, 0);
}

/* EOF: ReadAnalogInput_capi.c */
