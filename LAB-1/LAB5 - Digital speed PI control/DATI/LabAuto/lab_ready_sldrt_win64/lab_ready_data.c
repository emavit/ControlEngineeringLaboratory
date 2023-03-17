/*
 * lab_ready_data.c
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

/* Block parameters (default storage) */
P_lab_ready_T lab_ready_P = {
  /* Variable: degs2rpm
   * Referenced by: '<S5>/degs2rpm'
   */
  0.16666666666666666,

  /* Variable: rpm2rads
   * Referenced by: '<S1>/Gain'
   */
  0.10471975511965977,

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: RepeatingSequenceStair1_OutValues
   * Referenced by: '<S3>/Vector'
   */
  { 250.0, -250.0 },

  /* Mask Parameter: Staircase_OutValues
   * Referenced by: '<S4>/Vector'
   */
  { 0.0, 50.0, 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 450.0 },

  /* Mask Parameter: RepeatingSequenceStair_OutValues
   * Referenced by: '<S2>/Vector'
   */
  { 450.0, -450.0 },

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  1.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  0,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<Root>/Analog Input'
   */
  { 0, 1 },

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: LimitedCounter_uplimit
   * Referenced by: '<S8>/FixPt Switch'
   */
  1U,

  /* Mask Parameter: LimitedCounter_uplimit_n
   * Referenced by: '<S11>/FixPt Switch'
   */
  1U,

  /* Mask Parameter: LimitedCounter_uplimit_c
   * Referenced by: '<S14>/FixPt Switch'
   */
  10U,

  /* Expression: 1
   * Referenced by: '<S5>/Gain'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/pulse2deg - ATTENZIONE1'
   */
  -1.0,

  /* Expression: 2
   * Referenced by: '<S5>/Constant'
   */
  2.0,

  /* Expression: 0.18
   * Referenced by: '<Root>/pulse2deg - ATTENZIONE'
   */
  0.18,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S5>/Transfer Fcn'
   */
  -314.15926535897933,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S5>/Transfer Fcn'
   */
  -98696.044010893587,

  /* Computed Parameter: TransferFcn_D
   * Referenced by: '<S5>/Transfer Fcn'
   */
  314.15926535897933,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S5>/Transfer Fcn1'
   */
  { -444.2882938158366, -98696.044010893587 },

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S5>/Transfer Fcn1'
   */
  { 98696.044010893587, 0.0 },

  /* Expression: 0
   * Referenced by: '<S5>/Delay'
   */
  0.0,

  /* Expression: 0.056
   * Referenced by: '<S1>/P Gain'
   */
  0.056,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<S1>/Saturation'
   */
  12.0,

  /* Expression: -12
   * Referenced by: '<S1>/Saturation'
   */
  -12.0,

  /* Expression: 8.72
   * Referenced by: '<S1>/I Gain1'
   */
  8.72,

  /* Computed Parameter: Constant_Value_l
   * Referenced by: '<S8>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_f
   * Referenced by: '<S11>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S14>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S9>/Output'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition_l
   * Referenced by: '<S12>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S7>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition_b
   * Referenced by: '<S6>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value_i
   * Referenced by: '<S10>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value_a
   * Referenced by: '<S13>/FixPt Constant'
   */
  1U
};
