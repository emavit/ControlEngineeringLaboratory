/*
 * lab_readyAWU.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab_readyAWU".
 *
 * Model version              : 2.9
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed May 25 15:45:16 2022
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab_readyAWU.h"
#include "lab_readyAWU_private.h"
#include "lab_readyAWU_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  2.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-6221", 4294967295U, 5, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_lab_readyAWU_T lab_readyAWU_B;

/* Continuous states */
X_lab_readyAWU_T lab_readyAWU_X;

/* Block states (default storage) */
DW_lab_readyAWU_T lab_readyAWU_DW;

/* Real-time model */
static RT_MODEL_lab_readyAWU_T lab_readyAWU_M_;
RT_MODEL_lab_readyAWU_T *const lab_readyAWU_M = &lab_readyAWU_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (lab_readyAWU_M->Timing.TaskCounters.TID[2])++;
  if ((lab_readyAWU_M->Timing.TaskCounters.TID[2]) > 2999) {/* Sample time: [3.0s, 0.0s] */
    lab_readyAWU_M->Timing.TaskCounters.TID[2] = 0;
  }

  lab_readyAWU_M->Timing.sampleHits[2] =
    (lab_readyAWU_M->Timing.TaskCounters.TID[2] == 0);
}

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  lab_readyAWU_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  lab_readyAWU_output();
  lab_readyAWU_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  lab_readyAWU_output();
  lab_readyAWU_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  lab_readyAWU_output();
  lab_readyAWU_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void lab_readyAWU_output(void)
{
  /* local block i/o variables */
  real_T rtb_Gain_l;
  real_T rtb_AnalogInput[2];
  real_T rtb_TransferFcn;
  uint8_T rtb_Output_m;
  if (rtmIsMajorTimeStep(lab_readyAWU_M)) {
    /* set solver stop time */
    if (!(lab_readyAWU_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab_readyAWU_M->solverInfo,
                            ((lab_readyAWU_M->Timing.clockTickH0 + 1) *
        lab_readyAWU_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab_readyAWU_M->solverInfo,
                            ((lab_readyAWU_M->Timing.clockTick0 + 1) *
        lab_readyAWU_M->Timing.stepSize0 + lab_readyAWU_M->Timing.clockTickH0 *
        lab_readyAWU_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab_readyAWU_M)) {
    lab_readyAWU_M->Timing.t[0] = rtsiGetT(&lab_readyAWU_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab_readyAWU_M) &&
      lab_readyAWU_M->Timing.TaskCounters.TID[2] == 0) {
    /* UnitDelay: '<S4>/Output' */
    rtb_Output_m = lab_readyAWU_DW.Output_DSTATE;

    /* SignalConversion: '<S1>/Out' incorporates:
     *  Constant: '<S1>/Vector'
     *  MultiPortSwitch: '<S1>/Output'
     *  UnitDelay: '<S4>/Output'
     */
    lab_readyAWU_B.Out =
      lab_readyAWU_P.u_OutValues[lab_readyAWU_DW.Output_DSTATE];
  }

  /* S-Function (sldrtei): '<Root>/Encoder Input' */
  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = lab_readyAWU_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &lab_readyAWU_P.EncoderInput_Channels, &rtb_Gain_l, &parm);
  }

  if (rtmIsMajorTimeStep(lab_readyAWU_M) &&
      lab_readyAWU_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_readyAWU_P.AnalogInput_RangeMode;
      parm.rangeidx = lab_readyAWU_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                     lab_readyAWU_P.AnalogInput_Channels, &rtb_AnalogInput[0],
                     &parm);
    }

    /* Delay: '<S3>/Delay' */
    lab_readyAWU_B.Delay = lab_readyAWU_DW.Delay_DSTATE[0];
  }

  /* Gain: '<Root>/pulse2deg' */
  lab_readyAWU_B.thl_meas = lab_readyAWU_P.sens.enc.pulse2deg * rtb_Gain_l;

  /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
   *  Constant: '<S3>/Constant'
   */
  switch ((int32_T)lab_readyAWU_P.Constant_Value) {
   case 1:
    /* Gain: '<S2>/Gain' incorporates:
     *  TransferFcn: '<S3>/Transfer Fcn'
     */
    rtb_Gain_l = lab_readyAWU_P.TransferFcn_C *
      lab_readyAWU_X.TransferFcn_CSTATE + lab_readyAWU_P.TransferFcn_D *
      lab_readyAWU_B.thl_meas;
    break;

   case 2:
    /* Gain: '<S2>/Gain' incorporates:
     *  TransferFcn: '<S3>/Transfer Fcn1'
     */
    rtb_Gain_l = lab_readyAWU_P.TransferFcn1_C[0] *
      lab_readyAWU_X.TransferFcn1_CSTATE[0] + lab_readyAWU_P.TransferFcn1_C[1] *
      lab_readyAWU_X.TransferFcn1_CSTATE[1];
    break;

   default:
    /* Gain: '<S2>/Gain' incorporates:
     *  Gain: '<S3>/Gain'
     *  Sum: '<S3>/Sum'
     */
    rtb_Gain_l = (lab_readyAWU_B.thl_meas - lab_readyAWU_B.Delay) *
      lab_readyAWU_P.Gain_Gain;
    break;
  }

  /* End of MultiPortSwitch: '<S3>/Multiport Switch' */

  /* Gain: '<S3>/degs2rpm' */
  lab_readyAWU_B.degs2rpm = lab_readyAWU_P.degs2rpm * rtb_Gain_l;

  /* Sum: '<Root>/Sum' */
  lab_readyAWU_B.Sum = lab_readyAWU_B.Out - lab_readyAWU_B.degs2rpm;

  /* Gain: '<S2>/Gain' */
  rtb_Gain_l = lab_readyAWU_P.rpm2rads * lab_readyAWU_B.Sum;

  /* Integrator: '<S2>/Integrator' */
  lab_readyAWU_B.Integrator = lab_readyAWU_X.Integrator_CSTATE;

  /* Sum: '<S2>/Add' incorporates:
   *  Gain: '<S2>/P'
   */
  rtb_TransferFcn = lab_readyAWU_P.P_Gain * rtb_Gain_l +
    lab_readyAWU_B.Integrator;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_TransferFcn > lab_readyAWU_P.Saturation_UpperSat) {
    /* Saturate: '<S2>/Saturation' */
    lab_readyAWU_B.Saturation = lab_readyAWU_P.Saturation_UpperSat;
  } else if (rtb_TransferFcn < lab_readyAWU_P.Saturation_LowerSat) {
    /* Saturate: '<S2>/Saturation' */
    lab_readyAWU_B.Saturation = lab_readyAWU_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Saturation' */
    lab_readyAWU_B.Saturation = rtb_TransferFcn;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* S-Function (sldrtao): '<Root>/Analog Output' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_readyAWU_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_readyAWU_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab_readyAWU_P.AnalogOutput_Channels, ((real_T*)
        (&lab_readyAWU_B.Saturation)), &parm);
    }
  }

  if (rtmIsMajorTimeStep(lab_readyAWU_M) &&
      lab_readyAWU_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (rtmIsMajorTimeStep(lab_readyAWU_M) &&
      lab_readyAWU_M->Timing.TaskCounters.TID[2] == 0) {
  }

  if (rtmIsMajorTimeStep(lab_readyAWU_M) &&
      lab_readyAWU_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (rtmIsMajorTimeStep(lab_readyAWU_M) &&
      lab_readyAWU_M->Timing.TaskCounters.TID[2] == 0) {
    /* Sum: '<S5>/FixPt Sum1' incorporates:
     *  Constant: '<S5>/FixPt Constant'
     */
    rtb_Output_m = (uint8_T)((uint32_T)rtb_Output_m +
      lab_readyAWU_P.FixPtConstant_Value);

    /* Switch: '<S6>/FixPt Switch' */
    if (rtb_Output_m > lab_readyAWU_P.LimitedCounter_uplimit) {
      /* Switch: '<S6>/FixPt Switch' incorporates:
       *  Constant: '<S6>/Constant'
       */
      lab_readyAWU_B.FixPtSwitch = lab_readyAWU_P.Constant_Value_l;
    } else {
      /* Switch: '<S6>/FixPt Switch' */
      lab_readyAWU_B.FixPtSwitch = rtb_Output_m;
    }

    /* End of Switch: '<S6>/FixPt Switch' */
  }

  if (rtmIsMajorTimeStep(lab_readyAWU_M) &&
      lab_readyAWU_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Sum: '<S2>/Sum1' incorporates:
   *  Gain: '<S2>/AWU gain'
   *  Gain: '<S2>/I'
   *  Sum: '<S2>/Sum2'
   */
  lab_readyAWU_B.Sum1 = lab_readyAWU_P.I_Gain * rtb_Gain_l - (rtb_TransferFcn -
    lab_readyAWU_B.Saturation) * lab_readyAWU_P.AWUgain_Gain;
  if (rtmIsMajorTimeStep(lab_readyAWU_M) &&
      lab_readyAWU_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<Root>/Gain' incorporates:
     *  Sum: '<Root>/Add'
     */
    lab_readyAWU_B.ia = (rtb_AnalogInput[0] - rtb_AnalogInput[1]) *
      lab_readyAWU_P.Gain_Gain_j;
  }

  if (rtmIsMajorTimeStep(lab_readyAWU_M) &&
      lab_readyAWU_M->Timing.TaskCounters.TID[2] == 0) {
  }
}

/* Model update function */
void lab_readyAWU_update(void)
{
  int_T idxDelay;
  if (rtmIsMajorTimeStep(lab_readyAWU_M) &&
      lab_readyAWU_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for UnitDelay: '<S4>/Output' */
    lab_readyAWU_DW.Output_DSTATE = lab_readyAWU_B.FixPtSwitch;
  }

  if (rtmIsMajorTimeStep(lab_readyAWU_M) &&
      lab_readyAWU_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Delay: '<S3>/Delay' */
    for (idxDelay = 0; idxDelay < 9; idxDelay++) {
      lab_readyAWU_DW.Delay_DSTATE[idxDelay] =
        lab_readyAWU_DW.Delay_DSTATE[idxDelay + 1];
    }

    lab_readyAWU_DW.Delay_DSTATE[9] = lab_readyAWU_B.thl_meas;

    /* End of Update for Delay: '<S3>/Delay' */
  }

  if (rtmIsMajorTimeStep(lab_readyAWU_M)) {
    rt_ertODEUpdateContinuousStates(&lab_readyAWU_M->solverInfo);
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
  if (!(++lab_readyAWU_M->Timing.clockTick0)) {
    ++lab_readyAWU_M->Timing.clockTickH0;
  }

  lab_readyAWU_M->Timing.t[0] = rtsiGetSolverStopTime
    (&lab_readyAWU_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lab_readyAWU_M->Timing.clockTick1)) {
      ++lab_readyAWU_M->Timing.clockTickH1;
    }

    lab_readyAWU_M->Timing.t[1] = lab_readyAWU_M->Timing.clockTick1 *
      lab_readyAWU_M->Timing.stepSize1 + lab_readyAWU_M->Timing.clockTickH1 *
      lab_readyAWU_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(lab_readyAWU_M) &&
      lab_readyAWU_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [3.0s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lab_readyAWU_M->Timing.clockTick2)) {
      ++lab_readyAWU_M->Timing.clockTickH2;
    }

    lab_readyAWU_M->Timing.t[2] = lab_readyAWU_M->Timing.clockTick2 *
      lab_readyAWU_M->Timing.stepSize2 + lab_readyAWU_M->Timing.clockTickH2 *
      lab_readyAWU_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void lab_readyAWU_derivatives(void)
{
  XDot_lab_readyAWU_T *_rtXdot;
  _rtXdot = ((XDot_lab_readyAWU_T *) lab_readyAWU_M->derivs);

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += lab_readyAWU_P.TransferFcn_A *
    lab_readyAWU_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += lab_readyAWU_B.thl_meas;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += lab_readyAWU_P.TransferFcn1_A[0] *
    lab_readyAWU_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += lab_readyAWU_P.TransferFcn1_A[1] *
    lab_readyAWU_X.TransferFcn1_CSTATE[1];
  _rtXdot->TransferFcn1_CSTATE[1] += lab_readyAWU_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[0] += lab_readyAWU_B.thl_meas;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = lab_readyAWU_B.Sum1;
}

/* Model initialize function */
void lab_readyAWU_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_readyAWU_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_readyAWU_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab_readyAWU_P.AnalogOutput_Channels,
                     &lab_readyAWU_P.AnalogOutput_InitialValue, &parm);
    }
  }

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S4>/Output' */
    lab_readyAWU_DW.Output_DSTATE = lab_readyAWU_P.Output_InitialCondition;

    /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = lab_readyAWU_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                     &lab_readyAWU_P.EncoderInput_Channels, NULL, &parm);
    }

    /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn' */
    lab_readyAWU_X.TransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn1' */
    lab_readyAWU_X.TransferFcn1_CSTATE[0] = 0.0;
    lab_readyAWU_X.TransferFcn1_CSTATE[1] = 0.0;

    /* InitializeConditions for Delay: '<S3>/Delay' */
    for (i = 0; i < 10; i++) {
      lab_readyAWU_DW.Delay_DSTATE[i] = lab_readyAWU_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S3>/Delay' */

    /* InitializeConditions for Integrator: '<S2>/Integrator' */
    lab_readyAWU_X.Integrator_CSTATE = lab_readyAWU_P.Integrator_IC;
  }
}

/* Model terminate function */
void lab_readyAWU_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_readyAWU_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_readyAWU_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab_readyAWU_P.AnalogOutput_Channels,
                     &lab_readyAWU_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  lab_readyAWU_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lab_readyAWU_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  lab_readyAWU_initialize();
}

void MdlTerminate(void)
{
  lab_readyAWU_terminate();
}

/* Registration function */
RT_MODEL_lab_readyAWU_T *lab_readyAWU(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  lab_readyAWU_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)lab_readyAWU_M, 0,
                sizeof(RT_MODEL_lab_readyAWU_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab_readyAWU_M->solverInfo,
                          &lab_readyAWU_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab_readyAWU_M->solverInfo, &rtmGetTPtr(lab_readyAWU_M));
    rtsiSetStepSizePtr(&lab_readyAWU_M->solverInfo,
                       &lab_readyAWU_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab_readyAWU_M->solverInfo, &lab_readyAWU_M->derivs);
    rtsiSetContStatesPtr(&lab_readyAWU_M->solverInfo, (real_T **)
                         &lab_readyAWU_M->contStates);
    rtsiSetNumContStatesPtr(&lab_readyAWU_M->solverInfo,
      &lab_readyAWU_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab_readyAWU_M->solverInfo,
      &lab_readyAWU_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab_readyAWU_M->solverInfo,
      &lab_readyAWU_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab_readyAWU_M->solverInfo,
      &lab_readyAWU_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab_readyAWU_M->solverInfo, (&rtmGetErrorStatus
      (lab_readyAWU_M)));
    rtsiSetRTModelPtr(&lab_readyAWU_M->solverInfo, lab_readyAWU_M);
  }

  rtsiSetSimTimeStep(&lab_readyAWU_M->solverInfo, MAJOR_TIME_STEP);
  lab_readyAWU_M->intgData.y = lab_readyAWU_M->odeY;
  lab_readyAWU_M->intgData.f[0] = lab_readyAWU_M->odeF[0];
  lab_readyAWU_M->intgData.f[1] = lab_readyAWU_M->odeF[1];
  lab_readyAWU_M->intgData.f[2] = lab_readyAWU_M->odeF[2];
  lab_readyAWU_M->intgData.f[3] = lab_readyAWU_M->odeF[3];
  lab_readyAWU_M->contStates = ((real_T *) &lab_readyAWU_X);
  rtsiSetSolverData(&lab_readyAWU_M->solverInfo, (void *)
                    &lab_readyAWU_M->intgData);
  rtsiSetSolverName(&lab_readyAWU_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab_readyAWU_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    lab_readyAWU_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab_readyAWU_M->Timing.sampleTimes =
      (&lab_readyAWU_M->Timing.sampleTimesArray[0]);
    lab_readyAWU_M->Timing.offsetTimes =
      (&lab_readyAWU_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab_readyAWU_M->Timing.sampleTimes[0] = (0.0);
    lab_readyAWU_M->Timing.sampleTimes[1] = (0.001);
    lab_readyAWU_M->Timing.sampleTimes[2] = (3.0);

    /* task offsets */
    lab_readyAWU_M->Timing.offsetTimes[0] = (0.0);
    lab_readyAWU_M->Timing.offsetTimes[1] = (0.0);
    lab_readyAWU_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(lab_readyAWU_M, &lab_readyAWU_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab_readyAWU_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    lab_readyAWU_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab_readyAWU_M, 5.0);
  lab_readyAWU_M->Timing.stepSize0 = 0.001;
  lab_readyAWU_M->Timing.stepSize1 = 0.001;
  lab_readyAWU_M->Timing.stepSize2 = 3.0;

  /* External mode info */
  lab_readyAWU_M->Sizes.checksums[0] = (2370962401U);
  lab_readyAWU_M->Sizes.checksums[1] = (3802593683U);
  lab_readyAWU_M->Sizes.checksums[2] = (3071745101U);
  lab_readyAWU_M->Sizes.checksums[3] = (2592010047U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    lab_readyAWU_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab_readyAWU_M->extModeInfo,
      &lab_readyAWU_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab_readyAWU_M->extModeInfo,
                        lab_readyAWU_M->Sizes.checksums);
    rteiSetTPtr(lab_readyAWU_M->extModeInfo, rtmGetTPtr(lab_readyAWU_M));
  }

  lab_readyAWU_M->solverInfoPtr = (&lab_readyAWU_M->solverInfo);
  lab_readyAWU_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&lab_readyAWU_M->solverInfo, 0.001);
  rtsiSetSolverMode(&lab_readyAWU_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lab_readyAWU_M->blockIO = ((void *) &lab_readyAWU_B);
  (void) memset(((void *) &lab_readyAWU_B), 0,
                sizeof(B_lab_readyAWU_T));

  /* parameters */
  lab_readyAWU_M->defaultParam = ((real_T *)&lab_readyAWU_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab_readyAWU_X;
    lab_readyAWU_M->contStates = (x);
    (void) memset((void *)&lab_readyAWU_X, 0,
                  sizeof(X_lab_readyAWU_T));
  }

  /* states (dwork) */
  lab_readyAWU_M->dwork = ((void *) &lab_readyAWU_DW);
  (void) memset((void *)&lab_readyAWU_DW, 0,
                sizeof(DW_lab_readyAWU_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab_readyAWU_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab_readyAWU_M->Sizes.numContStates = (4);/* Number of continuous states */
  lab_readyAWU_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  lab_readyAWU_M->Sizes.numY = (0);    /* Number of model outputs */
  lab_readyAWU_M->Sizes.numU = (0);    /* Number of model inputs */
  lab_readyAWU_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab_readyAWU_M->Sizes.numSampTimes = (3);/* Number of sample times */
  lab_readyAWU_M->Sizes.numBlocks = (42);/* Number of blocks */
  lab_readyAWU_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  lab_readyAWU_M->Sizes.numBlockPrms = (43);/* Sum of parameter "widths" */
  return lab_readyAWU_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
