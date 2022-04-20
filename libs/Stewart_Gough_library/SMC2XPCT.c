
/*
 * You must specify the S_FUNCTION_NAME as the name of your S-function.
 */

#define S_FUNCTION_NAME  SMC2XPCT
#define S_FUNCTION_LEVEL 2
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
#include "simstruc.h"

#ifdef      MATLAB_MEX_FILE			//MATLAB_MEX_FILE es defined when the file is compiled as a MEX file.
#include    "mex.h"
#endif

#ifndef     MATLAB_MEX_FILE
#include    <windows.h>
#include    "xpctarget.h"
#endif

//----------------------------SPECIFIC DEFINITIONS
#define NUM_INPUTS          2       //NUMBER OF INPUT PORTS, xdesired[3] and d_m[2]
/* Input Port  0 */
#define INPUT_0_WIDTH       3
#define INPUT_0_FEEDTHROUGH 1
/* Input Port  1 */
#define INPUT_1_WIDTH       2
#define INPUT_1_FEEDTHROUGH 1

#define NUM_OUTPUTS          2      //NUMBER OF OUTPUT PORTS, u[1] and s[1]
/* Output Port  0 */
#define OUTPUT_0_WIDTH       1
#define OUTPUT_0_FEEDTHROUGH 1
/* Output Port  1 */
#define OUTPUT_1_WIDTH       1
#define OUTPUT_1_FEEDTHROUGH 1

#define NPARAMS              3      //NUMBER OF INPUT PARAMETERS

#define SAMPLE_TIME_0        INHERITED_SAMPLE_TIME
#define NUM_DISC_STATES      0
#define NUM_CONT_STATES      0

#define PARAM_0(S) ssGetSFcnParam(S, 0)
#define PARAM_1(S) ssGetSFcnParam(S, 1)
#define PARAM_2(S) ssGetSFcnParam(S, 2)

/*====================================================================*
 * Parameter handling methods. These methods are not supported by RTW *
 *====================================================================*/

#undef MDL_CHECK_PARAMETERS   /* Change to #undef to remove function */
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
    static void mdlCheckParameters(SimStruct *S)
  {
  }
#endif /* MDL_CHECK_PARAMETERS */


#undef MDL_PROCESS_PARAMETERS   /* Change to #undef to remove function */
#if defined(MDL_PROCESS_PARAMETERS) && defined(MATLAB_MEX_FILE)
    static void mdlProcessParameters(SimStruct *S)
  {
  }
#endif /* MDL_PROCESS_PARAMETERS */

static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, NPARAMS);  /* Number of expected parameters \eta and \lambda*/
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        /*
         * If the the number of expected input parameters is not equal
         * to the number of parameters entered in the dialog box return.
         * Simulink will generate an error indicating that there is a
         * parameter mismatch.
         */
        ssSetErrorStatus(S,"Kaka");
        return;
    }
    ssSetNumContStates(S, NUM_CONT_STATES);   /* number of continuous states           */
    ssSetNumDiscStates(S, NUM_DISC_STATES);   /* number of discrete states             */

    /*
     * Configure the input ports. First set the number of input ports. 
     */
    if (!ssSetNumInputPorts(S, NUM_INPUTS)) return;      
    /*Input Port 0 */
    ssSetInputPortWidth(S,  0, INPUT_0_WIDTH); /* */
    ssSetInputPortDirectFeedThrough(S, 0, INPUT_0_FEEDTHROUGH);
    /*Input Port 1 */
    ssSetInputPortWidth(S,  1, INPUT_1_WIDTH); /* */
    ssSetInputPortDirectFeedThrough(S, 1, INPUT_1_FEEDTHROUGH);
    
     /*
     * Configure the output ports.
     */    
    if (!ssSetNumOutputPorts(S, NUM_OUTPUTS)) return;
    /* Output Port 0 */
    ssSetOutputPortWidth(S, 0, OUTPUT_0_WIDTH);  
    /* Output Port 1 */
    ssSetOutputPortWidth(S, 1, OUTPUT_1_WIDTH);
    

    /*
     * Set the number of sample times. This must be a positive, nonzero
     * integer indicating the number of sample times or it can be
     * PORT_BASED_SAMPLE_TIMES. For multi-rate S-functions, the
     * suggested approach to setting sample times is via the port
     * based sample times method. When you create a multirate
     * S-function, care needs to be taking to verify that when
     * slower tasks are preempted that your S-function correctly
     * manages data as to avoid race conditions. When port based
     * sample times are specified, the block cannot inherit a constant
     * sample time at any port.
     */
    ssSetNumSampleTimes(S, 1);   /* number of sample times                */

    /*
     * Set size of the work vectors.
     */
    ssSetNumRWork(         S, 0);   /* number of real work vector elements   */
    ssSetNumIWork(         S, 0);   /* number of integer work vector elements*/
    ssSetNumPWork(         S, 0);   /* number of pointer work vector elements*/
    ssSetNumModes(         S, 0);   /* number of mode work vector elements   */
    ssSetNumNonsampledZCs( S, 0);   /* number of nonsampled zero crossings   */

    /* Specify the sim state compliance to be same as a built-in block */
    /* see sfun_simstate.c for example of other possible settings */
    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);

    /*
     * All options have the form SS_OPTION_<name> and are documented in
     * matlabroot/simulink/include/simstruc.h. The options should be
     * bitwise or'd together as in
     *   ssSetOptions(S, (SS_OPTION_name1 | SS_OPTION_name2))
     */

    ssSetOptions(S, 0);   /* general options (SS_OPTION_xx)        */

} /* end mdlInitializeSizes */


#undef MDL_SET_INPUT_PORT_FRAME_DATA  /* Change to #undef to remove function */
#if defined(MDL_SET_INPUT_PORT_FRAME_DATA) && defined(MATLAB_MEX_FILE)
  /* Function: mdlSetInputPortFrameData ========================================
   * Abstract:
   *    This method is called with the candidate frame setting (FRAME_YES, or
   *    FRAME_NO) for an input port. If the proposed setting is acceptable, 
   *    the method should go ahead and set the actual frame data setting using 
   *    ssSetInputPortFrameData(S,portIndex,frameData).  If
   *    the setting is unacceptable an error should generated via
   *    ssSetErrorStatus.  Note that any other dynamic frame input or
   *    output ports whose frame data setting are implicitly defined by virtue 
   *    of knowing the frame data setting of the given port can also have their
   *    frame data settings set via calls to ssSetInputPortFrameData and
   *    ssSetOutputPortFrameData.
   */
   static void mdlSetInputPortFrameData(SimStruct *S, 
                                        int       portIndex, 
                                        Frame_T   frameData)
  {
  } /* end mdlSetInputPortFrameData */
#endif /* MDL_SET_INPUT_PORT_FRAME_DATA */


#undef MDL_SET_INPUT_PORT_WIDTH   /* Change to #undef to remove function */
#if defined(MDL_SET_INPUT_PORT_WIDTH) && defined(MATLAB_MEX_FILE)
  /* Function: mdlSetInputPortWidth ===========================================
   * Abstract:
   *    This method is called with the candidate width for a dynamically
   *    sized port.  If the proposed width is acceptable, the method should
   *    go ahead and set the actual port width using ssSetInputPortWidth.  If
   *    the size is unacceptable an error should generated via
   *    ssSetErrorStatus.  Note that any other dynamically sized input or
   *    output ports whose widths are implicitly defined by virtue of knowing
   *    the width of the given port can also have their widths set via calls
   *    to ssSetInputPortWidth or ssSetOutputPortWidth.
   */
  static void mdlSetInputPortWidth(SimStruct *S, int portIndex, int width)
  {
  } /* end mdlSetInputPortWidth */
#endif /* MDL_SET_INPUT_PORT_WIDTH */


#undef MDL_SET_OUTPUT_PORT_WIDTH   /* Change to #undef to remove function */
#if defined(MDL_SET_OUTPUT_PORT_WIDTH) && defined(MATLAB_MEX_FILE)
  /* Function: mdlSetOutputPortWidth ==========================================
   * Abstract:
   *    This method is called with the candidate width for a dynamically
   *    sized port.  If the proposed width is acceptable, the method should
   *    go ahead and set the actual port width using ssSetOutputPortWidth.  If
   *    the size is unacceptable an error should generated via
   *    ssSetErrorStatus.  Note that any other dynamically sized input or
   *    output ports whose widths are implicitly defined by virtue of knowing
   *    the width of the given port can also have their widths set via calls
   *    to ssSetInputPortWidth or ssSetOutputPortWidth.
   */
  static void mdlSetOutputPortWidth(SimStruct *S, int portIndex, int width)
  {
  } /* end mdlSetOutputPortWidth */
#endif /* MDL_SET_OUTPUT_PORT_WIDTH */


#undef MDL_SET_INPUT_PORT_DIMENSION_INFO /* Change to #define to add function */
#if defined(MDL_SET_INPUT_PORT_DIMENSION_INFO) && defined(MATLAB_MEX_FILE)
  /* Function: mdlSetInputPortDimensionInfo ====================================
   * Abstract:
   *    This method is called with the candidate dimensions for an input port
   *    with unknown dimensions. If the proposed dimensions are acceptable, the 
   *    method should go ahead and set the actual port dimensions.  
   *    If they are unacceptable an error should be generated via 
   *    ssSetErrorStatus.  
   *    Note that any other input or output ports whose dimensions are  
   *    implicitly defined by virtue of knowing the dimensions of the given 
   *    port can also have their dimensions set.
   *
   *    See matlabroot/simulink/src/sfun_matadd.c for an example. 
   */
  static void mdlSetInputPortDimensionInfo(SimStruct        *S,         
                                           int_T            portIndex,
                                           const DimsInfo_T *dimsInfo)
  {
  } /* mdlSetInputPortDimensionInfo */
#endif /* MDL_SET_INPUT_PORT_DIMENSION_INFO */


#undef MDL_SET_OUTPUT_PORT_DIMENSION_INFO /* Change to #define to add function*/
#if defined(MDL_SET_OUTPUT_PORT_DIMENSION_INFO) && defined(MATLAB_MEX_FILE)
  /* Function: mdlSetOutputPortDimensionInfo ===================================
   * Abstract:
   *    This method is called with the candidate dimensions for an output port 
   *    with unknown dimensions. If the proposed dimensions are acceptable, the 
   *    method should go ahead and set the actual port dimensions.  
   *    If they are unacceptable an error should be generated via 
   *    ssSetErrorStatus.  
   *    Note that any other input or output ports whose dimensions are  
   *    implicitly defined by virtue of knowing the dimensions of the given 
   *    port can also have their dimensions set.
   *
   *    See matlabroot/simulink/src/sfun_matadd.c for an example. 
   */
  static void mdlSetOutputPortDimensionInfo(SimStruct        *S,        
                                            int_T            portIndex,
                                            const DimsInfo_T *dimsInfo)
  {
  } /* mdlSetOutputPortDimensionInfo */
#endif /* MDL_SET_OUTPUT_PORT_DIMENSION_INFO */


#undef MDL_SET_DEFAULT_PORT_DIMENSION_INFO /* Change to #define to add fcn */
#if defined(MDL_SET_DEFAULT_PORT_DIMENSION_INFO) && defined(MATLAB_MEX_FILE)
  /* Function: mdlSetDefaultPortDimensionInfo ==================================
   * Abstract:
   *    This method is called when there is not enough information in your
   *    model to uniquely determine the port dimensionality of signals
   *    entering or leaving your block. When this occurs, Simulink's
   *    dimension propagation engine calls this method to ask you to set
   *    your S-functions default dimensions for any input and output ports
   *    that are dynamically sized.
   *
   *    If you do not provide this method and you have dynamically sized ports
   *    where Simulink does not have enough information to propagate the
   *    dimensionality to your S-function, then Simulink will set these unknown
   *    ports to the 'block width' which is determined by examining any known
   *    ports. If there are no known ports, the width will be set to 1.
   *
   *    See matlabroot/simulink/src/sfun_matadd.c for an example. 
   */
  static void mdlSetDefaultPortDimensionInfo(SimStruct *S)
  {
  } /* mdlSetDefaultPortDimensionInfo */
#endif /* MDL_SET_DEFAULT_PORT_DIMENSION_INFO */


#undef MDL_SET_INPUT_PORT_SAMPLE_TIME
#if defined(MDL_SET_INPUT_PORT_SAMPLE_TIME) && defined(MATLAB_MEX_FILE)
  /* Function: mdlSetInputPortSampleTime =======================================
   * Abstract:
   *    This method is called with the candidate sample time for an inherited
   *    sample time input port. If the proposed sample time is acceptable, the
   *    method should go ahead and set the actual port sample time using
   *    ssSetInputPortSampleTime.  If the sample time is unacceptable an error
   *    should generated via ssSetErrorStatus.  Note that any other inherited
   *    input or output ports whose sample times are implicitly defined by
   *    virtue of knowing the sample time of the given port can also have
   *    their sample times set via calls to ssSetInputPortSampleTime or
   *    ssSetOutputPortSampleTime.
   *
   *    When inherited port based sample times are specified, we are guaranteed
   *    that the sample time will be one of the following:
   *                    [sampleTime, offsetTime]
   *       continuous   [0.0       , 0.0       ]
   *       discrete     [period    , offset    ]  where 0.0 < period < inf
   *                                                    0.0 <= offset < period
   *    Constant, triggered, and variable step sample times will not be
   *    propagated to S-functions with port based sample times.
   *
   *    Generally the mdlSetInputPortSampleTime or mdlSetOutputPortSampleTime
   *    is called once with the input port sample time. However, there can be
   *    cases where this function will be called more than once. This happens 
   *    when the simulation engine is converting continuous sample times to 
   *    continuous but fixed in minor steps sample times. When this occurs, the
   *    original values of the sample times specified in mdlInitializeSizes 
   *    will be restored before calling this method again. 
   *
   *    The final sample time specified at the port may be different (but
   *    equivalent to) from what was specified in this method. This occurs
   *    when:
   *      o) Using a fixed step solver and the port has a continuous but fixed
   *         in minor step sample time. In this case the sample time will
   *         be converted to the fundamental sample time for the model.
   *      o) We are adjusting sample times for numerical correctness. For 
   *         example [0.2499999999999, 0] is converted to [0.25, 0].
   *    S-functions are not explicitly notified of "converted" sample times.
   *    They can examine the final sample times in mdlInitializeSampleTimes.
   */
  static void mdlSetInputPortSampleTime(SimStruct *S,
                                        int_T     portIdx,
                                        real_T    sampleTime,
                                        real_T    offsetTime)
  {
  } /* end mdlSetInputPortSampleTime */
#endif /* MDL_SET_INPUT_PORT_SAMPLE_TIME */


#undef MDL_SET_OUTPUT_PORT_SAMPLE_TIME
#if defined(MDL_SET_OUTPUT_PORT_SAMPLE_TIME) && defined(MATLAB_MEX_FILE)
  /* Function: mdlSetOutputPortSampleTime ======================================
   * Abstract:
   *    This method is called with the candidate sample time for an inherited
   *    sample time output port. If the proposed sample time is acceptable, the
   *    method should go ahead and set the actual port sample time using
   *    ssSetOutputPortSampleTime.  If the sample time is unacceptable an error
   *    should generated via ssSetErrorStatus.  Note that any other inherited
   *    input or output ports whose sample times are implicitly defined by
   *    virtue of knowing the sample time of the given port can also have
   *    their sample times set via calls to ssSetInputPortSampleTime or
   *    ssSetOutputPortSampleTime.
   *
   *    Normally, sample times are propagated forwards, however if sources
   *    feeding this block have an inherited sample time, then Simulink
   *    may choose to back propagate known sample times to this block.
   *    When back propagating sample times, we call this method in succession
   *    for all inherited output port signals.
   *
   *    See mdlSetInputPortSampleTimes for more information about when this
   *    method is called.
   */
  static void mdlSetOutputPortSampleTime(SimStruct *S,
                                         int_T     portIdx,
                                         real_T    sampleTime,
                                         real_T    offsetTime)
  {
  } /* end mdlSetOutputPortSampleTime */
#endif /* MDL_SET_OUTPUT_PORT_SAMPLE_TIME */


/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *
 *    This function is used to specify the sample time(s) for your S-function.
 *    You must register the same number of sample times as specified in
 *    ssSetNumSampleTimes. If you specify that you have no sample times, then
 *    the S-function is assumed to have one inherited sample time.
 *
 *    The sample times are specified as pairs "[sample_time, offset_time]"
 *    via the following macros:
 *      ssSetSampleTime(S, sampleTimePairIndex, sample_time)
 *      ssSetOffsetTime(S, offsetTimePairIndex, offset_time)
 *    Where sampleTimePairIndex starts at 0.
 *
 *    The valid sample time pairs are (upper case values are macros defined
 *    in simstruc.h):
 *
 *      [CONTINUOUS_SAMPLE_TIME,  0.0                       ]
 *      [CONTINUOUS_SAMPLE_TIME,  FIXED_IN_MINOR_STEP_OFFSET]
 *      [discrete_sample_period,  offset                    ]
 *      [VARIABLE_SAMPLE_TIME  ,  0.0                       ]
 *
 *    Alternatively, you can specify that the sample time is inherited from the
 *    driving block in which case the S-function can have only one sample time
 *    pair:
 *
 *      [INHERITED_SAMPLE_TIME,  0.0                       ]
 *    or
 *      [INHERITED_SAMPLE_TIME,  FIXED_IN_MINOR_STEP_OFFSET]
 *
 *    The following guidelines may help aid in specifying sample times:
 *
 *      o A continuous function that changes during minor integration steps
 *        should register the [CONTINUOUS_SAMPLE_TIME, 0.0] sample time.
 *      o A continuous function that does not change during minor integration
 *        steps should register the
 *              [CONTINUOUS_SAMPLE_TIME, FIXED_IN_MINOR_STEP_OFFSET]
 *        sample time.
 *      o A discrete function that changes at a specified rate should register
 *        the discrete sample time pair
 *              [discrete_sample_period, offset]
 *        where
 *              discrete_sample_period > 0.0 and
 *              0.0 <= offset < discrete_sample_period
 *      o A discrete function that changes at a variable rate should
 *        register the variable step discrete [VARIABLE_SAMPLE_TIME, 0.0]
 *        sample time. The mdlGetTimeOfNextVarHit function is called to get
 *        the time of the next sample hit for the variable step discrete task.
 *        Note, the VARIABLE_SAMPLE_TIME can be used with variable step
 *        solvers only.
 *      o Discrete blocks which can operate in triggered subsystems.  For your 
 *        block to operate correctly in a triggered subsystem or a periodic 
 *        system it must register [INHERITED_SAMPLE_TIME, 0.0]. In a triggered
 *        subsystem after sample times have been propagated throughout the
 *        block diagram, the assigned sample time to the block will be 
 *        [INHERITED_SAMPLE_TIME, INHERITED_SAMPLE_TIME]. Typically discrete
 *        blocks which can be periodic or reside within triggered subsystems
 *        need to register the inherited sample time and the option
 *        SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME. Then in mdlSetWorkWidths, they
 *        need to verify that they were assigned a discrete or triggered
 *        sample time. To do this:
 *          mdlSetWorkWidths:
 *            if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME) {
 *              ssSetErrorStatus(S, "This block cannot be assigned a "
 *                               "continuous sample time");
 *            }
 *
 *    If your function has no intrinsic sample time, then you should indicate
 *    that your sample time is inherited according to the following guidelines:
 *
 *      o A function that changes as its input changes, even during minor
 *        integration steps should register the [INHERITED_SAMPLE_TIME, 0.0]
 *        sample time.
 *      o A function that changes as its input changes, but doesn't change
 *        during minor integration steps (i.e., held during minor steps) should
 *        register the [INHERITED_SAMPLE_TIME, FIXED_IN_MINOR_STEP_OFFSET]
 *        sample time.
 *
 *    To check for a sample hit during execution (in mdlOutputs or mdlUpdate),
 *    you should use the ssIsSampleHit or ssIsContinuousTask macros.
 *    For example, if your first sample time is continuous, then you
 *    used the following code-fragment to check for a sample hit. Note,
 *    you would get incorrect results if you used ssIsSampleHit(S,0,tid).
 *        if (ssIsContinuousTask(S,tid)) {
 *        }
 *    If say, you wanted to determine if the third (discrete) task has a hit,
 *    then you would use the following code-fragment:
 *        if (ssIsSampleHit(S,2,tid) {
 *        }
 *
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    /* Register one pair for each sample time */
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);

} /* end mdlInitializeSampleTimes */


#undef MDL_SET_INPUT_PORT_DATA_TYPE   /* Change to #undef to remove function */
#if defined(MDL_SET_INPUT_PORT_DATA_TYPE) && defined(MATLAB_MEX_FILE)
  /* Function: mdlSetInputPortDataType =========================================
   * Abstract:
   *    This method is called with the candidate data type id for a dynamically
   *    typed input port.  If the proposed data type is acceptable, the method
   *    should go ahead and set the actual port data type using
   *    ssSetInputPortDataType.  If the data type is unacceptable an error
   *    should generated via ssSetErrorStatus.  Note that any other dynamically
   *    typed input or output ports whose data types are implicitly defined by
   *    virtue of knowing the data type of the given port can also have their
   *    data types set via calls to ssSetInputPortDataType or 
   *    ssSetOutputPortDataType.  
   *
   *    See matlabroot/simulink/include/simstruc_types.h for built-in
   *    type defines: SS_DOUBLE, SS_BOOLEAN, etc.
   *
   *    See matlabroot/simulink/src/sfun_dtype_io.c for an example. 
   */
  static void mdlSetInputPortDataType(SimStruct *S, int portIndex,DTypeId dType)
  {
  } /* mdlSetInputPortDataType */
#endif /* MDL_SET_INPUT_PORT_DATA_TYPE */


#undef MDL_SET_OUTPUT_PORT_DATA_TYPE  /* Change to #undef to remove function */
#if defined(MDL_SET_OUTPUT_PORT_DATA_TYPE) && defined(MATLAB_MEX_FILE)
  /* Function: mdlSetOutputPortDataType ========================================
   * Abstract:
   *    This method is called with the candidate data type id for a dynamically
   *    typed output port.  If the proposed data type is acceptable, the method
   *    should go ahead and set the actual port data type using
   *    ssSetOutputPortDataType.  If the data type is unacceptable an error
   *    should generated via ssSetErrorStatus.  Note that any other dynamically
   *    typed input or output ports whose data types are implicitly defined by
   *    virtue of knowing the data type of the given port can also have their
   *    data types set via calls to ssSetInputPortDataType or 
   *    ssSetOutputPortDataType.  
   *
   *    See matlabroot/simulink/src/sfun_dtype_io.c for an example. 
   */
  static void mdlSetOutputPortDataType(SimStruct *S,int portIndex,DTypeId dType)
  {
  } /* mdlSetOutputPortDataType */
#endif /* MDL_SET_OUTPUT_PORT_DATA_TYPE */


#undef MDL_SET_DEFAULT_PORT_DATA_TYPES /* Change to #undef to remove function*/
#if defined(MDL_SET_DEFAULT_PORT_DATA_TYPES) && defined(MATLAB_MEX_FILE)
  /* Function:  mdlSetDefaultPortDataTypes =====================================
   * Abstract:
   *    This method is called when there is not enough information in your
   *    model to uniquely determine the input and output data types
   *    for your block. When this occurs, Simulink's data type propagation 
   *    engine calls this method to ask you to set your S-function default 
   *    data type for any dynamically typed input and output ports.
   *
   *    If you do not provide this method and you have dynamically typed
   *    ports where Simulink does not have enough information to propagate
   *    data types to your S-function, then Simulink will assign the
   *    data type to the largest known port data type of your S-function.
   *    If there are no known data types, then Simulink will set the
   *    data type to double.
   *
   *    See matlabroot/simulink/src/sfun_dtype_io.c for an example. 
   */
  static void mdlSetDefaultPortDataTypes(SimStruct *S)
  {
  } /* mdlSetDefaultPortDataTypes */
#endif /* MDL_SET_DEFAULT_PORT_DATA_TYPES */


#undef MDL_SET_INPUT_PORT_COMPLEX_SIGNAL   /* Change to #undef to remove */
#if defined(MDL_SET_INPUT_PORT_COMPLEX_SIGNAL) && defined(MATLAB_MEX_FILE)
  /* Function: mdlSetInputPortComplexSignal ====================================
   * Abstract:
   *    This method is called with the candidate complexity signal setting
   *    (COMPLEX_YES or COMPLEX_NO) for an input port whos complex signal
   *    attribute is set to COMPLEX_INHERITED. If the proposed complexity is
   *    acceptable, the method should go ahead and set the actual complexity
   *    using ssSetInputPortComplexSignal. If the complex setting is
   *    unacceptable an error should generated via ssSetErrorStatus.  Note that
   *    any other unknown ports whose complexity is implicitly defined by virtue
   *    of knowing the complexity of the given port can also have their
   *    complexity set via calls to ssSetInputPortComplexSignal or
   *    ssSetOutputPortComplexSignal.  
   *
   *    See matlabroot/simulink/src/sfun_cplx.c for an example. 
   */
  static void mdlSetInputPortComplexSignal(SimStruct *S, 
                                           int       portIndex, 
                                           CSignal_T cSignalSetting)
  {
  } /* mdlSetInputPortComplexSignal */
#endif /* MDL_SET_INPUT_PORT_COMPLEX_SIGNAL */


#undef MDL_SET_OUTPUT_PORT_COMPLEX_SIGNAL  /* Change to #undef to remove */
#if defined(MDL_SET_OUTPUT_PORT_COMPLEX_SIGNAL) && defined(MATLAB_MEX_FILE)
  /* Function: mdlSetOutputPortComplexSignal ===================================
   * Abstract:
   *    This method is called with the candidate complexity signal setting
   *    (COMPLEX_YES or COMPLEX_NO) for an output port whos complex signal
   *    attribute is set to COMPLEX_INHERITED. If the proposed complexity is
   *    acceptable, the method should go ahead and set the actual complexity
   *    using ssSetOutputPortComplexSignal. If the complex setting is
   *    unacceptable an error should generated via ssSetErrorStatus.  Note that
   *    any other unknown ports whose complexity is implicitly defined by virtue
   *    of knowing the complexity of the given port can also have their
   *    complexity set via calls to ssSetInputPortComplexSignal or
   *    ssSetOutputPortComplexSignal.  
   *
   *    See matlabroot/simulink/src/sfun_cplx.c for an example. 
   */
  static void mdlSetOutputPortComplexSignal(SimStruct *S, 
                                            int       portIndex, 
                                            CSignal_T cSignalSetting)
  {
  } /* mdlSetOutputPortComplexSignal */
#endif /* MDL_SET_OUTPUT_PORT_COMPLEX_SIGNAL */


#undef MDL_SET_DEFAULT_PORT_COMPLEX_SIGNALS /* Change to #undef to remove */
#if defined(MDL_SET_DEFAULT_PORT_COMPLEX_SIGNALS) && defined(MATLAB_MEX_FILE)
  /* Function:  mdlSetDefaultPortComplexSignals ================================
   * Abstract:
   *    This method is called when there is not enough information in your
   *    model to uniquely determine the complexity (COMPLEX_NO, COMPLEX_YES) 
   *    of signals entering your block. When this occurs, Simulink's 
   *    complex signal propagation engine calls this method to ask you to set
   *    your S-function default complexity type for any input and output ports
   *    who's complex signal attribute is set to COMPLEX_INHERITED.
   *
   *    If you do not provide this method and you have COMPLEX_INHERITED
   *    ports where Simulink does not have enough information to propagate
   *    the complexity to your S-function, then Simulink will set
   *    these unkown ports to COMPLEX_YES if any of your S-function
   *    ports are currently set to COMPLEX_YES, otherwise the unknown
   *    ports will be set to COMPLEX_NO.
   *
   *    See matlabroot/simulink/src/sfun_cplx.c for an example. 
   */
  static void mdlSetDefaultPortComplexSignals(SimStruct *S)
  {
  } /* mdlSetDefaultPortComplexSignals */
#endif /* MDL_SET_DEFAULT_PORT_COMPLEX_SIGNALS */


#undef MDL_SET_WORK_WIDTHS   /* Change to #undef to remove function */
#if defined(MDL_SET_WORK_WIDTHS) && defined(MATLAB_MEX_FILE)
  /* Function: mdlSetWorkWidths ===============================================
   * Abstract:
   *      The optional method, mdlSetWorkWidths is called after input port
   *      width, output port width, and sample times of the S-function have
   *      been determined to set any state and work vector sizes which are
   *      a function of the input, output, and/or sample times. This method
   *      is used to specify the nonzero work vector widths via the macros
   *      ssNumContStates, ssSetNumDiscStates, ssSetNumRWork, ssSetNumIWork,
   *      ssSetNumPWork, ssSetNumModes, and ssSetNumNonsampledZCs.
   *
   *      Run-time parameters are registered in this method using methods 
   *      ssSetNumRunTimeParams, ssSetRunTimeParamInfo, and related methods.
   *
   *      If you are using mdlSetWorkWidths, then any work vectors you are
   *      using in your S-function should be set to DYNAMICALLY_SIZED in
   *      mdlInitializeSizes, even if the exact value is known at that point.
   *      The actual size to be used by the S-function should then be specified
   *      in mdlSetWorkWidths.
   */
  static void mdlSetWorkWidths(SimStruct *S)
  {
  }
#endif /* MDL_SET_WORK_WIDTHS */


#undef MDL_INITIALIZE_CONDITIONS   /* Change to #undef to remove function */
#if defined(MDL_INITIALIZE_CONDITIONS)
  /* Function: mdlInitializeConditions ========================================
   * Abstract:
   *    In this function, you should initialize the continuous and discrete
   *    states for your S-function block.  The initial states are placed
   *    in the state vector, ssGetContStates(S) or ssGetDiscStates(S).
   *    You can also perform any other initialization activities that your
   *    S-function may require. Note, this method will be called at the
   *    start of simulation and if it is present in an enabled subsystem
   *    configured to reset states, it will be call when the enabled subsystem
   *    restarts execution to reset the states.
   *
   *    You can use the ssIsFirstInitCond(S) macro to determine if this is
   *    is the first time mdlInitializeConditions is being called.
   */
  static void mdlInitializeConditions(SimStruct *S)
  {
  }
#endif /* MDL_INITIALIZE_CONDITIONS */


#undef MDL_START  /* Change to #undef to remove function */
#if defined(MDL_START)
  /* Function: mdlStart =======================================================
   * Abstract:
   *    This function is called once at start of model execution. If you
   *    have states that should be initialized once, this is the place
   *    to do it.
   */
  static void mdlStart(SimStruct *S)
  {
  }
#endif /*  MDL_START */


/* Define to indicate that this S-Function has the mdlG[S]etSimState mothods */
#undef MDL_SIM_STATE /* Change to #undef to remove this function */
#if defined(MDL_SIM_STATE)
  /* Function: mdlGetSimState ===========================================
   * Abstract:
   *    Package complete simulation state (this includes all the run-time data
   *    that can change *after* mdlStart) as a MATLAB data structure and return
   *    it.
   */
  static mxArray* mdlGetSimState(SimStruct* S)
  {
  }

  /* Function: mdlSetSimState ===========================================
   * Abstract:
   *    Unack inSimState MATLAB data structure which contains the complete
   *    simulation state (this includes all the run-time data that can change
   *    *after* mdlStart) into the appropriate locations.
   */
  static void mdlSetSimState(SimStruct* S, const mxArray* inSimState)
  {
  }
#endif /* MDL_SIM_STATE */


#undef MDL_GET_TIME_OF_NEXT_VAR_HIT  /* Change to #undef to remove function */
#if defined(MDL_GET_TIME_OF_NEXT_VAR_HIT) && (defined(MATLAB_MEX_FILE) || \
                                              defined(NRT))
  /* Function: mdlGetTimeOfNextVarHit =========================================
   * Abstract:
   *    This function is called to get the time of the next variable sample
   *    time hit. This function is called once for every major integration time
   *    step. It must return time of next hit by using ssSetTNext. The time of
   *    the next hit must be greater than ssGetT(S).
   *
   *    Note, the time of next hit can be a function of the input signal(s).
   */

  static void mdlGetTimeOfNextVarHit(SimStruct *S)
  {
      time_T timeOfNextHit = ssGetT(S) /* + offset */ ;
      ssSetTNext(S, timeOfNextHit);
  }
#endif /* MDL_GET_TIME_OF_NEXT_VAR_HIT */


#undef MDL_ZERO_CROSSINGS   /* Change to #undef to remove function */
#if defined(MDL_ZERO_CROSSINGS) && (defined(MATLAB_MEX_FILE) || defined(NRT))
  /* Function: mdlZeroCrossings ===============================================
   * Abstract:
   *    If your S-function has registered CONTINUOUS_SAMPLE_TIME and there
   *    are signals entering the S-function or internally generated signals
   *    which have discontinuities, you can use this method to locate the
   *    discontinuities. When called, this method must update the
   *    ssGetNonsampleZCs(S) vector.
   */
  static void mdlZeroCrossings(SimStruct *S)
  {
  }
#endif /* MDL_ZERO_CROSSINGS */


/* Function: mdlOutputs =======================================================
 * Abstract:
 *    In this function, you compute the outputs of your S-function
 *    block. Generally outputs are placed in the output vector(s),
 *    ssGetOutputPortSignal.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    const int_T     F       = 15;     //set value to desired controller
    const int_T     bmax    = 75;     //set value to desired controller
    const int_T     bmin    = 35;     //set value to desired controller
    real_T          beta    = 0;
    real_T          bhat    = 0;
    real_T          fhat    = 0;
    real_T          uhat    = 0;
    real_T          k       = 0;
    real_T          sli     = 0;    
    real_T          signSli = 0;    
    InputRealPtrsType uPtrsXd = ssGetInputPortRealSignalPtrs(S,0);
    InputRealPtrsType uPtrsDm = ssGetInputPortRealSignalPtrs(S,1);
    real_T            *u    = ssGetOutputPortRealSignal(S,0);
    real_T            *u_s  = ssGetOutputPortRealSignal(S,1);
    const real_T *etaPtr    = mxGetPr(PARAM_0(S));
    const real_T *lambdaPtr = mxGetPr(PARAM_1(S));
    const real_T *tauPtr    = mxGetPr(PARAM_2(S));
    const real_T eta        = etaPtr[0];
    const real_T lambda     = lambdaPtr[0];
    const real_T tau        = tauPtr[0];
    real_T dm               = *uPtrsDm[0];
    real_T dmP              = *uPtrsDm[1];
    real_T xd               = *uPtrsXd[0];
    real_T xdP              = *uPtrsXd[1];
    real_T xdPP             = *uPtrsXd[2];
    
    beta = sqrt(bmax/bmin);
    bhat = sqrt(bmin*bmax);
    fhat = -tau*dmP;
    uhat = -fhat+xdPP-lambda*(dmP-xdP);
    k = beta*(F+eta)+(beta-1)*abs(uhat);
    sli = (dmP-xdP)+lambda*(dm-xd);
    
    signSli = sli/abs(sli);     //workout sign function
    if (sli == 0)
        signSli = 0;
    
    *u = (uhat-k*(signSli))/bhat;
    *u_s = sli;
    
    
    //*y = 2.0 *(*uPtrs[i]);
    
} /* end mdlOutputs */


#undef MDL_UPDATE  /* Change to #undef to remove function */
#if defined(MDL_UPDATE)
  /* Function: mdlUpdate ======================================================
   * Abstract:
   *    This function is called once for every major integration time step.
   *    Discrete states are typically updated here, but this function is useful
   *    for performing any tasks that should only take place once per
   *    integration step.
   */
  static void mdlUpdate(SimStruct *S, int_T tid)
  {
  }
#endif /* MDL_UPDATE */


#undef MDL_DERIVATIVES  /* Change to #undef to remove function */
#if defined(MDL_DERIVATIVES)
  /* Function: mdlDerivatives =================================================
   * Abstract:
   *    In this function, you compute the S-function block's derivatives.
   *    The derivatives are placed in the derivative vector, ssGetdX(S).
   */
  static void mdlDerivatives(SimStruct *S)
  {
  }
#endif /* MDL_DERIVATIVES */


/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was allocated
 *    in mdlStart, this is the place to free it.
 *
 *    Suppose your S-function allocates a few few chunks of memory in mdlStart
 *    and saves them in PWork. The following code fragment would free this
 *    memory.
 *        {
 *            int i;
 *            for (i = 0; i<ssGetNumPWork(S); i++) {
 *                if (ssGetPWorkValue(S,i) != NULL) {
 *                    free(ssGetPWorkValue(S,i));
 *                }
 *            }
 *        }
 */
static void mdlTerminate(SimStruct *S)
{
}


#undef MDL_RTW  /* Change to #undef to remove function */
#if defined(MDL_RTW) && defined(MATLAB_MEX_FILE)
  /* Function: mdlRTW =========================================================
   * Abstract:
   *
   *    This function is called when the Real-Time Workshop is generating
   *    the model.rtw file. In this method, you can call the following
   *    functions which add fields to the model.rtw file.
   *
   *    1) The following creates Parameter records for your S-functions.
   *       nParams is the number of tunable S-function parameters.
   *
   *       if ( !ssWriteRTWParameters(S, nParams,
   *
   *                                  SSWRITE_VALUE_[type],paramName,stringInfo,
   *                                  [type specific arguments below]
   *
   *                                 ) ) {
   *           return; (error reporting will be handled by SL)
   *       }
   *
   *       Where SSWRITE_VALUE_[type] can be one of the following groupings
   *       (and you must have "nParams" such groupings):
   *
   *         SSWRITE_VALUE_VECT,
   *           const char_T *paramName,
   *           const char_T *stringInfo,
   *           const real_T *valueVect,
   *           int_T        vectLen
   *
   *         SSWRITE_VALUE_2DMAT,
   *           const char_T *paramName,
   *           const char_T *stringInfo,
   *           const real_T *valueMat,
   *           int_T        nRows,
   *           int_T        nCols
   *
   *         SSWRITE_VALUE_DTYPE_VECT,
   *           const char_T   *paramName,
   *           const char_T   *stringInfo,
   *           const void     *valueVect,
   *           int_T          vectLen,
   *           int_T          dtInfo
   *
   *         SSWRITE_VALUE_DTYPE_2DMAT,
   *           const char_T   *paramName,
   *           const char_T   *stringInfo,
   *           const void     *valueMat,
   *           int_T          nRows,
   *           int_T          nCols,
   *           int_T          dtInfo
   *
   *         SSWRITE_VALUE_DTYPE_ML_VECT,
   *           const char_T   *paramName,
   *           const char_T   *stringInfo,
   *           const void     *rValueVect,
   *           const void     *iValueVect,
   *           int_T          vectLen,
   *           int_T          dtInfo
   *
   *         SSWRITE_VALUE_DTYPE_ML_2DMAT,
   *           const char_T   *paramName,
   *           const char_T   *stringInfo,
   *           const void     *rValueMat,
   *           const void     *iValueMat,
   *           int_T          nRows,
   *           int_T          nCols,
   *           int_T          dtInfo
   *
   *       Notes:
   *       1. nParams is an integer and stringInfo is a string describing
   *          generalinformation about the parameter such as how it was derived.
   *       2. The last argument to this function, dtInfo, is obtained from the
   *          DTINFO macro (defined in simstruc.h) as:
   *                 dtInfo = DTINFO(dataTypeId, isComplexSignal);
   *          where dataTypeId is the data type id and isComplexSignal is a
   *          boolean value specifying whether the parameter is complex.
   *
   *       See simulink/include/simulink.c for the definition (implementation)
   *       of this function and simulink/src/sfun_multiport.c for an example
   *       of using this function.
   *
   *    2) The following creates SFcnParameterSetting record for S-functions
   *       (these can be derived from the non-tunable S-function parameters).
   *
   *       if ( !ssWriteRTWParamSettings(S, nParamSettings,
   *
   *                                     SSWRITE_VALUE_[whatever], settingName,
   *                                     [type specific arguments below]
   *
   *                                    ) ) {
   *           return; (error reporting will be handled by SL)
   *       }
   *
   *       Where SSWRITE_VALUE_[type] can be one of the following groupings
   *       (and you must have "nParamSettings" such groupings):
   *       Also, the examples in the right hand column below show how the
   *       ParamSetting appears in the .rtw file
   *
   *         SSWRITE_VALUE_STR,              - Used to write (un)quoted strings
   *           const char_T *settingName,      example:
   *           const char_T *value,              Country      USA
   *
   *         SSWRITE_VALUE_QSTR,             - Used to write quoted strings
   *           const char_T *settingName,      example:
   *           const char_T *value,              Country      "U.S.A"
   *
   *         SSWRITE_VALUE_VECT_STR,         - Used to write vector of strings
   *           const char_T *settingName,      example:
   *           const char_T *value,              Countries    ["USA", "Mexico"]
   *           int_T        nItemsInVect
   *
   *         SSWRITE_VALUE_NUM,              - Used to write numbers
   *           const char_T *settingName,      example:
   *           const real_T value                 NumCountries  2
   *
   *
   *         SSWRITE_VALUE_VECT,             - Used to write numeric vectors
   *           const char_T *settingName,      example:
   *           const real_T *settingValue,       PopInMil        [300, 100]
   *           int_T        vectLen
   *
   *         SSWRITE_VALUE_2DMAT,            - Used to write 2D matrices
   *           const char_T *settingName,      example:
   *           const real_T *settingValue,       PopInMilBySex  Matrix(2,2)
   *           int_T        nRows,                   [[170, 130],[60, 40]]
   *           int_T        nCols
   *
   *         SSWRITE_VALUE_DTYPE_NUM,        - Used to write numeric vectors
   *           const char_T   *settingName,    example: int8 Num 3+4i
   *           const void     *settingValue,   written as: [3+4i]
   *           int_T          dtInfo
   *
   *
   *         SSWRITE_VALUE_DTYPE_VECT,       - Used to write data typed vectors
   *           const char_T   *settingName,    example: int8 CArray [1+2i 3+4i]
   *           const void     *settingValue,   written as:
   *           int_T          vectLen             CArray  [1+2i, 3+4i]
   *           int_T          dtInfo
   *
   *
   *         SSWRITE_VALUE_DTYPE_2DMAT,      - Used to write data typed 2D
   *           const char_T   *settingName     matrices
   *           const void     *settingValue,   example:
   *           int_T          nRow ,            int8 CMatrix  [1+2i 3+4i; 5 6]
   *           int_T          nCols,            written as:
   *           int_T          dtInfo               CMatrix         Matrix(2,2)
   *                                                [[1+2i, 3+4i]; [5+0i, 6+0i]]
   *
   *
   *         SSWRITE_VALUE_DTYPE_ML_VECT,    - Used to write complex matlab data
   *           const char_T   *settingName,    typed vectors example:
   *           const void     *settingRValue,  example: int8 CArray [1+2i 3+4i]
   *           const void     *settingIValue,      settingRValue: [1 3]
   *           int_T          vectLen              settingIValue: [2 4]
   *           int_T          dtInfo
   *                                             written as:
   *                                                CArray    [1+2i, 3+4i]
   *
   *         SSWRITE_VALUE_DTYPE_ML_2DMAT,   - Used to write matlab complex
   *           const char_T   *settingName,    data typed 2D matrices
   *           const void     *settingRValue,  example
   *           const void     *settingIValue,      int8 CMatrix [1+2i 3+4i; 5 6]
   *           int_T          nRows                settingRValue: [1 5 3 6]
   *           int_T          nCols,               settingIValue: [2 0 4 0]
   *           int_T          dtInfo
   *                                              written as:
   *                                              CMatrix         Matrix(2,2)
   *                                                [[1+2i, 3+4i]; [5+0i, 6+0i]]
   *
   *       Note, The examples above show how the ParamSetting is written out
   *       to the .rtw file
   *
   *       See simulink/include/simulink.c for the definition (implementation)
   *       of this function and simulink/src/sfun_multiport.c for an example
   *       of using this function.
   *
   *    3) The following creates the work vector records for S-functions
   *
   *       if (!ssWriteRTWWorkVect(S, vectName, nNames,
   *
   *                            name, size,   (must have nNames of these pairs)
   *                                 :
   *                           ) ) {
   *           return;  (error reporting will be handled by SL)
   *       }
   *
   *       Notes:
   *         a) vectName must be either "RWork", "IWork" or "PWork"
   *         b) nNames is an int_T (integer), name is a const char_T* (const
   *            char pointer) and size is int_T, and there must be nNames number
   *            of [name, size] pairs passed to the function.
   *         b) intSize1+intSize2+ ... +intSizeN = ssGetNum<vectName>(S)
   *            Recall that you would have to set ssSetNum<vectName>(S)
   *            in one of the initialization functions (mdlInitializeSizes
   *            or mdlSetWorkVectorWidths).
   *
   *       See simulink/include/simulink.c for the definition (implementation)
   *       of this function, and ... no example yet :(
   *
   *    4) Finally the following functions/macros give you the ability to write
   *       arbitrary strings and [name, value] pairs directly into the .rtw
   *       file.
   *
   *       if (!ssWriteRTWStr(S, const_char_*_string)) {
   *          return;
   *       }
   *
   *       if (!ssWriteRTWStrParam(S, const_char_*_name, const_char_*_value)) {
   *          return;
   *       }
   *
   *       if (!ssWriteRTWScalarParam(S, const_char_*_name, 
   *                                  const_void_*_value,
   *                                  DTypeId_dtypeId)) {
   *          return;
   *       }
   *
   *       if (!ssWriteRTWStrVectParam(S, const_char_*_name,
   *                                   const_char_*_value,
   *                                   int_num_items)) {
   *          return;
   *       }
   *
   *       if (!ssWriteRTWVectParam(S, const_char_*_name, const_void_*_value,
   *                                int_data_type_of_value, int_vect_len)){
   *          return;
   *       }
   *
   *       if (!ssWriteRTW2dMatParam(S, const_char_*_name, const_void_*_value,
   *                        int_data_type_of_value, int_nrows, int_ncols)){
   *          return;
   *       }
   *
   *       The 'data_type_of_value' input argument for the above two macros is
   *       obtained using
   *          DTINFO(dTypeId, isComplex),
   *       where
   *          dTypeId: can be any one of the enum values in BuitlInDTypeID
   *                   (SS_DOUBLE, SS_SINGLE, SS_INT8, SS_UINT8, SS_INT16,
   *                   SS_UINT16, SS_INT32, SS_UINT32, SS_BOOLEAN defined
   *                   in simstuc_types.h)
   *          isComplex: is either 0 or 1, as explained in Note-2 for
   *                    ssWriteRTWParameters.
   *
   *       For example DTINFO(SS_INT32,0) is a non-complex 32-bit signed
   *       integer.
   *
   *       If isComplex==1, then it is assumed that 'const_void_*_value' array
   *       has the real and imaginary parts arranged in an interleaved manner
   *       (i.e., Simulink Format).
   *
   *       If you prefer to pass the real and imaginary parts as two seperate
   *       arrays, you should use the follwing macros:
   *
   *       if (!ssWriteRTWMxVectParam(S, const_char_*_name,
   *                                  const_void_*_rvalue, const_void_*_ivalue,
   *                                  int_data_type_of_value, int_vect_len)){
   *          return;
   *       }
   *
   *       if (!ssWriteRTWMx2dMatParam(S, const_char_*_name,
   *                                   const_void_*_rvalue, const_void_*_ivalue,
   *                                   int_data_type_of_value,
   *                                   int_nrows, int_ncols)){
   *          return;
   *       }
   *
   *       See simulink/include/simulink.c and simstruc.h for the definition 
   *       (implementation) of these functions and simulink/src/ml2rtw.c for 
   *       examples of using these functions.
   *
   */
  static void mdlRTW(SimStruct *S)
  {
  }
#endif /* MDL_RTW */


/*=============================*
 * Required S-function trailer *
 *=============================*/

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
