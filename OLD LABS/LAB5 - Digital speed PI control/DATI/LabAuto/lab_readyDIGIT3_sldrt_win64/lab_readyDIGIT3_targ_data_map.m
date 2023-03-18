  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (lab_readyDIGIT3_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% lab_readyDIGIT3_P.sens
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% lab_readyDIGIT3_P.degs2rpm
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab_readyDIGIT3_P.denF
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab_readyDIGIT3_P.numF
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 4;
	
	  ;% lab_readyDIGIT3_P.rpm2rads
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 7;
	
	  ;% lab_readyDIGIT3_P.AnalogOutput_FinalValue
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 8;
	
	  ;% lab_readyDIGIT3_P.AnalogOutput_InitialValue
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 9;
	
	  ;% lab_readyDIGIT3_P.EncoderInput_InputFilter
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 10;
	
	  ;% lab_readyDIGIT3_P.EncoderInput_MaxMissedTicks
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 11;
	
	  ;% lab_readyDIGIT3_P.AnalogInput_MaxMissedTicks
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 12;
	
	  ;% lab_readyDIGIT3_P.AnalogOutput_MaxMissedTicks
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 13;
	
	  ;% lab_readyDIGIT3_P.u_OutValues
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 14;
	
	  ;% lab_readyDIGIT3_P.u_OutValues_k
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 16;
	
	  ;% lab_readyDIGIT3_P.u_OutValues_e
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 26;
	
	  ;% lab_readyDIGIT3_P.EncoderInput_YieldWhenWaiting
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 28;
	
	  ;% lab_readyDIGIT3_P.AnalogInput_YieldWhenWaiting
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 29;
	
	  ;% lab_readyDIGIT3_P.AnalogOutput_YieldWhenWaiting
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 30;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% lab_readyDIGIT3_P.EncoderInput_Channels
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab_readyDIGIT3_P.AnalogInput_Channels
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab_readyDIGIT3_P.AnalogOutput_Channels
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 3;
	
	  ;% lab_readyDIGIT3_P.AnalogInput_RangeMode
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 4;
	
	  ;% lab_readyDIGIT3_P.AnalogOutput_RangeMode
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 5;
	
	  ;% lab_readyDIGIT3_P.AnalogInput_VoltRange
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 6;
	
	  ;% lab_readyDIGIT3_P.AnalogOutput_VoltRange
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% lab_readyDIGIT3_P.LimitedCounter_uplimit
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab_readyDIGIT3_P.LimitedCounter_uplimit_e
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab_readyDIGIT3_P.LimitedCounter_uplimit_o
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% lab_readyDIGIT3_P.Gain_Gain
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab_readyDIGIT3_P.Constant_Value
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab_readyDIGIT3_P.Gain1_Gain
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% lab_readyDIGIT3_P.Integrator_IC
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 3;
	
	  ;% lab_readyDIGIT3_P.Constant_Value_m
	  section.data(5).logicalSrcIdx = 31;
	  section.data(5).dtTransOffset = 4;
	
	  ;% lab_readyDIGIT3_P.TransferFcn_A
	  section.data(6).logicalSrcIdx = 32;
	  section.data(6).dtTransOffset = 5;
	
	  ;% lab_readyDIGIT3_P.TransferFcn_C
	  section.data(7).logicalSrcIdx = 33;
	  section.data(7).dtTransOffset = 6;
	
	  ;% lab_readyDIGIT3_P.TransferFcn_D
	  section.data(8).logicalSrcIdx = 34;
	  section.data(8).dtTransOffset = 7;
	
	  ;% lab_readyDIGIT3_P.TransferFcn1_A
	  section.data(9).logicalSrcIdx = 35;
	  section.data(9).dtTransOffset = 8;
	
	  ;% lab_readyDIGIT3_P.TransferFcn1_C
	  section.data(10).logicalSrcIdx = 36;
	  section.data(10).dtTransOffset = 10;
	
	  ;% lab_readyDIGIT3_P.Delay_InitialCondition
	  section.data(11).logicalSrcIdx = 37;
	  section.data(11).dtTransOffset = 12;
	
	  ;% lab_readyDIGIT3_P.DiscreteTransferFcn_InitialStates
	  section.data(12).logicalSrcIdx = 38;
	  section.data(12).dtTransOffset = 13;
	
	  ;% lab_readyDIGIT3_P.P_Gain
	  section.data(13).logicalSrcIdx = 39;
	  section.data(13).dtTransOffset = 14;
	
	  ;% lab_readyDIGIT3_P.Integrator_IC_l
	  section.data(14).logicalSrcIdx = 40;
	  section.data(14).dtTransOffset = 15;
	
	  ;% lab_readyDIGIT3_P.Saturation_UpperSat
	  section.data(15).logicalSrcIdx = 41;
	  section.data(15).dtTransOffset = 16;
	
	  ;% lab_readyDIGIT3_P.Saturation_LowerSat
	  section.data(16).logicalSrcIdx = 42;
	  section.data(16).dtTransOffset = 17;
	
	  ;% lab_readyDIGIT3_P.I_Gain
	  section.data(17).logicalSrcIdx = 43;
	  section.data(17).dtTransOffset = 18;
	
	  ;% lab_readyDIGIT3_P.Gain_Gain_j
	  section.data(18).logicalSrcIdx = 44;
	  section.data(18).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% lab_readyDIGIT3_P.Constant_Value_c
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab_readyDIGIT3_P.Constant_Value_i
	  section.data(2).logicalSrcIdx = 46;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab_readyDIGIT3_P.Constant_Value_h
	  section.data(3).logicalSrcIdx = 47;
	  section.data(3).dtTransOffset = 2;
	
	  ;% lab_readyDIGIT3_P.Output_InitialCondition
	  section.data(4).logicalSrcIdx = 48;
	  section.data(4).dtTransOffset = 3;
	
	  ;% lab_readyDIGIT3_P.Output_InitialCondition_m
	  section.data(5).logicalSrcIdx = 49;
	  section.data(5).dtTransOffset = 4;
	
	  ;% lab_readyDIGIT3_P.FixPtConstant_Value
	  section.data(6).logicalSrcIdx = 50;
	  section.data(6).dtTransOffset = 5;
	
	  ;% lab_readyDIGIT3_P.FixPtConstant_Value_g
	  section.data(7).logicalSrcIdx = 51;
	  section.data(7).dtTransOffset = 6;
	
	  ;% lab_readyDIGIT3_P.FixPtConstant_Value_i
	  section.data(8).logicalSrcIdx = 52;
	  section.data(8).dtTransOffset = 7;
	
	  ;% lab_readyDIGIT3_P.Output_InitialCondition_f
	  section.data(9).logicalSrcIdx = 53;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (lab_readyDIGIT3_B)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% lab_readyDIGIT3_B.Output
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab_readyDIGIT3_B.Gain1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab_readyDIGIT3_B.MultiportSwitch
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% lab_readyDIGIT3_B.thl_meas
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% lab_readyDIGIT3_B.Delay
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% lab_readyDIGIT3_B.DiscreteTransferFcn
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% lab_readyDIGIT3_B.degs2rpm
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% lab_readyDIGIT3_B.Sum
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% lab_readyDIGIT3_B.Saturation
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% lab_readyDIGIT3_B.Output_p
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% lab_readyDIGIT3_B.I
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% lab_readyDIGIT3_B.ia
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% lab_readyDIGIT3_B.FixPtSwitch
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab_readyDIGIT3_B.FixPtSwitch_d
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab_readyDIGIT3_B.FixPtSwitch_f
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (lab_readyDIGIT3_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% lab_readyDIGIT3_DW.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab_readyDIGIT3_DW.DiscreteTransferFcn_states
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 10;
	
	  ;% lab_readyDIGIT3_DW.DiscreteTransferFcn_tmp
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% lab_readyDIGIT3_DW.EncoderInput_PWORK
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab_readyDIGIT3_DW.AnalogInput_PWORK
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab_readyDIGIT3_DW.AnalogOutput_PWORK
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% lab_readyDIGIT3_DW.ToWorkspace1_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% lab_readyDIGIT3_DW.ToWorkspace2_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% lab_readyDIGIT3_DW.ToWorkspace4_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 5;
	
	  ;% lab_readyDIGIT3_DW.ToWorkspace5_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 6;
	
	  ;% lab_readyDIGIT3_DW.ToWorkspace6_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 7;
	
	  ;% lab_readyDIGIT3_DW.ToWorkspace7_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% lab_readyDIGIT3_DW.Output_DSTATE
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab_readyDIGIT3_DW.Output_DSTATE_n
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab_readyDIGIT3_DW.Output_DSTATE_j
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 38240869;
  targMap.checksum1 = 1656308761;
  targMap.checksum2 = 3954046172;
  targMap.checksum3 = 1043229567;

