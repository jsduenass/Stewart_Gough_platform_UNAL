#ifndef __IdentificationMotor2Order_XPCOPTIONS_H___
#define __IdentificationMotor2Order_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "IdentificationMotor2Order.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_IdentificationMotor2Order))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     15000000
#define PROFILINGFLAG                  0
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0

/* Change all stepsize using the newBaseRateStepSize */
void IdentificationMotor2Order_ChangeStepSize(real_T newBaseRateStepSize,
  rtModel_IdentificationMotor2Order *const IdentificationMotor2Order_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  IdentificationMotor2Order_rtM->Timing.stepSize0 =
    IdentificationMotor2Order_rtM->Timing.stepSize0 * ratio;
  IdentificationMotor2Order_rtM->Timing.stepSize =
    IdentificationMotor2Order_rtM->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  IdentificationMotor2Order_ChangeStepSize(stepSize,
    IdentificationMotor2Order_rtM);
}

#endif                                 /* __IdentificationMotor2Order_XPCOPTIONS_H___ */
