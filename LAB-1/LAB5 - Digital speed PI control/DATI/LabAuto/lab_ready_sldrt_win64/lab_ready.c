/*
 * lab_ready.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab_ready".
 *
 * Model version              : 2.2
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed May 11 14:41:15 2022
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab_ready.h"
#include "lab_ready_private.h"
#include "lab_ready_dt.h"

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
B_lab_ready_T lab_ready_B;

/* Continuous states */
X_lab_ready_T lab_ready_X;

/* Block states (default storage) */
DW_lab_ready_T lab_ready_DW;

/* Real-time model */
static RT_MODEL_lab_ready_T lab_ready_M_;
RT_MODEL_lab_ready_T *const lab_ready_M = &lab_ready_M_;
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
  (lab_ready_M->Timing.TaskCounters.TID[2])++;
  if ((lab_ready_M->Timing.TaskCounters.TID[2]) > 999) {/* Sample time: [1.0s, 0.0s] */
    lab_ready_M->Timing.TaskCounters.TID[2] = 0;
  }

  lab_ready_M->Timing.sampleHits[2] = (lab_ready_M->Timing.TaskCounters.TID[2] ==
    0);
  (lab_ready_M->Timing.TaskCounters.TID[3])++;
  if ((lab_ready_M->Timing.TaskCounters.TID[3]) > 1499) {/* Sample time: [1.5s, 0.0s] */
    lab_ready_M->Timing.TaskCounters.TID[3] = 0;
  }

  lab_ready_M->Timing.sampleHits[3] = (lab_ready_M->Timing.TaskCounters.TID[3] ==
    0);
  (lab_ready_M->Timing.TaskCounters.TID[4])++;
  if ((lab_ready_M->Timing.TaskCounters.TID[4]) > 4999) {/* Sample time: [5.0s, 0.0s] */
    lab_ready_M->Timing.TaskCounters.TID[4] = 0;
  }

  lab_ready_M->Timing.sampleHits[4] = (lab_ready_M->Timing.TaskCounters.TID[4] ==
    0);
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
  lab_ready_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  lab_ready_output();
  lab_ready_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  lab_ready_output();
  lab_ready_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  lab_ready_output();
  lab_ready_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void lab_ready_output(void)
{
  /* local block i/o variables */
  real_T rtb_Gain_e;
  real_T rtb_AnalogInput[2];
  real_T u0;
  uint8_T rtb_FixPtSum1;
  uint8_T rtb_Output_gx;
  uint8_T rtb_Output_o;
  if (rtmIsMajorTimeStep(lab_ready_M)) {
    /* set solver stop time */
    if (!(lab_ready_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab_ready_M->solverInfo,
                            ((lab_ready_M->Timing.clockTickH0 + 1) *
        lab_ready_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab_ready_M->solverInfo,
                            ((lab_ready_M->Timing.clockTick0 + 1) *
        lab_ready_M->Timing.stepSize0 + lab_ready_M->Timing.clockTickH0 *
        lab_ready_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab_ready_M)) {
    lab_ready_M->Timing.t[0] = rtsiGetT(&lab_ready_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[3] == 0) {
    /* UnitDelay: '<S9>/Output' */
    rtb_Output_o = lab_ready_DW.Output_DSTATE;

    /* MultiPortSwitch: '<S3>/Output' incorporates:
     *  Constant: '<S3>/Vector'
     *  UnitDelay: '<S9>/Output'
     */
    lab_ready_B.Output =
      lab_ready_P.RepeatingSequenceStair1_OutValues[lab_ready_DW.Output_DSTATE];
  }

  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[4] == 0) {
    /* UnitDelay: '<S12>/Output' */
    rtb_Output_gx = lab_ready_DW.Output_DSTATE_b;

    /* Gain: '<Root>/pulse2deg - ATTENZIONE1' incorporates:
     *  Constant: '<S4>/Vector'
     *  MultiPortSwitch: '<S4>/Output'
     *  UnitDelay: '<S12>/Output'
     */
    lab_ready_B.pulse2degATTENZIONE1 = lab_ready_P.pulse2degATTENZIONE1_Gain *
      lab_ready_P.Staircase_OutValues[lab_ready_DW.Output_DSTATE_b];
  }

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Constant'
   */
  switch ((int32_T)lab_ready_P.Constant_Value) {
   case 1:
    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Integrator: '<Root>/Integrator'
     */
    lab_ready_B.MultiportSwitch = lab_ready_X.Integrator_CSTATE;
    break;

   case 2:
    /* MultiPortSwitch: '<Root>/Multiport Switch' */
    lab_ready_B.MultiportSwitch = lab_ready_B.Output;
    break;

   default:
    /* MultiPortSwitch: '<Root>/Multiport Switch' */
    lab_ready_B.MultiportSwitch = lab_ready_B.pulse2degATTENZIONE1;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* S-Function (sldrtei): '<Root>/Encoder Input' */
  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = lab_ready_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &lab_ready_P.EncoderInput_Channels, &rtb_Gain_e, &parm);
  }

  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_ready_P.AnalogInput_RangeMode;
      parm.rangeidx = lab_ready_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2, lab_ready_P.AnalogInput_Channels,
                     &rtb_AnalogInput[0], &parm);
    }

    /* Delay: '<S5>/Delay' */
    lab_ready_B.Delay = lab_ready_DW.Delay_DSTATE[0];
  }

  /* Gain: '<Root>/pulse2deg - ATTENZIONE' */
  lab_ready_B.pulse2degATTENZIONE = lab_ready_P.pulse2degATTENZIONE_Gain *
    rtb_Gain_e;

  /* MultiPortSwitch: '<S5>/Multiport Switch' incorporates:
   *  Constant: '<S5>/Constant'
   */
  switch ((int32_T)lab_ready_P.Constant_Value_n) {
   case 1:
    /* Gain: '<S1>/Gain' incorporates:
     *  TransferFcn: '<S5>/Transfer Fcn'
     */
    rtb_Gain_e = lab_ready_P.TransferFcn_C * lab_ready_X.TransferFcn_CSTATE +
      lab_ready_P.TransferFcn_D * lab_ready_B.pulse2degATTENZIONE;
    break;

   case 2:
    /* Gain: '<S1>/Gain' incorporates:
     *  TransferFcn: '<S5>/Transfer Fcn1'
     */
    rtb_Gain_e = lab_ready_P.TransferFcn1_C[0] *
      lab_ready_X.TransferFcn1_CSTATE[0] + lab_ready_P.TransferFcn1_C[1] *
      lab_ready_X.TransferFcn1_CSTATE[1];
    break;

   default:
    /* Gain: '<S1>/Gain' incorporates:
     *  Gain: '<S5>/Gain'
     *  Sum: '<S5>/Sum'
     */
    rtb_Gain_e = (lab_ready_B.pulse2degATTENZIONE - lab_ready_B.Delay) *
      lab_ready_P.Gain_Gain;
    break;
  }

  /* End of MultiPortSwitch: '<S5>/Multiport Switch' */

  /* Gain: '<S5>/degs2rpm' */
  lab_ready_B.degs2rpm = lab_ready_P.degs2rpm * rtb_Gain_e;

  /* Sum: '<Root>/Sum' */
  lab_ready_B.Sum = lab_ready_B.MultiportSwitch - lab_ready_B.degs2rpm;

  /* Gain: '<S1>/Gain' */
  rtb_Gain_e = lab_ready_P.rpm2rads * lab_ready_B.Sum;

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/P Gain'
   *  Integrator: '<S1>/Integrator'
   */
  u0 = lab_ready_P.PGain_Gain * rtb_Gain_e + lab_ready_X.Integrator_CSTATE_g;

  /* Saturate: '<S1>/Saturation' */
  if (u0 > lab_ready_P.Saturation_UpperSat) {
    /* Saturate: '<S1>/Saturation' */
    lab_ready_B.Saturation = lab_ready_P.Saturation_UpperSat;
  } else if (u0 < lab_ready_P.Saturation_LowerSat) {
    /* Saturate: '<S1>/Saturation' */
    lab_ready_B.Saturation = lab_ready_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S1>/Saturation' */
    lab_ready_B.Saturation = u0;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* S-Function (sldrtao): '<Root>/Analog Output' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_ready_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_ready_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab_ready_P.AnalogOutput_Channels, ((real_T*)
        (&lab_ready_B.Saturation)), &parm);
    }
  }

  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<Root>/Add' */
    lab_ready_B.Add = rtb_AnalogInput[0] - rtb_AnalogInput[1];
  }

  /* Gain: '<S1>/I Gain1' */
  lab_ready_B.IGain1 = lab_ready_P.IGain1_Gain * rtb_Gain_e;
  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[2] == 0) {
    /* Sum: '<S7>/FixPt Sum1' incorporates:
     *  Constant: '<S7>/FixPt Constant'
     *  UnitDelay: '<S6>/Output'
     */
    rtb_FixPtSum1 = (uint8_T)((uint32_T)lab_ready_DW.Output_DSTATE_l +
      lab_ready_P.FixPtConstant_Value);

    /* Switch: '<S8>/FixPt Switch' */
    if (rtb_FixPtSum1 > lab_ready_P.LimitedCounter_uplimit) {
      /* Switch: '<S8>/FixPt Switch' incorporates:
       *  Constant: '<S8>/Constant'
       */
      lab_ready_B.FixPtSwitch = lab_ready_P.Constant_Value_l;
    } else {
      /* Switch: '<S8>/FixPt Switch' */
      lab_ready_B.FixPtSwitch = rtb_FixPtSum1;
    }

    /* End of Switch: '<S8>/FixPt Switch' */

    /* MultiPortSwitch: '<S2>/Output' incorporates:
     *  Constant: '<S2>/Vector'
     *  UnitDelay: '<S6>/Output'
     */
    lab_ready_B.Output_p =
      lab_ready_P.RepeatingSequenceStair_OutValues[lab_ready_DW.Output_DSTATE_l];
  }

  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[3] == 0) {
    /* Sum: '<S10>/FixPt Sum1' incorporates:
     *  Constant: '<S10>/FixPt Constant'
     */
    rtb_Output_o = (uint8_T)((uint32_T)rtb_Output_o +
      lab_ready_P.FixPtConstant_Value_i);

    /* Switch: '<S11>/FixPt Switch' */
    if (rtb_Output_o > lab_ready_P.LimitedCounter_uplimit_n) {
      /* Switch: '<S11>/FixPt Switch' incorporates:
       *  Constant: '<S11>/Constant'
       */
      lab_ready_B.FixPtSwitch_p = lab_ready_P.Constant_Value_f;
    } else {
      /* Switch: '<S11>/FixPt Switch' */
      lab_ready_B.FixPtSwitch_p = rtb_Output_o;
    }

    /* End of Switch: '<S11>/FixPt Switch' */
  }

  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[4] == 0) {
    /* Sum: '<S13>/FixPt Sum1' incorporates:
     *  Constant: '<S13>/FixPt Constant'
     */
    rtb_Output_gx = (uint8_T)((uint32_T)rtb_Output_gx +
      lab_ready_P.FixPtConstant_Value_a);

    /* Switch: '<S14>/FixPt Switch' */
    if (rtb_Output_gx > lab_ready_P.LimitedCounter_uplimit_c) {
      /* Switch: '<S14>/FixPt Switch' incorporates:
       *  Constant: '<S14>/Constant'
       */
      lab_ready_B.FixPtSwitch_d = lab_ready_P.Constant_Value_a;
    } else {
      /* Switch: '<S14>/FixPt Switch' */
      lab_ready_B.FixPtSwitch_d = rtb_Output_gx;
    }

    /* End of Switch: '<S14>/FixPt Switch' */
  }
}

/* Model update function */
void lab_ready_update(void)
{
  int_T idxDelay;
  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update for UnitDelay: '<S9>/Output' */
    lab_ready_DW.Output_DSTATE = lab_ready_B.FixPtSwitch_p;
  }

  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update for UnitDelay: '<S12>/Output' */
    lab_ready_DW.Output_DSTATE_b = lab_ready_B.FixPtSwitch_d;
  }

  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Delay: '<S5>/Delay' */
    for (idxDelay = 0; idxDelay < 9; idxDelay++) {
      lab_ready_DW.Delay_DSTATE[idxDelay] = lab_ready_DW.Delay_DSTATE[idxDelay +
        1];
    }

    lab_ready_DW.Delay_DSTATE[9] = lab_ready_B.pulse2degATTENZIONE;

    /* End of Update for Delay: '<S5>/Delay' */
  }

  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for UnitDelay: '<S6>/Output' */
    lab_ready_DW.Output_DSTATE_l = lab_ready_B.FixPtSwitch;
  }

  if (rtmIsMajorTimeStep(lab_ready_M)) {
    rt_ertODEUpdateContinuousStates(&lab_ready_M->solverInfo);
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
  if (!(++lab_ready_M->Timing.clockTick0)) {
    ++lab_ready_M->Timing.clockTickH0;
  }

  lab_ready_M->Timing.t[0] = rtsiGetSolverStopTime(&lab_ready_M->solverInfo);

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
    if (!(++lab_ready_M->Timing.clockTick1)) {
      ++lab_ready_M->Timing.clockTickH1;
    }

    lab_ready_M->Timing.t[1] = lab_ready_M->Timing.clockTick1 *
      lab_ready_M->Timing.stepSize1 + lab_ready_M->Timing.clockTickH1 *
      lab_ready_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lab_ready_M->Timing.clockTick2)) {
      ++lab_ready_M->Timing.clockTickH2;
    }

    lab_ready_M->Timing.t[2] = lab_ready_M->Timing.clockTick2 *
      lab_ready_M->Timing.stepSize2 + lab_ready_M->Timing.clockTickH2 *
      lab_ready_M->Timing.stepSize2 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [1.5s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick3"
     * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick3 and the high bits
     * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lab_ready_M->Timing.clockTick3)) {
      ++lab_ready_M->Timing.clockTickH3;
    }

    lab_ready_M->Timing.t[3] = lab_ready_M->Timing.clockTick3 *
      lab_ready_M->Timing.stepSize3 + lab_ready_M->Timing.clockTickH3 *
      lab_ready_M->Timing.stepSize3 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(lab_ready_M) &&
      lab_ready_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update absolute timer for sample time: [5.0s, 0.0s] */
    /* The "clockTick4" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick4"
     * and "Timing.stepSize4". Size of "clockTick4" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick4 and the high bits
     * Timing.clockTickH4. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lab_ready_M->Timing.clockTick4)) {
      ++lab_ready_M->Timing.clockTickH4;
    }

    lab_ready_M->Timing.t[4] = lab_ready_M->Timing.clockTick4 *
      lab_ready_M->Timing.stepSize4 + lab_ready_M->Timing.clockTickH4 *
      lab_ready_M->Timing.stepSize4 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void lab_ready_derivatives(void)
{
  XDot_lab_ready_T *_rtXdot;
  _rtXdot = ((XDot_lab_ready_T *) lab_ready_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = lab_ready_B.Output_p;

  /* Derivatives for TransferFcn: '<S5>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += lab_ready_P.TransferFcn_A *
    lab_ready_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += lab_ready_B.pulse2degATTENZIONE;

  /* Derivatives for TransferFcn: '<S5>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += lab_ready_P.TransferFcn1_A[0] *
    lab_ready_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += lab_ready_P.TransferFcn1_A[1] *
    lab_ready_X.TransferFcn1_CSTATE[1];
  _rtXdot->TransferFcn1_CSTATE[1] += lab_ready_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[0] += lab_ready_B.pulse2degATTENZIONE;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = lab_ready_B.IGain1;
}

/* Model initialize function */
void lab_ready_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_ready_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_ready_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab_ready_P.AnalogOutput_Channels,
                     &lab_ready_P.AnalogOutput_InitialValue, &parm);
    }
  }

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    lab_ready_X.Integrator_CSTATE = lab_ready_P.Integrator_IC;

    /* InitializeConditions for UnitDelay: '<S9>/Output' */
    lab_ready_DW.Output_DSTATE = lab_ready_P.Output_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S12>/Output' */
    lab_ready_DW.Output_DSTATE_b = lab_ready_P.Output_InitialCondition_l;

    /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = lab_ready_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                     &lab_ready_P.EncoderInput_Channels, NULL, &parm);
    }

    /* InitializeConditions for TransferFcn: '<S5>/Transfer Fcn' */
    lab_ready_X.TransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S5>/Transfer Fcn1' */
    lab_ready_X.TransferFcn1_CSTATE[0] = 0.0;
    lab_ready_X.TransferFcn1_CSTATE[1] = 0.0;

    /* InitializeConditions for Delay: '<S5>/Delay' */
    for (i = 0; i < 10; i++) {
      lab_ready_DW.Delay_DSTATE[i] = lab_ready_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S5>/Delay' */

    /* InitializeConditions for Integrator: '<S1>/Integrator' */
    lab_ready_X.Integrator_CSTATE_g = lab_ready_P.Integrator_IC_g;

    /* InitializeConditions for UnitDelay: '<S6>/Output' */
    lab_ready_DW.Output_DSTATE_l = lab_ready_P.Output_InitialCondition_b;
  }
}

/* Model terminate function */
void lab_ready_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_ready_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_ready_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab_ready_P.AnalogOutput_Channels,
                     &lab_ready_P.AnalogOutput_FinalValue, &parm);
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
  lab_ready_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lab_ready_update();
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
  lab_ready_initialize();
}

void MdlTerminate(void)
{
  lab_ready_terminate();
}

/* Registration function */
RT_MODEL_lab_ready_T *lab_ready(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  lab_ready_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)lab_ready_M, 0,
                sizeof(RT_MODEL_lab_ready_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab_ready_M->solverInfo,
                          &lab_ready_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab_ready_M->solverInfo, &rtmGetTPtr(lab_ready_M));
    rtsiSetStepSizePtr(&lab_ready_M->solverInfo, &lab_ready_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab_ready_M->solverInfo, &lab_ready_M->derivs);
    rtsiSetContStatesPtr(&lab_ready_M->solverInfo, (real_T **)
                         &lab_ready_M->contStates);
    rtsiSetNumContStatesPtr(&lab_ready_M->solverInfo,
      &lab_ready_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab_ready_M->solverInfo,
      &lab_ready_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab_ready_M->solverInfo,
      &lab_ready_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab_ready_M->solverInfo,
      &lab_ready_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab_ready_M->solverInfo, (&rtmGetErrorStatus
      (lab_ready_M)));
    rtsiSetRTModelPtr(&lab_ready_M->solverInfo, lab_ready_M);
  }

  rtsiSetSimTimeStep(&lab_ready_M->solverInfo, MAJOR_TIME_STEP);
  lab_ready_M->intgData.y = lab_ready_M->odeY;
  lab_ready_M->intgData.f[0] = lab_ready_M->odeF[0];
  lab_ready_M->intgData.f[1] = lab_ready_M->odeF[1];
  lab_ready_M->intgData.f[2] = lab_ready_M->odeF[2];
  lab_ready_M->intgData.f[3] = lab_ready_M->odeF[3];
  lab_ready_M->contStates = ((real_T *) &lab_ready_X);
  rtsiSetSolverData(&lab_ready_M->solverInfo, (void *)&lab_ready_M->intgData);
  rtsiSetSolverName(&lab_ready_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab_ready_M->Timing.sampleTimeTaskIDArray;
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlTsMap[i] = i;
    }

    lab_ready_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab_ready_M->Timing.sampleTimes = (&lab_ready_M->Timing.sampleTimesArray[0]);
    lab_ready_M->Timing.offsetTimes = (&lab_ready_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab_ready_M->Timing.sampleTimes[0] = (0.0);
    lab_ready_M->Timing.sampleTimes[1] = (0.001);
    lab_ready_M->Timing.sampleTimes[2] = (1.0);
    lab_ready_M->Timing.sampleTimes[3] = (1.5);
    lab_ready_M->Timing.sampleTimes[4] = (5.0);

    /* task offsets */
    lab_ready_M->Timing.offsetTimes[0] = (0.0);
    lab_ready_M->Timing.offsetTimes[1] = (0.0);
    lab_ready_M->Timing.offsetTimes[2] = (0.0);
    lab_ready_M->Timing.offsetTimes[3] = (0.0);
    lab_ready_M->Timing.offsetTimes[4] = (0.0);
  }

  rtmSetTPtr(lab_ready_M, &lab_ready_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab_ready_M->Timing.sampleHitArray;
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlSampleHits[i] = 1;
    }

    lab_ready_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab_ready_M, 20.0);
  lab_ready_M->Timing.stepSize0 = 0.001;
  lab_ready_M->Timing.stepSize1 = 0.001;
  lab_ready_M->Timing.stepSize2 = 1.0;
  lab_ready_M->Timing.stepSize3 = 1.5;
  lab_ready_M->Timing.stepSize4 = 5.0;

  /* External mode info */
  lab_ready_M->Sizes.checksums[0] = (715139720U);
  lab_ready_M->Sizes.checksums[1] = (878723786U);
  lab_ready_M->Sizes.checksums[2] = (408227725U);
  lab_ready_M->Sizes.checksums[3] = (1774396191U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    lab_ready_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab_ready_M->extModeInfo,
      &lab_ready_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab_ready_M->extModeInfo, lab_ready_M->Sizes.checksums);
    rteiSetTPtr(lab_ready_M->extModeInfo, rtmGetTPtr(lab_ready_M));
  }

  lab_ready_M->solverInfoPtr = (&lab_ready_M->solverInfo);
  lab_ready_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&lab_ready_M->solverInfo, 0.001);
  rtsiSetSolverMode(&lab_ready_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lab_ready_M->blockIO = ((void *) &lab_ready_B);
  (void) memset(((void *) &lab_ready_B), 0,
                sizeof(B_lab_ready_T));

  /* parameters */
  lab_ready_M->defaultParam = ((real_T *)&lab_ready_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab_ready_X;
    lab_ready_M->contStates = (x);
    (void) memset((void *)&lab_ready_X, 0,
                  sizeof(X_lab_ready_T));
  }

  /* states (dwork) */
  lab_ready_M->dwork = ((void *) &lab_ready_DW);
  (void) memset((void *)&lab_ready_DW, 0,
                sizeof(DW_lab_ready_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab_ready_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab_ready_M->Sizes.numContStates = (5);/* Number of continuous states */
  lab_ready_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  lab_ready_M->Sizes.numY = (0);       /* Number of model outputs */
  lab_ready_M->Sizes.numU = (0);       /* Number of model inputs */
  lab_ready_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab_ready_M->Sizes.numSampTimes = (5);/* Number of sample times */
  lab_ready_M->Sizes.numBlocks = (56); /* Number of blocks */
  lab_ready_M->Sizes.numBlockIO = (14);/* Number of block outputs */
  lab_ready_M->Sizes.numBlockPrms = (65);/* Sum of parameter "widths" */
  return lab_ready_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
