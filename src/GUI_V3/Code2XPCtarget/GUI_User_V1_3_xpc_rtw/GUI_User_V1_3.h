/*
 * GUI_User_V1_3.h
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
#ifndef RTW_HEADER_GUI_User_V1_3_h_
#define RTW_HEADER_GUI_User_V1_3_h_
#include "rtw_modelmap.h"
#ifndef GUI_User_V1_3_COMMON_INCLUDES_
# define GUI_User_V1_3_COMMON_INCLUDES_
#include <serialdefines.h>
#include <xpctarget.h>
#include <xpcdatatypes.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rt_nonfinite.h"
#endif                                 /* GUI_User_V1_3_COMMON_INCLUDES_ */

#include "GUI_User_V1_3_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define GUI_User_V1_3_rtModel          rtModel_GUI_User_V1_3

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals for system '<S5>/If Action Subsystem' */
typedef struct {
  real_T Sum;                          /* '<S25>/Sum' */
} rtB_IfActionSubsystem_GUI_User_;

/* Block states (auto storage) for system '<S5>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S5>/If Action Subsystem' */
} rtDW_IfActionSubsystem_GUI_User;

/* Block signals for system '<S5>/If Action Subsystem1' */
typedef struct {
  real_T Gain;                         /* '<S26>/Gain' */
  real_T Sum;                          /* '<S26>/Sum' */
} rtB_IfActionSubsystem1_GUI_User;

/* Block states (auto storage) for system '<S5>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S5>/If Action Subsystem1' */
} rtDW_IfActionSubsystem1_GUI_Use;

/* Block signals (auto storage) */
typedef struct {
  serialfifoptr FIFOwrite1_o1;         /* '<S24>/FIFO write 1' */
  serialfifoptr FIFOwrite2_o1;         /* '<S24>/FIFO write 2' */
  serialfifoptr RateTransition;        /* '<S24>/Rate Transition' */
  serialfifoptr RateTransition2;       /* '<S24>/Rate Transition2' */
  serialfifoptr RateTransition1;       /* '<S24>/Rate Transition1' */
  serialfifoptr RateTransition3;       /* '<S24>/Rate Transition3' */
  serialfifoptr FIFOwrite2;            /* '<S39>/FIFO write 2' */
  serialfifoptr FIFOwrite1;            /* '<S38>/FIFO write 1' */
  real_T MM16ATAnalogInput_o1;         /* '<S6>/MM-16-AT Analog Input' */
  real_T MM16ATAnalogInput_o2;         /* '<S6>/MM-16-AT Analog Input' */
  real_T MM16ATAnalogInput_o3;         /* '<S6>/MM-16-AT Analog Input' */
  real_T MM16ATAnalogInput_o4;         /* '<S6>/MM-16-AT Analog Input' */
  real_T MM16ATAnalogInput_o5;         /* '<S6>/MM-16-AT Analog Input' */
  real_T MM16ATAnalogInput_o6;         /* '<S6>/MM-16-AT Analog Input' */
  real_T MM16ATAnalogInput_o7;         /* '<S6>/MM-16-AT Analog Input' */
  real_T MM16ATAnalogInput_o8;         /* '<S6>/MM-16-AT Analog Input' */
  real_T MM16ATAnalogInput_o9;         /* '<S6>/MM-16-AT Analog Input' */
  real_T MM16ATAnalogInput_o10;        /* '<S6>/MM-16-AT Analog Input' */
  real_T MM16ATAnalogInput_o11;        /* '<S6>/MM-16-AT Analog Input' */
  real_T MM16ATAnalogInput_o12;        /* '<S6>/MM-16-AT Analog Input' */
  real_T DiscreteStateSpace5;          /* '<S42>/Discrete State-Space5' */
  real_T Gain11;                       /* '<S42>/Gain11' */
  real_T Sum6;                         /* '<S42>/Sum6' */
  real_T DiscreteStateSpace4;          /* '<S42>/Discrete State-Space4' */
  real_T Gain10;                       /* '<S42>/Gain10' */
  real_T Sum5;                         /* '<S42>/Sum5' */
  real_T DiscreteStateSpace3;          /* '<S42>/Discrete State-Space3' */
  real_T Gain9;                        /* '<S42>/Gain9' */
  real_T Sum4;                         /* '<S42>/Sum4' */
  real_T DiscreteStateSpace2;          /* '<S42>/Discrete State-Space2' */
  real_T Gain8;                        /* '<S42>/Gain8' */
  real_T Sum3;                         /* '<S42>/Sum3' */
  real_T DiscreteStateSpace1;          /* '<S42>/Discrete State-Space1' */
  real_T Gain1;                        /* '<S42>/Gain1' */
  real_T Sum2;                         /* '<S42>/Sum2' */
  real_T DiscreteStateSpace6;          /* '<S42>/Discrete State-Space6' */
  real_T Gain;                         /* '<S42>/Gain' */
  real_T Sum1;                         /* '<S42>/Sum1' */
  real_T Merge[6];                     /* '<Root>/Merge' */
  real_T Saturation;                   /* '<S5>/Saturation' */
  real_T Saturation1;                  /* '<S5>/Saturation1' */
  real_T Saturation2;                  /* '<S5>/Saturation2' */
  real_T Saturation3;                  /* '<S5>/Saturation3' */
  real_T Saturation4;                  /* '<S5>/Saturation4' */
  real_T Saturation5;                  /* '<S5>/Saturation5' */
  real_T Merge_l;                      /* '<S5>/Merge' */
  real_T Merge1;                       /* '<S5>/Merge1' */
  real_T Merge2;                       /* '<S5>/Merge2' */
  real_T Merge3;                       /* '<S5>/Merge3' */
  real_T Merge4;                       /* '<S5>/Merge4' */
  real_T Merge5;                       /* '<S5>/Merge5' */
  real_T Gain2;                        /* '<S42>/Gain2' */
  real_T Gain3;                        /* '<S42>/Gain3' */
  real_T Gain4;                        /* '<S42>/Gain4' */
  real_T Gain5;                        /* '<S42>/Gain5' */
  real_T Gain6;                        /* '<S42>/Gain6' */
  real_T Gain7;                        /* '<S42>/Gain7' */
  real_T Unpack1[18];                  /* '<S17>/Unpack1' */
  real_T FeeedForwardGain1;            /* '<S15>/FeeedForward Gain1' */
  real_T FeeedForwardGain10;           /* '<S15>/FeeedForward Gain10' */
  real_T FeeedForwardGain11;           /* '<S15>/FeeedForward Gain11' */
  real_T FeeedForwardGain12;           /* '<S15>/FeeedForward Gain12' */
  real_T FeeedForwardGain2;            /* '<S15>/FeeedForward Gain2' */
  real_T FeeedForwardGain3;            /* '<S15>/FeeedForward Gain3' */
  real_T FeeedForwardGain4;            /* '<S15>/FeeedForward Gain4' */
  real_T FeeedForwardGain5;            /* '<S15>/FeeedForward Gain5' */
  real_T FeeedForwardGain6;            /* '<S15>/FeeedForward Gain6' */
  real_T FeeedForwardGain7;            /* '<S15>/FeeedForward Gain7' */
  real_T FeeedForwardGain8;            /* '<S15>/FeeedForward Gain8' */
  real_T FeeedForwardGain9;            /* '<S15>/FeeedForward Gain9' */
  real_T Sum6_c;                       /* '<S15>/Sum6' */
  real_T Sum3_o;                       /* '<S15>/Sum3' */
  real_T ProportionalGain;             /* '<S18>/Proportional Gain' */
  real_T Integrator;                   /* '<S18>/Integrator' */
  real_T DerivativeGain;               /* '<S18>/Derivative Gain' */
  real_T Filter;                       /* '<S18>/Filter' */
  real_T SumD;                         /* '<S18>/SumD' */
  real_T FilterCoefficient;            /* '<S18>/Filter Coefficient' */
  real_T Sum;                          /* '<S18>/Sum' */
  real_T Sum5_h;                       /* '<S15>/Sum5' */
  real_T Sum4_o;                       /* '<S15>/Sum4' */
  real_T Sum1_k;                       /* '<S15>/Sum1' */
  real_T ProportionalGain_c;           /* '<S19>/Proportional Gain' */
  real_T Integrator_i;                 /* '<S19>/Integrator' */
  real_T DerivativeGain_a;             /* '<S19>/Derivative Gain' */
  real_T Filter_j;                     /* '<S19>/Filter' */
  real_T SumD_h;                       /* '<S19>/SumD' */
  real_T FilterCoefficient_n;          /* '<S19>/Filter Coefficient' */
  real_T Sum_g;                        /* '<S19>/Sum' */
  real_T Sum2_i;                       /* '<S15>/Sum2' */
  real_T Sum12;                        /* '<S15>/Sum12' */
  real_T Sum10;                        /* '<S15>/Sum10' */
  real_T ProportionalGain_g;           /* '<S21>/Proportional Gain' */
  real_T Integrator_p;                 /* '<S21>/Integrator' */
  real_T DerivativeGain_p;             /* '<S21>/Derivative Gain' */
  real_T Filter_n;                     /* '<S21>/Filter' */
  real_T SumD_n;                       /* '<S21>/SumD' */
  real_T FilterCoefficient_j;          /* '<S21>/Filter Coefficient' */
  real_T Sum_p;                        /* '<S21>/Sum' */
  real_T Sum11;                        /* '<S15>/Sum11' */
  real_T Sum15;                        /* '<S15>/Sum15' */
  real_T Sum13;                        /* '<S15>/Sum13' */
  real_T ProportionalGain_m;           /* '<S22>/Proportional Gain' */
  real_T Integrator_g;                 /* '<S22>/Integrator' */
  real_T DerivativeGain_n;             /* '<S22>/Derivative Gain' */
  real_T Filter_e;                     /* '<S22>/Filter' */
  real_T SumD_m;                       /* '<S22>/SumD' */
  real_T FilterCoefficient_o;          /* '<S22>/Filter Coefficient' */
  real_T Sum_h;                        /* '<S22>/Sum' */
  real_T Sum14;                        /* '<S15>/Sum14' */
  real_T Sum18;                        /* '<S15>/Sum18' */
  real_T Sum16;                        /* '<S15>/Sum16' */
  real_T ProportionalGain_e;           /* '<S23>/Proportional Gain' */
  real_T Integrator_gs;                /* '<S23>/Integrator' */
  real_T DerivativeGain_h;             /* '<S23>/Derivative Gain' */
  real_T Filter_i;                     /* '<S23>/Filter' */
  real_T SumD_f;                       /* '<S23>/SumD' */
  real_T FilterCoefficient_m;          /* '<S23>/Filter Coefficient' */
  real_T Sum_i;                        /* '<S23>/Sum' */
  real_T Sum17;                        /* '<S15>/Sum17' */
  real_T Sum9;                         /* '<S15>/Sum9' */
  real_T Gain7_m;                      /* '<S15>/Gain7' */
  real_T Sum7;                         /* '<S15>/Sum7' */
  real_T ProportionalGain_k;           /* '<S20>/Proportional Gain' */
  real_T Integrator_m;                 /* '<S20>/Integrator' */
  real_T DerivativeGain_ap;            /* '<S20>/Derivative Gain' */
  real_T Filter_b;                     /* '<S20>/Filter' */
  real_T SumD_fc;                      /* '<S20>/SumD' */
  real_T FilterCoefficient_h;          /* '<S20>/Filter Coefficient' */
  real_T Sum_f;                        /* '<S20>/Sum' */
  real_T Gain8_p;                      /* '<S15>/Gain8' */
  real_T IntegralGain;                 /* '<S18>/Integral Gain' */
  real_T IntegralGain_e;               /* '<S19>/Integral Gain' */
  real_T IntegralGain_p;               /* '<S20>/Integral Gain' */
  real_T IntegralGain_k;               /* '<S21>/Integral Gain' */
  real_T IntegralGain_k4;              /* '<S22>/Integral Gain' */
  real_T IntegralGain_b;               /* '<S23>/Integral Gain' */
  real_T DiscreteZeroPole1;            /* '<S16>/Discrete Zero-Pole1' */
  real_T DiscreteZeroPole2;            /* '<S16>/Discrete Zero-Pole2' */
  real_T DiscreteZeroPole3;            /* '<S16>/Discrete Zero-Pole3' */
  real_T DiscreteZeroPole4;            /* '<S16>/Discrete Zero-Pole4' */
  real_T DiscreteZeroPole5;            /* '<S16>/Discrete Zero-Pole5' */
  real_T DiscreteZeroPole6;            /* '<S16>/Discrete Zero-Pole6' */
  real_T FeeedForwardGain1_m;          /* '<S16>/FeeedForward Gain1' */
  real_T FeeedForwardGain10_l;         /* '<S16>/FeeedForward Gain10' */
  real_T FeeedForwardGain11_l;         /* '<S16>/FeeedForward Gain11' */
  real_T FeeedForwardGain12_g;         /* '<S16>/FeeedForward Gain12' */
  real_T FeeedForwardGain2_c;          /* '<S16>/FeeedForward Gain2' */
  real_T FeeedForwardGain3_n;          /* '<S16>/FeeedForward Gain3' */
  real_T FeeedForwardGain4_i;          /* '<S16>/FeeedForward Gain4' */
  real_T FeeedForwardGain5_a;          /* '<S16>/FeeedForward Gain5' */
  real_T FeeedForwardGain6_b;          /* '<S16>/FeeedForward Gain6' */
  real_T FeeedForwardGain7_c;          /* '<S16>/FeeedForward Gain7' */
  real_T FeeedForwardGain8_o;          /* '<S16>/FeeedForward Gain8' */
  real_T FeeedForwardGain9_k;          /* '<S16>/FeeedForward Gain9' */
  real_T Sum6_d;                       /* '<S16>/Sum6' */
  real_T Sum5_l;                       /* '<S16>/Sum5' */
  real_T Gain1_p;                      /* '<S16>/Gain1' */
  real_T Sum4_c;                       /* '<S16>/Sum4' */
  real_T Sum2_im;                      /* '<S16>/Sum2' */
  real_T Gain3_k;                      /* '<S16>/Gain3' */
  real_T Sum12_d;                      /* '<S16>/Sum12' */
  real_T Sum11_f;                      /* '<S16>/Sum11' */
  real_T Gain4_g;                      /* '<S16>/Gain4' */
  real_T Sum15_f;                      /* '<S16>/Sum15' */
  real_T Sum14_i;                      /* '<S16>/Sum14' */
  real_T Gain5_o;                      /* '<S16>/Gain5' */
  real_T Sum18_c;                      /* '<S16>/Sum18' */
  real_T Sum17_b;                      /* '<S16>/Sum17' */
  real_T Gain6_h;                      /* '<S16>/Gain6' */
  real_T Sum9_l;                       /* '<S16>/Sum9' */
  real_T Gain7_j;                      /* '<S16>/Gain7' */
  real_T Gain8_f;                      /* '<S16>/Gain8' */
  real_T Sum1_e;                       /* '<S16>/Sum1' */
  real_T Sum10_l;                      /* '<S16>/Sum10' */
  real_T Sum13_d;                      /* '<S16>/Sum13' */
  real_T Sum16_i;                      /* '<S16>/Sum16' */
  real_T Sum3_l;                       /* '<S16>/Sum3' */
  real_T Sum7_i;                       /* '<S16>/Sum7' */
  real_T Sum8;                         /* '<S16>/Sum8' */
  real_T FeeedForwardGain5_n;          /* '<S8>/FeeedForward Gain5' */
  real_T FeeedForwardGain6_h;          /* '<S8>/FeeedForward Gain6' */
  real_T Sum9_lk;                      /* '<S8>/Sum9' */
  real_T Gain7_e;                      /* '<S8>/Gain7' */
  real_T Sum7_m;                       /* '<S8>/Sum7' */
  real_T ProportionalGain_d;           /* '<S11>/Proportional Gain' */
  real_T Integrator_l;                 /* '<S11>/Integrator' */
  real_T DerivativeGain_k;             /* '<S11>/Derivative Gain' */
  real_T Filter_p;                     /* '<S11>/Filter' */
  real_T SumD_k;                       /* '<S11>/SumD' */
  real_T FilterCoefficient_i;          /* '<S11>/Filter Coefficient' */
  real_T Sum_fe;                       /* '<S11>/Sum' */
  real_T Gain8_ff;                     /* '<S8>/Gain8' */
  real_T IntegralGain_c;               /* '<S11>/Integral Gain' */
  real_T Sum8_h;                       /* '<S8>/Sum8' */
  real_T FeeedForwardGain3_m;          /* '<S8>/FeeedForward Gain3' */
  real_T FeeedForwardGain4_d;          /* '<S8>/FeeedForward Gain4' */
  real_T Sum6_o;                       /* '<S8>/Sum6' */
  real_T Sum3_oz;                      /* '<S8>/Sum3' */
  real_T ProportionalGain_o;           /* '<S9>/Proportional Gain' */
  real_T Integrator_iz;                /* '<S9>/Integrator' */
  real_T DerivativeGain_l;             /* '<S9>/Derivative Gain' */
  real_T Filter_h;                     /* '<S9>/Filter' */
  real_T SumD_o;                       /* '<S9>/SumD' */
  real_T FilterCoefficient_jw;         /* '<S9>/Filter Coefficient' */
  real_T Sum_m;                        /* '<S9>/Sum' */
  real_T Sum5_h2;                      /* '<S8>/Sum5' */
  real_T Gain1_e;                      /* '<S8>/Gain1' */
  real_T IntegralGain_o;               /* '<S9>/Integral Gain' */
  real_T FeeedForwardGain1_j;          /* '<S8>/FeeedForward Gain1' */
  real_T FeeedForwardGain2_a;          /* '<S8>/FeeedForward Gain2' */
  real_T Sum4_cm;                      /* '<S8>/Sum4' */
  real_T Sum1_n;                       /* '<S8>/Sum1' */
  real_T ProportionalGain_ku;          /* '<S10>/Proportional Gain' */
  real_T Integrator_h;                 /* '<S10>/Integrator' */
  real_T DerivativeGain_kl;            /* '<S10>/Derivative Gain' */
  real_T Filter_f;                     /* '<S10>/Filter' */
  real_T SumD_fx;                      /* '<S10>/SumD' */
  real_T FilterCoefficient_a;          /* '<S10>/Filter Coefficient' */
  real_T Sum_n;                        /* '<S10>/Sum' */
  real_T Sum2_f;                       /* '<S8>/Sum2' */
  real_T Gain3_m;                      /* '<S8>/Gain3' */
  real_T IntegralGain_ko;              /* '<S10>/Integral Gain' */
  real_T FeeedForwardGain7_n;          /* '<S8>/FeeedForward Gain7' */
  real_T FeeedForwardGain8_d;          /* '<S8>/FeeedForward Gain8' */
  real_T Sum12_j;                      /* '<S8>/Sum12' */
  real_T Sum10_i;                      /* '<S8>/Sum10' */
  real_T ProportionalGain_mk;          /* '<S12>/Proportional Gain' */
  real_T Integrator_d;                 /* '<S12>/Integrator' */
  real_T DerivativeGain_e;             /* '<S12>/Derivative Gain' */
  real_T Filter_fz;                    /* '<S12>/Filter' */
  real_T SumD_d;                       /* '<S12>/SumD' */
  real_T FilterCoefficient_f;          /* '<S12>/Filter Coefficient' */
  real_T Sum_pc;                       /* '<S12>/Sum' */
  real_T Sum11_i;                      /* '<S8>/Sum11' */
  real_T Gain4_h;                      /* '<S8>/Gain4' */
  real_T IntegralGain_g;               /* '<S12>/Integral Gain' */
  real_T FeeedForwardGain10_l0;        /* '<S8>/FeeedForward Gain10' */
  real_T FeeedForwardGain9_a;          /* '<S8>/FeeedForward Gain9' */
  real_T Sum15_p;                      /* '<S8>/Sum15' */
  real_T Sum13_g;                      /* '<S8>/Sum13' */
  real_T ProportionalGain_mo;          /* '<S13>/Proportional Gain' */
  real_T Integrator_pa;                /* '<S13>/Integrator' */
  real_T DerivativeGain_klw;           /* '<S13>/Derivative Gain' */
  real_T Filter_io;                    /* '<S13>/Filter' */
  real_T SumD_m3;                      /* '<S13>/SumD' */
  real_T FilterCoefficient_hs;         /* '<S13>/Filter Coefficient' */
  real_T Sum_j;                        /* '<S13>/Sum' */
  real_T Sum14_k;                      /* '<S8>/Sum14' */
  real_T Gain5_f;                      /* '<S8>/Gain5' */
  real_T IntegralGain_h;               /* '<S13>/Integral Gain' */
  real_T FeeedForwardGain11_b;         /* '<S8>/FeeedForward Gain11' */
  real_T FeeedForwardGain12_j;         /* '<S8>/FeeedForward Gain12' */
  real_T Sum18_j;                      /* '<S8>/Sum18' */
  real_T Sum16_l;                      /* '<S8>/Sum16' */
  real_T ProportionalGain_mm;          /* '<S14>/Proportional Gain' */
  real_T Integrator_ir;                /* '<S14>/Integrator' */
  real_T DerivativeGain_eo;            /* '<S14>/Derivative Gain' */
  real_T Filter_d;                     /* '<S14>/Filter' */
  real_T SumD_g;                       /* '<S14>/SumD' */
  real_T FilterCoefficient_b;          /* '<S14>/Filter Coefficient' */
  real_T Sum_iv;                       /* '<S14>/Sum' */
  real_T Sum17_k;                      /* '<S8>/Sum17' */
  real_T Gain6_f;                      /* '<S8>/Gain6' */
  real_T IntegralGain_m;               /* '<S14>/Integral Gain' */
  uint32_T ReadIntStatusFC1_o2;        /* '<S37>/Read Int Status FC1' */
  uint32_T FIFOread2_o1[61];           /* '<S41>/FIFO read 2' */
  uint32_T FIFOread2_o2;               /* '<S41>/FIFO read 2' */
  uint32_T ReadHWFIFO2[65];            /* '<S39>/Read HW FIFO2' */
  uint32_T FIFOread1_o1[61];           /* '<S40>/FIFO read 1' */
  uint32_T FIFOread1_o2;               /* '<S40>/FIFO read 1' */
  uint32_T ReadHWFIFO1[65];            /* '<S38>/Read HW FIFO1' */
  uint16_T FIFOread1[1025];            /* '<S24>/FIFO read 1' */
  uint16_T FIFOread2[1025];            /* '<S24>/FIFO read 2' */
  uint8_T ASCIIEncode[9];              /* '<S5>/ASCII Encode ' */
  uint8_T FromFile1[144];              /* '<S17>/From File1' */
  boolean_T FIFOwrite1_o2;             /* '<S24>/FIFO write 1' */
  boolean_T FIFOwrite2_o2;             /* '<S24>/FIFO write 2' */
  rtB_IfActionSubsystem1_GUI_User IfActionSubsystem11;/* '<S5>/If Action Subsystem11' */
  rtB_IfActionSubsystem_GUI_User_ IfActionSubsystem10;/* '<S5>/If Action Subsystem10' */
  rtB_IfActionSubsystem1_GUI_User IfActionSubsystem9;/* '<S5>/If Action Subsystem9' */
  rtB_IfActionSubsystem_GUI_User_ IfActionSubsystem8;/* '<S5>/If Action Subsystem8' */
  rtB_IfActionSubsystem1_GUI_User IfActionSubsystem7;/* '<S5>/If Action Subsystem7' */
  rtB_IfActionSubsystem_GUI_User_ IfActionSubsystem6_a;/* '<S5>/If Action Subsystem6' */
  rtB_IfActionSubsystem1_GUI_User IfActionSubsystem5_i;/* '<S5>/If Action Subsystem5' */
  rtB_IfActionSubsystem_GUI_User_ IfActionSubsystem4;/* '<S5>/If Action Subsystem4' */
  rtB_IfActionSubsystem1_GUI_User IfActionSubsystem3;/* '<S5>/If Action Subsystem3' */
  rtB_IfActionSubsystem_GUI_User_ IfActionSubsystem2_c;/* '<S5>/If Action Subsystem2' */
  rtB_IfActionSubsystem1_GUI_User IfActionSubsystem1;/* '<S5>/If Action Subsystem1' */
  rtB_IfActionSubsystem_GUI_User_ IfActionSubsystem_h;/* '<S5>/If Action Subsystem' */
} BlockIO_GUI_User_V1_3;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteStateSpace5_DSTATE[2];/* '<S42>/Discrete State-Space5' */
  real_T DiscreteStateSpace4_DSTATE[2];/* '<S42>/Discrete State-Space4' */
  real_T DiscreteStateSpace3_DSTATE[2];/* '<S42>/Discrete State-Space3' */
  real_T DiscreteStateSpace2_DSTATE[2];/* '<S42>/Discrete State-Space2' */
  real_T DiscreteStateSpace1_DSTATE[2];/* '<S42>/Discrete State-Space1' */
  real_T DiscreteStateSpace6_DSTATE[2];/* '<S42>/Discrete State-Space6' */
  real_T Integrator_DSTATE;            /* '<S18>/Integrator' */
  real_T Filter_DSTATE;                /* '<S18>/Filter' */
  real_T Integrator_DSTATE_m;          /* '<S19>/Integrator' */
  real_T Filter_DSTATE_i;              /* '<S19>/Filter' */
  real_T Integrator_DSTATE_a;          /* '<S21>/Integrator' */
  real_T Filter_DSTATE_h;              /* '<S21>/Filter' */
  real_T Integrator_DSTATE_g;          /* '<S22>/Integrator' */
  real_T Filter_DSTATE_k;              /* '<S22>/Filter' */
  real_T Integrator_DSTATE_c;          /* '<S23>/Integrator' */
  real_T Filter_DSTATE_n;              /* '<S23>/Filter' */
  real_T Integrator_DSTATE_l;          /* '<S20>/Integrator' */
  real_T Filter_DSTATE_m;              /* '<S20>/Filter' */
  real_T DiscreteZeroPole1_DSTATE[4];  /* '<S16>/Discrete Zero-Pole1' */
  real_T DiscreteZeroPole2_DSTATE[4];  /* '<S16>/Discrete Zero-Pole2' */
  real_T DiscreteZeroPole3_DSTATE[4];  /* '<S16>/Discrete Zero-Pole3' */
  real_T DiscreteZeroPole4_DSTATE[4];  /* '<S16>/Discrete Zero-Pole4' */
  real_T DiscreteZeroPole5_DSTATE[4];  /* '<S16>/Discrete Zero-Pole5' */
  real_T DiscreteZeroPole6_DSTATE[4];  /* '<S16>/Discrete Zero-Pole6' */
  real_T Integrator_DSTATE_cb;         /* '<S11>/Integrator' */
  real_T Filter_DSTATE_f;              /* '<S11>/Filter' */
  real_T Integrator_DSTATE_j;          /* '<S9>/Integrator' */
  real_T Filter_DSTATE_o;              /* '<S9>/Filter' */
  real_T Integrator_DSTATE_d;          /* '<S10>/Integrator' */
  real_T Filter_DSTATE_mn;             /* '<S10>/Filter' */
  real_T Integrator_DSTATE_k;          /* '<S12>/Integrator' */
  real_T Filter_DSTATE_mv;             /* '<S12>/Filter' */
  real_T Integrator_DSTATE_mj;         /* '<S13>/Integrator' */
  real_T Filter_DSTATE_kq;             /* '<S13>/Filter' */
  real_T Integrator_DSTATE_i;          /* '<S14>/Integrator' */
  real_T Filter_DSTATE_me;             /* '<S14>/Filter' */
  real_T MM16ATAnalogInput_RWORK[2];   /* '<S6>/MM-16-AT Analog Input' */
  void *ASCIIEncode_PWORK;             /* '<S5>/ASCII Encode ' */
  void *FIFOwrite1_PWORK;              /* '<S24>/FIFO write 1' */
  void *FIFOwrite2_PWORK;              /* '<S24>/FIFO write 2' */
  void *FIFOwrite2_PWORK_o;            /* '<S39>/FIFO write 2' */
  void *FIFOwrite1_PWORK_d;            /* '<S38>/FIFO write 1' */
  int_T MM16ATAnalogInput_IWORK;       /* '<S6>/MM-16-AT Analog Input' */
  int_T FIFOwrite1_IWORK[3];           /* '<S24>/FIFO write 1' */
  int_T EnableTX1_IWORK;               /* '<S24>/Enable TX 1' */
  int_T FIFOwrite2_IWORK[3];           /* '<S24>/FIFO write 2' */
  int_T EnableTX2_IWORK;               /* '<S24>/Enable TX 2' */
  int_T Setup1_IWORK[3];               /* '<S24>/Setup1' */
  int_T Setup2_IWORK[3];               /* '<S24>/Setup2' */
  int_T WriteHWFIFO2_IWORK;            /* '<S41>/Write HW FIFO2' */
  int_T ReadHWFIFO2_IWORK;             /* '<S39>/Read HW FIFO2' */
  int_T FIFOwrite2_IWORK_k[3];         /* '<S39>/FIFO write 2' */
  int_T WriteHWFIFO1_IWORK;            /* '<S40>/Write HW FIFO1' */
  int_T ReadHWFIFO1_IWORK;             /* '<S38>/Read HW FIFO1' */
  int_T FIFOwrite1_IWORK_o[3];         /* '<S38>/FIFO write 1' */
  int_T FromFile1_IWORK;               /* '<S17>/From File1' */
  int8_T If_ActiveSubsystem;           /* '<Root>/If' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<Root>/If Action Subsystem' */
  int8_T IfActionSubsystem5_SubsysRanBC;/* '<Root>/If Action Subsystem5' */
  int8_T IfActionSubsystem6_SubsysRanBC;/* '<Root>/If Action Subsystem6' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<Root>/If Action Subsystem2' */
  int8_T RS232ISR_SubsysRanBC;         /* '<S24>/RS232 ISR' */
  int8_T Receive1_SubsysRanBC;         /* '<S37>/Receive 1' */
  int8_T Transmit1_SubsysRanBC;        /* '<S37>/Transmit 1' */
  int8_T Receive2_SubsysRanBC;         /* '<S37>/Receive 2' */
  int8_T Transmit2_SubsysRanBC;        /* '<S37>/Transmit 2' */
  rtDW_IfActionSubsystem1_GUI_Use IfActionSubsystem11;/* '<S5>/If Action Subsystem11' */
  rtDW_IfActionSubsystem_GUI_User IfActionSubsystem10;/* '<S5>/If Action Subsystem10' */
  rtDW_IfActionSubsystem1_GUI_Use IfActionSubsystem9;/* '<S5>/If Action Subsystem9' */
  rtDW_IfActionSubsystem_GUI_User IfActionSubsystem8;/* '<S5>/If Action Subsystem8' */
  rtDW_IfActionSubsystem1_GUI_Use IfActionSubsystem7;/* '<S5>/If Action Subsystem7' */
  rtDW_IfActionSubsystem_GUI_User IfActionSubsystem6_a;/* '<S5>/If Action Subsystem6' */
  rtDW_IfActionSubsystem1_GUI_Use IfActionSubsystem5_i;/* '<S5>/If Action Subsystem5' */
  rtDW_IfActionSubsystem_GUI_User IfActionSubsystem4;/* '<S5>/If Action Subsystem4' */
  rtDW_IfActionSubsystem1_GUI_Use IfActionSubsystem3;/* '<S5>/If Action Subsystem3' */
  rtDW_IfActionSubsystem_GUI_User IfActionSubsystem2_c;/* '<S5>/If Action Subsystem2' */
  rtDW_IfActionSubsystem1_GUI_Use IfActionSubsystem1;/* '<S5>/If Action Subsystem1' */
  rtDW_IfActionSubsystem_GUI_User IfActionSubsystem_h;/* '<S5>/If Action Subsystem' */
} D_Work_GUI_User_V1_3;

/* Backward compatible GRT Identifiers */
#define rtB                            GUI_User_V1_3_B
#define BlockIO                        BlockIO_GUI_User_V1_3
#define rtXdot                         GUI_User_V1_3_Xdot
#define StateDerivatives               StateDerivatives_GUI_User_V1_3
#define tXdis                          GUI_User_V1_3_Xdis
#define StateDisabled                  StateDisabled_GUI_User_V1_3
#define rtP                            GUI_User_V1_3_P
#define Parameters                     Parameters_GUI_User_V1_3
#define rtDWork                        GUI_User_V1_3_DWork
#define D_Work                         D_Work_GUI_User_V1_3

/* Parameters for system: '<S5>/If Action Subsystem' */
struct rtP_IfActionSubsystem_GUI_User__ {
  real_T Constant8_Value;              /* Expression: 50
                                        * Referenced by: '<S25>/Constant8'
                                        */
};

/* Parameters for system: '<S5>/If Action Subsystem1' */
struct rtP_IfActionSubsystem1_GUI_User_ {
  real_T Constant8_Value;              /* Expression: 150
                                        * Referenced by: '<S26>/Constant8'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S26>/Gain'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_GUI_User_V1_3_ {
  real_T ControlSignalsSetto0_Y0[6];   /* Expression: [0 0 0 0 0 0]
                                        * Referenced by: '<S1>/Control Signals Set to 0'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T ControlSig_Y0[6];             /* Expression: [0 0 0 0 0 0]
                                        * Referenced by: '<S3>/ControlSig'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<S8>/Constant8'
                                        */
  real_T FeeedForwardGain5_Gain;       /* Expression: tau(1)/kdc(1)
                                        * Referenced by: '<S8>/FeeedForward Gain5'
                                        */
  real_T FeeedForwardGain6_Gain;       /* Expression: 1/kdc(1)
                                        * Referenced by: '<S8>/FeeedForward Gain6'
                                        */
  real_T Gain7_Gain;                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain7'
                                        */
  real_T Posi1Free_Value;              /* Expression: ActLen(1)
                                        * Referenced by: '<S8>/Posi1Free'
                                        */
  real_T ProportionalGain_Gain;        /* Expression: P
                                        * Referenced by: '<S11>/Proportional Gain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S11>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S11>/Integrator'
                                        */
  real_T DerivativeGain_Gain;          /* Expression: D
                                        * Referenced by: '<S11>/Derivative Gain'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S11>/Filter'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S11>/Filter'
                                        */
  real_T FilterCoefficient_Gain;       /* Expression: N
                                        * Referenced by: '<S11>/Filter Coefficient'
                                        */
  real_T Gain8_Gain;                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain8'
                                        */
  real_T IntegralGain_Gain;            /* Expression: I
                                        * Referenced by: '<S11>/Integral Gain'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 40
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -40
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant10'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<S8>/Constant9'
                                        */
  real_T FeeedForwardGain3_Gain;       /* Expression: tau(2)/kdc(2)
                                        * Referenced by: '<S8>/FeeedForward Gain3'
                                        */
  real_T FeeedForwardGain4_Gain;       /* Expression: 1/kdc(2)
                                        * Referenced by: '<S8>/FeeedForward Gain4'
                                        */
  real_T Posi2Free_Value;              /* Expression: ActLen(2)
                                        * Referenced by: '<S8>/Posi2Free'
                                        */
  real_T ProportionalGain_Gain_f;      /* Expression: P
                                        * Referenced by: '<S9>/Proportional Gain'
                                        */
  real_T Integrator_gainval_p;         /* Computed Parameter: Integrator_gainval_p
                                        * Referenced by: '<S9>/Integrator'
                                        */
  real_T Integrator_IC_e;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S9>/Integrator'
                                        */
  real_T DerivativeGain_Gain_a;        /* Expression: D
                                        * Referenced by: '<S9>/Derivative Gain'
                                        */
  real_T Filter_gainval_c;             /* Computed Parameter: Filter_gainval_c
                                        * Referenced by: '<S9>/Filter'
                                        */
  real_T Filter_IC_a;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S9>/Filter'
                                        */
  real_T FilterCoefficient_Gain_i;     /* Expression: N
                                        * Referenced by: '<S9>/Filter Coefficient'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T IntegralGain_Gain_c;          /* Expression: I
                                        * Referenced by: '<S9>/Integral Gain'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 40
                                        * Referenced by: '<S8>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -40
                                        * Referenced by: '<S8>/Saturation2'
                                        */
  real_T Constant11_Value;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant11'
                                        */
  real_T Constant12_Value;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant12'
                                        */
  real_T FeeedForwardGain1_Gain;       /* Expression: tau(3)/kdc(3)
                                        * Referenced by: '<S8>/FeeedForward Gain1'
                                        */
  real_T FeeedForwardGain2_Gain;       /* Expression: 1/kdc(3)
                                        * Referenced by: '<S8>/FeeedForward Gain2'
                                        */
  real_T Posi3Free_Value;              /* Expression: ActLen(3)
                                        * Referenced by: '<S8>/Posi3Free'
                                        */
  real_T ProportionalGain_Gain_h;      /* Expression: P
                                        * Referenced by: '<S10>/Proportional Gain'
                                        */
  real_T Integrator_gainval_j;         /* Computed Parameter: Integrator_gainval_j
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T Integrator_IC_n;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T DerivativeGain_Gain_ax;       /* Expression: D
                                        * Referenced by: '<S10>/Derivative Gain'
                                        */
  real_T Filter_gainval_g;             /* Computed Parameter: Filter_gainval_g
                                        * Referenced by: '<S10>/Filter'
                                        */
  real_T Filter_IC_b;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S10>/Filter'
                                        */
  real_T FilterCoefficient_Gain_d;     /* Expression: N
                                        * Referenced by: '<S10>/Filter Coefficient'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain3'
                                        */
  real_T IntegralGain_Gain_m;          /* Expression: I
                                        * Referenced by: '<S10>/Integral Gain'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 40
                                        * Referenced by: '<S8>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -40
                                        * Referenced by: '<S8>/Saturation3'
                                        */
  real_T Constant13_Value;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant13'
                                        */
  real_T Constant14_Value;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant14'
                                        */
  real_T FeeedForwardGain7_Gain;       /* Expression: tau(4)/kdc(4)
                                        * Referenced by: '<S8>/FeeedForward Gain7'
                                        */
  real_T FeeedForwardGain8_Gain;       /* Expression: 1/kdc(4)
                                        * Referenced by: '<S8>/FeeedForward Gain8'
                                        */
  real_T Posi4Free_Value;              /* Expression: ActLen(4)
                                        * Referenced by: '<S8>/Posi4Free'
                                        */
  real_T ProportionalGain_Gain_c;      /* Expression: P
                                        * Referenced by: '<S12>/Proportional Gain'
                                        */
  real_T Integrator_gainval_j4;        /* Computed Parameter: Integrator_gainval_j4
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Integrator_IC_c;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T DerivativeGain_Gain_c;        /* Expression: D
                                        * Referenced by: '<S12>/Derivative Gain'
                                        */
  real_T Filter_gainval_e;             /* Computed Parameter: Filter_gainval_e
                                        * Referenced by: '<S12>/Filter'
                                        */
  real_T Filter_IC_h;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S12>/Filter'
                                        */
  real_T FilterCoefficient_Gain_l;     /* Expression: N
                                        * Referenced by: '<S12>/Filter Coefficient'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain4'
                                        */
  real_T IntegralGain_Gain_l;          /* Expression: I
                                        * Referenced by: '<S12>/Integral Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 40
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -40
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Constant15_Value;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant15'
                                        */
  real_T Constant16_Value;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant16'
                                        */
  real_T FeeedForwardGain10_Gain;      /* Expression: 1/kdc(5)
                                        * Referenced by: '<S8>/FeeedForward Gain10'
                                        */
  real_T FeeedForwardGain9_Gain;       /* Expression: tau(5)/kdc(5)
                                        * Referenced by: '<S8>/FeeedForward Gain9'
                                        */
  real_T Posi5Free_Value;              /* Expression: ActLen(5)
                                        * Referenced by: '<S8>/Posi5Free'
                                        */
  real_T ProportionalGain_Gain_n;      /* Expression: P
                                        * Referenced by: '<S13>/Proportional Gain'
                                        */
  real_T Integrator_gainval_i;         /* Computed Parameter: Integrator_gainval_i
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T Integrator_IC_g;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T DerivativeGain_Gain_e;        /* Expression: D
                                        * Referenced by: '<S13>/Derivative Gain'
                                        */
  real_T Filter_gainval_cs;            /* Computed Parameter: Filter_gainval_cs
                                        * Referenced by: '<S13>/Filter'
                                        */
  real_T Filter_IC_i;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S13>/Filter'
                                        */
  real_T FilterCoefficient_Gain_o;     /* Expression: N
                                        * Referenced by: '<S13>/Filter Coefficient'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain5'
                                        */
  real_T IntegralGain_Gain_i;          /* Expression: I
                                        * Referenced by: '<S13>/Integral Gain'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 40
                                        * Referenced by: '<S8>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -40
                                        * Referenced by: '<S8>/Saturation4'
                                        */
  real_T Constant17_Value;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant17'
                                        */
  real_T Constant18_Value;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant18'
                                        */
  real_T FeeedForwardGain11_Gain;      /* Expression: 1/kdc(6)
                                        * Referenced by: '<S8>/FeeedForward Gain11'
                                        */
  real_T FeeedForwardGain12_Gain;      /* Expression: tau(6)/kdc(6)
                                        * Referenced by: '<S8>/FeeedForward Gain12'
                                        */
  real_T Posi6Free_Value;              /* Expression: ActLen(6)
                                        * Referenced by: '<S8>/Posi6Free'
                                        */
  real_T ProportionalGain_Gain_e;      /* Expression: P
                                        * Referenced by: '<S14>/Proportional Gain'
                                        */
  real_T Integrator_gainval_f;         /* Computed Parameter: Integrator_gainval_f
                                        * Referenced by: '<S14>/Integrator'
                                        */
  real_T Integrator_IC_d;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S14>/Integrator'
                                        */
  real_T DerivativeGain_Gain_k;        /* Expression: D
                                        * Referenced by: '<S14>/Derivative Gain'
                                        */
  real_T Filter_gainval_n;             /* Computed Parameter: Filter_gainval_n
                                        * Referenced by: '<S14>/Filter'
                                        */
  real_T Filter_IC_n;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S14>/Filter'
                                        */
  real_T FilterCoefficient_Gain_b;     /* Expression: N
                                        * Referenced by: '<S14>/Filter Coefficient'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1/0.15
                                        * Referenced by: '<S8>/Gain6'
                                        */
  real_T IntegralGain_Gain_j;          /* Expression: I
                                        * Referenced by: '<S14>/Integral Gain'
                                        */
  real_T Saturation5_UpperSat;         /* Expression: 40
                                        * Referenced by: '<S8>/Saturation5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: -40
                                        * Referenced by: '<S8>/Saturation5'
                                        */
  real_T Controlsignal_Y0[6];          /* Expression: [0 0 0 0 0 0]
                                        * Referenced by: '<S4>/Control signal'
                                        */
  real_T ReferenceTrayectory_Y0[12];   /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S4>/ReferenceTrayectory'
                                        */
  real_T FromFile1_P1_Size[2];         /* Computed Parameter: FromFile1_P1_Size
                                        * Referenced by: '<S17>/From File1'
                                        */
  real_T FromFile1_P1[23];             /* Computed Parameter: FromFile1_P1
                                        * Referenced by: '<S17>/From File1'
                                        */
  real_T FromFile1_P2_Size[2];         /* Computed Parameter: FromFile1_P2_Size
                                        * Referenced by: '<S17>/From File1'
                                        */
  real_T FromFile1_P2;                 /* Expression: dataSize
                                        * Referenced by: '<S17>/From File1'
                                        */
  real_T FromFile1_P3_Size[2];         /* Computed Parameter: FromFile1_P3_Size
                                        * Referenced by: '<S17>/From File1'
                                        */
  real_T FromFile1_P3;                 /* Expression: bufSize
                                        * Referenced by: '<S17>/From File1'
                                        */
  real_T FromFile1_P4_Size[2];         /* Computed Parameter: FromFile1_P4_Size
                                        * Referenced by: '<S17>/From File1'
                                        */
  real_T FromFile1_P4;                 /* Expression: readSize
                                        * Referenced by: '<S17>/From File1'
                                        */
  real_T FromFile1_P5_Size[2];         /* Computed Parameter: FromFile1_P5_Size
                                        * Referenced by: '<S17>/From File1'
                                        */
  real_T FromFile1_P5;                 /* Expression: EOFOption
                                        * Referenced by: '<S17>/From File1'
                                        */
  real_T FromFile1_P6_Size[2];         /* Computed Parameter: FromFile1_P6_Size
                                        * Referenced by: '<S17>/From File1'
                                        */
  real_T FromFile1_P6;                 /* Expression: sampTime
                                        * Referenced by: '<S17>/From File1'
                                        */
  real_T FeeedForwardGain1_Gain_p;     /* Expression: 16/51.966
                                        * Referenced by: '<S15>/FeeedForward Gain1'
                                        */
  real_T FeeedForwardGain10_Gain_k;    /* Expression: 1/49.788
                                        * Referenced by: '<S15>/FeeedForward Gain10'
                                        */
  real_T FeeedForwardGain11_Gain_k;    /* Expression: 1/51.427
                                        * Referenced by: '<S15>/FeeedForward Gain11'
                                        */
  real_T FeeedForwardGain12_Gain_j;    /* Expression: 15.2/51.427
                                        * Referenced by: '<S15>/FeeedForward Gain12'
                                        */
  real_T FeeedForwardGain2_Gain_f;     /* Expression: 1/51.966
                                        * Referenced by: '<S15>/FeeedForward Gain2'
                                        */
  real_T FeeedForwardGain3_Gain_d;     /* Expression: 20.9/65.089
                                        * Referenced by: '<S15>/FeeedForward Gain3'
                                        */
  real_T FeeedForwardGain4_Gain_e;     /* Expression: 1/65.089
                                        * Referenced by: '<S15>/FeeedForward Gain4'
                                        */
  real_T FeeedForwardGain5_Gain_f;     /* Expression: 12.9/35.737
                                        * Referenced by: '<S15>/FeeedForward Gain5'
                                        */
  real_T FeeedForwardGain6_Gain_k;     /* Expression: 1/35.737
                                        * Referenced by: '<S15>/FeeedForward Gain6'
                                        */
  real_T FeeedForwardGain7_Gain_n;     /* Expression: 26.2/74.788
                                        * Referenced by: '<S15>/FeeedForward Gain7'
                                        */
  real_T FeeedForwardGain8_Gain_f;     /* Expression: 1/74.788
                                        * Referenced by: '<S15>/FeeedForward Gain8'
                                        */
  real_T FeeedForwardGain9_Gain_c;     /* Expression: 17.1/49.788
                                        * Referenced by: '<S15>/FeeedForward Gain9'
                                        */
  real_T ProportionalGain_Gain_d;      /* Expression: P
                                        * Referenced by: '<S18>/Proportional Gain'
                                        */
  real_T Integrator_gainval_fe;        /* Computed Parameter: Integrator_gainval_fe
                                        * Referenced by: '<S18>/Integrator'
                                        */
  real_T Integrator_IC_f;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S18>/Integrator'
                                        */
  real_T DerivativeGain_Gain_g;        /* Expression: D
                                        * Referenced by: '<S18>/Derivative Gain'
                                        */
  real_T Filter_gainval_p;             /* Computed Parameter: Filter_gainval_p
                                        * Referenced by: '<S18>/Filter'
                                        */
  real_T Filter_IC_p;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S18>/Filter'
                                        */
  real_T FilterCoefficient_Gain_bu;    /* Expression: N
                                        * Referenced by: '<S18>/Filter Coefficient'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T ProportionalGain_Gain_p;      /* Expression: P
                                        * Referenced by: '<S19>/Proportional Gain'
                                        */
  real_T Integrator_gainval_c;         /* Computed Parameter: Integrator_gainval_c
                                        * Referenced by: '<S19>/Integrator'
                                        */
  real_T Integrator_IC_cd;             /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S19>/Integrator'
                                        */
  real_T DerivativeGain_Gain_n;        /* Expression: D
                                        * Referenced by: '<S19>/Derivative Gain'
                                        */
  real_T Filter_gainval_o;             /* Computed Parameter: Filter_gainval_o
                                        * Referenced by: '<S19>/Filter'
                                        */
  real_T Filter_IC_aa;                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S19>/Filter'
                                        */
  real_T FilterCoefficient_Gain_g;     /* Expression: N
                                        * Referenced by: '<S19>/Filter Coefficient'
                                        */
  real_T Gain3_Gain_l;                 /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain3'
                                        */
  real_T ProportionalGain_Gain_j;      /* Expression: P
                                        * Referenced by: '<S21>/Proportional Gain'
                                        */
  real_T Integrator_gainval_g;         /* Computed Parameter: Integrator_gainval_g
                                        * Referenced by: '<S21>/Integrator'
                                        */
  real_T Integrator_IC_db;             /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S21>/Integrator'
                                        */
  real_T DerivativeGain_Gain_ny;       /* Expression: D
                                        * Referenced by: '<S21>/Derivative Gain'
                                        */
  real_T Filter_gainval_m;             /* Computed Parameter: Filter_gainval_m
                                        * Referenced by: '<S21>/Filter'
                                        */
  real_T Filter_IC_nf;                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S21>/Filter'
                                        */
  real_T FilterCoefficient_Gain_j;     /* Expression: N
                                        * Referenced by: '<S21>/Filter Coefficient'
                                        */
  real_T Gain4_Gain_e;                 /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain4'
                                        */
  real_T ProportionalGain_Gain_m;      /* Expression: P
                                        * Referenced by: '<S22>/Proportional Gain'
                                        */
  real_T Integrator_gainval_m;         /* Computed Parameter: Integrator_gainval_m
                                        * Referenced by: '<S22>/Integrator'
                                        */
  real_T Integrator_IC_dm;             /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S22>/Integrator'
                                        */
  real_T DerivativeGain_Gain_o;        /* Expression: D
                                        * Referenced by: '<S22>/Derivative Gain'
                                        */
  real_T Filter_gainval_d;             /* Computed Parameter: Filter_gainval_d
                                        * Referenced by: '<S22>/Filter'
                                        */
  real_T Filter_IC_m;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S22>/Filter'
                                        */
  real_T FilterCoefficient_Gain_ih;    /* Expression: N
                                        * Referenced by: '<S22>/Filter Coefficient'
                                        */
  real_T Gain5_Gain_e;                 /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain5'
                                        */
  real_T ProportionalGain_Gain_i;      /* Expression: P
                                        * Referenced by: '<S23>/Proportional Gain'
                                        */
  real_T Integrator_gainval_d;         /* Computed Parameter: Integrator_gainval_d
                                        * Referenced by: '<S23>/Integrator'
                                        */
  real_T Integrator_IC_k;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S23>/Integrator'
                                        */
  real_T DerivativeGain_Gain_h;        /* Expression: D
                                        * Referenced by: '<S23>/Derivative Gain'
                                        */
  real_T Filter_gainval_m1;            /* Computed Parameter: Filter_gainval_m1
                                        * Referenced by: '<S23>/Filter'
                                        */
  real_T Filter_IC_nc;                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S23>/Filter'
                                        */
  real_T FilterCoefficient_Gain_dz;    /* Expression: N
                                        * Referenced by: '<S23>/Filter Coefficient'
                                        */
  real_T Gain6_Gain_e;                 /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain6'
                                        */
  real_T Gain7_Gain_l;                 /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain7'
                                        */
  real_T ProportionalGain_Gain_c5;     /* Expression: P
                                        * Referenced by: '<S20>/Proportional Gain'
                                        */
  real_T Integrator_gainval_l;         /* Computed Parameter: Integrator_gainval_l
                                        * Referenced by: '<S20>/Integrator'
                                        */
  real_T Integrator_IC_dv;             /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S20>/Integrator'
                                        */
  real_T DerivativeGain_Gain_m;        /* Expression: D
                                        * Referenced by: '<S20>/Derivative Gain'
                                        */
  real_T Filter_gainval_py;            /* Computed Parameter: Filter_gainval_py
                                        * Referenced by: '<S20>/Filter'
                                        */
  real_T Filter_IC_o;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S20>/Filter'
                                        */
  real_T FilterCoefficient_Gain_a;     /* Expression: N
                                        * Referenced by: '<S20>/Filter Coefficient'
                                        */
  real_T Gain8_Gain_g;                 /* Expression: 1/0.15
                                        * Referenced by: '<S15>/Gain8'
                                        */
  real_T IntegralGain_Gain_n;          /* Expression: I
                                        * Referenced by: '<S18>/Integral Gain'
                                        */
  real_T IntegralGain_Gain_jp;         /* Expression: I
                                        * Referenced by: '<S19>/Integral Gain'
                                        */
  real_T IntegralGain_Gain_h;          /* Expression: I
                                        * Referenced by: '<S20>/Integral Gain'
                                        */
  real_T IntegralGain_Gain_iw;         /* Expression: I
                                        * Referenced by: '<S21>/Integral Gain'
                                        */
  real_T IntegralGain_Gain_ip;         /* Expression: I
                                        * Referenced by: '<S22>/Integral Gain'
                                        */
  real_T IntegralGain_Gain_he;         /* Expression: I
                                        * Referenced by: '<S23>/Integral Gain'
                                        */
  real_T DiscreteZeroPole1_A[8];       /* Computed Parameter: DiscreteZeroPole1_A
                                        * Referenced by: '<S16>/Discrete Zero-Pole1'
                                        */
  real_T DiscreteZeroPole1_B;          /* Computed Parameter: DiscreteZeroPole1_B
                                        * Referenced by: '<S16>/Discrete Zero-Pole1'
                                        */
  real_T DiscreteZeroPole1_C[4];       /* Computed Parameter: DiscreteZeroPole1_C
                                        * Referenced by: '<S16>/Discrete Zero-Pole1'
                                        */
  real_T DiscreteZeroPole2_A[8];       /* Computed Parameter: DiscreteZeroPole2_A
                                        * Referenced by: '<S16>/Discrete Zero-Pole2'
                                        */
  real_T DiscreteZeroPole2_B;          /* Computed Parameter: DiscreteZeroPole2_B
                                        * Referenced by: '<S16>/Discrete Zero-Pole2'
                                        */
  real_T DiscreteZeroPole2_C[4];       /* Computed Parameter: DiscreteZeroPole2_C
                                        * Referenced by: '<S16>/Discrete Zero-Pole2'
                                        */
  real_T DiscreteZeroPole3_A[8];       /* Computed Parameter: DiscreteZeroPole3_A
                                        * Referenced by: '<S16>/Discrete Zero-Pole3'
                                        */
  real_T DiscreteZeroPole3_B;          /* Computed Parameter: DiscreteZeroPole3_B
                                        * Referenced by: '<S16>/Discrete Zero-Pole3'
                                        */
  real_T DiscreteZeroPole3_C[4];       /* Computed Parameter: DiscreteZeroPole3_C
                                        * Referenced by: '<S16>/Discrete Zero-Pole3'
                                        */
  real_T DiscreteZeroPole4_A[8];       /* Computed Parameter: DiscreteZeroPole4_A
                                        * Referenced by: '<S16>/Discrete Zero-Pole4'
                                        */
  real_T DiscreteZeroPole4_B;          /* Computed Parameter: DiscreteZeroPole4_B
                                        * Referenced by: '<S16>/Discrete Zero-Pole4'
                                        */
  real_T DiscreteZeroPole4_C[4];       /* Computed Parameter: DiscreteZeroPole4_C
                                        * Referenced by: '<S16>/Discrete Zero-Pole4'
                                        */
  real_T DiscreteZeroPole5_A[8];       /* Computed Parameter: DiscreteZeroPole5_A
                                        * Referenced by: '<S16>/Discrete Zero-Pole5'
                                        */
  real_T DiscreteZeroPole5_B;          /* Computed Parameter: DiscreteZeroPole5_B
                                        * Referenced by: '<S16>/Discrete Zero-Pole5'
                                        */
  real_T DiscreteZeroPole5_C[4];       /* Computed Parameter: DiscreteZeroPole5_C
                                        * Referenced by: '<S16>/Discrete Zero-Pole5'
                                        */
  real_T DiscreteZeroPole6_A[8];       /* Computed Parameter: DiscreteZeroPole6_A
                                        * Referenced by: '<S16>/Discrete Zero-Pole6'
                                        */
  real_T DiscreteZeroPole6_B;          /* Computed Parameter: DiscreteZeroPole6_B
                                        * Referenced by: '<S16>/Discrete Zero-Pole6'
                                        */
  real_T DiscreteZeroPole6_C[4];       /* Computed Parameter: DiscreteZeroPole6_C
                                        * Referenced by: '<S16>/Discrete Zero-Pole6'
                                        */
  real_T FeeedForwardGain1_Gain_l;     /* Expression: 16/51.966
                                        * Referenced by: '<S16>/FeeedForward Gain1'
                                        */
  real_T FeeedForwardGain10_Gain_e;    /* Expression: 1/49.788
                                        * Referenced by: '<S16>/FeeedForward Gain10'
                                        */
  real_T FeeedForwardGain11_Gain_b;    /* Expression: 1/51.427
                                        * Referenced by: '<S16>/FeeedForward Gain11'
                                        */
  real_T FeeedForwardGain12_Gain_h;    /* Expression: 15.2/51.427
                                        * Referenced by: '<S16>/FeeedForward Gain12'
                                        */
  real_T FeeedForwardGain2_Gain_i;     /* Expression: 1/51.966
                                        * Referenced by: '<S16>/FeeedForward Gain2'
                                        */
  real_T FeeedForwardGain3_Gain_c;     /* Expression: 20.9/65.089
                                        * Referenced by: '<S16>/FeeedForward Gain3'
                                        */
  real_T FeeedForwardGain4_Gain_i;     /* Expression: 1/65.089
                                        * Referenced by: '<S16>/FeeedForward Gain4'
                                        */
  real_T FeeedForwardGain5_Gain_n;     /* Expression: 12.9/35.737
                                        * Referenced by: '<S16>/FeeedForward Gain5'
                                        */
  real_T FeeedForwardGain6_Gain_h;     /* Expression: 1/35.737
                                        * Referenced by: '<S16>/FeeedForward Gain6'
                                        */
  real_T FeeedForwardGain7_Gain_l;     /* Expression: 26.2/74.788
                                        * Referenced by: '<S16>/FeeedForward Gain7'
                                        */
  real_T FeeedForwardGain8_Gain_m;     /* Expression: 1/74.788
                                        * Referenced by: '<S16>/FeeedForward Gain8'
                                        */
  real_T FeeedForwardGain9_Gain_b;     /* Expression: 17.1/49.788
                                        * Referenced by: '<S16>/FeeedForward Gain9'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain1'
                                        */
  real_T Gain3_Gain_o;                 /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain3'
                                        */
  real_T Gain4_Gain_k;                 /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain4'
                                        */
  real_T Gain5_Gain_i;                 /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain5'
                                        */
  real_T Gain6_Gain_a;                 /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain6'
                                        */
  real_T Gain7_Gain_a;                 /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain7'
                                        */
  real_T Gain8_Gain_l;                 /* Expression: 1/0.15
                                        * Referenced by: '<S16>/Gain8'
                                        */
  real_T ControlSignals_Y0[6];         /* Expression: [0 0 0 0 0 0]
                                        * Referenced by: '<S2>/Control Signals'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Constant3_Value_i;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Constant4_Value_h;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant5_Value_e;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T FIFOwrite1_P1_Size[2];        /* Computed Parameter: FIFOwrite1_P1_Size
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P1;                /* Expression: size
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P2_Size[2];        /* Computed Parameter: FIFOwrite1_P2_Size
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P2;                /* Expression: inputtype
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P3_Size[2];        /* Computed Parameter: FIFOwrite1_P3_Size
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P3;                /* Expression: sampletime
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P4_Size[2];        /* Computed Parameter: FIFOwrite1_P4_Size
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P4;                /* Expression: present
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P5_Size[2];        /* Computed Parameter: FIFOwrite1_P5_Size
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P5[20];            /* Computed Parameter: FIFOwrite1_P5
                                        * Referenced by: '<S38>/FIFO write 1'
                                        */
  real_T FIFOread1_P1_Size[2];         /* Computed Parameter: FIFOread1_P1_Size
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P1;                 /* Expression: maxsize
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P2_Size[2];         /* Computed Parameter: FIFOread1_P2_Size
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P2;                 /* Expression: minsize
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P3_Size[2];         /* Computed Parameter: FIFOread1_P3_Size
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P3;                 /* Expression: usedelimiter
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P4_Size[2];         /* Computed Parameter: FIFOread1_P4_Size
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P4;                 /* Expression: delimiter
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P5_Size[2];         /* Computed Parameter: FIFOread1_P5_Size
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P5;                 /* Expression: outputtype
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P6_Size[2];         /* Computed Parameter: FIFOread1_P6_Size
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P6;                 /* Expression: sampletime
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P7_Size[2];         /* Computed Parameter: FIFOread1_P7_Size
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P7;                 /* Expression: enable
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P8_Size[2];         /* Computed Parameter: FIFOread1_P8_Size
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOread1_P8;                 /* Expression: enableout
                                        * Referenced by: '<S40>/FIFO read 1'
                                        */
  real_T FIFOwrite2_P1_Size[2];        /* Computed Parameter: FIFOwrite2_P1_Size
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P1;                /* Expression: size
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P2_Size[2];        /* Computed Parameter: FIFOwrite2_P2_Size
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P2;                /* Expression: inputtype
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P3_Size[2];        /* Computed Parameter: FIFOwrite2_P3_Size
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P3;                /* Expression: sampletime
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P4_Size[2];        /* Computed Parameter: FIFOwrite2_P4_Size
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P4;                /* Expression: present
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P5_Size[2];        /* Computed Parameter: FIFOwrite2_P5_Size
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P5[20];            /* Computed Parameter: FIFOwrite2_P5
                                        * Referenced by: '<S39>/FIFO write 2'
                                        */
  real_T FIFOread2_P1_Size[2];         /* Computed Parameter: FIFOread2_P1_Size
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P1;                 /* Expression: maxsize
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P2_Size[2];         /* Computed Parameter: FIFOread2_P2_Size
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P2;                 /* Expression: minsize
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P3_Size[2];         /* Computed Parameter: FIFOread2_P3_Size
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P3;                 /* Expression: usedelimiter
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P4_Size[2];         /* Computed Parameter: FIFOread2_P4_Size
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P4;                 /* Expression: delimiter
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P5_Size[2];         /* Computed Parameter: FIFOread2_P5_Size
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P5;                 /* Expression: outputtype
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P6_Size[2];         /* Computed Parameter: FIFOread2_P6_Size
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P6;                 /* Expression: sampletime
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P7_Size[2];         /* Computed Parameter: FIFOread2_P7_Size
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P7;                 /* Expression: enable
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P8_Size[2];         /* Computed Parameter: FIFOread2_P8_Size
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T FIFOread2_P8;                 /* Expression: enableout
                                        * Referenced by: '<S41>/FIFO read 2'
                                        */
  real_T ControlConstant_Value;        /* Expression: 0
                                        * Referenced by: '<Root>/ControlConstant'
                                        */
  real_T MM16ATAnalogInput_P1_Size[2]; /* Computed Parameter: MM16ATAnalogInput_P1_Size
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */
  real_T MM16ATAnalogInput_P1;         /* Expression: firstChan
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */
  real_T MM16ATAnalogInput_P2_Size[2]; /* Computed Parameter: MM16ATAnalogInput_P2_Size
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */
  real_T MM16ATAnalogInput_P2;         /* Expression: numChans
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */
  real_T MM16ATAnalogInput_P3_Size[2]; /* Computed Parameter: MM16ATAnalogInput_P3_Size
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */
  real_T MM16ATAnalogInput_P3;         /* Expression: range
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */
  real_T MM16ATAnalogInput_P4_Size[2]; /* Computed Parameter: MM16ATAnalogInput_P4_Size
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */
  real_T MM16ATAnalogInput_P4;         /* Expression: sampleTime
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */
  real_T MM16ATAnalogInput_P5_Size[2]; /* Computed Parameter: MM16ATAnalogInput_P5_Size
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */
  real_T MM16ATAnalogInput_P5;         /* Expression: baseDec
                                        * Referenced by: '<S6>/MM-16-AT Analog Input'
                                        */
  real_T DiscreteStateSpace5_A[4];     /* Computed Parameter: DiscreteStateSpace5_A
                                        * Referenced by: '<S42>/Discrete State-Space5'
                                        */
  real_T DiscreteStateSpace5_B[2];     /* Computed Parameter: DiscreteStateSpace5_B
                                        * Referenced by: '<S42>/Discrete State-Space5'
                                        */
  real_T DiscreteStateSpace5_C[2];     /* Computed Parameter: DiscreteStateSpace5_C
                                        * Referenced by: '<S42>/Discrete State-Space5'
                                        */
  real_T DiscreteStateSpace5_D;        /* Computed Parameter: DiscreteStateSpace5_D
                                        * Referenced by: '<S42>/Discrete State-Space5'
                                        */
  real_T DiscreteStateSpace5_X0[2];    /* Expression: IniStates(5,:)
                                        * Referenced by: '<S42>/Discrete State-Space5'
                                        */
  real_T Gain11_Gain;                  /* Expression: -67.813
                                        * Referenced by: '<S42>/Gain11'
                                        */
  real_T Constant6_Value;              /* Expression: 343.38
                                        * Referenced by: '<S42>/Constant6'
                                        */
  real_T DiscreteStateSpace4_A[4];     /* Computed Parameter: DiscreteStateSpace4_A
                                        * Referenced by: '<S42>/Discrete State-Space4'
                                        */
  real_T DiscreteStateSpace4_B[2];     /* Computed Parameter: DiscreteStateSpace4_B
                                        * Referenced by: '<S42>/Discrete State-Space4'
                                        */
  real_T DiscreteStateSpace4_C[2];     /* Computed Parameter: DiscreteStateSpace4_C
                                        * Referenced by: '<S42>/Discrete State-Space4'
                                        */
  real_T DiscreteStateSpace4_D;        /* Computed Parameter: DiscreteStateSpace4_D
                                        * Referenced by: '<S42>/Discrete State-Space4'
                                        */
  real_T DiscreteStateSpace4_X0[2];    /* Expression: IniStates(5,:)
                                        * Referenced by: '<S42>/Discrete State-Space4'
                                        */
  real_T Gain10_Gain;                  /* Expression: -67.813
                                        * Referenced by: '<S42>/Gain10'
                                        */
  real_T Constant5_Value_p;            /* Expression: 343.38
                                        * Referenced by: '<S42>/Constant5'
                                        */
  real_T DiscreteStateSpace3_A[4];     /* Computed Parameter: DiscreteStateSpace3_A
                                        * Referenced by: '<S42>/Discrete State-Space3'
                                        */
  real_T DiscreteStateSpace3_B[2];     /* Computed Parameter: DiscreteStateSpace3_B
                                        * Referenced by: '<S42>/Discrete State-Space3'
                                        */
  real_T DiscreteStateSpace3_C[2];     /* Computed Parameter: DiscreteStateSpace3_C
                                        * Referenced by: '<S42>/Discrete State-Space3'
                                        */
  real_T DiscreteStateSpace3_D;        /* Computed Parameter: DiscreteStateSpace3_D
                                        * Referenced by: '<S42>/Discrete State-Space3'
                                        */
  real_T DiscreteStateSpace3_X0[2];    /* Expression: IniStates(4,:)
                                        * Referenced by: '<S42>/Discrete State-Space3'
                                        */
  real_T Gain9_Gain;                   /* Expression: -67.813
                                        * Referenced by: '<S42>/Gain9'
                                        */
  real_T Constant4_Value_p;            /* Expression: 343.38
                                        * Referenced by: '<S42>/Constant4'
                                        */
  real_T DiscreteStateSpace2_A[4];     /* Computed Parameter: DiscreteStateSpace2_A
                                        * Referenced by: '<S42>/Discrete State-Space2'
                                        */
  real_T DiscreteStateSpace2_B[2];     /* Computed Parameter: DiscreteStateSpace2_B
                                        * Referenced by: '<S42>/Discrete State-Space2'
                                        */
  real_T DiscreteStateSpace2_C[2];     /* Computed Parameter: DiscreteStateSpace2_C
                                        * Referenced by: '<S42>/Discrete State-Space2'
                                        */
  real_T DiscreteStateSpace2_D;        /* Computed Parameter: DiscreteStateSpace2_D
                                        * Referenced by: '<S42>/Discrete State-Space2'
                                        */
  real_T DiscreteStateSpace2_X0[2];    /* Expression: IniStates(3,:)
                                        * Referenced by: '<S42>/Discrete State-Space2'
                                        */
  real_T Gain8_Gain_e;                 /* Expression: -67.485
                                        * Referenced by: '<S42>/Gain8'
                                        */
  real_T Constant3_Value_c;            /* Expression: 338.48
                                        * Referenced by: '<S42>/Constant3'
                                        */
  real_T DiscreteStateSpace1_A[4];     /* Computed Parameter: DiscreteStateSpace1_A
                                        * Referenced by: '<S42>/Discrete State-Space1'
                                        */
  real_T DiscreteStateSpace1_B[2];     /* Computed Parameter: DiscreteStateSpace1_B
                                        * Referenced by: '<S42>/Discrete State-Space1'
                                        */
  real_T DiscreteStateSpace1_C[2];     /* Computed Parameter: DiscreteStateSpace1_C
                                        * Referenced by: '<S42>/Discrete State-Space1'
                                        */
  real_T DiscreteStateSpace1_D;        /* Computed Parameter: DiscreteStateSpace1_D
                                        * Referenced by: '<S42>/Discrete State-Space1'
                                        */
  real_T DiscreteStateSpace1_X0[2];    /* Expression: IniStates(2,:)
                                        * Referenced by: '<S42>/Discrete State-Space1'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: -67.813
                                        * Referenced by: '<S42>/Gain1'
                                        */
  real_T Constant1_Value_n;            /* Expression: 343.38
                                        * Referenced by: '<S42>/Constant1'
                                        */
  real_T DiscreteStateSpace6_A[4];     /* Computed Parameter: DiscreteStateSpace6_A
                                        * Referenced by: '<S42>/Discrete State-Space6'
                                        */
  real_T DiscreteStateSpace6_B[2];     /* Computed Parameter: DiscreteStateSpace6_B
                                        * Referenced by: '<S42>/Discrete State-Space6'
                                        */
  real_T DiscreteStateSpace6_C[2];     /* Computed Parameter: DiscreteStateSpace6_C
                                        * Referenced by: '<S42>/Discrete State-Space6'
                                        */
  real_T DiscreteStateSpace6_D;        /* Computed Parameter: DiscreteStateSpace6_D
                                        * Referenced by: '<S42>/Discrete State-Space6'
                                        */
  real_T DiscreteStateSpace6_X0[2];    /* Expression: IniStates(1,:)
                                        * Referenced by: '<S42>/Discrete State-Space6'
                                        */
  real_T Gain_Gain;                    /* Expression: -67.813
                                        * Referenced by: '<S42>/Gain'
                                        */
  real_T Constant2_Value_f;            /* Expression: 343.38
                                        * Referenced by: '<S42>/Constant2'
                                        */
  real_T Merge_InitialOutput[6];       /* Expression: [0 0 0 0 0 0]
                                        * Referenced by: '<Root>/Merge'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: Satura
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: -Satura
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation1_UpperSat_b;       /* Expression: Satura
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_m;       /* Expression: -Satura
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation2_UpperSat_j;       /* Expression: Satura
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_a;       /* Expression: -Satura
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T Saturation3_UpperSat_m;       /* Expression: Satura
                                        * Referenced by: '<S5>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_j;       /* Expression: -Satura
                                        * Referenced by: '<S5>/Saturation3'
                                        */
  real_T Saturation4_UpperSat_n;       /* Expression: Satura
                                        * Referenced by: '<S5>/Saturation4'
                                        */
  real_T Saturation4_LowerSat_p;       /* Expression: -Satura
                                        * Referenced by: '<S5>/Saturation4'
                                        */
  real_T Saturation5_UpperSat_l;       /* Expression: Satura
                                        * Referenced by: '<S5>/Saturation5'
                                        */
  real_T Saturation5_LowerSat_l;       /* Expression: -Satura
                                        * Referenced by: '<S5>/Saturation5'
                                        */
  real_T ASCIIEncode_P1_Size[2];       /* Computed Parameter: ASCIIEncode_P1_Size
                                        * Referenced by: '<S5>/ASCII Encode '
                                        */
  real_T ASCIIEncode_P1[13];           /* Computed Parameter: ASCIIEncode_P1
                                        * Referenced by: '<S5>/ASCII Encode '
                                        */
  real_T ASCIIEncode_P2_Size[2];       /* Computed Parameter: ASCIIEncode_P2_Size
                                        * Referenced by: '<S5>/ASCII Encode '
                                        */
  real_T ASCIIEncode_P2;               /* Expression: maxlength
                                        * Referenced by: '<S5>/ASCII Encode '
                                        */
  real_T ASCIIEncode_P3_Size[2];       /* Computed Parameter: ASCIIEncode_P3_Size
                                        * Referenced by: '<S5>/ASCII Encode '
                                        */
  real_T ASCIIEncode_P3;               /* Expression: nvars
                                        * Referenced by: '<S5>/ASCII Encode '
                                        */
  real_T ASCIIEncode_P4_Size[2];       /* Computed Parameter: ASCIIEncode_P4_Size
                                        * Referenced by: '<S5>/ASCII Encode '
                                        */
  real_T ASCIIEncode_P4[6];            /* Expression: varids
                                        * Referenced by: '<S5>/ASCII Encode '
                                        */
  real_T FIFOwrite1_P1_Size_j[2];      /* Computed Parameter: FIFOwrite1_P1_Size_j
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P1_m;              /* Expression: size
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P2_Size_b[2];      /* Computed Parameter: FIFOwrite1_P2_Size_b
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P2_n;              /* Expression: inputtype
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P3_Size_f[2];      /* Computed Parameter: FIFOwrite1_P3_Size_f
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P3_g;              /* Expression: sampletime
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P4_Size_o[2];      /* Computed Parameter: FIFOwrite1_P4_Size_o
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P4_i;              /* Expression: present
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P5_Size_f[2];      /* Computed Parameter: FIFOwrite1_P5_Size_f
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */
  real_T FIFOwrite1_P5_h[20];          /* Computed Parameter: FIFOwrite1_P5_h
                                        * Referenced by: '<S24>/FIFO write 1'
                                        */
  real_T FIFOwrite2_P1_Size_j[2];      /* Computed Parameter: FIFOwrite2_P1_Size_j
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P1_c;              /* Expression: size
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P2_Size_a[2];      /* Computed Parameter: FIFOwrite2_P2_Size_a
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P2_n;              /* Expression: inputtype
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P3_Size_e[2];      /* Computed Parameter: FIFOwrite2_P3_Size_e
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P3_e;              /* Expression: sampletime
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P4_Size_d[2];      /* Computed Parameter: FIFOwrite2_P4_Size_d
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P4_i;              /* Expression: present
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P5_Size_d[2];      /* Computed Parameter: FIFOwrite2_P5_Size_d
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */
  real_T FIFOwrite2_P5_o[20];          /* Computed Parameter: FIFOwrite2_P5_o
                                        * Referenced by: '<S24>/FIFO write 2'
                                        */
  real_T FIFOread1_P1_Size_n[2];       /* Computed Parameter: FIFOread1_P1_Size_n
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P1_f;               /* Expression: maxsize
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P2_Size_i[2];       /* Computed Parameter: FIFOread1_P2_Size_i
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P2_d;               /* Expression: minsize
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P3_Size_l[2];       /* Computed Parameter: FIFOread1_P3_Size_l
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P3_d;               /* Expression: usedelimiter
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P4_Size_c[2];       /* Computed Parameter: FIFOread1_P4_Size_c
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P4_o;               /* Expression: delimiter
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P5_Size_b[2];       /* Computed Parameter: FIFOread1_P5_Size_b
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P5_d;               /* Expression: outputtype
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P6_Size_g[2];       /* Computed Parameter: FIFOread1_P6_Size_g
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P6_h;               /* Expression: sampletime
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P7_Size_b[2];       /* Computed Parameter: FIFOread1_P7_Size_b
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P7_h;               /* Expression: enable
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P8_Size_p[2];       /* Computed Parameter: FIFOread1_P8_Size_p
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread1_P8_n;               /* Expression: enableout
                                        * Referenced by: '<S24>/FIFO read 1'
                                        */
  real_T FIFOread2_P1_Size_d[2];       /* Computed Parameter: FIFOread2_P1_Size_d
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P1_c;               /* Expression: maxsize
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P2_Size_g[2];       /* Computed Parameter: FIFOread2_P2_Size_g
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P2_g;               /* Expression: minsize
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P3_Size_f[2];       /* Computed Parameter: FIFOread2_P3_Size_f
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P3_o;               /* Expression: usedelimiter
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P4_Size_e[2];       /* Computed Parameter: FIFOread2_P4_Size_e
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P4_a;               /* Expression: delimiter
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P5_Size_d[2];       /* Computed Parameter: FIFOread2_P5_Size_d
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P5_c;               /* Expression: outputtype
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P6_Size_p[2];       /* Computed Parameter: FIFOread2_P6_Size_p
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P6_k;               /* Expression: sampletime
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P7_Size_n[2];       /* Computed Parameter: FIFOread2_P7_Size_n
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P7_c;               /* Expression: enable
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P8_Size_k[2];       /* Computed Parameter: FIFOread2_P8_Size_k
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T FIFOread2_P8_a;               /* Expression: enableout
                                        * Referenced by: '<S24>/FIFO read 2'
                                        */
  real_T Setup1_P1_Size[2];            /* Computed Parameter: Setup1_P1_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P1;                    /* Expression: addr
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P2_Size[2];            /* Computed Parameter: Setup1_P2_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P2;                    /* Expression: baud
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P3_Size[2];            /* Computed Parameter: Setup1_P3_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P3;                    /* Expression: width
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P4_Size[2];            /* Computed Parameter: Setup1_P4_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P4;                    /* Expression: nstop
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P5_Size[2];            /* Computed Parameter: Setup1_P5_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P5;                    /* Expression: parity
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P6_Size[2];            /* Computed Parameter: Setup1_P6_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P6;                    /* Expression: fmode
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P7_Size[2];            /* Computed Parameter: Setup1_P7_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P7;                    /* Expression: ctsmode
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P8_Size[2];            /* Computed Parameter: Setup1_P8_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P8;                    /* Expression: rlevel
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup2_P1_Size[2];            /* Computed Parameter: Setup2_P1_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P1;                    /* Expression: addr
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P2_Size[2];            /* Computed Parameter: Setup2_P2_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P2;                    /* Expression: baud
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P3_Size[2];            /* Computed Parameter: Setup2_P3_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P3;                    /* Expression: width
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P4_Size[2];            /* Computed Parameter: Setup2_P4_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P4;                    /* Expression: nstop
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P5_Size[2];            /* Computed Parameter: Setup2_P5_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P5;                    /* Expression: parity
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P6_Size[2];            /* Computed Parameter: Setup2_P6_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P6;                    /* Expression: fmode
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P7_Size[2];            /* Computed Parameter: Setup2_P7_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P7;                    /* Expression: ctsmode
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P8_Size[2];            /* Computed Parameter: Setup2_P8_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P8;                    /* Expression: rlevel
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Gain2_Gain;                   /* Expression: 3.75
                                        * Referenced by: '<S42>/Gain2'
                                        */
  real_T Gain3_Gain_m;                 /* Expression: 3.75
                                        * Referenced by: '<S42>/Gain3'
                                        */
  real_T Gain4_Gain_n;                 /* Expression: 3.75
                                        * Referenced by: '<S42>/Gain4'
                                        */
  real_T Gain5_Gain_d;                 /* Expression: 3.75
                                        * Referenced by: '<S42>/Gain5'
                                        */
  real_T Gain6_Gain_b;                 /* Expression: 3.75
                                        * Referenced by: '<S42>/Gain6'
                                        */
  real_T Gain7_Gain_m;                 /* Expression: 3.75
                                        * Referenced by: '<S42>/Gain7'
                                        */
  uint32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S38>/Constant'
                                        */
  uint32_T Constant1_Value_k;          /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S40>/Constant1'
                                        */
  uint32_T Constant_Value_i;           /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S39>/Constant'
                                        */
  uint32_T Constant2_Value_h;          /* Computed Parameter: Constant2_Value_h
                                        * Referenced by: '<S41>/Constant2'
                                        */
  rtP_IfActionSubsystem1_GUI_User IfActionSubsystem11;/* '<S5>/If Action Subsystem11' */
  rtP_IfActionSubsystem_GUI_User_ IfActionSubsystem10;/* '<S5>/If Action Subsystem10' */
  rtP_IfActionSubsystem1_GUI_User IfActionSubsystem9;/* '<S5>/If Action Subsystem9' */
  rtP_IfActionSubsystem_GUI_User_ IfActionSubsystem8;/* '<S5>/If Action Subsystem8' */
  rtP_IfActionSubsystem1_GUI_User IfActionSubsystem7;/* '<S5>/If Action Subsystem7' */
  rtP_IfActionSubsystem_GUI_User_ IfActionSubsystem6_a;/* '<S5>/If Action Subsystem6' */
  rtP_IfActionSubsystem1_GUI_User IfActionSubsystem5_i;/* '<S5>/If Action Subsystem5' */
  rtP_IfActionSubsystem_GUI_User_ IfActionSubsystem4;/* '<S5>/If Action Subsystem4' */
  rtP_IfActionSubsystem1_GUI_User IfActionSubsystem3;/* '<S5>/If Action Subsystem3' */
  rtP_IfActionSubsystem_GUI_User_ IfActionSubsystem2_c;/* '<S5>/If Action Subsystem2' */
  rtP_IfActionSubsystem1_GUI_User IfActionSubsystem1;/* '<S5>/If Action Subsystem1' */
  rtP_IfActionSubsystem_GUI_User_ IfActionSubsystem_h;/* '<S5>/If Action Subsystem' */
};

/* Real-time Model Data Structure */
struct rtModel_GUI_User_V1_3 {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[13];
    SimStruct *childSFunctionPtrs[13];
    struct _ssBlkInfo2 blkInfo2[13];
    struct _ssSFcnModelMethods2 methods2[13];
    struct _ssSFcnModelMethods3 methods3[13];
    struct _ssStatesInfo2 statesInfo2[13];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[8];
      mxArray *params[8];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[8];
      mxArray *params[8];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[12];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[6];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[1];
      real_T const *UPtrs3[1];
      real_T const *UPtrs4[1];
      real_T const *UPtrs5[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[8];
      mxArray *params[8];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[8];
      mxArray *params[8];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn11;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn12;
  } NonInlinedSFcns;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint8_T rtmDbBufReadBuf1;
    uint8_T rtmDbBufWriteBuf1;
    boolean_T rtmDbBufLastBufWr1;
    uint32_T rtmDbBufClockTick1[2];
    uint32_T rtmDbBufClockTickH1[2];
    boolean_T firstInitCondFlag;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[2];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_GUI_User_V1_3 GUI_User_V1_3_P;

/* Block signals (auto storage) */
extern BlockIO_GUI_User_V1_3 GUI_User_V1_3_B;

/* Block states (auto storage) */
extern D_Work_GUI_User_V1_3 GUI_User_V1_3_DWork;

/* External data declarations for dependent source files */
extern const uint8_T GUI_User_V1_3_U8GND;/* uint8_T ground */
extern const uint8_T GUI_User_V1_3_U8GND;/* uint8_T ground */

/* Model entry point functions */
extern void GUI_User_V1_3_initialize(boolean_T firstTime);
extern void GUI_User_V1_3_output(int_T tid);
extern void GUI_User_V1_3_update(int_T tid);
extern void GUI_User_V1_3_terminate(void);

/* Real-time Model object */
extern struct rtModel_GUI_User_V1_3 *const GUI_User_V1_3_rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : GUI_User_V1_3
 * '<S1>'   : GUI_User_V1_3/If Action Subsystem
 * '<S2>'   : GUI_User_V1_3/If Action Subsystem2
 * '<S3>'   : GUI_User_V1_3/If Action Subsystem5
 * '<S4>'   : GUI_User_V1_3/If Action Subsystem6
 * '<S5>'   : GUI_User_V1_3/Motors - F4  STM - PWM
 * '<S6>'   : GUI_User_V1_3/SG-ADC Sensors
 * '<S7>'   : GUI_User_V1_3/If Action Subsystem5/Set1
 * '<S8>'   : GUI_User_V1_3/If Action Subsystem5/Set1/FeedForwardController
 * '<S9>'   : GUI_User_V1_3/If Action Subsystem5/Set1/FeedForwardController/PID Controller1
 * '<S10>'  : GUI_User_V1_3/If Action Subsystem5/Set1/FeedForwardController/PID Controller2
 * '<S11>'  : GUI_User_V1_3/If Action Subsystem5/Set1/FeedForwardController/PID Controller3
 * '<S12>'  : GUI_User_V1_3/If Action Subsystem5/Set1/FeedForwardController/PID Controller4
 * '<S13>'  : GUI_User_V1_3/If Action Subsystem5/Set1/FeedForwardController/PID Controller5
 * '<S14>'  : GUI_User_V1_3/If Action Subsystem5/Set1/FeedForwardController/PID Controller6
 * '<S15>'  : GUI_User_V1_3/If Action Subsystem6/FeedForwardController
 * '<S16>'  : GUI_User_V1_3/If Action Subsystem6/Hinf Ganancia Mixta
 * '<S17>'  : GUI_User_V1_3/If Action Subsystem6/Referece
 * '<S18>'  : GUI_User_V1_3/If Action Subsystem6/FeedForwardController/PID Controller1
 * '<S19>'  : GUI_User_V1_3/If Action Subsystem6/FeedForwardController/PID Controller2
 * '<S20>'  : GUI_User_V1_3/If Action Subsystem6/FeedForwardController/PID Controller3
 * '<S21>'  : GUI_User_V1_3/If Action Subsystem6/FeedForwardController/PID Controller4
 * '<S22>'  : GUI_User_V1_3/If Action Subsystem6/FeedForwardController/PID Controller5
 * '<S23>'  : GUI_User_V1_3/If Action Subsystem6/FeedForwardController/PID Controller6
 * '<S24>'  : GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1
 * '<S25>'  : GUI_User_V1_3/Motors - F4  STM - PWM/If Action Subsystem
 * '<S26>'  : GUI_User_V1_3/Motors - F4  STM - PWM/If Action Subsystem1
 * '<S27>'  : GUI_User_V1_3/Motors - F4  STM - PWM/If Action Subsystem10
 * '<S28>'  : GUI_User_V1_3/Motors - F4  STM - PWM/If Action Subsystem11
 * '<S29>'  : GUI_User_V1_3/Motors - F4  STM - PWM/If Action Subsystem2
 * '<S30>'  : GUI_User_V1_3/Motors - F4  STM - PWM/If Action Subsystem3
 * '<S31>'  : GUI_User_V1_3/Motors - F4  STM - PWM/If Action Subsystem4
 * '<S32>'  : GUI_User_V1_3/Motors - F4  STM - PWM/If Action Subsystem5
 * '<S33>'  : GUI_User_V1_3/Motors - F4  STM - PWM/If Action Subsystem6
 * '<S34>'  : GUI_User_V1_3/Motors - F4  STM - PWM/If Action Subsystem7
 * '<S35>'  : GUI_User_V1_3/Motors - F4  STM - PWM/If Action Subsystem8
 * '<S36>'  : GUI_User_V1_3/Motors - F4  STM - PWM/If Action Subsystem9
 * '<S37>'  : GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR
 * '<S38>'  : GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1
 * '<S39>'  : GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2
 * '<S40>'  : GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1
 * '<S41>'  : GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2
 * '<S42>'  : GUI_User_V1_3/SG-ADC Sensors/Signal Filtering and scaling
 */
#endif                                 /* RTW_HEADER_GUI_User_V1_3_h_ */
