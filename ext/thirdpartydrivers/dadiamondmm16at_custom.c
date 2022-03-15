/* dadiamondmmx.c - xPC Target, non-inlined S-function driver for D/A section of Diamond Systems MM-16 series boards  */


#define     S_FUNCTION_LEVEL    2
#undef      S_FUNCTION_NAME
#define     S_FUNCTION_NAME     dadiamondmm16at_custom

#include    <stddef.h>
#include    <stdlib.h>

#include    "simstruc.h" 

#ifdef      MATLAB_MEX_FILE
#include    "mex.h"
#endif

#ifndef     MATLAB_MEX_FILE
#include    <windows.h>
#include    "xpctarget.h"
#endif

/* Input Arguments */
#define NUMBER_OF_ARGS          (6)
#define CHANNEL_ARG             ssGetSFcnParam(S,0)
#define RANGE_ARG               ssGetSFcnParam(S,1)
#define FINAL_VAL_ARG			ssGetSFcnParam(S,2)
#define INIT_VAL_ARG            ssGetSFcnParam(S,3)
#define SAMP_TIME_ARG           ssGetSFcnParam(S,4)
#define BASE_ARG                ssGetSFcnParam(S,5)



#define SAMP_TIME_IND           (0)

#define NO_I_WORKS              (3)
#define BASE_I_IND              (0)
#define NCHANNELS_I_IND         (1)
#define FINAL_VAL_I_IND         (2)


#define NO_R_WORKS              (2)
#define GAIN_R_IND              (0)
#define OFFSET_R_IND            (1)

// WRITE register offsets

#define DA_LSB_REGISTER		           (1)
#define DA_CHAN_0_MSB	               (4) 

// READ register offsets

#define DA_UPDATE_ALL                  (4)

#define RESOLUTION					   (4096)
#define MAX_COUNT					   (RESOLUTION - 1)



static char_T msg[256];

static void mdlInitializeSizes(SimStruct *S)
{
    size_t i;

    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S))
    {
        sprintf(msg,"Wrong number of input arguments passed.\n%d arguments are expected\n",NUMBER_OF_ARGS);
        ssSetErrorStatus(S,msg);
        return;
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    if( !ssSetNumInputPorts(S, (int_T)mxGetN(CHANNEL_ARG))) return;
    for( i = 0 ; i < mxGetN(CHANNEL_ARG) ; i++ )
    {
      ssSetInputPortWidth(S, i, 1);
      ssSetInputPortDirectFeedThrough(S, i, 1);
    }

    if( !ssSetNumOutputPorts(S, 0)) return;

    ssSetNumSampleTimes(S, 1);

    ssSetNumRWork(S, NO_R_WORKS);
    ssSetNumIWork(S, NO_I_WORKS);
    ssSetNumPWork(S, 0);

    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    for (i=0;i<NUMBER_OF_ARGS;i++)
    {
        ssSetSFcnParamNotTunable(S,i);
    }

    ssSetSimStateCompliance(S, HAS_NO_SIM_STATE);

    ssSetOptions(S, SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME | SS_OPTION_EXCEPTION_FREE_CODE);
}
 
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, mxGetPr(SAMP_TIME_ARG)[SAMP_TIME_IND]);
    ssSetOffsetTime(S, 0, 0.0);
}
 
#define MDL_START
static void mdlStart(SimStruct *S)
{

#ifndef MATLAB_MEX_FILE

    int_T   nChannels, range, channel, i, counts;
    uint16_T base;
    real_T  *RWork = ssGetRWork(S);
    int_T   *IWork = ssGetIWork(S);
    real_T  value;
        
    base = (int_T)mxGetPr(BASE_ARG)[0];    
    IWork[BASE_I_IND] = (int_T)base;

	nChannels = mxGetN(CHANNEL_ARG);
    IWork[NCHANNELS_I_IND] = nChannels;
	
	range = (uint_T)mxGetPr(RANGE_ARG)[0];
    switch (range)
    {
      case 1:
        RWork[GAIN_R_IND] = RESOLUTION/5.0;
        RWork[OFFSET_R_IND] = 0.0;
        break;
      case 2:
        RWork[GAIN_R_IND] = RESOLUTION/10;
        RWork[OFFSET_R_IND] = RESOLUTION/2;
        break;
	  default: 
        sprintf(msg, "bad range code %d", range); 
        ssSetErrorStatus(S, msg);
        return;
    }
	  

	 for (i=0 ; i < nChannels; i++)
        {
            channel = (int_T)mxGetPr(CHANNEL_ARG)[i]-1;
            value = (int_T)mxGetPr(INIT_VAL_ARG)[i];

            counts = (int_T)((value + RWork[OFFSET_R_IND]) * RWork[GAIN_R_IND]);
			
			if (counts < 0) counts = 0;
			if (counts > MAX_COUNT) counts = MAX_COUNT;
            
            xpcOutpB((uint16_T)(base + DA_LSB_REGISTER), (uint8_T)(((uint16_T)counts) & 0xff));
            xpcOutpB((uint16_T)(base + DA_CHAN_0_MSB + channel), (uint8_T)((counts >> 8) & 0x0f) );                    
        }
	 xpcInpB((uint16_T)(base + DA_UPDATE_ALL));
#endif                     
}

static void mdlOutputs(SimStruct *S)
{

#ifndef MATLAB_MEX_FILE

    int_T               channel, i, counts;
    uint16_T            base;
    InputRealPtrsType   uPtrs;
    real_T              *RWork=ssGetRWork(S);
    int_T               *IWork=ssGetIWork(S);
    real_T              value;   

    base=IWork[BASE_I_IND];

	 for (i=0 ; i < IWork[NCHANNELS_I_IND] ; i++)
        {
            channel = (int_T)mxGetPr(CHANNEL_ARG)[i]-1;
            uPtrs = ssGetInputPortRealSignalPtrs(S,i);
            value = *uPtrs[0];

            counts = (int_T)((value + RWork[OFFSET_R_IND]) * RWork[GAIN_R_IND]);
			
			if (counts < 0) counts = 0;
			if (counts > MAX_COUNT) counts = MAX_COUNT;
            
            xpcOutpB((uint16_T)(base + DA_LSB_REGISTER), (uint8_T)(((uint16_T)counts) & 0xff));
            xpcOutpB((uint16_T)(base + DA_CHAN_0_MSB + channel), (uint8_T)((counts >> 8) & 0x0f) );
        }

	 xpcInpB((uint16_T)(base + DA_UPDATE_ALL));
#endif        
}

static void mdlTerminate(SimStruct *S)
{   

#ifndef MATLAB_MEX_FILE

    int_T               channel, i, counts;
    uint16_T            base;
    real_T              *RWork=ssGetRWork(S);
    int_T               *IWork=ssGetIWork(S);
    real_T              value;   

    base=IWork[BASE_I_IND];

	if ((int_T)mxGetPr(FINAL_VAL_ARG)[0])
	{

	 for (i=0 ; i < IWork[NCHANNELS_I_IND] ; i++)
        {
            channel = (int_T)mxGetPr(CHANNEL_ARG)[i]-1;            

            counts = (int_T)((RWork[OFFSET_R_IND]) * RWork[GAIN_R_IND]);			

			if (counts < 0) counts = 0;
			if (counts > MAX_COUNT) counts = MAX_COUNT;

            xpcOutpB((uint16_T)(base + DA_LSB_REGISTER), (uint8_T)(((uint16_T)counts) & 0xff));
            xpcOutpB((uint16_T)(base + DA_CHAN_0_MSB + channel), (uint8_T)((counts >> 8) & 0x0f) );         
           
        }
	 xpcInpB((uint16_T)(base + DA_UPDATE_ALL));
	}
    
#endif

}

#ifdef MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
#include "simulink.c"   /* Mex glue */
#else
#include "cg_sfun.h"    /* Code generation glue */
#endif
