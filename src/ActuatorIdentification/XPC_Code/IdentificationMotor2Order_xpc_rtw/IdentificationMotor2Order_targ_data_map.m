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
    ;% Auto data (IdentificationMotor2Order_P)
    ;%
      section.nData     = 220;
      section.data(220)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P1_Size
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P2_Size
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P3_Size
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P4_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P4
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P5_Size
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P5
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 14;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P1_Size
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 34;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 36;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P2_Size
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 37;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P2
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 39;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P3_Size
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 40;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P3
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 42;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P4_Size
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 43;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P4
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 45;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P5_Size
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 46;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P5
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 48;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P6_Size
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 49;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P6
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 51;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P7_Size
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 52;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P7
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 54;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P8_Size
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 55;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P8
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 57;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P1_Size
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 58;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P1
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 60;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P2_Size
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 61;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P2
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 63;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P3_Size
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 64;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P3
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 66;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P4_Size
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 67;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P4
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 69;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P5_Size
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 70;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P5
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 72;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P1_Size
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 92;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P1
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 94;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P2_Size
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 95;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P2
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 97;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P3_Size
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 98;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P3
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 100;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P4_Size
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 101;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P4
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 103;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P5_Size
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 104;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P5
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 106;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P6_Size
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 107;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P6
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 109;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P7_Size
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 110;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P7
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 112;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P8_Size
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 113;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P8
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 115;
	
	  ;% IdentificationMotor2Order_P.MM16ATAnalogInput_P1_Size
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 116;
	
	  ;% IdentificationMotor2Order_P.MM16ATAnalogInput_P1
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 118;
	
	  ;% IdentificationMotor2Order_P.MM16ATAnalogInput_P2_Size
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 119;
	
	  ;% IdentificationMotor2Order_P.MM16ATAnalogInput_P2
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 121;
	
	  ;% IdentificationMotor2Order_P.MM16ATAnalogInput_P3_Size
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 122;
	
	  ;% IdentificationMotor2Order_P.MM16ATAnalogInput_P3
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 124;
	
	  ;% IdentificationMotor2Order_P.MM16ATAnalogInput_P4_Size
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 125;
	
	  ;% IdentificationMotor2Order_P.MM16ATAnalogInput_P4
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 127;
	
	  ;% IdentificationMotor2Order_P.MM16ATAnalogInput_P5_Size
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 128;
	
	  ;% IdentificationMotor2Order_P.MM16ATAnalogInput_P5
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 130;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace6_A
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 131;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace6_B
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 135;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace6_C
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 137;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace6_D
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 139;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace6_X0
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 140;
	
	  ;% IdentificationMotor2Order_P.Gain_Gain
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 142;
	
	  ;% IdentificationMotor2Order_P.Constant2_Value
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 143;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace1_A
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 144;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace1_B
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 148;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace1_C
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 150;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace1_D
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 152;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace1_X0
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 153;
	
	  ;% IdentificationMotor2Order_P.Gain1_Gain
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 155;
	
	  ;% IdentificationMotor2Order_P.Constant1_Value
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 156;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace2_A
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 157;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace2_B
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 161;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace2_C
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 163;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace2_D
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 165;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace2_X0
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 166;
	
	  ;% IdentificationMotor2Order_P.Gain8_Gain
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 168;
	
	  ;% IdentificationMotor2Order_P.Constant3_Value
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 169;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace3_A
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 170;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace3_B
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 174;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace3_C
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 176;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace3_D
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 178;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace3_X0
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 179;
	
	  ;% IdentificationMotor2Order_P.Gain9_Gain
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 181;
	
	  ;% IdentificationMotor2Order_P.Constant4_Value
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 182;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace4_A
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 183;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace4_B
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 187;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace4_C
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 189;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace4_D
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 191;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace4_X0
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 192;
	
	  ;% IdentificationMotor2Order_P.Gain10_Gain
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 194;
	
	  ;% IdentificationMotor2Order_P.Constant5_Value
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 195;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace5_A
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 196;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace5_B
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 200;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace5_C
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 202;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace5_D
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 204;
	
	  ;% IdentificationMotor2Order_P.DiscreteStateSpace5_X0
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 205;
	
	  ;% IdentificationMotor2Order_P.Gain11_Gain
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 207;
	
	  ;% IdentificationMotor2Order_P.Constant6_Value
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 208;
	
	  ;% IdentificationMotor2Order_P.Gain2_Gain
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 209;
	
	  ;% IdentificationMotor2Order_P.Gain3_Gain
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 210;
	
	  ;% IdentificationMotor2Order_P.Gain4_Gain
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 211;
	
	  ;% IdentificationMotor2Order_P.Gain5_Gain
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 212;
	
	  ;% IdentificationMotor2Order_P.Gain6_Gain
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 213;
	
	  ;% IdentificationMotor2Order_P.Gain7_Gain
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 214;
	
	  ;% IdentificationMotor2Order_P.Gain_Gain_b
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 215;
	
	  ;% IdentificationMotor2Order_P.Constant_Value
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 216;
	
	  ;% IdentificationMotor2Order_P.Saturation_UpperSat
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 217;
	
	  ;% IdentificationMotor2Order_P.Saturation_LowerSat
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 218;
	
	  ;% IdentificationMotor2Order_P.Saturation1_UpperSat
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 219;
	
	  ;% IdentificationMotor2Order_P.Saturation1_LowerSat
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 220;
	
	  ;% IdentificationMotor2Order_P.Constant1_Value_l
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 221;
	
	  ;% IdentificationMotor2Order_P.Saturation2_UpperSat
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 222;
	
	  ;% IdentificationMotor2Order_P.Saturation2_LowerSat
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 223;
	
	  ;% IdentificationMotor2Order_P.Constant2_Value_e
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 224;
	
	  ;% IdentificationMotor2Order_P.Saturation3_UpperSat
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 225;
	
	  ;% IdentificationMotor2Order_P.Saturation3_LowerSat
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 226;
	
	  ;% IdentificationMotor2Order_P.Constant3_Value_a
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 227;
	
	  ;% IdentificationMotor2Order_P.Saturation4_UpperSat
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 228;
	
	  ;% IdentificationMotor2Order_P.Saturation4_LowerSat
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 229;
	
	  ;% IdentificationMotor2Order_P.Constant4_Value_g
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 230;
	
	  ;% IdentificationMotor2Order_P.Saturation5_UpperSat
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 231;
	
	  ;% IdentificationMotor2Order_P.Saturation5_LowerSat
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 232;
	
	  ;% IdentificationMotor2Order_P.ASCIIEncode_P1_Size
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 233;
	
	  ;% IdentificationMotor2Order_P.ASCIIEncode_P1
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 235;
	
	  ;% IdentificationMotor2Order_P.ASCIIEncode_P2_Size
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 248;
	
	  ;% IdentificationMotor2Order_P.ASCIIEncode_P2
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 250;
	
	  ;% IdentificationMotor2Order_P.ASCIIEncode_P3_Size
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 251;
	
	  ;% IdentificationMotor2Order_P.ASCIIEncode_P3
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 253;
	
	  ;% IdentificationMotor2Order_P.ASCIIEncode_P4_Size
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 254;
	
	  ;% IdentificationMotor2Order_P.ASCIIEncode_P4
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 256;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P1_Size_o
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 262;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P1_g
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 264;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P2_Size_n
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 265;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P2_g
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 267;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P3_Size_p
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 268;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P3_i
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 270;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P4_Size_k
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 271;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P4_b
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 273;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P5_Size_e
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 274;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite1_P5_c
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 276;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P1_Size_d
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 296;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P1_l
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 298;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P2_Size_f
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 299;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P2_c
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 301;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P3_Size_p
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 302;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P3_d
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 304;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P4_Size_p
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 305;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P4_o
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 307;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P5_Size_c
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 308;
	
	  ;% IdentificationMotor2Order_P.FIFOwrite2_P5_k
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 310;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P1_Size_k
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 330;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P1_b
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 332;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P2_Size_m
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 333;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P2_b
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 335;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P3_Size_d
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 336;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P3_e
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 338;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P4_Size_m
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 339;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P4_e
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 341;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P5_Size_k
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 342;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P5_o
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 344;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P6_Size_i
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 345;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P6_n
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 347;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P7_Size_i
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 348;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P7_o
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 350;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P8_Size_a
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 351;
	
	  ;% IdentificationMotor2Order_P.FIFOread1_P8_e
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 353;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P1_Size_n
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 354;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P1_o
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 356;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P2_Size_i
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 357;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P2_m
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 359;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P3_Size_h
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 360;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P3_n
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 362;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P4_Size_p
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 363;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P4_l
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 365;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P5_Size_m
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 366;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P5_h
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 368;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P6_Size_c
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 369;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P6_h
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 371;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P7_Size_k
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 372;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P7_j
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 374;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P8_Size_c
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 375;
	
	  ;% IdentificationMotor2Order_P.FIFOread2_P8_l
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 377;
	
	  ;% IdentificationMotor2Order_P.Setup1_P1_Size
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 378;
	
	  ;% IdentificationMotor2Order_P.Setup1_P1
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 380;
	
	  ;% IdentificationMotor2Order_P.Setup1_P2_Size
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 381;
	
	  ;% IdentificationMotor2Order_P.Setup1_P2
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 383;
	
	  ;% IdentificationMotor2Order_P.Setup1_P3_Size
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 384;
	
	  ;% IdentificationMotor2Order_P.Setup1_P3
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 386;
	
	  ;% IdentificationMotor2Order_P.Setup1_P4_Size
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 387;
	
	  ;% IdentificationMotor2Order_P.Setup1_P4
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 389;
	
	  ;% IdentificationMotor2Order_P.Setup1_P5_Size
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 390;
	
	  ;% IdentificationMotor2Order_P.Setup1_P5
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 392;
	
	  ;% IdentificationMotor2Order_P.Setup1_P6_Size
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 393;
	
	  ;% IdentificationMotor2Order_P.Setup1_P6
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 395;
	
	  ;% IdentificationMotor2Order_P.Setup1_P7_Size
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 396;
	
	  ;% IdentificationMotor2Order_P.Setup1_P7
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 398;
	
	  ;% IdentificationMotor2Order_P.Setup1_P8_Size
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 399;
	
	  ;% IdentificationMotor2Order_P.Setup1_P8
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 401;
	
	  ;% IdentificationMotor2Order_P.Setup2_P1_Size
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 402;
	
	  ;% IdentificationMotor2Order_P.Setup2_P1
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 404;
	
	  ;% IdentificationMotor2Order_P.Setup2_P2_Size
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 405;
	
	  ;% IdentificationMotor2Order_P.Setup2_P2
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 407;
	
	  ;% IdentificationMotor2Order_P.Setup2_P3_Size
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 408;
	
	  ;% IdentificationMotor2Order_P.Setup2_P3
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 410;
	
	  ;% IdentificationMotor2Order_P.Setup2_P4_Size
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 411;
	
	  ;% IdentificationMotor2Order_P.Setup2_P4
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 413;
	
	  ;% IdentificationMotor2Order_P.Setup2_P5_Size
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 414;
	
	  ;% IdentificationMotor2Order_P.Setup2_P5
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 416;
	
	  ;% IdentificationMotor2Order_P.Setup2_P6_Size
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 417;
	
	  ;% IdentificationMotor2Order_P.Setup2_P6
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 419;
	
	  ;% IdentificationMotor2Order_P.Setup2_P7_Size
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 420;
	
	  ;% IdentificationMotor2Order_P.Setup2_P7
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 422;
	
	  ;% IdentificationMotor2Order_P.Setup2_P8_Size
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 423;
	
	  ;% IdentificationMotor2Order_P.Setup2_P8
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 425;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.Constant_Value_o
	  section.data(1).logicalSrcIdx = 220;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_P.Constant1_Value_j
	  section.data(2).logicalSrcIdx = 221;
	  section.data(2).dtTransOffset = 1;
	
	  ;% IdentificationMotor2Order_P.Constant_Value_n
	  section.data(3).logicalSrcIdx = 222;
	  section.data(3).dtTransOffset = 2;
	
	  ;% IdentificationMotor2Order_P.Constant2_Value_c
	  section.data(4).logicalSrcIdx = 223;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.IfActionSubsystem11.Constant8_Value
	  section.data(1).logicalSrcIdx = 224;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_P.IfActionSubsystem11.Gain_Gain
	  section.data(2).logicalSrcIdx = 225;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.IfActionSubsystem10.Constant8_Value
	  section.data(1).logicalSrcIdx = 226;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.IfActionSubsystem9.Constant8_Value
	  section.data(1).logicalSrcIdx = 227;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_P.IfActionSubsystem9.Gain_Gain
	  section.data(2).logicalSrcIdx = 228;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.IfActionSubsystem8.Constant8_Value
	  section.data(1).logicalSrcIdx = 229;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.IfActionSubsystem7.Constant8_Value
	  section.data(1).logicalSrcIdx = 230;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_P.IfActionSubsystem7.Gain_Gain
	  section.data(2).logicalSrcIdx = 231;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.IfActionSubsystem6.Constant8_Value
	  section.data(1).logicalSrcIdx = 232;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.IfActionSubsystem5.Constant8_Value
	  section.data(1).logicalSrcIdx = 233;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_P.IfActionSubsystem5.Gain_Gain
	  section.data(2).logicalSrcIdx = 234;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.IfActionSubsystem4.Constant8_Value
	  section.data(1).logicalSrcIdx = 235;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.IfActionSubsystem3.Constant8_Value
	  section.data(1).logicalSrcIdx = 236;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_P.IfActionSubsystem3.Gain_Gain
	  section.data(2).logicalSrcIdx = 237;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.IfActionSubsystem2.Constant8_Value
	  section.data(1).logicalSrcIdx = 238;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.IfActionSubsystem1.Constant8_Value
	  section.data(1).logicalSrcIdx = 239;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_P.IfActionSubsystem1.Gain_Gain
	  section.data(2).logicalSrcIdx = 240;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_P.IfActionSubsystem.Constant8_Value
	  section.data(1).logicalSrcIdx = 241;
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
    ;% Auto data (IdentificationMotor2Order_B)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.FIFOwrite1_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_B.FIFOwrite2_o1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% IdentificationMotor2Order_B.RateTransition
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% IdentificationMotor2Order_B.RateTransition2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% IdentificationMotor2Order_B.RateTransition1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% IdentificationMotor2Order_B.RateTransition3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% IdentificationMotor2Order_B.FIFOwrite2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% IdentificationMotor2Order_B.FIFOwrite1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 50;
      section.data(50)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.MM16ATAnalogInput_o1
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_B.MM16ATAnalogInput_o2
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% IdentificationMotor2Order_B.MM16ATAnalogInput_o3
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% IdentificationMotor2Order_B.MM16ATAnalogInput_o4
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% IdentificationMotor2Order_B.MM16ATAnalogInput_o5
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% IdentificationMotor2Order_B.MM16ATAnalogInput_o6
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% IdentificationMotor2Order_B.MM16ATAnalogInput_o7
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% IdentificationMotor2Order_B.MM16ATAnalogInput_o8
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% IdentificationMotor2Order_B.MM16ATAnalogInput_o9
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 8;
	
	  ;% IdentificationMotor2Order_B.MM16ATAnalogInput_o10
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 9;
	
	  ;% IdentificationMotor2Order_B.MM16ATAnalogInput_o11
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 10;
	
	  ;% IdentificationMotor2Order_B.MM16ATAnalogInput_o12
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 11;
	
	  ;% IdentificationMotor2Order_B.DiscreteStateSpace6
	  section.data(13).logicalSrcIdx = 20;
	  section.data(13).dtTransOffset = 12;
	
	  ;% IdentificationMotor2Order_B.Gain
	  section.data(14).logicalSrcIdx = 21;
	  section.data(14).dtTransOffset = 13;
	
	  ;% IdentificationMotor2Order_B.Sum1
	  section.data(15).logicalSrcIdx = 22;
	  section.data(15).dtTransOffset = 14;
	
	  ;% IdentificationMotor2Order_B.DiscreteStateSpace1
	  section.data(16).logicalSrcIdx = 23;
	  section.data(16).dtTransOffset = 15;
	
	  ;% IdentificationMotor2Order_B.Gain1
	  section.data(17).logicalSrcIdx = 24;
	  section.data(17).dtTransOffset = 16;
	
	  ;% IdentificationMotor2Order_B.Sum2
	  section.data(18).logicalSrcIdx = 25;
	  section.data(18).dtTransOffset = 17;
	
	  ;% IdentificationMotor2Order_B.DiscreteStateSpace2
	  section.data(19).logicalSrcIdx = 26;
	  section.data(19).dtTransOffset = 18;
	
	  ;% IdentificationMotor2Order_B.Gain8
	  section.data(20).logicalSrcIdx = 27;
	  section.data(20).dtTransOffset = 19;
	
	  ;% IdentificationMotor2Order_B.Sum3
	  section.data(21).logicalSrcIdx = 28;
	  section.data(21).dtTransOffset = 20;
	
	  ;% IdentificationMotor2Order_B.DiscreteStateSpace3
	  section.data(22).logicalSrcIdx = 29;
	  section.data(22).dtTransOffset = 21;
	
	  ;% IdentificationMotor2Order_B.Gain9
	  section.data(23).logicalSrcIdx = 30;
	  section.data(23).dtTransOffset = 22;
	
	  ;% IdentificationMotor2Order_B.Sum4
	  section.data(24).logicalSrcIdx = 31;
	  section.data(24).dtTransOffset = 23;
	
	  ;% IdentificationMotor2Order_B.DiscreteStateSpace4
	  section.data(25).logicalSrcIdx = 32;
	  section.data(25).dtTransOffset = 24;
	
	  ;% IdentificationMotor2Order_B.Gain10
	  section.data(26).logicalSrcIdx = 33;
	  section.data(26).dtTransOffset = 25;
	
	  ;% IdentificationMotor2Order_B.Sum5
	  section.data(27).logicalSrcIdx = 34;
	  section.data(27).dtTransOffset = 26;
	
	  ;% IdentificationMotor2Order_B.DiscreteStateSpace5
	  section.data(28).logicalSrcIdx = 35;
	  section.data(28).dtTransOffset = 27;
	
	  ;% IdentificationMotor2Order_B.Gain11
	  section.data(29).logicalSrcIdx = 36;
	  section.data(29).dtTransOffset = 28;
	
	  ;% IdentificationMotor2Order_B.Sum6
	  section.data(30).logicalSrcIdx = 37;
	  section.data(30).dtTransOffset = 29;
	
	  ;% IdentificationMotor2Order_B.Gain2
	  section.data(31).logicalSrcIdx = 38;
	  section.data(31).dtTransOffset = 30;
	
	  ;% IdentificationMotor2Order_B.Gain3
	  section.data(32).logicalSrcIdx = 39;
	  section.data(32).dtTransOffset = 31;
	
	  ;% IdentificationMotor2Order_B.Gain4
	  section.data(33).logicalSrcIdx = 40;
	  section.data(33).dtTransOffset = 32;
	
	  ;% IdentificationMotor2Order_B.Gain5
	  section.data(34).logicalSrcIdx = 41;
	  section.data(34).dtTransOffset = 33;
	
	  ;% IdentificationMotor2Order_B.Gain6
	  section.data(35).logicalSrcIdx = 42;
	  section.data(35).dtTransOffset = 34;
	
	  ;% IdentificationMotor2Order_B.Gain7
	  section.data(36).logicalSrcIdx = 43;
	  section.data(36).dtTransOffset = 35;
	
	  ;% IdentificationMotor2Order_B.Velocityreference2
	  section.data(37).logicalSrcIdx = 44;
	  section.data(37).dtTransOffset = 36;
	
	  ;% IdentificationMotor2Order_B.ControlSignal2
	  section.data(38).logicalSrcIdx = 45;
	  section.data(38).dtTransOffset = 37;
	
	  ;% IdentificationMotor2Order_B.Saturation
	  section.data(39).logicalSrcIdx = 46;
	  section.data(39).dtTransOffset = 38;
	
	  ;% IdentificationMotor2Order_B.Saturation1
	  section.data(40).logicalSrcIdx = 47;
	  section.data(40).dtTransOffset = 39;
	
	  ;% IdentificationMotor2Order_B.Saturation2
	  section.data(41).logicalSrcIdx = 48;
	  section.data(41).dtTransOffset = 40;
	
	  ;% IdentificationMotor2Order_B.Saturation3
	  section.data(42).logicalSrcIdx = 49;
	  section.data(42).dtTransOffset = 41;
	
	  ;% IdentificationMotor2Order_B.Saturation4
	  section.data(43).logicalSrcIdx = 50;
	  section.data(43).dtTransOffset = 42;
	
	  ;% IdentificationMotor2Order_B.Saturation5
	  section.data(44).logicalSrcIdx = 51;
	  section.data(44).dtTransOffset = 43;
	
	  ;% IdentificationMotor2Order_B.Merge
	  section.data(45).logicalSrcIdx = 52;
	  section.data(45).dtTransOffset = 44;
	
	  ;% IdentificationMotor2Order_B.Merge1
	  section.data(46).logicalSrcIdx = 53;
	  section.data(46).dtTransOffset = 45;
	
	  ;% IdentificationMotor2Order_B.Merge2
	  section.data(47).logicalSrcIdx = 54;
	  section.data(47).dtTransOffset = 46;
	
	  ;% IdentificationMotor2Order_B.Merge3
	  section.data(48).logicalSrcIdx = 55;
	  section.data(48).dtTransOffset = 47;
	
	  ;% IdentificationMotor2Order_B.Merge4
	  section.data(49).logicalSrcIdx = 56;
	  section.data(49).dtTransOffset = 48;
	
	  ;% IdentificationMotor2Order_B.Merge5
	  section.data(50).logicalSrcIdx = 57;
	  section.data(50).dtTransOffset = 49;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.ReadIntStatusFC1_o2
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_B.FIFOread2_o1
	  section.data(2).logicalSrcIdx = 59;
	  section.data(2).dtTransOffset = 1;
	
	  ;% IdentificationMotor2Order_B.FIFOread2_o2
	  section.data(3).logicalSrcIdx = 60;
	  section.data(3).dtTransOffset = 62;
	
	  ;% IdentificationMotor2Order_B.ReadHWFIFO2
	  section.data(4).logicalSrcIdx = 61;
	  section.data(4).dtTransOffset = 63;
	
	  ;% IdentificationMotor2Order_B.FIFOread1_o1
	  section.data(5).logicalSrcIdx = 62;
	  section.data(5).dtTransOffset = 128;
	
	  ;% IdentificationMotor2Order_B.FIFOread1_o2
	  section.data(6).logicalSrcIdx = 63;
	  section.data(6).dtTransOffset = 189;
	
	  ;% IdentificationMotor2Order_B.ReadHWFIFO1
	  section.data(7).logicalSrcIdx = 64;
	  section.data(7).dtTransOffset = 190;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.FIFOread1
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_B.FIFOread2
	  section.data(2).logicalSrcIdx = 66;
	  section.data(2).dtTransOffset = 1025;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.ASCIIEncode
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.FIFOwrite1_o2
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_B.FIFOwrite2_o2
	  section.data(2).logicalSrcIdx = 69;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.IfActionSubsystem11.Gain
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_B.IfActionSubsystem11.Sum
	  section.data(2).logicalSrcIdx = 71;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.IfActionSubsystem10.Sum
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.IfActionSubsystem9.Gain
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_B.IfActionSubsystem9.Sum
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.IfActionSubsystem8.Sum
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.IfActionSubsystem7.Gain
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_B.IfActionSubsystem7.Sum
	  section.data(2).logicalSrcIdx = 77;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.IfActionSubsystem6.Sum
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.IfActionSubsystem5.Gain
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_B.IfActionSubsystem5.Sum
	  section.data(2).logicalSrcIdx = 80;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.IfActionSubsystem4.Sum
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.IfActionSubsystem3.Gain
	  section.data(1).logicalSrcIdx = 82;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_B.IfActionSubsystem3.Sum
	  section.data(2).logicalSrcIdx = 83;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.IfActionSubsystem2.Sum
	  section.data(1).logicalSrcIdx = 84;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.IfActionSubsystem1.Gain
	  section.data(1).logicalSrcIdx = 85;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_B.IfActionSubsystem1.Sum
	  section.data(2).logicalSrcIdx = 86;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_B.IfActionSubsystem.Sum
	  section.data(1).logicalSrcIdx = 87;
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
    ;% Auto data (IdentificationMotor2Order_DWork)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.DiscreteStateSpace6_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_DWork.DiscreteStateSpace1_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% IdentificationMotor2Order_DWork.DiscreteStateSpace2_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% IdentificationMotor2Order_DWork.DiscreteStateSpace3_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% IdentificationMotor2Order_DWork.DiscreteStateSpace4_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% IdentificationMotor2Order_DWork.DiscreteStateSpace5_DSTATE
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% IdentificationMotor2Order_DWork.MM16ATAnalogInput_RWORK
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.Velocityreference2_PWORK.TimePtr
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_DWork.ASCIIEncode_PWORK
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% IdentificationMotor2Order_DWork.FIFOwrite1_PWORK
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% IdentificationMotor2Order_DWork.FIFOwrite2_PWORK
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
	  ;% IdentificationMotor2Order_DWork.FIFOwrite2_PWORK_i
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 4;
	
	  ;% IdentificationMotor2Order_DWork.FIFOwrite1_PWORK_g
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.MM16ATAnalogInput_IWORK
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_DWork.Velocityreference2_IWORK.PrevIndex
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% IdentificationMotor2Order_DWork.FIFOwrite1_IWORK
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
	  ;% IdentificationMotor2Order_DWork.EnableTX1_IWORK
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 5;
	
	  ;% IdentificationMotor2Order_DWork.FIFOwrite2_IWORK
	  section.data(5).logicalSrcIdx = 17;
	  section.data(5).dtTransOffset = 6;
	
	  ;% IdentificationMotor2Order_DWork.EnableTX2_IWORK
	  section.data(6).logicalSrcIdx = 18;
	  section.data(6).dtTransOffset = 9;
	
	  ;% IdentificationMotor2Order_DWork.Setup1_IWORK
	  section.data(7).logicalSrcIdx = 19;
	  section.data(7).dtTransOffset = 10;
	
	  ;% IdentificationMotor2Order_DWork.Setup2_IWORK
	  section.data(8).logicalSrcIdx = 20;
	  section.data(8).dtTransOffset = 13;
	
	  ;% IdentificationMotor2Order_DWork.WriteHWFIFO2_IWORK
	  section.data(9).logicalSrcIdx = 21;
	  section.data(9).dtTransOffset = 16;
	
	  ;% IdentificationMotor2Order_DWork.ReadHWFIFO2_IWORK
	  section.data(10).logicalSrcIdx = 22;
	  section.data(10).dtTransOffset = 17;
	
	  ;% IdentificationMotor2Order_DWork.FIFOwrite2_IWORK_c
	  section.data(11).logicalSrcIdx = 23;
	  section.data(11).dtTransOffset = 18;
	
	  ;% IdentificationMotor2Order_DWork.WriteHWFIFO1_IWORK
	  section.data(12).logicalSrcIdx = 24;
	  section.data(12).dtTransOffset = 21;
	
	  ;% IdentificationMotor2Order_DWork.ReadHWFIFO1_IWORK
	  section.data(13).logicalSrcIdx = 25;
	  section.data(13).dtTransOffset = 22;
	
	  ;% IdentificationMotor2Order_DWork.FIFOwrite1_IWORK_b
	  section.data(14).logicalSrcIdx = 26;
	  section.data(14).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.RS232ISR_SubsysRanBC
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% IdentificationMotor2Order_DWork.Receive1_SubsysRanBC
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% IdentificationMotor2Order_DWork.Transmit1_SubsysRanBC
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% IdentificationMotor2Order_DWork.Receive2_SubsysRanBC
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 3;
	
	  ;% IdentificationMotor2Order_DWork.Transmit2_SubsysRanBC
	  section.data(5).logicalSrcIdx = 31;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.IfActionSubsystem11.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.IfActionSubsystem10.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.IfActionSubsystem9.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.IfActionSubsystem8.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.IfActionSubsystem7.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.IfActionSubsystem6.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.IfActionSubsystem5.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.IfActionSubsystem3.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% IdentificationMotor2Order_DWork.IfActionSubsystem.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 43;
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


  targMap.checksum0 = 3634476925;
  targMap.checksum1 = 347517418;
  targMap.checksum2 = 2458305616;
  targMap.checksum3 = 2039455143;

