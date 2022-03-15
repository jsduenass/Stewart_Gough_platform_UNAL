// AD_diamond_mm_16_AT_custom_driver - xPC Target, non-inlined S-function driver 
// for A/D section of Diamond Systems MM-16-AT boards  

#define     S_FUNCTION_LEVEL    2								//Defining a level 2 S-function.
#undef      S_FUNCTION_NAME
#define     S_FUNCTION_NAME     addiamondmm16atcustom			//Describing Function S name

#include    <stddef.h>
#include    <stdlib.h>

#include    "simstruc.h" 

/*
 * Need to include simstruc.h for the definition of the SimStruct and
 * its associated macro definitions.
 *
 * The following headers are included by matlabroot/simulink/include/simstruc.h
 * when compiling as a MEX file:
 *
 *   matlabroot/extern/include/tmwtypes.h    - General types, e.g. real_T
 *   matlabroot/extern/include/mex.h         - MATLAB MEX file API routines
 *   matlabroot/extern/include/matrix.h      - MATLAB MEX file API routines
 *
 * The following headers are included by matlabroot/simulink/include/simstruc.h
 * when compiling your S-function with RTW:
 *
 *   matlabroot/extern/include/tmwtypes.h    - General types, e.g. real_T
 *   matlabroot/rtw/c/libsrc/rt_matrx.h      - Macros for MATLAB API routines
 *
 */


#ifdef      MATLAB_MEX_FILE			//MATLAB_MEX_FILE es defined when the file is compiled as a MEX file.
#include    "mex.h"
#endif

#ifndef     MATLAB_MEX_FILE
#include    <windows.h>
#include    "xpctarget.h"
#endif

// input arguments (S function parameters)
#define NUM_ARGS                       5						//Number of input arguments
#define FIRST_CHAN_ARG                 ssGetSFcnParam(S,0)		//Pointer to the First channel argument (mxArray *) - Double
#define NUM_CHANS_ARG                  ssGetSFcnParam(S,1)		//Pointer to the value of desired channels (mxArray *) - Double
#define RANGE_ARG                      ssGetSFcnParam(S,2)		//Pointer to the value of desired voltage range (mxArray *) - Double
#define SAMP_TIME_ARG                  ssGetSFcnParam(S,3)		//Pointer to the value of desired sample time (mxArray *) - Double
#define BASE_ARG                       ssGetSFcnParam(S,4)		//Pointer to the value of desired base address (mxArray *) - Double

// write register offsets - (See diamond-16-AT datasheet - Register definitions)
#define START_AD_CONVERTION_REG	       (0)						//Start A/D Conversion
#define SELECT_INPUT_CHANNELS_REG      (2)						
#define STATUS_REGISTER				   (8)
#define CONTROL_REGISTER			   (9)
#define FIFO_CONTROL_REGISTERR		   (10)
#define INPUT_RANGE_REG		           (11)


// read register offsets
#define AD_LSB						   (0)						//A/D LSB
#define AD_MSB						   (1)
#define WAIT_CONVERTION_TO_FINISH_REG  (8)
#define FIFO_STATUS_REGISTER		   (10)

#define NUM_R_WORKS                    (2)
#define GAIN_R_IND                     (0)
#define OFFSET_R_IND                   (1)
#define NUM_I_WORKS                    (1)

#define SAMP_TIME_IND                  (0)
#define RESETS_I_IND                   (0)

#define RESOLUTION					    65536

static char_T msg[256];

static void mdlInitializeSizes(SimStruct *S)		//Revied
{
	
	int_T  i;
    int_T nChans = (int_T)mxGetPr(NUM_CHANS_ARG)[0];	
    ssSetNumSFcnParams(S, NUM_ARGS);	

    if (NUM_ARGS != ssGetSFcnParamsCount(S)) {
        sprintf(msg, "%d input args expected, %d passed", 
            NUM_ARGS, ssGetSFcnParamsCount(S));
        ssSetErrorStatus(S, msg);
        return;
    }

    ssSetNumContStates(S,0);
    ssSetNumDiscStates(S,0);
    if (!ssSetNumInputPorts(S,0)) return;

    if (!ssSetNumOutputPorts(S, nChans)) return;

    for (i = 0; i < nChans; i++) {
        ssSetOutputPortWidth(S, i, 1);
    }

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, NUM_R_WORKS);
    ssSetNumIWork(S, NUM_I_WORKS);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    for (i = 0; i < NUM_ARGS; i++)
        ssSetSFcnParamTunable(S, i, 0);
    
	ssSetSimStateCompliance(S, HAS_NO_SIM_STATE);

    ssSetOptions(S, SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME | SS_OPTION_EXCEPTION_FREE_CODE);
}

 //reviewed
static void mdlInitializeSampleTimes(SimStruct *S) 
{
    if (mxGetPr(SAMP_TIME_ARG)[0] == -1.0) {
        ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
        ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);
    } else {
        ssSetSampleTime(S, 0, mxGetPr(SAMP_TIME_ARG)[0]);
        ssSetOffsetTime(S, 0, 0.0);
    }
}
 //Reviewed
#define MDL_START
static void mdlStart(SimStruct *S)
{
#ifndef MATLAB_MEX_FILE
#define WAIT (0x80)
#define FIFO_EMPTY  (0x01)

    real_T *RWork  = ssGetRWork(S);
    int_T   nChans = (int_T)mxGetPr(NUM_CHANS_ARG)[0]; 
    uint16_T  base = (uint16_T)mxGetPr(BASE_ARG)[0]; 
    int_T   range  = (int_T)mxGetPr(RANGE_ARG)[0];
    int_T   loChan = (int_T)mxGetPr(FIRST_CHAN_ARG)[0]-1;
    int_T   hiChan = loChan + nChans - 1;

    bool    ok;
    uint8_T code,test;
    int_T   i;
        
    switch (range) {
        case 1:  // -10V to +10V
            RWork[GAIN_R_IND] = 10.0 / (RESOLUTION / 2);
            RWork[OFFSET_R_IND] = 0;
            code =  8;				// 1000; Range, ADBU, G1, G0
            break;
        case 2:  // -5V to +5V
            RWork[GAIN_R_IND] = 5.0 / (RESOLUTION / 2);
            RWork[OFFSET_R_IND] = 0;
            code =  9;				// 1001; Range, ADBU, G1, G0
            break;
        case 3:  // -2.5V to +2.5V
            RWork[GAIN_R_IND] = 2.5 / (RESOLUTION / 2);
            RWork[OFFSET_R_IND] = 0;
            code =  10;				// 1010; Range, ADBU, G1, G0 
            break;
        case 4:  // -1.25V to +1.25V
            RWork[GAIN_R_IND] = 1.25 / (RESOLUTION / 2);
            RWork[OFFSET_R_IND] = 0;
            code =  11;				// 1011; Range, ADBU, G1, G0 
            break;
        case 5:  // -0.625V to +0.625V
            RWork[GAIN_R_IND] = 0.625 / (RESOLUTION / 2);
            RWork[OFFSET_R_IND] = 0;
            code =  3;				// 0011; Range, ADBU, G1, G0 
            break;
        case 6:  // 0 to +10V
            RWork[GAIN_R_IND] = 10.0 / RESOLUTION;
            RWork[OFFSET_R_IND] = RESOLUTION / 2;
            code = 12;				// 1100; Range, ADBU, G1, G0 
            break;
        case 7:  // 0V to +5V
            RWork[GAIN_R_IND] = 5.0 / RESOLUTION;
            RWork[OFFSET_R_IND] = RESOLUTION / 2;
            code = 13;				// 1101; Range, ADBU, G1, G0 
            break;
        case 8:  // 0V to +2.5V
            RWork[GAIN_R_IND] = 2.5 / RESOLUTION;
            RWork[OFFSET_R_IND] = RESOLUTION / 2;
            code = 14;				// 1110; Range, ADBU, G1, G0  
            break;
        case 9:  // 0V to +1.25V
            RWork[GAIN_R_IND] = 1.25 / RESOLUTION;
            RWork[OFFSET_R_IND] = RESOLUTION / 2;
            code = 15;				// 1111; Range, ADBU, G1, G0 ; 
            break;
        default: 
            printf("bad range param for MM-16-AT A/D: %d\n", range);
    }
	// write register offsets
//#define START_AD_CONVERTION_REG	       (0)
//#define SELECT_INPUT_CHANNELS_REG        (2)
//#define STATUS_REGISTER				   (8)	
//#define CONTROL_REGISTER			       (9)
//#define FIFO_CONTROL_REGISTERR		   (10)
//#define INPUT_RANGE_REG		           (11)	  
	
	// Reset FIFO:
    xpcOutpB((uint16_T)(base +  FIFO_CONTROL_REGISTERR), (uint8_T) 0x90); 

	// set high and low channels
	xpcOutpB((uint16_T)(base +  SELECT_INPUT_CHANNELS_REG), (uint8_T)((hiChan << 4) | loChan));

    // set input range for all channels
	xpcOutpB((uint16_T)(base +  INPUT_RANGE_REG), (uint8_T)code);


	
    /* wait for the analog input circuitry to settle */
    for (i = 0, ok = false; i < 2000 && !ok; i++) 
    {
        test = xpcInpB((uint16_T)(base + FIFO_STATUS_REGISTER));
        ok = ((test & WAIT) == 0);						//Ok=true when settle process has been finished
    }

    if (!ok) {
        sprintf(msg, "MM-16-AT does not respond - check conections");
        ssSetErrorStatus(S, msg);
        return;
	}
	

	// Clear Interrupt Request Flip Flop
    xpcOutpB((uint16_T)(base +  STATUS_REGISTER), (uint8_T) (0x00)); 

	// no interrupts, no DMA, no hardware A/D trigger:
    xpcOutpB((uint16_T)(base +  CONTROL_REGISTER), (uint8_T) (0x00)); 

	// Scan Enable:
    xpcOutpB((uint16_T)(base +  FIFO_CONTROL_REGISTERR), (uint8_T) 0x10); 	
	
	
	//Is FIFO empty?
	ok = ((xpcInpB((uint16_T)(base + FIFO_STATUS_REGISTER)) & FIFO_EMPTY) == 1);

	if (!ok) {
        sprintf(msg, "FIFO is not empty");
        ssSetErrorStatus(S, msg);
        return;
    
    }
#endif
}
 //Reviewed
static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE
#define IN_PROGRESS (0x80)			
#define FIFO_EMPTY  (0x01)

    real_T *RWork = ssGetRWork(S);
    real_T gain   = RWork[GAIN_R_IND];
    real_T offset = RWork[OFFSET_R_IND];
    uint_T base   = (uint_T)mxGetPr(BASE_ARG)[0];
    int_T nChans  = (int_T)mxGetPr(NUM_CHANS_ARG)[0];

    bool    ok;
    int_T   i, j, chan;
	int16_T count;
    real_T *y;

	for (ok = false, i = 0; !ok && i < 5; i++) {
        xpcOutpB((uint16_T)(base + START_AD_CONVERTION_REG), 0);
        for (j = 0; !ok && j < 1000; j++) 
            ok = ((xpcInpB((uint16_T)(base + WAIT_CONVERTION_TO_FINISH_REG)) & IN_PROGRESS) == 0);		//ok = true when convertion finish
    }

    if (!ok) {
        printf("Can't start A/D conversion on MM-16-AT\n");
        return;
    }
    
    for (chan = 0; chan < nChans; chan++) {

        y = ssGetOutputPortSignal(S, chan);

        for (ok = false, i = 0; !ok && i < 50; i++)
            ok = ((xpcInpB((uint16_T)(base + FIFO_STATUS_REGISTER)) & FIFO_EMPTY) == 0); // ok=true when fifo has data

        if (!ok) {
            int_T *IWork = ssGetIWork(S);
            IWork[RESETS_I_IND] += 1;			
			mdlStart(S);
            return;
        }
		
        count  =(xpcInpB((uint16_T)(base + AD_LSB)));
		count +=(xpcInpB((uint16_T)(base + AD_MSB))) << 8;

        y[0] = gain * (count + offset);             
    }
#endif
}
 //Reviewed
static void mdlTerminate(SimStruct *S)
{   
#ifndef MATLAB_MEX_FILE
    int_T *IWork  = ssGetIWork(S);
    int_T  resets = IWork[RESETS_I_IND];

    if (resets > 0)
        printf("MM-16-AT A/D had to be reset %d times\n", resets);
#endif
}






#ifdef MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
#include "simulink.c"   /* Mex glue */
#else
#include "cg_sfun.h"    /* Code generation glue */
#endif
