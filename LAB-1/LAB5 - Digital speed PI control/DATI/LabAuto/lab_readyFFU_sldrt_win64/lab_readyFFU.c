/*
 * lab_readyFFU.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab_readyFFU".
 *
 * Model version              : 2.5
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed May 25 15:21:36 2022
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab_readyFFU.h"
#include "lab_readyFFU_private.h"
#include "lab_readyFFU_dt.h"

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
B_lab_readyFFU_T lab_readyFFU_B;

/* Continuous states */
X_lab_readyFFU_T lab_readyFFU_X;

/* Block states (default storage) */
DW_lab_readyFFU_T lab_readyFFU_DW;

/* Real-time model */
static RT_MODEL_lab_readyFFU_T lab_readyFFU_M_;
RT_MODEL_lab_readyFFU_T *const lab_readyFFU_M = &lab_readyFFU_M_;
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
  (lab_readyFFU_M->Timing.TaskCounters.TID[2])++;
  if ((lab_readyFFU_M->Timing.TaskCounters.TID[2]) > 499) {/* Sample time: [0.5s, 0.0s] */
    lab_readyFFU_M->Timing.TaskCounters.TID[2] = 0;
  }

  lab_readyFFU_M->Timing.sampleHits[2] =
    (lab_readyFFU_M->Timing.TaskCounters.TID[2] == 0);
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
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  lab_readyFFU_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  lab_readyFFU_output();
  lab_readyFFU_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  lab_readyFFU_output();
  lab_readyFFU_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  lab_readyFFU_output();
  lab_readyFFU_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void lab_readyFFU_output(void)
{
  /* local block i/o variables */
  real_T rtb_Sum5;
  real_T rtb_AnalogInput[2];
  real_T rtb_Gain4;
  real_T rtb_Gain_j;
  real_T rtb_Sum6;
  uint8_T rtb_Output;
  if (rtmIsMajorTimeStep(lab_readyFFU_M)) {
    /* set solver stop time */
    if (!(lab_readyFFU_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab_readyFFU_M->solverInfo,
                            ((lab_readyFFU_M->Timing.clockTickH0 + 1) *
        lab_readyFFU_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab_readyFFU_M->solverInfo,
                            ((lab_readyFFU_M->Timing.clockTick0 + 1) *
        lab_readyFFU_M->Timing.stepSize0 + lab_readyFFU_M->Timing.clockTickH0 *
        lab_readyFFU_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab_readyFFU_M)) {
    lab_readyFFU_M->Timing.t[0] = rtsiGetT(&lab_readyFFU_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab_readyFFU_M) &&
      lab_readyFFU_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_readyFFU_P.AnalogInput_RangeMode;
      parm.rangeidx = lab_readyFFU_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                     lab_readyFFU_P.AnalogInput_Channels, &rtb_AnalogInput[0],
                     &parm);
    }
  }

  /* S-Function (sldrtei): '<Root>/Encoder Input' */
  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = lab_readyFFU_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &lab_readyFFU_P.EncoderInput_Channels, &rtb_Sum5, &parm);
  }

  if (rtmIsMajorTimeStep(lab_readyFFU_M) &&
      lab_readyFFU_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<Root>/Gain' incorporates:
     *  Sum: '<Root>/Add'
     */
    lab_readyFFU_B.ia = (rtb_AnalogInput[0] - rtb_AnalogInput[1]) *
      lab_readyFFU_P.Gain_Gain_j;
  }

  if (rtmIsMajorTimeStep(lab_readyFFU_M) &&
      lab_readyFFU_M->Timing.TaskCounters.TID[2] == 0) {
    /* UnitDelay: '<S5>/Output' */
    rtb_Output = lab_readyFFU_DW.Output_DSTATE;

    /* MultiPortSwitch: '<S4>/Output' incorporates:
     *  Constant: '<S4>/Vector'
     *  UnitDelay: '<S5>/Output'
     */
    lab_readyFFU_B.Output =
      lab_readyFFU_P.al_OutValues[lab_readyFFU_DW.Output_DSTATE];

    /* Product: '<S2>/Product2' incorporates:
     *  Constant: '<S2>/Constant'
     *  Gain: '<S2>/Gain2'
     *  Gain: '<S2>/Gain3'
     */
    lab_readyFFU_B.Product2 = (lab_readyFFU_P.mot.R +
      lab_readyFFU_P.sens.curr.Rs) * lab_readyFFU_P.gbox.N * lab_readyFFU_P.J_eq
      / (lab_readyFFU_P.drv.dcgain * lab_readyFFU_P.mot.Kt) *
      (lab_readyFFU_P.rpm2rads * lab_readyFFU_B.Output) *
      lab_readyFFU_P.Constant_Value;
  }

  /* Integrator: '<S1>/Integrator' */
  lab_readyFFU_B.Integrator = lab_readyFFU_X.Integrator_CSTATE;

  /* Gain: '<S2>/Gain1' */
  rtb_Gain_j = lab_readyFFU_P.rpm2rads * lab_readyFFU_B.Integrator;

  /* Signum: '<S2>/Sign' */
  if (rtb_Gain_j < 0.0) {
    rtb_Sum6 = -1.0;
  } else if (rtb_Gain_j > 0.0) {
    rtb_Sum6 = 1.0;
  } else if (rtb_Gain_j == 0.0) {
    rtb_Sum6 = 0.0;
  } else {
    rtb_Sum6 = (rtNaN);
  }

  /* End of Signum: '<S2>/Sign' */

  /* Sum: '<S2>/Sum6' incorporates:
   *  Gain: '<S2>/Gain6'
   *  Gain: '<S2>/Gain7'
   */
  rtb_Sum6 = lab_readyFFU_P.B_eq * 196.0 * rtb_Gain_j + lab_readyFFU_P.tausf *
    rtb_Sum6;

  /* Gain: '<S2>/Gain4' */
  rtb_Gain4 = lab_readyFFU_P.gbox.N * lab_readyFFU_P.mot.Ke /
    lab_readyFFU_P.drv.dcgain * rtb_Gain_j;

  /* Gain: '<Root>/pulse2deg' */
  lab_readyFFU_B.thl_meas = lab_readyFFU_P.sens.enc.pulse2deg * rtb_Sum5;
  if (rtmIsMajorTimeStep(lab_readyFFU_M) &&
      lab_readyFFU_M->Timing.TaskCounters.TID[1] == 0) {
    /* Delay: '<S3>/Delay' */
    lab_readyFFU_B.Delay = lab_readyFFU_DW.Delay_DSTATE[0];
  }

  /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Gain: '<S3>/Gain'
   *  Sum: '<S3>/Sum'
   *  TransferFcn: '<S3>/Transfer Fcn'
   *  TransferFcn: '<S3>/Transfer Fcn1'
   */
  switch ((int32_T)lab_readyFFU_P.Constant_Value_l) {
   case 1:
    rtb_Gain_j = lab_readyFFU_P.TransferFcn_C *
      lab_readyFFU_X.TransferFcn_CSTATE + lab_readyFFU_P.TransferFcn_D *
      lab_readyFFU_B.thl_meas;
    break;

   case 2:
    rtb_Gain_j = lab_readyFFU_P.TransferFcn1_C[0] *
      lab_readyFFU_X.TransferFcn1_CSTATE[0] + lab_readyFFU_P.TransferFcn1_C[1] *
      lab_readyFFU_X.TransferFcn1_CSTATE[1];
    break;

   default:
    rtb_Gain_j = (lab_readyFFU_B.thl_meas - lab_readyFFU_B.Delay) *
      lab_readyFFU_P.Gain_Gain;
    break;
  }

  /* End of MultiPortSwitch: '<S3>/Multiport Switch' */

  /* Gain: '<S3>/degs2rpm' */
  lab_readyFFU_B.degs2rpm = lab_readyFFU_P.degs2rpm * rtb_Gain_j;

  /* Sum: '<Root>/Sum' */
  lab_readyFFU_B.Sum = lab_readyFFU_B.Integrator - lab_readyFFU_B.degs2rpm;

  /* Gain: '<S2>/Gain' */
  rtb_Gain_j = lab_readyFFU_P.rpm2rads * lab_readyFFU_B.Sum;

  /* Sum: '<S2>/Sum5' incorporates:
   *  Constant: '<S2>/Constant'
   *  Gain: '<S2>/Gain5'
   *  Gain: '<S2>/P'
   *  Integrator: '<S2>/Integrator'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   *  Sum: '<S2>/Add'
   *  Sum: '<S2>/Sum3'
   *  Sum: '<S2>/Sum4'
   */
  rtb_Sum5 = lab_readyFFU_X.Integrator_CSTATE_a;
  rtb_Sum5 = ((lab_readyFFU_P.mot.R + lab_readyFFU_P.sens.curr.Rs) /
              (lab_readyFFU_P.mot.Kt * lab_readyFFU_P.gbox.N *
               lab_readyFFU_P.drv.dcgain) * rtb_Sum6 *
              lab_readyFFU_P.Constant_Value + ((lab_readyFFU_P.P_Gain *
    rtb_Gain_j + rtb_Sum5) + rtb_Gain4 * lab_readyFFU_P.Constant_Value)) +
    lab_readyFFU_B.Product2;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Sum5 > lab_readyFFU_P.Saturation_UpperSat) {
    /* Saturate: '<S2>/Saturation' */
    lab_readyFFU_B.Saturation = lab_readyFFU_P.Saturation_UpperSat;
  } else if (rtb_Sum5 < lab_readyFFU_P.Saturation_LowerSat) {
    /* Saturate: '<S2>/Saturation' */
    lab_readyFFU_B.Saturation = lab_readyFFU_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Saturation' */
    lab_readyFFU_B.Saturation = rtb_Sum5;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* S-Function (sldrtao): '<Root>/Analog Output' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_readyFFU_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_readyFFU_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab_readyFFU_P.AnalogOutput_Channels, ((real_T*)
        (&lab_readyFFU_B.Saturation)), &parm);
    }
  }

  if (rtmIsMajorTimeStep(lab_readyFFU_M) &&
      lab_readyFFU_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (rtmIsMajorTimeStep(lab_readyFFU_M) &&
      lab_readyFFU_M->Timing.TaskCounters.TID[2] == 0) {
    /* Sum: '<S6>/FixPt Sum1' incorporates:
     *  Constant: '<S6>/FixPt Constant'
     */
    rtb_Output = (uint8_T)((uint32_T)rtb_Output +
      lab_readyFFU_P.FixPtConstant_Value);

    /* Switch: '<S7>/FixPt Switch' */
    if (rtb_Output > lab_readyFFU_P.LimitedCounter_uplimit) {
      /* Switch: '<S7>/FixPt Switch' incorporates:
       *  Constant: '<S7>/Constant'
       */
      lab_readyFFU_B.FixPtSwitch = lab_readyFFU_P.Constant_Value_m;
    } else {
      /* Switch: '<S7>/FixPt Switch' */
      lab_readyFFU_B.FixPtSwitch = rtb_Output;
    }

    /* End of Switch: '<S7>/FixPt Switch' */
  }

  /* Sum: '<S2>/Sum1' incorporates:
   *  Gain: '<S2>/AWU gain'
   *  Gain: '<S2>/I'
   *  Sum: '<S2>/Sum2'
   */
  lab_readyFFU_B.Sum1 = lab_readyFFU_P.I_Gain * rtb_Gain_j - (rtb_Sum5 -
    lab_readyFFU_B.Saturation) * lab_readyFFU_P.AWUgain_Gain;
}

/* Model update function */
void lab_readyFFU_update(void)
{
  int_T idxDelay;
  if (rtmIsMajorTimeStep(lab_readyFFU_M) &&
      lab_readyFFU_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for UnitDelay: '<S5>/Output' */
    lab_readyFFU_DW.Output_DSTATE = lab_readyFFU_B.FixPtSwitch;
  }

  if (rtmIsMajorTimeStep(lab_readyFFU_M) &&
      lab_readyFFU_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Delay: '<S3>/Delay' */
    for (idxDelay = 0; idxDelay < 9; idxDelay++) {
      lab_readyFFU_DW.Delay_DSTATE[idxDelay] =
        lab_readyFFU_DW.Delay_DSTATE[idxDelay + 1];
    }

    lab_readyFFU_DW.Delay_DSTATE[9] = lab_readyFFU_B.thl_meas;

    /* End of Update for Delay: '<S3>/Delay' */
  }

  if (rtmIsMajorTimeStep(lab_readyFFU_M)) {
    rt_ertODEUpdateContinuousStates(&lab_readyFFU_M->solverInfo);
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
  if (!(++lab_readyFFU_M->Timing.clockTick0)) {
    ++lab_readyFFU_M->Timing.clockTickH0;
  }

  lab_readyFFU_M->Timing.t[0] = rtsiGetSolverStopTime
    (&lab_readyFFU_M->solverInfo);

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
    if (!(++lab_readyFFU_M->Timing.clockTick1)) {
      ++lab_readyFFU_M->Timing.clockTickH1;
    }

    lab_readyFFU_M->Timing.t[1] = lab_readyFFU_M->Timing.clockTick1 *
      lab_readyFFU_M->Timing.stepSize1 + lab_readyFFU_M->Timing.clockTickH1 *
      lab_readyFFU_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(lab_readyFFU_M) &&
      lab_readyFFU_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.5s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lab_readyFFU_M->Timing.clockTick2)) {
      ++lab_readyFFU_M->Timing.clockTickH2;
    }

    lab_readyFFU_M->Timing.t[2] = lab_readyFFU_M->Timing.clockTick2 *
      lab_readyFFU_M->Timing.stepSize2 + lab_readyFFU_M->Timing.clockTickH2 *
      lab_readyFFU_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void lab_readyFFU_derivatives(void)
{
  XDot_lab_readyFFU_T *_rtXdot;
  _rtXdot = ((XDot_lab_readyFFU_T *) lab_readyFFU_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = lab_readyFFU_B.Output;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += lab_readyFFU_P.TransferFcn_A *
    lab_readyFFU_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += lab_readyFFU_B.thl_meas;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += lab_readyFFU_P.TransferFcn1_A[0] *
    lab_readyFFU_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += lab_readyFFU_P.TransferFcn1_A[1] *
    lab_readyFFU_X.TransferFcn1_CSTATE[1];
  _rtXdot->TransferFcn1_CSTATE[1] += lab_readyFFU_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[0] += lab_readyFFU_B.thl_meas;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE_a = lab_readyFFU_B.Sum1;
}

/* Model initialize function */
void lab_readyFFU_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_readyFFU_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_readyFFU_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab_readyFFU_P.AnalogOutput_Channels,
                     &lab_readyFFU_P.AnalogOutput_InitialValue, &parm);
    }
  }

  {
    int32_T i;

    /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = lab_readyFFU_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                     &lab_readyFFU_P.EncoderInput_Channels, NULL, &parm);
    }

    /* InitializeConditions for UnitDelay: '<S5>/Output' */
    lab_readyFFU_DW.Output_DSTATE = lab_readyFFU_P.Output_InitialCondition;

    /* InitializeConditions for Integrator: '<S1>/Integrator' */
    lab_readyFFU_X.Integrator_CSTATE = lab_readyFFU_P.Integrator_IC;

    /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn' */
    lab_readyFFU_X.TransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn1' */
    lab_readyFFU_X.TransferFcn1_CSTATE[0] = 0.0;
    lab_readyFFU_X.TransferFcn1_CSTATE[1] = 0.0;

    /* InitializeConditions for Delay: '<S3>/Delay' */
    for (i = 0; i < 10; i++) {
      lab_readyFFU_DW.Delay_DSTATE[i] = lab_readyFFU_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S3>/Delay' */

    /* InitializeConditions for Integrator: '<S2>/Integrator' */
    lab_readyFFU_X.Integrator_CSTATE_a = lab_readyFFU_P.Integrator_IC_o;
  }
}

/* Model terminate function */
void lab_readyFFU_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_readyFFU_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_readyFFU_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab_readyFFU_P.AnalogOutput_Channels,
                     &lab_readyFFU_P.AnalogOutput_FinalValue, &parm);
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
  lab_readyFFU_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lab_readyFFU_update();
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
  lab_readyFFU_initialize();
}

void MdlTerminate(void)
{
  lab_readyFFU_terminate();
}

/* Registration function */
RT_MODEL_lab_readyFFU_T *lab_readyFFU(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  lab_readyFFU_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)lab_readyFFU_M, 0,
                sizeof(RT_MODEL_lab_readyFFU_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab_readyFFU_M->solverInfo,
                          &lab_readyFFU_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab_readyFFU_M->solverInfo, &rtmGetTPtr(lab_readyFFU_M));
    rtsiSetStepSizePtr(&lab_readyFFU_M->solverInfo,
                       &lab_readyFFU_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab_readyFFU_M->solverInfo, &lab_readyFFU_M->derivs);
    rtsiSetContStatesPtr(&lab_readyFFU_M->solverInfo, (real_T **)
                         &lab_readyFFU_M->contStates);
    rtsiSetNumContStatesPtr(&lab_readyFFU_M->solverInfo,
      &lab_readyFFU_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab_readyFFU_M->solverInfo,
      &lab_readyFFU_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab_readyFFU_M->solverInfo,
      &lab_readyFFU_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab_readyFFU_M->solverInfo,
      &lab_readyFFU_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab_readyFFU_M->solverInfo, (&rtmGetErrorStatus
      (lab_readyFFU_M)));
    rtsiSetRTModelPtr(&lab_readyFFU_M->solverInfo, lab_readyFFU_M);
  }

  rtsiSetSimTimeStep(&lab_readyFFU_M->solverInfo, MAJOR_TIME_STEP);
  lab_readyFFU_M->intgData.y = lab_readyFFU_M->odeY;
  lab_readyFFU_M->intgData.f[0] = lab_readyFFU_M->odeF[0];
  lab_readyFFU_M->intgData.f[1] = lab_readyFFU_M->odeF[1];
  lab_readyFFU_M->intgData.f[2] = lab_readyFFU_M->odeF[2];
  lab_readyFFU_M->intgData.f[3] = lab_readyFFU_M->odeF[3];
  lab_readyFFU_M->contStates = ((real_T *) &lab_readyFFU_X);
  rtsiSetSolverData(&lab_readyFFU_M->solverInfo, (void *)
                    &lab_readyFFU_M->intgData);
  rtsiSetSolverName(&lab_readyFFU_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab_readyFFU_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    lab_readyFFU_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab_readyFFU_M->Timing.sampleTimes =
      (&lab_readyFFU_M->Timing.sampleTimesArray[0]);
    lab_readyFFU_M->Timing.offsetTimes =
      (&lab_readyFFU_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab_readyFFU_M->Timing.sampleTimes[0] = (0.0);
    lab_readyFFU_M->Timing.sampleTimes[1] = (0.001);
    lab_readyFFU_M->Timing.sampleTimes[2] = (0.5);

    /* task offsets */
    lab_readyFFU_M->Timing.offsetTimes[0] = (0.0);
    lab_readyFFU_M->Timing.offsetTimes[1] = (0.0);
    lab_readyFFU_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(lab_readyFFU_M, &lab_readyFFU_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab_readyFFU_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    lab_readyFFU_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab_readyFFU_M, 15.0);
  lab_readyFFU_M->Timing.stepSize0 = 0.001;
  lab_readyFFU_M->Timing.stepSize1 = 0.001;
  lab_readyFFU_M->Timing.stepSize2 = 0.5;

  /* External mode info */
  lab_readyFFU_M->Sizes.checksums[0] = (302610291U);
  lab_readyFFU_M->Sizes.checksums[1] = (613734449U);
  lab_readyFFU_M->Sizes.checksums[2] = (498612381U);
  lab_readyFFU_M->Sizes.checksums[3] = (2809814487U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    lab_readyFFU_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab_readyFFU_M->extModeInfo,
      &lab_readyFFU_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab_readyFFU_M->extModeInfo,
                        lab_readyFFU_M->Sizes.checksums);
    rteiSetTPtr(lab_readyFFU_M->extModeInfo, rtmGetTPtr(lab_readyFFU_M));
  }

  lab_readyFFU_M->solverInfoPtr = (&lab_readyFFU_M->solverInfo);
  lab_readyFFU_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&lab_readyFFU_M->solverInfo, 0.001);
  rtsiSetSolverMode(&lab_readyFFU_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lab_readyFFU_M->blockIO = ((void *) &lab_readyFFU_B);
  (void) memset(((void *) &lab_readyFFU_B), 0,
                sizeof(B_lab_readyFFU_T));

  /* parameters */
  lab_readyFFU_M->defaultParam = ((real_T *)&lab_readyFFU_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab_readyFFU_X;
    lab_readyFFU_M->contStates = (x);
    (void) memset((void *)&lab_readyFFU_X, 0,
                  sizeof(X_lab_readyFFU_T));
  }

  /* states (dwork) */
  lab_readyFFU_M->dwork = ((void *) &lab_readyFFU_DW);
  (void) memset((void *)&lab_readyFFU_DW, 0,
                sizeof(DW_lab_readyFFU_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab_readyFFU_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab_readyFFU_M->Sizes.numContStates = (5);/* Number of continuous states */
  lab_readyFFU_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  lab_readyFFU_M->Sizes.numY = (0);    /* Number of model outputs */
  lab_readyFFU_M->Sizes.numU = (0);    /* Number of model inputs */
  lab_readyFFU_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab_readyFFU_M->Sizes.numSampTimes = (3);/* Number of sample times */
  lab_readyFFU_M->Sizes.numBlocks = (56);/* Number of blocks */
  lab_readyFFU_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  lab_readyFFU_M->Sizes.numBlockPrms = (55);/* Sum of parameter "widths" */
  return lab_readyFFU_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
