  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
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
    ;% Auto data (ReadAnalogInput_P)
    ;%
      section.nData     = 40;
      section.data(40)  = dumData; %prealloc
      
	  ;% ReadAnalogInput_P.MM16ATAnalogInput_P1_Size
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ReadAnalogInput_P.MM16ATAnalogInput_P1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% ReadAnalogInput_P.MM16ATAnalogInput_P2_Size
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% ReadAnalogInput_P.MM16ATAnalogInput_P2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% ReadAnalogInput_P.MM16ATAnalogInput_P3_Size
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% ReadAnalogInput_P.MM16ATAnalogInput_P3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% ReadAnalogInput_P.MM16ATAnalogInput_P4_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% ReadAnalogInput_P.MM16ATAnalogInput_P4
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% ReadAnalogInput_P.MM16ATAnalogInput_P5_Size
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% ReadAnalogInput_P.MM16ATAnalogInput_P5
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 14;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace6_A
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 15;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace6_B
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 19;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace6_C
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 21;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace6_D
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 23;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace6_X0
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 24;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace1_A
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 26;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace1_B
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 30;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace1_C
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 32;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace1_D
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 34;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace1_X0
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 35;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace2_A
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 37;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace2_B
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 41;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace2_C
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 43;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace2_D
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 45;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace2_X0
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 46;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace3_A
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 48;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace3_B
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 52;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace3_C
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 54;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace3_D
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 56;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace3_X0
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 57;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace4_A
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 59;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace4_B
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 63;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace4_C
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 65;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace4_D
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 67;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace4_X0
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 68;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace5_A
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 70;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace5_B
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 74;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace5_C
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 76;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace5_D
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 78;
	
	  ;% ReadAnalogInput_P.DiscreteStateSpace5_X0
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 79;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
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
    nTotSects     = 1;
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
    ;% Auto data (ReadAnalogInput_B)
    ;%
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% ReadAnalogInput_B.MM16ATAnalogInput_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ReadAnalogInput_B.MM16ATAnalogInput_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ReadAnalogInput_B.MM16ATAnalogInput_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ReadAnalogInput_B.MM16ATAnalogInput_o4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ReadAnalogInput_B.MM16ATAnalogInput_o5
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ReadAnalogInput_B.MM16ATAnalogInput_o6
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ReadAnalogInput_B.MM16ATAnalogInput_o7
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ReadAnalogInput_B.MM16ATAnalogInput_o8
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ReadAnalogInput_B.MM16ATAnalogInput_o9
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ReadAnalogInput_B.MM16ATAnalogInput_o10
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ReadAnalogInput_B.MM16ATAnalogInput_o11
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ReadAnalogInput_B.MM16ATAnalogInput_o12
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% ReadAnalogInput_B.DiscreteStateSpace6
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% ReadAnalogInput_B.DiscreteStateSpace1
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% ReadAnalogInput_B.DiscreteStateSpace2
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% ReadAnalogInput_B.DiscreteStateSpace3
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% ReadAnalogInput_B.DiscreteStateSpace4
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% ReadAnalogInput_B.DiscreteStateSpace5
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
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
    nTotSects     = 2;
    sectIdxOffset = 1;
    
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
    ;% Auto data (ReadAnalogInput_DWork)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% ReadAnalogInput_DWork.DiscreteStateSpace6_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ReadAnalogInput_DWork.DiscreteStateSpace1_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% ReadAnalogInput_DWork.DiscreteStateSpace2_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% ReadAnalogInput_DWork.DiscreteStateSpace3_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% ReadAnalogInput_DWork.DiscreteStateSpace4_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% ReadAnalogInput_DWork.DiscreteStateSpace5_DSTATE
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% ReadAnalogInput_DWork.MM16ATAnalogInput_RWORK
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ReadAnalogInput_DWork.MM16ATAnalogInput_IWORK
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
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


  targMap.checksum0 = 2123821814;
  targMap.checksum1 = 1806069684;
  targMap.checksum2 = 3342642078;
  targMap.checksum3 = 1821963508;

