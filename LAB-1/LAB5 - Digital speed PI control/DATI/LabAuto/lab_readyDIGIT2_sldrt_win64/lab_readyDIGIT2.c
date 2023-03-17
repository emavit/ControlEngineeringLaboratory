/*
 * lab_readyDIGIT2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab_readyDIGIT2".
 *
 * Model version              : 2.10
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed Jun  1 13:38:01 2022
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab_readyDIGIT2.h"
#include "lab_readyDIGIT2_private.h"
#include "lab_readyDIGIT2_dt.h"

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
B_lab_readyDIGIT2_T lab_readyDIGIT2_B;

/* Continuous states */
X_lab_readyDIGIT2_T lab_readyDIGIT2_X;

/* Block states (default storage) */
DW_lab_readyDIGIT2_T lab_readyDIGIT2_DW;

/* Real-time model */
static RT_MODEL_lab_readyDIGIT2_T lab_readyDIGIT2_M_;
RT_MODEL_lab_readyDIGIT2_T *const lab_readyDIGIT2_M = &lab_readyDIGIT2_M_;
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
  (lab_readyDIGIT2_M->Timing.TaskCounters.TID[2])++;
  if ((lab_readyDIGIT2_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.02s, 0.0s] */
    lab_readyDIGIT2_M->Timing.TaskCounters.TID[2] = 0;
  }

  lab_readyDIGIT2_M->Timing.sampleHits[2] =
    (lab_readyDIGIT2_M->Timing.TaskCounters.TID[2] == 0);
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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  lab_readyDIGIT2_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  lab_readyDIGIT2_output();
  lab_readyDIGIT2_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  lab_readyDIGIT2_output();
  lab_readyDIGIT2_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  lab_readyDIGIT2_output();
  lab_readyDIGIT2_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void lab_readyDIGIT2_output(void)
{
  /* local block i/o variables */
  real_T rtb_Add_e;
  real_T rtb_AnalogInput[2];
  if (rtmIsMajorTimeStep(lab_readyDIGIT2_M)) {
    /* set solver stop time */
    if (!(lab_readyDIGIT2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab_readyDIGIT2_M->solverInfo,
                            ((lab_readyDIGIT2_M->Timing.clockTickH0 + 1) *
        lab_readyDIGIT2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab_readyDIGIT2_M->solverInfo,
                            ((lab_readyDIGIT2_M->Timing.clockTick0 + 1) *
        lab_readyDIGIT2_M->Timing.stepSize0 +
        lab_readyDIGIT2_M->Timing.clockTickH0 *
        lab_readyDIGIT2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab_readyDIGIT2_M)) {
    lab_readyDIGIT2_M->Timing.t[0] = rtsiGetT(&lab_readyDIGIT2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab_readyDIGIT2_M) &&
      lab_readyDIGIT2_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_readyDIGIT2_P.AnalogInput_RangeMode;
      parm.rangeidx = lab_readyDIGIT2_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                     lab_readyDIGIT2_P.AnalogInput_Channels, &rtb_AnalogInput[0],
                     &parm);
    }
  }

  /* S-Function (sldrtei): '<Root>/Encoder Input' */
  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = lab_readyDIGIT2_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &lab_readyDIGIT2_P.EncoderInput_Channels, &rtb_Add_e, &parm);
  }

  if (rtmIsMajorTimeStep(lab_readyDIGIT2_M) &&
      lab_readyDIGIT2_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<Root>/Gain' incorporates:
     *  Sum: '<Root>/Add'
     */
    lab_readyDIGIT2_B.ia = (rtb_AnalogInput[0] - rtb_AnalogInput[1]) *
      lab_readyDIGIT2_P.Gain_Gain_j;
  }

  /* Step: '<Root>/Step' */
  if (lab_readyDIGIT2_M->Timing.t[0] < lab_readyDIGIT2_P.Step_Time) {
    /* Step: '<Root>/Step' */
    lab_readyDIGIT2_B.Step = lab_readyDIGIT2_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    lab_readyDIGIT2_B.Step = lab_readyDIGIT2_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Gain: '<Root>/pulse2deg1' */
  lab_readyDIGIT2_B.thl_meas = lab_readyDIGIT2_P.sens.enc.pulse2deg * rtb_Add_e;
  if (rtmIsMajorTimeStep(lab_readyDIGIT2_M) &&
      lab_readyDIGIT2_M->Timing.TaskCounters.TID[1] == 0) {
    /* Delay: '<S2>/Delay' */
    lab_readyDIGIT2_B.Delay = lab_readyDIGIT2_DW.Delay_DSTATE[0];
  }

  if (rtmIsMajorTimeStep(lab_readyDIGIT2_M) &&
      lab_readyDIGIT2_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
    lab_readyDIGIT2_DW.DiscreteTransferFcn_tmp = ((lab_readyDIGIT2_B.thl_meas -
      lab_readyDIGIT2_P.denF[1] * lab_readyDIGIT2_DW.DiscreteTransferFcn_states
      [0]) - lab_readyDIGIT2_P.denF[2] *
      lab_readyDIGIT2_DW.DiscreteTransferFcn_states[1]) /
      lab_readyDIGIT2_P.denF[0];

    /* DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
    lab_readyDIGIT2_B.DiscreteTransferFcn = (lab_readyDIGIT2_P.numF[0] *
      lab_readyDIGIT2_DW.DiscreteTransferFcn_tmp + lab_readyDIGIT2_P.numF[1] *
      lab_readyDIGIT2_DW.DiscreteTransferFcn_states[0]) +
      lab_readyDIGIT2_P.numF[2] * lab_readyDIGIT2_DW.DiscreteTransferFcn_states
      [1];
  }

  /* MultiPortSwitch: '<S2>/Multiport Switch' incorporates:
   *  Constant: '<S2>/Constant'
   */
  switch ((int32_T)lab_readyDIGIT2_P.Constant_Value) {
   case 1:
    /* Sum: '<S1>/Add' incorporates:
     *  TransferFcn: '<S2>/Transfer Fcn'
     */
    rtb_Add_e = lab_readyDIGIT2_P.TransferFcn_C *
      lab_readyDIGIT2_X.TransferFcn_CSTATE + lab_readyDIGIT2_P.TransferFcn_D *
      lab_readyDIGIT2_B.thl_meas;
    break;

   case 2:
    /* Sum: '<S1>/Add' incorporates:
     *  TransferFcn: '<S2>/Transfer Fcn1'
     */
    rtb_Add_e = lab_readyDIGIT2_P.TransferFcn1_C[0] *
      lab_readyDIGIT2_X.TransferFcn1_CSTATE[0] +
      lab_readyDIGIT2_P.TransferFcn1_C[1] *
      lab_readyDIGIT2_X.TransferFcn1_CSTATE[1];
    break;

   case 3:
    /* Sum: '<S1>/Add' incorporates:
     *  Gain: '<S2>/Gain'
     *  Sum: '<S2>/Sum'
     */
    rtb_Add_e = (lab_readyDIGIT2_B.thl_meas - lab_readyDIGIT2_B.Delay) *
      lab_readyDIGIT2_P.Gain_Gain;
    break;

   default:
    /* Sum: '<S1>/Add' */
    rtb_Add_e = lab_readyDIGIT2_B.DiscreteTransferFcn;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch' */

  /* Gain: '<S2>/degs2rpm' */
  lab_readyDIGIT2_B.degs2rpm = lab_readyDIGIT2_P.degs2rpm * rtb_Add_e;

  /* Sum: '<Root>/Sum1' */
  lab_readyDIGIT2_B.Sum1 = lab_readyDIGIT2_B.Step - lab_readyDIGIT2_B.degs2rpm;

  /* Sum: '<S1>/Add' incorporates:
   *  Gain: '<S1>/Gain'
   */
  rtb_Add_e = lab_readyDIGIT2_P.rpm2rads * lab_readyDIGIT2_B.Sum1;
  if (rtmIsMajorTimeStep(lab_readyDIGIT2_M) &&
      lab_readyDIGIT2_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S1>/AWU gain' incorporates:
     *  Delay: '<S1>/Delay'
     */
    lab_readyDIGIT2_B.AWUgain = lab_readyDIGIT2_P.AWUgain_Gain *
      lab_readyDIGIT2_DW.Delay_DSTATE_j;
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Gain: '<S1>/I'
   */
  lab_readyDIGIT2_B.Sum1_g = lab_readyDIGIT2_P.I_Gain * rtb_Add_e -
    lab_readyDIGIT2_B.AWUgain;
  if (rtmIsMajorTimeStep(lab_readyDIGIT2_M) &&
      lab_readyDIGIT2_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    lab_readyDIGIT2_B.DiscreteTimeIntegrator =
      lab_readyDIGIT2_P.DiscreteTimeIntegrator_gainval *
      lab_readyDIGIT2_B.Sum1_g +
      lab_readyDIGIT2_DW.DiscreteTimeIntegrator_DSTATE;
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Gain: '<S1>/P'
   */
  rtb_Add_e = lab_readyDIGIT2_P.P_Gain * rtb_Add_e +
    lab_readyDIGIT2_B.DiscreteTimeIntegrator;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Add_e > lab_readyDIGIT2_P.Saturation_UpperSat) {
    /* Saturate: '<S1>/Saturation' */
    lab_readyDIGIT2_B.Saturation = lab_readyDIGIT2_P.Saturation_UpperSat;
  } else if (rtb_Add_e < lab_readyDIGIT2_P.Saturation_LowerSat) {
    /* Saturate: '<S1>/Saturation' */
    lab_readyDIGIT2_B.Saturation = lab_readyDIGIT2_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S1>/Saturation' */
    lab_readyDIGIT2_B.Saturation = rtb_Add_e;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* S-Function (sldrtao): '<Root>/Analog Output' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_readyDIGIT2_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_readyDIGIT2_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab_readyDIGIT2_P.AnalogOutput_Channels, ((real_T*)
        (&lab_readyDIGIT2_B.Saturation)), &parm);
    }
  }

  if (rtmIsMajorTimeStep(lab_readyDIGIT2_M) &&
      lab_readyDIGIT2_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Sum: '<S1>/Sum2' */
  lab_readyDIGIT2_B.Sum2 = rtb_Add_e - lab_readyDIGIT2_B.Saturation;
}

/* Model update function */
void lab_readyDIGIT2_update(void)
{
  int_T idxDelay;
  if (rtmIsMajorTimeStep(lab_readyDIGIT2_M) &&
      lab_readyDIGIT2_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Delay: '<S2>/Delay' */
    for (idxDelay = 0; idxDelay < 9; idxDelay++) {
      lab_readyDIGIT2_DW.Delay_DSTATE[idxDelay] =
        lab_readyDIGIT2_DW.Delay_DSTATE[idxDelay + 1];
    }

    lab_readyDIGIT2_DW.Delay_DSTATE[9] = lab_readyDIGIT2_B.thl_meas;

    /* End of Update for Delay: '<S2>/Delay' */

    /* Update for Delay: '<S1>/Delay' */
    lab_readyDIGIT2_DW.Delay_DSTATE_j = lab_readyDIGIT2_B.Sum2;
  }

  if (rtmIsMajorTimeStep(lab_readyDIGIT2_M) &&
      lab_readyDIGIT2_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
    lab_readyDIGIT2_DW.DiscreteTransferFcn_states[1] =
      lab_readyDIGIT2_DW.DiscreteTransferFcn_states[0];
    lab_readyDIGIT2_DW.DiscreteTransferFcn_states[0] =
      lab_readyDIGIT2_DW.DiscreteTransferFcn_tmp;

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    lab_readyDIGIT2_DW.DiscreteTimeIntegrator_DSTATE =
      lab_readyDIGIT2_P.DiscreteTimeIntegrator_gainval *
      lab_readyDIGIT2_B.Sum1_g + lab_readyDIGIT2_B.DiscreteTimeIntegrator;
  }

  if (rtmIsMajorTimeStep(lab_readyDIGIT2_M)) {
    rt_ertODEUpdateContinuousStates(&lab_readyDIGIT2_M->solverInfo);
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
  if (!(++lab_readyDIGIT2_M->Timing.clockTick0)) {
    ++lab_readyDIGIT2_M->Timing.clockTickH0;
  }

  lab_readyDIGIT2_M->Timing.t[0] = rtsiGetSolverStopTime
    (&lab_readyDIGIT2_M->solverInfo);

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
    if (!(++lab_readyDIGIT2_M->Timing.clockTick1)) {
      ++lab_readyDIGIT2_M->Timing.clockTickH1;
    }

    lab_readyDIGIT2_M->Timing.t[1] = lab_readyDIGIT2_M->Timing.clockTick1 *
      lab_readyDIGIT2_M->Timing.stepSize1 +
      lab_readyDIGIT2_M->Timing.clockTickH1 *
      lab_readyDIGIT2_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(lab_readyDIGIT2_M) &&
      lab_readyDIGIT2_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lab_readyDIGIT2_M->Timing.clockTick2)) {
      ++lab_readyDIGIT2_M->Timing.clockTickH2;
    }

    lab_readyDIGIT2_M->Timing.t[2] = lab_readyDIGIT2_M->Timing.clockTick2 *
      lab_readyDIGIT2_M->Timing.stepSize2 +
      lab_readyDIGIT2_M->Timing.clockTickH2 *
      lab_readyDIGIT2_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void lab_readyDIGIT2_derivatives(void)
{
  XDot_lab_readyDIGIT2_T *_rtXdot;
  _rtXdot = ((XDot_lab_readyDIGIT2_T *) lab_readyDIGIT2_M->derivs);

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += lab_readyDIGIT2_P.TransferFcn_A *
    lab_readyDIGIT2_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += lab_readyDIGIT2_B.thl_meas;

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += lab_readyDIGIT2_P.TransferFcn1_A[0] *
    lab_readyDIGIT2_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += lab_readyDIGIT2_P.TransferFcn1_A[1] *
    lab_readyDIGIT2_X.TransferFcn1_CSTATE[1];
  _rtXdot->TransferFcn1_CSTATE[1] += lab_readyDIGIT2_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[0] += lab_readyDIGIT2_B.thl_meas;
}

/* Model initialize function */
void lab_readyDIGIT2_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_readyDIGIT2_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_readyDIGIT2_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab_readyDIGIT2_P.AnalogOutput_Channels,
                     &lab_readyDIGIT2_P.AnalogOutput_InitialValue, &parm);
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
      parm.infilter = lab_readyDIGIT2_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                     &lab_readyDIGIT2_P.EncoderInput_Channels, NULL, &parm);
    }

    /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn' */
    lab_readyDIGIT2_X.TransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn1' */
    lab_readyDIGIT2_X.TransferFcn1_CSTATE[0] = 0.0;
    lab_readyDIGIT2_X.TransferFcn1_CSTATE[1] = 0.0;

    /* InitializeConditions for Delay: '<S2>/Delay' */
    for (i = 0; i < 10; i++) {
      lab_readyDIGIT2_DW.Delay_DSTATE[i] =
        lab_readyDIGIT2_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S2>/Delay' */

    /* InitializeConditions for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
    lab_readyDIGIT2_DW.DiscreteTransferFcn_states[0] =
      lab_readyDIGIT2_P.DiscreteTransferFcn_InitialStates;
    lab_readyDIGIT2_DW.DiscreteTransferFcn_states[1] =
      lab_readyDIGIT2_P.DiscreteTransferFcn_InitialStates;

    /* InitializeConditions for Delay: '<S1>/Delay' */
    lab_readyDIGIT2_DW.Delay_DSTATE_j =
      lab_readyDIGIT2_P.Delay_InitialCondition_e;

    /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    lab_readyDIGIT2_DW.DiscreteTimeIntegrator_DSTATE =
      lab_readyDIGIT2_P.DiscreteTimeIntegrator_IC;
  }
}

/* Model terminate function */
void lab_readyDIGIT2_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_readyDIGIT2_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_readyDIGIT2_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab_readyDIGIT2_P.AnalogOutput_Channels,
                     &lab_readyDIGIT2_P.AnalogOutput_FinalValue, &parm);
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
  lab_readyDIGIT2_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lab_readyDIGIT2_update();
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
  lab_readyDIGIT2_initialize();
}

void MdlTerminate(void)
{
  lab_readyDIGIT2_terminate();
}

/* Registration function */
RT_MODEL_lab_readyDIGIT2_T *lab_readyDIGIT2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  lab_readyDIGIT2_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)lab_readyDIGIT2_M, 0,
                sizeof(RT_MODEL_lab_readyDIGIT2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab_readyDIGIT2_M->solverInfo,
                          &lab_readyDIGIT2_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab_readyDIGIT2_M->solverInfo, &rtmGetTPtr(lab_readyDIGIT2_M));
    rtsiSetStepSizePtr(&lab_readyDIGIT2_M->solverInfo,
                       &lab_readyDIGIT2_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab_readyDIGIT2_M->solverInfo, &lab_readyDIGIT2_M->derivs);
    rtsiSetContStatesPtr(&lab_readyDIGIT2_M->solverInfo, (real_T **)
                         &lab_readyDIGIT2_M->contStates);
    rtsiSetNumContStatesPtr(&lab_readyDIGIT2_M->solverInfo,
      &lab_readyDIGIT2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab_readyDIGIT2_M->solverInfo,
      &lab_readyDIGIT2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab_readyDIGIT2_M->solverInfo,
      &lab_readyDIGIT2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab_readyDIGIT2_M->solverInfo,
      &lab_readyDIGIT2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab_readyDIGIT2_M->solverInfo, (&rtmGetErrorStatus
      (lab_readyDIGIT2_M)));
    rtsiSetRTModelPtr(&lab_readyDIGIT2_M->solverInfo, lab_readyDIGIT2_M);
  }

  rtsiSetSimTimeStep(&lab_readyDIGIT2_M->solverInfo, MAJOR_TIME_STEP);
  lab_readyDIGIT2_M->intgData.y = lab_readyDIGIT2_M->odeY;
  lab_readyDIGIT2_M->intgData.f[0] = lab_readyDIGIT2_M->odeF[0];
  lab_readyDIGIT2_M->intgData.f[1] = lab_readyDIGIT2_M->odeF[1];
  lab_readyDIGIT2_M->intgData.f[2] = lab_readyDIGIT2_M->odeF[2];
  lab_readyDIGIT2_M->intgData.f[3] = lab_readyDIGIT2_M->odeF[3];
  lab_readyDIGIT2_M->contStates = ((real_T *) &lab_readyDIGIT2_X);
  rtsiSetSolverData(&lab_readyDIGIT2_M->solverInfo, (void *)
                    &lab_readyDIGIT2_M->intgData);
  rtsiSetSolverName(&lab_readyDIGIT2_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab_readyDIGIT2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    lab_readyDIGIT2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab_readyDIGIT2_M->Timing.sampleTimes =
      (&lab_readyDIGIT2_M->Timing.sampleTimesArray[0]);
    lab_readyDIGIT2_M->Timing.offsetTimes =
      (&lab_readyDIGIT2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab_readyDIGIT2_M->Timing.sampleTimes[0] = (0.0);
    lab_readyDIGIT2_M->Timing.sampleTimes[1] = (0.001);
    lab_readyDIGIT2_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    lab_readyDIGIT2_M->Timing.offsetTimes[0] = (0.0);
    lab_readyDIGIT2_M->Timing.offsetTimes[1] = (0.0);
    lab_readyDIGIT2_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(lab_readyDIGIT2_M, &lab_readyDIGIT2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab_readyDIGIT2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    lab_readyDIGIT2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab_readyDIGIT2_M, 4.0);
  lab_readyDIGIT2_M->Timing.stepSize0 = 0.001;
  lab_readyDIGIT2_M->Timing.stepSize1 = 0.001;
  lab_readyDIGIT2_M->Timing.stepSize2 = 0.02;

  /* External mode info */
  lab_readyDIGIT2_M->Sizes.checksums[0] = (1540410877U);
  lab_readyDIGIT2_M->Sizes.checksums[1] = (4092785936U);
  lab_readyDIGIT2_M->Sizes.checksums[2] = (128287738U);
  lab_readyDIGIT2_M->Sizes.checksums[3] = (2660204149U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    lab_readyDIGIT2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab_readyDIGIT2_M->extModeInfo,
      &lab_readyDIGIT2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab_readyDIGIT2_M->extModeInfo,
                        lab_readyDIGIT2_M->Sizes.checksums);
    rteiSetTPtr(lab_readyDIGIT2_M->extModeInfo, rtmGetTPtr(lab_readyDIGIT2_M));
  }

  lab_readyDIGIT2_M->solverInfoPtr = (&lab_readyDIGIT2_M->solverInfo);
  lab_readyDIGIT2_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&lab_readyDIGIT2_M->solverInfo, 0.001);
  rtsiSetSolverMode(&lab_readyDIGIT2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lab_readyDIGIT2_M->blockIO = ((void *) &lab_readyDIGIT2_B);
  (void) memset(((void *) &lab_readyDIGIT2_B), 0,
                sizeof(B_lab_readyDIGIT2_T));

  /* parameters */
  lab_readyDIGIT2_M->defaultParam = ((real_T *)&lab_readyDIGIT2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab_readyDIGIT2_X;
    lab_readyDIGIT2_M->contStates = (x);
    (void) memset((void *)&lab_readyDIGIT2_X, 0,
                  sizeof(X_lab_readyDIGIT2_T));
  }

  /* states (dwork) */
  lab_readyDIGIT2_M->dwork = ((void *) &lab_readyDIGIT2_DW);
  (void) memset((void *)&lab_readyDIGIT2_DW, 0,
                sizeof(DW_lab_readyDIGIT2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab_readyDIGIT2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab_readyDIGIT2_M->Sizes.numContStates = (3);/* Number of continuous states */
  lab_readyDIGIT2_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  lab_readyDIGIT2_M->Sizes.numY = (0); /* Number of model outputs */
  lab_readyDIGIT2_M->Sizes.numU = (0); /* Number of model inputs */
  lab_readyDIGIT2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab_readyDIGIT2_M->Sizes.numSampTimes = (3);/* Number of sample times */
  lab_readyDIGIT2_M->Sizes.numBlocks = (35);/* Number of blocks */
  lab_readyDIGIT2_M->Sizes.numBlockIO = (12);/* Number of block outputs */
  lab_readyDIGIT2_M->Sizes.numBlockPrms = (49);/* Sum of parameter "widths" */
  return lab_readyDIGIT2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
