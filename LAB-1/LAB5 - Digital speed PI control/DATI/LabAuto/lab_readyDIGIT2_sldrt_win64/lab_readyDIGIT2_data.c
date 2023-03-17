/*
 * lab_readyDIGIT2_data.c
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

/* Block parameters (default storage) */
P_lab_readyDIGIT2_T lab_readyDIGIT2_P = {
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
   * Referenced by: '<S2>/degs2rpm'
   */
  0.16666666666666666,

  /* Variable: denF
   * Referenced by: '<S2>/Discrete Transfer Fcn'
   */
  { 1.0, 1.1584799000428243, 0.41970460582576558 },

  /* Variable: numF
   * Referenced by: '<S2>/Discrete Transfer Fcn'
   */
  { 64.454612646714736, 0.0, -64.454612646714736 },

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

  /* Expression: 1/(1e-2)
   * Referenced by: '<S2>/Gain'
   */
  100.0,

  /* Expression: 1/0.5
   * Referenced by: '<Root>/Gain'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 250
   * Referenced by: '<Root>/Step'
   */
  250.0,

  /* Expression: 4
   * Referenced by: '<S2>/Constant'
   */
  4.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S2>/Transfer Fcn'
   */
  -314.15926535897933,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S2>/Transfer Fcn'
   */
  -98696.044010893587,

  /* Computed Parameter: TransferFcn_D
   * Referenced by: '<S2>/Transfer Fcn'
   */
  314.15926535897933,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S2>/Transfer Fcn1'
   */
  { -444.2882938158366, -98696.044010893587 },

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S2>/Transfer Fcn1'
   */
  { 98696.044010893587, 0.0 },

  /* Expression: 0
   * Referenced by: '<S2>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 0.056
   * Referenced by: '<S1>/P'
   */
  0.056,

  /* Expression: 8.72
   * Referenced by: '<S1>/I'
   */
  8.72,

  /* Expression: 0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 5/0.15
   * Referenced by: '<S1>/AWU gain'
   */
  33.333333333333336,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S1>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1>/Saturation'
   */
  -10.0
};
