#ifndef __GUI_User_V1_3_XPCOPTIONS_H___
#define __GUI_User_V1_3_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "GUI_User_V1_3.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_GUI_User_V1_3))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
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
void GUI_User_V1_3_ChangeStepSize(real_T newBaseRateStepSize,
  rtModel_GUI_User_V1_3 *const GUI_User_V1_3_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  GUI_User_V1_3_rtM->Timing.stepSize0 = GUI_User_V1_3_rtM->Timing.stepSize0 *
    ratio;
  GUI_User_V1_3_rtM->Timing.stepSize = GUI_User_V1_3_rtM->Timing.stepSize *
    ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  GUI_User_V1_3_ChangeStepSize(stepSize, GUI_User_V1_3_rtM);
}

#endif                                 /* __GUI_User_V1_3_XPCOPTIONS_H___ */
