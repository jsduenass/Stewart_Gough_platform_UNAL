/*
 * ReadAnalogInput.c
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

#include "rt_logging_mmi.h"
#include "ReadAnalogInput_capi.h"
#include "ReadAnalogInput.h"
#include "ReadAnalogInput_private.h"
#include <stdio.h>
#include "ReadAnalogInput_dt.h"

/* Block signals (auto storage) */
BlockIO_ReadAnalogInput ReadAnalogInput_B;

/* Block states (auto storage) */
D_Work_ReadAnalogInput ReadAnalogInput_DWork;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_ReadAnalogInput ReadAnalogInput_Y;

/* Real-time model */
rtModel_ReadAnalogInput ReadAnalogInput_rtM_;
rtModel_ReadAnalogInput *const ReadAnalogInput_rtM = &ReadAnalogInput_rtM_;

/* Model output function */
void ReadAnalogInput_output(int_T tid)
{
  /* Level2 S-Function Block: '<Root>/MM-16-AT Analog Input' (addiamondmm16atcustom) */
  {
    SimStruct *rts = ReadAnalogInput_rtM->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* Outport: '<Root>/Out1' */
  ReadAnalogInput_Y.Out1[0] = ReadAnalogInput_B.MM16ATAnalogInput_o1;
  ReadAnalogInput_Y.Out1[1] = ReadAnalogInput_B.MM16ATAnalogInput_o3;
  ReadAnalogInput_Y.Out1[2] = ReadAnalogInput_B.MM16ATAnalogInput_o5;
  ReadAnalogInput_Y.Out1[3] = ReadAnalogInput_B.MM16ATAnalogInput_o7;
  ReadAnalogInput_Y.Out1[4] = ReadAnalogInput_B.MM16ATAnalogInput_o9;
  ReadAnalogInput_Y.Out1[5] = ReadAnalogInput_B.MM16ATAnalogInput_o11;

  /* DiscreteStateSpace: '<Root>/Discrete State-Space6' */
  {
    ReadAnalogInput_B.DiscreteStateSpace6 =
      (ReadAnalogInput_P.DiscreteStateSpace6_C[0])*
      ReadAnalogInput_DWork.DiscreteStateSpace6_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace6_C[1])*
      ReadAnalogInput_DWork.DiscreteStateSpace6_DSTATE[1];
    ReadAnalogInput_B.DiscreteStateSpace6 +=
      ReadAnalogInput_P.DiscreteStateSpace6_D*
      ReadAnalogInput_B.MM16ATAnalogInput_o1;
  }

  /* DiscreteStateSpace: '<Root>/Discrete State-Space1' */
  {
    ReadAnalogInput_B.DiscreteStateSpace1 =
      (ReadAnalogInput_P.DiscreteStateSpace1_C[0])*
      ReadAnalogInput_DWork.DiscreteStateSpace1_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace1_C[1])*
      ReadAnalogInput_DWork.DiscreteStateSpace1_DSTATE[1];
    ReadAnalogInput_B.DiscreteStateSpace1 +=
      ReadAnalogInput_P.DiscreteStateSpace1_D*
      ReadAnalogInput_B.MM16ATAnalogInput_o3;
  }

  /* DiscreteStateSpace: '<Root>/Discrete State-Space2' */
  {
    ReadAnalogInput_B.DiscreteStateSpace2 =
      (ReadAnalogInput_P.DiscreteStateSpace2_C[0])*
      ReadAnalogInput_DWork.DiscreteStateSpace2_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace2_C[1])*
      ReadAnalogInput_DWork.DiscreteStateSpace2_DSTATE[1];
    ReadAnalogInput_B.DiscreteStateSpace2 +=
      ReadAnalogInput_P.DiscreteStateSpace2_D*
      ReadAnalogInput_B.MM16ATAnalogInput_o5;
  }

  /* DiscreteStateSpace: '<Root>/Discrete State-Space3' */
  {
    ReadAnalogInput_B.DiscreteStateSpace3 =
      (ReadAnalogInput_P.DiscreteStateSpace3_C[0])*
      ReadAnalogInput_DWork.DiscreteStateSpace3_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace3_C[1])*
      ReadAnalogInput_DWork.DiscreteStateSpace3_DSTATE[1];
    ReadAnalogInput_B.DiscreteStateSpace3 +=
      ReadAnalogInput_P.DiscreteStateSpace3_D*
      ReadAnalogInput_B.MM16ATAnalogInput_o7;
  }

  /* DiscreteStateSpace: '<Root>/Discrete State-Space4' */
  {
    ReadAnalogInput_B.DiscreteStateSpace4 =
      (ReadAnalogInput_P.DiscreteStateSpace4_C[0])*
      ReadAnalogInput_DWork.DiscreteStateSpace4_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace4_C[1])*
      ReadAnalogInput_DWork.DiscreteStateSpace4_DSTATE[1];
    ReadAnalogInput_B.DiscreteStateSpace4 +=
      ReadAnalogInput_P.DiscreteStateSpace4_D*
      ReadAnalogInput_B.MM16ATAnalogInput_o9;
  }

  /* DiscreteStateSpace: '<Root>/Discrete State-Space5' */
  {
    ReadAnalogInput_B.DiscreteStateSpace5 =
      (ReadAnalogInput_P.DiscreteStateSpace5_C[0])*
      ReadAnalogInput_DWork.DiscreteStateSpace5_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace5_C[1])*
      ReadAnalogInput_DWork.DiscreteStateSpace5_DSTATE[1];
    ReadAnalogInput_B.DiscreteStateSpace5 +=
      ReadAnalogInput_P.DiscreteStateSpace5_D*
      ReadAnalogInput_B.MM16ATAnalogInput_o11;
  }

  /* Outport: '<Root>/Out2' */
  ReadAnalogInput_Y.Out2[0] = ReadAnalogInput_B.DiscreteStateSpace6;
  ReadAnalogInput_Y.Out2[1] = ReadAnalogInput_B.DiscreteStateSpace1;
  ReadAnalogInput_Y.Out2[2] = ReadAnalogInput_B.DiscreteStateSpace2;
  ReadAnalogInput_Y.Out2[3] = ReadAnalogInput_B.DiscreteStateSpace3;
  ReadAnalogInput_Y.Out2[4] = ReadAnalogInput_B.DiscreteStateSpace4;
  ReadAnalogInput_Y.Out2[5] = ReadAnalogInput_B.DiscreteStateSpace5;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void ReadAnalogInput_update(int_T tid)
{
  /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space6' */
  {
    real_T xnew[2];
    xnew[0] = (ReadAnalogInput_P.DiscreteStateSpace6_A[0])*
      ReadAnalogInput_DWork.DiscreteStateSpace6_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace6_A[1])*
      ReadAnalogInput_DWork.DiscreteStateSpace6_DSTATE[1];
    xnew[0] += (ReadAnalogInput_P.DiscreteStateSpace6_B[0])*
      ReadAnalogInput_B.MM16ATAnalogInput_o1;
    xnew[1] = (ReadAnalogInput_P.DiscreteStateSpace6_A[2])*
      ReadAnalogInput_DWork.DiscreteStateSpace6_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace6_A[3])*
      ReadAnalogInput_DWork.DiscreteStateSpace6_DSTATE[1];
    xnew[1] += (ReadAnalogInput_P.DiscreteStateSpace6_B[1])*
      ReadAnalogInput_B.MM16ATAnalogInput_o1;
    (void) memcpy(&ReadAnalogInput_DWork.DiscreteStateSpace6_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space1' */
  {
    real_T xnew[2];
    xnew[0] = (ReadAnalogInput_P.DiscreteStateSpace1_A[0])*
      ReadAnalogInput_DWork.DiscreteStateSpace1_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace1_A[1])*
      ReadAnalogInput_DWork.DiscreteStateSpace1_DSTATE[1];
    xnew[0] += (ReadAnalogInput_P.DiscreteStateSpace1_B[0])*
      ReadAnalogInput_B.MM16ATAnalogInput_o3;
    xnew[1] = (ReadAnalogInput_P.DiscreteStateSpace1_A[2])*
      ReadAnalogInput_DWork.DiscreteStateSpace1_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace1_A[3])*
      ReadAnalogInput_DWork.DiscreteStateSpace1_DSTATE[1];
    xnew[1] += (ReadAnalogInput_P.DiscreteStateSpace1_B[1])*
      ReadAnalogInput_B.MM16ATAnalogInput_o3;
    (void) memcpy(&ReadAnalogInput_DWork.DiscreteStateSpace1_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space2' */
  {
    real_T xnew[2];
    xnew[0] = (ReadAnalogInput_P.DiscreteStateSpace2_A[0])*
      ReadAnalogInput_DWork.DiscreteStateSpace2_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace2_A[1])*
      ReadAnalogInput_DWork.DiscreteStateSpace2_DSTATE[1];
    xnew[0] += (ReadAnalogInput_P.DiscreteStateSpace2_B[0])*
      ReadAnalogInput_B.MM16ATAnalogInput_o5;
    xnew[1] = (ReadAnalogInput_P.DiscreteStateSpace2_A[2])*
      ReadAnalogInput_DWork.DiscreteStateSpace2_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace2_A[3])*
      ReadAnalogInput_DWork.DiscreteStateSpace2_DSTATE[1];
    xnew[1] += (ReadAnalogInput_P.DiscreteStateSpace2_B[1])*
      ReadAnalogInput_B.MM16ATAnalogInput_o5;
    (void) memcpy(&ReadAnalogInput_DWork.DiscreteStateSpace2_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space3' */
  {
    real_T xnew[2];
    xnew[0] = (ReadAnalogInput_P.DiscreteStateSpace3_A[0])*
      ReadAnalogInput_DWork.DiscreteStateSpace3_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace3_A[1])*
      ReadAnalogInput_DWork.DiscreteStateSpace3_DSTATE[1];
    xnew[0] += (ReadAnalogInput_P.DiscreteStateSpace3_B[0])*
      ReadAnalogInput_B.MM16ATAnalogInput_o7;
    xnew[1] = (ReadAnalogInput_P.DiscreteStateSpace3_A[2])*
      ReadAnalogInput_DWork.DiscreteStateSpace3_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace3_A[3])*
      ReadAnalogInput_DWork.DiscreteStateSpace3_DSTATE[1];
    xnew[1] += (ReadAnalogInput_P.DiscreteStateSpace3_B[1])*
      ReadAnalogInput_B.MM16ATAnalogInput_o7;
    (void) memcpy(&ReadAnalogInput_DWork.DiscreteStateSpace3_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space4' */
  {
    real_T xnew[2];
    xnew[0] = (ReadAnalogInput_P.DiscreteStateSpace4_A[0])*
      ReadAnalogInput_DWork.DiscreteStateSpace4_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace4_A[1])*
      ReadAnalogInput_DWork.DiscreteStateSpace4_DSTATE[1];
    xnew[0] += (ReadAnalogInput_P.DiscreteStateSpace4_B[0])*
      ReadAnalogInput_B.MM16ATAnalogInput_o9;
    xnew[1] = (ReadAnalogInput_P.DiscreteStateSpace4_A[2])*
      ReadAnalogInput_DWork.DiscreteStateSpace4_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace4_A[3])*
      ReadAnalogInput_DWork.DiscreteStateSpace4_DSTATE[1];
    xnew[1] += (ReadAnalogInput_P.DiscreteStateSpace4_B[1])*
      ReadAnalogInput_B.MM16ATAnalogInput_o9;
    (void) memcpy(&ReadAnalogInput_DWork.DiscreteStateSpace4_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space5' */
  {
    real_T xnew[2];
    xnew[0] = (ReadAnalogInput_P.DiscreteStateSpace5_A[0])*
      ReadAnalogInput_DWork.DiscreteStateSpace5_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace5_A[1])*
      ReadAnalogInput_DWork.DiscreteStateSpace5_DSTATE[1];
    xnew[0] += (ReadAnalogInput_P.DiscreteStateSpace5_B[0])*
      ReadAnalogInput_B.MM16ATAnalogInput_o11;
    xnew[1] = (ReadAnalogInput_P.DiscreteStateSpace5_A[2])*
      ReadAnalogInput_DWork.DiscreteStateSpace5_DSTATE[0]
      + (ReadAnalogInput_P.DiscreteStateSpace5_A[3])*
      ReadAnalogInput_DWork.DiscreteStateSpace5_DSTATE[1];
    xnew[1] += (ReadAnalogInput_P.DiscreteStateSpace5_B[1])*
      ReadAnalogInput_B.MM16ATAnalogInput_o11;
    (void) memcpy(&ReadAnalogInput_DWork.DiscreteStateSpace5_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ReadAnalogInput_rtM->Timing.clockTick0)) {
    ++ReadAnalogInput_rtM->Timing.clockTickH0;
  }

  ReadAnalogInput_rtM->Timing.t[0] = ReadAnalogInput_rtM->Timing.clockTick0 *
    ReadAnalogInput_rtM->Timing.stepSize0 +
    ReadAnalogInput_rtM->Timing.clockTickH0 *
    ReadAnalogInput_rtM->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void ReadAnalogInput_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ReadAnalogInput_rtM, 0,
                sizeof(rtModel_ReadAnalogInput));
  rtsiSetSolverName(&ReadAnalogInput_rtM->solverInfo,"FixedStepDiscrete");
  ReadAnalogInput_rtM->solverInfoPtr = (&ReadAnalogInput_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ReadAnalogInput_rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    ReadAnalogInput_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ReadAnalogInput_rtM->Timing.sampleTimes =
      (&ReadAnalogInput_rtM->Timing.sampleTimesArray[0]);
    ReadAnalogInput_rtM->Timing.offsetTimes =
      (&ReadAnalogInput_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    ReadAnalogInput_rtM->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    ReadAnalogInput_rtM->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(ReadAnalogInput_rtM, &ReadAnalogInput_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ReadAnalogInput_rtM->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    ReadAnalogInput_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ReadAnalogInput_rtM, 3600.0);
  ReadAnalogInput_rtM->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ReadAnalogInput_rtM->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ReadAnalogInput_rtM->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ReadAnalogInput_rtM->rtwLogInfo, (NULL));
    rtliSetLogT(ReadAnalogInput_rtM->rtwLogInfo, "tout");
    rtliSetLogX(ReadAnalogInput_rtM->rtwLogInfo, "");
    rtliSetLogXFinal(ReadAnalogInput_rtM->rtwLogInfo, "");
    rtliSetSigLog(ReadAnalogInput_rtM->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ReadAnalogInput_rtM->rtwLogInfo, "rt_");
    rtliSetLogFormat(ReadAnalogInput_rtM->rtwLogInfo, 0);
    rtliSetLogMaxRows(ReadAnalogInput_rtM->rtwLogInfo, 0);
    rtliSetLogDecimation(ReadAnalogInput_rtM->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &ReadAnalogInput_Y.Out1[0],
        &ReadAnalogInput_Y.Out2[0]
      };

      rtliSetLogYSignalPtrs(ReadAnalogInput_rtM->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        6,
        6
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        6,
        6
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static int_T* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL)
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "ReadAnalogInput/Out1",
        "ReadAnalogInput/Out2" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(ReadAnalogInput_rtM->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(ReadAnalogInput_rtM->rtwLogInfo, "yout");
  }

  /* external mode info */
  ReadAnalogInput_rtM->Sizes.checksums[0] = (2123821814U);
  ReadAnalogInput_rtM->Sizes.checksums[1] = (1806069684U);
  ReadAnalogInput_rtM->Sizes.checksums[2] = (3342642078U);
  ReadAnalogInput_rtM->Sizes.checksums[3] = (1821963508U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ReadAnalogInput_rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ReadAnalogInput_rtM->extModeInfo,
      &ReadAnalogInput_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ReadAnalogInput_rtM->extModeInfo,
                        ReadAnalogInput_rtM->Sizes.checksums);
    rteiSetTPtr(ReadAnalogInput_rtM->extModeInfo, rtmGetTPtr(ReadAnalogInput_rtM));
  }

  ReadAnalogInput_rtM->solverInfoPtr = (&ReadAnalogInput_rtM->solverInfo);
  ReadAnalogInput_rtM->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&ReadAnalogInput_rtM->solverInfo, 0.001);
  rtsiSetSolverMode(&ReadAnalogInput_rtM->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ReadAnalogInput_rtM->ModelData.blockIO = ((void *) &ReadAnalogInput_B);
  (void) memset(((void *) &ReadAnalogInput_B), 0,
                sizeof(BlockIO_ReadAnalogInput));

  /* parameters */
  ReadAnalogInput_rtM->ModelData.defaultParam = ((real_T *)&ReadAnalogInput_P);

  /* states (dwork) */
  ReadAnalogInput_rtM->Work.dwork = ((void *) &ReadAnalogInput_DWork);
  (void) memset((void *)&ReadAnalogInput_DWork, 0,
                sizeof(D_Work_ReadAnalogInput));

  /* external outputs */
  ReadAnalogInput_rtM->ModelData.outputs = (&ReadAnalogInput_Y);
  (void) memset((void *)&ReadAnalogInput_Y, 0,
                sizeof(ExternalOutputs_ReadAnalogInput));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ReadAnalogInput_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    ReadAnalogInput_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  ReadAnalogInput_InitializeDataMapInfo(ReadAnalogInput_rtM);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &ReadAnalogInput_rtM->NonInlinedSFcns.sfcnInfo;
    ReadAnalogInput_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(ReadAnalogInput_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &ReadAnalogInput_rtM->Sizes.numSampTimes);
    ReadAnalogInput_rtM->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (ReadAnalogInput_rtM)[0]);
    rtssSetTPtrPtr(sfcnInfo,ReadAnalogInput_rtM->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(ReadAnalogInput_rtM));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(ReadAnalogInput_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (ReadAnalogInput_rtM));
    rtssSetStepSizePtr(sfcnInfo, &ReadAnalogInput_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(ReadAnalogInput_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &ReadAnalogInput_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &ReadAnalogInput_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &ReadAnalogInput_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &ReadAnalogInput_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &ReadAnalogInput_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &ReadAnalogInput_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &ReadAnalogInput_rtM->solverInfoPtr);
  }

  ReadAnalogInput_rtM->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&ReadAnalogInput_rtM->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  1*sizeof(SimStruct));
    ReadAnalogInput_rtM->childSfunctions =
      (&ReadAnalogInput_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);
    ReadAnalogInput_rtM->childSfunctions[0] =
      (&ReadAnalogInput_rtM->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: ReadAnalogInput/<Root>/MM-16-AT Analog Input (addiamondmm16atcustom) */
    {
      SimStruct *rts = ReadAnalogInput_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = ReadAnalogInput_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = ReadAnalogInput_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = ReadAnalogInput_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ReadAnalogInput_rtM->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, ReadAnalogInput_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ReadAnalogInput_rtM->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ReadAnalogInput_rtM->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &ReadAnalogInput_rtM->NonInlinedSFcns.statesInfo2
                         [0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ReadAnalogInput_rtM->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 12);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &ReadAnalogInput_B.MM16ATAnalogInput_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &ReadAnalogInput_B.MM16ATAnalogInput_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &ReadAnalogInput_B.MM16ATAnalogInput_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &ReadAnalogInput_B.MM16ATAnalogInput_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &ReadAnalogInput_B.MM16ATAnalogInput_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &ReadAnalogInput_B.MM16ATAnalogInput_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &ReadAnalogInput_B.MM16ATAnalogInput_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &ReadAnalogInput_B.MM16ATAnalogInput_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((real_T *)
            &ReadAnalogInput_B.MM16ATAnalogInput_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((real_T *)
            &ReadAnalogInput_B.MM16ATAnalogInput_o10));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((real_T *)
            &ReadAnalogInput_B.MM16ATAnalogInput_o11));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((real_T *)
            &ReadAnalogInput_B.MM16ATAnalogInput_o12));
        }
      }

      /* path info */
      ssSetModelName(rts, "MM-16-AT Analog Input");
      ssSetPath(rts, "ReadAnalogInput/MM-16-AT Analog Input");
      ssSetRTModel(rts,ReadAnalogInput_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ReadAnalogInput_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       ReadAnalogInput_P.MM16ATAnalogInput_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       ReadAnalogInput_P.MM16ATAnalogInput_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       ReadAnalogInput_P.MM16ATAnalogInput_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       ReadAnalogInput_P.MM16ATAnalogInput_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       ReadAnalogInput_P.MM16ATAnalogInput_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &ReadAnalogInput_DWork.MM16ATAnalogInput_RWORK
                 [0]);
      ssSetIWork(rts, (int_T *) &ReadAnalogInput_DWork.MM16ATAnalogInput_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ReadAnalogInput_rtM->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &ReadAnalogInput_rtM->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ReadAnalogInput_DWork.MM16ATAnalogInput_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &ReadAnalogInput_DWork.MM16ATAnalogInput_IWORK);
      }

      /* registration */
      addiamondmm16atcustom(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 0);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 0);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 0);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortConnected(rts, 9, 0);
      _ssSetOutputPortConnected(rts, 10, 1);
      _ssSetOutputPortConnected(rts, 11, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);
      _ssSetOutputPortBeingMerged(rts, 9, 0);
      _ssSetOutputPortBeingMerged(rts, 10, 0);
      _ssSetOutputPortBeingMerged(rts, 11, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }
}

/* Model terminate function */
void ReadAnalogInput_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/MM-16-AT Analog Input' (addiamondmm16atcustom) */
  {
    SimStruct *rts = ReadAnalogInput_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  ReadAnalogInput_output(tid);
}

void MdlUpdate(int_T tid)
{
  ReadAnalogInput_update(tid);
}

void MdlInitializeSizes(void)
{
  ReadAnalogInput_rtM->Sizes.numContStates = (0);/* Number of continuous states */
  ReadAnalogInput_rtM->Sizes.numY = (12);/* Number of model outputs */
  ReadAnalogInput_rtM->Sizes.numU = (0);/* Number of model inputs */
  ReadAnalogInput_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ReadAnalogInput_rtM->Sizes.numSampTimes = (1);/* Number of sample times */
  ReadAnalogInput_rtM->Sizes.numBlocks = (9);/* Number of blocks */
  ReadAnalogInput_rtM->Sizes.numBlockIO = (18);/* Number of block outputs */
  ReadAnalogInput_rtM->Sizes.numBlockPrms = (81);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space6' */
  ReadAnalogInput_DWork.DiscreteStateSpace6_DSTATE[0] =
    ReadAnalogInput_P.DiscreteStateSpace6_X0[0];
  ReadAnalogInput_DWork.DiscreteStateSpace6_DSTATE[1] =
    ReadAnalogInput_P.DiscreteStateSpace6_X0[1];

  /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space1' */
  ReadAnalogInput_DWork.DiscreteStateSpace1_DSTATE[0] =
    ReadAnalogInput_P.DiscreteStateSpace1_X0[0];
  ReadAnalogInput_DWork.DiscreteStateSpace1_DSTATE[1] =
    ReadAnalogInput_P.DiscreteStateSpace1_X0[1];

  /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space2' */
  ReadAnalogInput_DWork.DiscreteStateSpace2_DSTATE[0] =
    ReadAnalogInput_P.DiscreteStateSpace2_X0[0];
  ReadAnalogInput_DWork.DiscreteStateSpace2_DSTATE[1] =
    ReadAnalogInput_P.DiscreteStateSpace2_X0[1];

  /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space3' */
  ReadAnalogInput_DWork.DiscreteStateSpace3_DSTATE[0] =
    ReadAnalogInput_P.DiscreteStateSpace3_X0[0];
  ReadAnalogInput_DWork.DiscreteStateSpace3_DSTATE[1] =
    ReadAnalogInput_P.DiscreteStateSpace3_X0[1];

  /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space4' */
  ReadAnalogInput_DWork.DiscreteStateSpace4_DSTATE[0] =
    ReadAnalogInput_P.DiscreteStateSpace4_X0[0];
  ReadAnalogInput_DWork.DiscreteStateSpace4_DSTATE[1] =
    ReadAnalogInput_P.DiscreteStateSpace4_X0[1];

  /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space5' */
  ReadAnalogInput_DWork.DiscreteStateSpace5_DSTATE[0] =
    ReadAnalogInput_P.DiscreteStateSpace5_X0[0];
  ReadAnalogInput_DWork.DiscreteStateSpace5_DSTATE[1] =
    ReadAnalogInput_P.DiscreteStateSpace5_X0[1];
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<Root>/MM-16-AT Analog Input' (addiamondmm16atcustom) */
  {
    SimStruct *rts = ReadAnalogInput_rtM->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  ReadAnalogInput_terminate();
}

rtModel_ReadAnalogInput *ReadAnalogInput(void)
{
  ReadAnalogInput_initialize(1);
  return ReadAnalogInput_rtM;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
