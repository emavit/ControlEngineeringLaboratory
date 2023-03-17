/*
 * test1.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "test1".
 *
 * Model version              : 1.7
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed May 11 15:23:41 2022
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test1.h"
#include "test1_private.h"
#include "test1_dt.h"

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
B_test1_T test1_B;

/* Block states (default storage) */
DW_test1_T test1_DW;

/* Real-time model */
static RT_MODEL_test1_T test1_M_;
RT_MODEL_test1_T *const test1_M = &test1_M_;

/* Model output function */
void test1_output(void)
{
  /* S-Function (sldrtai): '<Root>/Analog Input' */
  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) test1_P.AnalogInput_RangeMode;
    parm.rangeidx = test1_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2, test1_P.AnalogInput_Channels,
                   &test1_B.AnalogInput[0], &parm);
  }

  /* S-Function (sldrtei): '<Root>/Encoder Input' */
  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = test1_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1, &test1_P.EncoderInput_Channels,
                   &test1_B.EncoderInput, &parm);
  }

  /* S-Function (sldrtao): '<Root>/Analog Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) test1_P.AnalogOutput_RangeMode;
      parm.rangeidx = test1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &test1_P.AnalogOutput_Channels,
                     ((real_T*) (&test1_P.Constant_Value)), &parm);
    }
  }
}

/* Model update function */
void test1_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++test1_M->Timing.clockTick0)) {
    ++test1_M->Timing.clockTickH0;
  }

  test1_M->Timing.t[0] = test1_M->Timing.clockTick0 * test1_M->Timing.stepSize0
    + test1_M->Timing.clockTickH0 * test1_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void test1_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' incorporates:
   *  Constant: '<Root>/Constant'
   */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) test1_P.AnalogOutput_RangeMode;
      parm.rangeidx = test1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &test1_P.AnalogOutput_Channels,
                     &test1_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = test1_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &test1_P.EncoderInput_Channels,
                   NULL, &parm);
  }
}

/* Model terminate function */
void test1_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' incorporates:
   *  Constant: '<Root>/Constant'
   */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) test1_P.AnalogOutput_RangeMode;
      parm.rangeidx = test1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &test1_P.AnalogOutput_Channels,
                     &test1_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  test1_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  test1_update();
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
  test1_initialize();
}

void MdlTerminate(void)
{
  test1_terminate();
}

/* Registration function */
RT_MODEL_test1_T *test1(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  test1_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)test1_M, 0,
                sizeof(RT_MODEL_test1_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = test1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    test1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    test1_M->Timing.sampleTimes = (&test1_M->Timing.sampleTimesArray[0]);
    test1_M->Timing.offsetTimes = (&test1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    test1_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    test1_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(test1_M, &test1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = test1_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    test1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(test1_M, -1);
  test1_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  test1_M->Sizes.checksums[0] = (2571719523U);
  test1_M->Sizes.checksums[1] = (1460056714U);
  test1_M->Sizes.checksums[2] = (59796899U);
  test1_M->Sizes.checksums[3] = (1309932077U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    test1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test1_M->extModeInfo,
      &test1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test1_M->extModeInfo, test1_M->Sizes.checksums);
    rteiSetTPtr(test1_M->extModeInfo, rtmGetTPtr(test1_M));
  }

  test1_M->solverInfoPtr = (&test1_M->solverInfo);
  test1_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&test1_M->solverInfo, 0.001);
  rtsiSetSolverMode(&test1_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  test1_M->blockIO = ((void *) &test1_B);
  (void) memset(((void *) &test1_B), 0,
                sizeof(B_test1_T));

  /* parameters */
  test1_M->defaultParam = ((real_T *)&test1_P);

  /* states (dwork) */
  test1_M->dwork = ((void *) &test1_DW);
  (void) memset((void *)&test1_DW, 0,
                sizeof(DW_test1_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    test1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  test1_M->Sizes.numContStates = (0);  /* Number of continuous states */
  test1_M->Sizes.numY = (0);           /* Number of model outputs */
  test1_M->Sizes.numU = (0);           /* Number of model inputs */
  test1_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  test1_M->Sizes.numSampTimes = (1);   /* Number of sample times */
  test1_M->Sizes.numBlocks = (6);      /* Number of blocks */
  test1_M->Sizes.numBlockIO = (2);     /* Number of block outputs */
  test1_M->Sizes.numBlockPrms = (18);  /* Sum of parameter "widths" */
  return test1_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
