/*
 * lab_readyFFU_data.c
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

/* Block parameters (default storage) */
P_lab_readyFFU_T lab_readyFFU_P = {
  /* Variable: sens
   * Referenced by:
   *   '<Root>/pulse2deg'
   *   '<S2>/Gain3'
   *   '<S2>/Gain5'
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

  /* Variable: mot
   * Referenced by:
   *   '<S2>/Gain3'
   *   '<S2>/Gain4'
   *   '<S2>/Gain5'
   */
  {
    2.6,
    0.00018,
    0.0076812800000000013,
    0.0076776344547530321,
    3.899238e-7,
    0.0,
    0.69,
    4.6811594202898554,
    6.0,
    0.78019323671497587,
    0.0059928827053140109,
    0.017085200000000002,
    753.98223686155029
  },

  /* Variable: gbox
   * Referenced by:
   *   '<S2>/Gain3'
   *   '<S2>/Gain4'
   *   '<S2>/Gain5'
   */
  {
    14.0,
    0.8,
    1.0,
    1.4e-6,
    1.0,
    14.0,
    0.8,
    4.2e-6
  },

  /* Variable: drv
   * Referenced by:
   *   '<S2>/Gain3'
   *   '<S2>/Gain4'
   *   '<S2>/Gain5'
   */
  {
    7500.0,
    1600.0,
    1200.0,
    500.0,
    1.0e-7,
    12.0,
    0.59780219780219779,
    0.00013186813186813186
  },

  /* Variable: B_eq
   * Referenced by: '<S2>/Gain7'
   */
  1.0827433803920016E-6,

  /* Variable: J_eq
   * Referenced by: '<S2>/Gain3'
   */
  7.3238E-7,

  /* Variable: degs2rpm
   * Referenced by: '<S3>/degs2rpm'
   */
  0.16666666666666666,

  /* Variable: rpm2rads
   * Referenced by:
   *   '<S2>/Gain'
   *   '<S2>/Gain1'
   *   '<S2>/Gain2'
   */
  0.10471975511965977,

  /* Variable: tausf
   * Referenced by: '<S2>/Gain6'
   */
  0.0098,

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

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input'
   */
  10.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: al_OutValues
   * Referenced by: '<S4>/Vector'
   */
  { 900.0, 0.0, -900.0, -900.0, 0.0, 900.0 },

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input'
   */
  0.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  1.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<Root>/Analog Input'
   */
  { 0, 1 },

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  0,

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
   * Referenced by: '<S7>/FixPt Switch'
   */
  5U,

  /* Expression: 1/(1e-2)
   * Referenced by: '<S3>/Gain'
   */
  100.0,

  /* Expression: 1/0.5
   * Referenced by: '<Root>/Gain'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S3>/Constant'
   */
  2.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S3>/Transfer Fcn'
   */
  -314.15926535897933,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S3>/Transfer Fcn'
   */
  -98696.044010893587,

  /* Computed Parameter: TransferFcn_D
   * Referenced by: '<S3>/Transfer Fcn'
   */
  314.15926535897933,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S3>/Transfer Fcn1'
   */
  { -444.2882938158366, -98696.044010893587 },

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S3>/Transfer Fcn1'
   */
  { 98696.044010893587, 0.0 },

  /* Expression: 0
   * Referenced by: '<S3>/Delay'
   */
  0.0,

  /* Expression: 0.056
   * Referenced by: '<S2>/P'
   */
  0.056,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S2>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S2>/Saturation'
   */
  -10.0,

  /* Expression: 5/0.15
   * Referenced by: '<S2>/AWU gain'
   */
  33.333333333333336,

  /* Expression: 8.72
   * Referenced by: '<S2>/I'
   */
  8.72,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S7>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S5>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S6>/FixPt Constant'
   */
  1U
};
