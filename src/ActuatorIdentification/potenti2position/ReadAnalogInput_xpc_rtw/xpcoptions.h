#ifndef __ReadAnalogInput_XPCOPTIONS_H___
#define __ReadAnalogInput_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "ReadAnalogInput.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_ReadAnalogInput))
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
void ReadAnalogInput_ChangeStepSize(real_T newBaseRateStepSize,
  rtModel_ReadAnalogInput *const ReadAnalogInput_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  ReadAnalogInput_rtM->Timing.stepSize0 = ReadAnalogInput_rtM->Timing.stepSize0 *
    ratio;
  ReadAnalogInput_rtM->Timing.stepSize = ReadAnalogInput_rtM->Timing.stepSize *
    ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  ReadAnalogInput_ChangeStepSize(stepSize, ReadAnalogInput_rtM);
}

#endif                                 /* __ReadAnalogInput_XPCOPTIONS_H___ */
