/*
 * sfuntmpl_basic.c: Basic 'C' template for a level 2 S-function.
 *
 *  -------------------------------------------------------------------------
 *  | See matlabroot/simulink/src/sfuntmpl_doc.c for a more detailed template |
 *  -------------------------------------------------------------------------
 *
 * Copyright 1990-2002 The MathWorks, Inc.
 * $Revision: 1.27.4.2 $
 */

// mex ForKinematics.c -LC:\Dropbox\Stewart-Gough\Matlab\Control\2013_04_24_Path_Replannig\codegen\lib\InverseKinematics\ -lInverseKinematics
/*
 * You must specify the S_FUNCTION_NAME as the name of your S-function
 * (i.e. replace sfuntmpl_basic with the name of your S-function).
 */

#define S_FUNCTION_NAME  ForKinematics
#define S_FUNCTION_LEVEL 2

/*
 * Need to include simstruc.h for the definition of the SimStruct and
 * its associated macro definitions.
 */
#include "simstruc.h"

//#include "codegen\lib\DirectKinematics\DirectKinematics.h"
//#include "codegen\lib\DirectKinematics\DirectKinematics.h"
//#include "codegen\lib\DirectKinematics\InverseKinematics.h"
//#include "codegen\lib\DirectKinematics\norm.h"
//#include "codegen\lib\DirectKinematics\mldivide.h"
#include "rtwtypesCustom.h"
//#include "DirectKinematics_types.h"


#define AI_PARAM(S) ssGetSFcnParam(S,0)
#define BI_PARAM(S) ssGetSFcnParam(S,1)
#define ACTUA(S)    ssGetSFcnParam(S,2)

typedef struct
{
    real_T ai[18];
    real_T bi[18];
} struct_T;

void DirectKinematics(const struct_T SG, real_T P[3], real_T aRb[9], const real_T Angles[3], const real_T di_ta[6], real_T C_aRb[9], real_T C_P[3], real_T C_Angles[3]);
void mldivide(const real_T A[36], real_T B[36]);
void InverseKinematics(const real_T SG_ai[18], const real_T SG_bi[18], const real_T P[3], const real_T aRb[9], real_T di[6], real_T Si[18]);
real_T norm(const real_T x[6]);



/* Error handling
 * --------------
 *
 * You should use the following technique to report errors encountered within
 * an S-function:
 *
 *       ssSetErrorStatus(S,"Error encountered due to ...");
 *       return;
 *
 * Note that the 2nd argument to ssSetErrorStatus must be persistent memory.
 * It cannot be a local variable. For example the following will cause
 * unpredictable errors:
 *
 *      mdlOutputs()
 *      {
 *         char msg[256];         {ILLEGAL: to fix use "static char msg[256];"}
 *         sprintf(msg,"Error due to %s", string);
 *         ssSetErrorStatus(S,msg);
 *         return;
 *      }
 *
 * See matlabroot/simulink/src/sfuntmpl_doc.c for more details.
 */

/*====================*
 * S-function methods *
 *====================*/

/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *    The sizes information is used by Simulink to determine the S-function
 *    block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct *S)
{
    /* See sfuntmpl_doc.c for more details on the macros below */

    ssSetNumSFcnParams(S, 3);  /* Number of expected parameters  SG.ai and SG.bi*/
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        /* Return if number of expected != number of actual parameters */
        return;
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    if (!ssSetNumInputPorts(S, 1)) return;
    ssSetInputPortWidth(S, 0, 6);
    //ssSetInputPortWidth(S, 1, 6);
    
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    //ssSetInputPortDirectFeedThrough(S, 1, 1);

    if (!ssSetNumOutputPorts(S, 1)) return;
    ssSetOutputPortWidth(S, 0, 6);

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    /* Specify the sim state compliance to be same as a built-in block */
    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);

    ssSetOptions(S, 0);
}



/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    This function is used to specify the sample time(s) for your
 *    S-function. You must register the same number of sample times as
 *    specified in ssSetNumSampleTimes.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);

}



#undef MDL_INITIALIZE_CONDITIONS   /* Change to #undef to remove function */
#if defined(MDL_INITIALIZE_CONDITIONS)
  /* Function: mdlInitializeConditions ========================================
   * Abstract:
   *    In this function, you should initialize the continuous and discrete
   *    states for your S-function block.  The initial states are placed
   *    in the state vector, ssGetContStates(S) or ssGetRealDiscStates(S).
   *    You can also perform any other initialization activities that your
   *    S-function may require. Note, this routine will be called at the
   *    start of simulation and if it is present in an enabled subsystem
   *    configured to reset states, it will be call when the enabled subsystem
   *    restarts execution to reset the states.
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



/* Function: mdlOutputs =======================================================
 * Abstract:
 *    In this function, you compute the outputs of your S-function
 *    block.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    
    InputRealPtrsType uPtrs1 = ssGetInputPortRealSignalPtrs(S,0);
    
    
    real_T       *y = ssGetOutputPortSignal(S,0);                   // Output port
    
    const real_T      *aipr     = mxGetPr(AI_PARAM(S));             //Parameter ai
    const real_T      *bipr     = mxGetPr(BI_PARAM(S));             //Parameter bi      
    real_T            *actuaOff = mxGetPr(ACTUA(S));                //Parameter actuaOffset 
        
    real_T      di[6] = {0};                                              //Actuatot length
    real_T      Si[18] = {0};                                             //Si unitary verctor
    
    
    real_T      PIni[3] = {0,0,0.7};
    real_T      aRbIni[9] = {1,0,0,0,1,0,0,0,1};  //[0 1 0; 1 0 0; 0 0 1];
    real_T      anglesIni[3] = {0,0,0};  //[0 1 0; 1 0 0; 0 0 1];
    
    real_T      PTa2[3] = {0};
    real_T      aRbTa2[9] = {0};  //[0 1 0; 1 0 0; 0 0 1];
    real_T      angleTa2[3] = {0};  //[0 1 0; 1 0 0; 0 0 1];
    
    //real_T  di_tar[6] = {*uPtrs1[0] + *actuaOff, *uPtrs1[1] + *actuaOff, *uPtrs1[2] + *actuaOff,*uPtrs1[3] + *actuaOff,*uPtrs1[4] + *actuaOff, *uPtrs1[5] + *actuaOff};
    real_T  di_tar[6] = {*uPtrs1[0]+*actuaOff, *uPtrs1[1]+*actuaOff, *uPtrs1[2]+*actuaOff, *uPtrs1[3]+*actuaOff, *uPtrs1[4]+*actuaOff, *uPtrs1[5]+*actuaOff};
            
    int_T i = 0;
    int_T j = 0;    
    
    struct_T InputSG;
        
    for (i = 0; i<6; i++)
    {
        for (j = 0; j<3; j++)
        {
            InputSG.ai[3*i + j] = aipr[3*i + j];
            InputSG.bi[3*i + j] = bipr[3*i + j];
        }        
    }
    
       
    //InverseKinematics (InputSG, PTa,aRbTa, di, Si);
    DirectKinematics(InputSG, PIni, aRbIni, anglesIni, di_tar, aRbTa2, PTa2, angleTa2);
            
    i = 0;
    y[0] = PTa2[0];
    y[1] = PTa2[1];
    y[2] = PTa2[2];
    y[3] = angleTa2[0];
    y[4] = angleTa2[1];
    y[5] = angleTa2[2];    
}



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
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{
}
//-------------------------CUSTOM CODE DIRECT KINEMATICS
void DirectKinematics(const struct_T SG, real_T P[3], real_T aRb[9], const
                      real_T Angles[3], const real_T di_ta[6], real_T C_aRb[9],
                      real_T C_P[3], real_T C_Angles[3])
{
  real_T unusedU0[18];
  real_T di_act[6];
  int32_T i0;
  real_T b_Angles[3];
  int32_T i;
  real_T errorA[6];
  real_T phi;
  real_T theta;
  real_T psii;
  boolean_T exitg1;
  real_T DX[6];
  real_T unusedU1[36];
  real_T y[3];
  int32_T i1;
  real_T b_y[3];
  static const real_T dv0[36] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  real_T Jxq[36];

  /* DIRECTKINEMATICS Summary of this function goes here */
  /*    Detailed explanation goes here */
  InverseKinematics(SG.ai, SG.bi, P, aRb, di_act, unusedU0);

  /* [di,Si]=InverseKinematics(SG,[0;0;0.4],[1,0,0;0,1,0;0,0,1]); */
  for (i0 = 0; i0 < 3; i0++) {
    b_Angles[i0] = Angles[i0];
  }

  for (i = 0; i < 6; i++) {
    errorA[i] = di_ta[i] - di_act[i];
  }

  phi = Angles[2];
  theta = Angles[1];
  psii = Angles[0];
  exitg1 = 0U;
  while ((exitg1 == 0U) && (norm(errorA) > 1.0E-9)) {
    /* JACOBIAN Summary of this function goes here */
    /*    Detailed explanation goes here */
    InverseKinematics(SG.ai, SG.bi, P, aRb, DX, unusedU0);
    memset((void *)&unusedU1[0], 0, 36U * sizeof(real_T));
    for (i = 0; i < 6; i++) {
      for (i0 = 0; i0 < 3; i0++) {
        y[i0] = 0.0;
        for (i1 = 0; i1 < 3; i1++) {
          y[i0] += aRb[i0 + 3 * i1] * SG.bi[i1 + 3 * i];
        }

        unusedU1[i + 6 * i0] = unusedU0[i0 + 3 * i];
      }

      b_y[0] = y[1] * unusedU0[2 + 3 * i] - y[2] * unusedU0[1 + 3 * i];
      b_y[1] = y[2] * unusedU0[3 * i] - y[0] * unusedU0[2 + 3 * i];
      b_y[2] = y[0] * unusedU0[1 + 3 * i] - y[1] * unusedU0[3 * i];
      for (i0 = 0; i0 < 3; i0++) {
        unusedU1[i + 6 * (i0 + 3)] = b_y[i0];
      }
    }

    memcpy((void *)&Jxq[0], (void *)&dv0[0], 36U * sizeof(real_T));
    mldivide(unusedU1, Jxq);

    /*  =>  Jxq=inv(Jx)*Jq; */
    for (i = 0; i < 6; i++) {
      errorA[i] = di_ta[i] - di_act[i];
    }

    if (norm(errorA) < 1.0E-9) {
      exitg1 = 1U;
    } else {
      for (i0 = 0; i0 < 6; i0++) {
        DX[i0] = 0.0;
        for (i1 = 0; i1 < 6; i1++) {
          DX[i0] += Jxq[i0 + 6 * i1] * errorA[i1];
        }
      }

      for (i0 = 0; i0 < 3; i0++) {
        b_Angles[i0] += DX[3 + i0];
        P[i0] += DX[i0];
      }

      /*  Atention to angle addition */
      /* Nomenclature for operation */
      phi = b_Angles[2];
      theta = b_Angles[1];
      psii = b_Angles[0];

      /* Rotation matrix based on Roll-Pitch-Yaw angles, review eq 1.48 TSAI */
      aRb[0] = cos(b_Angles[2]) * cos(b_Angles[1]);
      aRb[3] = cos(b_Angles[2]) * sin(b_Angles[1]) * sin(b_Angles[0]) - sin
        (b_Angles[2]) * cos(b_Angles[0]);
      aRb[6] = cos(b_Angles[2]) * sin(b_Angles[1]) * cos(b_Angles[0]) + sin
        (b_Angles[2]) * sin(b_Angles[0]);
      aRb[1] = sin(b_Angles[2]) * cos(b_Angles[1]);
      aRb[4] = sin(b_Angles[2]) * sin(b_Angles[1]) * sin(b_Angles[0]) + cos
        (b_Angles[2]) * cos(b_Angles[0]);
      aRb[7] = sin(b_Angles[2]) * sin(b_Angles[1]) * cos(b_Angles[0]) - cos
        (b_Angles[2]) * sin(b_Angles[0]);
      aRb[2] = -sin(b_Angles[1]);
      aRb[5] = cos(b_Angles[1]) * sin(b_Angles[0]);
      aRb[8] = cos(b_Angles[1]) * cos(b_Angles[0]);
      InverseKinematics(SG.ai, SG.bi, P, aRb, di_act, unusedU0);
    }
  }

  memcpy((void *)&C_aRb[0], (void *)&aRb[0], 9U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    C_P[i] = P[i];
  }

  C_Angles[0] = psii;
  C_Angles[1] = theta;
  C_Angles[2] = phi;
}

/* End of code generation (DirectKinematics.c) */

void mldivide(const real_T A[36], real_T B[36])
{
  real_T b_A[36];
  int32_T iy;
  int8_T ipiv[6];
  int32_T j;
  int32_T mmj;
  int32_T jj;
  int32_T jp1j;
  int32_T c;
  int32_T ix;
  real_T temp;
  int32_T k;
  real_T s;
  int32_T loop_ub;
  int32_T i;
  memcpy((void *)&b_A[0], (void *)&A[0], 36U * sizeof(real_T));
  for (iy = 0; iy < 6; iy++) {
    ipiv[iy] = (int8_T)(1 + iy);
  }

  for (j = 0; j < 5; j++) {
    mmj = -j;
    jj = j * 7;
    jp1j = jj + 1;
    c = mmj + 6;
    iy = 0;
    ix = jj;
    temp = fabs(b_A[jj]);
    for (k = 2; k <= c; k++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > temp) {
        iy = k - 1;
        temp = s;
      }
    }

    if (b_A[jj + iy] != 0.0) {
      if (iy != 0) {
        ipiv[j] = (int8_T)((j + iy) + 1);
        ix = j;
        iy += j;
        for (k = 0; k < 6; k++) {
          temp = b_A[ix];
          b_A[ix] = b_A[iy];
          b_A[iy] = temp;
          ix += 6;
          iy += 6;
        }
      }

      loop_ub = (jp1j + mmj) + 5;
      for (i = jp1j; i + 1 <= loop_ub; i++) {
        b_A[i] /= b_A[jj];
      }
    }

    c = 5 - j;
    iy = jj + 6;
    for (i = 1; i <= c; i++) {
      if (b_A[iy] != 0.0) {
        temp = b_A[iy] * -1.0;
        ix = jp1j;
        loop_ub = (mmj + jj) + 12;
        for (k = 7 + jj; k + 1 <= loop_ub; k++) {
          b_A[k] += b_A[ix] * temp;
          ix++;
        }
      }

      iy += 6;
      jj += 6;
    }
  }

  for (i = 0; i < 6; i++) {
    if (ipiv[i] != i + 1) {
      for (j = 0; j < 6; j++) {
        temp = B[i + 6 * j];
        B[i + 6 * j] = B[(ipiv[i] + 6 * j) - 1];
        B[(ipiv[i] + 6 * j) - 1] = temp;
      }
    }
  }

  for (j = 0; j < 6; j++) {
    c = 6 * j;
    for (k = 0; k < 6; k++) {
      iy = 6 * k;
      if (B[k + c] != 0.0) {
        for (i = k + 2; i < 7; i++) {
          B[(i + c) - 1] -= B[k + c] * b_A[(i + iy) - 1];
        }
      }
    }
  }

  for (j = 0; j < 6; j++) {
    c = 6 * j;
    for (k = 5; k > -1; k += -1) {
      iy = 6 * k;
      if (B[k + c] != 0.0) {
        B[k + c] /= b_A[k + iy];
        for (i = 0; i + 1 <= k; i++) {
          B[i + c] -= B[k + c] * b_A[i + iy];
        }
      }
    }
  }
}

/* End of code generation (mldivide.c) */

real_T norm(const real_T x[6])
{
  real_T y;
  real_T scale;
  boolean_T firstNonZero;
  int32_T k;
  real_T absxk;
  real_T t;
  y = 0.0;
  scale = 0.0;
  firstNonZero = TRUE;
  for (k = 0; k < 6; k++) {
    if (x[k] != 0.0) {
      absxk = fabs(x[k]);
      if (firstNonZero) {
        scale = absxk;
        y = 1.0;
        firstNonZero = FALSE;
      } else if (scale < absxk) {
        t = scale / absxk;
        y = 1.0 + y * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
    }
  }

  return scale * sqrt(y);
}

/* End of code generation (norm.c) */

void InverseKinematics(const real_T SG_ai[18], const real_T SG_bi[18], const
  real_T P[3], const real_T aRb[9], real_T di[6], real_T Si[18])
{
  int32_T i;
  int32_T k;
  real_T y;
  int32_T i2;
  real_T S[3];
  real_T scale;
  boolean_T firstNonZero;
  real_T absxk;
  real_T t;

  /*  The inverse kinematics provides the actuator's length, given the end */
  /*  efector's position. */
  for (i = 0; i < 6; i++) {
    di[i] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    for (k = 0; k < 3; k++) {
      y = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        y += aRb[k + 3 * i2] * SG_bi[i2 + 3 * i];
      }

      S[k] = (P[k] + y) - SG_ai[k + 3 * i];
    }

    y = 0.0;
    scale = 0.0;
    firstNonZero = TRUE;
    for (k = 0; k < 3; k++) {
      if (S[k] != 0.0) {
        absxk = fabs(S[k]);
        if (firstNonZero) {
          scale = absxk;
          y = 1.0;
          firstNonZero = FALSE;
        } else if (scale < absxk) {
          t = scale / absxk;
          y = 1.0 + y * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }
    }

    y = scale * sqrt(y);
    di[i] = y;
    for (k = 0; k < 3; k++) {
      Si[k + 3 * i] = S[k] / di[i];
    }
  }
}

/* End of code generation (InverseKinematics.c) */


/*======================================================*
 * See sfuntmpl_doc.c for the optional S-function methods *
 *======================================================*/

/*=============================*
 * Required S-function trailer *
 *=============================*/

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
