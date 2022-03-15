/*
 * IdentificationMotor2Order_private.h
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
#ifndef RTW_HEADER_IdentificationMotor2Order_private_h_
#define RTW_HEADER_IdentificationMotor2Order_private_h_
#include "rtwtypes.h"

/* Used by FromWorkspace Block: '<Root>/Velocity reference2' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

/* Define interrupt functions for board 1 */
xpcPCIDevice xpcDev_1;

/* Done with interrupt functions for board 1 */
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern void fifowrite(SimStruct *rts);
extern void fiforead(SimStruct *rts);
extern void addiamondmm16atcustom(SimStruct *rts);
extern void asciiencode(SimStruct *rts);
extern void sersetupbase(SimStruct *rts);
extern void IdentificationMo_RS232ISR_Start(void);
extern void IdentificationMotor2Or_RS232ISR(int_T controlPortIdx);
extern void Identificatio_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1,
  rtB_IfActionSubsystem_Identific *localB, rtP_IfActionSubsystem_Identific
  *localP);
extern void Identificati_IfActionSubsystem1(real_T rtu_In1, real_T *rty_Out1,
  rtB_IfActionSubsystem1_Identifi *localB, rtP_IfActionSubsystem1_Identifi
  *localP);

#endif                                 /* RTW_HEADER_IdentificationMotor2Order_private_h_ */
