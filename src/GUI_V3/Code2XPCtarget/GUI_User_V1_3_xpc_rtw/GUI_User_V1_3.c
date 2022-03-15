/*
 * GUI_User_V1_3.c
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

#include "rt_logging_mmi.h"
#include "GUI_User_V1_3_capi.h"
#include "GUI_User_V1_3.h"
#include "GUI_User_V1_3_private.h"
#include <stdio.h>
#include "GUI_User_V1_3_dt.h"

const uint8_T GUI_User_V1_3_U8GND = 0U;/* uint8_T ground */

/* Block signals (auto storage) */
BlockIO_GUI_User_V1_3 GUI_User_V1_3_B;

/* Block states (auto storage) */
D_Work_GUI_User_V1_3 GUI_User_V1_3_DWork;

/* Real-time model */
rtModel_GUI_User_V1_3 GUI_User_V1_3_rtM_;
rtModel_GUI_User_V1_3 *const GUI_User_V1_3_rtM = &GUI_User_V1_3_rtM_;

/* xPC Target Async Interrupt Block '<S24>/IRQ Source' */
void xPCISR1(void)
{
  {
    /* RTWBLOCK_START_COMMENT */
    /* RTWBLOCK_START_COMMENT */
    /* RTWBLOCK_START_COMMENT */
    /* RTWBLOCK_START_COMMENT */
    /* Reset subsysRan breadcrumbs */
    srClearBC(GUI_User_V1_3_DWork.Receive1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(GUI_User_V1_3_DWork.Transmit1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(GUI_User_V1_3_DWork.Receive2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(GUI_User_V1_3_DWork.Transmit2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(GUI_User_V1_3_DWork.RS232ISR_SubsysRanBC);

    /* RateTransition: '<S24>/Rate Transition' */
    /* RTWBLOCK_START_COMMENT */
    GUI_User_V1_3_B.RateTransition = GUI_User_V1_3_B.FIFOwrite1_o1;

    /* RateTransition: '<S24>/Rate Transition2' */
    GUI_User_V1_3_B.RateTransition2 = GUI_User_V1_3_B.FIFOwrite2_o1;
    GUI_User_V1_3_RS232ISR(0);
  }
}

/* Start for function-call system: '<S24>/RS232 ISR' */
void GUI_User_V1_3_RS232ISR_Start(void)
{
  /* Start for function-call system: '<S37>/Receive 1' */

  /* S-Function Block: <S38>/Read HW FIFO1 (serreadbase) */
  {
    int count = 0;

    // Flush the hardware fifo on startup.
    while (xpcInpB( (unsigned short)(1016 + LSR) ) & LSRDR ) {
      // Read and discard the data.
      xpcInpB( (unsigned short)(1016 + DATA) );
      if (count++ > 1000 ) {
        static char msg[50];
        sprintf( msg, "A UART at address 0x%x is not responding", 1016 );

        // No baseboard UART has that large a hardware fifo!
        rtmSetErrorStatus(GUI_User_V1_3_rtM, msg);
        return;
      }
    }
  }

  /* Level2 S-Function Block: '<S38>/FIFO write 1' (fifowrite) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for function-call system: '<S37>/Transmit 1' */

  /* Level2 S-Function Block: '<S40>/FIFO read 1' (fiforead) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for function-call system: '<S37>/Receive 2' */

  /* Level2 S-Function Block: '<S39>/FIFO write 2' (fifowrite) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for function-call system: '<S37>/Transmit 2' */

  /* Level2 S-Function Block: '<S41>/FIFO read 2' (fiforead) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Output and update for function-call system: '<S24>/RS232 ISR' */
void GUI_User_V1_3_RS232ISR(int_T controlPortIdx)
{
  /* S-Function Block: <S37>/Read Int Status FC1 (iquerybase) */
  {
    int base[2] = { (int)1016, (int)0 };

    uint32_T port, max;
    volatile int iir;                  // local interrupt register, per uart
    for (port = 0 ; port < 2 ; port++ ) {
      if (base[port] == 0 ) {
        continue;
      }

      iir = xpcInpB( (unsigned short)(base[port] + IIR) ) & 0xff;

      //printf("lint = 0x%x\n", iir );
      if ((iir & (IIRFEBL | IIR64) ) == (IIRFEBL | IIR64) )
        max = 60;
      else if ((iir & (IIRFEBL | IIR64) ) == IIRFEBL )
        max = 15;
      else
        max = 1;
      *&GUI_User_V1_3_B.ReadIntStatusFC1_o2 = max;
      iir &= IIRREASON;
      while (iir != 1 )                // Service all reasons
      {
        switch ( iir )
        {
         case 1:                       // No interrupt on this UART
          break;

         case 4:                       // received data available
         case 6:                       // receiver line status, overrun etc.
         case 0xc:                     // character timeout
          //printf("%1xa", base[i]>>8);
          // All three are receive interrupts
          switch (port)
          {
           case 0:
            /* Output and update for function-call system: '<S37>/Receive 1' */

            /* S-Function (serreadbase): '<S38>/Read HW FIFO1' */
            {
              /* S-Function Block: <S38>/Read HW FIFO1 (serreadbase) */
              int status = 0;
              int count = 0;

              // While there is data in the fifo, read it, also read error status.
              // Cap the read length to the interrupt point in 64 byte fifo mode.
              while (((status = xpcInpB( (unsigned short)(1016 + LSR) ) & 0xff )
                      & LSRDR) && (count < 56) ) {
                int c;
                int masked;
                count++;
                c = xpcInpB( (unsigned short)(1016 + DATA) ) & 0xff;// read character
                masked = status & (LSROE | LSRPE | LSRFE | LSRBI);
                ((int_T *)GUI_User_V1_3_B.ReadHWFIFO1)[count] = (masked << 8) |
                  c;
              }

              ((int_T *)GUI_User_V1_3_B.ReadHWFIFO1)[0] = count;
            }

            /* Level2 S-Function Block: '<S38>/FIFO write 1' (fifowrite) */
            {
              SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[1];
              sfcnOutputs(rts, 1);
            }

            GUI_User_V1_3_DWork.Receive1_SubsysRanBC = 4;
            break;
          }
          break;

         case 2:                       // Transmitter holding register empty
          //printf("%1xb", base[i]>>8);
          switch (port)
          {
           case 0:
            /* Output and update for function-call system: '<S37>/Transmit 1' */

            /* Level2 S-Function Block: '<S40>/FIFO read 1' (fiforead) */
            {
              SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[2];
              sfcnOutputs(rts, 1);
            }

            /* S-Function (serwritebase): '<S40>/Write HW FIFO1' */
            {
              /* S-Function Block: <S40>/Write HW FIFO1 (serwritebase) */
              int_T *IPtr = (int_T *)GUI_User_V1_3_B.FIFOread1_o1;
              if (GUI_User_V1_3_B.FIFOread1_o2 > 0 ) {
                // On entry, verify that the transmitter holding register is empty
                // so we can stuff all that came from the software fifo into the
                // hardware fifo.  Assume that the software fifo has a max read
                // parameter that fits with the hardware fifo mode setting.
                if (IPtr[0] == 0 ) {
                  // No data, turn off the transmitter empty interrupt and leave
                  int ier = xpcInpB( (unsigned short)(1016 + IER) ) & 0xff;
                  xpcOutpB( (unsigned short)(1016 + IER), (uint8_T)(ier &
                            ~IERXMT) );
                } else if (xpcInpB( (unsigned short)(1016 + LSR) ) & LSRTHRE ) {
                  int i;

                  // Copy all the data from the input vector to the HW fifo.
                  // The fifo read block MUST have the correct max read value
                  // for the fifo mode.
                  for (i = 0 ; i < IPtr[0] ; i++ ) {
                    xpcOutpB( (ushort_T)(1016 + DATA), (uint8_T)(IPtr[i+1] &
                              0xff) );
                  }
                } else {
                  rtmSetErrorStatus(GUI_User_V1_3_rtM,
                                    "Attempted write to hardware fifo that isn't empty");
                  return;
                }
              }
            }

            GUI_User_V1_3_DWork.Transmit1_SubsysRanBC = 4;
            break;
          }
          break;

         case 0:
          // Modem status change
          break;
        }

        // Read IIR again to see if we're done with this UART
        iir = xpcInpB( (unsigned short)(base[port] + IIR) ) & IIRREASON;
      }
    }
  }

  GUI_User_V1_3_DWork.RS232ISR_SubsysRanBC = 4;
}

/*
 * Output and update for action system:
 *    '<S5>/If Action Subsystem'
 *    '<S5>/If Action Subsystem2'
 *    '<S5>/If Action Subsystem4'
 *    '<S5>/If Action Subsystem6'
 *    '<S5>/If Action Subsystem8'
 *    '<S5>/If Action Subsystem10'
 */
void GUI_User_V1_3_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1,
  rtB_IfActionSubsystem_GUI_User_ *localB, rtP_IfActionSubsystem_GUI_User_
  *localP)
{
  /* Sum: '<S25>/Sum' incorporates:
   *  Constant: '<S25>/Constant8'
   */
  localB->Sum = rtu_In1 + localP->Constant8_Value;

  /* Rounding: '<S25>/Rounding Function' */
  (*rty_Out1) = ceil(localB->Sum);
}

/*
 * Output and update for action system:
 *    '<S5>/If Action Subsystem1'
 *    '<S5>/If Action Subsystem3'
 *    '<S5>/If Action Subsystem5'
 *    '<S5>/If Action Subsystem7'
 *    '<S5>/If Action Subsystem9'
 *    '<S5>/If Action Subsystem11'
 */
void GUI_User_V1__IfActionSubsystem1(real_T rtu_In1, real_T *rty_Out1,
  rtB_IfActionSubsystem1_GUI_User *localB, rtP_IfActionSubsystem1_GUI_User
  *localP)
{
  /* Gain: '<S26>/Gain' */
  localB->Gain = localP->Gain_Gain * rtu_In1;

  /* Sum: '<S26>/Sum' incorporates:
   *  Constant: '<S26>/Constant8'
   */
  localB->Sum = localB->Gain + localP->Constant8_Value;

  /* Rounding: '<S26>/Rounding Function' */
  (*rty_Out1) = ceil(localB->Sum);
}

/* Model output function */
void GUI_User_V1_3_output(int_T tid)
{
  int8_T rtAction;
  real_T u;
  real_T u_0;
  real_T u_1;

  /* RTWBLOCK_START_COMMENT */
  /* RTWBLOCK_START_COMMENT */
  /* RTWBLOCK_START_COMMENT */
  /* RTWBLOCK_START_COMMENT */
  /* RTWBLOCK_START_COMMENT */
  /* Reset subsysRan breadcrumbs */
  srClearBC(GUI_User_V1_3_DWork.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GUI_User_V1_3_DWork.IfActionSubsystem5_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GUI_User_V1_3_DWork.IfActionSubsystem6_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GUI_User_V1_3_DWork.IfActionSubsystem2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (GUI_User_V1_3_DWork.IfActionSubsystem_h.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (GUI_User_V1_3_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);

  /* RTWBLOCK_START_COMMENT */

  /* Level2 S-Function Block: '<S6>/MM-16-AT Analog Input' (addiamondmm16atcustom) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[5];
    sfcnOutputs(rts, 0);
  }

  /* DiscreteStateSpace: '<S42>/Discrete State-Space5' */
  {
    GUI_User_V1_3_B.DiscreteStateSpace5 =
      (GUI_User_V1_3_P.DiscreteStateSpace5_C[0])*
      GUI_User_V1_3_DWork.DiscreteStateSpace5_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace5_C[1])*
      GUI_User_V1_3_DWork.DiscreteStateSpace5_DSTATE[1];
    GUI_User_V1_3_B.DiscreteStateSpace5 += GUI_User_V1_3_P.DiscreteStateSpace5_D*
      GUI_User_V1_3_B.MM16ATAnalogInput_o11;
  }

  /* Gain: '<S42>/Gain11' */
  GUI_User_V1_3_B.Gain11 = GUI_User_V1_3_P.Gain11_Gain *
    GUI_User_V1_3_B.DiscreteStateSpace5;

  /* Sum: '<S42>/Sum6' incorporates:
   *  Constant: '<S42>/Constant6'
   */
  GUI_User_V1_3_B.Sum6 = GUI_User_V1_3_B.Gain11 +
    GUI_User_V1_3_P.Constant6_Value;

  /* DiscreteStateSpace: '<S42>/Discrete State-Space4' */
  {
    GUI_User_V1_3_B.DiscreteStateSpace4 =
      (GUI_User_V1_3_P.DiscreteStateSpace4_C[0])*
      GUI_User_V1_3_DWork.DiscreteStateSpace4_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace4_C[1])*
      GUI_User_V1_3_DWork.DiscreteStateSpace4_DSTATE[1];
    GUI_User_V1_3_B.DiscreteStateSpace4 += GUI_User_V1_3_P.DiscreteStateSpace4_D*
      GUI_User_V1_3_B.MM16ATAnalogInput_o9;
  }

  /* Gain: '<S42>/Gain10' */
  GUI_User_V1_3_B.Gain10 = GUI_User_V1_3_P.Gain10_Gain *
    GUI_User_V1_3_B.DiscreteStateSpace4;

  /* Sum: '<S42>/Sum5' incorporates:
   *  Constant: '<S42>/Constant5'
   */
  GUI_User_V1_3_B.Sum5 = GUI_User_V1_3_B.Gain10 +
    GUI_User_V1_3_P.Constant5_Value_p;

  /* DiscreteStateSpace: '<S42>/Discrete State-Space3' */
  {
    GUI_User_V1_3_B.DiscreteStateSpace3 =
      (GUI_User_V1_3_P.DiscreteStateSpace3_C[0])*
      GUI_User_V1_3_DWork.DiscreteStateSpace3_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace3_C[1])*
      GUI_User_V1_3_DWork.DiscreteStateSpace3_DSTATE[1];
    GUI_User_V1_3_B.DiscreteStateSpace3 += GUI_User_V1_3_P.DiscreteStateSpace3_D*
      GUI_User_V1_3_B.MM16ATAnalogInput_o7;
  }

  /* Gain: '<S42>/Gain9' */
  GUI_User_V1_3_B.Gain9 = GUI_User_V1_3_P.Gain9_Gain *
    GUI_User_V1_3_B.DiscreteStateSpace3;

  /* Sum: '<S42>/Sum4' incorporates:
   *  Constant: '<S42>/Constant4'
   */
  GUI_User_V1_3_B.Sum4 = GUI_User_V1_3_B.Gain9 +
    GUI_User_V1_3_P.Constant4_Value_p;

  /* DiscreteStateSpace: '<S42>/Discrete State-Space2' */
  {
    GUI_User_V1_3_B.DiscreteStateSpace2 =
      (GUI_User_V1_3_P.DiscreteStateSpace2_C[0])*
      GUI_User_V1_3_DWork.DiscreteStateSpace2_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace2_C[1])*
      GUI_User_V1_3_DWork.DiscreteStateSpace2_DSTATE[1];
    GUI_User_V1_3_B.DiscreteStateSpace2 += GUI_User_V1_3_P.DiscreteStateSpace2_D*
      GUI_User_V1_3_B.MM16ATAnalogInput_o5;
  }

  /* Gain: '<S42>/Gain8' */
  GUI_User_V1_3_B.Gain8 = GUI_User_V1_3_P.Gain8_Gain_e *
    GUI_User_V1_3_B.DiscreteStateSpace2;

  /* Sum: '<S42>/Sum3' incorporates:
   *  Constant: '<S42>/Constant3'
   */
  GUI_User_V1_3_B.Sum3 = GUI_User_V1_3_B.Gain8 +
    GUI_User_V1_3_P.Constant3_Value_c;

  /* DiscreteStateSpace: '<S42>/Discrete State-Space1' */
  {
    GUI_User_V1_3_B.DiscreteStateSpace1 =
      (GUI_User_V1_3_P.DiscreteStateSpace1_C[0])*
      GUI_User_V1_3_DWork.DiscreteStateSpace1_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace1_C[1])*
      GUI_User_V1_3_DWork.DiscreteStateSpace1_DSTATE[1];
    GUI_User_V1_3_B.DiscreteStateSpace1 += GUI_User_V1_3_P.DiscreteStateSpace1_D*
      GUI_User_V1_3_B.MM16ATAnalogInput_o3;
  }

  /* Gain: '<S42>/Gain1' */
  GUI_User_V1_3_B.Gain1 = GUI_User_V1_3_P.Gain1_Gain_g *
    GUI_User_V1_3_B.DiscreteStateSpace1;

  /* Sum: '<S42>/Sum2' incorporates:
   *  Constant: '<S42>/Constant1'
   */
  GUI_User_V1_3_B.Sum2 = GUI_User_V1_3_B.Gain1 +
    GUI_User_V1_3_P.Constant1_Value_n;

  /* DiscreteStateSpace: '<S42>/Discrete State-Space6' */
  {
    GUI_User_V1_3_B.DiscreteStateSpace6 =
      (GUI_User_V1_3_P.DiscreteStateSpace6_C[0])*
      GUI_User_V1_3_DWork.DiscreteStateSpace6_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace6_C[1])*
      GUI_User_V1_3_DWork.DiscreteStateSpace6_DSTATE[1];
    GUI_User_V1_3_B.DiscreteStateSpace6 += GUI_User_V1_3_P.DiscreteStateSpace6_D*
      GUI_User_V1_3_B.MM16ATAnalogInput_o1;
  }

  /* Gain: '<S42>/Gain' */
  GUI_User_V1_3_B.Gain = GUI_User_V1_3_P.Gain_Gain *
    GUI_User_V1_3_B.DiscreteStateSpace6;

  /* Sum: '<S42>/Sum1' incorporates:
   *  Constant: '<S42>/Constant2'
   */
  GUI_User_V1_3_B.Sum1 = GUI_User_V1_3_B.Gain +
    GUI_User_V1_3_P.Constant2_Value_f;

  /* If: '<Root>/If' incorporates:
   *  Constant: '<Root>/ControlConstant'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  if (GUI_User_V1_3_P.ControlConstant_Value == 0.0) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    GUI_User_V1_3_B.Merge[0] = GUI_User_V1_3_P.Constant_Value;
    GUI_User_V1_3_B.Merge[1] = GUI_User_V1_3_P.Constant1_Value;
    GUI_User_V1_3_B.Merge[2] = GUI_User_V1_3_P.Constant2_Value;
    GUI_User_V1_3_B.Merge[3] = GUI_User_V1_3_P.Constant3_Value;
    GUI_User_V1_3_B.Merge[4] = GUI_User_V1_3_P.Constant4_Value;
    GUI_User_V1_3_B.Merge[5] = GUI_User_V1_3_P.Constant5_Value;
    srUpdateBC(GUI_User_V1_3_DWork.IfActionSubsystem_SubsysRanBC);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
  } else if (GUI_User_V1_3_P.ControlConstant_Value == 1.0) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Gain: '<S8>/FeeedForward Gain5' incorporates:
     *  Constant: '<S8>/Constant1'
     */
    GUI_User_V1_3_B.FeeedForwardGain5_n = GUI_User_V1_3_P.FeeedForwardGain5_Gain
      * GUI_User_V1_3_P.Constant1_Value_p;

    /* Gain: '<S8>/FeeedForward Gain6' incorporates:
     *  Constant: '<S8>/Constant8'
     */
    GUI_User_V1_3_B.FeeedForwardGain6_h = GUI_User_V1_3_P.FeeedForwardGain6_Gain
      * GUI_User_V1_3_P.Constant8_Value;

    /* Sum: '<S8>/Sum9' */
    GUI_User_V1_3_B.Sum9_lk = GUI_User_V1_3_B.FeeedForwardGain5_n +
      GUI_User_V1_3_B.FeeedForwardGain6_h;

    /* Gain: '<S8>/Gain7' */
    GUI_User_V1_3_B.Gain7_e = GUI_User_V1_3_P.Gain7_Gain *
      GUI_User_V1_3_B.Sum9_lk;

    /* Sum: '<S8>/Sum7' incorporates:
     *  Constant: '<S8>/Posi1Free'
     */
    GUI_User_V1_3_B.Sum7_m = GUI_User_V1_3_P.Posi1Free_Value -
      GUI_User_V1_3_B.Sum1;

    /* Gain: '<S11>/Proportional Gain' */
    GUI_User_V1_3_B.ProportionalGain_d = GUI_User_V1_3_P.ProportionalGain_Gain *
      GUI_User_V1_3_B.Sum7_m;

    /* DiscreteIntegrator: '<S11>/Integrator' */
    GUI_User_V1_3_B.Integrator_l = GUI_User_V1_3_DWork.Integrator_DSTATE_cb;

    /* Gain: '<S11>/Derivative Gain' */
    GUI_User_V1_3_B.DerivativeGain_k = GUI_User_V1_3_P.DerivativeGain_Gain *
      GUI_User_V1_3_B.Sum7_m;

    /* DiscreteIntegrator: '<S11>/Filter' */
    GUI_User_V1_3_B.Filter_p = GUI_User_V1_3_DWork.Filter_DSTATE_f;

    /* Sum: '<S11>/SumD' */
    GUI_User_V1_3_B.SumD_k = GUI_User_V1_3_B.DerivativeGain_k -
      GUI_User_V1_3_B.Filter_p;

    /* Gain: '<S11>/Filter Coefficient' */
    GUI_User_V1_3_B.FilterCoefficient_i = GUI_User_V1_3_P.FilterCoefficient_Gain
      * GUI_User_V1_3_B.SumD_k;

    /* Sum: '<S11>/Sum' */
    GUI_User_V1_3_B.Sum_fe = (GUI_User_V1_3_B.ProportionalGain_d +
      GUI_User_V1_3_B.Integrator_l) + GUI_User_V1_3_B.FilterCoefficient_i;

    /* Gain: '<S8>/Gain8' */
    GUI_User_V1_3_B.Gain8_ff = GUI_User_V1_3_P.Gain8_Gain *
      GUI_User_V1_3_B.Sum_fe;

    /* Gain: '<S11>/Integral Gain' */
    GUI_User_V1_3_B.IntegralGain_c = GUI_User_V1_3_P.IntegralGain_Gain *
      GUI_User_V1_3_B.Sum7_m;

    /* Sum: '<S8>/Sum8' */
    GUI_User_V1_3_B.Sum8_h = GUI_User_V1_3_B.Gain7_e + GUI_User_V1_3_B.Gain8_ff;

    /* Saturate: '<S8>/Saturation1' */
    u = GUI_User_V1_3_B.Sum8_h;
    u_0 = GUI_User_V1_3_P.Saturation1_LowerSat;
    u_1 = GUI_User_V1_3_P.Saturation1_UpperSat;
    u = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;
    GUI_User_V1_3_B.Merge[0] = u;

    /* Gain: '<S8>/FeeedForward Gain3' incorporates:
     *  Constant: '<S8>/Constant9'
     */
    GUI_User_V1_3_B.FeeedForwardGain3_m = GUI_User_V1_3_P.FeeedForwardGain3_Gain
      * GUI_User_V1_3_P.Constant9_Value;

    /* Gain: '<S8>/FeeedForward Gain4' incorporates:
     *  Constant: '<S8>/Constant10'
     */
    GUI_User_V1_3_B.FeeedForwardGain4_d = GUI_User_V1_3_P.FeeedForwardGain4_Gain
      * GUI_User_V1_3_P.Constant10_Value;

    /* Sum: '<S8>/Sum6' */
    GUI_User_V1_3_B.Sum6_o = GUI_User_V1_3_B.FeeedForwardGain3_m +
      GUI_User_V1_3_B.FeeedForwardGain4_d;

    /* Sum: '<S8>/Sum3' incorporates:
     *  Constant: '<S8>/Posi2Free'
     */
    GUI_User_V1_3_B.Sum3_oz = GUI_User_V1_3_P.Posi2Free_Value -
      GUI_User_V1_3_B.Sum2;

    /* Gain: '<S9>/Proportional Gain' */
    GUI_User_V1_3_B.ProportionalGain_o = GUI_User_V1_3_P.ProportionalGain_Gain_f
      * GUI_User_V1_3_B.Sum3_oz;

    /* DiscreteIntegrator: '<S9>/Integrator' */
    GUI_User_V1_3_B.Integrator_iz = GUI_User_V1_3_DWork.Integrator_DSTATE_j;

    /* Gain: '<S9>/Derivative Gain' */
    GUI_User_V1_3_B.DerivativeGain_l = GUI_User_V1_3_P.DerivativeGain_Gain_a *
      GUI_User_V1_3_B.Sum3_oz;

    /* DiscreteIntegrator: '<S9>/Filter' */
    GUI_User_V1_3_B.Filter_h = GUI_User_V1_3_DWork.Filter_DSTATE_o;

    /* Sum: '<S9>/SumD' */
    GUI_User_V1_3_B.SumD_o = GUI_User_V1_3_B.DerivativeGain_l -
      GUI_User_V1_3_B.Filter_h;

    /* Gain: '<S9>/Filter Coefficient' */
    GUI_User_V1_3_B.FilterCoefficient_jw =
      GUI_User_V1_3_P.FilterCoefficient_Gain_i * GUI_User_V1_3_B.SumD_o;

    /* Sum: '<S9>/Sum' */
    GUI_User_V1_3_B.Sum_m = (GUI_User_V1_3_B.ProportionalGain_o +
      GUI_User_V1_3_B.Integrator_iz) + GUI_User_V1_3_B.FilterCoefficient_jw;

    /* Sum: '<S8>/Sum5' */
    GUI_User_V1_3_B.Sum5_h2 = GUI_User_V1_3_B.Sum6_o + GUI_User_V1_3_B.Sum_m;

    /* Gain: '<S8>/Gain1' */
    GUI_User_V1_3_B.Gain1_e = GUI_User_V1_3_P.Gain1_Gain *
      GUI_User_V1_3_B.Sum5_h2;

    /* Gain: '<S9>/Integral Gain' */
    GUI_User_V1_3_B.IntegralGain_o = GUI_User_V1_3_P.IntegralGain_Gain_c *
      GUI_User_V1_3_B.Sum3_oz;

    /* Saturate: '<S8>/Saturation2' */
    u = GUI_User_V1_3_B.Gain1_e;
    u_0 = GUI_User_V1_3_P.Saturation2_LowerSat;
    u_1 = GUI_User_V1_3_P.Saturation2_UpperSat;
    u = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;
    GUI_User_V1_3_B.Merge[1] = u;

    /* Gain: '<S8>/FeeedForward Gain1' incorporates:
     *  Constant: '<S8>/Constant11'
     */
    GUI_User_V1_3_B.FeeedForwardGain1_j = GUI_User_V1_3_P.FeeedForwardGain1_Gain
      * GUI_User_V1_3_P.Constant11_Value;

    /* Gain: '<S8>/FeeedForward Gain2' incorporates:
     *  Constant: '<S8>/Constant12'
     */
    GUI_User_V1_3_B.FeeedForwardGain2_a = GUI_User_V1_3_P.FeeedForwardGain2_Gain
      * GUI_User_V1_3_P.Constant12_Value;

    /* Sum: '<S8>/Sum4' */
    GUI_User_V1_3_B.Sum4_cm = GUI_User_V1_3_B.FeeedForwardGain1_j +
      GUI_User_V1_3_B.FeeedForwardGain2_a;

    /* Sum: '<S8>/Sum1' incorporates:
     *  Constant: '<S8>/Posi3Free'
     */
    GUI_User_V1_3_B.Sum1_n = GUI_User_V1_3_P.Posi3Free_Value -
      GUI_User_V1_3_B.Sum3;

    /* Gain: '<S10>/Proportional Gain' */
    GUI_User_V1_3_B.ProportionalGain_ku =
      GUI_User_V1_3_P.ProportionalGain_Gain_h * GUI_User_V1_3_B.Sum1_n;

    /* DiscreteIntegrator: '<S10>/Integrator' */
    GUI_User_V1_3_B.Integrator_h = GUI_User_V1_3_DWork.Integrator_DSTATE_d;

    /* Gain: '<S10>/Derivative Gain' */
    GUI_User_V1_3_B.DerivativeGain_kl = GUI_User_V1_3_P.DerivativeGain_Gain_ax *
      GUI_User_V1_3_B.Sum1_n;

    /* DiscreteIntegrator: '<S10>/Filter' */
    GUI_User_V1_3_B.Filter_f = GUI_User_V1_3_DWork.Filter_DSTATE_mn;

    /* Sum: '<S10>/SumD' */
    GUI_User_V1_3_B.SumD_fx = GUI_User_V1_3_B.DerivativeGain_kl -
      GUI_User_V1_3_B.Filter_f;

    /* Gain: '<S10>/Filter Coefficient' */
    GUI_User_V1_3_B.FilterCoefficient_a =
      GUI_User_V1_3_P.FilterCoefficient_Gain_d * GUI_User_V1_3_B.SumD_fx;

    /* Sum: '<S10>/Sum' */
    GUI_User_V1_3_B.Sum_n = (GUI_User_V1_3_B.ProportionalGain_ku +
      GUI_User_V1_3_B.Integrator_h) + GUI_User_V1_3_B.FilterCoefficient_a;

    /* Sum: '<S8>/Sum2' */
    GUI_User_V1_3_B.Sum2_f = GUI_User_V1_3_B.Sum4_cm + GUI_User_V1_3_B.Sum_n;

    /* Gain: '<S8>/Gain3' */
    GUI_User_V1_3_B.Gain3_m = GUI_User_V1_3_P.Gain3_Gain *
      GUI_User_V1_3_B.Sum2_f;

    /* Gain: '<S10>/Integral Gain' */
    GUI_User_V1_3_B.IntegralGain_ko = GUI_User_V1_3_P.IntegralGain_Gain_m *
      GUI_User_V1_3_B.Sum1_n;

    /* Saturate: '<S8>/Saturation3' */
    u = GUI_User_V1_3_B.Gain3_m;
    u_0 = GUI_User_V1_3_P.Saturation3_LowerSat;
    u_1 = GUI_User_V1_3_P.Saturation3_UpperSat;
    u = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;
    GUI_User_V1_3_B.Merge[2] = u;

    /* Gain: '<S8>/FeeedForward Gain7' incorporates:
     *  Constant: '<S8>/Constant13'
     */
    GUI_User_V1_3_B.FeeedForwardGain7_n = GUI_User_V1_3_P.FeeedForwardGain7_Gain
      * GUI_User_V1_3_P.Constant13_Value;

    /* Gain: '<S8>/FeeedForward Gain8' incorporates:
     *  Constant: '<S8>/Constant14'
     */
    GUI_User_V1_3_B.FeeedForwardGain8_d = GUI_User_V1_3_P.FeeedForwardGain8_Gain
      * GUI_User_V1_3_P.Constant14_Value;

    /* Sum: '<S8>/Sum12' */
    GUI_User_V1_3_B.Sum12_j = GUI_User_V1_3_B.FeeedForwardGain7_n +
      GUI_User_V1_3_B.FeeedForwardGain8_d;

    /* Sum: '<S8>/Sum10' incorporates:
     *  Constant: '<S8>/Posi4Free'
     */
    GUI_User_V1_3_B.Sum10_i = GUI_User_V1_3_P.Posi4Free_Value -
      GUI_User_V1_3_B.Sum4;

    /* Gain: '<S12>/Proportional Gain' */
    GUI_User_V1_3_B.ProportionalGain_mk =
      GUI_User_V1_3_P.ProportionalGain_Gain_c * GUI_User_V1_3_B.Sum10_i;

    /* DiscreteIntegrator: '<S12>/Integrator' */
    GUI_User_V1_3_B.Integrator_d = GUI_User_V1_3_DWork.Integrator_DSTATE_k;

    /* Gain: '<S12>/Derivative Gain' */
    GUI_User_V1_3_B.DerivativeGain_e = GUI_User_V1_3_P.DerivativeGain_Gain_c *
      GUI_User_V1_3_B.Sum10_i;

    /* DiscreteIntegrator: '<S12>/Filter' */
    GUI_User_V1_3_B.Filter_fz = GUI_User_V1_3_DWork.Filter_DSTATE_mv;

    /* Sum: '<S12>/SumD' */
    GUI_User_V1_3_B.SumD_d = GUI_User_V1_3_B.DerivativeGain_e -
      GUI_User_V1_3_B.Filter_fz;

    /* Gain: '<S12>/Filter Coefficient' */
    GUI_User_V1_3_B.FilterCoefficient_f =
      GUI_User_V1_3_P.FilterCoefficient_Gain_l * GUI_User_V1_3_B.SumD_d;

    /* Sum: '<S12>/Sum' */
    GUI_User_V1_3_B.Sum_pc = (GUI_User_V1_3_B.ProportionalGain_mk +
      GUI_User_V1_3_B.Integrator_d) + GUI_User_V1_3_B.FilterCoefficient_f;

    /* Sum: '<S8>/Sum11' */
    GUI_User_V1_3_B.Sum11_i = GUI_User_V1_3_B.Sum12_j + GUI_User_V1_3_B.Sum_pc;

    /* Gain: '<S8>/Gain4' */
    GUI_User_V1_3_B.Gain4_h = GUI_User_V1_3_P.Gain4_Gain *
      GUI_User_V1_3_B.Sum11_i;

    /* Gain: '<S12>/Integral Gain' */
    GUI_User_V1_3_B.IntegralGain_g = GUI_User_V1_3_P.IntegralGain_Gain_l *
      GUI_User_V1_3_B.Sum10_i;

    /* Saturate: '<S8>/Saturation' */
    u = GUI_User_V1_3_B.Gain4_h;
    u_0 = GUI_User_V1_3_P.Saturation_LowerSat;
    u_1 = GUI_User_V1_3_P.Saturation_UpperSat;
    u = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;
    GUI_User_V1_3_B.Merge[3] = u;

    /* Gain: '<S8>/FeeedForward Gain10' incorporates:
     *  Constant: '<S8>/Constant16'
     */
    GUI_User_V1_3_B.FeeedForwardGain10_l0 =
      GUI_User_V1_3_P.FeeedForwardGain10_Gain * GUI_User_V1_3_P.Constant16_Value;

    /* Gain: '<S8>/FeeedForward Gain9' incorporates:
     *  Constant: '<S8>/Constant15'
     */
    GUI_User_V1_3_B.FeeedForwardGain9_a = GUI_User_V1_3_P.FeeedForwardGain9_Gain
      * GUI_User_V1_3_P.Constant15_Value;

    /* Sum: '<S8>/Sum15' */
    GUI_User_V1_3_B.Sum15_p = GUI_User_V1_3_B.FeeedForwardGain9_a +
      GUI_User_V1_3_B.FeeedForwardGain10_l0;

    /* Sum: '<S8>/Sum13' incorporates:
     *  Constant: '<S8>/Posi5Free'
     */
    GUI_User_V1_3_B.Sum13_g = GUI_User_V1_3_P.Posi5Free_Value -
      GUI_User_V1_3_B.Sum5;

    /* Gain: '<S13>/Proportional Gain' */
    GUI_User_V1_3_B.ProportionalGain_mo =
      GUI_User_V1_3_P.ProportionalGain_Gain_n * GUI_User_V1_3_B.Sum13_g;

    /* DiscreteIntegrator: '<S13>/Integrator' */
    GUI_User_V1_3_B.Integrator_pa = GUI_User_V1_3_DWork.Integrator_DSTATE_mj;

    /* Gain: '<S13>/Derivative Gain' */
    GUI_User_V1_3_B.DerivativeGain_klw = GUI_User_V1_3_P.DerivativeGain_Gain_e *
      GUI_User_V1_3_B.Sum13_g;

    /* DiscreteIntegrator: '<S13>/Filter' */
    GUI_User_V1_3_B.Filter_io = GUI_User_V1_3_DWork.Filter_DSTATE_kq;

    /* Sum: '<S13>/SumD' */
    GUI_User_V1_3_B.SumD_m3 = GUI_User_V1_3_B.DerivativeGain_klw -
      GUI_User_V1_3_B.Filter_io;

    /* Gain: '<S13>/Filter Coefficient' */
    GUI_User_V1_3_B.FilterCoefficient_hs =
      GUI_User_V1_3_P.FilterCoefficient_Gain_o * GUI_User_V1_3_B.SumD_m3;

    /* Sum: '<S13>/Sum' */
    GUI_User_V1_3_B.Sum_j = (GUI_User_V1_3_B.ProportionalGain_mo +
      GUI_User_V1_3_B.Integrator_pa) + GUI_User_V1_3_B.FilterCoefficient_hs;

    /* Sum: '<S8>/Sum14' */
    GUI_User_V1_3_B.Sum14_k = GUI_User_V1_3_B.Sum15_p + GUI_User_V1_3_B.Sum_j;

    /* Gain: '<S8>/Gain5' */
    GUI_User_V1_3_B.Gain5_f = GUI_User_V1_3_P.Gain5_Gain *
      GUI_User_V1_3_B.Sum14_k;

    /* Gain: '<S13>/Integral Gain' */
    GUI_User_V1_3_B.IntegralGain_h = GUI_User_V1_3_P.IntegralGain_Gain_i *
      GUI_User_V1_3_B.Sum13_g;

    /* Saturate: '<S8>/Saturation4' */
    u = GUI_User_V1_3_B.Gain5_f;
    u_0 = GUI_User_V1_3_P.Saturation4_LowerSat;
    u_1 = GUI_User_V1_3_P.Saturation4_UpperSat;
    u = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;
    GUI_User_V1_3_B.Merge[4] = u;

    /* Gain: '<S8>/FeeedForward Gain11' incorporates:
     *  Constant: '<S8>/Constant18'
     */
    GUI_User_V1_3_B.FeeedForwardGain11_b =
      GUI_User_V1_3_P.FeeedForwardGain11_Gain * GUI_User_V1_3_P.Constant18_Value;

    /* Gain: '<S8>/FeeedForward Gain12' incorporates:
     *  Constant: '<S8>/Constant17'
     */
    GUI_User_V1_3_B.FeeedForwardGain12_j =
      GUI_User_V1_3_P.FeeedForwardGain12_Gain * GUI_User_V1_3_P.Constant17_Value;

    /* Sum: '<S8>/Sum18' */
    GUI_User_V1_3_B.Sum18_j = GUI_User_V1_3_B.FeeedForwardGain12_j +
      GUI_User_V1_3_B.FeeedForwardGain11_b;

    /* Sum: '<S8>/Sum16' incorporates:
     *  Constant: '<S8>/Posi6Free'
     */
    GUI_User_V1_3_B.Sum16_l = GUI_User_V1_3_P.Posi6Free_Value -
      GUI_User_V1_3_B.Sum6;

    /* Gain: '<S14>/Proportional Gain' */
    GUI_User_V1_3_B.ProportionalGain_mm =
      GUI_User_V1_3_P.ProportionalGain_Gain_e * GUI_User_V1_3_B.Sum16_l;

    /* DiscreteIntegrator: '<S14>/Integrator' */
    GUI_User_V1_3_B.Integrator_ir = GUI_User_V1_3_DWork.Integrator_DSTATE_i;

    /* Gain: '<S14>/Derivative Gain' */
    GUI_User_V1_3_B.DerivativeGain_eo = GUI_User_V1_3_P.DerivativeGain_Gain_k *
      GUI_User_V1_3_B.Sum16_l;

    /* DiscreteIntegrator: '<S14>/Filter' */
    GUI_User_V1_3_B.Filter_d = GUI_User_V1_3_DWork.Filter_DSTATE_me;

    /* Sum: '<S14>/SumD' */
    GUI_User_V1_3_B.SumD_g = GUI_User_V1_3_B.DerivativeGain_eo -
      GUI_User_V1_3_B.Filter_d;

    /* Gain: '<S14>/Filter Coefficient' */
    GUI_User_V1_3_B.FilterCoefficient_b =
      GUI_User_V1_3_P.FilterCoefficient_Gain_b * GUI_User_V1_3_B.SumD_g;

    /* Sum: '<S14>/Sum' */
    GUI_User_V1_3_B.Sum_iv = (GUI_User_V1_3_B.ProportionalGain_mm +
      GUI_User_V1_3_B.Integrator_ir) + GUI_User_V1_3_B.FilterCoefficient_b;

    /* Sum: '<S8>/Sum17' */
    GUI_User_V1_3_B.Sum17_k = GUI_User_V1_3_B.Sum18_j + GUI_User_V1_3_B.Sum_iv;

    /* Gain: '<S8>/Gain6' */
    GUI_User_V1_3_B.Gain6_f = GUI_User_V1_3_P.Gain6_Gain *
      GUI_User_V1_3_B.Sum17_k;

    /* Gain: '<S14>/Integral Gain' */
    GUI_User_V1_3_B.IntegralGain_m = GUI_User_V1_3_P.IntegralGain_Gain_j *
      GUI_User_V1_3_B.Sum16_l;

    /* Saturate: '<S8>/Saturation5' */
    u = GUI_User_V1_3_B.Gain6_f;
    u_0 = GUI_User_V1_3_P.Saturation5_LowerSat;
    u_1 = GUI_User_V1_3_P.Saturation5_UpperSat;
    u = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;
    GUI_User_V1_3_B.Merge[5] = u;
    srUpdateBC(GUI_User_V1_3_DWork.IfActionSubsystem5_SubsysRanBC);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem5' */
  } else if (GUI_User_V1_3_P.ControlConstant_Value == 2.0) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */

    /* Level2 S-Function Block: '<S17>/From File1' (xpcfromfile) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[0];
      sfcnOutputs(rts, 0);
    }

    /* Unpack: <S17>/Unpack1 */
    (void) memcpy(GUI_User_V1_3_B.Unpack1, GUI_User_V1_3_B.FromFile1,
                  144);

    /* Gain: '<S15>/FeeedForward Gain1' */
    GUI_User_V1_3_B.FeeedForwardGain1 = GUI_User_V1_3_P.FeeedForwardGain1_Gain_p
      * GUI_User_V1_3_B.Unpack1[8];

    /* Gain: '<S15>/FeeedForward Gain10' */
    GUI_User_V1_3_B.FeeedForwardGain10 =
      GUI_User_V1_3_P.FeeedForwardGain10_Gain_k * GUI_User_V1_3_B.Unpack1[16];

    /* Gain: '<S15>/FeeedForward Gain11' */
    GUI_User_V1_3_B.FeeedForwardGain11 =
      GUI_User_V1_3_P.FeeedForwardGain11_Gain_k * GUI_User_V1_3_B.Unpack1[17];

    /* Gain: '<S15>/FeeedForward Gain12' */
    GUI_User_V1_3_B.FeeedForwardGain12 =
      GUI_User_V1_3_P.FeeedForwardGain12_Gain_j * GUI_User_V1_3_B.Unpack1[11];

    /* Gain: '<S15>/FeeedForward Gain2' */
    GUI_User_V1_3_B.FeeedForwardGain2 = GUI_User_V1_3_P.FeeedForwardGain2_Gain_f
      * GUI_User_V1_3_B.Unpack1[14];

    /* Gain: '<S15>/FeeedForward Gain3' */
    GUI_User_V1_3_B.FeeedForwardGain3 = GUI_User_V1_3_P.FeeedForwardGain3_Gain_d
      * GUI_User_V1_3_B.Unpack1[7];

    /* Gain: '<S15>/FeeedForward Gain4' */
    GUI_User_V1_3_B.FeeedForwardGain4 = GUI_User_V1_3_P.FeeedForwardGain4_Gain_e
      * GUI_User_V1_3_B.Unpack1[13];

    /* Gain: '<S15>/FeeedForward Gain5' */
    GUI_User_V1_3_B.FeeedForwardGain5 = GUI_User_V1_3_P.FeeedForwardGain5_Gain_f
      * GUI_User_V1_3_B.Unpack1[6];

    /* Gain: '<S15>/FeeedForward Gain6' */
    GUI_User_V1_3_B.FeeedForwardGain6 = GUI_User_V1_3_P.FeeedForwardGain6_Gain_k
      * GUI_User_V1_3_B.Unpack1[12];

    /* Gain: '<S15>/FeeedForward Gain7' */
    GUI_User_V1_3_B.FeeedForwardGain7 = GUI_User_V1_3_P.FeeedForwardGain7_Gain_n
      * GUI_User_V1_3_B.Unpack1[9];

    /* Gain: '<S15>/FeeedForward Gain8' */
    GUI_User_V1_3_B.FeeedForwardGain8 = GUI_User_V1_3_P.FeeedForwardGain8_Gain_f
      * GUI_User_V1_3_B.Unpack1[15];

    /* Gain: '<S15>/FeeedForward Gain9' */
    GUI_User_V1_3_B.FeeedForwardGain9 = GUI_User_V1_3_P.FeeedForwardGain9_Gain_c
      * GUI_User_V1_3_B.Unpack1[10];

    /* Sum: '<S15>/Sum6' */
    GUI_User_V1_3_B.Sum6_c = GUI_User_V1_3_B.FeeedForwardGain3 +
      GUI_User_V1_3_B.FeeedForwardGain4;

    /* Sum: '<S15>/Sum3' */
    GUI_User_V1_3_B.Sum3_o = GUI_User_V1_3_B.Unpack1[1] - GUI_User_V1_3_B.Sum2;

    /* Gain: '<S18>/Proportional Gain' */
    GUI_User_V1_3_B.ProportionalGain = GUI_User_V1_3_P.ProportionalGain_Gain_d *
      GUI_User_V1_3_B.Sum3_o;

    /* DiscreteIntegrator: '<S18>/Integrator' */
    GUI_User_V1_3_B.Integrator = GUI_User_V1_3_DWork.Integrator_DSTATE;

    /* Gain: '<S18>/Derivative Gain' */
    GUI_User_V1_3_B.DerivativeGain = GUI_User_V1_3_P.DerivativeGain_Gain_g *
      GUI_User_V1_3_B.Sum3_o;

    /* DiscreteIntegrator: '<S18>/Filter' */
    GUI_User_V1_3_B.Filter = GUI_User_V1_3_DWork.Filter_DSTATE;

    /* Sum: '<S18>/SumD' */
    GUI_User_V1_3_B.SumD = GUI_User_V1_3_B.DerivativeGain -
      GUI_User_V1_3_B.Filter;

    /* Gain: '<S18>/Filter Coefficient' */
    GUI_User_V1_3_B.FilterCoefficient =
      GUI_User_V1_3_P.FilterCoefficient_Gain_bu * GUI_User_V1_3_B.SumD;

    /* Sum: '<S18>/Sum' */
    GUI_User_V1_3_B.Sum = (GUI_User_V1_3_B.ProportionalGain +
      GUI_User_V1_3_B.Integrator) + GUI_User_V1_3_B.FilterCoefficient;

    /* Sum: '<S15>/Sum5' */
    GUI_User_V1_3_B.Sum5_h = GUI_User_V1_3_B.Sum6_c + GUI_User_V1_3_B.Sum;

    /* Gain: '<S15>/Gain1' */
    GUI_User_V1_3_B.Merge[1] = GUI_User_V1_3_P.Gain1_Gain_i *
      GUI_User_V1_3_B.Sum5_h;

    /* Sum: '<S15>/Sum4' */
    GUI_User_V1_3_B.Sum4_o = GUI_User_V1_3_B.FeeedForwardGain1 +
      GUI_User_V1_3_B.FeeedForwardGain2;

    /* Sum: '<S15>/Sum1' */
    GUI_User_V1_3_B.Sum1_k = GUI_User_V1_3_B.Unpack1[2] - GUI_User_V1_3_B.Sum3;

    /* Gain: '<S19>/Proportional Gain' */
    GUI_User_V1_3_B.ProportionalGain_c = GUI_User_V1_3_P.ProportionalGain_Gain_p
      * GUI_User_V1_3_B.Sum1_k;

    /* DiscreteIntegrator: '<S19>/Integrator' */
    GUI_User_V1_3_B.Integrator_i = GUI_User_V1_3_DWork.Integrator_DSTATE_m;

    /* Gain: '<S19>/Derivative Gain' */
    GUI_User_V1_3_B.DerivativeGain_a = GUI_User_V1_3_P.DerivativeGain_Gain_n *
      GUI_User_V1_3_B.Sum1_k;

    /* DiscreteIntegrator: '<S19>/Filter' */
    GUI_User_V1_3_B.Filter_j = GUI_User_V1_3_DWork.Filter_DSTATE_i;

    /* Sum: '<S19>/SumD' */
    GUI_User_V1_3_B.SumD_h = GUI_User_V1_3_B.DerivativeGain_a -
      GUI_User_V1_3_B.Filter_j;

    /* Gain: '<S19>/Filter Coefficient' */
    GUI_User_V1_3_B.FilterCoefficient_n =
      GUI_User_V1_3_P.FilterCoefficient_Gain_g * GUI_User_V1_3_B.SumD_h;

    /* Sum: '<S19>/Sum' */
    GUI_User_V1_3_B.Sum_g = (GUI_User_V1_3_B.ProportionalGain_c +
      GUI_User_V1_3_B.Integrator_i) + GUI_User_V1_3_B.FilterCoefficient_n;

    /* Sum: '<S15>/Sum2' */
    GUI_User_V1_3_B.Sum2_i = GUI_User_V1_3_B.Sum4_o + GUI_User_V1_3_B.Sum_g;

    /* Gain: '<S15>/Gain3' */
    GUI_User_V1_3_B.Merge[2] = GUI_User_V1_3_P.Gain3_Gain_l *
      GUI_User_V1_3_B.Sum2_i;

    /* Sum: '<S15>/Sum12' */
    GUI_User_V1_3_B.Sum12 = GUI_User_V1_3_B.FeeedForwardGain7 +
      GUI_User_V1_3_B.FeeedForwardGain8;

    /* Sum: '<S15>/Sum10' */
    GUI_User_V1_3_B.Sum10 = GUI_User_V1_3_B.Unpack1[3] - GUI_User_V1_3_B.Sum4;

    /* Gain: '<S21>/Proportional Gain' */
    GUI_User_V1_3_B.ProportionalGain_g = GUI_User_V1_3_P.ProportionalGain_Gain_j
      * GUI_User_V1_3_B.Sum10;

    /* DiscreteIntegrator: '<S21>/Integrator' */
    GUI_User_V1_3_B.Integrator_p = GUI_User_V1_3_DWork.Integrator_DSTATE_a;

    /* Gain: '<S21>/Derivative Gain' */
    GUI_User_V1_3_B.DerivativeGain_p = GUI_User_V1_3_P.DerivativeGain_Gain_ny *
      GUI_User_V1_3_B.Sum10;

    /* DiscreteIntegrator: '<S21>/Filter' */
    GUI_User_V1_3_B.Filter_n = GUI_User_V1_3_DWork.Filter_DSTATE_h;

    /* Sum: '<S21>/SumD' */
    GUI_User_V1_3_B.SumD_n = GUI_User_V1_3_B.DerivativeGain_p -
      GUI_User_V1_3_B.Filter_n;

    /* Gain: '<S21>/Filter Coefficient' */
    GUI_User_V1_3_B.FilterCoefficient_j =
      GUI_User_V1_3_P.FilterCoefficient_Gain_j * GUI_User_V1_3_B.SumD_n;

    /* Sum: '<S21>/Sum' */
    GUI_User_V1_3_B.Sum_p = (GUI_User_V1_3_B.ProportionalGain_g +
      GUI_User_V1_3_B.Integrator_p) + GUI_User_V1_3_B.FilterCoefficient_j;

    /* Sum: '<S15>/Sum11' */
    GUI_User_V1_3_B.Sum11 = GUI_User_V1_3_B.Sum12 + GUI_User_V1_3_B.Sum_p;

    /* Gain: '<S15>/Gain4' */
    GUI_User_V1_3_B.Merge[3] = GUI_User_V1_3_P.Gain4_Gain_e *
      GUI_User_V1_3_B.Sum11;

    /* Sum: '<S15>/Sum15' */
    GUI_User_V1_3_B.Sum15 = GUI_User_V1_3_B.FeeedForwardGain9 +
      GUI_User_V1_3_B.FeeedForwardGain10;

    /* Sum: '<S15>/Sum13' */
    GUI_User_V1_3_B.Sum13 = GUI_User_V1_3_B.Unpack1[4] - GUI_User_V1_3_B.Sum5;

    /* Gain: '<S22>/Proportional Gain' */
    GUI_User_V1_3_B.ProportionalGain_m = GUI_User_V1_3_P.ProportionalGain_Gain_m
      * GUI_User_V1_3_B.Sum13;

    /* DiscreteIntegrator: '<S22>/Integrator' */
    GUI_User_V1_3_B.Integrator_g = GUI_User_V1_3_DWork.Integrator_DSTATE_g;

    /* Gain: '<S22>/Derivative Gain' */
    GUI_User_V1_3_B.DerivativeGain_n = GUI_User_V1_3_P.DerivativeGain_Gain_o *
      GUI_User_V1_3_B.Sum13;

    /* DiscreteIntegrator: '<S22>/Filter' */
    GUI_User_V1_3_B.Filter_e = GUI_User_V1_3_DWork.Filter_DSTATE_k;

    /* Sum: '<S22>/SumD' */
    GUI_User_V1_3_B.SumD_m = GUI_User_V1_3_B.DerivativeGain_n -
      GUI_User_V1_3_B.Filter_e;

    /* Gain: '<S22>/Filter Coefficient' */
    GUI_User_V1_3_B.FilterCoefficient_o =
      GUI_User_V1_3_P.FilterCoefficient_Gain_ih * GUI_User_V1_3_B.SumD_m;

    /* Sum: '<S22>/Sum' */
    GUI_User_V1_3_B.Sum_h = (GUI_User_V1_3_B.ProportionalGain_m +
      GUI_User_V1_3_B.Integrator_g) + GUI_User_V1_3_B.FilterCoefficient_o;

    /* Sum: '<S15>/Sum14' */
    GUI_User_V1_3_B.Sum14 = GUI_User_V1_3_B.Sum15 + GUI_User_V1_3_B.Sum_h;

    /* Gain: '<S15>/Gain5' */
    GUI_User_V1_3_B.Merge[4] = GUI_User_V1_3_P.Gain5_Gain_e *
      GUI_User_V1_3_B.Sum14;

    /* Sum: '<S15>/Sum18' */
    GUI_User_V1_3_B.Sum18 = GUI_User_V1_3_B.FeeedForwardGain12 +
      GUI_User_V1_3_B.FeeedForwardGain11;

    /* Sum: '<S15>/Sum16' */
    GUI_User_V1_3_B.Sum16 = GUI_User_V1_3_B.Unpack1[5] - GUI_User_V1_3_B.Sum6;

    /* Gain: '<S23>/Proportional Gain' */
    GUI_User_V1_3_B.ProportionalGain_e = GUI_User_V1_3_P.ProportionalGain_Gain_i
      * GUI_User_V1_3_B.Sum16;

    /* DiscreteIntegrator: '<S23>/Integrator' */
    GUI_User_V1_3_B.Integrator_gs = GUI_User_V1_3_DWork.Integrator_DSTATE_c;

    /* Gain: '<S23>/Derivative Gain' */
    GUI_User_V1_3_B.DerivativeGain_h = GUI_User_V1_3_P.DerivativeGain_Gain_h *
      GUI_User_V1_3_B.Sum16;

    /* DiscreteIntegrator: '<S23>/Filter' */
    GUI_User_V1_3_B.Filter_i = GUI_User_V1_3_DWork.Filter_DSTATE_n;

    /* Sum: '<S23>/SumD' */
    GUI_User_V1_3_B.SumD_f = GUI_User_V1_3_B.DerivativeGain_h -
      GUI_User_V1_3_B.Filter_i;

    /* Gain: '<S23>/Filter Coefficient' */
    GUI_User_V1_3_B.FilterCoefficient_m =
      GUI_User_V1_3_P.FilterCoefficient_Gain_dz * GUI_User_V1_3_B.SumD_f;

    /* Sum: '<S23>/Sum' */
    GUI_User_V1_3_B.Sum_i = (GUI_User_V1_3_B.ProportionalGain_e +
      GUI_User_V1_3_B.Integrator_gs) + GUI_User_V1_3_B.FilterCoefficient_m;

    /* Sum: '<S15>/Sum17' */
    GUI_User_V1_3_B.Sum17 = GUI_User_V1_3_B.Sum18 + GUI_User_V1_3_B.Sum_i;

    /* Gain: '<S15>/Gain6' */
    GUI_User_V1_3_B.Merge[5] = GUI_User_V1_3_P.Gain6_Gain_e *
      GUI_User_V1_3_B.Sum17;

    /* Sum: '<S15>/Sum9' */
    GUI_User_V1_3_B.Sum9 = GUI_User_V1_3_B.FeeedForwardGain5 +
      GUI_User_V1_3_B.FeeedForwardGain6;

    /* Gain: '<S15>/Gain7' */
    GUI_User_V1_3_B.Gain7_m = GUI_User_V1_3_P.Gain7_Gain_l *
      GUI_User_V1_3_B.Sum9;

    /* Sum: '<S15>/Sum7' */
    GUI_User_V1_3_B.Sum7 = GUI_User_V1_3_B.Unpack1[0] - GUI_User_V1_3_B.Sum1;

    /* Gain: '<S20>/Proportional Gain' */
    GUI_User_V1_3_B.ProportionalGain_k =
      GUI_User_V1_3_P.ProportionalGain_Gain_c5 * GUI_User_V1_3_B.Sum7;

    /* DiscreteIntegrator: '<S20>/Integrator' */
    GUI_User_V1_3_B.Integrator_m = GUI_User_V1_3_DWork.Integrator_DSTATE_l;

    /* Gain: '<S20>/Derivative Gain' */
    GUI_User_V1_3_B.DerivativeGain_ap = GUI_User_V1_3_P.DerivativeGain_Gain_m *
      GUI_User_V1_3_B.Sum7;

    /* DiscreteIntegrator: '<S20>/Filter' */
    GUI_User_V1_3_B.Filter_b = GUI_User_V1_3_DWork.Filter_DSTATE_m;

    /* Sum: '<S20>/SumD' */
    GUI_User_V1_3_B.SumD_fc = GUI_User_V1_3_B.DerivativeGain_ap -
      GUI_User_V1_3_B.Filter_b;

    /* Gain: '<S20>/Filter Coefficient' */
    GUI_User_V1_3_B.FilterCoefficient_h =
      GUI_User_V1_3_P.FilterCoefficient_Gain_a * GUI_User_V1_3_B.SumD_fc;

    /* Sum: '<S20>/Sum' */
    GUI_User_V1_3_B.Sum_f = (GUI_User_V1_3_B.ProportionalGain_k +
      GUI_User_V1_3_B.Integrator_m) + GUI_User_V1_3_B.FilterCoefficient_h;

    /* Gain: '<S15>/Gain8' */
    GUI_User_V1_3_B.Gain8_p = GUI_User_V1_3_P.Gain8_Gain_g *
      GUI_User_V1_3_B.Sum_f;

    /* Gain: '<S18>/Integral Gain' */
    GUI_User_V1_3_B.IntegralGain = GUI_User_V1_3_P.IntegralGain_Gain_n *
      GUI_User_V1_3_B.Sum3_o;

    /* Gain: '<S19>/Integral Gain' */
    GUI_User_V1_3_B.IntegralGain_e = GUI_User_V1_3_P.IntegralGain_Gain_jp *
      GUI_User_V1_3_B.Sum1_k;

    /* Gain: '<S20>/Integral Gain' */
    GUI_User_V1_3_B.IntegralGain_p = GUI_User_V1_3_P.IntegralGain_Gain_h *
      GUI_User_V1_3_B.Sum7;

    /* Gain: '<S21>/Integral Gain' */
    GUI_User_V1_3_B.IntegralGain_k = GUI_User_V1_3_P.IntegralGain_Gain_iw *
      GUI_User_V1_3_B.Sum10;

    /* Gain: '<S22>/Integral Gain' */
    GUI_User_V1_3_B.IntegralGain_k4 = GUI_User_V1_3_P.IntegralGain_Gain_ip *
      GUI_User_V1_3_B.Sum13;

    /* Gain: '<S23>/Integral Gain' */
    GUI_User_V1_3_B.IntegralGain_b = GUI_User_V1_3_P.IntegralGain_Gain_he *
      GUI_User_V1_3_B.Sum16;

    /* Sum: '<S15>/Sum8' */
    GUI_User_V1_3_B.Merge[0] = GUI_User_V1_3_B.Gain7_m + GUI_User_V1_3_B.Gain8_p;

    /* DiscreteZeroPole: '<S16>/Discrete Zero-Pole1' */
    {
      GUI_User_V1_3_B.DiscreteZeroPole1 = (GUI_User_V1_3_P.DiscreteZeroPole1_C[0])*
        GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole1_C[1])*
        GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE[1]
        + (GUI_User_V1_3_P.DiscreteZeroPole1_C[2])*
        GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE[2]
        + (GUI_User_V1_3_P.DiscreteZeroPole1_C[3])*
        GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE[3];
    }

    /* DiscreteZeroPole: '<S16>/Discrete Zero-Pole2' */
    {
      GUI_User_V1_3_B.DiscreteZeroPole2 = (GUI_User_V1_3_P.DiscreteZeroPole2_C[0])*
        GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole2_C[1])*
        GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE[1]
        + (GUI_User_V1_3_P.DiscreteZeroPole2_C[2])*
        GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE[2]
        + (GUI_User_V1_3_P.DiscreteZeroPole2_C[3])*
        GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE[3];
    }

    /* DiscreteZeroPole: '<S16>/Discrete Zero-Pole3' */
    {
      GUI_User_V1_3_B.DiscreteZeroPole3 = (GUI_User_V1_3_P.DiscreteZeroPole3_C[0])*
        GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole3_C[1])*
        GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE[1]
        + (GUI_User_V1_3_P.DiscreteZeroPole3_C[2])*
        GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE[2]
        + (GUI_User_V1_3_P.DiscreteZeroPole3_C[3])*
        GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE[3];
    }

    /* DiscreteZeroPole: '<S16>/Discrete Zero-Pole4' */
    {
      GUI_User_V1_3_B.DiscreteZeroPole4 = (GUI_User_V1_3_P.DiscreteZeroPole4_C[0])*
        GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole4_C[1])*
        GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE[1]
        + (GUI_User_V1_3_P.DiscreteZeroPole4_C[2])*
        GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE[2]
        + (GUI_User_V1_3_P.DiscreteZeroPole4_C[3])*
        GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE[3];
    }

    /* DiscreteZeroPole: '<S16>/Discrete Zero-Pole5' */
    {
      GUI_User_V1_3_B.DiscreteZeroPole5 = (GUI_User_V1_3_P.DiscreteZeroPole5_C[0])*
        GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole5_C[1])*
        GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE[1]
        + (GUI_User_V1_3_P.DiscreteZeroPole5_C[2])*
        GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE[2]
        + (GUI_User_V1_3_P.DiscreteZeroPole5_C[3])*
        GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE[3];
    }

    /* DiscreteZeroPole: '<S16>/Discrete Zero-Pole6' */
    {
      GUI_User_V1_3_B.DiscreteZeroPole6 = (GUI_User_V1_3_P.DiscreteZeroPole6_C[0])*
        GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole6_C[1])*
        GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE[1]
        + (GUI_User_V1_3_P.DiscreteZeroPole6_C[2])*
        GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE[2]
        + (GUI_User_V1_3_P.DiscreteZeroPole6_C[3])*
        GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE[3];
    }

    /* Gain: '<S16>/FeeedForward Gain1' */
    GUI_User_V1_3_B.FeeedForwardGain1_m =
      GUI_User_V1_3_P.FeeedForwardGain1_Gain_l * GUI_User_V1_3_B.Unpack1[8];

    /* Gain: '<S16>/FeeedForward Gain10' */
    GUI_User_V1_3_B.FeeedForwardGain10_l =
      GUI_User_V1_3_P.FeeedForwardGain10_Gain_e * GUI_User_V1_3_B.Unpack1[16];

    /* Gain: '<S16>/FeeedForward Gain11' */
    GUI_User_V1_3_B.FeeedForwardGain11_l =
      GUI_User_V1_3_P.FeeedForwardGain11_Gain_b * GUI_User_V1_3_B.Unpack1[17];

    /* Gain: '<S16>/FeeedForward Gain12' */
    GUI_User_V1_3_B.FeeedForwardGain12_g =
      GUI_User_V1_3_P.FeeedForwardGain12_Gain_h * GUI_User_V1_3_B.Unpack1[11];

    /* Gain: '<S16>/FeeedForward Gain2' */
    GUI_User_V1_3_B.FeeedForwardGain2_c =
      GUI_User_V1_3_P.FeeedForwardGain2_Gain_i * GUI_User_V1_3_B.Unpack1[14];

    /* Gain: '<S16>/FeeedForward Gain3' */
    GUI_User_V1_3_B.FeeedForwardGain3_n =
      GUI_User_V1_3_P.FeeedForwardGain3_Gain_c * GUI_User_V1_3_B.Unpack1[7];

    /* Gain: '<S16>/FeeedForward Gain4' */
    GUI_User_V1_3_B.FeeedForwardGain4_i =
      GUI_User_V1_3_P.FeeedForwardGain4_Gain_i * GUI_User_V1_3_B.Unpack1[13];

    /* Gain: '<S16>/FeeedForward Gain5' */
    GUI_User_V1_3_B.FeeedForwardGain5_a =
      GUI_User_V1_3_P.FeeedForwardGain5_Gain_n * GUI_User_V1_3_B.Unpack1[6];

    /* Gain: '<S16>/FeeedForward Gain6' */
    GUI_User_V1_3_B.FeeedForwardGain6_b =
      GUI_User_V1_3_P.FeeedForwardGain6_Gain_h * GUI_User_V1_3_B.Unpack1[12];

    /* Gain: '<S16>/FeeedForward Gain7' */
    GUI_User_V1_3_B.FeeedForwardGain7_c =
      GUI_User_V1_3_P.FeeedForwardGain7_Gain_l * GUI_User_V1_3_B.Unpack1[9];

    /* Gain: '<S16>/FeeedForward Gain8' */
    GUI_User_V1_3_B.FeeedForwardGain8_o =
      GUI_User_V1_3_P.FeeedForwardGain8_Gain_m * GUI_User_V1_3_B.Unpack1[15];

    /* Gain: '<S16>/FeeedForward Gain9' */
    GUI_User_V1_3_B.FeeedForwardGain9_k =
      GUI_User_V1_3_P.FeeedForwardGain9_Gain_b * GUI_User_V1_3_B.Unpack1[10];

    /* Sum: '<S16>/Sum6' */
    GUI_User_V1_3_B.Sum6_d = GUI_User_V1_3_B.FeeedForwardGain3_n +
      GUI_User_V1_3_B.FeeedForwardGain4_i;

    /* Sum: '<S16>/Sum5' */
    GUI_User_V1_3_B.Sum5_l = GUI_User_V1_3_B.Sum6_d +
      GUI_User_V1_3_B.DiscreteZeroPole1;

    /* Gain: '<S16>/Gain1' */
    GUI_User_V1_3_B.Gain1_p = GUI_User_V1_3_P.Gain1_Gain_p *
      GUI_User_V1_3_B.Sum5_l;

    /* Sum: '<S16>/Sum4' */
    GUI_User_V1_3_B.Sum4_c = GUI_User_V1_3_B.FeeedForwardGain1_m +
      GUI_User_V1_3_B.FeeedForwardGain2_c;

    /* Sum: '<S16>/Sum2' */
    GUI_User_V1_3_B.Sum2_im = GUI_User_V1_3_B.Sum4_c +
      GUI_User_V1_3_B.DiscreteZeroPole2;

    /* Gain: '<S16>/Gain3' */
    GUI_User_V1_3_B.Gain3_k = GUI_User_V1_3_P.Gain3_Gain_o *
      GUI_User_V1_3_B.Sum2_im;

    /* Sum: '<S16>/Sum12' */
    GUI_User_V1_3_B.Sum12_d = GUI_User_V1_3_B.FeeedForwardGain7_c +
      GUI_User_V1_3_B.FeeedForwardGain8_o;

    /* Sum: '<S16>/Sum11' */
    GUI_User_V1_3_B.Sum11_f = GUI_User_V1_3_B.Sum12_d +
      GUI_User_V1_3_B.DiscreteZeroPole3;

    /* Gain: '<S16>/Gain4' */
    GUI_User_V1_3_B.Gain4_g = GUI_User_V1_3_P.Gain4_Gain_k *
      GUI_User_V1_3_B.Sum11_f;

    /* Sum: '<S16>/Sum15' */
    GUI_User_V1_3_B.Sum15_f = GUI_User_V1_3_B.FeeedForwardGain9_k +
      GUI_User_V1_3_B.FeeedForwardGain10_l;

    /* Sum: '<S16>/Sum14' */
    GUI_User_V1_3_B.Sum14_i = GUI_User_V1_3_B.Sum15_f +
      GUI_User_V1_3_B.DiscreteZeroPole5;

    /* Gain: '<S16>/Gain5' */
    GUI_User_V1_3_B.Gain5_o = GUI_User_V1_3_P.Gain5_Gain_i *
      GUI_User_V1_3_B.Sum14_i;

    /* Sum: '<S16>/Sum18' */
    GUI_User_V1_3_B.Sum18_c = GUI_User_V1_3_B.FeeedForwardGain12_g +
      GUI_User_V1_3_B.FeeedForwardGain11_l;

    /* Sum: '<S16>/Sum17' */
    GUI_User_V1_3_B.Sum17_b = GUI_User_V1_3_B.Sum18_c +
      GUI_User_V1_3_B.DiscreteZeroPole6;

    /* Gain: '<S16>/Gain6' */
    GUI_User_V1_3_B.Gain6_h = GUI_User_V1_3_P.Gain6_Gain_a *
      GUI_User_V1_3_B.Sum17_b;

    /* Sum: '<S16>/Sum9' */
    GUI_User_V1_3_B.Sum9_l = GUI_User_V1_3_B.FeeedForwardGain5_a +
      GUI_User_V1_3_B.FeeedForwardGain6_b;

    /* Gain: '<S16>/Gain7' */
    GUI_User_V1_3_B.Gain7_j = GUI_User_V1_3_P.Gain7_Gain_a *
      GUI_User_V1_3_B.Sum9_l;

    /* Gain: '<S16>/Gain8' */
    GUI_User_V1_3_B.Gain8_f = GUI_User_V1_3_P.Gain8_Gain_l *
      GUI_User_V1_3_B.DiscreteZeroPole4;

    /* Sum: '<S16>/Sum1' */
    GUI_User_V1_3_B.Sum1_e = GUI_User_V1_3_B.Unpack1[2] - GUI_User_V1_3_B.Sum3;

    /* Sum: '<S16>/Sum10' */
    GUI_User_V1_3_B.Sum10_l = GUI_User_V1_3_B.Unpack1[3] - GUI_User_V1_3_B.Sum4;

    /* Sum: '<S16>/Sum13' */
    GUI_User_V1_3_B.Sum13_d = GUI_User_V1_3_B.Unpack1[4] - GUI_User_V1_3_B.Sum5;

    /* Sum: '<S16>/Sum16' */
    GUI_User_V1_3_B.Sum16_i = GUI_User_V1_3_B.Unpack1[5] - GUI_User_V1_3_B.Sum6;

    /* Sum: '<S16>/Sum3' */
    GUI_User_V1_3_B.Sum3_l = GUI_User_V1_3_B.Unpack1[1] - GUI_User_V1_3_B.Sum2;

    /* Sum: '<S16>/Sum7' */
    GUI_User_V1_3_B.Sum7_i = GUI_User_V1_3_B.Unpack1[0] - GUI_User_V1_3_B.Sum1;

    /* Sum: '<S16>/Sum8' */
    GUI_User_V1_3_B.Sum8 = GUI_User_V1_3_B.Gain7_j + GUI_User_V1_3_B.Gain8_f;
    srUpdateBC(GUI_User_V1_3_DWork.IfActionSubsystem6_SubsysRanBC);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem6' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    GUI_User_V1_3_B.Merge[0] = GUI_User_V1_3_P.Constant_Value_n;
    GUI_User_V1_3_B.Merge[1] = GUI_User_V1_3_P.Constant1_Value_m;
    GUI_User_V1_3_B.Merge[2] = GUI_User_V1_3_P.Constant2_Value_n;
    GUI_User_V1_3_B.Merge[3] = GUI_User_V1_3_P.Constant3_Value_i;
    GUI_User_V1_3_B.Merge[4] = GUI_User_V1_3_P.Constant4_Value_h;
    GUI_User_V1_3_B.Merge[5] = GUI_User_V1_3_P.Constant5_Value_e;
    srUpdateBC(GUI_User_V1_3_DWork.IfActionSubsystem2_SubsysRanBC);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem2' */
  }

  GUI_User_V1_3_DWork.If_ActiveSubsystem = rtAction;

  /* End of If: '<Root>/If' */

  /* Saturate: '<S5>/Saturation' */
  u = GUI_User_V1_3_B.Merge[0];
  u_0 = GUI_User_V1_3_P.Saturation_LowerSat_b;
  u_1 = GUI_User_V1_3_P.Saturation_UpperSat_j;
  GUI_User_V1_3_B.Saturation = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;

  /* If: '<S5>/If' */
  if ((GUI_User_V1_3_B.Saturation >= 0.0) && (GUI_User_V1_3_B.Saturation <=
       100.0)) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    GUI_User_V1_3_IfActionSubsystem(GUI_User_V1_3_B.Saturation,
      &GUI_User_V1_3_B.Merge_l, &GUI_User_V1_3_B.IfActionSubsystem_h,
      (rtP_IfActionSubsystem_GUI_User_ *) &GUI_User_V1_3_P.IfActionSubsystem_h);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem' */
  } else {
    if ((GUI_User_V1_3_B.Saturation < 0.0) && (GUI_User_V1_3_B.Saturation >=
         -100.0)) {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      GUI_User_V1__IfActionSubsystem1(GUI_User_V1_3_B.Saturation,
        &GUI_User_V1_3_B.Merge_l, &GUI_User_V1_3_B.IfActionSubsystem1,
        (rtP_IfActionSubsystem1_GUI_User *) &GUI_User_V1_3_P.IfActionSubsystem1);

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
    }
  }

  /* End of If: '<S5>/If' */

  /* Saturate: '<S5>/Saturation1' */
  u = GUI_User_V1_3_B.Merge[1];
  u_0 = GUI_User_V1_3_P.Saturation1_LowerSat_m;
  u_1 = GUI_User_V1_3_P.Saturation1_UpperSat_b;
  GUI_User_V1_3_B.Saturation1 = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;

  /* If: '<S5>/If1' */
  if ((GUI_User_V1_3_B.Saturation1 >= 0.0) && (GUI_User_V1_3_B.Saturation1 <=
       100.0)) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    GUI_User_V1_3_IfActionSubsystem(GUI_User_V1_3_B.Saturation1,
      &GUI_User_V1_3_B.Merge1, &GUI_User_V1_3_B.IfActionSubsystem2_c,
      (rtP_IfActionSubsystem_GUI_User_ *) &GUI_User_V1_3_P.IfActionSubsystem2_c);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem2' */
  } else {
    if ((GUI_User_V1_3_B.Saturation1 < 0.0) && (GUI_User_V1_3_B.Saturation1 >=
         -100.0)) {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      GUI_User_V1__IfActionSubsystem1(GUI_User_V1_3_B.Saturation1,
        &GUI_User_V1_3_B.Merge1, &GUI_User_V1_3_B.IfActionSubsystem3,
        (rtP_IfActionSubsystem1_GUI_User *) &GUI_User_V1_3_P.IfActionSubsystem3);

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem3' */
    }
  }

  /* End of If: '<S5>/If1' */

  /* Saturate: '<S5>/Saturation2' */
  u = GUI_User_V1_3_B.Merge[2];
  u_0 = GUI_User_V1_3_P.Saturation2_LowerSat_a;
  u_1 = GUI_User_V1_3_P.Saturation2_UpperSat_j;
  GUI_User_V1_3_B.Saturation2 = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;

  /* If: '<S5>/If2' */
  if ((GUI_User_V1_3_B.Saturation2 >= 0.0) && (GUI_User_V1_3_B.Saturation2 <=
       100.0)) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    GUI_User_V1_3_IfActionSubsystem(GUI_User_V1_3_B.Saturation2,
      &GUI_User_V1_3_B.Merge2, &GUI_User_V1_3_B.IfActionSubsystem4,
      (rtP_IfActionSubsystem_GUI_User_ *) &GUI_User_V1_3_P.IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem4' */
  } else {
    if ((GUI_User_V1_3_B.Saturation2 < 0.0) && (GUI_User_V1_3_B.Saturation2 >=
         -100.0)) {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S32>/Action Port'
       */
      GUI_User_V1__IfActionSubsystem1(GUI_User_V1_3_B.Saturation2,
        &GUI_User_V1_3_B.Merge2, &GUI_User_V1_3_B.IfActionSubsystem5_i,
        (rtP_IfActionSubsystem1_GUI_User *)
        &GUI_User_V1_3_P.IfActionSubsystem5_i);

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem5' */
    }
  }

  /* End of If: '<S5>/If2' */

  /* Saturate: '<S5>/Saturation3' */
  u = GUI_User_V1_3_B.Merge[3];
  u_0 = GUI_User_V1_3_P.Saturation3_LowerSat_j;
  u_1 = GUI_User_V1_3_P.Saturation3_UpperSat_m;
  GUI_User_V1_3_B.Saturation3 = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;

  /* If: '<S5>/If3' */
  if ((GUI_User_V1_3_B.Saturation3 >= 0.0) && (GUI_User_V1_3_B.Saturation3 <=
       100.0)) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    GUI_User_V1_3_IfActionSubsystem(GUI_User_V1_3_B.Saturation3,
      &GUI_User_V1_3_B.Merge3, &GUI_User_V1_3_B.IfActionSubsystem6_a,
      (rtP_IfActionSubsystem_GUI_User_ *) &GUI_User_V1_3_P.IfActionSubsystem6_a);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem6' */
  } else {
    if ((GUI_User_V1_3_B.Saturation3 < 0.0) && (GUI_User_V1_3_B.Saturation3 >=
         -100.0)) {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      GUI_User_V1__IfActionSubsystem1(GUI_User_V1_3_B.Saturation3,
        &GUI_User_V1_3_B.Merge3, &GUI_User_V1_3_B.IfActionSubsystem7,
        (rtP_IfActionSubsystem1_GUI_User *) &GUI_User_V1_3_P.IfActionSubsystem7);

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem7' */
    }
  }

  /* End of If: '<S5>/If3' */

  /* Saturate: '<S5>/Saturation4' */
  u = GUI_User_V1_3_B.Merge[4];
  u_0 = GUI_User_V1_3_P.Saturation4_LowerSat_p;
  u_1 = GUI_User_V1_3_P.Saturation4_UpperSat_n;
  GUI_User_V1_3_B.Saturation4 = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;

  /* If: '<S5>/If4' */
  if ((GUI_User_V1_3_B.Saturation4 >= 0.0) && (GUI_User_V1_3_B.Saturation4 <=
       100.0)) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    GUI_User_V1_3_IfActionSubsystem(GUI_User_V1_3_B.Saturation4,
      &GUI_User_V1_3_B.Merge4, &GUI_User_V1_3_B.IfActionSubsystem8,
      (rtP_IfActionSubsystem_GUI_User_ *) &GUI_User_V1_3_P.IfActionSubsystem8);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem8' */
  } else {
    if ((GUI_User_V1_3_B.Saturation4 < 0.0) && (GUI_User_V1_3_B.Saturation4 >=
         -100.0)) {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem9' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      GUI_User_V1__IfActionSubsystem1(GUI_User_V1_3_B.Saturation4,
        &GUI_User_V1_3_B.Merge4, &GUI_User_V1_3_B.IfActionSubsystem9,
        (rtP_IfActionSubsystem1_GUI_User *) &GUI_User_V1_3_P.IfActionSubsystem9);

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem9' */
    }
  }

  /* End of If: '<S5>/If4' */

  /* Saturate: '<S5>/Saturation5' */
  u = GUI_User_V1_3_B.Merge[5];
  u_0 = GUI_User_V1_3_P.Saturation5_LowerSat_l;
  u_1 = GUI_User_V1_3_P.Saturation5_UpperSat_l;
  GUI_User_V1_3_B.Saturation5 = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;

  /* If: '<S5>/If5' */
  if ((GUI_User_V1_3_B.Saturation5 >= 0.0) && (GUI_User_V1_3_B.Saturation5 <=
       100.0)) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    GUI_User_V1_3_IfActionSubsystem(GUI_User_V1_3_B.Saturation5,
      &GUI_User_V1_3_B.Merge5, &GUI_User_V1_3_B.IfActionSubsystem10,
      (rtP_IfActionSubsystem_GUI_User_ *) &GUI_User_V1_3_P.IfActionSubsystem10);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem10' */
  } else {
    if ((GUI_User_V1_3_B.Saturation5 < 0.0) && (GUI_User_V1_3_B.Saturation5 >=
         -100.0)) {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem11' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      GUI_User_V1__IfActionSubsystem1(GUI_User_V1_3_B.Saturation5,
        &GUI_User_V1_3_B.Merge5, &GUI_User_V1_3_B.IfActionSubsystem11,
        (rtP_IfActionSubsystem1_GUI_User *) &GUI_User_V1_3_P.IfActionSubsystem11);

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem11' */
    }
  }

  /* End of If: '<S5>/If5' */

  /* Level2 S-Function Block: '<S5>/ASCII Encode ' (asciiencode) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[6];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S24>/FIFO write 1' (fifowrite) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[7];
    sfcnOutputs(rts, 0);
  }

  /* S-Function Block: <S24>/Enable TX 1 (sertxenablebase) */
  if (GUI_User_V1_3_B.FIFOwrite1_o2 == 1 ) {
    uint8_T reg = (uint8_T)xpcInpB( (unsigned short)(1016 + IER) ) & 0xff;
    xpcOutpB( (unsigned short)(1016 + IER), (uint8_T)(reg & ~IERXMT) );
    reg |= IERXMT;
    xpcOutpB( (unsigned short)(1016 + IER), reg );
  }

  /* Level2 S-Function Block: '<S24>/FIFO write 2' (fifowrite) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[8];
    sfcnOutputs(rts, 0);
  }

  /* RateTransition: '<S24>/Rate Transition1' */
  GUI_User_V1_3_B.RateTransition1 = GUI_User_V1_3_B.FIFOwrite1;

  /* Level2 S-Function Block: '<S24>/FIFO read 1' (fiforead) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[9];
    sfcnOutputs(rts, 0);
  }

  /* RateTransition: '<S24>/Rate Transition3' */
  GUI_User_V1_3_B.RateTransition3 = GUI_User_V1_3_B.FIFOwrite2;

  /* Level2 S-Function Block: '<S24>/FIFO read 2' (fiforead) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[10];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S24>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[11];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S24>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[12];
    sfcnOutputs(rts, 0);
  }

  /* Gain: '<S42>/Gain2' */
  GUI_User_V1_3_B.Gain2 = GUI_User_V1_3_P.Gain2_Gain *
    GUI_User_V1_3_B.MM16ATAnalogInput_o2;

  /* Gain: '<S42>/Gain3' */
  GUI_User_V1_3_B.Gain3 = GUI_User_V1_3_P.Gain3_Gain_m *
    GUI_User_V1_3_B.MM16ATAnalogInput_o4;

  /* Gain: '<S42>/Gain4' */
  GUI_User_V1_3_B.Gain4 = GUI_User_V1_3_P.Gain4_Gain_n *
    GUI_User_V1_3_B.MM16ATAnalogInput_o6;

  /* Gain: '<S42>/Gain5' */
  GUI_User_V1_3_B.Gain5 = GUI_User_V1_3_P.Gain5_Gain_d *
    GUI_User_V1_3_B.MM16ATAnalogInput_o8;

  /* Gain: '<S42>/Gain6' */
  GUI_User_V1_3_B.Gain6 = GUI_User_V1_3_P.Gain6_Gain_b *
    GUI_User_V1_3_B.MM16ATAnalogInput_o10;

  /* Gain: '<S42>/Gain7' */
  GUI_User_V1_3_B.Gain7 = GUI_User_V1_3_P.Gain7_Gain_m *
    GUI_User_V1_3_B.MM16ATAnalogInput_o12;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void GUI_User_V1_3_update(int_T tid)
{
  /* Update for DiscreteStateSpace: '<S42>/Discrete State-Space5' */
  {
    real_T xnew[2];
    xnew[0] = (GUI_User_V1_3_P.DiscreteStateSpace5_A[0])*
      GUI_User_V1_3_DWork.DiscreteStateSpace5_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace5_A[1])*
      GUI_User_V1_3_DWork.DiscreteStateSpace5_DSTATE[1];
    xnew[0] += (GUI_User_V1_3_P.DiscreteStateSpace5_B[0])*
      GUI_User_V1_3_B.MM16ATAnalogInput_o11;
    xnew[1] = (GUI_User_V1_3_P.DiscreteStateSpace5_A[2])*
      GUI_User_V1_3_DWork.DiscreteStateSpace5_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace5_A[3])*
      GUI_User_V1_3_DWork.DiscreteStateSpace5_DSTATE[1];
    xnew[1] += (GUI_User_V1_3_P.DiscreteStateSpace5_B[1])*
      GUI_User_V1_3_B.MM16ATAnalogInput_o11;
    (void) memcpy(&GUI_User_V1_3_DWork.DiscreteStateSpace5_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S42>/Discrete State-Space4' */
  {
    real_T xnew[2];
    xnew[0] = (GUI_User_V1_3_P.DiscreteStateSpace4_A[0])*
      GUI_User_V1_3_DWork.DiscreteStateSpace4_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace4_A[1])*
      GUI_User_V1_3_DWork.DiscreteStateSpace4_DSTATE[1];
    xnew[0] += (GUI_User_V1_3_P.DiscreteStateSpace4_B[0])*
      GUI_User_V1_3_B.MM16ATAnalogInput_o9;
    xnew[1] = (GUI_User_V1_3_P.DiscreteStateSpace4_A[2])*
      GUI_User_V1_3_DWork.DiscreteStateSpace4_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace4_A[3])*
      GUI_User_V1_3_DWork.DiscreteStateSpace4_DSTATE[1];
    xnew[1] += (GUI_User_V1_3_P.DiscreteStateSpace4_B[1])*
      GUI_User_V1_3_B.MM16ATAnalogInput_o9;
    (void) memcpy(&GUI_User_V1_3_DWork.DiscreteStateSpace4_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S42>/Discrete State-Space3' */
  {
    real_T xnew[2];
    xnew[0] = (GUI_User_V1_3_P.DiscreteStateSpace3_A[0])*
      GUI_User_V1_3_DWork.DiscreteStateSpace3_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace3_A[1])*
      GUI_User_V1_3_DWork.DiscreteStateSpace3_DSTATE[1];
    xnew[0] += (GUI_User_V1_3_P.DiscreteStateSpace3_B[0])*
      GUI_User_V1_3_B.MM16ATAnalogInput_o7;
    xnew[1] = (GUI_User_V1_3_P.DiscreteStateSpace3_A[2])*
      GUI_User_V1_3_DWork.DiscreteStateSpace3_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace3_A[3])*
      GUI_User_V1_3_DWork.DiscreteStateSpace3_DSTATE[1];
    xnew[1] += (GUI_User_V1_3_P.DiscreteStateSpace3_B[1])*
      GUI_User_V1_3_B.MM16ATAnalogInput_o7;
    (void) memcpy(&GUI_User_V1_3_DWork.DiscreteStateSpace3_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S42>/Discrete State-Space2' */
  {
    real_T xnew[2];
    xnew[0] = (GUI_User_V1_3_P.DiscreteStateSpace2_A[0])*
      GUI_User_V1_3_DWork.DiscreteStateSpace2_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace2_A[1])*
      GUI_User_V1_3_DWork.DiscreteStateSpace2_DSTATE[1];
    xnew[0] += (GUI_User_V1_3_P.DiscreteStateSpace2_B[0])*
      GUI_User_V1_3_B.MM16ATAnalogInput_o5;
    xnew[1] = (GUI_User_V1_3_P.DiscreteStateSpace2_A[2])*
      GUI_User_V1_3_DWork.DiscreteStateSpace2_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace2_A[3])*
      GUI_User_V1_3_DWork.DiscreteStateSpace2_DSTATE[1];
    xnew[1] += (GUI_User_V1_3_P.DiscreteStateSpace2_B[1])*
      GUI_User_V1_3_B.MM16ATAnalogInput_o5;
    (void) memcpy(&GUI_User_V1_3_DWork.DiscreteStateSpace2_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S42>/Discrete State-Space1' */
  {
    real_T xnew[2];
    xnew[0] = (GUI_User_V1_3_P.DiscreteStateSpace1_A[0])*
      GUI_User_V1_3_DWork.DiscreteStateSpace1_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace1_A[1])*
      GUI_User_V1_3_DWork.DiscreteStateSpace1_DSTATE[1];
    xnew[0] += (GUI_User_V1_3_P.DiscreteStateSpace1_B[0])*
      GUI_User_V1_3_B.MM16ATAnalogInput_o3;
    xnew[1] = (GUI_User_V1_3_P.DiscreteStateSpace1_A[2])*
      GUI_User_V1_3_DWork.DiscreteStateSpace1_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace1_A[3])*
      GUI_User_V1_3_DWork.DiscreteStateSpace1_DSTATE[1];
    xnew[1] += (GUI_User_V1_3_P.DiscreteStateSpace1_B[1])*
      GUI_User_V1_3_B.MM16ATAnalogInput_o3;
    (void) memcpy(&GUI_User_V1_3_DWork.DiscreteStateSpace1_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S42>/Discrete State-Space6' */
  {
    real_T xnew[2];
    xnew[0] = (GUI_User_V1_3_P.DiscreteStateSpace6_A[0])*
      GUI_User_V1_3_DWork.DiscreteStateSpace6_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace6_A[1])*
      GUI_User_V1_3_DWork.DiscreteStateSpace6_DSTATE[1];
    xnew[0] += (GUI_User_V1_3_P.DiscreteStateSpace6_B[0])*
      GUI_User_V1_3_B.MM16ATAnalogInput_o1;
    xnew[1] = (GUI_User_V1_3_P.DiscreteStateSpace6_A[2])*
      GUI_User_V1_3_DWork.DiscreteStateSpace6_DSTATE[0]
      + (GUI_User_V1_3_P.DiscreteStateSpace6_A[3])*
      GUI_User_V1_3_DWork.DiscreteStateSpace6_DSTATE[1];
    xnew[1] += (GUI_User_V1_3_P.DiscreteStateSpace6_B[1])*
      GUI_User_V1_3_B.MM16ATAnalogInput_o1;
    (void) memcpy(&GUI_User_V1_3_DWork.DiscreteStateSpace6_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for If: '<Root>/If' */
  switch (GUI_User_V1_3_DWork.If_ActiveSubsystem) {
   case 0:
    break;

   case 1:
    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem5' incorporates:
     *  Update for ActionPort: '<S3>/Action Port'
     */
    /* Update for DiscreteIntegrator: '<S11>/Integrator' */
    GUI_User_V1_3_DWork.Integrator_DSTATE_cb =
      GUI_User_V1_3_P.Integrator_gainval * GUI_User_V1_3_B.IntegralGain_c +
      GUI_User_V1_3_DWork.Integrator_DSTATE_cb;

    /* Update for DiscreteIntegrator: '<S11>/Filter' */
    GUI_User_V1_3_DWork.Filter_DSTATE_f = GUI_User_V1_3_P.Filter_gainval *
      GUI_User_V1_3_B.FilterCoefficient_i + GUI_User_V1_3_DWork.Filter_DSTATE_f;

    /* Update for DiscreteIntegrator: '<S9>/Integrator' */
    GUI_User_V1_3_DWork.Integrator_DSTATE_j =
      GUI_User_V1_3_P.Integrator_gainval_p * GUI_User_V1_3_B.IntegralGain_o +
      GUI_User_V1_3_DWork.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S9>/Filter' */
    GUI_User_V1_3_DWork.Filter_DSTATE_o = GUI_User_V1_3_P.Filter_gainval_c *
      GUI_User_V1_3_B.FilterCoefficient_jw + GUI_User_V1_3_DWork.Filter_DSTATE_o;

    /* Update for DiscreteIntegrator: '<S10>/Integrator' */
    GUI_User_V1_3_DWork.Integrator_DSTATE_d =
      GUI_User_V1_3_P.Integrator_gainval_j * GUI_User_V1_3_B.IntegralGain_ko +
      GUI_User_V1_3_DWork.Integrator_DSTATE_d;

    /* Update for DiscreteIntegrator: '<S10>/Filter' */
    GUI_User_V1_3_DWork.Filter_DSTATE_mn = GUI_User_V1_3_P.Filter_gainval_g *
      GUI_User_V1_3_B.FilterCoefficient_a + GUI_User_V1_3_DWork.Filter_DSTATE_mn;

    /* Update for DiscreteIntegrator: '<S12>/Integrator' */
    GUI_User_V1_3_DWork.Integrator_DSTATE_k =
      GUI_User_V1_3_P.Integrator_gainval_j4 * GUI_User_V1_3_B.IntegralGain_g +
      GUI_User_V1_3_DWork.Integrator_DSTATE_k;

    /* Update for DiscreteIntegrator: '<S12>/Filter' */
    GUI_User_V1_3_DWork.Filter_DSTATE_mv = GUI_User_V1_3_P.Filter_gainval_e *
      GUI_User_V1_3_B.FilterCoefficient_f + GUI_User_V1_3_DWork.Filter_DSTATE_mv;

    /* Update for DiscreteIntegrator: '<S13>/Integrator' */
    GUI_User_V1_3_DWork.Integrator_DSTATE_mj =
      GUI_User_V1_3_P.Integrator_gainval_i * GUI_User_V1_3_B.IntegralGain_h +
      GUI_User_V1_3_DWork.Integrator_DSTATE_mj;

    /* Update for DiscreteIntegrator: '<S13>/Filter' */
    GUI_User_V1_3_DWork.Filter_DSTATE_kq = GUI_User_V1_3_P.Filter_gainval_cs *
      GUI_User_V1_3_B.FilterCoefficient_hs +
      GUI_User_V1_3_DWork.Filter_DSTATE_kq;

    /* Update for DiscreteIntegrator: '<S14>/Integrator' */
    GUI_User_V1_3_DWork.Integrator_DSTATE_i =
      GUI_User_V1_3_P.Integrator_gainval_f * GUI_User_V1_3_B.IntegralGain_m +
      GUI_User_V1_3_DWork.Integrator_DSTATE_i;

    /* Update for DiscreteIntegrator: '<S14>/Filter' */
    GUI_User_V1_3_DWork.Filter_DSTATE_me = GUI_User_V1_3_P.Filter_gainval_n *
      GUI_User_V1_3_B.FilterCoefficient_b + GUI_User_V1_3_DWork.Filter_DSTATE_me;

    /* End of Update for SubSystem: '<Root>/If Action Subsystem5' */
    break;

   case 2:
    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem6' incorporates:
     *  Update for ActionPort: '<S4>/Action Port'
     */
    /* Update for DiscreteIntegrator: '<S18>/Integrator' */
    GUI_User_V1_3_DWork.Integrator_DSTATE =
      GUI_User_V1_3_P.Integrator_gainval_fe * GUI_User_V1_3_B.IntegralGain +
      GUI_User_V1_3_DWork.Integrator_DSTATE;

    /* Update for DiscreteIntegrator: '<S18>/Filter' */
    GUI_User_V1_3_DWork.Filter_DSTATE = GUI_User_V1_3_P.Filter_gainval_p *
      GUI_User_V1_3_B.FilterCoefficient + GUI_User_V1_3_DWork.Filter_DSTATE;

    /* Update for DiscreteIntegrator: '<S19>/Integrator' */
    GUI_User_V1_3_DWork.Integrator_DSTATE_m =
      GUI_User_V1_3_P.Integrator_gainval_c * GUI_User_V1_3_B.IntegralGain_e +
      GUI_User_V1_3_DWork.Integrator_DSTATE_m;

    /* Update for DiscreteIntegrator: '<S19>/Filter' */
    GUI_User_V1_3_DWork.Filter_DSTATE_i = GUI_User_V1_3_P.Filter_gainval_o *
      GUI_User_V1_3_B.FilterCoefficient_n + GUI_User_V1_3_DWork.Filter_DSTATE_i;

    /* Update for DiscreteIntegrator: '<S21>/Integrator' */
    GUI_User_V1_3_DWork.Integrator_DSTATE_a =
      GUI_User_V1_3_P.Integrator_gainval_g * GUI_User_V1_3_B.IntegralGain_k +
      GUI_User_V1_3_DWork.Integrator_DSTATE_a;

    /* Update for DiscreteIntegrator: '<S21>/Filter' */
    GUI_User_V1_3_DWork.Filter_DSTATE_h = GUI_User_V1_3_P.Filter_gainval_m *
      GUI_User_V1_3_B.FilterCoefficient_j + GUI_User_V1_3_DWork.Filter_DSTATE_h;

    /* Update for DiscreteIntegrator: '<S22>/Integrator' */
    GUI_User_V1_3_DWork.Integrator_DSTATE_g =
      GUI_User_V1_3_P.Integrator_gainval_m * GUI_User_V1_3_B.IntegralGain_k4 +
      GUI_User_V1_3_DWork.Integrator_DSTATE_g;

    /* Update for DiscreteIntegrator: '<S22>/Filter' */
    GUI_User_V1_3_DWork.Filter_DSTATE_k = GUI_User_V1_3_P.Filter_gainval_d *
      GUI_User_V1_3_B.FilterCoefficient_o + GUI_User_V1_3_DWork.Filter_DSTATE_k;

    /* Update for DiscreteIntegrator: '<S23>/Integrator' */
    GUI_User_V1_3_DWork.Integrator_DSTATE_c =
      GUI_User_V1_3_P.Integrator_gainval_d * GUI_User_V1_3_B.IntegralGain_b +
      GUI_User_V1_3_DWork.Integrator_DSTATE_c;

    /* Update for DiscreteIntegrator: '<S23>/Filter' */
    GUI_User_V1_3_DWork.Filter_DSTATE_n = GUI_User_V1_3_P.Filter_gainval_m1 *
      GUI_User_V1_3_B.FilterCoefficient_m + GUI_User_V1_3_DWork.Filter_DSTATE_n;

    /* Update for DiscreteIntegrator: '<S20>/Integrator' */
    GUI_User_V1_3_DWork.Integrator_DSTATE_l =
      GUI_User_V1_3_P.Integrator_gainval_l * GUI_User_V1_3_B.IntegralGain_p +
      GUI_User_V1_3_DWork.Integrator_DSTATE_l;

    /* Update for DiscreteIntegrator: '<S20>/Filter' */
    GUI_User_V1_3_DWork.Filter_DSTATE_m = GUI_User_V1_3_P.Filter_gainval_py *
      GUI_User_V1_3_B.FilterCoefficient_h + GUI_User_V1_3_DWork.Filter_DSTATE_m;

    /* Update for DiscreteZeroPole: '<S16>/Discrete Zero-Pole1' */
    {
      real_T xnew[4];
      xnew[0] = (GUI_User_V1_3_P.DiscreteZeroPole1_A[0])*
        GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole1_A[1])*
        GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE[1];
      xnew[0] += GUI_User_V1_3_P.DiscreteZeroPole1_B*GUI_User_V1_3_B.Sum3_l;
      xnew[1] = (GUI_User_V1_3_P.DiscreteZeroPole1_A[2])*
        GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE[0];
      xnew[2] = (GUI_User_V1_3_P.DiscreteZeroPole1_A[3])*
        GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole1_A[4])*
        GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE[1]
        + (GUI_User_V1_3_P.DiscreteZeroPole1_A[5])*
        GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE[2]
        + (GUI_User_V1_3_P.DiscreteZeroPole1_A[6])*
        GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE[3];
      xnew[3] = (GUI_User_V1_3_P.DiscreteZeroPole1_A[7])*
        GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE[2];
      (void) memcpy(&GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE[0], xnew,
                    sizeof(real_T)*4);
    }

    /* Update for DiscreteZeroPole: '<S16>/Discrete Zero-Pole2' */
    {
      real_T xnew[4];
      xnew[0] = (GUI_User_V1_3_P.DiscreteZeroPole2_A[0])*
        GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole2_A[1])*
        GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE[1];
      xnew[0] += GUI_User_V1_3_P.DiscreteZeroPole2_B*GUI_User_V1_3_B.Sum1_e;
      xnew[1] = (GUI_User_V1_3_P.DiscreteZeroPole2_A[2])*
        GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE[0];
      xnew[2] = (GUI_User_V1_3_P.DiscreteZeroPole2_A[3])*
        GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole2_A[4])*
        GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE[1]
        + (GUI_User_V1_3_P.DiscreteZeroPole2_A[5])*
        GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE[2]
        + (GUI_User_V1_3_P.DiscreteZeroPole2_A[6])*
        GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE[3];
      xnew[3] = (GUI_User_V1_3_P.DiscreteZeroPole2_A[7])*
        GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE[2];
      (void) memcpy(&GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE[0], xnew,
                    sizeof(real_T)*4);
    }

    /* Update for DiscreteZeroPole: '<S16>/Discrete Zero-Pole3' */
    {
      real_T xnew[4];
      xnew[0] = (GUI_User_V1_3_P.DiscreteZeroPole3_A[0])*
        GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole3_A[1])*
        GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE[1];
      xnew[0] += GUI_User_V1_3_P.DiscreteZeroPole3_B*GUI_User_V1_3_B.Sum10_l;
      xnew[1] = (GUI_User_V1_3_P.DiscreteZeroPole3_A[2])*
        GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE[0];
      xnew[2] = (GUI_User_V1_3_P.DiscreteZeroPole3_A[3])*
        GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole3_A[4])*
        GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE[1]
        + (GUI_User_V1_3_P.DiscreteZeroPole3_A[5])*
        GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE[2]
        + (GUI_User_V1_3_P.DiscreteZeroPole3_A[6])*
        GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE[3];
      xnew[3] = (GUI_User_V1_3_P.DiscreteZeroPole3_A[7])*
        GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE[2];
      (void) memcpy(&GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE[0], xnew,
                    sizeof(real_T)*4);
    }

    /* Update for DiscreteZeroPole: '<S16>/Discrete Zero-Pole4' */
    {
      real_T xnew[4];
      xnew[0] = (GUI_User_V1_3_P.DiscreteZeroPole4_A[0])*
        GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole4_A[1])*
        GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE[1];
      xnew[0] += GUI_User_V1_3_P.DiscreteZeroPole4_B*GUI_User_V1_3_B.Sum7_i;
      xnew[1] = (GUI_User_V1_3_P.DiscreteZeroPole4_A[2])*
        GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE[0];
      xnew[2] = (GUI_User_V1_3_P.DiscreteZeroPole4_A[3])*
        GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole4_A[4])*
        GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE[1]
        + (GUI_User_V1_3_P.DiscreteZeroPole4_A[5])*
        GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE[2]
        + (GUI_User_V1_3_P.DiscreteZeroPole4_A[6])*
        GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE[3];
      xnew[3] = (GUI_User_V1_3_P.DiscreteZeroPole4_A[7])*
        GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE[2];
      (void) memcpy(&GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE[0], xnew,
                    sizeof(real_T)*4);
    }

    /* Update for DiscreteZeroPole: '<S16>/Discrete Zero-Pole5' */
    {
      real_T xnew[4];
      xnew[0] = (GUI_User_V1_3_P.DiscreteZeroPole5_A[0])*
        GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole5_A[1])*
        GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE[1];
      xnew[0] += GUI_User_V1_3_P.DiscreteZeroPole5_B*GUI_User_V1_3_B.Sum13_d;
      xnew[1] = (GUI_User_V1_3_P.DiscreteZeroPole5_A[2])*
        GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE[0];
      xnew[2] = (GUI_User_V1_3_P.DiscreteZeroPole5_A[3])*
        GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole5_A[4])*
        GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE[1]
        + (GUI_User_V1_3_P.DiscreteZeroPole5_A[5])*
        GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE[2]
        + (GUI_User_V1_3_P.DiscreteZeroPole5_A[6])*
        GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE[3];
      xnew[3] = (GUI_User_V1_3_P.DiscreteZeroPole5_A[7])*
        GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE[2];
      (void) memcpy(&GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE[0], xnew,
                    sizeof(real_T)*4);
    }

    /* Update for DiscreteZeroPole: '<S16>/Discrete Zero-Pole6' */
    {
      real_T xnew[4];
      xnew[0] = (GUI_User_V1_3_P.DiscreteZeroPole6_A[0])*
        GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole6_A[1])*
        GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE[1];
      xnew[0] += GUI_User_V1_3_P.DiscreteZeroPole6_B*GUI_User_V1_3_B.Sum16_i;
      xnew[1] = (GUI_User_V1_3_P.DiscreteZeroPole6_A[2])*
        GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE[0];
      xnew[2] = (GUI_User_V1_3_P.DiscreteZeroPole6_A[3])*
        GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE[0]
        + (GUI_User_V1_3_P.DiscreteZeroPole6_A[4])*
        GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE[1]
        + (GUI_User_V1_3_P.DiscreteZeroPole6_A[5])*
        GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE[2]
        + (GUI_User_V1_3_P.DiscreteZeroPole6_A[6])*
        GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE[3];
      xnew[3] = (GUI_User_V1_3_P.DiscreteZeroPole6_A[7])*
        GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE[2];
      (void) memcpy(&GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE[0], xnew,
                    sizeof(real_T)*4);
    }

    /* End of Update for SubSystem: '<Root>/If Action Subsystem6' */
    break;

   case 3:
    break;
  }

  /* End of If: '<Root>/If' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++GUI_User_V1_3_rtM->Timing.clockTick0)) {
    ++GUI_User_V1_3_rtM->Timing.clockTickH0;
  }

  GUI_User_V1_3_rtM->Timing.t[0] = GUI_User_V1_3_rtM->Timing.clockTick0 *
    GUI_User_V1_3_rtM->Timing.stepSize0 + GUI_User_V1_3_rtM->Timing.clockTickH0 *
    GUI_User_V1_3_rtM->Timing.stepSize0 * 4294967296.0;
  switch (GUI_User_V1_3_rtM->Timing.rtmDbBufReadBuf1) {
   case 0:
    GUI_User_V1_3_rtM->Timing.rtmDbBufWriteBuf1 = 1;
    break;

   case 1:
    GUI_User_V1_3_rtM->Timing.rtmDbBufWriteBuf1 = 0;
    break;

   default:
    GUI_User_V1_3_rtM->Timing.rtmDbBufWriteBuf1 =
      !GUI_User_V1_3_rtM->Timing.rtmDbBufLastBufWr1;
    break;
  }

  GUI_User_V1_3_rtM->Timing.rtmDbBufClockTick1
    [GUI_User_V1_3_rtM->Timing.rtmDbBufWriteBuf1] =
    GUI_User_V1_3_rtM->Timing.clockTick0;
  GUI_User_V1_3_rtM->Timing.rtmDbBufClockTickH1
    [GUI_User_V1_3_rtM->Timing.rtmDbBufWriteBuf1] =
    GUI_User_V1_3_rtM->Timing.clockTickH0;
  GUI_User_V1_3_rtM->Timing.rtmDbBufLastBufWr1 =
    GUI_User_V1_3_rtM->Timing.rtmDbBufWriteBuf1;
  GUI_User_V1_3_rtM->Timing.rtmDbBufWriteBuf1 = 0xFF;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void GUI_User_V1_3_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)GUI_User_V1_3_rtM, 0,
                sizeof(rtModel_GUI_User_V1_3));
  rtsiSetSolverName(&GUI_User_V1_3_rtM->solverInfo,"FixedStepDiscrete");
  GUI_User_V1_3_rtM->solverInfoPtr = (&GUI_User_V1_3_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = GUI_User_V1_3_rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    GUI_User_V1_3_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    GUI_User_V1_3_rtM->Timing.sampleTimes =
      (&GUI_User_V1_3_rtM->Timing.sampleTimesArray[0]);
    GUI_User_V1_3_rtM->Timing.offsetTimes =
      (&GUI_User_V1_3_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    GUI_User_V1_3_rtM->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    GUI_User_V1_3_rtM->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(GUI_User_V1_3_rtM, &GUI_User_V1_3_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = GUI_User_V1_3_rtM->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    GUI_User_V1_3_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(GUI_User_V1_3_rtM, 3.1536E+7);
  GUI_User_V1_3_rtM->Timing.stepSize0 = 0.001;
  GUI_User_V1_3_rtM->Timing.stepSize1 = 0.001;
  rtmSetFirstInitCond(GUI_User_V1_3_rtM, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    GUI_User_V1_3_rtM->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(GUI_User_V1_3_rtM->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(GUI_User_V1_3_rtM->rtwLogInfo, (NULL));
    rtliSetLogT(GUI_User_V1_3_rtM->rtwLogInfo, "tout");
    rtliSetLogX(GUI_User_V1_3_rtM->rtwLogInfo, "");
    rtliSetLogXFinal(GUI_User_V1_3_rtM->rtwLogInfo, "");
    rtliSetSigLog(GUI_User_V1_3_rtM->rtwLogInfo, "");
    rtliSetLogVarNameModifier(GUI_User_V1_3_rtM->rtwLogInfo, "rt_");
    rtliSetLogFormat(GUI_User_V1_3_rtM->rtwLogInfo, 0);
    rtliSetLogMaxRows(GUI_User_V1_3_rtM->rtwLogInfo, 0);
    rtliSetLogDecimation(GUI_User_V1_3_rtM->rtwLogInfo, 1);
    rtliSetLogY(GUI_User_V1_3_rtM->rtwLogInfo, "");
    rtliSetLogYSignalInfo(GUI_User_V1_3_rtM->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(GUI_User_V1_3_rtM->rtwLogInfo, (NULL));
  }

  /* external mode info */
  GUI_User_V1_3_rtM->Sizes.checksums[0] = (3187963147U);
  GUI_User_V1_3_rtM->Sizes.checksums[1] = (3578660434U);
  GUI_User_V1_3_rtM->Sizes.checksums[2] = (1249621880U);
  GUI_User_V1_3_rtM->Sizes.checksums[3] = (2337795904U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[22];
    GUI_User_V1_3_rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem2_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem5_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem6_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&GUI_User_V1_3_DWork.Receive1_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&GUI_User_V1_3_DWork.Receive2_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&GUI_User_V1_3_DWork.Transmit1_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&GUI_User_V1_3_DWork.Transmit2_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&GUI_User_V1_3_DWork.RS232ISR_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem_h.IfActionSubsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem10.IfActionSubsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem11.IfActionSubsystem1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem2_c.IfActionSubsystem_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem3.IfActionSubsystem1_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem5_i.IfActionSubsystem1_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem6_a.IfActionSubsystem_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem7.IfActionSubsystem1_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem8.IfActionSubsystem_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &GUI_User_V1_3_DWork.IfActionSubsystem9.IfActionSubsystem1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(GUI_User_V1_3_rtM->extModeInfo,
      &GUI_User_V1_3_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(GUI_User_V1_3_rtM->extModeInfo,
                        GUI_User_V1_3_rtM->Sizes.checksums);
    rteiSetTPtr(GUI_User_V1_3_rtM->extModeInfo, rtmGetTPtr(GUI_User_V1_3_rtM));
  }

  GUI_User_V1_3_rtM->solverInfoPtr = (&GUI_User_V1_3_rtM->solverInfo);
  GUI_User_V1_3_rtM->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&GUI_User_V1_3_rtM->solverInfo, 0.001);
  rtsiSetSolverMode(&GUI_User_V1_3_rtM->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  GUI_User_V1_3_rtM->ModelData.blockIO = ((void *) &GUI_User_V1_3_B);
  (void) memset(((void *) &GUI_User_V1_3_B), 0,
                sizeof(BlockIO_GUI_User_V1_3));

  {
    GUI_User_V1_3_B.FIFOwrite1_o1 = serialfifoground;
    GUI_User_V1_3_B.FIFOwrite2_o1 = serialfifoground;
    GUI_User_V1_3_B.RateTransition = serialfifoground;
    GUI_User_V1_3_B.RateTransition2 = serialfifoground;
    GUI_User_V1_3_B.RateTransition1 = serialfifoground;
    GUI_User_V1_3_B.RateTransition3 = serialfifoground;
    GUI_User_V1_3_B.FIFOwrite2 = serialfifoground;
    GUI_User_V1_3_B.FIFOwrite1 = serialfifoground;
  }

  /* parameters */
  GUI_User_V1_3_rtM->ModelData.defaultParam = ((real_T *)&GUI_User_V1_3_P);

  /* states (dwork) */
  GUI_User_V1_3_rtM->Work.dwork = ((void *) &GUI_User_V1_3_DWork);
  (void) memset((void *)&GUI_User_V1_3_DWork, 0,
                sizeof(D_Work_GUI_User_V1_3));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    GUI_User_V1_3_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    GUI_User_V1_3_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  GUI_User_V1_3_InitializeDataMapInfo(GUI_User_V1_3_rtM);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &GUI_User_V1_3_rtM->NonInlinedSFcns.sfcnInfo;
    GUI_User_V1_3_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(GUI_User_V1_3_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &GUI_User_V1_3_rtM->Sizes.numSampTimes);
    GUI_User_V1_3_rtM->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (GUI_User_V1_3_rtM)[0]);
    GUI_User_V1_3_rtM->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (GUI_User_V1_3_rtM)[1]);
    rtssSetTPtrPtr(sfcnInfo,GUI_User_V1_3_rtM->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(GUI_User_V1_3_rtM));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(GUI_User_V1_3_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (GUI_User_V1_3_rtM));
    rtssSetStepSizePtr(sfcnInfo, &GUI_User_V1_3_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(GUI_User_V1_3_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &GUI_User_V1_3_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &GUI_User_V1_3_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &GUI_User_V1_3_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &GUI_User_V1_3_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &GUI_User_V1_3_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &GUI_User_V1_3_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &GUI_User_V1_3_rtM->solverInfoPtr);
  }

  GUI_User_V1_3_rtM->Sizes.numSFcns = (13);

  /* register each child */
  {
    (void) memset((void *)&GUI_User_V1_3_rtM->NonInlinedSFcns.childSFunctions[0],
                  0,
                  13*sizeof(SimStruct));
    GUI_User_V1_3_rtM->childSfunctions =
      (&GUI_User_V1_3_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 13; i++) {
        GUI_User_V1_3_rtM->childSfunctions[i] =
          (&GUI_User_V1_3_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: GUI_User_V1_3/<S17>/From File1 (xpcfromfile) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, GUI_User_V1_3_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 144);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) GUI_User_V1_3_B.FromFile1));
        }
      }

      /* path info */
      ssSetModelName(rts, "From File1");
      ssSetPath(rts, "GUI_User_V1_3/If Action Subsystem6/Referece/From File1");
      ssSetRTModel(rts,GUI_User_V1_3_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GUI_User_V1_3_P.FromFile1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GUI_User_V1_3_P.FromFile1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)GUI_User_V1_3_P.FromFile1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)GUI_User_V1_3_P.FromFile1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)GUI_User_V1_3_P.FromFile1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)GUI_User_V1_3_P.FromFile1_P6_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &GUI_User_V1_3_DWork.FromFile1_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &GUI_User_V1_3_DWork.FromFile1_IWORK);
      }

      /* registration */
      xpcfromfile(rts);
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
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: GUI_User_V1_3/<S38>/FIFO write 1 (fifowrite) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, GUI_User_V1_3_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, GUI_User_V1_3_B.ReadHWFIFO1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 65);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((serialfifoptr *)
            &GUI_User_V1_3_B.FIFOwrite1));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO write 1");
      ssSetPath(rts,
                "GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1");
      ssSetRTModel(rts,GUI_User_V1_3_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GUI_User_V1_3_P.FIFOwrite1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GUI_User_V1_3_P.FIFOwrite1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)GUI_User_V1_3_P.FIFOwrite1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)GUI_User_V1_3_P.FIFOwrite1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)GUI_User_V1_3_P.FIFOwrite1_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &GUI_User_V1_3_DWork.FIFOwrite1_IWORK_o[0]);
      ssSetPWork(rts, (void **) &GUI_User_V1_3_DWork.FIFOwrite1_PWORK_d);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &GUI_User_V1_3_DWork.FIFOwrite1_IWORK_o[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &GUI_User_V1_3_DWork.FIFOwrite1_PWORK_d);
      }

      /* registration */
      fifowrite(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, -1.0);
      ssSetOffsetTime(rts, 0, -2.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 65);
      ssSetInputPortDataType(rts, 0, SS_UINT32);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: GUI_User_V1_3/<S40>/FIFO read 1 (fiforead) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, GUI_User_V1_3_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &GUI_User_V1_3_B.RateTransition);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &GUI_User_V1_3_B.ReadIntStatusFC1_o2);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          ssSetInputPortRequiredContiguous(rts, 2, 1);
          ssSetInputPortSignal(rts, 2, &GUI_User_V1_3_P.Constant1_Value_k);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 61);
          ssSetOutputPortSignal(rts, 0, ((uint32_T *)
            GUI_User_V1_3_B.FIFOread1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &GUI_User_V1_3_B.FIFOread1_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO read 1");
      ssSetPath(rts,
                "GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1");
      ssSetRTModel(rts,GUI_User_V1_3_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GUI_User_V1_3_P.FIFOread1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GUI_User_V1_3_P.FIFOread1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)GUI_User_V1_3_P.FIFOread1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)GUI_User_V1_3_P.FIFOread1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)GUI_User_V1_3_P.FIFOread1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)GUI_User_V1_3_P.FIFOread1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)GUI_User_V1_3_P.FIFOread1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)GUI_User_V1_3_P.FIFOread1_P8_Size);
      }

      /* registration */
      fiforead(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, -1.0);
      ssSetOffsetTime(rts, 0, -2.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: GUI_User_V1_3/<S39>/FIFO write 2 (fifowrite) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, GUI_User_V1_3_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, GUI_User_V1_3_B.ReadHWFIFO2);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 65);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((serialfifoptr *)
            &GUI_User_V1_3_B.FIFOwrite2));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO write 2");
      ssSetPath(rts,
                "GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2");
      ssSetRTModel(rts,GUI_User_V1_3_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GUI_User_V1_3_P.FIFOwrite2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GUI_User_V1_3_P.FIFOwrite2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)GUI_User_V1_3_P.FIFOwrite2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)GUI_User_V1_3_P.FIFOwrite2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)GUI_User_V1_3_P.FIFOwrite2_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &GUI_User_V1_3_DWork.FIFOwrite2_IWORK_k[0]);
      ssSetPWork(rts, (void **) &GUI_User_V1_3_DWork.FIFOwrite2_PWORK_o);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &GUI_User_V1_3_DWork.FIFOwrite2_IWORK_k[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &GUI_User_V1_3_DWork.FIFOwrite2_PWORK_o);
      }

      /* registration */
      fifowrite(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, -1.0);
      ssSetOffsetTime(rts, 0, -2.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 65);
      ssSetInputPortDataType(rts, 0, SS_UINT32);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: GUI_User_V1_3/<S41>/FIFO read 2 (fiforead) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, GUI_User_V1_3_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &GUI_User_V1_3_B.RateTransition2);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &GUI_User_V1_3_B.ReadIntStatusFC1_o2);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          ssSetInputPortRequiredContiguous(rts, 2, 1);
          ssSetInputPortSignal(rts, 2, &GUI_User_V1_3_P.Constant2_Value_h);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 61);
          ssSetOutputPortSignal(rts, 0, ((uint32_T *)
            GUI_User_V1_3_B.FIFOread2_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &GUI_User_V1_3_B.FIFOread2_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO read 2");
      ssSetPath(rts,
                "GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2");
      ssSetRTModel(rts,GUI_User_V1_3_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GUI_User_V1_3_P.FIFOread2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GUI_User_V1_3_P.FIFOread2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)GUI_User_V1_3_P.FIFOread2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)GUI_User_V1_3_P.FIFOread2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)GUI_User_V1_3_P.FIFOread2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)GUI_User_V1_3_P.FIFOread2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)GUI_User_V1_3_P.FIFOread2_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)GUI_User_V1_3_P.FIFOread2_P8_Size);
      }

      /* registration */
      fiforead(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, -1.0);
      ssSetOffsetTime(rts, 0, -2.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: GUI_User_V1_3/<S6>/MM-16-AT Analog Input (addiamondmm16atcustom) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, GUI_User_V1_3_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 12);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &GUI_User_V1_3_B.MM16ATAnalogInput_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &GUI_User_V1_3_B.MM16ATAnalogInput_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &GUI_User_V1_3_B.MM16ATAnalogInput_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &GUI_User_V1_3_B.MM16ATAnalogInput_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &GUI_User_V1_3_B.MM16ATAnalogInput_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &GUI_User_V1_3_B.MM16ATAnalogInput_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &GUI_User_V1_3_B.MM16ATAnalogInput_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &GUI_User_V1_3_B.MM16ATAnalogInput_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((real_T *)
            &GUI_User_V1_3_B.MM16ATAnalogInput_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((real_T *)
            &GUI_User_V1_3_B.MM16ATAnalogInput_o10));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((real_T *)
            &GUI_User_V1_3_B.MM16ATAnalogInput_o11));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((real_T *)
            &GUI_User_V1_3_B.MM16ATAnalogInput_o12));
        }
      }

      /* path info */
      ssSetModelName(rts, "MM-16-AT Analog Input");
      ssSetPath(rts, "GUI_User_V1_3/SG-ADC Sensors/MM-16-AT Analog Input");
      ssSetRTModel(rts,GUI_User_V1_3_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       GUI_User_V1_3_P.MM16ATAnalogInput_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       GUI_User_V1_3_P.MM16ATAnalogInput_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       GUI_User_V1_3_P.MM16ATAnalogInput_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       GUI_User_V1_3_P.MM16ATAnalogInput_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       GUI_User_V1_3_P.MM16ATAnalogInput_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &GUI_User_V1_3_DWork.MM16ATAnalogInput_RWORK[0]);
      ssSetIWork(rts, (int_T *) &GUI_User_V1_3_DWork.MM16ATAnalogInput_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &GUI_User_V1_3_DWork.MM16ATAnalogInput_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &GUI_User_V1_3_DWork.MM16ATAnalogInput_IWORK);
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
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortConnected(rts, 9, 1);
      _ssSetOutputPortConnected(rts, 10, 1);
      _ssSetOutputPortConnected(rts, 11, 1);
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

    /* Level2 S-Function Block: GUI_User_V1_3/<S5>/ASCII Encode  (asciiencode) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, GUI_User_V1_3_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.statesInfo2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 6);
        ssSetPortInfoForInputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &GUI_User_V1_3_B.Merge_l;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] = &GUI_User_V1_3_B.Merge1;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.UPtrs2;
          sfcnUPtrs[0] = &GUI_User_V1_3_B.Merge2;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.UPtrs3;
          sfcnUPtrs[0] = &GUI_User_V1_3_B.Merge3;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.UPtrs4;
          sfcnUPtrs[0] = &GUI_User_V1_3_B.Merge4;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.UPtrs5;
          sfcnUPtrs[0] = &GUI_User_V1_3_B.Merge5;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 9);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) GUI_User_V1_3_B.ASCIIEncode));
        }
      }

      /* path info */
      ssSetModelName(rts, "ASCII Encode ");
      ssSetPath(rts, "GUI_User_V1_3/Motors - F4  STM - PWM/ASCII Encode ");
      ssSetRTModel(rts,GUI_User_V1_3_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GUI_User_V1_3_P.ASCIIEncode_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GUI_User_V1_3_P.ASCIIEncode_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)GUI_User_V1_3_P.ASCIIEncode_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)GUI_User_V1_3_P.ASCIIEncode_P4_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &GUI_User_V1_3_DWork.ASCIIEncode_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &GUI_User_V1_3_DWork.ASCIIEncode_PWORK);
      }

      /* registration */
      asciiencode(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetInputPortConnected(rts, 4, 1);
      _ssSetInputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
      ssSetInputPortBufferDstPort(rts, 4, -1);
      ssSetInputPortBufferDstPort(rts, 5, -1);
    }

    /* Level2 S-Function Block: GUI_User_V1_3/<S24>/FIFO write 1 (fifowrite) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, GUI_User_V1_3_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, GUI_User_V1_3_B.ASCIIEncode);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 9);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((serialfifoptr *)
            &GUI_User_V1_3_B.FIFOwrite1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((boolean_T *)
            &GUI_User_V1_3_B.FIFOwrite1_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO write 1");
      ssSetPath(rts,
                "GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1");
      ssSetRTModel(rts,GUI_User_V1_3_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GUI_User_V1_3_P.FIFOwrite1_P1_Size_j);
        ssSetSFcnParam(rts, 1, (mxArray*)GUI_User_V1_3_P.FIFOwrite1_P2_Size_b);
        ssSetSFcnParam(rts, 2, (mxArray*)GUI_User_V1_3_P.FIFOwrite1_P3_Size_f);
        ssSetSFcnParam(rts, 3, (mxArray*)GUI_User_V1_3_P.FIFOwrite1_P4_Size_o);
        ssSetSFcnParam(rts, 4, (mxArray*)GUI_User_V1_3_P.FIFOwrite1_P5_Size_f);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &GUI_User_V1_3_DWork.FIFOwrite1_IWORK[0]);
      ssSetPWork(rts, (void **) &GUI_User_V1_3_DWork.FIFOwrite1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &GUI_User_V1_3_DWork.FIFOwrite1_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &GUI_User_V1_3_DWork.FIFOwrite1_PWORK);
      }

      /* registration */
      fifowrite(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 9);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: GUI_User_V1_3/<S24>/FIFO write 2 (fifowrite) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, GUI_User_V1_3_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.statesInfo2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, (uint8_T*)&GUI_User_V1_3_U8GND);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((serialfifoptr *)
            &GUI_User_V1_3_B.FIFOwrite2_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((boolean_T *)
            &GUI_User_V1_3_B.FIFOwrite2_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO write 2");
      ssSetPath(rts,
                "GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2");
      ssSetRTModel(rts,GUI_User_V1_3_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GUI_User_V1_3_P.FIFOwrite2_P1_Size_j);
        ssSetSFcnParam(rts, 1, (mxArray*)GUI_User_V1_3_P.FIFOwrite2_P2_Size_a);
        ssSetSFcnParam(rts, 2, (mxArray*)GUI_User_V1_3_P.FIFOwrite2_P3_Size_e);
        ssSetSFcnParam(rts, 3, (mxArray*)GUI_User_V1_3_P.FIFOwrite2_P4_Size_d);
        ssSetSFcnParam(rts, 4, (mxArray*)GUI_User_V1_3_P.FIFOwrite2_P5_Size_d);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &GUI_User_V1_3_DWork.FIFOwrite2_IWORK[0]);
      ssSetPWork(rts, (void **) &GUI_User_V1_3_DWork.FIFOwrite2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &GUI_User_V1_3_DWork.FIFOwrite2_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &GUI_User_V1_3_DWork.FIFOwrite2_PWORK);
      }

      /* registration */
      fifowrite(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: GUI_User_V1_3/<S24>/FIFO read 1 (fiforead) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.blkInfo2[9]);
      }

      ssSetRTWSfcnInfo(rts, GUI_User_V1_3_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods2[9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods3[9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.statesInfo2[9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn9.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &GUI_User_V1_3_B.RateTransition1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1025);
          ssSetOutputPortSignal(rts, 0, ((uint16_T *) GUI_User_V1_3_B.FIFOread1));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO read 1");
      ssSetPath(rts,
                "GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1");
      ssSetRTModel(rts,GUI_User_V1_3_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GUI_User_V1_3_P.FIFOread1_P1_Size_n);
        ssSetSFcnParam(rts, 1, (mxArray*)GUI_User_V1_3_P.FIFOread1_P2_Size_i);
        ssSetSFcnParam(rts, 2, (mxArray*)GUI_User_V1_3_P.FIFOread1_P3_Size_l);
        ssSetSFcnParam(rts, 3, (mxArray*)GUI_User_V1_3_P.FIFOread1_P4_Size_c);
        ssSetSFcnParam(rts, 4, (mxArray*)GUI_User_V1_3_P.FIFOread1_P5_Size_b);
        ssSetSFcnParam(rts, 5, (mxArray*)GUI_User_V1_3_P.FIFOread1_P6_Size_g);
        ssSetSFcnParam(rts, 6, (mxArray*)GUI_User_V1_3_P.FIFOread1_P7_Size_b);
        ssSetSFcnParam(rts, 7, (mxArray*)GUI_User_V1_3_P.FIFOread1_P8_Size_p);
      }

      /* registration */
      fiforead(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: GUI_User_V1_3/<S24>/FIFO read 2 (fiforead) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.blkInfo2[10]);
      }

      ssSetRTWSfcnInfo(rts, GUI_User_V1_3_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods2[10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods3[10]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.statesInfo2[10]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn10.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &GUI_User_V1_3_B.RateTransition3);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1025);
          ssSetOutputPortSignal(rts, 0, ((uint16_T *) GUI_User_V1_3_B.FIFOread2));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO read 2");
      ssSetPath(rts,
                "GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2");
      ssSetRTModel(rts,GUI_User_V1_3_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GUI_User_V1_3_P.FIFOread2_P1_Size_d);
        ssSetSFcnParam(rts, 1, (mxArray*)GUI_User_V1_3_P.FIFOread2_P2_Size_g);
        ssSetSFcnParam(rts, 2, (mxArray*)GUI_User_V1_3_P.FIFOread2_P3_Size_f);
        ssSetSFcnParam(rts, 3, (mxArray*)GUI_User_V1_3_P.FIFOread2_P4_Size_e);
        ssSetSFcnParam(rts, 4, (mxArray*)GUI_User_V1_3_P.FIFOread2_P5_Size_d);
        ssSetSFcnParam(rts, 5, (mxArray*)GUI_User_V1_3_P.FIFOread2_P6_Size_p);
        ssSetSFcnParam(rts, 6, (mxArray*)GUI_User_V1_3_P.FIFOread2_P7_Size_n);
        ssSetSFcnParam(rts, 7, (mxArray*)GUI_User_V1_3_P.FIFOread2_P8_Size_k);
      }

      /* registration */
      fiforead(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: GUI_User_V1_3/<S24>/Setup1 (sersetupbase) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.blkInfo2[11]);
      }

      ssSetRTWSfcnInfo(rts, GUI_User_V1_3_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods2[11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods3[11]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.statesInfo2[11]);
      }

      /* path info */
      ssSetModelName(rts, "Setup1");
      ssSetPath(rts,
                "GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/Setup1");
      ssSetRTModel(rts,GUI_User_V1_3_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GUI_User_V1_3_P.Setup1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GUI_User_V1_3_P.Setup1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)GUI_User_V1_3_P.Setup1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)GUI_User_V1_3_P.Setup1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)GUI_User_V1_3_P.Setup1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)GUI_User_V1_3_P.Setup1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)GUI_User_V1_3_P.Setup1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)GUI_User_V1_3_P.Setup1_P8_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &GUI_User_V1_3_DWork.Setup1_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn11.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn11.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &GUI_User_V1_3_DWork.Setup1_IWORK[0]);
      }

      /* registration */
      sersetupbase(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: GUI_User_V1_3/<S24>/Setup2 (sersetupbase) */
    {
      SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.blkInfo2[12]);
      }

      ssSetRTWSfcnInfo(rts, GUI_User_V1_3_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods2[12]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.methods3[12]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GUI_User_V1_3_rtM->NonInlinedSFcns.statesInfo2[12]);
      }

      /* path info */
      ssSetModelName(rts, "Setup2");
      ssSetPath(rts,
                "GUI_User_V1_3/Motors - F4  STM - PWM/Baseboard Serial1/Setup2");
      ssSetRTModel(rts,GUI_User_V1_3_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GUI_User_V1_3_P.Setup2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GUI_User_V1_3_P.Setup2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)GUI_User_V1_3_P.Setup2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)GUI_User_V1_3_P.Setup2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)GUI_User_V1_3_P.Setup2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)GUI_User_V1_3_P.Setup2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)GUI_User_V1_3_P.Setup2_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)GUI_User_V1_3_P.Setup2_P8_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &GUI_User_V1_3_DWork.Setup2_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn12.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &GUI_User_V1_3_rtM->NonInlinedSFcns.Sfcn12.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &GUI_User_V1_3_DWork.Setup2_IWORK[0]);
      }

      /* registration */
      sersetupbase(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }
  }
}

/* Model terminate function */
void GUI_User_V1_3_terminate(void)
{
  /* user code (Terminate function Header) */

  /* Stop first, then deregister, else the board could interrupt
   * after deregistering and before the stop.
   */
  /* disable interrupt for IRQ 4 */
  xpceDeRegisterISR( &xpcDev_1 );

  /* Level2 S-Function Block: '<S6>/MM-16-AT Analog Input' (addiamondmm16atcustom) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for IfAction SubSystem: '<Root>/If Action Subsystem6' */

  /* Level2 S-Function Block: '<S17>/From File1' (xpcfromfile) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<Root>/If Action Subsystem6' */

  /* Level2 S-Function Block: '<S5>/ASCII Encode ' (asciiencode) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S24>/FIFO write 1' (fifowrite) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S24>/FIFO write 2' (fifowrite) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S24>/FIFO read 1' (fiforead) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S24>/FIFO read 2' (fiforead) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S24>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S24>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[12];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  GUI_User_V1_3_output(tid);
}

void MdlUpdate(int_T tid)
{
  GUI_User_V1_3_update(tid);
}

void MdlInitializeSizes(void)
{
  GUI_User_V1_3_rtM->Sizes.numContStates = (0);/* Number of continuous states */
  GUI_User_V1_3_rtM->Sizes.numY = (0); /* Number of model outputs */
  GUI_User_V1_3_rtM->Sizes.numU = (0); /* Number of model inputs */
  GUI_User_V1_3_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  GUI_User_V1_3_rtM->Sizes.numSampTimes = (1);/* Number of sample times */
  GUI_User_V1_3_rtM->Sizes.numBlocks = (358);/* Number of blocks */
  GUI_User_V1_3_rtM->Sizes.numBlockIO = (296);/* Number of block outputs */
  GUI_User_V1_3_rtM->Sizes.numBlockPrms = (798);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  {
    int32_T i;

    /* user code (Initialize function Body) */
    {
      uint8_T irq = 4;

      /* For an ISA board, save the given address in the struct. */
      xpcDev_1.BaseAddress[0] = 0;

      /* connect ISR system: IRQ 4 */
      if (xpceRegisterISR( irq, xPCISR1,
                          NULL,
                          NULL, 0,
                          &xpcDev_1) == -1) {
        static uint8_T ermsg[100];
        sprintf( ermsg,
                "ISR registration failed for Interrupt %d ISA board at 0." );
        rtmSetErrorStatus(GUI_User_V1_3_rtM, ermsg);
        return;
      }
    }

    GUI_User_V1_3_rtM->Timing.rtmDbBufReadBuf1 = 0xFF;
    GUI_User_V1_3_rtM->Timing.rtmDbBufWriteBuf1 = 0xFF;
    GUI_User_V1_3_rtM->Timing.rtmDbBufLastBufWr1 = 0;

    /* InitializeConditions for DiscreteStateSpace: '<S42>/Discrete State-Space5' */
    GUI_User_V1_3_DWork.DiscreteStateSpace5_DSTATE[0] =
      GUI_User_V1_3_P.DiscreteStateSpace5_X0[0];
    GUI_User_V1_3_DWork.DiscreteStateSpace5_DSTATE[1] =
      GUI_User_V1_3_P.DiscreteStateSpace5_X0[1];

    /* InitializeConditions for DiscreteStateSpace: '<S42>/Discrete State-Space4' */
    GUI_User_V1_3_DWork.DiscreteStateSpace4_DSTATE[0] =
      GUI_User_V1_3_P.DiscreteStateSpace4_X0[0];
    GUI_User_V1_3_DWork.DiscreteStateSpace4_DSTATE[1] =
      GUI_User_V1_3_P.DiscreteStateSpace4_X0[1];

    /* InitializeConditions for DiscreteStateSpace: '<S42>/Discrete State-Space3' */
    GUI_User_V1_3_DWork.DiscreteStateSpace3_DSTATE[0] =
      GUI_User_V1_3_P.DiscreteStateSpace3_X0[0];
    GUI_User_V1_3_DWork.DiscreteStateSpace3_DSTATE[1] =
      GUI_User_V1_3_P.DiscreteStateSpace3_X0[1];

    /* InitializeConditions for DiscreteStateSpace: '<S42>/Discrete State-Space2' */
    GUI_User_V1_3_DWork.DiscreteStateSpace2_DSTATE[0] =
      GUI_User_V1_3_P.DiscreteStateSpace2_X0[0];
    GUI_User_V1_3_DWork.DiscreteStateSpace2_DSTATE[1] =
      GUI_User_V1_3_P.DiscreteStateSpace2_X0[1];

    /* InitializeConditions for DiscreteStateSpace: '<S42>/Discrete State-Space1' */
    GUI_User_V1_3_DWork.DiscreteStateSpace1_DSTATE[0] =
      GUI_User_V1_3_P.DiscreteStateSpace1_X0[0];
    GUI_User_V1_3_DWork.DiscreteStateSpace1_DSTATE[1] =
      GUI_User_V1_3_P.DiscreteStateSpace1_X0[1];

    /* InitializeConditions for DiscreteStateSpace: '<S42>/Discrete State-Space6' */
    GUI_User_V1_3_DWork.DiscreteStateSpace6_DSTATE[0] =
      GUI_User_V1_3_P.DiscreteStateSpace6_X0[0];
    GUI_User_V1_3_DWork.DiscreteStateSpace6_DSTATE[1] =
      GUI_User_V1_3_P.DiscreteStateSpace6_X0[1];

    /* InitializeConditions for Merge: '<Root>/Merge' */
    if (rtmIsFirstInitCond(GUI_User_V1_3_rtM)) {
      for (i = 0; i < 6; i++) {
        GUI_User_V1_3_B.Merge[i] = GUI_User_V1_3_P.Merge_InitialOutput[i];
      }
    }

    /* End of Merge: '<Root>/Merge' */

    /* user code (Initialize function Trailer) */
    xpcOutpB( 0xA0, 0x20 );
    xpcOutpB( 0x20, 0x20 );

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(GUI_User_V1_3_rtM)) {
      rtmSetFirstInitCond(GUI_User_V1_3_rtM, 0);
    }
  }
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<S6>/MM-16-AT Analog Input' (addiamondmm16atcustom) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for If: '<Root>/If' */
  GUI_User_V1_3_DWork.If_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<Root>/If Action Subsystem' */
  /* VirtualOutportStart for Outport: '<S1>/Control Signals Set to 0' */
  GUI_User_V1_3_B.Merge[0] = GUI_User_V1_3_P.ControlSignalsSetto0_Y0[0];
  GUI_User_V1_3_B.Merge[1] = GUI_User_V1_3_P.ControlSignalsSetto0_Y0[1];
  GUI_User_V1_3_B.Merge[2] = GUI_User_V1_3_P.ControlSignalsSetto0_Y0[2];
  GUI_User_V1_3_B.Merge[3] = GUI_User_V1_3_P.ControlSignalsSetto0_Y0[3];
  GUI_User_V1_3_B.Merge[4] = GUI_User_V1_3_P.ControlSignalsSetto0_Y0[4];
  GUI_User_V1_3_B.Merge[5] = GUI_User_V1_3_P.ControlSignalsSetto0_Y0[5];

  /* End of Start for SubSystem: '<Root>/If Action Subsystem' */

  /* Start for IfAction SubSystem: '<Root>/If Action Subsystem5' */
  /* InitializeConditions for DiscreteIntegrator: '<S11>/Integrator' */
  GUI_User_V1_3_DWork.Integrator_DSTATE_cb = GUI_User_V1_3_P.Integrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Filter' */
  GUI_User_V1_3_DWork.Filter_DSTATE_f = GUI_User_V1_3_P.Filter_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Integrator' */
  GUI_User_V1_3_DWork.Integrator_DSTATE_j = GUI_User_V1_3_P.Integrator_IC_e;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Filter' */
  GUI_User_V1_3_DWork.Filter_DSTATE_o = GUI_User_V1_3_P.Filter_IC_a;

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Integrator' */
  GUI_User_V1_3_DWork.Integrator_DSTATE_d = GUI_User_V1_3_P.Integrator_IC_n;

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Filter' */
  GUI_User_V1_3_DWork.Filter_DSTATE_mn = GUI_User_V1_3_P.Filter_IC_b;

  /* InitializeConditions for DiscreteIntegrator: '<S12>/Integrator' */
  GUI_User_V1_3_DWork.Integrator_DSTATE_k = GUI_User_V1_3_P.Integrator_IC_c;

  /* InitializeConditions for DiscreteIntegrator: '<S12>/Filter' */
  GUI_User_V1_3_DWork.Filter_DSTATE_mv = GUI_User_V1_3_P.Filter_IC_h;

  /* InitializeConditions for DiscreteIntegrator: '<S13>/Integrator' */
  GUI_User_V1_3_DWork.Integrator_DSTATE_mj = GUI_User_V1_3_P.Integrator_IC_g;

  /* InitializeConditions for DiscreteIntegrator: '<S13>/Filter' */
  GUI_User_V1_3_DWork.Filter_DSTATE_kq = GUI_User_V1_3_P.Filter_IC_i;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Integrator' */
  GUI_User_V1_3_DWork.Integrator_DSTATE_i = GUI_User_V1_3_P.Integrator_IC_d;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Filter' */
  GUI_User_V1_3_DWork.Filter_DSTATE_me = GUI_User_V1_3_P.Filter_IC_n;

  /* VirtualOutportStart for Outport: '<S3>/ControlSig' */
  GUI_User_V1_3_B.Merge[0] = GUI_User_V1_3_P.ControlSig_Y0[0];
  GUI_User_V1_3_B.Merge[1] = GUI_User_V1_3_P.ControlSig_Y0[1];
  GUI_User_V1_3_B.Merge[2] = GUI_User_V1_3_P.ControlSig_Y0[2];
  GUI_User_V1_3_B.Merge[3] = GUI_User_V1_3_P.ControlSig_Y0[3];
  GUI_User_V1_3_B.Merge[4] = GUI_User_V1_3_P.ControlSig_Y0[4];
  GUI_User_V1_3_B.Merge[5] = GUI_User_V1_3_P.ControlSig_Y0[5];

  /* End of Start for SubSystem: '<Root>/If Action Subsystem5' */

  /* Start for IfAction SubSystem: '<Root>/If Action Subsystem6' */

  /* Level2 S-Function Block: '<S17>/From File1' (xpcfromfile) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Integrator' */
  GUI_User_V1_3_DWork.Integrator_DSTATE = GUI_User_V1_3_P.Integrator_IC_f;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Filter' */
  GUI_User_V1_3_DWork.Filter_DSTATE = GUI_User_V1_3_P.Filter_IC_p;

  /* InitializeConditions for DiscreteIntegrator: '<S19>/Integrator' */
  GUI_User_V1_3_DWork.Integrator_DSTATE_m = GUI_User_V1_3_P.Integrator_IC_cd;

  /* InitializeConditions for DiscreteIntegrator: '<S19>/Filter' */
  GUI_User_V1_3_DWork.Filter_DSTATE_i = GUI_User_V1_3_P.Filter_IC_aa;

  /* InitializeConditions for DiscreteIntegrator: '<S21>/Integrator' */
  GUI_User_V1_3_DWork.Integrator_DSTATE_a = GUI_User_V1_3_P.Integrator_IC_db;

  /* InitializeConditions for DiscreteIntegrator: '<S21>/Filter' */
  GUI_User_V1_3_DWork.Filter_DSTATE_h = GUI_User_V1_3_P.Filter_IC_nf;

  /* InitializeConditions for DiscreteIntegrator: '<S22>/Integrator' */
  GUI_User_V1_3_DWork.Integrator_DSTATE_g = GUI_User_V1_3_P.Integrator_IC_dm;

  /* InitializeConditions for DiscreteIntegrator: '<S22>/Filter' */
  GUI_User_V1_3_DWork.Filter_DSTATE_k = GUI_User_V1_3_P.Filter_IC_m;

  /* InitializeConditions for DiscreteIntegrator: '<S23>/Integrator' */
  GUI_User_V1_3_DWork.Integrator_DSTATE_c = GUI_User_V1_3_P.Integrator_IC_k;

  /* InitializeConditions for DiscreteIntegrator: '<S23>/Filter' */
  GUI_User_V1_3_DWork.Filter_DSTATE_n = GUI_User_V1_3_P.Filter_IC_nc;

  /* InitializeConditions for DiscreteIntegrator: '<S20>/Integrator' */
  GUI_User_V1_3_DWork.Integrator_DSTATE_l = GUI_User_V1_3_P.Integrator_IC_dv;

  /* InitializeConditions for DiscreteIntegrator: '<S20>/Filter' */
  GUI_User_V1_3_DWork.Filter_DSTATE_m = GUI_User_V1_3_P.Filter_IC_o;

  /* VirtualOutportStart for Outport: '<S4>/Control signal' */
  GUI_User_V1_3_B.Merge[0] = GUI_User_V1_3_P.Controlsignal_Y0[0];
  GUI_User_V1_3_B.Merge[1] = GUI_User_V1_3_P.Controlsignal_Y0[1];
  GUI_User_V1_3_B.Merge[2] = GUI_User_V1_3_P.Controlsignal_Y0[2];
  GUI_User_V1_3_B.Merge[3] = GUI_User_V1_3_P.Controlsignal_Y0[3];
  GUI_User_V1_3_B.Merge[4] = GUI_User_V1_3_P.Controlsignal_Y0[4];
  GUI_User_V1_3_B.Merge[5] = GUI_User_V1_3_P.Controlsignal_Y0[5];

  /* VirtualOutportStart for Outport: '<S4>/ReferenceTrayectory' */
  memcpy((void *)(&GUI_User_V1_3_B.Unpack1[0]), (void *)
         GUI_User_V1_3_P.ReferenceTrayectory_Y0, 12U * sizeof(real_T));

  /* End of Start for SubSystem: '<Root>/If Action Subsystem6' */

  /* Start for IfAction SubSystem: '<Root>/If Action Subsystem2' */
  /* VirtualOutportStart for Outport: '<S2>/Control Signals' */
  GUI_User_V1_3_B.Merge[0] = GUI_User_V1_3_P.ControlSignals_Y0[0];
  GUI_User_V1_3_B.Merge[1] = GUI_User_V1_3_P.ControlSignals_Y0[1];
  GUI_User_V1_3_B.Merge[2] = GUI_User_V1_3_P.ControlSignals_Y0[2];
  GUI_User_V1_3_B.Merge[3] = GUI_User_V1_3_P.ControlSignals_Y0[3];
  GUI_User_V1_3_B.Merge[4] = GUI_User_V1_3_P.ControlSignals_Y0[4];
  GUI_User_V1_3_B.Merge[5] = GUI_User_V1_3_P.ControlSignals_Y0[5];

  /* End of Start for SubSystem: '<Root>/If Action Subsystem2' */

  /* Level2 S-Function Block: '<S5>/ASCII Encode ' (asciiencode) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S24>/FIFO write 1' (fifowrite) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S24>/FIFO write 2' (fifowrite) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (xpcinterrupt): '<S24>/IRQ Source' */
  GUI_User_V1_3_RS232ISR_Start();

  /* Level2 S-Function Block: '<S24>/FIFO read 1' (fiforead) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S24>/FIFO read 2' (fiforead) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S24>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[11];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S24>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = GUI_User_V1_3_rtM->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  GUI_User_V1_3_terminate();
}

rtModel_GUI_User_V1_3 *GUI_User_V1_3(void)
{
  GUI_User_V1_3_initialize(1);
  return GUI_User_V1_3_rtM;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
