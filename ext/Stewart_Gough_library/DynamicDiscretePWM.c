
#define S_FUNCTION_NAME  DynamicDiscretePWM
#define S_FUNCTION_LEVEL 2

#define SAMPLE_TIME_PARAM    ssGetSFcnParam(S,0)
#define PWM_AMPLITUDE_PARAM  ssGetSFcnParam(S,1)
#define PWM_PERIOD_PARAM     ssGetSFcnParam(S,2)

#include "simstruc.h"
#include <stdlib.h>    //For use of the absolute value

static void mdlInitializeSizes(SimStruct *S)
{
    int_T i;
    int_T nInputPorts  = 6;  /* number of input ports  */
    int_T nOutputPorts = 12;  /* number of output ports */
   
    ssSetNumSFcnParams(S, 3);  /* Number of expected parameters */
    
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
       return;
    }
    ssSetSFcnParamTunable(S, 0, 0);
    ssSetSFcnParamTunable(S, 1, 1);
    ssSetSFcnParamTunable(S, 2, 1);
    
    ssSetNumContStates(S, 0);   /* number of continuous states           */
    ssSetNumDiscStates(S, 0);   /* number of discrete states             */


    /*
     * Configure the input ports. First set the number of input ports. 
     */
    if (!ssSetNumInputPorts(S, nInputPorts)) return; 
    for (i=0;i<6;i++)
    {
        ssSetInputPortWidth(S, i, 1);   
        ssSetInputPortDirectFeedThrough(S, i, 1);         
    }
        
    if (!ssSetNumOutputPorts(S, nOutputPorts)) return;
    for (i=0;i<12;i++)
    {
        ssSetOutputPortWidth(S, i, 1);         
    }
      

    ssSetNumSampleTimes(S, 1);   /* number of sample times                */

    ssSetNumRWork(S, 7);   /* number of real work vector elements   */
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);
    
    ssSetOptions(S, 0);   /* general options (SS_OPTION_xx)        */

} /* end mdlInitializeSizes */


static void mdlInitializeSampleTimes(SimStruct *S)
{
    /* Register one pair for each sample time */
    
    ssSetSampleTime(S, 0, mxGetPr(SAMPLE_TIME_PARAM)[0]);       
    ssSetOffsetTime(S, 0, 0.0);

} /* end mdlInitializeSampleTimes */


  static void mdlInitializeConditions(SimStruct *S)
  {   
    real_T *RWork  = ssGetRWork(S);    
    RWork[0]=0;
    RWork[1]=0;
    RWork[2]=0;
    RWork[3]=0;
    RWork[4]=0;
    RWork[5]=0;
    RWork[6]=0;
  }

  static void mdlStart(SimStruct *S)
  {
  }
    
static void mdlOutputs(SimStruct *S, int_T tid)
{
    real_T *RWork  = ssGetRWork(S);
    int_T SampleHint,Output,i;
    int_T Width_pulses[6];
    
    InputRealPtrsType uPtrs;                                      
    real_T *y;   
    
    SampleHint=((int_T)RWork[0] % (int_T)mxGetPr(PWM_PERIOD_PARAM)[0]);
    //ssPrintf("SampleHint: %d ", SampleHint);
    // Modify PWM width only at PWM period time
    if (SampleHint==0)
    {
        for(i=0;i<6;i++)
        {
            uPtrs =   ssGetInputPortRealSignalPtrs(S,i);
            RWork[i+1]= (int_T)*uPtrs[0];
        }
    }     
    
    for (i=0; i<6 ; i++)   
    {           
        
        Width_pulses[i]=(int_T)((int_T)mxGetPr(PWM_PERIOD_PARAM)[0]*(int_T)RWork[i+1]/100);
        Width_pulses[i]=abs(Width_pulses[i]);
        //ssPrintf("Width_Pulse: %d ", Width_pulses[i]);
        if (SampleHint >= Width_pulses[i]) Output=0;    
        else Output=(int_T)mxGetPr(PWM_AMPLITUDE_PARAM)[0];
        
        if ((int_T)RWork[i+1]>0)
        {
            y = ssGetOutputPortSignal(S,i*2);
            y[0]=Output;
            y = ssGetOutputPortSignal(S,i*2+1);
            y[0]=0;
        }
        else if ((int_T)RWork[i+1]<0)
        {
            y = ssGetOutputPortSignal(S,i*2);
            y[0]=0;
            y = ssGetOutputPortSignal(S,i*2+1);
            y[0]=Output;
        }
        else
        {
            y = ssGetOutputPortSignal(S,i*2);
            y[0]=0;
            y = ssGetOutputPortSignal(S,i*2+1);
            y[0]=0;
        }  
    }        
    //ssPrintf("\n");
    RWork[0]=RWork[0]+1;      
} /* end mdlOutputs */


static void mdlTerminate(SimStruct *S)
{
}
     
/*=============================*
 * Required S-function trailer *
 *=============================*/

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
