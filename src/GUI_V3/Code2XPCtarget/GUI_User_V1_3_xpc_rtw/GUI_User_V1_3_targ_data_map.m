  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 14;
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
    ;% Auto data (GUI_User_V1_3_P)
    ;%
      section.nData     = 446;
      section.data(446)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.ControlSignalsSetto0_Y0
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_P.Constant_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 6;
	
	  ;% GUI_User_V1_3_P.Constant1_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 7;
	
	  ;% GUI_User_V1_3_P.Constant2_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 8;
	
	  ;% GUI_User_V1_3_P.Constant3_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 9;
	
	  ;% GUI_User_V1_3_P.Constant4_Value
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% GUI_User_V1_3_P.Constant5_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 11;
	
	  ;% GUI_User_V1_3_P.ControlSig_Y0
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 12;
	
	  ;% GUI_User_V1_3_P.Constant1_Value_p
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 18;
	
	  ;% GUI_User_V1_3_P.Constant8_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 19;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain5_Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 20;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain6_Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 21;
	
	  ;% GUI_User_V1_3_P.Gain7_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 22;
	
	  ;% GUI_User_V1_3_P.Posi1Free_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 23;
	
	  ;% GUI_User_V1_3_P.ProportionalGain_Gain
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 24;
	
	  ;% GUI_User_V1_3_P.Integrator_gainval
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 25;
	
	  ;% GUI_User_V1_3_P.Integrator_IC
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 26;
	
	  ;% GUI_User_V1_3_P.DerivativeGain_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 27;
	
	  ;% GUI_User_V1_3_P.Filter_gainval
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 28;
	
	  ;% GUI_User_V1_3_P.Filter_IC
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 29;
	
	  ;% GUI_User_V1_3_P.FilterCoefficient_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 30;
	
	  ;% GUI_User_V1_3_P.Gain8_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 31;
	
	  ;% GUI_User_V1_3_P.IntegralGain_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 32;
	
	  ;% GUI_User_V1_3_P.Saturation1_UpperSat
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 33;
	
	  ;% GUI_User_V1_3_P.Saturation1_LowerSat
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 34;
	
	  ;% GUI_User_V1_3_P.Constant10_Value
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 35;
	
	  ;% GUI_User_V1_3_P.Constant9_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 36;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain3_Gain
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 37;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain4_Gain
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 38;
	
	  ;% GUI_User_V1_3_P.Posi2Free_Value
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 39;
	
	  ;% GUI_User_V1_3_P.ProportionalGain_Gain_f
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 40;
	
	  ;% GUI_User_V1_3_P.Integrator_gainval_p
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 41;
	
	  ;% GUI_User_V1_3_P.Integrator_IC_e
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 42;
	
	  ;% GUI_User_V1_3_P.DerivativeGain_Gain_a
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 43;
	
	  ;% GUI_User_V1_3_P.Filter_gainval_c
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 44;
	
	  ;% GUI_User_V1_3_P.Filter_IC_a
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 45;
	
	  ;% GUI_User_V1_3_P.FilterCoefficient_Gain_i
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 46;
	
	  ;% GUI_User_V1_3_P.Gain1_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 47;
	
	  ;% GUI_User_V1_3_P.IntegralGain_Gain_c
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 48;
	
	  ;% GUI_User_V1_3_P.Saturation2_UpperSat
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 49;
	
	  ;% GUI_User_V1_3_P.Saturation2_LowerSat
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 50;
	
	  ;% GUI_User_V1_3_P.Constant11_Value
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 51;
	
	  ;% GUI_User_V1_3_P.Constant12_Value
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 52;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain1_Gain
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 53;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain2_Gain
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 54;
	
	  ;% GUI_User_V1_3_P.Posi3Free_Value
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 55;
	
	  ;% GUI_User_V1_3_P.ProportionalGain_Gain_h
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 56;
	
	  ;% GUI_User_V1_3_P.Integrator_gainval_j
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 57;
	
	  ;% GUI_User_V1_3_P.Integrator_IC_n
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 58;
	
	  ;% GUI_User_V1_3_P.DerivativeGain_Gain_ax
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 59;
	
	  ;% GUI_User_V1_3_P.Filter_gainval_g
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 60;
	
	  ;% GUI_User_V1_3_P.Filter_IC_b
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 61;
	
	  ;% GUI_User_V1_3_P.FilterCoefficient_Gain_d
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 62;
	
	  ;% GUI_User_V1_3_P.Gain3_Gain
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 63;
	
	  ;% GUI_User_V1_3_P.IntegralGain_Gain_m
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 64;
	
	  ;% GUI_User_V1_3_P.Saturation3_UpperSat
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 65;
	
	  ;% GUI_User_V1_3_P.Saturation3_LowerSat
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 66;
	
	  ;% GUI_User_V1_3_P.Constant13_Value
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 67;
	
	  ;% GUI_User_V1_3_P.Constant14_Value
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 68;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain7_Gain
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 69;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain8_Gain
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 70;
	
	  ;% GUI_User_V1_3_P.Posi4Free_Value
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 71;
	
	  ;% GUI_User_V1_3_P.ProportionalGain_Gain_c
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 72;
	
	  ;% GUI_User_V1_3_P.Integrator_gainval_j4
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 73;
	
	  ;% GUI_User_V1_3_P.Integrator_IC_c
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 74;
	
	  ;% GUI_User_V1_3_P.DerivativeGain_Gain_c
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 75;
	
	  ;% GUI_User_V1_3_P.Filter_gainval_e
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 76;
	
	  ;% GUI_User_V1_3_P.Filter_IC_h
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 77;
	
	  ;% GUI_User_V1_3_P.FilterCoefficient_Gain_l
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 78;
	
	  ;% GUI_User_V1_3_P.Gain4_Gain
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 79;
	
	  ;% GUI_User_V1_3_P.IntegralGain_Gain_l
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 80;
	
	  ;% GUI_User_V1_3_P.Saturation_UpperSat
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 81;
	
	  ;% GUI_User_V1_3_P.Saturation_LowerSat
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 82;
	
	  ;% GUI_User_V1_3_P.Constant15_Value
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 83;
	
	  ;% GUI_User_V1_3_P.Constant16_Value
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 84;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain10_Gain
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 85;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain9_Gain
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 86;
	
	  ;% GUI_User_V1_3_P.Posi5Free_Value
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 87;
	
	  ;% GUI_User_V1_3_P.ProportionalGain_Gain_n
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 88;
	
	  ;% GUI_User_V1_3_P.Integrator_gainval_i
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 89;
	
	  ;% GUI_User_V1_3_P.Integrator_IC_g
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 90;
	
	  ;% GUI_User_V1_3_P.DerivativeGain_Gain_e
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 91;
	
	  ;% GUI_User_V1_3_P.Filter_gainval_cs
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 92;
	
	  ;% GUI_User_V1_3_P.Filter_IC_i
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 93;
	
	  ;% GUI_User_V1_3_P.FilterCoefficient_Gain_o
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 94;
	
	  ;% GUI_User_V1_3_P.Gain5_Gain
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 95;
	
	  ;% GUI_User_V1_3_P.IntegralGain_Gain_i
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 96;
	
	  ;% GUI_User_V1_3_P.Saturation4_UpperSat
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 97;
	
	  ;% GUI_User_V1_3_P.Saturation4_LowerSat
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 98;
	
	  ;% GUI_User_V1_3_P.Constant17_Value
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 99;
	
	  ;% GUI_User_V1_3_P.Constant18_Value
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 100;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain11_Gain
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 101;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain12_Gain
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 102;
	
	  ;% GUI_User_V1_3_P.Posi6Free_Value
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 103;
	
	  ;% GUI_User_V1_3_P.ProportionalGain_Gain_e
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 104;
	
	  ;% GUI_User_V1_3_P.Integrator_gainval_f
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 105;
	
	  ;% GUI_User_V1_3_P.Integrator_IC_d
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 106;
	
	  ;% GUI_User_V1_3_P.DerivativeGain_Gain_k
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 107;
	
	  ;% GUI_User_V1_3_P.Filter_gainval_n
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 108;
	
	  ;% GUI_User_V1_3_P.Filter_IC_n
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 109;
	
	  ;% GUI_User_V1_3_P.FilterCoefficient_Gain_b
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 110;
	
	  ;% GUI_User_V1_3_P.Gain6_Gain
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 111;
	
	  ;% GUI_User_V1_3_P.IntegralGain_Gain_j
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 112;
	
	  ;% GUI_User_V1_3_P.Saturation5_UpperSat
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 113;
	
	  ;% GUI_User_V1_3_P.Saturation5_LowerSat
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 114;
	
	  ;% GUI_User_V1_3_P.Controlsignal_Y0
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 115;
	
	  ;% GUI_User_V1_3_P.ReferenceTrayectory_Y0
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 121;
	
	  ;% GUI_User_V1_3_P.FromFile1_P1_Size
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 133;
	
	  ;% GUI_User_V1_3_P.FromFile1_P1
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 135;
	
	  ;% GUI_User_V1_3_P.FromFile1_P2_Size
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 158;
	
	  ;% GUI_User_V1_3_P.FromFile1_P2
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 160;
	
	  ;% GUI_User_V1_3_P.FromFile1_P3_Size
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 161;
	
	  ;% GUI_User_V1_3_P.FromFile1_P3
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 163;
	
	  ;% GUI_User_V1_3_P.FromFile1_P4_Size
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 164;
	
	  ;% GUI_User_V1_3_P.FromFile1_P4
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 166;
	
	  ;% GUI_User_V1_3_P.FromFile1_P5_Size
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 167;
	
	  ;% GUI_User_V1_3_P.FromFile1_P5
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 169;
	
	  ;% GUI_User_V1_3_P.FromFile1_P6_Size
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 170;
	
	  ;% GUI_User_V1_3_P.FromFile1_P6
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 172;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain1_Gain_p
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 173;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain10_Gain_k
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 174;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain11_Gain_k
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 175;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain12_Gain_j
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 176;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain2_Gain_f
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 177;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain3_Gain_d
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 178;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain4_Gain_e
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 179;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain5_Gain_f
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 180;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain6_Gain_k
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 181;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain7_Gain_n
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 182;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain8_Gain_f
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 183;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain9_Gain_c
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 184;
	
	  ;% GUI_User_V1_3_P.ProportionalGain_Gain_d
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 185;
	
	  ;% GUI_User_V1_3_P.Integrator_gainval_fe
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 186;
	
	  ;% GUI_User_V1_3_P.Integrator_IC_f
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 187;
	
	  ;% GUI_User_V1_3_P.DerivativeGain_Gain_g
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 188;
	
	  ;% GUI_User_V1_3_P.Filter_gainval_p
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 189;
	
	  ;% GUI_User_V1_3_P.Filter_IC_p
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 190;
	
	  ;% GUI_User_V1_3_P.FilterCoefficient_Gain_bu
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 191;
	
	  ;% GUI_User_V1_3_P.Gain1_Gain_i
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 192;
	
	  ;% GUI_User_V1_3_P.ProportionalGain_Gain_p
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 193;
	
	  ;% GUI_User_V1_3_P.Integrator_gainval_c
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 194;
	
	  ;% GUI_User_V1_3_P.Integrator_IC_cd
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 195;
	
	  ;% GUI_User_V1_3_P.DerivativeGain_Gain_n
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 196;
	
	  ;% GUI_User_V1_3_P.Filter_gainval_o
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 197;
	
	  ;% GUI_User_V1_3_P.Filter_IC_aa
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 198;
	
	  ;% GUI_User_V1_3_P.FilterCoefficient_Gain_g
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 199;
	
	  ;% GUI_User_V1_3_P.Gain3_Gain_l
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 200;
	
	  ;% GUI_User_V1_3_P.ProportionalGain_Gain_j
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 201;
	
	  ;% GUI_User_V1_3_P.Integrator_gainval_g
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 202;
	
	  ;% GUI_User_V1_3_P.Integrator_IC_db
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 203;
	
	  ;% GUI_User_V1_3_P.DerivativeGain_Gain_ny
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 204;
	
	  ;% GUI_User_V1_3_P.Filter_gainval_m
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 205;
	
	  ;% GUI_User_V1_3_P.Filter_IC_nf
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 206;
	
	  ;% GUI_User_V1_3_P.FilterCoefficient_Gain_j
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 207;
	
	  ;% GUI_User_V1_3_P.Gain4_Gain_e
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 208;
	
	  ;% GUI_User_V1_3_P.ProportionalGain_Gain_m
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 209;
	
	  ;% GUI_User_V1_3_P.Integrator_gainval_m
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 210;
	
	  ;% GUI_User_V1_3_P.Integrator_IC_dm
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 211;
	
	  ;% GUI_User_V1_3_P.DerivativeGain_Gain_o
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 212;
	
	  ;% GUI_User_V1_3_P.Filter_gainval_d
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 213;
	
	  ;% GUI_User_V1_3_P.Filter_IC_m
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 214;
	
	  ;% GUI_User_V1_3_P.FilterCoefficient_Gain_ih
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 215;
	
	  ;% GUI_User_V1_3_P.Gain5_Gain_e
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 216;
	
	  ;% GUI_User_V1_3_P.ProportionalGain_Gain_i
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 217;
	
	  ;% GUI_User_V1_3_P.Integrator_gainval_d
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 218;
	
	  ;% GUI_User_V1_3_P.Integrator_IC_k
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 219;
	
	  ;% GUI_User_V1_3_P.DerivativeGain_Gain_h
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 220;
	
	  ;% GUI_User_V1_3_P.Filter_gainval_m1
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 221;
	
	  ;% GUI_User_V1_3_P.Filter_IC_nc
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 222;
	
	  ;% GUI_User_V1_3_P.FilterCoefficient_Gain_dz
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 223;
	
	  ;% GUI_User_V1_3_P.Gain6_Gain_e
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 224;
	
	  ;% GUI_User_V1_3_P.Gain7_Gain_l
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 225;
	
	  ;% GUI_User_V1_3_P.ProportionalGain_Gain_c5
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 226;
	
	  ;% GUI_User_V1_3_P.Integrator_gainval_l
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 227;
	
	  ;% GUI_User_V1_3_P.Integrator_IC_dv
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 228;
	
	  ;% GUI_User_V1_3_P.DerivativeGain_Gain_m
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 229;
	
	  ;% GUI_User_V1_3_P.Filter_gainval_py
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 230;
	
	  ;% GUI_User_V1_3_P.Filter_IC_o
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 231;
	
	  ;% GUI_User_V1_3_P.FilterCoefficient_Gain_a
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 232;
	
	  ;% GUI_User_V1_3_P.Gain8_Gain_g
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 233;
	
	  ;% GUI_User_V1_3_P.IntegralGain_Gain_n
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 234;
	
	  ;% GUI_User_V1_3_P.IntegralGain_Gain_jp
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 235;
	
	  ;% GUI_User_V1_3_P.IntegralGain_Gain_h
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 236;
	
	  ;% GUI_User_V1_3_P.IntegralGain_Gain_iw
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 237;
	
	  ;% GUI_User_V1_3_P.IntegralGain_Gain_ip
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 238;
	
	  ;% GUI_User_V1_3_P.IntegralGain_Gain_he
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 239;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole1_A
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 240;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole1_B
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 248;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole1_C
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 249;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole2_A
	  section.data(190).logicalSrcIdx = 191;
	  section.data(190).dtTransOffset = 253;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole2_B
	  section.data(191).logicalSrcIdx = 192;
	  section.data(191).dtTransOffset = 261;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole2_C
	  section.data(192).logicalSrcIdx = 193;
	  section.data(192).dtTransOffset = 262;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole3_A
	  section.data(193).logicalSrcIdx = 196;
	  section.data(193).dtTransOffset = 266;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole3_B
	  section.data(194).logicalSrcIdx = 197;
	  section.data(194).dtTransOffset = 274;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole3_C
	  section.data(195).logicalSrcIdx = 198;
	  section.data(195).dtTransOffset = 275;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole4_A
	  section.data(196).logicalSrcIdx = 201;
	  section.data(196).dtTransOffset = 279;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole4_B
	  section.data(197).logicalSrcIdx = 202;
	  section.data(197).dtTransOffset = 287;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole4_C
	  section.data(198).logicalSrcIdx = 203;
	  section.data(198).dtTransOffset = 288;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole5_A
	  section.data(199).logicalSrcIdx = 206;
	  section.data(199).dtTransOffset = 292;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole5_B
	  section.data(200).logicalSrcIdx = 207;
	  section.data(200).dtTransOffset = 300;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole5_C
	  section.data(201).logicalSrcIdx = 208;
	  section.data(201).dtTransOffset = 301;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole6_A
	  section.data(202).logicalSrcIdx = 211;
	  section.data(202).dtTransOffset = 305;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole6_B
	  section.data(203).logicalSrcIdx = 212;
	  section.data(203).dtTransOffset = 313;
	
	  ;% GUI_User_V1_3_P.DiscreteZeroPole6_C
	  section.data(204).logicalSrcIdx = 213;
	  section.data(204).dtTransOffset = 314;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain1_Gain_l
	  section.data(205).logicalSrcIdx = 216;
	  section.data(205).dtTransOffset = 318;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain10_Gain_e
	  section.data(206).logicalSrcIdx = 217;
	  section.data(206).dtTransOffset = 319;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain11_Gain_b
	  section.data(207).logicalSrcIdx = 218;
	  section.data(207).dtTransOffset = 320;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain12_Gain_h
	  section.data(208).logicalSrcIdx = 219;
	  section.data(208).dtTransOffset = 321;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain2_Gain_i
	  section.data(209).logicalSrcIdx = 220;
	  section.data(209).dtTransOffset = 322;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain3_Gain_c
	  section.data(210).logicalSrcIdx = 221;
	  section.data(210).dtTransOffset = 323;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain4_Gain_i
	  section.data(211).logicalSrcIdx = 222;
	  section.data(211).dtTransOffset = 324;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain5_Gain_n
	  section.data(212).logicalSrcIdx = 223;
	  section.data(212).dtTransOffset = 325;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain6_Gain_h
	  section.data(213).logicalSrcIdx = 224;
	  section.data(213).dtTransOffset = 326;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain7_Gain_l
	  section.data(214).logicalSrcIdx = 225;
	  section.data(214).dtTransOffset = 327;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain8_Gain_m
	  section.data(215).logicalSrcIdx = 226;
	  section.data(215).dtTransOffset = 328;
	
	  ;% GUI_User_V1_3_P.FeeedForwardGain9_Gain_b
	  section.data(216).logicalSrcIdx = 227;
	  section.data(216).dtTransOffset = 329;
	
	  ;% GUI_User_V1_3_P.Gain1_Gain_p
	  section.data(217).logicalSrcIdx = 228;
	  section.data(217).dtTransOffset = 330;
	
	  ;% GUI_User_V1_3_P.Gain3_Gain_o
	  section.data(218).logicalSrcIdx = 229;
	  section.data(218).dtTransOffset = 331;
	
	  ;% GUI_User_V1_3_P.Gain4_Gain_k
	  section.data(219).logicalSrcIdx = 230;
	  section.data(219).dtTransOffset = 332;
	
	  ;% GUI_User_V1_3_P.Gain5_Gain_i
	  section.data(220).logicalSrcIdx = 231;
	  section.data(220).dtTransOffset = 333;
	
	  ;% GUI_User_V1_3_P.Gain6_Gain_a
	  section.data(221).logicalSrcIdx = 232;
	  section.data(221).dtTransOffset = 334;
	
	  ;% GUI_User_V1_3_P.Gain7_Gain_a
	  section.data(222).logicalSrcIdx = 233;
	  section.data(222).dtTransOffset = 335;
	
	  ;% GUI_User_V1_3_P.Gain8_Gain_l
	  section.data(223).logicalSrcIdx = 234;
	  section.data(223).dtTransOffset = 336;
	
	  ;% GUI_User_V1_3_P.ControlSignals_Y0
	  section.data(224).logicalSrcIdx = 235;
	  section.data(224).dtTransOffset = 337;
	
	  ;% GUI_User_V1_3_P.Constant_Value_n
	  section.data(225).logicalSrcIdx = 236;
	  section.data(225).dtTransOffset = 343;
	
	  ;% GUI_User_V1_3_P.Constant1_Value_m
	  section.data(226).logicalSrcIdx = 237;
	  section.data(226).dtTransOffset = 344;
	
	  ;% GUI_User_V1_3_P.Constant2_Value_n
	  section.data(227).logicalSrcIdx = 238;
	  section.data(227).dtTransOffset = 345;
	
	  ;% GUI_User_V1_3_P.Constant3_Value_i
	  section.data(228).logicalSrcIdx = 239;
	  section.data(228).dtTransOffset = 346;
	
	  ;% GUI_User_V1_3_P.Constant4_Value_h
	  section.data(229).logicalSrcIdx = 240;
	  section.data(229).dtTransOffset = 347;
	
	  ;% GUI_User_V1_3_P.Constant5_Value_e
	  section.data(230).logicalSrcIdx = 241;
	  section.data(230).dtTransOffset = 348;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P1_Size
	  section.data(231).logicalSrcIdx = 242;
	  section.data(231).dtTransOffset = 349;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P1
	  section.data(232).logicalSrcIdx = 243;
	  section.data(232).dtTransOffset = 351;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P2_Size
	  section.data(233).logicalSrcIdx = 244;
	  section.data(233).dtTransOffset = 352;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P2
	  section.data(234).logicalSrcIdx = 245;
	  section.data(234).dtTransOffset = 354;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P3_Size
	  section.data(235).logicalSrcIdx = 246;
	  section.data(235).dtTransOffset = 355;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P3
	  section.data(236).logicalSrcIdx = 247;
	  section.data(236).dtTransOffset = 357;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P4_Size
	  section.data(237).logicalSrcIdx = 248;
	  section.data(237).dtTransOffset = 358;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P4
	  section.data(238).logicalSrcIdx = 249;
	  section.data(238).dtTransOffset = 360;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P5_Size
	  section.data(239).logicalSrcIdx = 250;
	  section.data(239).dtTransOffset = 361;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P5
	  section.data(240).logicalSrcIdx = 251;
	  section.data(240).dtTransOffset = 363;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P1_Size
	  section.data(241).logicalSrcIdx = 252;
	  section.data(241).dtTransOffset = 383;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P1
	  section.data(242).logicalSrcIdx = 253;
	  section.data(242).dtTransOffset = 385;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P2_Size
	  section.data(243).logicalSrcIdx = 254;
	  section.data(243).dtTransOffset = 386;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P2
	  section.data(244).logicalSrcIdx = 255;
	  section.data(244).dtTransOffset = 388;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P3_Size
	  section.data(245).logicalSrcIdx = 256;
	  section.data(245).dtTransOffset = 389;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P3
	  section.data(246).logicalSrcIdx = 257;
	  section.data(246).dtTransOffset = 391;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P4_Size
	  section.data(247).logicalSrcIdx = 258;
	  section.data(247).dtTransOffset = 392;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P4
	  section.data(248).logicalSrcIdx = 259;
	  section.data(248).dtTransOffset = 394;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P5_Size
	  section.data(249).logicalSrcIdx = 260;
	  section.data(249).dtTransOffset = 395;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P5
	  section.data(250).logicalSrcIdx = 261;
	  section.data(250).dtTransOffset = 397;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P6_Size
	  section.data(251).logicalSrcIdx = 262;
	  section.data(251).dtTransOffset = 398;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P6
	  section.data(252).logicalSrcIdx = 263;
	  section.data(252).dtTransOffset = 400;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P7_Size
	  section.data(253).logicalSrcIdx = 264;
	  section.data(253).dtTransOffset = 401;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P7
	  section.data(254).logicalSrcIdx = 265;
	  section.data(254).dtTransOffset = 403;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P8_Size
	  section.data(255).logicalSrcIdx = 266;
	  section.data(255).dtTransOffset = 404;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P8
	  section.data(256).logicalSrcIdx = 267;
	  section.data(256).dtTransOffset = 406;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P1_Size
	  section.data(257).logicalSrcIdx = 268;
	  section.data(257).dtTransOffset = 407;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P1
	  section.data(258).logicalSrcIdx = 269;
	  section.data(258).dtTransOffset = 409;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P2_Size
	  section.data(259).logicalSrcIdx = 270;
	  section.data(259).dtTransOffset = 410;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P2
	  section.data(260).logicalSrcIdx = 271;
	  section.data(260).dtTransOffset = 412;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P3_Size
	  section.data(261).logicalSrcIdx = 272;
	  section.data(261).dtTransOffset = 413;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P3
	  section.data(262).logicalSrcIdx = 273;
	  section.data(262).dtTransOffset = 415;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P4_Size
	  section.data(263).logicalSrcIdx = 274;
	  section.data(263).dtTransOffset = 416;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P4
	  section.data(264).logicalSrcIdx = 275;
	  section.data(264).dtTransOffset = 418;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P5_Size
	  section.data(265).logicalSrcIdx = 276;
	  section.data(265).dtTransOffset = 419;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P5
	  section.data(266).logicalSrcIdx = 277;
	  section.data(266).dtTransOffset = 421;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P1_Size
	  section.data(267).logicalSrcIdx = 278;
	  section.data(267).dtTransOffset = 441;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P1
	  section.data(268).logicalSrcIdx = 279;
	  section.data(268).dtTransOffset = 443;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P2_Size
	  section.data(269).logicalSrcIdx = 280;
	  section.data(269).dtTransOffset = 444;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P2
	  section.data(270).logicalSrcIdx = 281;
	  section.data(270).dtTransOffset = 446;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P3_Size
	  section.data(271).logicalSrcIdx = 282;
	  section.data(271).dtTransOffset = 447;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P3
	  section.data(272).logicalSrcIdx = 283;
	  section.data(272).dtTransOffset = 449;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P4_Size
	  section.data(273).logicalSrcIdx = 284;
	  section.data(273).dtTransOffset = 450;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P4
	  section.data(274).logicalSrcIdx = 285;
	  section.data(274).dtTransOffset = 452;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P5_Size
	  section.data(275).logicalSrcIdx = 286;
	  section.data(275).dtTransOffset = 453;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P5
	  section.data(276).logicalSrcIdx = 287;
	  section.data(276).dtTransOffset = 455;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P6_Size
	  section.data(277).logicalSrcIdx = 288;
	  section.data(277).dtTransOffset = 456;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P6
	  section.data(278).logicalSrcIdx = 289;
	  section.data(278).dtTransOffset = 458;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P7_Size
	  section.data(279).logicalSrcIdx = 290;
	  section.data(279).dtTransOffset = 459;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P7
	  section.data(280).logicalSrcIdx = 291;
	  section.data(280).dtTransOffset = 461;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P8_Size
	  section.data(281).logicalSrcIdx = 292;
	  section.data(281).dtTransOffset = 462;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P8
	  section.data(282).logicalSrcIdx = 293;
	  section.data(282).dtTransOffset = 464;
	
	  ;% GUI_User_V1_3_P.ControlConstant_Value
	  section.data(283).logicalSrcIdx = 294;
	  section.data(283).dtTransOffset = 465;
	
	  ;% GUI_User_V1_3_P.MM16ATAnalogInput_P1_Size
	  section.data(284).logicalSrcIdx = 295;
	  section.data(284).dtTransOffset = 466;
	
	  ;% GUI_User_V1_3_P.MM16ATAnalogInput_P1
	  section.data(285).logicalSrcIdx = 296;
	  section.data(285).dtTransOffset = 468;
	
	  ;% GUI_User_V1_3_P.MM16ATAnalogInput_P2_Size
	  section.data(286).logicalSrcIdx = 297;
	  section.data(286).dtTransOffset = 469;
	
	  ;% GUI_User_V1_3_P.MM16ATAnalogInput_P2
	  section.data(287).logicalSrcIdx = 298;
	  section.data(287).dtTransOffset = 471;
	
	  ;% GUI_User_V1_3_P.MM16ATAnalogInput_P3_Size
	  section.data(288).logicalSrcIdx = 299;
	  section.data(288).dtTransOffset = 472;
	
	  ;% GUI_User_V1_3_P.MM16ATAnalogInput_P3
	  section.data(289).logicalSrcIdx = 300;
	  section.data(289).dtTransOffset = 474;
	
	  ;% GUI_User_V1_3_P.MM16ATAnalogInput_P4_Size
	  section.data(290).logicalSrcIdx = 301;
	  section.data(290).dtTransOffset = 475;
	
	  ;% GUI_User_V1_3_P.MM16ATAnalogInput_P4
	  section.data(291).logicalSrcIdx = 302;
	  section.data(291).dtTransOffset = 477;
	
	  ;% GUI_User_V1_3_P.MM16ATAnalogInput_P5_Size
	  section.data(292).logicalSrcIdx = 303;
	  section.data(292).dtTransOffset = 478;
	
	  ;% GUI_User_V1_3_P.MM16ATAnalogInput_P5
	  section.data(293).logicalSrcIdx = 304;
	  section.data(293).dtTransOffset = 480;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace5_A
	  section.data(294).logicalSrcIdx = 305;
	  section.data(294).dtTransOffset = 481;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace5_B
	  section.data(295).logicalSrcIdx = 306;
	  section.data(295).dtTransOffset = 485;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace5_C
	  section.data(296).logicalSrcIdx = 307;
	  section.data(296).dtTransOffset = 487;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace5_D
	  section.data(297).logicalSrcIdx = 308;
	  section.data(297).dtTransOffset = 489;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace5_X0
	  section.data(298).logicalSrcIdx = 309;
	  section.data(298).dtTransOffset = 490;
	
	  ;% GUI_User_V1_3_P.Gain11_Gain
	  section.data(299).logicalSrcIdx = 310;
	  section.data(299).dtTransOffset = 492;
	
	  ;% GUI_User_V1_3_P.Constant6_Value
	  section.data(300).logicalSrcIdx = 311;
	  section.data(300).dtTransOffset = 493;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace4_A
	  section.data(301).logicalSrcIdx = 312;
	  section.data(301).dtTransOffset = 494;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace4_B
	  section.data(302).logicalSrcIdx = 313;
	  section.data(302).dtTransOffset = 498;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace4_C
	  section.data(303).logicalSrcIdx = 314;
	  section.data(303).dtTransOffset = 500;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace4_D
	  section.data(304).logicalSrcIdx = 315;
	  section.data(304).dtTransOffset = 502;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace4_X0
	  section.data(305).logicalSrcIdx = 316;
	  section.data(305).dtTransOffset = 503;
	
	  ;% GUI_User_V1_3_P.Gain10_Gain
	  section.data(306).logicalSrcIdx = 317;
	  section.data(306).dtTransOffset = 505;
	
	  ;% GUI_User_V1_3_P.Constant5_Value_p
	  section.data(307).logicalSrcIdx = 318;
	  section.data(307).dtTransOffset = 506;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace3_A
	  section.data(308).logicalSrcIdx = 319;
	  section.data(308).dtTransOffset = 507;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace3_B
	  section.data(309).logicalSrcIdx = 320;
	  section.data(309).dtTransOffset = 511;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace3_C
	  section.data(310).logicalSrcIdx = 321;
	  section.data(310).dtTransOffset = 513;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace3_D
	  section.data(311).logicalSrcIdx = 322;
	  section.data(311).dtTransOffset = 515;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace3_X0
	  section.data(312).logicalSrcIdx = 323;
	  section.data(312).dtTransOffset = 516;
	
	  ;% GUI_User_V1_3_P.Gain9_Gain
	  section.data(313).logicalSrcIdx = 324;
	  section.data(313).dtTransOffset = 518;
	
	  ;% GUI_User_V1_3_P.Constant4_Value_p
	  section.data(314).logicalSrcIdx = 325;
	  section.data(314).dtTransOffset = 519;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace2_A
	  section.data(315).logicalSrcIdx = 326;
	  section.data(315).dtTransOffset = 520;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace2_B
	  section.data(316).logicalSrcIdx = 327;
	  section.data(316).dtTransOffset = 524;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace2_C
	  section.data(317).logicalSrcIdx = 328;
	  section.data(317).dtTransOffset = 526;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace2_D
	  section.data(318).logicalSrcIdx = 329;
	  section.data(318).dtTransOffset = 528;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace2_X0
	  section.data(319).logicalSrcIdx = 330;
	  section.data(319).dtTransOffset = 529;
	
	  ;% GUI_User_V1_3_P.Gain8_Gain_e
	  section.data(320).logicalSrcIdx = 331;
	  section.data(320).dtTransOffset = 531;
	
	  ;% GUI_User_V1_3_P.Constant3_Value_c
	  section.data(321).logicalSrcIdx = 332;
	  section.data(321).dtTransOffset = 532;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace1_A
	  section.data(322).logicalSrcIdx = 333;
	  section.data(322).dtTransOffset = 533;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace1_B
	  section.data(323).logicalSrcIdx = 334;
	  section.data(323).dtTransOffset = 537;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace1_C
	  section.data(324).logicalSrcIdx = 335;
	  section.data(324).dtTransOffset = 539;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace1_D
	  section.data(325).logicalSrcIdx = 336;
	  section.data(325).dtTransOffset = 541;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace1_X0
	  section.data(326).logicalSrcIdx = 337;
	  section.data(326).dtTransOffset = 542;
	
	  ;% GUI_User_V1_3_P.Gain1_Gain_g
	  section.data(327).logicalSrcIdx = 338;
	  section.data(327).dtTransOffset = 544;
	
	  ;% GUI_User_V1_3_P.Constant1_Value_n
	  section.data(328).logicalSrcIdx = 339;
	  section.data(328).dtTransOffset = 545;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace6_A
	  section.data(329).logicalSrcIdx = 340;
	  section.data(329).dtTransOffset = 546;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace6_B
	  section.data(330).logicalSrcIdx = 341;
	  section.data(330).dtTransOffset = 550;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace6_C
	  section.data(331).logicalSrcIdx = 342;
	  section.data(331).dtTransOffset = 552;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace6_D
	  section.data(332).logicalSrcIdx = 343;
	  section.data(332).dtTransOffset = 554;
	
	  ;% GUI_User_V1_3_P.DiscreteStateSpace6_X0
	  section.data(333).logicalSrcIdx = 344;
	  section.data(333).dtTransOffset = 555;
	
	  ;% GUI_User_V1_3_P.Gain_Gain
	  section.data(334).logicalSrcIdx = 345;
	  section.data(334).dtTransOffset = 557;
	
	  ;% GUI_User_V1_3_P.Constant2_Value_f
	  section.data(335).logicalSrcIdx = 346;
	  section.data(335).dtTransOffset = 558;
	
	  ;% GUI_User_V1_3_P.Merge_InitialOutput
	  section.data(336).logicalSrcIdx = 347;
	  section.data(336).dtTransOffset = 559;
	
	  ;% GUI_User_V1_3_P.Saturation_UpperSat_j
	  section.data(337).logicalSrcIdx = 348;
	  section.data(337).dtTransOffset = 565;
	
	  ;% GUI_User_V1_3_P.Saturation_LowerSat_b
	  section.data(338).logicalSrcIdx = 349;
	  section.data(338).dtTransOffset = 566;
	
	  ;% GUI_User_V1_3_P.Saturation1_UpperSat_b
	  section.data(339).logicalSrcIdx = 350;
	  section.data(339).dtTransOffset = 567;
	
	  ;% GUI_User_V1_3_P.Saturation1_LowerSat_m
	  section.data(340).logicalSrcIdx = 351;
	  section.data(340).dtTransOffset = 568;
	
	  ;% GUI_User_V1_3_P.Saturation2_UpperSat_j
	  section.data(341).logicalSrcIdx = 352;
	  section.data(341).dtTransOffset = 569;
	
	  ;% GUI_User_V1_3_P.Saturation2_LowerSat_a
	  section.data(342).logicalSrcIdx = 353;
	  section.data(342).dtTransOffset = 570;
	
	  ;% GUI_User_V1_3_P.Saturation3_UpperSat_m
	  section.data(343).logicalSrcIdx = 354;
	  section.data(343).dtTransOffset = 571;
	
	  ;% GUI_User_V1_3_P.Saturation3_LowerSat_j
	  section.data(344).logicalSrcIdx = 355;
	  section.data(344).dtTransOffset = 572;
	
	  ;% GUI_User_V1_3_P.Saturation4_UpperSat_n
	  section.data(345).logicalSrcIdx = 356;
	  section.data(345).dtTransOffset = 573;
	
	  ;% GUI_User_V1_3_P.Saturation4_LowerSat_p
	  section.data(346).logicalSrcIdx = 357;
	  section.data(346).dtTransOffset = 574;
	
	  ;% GUI_User_V1_3_P.Saturation5_UpperSat_l
	  section.data(347).logicalSrcIdx = 358;
	  section.data(347).dtTransOffset = 575;
	
	  ;% GUI_User_V1_3_P.Saturation5_LowerSat_l
	  section.data(348).logicalSrcIdx = 359;
	  section.data(348).dtTransOffset = 576;
	
	  ;% GUI_User_V1_3_P.ASCIIEncode_P1_Size
	  section.data(349).logicalSrcIdx = 360;
	  section.data(349).dtTransOffset = 577;
	
	  ;% GUI_User_V1_3_P.ASCIIEncode_P1
	  section.data(350).logicalSrcIdx = 361;
	  section.data(350).dtTransOffset = 579;
	
	  ;% GUI_User_V1_3_P.ASCIIEncode_P2_Size
	  section.data(351).logicalSrcIdx = 362;
	  section.data(351).dtTransOffset = 592;
	
	  ;% GUI_User_V1_3_P.ASCIIEncode_P2
	  section.data(352).logicalSrcIdx = 363;
	  section.data(352).dtTransOffset = 594;
	
	  ;% GUI_User_V1_3_P.ASCIIEncode_P3_Size
	  section.data(353).logicalSrcIdx = 364;
	  section.data(353).dtTransOffset = 595;
	
	  ;% GUI_User_V1_3_P.ASCIIEncode_P3
	  section.data(354).logicalSrcIdx = 365;
	  section.data(354).dtTransOffset = 597;
	
	  ;% GUI_User_V1_3_P.ASCIIEncode_P4_Size
	  section.data(355).logicalSrcIdx = 366;
	  section.data(355).dtTransOffset = 598;
	
	  ;% GUI_User_V1_3_P.ASCIIEncode_P4
	  section.data(356).logicalSrcIdx = 367;
	  section.data(356).dtTransOffset = 600;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P1_Size_j
	  section.data(357).logicalSrcIdx = 368;
	  section.data(357).dtTransOffset = 606;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P1_m
	  section.data(358).logicalSrcIdx = 369;
	  section.data(358).dtTransOffset = 608;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P2_Size_b
	  section.data(359).logicalSrcIdx = 370;
	  section.data(359).dtTransOffset = 609;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P2_n
	  section.data(360).logicalSrcIdx = 371;
	  section.data(360).dtTransOffset = 611;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P3_Size_f
	  section.data(361).logicalSrcIdx = 372;
	  section.data(361).dtTransOffset = 612;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P3_g
	  section.data(362).logicalSrcIdx = 373;
	  section.data(362).dtTransOffset = 614;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P4_Size_o
	  section.data(363).logicalSrcIdx = 374;
	  section.data(363).dtTransOffset = 615;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P4_i
	  section.data(364).logicalSrcIdx = 375;
	  section.data(364).dtTransOffset = 617;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P5_Size_f
	  section.data(365).logicalSrcIdx = 376;
	  section.data(365).dtTransOffset = 618;
	
	  ;% GUI_User_V1_3_P.FIFOwrite1_P5_h
	  section.data(366).logicalSrcIdx = 377;
	  section.data(366).dtTransOffset = 620;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P1_Size_j
	  section.data(367).logicalSrcIdx = 378;
	  section.data(367).dtTransOffset = 640;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P1_c
	  section.data(368).logicalSrcIdx = 379;
	  section.data(368).dtTransOffset = 642;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P2_Size_a
	  section.data(369).logicalSrcIdx = 380;
	  section.data(369).dtTransOffset = 643;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P2_n
	  section.data(370).logicalSrcIdx = 381;
	  section.data(370).dtTransOffset = 645;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P3_Size_e
	  section.data(371).logicalSrcIdx = 382;
	  section.data(371).dtTransOffset = 646;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P3_e
	  section.data(372).logicalSrcIdx = 383;
	  section.data(372).dtTransOffset = 648;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P4_Size_d
	  section.data(373).logicalSrcIdx = 384;
	  section.data(373).dtTransOffset = 649;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P4_i
	  section.data(374).logicalSrcIdx = 385;
	  section.data(374).dtTransOffset = 651;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P5_Size_d
	  section.data(375).logicalSrcIdx = 386;
	  section.data(375).dtTransOffset = 652;
	
	  ;% GUI_User_V1_3_P.FIFOwrite2_P5_o
	  section.data(376).logicalSrcIdx = 387;
	  section.data(376).dtTransOffset = 654;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P1_Size_n
	  section.data(377).logicalSrcIdx = 388;
	  section.data(377).dtTransOffset = 674;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P1_f
	  section.data(378).logicalSrcIdx = 389;
	  section.data(378).dtTransOffset = 676;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P2_Size_i
	  section.data(379).logicalSrcIdx = 390;
	  section.data(379).dtTransOffset = 677;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P2_d
	  section.data(380).logicalSrcIdx = 391;
	  section.data(380).dtTransOffset = 679;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P3_Size_l
	  section.data(381).logicalSrcIdx = 392;
	  section.data(381).dtTransOffset = 680;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P3_d
	  section.data(382).logicalSrcIdx = 393;
	  section.data(382).dtTransOffset = 682;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P4_Size_c
	  section.data(383).logicalSrcIdx = 394;
	  section.data(383).dtTransOffset = 683;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P4_o
	  section.data(384).logicalSrcIdx = 395;
	  section.data(384).dtTransOffset = 685;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P5_Size_b
	  section.data(385).logicalSrcIdx = 396;
	  section.data(385).dtTransOffset = 686;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P5_d
	  section.data(386).logicalSrcIdx = 397;
	  section.data(386).dtTransOffset = 688;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P6_Size_g
	  section.data(387).logicalSrcIdx = 398;
	  section.data(387).dtTransOffset = 689;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P6_h
	  section.data(388).logicalSrcIdx = 399;
	  section.data(388).dtTransOffset = 691;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P7_Size_b
	  section.data(389).logicalSrcIdx = 400;
	  section.data(389).dtTransOffset = 692;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P7_h
	  section.data(390).logicalSrcIdx = 401;
	  section.data(390).dtTransOffset = 694;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P8_Size_p
	  section.data(391).logicalSrcIdx = 402;
	  section.data(391).dtTransOffset = 695;
	
	  ;% GUI_User_V1_3_P.FIFOread1_P8_n
	  section.data(392).logicalSrcIdx = 403;
	  section.data(392).dtTransOffset = 697;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P1_Size_d
	  section.data(393).logicalSrcIdx = 404;
	  section.data(393).dtTransOffset = 698;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P1_c
	  section.data(394).logicalSrcIdx = 405;
	  section.data(394).dtTransOffset = 700;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P2_Size_g
	  section.data(395).logicalSrcIdx = 406;
	  section.data(395).dtTransOffset = 701;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P2_g
	  section.data(396).logicalSrcIdx = 407;
	  section.data(396).dtTransOffset = 703;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P3_Size_f
	  section.data(397).logicalSrcIdx = 408;
	  section.data(397).dtTransOffset = 704;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P3_o
	  section.data(398).logicalSrcIdx = 409;
	  section.data(398).dtTransOffset = 706;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P4_Size_e
	  section.data(399).logicalSrcIdx = 410;
	  section.data(399).dtTransOffset = 707;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P4_a
	  section.data(400).logicalSrcIdx = 411;
	  section.data(400).dtTransOffset = 709;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P5_Size_d
	  section.data(401).logicalSrcIdx = 412;
	  section.data(401).dtTransOffset = 710;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P5_c
	  section.data(402).logicalSrcIdx = 413;
	  section.data(402).dtTransOffset = 712;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P6_Size_p
	  section.data(403).logicalSrcIdx = 414;
	  section.data(403).dtTransOffset = 713;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P6_k
	  section.data(404).logicalSrcIdx = 415;
	  section.data(404).dtTransOffset = 715;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P7_Size_n
	  section.data(405).logicalSrcIdx = 416;
	  section.data(405).dtTransOffset = 716;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P7_c
	  section.data(406).logicalSrcIdx = 417;
	  section.data(406).dtTransOffset = 718;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P8_Size_k
	  section.data(407).logicalSrcIdx = 418;
	  section.data(407).dtTransOffset = 719;
	
	  ;% GUI_User_V1_3_P.FIFOread2_P8_a
	  section.data(408).logicalSrcIdx = 419;
	  section.data(408).dtTransOffset = 721;
	
	  ;% GUI_User_V1_3_P.Setup1_P1_Size
	  section.data(409).logicalSrcIdx = 420;
	  section.data(409).dtTransOffset = 722;
	
	  ;% GUI_User_V1_3_P.Setup1_P1
	  section.data(410).logicalSrcIdx = 421;
	  section.data(410).dtTransOffset = 724;
	
	  ;% GUI_User_V1_3_P.Setup1_P2_Size
	  section.data(411).logicalSrcIdx = 422;
	  section.data(411).dtTransOffset = 725;
	
	  ;% GUI_User_V1_3_P.Setup1_P2
	  section.data(412).logicalSrcIdx = 423;
	  section.data(412).dtTransOffset = 727;
	
	  ;% GUI_User_V1_3_P.Setup1_P3_Size
	  section.data(413).logicalSrcIdx = 424;
	  section.data(413).dtTransOffset = 728;
	
	  ;% GUI_User_V1_3_P.Setup1_P3
	  section.data(414).logicalSrcIdx = 425;
	  section.data(414).dtTransOffset = 730;
	
	  ;% GUI_User_V1_3_P.Setup1_P4_Size
	  section.data(415).logicalSrcIdx = 426;
	  section.data(415).dtTransOffset = 731;
	
	  ;% GUI_User_V1_3_P.Setup1_P4
	  section.data(416).logicalSrcIdx = 427;
	  section.data(416).dtTransOffset = 733;
	
	  ;% GUI_User_V1_3_P.Setup1_P5_Size
	  section.data(417).logicalSrcIdx = 428;
	  section.data(417).dtTransOffset = 734;
	
	  ;% GUI_User_V1_3_P.Setup1_P5
	  section.data(418).logicalSrcIdx = 429;
	  section.data(418).dtTransOffset = 736;
	
	  ;% GUI_User_V1_3_P.Setup1_P6_Size
	  section.data(419).logicalSrcIdx = 430;
	  section.data(419).dtTransOffset = 737;
	
	  ;% GUI_User_V1_3_P.Setup1_P6
	  section.data(420).logicalSrcIdx = 431;
	  section.data(420).dtTransOffset = 739;
	
	  ;% GUI_User_V1_3_P.Setup1_P7_Size
	  section.data(421).logicalSrcIdx = 432;
	  section.data(421).dtTransOffset = 740;
	
	  ;% GUI_User_V1_3_P.Setup1_P7
	  section.data(422).logicalSrcIdx = 433;
	  section.data(422).dtTransOffset = 742;
	
	  ;% GUI_User_V1_3_P.Setup1_P8_Size
	  section.data(423).logicalSrcIdx = 434;
	  section.data(423).dtTransOffset = 743;
	
	  ;% GUI_User_V1_3_P.Setup1_P8
	  section.data(424).logicalSrcIdx = 435;
	  section.data(424).dtTransOffset = 745;
	
	  ;% GUI_User_V1_3_P.Setup2_P1_Size
	  section.data(425).logicalSrcIdx = 436;
	  section.data(425).dtTransOffset = 746;
	
	  ;% GUI_User_V1_3_P.Setup2_P1
	  section.data(426).logicalSrcIdx = 437;
	  section.data(426).dtTransOffset = 748;
	
	  ;% GUI_User_V1_3_P.Setup2_P2_Size
	  section.data(427).logicalSrcIdx = 438;
	  section.data(427).dtTransOffset = 749;
	
	  ;% GUI_User_V1_3_P.Setup2_P2
	  section.data(428).logicalSrcIdx = 439;
	  section.data(428).dtTransOffset = 751;
	
	  ;% GUI_User_V1_3_P.Setup2_P3_Size
	  section.data(429).logicalSrcIdx = 440;
	  section.data(429).dtTransOffset = 752;
	
	  ;% GUI_User_V1_3_P.Setup2_P3
	  section.data(430).logicalSrcIdx = 441;
	  section.data(430).dtTransOffset = 754;
	
	  ;% GUI_User_V1_3_P.Setup2_P4_Size
	  section.data(431).logicalSrcIdx = 442;
	  section.data(431).dtTransOffset = 755;
	
	  ;% GUI_User_V1_3_P.Setup2_P4
	  section.data(432).logicalSrcIdx = 443;
	  section.data(432).dtTransOffset = 757;
	
	  ;% GUI_User_V1_3_P.Setup2_P5_Size
	  section.data(433).logicalSrcIdx = 444;
	  section.data(433).dtTransOffset = 758;
	
	  ;% GUI_User_V1_3_P.Setup2_P5
	  section.data(434).logicalSrcIdx = 445;
	  section.data(434).dtTransOffset = 760;
	
	  ;% GUI_User_V1_3_P.Setup2_P6_Size
	  section.data(435).logicalSrcIdx = 446;
	  section.data(435).dtTransOffset = 761;
	
	  ;% GUI_User_V1_3_P.Setup2_P6
	  section.data(436).logicalSrcIdx = 447;
	  section.data(436).dtTransOffset = 763;
	
	  ;% GUI_User_V1_3_P.Setup2_P7_Size
	  section.data(437).logicalSrcIdx = 448;
	  section.data(437).dtTransOffset = 764;
	
	  ;% GUI_User_V1_3_P.Setup2_P7
	  section.data(438).logicalSrcIdx = 449;
	  section.data(438).dtTransOffset = 766;
	
	  ;% GUI_User_V1_3_P.Setup2_P8_Size
	  section.data(439).logicalSrcIdx = 450;
	  section.data(439).dtTransOffset = 767;
	
	  ;% GUI_User_V1_3_P.Setup2_P8
	  section.data(440).logicalSrcIdx = 451;
	  section.data(440).dtTransOffset = 769;
	
	  ;% GUI_User_V1_3_P.Gain2_Gain
	  section.data(441).logicalSrcIdx = 452;
	  section.data(441).dtTransOffset = 770;
	
	  ;% GUI_User_V1_3_P.Gain3_Gain_m
	  section.data(442).logicalSrcIdx = 453;
	  section.data(442).dtTransOffset = 771;
	
	  ;% GUI_User_V1_3_P.Gain4_Gain_n
	  section.data(443).logicalSrcIdx = 454;
	  section.data(443).dtTransOffset = 772;
	
	  ;% GUI_User_V1_3_P.Gain5_Gain_d
	  section.data(444).logicalSrcIdx = 455;
	  section.data(444).dtTransOffset = 773;
	
	  ;% GUI_User_V1_3_P.Gain6_Gain_b
	  section.data(445).logicalSrcIdx = 456;
	  section.data(445).dtTransOffset = 774;
	
	  ;% GUI_User_V1_3_P.Gain7_Gain_m
	  section.data(446).logicalSrcIdx = 457;
	  section.data(446).dtTransOffset = 775;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.Constant_Value_a
	  section.data(1).logicalSrcIdx = 458;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_P.Constant1_Value_k
	  section.data(2).logicalSrcIdx = 459;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GUI_User_V1_3_P.Constant_Value_i
	  section.data(3).logicalSrcIdx = 460;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GUI_User_V1_3_P.Constant2_Value_h
	  section.data(4).logicalSrcIdx = 461;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.IfActionSubsystem11.Constant8_Value
	  section.data(1).logicalSrcIdx = 462;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_P.IfActionSubsystem11.Gain_Gain
	  section.data(2).logicalSrcIdx = 463;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.IfActionSubsystem10.Constant8_Value
	  section.data(1).logicalSrcIdx = 464;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.IfActionSubsystem9.Constant8_Value
	  section.data(1).logicalSrcIdx = 465;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_P.IfActionSubsystem9.Gain_Gain
	  section.data(2).logicalSrcIdx = 466;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.IfActionSubsystem8.Constant8_Value
	  section.data(1).logicalSrcIdx = 467;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.IfActionSubsystem7.Constant8_Value
	  section.data(1).logicalSrcIdx = 468;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_P.IfActionSubsystem7.Gain_Gain
	  section.data(2).logicalSrcIdx = 469;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.IfActionSubsystem6_a.Constant8_Value
	  section.data(1).logicalSrcIdx = 470;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.IfActionSubsystem5_i.Constant8_Value
	  section.data(1).logicalSrcIdx = 471;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_P.IfActionSubsystem5_i.Gain_Gain
	  section.data(2).logicalSrcIdx = 472;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.IfActionSubsystem4.Constant8_Value
	  section.data(1).logicalSrcIdx = 473;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.IfActionSubsystem3.Constant8_Value
	  section.data(1).logicalSrcIdx = 474;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_P.IfActionSubsystem3.Gain_Gain
	  section.data(2).logicalSrcIdx = 475;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.IfActionSubsystem2_c.Constant8_Value
	  section.data(1).logicalSrcIdx = 476;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.IfActionSubsystem1.Constant8_Value
	  section.data(1).logicalSrcIdx = 477;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_P.IfActionSubsystem1.Gain_Gain
	  section.data(2).logicalSrcIdx = 478;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_P.IfActionSubsystem_h.Constant8_Value
	  section.data(1).logicalSrcIdx = 479;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
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
    nTotSects     = 18;
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
    ;% Auto data (GUI_User_V1_3_B)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.FIFOwrite1_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_B.FIFOwrite2_o1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GUI_User_V1_3_B.RateTransition
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GUI_User_V1_3_B.RateTransition2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GUI_User_V1_3_B.RateTransition1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GUI_User_V1_3_B.RateTransition3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GUI_User_V1_3_B.FIFOwrite2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GUI_User_V1_3_B.FIFOwrite1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 257;
      section.data(257)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.MM16ATAnalogInput_o1
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_B.MM16ATAnalogInput_o2
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GUI_User_V1_3_B.MM16ATAnalogInput_o3
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GUI_User_V1_3_B.MM16ATAnalogInput_o4
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GUI_User_V1_3_B.MM16ATAnalogInput_o5
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GUI_User_V1_3_B.MM16ATAnalogInput_o6
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GUI_User_V1_3_B.MM16ATAnalogInput_o7
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GUI_User_V1_3_B.MM16ATAnalogInput_o8
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% GUI_User_V1_3_B.MM16ATAnalogInput_o9
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 8;
	
	  ;% GUI_User_V1_3_B.MM16ATAnalogInput_o10
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 9;
	
	  ;% GUI_User_V1_3_B.MM16ATAnalogInput_o11
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 10;
	
	  ;% GUI_User_V1_3_B.MM16ATAnalogInput_o12
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 11;
	
	  ;% GUI_User_V1_3_B.DiscreteStateSpace5
	  section.data(13).logicalSrcIdx = 20;
	  section.data(13).dtTransOffset = 12;
	
	  ;% GUI_User_V1_3_B.Gain11
	  section.data(14).logicalSrcIdx = 21;
	  section.data(14).dtTransOffset = 13;
	
	  ;% GUI_User_V1_3_B.Sum6
	  section.data(15).logicalSrcIdx = 22;
	  section.data(15).dtTransOffset = 14;
	
	  ;% GUI_User_V1_3_B.DiscreteStateSpace4
	  section.data(16).logicalSrcIdx = 23;
	  section.data(16).dtTransOffset = 15;
	
	  ;% GUI_User_V1_3_B.Gain10
	  section.data(17).logicalSrcIdx = 24;
	  section.data(17).dtTransOffset = 16;
	
	  ;% GUI_User_V1_3_B.Sum5
	  section.data(18).logicalSrcIdx = 25;
	  section.data(18).dtTransOffset = 17;
	
	  ;% GUI_User_V1_3_B.DiscreteStateSpace3
	  section.data(19).logicalSrcIdx = 26;
	  section.data(19).dtTransOffset = 18;
	
	  ;% GUI_User_V1_3_B.Gain9
	  section.data(20).logicalSrcIdx = 27;
	  section.data(20).dtTransOffset = 19;
	
	  ;% GUI_User_V1_3_B.Sum4
	  section.data(21).logicalSrcIdx = 28;
	  section.data(21).dtTransOffset = 20;
	
	  ;% GUI_User_V1_3_B.DiscreteStateSpace2
	  section.data(22).logicalSrcIdx = 29;
	  section.data(22).dtTransOffset = 21;
	
	  ;% GUI_User_V1_3_B.Gain8
	  section.data(23).logicalSrcIdx = 30;
	  section.data(23).dtTransOffset = 22;
	
	  ;% GUI_User_V1_3_B.Sum3
	  section.data(24).logicalSrcIdx = 31;
	  section.data(24).dtTransOffset = 23;
	
	  ;% GUI_User_V1_3_B.DiscreteStateSpace1
	  section.data(25).logicalSrcIdx = 32;
	  section.data(25).dtTransOffset = 24;
	
	  ;% GUI_User_V1_3_B.Gain1
	  section.data(26).logicalSrcIdx = 33;
	  section.data(26).dtTransOffset = 25;
	
	  ;% GUI_User_V1_3_B.Sum2
	  section.data(27).logicalSrcIdx = 34;
	  section.data(27).dtTransOffset = 26;
	
	  ;% GUI_User_V1_3_B.DiscreteStateSpace6
	  section.data(28).logicalSrcIdx = 35;
	  section.data(28).dtTransOffset = 27;
	
	  ;% GUI_User_V1_3_B.Gain
	  section.data(29).logicalSrcIdx = 36;
	  section.data(29).dtTransOffset = 28;
	
	  ;% GUI_User_V1_3_B.Sum1
	  section.data(30).logicalSrcIdx = 37;
	  section.data(30).dtTransOffset = 29;
	
	  ;% GUI_User_V1_3_B.Merge
	  section.data(31).logicalSrcIdx = 38;
	  section.data(31).dtTransOffset = 30;
	
	  ;% GUI_User_V1_3_B.Saturation
	  section.data(32).logicalSrcIdx = 39;
	  section.data(32).dtTransOffset = 36;
	
	  ;% GUI_User_V1_3_B.Saturation1
	  section.data(33).logicalSrcIdx = 40;
	  section.data(33).dtTransOffset = 37;
	
	  ;% GUI_User_V1_3_B.Saturation2
	  section.data(34).logicalSrcIdx = 41;
	  section.data(34).dtTransOffset = 38;
	
	  ;% GUI_User_V1_3_B.Saturation3
	  section.data(35).logicalSrcIdx = 42;
	  section.data(35).dtTransOffset = 39;
	
	  ;% GUI_User_V1_3_B.Saturation4
	  section.data(36).logicalSrcIdx = 43;
	  section.data(36).dtTransOffset = 40;
	
	  ;% GUI_User_V1_3_B.Saturation5
	  section.data(37).logicalSrcIdx = 44;
	  section.data(37).dtTransOffset = 41;
	
	  ;% GUI_User_V1_3_B.Merge_l
	  section.data(38).logicalSrcIdx = 45;
	  section.data(38).dtTransOffset = 42;
	
	  ;% GUI_User_V1_3_B.Merge1
	  section.data(39).logicalSrcIdx = 46;
	  section.data(39).dtTransOffset = 43;
	
	  ;% GUI_User_V1_3_B.Merge2
	  section.data(40).logicalSrcIdx = 47;
	  section.data(40).dtTransOffset = 44;
	
	  ;% GUI_User_V1_3_B.Merge3
	  section.data(41).logicalSrcIdx = 48;
	  section.data(41).dtTransOffset = 45;
	
	  ;% GUI_User_V1_3_B.Merge4
	  section.data(42).logicalSrcIdx = 49;
	  section.data(42).dtTransOffset = 46;
	
	  ;% GUI_User_V1_3_B.Merge5
	  section.data(43).logicalSrcIdx = 50;
	  section.data(43).dtTransOffset = 47;
	
	  ;% GUI_User_V1_3_B.Gain2
	  section.data(44).logicalSrcIdx = 51;
	  section.data(44).dtTransOffset = 48;
	
	  ;% GUI_User_V1_3_B.Gain3
	  section.data(45).logicalSrcIdx = 52;
	  section.data(45).dtTransOffset = 49;
	
	  ;% GUI_User_V1_3_B.Gain4
	  section.data(46).logicalSrcIdx = 53;
	  section.data(46).dtTransOffset = 50;
	
	  ;% GUI_User_V1_3_B.Gain5
	  section.data(47).logicalSrcIdx = 54;
	  section.data(47).dtTransOffset = 51;
	
	  ;% GUI_User_V1_3_B.Gain6
	  section.data(48).logicalSrcIdx = 55;
	  section.data(48).dtTransOffset = 52;
	
	  ;% GUI_User_V1_3_B.Gain7
	  section.data(49).logicalSrcIdx = 56;
	  section.data(49).dtTransOffset = 53;
	
	  ;% GUI_User_V1_3_B.Unpack1
	  section.data(50).logicalSrcIdx = 57;
	  section.data(50).dtTransOffset = 54;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain1
	  section.data(51).logicalSrcIdx = 58;
	  section.data(51).dtTransOffset = 72;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain10
	  section.data(52).logicalSrcIdx = 59;
	  section.data(52).dtTransOffset = 73;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain11
	  section.data(53).logicalSrcIdx = 60;
	  section.data(53).dtTransOffset = 74;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain12
	  section.data(54).logicalSrcIdx = 61;
	  section.data(54).dtTransOffset = 75;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain2
	  section.data(55).logicalSrcIdx = 62;
	  section.data(55).dtTransOffset = 76;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain3
	  section.data(56).logicalSrcIdx = 63;
	  section.data(56).dtTransOffset = 77;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain4
	  section.data(57).logicalSrcIdx = 64;
	  section.data(57).dtTransOffset = 78;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain5
	  section.data(58).logicalSrcIdx = 65;
	  section.data(58).dtTransOffset = 79;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain6
	  section.data(59).logicalSrcIdx = 66;
	  section.data(59).dtTransOffset = 80;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain7
	  section.data(60).logicalSrcIdx = 67;
	  section.data(60).dtTransOffset = 81;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain8
	  section.data(61).logicalSrcIdx = 68;
	  section.data(61).dtTransOffset = 82;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain9
	  section.data(62).logicalSrcIdx = 69;
	  section.data(62).dtTransOffset = 83;
	
	  ;% GUI_User_V1_3_B.Sum6_c
	  section.data(63).logicalSrcIdx = 70;
	  section.data(63).dtTransOffset = 84;
	
	  ;% GUI_User_V1_3_B.Sum3_o
	  section.data(64).logicalSrcIdx = 71;
	  section.data(64).dtTransOffset = 85;
	
	  ;% GUI_User_V1_3_B.ProportionalGain
	  section.data(65).logicalSrcIdx = 72;
	  section.data(65).dtTransOffset = 86;
	
	  ;% GUI_User_V1_3_B.Integrator
	  section.data(66).logicalSrcIdx = 73;
	  section.data(66).dtTransOffset = 87;
	
	  ;% GUI_User_V1_3_B.DerivativeGain
	  section.data(67).logicalSrcIdx = 74;
	  section.data(67).dtTransOffset = 88;
	
	  ;% GUI_User_V1_3_B.Filter
	  section.data(68).logicalSrcIdx = 75;
	  section.data(68).dtTransOffset = 89;
	
	  ;% GUI_User_V1_3_B.SumD
	  section.data(69).logicalSrcIdx = 76;
	  section.data(69).dtTransOffset = 90;
	
	  ;% GUI_User_V1_3_B.FilterCoefficient
	  section.data(70).logicalSrcIdx = 77;
	  section.data(70).dtTransOffset = 91;
	
	  ;% GUI_User_V1_3_B.Sum
	  section.data(71).logicalSrcIdx = 78;
	  section.data(71).dtTransOffset = 92;
	
	  ;% GUI_User_V1_3_B.Sum5_h
	  section.data(72).logicalSrcIdx = 79;
	  section.data(72).dtTransOffset = 93;
	
	  ;% GUI_User_V1_3_B.Sum4_o
	  section.data(73).logicalSrcIdx = 80;
	  section.data(73).dtTransOffset = 94;
	
	  ;% GUI_User_V1_3_B.Sum1_k
	  section.data(74).logicalSrcIdx = 81;
	  section.data(74).dtTransOffset = 95;
	
	  ;% GUI_User_V1_3_B.ProportionalGain_c
	  section.data(75).logicalSrcIdx = 82;
	  section.data(75).dtTransOffset = 96;
	
	  ;% GUI_User_V1_3_B.Integrator_i
	  section.data(76).logicalSrcIdx = 83;
	  section.data(76).dtTransOffset = 97;
	
	  ;% GUI_User_V1_3_B.DerivativeGain_a
	  section.data(77).logicalSrcIdx = 84;
	  section.data(77).dtTransOffset = 98;
	
	  ;% GUI_User_V1_3_B.Filter_j
	  section.data(78).logicalSrcIdx = 85;
	  section.data(78).dtTransOffset = 99;
	
	  ;% GUI_User_V1_3_B.SumD_h
	  section.data(79).logicalSrcIdx = 86;
	  section.data(79).dtTransOffset = 100;
	
	  ;% GUI_User_V1_3_B.FilterCoefficient_n
	  section.data(80).logicalSrcIdx = 87;
	  section.data(80).dtTransOffset = 101;
	
	  ;% GUI_User_V1_3_B.Sum_g
	  section.data(81).logicalSrcIdx = 88;
	  section.data(81).dtTransOffset = 102;
	
	  ;% GUI_User_V1_3_B.Sum2_i
	  section.data(82).logicalSrcIdx = 89;
	  section.data(82).dtTransOffset = 103;
	
	  ;% GUI_User_V1_3_B.Sum12
	  section.data(83).logicalSrcIdx = 90;
	  section.data(83).dtTransOffset = 104;
	
	  ;% GUI_User_V1_3_B.Sum10
	  section.data(84).logicalSrcIdx = 91;
	  section.data(84).dtTransOffset = 105;
	
	  ;% GUI_User_V1_3_B.ProportionalGain_g
	  section.data(85).logicalSrcIdx = 92;
	  section.data(85).dtTransOffset = 106;
	
	  ;% GUI_User_V1_3_B.Integrator_p
	  section.data(86).logicalSrcIdx = 93;
	  section.data(86).dtTransOffset = 107;
	
	  ;% GUI_User_V1_3_B.DerivativeGain_p
	  section.data(87).logicalSrcIdx = 94;
	  section.data(87).dtTransOffset = 108;
	
	  ;% GUI_User_V1_3_B.Filter_n
	  section.data(88).logicalSrcIdx = 95;
	  section.data(88).dtTransOffset = 109;
	
	  ;% GUI_User_V1_3_B.SumD_n
	  section.data(89).logicalSrcIdx = 96;
	  section.data(89).dtTransOffset = 110;
	
	  ;% GUI_User_V1_3_B.FilterCoefficient_j
	  section.data(90).logicalSrcIdx = 97;
	  section.data(90).dtTransOffset = 111;
	
	  ;% GUI_User_V1_3_B.Sum_p
	  section.data(91).logicalSrcIdx = 98;
	  section.data(91).dtTransOffset = 112;
	
	  ;% GUI_User_V1_3_B.Sum11
	  section.data(92).logicalSrcIdx = 99;
	  section.data(92).dtTransOffset = 113;
	
	  ;% GUI_User_V1_3_B.Sum15
	  section.data(93).logicalSrcIdx = 100;
	  section.data(93).dtTransOffset = 114;
	
	  ;% GUI_User_V1_3_B.Sum13
	  section.data(94).logicalSrcIdx = 101;
	  section.data(94).dtTransOffset = 115;
	
	  ;% GUI_User_V1_3_B.ProportionalGain_m
	  section.data(95).logicalSrcIdx = 102;
	  section.data(95).dtTransOffset = 116;
	
	  ;% GUI_User_V1_3_B.Integrator_g
	  section.data(96).logicalSrcIdx = 103;
	  section.data(96).dtTransOffset = 117;
	
	  ;% GUI_User_V1_3_B.DerivativeGain_n
	  section.data(97).logicalSrcIdx = 104;
	  section.data(97).dtTransOffset = 118;
	
	  ;% GUI_User_V1_3_B.Filter_e
	  section.data(98).logicalSrcIdx = 105;
	  section.data(98).dtTransOffset = 119;
	
	  ;% GUI_User_V1_3_B.SumD_m
	  section.data(99).logicalSrcIdx = 106;
	  section.data(99).dtTransOffset = 120;
	
	  ;% GUI_User_V1_3_B.FilterCoefficient_o
	  section.data(100).logicalSrcIdx = 107;
	  section.data(100).dtTransOffset = 121;
	
	  ;% GUI_User_V1_3_B.Sum_h
	  section.data(101).logicalSrcIdx = 108;
	  section.data(101).dtTransOffset = 122;
	
	  ;% GUI_User_V1_3_B.Sum14
	  section.data(102).logicalSrcIdx = 109;
	  section.data(102).dtTransOffset = 123;
	
	  ;% GUI_User_V1_3_B.Sum18
	  section.data(103).logicalSrcIdx = 110;
	  section.data(103).dtTransOffset = 124;
	
	  ;% GUI_User_V1_3_B.Sum16
	  section.data(104).logicalSrcIdx = 111;
	  section.data(104).dtTransOffset = 125;
	
	  ;% GUI_User_V1_3_B.ProportionalGain_e
	  section.data(105).logicalSrcIdx = 112;
	  section.data(105).dtTransOffset = 126;
	
	  ;% GUI_User_V1_3_B.Integrator_gs
	  section.data(106).logicalSrcIdx = 113;
	  section.data(106).dtTransOffset = 127;
	
	  ;% GUI_User_V1_3_B.DerivativeGain_h
	  section.data(107).logicalSrcIdx = 114;
	  section.data(107).dtTransOffset = 128;
	
	  ;% GUI_User_V1_3_B.Filter_i
	  section.data(108).logicalSrcIdx = 115;
	  section.data(108).dtTransOffset = 129;
	
	  ;% GUI_User_V1_3_B.SumD_f
	  section.data(109).logicalSrcIdx = 116;
	  section.data(109).dtTransOffset = 130;
	
	  ;% GUI_User_V1_3_B.FilterCoefficient_m
	  section.data(110).logicalSrcIdx = 117;
	  section.data(110).dtTransOffset = 131;
	
	  ;% GUI_User_V1_3_B.Sum_i
	  section.data(111).logicalSrcIdx = 118;
	  section.data(111).dtTransOffset = 132;
	
	  ;% GUI_User_V1_3_B.Sum17
	  section.data(112).logicalSrcIdx = 119;
	  section.data(112).dtTransOffset = 133;
	
	  ;% GUI_User_V1_3_B.Sum9
	  section.data(113).logicalSrcIdx = 120;
	  section.data(113).dtTransOffset = 134;
	
	  ;% GUI_User_V1_3_B.Gain7_m
	  section.data(114).logicalSrcIdx = 121;
	  section.data(114).dtTransOffset = 135;
	
	  ;% GUI_User_V1_3_B.Sum7
	  section.data(115).logicalSrcIdx = 122;
	  section.data(115).dtTransOffset = 136;
	
	  ;% GUI_User_V1_3_B.ProportionalGain_k
	  section.data(116).logicalSrcIdx = 123;
	  section.data(116).dtTransOffset = 137;
	
	  ;% GUI_User_V1_3_B.Integrator_m
	  section.data(117).logicalSrcIdx = 124;
	  section.data(117).dtTransOffset = 138;
	
	  ;% GUI_User_V1_3_B.DerivativeGain_ap
	  section.data(118).logicalSrcIdx = 125;
	  section.data(118).dtTransOffset = 139;
	
	  ;% GUI_User_V1_3_B.Filter_b
	  section.data(119).logicalSrcIdx = 126;
	  section.data(119).dtTransOffset = 140;
	
	  ;% GUI_User_V1_3_B.SumD_fc
	  section.data(120).logicalSrcIdx = 127;
	  section.data(120).dtTransOffset = 141;
	
	  ;% GUI_User_V1_3_B.FilterCoefficient_h
	  section.data(121).logicalSrcIdx = 128;
	  section.data(121).dtTransOffset = 142;
	
	  ;% GUI_User_V1_3_B.Sum_f
	  section.data(122).logicalSrcIdx = 129;
	  section.data(122).dtTransOffset = 143;
	
	  ;% GUI_User_V1_3_B.Gain8_p
	  section.data(123).logicalSrcIdx = 130;
	  section.data(123).dtTransOffset = 144;
	
	  ;% GUI_User_V1_3_B.IntegralGain
	  section.data(124).logicalSrcIdx = 131;
	  section.data(124).dtTransOffset = 145;
	
	  ;% GUI_User_V1_3_B.IntegralGain_e
	  section.data(125).logicalSrcIdx = 132;
	  section.data(125).dtTransOffset = 146;
	
	  ;% GUI_User_V1_3_B.IntegralGain_p
	  section.data(126).logicalSrcIdx = 133;
	  section.data(126).dtTransOffset = 147;
	
	  ;% GUI_User_V1_3_B.IntegralGain_k
	  section.data(127).logicalSrcIdx = 134;
	  section.data(127).dtTransOffset = 148;
	
	  ;% GUI_User_V1_3_B.IntegralGain_k4
	  section.data(128).logicalSrcIdx = 135;
	  section.data(128).dtTransOffset = 149;
	
	  ;% GUI_User_V1_3_B.IntegralGain_b
	  section.data(129).logicalSrcIdx = 136;
	  section.data(129).dtTransOffset = 150;
	
	  ;% GUI_User_V1_3_B.DiscreteZeroPole1
	  section.data(130).logicalSrcIdx = 137;
	  section.data(130).dtTransOffset = 151;
	
	  ;% GUI_User_V1_3_B.DiscreteZeroPole2
	  section.data(131).logicalSrcIdx = 138;
	  section.data(131).dtTransOffset = 152;
	
	  ;% GUI_User_V1_3_B.DiscreteZeroPole3
	  section.data(132).logicalSrcIdx = 139;
	  section.data(132).dtTransOffset = 153;
	
	  ;% GUI_User_V1_3_B.DiscreteZeroPole4
	  section.data(133).logicalSrcIdx = 140;
	  section.data(133).dtTransOffset = 154;
	
	  ;% GUI_User_V1_3_B.DiscreteZeroPole5
	  section.data(134).logicalSrcIdx = 141;
	  section.data(134).dtTransOffset = 155;
	
	  ;% GUI_User_V1_3_B.DiscreteZeroPole6
	  section.data(135).logicalSrcIdx = 142;
	  section.data(135).dtTransOffset = 156;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain1_m
	  section.data(136).logicalSrcIdx = 143;
	  section.data(136).dtTransOffset = 157;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain10_l
	  section.data(137).logicalSrcIdx = 144;
	  section.data(137).dtTransOffset = 158;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain11_l
	  section.data(138).logicalSrcIdx = 145;
	  section.data(138).dtTransOffset = 159;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain12_g
	  section.data(139).logicalSrcIdx = 146;
	  section.data(139).dtTransOffset = 160;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain2_c
	  section.data(140).logicalSrcIdx = 147;
	  section.data(140).dtTransOffset = 161;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain3_n
	  section.data(141).logicalSrcIdx = 148;
	  section.data(141).dtTransOffset = 162;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain4_i
	  section.data(142).logicalSrcIdx = 149;
	  section.data(142).dtTransOffset = 163;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain5_a
	  section.data(143).logicalSrcIdx = 150;
	  section.data(143).dtTransOffset = 164;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain6_b
	  section.data(144).logicalSrcIdx = 151;
	  section.data(144).dtTransOffset = 165;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain7_c
	  section.data(145).logicalSrcIdx = 152;
	  section.data(145).dtTransOffset = 166;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain8_o
	  section.data(146).logicalSrcIdx = 153;
	  section.data(146).dtTransOffset = 167;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain9_k
	  section.data(147).logicalSrcIdx = 154;
	  section.data(147).dtTransOffset = 168;
	
	  ;% GUI_User_V1_3_B.Sum6_d
	  section.data(148).logicalSrcIdx = 155;
	  section.data(148).dtTransOffset = 169;
	
	  ;% GUI_User_V1_3_B.Sum5_l
	  section.data(149).logicalSrcIdx = 156;
	  section.data(149).dtTransOffset = 170;
	
	  ;% GUI_User_V1_3_B.Gain1_p
	  section.data(150).logicalSrcIdx = 157;
	  section.data(150).dtTransOffset = 171;
	
	  ;% GUI_User_V1_3_B.Sum4_c
	  section.data(151).logicalSrcIdx = 158;
	  section.data(151).dtTransOffset = 172;
	
	  ;% GUI_User_V1_3_B.Sum2_im
	  section.data(152).logicalSrcIdx = 159;
	  section.data(152).dtTransOffset = 173;
	
	  ;% GUI_User_V1_3_B.Gain3_k
	  section.data(153).logicalSrcIdx = 160;
	  section.data(153).dtTransOffset = 174;
	
	  ;% GUI_User_V1_3_B.Sum12_d
	  section.data(154).logicalSrcIdx = 161;
	  section.data(154).dtTransOffset = 175;
	
	  ;% GUI_User_V1_3_B.Sum11_f
	  section.data(155).logicalSrcIdx = 162;
	  section.data(155).dtTransOffset = 176;
	
	  ;% GUI_User_V1_3_B.Gain4_g
	  section.data(156).logicalSrcIdx = 163;
	  section.data(156).dtTransOffset = 177;
	
	  ;% GUI_User_V1_3_B.Sum15_f
	  section.data(157).logicalSrcIdx = 164;
	  section.data(157).dtTransOffset = 178;
	
	  ;% GUI_User_V1_3_B.Sum14_i
	  section.data(158).logicalSrcIdx = 165;
	  section.data(158).dtTransOffset = 179;
	
	  ;% GUI_User_V1_3_B.Gain5_o
	  section.data(159).logicalSrcIdx = 166;
	  section.data(159).dtTransOffset = 180;
	
	  ;% GUI_User_V1_3_B.Sum18_c
	  section.data(160).logicalSrcIdx = 167;
	  section.data(160).dtTransOffset = 181;
	
	  ;% GUI_User_V1_3_B.Sum17_b
	  section.data(161).logicalSrcIdx = 168;
	  section.data(161).dtTransOffset = 182;
	
	  ;% GUI_User_V1_3_B.Gain6_h
	  section.data(162).logicalSrcIdx = 169;
	  section.data(162).dtTransOffset = 183;
	
	  ;% GUI_User_V1_3_B.Sum9_l
	  section.data(163).logicalSrcIdx = 170;
	  section.data(163).dtTransOffset = 184;
	
	  ;% GUI_User_V1_3_B.Gain7_j
	  section.data(164).logicalSrcIdx = 171;
	  section.data(164).dtTransOffset = 185;
	
	  ;% GUI_User_V1_3_B.Gain8_f
	  section.data(165).logicalSrcIdx = 172;
	  section.data(165).dtTransOffset = 186;
	
	  ;% GUI_User_V1_3_B.Sum1_e
	  section.data(166).logicalSrcIdx = 173;
	  section.data(166).dtTransOffset = 187;
	
	  ;% GUI_User_V1_3_B.Sum10_l
	  section.data(167).logicalSrcIdx = 174;
	  section.data(167).dtTransOffset = 188;
	
	  ;% GUI_User_V1_3_B.Sum13_d
	  section.data(168).logicalSrcIdx = 175;
	  section.data(168).dtTransOffset = 189;
	
	  ;% GUI_User_V1_3_B.Sum16_i
	  section.data(169).logicalSrcIdx = 176;
	  section.data(169).dtTransOffset = 190;
	
	  ;% GUI_User_V1_3_B.Sum3_l
	  section.data(170).logicalSrcIdx = 177;
	  section.data(170).dtTransOffset = 191;
	
	  ;% GUI_User_V1_3_B.Sum7_i
	  section.data(171).logicalSrcIdx = 178;
	  section.data(171).dtTransOffset = 192;
	
	  ;% GUI_User_V1_3_B.Sum8
	  section.data(172).logicalSrcIdx = 179;
	  section.data(172).dtTransOffset = 193;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain5_n
	  section.data(173).logicalSrcIdx = 180;
	  section.data(173).dtTransOffset = 194;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain6_h
	  section.data(174).logicalSrcIdx = 181;
	  section.data(174).dtTransOffset = 195;
	
	  ;% GUI_User_V1_3_B.Sum9_lk
	  section.data(175).logicalSrcIdx = 182;
	  section.data(175).dtTransOffset = 196;
	
	  ;% GUI_User_V1_3_B.Gain7_e
	  section.data(176).logicalSrcIdx = 183;
	  section.data(176).dtTransOffset = 197;
	
	  ;% GUI_User_V1_3_B.Sum7_m
	  section.data(177).logicalSrcIdx = 184;
	  section.data(177).dtTransOffset = 198;
	
	  ;% GUI_User_V1_3_B.ProportionalGain_d
	  section.data(178).logicalSrcIdx = 185;
	  section.data(178).dtTransOffset = 199;
	
	  ;% GUI_User_V1_3_B.Integrator_l
	  section.data(179).logicalSrcIdx = 186;
	  section.data(179).dtTransOffset = 200;
	
	  ;% GUI_User_V1_3_B.DerivativeGain_k
	  section.data(180).logicalSrcIdx = 187;
	  section.data(180).dtTransOffset = 201;
	
	  ;% GUI_User_V1_3_B.Filter_p
	  section.data(181).logicalSrcIdx = 188;
	  section.data(181).dtTransOffset = 202;
	
	  ;% GUI_User_V1_3_B.SumD_k
	  section.data(182).logicalSrcIdx = 189;
	  section.data(182).dtTransOffset = 203;
	
	  ;% GUI_User_V1_3_B.FilterCoefficient_i
	  section.data(183).logicalSrcIdx = 190;
	  section.data(183).dtTransOffset = 204;
	
	  ;% GUI_User_V1_3_B.Sum_fe
	  section.data(184).logicalSrcIdx = 191;
	  section.data(184).dtTransOffset = 205;
	
	  ;% GUI_User_V1_3_B.Gain8_ff
	  section.data(185).logicalSrcIdx = 192;
	  section.data(185).dtTransOffset = 206;
	
	  ;% GUI_User_V1_3_B.IntegralGain_c
	  section.data(186).logicalSrcIdx = 193;
	  section.data(186).dtTransOffset = 207;
	
	  ;% GUI_User_V1_3_B.Sum8_h
	  section.data(187).logicalSrcIdx = 194;
	  section.data(187).dtTransOffset = 208;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain3_m
	  section.data(188).logicalSrcIdx = 195;
	  section.data(188).dtTransOffset = 209;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain4_d
	  section.data(189).logicalSrcIdx = 196;
	  section.data(189).dtTransOffset = 210;
	
	  ;% GUI_User_V1_3_B.Sum6_o
	  section.data(190).logicalSrcIdx = 197;
	  section.data(190).dtTransOffset = 211;
	
	  ;% GUI_User_V1_3_B.Sum3_oz
	  section.data(191).logicalSrcIdx = 198;
	  section.data(191).dtTransOffset = 212;
	
	  ;% GUI_User_V1_3_B.ProportionalGain_o
	  section.data(192).logicalSrcIdx = 199;
	  section.data(192).dtTransOffset = 213;
	
	  ;% GUI_User_V1_3_B.Integrator_iz
	  section.data(193).logicalSrcIdx = 200;
	  section.data(193).dtTransOffset = 214;
	
	  ;% GUI_User_V1_3_B.DerivativeGain_l
	  section.data(194).logicalSrcIdx = 201;
	  section.data(194).dtTransOffset = 215;
	
	  ;% GUI_User_V1_3_B.Filter_h
	  section.data(195).logicalSrcIdx = 202;
	  section.data(195).dtTransOffset = 216;
	
	  ;% GUI_User_V1_3_B.SumD_o
	  section.data(196).logicalSrcIdx = 203;
	  section.data(196).dtTransOffset = 217;
	
	  ;% GUI_User_V1_3_B.FilterCoefficient_jw
	  section.data(197).logicalSrcIdx = 204;
	  section.data(197).dtTransOffset = 218;
	
	  ;% GUI_User_V1_3_B.Sum_m
	  section.data(198).logicalSrcIdx = 205;
	  section.data(198).dtTransOffset = 219;
	
	  ;% GUI_User_V1_3_B.Sum5_h2
	  section.data(199).logicalSrcIdx = 206;
	  section.data(199).dtTransOffset = 220;
	
	  ;% GUI_User_V1_3_B.Gain1_e
	  section.data(200).logicalSrcIdx = 207;
	  section.data(200).dtTransOffset = 221;
	
	  ;% GUI_User_V1_3_B.IntegralGain_o
	  section.data(201).logicalSrcIdx = 208;
	  section.data(201).dtTransOffset = 222;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain1_j
	  section.data(202).logicalSrcIdx = 209;
	  section.data(202).dtTransOffset = 223;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain2_a
	  section.data(203).logicalSrcIdx = 210;
	  section.data(203).dtTransOffset = 224;
	
	  ;% GUI_User_V1_3_B.Sum4_cm
	  section.data(204).logicalSrcIdx = 211;
	  section.data(204).dtTransOffset = 225;
	
	  ;% GUI_User_V1_3_B.Sum1_n
	  section.data(205).logicalSrcIdx = 212;
	  section.data(205).dtTransOffset = 226;
	
	  ;% GUI_User_V1_3_B.ProportionalGain_ku
	  section.data(206).logicalSrcIdx = 213;
	  section.data(206).dtTransOffset = 227;
	
	  ;% GUI_User_V1_3_B.Integrator_h
	  section.data(207).logicalSrcIdx = 214;
	  section.data(207).dtTransOffset = 228;
	
	  ;% GUI_User_V1_3_B.DerivativeGain_kl
	  section.data(208).logicalSrcIdx = 215;
	  section.data(208).dtTransOffset = 229;
	
	  ;% GUI_User_V1_3_B.Filter_f
	  section.data(209).logicalSrcIdx = 216;
	  section.data(209).dtTransOffset = 230;
	
	  ;% GUI_User_V1_3_B.SumD_fx
	  section.data(210).logicalSrcIdx = 217;
	  section.data(210).dtTransOffset = 231;
	
	  ;% GUI_User_V1_3_B.FilterCoefficient_a
	  section.data(211).logicalSrcIdx = 218;
	  section.data(211).dtTransOffset = 232;
	
	  ;% GUI_User_V1_3_B.Sum_n
	  section.data(212).logicalSrcIdx = 219;
	  section.data(212).dtTransOffset = 233;
	
	  ;% GUI_User_V1_3_B.Sum2_f
	  section.data(213).logicalSrcIdx = 220;
	  section.data(213).dtTransOffset = 234;
	
	  ;% GUI_User_V1_3_B.Gain3_m
	  section.data(214).logicalSrcIdx = 221;
	  section.data(214).dtTransOffset = 235;
	
	  ;% GUI_User_V1_3_B.IntegralGain_ko
	  section.data(215).logicalSrcIdx = 222;
	  section.data(215).dtTransOffset = 236;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain7_n
	  section.data(216).logicalSrcIdx = 223;
	  section.data(216).dtTransOffset = 237;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain8_d
	  section.data(217).logicalSrcIdx = 224;
	  section.data(217).dtTransOffset = 238;
	
	  ;% GUI_User_V1_3_B.Sum12_j
	  section.data(218).logicalSrcIdx = 225;
	  section.data(218).dtTransOffset = 239;
	
	  ;% GUI_User_V1_3_B.Sum10_i
	  section.data(219).logicalSrcIdx = 226;
	  section.data(219).dtTransOffset = 240;
	
	  ;% GUI_User_V1_3_B.ProportionalGain_mk
	  section.data(220).logicalSrcIdx = 227;
	  section.data(220).dtTransOffset = 241;
	
	  ;% GUI_User_V1_3_B.Integrator_d
	  section.data(221).logicalSrcIdx = 228;
	  section.data(221).dtTransOffset = 242;
	
	  ;% GUI_User_V1_3_B.DerivativeGain_e
	  section.data(222).logicalSrcIdx = 229;
	  section.data(222).dtTransOffset = 243;
	
	  ;% GUI_User_V1_3_B.Filter_fz
	  section.data(223).logicalSrcIdx = 230;
	  section.data(223).dtTransOffset = 244;
	
	  ;% GUI_User_V1_3_B.SumD_d
	  section.data(224).logicalSrcIdx = 231;
	  section.data(224).dtTransOffset = 245;
	
	  ;% GUI_User_V1_3_B.FilterCoefficient_f
	  section.data(225).logicalSrcIdx = 232;
	  section.data(225).dtTransOffset = 246;
	
	  ;% GUI_User_V1_3_B.Sum_pc
	  section.data(226).logicalSrcIdx = 233;
	  section.data(226).dtTransOffset = 247;
	
	  ;% GUI_User_V1_3_B.Sum11_i
	  section.data(227).logicalSrcIdx = 234;
	  section.data(227).dtTransOffset = 248;
	
	  ;% GUI_User_V1_3_B.Gain4_h
	  section.data(228).logicalSrcIdx = 235;
	  section.data(228).dtTransOffset = 249;
	
	  ;% GUI_User_V1_3_B.IntegralGain_g
	  section.data(229).logicalSrcIdx = 236;
	  section.data(229).dtTransOffset = 250;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain10_l0
	  section.data(230).logicalSrcIdx = 237;
	  section.data(230).dtTransOffset = 251;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain9_a
	  section.data(231).logicalSrcIdx = 238;
	  section.data(231).dtTransOffset = 252;
	
	  ;% GUI_User_V1_3_B.Sum15_p
	  section.data(232).logicalSrcIdx = 239;
	  section.data(232).dtTransOffset = 253;
	
	  ;% GUI_User_V1_3_B.Sum13_g
	  section.data(233).logicalSrcIdx = 240;
	  section.data(233).dtTransOffset = 254;
	
	  ;% GUI_User_V1_3_B.ProportionalGain_mo
	  section.data(234).logicalSrcIdx = 241;
	  section.data(234).dtTransOffset = 255;
	
	  ;% GUI_User_V1_3_B.Integrator_pa
	  section.data(235).logicalSrcIdx = 242;
	  section.data(235).dtTransOffset = 256;
	
	  ;% GUI_User_V1_3_B.DerivativeGain_klw
	  section.data(236).logicalSrcIdx = 243;
	  section.data(236).dtTransOffset = 257;
	
	  ;% GUI_User_V1_3_B.Filter_io
	  section.data(237).logicalSrcIdx = 244;
	  section.data(237).dtTransOffset = 258;
	
	  ;% GUI_User_V1_3_B.SumD_m3
	  section.data(238).logicalSrcIdx = 245;
	  section.data(238).dtTransOffset = 259;
	
	  ;% GUI_User_V1_3_B.FilterCoefficient_hs
	  section.data(239).logicalSrcIdx = 246;
	  section.data(239).dtTransOffset = 260;
	
	  ;% GUI_User_V1_3_B.Sum_j
	  section.data(240).logicalSrcIdx = 247;
	  section.data(240).dtTransOffset = 261;
	
	  ;% GUI_User_V1_3_B.Sum14_k
	  section.data(241).logicalSrcIdx = 248;
	  section.data(241).dtTransOffset = 262;
	
	  ;% GUI_User_V1_3_B.Gain5_f
	  section.data(242).logicalSrcIdx = 249;
	  section.data(242).dtTransOffset = 263;
	
	  ;% GUI_User_V1_3_B.IntegralGain_h
	  section.data(243).logicalSrcIdx = 250;
	  section.data(243).dtTransOffset = 264;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain11_b
	  section.data(244).logicalSrcIdx = 251;
	  section.data(244).dtTransOffset = 265;
	
	  ;% GUI_User_V1_3_B.FeeedForwardGain12_j
	  section.data(245).logicalSrcIdx = 252;
	  section.data(245).dtTransOffset = 266;
	
	  ;% GUI_User_V1_3_B.Sum18_j
	  section.data(246).logicalSrcIdx = 253;
	  section.data(246).dtTransOffset = 267;
	
	  ;% GUI_User_V1_3_B.Sum16_l
	  section.data(247).logicalSrcIdx = 254;
	  section.data(247).dtTransOffset = 268;
	
	  ;% GUI_User_V1_3_B.ProportionalGain_mm
	  section.data(248).logicalSrcIdx = 255;
	  section.data(248).dtTransOffset = 269;
	
	  ;% GUI_User_V1_3_B.Integrator_ir
	  section.data(249).logicalSrcIdx = 256;
	  section.data(249).dtTransOffset = 270;
	
	  ;% GUI_User_V1_3_B.DerivativeGain_eo
	  section.data(250).logicalSrcIdx = 257;
	  section.data(250).dtTransOffset = 271;
	
	  ;% GUI_User_V1_3_B.Filter_d
	  section.data(251).logicalSrcIdx = 258;
	  section.data(251).dtTransOffset = 272;
	
	  ;% GUI_User_V1_3_B.SumD_g
	  section.data(252).logicalSrcIdx = 259;
	  section.data(252).dtTransOffset = 273;
	
	  ;% GUI_User_V1_3_B.FilterCoefficient_b
	  section.data(253).logicalSrcIdx = 260;
	  section.data(253).dtTransOffset = 274;
	
	  ;% GUI_User_V1_3_B.Sum_iv
	  section.data(254).logicalSrcIdx = 261;
	  section.data(254).dtTransOffset = 275;
	
	  ;% GUI_User_V1_3_B.Sum17_k
	  section.data(255).logicalSrcIdx = 262;
	  section.data(255).dtTransOffset = 276;
	
	  ;% GUI_User_V1_3_B.Gain6_f
	  section.data(256).logicalSrcIdx = 263;
	  section.data(256).dtTransOffset = 277;
	
	  ;% GUI_User_V1_3_B.IntegralGain_m
	  section.data(257).logicalSrcIdx = 264;
	  section.data(257).dtTransOffset = 278;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.ReadIntStatusFC1_o2
	  section.data(1).logicalSrcIdx = 265;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_B.FIFOread2_o1
	  section.data(2).logicalSrcIdx = 266;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GUI_User_V1_3_B.FIFOread2_o2
	  section.data(3).logicalSrcIdx = 267;
	  section.data(3).dtTransOffset = 62;
	
	  ;% GUI_User_V1_3_B.ReadHWFIFO2
	  section.data(4).logicalSrcIdx = 268;
	  section.data(4).dtTransOffset = 63;
	
	  ;% GUI_User_V1_3_B.FIFOread1_o1
	  section.data(5).logicalSrcIdx = 269;
	  section.data(5).dtTransOffset = 128;
	
	  ;% GUI_User_V1_3_B.FIFOread1_o2
	  section.data(6).logicalSrcIdx = 270;
	  section.data(6).dtTransOffset = 189;
	
	  ;% GUI_User_V1_3_B.ReadHWFIFO1
	  section.data(7).logicalSrcIdx = 271;
	  section.data(7).dtTransOffset = 190;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.FIFOread1
	  section.data(1).logicalSrcIdx = 272;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_B.FIFOread2
	  section.data(2).logicalSrcIdx = 273;
	  section.data(2).dtTransOffset = 1025;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.ASCIIEncode
	  section.data(1).logicalSrcIdx = 274;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_B.FromFile1
	  section.data(2).logicalSrcIdx = 275;
	  section.data(2).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.FIFOwrite1_o2
	  section.data(1).logicalSrcIdx = 276;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_B.FIFOwrite2_o2
	  section.data(2).logicalSrcIdx = 277;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.IfActionSubsystem11.Gain
	  section.data(1).logicalSrcIdx = 278;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_B.IfActionSubsystem11.Sum
	  section.data(2).logicalSrcIdx = 279;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.IfActionSubsystem10.Sum
	  section.data(1).logicalSrcIdx = 280;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.IfActionSubsystem9.Gain
	  section.data(1).logicalSrcIdx = 281;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_B.IfActionSubsystem9.Sum
	  section.data(2).logicalSrcIdx = 282;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.IfActionSubsystem8.Sum
	  section.data(1).logicalSrcIdx = 283;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.IfActionSubsystem7.Gain
	  section.data(1).logicalSrcIdx = 284;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_B.IfActionSubsystem7.Sum
	  section.data(2).logicalSrcIdx = 285;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.IfActionSubsystem6_a.Sum
	  section.data(1).logicalSrcIdx = 286;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.IfActionSubsystem5_i.Gain
	  section.data(1).logicalSrcIdx = 287;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_B.IfActionSubsystem5_i.Sum
	  section.data(2).logicalSrcIdx = 288;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.IfActionSubsystem4.Sum
	  section.data(1).logicalSrcIdx = 289;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.IfActionSubsystem3.Gain
	  section.data(1).logicalSrcIdx = 290;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_B.IfActionSubsystem3.Sum
	  section.data(2).logicalSrcIdx = 291;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.IfActionSubsystem2_c.Sum
	  section.data(1).logicalSrcIdx = 292;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.IfActionSubsystem1.Gain
	  section.data(1).logicalSrcIdx = 293;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_B.IfActionSubsystem1.Sum
	  section.data(2).logicalSrcIdx = 294;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_B.IfActionSubsystem_h.Sum
	  section.data(1).logicalSrcIdx = 295;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(18) = section;
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
    nTotSects     = 16;
    sectIdxOffset = 18;
    
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
    ;% Auto data (GUI_User_V1_3_DWork)
    ;%
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.DiscreteStateSpace5_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_DWork.DiscreteStateSpace4_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% GUI_User_V1_3_DWork.DiscreteStateSpace3_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% GUI_User_V1_3_DWork.DiscreteStateSpace2_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% GUI_User_V1_3_DWork.DiscreteStateSpace1_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% GUI_User_V1_3_DWork.DiscreteStateSpace6_DSTATE
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% GUI_User_V1_3_DWork.Integrator_DSTATE
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% GUI_User_V1_3_DWork.Filter_DSTATE
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 13;
	
	  ;% GUI_User_V1_3_DWork.Integrator_DSTATE_m
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 14;
	
	  ;% GUI_User_V1_3_DWork.Filter_DSTATE_i
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 15;
	
	  ;% GUI_User_V1_3_DWork.Integrator_DSTATE_a
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 16;
	
	  ;% GUI_User_V1_3_DWork.Filter_DSTATE_h
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 17;
	
	  ;% GUI_User_V1_3_DWork.Integrator_DSTATE_g
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% GUI_User_V1_3_DWork.Filter_DSTATE_k
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% GUI_User_V1_3_DWork.Integrator_DSTATE_c
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 20;
	
	  ;% GUI_User_V1_3_DWork.Filter_DSTATE_n
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 21;
	
	  ;% GUI_User_V1_3_DWork.Integrator_DSTATE_l
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 22;
	
	  ;% GUI_User_V1_3_DWork.Filter_DSTATE_m
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 23;
	
	  ;% GUI_User_V1_3_DWork.DiscreteZeroPole1_DSTATE
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 24;
	
	  ;% GUI_User_V1_3_DWork.DiscreteZeroPole2_DSTATE
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 28;
	
	  ;% GUI_User_V1_3_DWork.DiscreteZeroPole3_DSTATE
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 32;
	
	  ;% GUI_User_V1_3_DWork.DiscreteZeroPole4_DSTATE
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 36;
	
	  ;% GUI_User_V1_3_DWork.DiscreteZeroPole5_DSTATE
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 40;
	
	  ;% GUI_User_V1_3_DWork.DiscreteZeroPole6_DSTATE
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 44;
	
	  ;% GUI_User_V1_3_DWork.Integrator_DSTATE_cb
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 48;
	
	  ;% GUI_User_V1_3_DWork.Filter_DSTATE_f
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 49;
	
	  ;% GUI_User_V1_3_DWork.Integrator_DSTATE_j
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 50;
	
	  ;% GUI_User_V1_3_DWork.Filter_DSTATE_o
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 51;
	
	  ;% GUI_User_V1_3_DWork.Integrator_DSTATE_d
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 52;
	
	  ;% GUI_User_V1_3_DWork.Filter_DSTATE_mn
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 53;
	
	  ;% GUI_User_V1_3_DWork.Integrator_DSTATE_k
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 54;
	
	  ;% GUI_User_V1_3_DWork.Filter_DSTATE_mv
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 55;
	
	  ;% GUI_User_V1_3_DWork.Integrator_DSTATE_mj
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 56;
	
	  ;% GUI_User_V1_3_DWork.Filter_DSTATE_kq
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 57;
	
	  ;% GUI_User_V1_3_DWork.Integrator_DSTATE_i
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 58;
	
	  ;% GUI_User_V1_3_DWork.Filter_DSTATE_me
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 59;
	
	  ;% GUI_User_V1_3_DWork.MM16ATAnalogInput_RWORK
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 60;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.ASCIIEncode_PWORK
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_DWork.FIFOwrite1_PWORK
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GUI_User_V1_3_DWork.FIFOwrite2_PWORK
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GUI_User_V1_3_DWork.FIFOwrite2_PWORK_o
	  section.data(4).logicalSrcIdx = 40;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GUI_User_V1_3_DWork.FIFOwrite1_PWORK_d
	  section.data(5).logicalSrcIdx = 41;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.MM16ATAnalogInput_IWORK
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_DWork.FIFOwrite1_IWORK
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GUI_User_V1_3_DWork.EnableTX1_IWORK
	  section.data(3).logicalSrcIdx = 44;
	  section.data(3).dtTransOffset = 4;
	
	  ;% GUI_User_V1_3_DWork.FIFOwrite2_IWORK
	  section.data(4).logicalSrcIdx = 45;
	  section.data(4).dtTransOffset = 5;
	
	  ;% GUI_User_V1_3_DWork.EnableTX2_IWORK
	  section.data(5).logicalSrcIdx = 46;
	  section.data(5).dtTransOffset = 8;
	
	  ;% GUI_User_V1_3_DWork.Setup1_IWORK
	  section.data(6).logicalSrcIdx = 47;
	  section.data(6).dtTransOffset = 9;
	
	  ;% GUI_User_V1_3_DWork.Setup2_IWORK
	  section.data(7).logicalSrcIdx = 48;
	  section.data(7).dtTransOffset = 12;
	
	  ;% GUI_User_V1_3_DWork.WriteHWFIFO2_IWORK
	  section.data(8).logicalSrcIdx = 49;
	  section.data(8).dtTransOffset = 15;
	
	  ;% GUI_User_V1_3_DWork.ReadHWFIFO2_IWORK
	  section.data(9).logicalSrcIdx = 50;
	  section.data(9).dtTransOffset = 16;
	
	  ;% GUI_User_V1_3_DWork.FIFOwrite2_IWORK_k
	  section.data(10).logicalSrcIdx = 51;
	  section.data(10).dtTransOffset = 17;
	
	  ;% GUI_User_V1_3_DWork.WriteHWFIFO1_IWORK
	  section.data(11).logicalSrcIdx = 52;
	  section.data(11).dtTransOffset = 20;
	
	  ;% GUI_User_V1_3_DWork.ReadHWFIFO1_IWORK
	  section.data(12).logicalSrcIdx = 53;
	  section.data(12).dtTransOffset = 21;
	
	  ;% GUI_User_V1_3_DWork.FIFOwrite1_IWORK_o
	  section.data(13).logicalSrcIdx = 54;
	  section.data(13).dtTransOffset = 22;
	
	  ;% GUI_User_V1_3_DWork.FromFile1_IWORK
	  section.data(14).logicalSrcIdx = 55;
	  section.data(14).dtTransOffset = 25;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.If_ActiveSubsystem
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem_SubsysRanBC
	  section.data(2).logicalSrcIdx = 57;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem5_SubsysRanBC
	  section.data(3).logicalSrcIdx = 58;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem6_SubsysRanBC
	  section.data(4).logicalSrcIdx = 59;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem2_SubsysRanBC
	  section.data(5).logicalSrcIdx = 60;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GUI_User_V1_3_DWork.RS232ISR_SubsysRanBC
	  section.data(6).logicalSrcIdx = 61;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GUI_User_V1_3_DWork.Receive1_SubsysRanBC
	  section.data(7).logicalSrcIdx = 62;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GUI_User_V1_3_DWork.Transmit1_SubsysRanBC
	  section.data(8).logicalSrcIdx = 63;
	  section.data(8).dtTransOffset = 7;
	
	  ;% GUI_User_V1_3_DWork.Receive2_SubsysRanBC
	  section.data(9).logicalSrcIdx = 64;
	  section.data(9).dtTransOffset = 8;
	
	  ;% GUI_User_V1_3_DWork.Transmit2_SubsysRanBC
	  section.data(10).logicalSrcIdx = 65;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem11.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem10.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem9.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem8.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem7.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem6_a.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem5_i.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem3.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem2_c.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GUI_User_V1_3_DWork.IfActionSubsystem_h.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
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


  targMap.checksum0 = 3187963147;
  targMap.checksum1 = 3578660434;
  targMap.checksum2 = 1249621880;
  targMap.checksum3 = 2337795904;

