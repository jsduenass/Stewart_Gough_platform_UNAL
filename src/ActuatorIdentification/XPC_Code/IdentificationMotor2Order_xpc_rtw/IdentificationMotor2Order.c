/*
 * IdentificationMotor2Order.c
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

#include "rt_logging_mmi.h"
#include "IdentificationMotor2Order_capi.h"
#include "IdentificationMotor2Order.h"
#include "IdentificationMotor2Order_private.h"
#include <stdio.h>
#include "IdentificationMotor2Order_dt.h"

const uint8_T IdentificationMotor2Order_U8GND = 0U;/* uint8_T ground */

/* Block signals (auto storage) */
BlockIO_IdentificationMotor2Order IdentificationMotor2Order_B;

/* Block states (auto storage) */
D_Work_IdentificationMotor2Order IdentificationMotor2Order_DWork;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_IdentificationMotor2Order IdentificationMotor2Order_Y;

/* Real-time model */
rtModel_IdentificationMotor2Order IdentificationMotor2Order_rtM_;
rtModel_IdentificationMotor2Order *const IdentificationMotor2Order_rtM =
  &IdentificationMotor2Order_rtM_;

/* xPC Target Async Interrupt Block '<S3>/IRQ Source' */
void xPCISR1(void)
{
  {
    /* RTWBLOCK_START_COMMENT */
    /* RTWBLOCK_START_COMMENT */
    /* RTWBLOCK_START_COMMENT */
    /* RTWBLOCK_START_COMMENT */
    /* Reset subsysRan breadcrumbs */
    srClearBC(IdentificationMotor2Order_DWork.Receive1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(IdentificationMotor2Order_DWork.Transmit1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(IdentificationMotor2Order_DWork.Receive2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(IdentificationMotor2Order_DWork.Transmit2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(IdentificationMotor2Order_DWork.RS232ISR_SubsysRanBC);

    /* RateTransition: '<S3>/Rate Transition' */
    /* RTWBLOCK_START_COMMENT */
    IdentificationMotor2Order_B.RateTransition =
      IdentificationMotor2Order_B.FIFOwrite1_o1;

    /* RateTransition: '<S3>/Rate Transition2' */
    IdentificationMotor2Order_B.RateTransition2 =
      IdentificationMotor2Order_B.FIFOwrite2_o1;
    IdentificationMotor2Or_RS232ISR(0);
  }
}

/* Start for function-call system: '<S3>/RS232 ISR' */
void IdentificationMo_RS232ISR_Start(void)
{
  /* Start for function-call system: '<S16>/Receive 1' */

  /* S-Function Block: <S17>/Read HW FIFO1 (serreadbase) */
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
        rtmSetErrorStatus(IdentificationMotor2Order_rtM, msg);
        return;
      }
    }
  }

  /* Level2 S-Function Block: '<S17>/FIFO write 1' (fifowrite) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for function-call system: '<S16>/Transmit 1' */

  /* Level2 S-Function Block: '<S19>/FIFO read 1' (fiforead) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for function-call system: '<S16>/Receive 2' */

  /* Level2 S-Function Block: '<S18>/FIFO write 2' (fifowrite) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for function-call system: '<S16>/Transmit 2' */

  /* Level2 S-Function Block: '<S20>/FIFO read 2' (fiforead) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Output and update for function-call system: '<S3>/RS232 ISR' */
void IdentificationMotor2Or_RS232ISR(int_T controlPortIdx)
{
  /* S-Function Block: <S16>/Read Int Status FC1 (iquerybase) */
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
      *&IdentificationMotor2Order_B.ReadIntStatusFC1_o2 = max;
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
            /* Output and update for function-call system: '<S16>/Receive 1' */

            /* S-Function (serreadbase): '<S17>/Read HW FIFO1' */
            {
              /* S-Function Block: <S17>/Read HW FIFO1 (serreadbase) */
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
                ((int_T *)IdentificationMotor2Order_B.ReadHWFIFO1)[count] =
                  (masked << 8) | c;
              }

              ((int_T *)IdentificationMotor2Order_B.ReadHWFIFO1)[0] = count;
            }

            /* Level2 S-Function Block: '<S17>/FIFO write 1' (fifowrite) */
            {
              SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[0];
              sfcnOutputs(rts, 1);
            }

            IdentificationMotor2Order_DWork.Receive1_SubsysRanBC = 4;
            break;
          }
          break;

         case 2:                       // Transmitter holding register empty
          //printf("%1xb", base[i]>>8);
          switch (port)
          {
           case 0:
            /* Output and update for function-call system: '<S16>/Transmit 1' */

            /* Level2 S-Function Block: '<S19>/FIFO read 1' (fiforead) */
            {
              SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[1];
              sfcnOutputs(rts, 1);
            }

            /* S-Function (serwritebase): '<S19>/Write HW FIFO1' */
            {
              /* S-Function Block: <S19>/Write HW FIFO1 (serwritebase) */
              int_T *IPtr = (int_T *)IdentificationMotor2Order_B.FIFOread1_o1;
              if (IdentificationMotor2Order_B.FIFOread1_o2 > 0 ) {
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
                  rtmSetErrorStatus(IdentificationMotor2Order_rtM,
                                    "Attempted write to hardware fifo that isn't empty");
                  return;
                }
              }
            }

            IdentificationMotor2Order_DWork.Transmit1_SubsysRanBC = 4;
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

  IdentificationMotor2Order_DWork.RS232ISR_SubsysRanBC = 4;
}

/*
 * Output and update for action system:
 *    '<S1>/If Action Subsystem'
 *    '<S1>/If Action Subsystem2'
 *    '<S1>/If Action Subsystem4'
 *    '<S1>/If Action Subsystem6'
 *    '<S1>/If Action Subsystem8'
 *    '<S1>/If Action Subsystem10'
 */
void Identificatio_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1,
  rtB_IfActionSubsystem_Identific *localB, rtP_IfActionSubsystem_Identific
  *localP)
{
  /* Sum: '<S4>/Sum' incorporates:
   *  Constant: '<S4>/Constant8'
   */
  localB->Sum = rtu_In1 + localP->Constant8_Value;

  /* Rounding: '<S4>/Rounding Function' */
  (*rty_Out1) = ceil(localB->Sum);
}

/*
 * Output and update for action system:
 *    '<S1>/If Action Subsystem1'
 *    '<S1>/If Action Subsystem3'
 *    '<S1>/If Action Subsystem5'
 *    '<S1>/If Action Subsystem7'
 *    '<S1>/If Action Subsystem9'
 *    '<S1>/If Action Subsystem11'
 */
void Identificati_IfActionSubsystem1(real_T rtu_In1, real_T *rty_Out1,
  rtB_IfActionSubsystem1_Identifi *localB, rtP_IfActionSubsystem1_Identifi
  *localP)
{
  /* Gain: '<S5>/Gain' */
  localB->Gain = localP->Gain_Gain * rtu_In1;

  /* Sum: '<S5>/Sum' incorporates:
   *  Constant: '<S5>/Constant8'
   */
  localB->Sum = localB->Gain + localP->Constant8_Value;

  /* Rounding: '<S5>/Rounding Function' */
  (*rty_Out1) = ceil(localB->Sum);
}

/* Model output function */
void IdentificationMotor2Order_output(int_T tid)
{
  real_T u;
  real_T u_0;
  real_T u_1;

  /* RTWBLOCK_START_COMMENT */
  /* Reset subsysRan breadcrumbs */
  srClearBC
    (IdentificationMotor2Order_DWork.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (IdentificationMotor2Order_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);

  /* RTWBLOCK_START_COMMENT */

  /* Level2 S-Function Block: '<S2>/MM-16-AT Analog Input' (addiamondmm16atcustom) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[4];
    sfcnOutputs(rts, 0);
  }

  /* DiscreteStateSpace: '<S21>/Discrete State-Space6' */
  {
    IdentificationMotor2Order_B.DiscreteStateSpace6 =
      (IdentificationMotor2Order_P.DiscreteStateSpace6_C[0])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace6_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace6_C[1])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace6_DSTATE[1];
    IdentificationMotor2Order_B.DiscreteStateSpace6 +=
      IdentificationMotor2Order_P.DiscreteStateSpace6_D*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o1;
  }

  /* Gain: '<S21>/Gain' */
  IdentificationMotor2Order_B.Gain = IdentificationMotor2Order_P.Gain_Gain *
    IdentificationMotor2Order_B.DiscreteStateSpace6;

  /* Sum: '<S21>/Sum1' incorporates:
   *  Constant: '<S21>/Constant2'
   */
  IdentificationMotor2Order_B.Sum1 = IdentificationMotor2Order_B.Gain +
    IdentificationMotor2Order_P.Constant2_Value;

  /* DiscreteStateSpace: '<S21>/Discrete State-Space1' */
  {
    IdentificationMotor2Order_B.DiscreteStateSpace1 =
      (IdentificationMotor2Order_P.DiscreteStateSpace1_C[0])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace1_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace1_C[1])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace1_DSTATE[1];
    IdentificationMotor2Order_B.DiscreteStateSpace1 +=
      IdentificationMotor2Order_P.DiscreteStateSpace1_D*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o3;
  }

  /* Gain: '<S21>/Gain1' */
  IdentificationMotor2Order_B.Gain1 = IdentificationMotor2Order_P.Gain1_Gain *
    IdentificationMotor2Order_B.DiscreteStateSpace1;

  /* Sum: '<S21>/Sum2' incorporates:
   *  Constant: '<S21>/Constant1'
   */
  IdentificationMotor2Order_B.Sum2 = IdentificationMotor2Order_B.Gain1 +
    IdentificationMotor2Order_P.Constant1_Value;

  /* DiscreteStateSpace: '<S21>/Discrete State-Space2' */
  {
    IdentificationMotor2Order_B.DiscreteStateSpace2 =
      (IdentificationMotor2Order_P.DiscreteStateSpace2_C[0])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace2_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace2_C[1])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace2_DSTATE[1];
    IdentificationMotor2Order_B.DiscreteStateSpace2 +=
      IdentificationMotor2Order_P.DiscreteStateSpace2_D*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o5;
  }

  /* Gain: '<S21>/Gain8' */
  IdentificationMotor2Order_B.Gain8 = IdentificationMotor2Order_P.Gain8_Gain *
    IdentificationMotor2Order_B.DiscreteStateSpace2;

  /* Sum: '<S21>/Sum3' incorporates:
   *  Constant: '<S21>/Constant3'
   */
  IdentificationMotor2Order_B.Sum3 = IdentificationMotor2Order_B.Gain8 +
    IdentificationMotor2Order_P.Constant3_Value;

  /* DiscreteStateSpace: '<S21>/Discrete State-Space3' */
  {
    IdentificationMotor2Order_B.DiscreteStateSpace3 =
      (IdentificationMotor2Order_P.DiscreteStateSpace3_C[0])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace3_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace3_C[1])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace3_DSTATE[1];
    IdentificationMotor2Order_B.DiscreteStateSpace3 +=
      IdentificationMotor2Order_P.DiscreteStateSpace3_D*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o7;
  }

  /* Gain: '<S21>/Gain9' */
  IdentificationMotor2Order_B.Gain9 = IdentificationMotor2Order_P.Gain9_Gain *
    IdentificationMotor2Order_B.DiscreteStateSpace3;

  /* Sum: '<S21>/Sum4' incorporates:
   *  Constant: '<S21>/Constant4'
   */
  IdentificationMotor2Order_B.Sum4 = IdentificationMotor2Order_B.Gain9 +
    IdentificationMotor2Order_P.Constant4_Value;

  /* DiscreteStateSpace: '<S21>/Discrete State-Space4' */
  {
    IdentificationMotor2Order_B.DiscreteStateSpace4 =
      (IdentificationMotor2Order_P.DiscreteStateSpace4_C[0])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace4_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace4_C[1])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace4_DSTATE[1];
    IdentificationMotor2Order_B.DiscreteStateSpace4 +=
      IdentificationMotor2Order_P.DiscreteStateSpace4_D*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o9;
  }

  /* Gain: '<S21>/Gain10' */
  IdentificationMotor2Order_B.Gain10 = IdentificationMotor2Order_P.Gain10_Gain *
    IdentificationMotor2Order_B.DiscreteStateSpace4;

  /* Sum: '<S21>/Sum5' incorporates:
   *  Constant: '<S21>/Constant5'
   */
  IdentificationMotor2Order_B.Sum5 = IdentificationMotor2Order_B.Gain10 +
    IdentificationMotor2Order_P.Constant5_Value;

  /* DiscreteStateSpace: '<S21>/Discrete State-Space5' */
  {
    IdentificationMotor2Order_B.DiscreteStateSpace5 =
      (IdentificationMotor2Order_P.DiscreteStateSpace5_C[0])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace5_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace5_C[1])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace5_DSTATE[1];
    IdentificationMotor2Order_B.DiscreteStateSpace5 +=
      IdentificationMotor2Order_P.DiscreteStateSpace5_D*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o11;
  }

  /* Gain: '<S21>/Gain11' */
  IdentificationMotor2Order_B.Gain11 = IdentificationMotor2Order_P.Gain11_Gain *
    IdentificationMotor2Order_B.DiscreteStateSpace5;

  /* Sum: '<S21>/Sum6' incorporates:
   *  Constant: '<S21>/Constant6'
   */
  IdentificationMotor2Order_B.Sum6 = IdentificationMotor2Order_B.Gain11 +
    IdentificationMotor2Order_P.Constant6_Value;

  /* Outport: '<Root>/Out1' */
  IdentificationMotor2Order_Y.Out1[0] = IdentificationMotor2Order_B.Sum1;
  IdentificationMotor2Order_Y.Out1[1] = IdentificationMotor2Order_B.Sum2;
  IdentificationMotor2Order_Y.Out1[2] = IdentificationMotor2Order_B.Sum3;
  IdentificationMotor2Order_Y.Out1[3] = IdentificationMotor2Order_B.Sum4;
  IdentificationMotor2Order_Y.Out1[4] = IdentificationMotor2Order_B.Sum5;
  IdentificationMotor2Order_Y.Out1[5] = IdentificationMotor2Order_B.Sum6;

  /* Gain: '<S21>/Gain2' */
  IdentificationMotor2Order_B.Gain2 = IdentificationMotor2Order_P.Gain2_Gain *
    IdentificationMotor2Order_B.MM16ATAnalogInput_o2;

  /* Gain: '<S21>/Gain3' */
  IdentificationMotor2Order_B.Gain3 = IdentificationMotor2Order_P.Gain3_Gain *
    IdentificationMotor2Order_B.MM16ATAnalogInput_o4;

  /* Gain: '<S21>/Gain4' */
  IdentificationMotor2Order_B.Gain4 = IdentificationMotor2Order_P.Gain4_Gain *
    IdentificationMotor2Order_B.MM16ATAnalogInput_o6;

  /* Gain: '<S21>/Gain5' */
  IdentificationMotor2Order_B.Gain5 = IdentificationMotor2Order_P.Gain5_Gain *
    IdentificationMotor2Order_B.MM16ATAnalogInput_o8;

  /* Gain: '<S21>/Gain6' */
  IdentificationMotor2Order_B.Gain6 = IdentificationMotor2Order_P.Gain6_Gain *
    IdentificationMotor2Order_B.MM16ATAnalogInput_o10;

  /* Gain: '<S21>/Gain7' */
  IdentificationMotor2Order_B.Gain7 = IdentificationMotor2Order_P.Gain7_Gain *
    IdentificationMotor2Order_B.MM16ATAnalogInput_o12;

  /* FromWorkspace: '<Root>/Velocity reference2' */
  {
    real_T *pDataValues = (real_T *)
      IdentificationMotor2Order_DWork.Velocityreference2_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      IdentificationMotor2Order_DWork.Velocityreference2_PWORK.TimePtr;
    int_T currTimeIndex =
      IdentificationMotor2Order_DWork.Velocityreference2_IWORK.PrevIndex;
    real_T t = IdentificationMotor2Order_rtM->Timing.t[0];
    if (t >= pTimeValues[399]) {
      IdentificationMotor2Order_B.Velocityreference2 = pDataValues[399];
    } else {
      /* get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[399]) {
        currTimeIndex = 398;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      IdentificationMotor2Order_DWork.Velocityreference2_IWORK.PrevIndex =
        currTimeIndex;

      /* post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            IdentificationMotor2Order_B.Velocityreference2 =
              pDataValues[currTimeIndex];
          } else {
            IdentificationMotor2Order_B.Velocityreference2 =
              pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex= currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          IdentificationMotor2Order_B.Velocityreference2 = (real_T)
            rtInterpolate(d1, d2, f1, f2);
          pDataValues += 400;
        }
      }
    }
  }

  /* Gain: '<Root>/Gain' */
  IdentificationMotor2Order_B.ControlSignal2 =
    IdentificationMotor2Order_P.Gain_Gain_b *
    IdentificationMotor2Order_B.Velocityreference2;

  /* Outport: '<Root>/Out2' */
  IdentificationMotor2Order_Y.Out2 = IdentificationMotor2Order_B.ControlSignal2;

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Constant: '<Root>/Constant'
   */
  u = IdentificationMotor2Order_P.Constant_Value;
  u_0 = IdentificationMotor2Order_P.Saturation_LowerSat;
  u_1 = IdentificationMotor2Order_P.Saturation_UpperSat;
  IdentificationMotor2Order_B.Saturation = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;

  /* If: '<S1>/If' */
  if ((IdentificationMotor2Order_B.Saturation >= 0.0) &&
      (IdentificationMotor2Order_B.Saturation <= 100.0)) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    Identificatio_IfActionSubsystem(IdentificationMotor2Order_B.Saturation,
      &IdentificationMotor2Order_B.Merge,
      &IdentificationMotor2Order_B.IfActionSubsystem,
      (rtP_IfActionSubsystem_Identific *)
      &IdentificationMotor2Order_P.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
  } else {
    if ((IdentificationMotor2Order_B.Saturation < 0.0) &&
        (IdentificationMotor2Order_B.Saturation >= -100.0)) {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      Identificati_IfActionSubsystem1(IdentificationMotor2Order_B.Saturation,
        &IdentificationMotor2Order_B.Merge,
        &IdentificationMotor2Order_B.IfActionSubsystem1,
        (rtP_IfActionSubsystem1_Identifi *)
        &IdentificationMotor2Order_P.IfActionSubsystem1);

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */
    }
  }

  /* End of If: '<S1>/If' */

  /* Saturate: '<S1>/Saturation1' */
  u = IdentificationMotor2Order_B.ControlSignal2;
  u_0 = IdentificationMotor2Order_P.Saturation1_LowerSat;
  u_1 = IdentificationMotor2Order_P.Saturation1_UpperSat;
  IdentificationMotor2Order_B.Saturation1 = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;

  /* If: '<S1>/If1' */
  if ((IdentificationMotor2Order_B.Saturation1 >= 0.0) &&
      (IdentificationMotor2Order_B.Saturation1 <= 100.0)) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    Identificatio_IfActionSubsystem(IdentificationMotor2Order_B.Saturation1,
      &IdentificationMotor2Order_B.Merge1,
      &IdentificationMotor2Order_B.IfActionSubsystem2,
      (rtP_IfActionSubsystem_Identific *)
      &IdentificationMotor2Order_P.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem2' */
  } else {
    if ((IdentificationMotor2Order_B.Saturation1 < 0.0) &&
        (IdentificationMotor2Order_B.Saturation1 >= -100.0)) {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      Identificati_IfActionSubsystem1(IdentificationMotor2Order_B.Saturation1,
        &IdentificationMotor2Order_B.Merge1,
        &IdentificationMotor2Order_B.IfActionSubsystem3,
        (rtP_IfActionSubsystem1_Identifi *)
        &IdentificationMotor2Order_P.IfActionSubsystem3);

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem3' */
    }
  }

  /* End of If: '<S1>/If1' */

  /* Saturate: '<S1>/Saturation2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  u = IdentificationMotor2Order_P.Constant1_Value_l;
  u_0 = IdentificationMotor2Order_P.Saturation2_LowerSat;
  u_1 = IdentificationMotor2Order_P.Saturation2_UpperSat;
  IdentificationMotor2Order_B.Saturation2 = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;

  /* If: '<S1>/If2' */
  if ((IdentificationMotor2Order_B.Saturation2 >= 0.0) &&
      (IdentificationMotor2Order_B.Saturation2 <= 100.0)) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    Identificatio_IfActionSubsystem(IdentificationMotor2Order_B.Saturation2,
      &IdentificationMotor2Order_B.Merge2,
      &IdentificationMotor2Order_B.IfActionSubsystem4,
      (rtP_IfActionSubsystem_Identific *)
      &IdentificationMotor2Order_P.IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem4' */
  } else {
    if ((IdentificationMotor2Order_B.Saturation2 < 0.0) &&
        (IdentificationMotor2Order_B.Saturation2 >= -100.0)) {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      Identificati_IfActionSubsystem1(IdentificationMotor2Order_B.Saturation2,
        &IdentificationMotor2Order_B.Merge2,
        &IdentificationMotor2Order_B.IfActionSubsystem5,
        (rtP_IfActionSubsystem1_Identifi *)
        &IdentificationMotor2Order_P.IfActionSubsystem5);

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem5' */
    }
  }

  /* End of If: '<S1>/If2' */

  /* Saturate: '<S1>/Saturation3' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  u = IdentificationMotor2Order_P.Constant2_Value_e;
  u_0 = IdentificationMotor2Order_P.Saturation3_LowerSat;
  u_1 = IdentificationMotor2Order_P.Saturation3_UpperSat;
  IdentificationMotor2Order_B.Saturation3 = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;

  /* If: '<S1>/If3' */
  if ((IdentificationMotor2Order_B.Saturation3 >= 0.0) &&
      (IdentificationMotor2Order_B.Saturation3 <= 100.0)) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    Identificatio_IfActionSubsystem(IdentificationMotor2Order_B.Saturation3,
      &IdentificationMotor2Order_B.Merge3,
      &IdentificationMotor2Order_B.IfActionSubsystem6,
      (rtP_IfActionSubsystem_Identific *)
      &IdentificationMotor2Order_P.IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem6' */
  } else {
    if ((IdentificationMotor2Order_B.Saturation3 < 0.0) &&
        (IdentificationMotor2Order_B.Saturation3 >= -100.0)) {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      Identificati_IfActionSubsystem1(IdentificationMotor2Order_B.Saturation3,
        &IdentificationMotor2Order_B.Merge3,
        &IdentificationMotor2Order_B.IfActionSubsystem7,
        (rtP_IfActionSubsystem1_Identifi *)
        &IdentificationMotor2Order_P.IfActionSubsystem7);

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem7' */
    }
  }

  /* End of If: '<S1>/If3' */

  /* Saturate: '<S1>/Saturation4' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  u = IdentificationMotor2Order_P.Constant3_Value_a;
  u_0 = IdentificationMotor2Order_P.Saturation4_LowerSat;
  u_1 = IdentificationMotor2Order_P.Saturation4_UpperSat;
  IdentificationMotor2Order_B.Saturation4 = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;

  /* If: '<S1>/If4' */
  if ((IdentificationMotor2Order_B.Saturation4 >= 0.0) &&
      (IdentificationMotor2Order_B.Saturation4 <= 100.0)) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    Identificatio_IfActionSubsystem(IdentificationMotor2Order_B.Saturation4,
      &IdentificationMotor2Order_B.Merge4,
      &IdentificationMotor2Order_B.IfActionSubsystem8,
      (rtP_IfActionSubsystem_Identific *)
      &IdentificationMotor2Order_P.IfActionSubsystem8);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem8' */
  } else {
    if ((IdentificationMotor2Order_B.Saturation4 < 0.0) &&
        (IdentificationMotor2Order_B.Saturation4 >= -100.0)) {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem9' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      Identificati_IfActionSubsystem1(IdentificationMotor2Order_B.Saturation4,
        &IdentificationMotor2Order_B.Merge4,
        &IdentificationMotor2Order_B.IfActionSubsystem9,
        (rtP_IfActionSubsystem1_Identifi *)
        &IdentificationMotor2Order_P.IfActionSubsystem9);

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem9' */
    }
  }

  /* End of If: '<S1>/If4' */

  /* Saturate: '<S1>/Saturation5' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  u = IdentificationMotor2Order_P.Constant4_Value_g;
  u_0 = IdentificationMotor2Order_P.Saturation5_LowerSat;
  u_1 = IdentificationMotor2Order_P.Saturation5_UpperSat;
  IdentificationMotor2Order_B.Saturation5 = u >= u_1 ? u_1 : u <= u_0 ? u_0 : u;

  /* If: '<S1>/If5' */
  if ((IdentificationMotor2Order_B.Saturation5 >= 0.0) &&
      (IdentificationMotor2Order_B.Saturation5 <= 100.0)) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    Identificatio_IfActionSubsystem(IdentificationMotor2Order_B.Saturation5,
      &IdentificationMotor2Order_B.Merge5,
      &IdentificationMotor2Order_B.IfActionSubsystem10,
      (rtP_IfActionSubsystem_Identific *)
      &IdentificationMotor2Order_P.IfActionSubsystem10);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem10' */
  } else {
    if ((IdentificationMotor2Order_B.Saturation5 < 0.0) &&
        (IdentificationMotor2Order_B.Saturation5 >= -100.0)) {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem11' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      Identificati_IfActionSubsystem1(IdentificationMotor2Order_B.Saturation5,
        &IdentificationMotor2Order_B.Merge5,
        &IdentificationMotor2Order_B.IfActionSubsystem11,
        (rtP_IfActionSubsystem1_Identifi *)
        &IdentificationMotor2Order_P.IfActionSubsystem11);

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem11' */
    }
  }

  /* End of If: '<S1>/If5' */

  /* Level2 S-Function Block: '<S1>/ASCII Encode ' (asciiencode) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[5];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S3>/FIFO write 1' (fifowrite) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[6];
    sfcnOutputs(rts, 0);
  }

  /* S-Function Block: <S3>/Enable TX 1 (sertxenablebase) */
  if (IdentificationMotor2Order_B.FIFOwrite1_o2 == 1 ) {
    uint8_T reg = (uint8_T)xpcInpB( (unsigned short)(1016 + IER) ) & 0xff;
    xpcOutpB( (unsigned short)(1016 + IER), (uint8_T)(reg & ~IERXMT) );
    reg |= IERXMT;
    xpcOutpB( (unsigned short)(1016 + IER), reg );
  }

  /* Level2 S-Function Block: '<S3>/FIFO write 2' (fifowrite) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[7];
    sfcnOutputs(rts, 0);
  }

  /* RateTransition: '<S3>/Rate Transition1' */
  IdentificationMotor2Order_B.RateTransition1 =
    IdentificationMotor2Order_B.FIFOwrite1;

  /* Level2 S-Function Block: '<S3>/FIFO read 1' (fiforead) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[8];
    sfcnOutputs(rts, 0);
  }

  /* RateTransition: '<S3>/Rate Transition3' */
  IdentificationMotor2Order_B.RateTransition3 =
    IdentificationMotor2Order_B.FIFOwrite2;

  /* Level2 S-Function Block: '<S3>/FIFO read 2' (fiforead) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[9];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S3>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[10];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S3>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[11];
    sfcnOutputs(rts, 0);
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void IdentificationMotor2Order_update(int_T tid)
{
  /* Update for DiscreteStateSpace: '<S21>/Discrete State-Space6' */
  {
    real_T xnew[2];
    xnew[0] = (IdentificationMotor2Order_P.DiscreteStateSpace6_A[0])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace6_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace6_A[1])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace6_DSTATE[1];
    xnew[0] += (IdentificationMotor2Order_P.DiscreteStateSpace6_B[0])*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o1;
    xnew[1] = (IdentificationMotor2Order_P.DiscreteStateSpace6_A[2])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace6_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace6_A[3])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace6_DSTATE[1];
    xnew[1] += (IdentificationMotor2Order_P.DiscreteStateSpace6_B[1])*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o1;
    (void) memcpy(&IdentificationMotor2Order_DWork.DiscreteStateSpace6_DSTATE[0],
                  xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S21>/Discrete State-Space1' */
  {
    real_T xnew[2];
    xnew[0] = (IdentificationMotor2Order_P.DiscreteStateSpace1_A[0])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace1_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace1_A[1])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace1_DSTATE[1];
    xnew[0] += (IdentificationMotor2Order_P.DiscreteStateSpace1_B[0])*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o3;
    xnew[1] = (IdentificationMotor2Order_P.DiscreteStateSpace1_A[2])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace1_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace1_A[3])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace1_DSTATE[1];
    xnew[1] += (IdentificationMotor2Order_P.DiscreteStateSpace1_B[1])*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o3;
    (void) memcpy(&IdentificationMotor2Order_DWork.DiscreteStateSpace1_DSTATE[0],
                  xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S21>/Discrete State-Space2' */
  {
    real_T xnew[2];
    xnew[0] = (IdentificationMotor2Order_P.DiscreteStateSpace2_A[0])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace2_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace2_A[1])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace2_DSTATE[1];
    xnew[0] += (IdentificationMotor2Order_P.DiscreteStateSpace2_B[0])*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o5;
    xnew[1] = (IdentificationMotor2Order_P.DiscreteStateSpace2_A[2])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace2_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace2_A[3])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace2_DSTATE[1];
    xnew[1] += (IdentificationMotor2Order_P.DiscreteStateSpace2_B[1])*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o5;
    (void) memcpy(&IdentificationMotor2Order_DWork.DiscreteStateSpace2_DSTATE[0],
                  xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S21>/Discrete State-Space3' */
  {
    real_T xnew[2];
    xnew[0] = (IdentificationMotor2Order_P.DiscreteStateSpace3_A[0])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace3_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace3_A[1])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace3_DSTATE[1];
    xnew[0] += (IdentificationMotor2Order_P.DiscreteStateSpace3_B[0])*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o7;
    xnew[1] = (IdentificationMotor2Order_P.DiscreteStateSpace3_A[2])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace3_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace3_A[3])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace3_DSTATE[1];
    xnew[1] += (IdentificationMotor2Order_P.DiscreteStateSpace3_B[1])*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o7;
    (void) memcpy(&IdentificationMotor2Order_DWork.DiscreteStateSpace3_DSTATE[0],
                  xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S21>/Discrete State-Space4' */
  {
    real_T xnew[2];
    xnew[0] = (IdentificationMotor2Order_P.DiscreteStateSpace4_A[0])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace4_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace4_A[1])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace4_DSTATE[1];
    xnew[0] += (IdentificationMotor2Order_P.DiscreteStateSpace4_B[0])*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o9;
    xnew[1] = (IdentificationMotor2Order_P.DiscreteStateSpace4_A[2])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace4_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace4_A[3])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace4_DSTATE[1];
    xnew[1] += (IdentificationMotor2Order_P.DiscreteStateSpace4_B[1])*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o9;
    (void) memcpy(&IdentificationMotor2Order_DWork.DiscreteStateSpace4_DSTATE[0],
                  xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S21>/Discrete State-Space5' */
  {
    real_T xnew[2];
    xnew[0] = (IdentificationMotor2Order_P.DiscreteStateSpace5_A[0])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace5_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace5_A[1])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace5_DSTATE[1];
    xnew[0] += (IdentificationMotor2Order_P.DiscreteStateSpace5_B[0])*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o11;
    xnew[1] = (IdentificationMotor2Order_P.DiscreteStateSpace5_A[2])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace5_DSTATE[0]
      + (IdentificationMotor2Order_P.DiscreteStateSpace5_A[3])*
      IdentificationMotor2Order_DWork.DiscreteStateSpace5_DSTATE[1];
    xnew[1] += (IdentificationMotor2Order_P.DiscreteStateSpace5_B[1])*
      IdentificationMotor2Order_B.MM16ATAnalogInput_o11;
    (void) memcpy(&IdentificationMotor2Order_DWork.DiscreteStateSpace5_DSTATE[0],
                  xnew,
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
  if (!(++IdentificationMotor2Order_rtM->Timing.clockTick0)) {
    ++IdentificationMotor2Order_rtM->Timing.clockTickH0;
  }

  IdentificationMotor2Order_rtM->Timing.t[0] =
    IdentificationMotor2Order_rtM->Timing.clockTick0 *
    IdentificationMotor2Order_rtM->Timing.stepSize0 +
    IdentificationMotor2Order_rtM->Timing.clockTickH0 *
    IdentificationMotor2Order_rtM->Timing.stepSize0 * 4294967296.0;
  switch (IdentificationMotor2Order_rtM->Timing.rtmDbBufReadBuf1) {
   case 0:
    IdentificationMotor2Order_rtM->Timing.rtmDbBufWriteBuf1 = 1;
    break;

   case 1:
    IdentificationMotor2Order_rtM->Timing.rtmDbBufWriteBuf1 = 0;
    break;

   default:
    IdentificationMotor2Order_rtM->Timing.rtmDbBufWriteBuf1 =
      !IdentificationMotor2Order_rtM->Timing.rtmDbBufLastBufWr1;
    break;
  }

  IdentificationMotor2Order_rtM->
    Timing.rtmDbBufClockTick1
    [IdentificationMotor2Order_rtM->Timing.rtmDbBufWriteBuf1] =
    IdentificationMotor2Order_rtM->Timing.clockTick0;
  IdentificationMotor2Order_rtM->
    Timing.rtmDbBufClockTickH1
    [IdentificationMotor2Order_rtM->Timing.rtmDbBufWriteBuf1] =
    IdentificationMotor2Order_rtM->Timing.clockTickH0;
  IdentificationMotor2Order_rtM->Timing.rtmDbBufLastBufWr1 =
    IdentificationMotor2Order_rtM->Timing.rtmDbBufWriteBuf1;
  IdentificationMotor2Order_rtM->Timing.rtmDbBufWriteBuf1 = 0xFF;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void IdentificationMotor2Order_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)IdentificationMotor2Order_rtM, 0,
                sizeof(rtModel_IdentificationMotor2Order));
  rtsiSetSolverName(&IdentificationMotor2Order_rtM->solverInfo,
                    "FixedStepDiscrete");
  IdentificationMotor2Order_rtM->solverInfoPtr =
    (&IdentificationMotor2Order_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      IdentificationMotor2Order_rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    IdentificationMotor2Order_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    IdentificationMotor2Order_rtM->Timing.sampleTimes =
      (&IdentificationMotor2Order_rtM->Timing.sampleTimesArray[0]);
    IdentificationMotor2Order_rtM->Timing.offsetTimes =
      (&IdentificationMotor2Order_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    IdentificationMotor2Order_rtM->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    IdentificationMotor2Order_rtM->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(IdentificationMotor2Order_rtM,
             &IdentificationMotor2Order_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = IdentificationMotor2Order_rtM->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    IdentificationMotor2Order_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(IdentificationMotor2Order_rtM, 3600.0);
  IdentificationMotor2Order_rtM->Timing.stepSize0 = 0.001;
  IdentificationMotor2Order_rtM->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    IdentificationMotor2Order_rtM->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    /*
     * Set pointers to the data and signal info each state
     */
    {
      static int_T rt_LoggedStateWidths[] = {
        2,
        2,
        2,
        2,
        2,
        2
      };

      static int_T rt_LoggedStateNumDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedStateDimensions[] = {
        2,
        2,
        2,
        2,
        2,
        2
      };

      static boolean_T rt_LoggedStateIsVarDims[] = {
        0,
        0,
        0,
        0,
        0,
        0
      };

      static BuiltInDTypeId rt_LoggedStateDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedStateComplexSignals[] = {
        0,
        0,
        0,
        0,
        0,
        0
      };

      static const char_T *rt_LoggedStateLabels[] = {
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE"
      };

      static const char_T *rt_LoggedStateBlockNames[] = {
        "IdentificationMotor2Order/SG-ADC\nSensors/Signal Filtering and scaling/Discrete State-Space6",
        "IdentificationMotor2Order/SG-ADC\nSensors/Signal Filtering and scaling/Discrete State-Space1",
        "IdentificationMotor2Order/SG-ADC\nSensors/Signal Filtering and scaling/Discrete State-Space2",
        "IdentificationMotor2Order/SG-ADC\nSensors/Signal Filtering and scaling/Discrete State-Space3",
        "IdentificationMotor2Order/SG-ADC\nSensors/Signal Filtering and scaling/Discrete State-Space4",
        "IdentificationMotor2Order/SG-ADC\nSensors/Signal Filtering and scaling/Discrete State-Space5"
      };

      static const char_T *rt_LoggedStateNames[] = {
        "",
        "",
        "",
        "",
        "",
        ""
      };

      static boolean_T rt_LoggedStateCrossMdlRef[] = {
        0,
        0,
        0,
        0,
        0,
        0
      };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedStateSignalInfo = {
        6,
        rt_LoggedStateWidths,
        rt_LoggedStateNumDimensions,
        rt_LoggedStateDimensions,
        rt_LoggedStateIsVarDims,
        (NULL),
        rt_LoggedStateDataTypeIds,
        rt_LoggedStateComplexSignals,
        (NULL),

        { rt_LoggedStateLabels },
        (NULL),
        (NULL),
        (NULL),

        { rt_LoggedStateBlockNames },

        { rt_LoggedStateNames },
        rt_LoggedStateCrossMdlRef,
        rt_RTWLogDataTypeConvert
      };

      static void * rt_LoggedStateSignalPtrs[6];
      rtliSetLogXSignalPtrs(IdentificationMotor2Order_rtM->rtwLogInfo,
                            (LogSignalPtrsType) rt_LoggedStateSignalPtrs);
      rtliSetLogXSignalInfo(IdentificationMotor2Order_rtM->rtwLogInfo,
                            &rt_LoggedStateSignalInfo);
      rt_LoggedStateSignalPtrs[0] = (void*)
        IdentificationMotor2Order_DWork.DiscreteStateSpace6_DSTATE;
      rt_LoggedStateSignalPtrs[1] = (void*)
        IdentificationMotor2Order_DWork.DiscreteStateSpace1_DSTATE;
      rt_LoggedStateSignalPtrs[2] = (void*)
        IdentificationMotor2Order_DWork.DiscreteStateSpace2_DSTATE;
      rt_LoggedStateSignalPtrs[3] = (void*)
        IdentificationMotor2Order_DWork.DiscreteStateSpace3_DSTATE;
      rt_LoggedStateSignalPtrs[4] = (void*)
        IdentificationMotor2Order_DWork.DiscreteStateSpace4_DSTATE;
      rt_LoggedStateSignalPtrs[5] = (void*)
        IdentificationMotor2Order_DWork.DiscreteStateSpace5_DSTATE;
    }

    rtliSetLogT(IdentificationMotor2Order_rtM->rtwLogInfo, "tout");
    rtliSetLogX(IdentificationMotor2Order_rtM->rtwLogInfo, "xout");
    rtliSetLogXFinal(IdentificationMotor2Order_rtM->rtwLogInfo, "");
    rtliSetSigLog(IdentificationMotor2Order_rtM->rtwLogInfo, "");
    rtliSetLogVarNameModifier(IdentificationMotor2Order_rtM->rtwLogInfo, "rt_");
    rtliSetLogFormat(IdentificationMotor2Order_rtM->rtwLogInfo, 0);
    rtliSetLogMaxRows(IdentificationMotor2Order_rtM->rtwLogInfo, 0);
    rtliSetLogDecimation(IdentificationMotor2Order_rtM->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &IdentificationMotor2Order_Y.Out1[0],
        &IdentificationMotor2Order_Y.Out2
      };

      rtliSetLogYSignalPtrs(IdentificationMotor2Order_rtM->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        6,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        6,
        1
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
        "ControlSignal2" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "IdentificationMotor2Order/Out1",
        "IdentificationMotor2Order/Out2" };

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

      rtliSetLogYSignalInfo(IdentificationMotor2Order_rtM->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(IdentificationMotor2Order_rtM->rtwLogInfo, "yout");
  }

  /* external mode info */
  IdentificationMotor2Order_rtM->Sizes.checksums[0] = (3634476925U);
  IdentificationMotor2Order_rtM->Sizes.checksums[1] = (347517418U);
  IdentificationMotor2Order_rtM->Sizes.checksums[2] = (2458305616U);
  IdentificationMotor2Order_rtM->Sizes.checksums[3] = (2039455143U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[18];
    IdentificationMotor2Order_rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.Receive1_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.Receive2_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.Transmit1_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.Transmit2_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.RS232ISR_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.IfActionSubsystem10.IfActionSubsystem_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.IfActionSubsystem11.IfActionSubsystem1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.IfActionSubsystem3.IfActionSubsystem1_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.IfActionSubsystem5.IfActionSubsystem1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.IfActionSubsystem6.IfActionSubsystem_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.IfActionSubsystem7.IfActionSubsystem1_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.IfActionSubsystem8.IfActionSubsystem_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &IdentificationMotor2Order_DWork.IfActionSubsystem9.IfActionSubsystem1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(IdentificationMotor2Order_rtM->extModeInfo,
      &IdentificationMotor2Order_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(IdentificationMotor2Order_rtM->extModeInfo,
                        IdentificationMotor2Order_rtM->Sizes.checksums);
    rteiSetTPtr(IdentificationMotor2Order_rtM->extModeInfo, rtmGetTPtr
                (IdentificationMotor2Order_rtM));
  }

  IdentificationMotor2Order_rtM->solverInfoPtr =
    (&IdentificationMotor2Order_rtM->solverInfo);
  IdentificationMotor2Order_rtM->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&IdentificationMotor2Order_rtM->solverInfo, 0.001);
  rtsiSetSolverMode(&IdentificationMotor2Order_rtM->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  IdentificationMotor2Order_rtM->ModelData.blockIO = ((void *)
    &IdentificationMotor2Order_B);
  (void) memset(((void *) &IdentificationMotor2Order_B), 0,
                sizeof(BlockIO_IdentificationMotor2Order));

  {
    IdentificationMotor2Order_B.FIFOwrite1_o1 = serialfifoground;
    IdentificationMotor2Order_B.FIFOwrite2_o1 = serialfifoground;
    IdentificationMotor2Order_B.RateTransition = serialfifoground;
    IdentificationMotor2Order_B.RateTransition2 = serialfifoground;
    IdentificationMotor2Order_B.RateTransition1 = serialfifoground;
    IdentificationMotor2Order_B.RateTransition3 = serialfifoground;
    IdentificationMotor2Order_B.FIFOwrite2 = serialfifoground;
    IdentificationMotor2Order_B.FIFOwrite1 = serialfifoground;
  }

  /* parameters */
  IdentificationMotor2Order_rtM->ModelData.defaultParam = ((real_T *)
    &IdentificationMotor2Order_P);

  /* states (dwork) */
  IdentificationMotor2Order_rtM->Work.dwork = ((void *)
    &IdentificationMotor2Order_DWork);
  (void) memset((void *)&IdentificationMotor2Order_DWork, 0,
                sizeof(D_Work_IdentificationMotor2Order));

  /* external outputs */
  IdentificationMotor2Order_rtM->ModelData.outputs =
    (&IdentificationMotor2Order_Y);
  (void) memset((void *)&IdentificationMotor2Order_Y, 0,
                sizeof(ExternalOutputs_IdentificationMotor2Order));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    IdentificationMotor2Order_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    IdentificationMotor2Order_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  IdentificationMotor2Order_InitializeDataMapInfo(IdentificationMotor2Order_rtM);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &IdentificationMotor2Order_rtM->NonInlinedSFcns.sfcnInfo;
    IdentificationMotor2Order_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (IdentificationMotor2Order_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &IdentificationMotor2Order_rtM->Sizes.numSampTimes);
    IdentificationMotor2Order_rtM->NonInlinedSFcns.taskTimePtrs[0] =
      &(rtmGetTPtr(IdentificationMotor2Order_rtM)[0]);
    IdentificationMotor2Order_rtM->NonInlinedSFcns.taskTimePtrs[1] =
      &(rtmGetTPtr(IdentificationMotor2Order_rtM)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   IdentificationMotor2Order_rtM->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(IdentificationMotor2Order_rtM));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(IdentificationMotor2Order_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (IdentificationMotor2Order_rtM));
    rtssSetStepSizePtr(sfcnInfo, &IdentificationMotor2Order_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (IdentificationMotor2Order_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &IdentificationMotor2Order_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &IdentificationMotor2Order_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &IdentificationMotor2Order_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &IdentificationMotor2Order_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &IdentificationMotor2Order_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &IdentificationMotor2Order_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &IdentificationMotor2Order_rtM->solverInfoPtr);
  }

  IdentificationMotor2Order_rtM->Sizes.numSFcns = (12);

  /* register each child */
  {
    (void) memset((void *)
                  &IdentificationMotor2Order_rtM->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  12*sizeof(SimStruct));
    IdentificationMotor2Order_rtM->childSfunctions =
      (&IdentificationMotor2Order_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 12; i++) {
        IdentificationMotor2Order_rtM->childSfunctions[i] =
          (&IdentificationMotor2Order_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: IdentificationMotor2Order/<S17>/FIFO write 1 (fifowrite) */
    {
      SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      ssSetRTWSfcnInfo(rts, IdentificationMotor2Order_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.statesInfo2
                         [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, IdentificationMotor2Order_B.ReadHWFIFO1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 65);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((serialfifoptr *)
            &IdentificationMotor2Order_B.FIFOwrite1));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO write 1");
      ssSetPath(rts,
                "IdentificationMotor2Order/Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 1/FIFO write 1");
      ssSetRTModel(rts,IdentificationMotor2Order_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite1_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &IdentificationMotor2Order_DWork.FIFOwrite1_IWORK_b[0]);
      ssSetPWork(rts, (void **)
                 &IdentificationMotor2Order_DWork.FIFOwrite1_PWORK_g);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &IdentificationMotor2Order_DWork.FIFOwrite1_IWORK_b[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &IdentificationMotor2Order_DWork.FIFOwrite1_PWORK_g);
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

    /* Level2 S-Function Block: IdentificationMotor2Order/<S19>/FIFO read 1 (fiforead) */
    {
      SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      ssSetRTWSfcnInfo(rts, IdentificationMotor2Order_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.statesInfo2
                         [1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &IdentificationMotor2Order_B.RateTransition);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1,
                               &IdentificationMotor2Order_B.ReadIntStatusFC1_o2);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          ssSetInputPortRequiredContiguous(rts, 2, 1);
          ssSetInputPortSignal(rts, 2,
                               &IdentificationMotor2Order_P.Constant1_Value_j);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 61);
          ssSetOutputPortSignal(rts, 0, ((uint32_T *)
            IdentificationMotor2Order_B.FIFOread1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &IdentificationMotor2Order_B.FIFOread1_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO read 1");
      ssSetPath(rts,
                "IdentificationMotor2Order/Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 1/FIFO read 1");
      ssSetRTModel(rts,IdentificationMotor2Order_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P8_Size);
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

    /* Level2 S-Function Block: IdentificationMotor2Order/<S18>/FIFO write 2 (fifowrite) */
    {
      SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.blkInfo2
                         [2]);
      }

      ssSetRTWSfcnInfo(rts, IdentificationMotor2Order_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods3
                           [2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.statesInfo2
                         [2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, IdentificationMotor2Order_B.ReadHWFIFO2);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 65);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((serialfifoptr *)
            &IdentificationMotor2Order_B.FIFOwrite2));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO write 2");
      ssSetPath(rts,
                "IdentificationMotor2Order/Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Receive 2/FIFO write 2");
      ssSetRTModel(rts,IdentificationMotor2Order_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite2_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &IdentificationMotor2Order_DWork.FIFOwrite2_IWORK_c[0]);
      ssSetPWork(rts, (void **)
                 &IdentificationMotor2Order_DWork.FIFOwrite2_PWORK_i);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &IdentificationMotor2Order_DWork.FIFOwrite2_IWORK_c[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &IdentificationMotor2Order_DWork.FIFOwrite2_PWORK_i);
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

    /* Level2 S-Function Block: IdentificationMotor2Order/<S20>/FIFO read 2 (fiforead) */
    {
      SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.blkInfo2
                         [3]);
      }

      ssSetRTWSfcnInfo(rts, IdentificationMotor2Order_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods2
                           [3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods3
                           [3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.statesInfo2
                         [3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &IdentificationMotor2Order_B.RateTransition2);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1,
                               &IdentificationMotor2Order_B.ReadIntStatusFC1_o2);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          ssSetInputPortRequiredContiguous(rts, 2, 1);
          ssSetInputPortSignal(rts, 2,
                               &IdentificationMotor2Order_P.Constant2_Value_c);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 61);
          ssSetOutputPortSignal(rts, 0, ((uint32_T *)
            IdentificationMotor2Order_B.FIFOread2_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &IdentificationMotor2Order_B.FIFOread2_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO read 2");
      ssSetPath(rts,
                "IdentificationMotor2Order/Motors - F4  STM - PWM/Baseboard Serial1/RS232 ISR/Transmit 2/FIFO read 2");
      ssSetRTModel(rts,IdentificationMotor2Order_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P8_Size);
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

    /* Level2 S-Function Block: IdentificationMotor2Order/<S2>/MM-16-AT Analog Input (addiamondmm16atcustom) */
    {
      SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.blkInfo2
                         [4]);
      }

      ssSetRTWSfcnInfo(rts, IdentificationMotor2Order_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods2
                           [4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods3
                           [4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.statesInfo2
                         [4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 12);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &IdentificationMotor2Order_B.MM16ATAnalogInput_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &IdentificationMotor2Order_B.MM16ATAnalogInput_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &IdentificationMotor2Order_B.MM16ATAnalogInput_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &IdentificationMotor2Order_B.MM16ATAnalogInput_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &IdentificationMotor2Order_B.MM16ATAnalogInput_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &IdentificationMotor2Order_B.MM16ATAnalogInput_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &IdentificationMotor2Order_B.MM16ATAnalogInput_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &IdentificationMotor2Order_B.MM16ATAnalogInput_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((real_T *)
            &IdentificationMotor2Order_B.MM16ATAnalogInput_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((real_T *)
            &IdentificationMotor2Order_B.MM16ATAnalogInput_o10));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((real_T *)
            &IdentificationMotor2Order_B.MM16ATAnalogInput_o11));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((real_T *)
            &IdentificationMotor2Order_B.MM16ATAnalogInput_o12));
        }
      }

      /* path info */
      ssSetModelName(rts, "MM-16-AT Analog Input");
      ssSetPath(rts,
                "IdentificationMotor2Order/SG-ADC Sensors/MM-16-AT Analog Input");
      ssSetRTModel(rts,IdentificationMotor2Order_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IdentificationMotor2Order_P.MM16ATAnalogInput_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IdentificationMotor2Order_P.MM16ATAnalogInput_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IdentificationMotor2Order_P.MM16ATAnalogInput_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       IdentificationMotor2Order_P.MM16ATAnalogInput_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       IdentificationMotor2Order_P.MM16ATAnalogInput_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &IdentificationMotor2Order_DWork.MM16ATAnalogInput_RWORK[0]);
      ssSetIWork(rts, (int_T *)
                 &IdentificationMotor2Order_DWork.MM16ATAnalogInput_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &IdentificationMotor2Order_DWork.MM16ATAnalogInput_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1,
                   &IdentificationMotor2Order_DWork.MM16ATAnalogInput_IWORK);
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

    /* Level2 S-Function Block: IdentificationMotor2Order/<S1>/ASCII Encode  (asciiencode) */
    {
      SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.blkInfo2
                         [5]);
      }

      ssSetRTWSfcnInfo(rts, IdentificationMotor2Order_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods2
                           [5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods3
                           [5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.statesInfo2
                         [5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 6);
        ssSetPortInfoForInputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &IdentificationMotor2Order_B.Merge;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.UPtrs1;
          sfcnUPtrs[0] = &IdentificationMotor2Order_B.Merge1;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.UPtrs2;
          sfcnUPtrs[0] = &IdentificationMotor2Order_B.Merge2;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.UPtrs3;
          sfcnUPtrs[0] = &IdentificationMotor2Order_B.Merge3;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.UPtrs4;
          sfcnUPtrs[0] = &IdentificationMotor2Order_B.Merge4;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.UPtrs5;
          sfcnUPtrs[0] = &IdentificationMotor2Order_B.Merge5;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 9);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            IdentificationMotor2Order_B.ASCIIEncode));
        }
      }

      /* path info */
      ssSetModelName(rts, "ASCII Encode ");
      ssSetPath(rts,
                "IdentificationMotor2Order/Motors - F4  STM - PWM/ASCII Encode ");
      ssSetRTModel(rts,IdentificationMotor2Order_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IdentificationMotor2Order_P.ASCIIEncode_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IdentificationMotor2Order_P.ASCIIEncode_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IdentificationMotor2Order_P.ASCIIEncode_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       IdentificationMotor2Order_P.ASCIIEncode_P4_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &IdentificationMotor2Order_DWork.ASCIIEncode_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &IdentificationMotor2Order_DWork.ASCIIEncode_PWORK);
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

    /* Level2 S-Function Block: IdentificationMotor2Order/<S3>/FIFO write 1 (fifowrite) */
    {
      SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.blkInfo2
                         [6]);
      }

      ssSetRTWSfcnInfo(rts, IdentificationMotor2Order_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods2
                           [6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods3
                           [6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.statesInfo2
                         [6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, IdentificationMotor2Order_B.ASCIIEncode);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 9);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((serialfifoptr *)
            &IdentificationMotor2Order_B.FIFOwrite1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((boolean_T *)
            &IdentificationMotor2Order_B.FIFOwrite1_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO write 1");
      ssSetPath(rts,
                "IdentificationMotor2Order/Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 1");
      ssSetRTModel(rts,IdentificationMotor2Order_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite1_P1_Size_o);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite1_P2_Size_n);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite1_P3_Size_p);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite1_P4_Size_k);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite1_P5_Size_e);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &IdentificationMotor2Order_DWork.FIFOwrite1_IWORK[0]);
      ssSetPWork(rts, (void **)
                 &IdentificationMotor2Order_DWork.FIFOwrite1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &IdentificationMotor2Order_DWork.FIFOwrite1_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &IdentificationMotor2Order_DWork.FIFOwrite1_PWORK);
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

    /* Level2 S-Function Block: IdentificationMotor2Order/<S3>/FIFO write 2 (fifowrite) */
    {
      SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.blkInfo2
                         [7]);
      }

      ssSetRTWSfcnInfo(rts, IdentificationMotor2Order_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods2
                           [7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods3
                           [7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.statesInfo2
                         [7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, (uint8_T*)
                               &IdentificationMotor2Order_U8GND);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((serialfifoptr *)
            &IdentificationMotor2Order_B.FIFOwrite2_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((boolean_T *)
            &IdentificationMotor2Order_B.FIFOwrite2_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO write 2");
      ssSetPath(rts,
                "IdentificationMotor2Order/Motors - F4  STM - PWM/Baseboard Serial1/FIFO write 2");
      ssSetRTModel(rts,IdentificationMotor2Order_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite2_P1_Size_d);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite2_P2_Size_f);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite2_P3_Size_p);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite2_P4_Size_p);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       IdentificationMotor2Order_P.FIFOwrite2_P5_Size_c);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &IdentificationMotor2Order_DWork.FIFOwrite2_IWORK[0]);
      ssSetPWork(rts, (void **)
                 &IdentificationMotor2Order_DWork.FIFOwrite2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &IdentificationMotor2Order_DWork.FIFOwrite2_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &IdentificationMotor2Order_DWork.FIFOwrite2_PWORK);
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

    /* Level2 S-Function Block: IdentificationMotor2Order/<S3>/FIFO read 1 (fiforead) */
    {
      SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.blkInfo2
                         [8]);
      }

      ssSetRTWSfcnInfo(rts, IdentificationMotor2Order_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods2
                           [8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods3
                           [8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.statesInfo2
                         [8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &IdentificationMotor2Order_B.RateTransition1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1025);
          ssSetOutputPortSignal(rts, 0, ((uint16_T *)
            IdentificationMotor2Order_B.FIFOread1));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO read 1");
      ssSetPath(rts,
                "IdentificationMotor2Order/Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 1");
      ssSetRTModel(rts,IdentificationMotor2Order_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P1_Size_k);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P2_Size_m);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P3_Size_d);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P4_Size_m);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P5_Size_k);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P6_Size_i);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P7_Size_i);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread1_P8_Size_a);
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

    /* Level2 S-Function Block: IdentificationMotor2Order/<S3>/FIFO read 2 (fiforead) */
    {
      SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.blkInfo2
                         [9]);
      }

      ssSetRTWSfcnInfo(rts, IdentificationMotor2Order_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods2
                           [9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods3
                           [9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.statesInfo2
                         [9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn9.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &IdentificationMotor2Order_B.RateTransition3);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1025);
          ssSetOutputPortSignal(rts, 0, ((uint16_T *)
            IdentificationMotor2Order_B.FIFOread2));
        }
      }

      /* path info */
      ssSetModelName(rts, "FIFO read 2");
      ssSetPath(rts,
                "IdentificationMotor2Order/Motors - F4  STM - PWM/Baseboard Serial1/FIFO read 2");
      ssSetRTModel(rts,IdentificationMotor2Order_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P1_Size_n);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P2_Size_i);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P3_Size_h);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P4_Size_p);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P5_Size_m);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P6_Size_c);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P7_Size_k);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       IdentificationMotor2Order_P.FIFOread2_P8_Size_c);
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

    /* Level2 S-Function Block: IdentificationMotor2Order/<S3>/Setup1 (sersetupbase) */
    {
      SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.blkInfo2
                         [10]);
      }

      ssSetRTWSfcnInfo(rts, IdentificationMotor2Order_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods2
                           [10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods3
                           [10]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.statesInfo2
                         [10]);
      }

      /* path info */
      ssSetModelName(rts, "Setup1");
      ssSetPath(rts,
                "IdentificationMotor2Order/Motors - F4  STM - PWM/Baseboard Serial1/Setup1");
      ssSetRTModel(rts,IdentificationMotor2Order_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IdentificationMotor2Order_P.Setup1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IdentificationMotor2Order_P.Setup1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IdentificationMotor2Order_P.Setup1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       IdentificationMotor2Order_P.Setup1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       IdentificationMotor2Order_P.Setup1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       IdentificationMotor2Order_P.Setup1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       IdentificationMotor2Order_P.Setup1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       IdentificationMotor2Order_P.Setup1_P8_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &IdentificationMotor2Order_DWork.Setup1_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn10.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn10.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &IdentificationMotor2Order_DWork.Setup1_IWORK[0]);
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

    /* Level2 S-Function Block: IdentificationMotor2Order/<S3>/Setup2 (sersetupbase) */
    {
      SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap =
        IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.blkInfo2
                         [11]);
      }

      ssSetRTWSfcnInfo(rts, IdentificationMotor2Order_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods2
                           [11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &IdentificationMotor2Order_rtM->NonInlinedSFcns.methods3
                           [11]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &IdentificationMotor2Order_rtM->NonInlinedSFcns.statesInfo2
                         [11]);
      }

      /* path info */
      ssSetModelName(rts, "Setup2");
      ssSetPath(rts,
                "IdentificationMotor2Order/Motors - F4  STM - PWM/Baseboard Serial1/Setup2");
      ssSetRTModel(rts,IdentificationMotor2Order_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       IdentificationMotor2Order_P.Setup2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       IdentificationMotor2Order_P.Setup2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       IdentificationMotor2Order_P.Setup2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       IdentificationMotor2Order_P.Setup2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       IdentificationMotor2Order_P.Setup2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       IdentificationMotor2Order_P.Setup2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       IdentificationMotor2Order_P.Setup2_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       IdentificationMotor2Order_P.Setup2_P8_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &IdentificationMotor2Order_DWork.Setup2_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn11.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &IdentificationMotor2Order_rtM->NonInlinedSFcns.Sfcn11.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &IdentificationMotor2Order_DWork.Setup2_IWORK[0]);
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
void IdentificationMotor2Order_terminate(void)
{
  /* user code (Terminate function Header) */

  /* Stop first, then deregister, else the board could interrupt
   * after deregistering and before the stop.
   */
  /* disable interrupt for IRQ 4 */
  xpceDeRegisterISR( &xpcDev_1 );

  /* Level2 S-Function Block: '<S2>/MM-16-AT Analog Input' (addiamondmm16atcustom) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/ASCII Encode ' (asciiencode) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/FIFO write 1' (fifowrite) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/FIFO write 2' (fifowrite) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/FIFO read 1' (fiforead) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/FIFO read 2' (fiforead) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[11];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  IdentificationMotor2Order_output(tid);
}

void MdlUpdate(int_T tid)
{
  IdentificationMotor2Order_update(tid);
}

void MdlInitializeSizes(void)
{
  IdentificationMotor2Order_rtM->Sizes.numContStates = (0);/* Number of continuous states */
  IdentificationMotor2Order_rtM->Sizes.numY = (7);/* Number of model outputs */
  IdentificationMotor2Order_rtM->Sizes.numU = (0);/* Number of model inputs */
  IdentificationMotor2Order_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  IdentificationMotor2Order_rtM->Sizes.numSampTimes = (1);/* Number of sample times */
  IdentificationMotor2Order_rtM->Sizes.numBlocks = (109);/* Number of blocks */
  IdentificationMotor2Order_rtM->Sizes.numBlockIO = (88);/* Number of block outputs */
  IdentificationMotor2Order_rtM->Sizes.numBlockPrms = (448);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
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
      sprintf( ermsg, "ISR registration failed for Interrupt %d ISA board at 0."
              );
      rtmSetErrorStatus(IdentificationMotor2Order_rtM, ermsg);
      return;
    }
  }

  IdentificationMotor2Order_rtM->Timing.rtmDbBufReadBuf1 = 0xFF;
  IdentificationMotor2Order_rtM->Timing.rtmDbBufWriteBuf1 = 0xFF;
  IdentificationMotor2Order_rtM->Timing.rtmDbBufLastBufWr1 = 0;

  /* InitializeConditions for DiscreteStateSpace: '<S21>/Discrete State-Space6' */
  IdentificationMotor2Order_DWork.DiscreteStateSpace6_DSTATE[0] =
    IdentificationMotor2Order_P.DiscreteStateSpace6_X0[0];
  IdentificationMotor2Order_DWork.DiscreteStateSpace6_DSTATE[1] =
    IdentificationMotor2Order_P.DiscreteStateSpace6_X0[1];

  /* InitializeConditions for DiscreteStateSpace: '<S21>/Discrete State-Space1' */
  IdentificationMotor2Order_DWork.DiscreteStateSpace1_DSTATE[0] =
    IdentificationMotor2Order_P.DiscreteStateSpace1_X0[0];
  IdentificationMotor2Order_DWork.DiscreteStateSpace1_DSTATE[1] =
    IdentificationMotor2Order_P.DiscreteStateSpace1_X0[1];

  /* InitializeConditions for DiscreteStateSpace: '<S21>/Discrete State-Space2' */
  IdentificationMotor2Order_DWork.DiscreteStateSpace2_DSTATE[0] =
    IdentificationMotor2Order_P.DiscreteStateSpace2_X0[0];
  IdentificationMotor2Order_DWork.DiscreteStateSpace2_DSTATE[1] =
    IdentificationMotor2Order_P.DiscreteStateSpace2_X0[1];

  /* InitializeConditions for DiscreteStateSpace: '<S21>/Discrete State-Space3' */
  IdentificationMotor2Order_DWork.DiscreteStateSpace3_DSTATE[0] =
    IdentificationMotor2Order_P.DiscreteStateSpace3_X0[0];
  IdentificationMotor2Order_DWork.DiscreteStateSpace3_DSTATE[1] =
    IdentificationMotor2Order_P.DiscreteStateSpace3_X0[1];

  /* InitializeConditions for DiscreteStateSpace: '<S21>/Discrete State-Space4' */
  IdentificationMotor2Order_DWork.DiscreteStateSpace4_DSTATE[0] =
    IdentificationMotor2Order_P.DiscreteStateSpace4_X0[0];
  IdentificationMotor2Order_DWork.DiscreteStateSpace4_DSTATE[1] =
    IdentificationMotor2Order_P.DiscreteStateSpace4_X0[1];

  /* InitializeConditions for DiscreteStateSpace: '<S21>/Discrete State-Space5' */
  IdentificationMotor2Order_DWork.DiscreteStateSpace5_DSTATE[0] =
    IdentificationMotor2Order_P.DiscreteStateSpace5_X0[0];
  IdentificationMotor2Order_DWork.DiscreteStateSpace5_DSTATE[1] =
    IdentificationMotor2Order_P.DiscreteStateSpace5_X0[1];

  /* user code (Initialize function Trailer) */
  xpcOutpB( 0xA0, 0x20 );
  xpcOutpB( 0x20, 0x20 );
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<S2>/MM-16-AT Analog Input' (addiamondmm16atcustom) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for FromWorkspace: '<Root>/Velocity reference2' */
  {
    static real_T pTimeValues[] = { 0.0, 0.1, 0.2, 0.30000000000000004, 0.4, 0.5,
      0.6, 0.7, 0.79999999999999993, 0.89999999999999991, 0.99999999999999989,
      1.0999999999999999, 1.2, 1.3, 1.4000000000000001, 1.5000000000000002,
      1.6000000000000003, 1.7000000000000004, 1.8000000000000005,
      1.9000000000000006, 2.0000000000000004, 2.1000000000000005,
      2.2000000000000006, 2.3000000000000007, 2.4000000000000008,
      2.5000000000000009, 2.600000000000001, 2.7000000000000011,
      2.8000000000000012, 2.9000000000000012, 3.0000000000000013,
      3.1000000000000014, 3.2000000000000015, 3.3000000000000016,
      3.4000000000000017, 3.5000000000000018, 3.6000000000000019,
      3.700000000000002, 3.800000000000002, 3.9000000000000021,
      4.0000000000000018, 4.1000000000000014, 4.2000000000000011,
      4.3000000000000007, 4.4, 4.5, 4.6, 4.6999999999999993, 4.7999999999999989,
      4.8999999999999986, 4.9999999999999982, 5.0999999999999979,
      5.1999999999999975, 5.2999999999999972, 5.3999999999999968,
      5.4999999999999964, 5.5999999999999961, 5.6999999999999957,
      5.7999999999999954, 5.899999999999995, 5.9999999999999947,
      6.0999999999999943, 6.199999999999994, 6.2999999999999936,
      6.3999999999999932, 6.4999999999999929, 6.5999999999999925,
      6.6999999999999922, 6.7999999999999918, 6.8999999999999915,
      6.9999999999999911, 7.0999999999999908, 7.19999999999999, 7.29999999999999,
      7.39999999999999, 7.4999999999999893, 7.599999999999989,
      7.6999999999999886, 7.7999999999999883, 7.8999999999999879,
      7.9999999999999876, 8.0999999999999872, 8.1999999999999869,
      8.2999999999999865, 8.3999999999999861, 8.4999999999999858,
      8.5999999999999854, 8.6999999999999851, 8.7999999999999847,
      8.8999999999999844, 8.999999999999984, 9.0999999999999837,
      9.1999999999999833, 9.2999999999999829, 9.3999999999999826,
      9.4999999999999822, 9.5999999999999819, 9.6999999999999815,
      9.7999999999999812, 9.89999999999998, 9.99999999999998, 10.09999999999998,
      10.19999999999998, 10.299999999999979, 10.399999999999979,
      10.499999999999979, 10.599999999999978, 10.699999999999978,
      10.799999999999978, 10.899999999999977, 10.999999999999977,
      11.099999999999977, 11.199999999999976, 11.299999999999976,
      11.399999999999975, 11.499999999999975, 11.599999999999975,
      11.699999999999974, 11.799999999999974, 11.899999999999974,
      11.999999999999973, 12.099999999999973, 12.199999999999973,
      12.299999999999972, 12.399999999999972, 12.499999999999972,
      12.599999999999971, 12.699999999999971, 12.799999999999971,
      12.89999999999997, 12.99999999999997, 13.099999999999969,
      13.199999999999969, 13.299999999999969, 13.399999999999968,
      13.499999999999968, 13.599999999999968, 13.699999999999967,
      13.799999999999967, 13.899999999999967, 13.999999999999966,
      14.099999999999966, 14.199999999999966, 14.299999999999965,
      14.399999999999965, 14.499999999999964, 14.599999999999964,
      14.699999999999964, 14.799999999999963, 14.899999999999963,
      14.999999999999963, 15.099999999999962, 15.199999999999962,
      15.299999999999962, 15.399999999999961, 15.499999999999961,
      15.599999999999961, 15.69999999999996, 15.79999999999996,
      15.899999999999959, 15.999999999999959, 16.099999999999959,
      16.19999999999996, 16.299999999999962, 16.399999999999963,
      16.499999999999964, 16.599999999999966, 16.699999999999967,
      16.799999999999969, 16.89999999999997, 16.999999999999972,
      17.099999999999973, 17.199999999999974, 17.299999999999976,
      17.399999999999977, 17.499999999999979, 17.59999999999998,
      17.699999999999982, 17.799999999999983, 17.899999999999984,
      17.999999999999986, 18.099999999999987, 18.199999999999989,
      18.29999999999999, 18.399999999999991, 18.499999999999993,
      18.599999999999994, 18.699999999999996, 18.799999999999997, 18.9, 19.0,
      19.1, 19.200000000000003, 19.300000000000004, 19.400000000000006,
      19.500000000000007, 19.600000000000009, 19.70000000000001,
      19.800000000000011, 19.900000000000013, 20.000000000000014,
      20.100000000000016, 20.200000000000017, 20.300000000000018,
      20.40000000000002, 20.500000000000021, 20.600000000000023,
      20.700000000000024, 20.800000000000026, 20.900000000000027,
      21.000000000000028, 21.10000000000003, 21.200000000000031,
      21.300000000000033, 21.400000000000034, 21.500000000000036,
      21.600000000000037, 21.700000000000038, 21.80000000000004,
      21.900000000000041, 22.000000000000043, 22.100000000000044,
      22.200000000000045, 22.300000000000047, 22.400000000000048,
      22.50000000000005, 22.600000000000051, 22.700000000000053,
      22.800000000000054, 22.900000000000055, 23.000000000000057,
      23.100000000000058, 23.20000000000006, 23.300000000000061,
      23.400000000000063, 23.500000000000064, 23.600000000000065,
      23.700000000000067, 23.800000000000068, 23.90000000000007,
      24.000000000000071, 24.100000000000072, 24.200000000000074,
      24.300000000000075, 24.400000000000077, 24.500000000000078,
      24.60000000000008, 24.700000000000081, 24.800000000000082,
      24.900000000000084, 25.000000000000085, 25.100000000000087,
      25.200000000000088, 25.30000000000009, 25.400000000000091,
      25.500000000000092, 25.600000000000094, 25.700000000000095,
      25.800000000000097, 25.900000000000098, 26.0000000000001, 26.1000000000001,
      26.200000000000102, 26.300000000000104, 26.400000000000105,
      26.500000000000107, 26.600000000000108, 26.700000000000109,
      26.800000000000111, 26.900000000000112, 27.000000000000114,
      27.100000000000115, 27.200000000000117, 27.300000000000118,
      27.400000000000119, 27.500000000000121, 27.600000000000122,
      27.700000000000124, 27.800000000000125, 27.900000000000126,
      28.000000000000128, 28.100000000000129, 28.200000000000131,
      28.300000000000132, 28.400000000000134, 28.500000000000135,
      28.600000000000136, 28.700000000000138, 28.800000000000139,
      28.900000000000141, 29.000000000000142, 29.100000000000144,
      29.200000000000145, 29.300000000000146, 29.400000000000148,
      29.500000000000149, 29.600000000000151, 29.700000000000152,
      29.800000000000153, 29.900000000000155, 30.000000000000156,
      30.100000000000158, 30.200000000000159, 30.300000000000161,
      30.400000000000162, 30.500000000000163, 30.600000000000165,
      30.700000000000166, 30.800000000000168, 30.900000000000169,
      31.000000000000171, 31.100000000000172, 31.200000000000173,
      31.300000000000175, 31.400000000000176, 31.500000000000178,
      31.600000000000179, 31.70000000000018, 31.800000000000182,
      31.900000000000183, 32.000000000000185, 32.100000000000186,
      32.200000000000188, 32.300000000000189, 32.40000000000019,
      32.500000000000192, 32.600000000000193, 32.700000000000195,
      32.800000000000196, 32.9000000000002, 33.0000000000002, 33.1000000000002,
      33.2000000000002, 33.3000000000002, 33.400000000000205, 33.500000000000206,
      33.600000000000207, 33.700000000000209, 33.80000000000021,
      33.900000000000212, 34.000000000000213, 34.100000000000215,
      34.200000000000216, 34.300000000000217, 34.400000000000219,
      34.50000000000022, 34.600000000000222, 34.700000000000223,
      34.800000000000225, 34.900000000000226, 35.000000000000227,
      35.100000000000229, 35.20000000000023, 35.300000000000232,
      35.400000000000233, 35.500000000000234, 35.600000000000236,
      35.700000000000237, 35.800000000000239, 35.90000000000024,
      36.000000000000242, 36.100000000000243, 36.200000000000244,
      36.300000000000246, 36.400000000000247, 36.500000000000249,
      36.60000000000025, 36.700000000000252, 36.800000000000253,
      36.900000000000254, 37.000000000000256, 37.100000000000257,
      37.200000000000259, 37.30000000000026, 37.400000000000261,
      37.500000000000263, 37.600000000000264, 37.700000000000266,
      37.800000000000267, 37.900000000000269, 38.00000000000027,
      38.100000000000271, 38.200000000000273, 38.300000000000274,
      38.400000000000276, 38.500000000000277, 38.600000000000279,
      38.70000000000028, 38.800000000000281, 38.900000000000283,
      39.000000000000284, 39.100000000000286, 39.200000000000287,
      39.300000000000288, 39.40000000000029, 39.500000000000291,
      39.600000000000293, 39.700000000000294, 39.800000000000296,
      39.9000000000003 } ;

    static real_T pDataValues[] = { -10.0, -10.0, -10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, 10.0, 10.0, -10.0, -10.0, -10.0, 10.0, -10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, -10.0, 10.0, -10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, -10.0, -10.0,
      -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, -10.0, 10.0, 10.0, 10.0, 10.0, 10.0, -10.0, 10.0,
      10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0,
      -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0,
      -10.0, 10.0, 10.0, 10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0,
      -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, 10.0, 10.0, 10.0, 10.0,
      -10.0, 10.0, 10.0, 10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, 10.0,
      -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0,
      -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0,
      -10.0, -10.0, -10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, -10.0, 10.0,
      -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0,
      -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, -10.0, -10.0, -10.0, -10.0,
      -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0,
      -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0,
      -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0,
      -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0,
      -10.0, -10.0, -10.0, -10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
      -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0,
      -10.0, -10.0, -10.0, 10.0, -10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, -10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, -10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, -10.0, 10.0, 10.0, 10.0, 10.0,
      10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0 } ;

    IdentificationMotor2Order_DWork.Velocityreference2_PWORK.TimePtr = (void *)
      pTimeValues;
    IdentificationMotor2Order_DWork.Velocityreference2_PWORK.DataPtr = (void *)
      pDataValues;
    IdentificationMotor2Order_DWork.Velocityreference2_IWORK.PrevIndex = 0;
  }

  /* Level2 S-Function Block: '<S1>/ASCII Encode ' (asciiencode) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/FIFO write 1' (fifowrite) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/FIFO write 2' (fifowrite) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (xpcinterrupt): '<S3>/IRQ Source' */
  IdentificationMo_RS232ISR_Start();

  /* Level2 S-Function Block: '<S3>/FIFO read 1' (fiforead) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/FIFO read 2' (fiforead) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = IdentificationMotor2Order_rtM->childSfunctions[11];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  IdentificationMotor2Order_terminate();
}

rtModel_IdentificationMotor2Order *IdentificationMotor2Order(void)
{
  IdentificationMotor2Order_initialize(1);
  return IdentificationMotor2Order_rtM;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
