/*
 * lab_readyDIGIT3_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab_readyDIGIT3".
 *
 * Model version              : 2.12
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed Jun  1 13:24:37 2022
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab_readyDIGIT3.h"
#include "lab_readyDIGIT3_private.h"

/* Block parameters (default storage) */
P_lab_readyDIGIT3_T lab_readyDIGIT3_P = {
  /* Variable: sens
   * Referenced by: '<Root>/pulse2deg1'
   */
  {
    {
      0.5
    },

    {
      2000.0,
      0.18,
      0.0031415926535897933,
      5.5555555555555554,
      318.3098861837907
    },

    {
      {
        10000.0,
        5.0,
        345.0,
        6.0213859193804371
      },
      0.014492753623188406,
      0.83037361613162786,
      69.0,
      1.2042771838760873
    }
  },

  /* Variable: degs2rpm
   * Referenced by: '<S5>/degs2rpm'
   */
  0.16666666666666666,

  /* Variable: denF
   * Referenced by: '<S5>/Discrete Transfer Fcn'
   */
  { 1.0, 1.1584799000428243, 0.41970460582576558 },

  /* Variable: numF
   * Referenced by: '<S5>/Discrete Transfer Fcn'
   */
  { 64.454612646714736, 0.0, -64.454612646714736 },

  /* Variable: rpm2rads
   * Referenced by: '<S4>/Gain'
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

  /* Mask Parameter: u_OutValues
   * Referenced by: '<S1>/Vector'
   */
  { 250.0, -250.0 },

  /* Mask Parameter: u_OutValues_k
   * Referenced by: '<S2>/Vector'
   */
  { 0.0, 50.0, 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0 },

  /* Mask Parameter: u_OutValues_e
   * Referenced by: '<S3>/Vector'
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

  /* Mask Parameter: LimitedCounter_uplimit_e
   * Referenced by: '<S11>/FixPt Switch'
   */
  9U,

  /* Mask Parameter: LimitedCounter_uplimit_o
   * Referenced by: '<S14>/FixPt Switch'
   */
  1U,

  /* Expression: 1/(1e-2)
   * Referenced by: '<S5>/Gain'
   */
  100.0,

  /* Expression: 3
   * Referenced by: '<Root>/Constant'
   */
  3.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S5>/Constant'
   */
  2.0,

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

  /* Expression: 0
   * Referenced by: '<S5>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 0.056
   * Referenced by: '<S4>/P'
   */
  0.056,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S4>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S4>/Saturation'
   */
  -10.0,

  /* Expression: 8.72
   * Referenced by: '<S4>/I'
   */
  8.72,

  /* Expression: 1/0.5
   * Referenced by: '<Root>/Gain'
   */
  2.0,

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<S8>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S11>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S14>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S6>/Output'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition_m
   * Referenced by: '<S9>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S7>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value_g
   * Referenced by: '<S10>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value_i
   * Referenced by: '<S13>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition_f
   * Referenced by: '<S12>/Output'
   */
  0U
};
