//
// File: FaultModel.cpp
//
// Code generated for Simulink model 'FaultModel'.
//
// Model version                  : 7.70
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Wed Sep 20 18:03:41 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FaultModel.h"
#define NumBitsPerChar                 8U

// Private macros used by the generated code to access rtModel
#ifndef rtmSetFirstInitCond
#define rtmSetFirstInitCond(rtm, val)  ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef GRAVITY2_TYPEDEF

typedef enum { WGS84TAYLORSERIES = 1, WGS84CLOSEAPPROX,
  WGS84EXACT } GravityTypeIdx;

typedef enum { METRIC = 1, ENGLISH } UnitIdx;

typedef enum { JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
  AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER } MonthIdx;

#define GRAVITY2_TYPEDEF
#endif                                 // GRAVITY2_TYPEDEF

#ifndef WGS84_DEFINE
#define WGS84_A                        6378137.0                 // Semi-major Axis (m) 
#define WGS84_INV_F                    298.257223563             // Reciprocal of Flattening 
#define WGS84_W_DEF                    7292115.0e-11             // WGS 84 Angular Velocity of Earth (rad/sec)
#define WGS84_GM_DEF                   3986004.418e+8            // Earth's Gravitational Const. (m^3/sec^2) 
#define WGS84_GM_PRM                   3986000.9e+8              // Earth's Grav. Const. (m^3/sec^2) [no atmos]
#define WGS84_W_PRM                    7292115.1467e-11          // IAU Angular Velocity of Earth (rad/sec) 
#define WGS84_G_E                      9.7803253359              // Theoretical (Normal) Gravity at the Equator
                                                                 // (on the Ellipsoid) (m/s^2) 
#define WGS84_K                        0.00193185265241          // Theoretical (Normal) Gravity Formula Const.
#define WGS84_E_2                      6.69437999014e-3          // First Eccentricity Squared 
#define WGS84_EL                       5.2185400842339e+5        // Linear Eccentricity 
#define WGS84_B                        6356752.3142              // Semi-minor Axis (m) 
#define WGS84_B_A                      0.996647189335            // Axis Ratio
#define M2FT                           1.0/0.3048
#define AERO_PI                        3.14159265358979323846
#define DEG2RAD                        AERO_PI/180.0
#define YEAR2000                       2000
#define WGS84_DEFINE
#endif                                 // WGS84_DEFINE

// Block parameters (default storage)
P_FaultModel_T MulticopterModelClass::FaultModel_P = {
  // Variable: ModelInit_AngEuler
  //  Referenced by: '<S13>/Initial Euler Angles'

  { 0.0, 0.0, 0.0 },

  // Variable: ModelInit_PosE
  //  Referenced by: '<S12>/xe,ye,ze'

  { 0.0, 0.0, 0.0 },

  // Variable: ModelInit_RPM
  //  Referenced by: '<S300>/ModelInit_RPM'

  0.0,

  // Variable: ModelInit_RateB
  //  Referenced by: '<S12>/p,q,r '

  { 0.0, 0.0, 0.0 },

  // Variable: ModelInit_VelB
  //  Referenced by: '<S12>/ub,vb,wb'

  { 0.0, 0.0, 0.0 },

  // Variable: ModelParam_BattHoverMinutes
  //  Referenced by: '<S55>/ModelParam.BattHoverMinutes'

  18.0,

  // Variable: ModelParam_BattHoverThr
  //  Referenced by: '<S55>/ModelParam.BattHoverThr'

  0.609,

  // Variable: ModelParam_GPSEphFinal
  //  Referenced by: '<S327>/ModelParam.GPSEphFinal'

  0.3,

  // Variable: ModelParam_GPSEpvFinal
  //  Referenced by: '<S327>/ModelParam.GPSEpvFinal'

  0.4,

  // Variable: ModelParam_GPSFix3DFix
  //  Referenced by: '<S327>/ModelParam_GPSFix3DFix'

  3.0,

  // Variable: ModelParam_GPSLatLong
  //  Referenced by:
  //    '<S69>/ref_position'
  //    '<S374>/ref_position'

  { 40.1540302, 116.2593683 },

  // Variable: ModelParam_GPSSatsVisible
  //  Referenced by: '<S327>/ModelParam.GPSSatsVisible'

  15.0,

  // Variable: ModelParam_envAltitude
  //  Referenced by:
  //    '<S61>/ModelParam.envAltitude'
  //    '<S327>/ModelParam.envAltitude'

  0.0,

  // Variable: ModelParam_motorCr
  //  Referenced by: '<S300>/ModelParam.motorCr'

  1197.53,

  // Variable: ModelParam_motorJm
  //  Referenced by: '<S7>/ModelParam.motorJm'

  0.0001287,

  // Variable: ModelParam_motorMinThr
  //  Referenced by:
  //    '<S310>/Constant'
  //    '<S312>/Constant'
  //    '<S314>/Constant'
  //    '<S316>/Constant'
  //    '<S318>/Constant'
  //    '<S320>/Constant'
  //    '<S322>/Constant'
  //    '<S324>/Constant'

  0.05,

  // Variable: ModelParam_motorT
  //  Referenced by: '<S300>/ModelParam.motorT'

  0.02,

  // Variable: ModelParam_motorWb
  //  Referenced by: '<S300>/ModelParam.motorWb'

  238.2,

  // Variable: ModelParam_noisePowerOffGainAccel
  //  Referenced by: '<S400>/AccelNoiseGainFunction'

  0.04,

  // Variable: ModelParam_noisePowerOffGainAccelZ
  //  Referenced by: '<S400>/AccelNoiseGainFunction'

  0.03,

  // Variable: ModelParam_noisePowerOffGainGyro
  //  Referenced by: '<S400>/GyroNoiseGainFunction'

  0.02,

  // Variable: ModelParam_noisePowerOffGainGyroZ
  //  Referenced by: '<S400>/GyroNoiseGainFunction'

  0.025,

  // Variable: ModelParam_noisePowerOffGainMag
  //  Referenced by: '<S400>/MagNoiseGainFunction'

  0.02,

  // Variable: ModelParam_noisePowerOffGainMagZ
  //  Referenced by: '<S400>/MagNoiseGainFunction'

  0.035,

  // Variable: ModelParam_noisePowerOnGainAccel
  //  Referenced by: '<S400>/AccelNoiseGainFunction'

  0.8,

  // Variable: ModelParam_noisePowerOnGainAccelZ
  //  Referenced by: '<S400>/AccelNoiseGainFunction'

  4.5,

  // Variable: ModelParam_noisePowerOnGainGyro
  //  Referenced by: '<S400>/GyroNoiseGainFunction'

  2.0,

  // Variable: ModelParam_noisePowerOnGainGyroZ
  //  Referenced by: '<S400>/GyroNoiseGainFunction'

  1.0,

  // Variable: ModelParam_noisePowerOnGainMag
  //  Referenced by: '<S400>/MagNoiseGainFunction'

  0.025,

  // Variable: ModelParam_noisePowerOnGainMagZ
  //  Referenced by: '<S400>/MagNoiseGainFunction'

  0.05,

  // Variable: ModelParam_rotorCm
  //  Referenced by: '<S7>/ModelParam.rotorCm'

  1.4232E-7,

  // Variable: ModelParam_rotorCt
  //  Referenced by: '<S7>/ModelParam.rotorCt'

  1.6575E-5,

  // Variable: ModelParam_uavCCm
  //  Referenced by: '<S7>/ModelParam.uavCCm'

  { 0.0035, 0.0039, 0.0034 },

  // Variable: ModelParam_uavCd
  //  Referenced by: '<S7>/ModelParam.uavCd'

  { 0.7095, 0.6342, 0.9 },

  // Variable: ModelParam_uavDearo
  //  Referenced by: '<S7>/ModelParam.uavDearo'

  0.12,

  // Variable: ModelParam_uavJ
  //  Referenced by: '<S185>/uavJ'

  { 0.01731, 0.0, 0.0, 0.0, 0.01977, 0.0, 0.0, 0.0, 0.03026 },

  // Variable: ModelParam_uavMass
  //  Referenced by: '<S185>/ModelParam.uavMass'

  2.0843,

  // Variable: ModelParam_uavR
  //  Referenced by: '<S185>/ModelParam.uavR'

  0.225,

  // Variable: ModelFailEnable
  //  Referenced by: '<S11>/ModelFailEnable'

  0,

  // Variable: ModelParam_uavMotNumbs
  //  Referenced by: '<S55>/ModelParam.uavMotNumbs'

  4,

  // Variable: ModelParam_uavType
  //  Referenced by:
  //    '<S7>/ModelParam.uavType'
  //    '<S11>/UAVType'

  3,

  // Mask Parameter: DrydenWindTurbulenceModelDiscre
  //  Referenced by: '<S155>/Medium//High Altitude'

  533.4,

  // Mask Parameter: DrydenWindTurbulenceModelDisc_j
  //  Referenced by: '<S116>/Medium//High Altitude'

  533.4,

  // Mask Parameter: DrydenWindTurbulenceModelDisc_k
  //  Referenced by: '<S129>/White Noise'

  { 23301.0, 23542.0, 82443.0, 33344.0 },

  // Mask Parameter: DrydenWindTurbulenceModelDisc_n
  //  Referenced by: '<S90>/White Noise'

  { 23341.0, 23342.0, 23343.0, 23344.0 },

  // Mask Parameter: DrydenWindTurbulenceModelDisc_a
  //  Referenced by:
  //    '<S119>/Constant1'
  //    '<S119>/Constant2'
  //    '<S119>/Constant3'
  //    '<S120>/Constant3'

  1.0,

  // Mask Parameter: DrydenWindTurbulenceModelDisc_m
  //  Referenced by:
  //    '<S80>/Constant1'
  //    '<S80>/Constant2'
  //    '<S80>/Constant3'
  //    '<S81>/Constant3'

  1.0,

  // Mask Parameter: WhiteNoise_Ts
  //  Referenced by: '<S129>/Constant1'

  0.01,

  // Mask Parameter: WhiteNoise_Ts_p
  //  Referenced by: '<S90>/Constant1'

  0.01,

  // Mask Parameter: DrydenWindTurbulenceModelDis_aw
  //  Referenced by: '<S136>/Probability of  Exceedance'

  3.0,

  // Mask Parameter: DrydenWindTurbulenceModelDisc_h
  //  Referenced by: '<S97>/Probability of  Exceedance'

  4.0,

  // Mask Parameter: DrydenWindTurbulenceModelDis_m3
  //  Referenced by: '<S63>/Windspeed at 20ft (6m)'

  2.0,

  // Mask Parameter: DrydenWindTurbulenceModelDis_mb
  //  Referenced by: '<S62>/Windspeed at 20ft (6m)'

  5.0,

  // Mask Parameter: WindShearModel_W_20
  //  Referenced by: '<S77>/Wind speed at reference height'

  2.0,

  // Mask Parameter: DrydenWindTurbulenceModelDisc_i
  //  Referenced by: '<S63>/Wind direction'

  0.0,

  // Mask Parameter: DrydenWindTurbulenceModelDisc_o
  //  Referenced by: '<S62>/Wind direction'

  1.0,

  // Mask Parameter: WindShearModel_Wdeg
  //  Referenced by: '<S77>/Wind Direction'

  1.0,

  // Mask Parameter: DrydenWindTurbulenceModelDisc_f
  //  Referenced by: '<S62>/Wingspan'

  1.0,

  // Mask Parameter: DrydenWindTurbulenceModelDis_az
  //  Referenced by: '<S63>/Wingspan'

  1.0,

  // Mask Parameter: ThreeaxisInertialMeasurementUni
  //  Referenced by: '<S423>/Measurement bias'

  { 0.0, 0.0, 0.0 },

  // Mask Parameter: ThreeaxisInertialMeasurementU_o
  //  Referenced by: '<S423>/Scale factors & Cross-coupling  errors'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Mask Parameter: DirectionCosineMatrixtoQuaterni
  //  Referenced by:
  //    '<S202>/If Warning//Error'
  //    '<S202>/Constant'

  1.0,

  // Mask Parameter: DirectionCosineMatrixtoQuater_p
  //  Referenced by:
  //    '<S240>/If Warning//Error'
  //    '<S240>/Constant'

  1.0,

  // Mask Parameter: DirectionCosineMatrixtoQuater_c
  //  Referenced by:
  //    '<S334>/If Warning//Error'
  //    '<S334>/Constant'

  1.0,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S171>/Constant'

  180.0,

  // Mask Parameter: CompareToConstant_const_n
  //  Referenced by: '<S169>/Constant'

  90.0,

  // Mask Parameter: CompareToConstant_const_ng
  //  Referenced by: '<S172>/Constant'

  180.0,

  // Mask Parameter: CompareToConstant_const_b
  //  Referenced by: '<S165>/Constant'

  180.0,

  // Mask Parameter: CompareToConstant_const_e
  //  Referenced by: '<S163>/Constant'

  90.0,

  // Mask Parameter: CompareToConstant_const_i
  //  Referenced by: '<S166>/Constant'

  180.0,

  // Mask Parameter: CompareToConstant_const_k
  //  Referenced by: '<S456>/Constant'

  180.0,

  // Mask Parameter: CompareToConstant_const_p
  //  Referenced by: '<S454>/Constant'

  90.0,

  // Mask Parameter: CompareToConstant_const_o
  //  Referenced by: '<S457>/Constant'

  180.0,

  // Mask Parameter: CompareToConstant_const_d
  //  Referenced by: '<S392>/Constant'

  180.0,

  // Mask Parameter: CompareToConstant_const_l
  //  Referenced by: '<S390>/Constant'

  90.0,

  // Mask Parameter: CompareToConstant_const_a
  //  Referenced by: '<S393>/Constant'

  180.0,

  // Mask Parameter: CompareToConstant_const_k3
  //  Referenced by: '<S386>/Constant'

  180.0,

  // Mask Parameter: CompareToConstant_const_dl
  //  Referenced by: '<S384>/Constant'

  90.0,

  // Mask Parameter: CompareToConstant_const_lc
  //  Referenced by: '<S387>/Constant'

  180.0,

  // Mask Parameter: ThreeaxisInertialMeasurementU_i
  //  Referenced by: '<S424>/Measurement bias'

  { 0.0, 0.0, 0.0 },

  // Mask Parameter: ThreeaxisInertialMeasurementU_f
  //  Referenced by: '<S424>/g-sensitive bias'

  { 0.0, 0.0, 0.0 },

  // Mask Parameter: ThreeaxisInertialMeasurementU_j
  //  Referenced by: '<S424>/Scale factors & Cross-coupling  errors '

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Mask Parameter: ThreeaxisInertialMeasurement_j5
  //  Referenced by: '<S423>/wl_ins'

  { 0.0, 0.0, 0.0 },

  // Mask Parameter: CustomVariableMass6DOFQuaternio
  //  Referenced by: '<S24>/High Gain Quaternion Normalization'

  1.0,

  // Mask Parameter: CheckAltitude_max
  //  Referenced by: '<S441>/max_val'

  850000.0,

  // Mask Parameter: CheckLatitude_max
  //  Referenced by: '<S442>/max_val'

  90.0,

  // Mask Parameter: CheckLongitude_max
  //  Referenced by: '<S443>/max_val'

  180.0,

  // Mask Parameter: Istimewithinmodellimits_max
  //  Referenced by: '<S445>/max_val'

  5.0,

  // Mask Parameter: CheckAltitude_min
  //  Referenced by: '<S441>/min_val'

  -1000.0,

  // Mask Parameter: CheckLatitude_min
  //  Referenced by: '<S442>/min_val'

  -90.0,

  // Mask Parameter: CheckLongitude_min
  //  Referenced by: '<S443>/min_val'

  -180.0,

  // Mask Parameter: Istimewithinmodellimits_min
  //  Referenced by: '<S445>/min_val'

  0.0,

  // Mask Parameter: FlatEarthtoLLA_psi
  //  Referenced by: '<S69>/ref_rotation'

  0.0,

  // Mask Parameter: FlatEarthtoLLA_psi_b
  //  Referenced by: '<S374>/ref_rotation'

  0.0,

  // Mask Parameter: WhiteNoise_pwr
  //  Referenced by: '<S129>/Constant'

  { 0.01, 0.01, 0.01, 0.01 },

  // Mask Parameter: WhiteNoise_pwr_d
  //  Referenced by: '<S90>/Constant'

  { 0.01, 0.01, 0.01, 0.01 },

  // Mask Parameter: DirectionCosineMatrixtoQuater_i
  //  Referenced by: '<S202>/If Warning//Error'

  4.4408920985006262E-16,

  // Mask Parameter: DirectionCosineMatrixtoQuate_i5
  //  Referenced by: '<S240>/If Warning//Error'

  4.4408920985006262E-16,

  // Mask Parameter: DirectionCosineMatrixtoQuater_b
  //  Referenced by: '<S334>/If Warning//Error'

  4.4408920985006262E-16,

  // Mask Parameter: ThreeaxisInertialMeasurementU_e
  //  Referenced by:
  //    '<S429>/2*zeta * wn'
  //    '<S429>/wn^2'

  190.0,

  // Mask Parameter: ThreeaxisInertialMeasurementU_m
  //  Referenced by:
  //    '<S440>/2*zeta * wn'
  //    '<S440>/wn^2'

  190.0,

  // Mask Parameter: ThreeaxisInertialMeasurementU_n
  //  Referenced by: '<S429>/2*zeta * wn'

  0.707,

  // Mask Parameter: ThreeaxisInertialMeasurement_jx
  //  Referenced by: '<S440>/2*zeta * wn'

  0.707,

  // Expression: 1
  //  Referenced by: '<S41>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S42>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S101>/Gain'

  1.0,

  // Expression: 1
  //  Referenced by: '<S109>/Gain'

  1.0,

  // Expression: 1
  //  Referenced by: '<S140>/Gain'

  1.0,

  // Expression: 1
  //  Referenced by: '<S148>/Gain'

  1.0,

  // Expression: -90
  //  Referenced by: '<S161>/Bias'

  -90.0,

  // Expression: -1
  //  Referenced by: '<S161>/Gain'

  -1.0,

  // Expression: +90
  //  Referenced by: '<S161>/Bias1'

  90.0,

  // Expression: 180
  //  Referenced by: '<S164>/Bias'

  180.0,

  // Expression: -180
  //  Referenced by: '<S164>/Bias1'

  -180.0,

  // Expression: 180
  //  Referenced by: '<S162>/Bias'

  180.0,

  // Expression: -180
  //  Referenced by: '<S162>/Bias1'

  -180.0,

  // Expression: -90
  //  Referenced by: '<S167>/Bias'

  -90.0,

  // Expression: -1
  //  Referenced by: '<S167>/Gain'

  -1.0,

  // Expression: +90
  //  Referenced by: '<S167>/Bias1'

  90.0,

  // Expression: 360
  //  Referenced by: '<S170>/Constant2'

  360.0,

  // Expression: 180
  //  Referenced by: '<S170>/Bias'

  180.0,

  // Expression: -180
  //  Referenced by: '<S170>/Bias1'

  -180.0,

  // Expression: 180
  //  Referenced by: '<S158>/Constant'

  180.0,

  // Expression: 0
  //  Referenced by: '<S158>/Constant1'

  0.0,

  // Expression: 360
  //  Referenced by: '<S168>/Constant2'

  360.0,

  // Expression: 180
  //  Referenced by: '<S168>/Bias'

  180.0,

  // Expression: -180
  //  Referenced by: '<S168>/Bias1'

  -180.0,

  // Expression: -90
  //  Referenced by: '<S382>/Bias'

  -90.0,

  // Expression: -1
  //  Referenced by: '<S382>/Gain'

  -1.0,

  // Expression: +90
  //  Referenced by: '<S382>/Bias1'

  90.0,

  // Expression: 180
  //  Referenced by: '<S385>/Bias'

  180.0,

  // Expression: -180
  //  Referenced by: '<S385>/Bias1'

  -180.0,

  // Expression: 180
  //  Referenced by: '<S383>/Bias'

  180.0,

  // Expression: -180
  //  Referenced by: '<S383>/Bias1'

  -180.0,

  // Expression: -90
  //  Referenced by: '<S388>/Bias'

  -90.0,

  // Expression: -1
  //  Referenced by: '<S388>/Gain'

  -1.0,

  // Expression: +90
  //  Referenced by: '<S388>/Bias1'

  90.0,

  // Expression: 360
  //  Referenced by: '<S391>/Constant2'

  360.0,

  // Expression: 180
  //  Referenced by: '<S391>/Bias'

  180.0,

  // Expression: -180
  //  Referenced by: '<S391>/Bias1'

  -180.0,

  // Expression: 180
  //  Referenced by: '<S379>/Constant'

  180.0,

  // Expression: 0
  //  Referenced by: '<S379>/Constant1'

  0.0,

  // Expression: 360
  //  Referenced by: '<S389>/Constant2'

  360.0,

  // Expression: 180
  //  Referenced by: '<S389>/Bias'

  180.0,

  // Expression: -180
  //  Referenced by: '<S389>/Bias1'

  -180.0,

  // Expression: -90
  //  Referenced by: '<S452>/Bias'

  -90.0,

  // Expression: -1
  //  Referenced by: '<S452>/Gain'

  -1.0,

  // Expression: +90
  //  Referenced by: '<S452>/Bias1'

  90.0,

  // Expression: 180
  //  Referenced by: '<S455>/Bias'

  180.0,

  // Expression: -180
  //  Referenced by: '<S455>/Bias1'

  -180.0,

  // Expression: 180
  //  Referenced by: '<S453>/Bias'

  180.0,

  // Expression: -180
  //  Referenced by: '<S453>/Bias1'

  -180.0,

  // Expression: ones(1,maxdef+1)
  //  Referenced by: '<S474>/pp[13]'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: 1
  //  Referenced by: '<S474>/Constant'

  1.0,

  // Expression: ones(1,maxdef+1)
  //  Referenced by: '<S475>/pp[13]'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: k
  //  Referenced by: '<S475>/k[13][13]'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.33333333333333331,
    0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.26666666666666666, 0.2, 0.0, -0.33333333333333331, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.25714285714285712, 0.22857142857142856,
    0.14285714285714285, 0.0, -0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.25396825396825395, 0.23809523809523808, 0.19047619047619047,
    0.1111111111111111, 0.0, -0.14285714285714285, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.25252525252525254, 0.24242424242424243, 0.21212121212121213,
    0.16161616161616163, 0.090909090909090912, 0.0, -0.1111111111111111, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.25174825174825177, 0.24475524475524477,
    0.22377622377622378, 0.1888111888111888, 0.13986013986013987,
    0.076923076923076927, 0.0, -0.090909090909090912, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.25128205128205128, 0.24615384615384617, 0.23076923076923078,
    0.20512820512820512, 0.16923076923076924, 0.12307692307692308,
    0.066666666666666666, 0.0, -0.076923076923076927, 0.0, 0.0, 0.0, 0.0,
    0.25098039215686274, 0.24705882352941178, 0.23529411764705882,
    0.21568627450980393, 0.18823529411764706, 0.15294117647058825,
    0.10980392156862745, 0.058823529411764705, 0.0, -0.066666666666666666, 0.0,
    0.0, 0.0, 0.25077399380804954, 0.24767801857585139, 0.23839009287925697,
    0.22291021671826625, 0.20123839009287925, 0.17337461300309598,
    0.13931888544891641, 0.099071207430340563, 0.052631578947368418, 0.0,
    -0.058823529411764705, 0.0, 0.0, 0.25062656641604009, 0.24812030075187969,
    0.24060150375939848, 0.22807017543859648, 0.21052631578947367,
    0.18796992481203006, 0.16040100250626566, 0.12781954887218044,
    0.090225563909774431, 0.047619047619047616, 0.0, -0.052631578947368418, 0.0,
    0.25051759834368531, 0.2484472049689441, 0.24223602484472051,
    0.2318840579710145, 0.21739130434782608, 0.19875776397515527,
    0.17598343685300208, 0.14906832298136646, 0.11801242236024845,
    0.082815734989648032, 0.043478260869565216, 0.0, -0.047619047619047616 },

  // Expression: 0
  //  Referenced by: '<S470>/bpp'

  0.0,

  // Expression: fm(2)
  //  Referenced by: '<S470>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S470>/Constant1'

  1.0,

  // Expression: ones(1,maxdef+1)
  //  Referenced by: '<S470>/Unit Delay1'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: 1
  //  Referenced by: '<S478>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S478>/Gain1'

  1.0,

  // Expression: 1
  //  Referenced by: '<S478>/Gain2'

  1.0,

  // Expression: 1
  //  Referenced by: '<S480>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S481>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S484>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S484>/Constant'

  0.0,

  // Expression: 0.5
  //  Referenced by: '<S484>/Switch'

  0.5,

  // Expression: k
  //  Referenced by: '<S484>/k[13][13]'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.33333333333333331,
    0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.26666666666666666, 0.2, 0.0, -0.33333333333333331, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.25714285714285712, 0.22857142857142856,
    0.14285714285714285, 0.0, -0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.25396825396825395, 0.23809523809523808, 0.19047619047619047,
    0.1111111111111111, 0.0, -0.14285714285714285, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.25252525252525254, 0.24242424242424243, 0.21212121212121213,
    0.16161616161616163, 0.090909090909090912, 0.0, -0.1111111111111111, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.25174825174825177, 0.24475524475524477,
    0.22377622377622378, 0.1888111888111888, 0.13986013986013987,
    0.076923076923076927, 0.0, -0.090909090909090912, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.25128205128205128, 0.24615384615384617, 0.23076923076923078,
    0.20512820512820512, 0.16923076923076924, 0.12307692307692308,
    0.066666666666666666, 0.0, -0.076923076923076927, 0.0, 0.0, 0.0, 0.0,
    0.25098039215686274, 0.24705882352941178, 0.23529411764705882,
    0.21568627450980393, 0.18823529411764706, 0.15294117647058825,
    0.10980392156862745, 0.058823529411764705, 0.0, -0.066666666666666666, 0.0,
    0.0, 0.0, 0.25077399380804954, 0.24767801857585139, 0.23839009287925697,
    0.22291021671826625, 0.20123839009287925, 0.17337461300309598,
    0.13931888544891641, 0.099071207430340563, 0.052631578947368418, 0.0,
    -0.058823529411764705, 0.0, 0.0, 0.25062656641604009, 0.24812030075187969,
    0.24060150375939848, 0.22807017543859648, 0.21052631578947367,
    0.18796992481203006, 0.16040100250626566, 0.12781954887218044,
    0.090225563909774431, 0.047619047619047616, 0.0, -0.052631578947368418, 0.0,
    0.25051759834368531, 0.2484472049689441, 0.24223602484472051,
    0.2318840579710145, 0.21739130434782608, 0.19875776397515527,
    0.17598343685300208, 0.14906832298136646, 0.11801242236024845,
    0.082815734989648032, 0.043478260869565216, 0.0, -0.047619047619047616 },

  // Expression: 0.5
  //  Referenced by: '<S484>/Switch1'

  0.5,

  // Expression: zeros(maxdef+1,maxdef+1)
  //  Referenced by: '<S468>/dp[13][13]'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 },

  // Expression: snorm
  //  Referenced by: '<S468>/snorm[169]'

  { 1.0, 1.0, 1.5, 2.5, 4.375, 7.875, 14.4375, 26.8125, 50.2734375, 94.9609375,
    180.42578125, 344.44921875, 660.1943359375, 0.0, 1.0, 1.7320508075688772,
    3.0618621784789726, 5.5339859052946636, 10.16658128379447,
    18.903124741692839, 35.469603513959669, 67.03125, 127.40346687426536,
    243.28607380714598, 466.38644692864216, 897.027461585248, 0.0, 0.0,
    0.8660254037844386, 1.9364916731037085, 3.9131189606246322,
    7.685213074469698, 14.944232269507859, 28.960809996010127,
    56.082367403612253, 108.65004161512664, 210.69192030396434,
    409.04797337487776, 795.12986069746626, 0.0, 0.0, 0.0, 0.79056941504209488,
    2.0916500663351889, 4.7062126492541738, 9.9628215130052382,
    20.478385136833914, 41.41957332816817, 82.982839993569982,
    165.28034045942309, 327.9680080977904, 649.22081265302029, 0.0, 0.0, 0.0,
    0.0, 0.739509972887452, 2.2185299186623553, 5.4568620790707172,
    12.348930874776167, 26.736219617835371, 56.375738371688975,
    116.87084953567937, 239.5139682335957, 486.91560948976519, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.7015607600201138, 2.3268138086232852, 6.1744654373880836,
    14.830586268334102, 33.69094768709671, 73.915615322315773,
    158.42359886807964, 334.02135244518831, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.671693289381396, 2.4218245962496963, 6.8652274293172546, 17.39793057467611,
    41.320085114855779, 94.117642301250768, 208.29891011946015, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.6472598492877496, 2.5068266169601756,
    7.5335249254737544, 20.043185339772048, 49.604352946160631,
    117.05388227149012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.6267066542400439, 2.5839777317091466, 8.1825961504123, 22.760038068635609,
    58.526941135745062, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.60904939217552367, 2.65478475211798, 8.8149248398872544,
    25.543251233216804, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.59362791713657326, 2.72034486491732, 9.4324706362690076, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.579979473934679,
    2.7814838439702596, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.56776801212685635 },

  // Expression: zeros(maxdef+1,maxdef+1)
  //  Referenced by: '<S468>/Unit Delay'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 },

  // Expression: snorm
  //  Referenced by: '<S468>/Unit Delay1'

  { 1.0, 1.0, 1.5, 2.5, 4.375, 7.875, 14.4375, 26.8125, 50.2734375, 94.9609375,
    180.42578125, 344.44921875, 660.1943359375, 0.0, 1.0, 1.7320508075688772,
    3.0618621784789726, 5.5339859052946636, 10.16658128379447,
    18.903124741692839, 35.469603513959669, 67.03125, 127.40346687426536,
    243.28607380714598, 466.38644692864216, 897.027461585248, 0.0, 0.0,
    0.8660254037844386, 1.9364916731037085, 3.9131189606246322,
    7.685213074469698, 14.944232269507859, 28.960809996010127,
    56.082367403612253, 108.65004161512664, 210.69192030396434,
    409.04797337487776, 795.12986069746626, 0.0, 0.0, 0.0, 0.79056941504209488,
    2.0916500663351889, 4.7062126492541738, 9.9628215130052382,
    20.478385136833914, 41.41957332816817, 82.982839993569982,
    165.28034045942309, 327.9680080977904, 649.22081265302029, 0.0, 0.0, 0.0,
    0.0, 0.739509972887452, 2.2185299186623553, 5.4568620790707172,
    12.348930874776167, 26.736219617835371, 56.375738371688975,
    116.87084953567937, 239.5139682335957, 486.91560948976519, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.7015607600201138, 2.3268138086232852, 6.1744654373880836,
    14.830586268334102, 33.69094768709671, 73.915615322315773,
    158.42359886807964, 334.02135244518831, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.671693289381396, 2.4218245962496963, 6.8652274293172546, 17.39793057467611,
    41.320085114855779, 94.117642301250768, 208.29891011946015, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.6472598492877496, 2.5068266169601756,
    7.5335249254737544, 20.043185339772048, 49.604352946160631,
    117.05388227149012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.6267066542400439, 2.5839777317091466, 8.1825961504123, 22.760038068635609,
    58.526941135745062, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.60904939217552367, 2.65478475211798, 8.8149248398872544,
    25.543251233216804, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.59362791713657326, 2.72034486491732, 9.4324706362690076, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.579979473934679,
    2.7814838439702596, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.56776801212685635 },

  // Expression: 0
  //  Referenced by: '<S468>/Merge1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S468>/Merge'

  0.0,

  // Expression: 1
  //  Referenced by: '<S497>/Gain'

  1.0,

  // Expression: zeros(maxdef+1,maxdef+1)
  //  Referenced by: '<S496>/zeros(maxdef+1,maxdef+1)'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(maxdef+1,maxdef+1)
  //  Referenced by: '<S469>/tc[13][13]'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(maxdef+1,maxdef+1)
  //  Referenced by: '<S469>/Unit Delay'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 },

  // Expression: c
  //  Referenced by: '<S469>/c[maxdef][maxdef]'

  { 0.0, 4796.3, -4923.1812154337767, -348.13372969305919, 1567.7782069699783,
    476.81266220996059, -379.95280730802608, -1925.9994708080098, 677.015625,
    -2777.3955778589848, 802.84404356358175, -0.0, -897.027461585248, -29438.2,
    -1493.5, -553.21702793749932, 477.34519742006415, -738.01423597380563,
    1510.1443691332956, 490.17081843985773, -564.73579492219744,
    -1026.3073234861042, 1162.5554452818549, -84.276768121585746,
    859.00074408724333, 238.53895820923987, -3666.75, 5221.6135695778939,
    1454.0566529540724, -424.8520036436218, 377.9611669867686,
    -564.2748966455755, 588.80275141860955, 122.87031082100349,
    550.88032526463667, 979.19751192412582, 760.28956611334615,
    -196.78080485867423, 1168.5974627754365, 3379.5, -7200.2750989111519,
    2369.4912112096977, 460.34857037901179, -244.03829105285917,
    35.496478698597684, -366.1554455056451, 302.54880643201608,
    -387.67518445861288, -383.35502092748504, 514.23173795698926,
    -263.46536505695531, -1071.2143408774834, 3970.3125, 4509.091715634092,
    460.96541356158167, -701.95776226208943, 51.543845110255411,
    70.577012458023447, 18.84719184984861, 21.610629030858291,
    240.25549754701245, -232.4675390409673, -583.93336104629464,
    110.89651920765574, 100.20640573355649, -1834.0875, 3660.9859202943885,
    1473.2553463758411, -664.98784733961486, -348.75290321372222,
    5.4020178521548763, 41.577814612708416, -67.084541316116585,
    41.191364575903528, 137.44365153994127, -24.792051068913466,
    -18.823528460250156, 145.80923708362209, 1001.9625000000001,
    1279.7415450126052, 1080.4679930854181, -1286.2002573289762,
    -154.97488304560835, 31.644667797276679, -47.220038243512143,
    -1.8770535629344738, -23.062804876033614, 7.5335249254737544,
    -84.1813784270426, -104.16914118693732, -11.705388227149014, 2190.58125,
    -2692.1429067095391, -205.6217509716719, 1068.9717041427305,
    185.23396312164252, 56.187635480231556, -7.2654737887490892,
    3.8188331107977227, 1.5040959701761054, -10.077513153665672,
    -23.729528836195669, -34.140057102953413, 17.558082340723519, 1216.6171875,
    596.578125, -947.792009121047, -128.40067731732134, -553.43974608919211,
    197.24679736884357, 79.636638180080155, -40.861273856450865,
    -1.3160839739040922, 5.1769198334919508, -2.9202632273297784,
    -22.918804583706862, 5.1086502466433608, 522.28515625, 1121.1505084935352,
    325.95012484537995, -265.54508797942395, 33.825443023013385,
    -444.72050946967653, -1.739793057467611, 65.541666851621656,
    -23.514197358553233, -6.3341136786254468, -5.2239256708018447,
    -5.44068972983464, -8.489223572642107, -360.8515625, -1484.0450502235904,
    42.138384060792873, 99.168204275653849, -58.435424767839685,
    133.04810758016839, -28.924059580399042, 44.095007747498506,
    19.638230760989519, -4.7786125538123647, -2.1370605016916637,
    -1.3339527900497614, -0.556296768794052, 1033.34765625, -652.941025700099,
    -940.81033876221875, 688.73281700535983, -191.61117458687659,
    95.054159320847774, -65.882349610875536, 4.9604352946160635,
    38.692064716680534, -1.762984967977451, 1.088137945966928,
    2.0299281587713764, 0.45421440970148508, -1320.388671875, -89.7027461585248,
    397.56493034873313, 779.06497518362437, -438.22404854078866,
    300.61921720066948, 20.829891011946017, 70.232329362894077,
    -23.410776454298027, -12.771625616608402, 1.8864941272538016,
    -2.5033354595732336, -0.0 },

  // Expression: cd
  //  Referenced by: '<S469>/cd[maxdef][maxdef]'

  { 0.0, -30.2, -51.268703904038766, 19.902104160113321, -2.2135943621178655,
    2.0333162567588938, 5.6709374225078513, 21.2817621083758, -26.8125,
    -38.221040062279606, 0.0, 0.0, -0.0, 7.0, 9.0, -14.982239485470789,
    -1.5491933384829668, 22.696089971622865, 17.675990071280303,
    -22.41634840426179, 14.480404998005064, 33.649420442167347,
    10.865004161512665, 21.069192030396437, 40.904797337487778, 0.0, -16.5,
    -10.738715006927039, 0.25980762113533157, -1.5811388300841898,
    7.9482702520737174, -0.0, -11.955385815606286, -16.382708109467131,
    -4.1419573328168173, -33.193135997427994, -33.056068091884619, 0.0,
    -64.922081265302026, 6.0, -17.452614417330143, 3.872983346207417,
    -8.6962635654630436, -2.5882849051060819, 7.3211487315857724,
    2.1827448316282871, -2.4697861749552334, 16.041731770701222,
    16.912721511506692, 11.687084953567938, 23.951396823359573,
    48.691560948976523, -3.5, -4.9805873147651978, -25.435273244060109,
    10.876580344942983, -2.9580398915498081, -0.42093645601206825,
    0.46536276172465707, -6.7919119811268924, -2.9661172536668206,
    3.3690947687096711, -7.3915615322315773, -0.0, -0.0, -2.3625,
    6.0999487702766819, -6.1481704595757591, 0.47062126492541739,
    2.6622359023948263, 0.9821850640281593, 0.87320127619581489,
    0.24218245962496965, -3.4326137146586273, -0.0, 4.1320085114855782, -0.0,
    0.0, -11.55, -9.45156237084642, -1.494423226950786, 15.940514420808382,
    -8.7309793265131486, 0.0, 0.80603194725767524, 0.12945196985754992,
    1.2534133084800878, -0.75335249254737546, -0.0, 4.9604352946160635, -0.0,
    -8.04375, -7.0939207027919338, -8.6882429988030374, 18.430546623150523,
    1.2348930874776167, -3.70467926243285, -2.1796421366247265,
    0.45308189450142466, 0.062670665424004388, 1.2919888658545733,
    -0.81825961504123, -0.0, 0.0, -5.02734375, 13.40625, -11.216473480722451,
    20.709786664084085, -2.6736219617835371, 5.9322345073336411,
    2.7460909717269022, -0.25068266169601755, 0.25068266169601755,
    0.12180987843510474, 0.530956950423596, -0.88149248398872548, 0.0,
    -9.49609375, -12.740346687426538, -0.0, 33.193135997427994,
    -22.55029534867559, 0.0, 5.2193791724028324, 0.0, -0.0, -0.1827148176526571,
    -0.0, -0.0, -0.0, 0.0, -0.0, -21.069192030396437, 33.056068091884619,
    -11.687084953567938, -14.783123064463155, -0.0, -2.0043185339772047,
    -1.63651923008246, -0.265478475211798, -0.0, -0.0579979473934679, 0.0, -0.0,
    0.0, -0.0, 0.0, -0.0, -15.842359886807964, 0.0, -0.0, -0.0,
    -0.88149248398872548, -0.0, -0.0579979473934679, -0.056776801212685635, 0.0,
    0.0, -0.0, 0.0, -48.691560948976523, -0.0, 0.0, -0.0, 0.0, -0.0, -0.0, -0.0,
    -0.056776801212685635 },

  // Expression: zeros(maxdef+1,maxdef+1)
  //  Referenced by: '<S496>/Unit Delay'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S466>/bt'

  0.0,

  // Expression: 0
  //  Referenced by: '<S466>/bp'

  0.0,

  // Expression: 0
  //  Referenced by: '<S466>/br'

  0.0,

  // Expression: 0
  //  Referenced by: '<S466>/bpp'

  0.0,

  // Expression: 1
  //  Referenced by: '<S472>/Constant1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S472>/Merge'

  0.0,

  // Expression: fm
  //  Referenced by: '<S467>/fm'

  { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0 },

  // Expression: 0
  //  Referenced by: '<S472>/Merge1'

  0.0,

  // Expression: fn
  //  Referenced by: '<S467>/fn'

  { 0.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0 },

  // Expression: 0
  //  Referenced by: '<S473>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S467>/Unit Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S467>/Unit Delay3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S467>/Unit Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S467>/Unit Delay4'

  0.0,

  // Expression: [0 0 0 0]
  //  Referenced by: '<S458>/bt,bp,br,bpp'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S458>/Unit Delay'

  0.0,

  // Expression: [0 0 0 0]
  //  Referenced by: '<S458>/Unit Delay2'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: 6378.137
  //  Referenced by: '<S459>/r'

  6378.137,

  // Expression: 1
  //  Referenced by: '<S459>/ct'

  1.0,

  // Expression: 0
  //  Referenced by: '<S459>/st'

  0.0,

  // Expression: 0
  //  Referenced by: '<S459>/sa'

  0.0,

  // Expression: 0
  //  Referenced by: '<S459>/ca'

  0.0,

  // Expression: 6356.7523142
  //  Referenced by: '<S459>/b'

  6356.7523142,

  // Expression: 6378.137
  //  Referenced by: '<S459>/a'

  6378.137,

  // Expression: 2
  //  Referenced by: '<S504>/Gain'

  2.0,

  // Expression: 1
  //  Referenced by: '<S506>/Constant'

  1.0,

  // Expression: (1:(maxdef-1))
  //  Referenced by: '<S507>/sp[11]'

  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 },

  // Expression: (1:(maxdef-1))
  //  Referenced by: '<S507>/cp[11]'

  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 },

  // Expression: maxdef-1
  //  Referenced by: '<S507>/For Iterator'

  11.0,

  // Expression: [1:maxdef-1]
  //  Referenced by: '<S507>/Constant'

  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 },

  // Expression: 0
  //  Referenced by: '<S507>/Unit Delay1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S507>/cp[m-1] sp[m-1]'

  1.0,

  // Expression: [1:maxdef-1]
  //  Referenced by: '<S507>/Constant1'

  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 },

  // Expression: [0 0 (1:(maxdef-1))]
  //  Referenced by: '<S460>/sp[13]'

  { 0.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 },

  // Expression: [1 1 (1:(maxdef-1))]
  //  Referenced by: '<S460>/cp[13]'

  { 1.0, 1.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 },

  // Expression: 1
  //  Referenced by: '<S460>/Gain'

  1.0,

  // Expression: 1
  //  Referenced by: '<S460>/Gain1'

  1.0,

  // Expression: 1
  //  Referenced by: '<S460>/cp[1]'

  1.0,

  // Expression: 0
  //  Referenced by: '<S460>/sp[1]'

  0.0,

  // Expression: 1E6
  //  Referenced by: '<S11>/Gain_clock'

  1.0E+6,

  // Expression: 0
  //  Referenced by: '<S429>/Integrator, Second-Order Limited'

  0.0,

  // Expression: 0
  //  Referenced by: '<S429>/Integrator, Second-Order Limited'

  0.0,

  // Expression: dtype_a
  //  Referenced by: '<S425>/Constant'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<S23>/1//2'

  0.5,

  // Expression: 2
  //  Referenced by: '<S28>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S31>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S26>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S32>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S27>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S30>/Gain'

  2.0,

  // Expression: 1
  //  Referenced by: '<S173>/Constant2'

  1.0,

  // Expression: R
  //  Referenced by: '<S173>/Constant1'

  6.378137E+6,

  // Expression: 1
  //  Referenced by: '<S176>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S178>/Constant'

  1.0,

  // Expression: F
  //  Referenced by: '<S177>/Constant'

  0.0033528106647474805,

  // Expression: 1
  //  Referenced by: '<S177>/f'

  1.0,

  // Expression: 1
  //  Referenced by: '<S173>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S173>/Constant3'

  1.0,

  // Expression: 360
  //  Referenced by: '<S164>/Constant2'

  360.0,

  // Expression: 180
  //  Referenced by: '<S157>/Constant'

  180.0,

  // Expression: 0
  //  Referenced by: '<S157>/Constant1'

  0.0,

  // Expression: 360
  //  Referenced by: '<S162>/Constant2'

  360.0,

  // Expression: 100000
  //  Referenced by: '<S61>/Saturation_1'

  100000.0,

  // Expression: 0
  //  Referenced by: '<S61>/Saturation_1'

  0.0,

  // Expression: juliandate(year,month,day)
  //  Referenced by: '<S76>/Julian Date'

  2.4532885E+6,

  // Expression: [1 0 0 0]
  //  Referenced by: '<S192>/Merge'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: [1 0 0 0]
  //  Referenced by: '<S191>/Merge'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Memory'

  0.0,

  // Expression: 1/4.2
  //  Referenced by: '<S55>/MotorFault3'

  0.23809523809523808,

  // Expression: [1,1,1]
  //  Referenced by: '<S61>/Constant_[1 1 1]'

  { 1.0, 1.0, 1.0 },

  // Expression: [-1,-1,-0.5]
  //  Referenced by: '<S61>/Uniform Random Number'

  { -1.0, -1.0, -0.5 },

  // Expression: [1,1,0.5]
  //  Referenced by: '<S61>/Uniform Random Number'

  { 1.0, 1.0, 0.5 },

  // Expression: [564565,6846798,46545]
  //  Referenced by: '<S61>/Uniform Random Number'

  { 564565.0, 6.846798E+6, 46545.0 },

  // Expression: -1
  //  Referenced by: '<S61>/Gain_-1'

  -1.0,

  // Expression: 10000
  //  Referenced by: '<S61>/Saturation_2'

  10000.0,

  // Expression: 0
  //  Referenced by: '<S61>/Saturation_2'

  0.0,

  // Expression: 5
  //  Referenced by: '<S61>/Constant_V'

  5.0,

  // Expression: max_height_low
  //  Referenced by: '<S154>/Limit Function 10ft to 1000ft'

  1000.0,

  // Expression: 10
  //  Referenced by: '<S154>/Limit Function 10ft to 1000ft'

  10.0,

  // Expression: max_height_low
  //  Referenced by: '<S137>/Limit Height h<1000ft'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S137>/Limit Height h<1000ft'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S137>/sigma_wg '

  0.1,

  // Expression: h_vec
  //  Referenced by: '<S136>/PreLook-Up Index Search  (altitude)'

  { 500.0, 1750.0, 3750.0, 7500.0, 15000.0, 25000.0, 35000.0, 45000.0, 55000.0,
    65000.0, 75000.0, 80000.0 },

  // Expression: [1:7]
  //  Referenced by: '<S136>/PreLook-Up Index Search  (prob of exceed)'

  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 },

  // Expression: sigma_vec'
  //  Referenced by: '<S136>/Medium//High Altitude Intensity'

  { 3.2, 2.2, 1.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.2, 3.6, 3.3,
    1.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.6, 6.9, 7.4, 6.7, 4.6, 2.7,
    0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 8.6, 9.6, 10.6, 10.1, 8.0, 6.6, 5.0, 4.2, 2.7,
    0.0, 0.0, 0.0, 11.8, 13.0, 16.0, 15.1, 11.6, 9.7, 8.1, 8.2, 7.9, 4.9, 3.2,
    2.1, 15.6, 17.6, 23.0, 23.6, 22.1, 20.0, 16.0, 15.1, 12.1, 7.9, 6.2, 5.1,
    18.7, 21.5, 28.4, 30.2, 30.7, 31.0, 25.2, 23.1, 17.5, 10.7, 8.4, 7.2 },

  // Expression: 0
  //  Referenced by: '<S129>/White Noise'

  0.0,

  // Computed Parameter: WhiteNoise_StdDev
  //  Referenced by: '<S129>/White Noise'

  1.0,

  // Expression: 1
  //  Referenced by: '<S126>/Lv'

  1.0,

  // Expression: 1
  //  Referenced by: '<S126>/Lw'

  1.0,

  // Expression: eye(3)
  //  Referenced by: '<S61>/Constant_DCM'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: max_height_low
  //  Referenced by: '<S115>/Limit Function 10ft to 1000ft'

  1000.0,

  // Expression: 10
  //  Referenced by: '<S115>/Limit Function 10ft to 1000ft'

  10.0,

  // Expression: max_height_low
  //  Referenced by: '<S98>/Limit Height h<1000ft'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S98>/Limit Height h<1000ft'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S98>/sigma_wg '

  0.1,

  // Expression: h_vec
  //  Referenced by: '<S97>/PreLook-Up Index Search  (altitude)'

  { 500.0, 1750.0, 3750.0, 7500.0, 15000.0, 25000.0, 35000.0, 45000.0, 55000.0,
    65000.0, 75000.0, 80000.0 },

  // Expression: [1:7]
  //  Referenced by: '<S97>/PreLook-Up Index Search  (prob of exceed)'

  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 },

  // Expression: sigma_vec'
  //  Referenced by: '<S97>/Medium//High Altitude Intensity'

  { 3.2, 2.2, 1.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.2, 3.6, 3.3,
    1.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.6, 6.9, 7.4, 6.7, 4.6, 2.7,
    0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 8.6, 9.6, 10.6, 10.1, 8.0, 6.6, 5.0, 4.2, 2.7,
    0.0, 0.0, 0.0, 11.8, 13.0, 16.0, 15.1, 11.6, 9.7, 8.1, 8.2, 7.9, 4.9, 3.2,
    2.1, 15.6, 17.6, 23.0, 23.6, 22.1, 20.0, 16.0, 15.1, 12.1, 7.9, 6.2, 5.1,
    18.7, 21.5, 28.4, 30.2, 30.7, 31.0, 25.2, 23.1, 17.5, 10.7, 8.4, 7.2 },

  // Expression: 0
  //  Referenced by: '<S90>/White Noise'

  0.0,

  // Computed Parameter: WhiteNoise_StdDev_h
  //  Referenced by: '<S90>/White Noise'

  1.0,

  // Expression: 1
  //  Referenced by: '<S87>/Lv'

  1.0,

  // Expression: 1
  //  Referenced by: '<S87>/Lw'

  1.0,

  // Expression: inf
  //  Referenced by: '<S77>/3ft-->inf'

  0.0,

  // Expression: 3
  //  Referenced by: '<S77>/3ft-->inf'

  3.0,

  // Expression: 1/z0
  //  Referenced by: '<S77>/h//z0'

  6.666666666666667,

  // Expression: 20/z0
  //  Referenced by: '<S77>/ref_height//z0'

  133.33333333333334,

  // Expression: 0
  //  Referenced by: '<S77>/Wdeg1'

  0.0,

  // Expression: [1,1,1,1,1,1,1,1]
  //  Referenced by: '<S286>/rotor_k_ct'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: 1
  //  Referenced by: '<S423>/Zero-Order Hold1'

  1.0,

  // Expression: 1
  //  Referenced by: '<S423>/Zero-Order Hold2'

  1.0,

  // Expression: 1
  //  Referenced by: '<S423>/Zero-Order Hold'

  1.0,

  // Expression: [0 0 0]
  //  Referenced by: '<S400>/center of gravity'

  { 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S423>/Zero-Order Hold4'

  1.0,

  // Expression: [1 -1 1]
  //  Referenced by: '<S423>/Gain'

  { 1.0, -1.0, 1.0 },

  // Expression: zeros(3,3)
  //  Referenced by: '<S1>/Constant_dI//dt'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S423>/Zero-Order Hold3'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<S425>/Switch'

  0.5,

  // Expression: a_sath
  //  Referenced by: '<S423>/Saturation'

  { 160.0, 160.0, 160.0 },

  // Expression: a_satl
  //  Referenced by: '<S423>/Saturation'

  { -160.0, -160.0, -160.0 },

  // Expression: -[0.1,0.1,0.2]
  //  Referenced by: '<S400>/Uniform Random Number5'

  { -0.1, -0.1, -0.2 },

  // Expression: [0.1,0.1,0.2]
  //  Referenced by: '<S400>/Uniform Random Number5'

  { 0.1, 0.1, 0.2 },

  // Expression: [12233,645554,678766]
  //  Referenced by: '<S400>/Uniform Random Number5'

  { 12233.0, 645554.0, 678766.0 },

  // Expression: 5
  //  Referenced by: '<S400>/Gain10'

  5.0,

  // Expression: 0
  //  Referenced by: '<S440>/Integrator, Second-Order Limited'

  0.0,

  // Expression: 0
  //  Referenced by: '<S440>/Integrator, Second-Order Limited'

  0.0,

  // Expression: dtype_g
  //  Referenced by: '<S438>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S424>/Zero-Order Hold'

  1.0,

  // Expression: 1
  //  Referenced by: '<S424>/Zero-Order Hold1'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<S438>/Switch'

  0.5,

  // Expression: g_sath
  //  Referenced by: '<S424>/Saturation'

  { 4.36, 4.36, 4.36 },

  // Expression: g_satl
  //  Referenced by: '<S424>/Saturation'

  { -4.36, -4.36, -4.36 },

  // Expression: -[0.01,0.01,0.01]
  //  Referenced by: '<S400>/Uniform Random Number1'

  { -0.01, -0.01, -0.01 },

  // Expression: [0.01,0.01,0.01]
  //  Referenced by: '<S400>/Uniform Random Number1'

  { 0.01, 0.01, 0.01 },

  // Expression: [3243,44556,2334343]
  //  Referenced by: '<S400>/Uniform Random Number1'

  { 3243.0, 44556.0, 2.334343E+6 },

  // Expression: 5
  //  Referenced by: '<S400>/Gain6'

  5.0,

  // Expression: epoch
  //  Referenced by: '<S450>/epoch'

  2015.0,

  // Expression: dyear
  //  Referenced by: '<S416>/Decimal Year'

  2017.8383561643836,

  // Expression: -1000
  //  Referenced by: '<S464>/otime'

  -1000.0,

  // Expression: 180
  //  Referenced by: '<S446>/Constant'

  180.0,

  // Expression: 360
  //  Referenced by: '<S455>/Constant2'

  360.0,

  // Expression: 0
  //  Referenced by: '<S446>/Constant1'

  0.0,

  // Expression: 360
  //  Referenced by: '<S453>/Constant2'

  360.0,

  // Expression: -1000
  //  Referenced by: '<S463>/olon'

  -1000.0,

  // Expression: -1000
  //  Referenced by: '<S462>/olat'

  -1000.0,

  // Expression: 0.001
  //  Referenced by: '<S416>/Gain'

  0.001,

  // Expression: -1000
  //  Referenced by: '<S462>/oalt'

  -1000.0,

  // Expression: 6371.2
  //  Referenced by: '<S450>/re'

  6371.2,

  // Expression: 1
  //  Referenced by: '<S400>/Gain_Mag'

  1.0,

  // Expression: 1E-5
  //  Referenced by: '<S400>/nT2Gauss'

  1.0E-5,

  // Expression: -[0.01,0.01,0.01]
  //  Referenced by: '<S400>/Uniform Random Number7'

  { -0.01, -0.01, -0.01 },

  // Expression: [0.01,0.01,0.01]
  //  Referenced by: '<S400>/Uniform Random Number7'

  { 0.01, 0.01, 0.01 },

  // Expression: [45465,454534,1234232]
  //  Referenced by: '<S400>/Uniform Random Number7'

  { 45465.0, 454534.0, 1.234232E+6 },

  // Expression: 2
  //  Referenced by: '<S400>/Gain11'

  2.0,

  // Expression: T0
  //  Referenced by: '<S412>/Sea Level  Temperature'

  288.15,

  // Expression: T0
  //  Referenced by: '<S70>/Sea Level  Temperature'

  288.15,

  // Expression: h_trop
  //  Referenced by: '<S70>/Limit  altitude  to troposhere'

  11000.0,

  // Expression: h0
  //  Referenced by: '<S70>/Limit  altitude  to troposhere'

  0.0,

  // Expression: L
  //  Referenced by: '<S70>/Lapse Rate'

  0.0065,

  // Expression: 1/T0
  //  Referenced by: '<S70>/1//T0'

  0.00347041471455839,

  // Expression: g/(L*R)
  //  Referenced by: '<S70>/Constant'

  5.2558756014667134,

  // Expression: rho0
  //  Referenced by: '<S70>/rho0'

  1.225,

  // Expression: h_trop
  //  Referenced by: '<S70>/Altitude of Troposphere'

  11000.0,

  // Expression: 0
  //  Referenced by: '<S70>/Limit  altitude  to Stratosphere'

  0.0,

  // Expression: h_trop-h_strat
  //  Referenced by: '<S70>/Limit  altitude  to Stratosphere'

  -9000.0,

  // Expression: g/R
  //  Referenced by: '<S70>/g//R'

  0.034163191409533639,

  // Expression: 1/2
  //  Referenced by: '<S403>/1//2rhoV^2'

  0.5,

  // Expression: 0
  //  Referenced by: '<S400>/Constant1'

  0.0,

  // Expression: -2
  //  Referenced by: '<S400>/Uniform Random Number'

  -2.0,

  // Expression: 2
  //  Referenced by: '<S400>/Uniform Random Number'

  2.0,

  // Expression: 15634
  //  Referenced by: '<S400>/Uniform Random Number'

  15634.0,

  // Expression: 0.2
  //  Referenced by: '<S400>/Gain5'

  0.2,

  // Expression: 0.3
  //  Referenced by: '<S410>/Constant2'

  0.3,

  // Expression: h_trop
  //  Referenced by: '<S412>/Limit  altitude  to troposhere'

  11000.0,

  // Expression: h0
  //  Referenced by: '<S412>/Limit  altitude  to troposhere'

  0.0,

  // Expression: L
  //  Referenced by: '<S412>/Lapse Rate'

  0.0065,

  // Expression: 1/T0
  //  Referenced by: '<S412>/1//T0'

  0.00347041471455839,

  // Expression: g/(L*R)
  //  Referenced by: '<S412>/Constant'

  5.2558756014667134,

  // Expression: P0
  //  Referenced by: '<S412>/P0'

  101325.0,

  // Expression: h_trop
  //  Referenced by: '<S412>/Altitude of Troposphere'

  11000.0,

  // Expression: 0
  //  Referenced by: '<S412>/Limit  altitude  to Stratosphere'

  0.0,

  // Expression: h_trop-h_strat
  //  Referenced by: '<S412>/Limit  altitude  to Stratosphere'

  -9000.0,

  // Expression: g/R
  //  Referenced by: '<S412>/g//R'

  0.034163191409533639,

  // Expression: 0.01
  //  Referenced by: '<S400>/Gain'

  0.01,

  // Expression: -1
  //  Referenced by: '<S400>/Uniform Random Number2'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S400>/Uniform Random Number2'

  1.0,

  // Expression: 45465
  //  Referenced by: '<S400>/Uniform Random Number2'

  45465.0,

  // Expression: 10
  //  Referenced by: '<S400>/Gain7'

  10.0,

  // Expression: -1
  //  Referenced by: '<S400>/Uniform Random Number4'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S400>/Uniform Random Number4'

  1.0,

  // Expression: 25634
  //  Referenced by: '<S400>/Uniform Random Number4'

  25634.0,

  // Expression: 0.01
  //  Referenced by: '<S400>/Gain9'

  0.01,

  // Expression: 0.5
  //  Referenced by: '<S411>/Constant'

  0.5,

  // Expression: 0.7
  //  Referenced by: '<S411>/Gain2'

  0.7,

  // Expression: 0.3
  //  Referenced by: '<S411>/Constant2'

  0.3,

  // Expression: 0.01
  //  Referenced by: '<S400>/Gain1'

  0.01,

  // Expression: 10
  //  Referenced by: '<S61>/Constant1'

  10.0,

  // Expression: 8191
  //  Referenced by: '<S400>/Constant'

  8191.0,

  // Expression: [1 0 0 0]
  //  Referenced by: '<S326>/Merge'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: 1E7
  //  Referenced by: '<S329>/Gain'

  1.0E+7,

  // Expression: 1E7
  //  Referenced by: '<S329>/Gain1'

  1.0E+7,

  // Expression: 1E3
  //  Referenced by: '<S329>/Gain3'

  1000.0,

  // Expression: 100
  //  Referenced by: '<S329>/Gain4'

  100.0,

  // Expression: 1/2
  //  Referenced by: '<S515>/1//2rhoV^2'

  0.5,

  // Expression: 2/1.225
  //  Referenced by: '<S329>/Gain2'

  1.6326530612244896,

  // Expression: 100
  //  Referenced by: '<S329>/Gain7'

  100.0,

  // Expression: 1000.0/9.80665
  //  Referenced by: '<S329>/Gain5'

  101.97162129779284,

  // Expression: [-1,-1,-2]
  //  Referenced by: '<S327>/Uniform Random Number5'

  { -1.0, -1.0, -2.0 },

  // Expression: [1,1,2]
  //  Referenced by: '<S327>/Uniform Random Number5'

  { 1.0, 1.0, 2.0 },

  // Expression: [1452,787,69]
  //  Referenced by: '<S327>/Uniform Random Number5'

  { 1452.0, 787.0, 69.0 },

  // Expression: 0.2
  //  Referenced by: '<S327>/BiasGain2'

  0.2,

  // Expression: 1
  //  Referenced by: '<S394>/Constant2'

  1.0,

  // Expression: R
  //  Referenced by: '<S394>/Constant1'

  6.378137E+6,

  // Expression: 1
  //  Referenced by: '<S397>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S399>/Constant'

  1.0,

  // Expression: F
  //  Referenced by: '<S398>/Constant'

  0.0033528106647474805,

  // Expression: 1
  //  Referenced by: '<S398>/f'

  1.0,

  // Expression: 1
  //  Referenced by: '<S394>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S394>/Constant3'

  1.0,

  // Expression: 360
  //  Referenced by: '<S385>/Constant2'

  360.0,

  // Expression: 1E7
  //  Referenced by: '<S327>/latScale'

  1.0E+7,

  // Expression: 180
  //  Referenced by: '<S378>/Constant'

  180.0,

  // Expression: 0
  //  Referenced by: '<S378>/Constant1'

  0.0,

  // Expression: 360
  //  Referenced by: '<S383>/Constant2'

  360.0,

  // Expression: 1E7
  //  Referenced by: '<S327>/lonScale'

  1.0E+7,

  // Expression: 100000
  //  Referenced by: '<S327>/Saturation'

  100000.0,

  // Expression: 0
  //  Referenced by: '<S327>/Saturation'

  0.0,

  // Expression: 1E3
  //  Referenced by: '<S327>/altScale'

  1000.0,

  // Expression: 100
  //  Referenced by: '<S327>/Gain6'

  100.0,

  // Expression: 100
  //  Referenced by: '<S327>/Gain8'

  100.0,

  // Computed Parameter: TransferFcn4_A
  //  Referenced by: '<S376>/Transfer Fcn4'

  -20.0,

  // Computed Parameter: TransferFcn4_C
  //  Referenced by: '<S376>/Transfer Fcn4'

  20.0,

  // Computed Parameter: TransferFcn1_A
  //  Referenced by: '<S376>/Transfer Fcn1'

  -20.0,

  // Computed Parameter: TransferFcn1_C
  //  Referenced by: '<S376>/Transfer Fcn1'

  20.0,

  // Computed Parameter: TransferFcn2_A
  //  Referenced by: '<S376>/Transfer Fcn2'

  -20.0,

  // Computed Parameter: TransferFcn2_C
  //  Referenced by: '<S376>/Transfer Fcn2'

  20.0,

  // Expression: 1E2
  //  Referenced by: '<S327>/VelScale'

  100.0,

  // Expression: 1E2
  //  Referenced by: '<S327>/VeScale'

  100.0,

  // Expression: 1E2
  //  Referenced by: '<S327>/AngleScale'

  100.0,

  // Expression: 1E3
  //  Referenced by: '<S327>/Gain1'

  1000.0,

  // Expression: 1E3
  //  Referenced by: '<S327>/Gain3'

  1000.0,

  // Expression: 1E3
  //  Referenced by: '<S327>/VeScale1'

  1000.0,

  // Expression: 1E3
  //  Referenced by: '<S327>/VelScale1'

  1000.0,

  // Expression: 1E5
  //  Referenced by: '<S327>/headMotAngle'

  100000.0,

  // Expression: 1E5
  //  Referenced by: '<S327>/headVehAngleScale'

  100000.0,

  // Expression: 100
  //  Referenced by: '<S400>/magDecGain'

  100.0,

  // Expression: 60/2/pi
  //  Referenced by: '<S11>/Gain'

  9.5492965855137211,

  // Expression: 1
  //  Referenced by: '<S11>/CopterID'

  1.0,

  // Expression: 1
  //  Referenced by: '<S24>/Constant'

  1.0,

  // Expression: [-1,-1,-2]
  //  Referenced by: '<S327>/Uniform Random Number4'

  { -1.0, -1.0, -2.0 },

  // Expression: [1,1,2]
  //  Referenced by: '<S327>/Uniform Random Number4'

  { 1.0, 1.0, 2.0 },

  // Expression: [5445,45433,33433]
  //  Referenced by: '<S327>/Uniform Random Number4'

  { 5445.0, 45433.0, 33433.0 },

  // Expression: 0.1
  //  Referenced by: '<S327>/BiasGain1'

  0.1,

  // Computed Parameter: Constant1_Value_ir
  //  Referenced by: '<S476>/Constant1'

  1,

  // Computed Parameter: Constant_Value_ao
  //  Referenced by: '<S477>/Constant'

  1,

  // Computed Parameter: Constant_Value_dt
  //  Referenced by: '<S475>/Constant'

  1,

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S486>/Constant'

  1,

  // Computed Parameter: Gain_Gain_id
  //  Referenced by: '<S486>/Gain'

  13,

  // Computed Parameter: Constant_Value_by
  //  Referenced by: '<S489>/Constant'

  1,

  // Computed Parameter: Gain_Gain_ngk
  //  Referenced by: '<S488>/Gain'

  13,

  // Computed Parameter: Constant_Value_k4
  //  Referenced by: '<S492>/Constant'

  1,

  // Computed Parameter: Constant1_Value_ob
  //  Referenced by: '<S492>/Constant1'

  1,

  // Computed Parameter: Constant1_Value_l
  //  Referenced by: '<S493>/Constant1'

  2,

  // Computed Parameter: Constant_Value_pw
  //  Referenced by: '<S491>/Constant'

  1,

  // Computed Parameter: Constant1_Value_f
  //  Referenced by: '<S490>/Constant1'

  1,

  // Computed Parameter: Gain_Gain_bi
  //  Referenced by: '<S490>/Gain'

  13,

  // Computed Parameter: Constant1_Value_lt
  //  Referenced by: '<S494>/Constant1'

  2,

  // Computed Parameter: Constant_Value_b2
  //  Referenced by: '<S468>/Constant'

  1,

  // Computed Parameter: Constant_Value_kp
  //  Referenced by: '<S485>/Constant'

  1,

  // Computed Parameter: Gain_Gain_lf
  //  Referenced by: '<S485>/Gain'

  13,

  // Computed Parameter: Constant_Value_h3
  //  Referenced by: '<S495>/Constant'

  1,

  // Computed Parameter: Constant1_Value_p
  //  Referenced by: '<S495>/Constant1'

  1,

  // Computed Parameter: Constant_Value_ex
  //  Referenced by: '<S497>/Constant'

  1,

  // Computed Parameter: tc_old_Threshold
  //  Referenced by: '<S496>/tc_old'

  1,

  // Computed Parameter: Constant_Value_h1y
  //  Referenced by: '<S467>/Constant'

  1,

  // Computed Parameter: Constant1_Value_jl
  //  Referenced by: '<S467>/Constant1'

  1,

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S466>/Constant'

  1,

  // Computed Parameter: Constant_Value_aoh
  //  Referenced by: '<S471>/Constant'

  1,

  // Computed Parameter: Gain_Gain_a1
  //  Referenced by: '<S471>/Gain'

  13,

  // Computed Parameter: Constant_Value_kg
  //  Referenced by: '<S473>/Constant'

  1,

  // Computed Parameter: ForIterator_IterationLimit_n
  //  Referenced by: '<S458>/For Iterator'

  12,

  // Computed Parameter: Constant_Value_o2
  //  Referenced by: '<S458>/Constant'

  1,

  // Computed Parameter: arn_Threshold
  //  Referenced by: '<S458>/ar(n)'

  1,

  // Computed Parameter: FaultID_Value
  //  Referenced by: '<S185>/FaultID'

  123457,

  // Computed Parameter: FaultID1_Value
  //  Referenced by: '<S185>/FaultID1'

  123458,

  // Computed Parameter: FaultID2_Value
  //  Referenced by: '<S185>/FaultID2'

  123459,

  // Computed Parameter: FaultID_Value_f
  //  Referenced by: '<S295>/FaultID'

  123450,

  // Computed Parameter: FaultID1_Value_f
  //  Referenced by: '<S295>/FaultID1'

  123549,

  // Computed Parameter: FaultID_Value_i
  //  Referenced by: '<S55>/FaultID'

  123540,

  // Computed Parameter: FaultID1_Value_i
  //  Referenced by: '<S55>/FaultID1'

  123541,

  // Computed Parameter: FaultID2_Value_n
  //  Referenced by: '<S55>/FaultID2'

  123542,

  // Computed Parameter: FaultID3_Value
  //  Referenced by: '<S55>/FaultID3'

  123543,

  // Computed Parameter: FaultID4_Value
  //  Referenced by: '<S61>/FaultID4'

  123548,

  // Computed Parameter: FaultID_Value_g
  //  Referenced by: '<S61>/FaultID'

  123544,

  // Computed Parameter: FaultID1_Value_m
  //  Referenced by: '<S61>/FaultID1'

  123545,

  // Computed Parameter: FaultID2_Value_g
  //  Referenced by: '<S61>/FaultID2'

  123546,

  // Computed Parameter: FaultID3_Value_g
  //  Referenced by: '<S61>/FaultID3'

  123547,

  // Computed Parameter: FaultID_Value_p
  //  Referenced by: '<S286>/FaultID'

  123451,

  // Computed Parameter: FaultID_Value_h
  //  Referenced by: '<S400>/FaultID'

  123452,

  // Computed Parameter: FaultID1_Value_d
  //  Referenced by: '<S400>/FaultID1'

  123453,

  // Computed Parameter: FaultID2_Value_ni
  //  Referenced by: '<S400>/FaultID2'

  123455,

  // Computed Parameter: FaultID3_Value_h
  //  Referenced by: '<S400>/FaultID3'

  123454,

  // Computed Parameter: FaultID_Value_k
  //  Referenced by: '<S327>/FaultID'

  123456,

  // Computed Parameter: MediumHighAltitudeIntensity_max
  //  Referenced by: '<S136>/Medium//High Altitude Intensity'

  { 11U, 6U },

  // Computed Parameter: MediumHighAltitudeIntensity_m_o
  //  Referenced by: '<S97>/Medium//High Altitude Intensity'

  { 11U, 6U },

  // Start of '<S334>/If Warning//Error'
  {
    // Expression: 0
    //  Referenced by: '<S360>/Constant1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S359>/Constant1'

    0.0,

    // Expression: -1
    //  Referenced by: '<S362>/Bias'

    -1.0,

    // Expression: -eye(3)
    //  Referenced by: '<S361>/Bias1'

    { -1.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -1.0 }
  }
  ,

  // End of '<S334>/If Warning//Error'

  // Start of '<S326>/Negative Trace'
  {
    // Expression: 1
    //  Referenced by: '<S349>/Constant'

    1.0,

    // Expression: 0.5
    //  Referenced by: '<S337>/Gain'

    0.5,

    // Expression: 0.5
    //  Referenced by: '<S348>/Constant1'

    0.5,

    // Expression: [0 1]
    //  Referenced by: '<S348>/Constant2'

    { 0.0, 1.0 },

    // Expression: 1
    //  Referenced by: '<S337>/Gain1'

    1.0,

    // Expression: 1
    //  Referenced by: '<S337>/Gain3'

    1.0,

    // Expression: 1
    //  Referenced by: '<S337>/Gain4'

    1.0,

    // Expression: 1
    //  Referenced by: '<S354>/Constant'

    1.0,

    // Expression: 0.5
    //  Referenced by: '<S338>/Gain'

    0.5,

    // Expression: 0.5
    //  Referenced by: '<S353>/Constant1'

    0.5,

    // Expression: [0 1]
    //  Referenced by: '<S353>/Constant2'

    { 0.0, 1.0 },

    // Expression: 1
    //  Referenced by: '<S338>/Gain1'

    1.0,

    // Expression: 1
    //  Referenced by: '<S338>/Gain2'

    1.0,

    // Expression: 1
    //  Referenced by: '<S338>/Gain3'

    1.0,

    // Expression: 1
    //  Referenced by: '<S344>/Constant'

    1.0,

    // Expression: 0.5
    //  Referenced by: '<S336>/Gain'

    0.5,

    // Expression: 0.5
    //  Referenced by: '<S343>/Constant1'

    0.5,

    // Expression: [0 1]
    //  Referenced by: '<S343>/Constant2'

    { 0.0, 1.0 },

    // Expression: 1
    //  Referenced by: '<S336>/Gain1'

    1.0,

    // Expression: 1
    //  Referenced by: '<S336>/Gain2'

    1.0,

    // Expression: 1
    //  Referenced by: '<S336>/Gain3'

    1.0
  }
  ,

  // End of '<S326>/Negative Trace'

  // Start of '<S326>/Positive Trace'
  {
    // Expression: 1
    //  Referenced by: '<S333>/Constant'

    1.0,

    // Expression: 0.5
    //  Referenced by: '<S333>/Gain'

    0.5,

    // Expression: 2
    //  Referenced by: '<S333>/Gain1'

    2.0
  }
  ,

  // End of '<S326>/Positive Trace'

  // Start of '<S300>/MotorNonlinearDynamic8'
  {
    // Expression: 0.95
    //  Referenced by: '<S309>/Signal_Saturation'

    0.95,

    // Expression: 0
    //  Referenced by: '<S309>/Signal_Saturation'

    0.0
  }
  ,

  // End of '<S300>/MotorNonlinearDynamic8'

  // Start of '<S300>/MotorNonlinearDynamic7'
  {
    // Expression: 0.95
    //  Referenced by: '<S308>/Signal_Saturation'

    0.95,

    // Expression: 0
    //  Referenced by: '<S308>/Signal_Saturation'

    0.0
  }
  ,

  // End of '<S300>/MotorNonlinearDynamic7'

  // Start of '<S300>/MotorNonlinearDynamic6'
  {
    // Expression: 0.95
    //  Referenced by: '<S307>/Signal_Saturation'

    0.95,

    // Expression: 0
    //  Referenced by: '<S307>/Signal_Saturation'

    0.0
  }
  ,

  // End of '<S300>/MotorNonlinearDynamic6'

  // Start of '<S300>/MotorNonlinearDynamic5'
  {
    // Expression: 0.95
    //  Referenced by: '<S306>/Signal_Saturation'

    0.95,

    // Expression: 0
    //  Referenced by: '<S306>/Signal_Saturation'

    0.0
  }
  ,

  // End of '<S300>/MotorNonlinearDynamic5'

  // Start of '<S300>/MotorNonlinearDynamic4'
  {
    // Expression: 0.95
    //  Referenced by: '<S305>/Signal_Saturation'

    0.95,

    // Expression: 0
    //  Referenced by: '<S305>/Signal_Saturation'

    0.0
  }
  ,

  // End of '<S300>/MotorNonlinearDynamic4'

  // Start of '<S300>/MotorNonlinearDynamic3'
  {
    // Expression: 0.95
    //  Referenced by: '<S304>/Signal_Saturation'

    0.95,

    // Expression: 0
    //  Referenced by: '<S304>/Signal_Saturation'

    0.0
  }
  ,

  // End of '<S300>/MotorNonlinearDynamic3'

  // Start of '<S300>/MotorNonlinearDynamic2'
  {
    // Expression: 0.95
    //  Referenced by: '<S303>/Signal_Saturation'

    0.95,

    // Expression: 0
    //  Referenced by: '<S303>/Signal_Saturation'

    0.0
  }
  ,

  // End of '<S300>/MotorNonlinearDynamic2'

  // Start of '<S300>/MotorNonlinearDynamic1'
  {
    // Expression: 0.95
    //  Referenced by: '<S302>/Signal_Saturation'

    0.95,

    // Expression: 0
    //  Referenced by: '<S302>/Signal_Saturation'

    0.0
  }
  ,

  // End of '<S300>/MotorNonlinearDynamic1'

  // Start of '<S240>/If Warning//Error'
  {
    // Expression: 0
    //  Referenced by: '<S266>/Constant1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S265>/Constant1'

    0.0,

    // Expression: -1
    //  Referenced by: '<S268>/Bias'

    -1.0,

    // Expression: -eye(3)
    //  Referenced by: '<S267>/Bias1'

    { -1.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -1.0 }
  }
  ,

  // End of '<S240>/If Warning//Error'

  // Start of '<S192>/Negative Trace'
  {
    // Expression: 1
    //  Referenced by: '<S255>/Constant'

    1.0,

    // Expression: 0.5
    //  Referenced by: '<S243>/Gain'

    0.5,

    // Expression: 0.5
    //  Referenced by: '<S254>/Constant1'

    0.5,

    // Expression: [0 1]
    //  Referenced by: '<S254>/Constant2'

    { 0.0, 1.0 },

    // Expression: 1
    //  Referenced by: '<S243>/Gain1'

    1.0,

    // Expression: 1
    //  Referenced by: '<S243>/Gain3'

    1.0,

    // Expression: 1
    //  Referenced by: '<S243>/Gain4'

    1.0,

    // Expression: 1
    //  Referenced by: '<S260>/Constant'

    1.0,

    // Expression: 0.5
    //  Referenced by: '<S244>/Gain'

    0.5,

    // Expression: 0.5
    //  Referenced by: '<S259>/Constant1'

    0.5,

    // Expression: [0 1]
    //  Referenced by: '<S259>/Constant2'

    { 0.0, 1.0 },

    // Expression: 1
    //  Referenced by: '<S244>/Gain1'

    1.0,

    // Expression: 1
    //  Referenced by: '<S244>/Gain2'

    1.0,

    // Expression: 1
    //  Referenced by: '<S244>/Gain3'

    1.0,

    // Expression: 1
    //  Referenced by: '<S250>/Constant'

    1.0,

    // Expression: 0.5
    //  Referenced by: '<S242>/Gain'

    0.5,

    // Expression: 0.5
    //  Referenced by: '<S249>/Constant1'

    0.5,

    // Expression: [0 1]
    //  Referenced by: '<S249>/Constant2'

    { 0.0, 1.0 },

    // Expression: 1
    //  Referenced by: '<S242>/Gain1'

    1.0,

    // Expression: 1
    //  Referenced by: '<S242>/Gain2'

    1.0,

    // Expression: 1
    //  Referenced by: '<S242>/Gain3'

    1.0
  }
  ,

  // End of '<S192>/Negative Trace'

  // Start of '<S192>/Positive Trace'
  {
    // Expression: 1
    //  Referenced by: '<S239>/Constant'

    1.0,

    // Expression: 0.5
    //  Referenced by: '<S239>/Gain'

    0.5,

    // Expression: 2
    //  Referenced by: '<S239>/Gain1'

    2.0
  }
  ,

  // End of '<S192>/Positive Trace'

  // Start of '<S202>/If Warning//Error'
  {
    // Expression: 0
    //  Referenced by: '<S228>/Constant1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S227>/Constant1'

    0.0,

    // Expression: -1
    //  Referenced by: '<S230>/Bias'

    -1.0,

    // Expression: -eye(3)
    //  Referenced by: '<S229>/Bias1'

    { -1.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -1.0 }
  }
  ,

  // End of '<S202>/If Warning//Error'

  // Start of '<S191>/Negative Trace'
  {
    // Expression: 1
    //  Referenced by: '<S217>/Constant'

    1.0,

    // Expression: 0.5
    //  Referenced by: '<S205>/Gain'

    0.5,

    // Expression: 0.5
    //  Referenced by: '<S216>/Constant1'

    0.5,

    // Expression: [0 1]
    //  Referenced by: '<S216>/Constant2'

    { 0.0, 1.0 },

    // Expression: 1
    //  Referenced by: '<S205>/Gain1'

    1.0,

    // Expression: 1
    //  Referenced by: '<S205>/Gain3'

    1.0,

    // Expression: 1
    //  Referenced by: '<S205>/Gain4'

    1.0,

    // Expression: 1
    //  Referenced by: '<S222>/Constant'

    1.0,

    // Expression: 0.5
    //  Referenced by: '<S206>/Gain'

    0.5,

    // Expression: 0.5
    //  Referenced by: '<S221>/Constant1'

    0.5,

    // Expression: [0 1]
    //  Referenced by: '<S221>/Constant2'

    { 0.0, 1.0 },

    // Expression: 1
    //  Referenced by: '<S206>/Gain1'

    1.0,

    // Expression: 1
    //  Referenced by: '<S206>/Gain2'

    1.0,

    // Expression: 1
    //  Referenced by: '<S206>/Gain3'

    1.0,

    // Expression: 1
    //  Referenced by: '<S212>/Constant'

    1.0,

    // Expression: 0.5
    //  Referenced by: '<S204>/Gain'

    0.5,

    // Expression: 0.5
    //  Referenced by: '<S211>/Constant1'

    0.5,

    // Expression: [0 1]
    //  Referenced by: '<S211>/Constant2'

    { 0.0, 1.0 },

    // Expression: 1
    //  Referenced by: '<S204>/Gain1'

    1.0,

    // Expression: 1
    //  Referenced by: '<S204>/Gain2'

    1.0,

    // Expression: 1
    //  Referenced by: '<S204>/Gain3'

    1.0
  }
  ,

  // End of '<S191>/Negative Trace'

  // Start of '<S191>/Positive Trace'
  {
    // Expression: 1
    //  Referenced by: '<S201>/Constant'

    1.0,

    // Expression: 0.5
    //  Referenced by: '<S201>/Gain'

    0.5,

    // Expression: 2
    //  Referenced by: '<S201>/Gain1'

    2.0
  }
  ,

  // End of '<S191>/Positive Trace'

  // Start of '<S125>/Interpolate  velocities'
  {
    // Expression: max_height_low
    //  Referenced by: '<S146>/max_height_low'

    1000.0,

    // Expression: min_height_high
    //  Referenced by: '<S146>/min_height_high'

    2000.0
  }
  ,

  // End of '<S125>/Interpolate  velocities'

  // Start of '<S124>/Interpolate  rates'
  {
    // Expression: max_height_low
    //  Referenced by: '<S138>/max_height_low'

    1000.0,

    // Expression: min_height_high
    //  Referenced by: '<S138>/min_height_high'

    2000.0
  }
  ,

  // End of '<S124>/Interpolate  rates'

  // Start of '<S120>/Hwgw(z)'
  {
    // Expression: 0
    //  Referenced by: '<S135>/wgw'

    0.0,

    // Expression: 2*dt
    //  Referenced by: '<S135>/2'

    0.02,

    // Expression: 1
    //  Referenced by: '<S135>/Constant'

    1.0,

    // Expression: dt
    //  Referenced by: '<S135>/dt'

    0.01,

    // Expression: 0
    //  Referenced by: '<S135>/Unit Delay'

    0.0
  }
  ,

  // End of '<S120>/Hwgw(z)'

  // Start of '<S120>/Hvgw(z)'
  {
    // Expression: 0
    //  Referenced by: '<S134>/vgw'

    0.0,

    // Expression: 2*dt
    //  Referenced by: '<S134>/2'

    0.02,

    // Expression: 1
    //  Referenced by: '<S134>/Constant'

    1.0,

    // Expression: dt
    //  Referenced by: '<S134>/dt'

    0.01,

    // Expression: 0
    //  Referenced by: '<S134>/Unit Delay'

    0.0
  }
  ,

  // End of '<S120>/Hvgw(z)'

  // Start of '<S120>/Hugw(z)'
  {
    // Expression: 0
    //  Referenced by: '<S133>/ugw'

    0.0,

    // Expression: 2*dt
    //  Referenced by: '<S133>/2'

    0.02,

    // Expression: 1
    //  Referenced by: '<S133>/Constant'

    1.0,

    // Expression: dt
    //  Referenced by: '<S133>/dt'

    0.01,

    // Expression: 0
    //  Referenced by: '<S133>/Unit Delay'

    0.0
  }
  ,

  // End of '<S120>/Hugw(z)'

  // Start of '<S119>/Hrgw'
  {
    // Expression: 0
    //  Referenced by: '<S132>/rgw'

    0.0,

    // Expression: 1
    //  Referenced by: '<S132>/Constant'

    1.0,

    // Expression: 3/pi
    //  Referenced by: '<S132>/dt1'

    0.954929658551372,

    // Expression: dt
    //  Referenced by: '<S132>/dt'

    0.01,

    // Expression: 0
    //  Referenced by: '<S132>/Unit Delay'

    0.0,

    // Expression: 0
    //  Referenced by: '<S132>/Unit Delay1'

    0.0
  }
  ,

  // End of '<S119>/Hrgw'

  // Start of '<S119>/Hqgw'
  {
    // Expression: 0
    //  Referenced by: '<S131>/qgw'

    0.0,

    // Expression: 1
    //  Referenced by: '<S131>/Constant'

    1.0,

    // Expression: 4/pi
    //  Referenced by: '<S131>/dt1'

    1.2732395447351628,

    // Expression: dt
    //  Referenced by: '<S131>/dt'

    0.01,

    // Expression: 0
    //  Referenced by: '<S131>/Unit Delay'

    0.0,

    // Expression: 0
    //  Referenced by: '<S131>/Unit Delay1'

    0.0
  }
  ,

  // End of '<S119>/Hqgw'

  // Start of '<S119>/Hpgw'
  {
    // Expression: 0
    //  Referenced by: '<S130>/pgw'

    0.0,

    // Expression: 2.6
    //  Referenced by: '<S130>/Constant2'

    2.6,

    // Expression: 2*dt
    //  Referenced by: '<S130>/2'

    0.02,

    // Expression: 1
    //  Referenced by: '<S130>/Constant'

    1.0,

    // Expression: 0.95
    //  Referenced by: '<S130>/Constant1'

    0.95,

    // Expression: 1/3
    //  Referenced by: '<S130>/Constant3'

    0.33333333333333331,

    // Expression: dt
    //  Referenced by: '<S130>/dt'

    0.01,

    // Expression: 0
    //  Referenced by: '<S130>/Unit Delay'

    0.0
  }
  ,

  // End of '<S119>/Hpgw'

  // Start of '<S86>/Interpolate  velocities'
  {
    // Expression: max_height_low
    //  Referenced by: '<S107>/max_height_low'

    1000.0,

    // Expression: min_height_high
    //  Referenced by: '<S107>/min_height_high'

    2000.0
  }
  ,

  // End of '<S86>/Interpolate  velocities'

  // Start of '<S85>/Interpolate  rates'
  {
    // Expression: max_height_low
    //  Referenced by: '<S99>/max_height_low'

    1000.0,

    // Expression: min_height_high
    //  Referenced by: '<S99>/min_height_high'

    2000.0
  }
  ,

  // End of '<S85>/Interpolate  rates'

  // Start of '<S81>/Hwgw(z)'
  {
    // Expression: 0
    //  Referenced by: '<S96>/wgw'

    0.0,

    // Expression: 2*dt
    //  Referenced by: '<S96>/2'

    0.02,

    // Expression: 1
    //  Referenced by: '<S96>/Constant'

    1.0,

    // Expression: dt
    //  Referenced by: '<S96>/dt'

    0.01,

    // Expression: 0
    //  Referenced by: '<S96>/Unit Delay'

    0.0
  }
  ,

  // End of '<S81>/Hwgw(z)'

  // Start of '<S81>/Hvgw(z)'
  {
    // Expression: 0
    //  Referenced by: '<S95>/vgw'

    0.0,

    // Expression: 2*dt
    //  Referenced by: '<S95>/2'

    0.02,

    // Expression: 1
    //  Referenced by: '<S95>/Constant'

    1.0,

    // Expression: dt
    //  Referenced by: '<S95>/dt'

    0.01,

    // Expression: 0
    //  Referenced by: '<S95>/Unit Delay'

    0.0
  }
  ,

  // End of '<S81>/Hvgw(z)'

  // Start of '<S81>/Hugw(z)'
  {
    // Expression: 0
    //  Referenced by: '<S94>/ugw'

    0.0,

    // Expression: 2*dt
    //  Referenced by: '<S94>/2'

    0.02,

    // Expression: 1
    //  Referenced by: '<S94>/Constant'

    1.0,

    // Expression: dt
    //  Referenced by: '<S94>/dt'

    0.01,

    // Expression: 0
    //  Referenced by: '<S94>/Unit Delay'

    0.0
  }
  ,

  // End of '<S81>/Hugw(z)'

  // Start of '<S80>/Hrgw'
  {
    // Expression: 0
    //  Referenced by: '<S93>/rgw'

    0.0,

    // Expression: 1
    //  Referenced by: '<S93>/Constant'

    1.0,

    // Expression: 3/pi
    //  Referenced by: '<S93>/dt1'

    0.954929658551372,

    // Expression: dt
    //  Referenced by: '<S93>/dt'

    0.01,

    // Expression: 0
    //  Referenced by: '<S93>/Unit Delay'

    0.0,

    // Expression: 0
    //  Referenced by: '<S93>/Unit Delay1'

    0.0
  }
  ,

  // End of '<S80>/Hrgw'

  // Start of '<S80>/Hqgw'
  {
    // Expression: 0
    //  Referenced by: '<S92>/qgw'

    0.0,

    // Expression: 1
    //  Referenced by: '<S92>/Constant'

    1.0,

    // Expression: 4/pi
    //  Referenced by: '<S92>/dt1'

    1.2732395447351628,

    // Expression: dt
    //  Referenced by: '<S92>/dt'

    0.01,

    // Expression: 0
    //  Referenced by: '<S92>/Unit Delay'

    0.0,

    // Expression: 0
    //  Referenced by: '<S92>/Unit Delay1'

    0.0
  }
  ,

  // End of '<S80>/Hqgw'

  // Start of '<S80>/Hpgw'
  {
    // Expression: 0
    //  Referenced by: '<S91>/pgw'

    0.0,

    // Expression: 2.6
    //  Referenced by: '<S91>/Constant2'

    2.6,

    // Expression: 2*dt
    //  Referenced by: '<S91>/2'

    0.02,

    // Expression: 1
    //  Referenced by: '<S91>/Constant'

    1.0,

    // Expression: 0.95
    //  Referenced by: '<S91>/Constant1'

    0.95,

    // Expression: 1/3
    //  Referenced by: '<S91>/Constant3'

    0.33333333333333331,

    // Expression: dt
    //  Referenced by: '<S91>/dt'

    0.01,

    // Expression: 0
    //  Referenced by: '<S91>/Unit Delay'

    0.0
  }
  // End of '<S80>/Hpgw'
};

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(const real_T u0[3], const real_T u1
  [9], real_T y[3]);
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
void wgs84_taylor_series(real_T *h, real_T *phi, real_T opt_m2ft, real_T *y,
  int_T k);
static uint32_T plook_bincpa(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction, uint32_T *prevIndex);
static real_T intrp2d_la_pw(const uint32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride, const uint32_T maxIndex[]);
static uint32_T binsearch_u32d_prevIdx(real_T u, const real_T bp[], uint32_T
  startIndex, uint32_T maxIndex);
static void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
static int32_T mul_s32_sat(int32_T a, int32_T b);

// private model entry point functions
extern void FaultModel_derivatives();
static void rate_scheduler(RT_MODEL_FaultModel_T *const FaultModel_M);

//===========*
//  Constants *
// ===========
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

//
//  UNUSED_PARAMETER(x)
//    Used to specify that a function parameter (argument) is required but not
//    accessed by the function body.

#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)                                      // do nothing
#else

//
//  This is the semi-ANSI standard way of indicating that an
//  unused function parameter is required.

#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

extern "C" {
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}
//=========*
//  Asserts *
// =========
#ifndef utAssert
#if defined(DOASSERTS)
#if !defined(PRINT_ASSERTS)
#include <assert.h>
#define utAssert(exp)                  assert(exp)
#else
#include <stdio.h>

static void _assert(char *statement, char *file, int line)
{
  printf("%s in %s on line %d\n", statement, file, line);
}

#define utAssert(_EX)                  ((_EX) ? (void)0 : _assert(#_EX, __FILE__, __LINE__))
#endif

#else
#define utAssert(exp)                                            // do nothing
#endif
#endif

extern "C" {
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T inf = 0.0;
    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0x7FF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      inf = tmpVal.fltVal;
    }

    return inf;
  }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T minf = 0.0;
    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      minf = tmpVal.fltVal;
    }

    return minf;
  }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}
  extern "C"
{
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetNaN(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T nan = 0.0;
    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF80000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      nan = tmpVal.fltVal;
    }

    return nan;
  }

  //
  // Initialize rtNaNF needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetNaNF(void)
  {
    IEEESingle nanF = { { 0 } };

    nanF.wordL.wordLuint = 0xFFC00000U;
    return nanF.wordL.wordLreal;
  }
}

extern "C" {
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  static void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // Test if value is infinite
  static boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  static boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  static boolean_T rtIsNaN(real_T value)
  {
    boolean_T result = (boolean_T) 0;
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    if (bitsPerReal == 32U) {
      result = rtIsNaNF((real32_T)value);
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.fltVal = value;
      result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) ==
                           0x7FF00000 &&
                           ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                            (tmpVal.bitVal.words.wordL != 0) ));
    }

    return result;
  }

  // Test if single-precision value is not a number
  static boolean_T rtIsNaNF(real32_T value)
  {
    IEEESingle tmp;
    tmp.wordL.wordLreal = value;
    return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                       (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
  }
}
//
//     Taylor Series expansion approximation of WGS84 model of
//     ellipsoid normal gravity
//
  void wgs84_taylor_series(real_T *h, real_T *phi, real_T opt_m2ft, real_T *y,
  int_T k)
{
  real_T gamma_ts, m, sinphi, sin2phi;
  int_T i;
  for (i = 0; i < k; i++ ) {
    sinphi = std::sin(phi[i]);
    sin2phi = sinphi*sinphi;

    // Calculate theoretical normal gravity (gamma) /eq. 4-1/
    gamma_ts = (WGS84_G_E)*( 1.0 + (WGS84_K)*sin2phi )/( std::sqrt(1.0 -
      (WGS84_E_2)*sin2phi) );
    m = (WGS84_A)*(WGS84_A)*(WGS84_B)*(WGS84_W_DEF)*(WGS84_W_DEF)/
      (WGS84_GM_DEF);

    // Return normal gravity as the output /eq. 4-3/
    y[i] = opt_m2ft*gamma_ts*( 1.0 - 2.0*( 1.0 + 1.0/(WGS84_INV_F) + m -
      2.0*sin2phi/(WGS84_INV_F) )*h[i]/(WGS84_A) + 3.0*h[i]*h[i]/(
      (WGS84_A)*(WGS84_A)) );
  }
}

static uint32_T plook_bincpa(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction, uint32_T *prevIndex)
{
  uint32_T bpIndex;

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Clip'
  // Use previous index: 'on'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = 0.0;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d_prevIdx(u, bp, *prevIndex, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex;
    *fraction = 0.0;
  }

  *prevIndex = bpIndex;
  return bpIndex;
}

static real_T intrp2d_la_pw(const uint32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride, const uint32_T maxIndex[])
{
  real_T y;
  real_T yL_0d0;
  uint32_T offset_1d;

  // Column-major Interpolation 2-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Overflow mode: 'portable wrapping'

  offset_1d = bpIndex[1U] * stride + bpIndex[0U];
  if (bpIndex[0U] == maxIndex[0U]) {
    y = table[offset_1d];
  } else {
    yL_0d0 = table[offset_1d];
    y = (table[offset_1d + 1U] - yL_0d0) * frac[0U] + yL_0d0;
  }

  if (bpIndex[1U] == maxIndex[1U]) {
  } else {
    offset_1d += stride;
    if (bpIndex[0U] == maxIndex[0U]) {
      yL_0d0 = table[offset_1d];
    } else {
      yL_0d0 = table[offset_1d];
      yL_0d0 += (table[offset_1d + 1U] - yL_0d0) * frac[0U];
    }

    y += (yL_0d0 - y) * frac[1U];
  }

  return y;
}

static uint32_T binsearch_u32d_prevIdx(real_T u, const real_T bp[], uint32_T
  startIndex, uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T found;
  uint32_T iLeft;
  uint32_T iRght;

  // Binary Search using Previous Index
  bpIndex = startIndex;
  iLeft = 0U;
  iRght = maxIndex;
  found = 0U;
  while (found == 0U) {
    if (u < bp[bpIndex]) {
      iRght = bpIndex - 1U;
      bpIndex = ((bpIndex + iLeft) - 1U) >> 1U;
    } else if (u < bp[bpIndex + 1U]) {
      found = 1U;
    } else {
      iLeft = bpIndex + 1U;
      bpIndex = ((bpIndex + iRght) + 1U) >> 1U;
    }
  }

  return bpIndex;
}

static void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Hi;
  uint32_T in0Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~static_cast<uint32_T>(in0) + 1U : static_cast<uint32_T>
    (in0);
  absIn1 = in1 < 0 ? ~static_cast<uint32_T>(in1) + 1U : static_cast<uint32_T>
    (in1);
  in0Hi = absIn0 >> 16U;
  in0Lo = absIn0 & 65535U;
  in1Hi = absIn1 >> 16U;
  absIn0 = absIn1 & 65535U;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0U;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1U;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    absIn1;
  if (static_cast<int32_T>((in0 != 0) && ((in1 != 0) && ((in0 > 0) != (in1 > 0)))))
  {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

static int32_T mul_s32_sat(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  if ((static_cast<int32_T>(u32_chi) > 0) || ((u32_chi == 0U) && (u32_clo >=
        2147483648U))) {
    result = MAX_int32_T;
  } else if ((static_cast<int32_T>(u32_chi) < -1) || ((static_cast<int32_T>
               (u32_chi) == -1) && (u32_clo < 2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = static_cast<int32_T>(u32_clo);
  }

  return result;
}

//
//   This function updates active task flag for each subrate.
// The function is called at model base rate, hence the
// generated code self-manages all its subrates.
//
static void rate_scheduler(RT_MODEL_FaultModel_T *const FaultModel_M)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (FaultModel_M->Timing.TaskCounters.TID[2])++;
  if ((FaultModel_M->Timing.TaskCounters.TID[2]) > 2) {// Sample time: [0.003s, 0.0s] 
    FaultModel_M->Timing.TaskCounters.TID[2] = 0;
  }

  (FaultModel_M->Timing.TaskCounters.TID[3])++;
  if ((FaultModel_M->Timing.TaskCounters.TID[3]) > 9) {// Sample time: [0.01s, 0.0s] 
    FaultModel_M->Timing.TaskCounters.TID[3] = 0;
  }

  (FaultModel_M->Timing.TaskCounters.TID[4])++;
  if ((FaultModel_M->Timing.TaskCounters.TID[4]) > 19) {// Sample time: [0.02s, 0.0s] 
    FaultModel_M->Timing.TaskCounters.TID[4] = 0;
  }
}

//
// This function updates continuous states using the ODE4 fixed-step
// solver algorithm
//
void MulticopterModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = static_cast<ODE4_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 36;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  FaultModel_derivatives();

  // f1 = f(t + (h/2), y + (h/2)*f0)
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  this->step();
  FaultModel_derivatives();

  // f2 = f(t + (h/2), y + (h/2)*f1)
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  this->step();
  FaultModel_derivatives();

  // f3 = f(t + h, y + h*f2)
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  this->step();
  FaultModel_derivatives();

  // tnew = t + h
  // ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3)
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

//
// System initialize for enable system:
//    '<S80>/Hpgw'
//    '<S119>/Hpgw'
//
void MulticopterModelClass::FaultModel_Hpgw_Init(B_Hpgw_FaultModel_T *localB,
  DW_Hpgw_FaultModel_T *localDW, P_Hpgw_FaultModel_T *localP)
{
  // InitializeConditions for UnitDelay: '<S91>/Unit Delay'
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition;

  // SystemInitialize for Sum: '<S91>/Sum' incorporates:
  //   Outport: '<S91>/pgw'

  localB->Sum[0] = localP->pgw_Y0;

  // InitializeConditions for UnitDelay: '<S91>/Unit Delay'
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition;

  // SystemInitialize for Sum: '<S91>/Sum' incorporates:
  //   Outport: '<S91>/pgw'

  localB->Sum[1] = localP->pgw_Y0;
}

//
// System reset for enable system:
//    '<S80>/Hpgw'
//    '<S119>/Hpgw'
//
void MulticopterModelClass::FaultModel_Hpgw_Reset(DW_Hpgw_FaultModel_T *localDW,
  P_Hpgw_FaultModel_T *localP)
{
  // InitializeConditions for UnitDelay: '<S91>/Unit Delay'
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition;
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition;
}

//
// Disable for enable system:
//    '<S80>/Hpgw'
//    '<S119>/Hpgw'
//
void MulticopterModelClass::FaultModel_Hpgw_Disable(B_Hpgw_FaultModel_T *localB,
  DW_Hpgw_FaultModel_T *localDW, P_Hpgw_FaultModel_T *localP)
{
  // Disable for Sum: '<S91>/Sum' incorporates:
  //   Outport: '<S91>/pgw'

  localB->Sum[0] = localP->pgw_Y0;
  localB->Sum[1] = localP->pgw_Y0;
  localDW->Hpgw_MODE = false;
}

//
// Outputs for enable system:
//    '<S80>/Hpgw'
//    '<S119>/Hpgw'
//
void MulticopterModelClass::FaultModel_Hpgw(real_T rtu_Enable, const real_T
  rtu_L_wg[2], real_T rtu_sigma_wg, real_T rtu_sigma_wg_d, real_T rtu_Noise,
  real_T rtu_wingspan, B_Hpgw_FaultModel_T *localB, DW_Hpgw_FaultModel_T
  *localDW, P_Hpgw_FaultModel_T *localP)
{
  real_T rtb_ap_idx_0;
  real_T rtb_ap_idx_1;
  real_T rtb_sp;
  real_T rtb_sp_idx_0;
  real_T tmp;

  // Outputs for Enabled SubSystem: '<S80>/Hpgw' incorporates:
  //   EnablePort: '<S91>/Enable'

  if ((rtmIsMajorTimeStep((&FaultModel_M)) &&
       (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep((
        &FaultModel_M))) {
    if (rtu_Enable > 0.0) {
      if (!localDW->Hpgw_MODE) {
        FaultModel_Hpgw_Reset(localDW, localP);
        localDW->Hpgw_MODE = true;
      }
    } else {
      if (localDW->Hpgw_MODE) {
        FaultModel_Hpgw_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->Hpgw_MODE) {
    // Product: '<S91>/w2'
    rtb_sp = rtu_L_wg[0] * rtu_wingspan;

    // Product: '<S91>/w1' incorporates:
    //   Constant: '<S91>/Constant2'
    //   Sqrt: '<S91>/sqrt'

    rtb_ap_idx_0 = localP->Constant2_Value / std::sqrt(rtb_sp);

    // Product: '<S91>/w4'
    rtb_sp *= rtu_wingspan;

    // Math: '<S91>/Math Function' incorporates:
    //   Constant: '<S91>/Constant3'

    tmp = std::floor(localP->Constant3_Value);
    if ((rtb_sp < 0.0) && (localP->Constant3_Value > tmp)) {
      rtb_sp = -rt_powd_snf(-rtb_sp, localP->Constant3_Value);
    } else {
      rtb_sp = rt_powd_snf(rtb_sp, localP->Constant3_Value);
    }

    // Product: '<S91>/w2' incorporates:
    //   Constant: '<S91>/Constant1'
    //   Product: '<S91>/w3'

    rtb_sp_idx_0 = localP->Constant1_Value / rtb_sp * rtu_sigma_wg;
    rtb_sp = rtu_L_wg[1] * rtu_wingspan;

    // Product: '<S91>/w1' incorporates:
    //   Constant: '<S91>/Constant2'
    //   Sqrt: '<S91>/sqrt'

    rtb_ap_idx_1 = localP->Constant2_Value / std::sqrt(rtb_sp);

    // Product: '<S91>/w4'
    rtb_sp *= rtu_wingspan;

    // Math: '<S91>/Math Function' incorporates:
    //   Constant: '<S91>/Constant3'

    if ((rtb_sp < 0.0) && (localP->Constant3_Value > tmp)) {
      rtb_sp = -rt_powd_snf(-rtb_sp, localP->Constant3_Value);
    } else {
      rtb_sp = rt_powd_snf(rtb_sp, localP->Constant3_Value);
    }

    // Product: '<S91>/w3' incorporates:
    //   Constant: '<S91>/Constant1'

    rtb_sp = localP->Constant1_Value / rtb_sp * rtu_sigma_wg_d;
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
      // UnitDelay: '<S91>/Unit Delay'
      localB->UnitDelay[0] = localDW->UnitDelay_DSTATE[0];
      localB->UnitDelay[1] = localDW->UnitDelay_DSTATE[1];
    }

    // Sum: '<S91>/Sum' incorporates:
    //   Constant: '<S91>/Constant'
    //   Gain: '<S91>/2'
    //   Gain: '<S91>/dt'
    //   Product: '<S91>/Lug//V1'
    //   Product: '<S91>/Lug//V2'
    //   Sqrt: '<S91>/sqrt1'
    //   Sum: '<S91>/Sum1'

    localB->Sum[0] = (localP->Constant_Value - localP->dt_Gain * rtb_ap_idx_0) *
      localB->UnitDelay[0] + std::sqrt(localP->u_Gain * rtb_ap_idx_0) *
      rtb_sp_idx_0 * rtu_Noise;
    localB->Sum[1] = (localP->Constant_Value - localP->dt_Gain * rtb_ap_idx_1) *
      localB->UnitDelay[1] + std::sqrt(localP->u_Gain * rtb_ap_idx_1) * rtb_sp *
      rtu_Noise;
  }

  // End of Outputs for SubSystem: '<S80>/Hpgw'
}

//
// Update for enable system:
//    '<S80>/Hpgw'
//    '<S119>/Hpgw'
//
void MulticopterModelClass::FaultModel_Hpgw_Update(B_Hpgw_FaultModel_T *localB,
  DW_Hpgw_FaultModel_T *localDW)
{
  // Update for Enabled SubSystem: '<S80>/Hpgw' incorporates:
  //   EnablePort: '<S91>/Enable'

  if (localDW->Hpgw_MODE && (rtmIsMajorTimeStep((&FaultModel_M)) &&
       (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0)) {
    // Update for UnitDelay: '<S91>/Unit Delay'
    localDW->UnitDelay_DSTATE[0] = localB->Sum[0];
    localDW->UnitDelay_DSTATE[1] = localB->Sum[1];
  }

  // End of Update for SubSystem: '<S80>/Hpgw'
}

//
// System initialize for enable system:
//    '<S80>/Hqgw'
//    '<S119>/Hqgw'
//
void MulticopterModelClass::FaultModel_Hqgw_Init(B_Hqgw_FaultModel_T *localB,
  DW_Hqgw_FaultModel_T *localDW, P_Hqgw_FaultModel_T *localP)
{
  // InitializeConditions for UnitDelay: '<S92>/Unit Delay'
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition;

  // InitializeConditions for UnitDelay: '<S92>/Unit Delay1'
  localDW->UnitDelay1_DSTATE[0] = localP->UnitDelay1_InitialCondition;

  // SystemInitialize for Sum: '<S92>/Sum1' incorporates:
  //   Outport: '<S92>/qgw'

  localB->Sum1[0] = localP->qgw_Y0;

  // InitializeConditions for UnitDelay: '<S92>/Unit Delay'
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition;

  // InitializeConditions for UnitDelay: '<S92>/Unit Delay1'
  localDW->UnitDelay1_DSTATE[1] = localP->UnitDelay1_InitialCondition;

  // SystemInitialize for Sum: '<S92>/Sum1' incorporates:
  //   Outport: '<S92>/qgw'

  localB->Sum1[1] = localP->qgw_Y0;
}

//
// System reset for enable system:
//    '<S80>/Hqgw'
//    '<S119>/Hqgw'
//
void MulticopterModelClass::FaultModel_Hqgw_Reset(DW_Hqgw_FaultModel_T *localDW,
  P_Hqgw_FaultModel_T *localP)
{
  // InitializeConditions for UnitDelay: '<S92>/Unit Delay'
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition;

  // InitializeConditions for UnitDelay: '<S92>/Unit Delay1'
  localDW->UnitDelay1_DSTATE[0] = localP->UnitDelay1_InitialCondition;

  // InitializeConditions for UnitDelay: '<S92>/Unit Delay'
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition;

  // InitializeConditions for UnitDelay: '<S92>/Unit Delay1'
  localDW->UnitDelay1_DSTATE[1] = localP->UnitDelay1_InitialCondition;
}

//
// Disable for enable system:
//    '<S80>/Hqgw'
//    '<S119>/Hqgw'
//
void MulticopterModelClass::FaultModel_Hqgw_Disable(B_Hqgw_FaultModel_T *localB,
  DW_Hqgw_FaultModel_T *localDW, P_Hqgw_FaultModel_T *localP)
{
  // Disable for Sum: '<S92>/Sum1' incorporates:
  //   Outport: '<S92>/qgw'

  localB->Sum1[0] = localP->qgw_Y0;
  localB->Sum1[1] = localP->qgw_Y0;
  localDW->Hqgw_MODE = false;
}

//
// Outputs for enable system:
//    '<S80>/Hqgw'
//    '<S119>/Hqgw'
//
void MulticopterModelClass::FaultModel_Hqgw(real_T rtu_Enable, real_T rtu_V,
  const real_T rtu_wg[2], real_T rtu_wingspan, B_Hqgw_FaultModel_T *localB,
  DW_Hqgw_FaultModel_T *localDW, P_Hqgw_FaultModel_T *localP)
{
  // Outputs for Enabled SubSystem: '<S80>/Hqgw' incorporates:
  //   EnablePort: '<S92>/Enable'

  if ((rtmIsMajorTimeStep((&FaultModel_M)) &&
       (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep((
        &FaultModel_M))) {
    if (rtu_Enable > 0.0) {
      if (!localDW->Hqgw_MODE) {
        FaultModel_Hqgw_Reset(localDW, localP);
        localDW->Hqgw_MODE = true;
      }
    } else {
      if (localDW->Hqgw_MODE) {
        FaultModel_Hqgw_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->Hqgw_MODE) {
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
      // Gain: '<S92>/dt1'
      localB->dt1 = localP->dt1_Gain * rtu_wingspan;

      // Sum: '<S92>/Sum2' incorporates:
      //   Constant: '<S92>/Constant'
      //   Gain: '<S92>/dt'
      //   Product: '<S92>/w1'

      localB->Sum2 = localP->Constant_Value - rtu_V / localB->dt1 *
        localP->dt_Gain;
    }

    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
      // Product: '<S92>/Lug//V2' incorporates:
      //   UnitDelay: '<S92>/Unit Delay'

      localB->LugV2[0] = localB->Sum2 * localDW->UnitDelay_DSTATE[0];

      // UnitDelay: '<S92>/Unit Delay1'
      localB->UnitDelay1[0] = localDW->UnitDelay1_DSTATE[0];

      // Product: '<S92>/Lug//V2' incorporates:
      //   UnitDelay: '<S92>/Unit Delay'

      localB->LugV2[1] = localB->Sum2 * localDW->UnitDelay_DSTATE[1];

      // UnitDelay: '<S92>/Unit Delay1'
      localB->UnitDelay1[1] = localDW->UnitDelay1_DSTATE[1];
    }

    // Sum: '<S92>/Sum1' incorporates:
    //   Product: '<S92>/w2'
    //   Sum: '<S92>/Sum3'

    localB->Sum1[0] = localB->LugV2[0] - (rtu_wg[0] - localB->UnitDelay1[0]) /
      localB->dt1;
    localB->Sum1[1] = localB->LugV2[1] - (rtu_wg[1] - localB->UnitDelay1[1]) /
      localB->dt1;
  }

  // End of Outputs for SubSystem: '<S80>/Hqgw'
}

//
// Update for enable system:
//    '<S80>/Hqgw'
//    '<S119>/Hqgw'
//
void MulticopterModelClass::FaultModel_Hqgw_Update(const real_T rtu_wg[2],
  B_Hqgw_FaultModel_T *localB, DW_Hqgw_FaultModel_T *localDW)
{
  // Update for Enabled SubSystem: '<S80>/Hqgw' incorporates:
  //   EnablePort: '<S92>/Enable'

  if (localDW->Hqgw_MODE && (rtmIsMajorTimeStep((&FaultModel_M)) &&
       (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0)) {
    // Update for UnitDelay: '<S92>/Unit Delay'
    localDW->UnitDelay_DSTATE[0] = localB->Sum1[0];

    // Update for UnitDelay: '<S92>/Unit Delay1'
    localDW->UnitDelay1_DSTATE[0] = rtu_wg[0];

    // Update for UnitDelay: '<S92>/Unit Delay'
    localDW->UnitDelay_DSTATE[1] = localB->Sum1[1];

    // Update for UnitDelay: '<S92>/Unit Delay1'
    localDW->UnitDelay1_DSTATE[1] = rtu_wg[1];
  }

  // End of Update for SubSystem: '<S80>/Hqgw'
}

//
// System initialize for enable system:
//    '<S80>/Hrgw'
//    '<S119>/Hrgw'
//
void MulticopterModelClass::FaultModel_Hrgw_Init(B_Hrgw_FaultModel_T *localB,
  DW_Hrgw_FaultModel_T *localDW, P_Hrgw_FaultModel_T *localP)
{
  // InitializeConditions for UnitDelay: '<S93>/Unit Delay'
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition;

  // InitializeConditions for UnitDelay: '<S93>/Unit Delay1'
  localDW->UnitDelay1_DSTATE[0] = localP->UnitDelay1_InitialCondition;

  // SystemInitialize for Sum: '<S93>/Sum1' incorporates:
  //   Outport: '<S93>/rgw'

  localB->Sum1[0] = localP->rgw_Y0;

  // InitializeConditions for UnitDelay: '<S93>/Unit Delay'
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition;

  // InitializeConditions for UnitDelay: '<S93>/Unit Delay1'
  localDW->UnitDelay1_DSTATE[1] = localP->UnitDelay1_InitialCondition;

  // SystemInitialize for Sum: '<S93>/Sum1' incorporates:
  //   Outport: '<S93>/rgw'

  localB->Sum1[1] = localP->rgw_Y0;
}

//
// System reset for enable system:
//    '<S80>/Hrgw'
//    '<S119>/Hrgw'
//
void MulticopterModelClass::FaultModel_Hrgw_Reset(DW_Hrgw_FaultModel_T *localDW,
  P_Hrgw_FaultModel_T *localP)
{
  // InitializeConditions for UnitDelay: '<S93>/Unit Delay'
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition;

  // InitializeConditions for UnitDelay: '<S93>/Unit Delay1'
  localDW->UnitDelay1_DSTATE[0] = localP->UnitDelay1_InitialCondition;

  // InitializeConditions for UnitDelay: '<S93>/Unit Delay'
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition;

  // InitializeConditions for UnitDelay: '<S93>/Unit Delay1'
  localDW->UnitDelay1_DSTATE[1] = localP->UnitDelay1_InitialCondition;
}

//
// Disable for enable system:
//    '<S80>/Hrgw'
//    '<S119>/Hrgw'
//
void MulticopterModelClass::FaultModel_Hrgw_Disable(B_Hrgw_FaultModel_T *localB,
  DW_Hrgw_FaultModel_T *localDW, P_Hrgw_FaultModel_T *localP)
{
  // Disable for Sum: '<S93>/Sum1' incorporates:
  //   Outport: '<S93>/rgw'

  localB->Sum1[0] = localP->rgw_Y0;
  localB->Sum1[1] = localP->rgw_Y0;
  localDW->Hrgw_MODE = false;
}

//
// Outputs for enable system:
//    '<S80>/Hrgw'
//    '<S119>/Hrgw'
//
void MulticopterModelClass::FaultModel_Hrgw(real_T rtu_Enable, real_T rtu_V,
  const real_T rtu_vg[2], real_T rtu_wingspan, B_Hrgw_FaultModel_T *localB,
  DW_Hrgw_FaultModel_T *localDW, P_Hrgw_FaultModel_T *localP)
{
  // Outputs for Enabled SubSystem: '<S80>/Hrgw' incorporates:
  //   EnablePort: '<S93>/Enable'

  if ((rtmIsMajorTimeStep((&FaultModel_M)) &&
       (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep((
        &FaultModel_M))) {
    if (rtu_Enable > 0.0) {
      if (!localDW->Hrgw_MODE) {
        FaultModel_Hrgw_Reset(localDW, localP);
        localDW->Hrgw_MODE = true;
      }
    } else {
      if (localDW->Hrgw_MODE) {
        FaultModel_Hrgw_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->Hrgw_MODE) {
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
      // Gain: '<S93>/dt1'
      localB->dt1 = localP->dt1_Gain * rtu_wingspan;

      // Sum: '<S93>/Sum2' incorporates:
      //   Constant: '<S93>/Constant'
      //   Gain: '<S93>/dt'
      //   Product: '<S93>/w1'

      localB->Sum2 = localP->Constant_Value - rtu_V / localB->dt1 *
        localP->dt_Gain;
    }

    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
      // Product: '<S93>/Lug//V2' incorporates:
      //   UnitDelay: '<S93>/Unit Delay'

      localB->LugV2[0] = localB->Sum2 * localDW->UnitDelay_DSTATE[0];

      // UnitDelay: '<S93>/Unit Delay1'
      localB->UnitDelay1[0] = localDW->UnitDelay1_DSTATE[0];

      // Product: '<S93>/Lug//V2' incorporates:
      //   UnitDelay: '<S93>/Unit Delay'

      localB->LugV2[1] = localB->Sum2 * localDW->UnitDelay_DSTATE[1];

      // UnitDelay: '<S93>/Unit Delay1'
      localB->UnitDelay1[1] = localDW->UnitDelay1_DSTATE[1];
    }

    // Sum: '<S93>/Sum1' incorporates:
    //   Product: '<S93>/w2'
    //   Sum: '<S93>/Sum3'

    localB->Sum1[0] = (rtu_vg[0] - localB->UnitDelay1[0]) / localB->dt1 +
      localB->LugV2[0];
    localB->Sum1[1] = (rtu_vg[1] - localB->UnitDelay1[1]) / localB->dt1 +
      localB->LugV2[1];
  }

  // End of Outputs for SubSystem: '<S80>/Hrgw'
}

//
// Update for enable system:
//    '<S80>/Hrgw'
//    '<S119>/Hrgw'
//
void MulticopterModelClass::FaultModel_Hrgw_Update(const real_T rtu_vg[2],
  B_Hrgw_FaultModel_T *localB, DW_Hrgw_FaultModel_T *localDW)
{
  // Update for Enabled SubSystem: '<S80>/Hrgw' incorporates:
  //   EnablePort: '<S93>/Enable'

  if (localDW->Hrgw_MODE && (rtmIsMajorTimeStep((&FaultModel_M)) &&
       (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0)) {
    // Update for UnitDelay: '<S93>/Unit Delay'
    localDW->UnitDelay_DSTATE[0] = localB->Sum1[0];

    // Update for UnitDelay: '<S93>/Unit Delay1'
    localDW->UnitDelay1_DSTATE[0] = rtu_vg[0];

    // Update for UnitDelay: '<S93>/Unit Delay'
    localDW->UnitDelay_DSTATE[1] = localB->Sum1[1];

    // Update for UnitDelay: '<S93>/Unit Delay1'
    localDW->UnitDelay1_DSTATE[1] = rtu_vg[1];
  }

  // End of Update for SubSystem: '<S80>/Hrgw'
}

//
// System initialize for enable system:
//    '<S81>/Hugw(z)'
//    '<S120>/Hugw(z)'
//
void MulticopterModelClass::FaultModel_Hugwz_Init(B_Hugwz_FaultModel_T *localB,
  DW_Hugwz_FaultModel_T *localDW, P_Hugwz_FaultModel_T *localP)
{
  // InitializeConditions for UnitDelay: '<S94>/Unit Delay'
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition;

  // SystemInitialize for Sum: '<S94>/Sum' incorporates:
  //   Outport: '<S94>/ugw'

  localB->Sum[0] = localP->ugw_Y0;

  // InitializeConditions for UnitDelay: '<S94>/Unit Delay'
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition;

  // SystemInitialize for Sum: '<S94>/Sum' incorporates:
  //   Outport: '<S94>/ugw'

  localB->Sum[1] = localP->ugw_Y0;
}

//
// System reset for enable system:
//    '<S81>/Hugw(z)'
//    '<S120>/Hugw(z)'
//
void MulticopterModelClass::FaultModel_Hugwz_Reset(DW_Hugwz_FaultModel_T
  *localDW, P_Hugwz_FaultModel_T *localP)
{
  // InitializeConditions for UnitDelay: '<S94>/Unit Delay'
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition;
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition;
}

//
// Disable for enable system:
//    '<S81>/Hugw(z)'
//    '<S120>/Hugw(z)'
//
void MulticopterModelClass::FaultModel_Hugwz_Disable(B_Hugwz_FaultModel_T
  *localB, DW_Hugwz_FaultModel_T *localDW, P_Hugwz_FaultModel_T *localP)
{
  // Disable for Sum: '<S94>/Sum' incorporates:
  //   Outport: '<S94>/ugw'

  localB->Sum[0] = localP->ugw_Y0;
  localB->Sum[1] = localP->ugw_Y0;
  localDW->Hugwz_MODE = false;
}

//
// Outputs for enable system:
//    '<S81>/Hugw(z)'
//    '<S120>/Hugw(z)'
//
void MulticopterModelClass::FaultModel_Hugwz(real_T rtu_Enable, real_T rtu_V,
  real_T rtu_L_ug, real_T rtu_L_ug_f, real_T rtu_sigma_ug, real_T rtu_sigma_ug_b,
  real_T rtu_Noise, B_Hugwz_FaultModel_T *localB, DW_Hugwz_FaultModel_T *localDW,
  P_Hugwz_FaultModel_T *localP)
{
  real_T rtb_VLug_idx_0;
  real_T rtb_VLug_idx_1;

  // Outputs for Enabled SubSystem: '<S81>/Hugw(z)' incorporates:
  //   EnablePort: '<S94>/Enable'

  if ((rtmIsMajorTimeStep((&FaultModel_M)) &&
       (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep((
        &FaultModel_M))) {
    if (rtu_Enable > 0.0) {
      if (!localDW->Hugwz_MODE) {
        FaultModel_Hugwz_Reset(localDW, localP);
        localDW->Hugwz_MODE = true;
      }
    } else {
      if (localDW->Hugwz_MODE) {
        FaultModel_Hugwz_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->Hugwz_MODE) {
    // Product: '<S94>/V//Lug'
    rtb_VLug_idx_0 = rtu_V / rtu_L_ug;
    rtb_VLug_idx_1 = rtu_V / rtu_L_ug_f;
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
      // UnitDelay: '<S94>/Unit Delay'
      localB->UnitDelay[0] = localDW->UnitDelay_DSTATE[0];
      localB->UnitDelay[1] = localDW->UnitDelay_DSTATE[1];
    }

    // Sum: '<S94>/Sum' incorporates:
    //   Constant: '<S94>/Constant'
    //   Gain: '<S94>/2'
    //   Gain: '<S94>/dt'
    //   Product: '<S94>/Lug//V1'
    //   Product: '<S94>/Lug//V2'
    //   Sqrt: '<S94>/sqrt'
    //   Sum: '<S94>/Sum1'

    localB->Sum[0] = (localP->Constant_Value - localP->dt_Gain * rtb_VLug_idx_0)
      * localB->UnitDelay[0] + std::sqrt(localP->u_Gain * rtb_VLug_idx_0) *
      rtu_Noise * rtu_sigma_ug;
    localB->Sum[1] = (localP->Constant_Value - localP->dt_Gain * rtb_VLug_idx_1)
      * localB->UnitDelay[1] + std::sqrt(localP->u_Gain * rtb_VLug_idx_1) *
      rtu_Noise * rtu_sigma_ug_b;
  }

  // End of Outputs for SubSystem: '<S81>/Hugw(z)'
}

//
// Update for enable system:
//    '<S81>/Hugw(z)'
//    '<S120>/Hugw(z)'
//
void MulticopterModelClass::FaultModel_Hugwz_Update(B_Hugwz_FaultModel_T *localB,
  DW_Hugwz_FaultModel_T *localDW)
{
  // Update for Enabled SubSystem: '<S81>/Hugw(z)' incorporates:
  //   EnablePort: '<S94>/Enable'

  if (localDW->Hugwz_MODE && (rtmIsMajorTimeStep((&FaultModel_M)) &&
       (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0)) {
    // Update for UnitDelay: '<S94>/Unit Delay'
    localDW->UnitDelay_DSTATE[0] = localB->Sum[0];
    localDW->UnitDelay_DSTATE[1] = localB->Sum[1];
  }

  // End of Update for SubSystem: '<S81>/Hugw(z)'
}

//
// System initialize for enable system:
//    '<S81>/Hvgw(z)'
//    '<S120>/Hvgw(z)'
//
void MulticopterModelClass::FaultModel_Hvgwz_Init(B_Hvgwz_FaultModel_T *localB,
  DW_Hvgwz_FaultModel_T *localDW, P_Hvgwz_FaultModel_T *localP)
{
  // InitializeConditions for UnitDelay: '<S95>/Unit Delay'
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition;

  // SystemInitialize for Sum: '<S95>/Sum' incorporates:
  //   Outport: '<S95>/vgw'

  localB->Sum[0] = localP->vgw_Y0;

  // InitializeConditions for UnitDelay: '<S95>/Unit Delay'
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition;

  // SystemInitialize for Sum: '<S95>/Sum' incorporates:
  //   Outport: '<S95>/vgw'

  localB->Sum[1] = localP->vgw_Y0;
}

//
// System reset for enable system:
//    '<S81>/Hvgw(z)'
//    '<S120>/Hvgw(z)'
//
void MulticopterModelClass::FaultModel_Hvgwz_Reset(DW_Hvgwz_FaultModel_T
  *localDW, P_Hvgwz_FaultModel_T *localP)
{
  // InitializeConditions for UnitDelay: '<S95>/Unit Delay'
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition;
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition;
}

//
// Disable for enable system:
//    '<S81>/Hvgw(z)'
//    '<S120>/Hvgw(z)'
//
void MulticopterModelClass::FaultModel_Hvgwz_Disable(B_Hvgwz_FaultModel_T
  *localB, DW_Hvgwz_FaultModel_T *localDW, P_Hvgwz_FaultModel_T *localP)
{
  // Disable for Sum: '<S95>/Sum' incorporates:
  //   Outport: '<S95>/vgw'

  localB->Sum[0] = localP->vgw_Y0;
  localB->Sum[1] = localP->vgw_Y0;
  localDW->Hvgwz_MODE = false;
}

//
// Outputs for enable system:
//    '<S81>/Hvgw(z)'
//    '<S120>/Hvgw(z)'
//
void MulticopterModelClass::FaultModel_Hvgwz(real_T rtu_Enable, real_T
  rtu_sigma_vg, real_T rtu_sigma_vg_p, const real_T rtu_L_vg[2], real_T rtu_V,
  real_T rtu_Noise, B_Hvgwz_FaultModel_T *localB, DW_Hvgwz_FaultModel_T *localDW,
  P_Hvgwz_FaultModel_T *localP)
{
  real_T rtb_VLvg_idx_0;
  real_T rtb_VLvg_idx_1;

  // Outputs for Enabled SubSystem: '<S81>/Hvgw(z)' incorporates:
  //   EnablePort: '<S95>/Enable'

  if ((rtmIsMajorTimeStep((&FaultModel_M)) &&
       (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep((
        &FaultModel_M))) {
    if (rtu_Enable > 0.0) {
      if (!localDW->Hvgwz_MODE) {
        FaultModel_Hvgwz_Reset(localDW, localP);
        localDW->Hvgwz_MODE = true;
      }
    } else {
      if (localDW->Hvgwz_MODE) {
        FaultModel_Hvgwz_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->Hvgwz_MODE) {
    // Product: '<S95>/V//Lvg'
    rtb_VLvg_idx_0 = rtu_V / rtu_L_vg[0];
    rtb_VLvg_idx_1 = rtu_V / rtu_L_vg[1];
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
      // UnitDelay: '<S95>/Unit Delay'
      localB->UnitDelay[0] = localDW->UnitDelay_DSTATE[0];
      localB->UnitDelay[1] = localDW->UnitDelay_DSTATE[1];
    }

    // Sum: '<S95>/Sum' incorporates:
    //   Constant: '<S95>/Constant'
    //   Gain: '<S95>/2'
    //   Gain: '<S95>/dt'
    //   Product: '<S95>/Lug//V1'
    //   Product: '<S95>/Lug//V2'
    //   Sqrt: '<S95>/sqrt'
    //   Sum: '<S95>/Sum1'

    localB->Sum[0] = (localP->Constant_Value - localP->dt_Gain * rtb_VLvg_idx_0)
      * localB->UnitDelay[0] + std::sqrt(localP->u_Gain * rtb_VLvg_idx_0) *
      rtu_Noise * rtu_sigma_vg;
    localB->Sum[1] = (localP->Constant_Value - localP->dt_Gain * rtb_VLvg_idx_1)
      * localB->UnitDelay[1] + std::sqrt(localP->u_Gain * rtb_VLvg_idx_1) *
      rtu_Noise * rtu_sigma_vg_p;
  }

  // End of Outputs for SubSystem: '<S81>/Hvgw(z)'
}

//
// Update for enable system:
//    '<S81>/Hvgw(z)'
//    '<S120>/Hvgw(z)'
//
void MulticopterModelClass::FaultModel_Hvgwz_Update(B_Hvgwz_FaultModel_T *localB,
  DW_Hvgwz_FaultModel_T *localDW)
{
  // Update for Enabled SubSystem: '<S81>/Hvgw(z)' incorporates:
  //   EnablePort: '<S95>/Enable'

  if (localDW->Hvgwz_MODE && (rtmIsMajorTimeStep((&FaultModel_M)) &&
       (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0)) {
    // Update for UnitDelay: '<S95>/Unit Delay'
    localDW->UnitDelay_DSTATE[0] = localB->Sum[0];
    localDW->UnitDelay_DSTATE[1] = localB->Sum[1];
  }

  // End of Update for SubSystem: '<S81>/Hvgw(z)'
}

//
// System initialize for enable system:
//    '<S81>/Hwgw(z)'
//    '<S120>/Hwgw(z)'
//
void MulticopterModelClass::FaultModel_Hwgwz_Init(B_Hwgwz_FaultModel_T *localB,
  DW_Hwgwz_FaultModel_T *localDW, P_Hwgwz_FaultModel_T *localP)
{
  // InitializeConditions for UnitDelay: '<S96>/Unit Delay'
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition;

  // SystemInitialize for Sum: '<S96>/Sum' incorporates:
  //   Outport: '<S96>/wgw'

  localB->Sum[0] = localP->wgw_Y0;

  // InitializeConditions for UnitDelay: '<S96>/Unit Delay'
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition;

  // SystemInitialize for Sum: '<S96>/Sum' incorporates:
  //   Outport: '<S96>/wgw'

  localB->Sum[1] = localP->wgw_Y0;
}

//
// System reset for enable system:
//    '<S81>/Hwgw(z)'
//    '<S120>/Hwgw(z)'
//
void MulticopterModelClass::FaultModel_Hwgwz_Reset(DW_Hwgwz_FaultModel_T
  *localDW, P_Hwgwz_FaultModel_T *localP)
{
  // InitializeConditions for UnitDelay: '<S96>/Unit Delay'
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition;
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition;
}

//
// Disable for enable system:
//    '<S81>/Hwgw(z)'
//    '<S120>/Hwgw(z)'
//
void MulticopterModelClass::FaultModel_Hwgwz_Disable(B_Hwgwz_FaultModel_T
  *localB, DW_Hwgwz_FaultModel_T *localDW, P_Hwgwz_FaultModel_T *localP)
{
  // Disable for Sum: '<S96>/Sum' incorporates:
  //   Outport: '<S96>/wgw'

  localB->Sum[0] = localP->wgw_Y0;
  localB->Sum[1] = localP->wgw_Y0;
  localDW->Hwgwz_MODE = false;
}

//
// Outputs for enable system:
//    '<S81>/Hwgw(z)'
//    '<S120>/Hwgw(z)'
//
void MulticopterModelClass::FaultModel_Hwgwz(real_T rtu_Enable, real_T rtu_V,
  const real_T rtu_L_wg[2], real_T rtu_sigma_wg, real_T rtu_sigma_wg_h, real_T
  rtu_Noise, B_Hwgwz_FaultModel_T *localB, DW_Hwgwz_FaultModel_T *localDW,
  P_Hwgwz_FaultModel_T *localP)
{
  real_T rtb_VLwg_idx_0;
  real_T rtb_VLwg_idx_1;

  // Outputs for Enabled SubSystem: '<S81>/Hwgw(z)' incorporates:
  //   EnablePort: '<S96>/Enable'

  if ((rtmIsMajorTimeStep((&FaultModel_M)) &&
       (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep((
        &FaultModel_M))) {
    if (rtu_Enable > 0.0) {
      if (!localDW->Hwgwz_MODE) {
        FaultModel_Hwgwz_Reset(localDW, localP);
        localDW->Hwgwz_MODE = true;
      }
    } else {
      if (localDW->Hwgwz_MODE) {
        FaultModel_Hwgwz_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->Hwgwz_MODE) {
    // Product: '<S96>/V//Lwg'
    rtb_VLwg_idx_0 = rtu_V / rtu_L_wg[0];
    rtb_VLwg_idx_1 = rtu_V / rtu_L_wg[1];
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
      // UnitDelay: '<S96>/Unit Delay'
      localB->UnitDelay[0] = localDW->UnitDelay_DSTATE[0];
      localB->UnitDelay[1] = localDW->UnitDelay_DSTATE[1];
    }

    // Sum: '<S96>/Sum' incorporates:
    //   Constant: '<S96>/Constant'
    //   Gain: '<S96>/2'
    //   Gain: '<S96>/dt'
    //   Product: '<S96>/Lug//V1'
    //   Product: '<S96>/Lug//V2'
    //   Sqrt: '<S96>/sqrt'
    //   Sum: '<S96>/Sum1'

    localB->Sum[0] = (localP->Constant_Value - localP->dt_Gain * rtb_VLwg_idx_0)
      * localB->UnitDelay[0] + std::sqrt(localP->u_Gain * rtb_VLwg_idx_0) *
      rtu_Noise * rtu_sigma_wg;
    localB->Sum[1] = (localP->Constant_Value - localP->dt_Gain * rtb_VLwg_idx_1)
      * localB->UnitDelay[1] + std::sqrt(localP->u_Gain * rtb_VLwg_idx_1) *
      rtu_Noise * rtu_sigma_wg_h;
  }

  // End of Outputs for SubSystem: '<S81>/Hwgw(z)'
}

//
// Update for enable system:
//    '<S81>/Hwgw(z)'
//    '<S120>/Hwgw(z)'
//
void MulticopterModelClass::FaultModel_Hwgwz_Update(B_Hwgwz_FaultModel_T *localB,
  DW_Hwgwz_FaultModel_T *localDW)
{
  // Update for Enabled SubSystem: '<S81>/Hwgw(z)' incorporates:
  //   EnablePort: '<S96>/Enable'

  if (localDW->Hwgwz_MODE && (rtmIsMajorTimeStep((&FaultModel_M)) &&
       (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0)) {
    // Update for UnitDelay: '<S96>/Unit Delay'
    localDW->UnitDelay_DSTATE[0] = localB->Sum[0];
    localDW->UnitDelay_DSTATE[1] = localB->Sum[1];
  }

  // End of Update for SubSystem: '<S81>/Hwgw(z)'
}

//
// Output and update for action system:
//    '<S85>/Low altitude  rates'
//    '<S124>/Low altitude  rates'
//
void MulticopterModelClass::FaultModel_Lowaltituderates(const real_T rtu_DCM[9],
  const real_T rtu_pgw_hl[2], const real_T rtu_qgw_hl[2], const real_T
  rtu_rgw_hl[2], real_T rtu_Winddirection, real_T rty_pgwqgwrgw[3])
{
  real_T rtb_TrigonometricFunction1_o1;
  real_T rtb_TrigonometricFunction1_o2;
  real_T rtb_VectorConcatenate_idx_0;
  real_T rtb_VectorConcatenate_idx_2;
  int32_T i;

  // SignalConversion generated from: '<S105>/Vector Concatenate'
  rtb_VectorConcatenate_idx_2 = rtu_rgw_hl[0];

  // Trigonometry: '<S106>/Trigonometric Function1'
  rtb_TrigonometricFunction1_o1 = std::sin(rtu_Winddirection);
  rtb_TrigonometricFunction1_o2 = std::cos(rtu_Winddirection);

  // Sum: '<S106>/Sum' incorporates:
  //   Product: '<S106>/Product1'
  //   Product: '<S106>/Product2'

  rtb_VectorConcatenate_idx_0 = rtu_pgw_hl[0] * rtb_TrigonometricFunction1_o2 -
    rtb_TrigonometricFunction1_o1 * rtu_qgw_hl[0];

  // Sum: '<S106>/Sum1' incorporates:
  //   Product: '<S106>/Product1'
  //   Product: '<S106>/Product2'

  rtb_TrigonometricFunction1_o1 = rtu_qgw_hl[0] * rtb_TrigonometricFunction1_o2
    + rtb_TrigonometricFunction1_o1 * rtu_pgw_hl[0];

  // Reshape: '<S105>/Reshape1' incorporates:
  //   Concatenate: '<S105>/Vector Concatenate'
  //   Product: '<S105>/Product'

  for (i = 0; i < 3; i++) {
    rty_pgwqgwrgw[i] = 0.0;
    rty_pgwqgwrgw[i] += rtu_DCM[i] * rtb_VectorConcatenate_idx_0;
    rty_pgwqgwrgw[i] += rtu_DCM[i + 3] * rtb_TrigonometricFunction1_o1;
    rty_pgwqgwrgw[i] += rtu_DCM[i + 6] * rtb_VectorConcatenate_idx_2;
  }

  // End of Reshape: '<S105>/Reshape1'
}

//
// Output and update for action system:
//    '<S85>/Interpolate  rates'
//    '<S124>/Interpolate  rates'
//
void MulticopterModelClass::FaultModel_Interpolaterates(const real_T rtu_pgw_hl
  [2], const real_T rtu_qgw_hl[2], const real_T rtu_rgw_hl[2], const real_T
  rtu_DCM[9], real_T rtu_Winddirection, real_T rtu_Altitude, real_T
  rty_pgwqgwrgw[3], B_Interpolaterates_FaultModel_T *localB,
  P_Interpolaterates_FaultModel_T *localP)
{
  real_T rtb_Product_jz[3];
  real_T rtb_TrigonometricFunction_o1;
  real_T rtb_TrigonometricFunction_o2;
  real_T rtb_VectorConcatenate_g_idx_0;
  int32_T i;

  // Trigonometry: '<S104>/Trigonometric Function'
  rtb_TrigonometricFunction_o1 = std::sin(rtu_Winddirection);
  rtb_TrigonometricFunction_o2 = std::cos(rtu_Winddirection);

  // Sum: '<S104>/Sum' incorporates:
  //   Product: '<S104>/Product1'
  //   Product: '<S104>/Product2'

  rtb_VectorConcatenate_g_idx_0 = rtu_pgw_hl[0] * rtb_TrigonometricFunction_o2 -
    rtb_TrigonometricFunction_o1 * rtu_qgw_hl[0];

  // Sum: '<S104>/Sum1' incorporates:
  //   Product: '<S104>/Product1'
  //   Product: '<S104>/Product2'

  rtb_TrigonometricFunction_o1 = rtu_qgw_hl[0] * rtb_TrigonometricFunction_o2 +
    rtb_TrigonometricFunction_o1 * rtu_pgw_hl[0];

  // SignalConversion generated from: '<S103>/Vector Concatenate'
  rtb_TrigonometricFunction_o2 = rtu_rgw_hl[0];

  // Product: '<S103>/Product' incorporates:
  //   Concatenate: '<S103>/Vector Concatenate'

  for (i = 0; i < 3; i++) {
    rtb_Product_jz[i] = rtu_DCM[i + 6] * rtb_TrigonometricFunction_o2 +
      (rtu_DCM[i + 3] * rtb_TrigonometricFunction_o1 + rtu_DCM[i] *
       rtb_VectorConcatenate_g_idx_0);
  }

  // End of Product: '<S103>/Product'

  // Sum: '<S99>/Sum1' incorporates:
  //   Constant: '<S99>/max_height_low'

  rtb_TrigonometricFunction_o1 = rtu_Altitude - localP->max_height_low_Value;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Sum: '<S99>/Sum' incorporates:
    //   Constant: '<S99>/max_height_low'
    //   Constant: '<S99>/min_height_high'

    localB->Sum = localP->min_height_high_Value - localP->max_height_low_Value;
  }

  // Sum: '<S99>/Sum3' incorporates:
  //   Product: '<S99>/Product1'
  //   Sum: '<S99>/Sum2'

  rty_pgwqgwrgw[0] = (rtu_pgw_hl[1] - rtb_Product_jz[0]) *
    rtb_TrigonometricFunction_o1 / localB->Sum + rtb_Product_jz[0];
  rty_pgwqgwrgw[1] = (rtu_qgw_hl[1] - rtb_Product_jz[1]) *
    rtb_TrigonometricFunction_o1 / localB->Sum + rtb_Product_jz[1];
  rty_pgwqgwrgw[2] = (rtu_rgw_hl[1] - rtb_Product_jz[2]) *
    rtb_TrigonometricFunction_o1 / localB->Sum + rtb_Product_jz[2];
}

//
// Output and update for action system:
//    '<S86>/Low altitude  velocities'
//    '<S125>/Low altitude  velocities'
//
void MulticopterModelClass::FaultMode_Lowaltitudevelocities(const real_T
  rtu_DCM[9], const real_T rtu_ugw_hl[2], const real_T rtu_vgw_hl[2], const
  real_T rtu_wgw_hl[2], real_T rtu_Winddirection, real_T rty_ugwvgwwgw[3])
{
  real_T rtb_TrigonometricFunction_o1;
  real_T rtb_TrigonometricFunction_o2;
  real_T rtb_VectorConcatenate_c_idx_0;
  real_T rtb_VectorConcatenate_c_idx_2;
  int32_T i;

  // SignalConversion generated from: '<S113>/Vector Concatenate'
  rtb_VectorConcatenate_c_idx_2 = rtu_wgw_hl[0];

  // Trigonometry: '<S114>/Trigonometric Function'
  rtb_TrigonometricFunction_o1 = std::sin(rtu_Winddirection);
  rtb_TrigonometricFunction_o2 = std::cos(rtu_Winddirection);

  // Sum: '<S114>/Sum' incorporates:
  //   Product: '<S114>/Product1'
  //   Product: '<S114>/Product2'

  rtb_VectorConcatenate_c_idx_0 = rtu_ugw_hl[0] * rtb_TrigonometricFunction_o2 -
    rtb_TrigonometricFunction_o1 * rtu_vgw_hl[0];

  // Sum: '<S114>/Sum1' incorporates:
  //   Product: '<S114>/Product1'
  //   Product: '<S114>/Product2'

  rtb_TrigonometricFunction_o1 = rtu_vgw_hl[0] * rtb_TrigonometricFunction_o2 +
    rtb_TrigonometricFunction_o1 * rtu_ugw_hl[0];

  // Reshape: '<S113>/Reshape1' incorporates:
  //   Concatenate: '<S113>/Vector Concatenate'
  //   Product: '<S113>/Product'

  for (i = 0; i < 3; i++) {
    rty_ugwvgwwgw[i] = 0.0;
    rty_ugwvgwwgw[i] += rtu_DCM[i] * rtb_VectorConcatenate_c_idx_0;
    rty_ugwvgwwgw[i] += rtu_DCM[i + 3] * rtb_TrigonometricFunction_o1;
    rty_ugwvgwwgw[i] += rtu_DCM[i + 6] * rtb_VectorConcatenate_c_idx_2;
  }

  // End of Reshape: '<S113>/Reshape1'
}

//
// Output and update for action system:
//    '<S86>/Interpolate  velocities'
//    '<S125>/Interpolate  velocities'
//
void MulticopterModelClass::FaultMode_Interpolatevelocities(const real_T
  rtu_ugw_hl[2], const real_T rtu_vgw_hl[2], const real_T rtu_wgw_hl[2], const
  real_T rtu_DCM[9], real_T rtu_Winddirection, real_T rtu_Altitude, real_T
  rty_ugwvgwwgw[3], B_Interpolatevelocities_Fault_T *localB,
  P_Interpolatevelocities_Fault_T *localP)
{
  real_T rtb_Product_pr[3];
  real_T rtb_TrigonometricFunction_o1;
  real_T rtb_TrigonometricFunction_o2;
  real_T rtb_VectorConcatenate_i_idx_0;
  int32_T i;

  // Trigonometry: '<S112>/Trigonometric Function'
  rtb_TrigonometricFunction_o1 = std::sin(rtu_Winddirection);
  rtb_TrigonometricFunction_o2 = std::cos(rtu_Winddirection);

  // Sum: '<S112>/Sum' incorporates:
  //   Product: '<S112>/Product1'
  //   Product: '<S112>/Product2'

  rtb_VectorConcatenate_i_idx_0 = rtu_ugw_hl[0] * rtb_TrigonometricFunction_o2 -
    rtb_TrigonometricFunction_o1 * rtu_vgw_hl[0];

  // Sum: '<S112>/Sum1' incorporates:
  //   Product: '<S112>/Product1'
  //   Product: '<S112>/Product2'

  rtb_TrigonometricFunction_o1 = rtu_vgw_hl[0] * rtb_TrigonometricFunction_o2 +
    rtb_TrigonometricFunction_o1 * rtu_ugw_hl[0];

  // SignalConversion generated from: '<S111>/Vector Concatenate'
  rtb_TrigonometricFunction_o2 = rtu_wgw_hl[0];

  // Product: '<S111>/Product' incorporates:
  //   Concatenate: '<S111>/Vector Concatenate'

  for (i = 0; i < 3; i++) {
    rtb_Product_pr[i] = rtu_DCM[i + 6] * rtb_TrigonometricFunction_o2 +
      (rtu_DCM[i + 3] * rtb_TrigonometricFunction_o1 + rtu_DCM[i] *
       rtb_VectorConcatenate_i_idx_0);
  }

  // End of Product: '<S111>/Product'

  // Sum: '<S107>/Sum1' incorporates:
  //   Constant: '<S107>/max_height_low'

  rtb_TrigonometricFunction_o1 = rtu_Altitude - localP->max_height_low_Value;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Sum: '<S107>/Sum' incorporates:
    //   Constant: '<S107>/max_height_low'
    //   Constant: '<S107>/min_height_high'

    localB->Sum = localP->min_height_high_Value - localP->max_height_low_Value;
  }

  // Sum: '<S107>/Sum3' incorporates:
  //   Product: '<S107>/Product1'
  //   Sum: '<S107>/Sum2'

  rty_ugwvgwwgw[0] = (rtu_ugw_hl[1] - rtb_Product_pr[0]) *
    rtb_TrigonometricFunction_o1 / localB->Sum + rtb_Product_pr[0];
  rty_ugwvgwwgw[1] = (rtu_vgw_hl[1] - rtb_Product_pr[1]) *
    rtb_TrigonometricFunction_o1 / localB->Sum + rtb_Product_pr[1];
  rty_ugwvgwwgw[2] = (rtu_wgw_hl[1] - rtb_Product_pr[2]) *
    rtb_TrigonometricFunction_o1 / localB->Sum + rtb_Product_pr[2];
}

//
// Output and update for action system:
//    '<S191>/Positive Trace'
//    '<S192>/Positive Trace'
//    '<S326>/Positive Trace'
//
void MulticopterModelClass::FaultModel_PositiveTrace(real_T rtu_traceDCM, const
  real_T rtu_DCM[9], real_T *rty_qwqxqyqz, real_T rty_qwqxqyqz_a[3],
  P_PositiveTrace_FaultModel_T *localP)
{
  real_T rtb_Gain1_o;

  // Sqrt: '<S201>/sqrt' incorporates:
  //   Constant: '<S201>/Constant'
  //   Sum: '<S201>/Sum'

  rtb_Gain1_o = std::sqrt(rtu_traceDCM + localP->Constant_Value);

  // Gain: '<S201>/Gain'
  *rty_qwqxqyqz = localP->Gain_Gain * rtb_Gain1_o;

  // Gain: '<S201>/Gain1'
  rtb_Gain1_o *= localP->Gain1_Gain;

  // Product: '<S201>/Product' incorporates:
  //   Sum: '<S223>/Add'
  //   Sum: '<S224>/Add'
  //   Sum: '<S225>/Add'

  rty_qwqxqyqz_a[0] = (rtu_DCM[7] - rtu_DCM[5]) / rtb_Gain1_o;
  rty_qwqxqyqz_a[1] = (rtu_DCM[2] - rtu_DCM[6]) / rtb_Gain1_o;
  rty_qwqxqyqz_a[2] = (rtu_DCM[3] - rtu_DCM[1]) / rtb_Gain1_o;
}

//
// System initialize for action system:
//    '<S191>/Negative Trace'
//    '<S192>/Negative Trace'
//    '<S326>/Negative Trace'
//
void MulticopterModelClass::FaultModel_NegativeTrace_Init
  (DW_NegativeTrace_FaultModel_T *localDW)
{
  // Start for If: '<S200>/Find Maximum Diagonal Value'
  localDW->FindMaximumDiagonalValue_Active = -1;
}

//
// Output and update for action system:
//    '<S191>/Negative Trace'
//    '<S192>/Negative Trace'
//    '<S326>/Negative Trace'
//
void MulticopterModelClass::FaultModel_NegativeTrace(const real_T rtu_DCM[9],
  real_T rty_qwqxqyqz[4], DW_NegativeTrace_FaultModel_T *localDW,
  P_NegativeTrace_FaultModel_T *localP)
{
  real_T rtb_Product_nw;
  real_T rtb_Switch_c_idx_0;
  int8_T rtAction;

  // If: '<S200>/Find Maximum Diagonal Value'
  if (rtmIsMajorTimeStep((&FaultModel_M))) {
    if ((rtu_DCM[4] > rtu_DCM[0]) && (rtu_DCM[4] > rtu_DCM[8])) {
      rtAction = 0;
    } else if (rtu_DCM[8] > rtu_DCM[0]) {
      rtAction = 1;
    } else {
      rtAction = 2;
    }

    localDW->FindMaximumDiagonalValue_Active = rtAction;
  } else {
    rtAction = localDW->FindMaximumDiagonalValue_Active;
  }

  switch (rtAction) {
   case 0:
    // Outputs for IfAction SubSystem: '<S200>/Maximum Value at DCM(2,2)' incorporates:
    //   ActionPort: '<S205>/Action Port'

    // Sqrt: '<S205>/sqrt' incorporates:
    //   Constant: '<S217>/Constant'
    //   Sum: '<S217>/Add'

    rtb_Product_nw = std::sqrt(((rtu_DCM[4] - rtu_DCM[0]) - rtu_DCM[8]) +
      localP->Constant_Value);

    // Gain: '<S205>/Gain'
    rty_qwqxqyqz[2] = localP->Gain_Gain * rtb_Product_nw;

    // Switch: '<S216>/Switch' incorporates:
    //   Constant: '<S216>/Constant1'
    //   Constant: '<S216>/Constant2'

    if (rtb_Product_nw != 0.0) {
      rtb_Switch_c_idx_0 = localP->Constant1_Value;
    } else {
      rtb_Switch_c_idx_0 = localP->Constant2_Value[0];
      rtb_Product_nw = localP->Constant2_Value[1];
    }

    // End of Switch: '<S216>/Switch'

    // Product: '<S216>/Product'
    rtb_Product_nw = rtb_Switch_c_idx_0 / rtb_Product_nw;

    // Gain: '<S205>/Gain1' incorporates:
    //   Product: '<S205>/Product'
    //   Sum: '<S215>/Add'

    rty_qwqxqyqz[1] = (rtu_DCM[1] + rtu_DCM[3]) * rtb_Product_nw *
      localP->Gain1_Gain;

    // Gain: '<S205>/Gain3' incorporates:
    //   Product: '<S205>/Product'
    //   Sum: '<S214>/Add'

    rty_qwqxqyqz[3] = (rtu_DCM[5] + rtu_DCM[7]) * rtb_Product_nw *
      localP->Gain3_Gain;

    // Gain: '<S205>/Gain4' incorporates:
    //   Product: '<S205>/Product'
    //   Sum: '<S213>/Add'

    rty_qwqxqyqz[0] = (rtu_DCM[2] - rtu_DCM[6]) * rtb_Product_nw *
      localP->Gain4_Gain;

    // End of Outputs for SubSystem: '<S200>/Maximum Value at DCM(2,2)'
    break;

   case 1:
    // Outputs for IfAction SubSystem: '<S200>/Maximum Value at DCM(3,3)' incorporates:
    //   ActionPort: '<S206>/Action Port'

    // Sqrt: '<S206>/sqrt' incorporates:
    //   Constant: '<S222>/Constant'
    //   Sum: '<S222>/Add'

    rtb_Product_nw = std::sqrt(((rtu_DCM[8] - rtu_DCM[0]) - rtu_DCM[4]) +
      localP->Constant_Value_n);

    // Gain: '<S206>/Gain'
    rty_qwqxqyqz[3] = localP->Gain_Gain_c * rtb_Product_nw;

    // Switch: '<S221>/Switch' incorporates:
    //   Constant: '<S221>/Constant1'
    //   Constant: '<S221>/Constant2'

    if (rtb_Product_nw != 0.0) {
      rtb_Switch_c_idx_0 = localP->Constant1_Value_a;
    } else {
      rtb_Switch_c_idx_0 = localP->Constant2_Value_c[0];
      rtb_Product_nw = localP->Constant2_Value_c[1];
    }

    // End of Switch: '<S221>/Switch'

    // Product: '<S221>/Product'
    rtb_Product_nw = rtb_Switch_c_idx_0 / rtb_Product_nw;

    // Gain: '<S206>/Gain1' incorporates:
    //   Product: '<S206>/Product'
    //   Sum: '<S218>/Add'

    rty_qwqxqyqz[1] = (rtu_DCM[2] + rtu_DCM[6]) * rtb_Product_nw *
      localP->Gain1_Gain_n;

    // Gain: '<S206>/Gain2' incorporates:
    //   Product: '<S206>/Product'
    //   Sum: '<S219>/Add'

    rty_qwqxqyqz[2] = (rtu_DCM[5] + rtu_DCM[7]) * rtb_Product_nw *
      localP->Gain2_Gain;

    // Gain: '<S206>/Gain3' incorporates:
    //   Product: '<S206>/Product'
    //   Sum: '<S220>/Add'

    rty_qwqxqyqz[0] = (rtu_DCM[3] - rtu_DCM[1]) * rtb_Product_nw *
      localP->Gain3_Gain_m;

    // End of Outputs for SubSystem: '<S200>/Maximum Value at DCM(3,3)'
    break;

   case 2:
    // Outputs for IfAction SubSystem: '<S200>/Maximum Value at DCM(1,1)' incorporates:
    //   ActionPort: '<S204>/Action Port'

    // Sqrt: '<S204>/sqrt' incorporates:
    //   Constant: '<S212>/Constant'
    //   Sum: '<S212>/Add'

    rtb_Product_nw = std::sqrt(((rtu_DCM[0] - rtu_DCM[4]) - rtu_DCM[8]) +
      localP->Constant_Value_m);

    // Gain: '<S204>/Gain'
    rty_qwqxqyqz[1] = localP->Gain_Gain_l * rtb_Product_nw;

    // Switch: '<S211>/Switch' incorporates:
    //   Constant: '<S211>/Constant1'
    //   Constant: '<S211>/Constant2'

    if (rtb_Product_nw != 0.0) {
      rtb_Switch_c_idx_0 = localP->Constant1_Value_i;
    } else {
      rtb_Switch_c_idx_0 = localP->Constant2_Value_b[0];
      rtb_Product_nw = localP->Constant2_Value_b[1];
    }

    // End of Switch: '<S211>/Switch'

    // Product: '<S211>/Product'
    rtb_Product_nw = rtb_Switch_c_idx_0 / rtb_Product_nw;

    // Gain: '<S204>/Gain1' incorporates:
    //   Product: '<S204>/Product'
    //   Sum: '<S210>/Add'

    rty_qwqxqyqz[2] = (rtu_DCM[1] + rtu_DCM[3]) * rtb_Product_nw *
      localP->Gain1_Gain_b;

    // Gain: '<S204>/Gain2' incorporates:
    //   Product: '<S204>/Product'
    //   Sum: '<S208>/Add'

    rty_qwqxqyqz[3] = (rtu_DCM[2] + rtu_DCM[6]) * rtb_Product_nw *
      localP->Gain2_Gain_d;

    // Gain: '<S204>/Gain3' incorporates:
    //   Product: '<S204>/Product'
    //   Sum: '<S209>/Add'

    rty_qwqxqyqz[0] = (rtu_DCM[7] - rtu_DCM[5]) * rtb_Product_nw *
      localP->Gain3_Gain_n;

    // End of Outputs for SubSystem: '<S200>/Maximum Value at DCM(1,1)'
    break;
  }

  // End of If: '<S200>/Find Maximum Diagonal Value'
}

//
// Output and update for action system:
//    '<S202>/If Warning//Error'
//    '<S240>/If Warning//Error'
//    '<S334>/If Warning//Error'
//
void MulticopterModelClass::FaultModel_IfWarningError(const real_T rtu_dcm[9],
  P_IfWarningError_FaultModel_T *localP, real_T rtp_action, real_T rtp_tolerance)
{
  real_T rtu_dcm_0[9];
  int32_T i;
  int32_T i_0;
  int32_T rtu_dcm_tmp;
  boolean_T rtb_Compare_k[9];
  boolean_T tmp;

  // Bias: '<S229>/Bias1' incorporates:
  //   Math: '<S229>/Math Function'
  //   Product: '<S229>/Product'

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtu_dcm_tmp = 3 * i_0 + i;
      rtu_dcm_0[rtu_dcm_tmp] = ((rtu_dcm[3 * i + 1] * rtu_dcm[3 * i_0 + 1] +
        rtu_dcm[3 * i] * rtu_dcm[3 * i_0]) + rtu_dcm[3 * i + 2] * rtu_dcm[3 *
        i_0 + 2]) + localP->Bias1_Bias[rtu_dcm_tmp];
    }
  }

  // End of Bias: '<S229>/Bias1'

  // RelationalOperator: '<S235>/Compare' incorporates:
  //   Abs: '<S229>/Abs2'
  //   Constant: '<S235>/Constant'

  for (i = 0; i < 9; i++) {
    rtb_Compare_k[i] = (std::abs(rtu_dcm_0[i]) > rtp_tolerance);
  }

  // End of RelationalOperator: '<S235>/Compare'

  // Logic: '<S229>/Logical Operator1' incorporates:
  //   RelationalOperator: '<S235>/Compare'

  tmp = rtb_Compare_k[0];
  for (i = 0; i < 8; i++) {
    tmp = (tmp || rtb_Compare_k[i + 1]);
  }

  // If: '<S226>/If' incorporates:
  //   Abs: '<S230>/Abs1'
  //   Bias: '<S230>/Bias'
  //   Constant: '<S237>/Constant'
  //   Logic: '<S229>/Logical Operator1'
  //   Product: '<S236>/Product'
  //   Product: '<S236>/Product1'
  //   Product: '<S236>/Product2'
  //   Product: '<S236>/Product3'
  //   Product: '<S236>/Product4'
  //   Product: '<S236>/Product5'
  //   RelationalOperator: '<S237>/Compare'
  //   Reshape: '<S236>/Reshape'
  //   Sum: '<S236>/Sum'

  if (std::abs((((((rtu_dcm[0] * rtu_dcm[4] * rtu_dcm[8] - rtu_dcm[0] * rtu_dcm
                    [5] * rtu_dcm[7]) - rtu_dcm[1] * rtu_dcm[3] * rtu_dcm[8]) +
                  rtu_dcm[2] * rtu_dcm[3] * rtu_dcm[7]) + rtu_dcm[1] * rtu_dcm[5]
                 * rtu_dcm[6]) - rtu_dcm[2] * rtu_dcm[4] * rtu_dcm[6]) +
               localP->Bias_Bias) > rtp_tolerance) {
    // Outputs for IfAction SubSystem: '<S226>/If Not Proper' incorporates:
    //   ActionPort: '<S228>/Action Port'

    // If: '<S228>/If' incorporates:
    //   Constant: '<S228>/Constant'

    if (rtp_action == 2.0) {
      // Outputs for IfAction SubSystem: '<S228>/Warning' incorporates:
      //   ActionPort: '<S234>/Action Port'

      // Assertion: '<S234>/Assertion' incorporates:
      //   Constant: '<S228>/Constant1'

      utAssert(localP->Constant1_Value != 0.0);

      // End of Outputs for SubSystem: '<S228>/Warning'
    } else {
      if (rtp_action == 3.0) {
        // Outputs for IfAction SubSystem: '<S228>/Error' incorporates:
        //   ActionPort: '<S233>/Action Port'

        // Assertion: '<S233>/Assertion' incorporates:
        //   Constant: '<S228>/Constant1'

        utAssert(localP->Constant1_Value != 0.0);

        // End of Outputs for SubSystem: '<S228>/Error'
      }
    }

    // End of If: '<S228>/If'
    // End of Outputs for SubSystem: '<S226>/If Not Proper'
  } else {
    if (tmp) {
      // Outputs for IfAction SubSystem: '<S226>/Else If Not Orthogonal' incorporates:
      //   ActionPort: '<S227>/Action Port'

      // If: '<S227>/If' incorporates:
      //   Constant: '<S227>/Constant'

      if (rtp_action == 2.0) {
        // Outputs for IfAction SubSystem: '<S227>/Warning' incorporates:
        //   ActionPort: '<S232>/Action Port'

        // Assertion: '<S232>/Assertion' incorporates:
        //   Constant: '<S227>/Constant1'

        utAssert(localP->Constant1_Value_k != 0.0);

        // End of Outputs for SubSystem: '<S227>/Warning'
      } else {
        if (rtp_action == 3.0) {
          // Outputs for IfAction SubSystem: '<S227>/Error' incorporates:
          //   ActionPort: '<S231>/Action Port'

          // Assertion: '<S231>/Assertion' incorporates:
          //   Constant: '<S227>/Constant1'

          utAssert(localP->Constant1_Value_k != 0.0);

          // End of Outputs for SubSystem: '<S227>/Error'
        }
      }

      // End of If: '<S227>/If'
      // End of Outputs for SubSystem: '<S226>/Else If Not Orthogonal'
    }
  }

  // End of If: '<S226>/If'
}

//
// System initialize for atomic system:
//    '<S302>/Motor_Dynamics'
//    '<S303>/Motor_Dynamics'
//    '<S304>/Motor_Dynamics'
//    '<S305>/Motor_Dynamics'
//    '<S306>/Motor_Dynamics'
//    '<S307>/Motor_Dynamics'
//    '<S308>/Motor_Dynamics'
//    '<S309>/Motor_Dynamics'
//
void MulticopterModelClass::FaultModel_Motor_Dynamics_Init
  (DW_Motor_Dynamics_FaultModel_T *localDW, X_Motor_Dynamics_FaultModel_T
   *localX)
{
  // InitializeConditions for Integrator: '<S311>/Integrator'
  if (rtmIsFirstInitCond((&FaultModel_M))) {
    localX->Integrator_CSTATE = 0.0;
  }

  localDW->Integrator_IWORK = 1;

  // End of InitializeConditions for Integrator: '<S311>/Integrator'
}

//
// Outputs for atomic system:
//    '<S302>/Motor_Dynamics'
//    '<S303>/Motor_Dynamics'
//    '<S304>/Motor_Dynamics'
//    '<S305>/Motor_Dynamics'
//    '<S306>/Motor_Dynamics'
//    '<S307>/Motor_Dynamics'
//    '<S308>/Motor_Dynamics'
//    '<S309>/Motor_Dynamics'
//
void MulticopterModelClass::FaultModel_Motor_Dynamics(real_T rtu_motor_rate_d,
  real_T rtu_ModelInit_RPM, real_T rtu_motorT, B_Motor_Dynamics_FaultModel_T
  *localB, DW_Motor_Dynamics_FaultModel_T *localDW,
  X_Motor_Dynamics_FaultModel_T *localX)
{
  // Integrator: '<S311>/Integrator'
  if (localDW->Integrator_IWORK != 0) {
    localX->Integrator_CSTATE = rtu_ModelInit_RPM;
  }

  // Integrator: '<S311>/Integrator'
  localB->x = localX->Integrator_CSTATE;

  // Product: '<S311>/Divide' incorporates:
  //   Sum: '<S311>/Add'

  localB->dratedt = (rtu_motor_rate_d - localB->x) / rtu_motorT;
}

//
// Update for atomic system:
//    '<S302>/Motor_Dynamics'
//    '<S303>/Motor_Dynamics'
//    '<S304>/Motor_Dynamics'
//    '<S305>/Motor_Dynamics'
//    '<S306>/Motor_Dynamics'
//    '<S307>/Motor_Dynamics'
//    '<S308>/Motor_Dynamics'
//    '<S309>/Motor_Dynamics'
//
void MulticopterModelClass::FaultMode_Motor_Dynamics_Update
  (DW_Motor_Dynamics_FaultModel_T *localDW)
{
  // Update for Integrator: '<S311>/Integrator'
  localDW->Integrator_IWORK = 0;
}

//
// Derivatives for atomic system:
//    '<S302>/Motor_Dynamics'
//    '<S303>/Motor_Dynamics'
//    '<S304>/Motor_Dynamics'
//    '<S305>/Motor_Dynamics'
//    '<S306>/Motor_Dynamics'
//    '<S307>/Motor_Dynamics'
//    '<S308>/Motor_Dynamics'
//    '<S309>/Motor_Dynamics'
//
void MulticopterModelClass::FaultModel_Motor_Dynamics_Deriv
  (B_Motor_Dynamics_FaultModel_T *localB, XDot_Motor_Dynamics_FaultMode_T
   *localXdot)
{
  // Derivatives for Integrator: '<S311>/Integrator'
  localXdot->Integrator_CSTATE = localB->dratedt;
}

//
// System initialize for atomic system:
//    '<S300>/MotorNonlinearDynamic1'
//    '<S300>/MotorNonlinearDynamic2'
//    '<S300>/MotorNonlinearDynamic3'
//    '<S300>/MotorNonlinearDynamic4'
//    '<S300>/MotorNonlinearDynamic5'
//    '<S300>/MotorNonlinearDynamic6'
//    '<S300>/MotorNonlinearDynamic7'
//    '<S300>/MotorNonlinearDynamic8'
//
void MulticopterModelClass::Fau_MotorNonlinearDynamic1_Init
  (DW_MotorNonlinearDynamic1_Fau_T *localDW, X_MotorNonlinearDynamic1_Faul_T
   *localX)
{
  // SystemInitialize for Atomic SubSystem: '<S302>/Motor_Dynamics'
  FaultModel_Motor_Dynamics_Init(&localDW->Motor_Dynamics,
    &localX->Motor_Dynamics);

  // End of SystemInitialize for SubSystem: '<S302>/Motor_Dynamics'
}

//
// Outputs for atomic system:
//    '<S300>/MotorNonlinearDynamic1'
//    '<S300>/MotorNonlinearDynamic2'
//    '<S300>/MotorNonlinearDynamic3'
//    '<S300>/MotorNonlinearDynamic4'
//    '<S300>/MotorNonlinearDynamic5'
//    '<S300>/MotorNonlinearDynamic6'
//    '<S300>/MotorNonlinearDynamic7'
//    '<S300>/MotorNonlinearDynamic8'
//
void MulticopterModelClass::FaultMod_MotorNonlinearDynamic1(real_T rtu_Wb,
  real_T rtu_Cr, real_T rtu_motorT, real_T rtu_ModelInit_RPM, real_T rtu_PWM,
  B_MotorNonlinearDynamic1_Faul_T *localB, DW_MotorNonlinearDynamic1_Fau_T
  *localDW, P_MotorNonlinearDynamic1_Faul_T *localP, P_FaultModel_T
  *FaultModel_P, X_MotorNonlinearDynamic1_Faul_T *localX)
{
  real_T rtb_Sum1_g;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Saturate: '<S302>/Signal_Saturation'
    if (rtu_PWM > localP->Signal_Saturation_UpperSat) {
      rtb_Sum1_g = localP->Signal_Saturation_UpperSat;
    } else if (rtu_PWM < localP->Signal_Saturation_LowerSat) {
      rtb_Sum1_g = localP->Signal_Saturation_LowerSat;
    } else {
      rtb_Sum1_g = rtu_PWM;
    }

    // End of Saturate: '<S302>/Signal_Saturation'

    // Product: '<S302>/Product' incorporates:
    //   Constant: '<S310>/Constant'
    //   Product: '<S302>/Product1'
    //   RelationalOperator: '<S310>/Compare'
    //   Sum: '<S302>/Sum1'

    localB->Product = (rtu_Cr * rtb_Sum1_g + rtu_Wb) * static_cast<real_T>
      (rtb_Sum1_g >= FaultModel_P->ModelParam_motorMinThr);
  }

  // Outputs for Atomic SubSystem: '<S302>/Motor_Dynamics'
  FaultModel_Motor_Dynamics(localB->Product, rtu_ModelInit_RPM, rtu_motorT,
    &localB->Motor_Dynamics, &localDW->Motor_Dynamics, &localX->Motor_Dynamics);

  // End of Outputs for SubSystem: '<S302>/Motor_Dynamics'
}

//
// Update for atomic system:
//    '<S300>/MotorNonlinearDynamic1'
//    '<S300>/MotorNonlinearDynamic2'
//    '<S300>/MotorNonlinearDynamic3'
//    '<S300>/MotorNonlinearDynamic4'
//    '<S300>/MotorNonlinearDynamic5'
//    '<S300>/MotorNonlinearDynamic6'
//    '<S300>/MotorNonlinearDynamic7'
//    '<S300>/MotorNonlinearDynamic8'
//
void MulticopterModelClass::F_MotorNonlinearDynamic1_Update
  (DW_MotorNonlinearDynamic1_Fau_T *localDW)
{
  // Update for Atomic SubSystem: '<S302>/Motor_Dynamics'
  FaultMode_Motor_Dynamics_Update(&localDW->Motor_Dynamics);

  // End of Update for SubSystem: '<S302>/Motor_Dynamics'
}

//
// Derivatives for atomic system:
//    '<S300>/MotorNonlinearDynamic1'
//    '<S300>/MotorNonlinearDynamic2'
//    '<S300>/MotorNonlinearDynamic3'
//    '<S300>/MotorNonlinearDynamic4'
//    '<S300>/MotorNonlinearDynamic5'
//    '<S300>/MotorNonlinearDynamic6'
//    '<S300>/MotorNonlinearDynamic7'
//    '<S300>/MotorNonlinearDynamic8'
//
void MulticopterModelClass::Fa_MotorNonlinearDynamic1_Deriv
  (B_MotorNonlinearDynamic1_Faul_T *localB, XDot_MotorNonlinearDynamic1_F_T
   *localXdot)
{
  // Derivatives for Atomic SubSystem: '<S302>/Motor_Dynamics'
  FaultModel_Motor_Dynamics_Deriv(&localB->Motor_Dynamics,
    &localXdot->Motor_Dynamics);

  // End of Derivatives for SubSystem: '<S302>/Motor_Dynamics'
}

//
// Output and update for atomic system:
//    '<S401>/Acc Fun'
//    '<S409>/Gyro Fun'
//
void MulticopterModelClass::FaultModel_AccFun(const real_T rtu_u[3], boolean_T
  rtu_isAccFault, const real_T rtu_AccFaultParams[20], B_AccFun_FaultModel_T
  *localB)
{
  // MATLAB Function 'OutputPort1/HILSensorMavModel1/Subsystem/AccNoiseSwitch/Acc Fun': '<S418>:1' 
  // '<S418>:1:3' y = 0.2*u';
  // '<S418>:1:4' y_scale = [1,1,1];
  localB->y[0] = 0.2 * rtu_u[0];
  localB->y_scale[0] = 1.0;
  localB->y[1] = 0.2 * rtu_u[1];
  localB->y_scale[1] = 1.0;
  localB->y[2] = 0.2 * rtu_u[2];
  localB->y_scale[2] = 1.0;

  // '<S418>:1:6' if isAccFault
  if (rtu_isAccFault) {
    // '<S418>:1:7' if AccFaultParams(1) == 3
    if (rtu_AccFaultParams[0] == 3.0) {
      // '<S418>:1:8' y = [0.2+0.8*AccFaultParams(3),0.2+0.8*AccFaultParams(5),0.2+0.8*AccFaultParams(7)] .*u' + [AccFaultParams(2),AccFaultParams(4),AccFaultParams(6)]; 
      localB->y[0] = (0.8 * rtu_AccFaultParams[2] + 0.2) * rtu_u[0] +
        rtu_AccFaultParams[1];
      localB->y[1] = (0.8 * rtu_AccFaultParams[4] + 0.2) * rtu_u[1] +
        rtu_AccFaultParams[3];
      localB->y[2] = (0.8 * rtu_AccFaultParams[6] + 0.2) * rtu_u[2] +
        rtu_AccFaultParams[5];

      //  y = (0.2+0.8*AccFaultParams(2))*u;
    } else {
      if (rtu_AccFaultParams[0] == 4.0) {
        // '<S418>:1:10' elseif AccFaultParams(1) == 4
        // '<S418>:1:11' y_scale = [AccFaultParams(2),AccFaultParams(3),AccFaultParams(4)]; 
        localB->y_scale[0] = rtu_AccFaultParams[1];
        localB->y_scale[1] = rtu_AccFaultParams[2];
        localB->y_scale[2] = rtu_AccFaultParams[3];
      }
    }
  }
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = std::fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > std::floor(u1))) {
      q = std::abs(u0 / u1);
      yEq = !(std::abs(q - std::floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else {
      if ((u0 < 0.0) != (u1 < 0.0)) {
        y += u1;
      }
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = std::atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

// Function for MATLAB Function: '<Root>/CollisionDetection'
real_T MulticopterModelClass::FaultModel_eml_rand_mt19937ar(uint32_T state[625])
{
  real_T r;
  int32_T exitg1;
  int32_T k;
  int32_T kk;
  uint32_T u[2];
  uint32_T mti;
  uint32_T y;
  boolean_T b_isvalid;
  boolean_T exitg2;

  // ========================= COPYRIGHT NOTICE ============================
  //  This is a uniform (0,1) pseudorandom number generator based on:
  //
  //  A C-program for MT19937, with initialization improved 2002/1/26.
  //  Coded by Takuji Nishimura and Makoto Matsumoto.
  //
  //  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
  //  All rights reserved.
  //
  //  Redistribution and use in source and binary forms, with or without
  //  modification, are permitted provided that the following conditions
  //  are met:
  //
  //    1. Redistributions of source code must retain the above copyright
  //       notice, this list of conditions and the following disclaimer.
  //
  //    2. Redistributions in binary form must reproduce the above copyright
  //       notice, this list of conditions and the following disclaimer
  //       in the documentation and/or other materials provided with the
  //       distribution.
  //
  //    3. The names of its contributors may not be used to endorse or
  //       promote products derived from this software without specific
  //       prior written permission.
  //
  //  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  //  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  //  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  //  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
  //  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  //  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  //  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  //  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  //  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  //  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  //  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  //
  // =============================   END   =================================
  do {
    exitg1 = 0;
    for (k = 0; k < 2; k++) {
      mti = state[624] + 1U;
      if (state[624] + 1U >= 625U) {
        for (kk = 0; kk < 227; kk++) {
          y = (state[kk + 1] & 2147483647U) | (state[kk] & 2147483648U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          state[kk] = state[kk + 397] ^ y;
        }

        for (kk = 0; kk < 396; kk++) {
          y = (state[kk + 227] & 2147483648U) | (state[kk + 228] & 2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          state[kk + 227] = state[kk] ^ y;
        }

        y = (state[623] & 2147483648U) | (state[0] & 2147483647U);
        if ((y & 1U) == 0U) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }

        state[623] = state[396] ^ y;
        mti = 1U;
      }

      y = state[static_cast<int32_T>(mti) - 1];
      state[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      u[k] = y >> 18U ^ y;
    }

    r = (static_cast<real_T>(u[0] >> 5U) * 6.7108864E+7 + static_cast<real_T>(u
          [1] >> 6U)) * 1.1102230246251565E-16;
    if (r == 0.0) {
      b_isvalid = ((state[624] >= 1U) && (state[624] < 625U));
      if (b_isvalid) {
        b_isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (state[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!b_isvalid) {
        mti = 5489U;
        state[0] = 5489U;
        for (k = 0; k < 623; k++) {
          mti = ((mti >> 30U ^ mti) * 1812433253U + k) + 1U;
          state[k + 1] = mti;
        }

        state[624] = 624U;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return r;
}

// Function for MATLAB Function: '<Root>/CollisionDetection'
real_T MulticopterModelClass::FaultModel_eml_rand_mcg16807(uint32_T *state)
{
  int32_T hi;
  uint32_T test1;
  uint32_T test2;
  hi = static_cast<int32_T>(*state / 127773U);
  test1 = (*state - hi * 127773U) * 16807U;
  test2 = 2836U * hi;
  if (test1 < test2) {
    test1 = ~(test2 - test1) & 2147483647U;
  } else {
    test1 -= test2;
  }

  *state = test1;
  return static_cast<real_T>(test1) * 4.6566128752457969E-10;
}

// Function for MATLAB Function: '<Root>/CollisionDetection'
real_T MulticopterModelClass::FaultModel_rand(void)
{
  real_T r;
  int32_T mti;
  uint32_T b_r;
  uint32_T e;
  switch (FaultModel_DW.method_l) {
   case 4U:
    r = FaultModel_eml_rand_mcg16807(&FaultModel_DW.state_m);
    break;

   case 5U:
    b_r = 69069U * FaultModel_DW.state_fo[0] + 1234567U;
    e = FaultModel_DW.state_fo[1] << 13 ^ FaultModel_DW.state_fo[1];
    e ^= e >> 17;
    e ^= e << 5;
    FaultModel_DW.state_fo[0] = b_r;
    FaultModel_DW.state_fo[1] = e;
    r = static_cast<real_T>(b_r + e) * 2.328306436538696E-10;
    break;

   default:
    if (!FaultModel_DW.state_not_empty_d) {
      std::memset(&FaultModel_DW.state_p[0], 0, 625U * sizeof(uint32_T));
      b_r = 5489U;
      FaultModel_DW.state_p[0] = 5489U;
      for (mti = 0; mti < 623; mti++) {
        b_r = ((b_r >> 30U ^ b_r) * 1812433253U + mti) + 1U;
        FaultModel_DW.state_p[mti + 1] = b_r;
      }

      FaultModel_DW.state_p[624] = 624U;
      FaultModel_DW.state_not_empty_d = true;
    }

    r = FaultModel_eml_rand_mt19937ar(FaultModel_DW.state_p);
    break;
  }

  return r;
}

// Function for MATLAB Function: '<Root>/CollisionDetection'
void MulticopterModelClass::FaultModel_rand_k(real_T r[3])
{
  int32_T mti;
  uint32_T b_r;
  uint32_T e;
  switch (FaultModel_DW.method_l) {
   case 4U:
    r[0] = FaultModel_eml_rand_mcg16807(&FaultModel_DW.state_m);
    r[1] = FaultModel_eml_rand_mcg16807(&FaultModel_DW.state_m);
    r[2] = FaultModel_eml_rand_mcg16807(&FaultModel_DW.state_m);
    break;

   case 5U:
    b_r = 69069U * FaultModel_DW.state_fo[0] + 1234567U;
    e = FaultModel_DW.state_fo[1] << 13 ^ FaultModel_DW.state_fo[1];
    e ^= e >> 17;
    e ^= e << 5;
    FaultModel_DW.state_fo[0] = b_r;
    FaultModel_DW.state_fo[1] = e;
    r[0] = static_cast<real_T>(b_r + e) * 2.328306436538696E-10;
    b_r = 69069U * FaultModel_DW.state_fo[0] + 1234567U;
    e = FaultModel_DW.state_fo[1] << 13 ^ FaultModel_DW.state_fo[1];
    e ^= e >> 17;
    e ^= e << 5;
    FaultModel_DW.state_fo[0] = b_r;
    FaultModel_DW.state_fo[1] = e;
    r[1] = static_cast<real_T>(b_r + e) * 2.328306436538696E-10;
    b_r = 69069U * FaultModel_DW.state_fo[0] + 1234567U;
    e = FaultModel_DW.state_fo[1] << 13 ^ FaultModel_DW.state_fo[1];
    e ^= e >> 17;
    e ^= e << 5;
    FaultModel_DW.state_fo[0] = b_r;
    FaultModel_DW.state_fo[1] = e;
    r[2] = static_cast<real_T>(b_r + e) * 2.328306436538696E-10;
    break;

   default:
    if (!FaultModel_DW.state_not_empty_d) {
      std::memset(&FaultModel_DW.state_p[0], 0, 625U * sizeof(uint32_T));
      b_r = 5489U;
      FaultModel_DW.state_p[0] = 5489U;
      for (mti = 0; mti < 623; mti++) {
        b_r = ((b_r >> 30U ^ b_r) * 1812433253U + mti) + 1U;
        FaultModel_DW.state_p[mti + 1] = b_r;
      }

      FaultModel_DW.state_p[624] = 624U;
      FaultModel_DW.state_not_empty_d = true;
    }

    r[0] = FaultModel_eml_rand_mt19937ar(FaultModel_DW.state_p);
    r[1] = FaultModel_eml_rand_mt19937ar(FaultModel_DW.state_p);
    r[2] = FaultModel_eml_rand_mt19937ar(FaultModel_DW.state_p);
    break;
  }
}

// Function for MATLAB Function: '<Root>/Crash_Motor_Fault'
real_T MulticopterModelClass::FaultModel_rand_n(void)
{
  real_T r;
  int32_T hi;
  uint32_T b_r;
  uint32_T test2;
  switch (FaultModel_DW.method_a) {
   case 4U:
    hi = static_cast<int32_T>(FaultModel_DW.state_c / 127773U);
    b_r = (FaultModel_DW.state_c - hi * 127773U) * 16807U;
    test2 = 2836U * hi;
    if (b_r < test2) {
      b_r = ~(test2 - b_r) & 2147483647U;
    } else {
      b_r -= test2;
    }

    FaultModel_DW.state_c = b_r;
    r = static_cast<real_T>(b_r) * 4.6566128752457969E-10;
    break;

   case 5U:
    b_r = 69069U * FaultModel_DW.state_f[0] + 1234567U;
    test2 = FaultModel_DW.state_f[1] << 13 ^ FaultModel_DW.state_f[1];
    test2 ^= test2 >> 17;
    test2 ^= test2 << 5;
    FaultModel_DW.state_f[0] = b_r;
    FaultModel_DW.state_f[1] = test2;
    r = static_cast<real_T>(b_r + test2) * 2.328306436538696E-10;
    break;

   default:
    if (!FaultModel_DW.state_not_empty_n) {
      std::memset(&FaultModel_DW.state_g[0], 0, 625U * sizeof(uint32_T));
      b_r = 5489U;
      FaultModel_DW.state_g[0] = 5489U;
      for (hi = 0; hi < 623; hi++) {
        b_r = ((b_r >> 30U ^ b_r) * 1812433253U + hi) + 1U;
        FaultModel_DW.state_g[hi + 1] = b_r;
      }

      FaultModel_DW.state_g[624] = 624U;
      FaultModel_DW.state_not_empty_n = true;
    }

    r = FaultModel_eml_rand_mt19937ar(FaultModel_DW.state_g);
    break;
  }

  return r;
}

// Function for MATLAB Function: '<S61>/MATLAB Function'
real_T MulticopterModelClass::FaultModel_rand_j(void)
{
  real_T r;
  int32_T hi;
  uint32_T b_r;
  uint32_T test2;
  switch (FaultModel_DW.method) {
   case 4U:
    hi = static_cast<int32_T>(FaultModel_DW.state / 127773U);
    b_r = (FaultModel_DW.state - hi * 127773U) * 16807U;
    test2 = 2836U * hi;
    if (b_r < test2) {
      b_r = ~(test2 - b_r) & 2147483647U;
    } else {
      b_r -= test2;
    }

    FaultModel_DW.state = b_r;
    r = static_cast<real_T>(b_r) * 4.6566128752457969E-10;
    break;

   case 5U:
    b_r = 69069U * FaultModel_DW.state_k[0] + 1234567U;
    test2 = FaultModel_DW.state_k[1] << 13 ^ FaultModel_DW.state_k[1];
    test2 ^= test2 >> 17;
    test2 ^= test2 << 5;
    FaultModel_DW.state_k[0] = b_r;
    FaultModel_DW.state_k[1] = test2;
    r = static_cast<real_T>(b_r + test2) * 2.328306436538696E-10;
    break;

   default:
    if (!FaultModel_DW.state_not_empty) {
      std::memset(&FaultModel_DW.state_d[0], 0, 625U * sizeof(uint32_T));
      b_r = 5489U;
      FaultModel_DW.state_d[0] = 5489U;
      for (hi = 0; hi < 623; hi++) {
        b_r = ((b_r >> 30U ^ b_r) * 1812433253U + hi) + 1U;
        FaultModel_DW.state_d[hi + 1] = b_r;
      }

      FaultModel_DW.state_d[624] = 624U;
      FaultModel_DW.state_not_empty = true;
    }

    r = FaultModel_eml_rand_mt19937ar(FaultModel_DW.state_d);
    break;
  }

  return r;
}

void rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(const real_T u0[3], const real_T u1[9],
  real_T y[3])
{
  real_T A[9];
  real_T a21;
  real_T maxval;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  std::memcpy(&A[0], &u1[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = std::abs(u1[0]);
  a21 = std::abs(u1[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (std::abs(u1[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  A[r2] = u1[r2] / u1[r1];
  A[r3] /= A[r1];
  A[r2 + 3] -= A[r1 + 3] * A[r2];
  A[r3 + 3] -= A[r1 + 3] * A[r3];
  A[r2 + 6] -= A[r1 + 6] * A[r2];
  A[r3 + 6] -= A[r1 + 6] * A[r3];
  if (std::abs(A[r3 + 3]) > std::abs(A[r2 + 3])) {
    rtemp = r2 + 1;
    r2 = r3;
    r3 = rtemp - 1;
  }

  A[r3 + 3] /= A[r2 + 3];
  A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
  y[r1] = u0[0] / A[r1];
  y[r2] = u0[1] - A[r1 + 3] * y[r1];
  y[r3] = u0[2] - A[r1 + 6] * y[r1];
  y[r2] /= A[r2 + 3];
  y[r3] -= A[r2 + 6] * y[r2];
  y[r3] /= A[r3 + 6];
  y[r2] -= A[r3 + 3] * y[r3];
  y[r1] -= y[r3] * A[r3];
  y[r1] -= y[r2] * A[r2];
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

// Function for MATLAB Function: '<S11>/Model Fail Assessment'
real_T MulticopterModelClass::FaultModel_norm(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = std::abs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = std::abs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = std::abs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * std::sqrt(y);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  // Uniform random number generator (random number between 0 and 1)

  // #define IA      16807                      magic multiplier = 7^5
  // #define IM      2147483647                 modulus = 2^31-1
  // #define IQ      127773                     IM div IA
  // #define IR      2836                       IM modulo IA
  // #define S       4.656612875245797e-10      reciprocal of 2^31-1
  // test = IA * (seed % IQ) - IR * (seed/IQ)
  // seed = test < 0 ? (test + IM) : test
  // return (seed*S)

  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return static_cast<real_T>(*u) * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  // Normal (Gaussian) random number generator
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = std::sqrt(-2.0 * std::log(si) / si) * sr;
  return y;
}

// Model step function
void MulticopterModelClass::step()
{
  // local block i/o variables
  real_T rtb_Wind[3];
  real_T rtb_y_h[8];

  // local scratch DWork variables
  int32_T ForEach_itr;
  static const real_T TypeMotorAngMatrix[80] = { 1.0471975511965976,
    1.0471975511965976, 0.78539816339744828, 1.5707963267948966,
    1.5707963267948966, 0.0, 1.0471975511965976, 0.39269908169872414, 0.0,
    0.78539816339744828, 3.1415926535897931, 3.1415926535897931,
    3.9269908169872414, 4.71238898038469, 4.71238898038469, 3.1415926535897931,
    1.0471975511965976, 3.5342917352885173, 3.1415926535897931,
    -0.78539816339744828, -1.0471975511965976, -1.0471975511965976,
    5.497787143782138, 0.0, 5.7595865315812871, 4.1887902047863905,
    3.1415926535897931, 1.1780972450961724, 0.78539816339744828,
    3.9269908169872414, 0.0, 0.0, 2.3561944901923448, 3.1415926535897931,
    2.617993877991494, 1.0471975511965976, 3.1415926535897931, 2.748893571891069,
    2.3561944901923448, 2.3561944901923448, 0.0, 0.0, 0.0, 0.0,
    0.52359877559829893, -1.0471975511965976, -1.0471975511965976,
    -0.39269908169872414, -0.78539816339744828, -0.78539816339744828, 0.0, 0.0,
    0.0, 0.0, 3.6651914291880923, 2.0943951023931957, -1.0471975511965976,
    4.3196898986859651, 3.9269908169872414, 0.78539816339744828, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 5.1050880620834143, 4.71238898038469, 2.3561944901923448,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.9634954084936207, 1.5707963267948966,
    3.9269908169872414 };

  static const int8_T TypeMotorDirMatrix[80] = { -1, 1, -1, -1, 1, 1, 1, 1, 1, 1,
    -1, 1, -1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, 1, 1, -1, -1, 1, 0, 0,
    1, 1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, -1, -1, 1, -1, -1, 1, 0, 0, 0, 0,
    1, 1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, -1 };

  static const int8_T TypeMotorNonVector[10] = { 3, 3, 4, 4, 6, 6, 6, 8, 8, 8 };

  real_T rtb_tc_old[169];
  real_T LoadLeakParams[20];
  real_T LoadShiftParams[20];
  real_T fParamTmp[20];
  real_T inSILFloats[20];
  real_T rtb_FaultParam_e5[20];
  real_T rtb_FaultParam_g[20];
  real_T rtb_MatrixConcatenation[18];
  real_T rtb_TmpSignalConversionAtppnInp[13];
  real_T rtb_Assignment[11];
  real_T rtb_Assignment1[11];
  real_T VectorConcatenate[9];
  real_T VectorConcatenate_p[9];
  real_T rtb_uavlostJ[9];
  real_T Memory[8];
  real_T rtb_y[8];
  real_T rtb_y_c[8];
  real_T ddm[6];
  real_T Product1[3];
  real_T rtb_Fd[3];
  real_T rtb_MatrixMultiply2[3];
  real_T rtb_Sum1_ki[3];
  real_T rtb_Windb[3];
  real_T rtb_sincos_o1[3];
  real_T tmp[3];
  real_T frac[2];
  real_T frac_0[2];
  real_T rtb_Sum_ik[2];
  real_T VectorConcatenate_n_idx_0;
  real_T VectorConcatenate_n_idx_1;
  real_T VectorConcatenate_n_idx_2;
  real_T Y;
  real_T Z;
  real_T discharge_capacity;
  real_T hover_current;
  real_T massOb;
  real_T rtb_Add;
  real_T rtb_Clock1_tmp;
  real_T rtb_LimitaltitudetoStratosphere;
  real_T rtb_Mb_idx_0;
  real_T rtb_Mb_idx_1;
  real_T rtb_Product2_l;
  real_T rtb_Saturation_1;
  real_T rtb_Sum_os;
  real_T rtb_TmpSignalConversionAtSFun_0;
  real_T rtb_TmpSignalConversionAtSFun_1;
  real_T rtb_TmpSignalConversionAtSFun_2;
  real_T rtb_count;
  real_T rtb_count_m;
  real_T rtb_jxi;
  real_T rtb_q2dot;
  real_T rtb_q3dot;
  real_T rtb_sincos_o1_p_idx_0_tmp;
  real_T rtb_sincos_o1_p_idx_1;
  real_T rtb_uavlostMass;
  real_T rtb_wind_idx_0;
  real_T tz_idx_0;
  real_T tz_idx_1;
  real_T tz_idx_2;
  real_T tz_idx_3;
  real_T uavlostJxy;
  real_T uavlostJyz;
  real_T uavlostJzx;
  real_T y;
  real_T y_0;
  int32_T b_t;
  int32_T i;
  int32_T qY;
  int32_T qY_0;
  int32_T qY_1;
  int32_T qY_2;
  int32_T r;
  int32_T r_0;
  int32_T r_1;
  int32_T rtb_Sum1_kf;
  int32_T rtb_Sum1_pe;
  int32_T rtb_alt;
  uint32_T bpIndex[2];
  uint32_T bpIndex_0[2];
  uint32_T b_r;
  uint32_T rtb_time_usec;
  uint32_T seed;
  int8_T rtAction;
  int8_T rtb_landed;
  uint8_T ForIterator_IterationMarker[6];
  boolean_T hFaultTmp;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_hasFault;
  boolean_T rtb_hasFault_j;
  if (rtmIsMajorTimeStep((&FaultModel_M))) {
    // set solver stop time
    rtsiSetSolverStopTime(&(&FaultModel_M)->solverInfo,(((&FaultModel_M)
      ->Timing.clockTick0+1)*(&FaultModel_M)->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep((&FaultModel_M))) {
    (&FaultModel_M)->Timing.t[0] = rtsiGetT(&(&FaultModel_M)->solverInfo);
  }

  // Clock: '<S11>/Clock1' incorporates:
  //   Clock: '<Root>/Clock'
  //   Clock: '<S185>/Clock'
  //   Clock: '<S55>/Clock1'
  //   Clock: '<S61>/Clock1'

  rtb_Clock1_tmp = (&FaultModel_M)->Timing.t[0];

  // Product: '<S294>/Product2' incorporates:
  //   Clock: '<S11>/Clock1'
  //   Gain: '<S11>/Gain_clock'

  rtb_Product2_l = FaultModel_P.Gain_clock_Gain * rtb_Clock1_tmp;

  // DataTypeConversion: '<S11>/Data Type Conversion1'
  rtb_wind_idx_0 = std::floor(rtb_Product2_l);
  if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
    rtb_wind_idx_0 = 0.0;
  } else {
    rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 4.294967296E+9);
  }

  rtb_time_usec = rtb_wind_idx_0 < 0.0 ? static_cast<uint32_T>
    (-static_cast<int32_T>(static_cast<uint32_T>(-rtb_wind_idx_0))) :
    static_cast<uint32_T>(rtb_wind_idx_0);

  // End of DataTypeConversion: '<S11>/Data Type Conversion1'
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Gain: '<S23>/1//2' incorporates:
    //   Constant: '<S13>/Initial Euler Angles'

    rtb_sincos_o1[0] = FaultModel_P.u2_Gain * FaultModel_P.ModelInit_AngEuler[2];
    rtb_sincos_o1[1] = FaultModel_P.u2_Gain * FaultModel_P.ModelInit_AngEuler[1];
    rtb_sincos_o1[2] = FaultModel_P.u2_Gain * FaultModel_P.ModelInit_AngEuler[0];

    // Trigonometry: '<S23>/sincos'
    rtb_TmpSignalConversionAtSFun_0 = std::cos(rtb_sincos_o1[0]);
    rtb_sincos_o1[0] = std::sin(rtb_sincos_o1[0]);
    rtb_TmpSignalConversionAtSFun_1 = std::cos(rtb_sincos_o1[1]);
    rtb_sincos_o1[1] = std::sin(rtb_sincos_o1[1]);
    rtb_TmpSignalConversionAtSFun_2 = std::cos(rtb_sincos_o1[2]);
    rtb_Saturation_1 = std::sin(rtb_sincos_o1[2]);

    // Fcn: '<S23>/q0' incorporates:
    //   Fcn: '<S23>/q1'

    rtb_uavlostMass = rtb_TmpSignalConversionAtSFun_0 *
      rtb_TmpSignalConversionAtSFun_1;
    VectorConcatenate_n_idx_0 = rtb_sincos_o1[0] * rtb_sincos_o1[1];

    // Fcn: '<S23>/q0'
    FaultModel_B.q0 = rtb_uavlostMass * rtb_TmpSignalConversionAtSFun_2 +
      VectorConcatenate_n_idx_0 * rtb_Saturation_1;

    // Fcn: '<S23>/q1'
    FaultModel_B.q1 = rtb_uavlostMass * rtb_Saturation_1 -
      VectorConcatenate_n_idx_0 * rtb_TmpSignalConversionAtSFun_2;

    // Fcn: '<S23>/q2' incorporates:
    //   Fcn: '<S23>/q3'

    rtb_uavlostMass = rtb_sincos_o1[0] * rtb_TmpSignalConversionAtSFun_1;
    VectorConcatenate_n_idx_0 = rtb_TmpSignalConversionAtSFun_0 * rtb_sincos_o1
      [1];

    // Fcn: '<S23>/q2'
    FaultModel_B.q2 = VectorConcatenate_n_idx_0 *
      rtb_TmpSignalConversionAtSFun_2 + rtb_uavlostMass * rtb_Saturation_1;

    // Fcn: '<S23>/q3'
    FaultModel_B.q3 = rtb_uavlostMass * rtb_TmpSignalConversionAtSFun_2 -
      VectorConcatenate_n_idx_0 * rtb_Saturation_1;
  }

  // Integrator: '<S13>/q0 q1 q2 q3' incorporates:
  //   SignalConversion generated from: '<S13>/q0 q1 q2 q3'

  if (FaultModel_DW.q0q1q2q3_IWORK != 0) {
    FaultModel_X.q0q1q2q3_CSTATE[0] = FaultModel_B.q0;
    FaultModel_X.q0q1q2q3_CSTATE[1] = FaultModel_B.q1;
    FaultModel_X.q0q1q2q3_CSTATE[2] = FaultModel_B.q2;
    FaultModel_X.q0q1q2q3_CSTATE[3] = FaultModel_B.q3;
  }

  // Product: '<S294>/Product2' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'
  //   Product: '<S37>/Product'

  rtb_Product2_l = FaultModel_X.q0q1q2q3_CSTATE[0] *
    FaultModel_X.q0q1q2q3_CSTATE[0];

  // Saturate: '<S412>/Limit  altitude  to Stratosphere' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'
  //   Product: '<S37>/Product1'

  rtb_LimitaltitudetoStratosphere = FaultModel_X.q0q1q2q3_CSTATE[1] *
    FaultModel_X.q0q1q2q3_CSTATE[1];

  // Product: '<S294>/Product2' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'
  //   Product: '<S37>/Product2'
  //   Product: '<S37>/Product3'
  //   Sqrt: '<S36>/sqrt'
  //   Sum: '<S37>/Sum'

  rtb_Product2_l = ((rtb_Product2_l + rtb_LimitaltitudetoStratosphere) +
                    FaultModel_X.q0q1q2q3_CSTATE[2] *
                    FaultModel_X.q0q1q2q3_CSTATE[2]) +
    FaultModel_X.q0q1q2q3_CSTATE[3] * FaultModel_X.q0q1q2q3_CSTATE[3];
  rtb_Product2_l = std::sqrt(rtb_Product2_l);

  // Product: '<S35>/Product' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'

  rtb_TmpSignalConversionAtSFun_2 = FaultModel_X.q0q1q2q3_CSTATE[0] /
    rtb_Product2_l;

  // Product: '<S35>/Product1' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'

  rtb_Saturation_1 = FaultModel_X.q0q1q2q3_CSTATE[1] / rtb_Product2_l;

  // Saturate: '<S412>/Limit  altitude  to Stratosphere' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'
  //   Product: '<S35>/Product2'

  rtb_LimitaltitudetoStratosphere = FaultModel_X.q0q1q2q3_CSTATE[2] /
    rtb_Product2_l;

  // Product: '<S294>/Product2' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'
  //   Product: '<S35>/Product3'

  rtb_Product2_l = FaultModel_X.q0q1q2q3_CSTATE[3] / rtb_Product2_l;

  // Product: '<S25>/Product3' incorporates:
  //   Product: '<S29>/Product3'

  rtb_uavlostMass = rtb_TmpSignalConversionAtSFun_2 *
    rtb_TmpSignalConversionAtSFun_2;

  // Product: '<S25>/Product2' incorporates:
  //   Product: '<S29>/Product2'

  VectorConcatenate_n_idx_0 = rtb_Saturation_1 * rtb_Saturation_1;

  // Product: '<S25>/Product1' incorporates:
  //   Product: '<S29>/Product1'
  //   Product: '<S33>/Product1'

  VectorConcatenate_n_idx_1 = rtb_LimitaltitudetoStratosphere *
    rtb_LimitaltitudetoStratosphere;

  // Product: '<S25>/Product' incorporates:
  //   Product: '<S29>/Product'
  //   Product: '<S33>/Product'

  VectorConcatenate_n_idx_2 = rtb_Product2_l * rtb_Product2_l;

  // Sum: '<S25>/Sum' incorporates:
  //   Product: '<S25>/Product'
  //   Product: '<S25>/Product1'
  //   Product: '<S25>/Product2'
  //   Product: '<S25>/Product3'

  VectorConcatenate[0] = ((rtb_uavlostMass + VectorConcatenate_n_idx_0) -
    VectorConcatenate_n_idx_1) - VectorConcatenate_n_idx_2;

  // Product: '<S28>/Product3' incorporates:
  //   Product: '<S26>/Product3'

  uavlostJyz = rtb_Product2_l * rtb_TmpSignalConversionAtSFun_2;

  // Product: '<S28>/Product2' incorporates:
  //   Product: '<S26>/Product2'

  rtb_Add = rtb_Saturation_1 * rtb_LimitaltitudetoStratosphere;

  // Gain: '<S28>/Gain' incorporates:
  //   Product: '<S28>/Product2'
  //   Product: '<S28>/Product3'
  //   Sum: '<S28>/Sum'

  VectorConcatenate[1] = (rtb_Add - uavlostJyz) * FaultModel_P.Gain_Gain_pu;

  // Product: '<S31>/Product2' incorporates:
  //   Product: '<S27>/Product2'

  massOb = rtb_Saturation_1 * rtb_Product2_l;

  // Product: '<S31>/Product1' incorporates:
  //   Product: '<S27>/Product1'

  rtb_TmpSignalConversionAtSFun_0 = rtb_TmpSignalConversionAtSFun_2 *
    rtb_LimitaltitudetoStratosphere;

  // Gain: '<S31>/Gain' incorporates:
  //   Product: '<S31>/Product1'
  //   Product: '<S31>/Product2'
  //   Sum: '<S31>/Sum'

  VectorConcatenate[2] = (rtb_TmpSignalConversionAtSFun_0 + massOb) *
    FaultModel_P.Gain_Gain_oj;

  // Gain: '<S26>/Gain' incorporates:
  //   Sum: '<S26>/Sum'

  VectorConcatenate[3] = (uavlostJyz + rtb_Add) * FaultModel_P.Gain_Gain_n3;

  // Sum: '<S29>/Sum' incorporates:
  //   Sum: '<S33>/Sum'

  rtb_uavlostMass -= VectorConcatenate_n_idx_0;
  VectorConcatenate[4] = (rtb_uavlostMass + VectorConcatenate_n_idx_1) -
    VectorConcatenate_n_idx_2;

  // Product: '<S32>/Product1' incorporates:
  //   Product: '<S30>/Product1'

  VectorConcatenate_n_idx_0 = rtb_TmpSignalConversionAtSFun_2 * rtb_Saturation_1;

  // Product: '<S32>/Product2' incorporates:
  //   Product: '<S30>/Product2'

  uavlostJyz = rtb_LimitaltitudetoStratosphere * rtb_Product2_l;

  // Gain: '<S32>/Gain' incorporates:
  //   Product: '<S32>/Product1'
  //   Product: '<S32>/Product2'
  //   Sum: '<S32>/Sum'

  VectorConcatenate[5] = (uavlostJyz - VectorConcatenate_n_idx_0) *
    FaultModel_P.Gain_Gain_nd;

  // Gain: '<S27>/Gain' incorporates:
  //   Sum: '<S27>/Sum'

  VectorConcatenate[6] = (massOb - rtb_TmpSignalConversionAtSFun_0) *
    FaultModel_P.Gain_Gain_a;

  // Gain: '<S30>/Gain' incorporates:
  //   Sum: '<S30>/Sum'

  VectorConcatenate[7] = (VectorConcatenate_n_idx_0 + uavlostJyz) *
    FaultModel_P.Gain_Gain_cm;

  // Sum: '<S33>/Sum'
  VectorConcatenate[8] = (rtb_uavlostMass - VectorConcatenate_n_idx_1) +
    VectorConcatenate_n_idx_2;
  for (i = 0; i < 20; i++) {
    // DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
    //   Inport: '<Root>/inSILFloats'

    inSILFloats[i] = FaultModel_U.inSILFloats[i];
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // MATLAB Function: '<S185>/FaultParamsExtract3' incorporates:
    //   Constant: '<S185>/FaultID'
    //   Inport: '<Root>/inSILInts'

    // MATLAB Function 'Fail Model/Prop FaultModel/FaultParamsExtract3': '<S188>:1' 
    // '<S188>:1:5' if isempty(hFault)
    // '<S188>:1:8' if isempty(fParam)
    // '<S188>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S188>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S188>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S188>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S188>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID_Value) {
        // '<S188>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S188>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        b_t = (r + 1) << 1;
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[b_t - 2];

        // '<S188>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] =
          inSILFloats[b_t - 1];

        // '<S188>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S188>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S188>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_br = true;

      // '<S188>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S188>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_bw[0], &fParamTmp[0], 20U * sizeof
                  (real_T));
    }

    // MATLAB Function: '<S185>/FaultParamsExtract1' incorporates:
    //   Constant: '<S185>/FaultID1'
    //   Inport: '<Root>/inSILInts'

    // '<S188>:1:29' hasFault_isloadFall=hFault;
    // '<S188>:1:30' FaultParam=fParam;
    // MATLAB Function 'Fail Model/Prop FaultModel/FaultParamsExtract1': '<S186>:1' 
    // '<S186>:1:5' if isempty(hFault)
    // '<S186>:1:8' if isempty(fParam)
    // '<S186>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S186>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S186>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S186>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S186>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID1_Value) {
        // '<S186>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S186>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S186>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S186>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S186>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S186>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_c = true;

      // '<S186>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S186>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_c[0], &fParamTmp[0], 20U * sizeof(real_T));
    }

    // MATLAB Function: '<S185>/FaultParamsExtract2' incorporates:
    //   Constant: '<S185>/FaultID2'
    //   Inport: '<Root>/inSILInts'

    // '<S186>:1:29' hasFault_isloadShift=hFault;
    // '<S186>:1:30' FaultParam=fParam;
    // MATLAB Function 'Fail Model/Prop FaultModel/FaultParamsExtract2': '<S187>:1' 
    // '<S187>:1:5' if isempty(hFault)
    // '<S187>:1:8' if isempty(fParam)
    // '<S187>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S187>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S187>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S187>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S187>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID2_Value) {
        // '<S187>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S187>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S187>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S187>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S187>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S187>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_i = true;

      // '<S187>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S187>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_i[0], &fParamTmp[0], 20U * sizeof(real_T));
    }

    // MATLAB Function: '<S185>/Model Failure' incorporates:
    //   Concatenate: '<S34>/Vector Concatenate'
    //   Constant: '<S185>/ModelParam.uavMass'
    //   Constant: '<S185>/ModelParam.uavR'
    //   MATLAB Function: '<S185>/FaultParamsExtract1'
    //   MATLAB Function: '<S185>/FaultParamsExtract2'
    //   MATLAB Function: '<S185>/FaultParamsExtract3'

    // '<S187>:1:29' hasFault_isloadLeak=hFault;
    // '<S187>:1:30' FaultParam=fParam;
    std::memcpy(&fParamTmp[0], &FaultModel_DW.fParam_bw[0], 20U * sizeof(real_T));
    std::memcpy(&LoadShiftParams[0], &FaultModel_DW.fParam_c[0], 20U * sizeof
                (real_T));
    std::memcpy(&LoadLeakParams[0], &FaultModel_DW.fParam_i[0], 20U * sizeof
                (real_T));

    //  This function aims to calculate the variation of mass and moment of
    //  inertia caused by model failure including LoadFall, LoadShift, and
    //  LoadLeak.
    // MATLAB Function 'Fail Model/Prop FaultModel/Model Failure': '<S189>:1'
    // '<S189>:1:7' if isempty(tOld)
    // '<S189>:1:11' deltaM=[0;0;0];
    FaultModel_B.deltaM[0] = 0.0;
    FaultModel_B.deltaM[1] = 0.0;
    FaultModel_B.deltaM[2] = 0.0;

    // '<S189>:1:13' if isLoadFall
    if (FaultModel_DW.hFault_br) {
      // '<S189>:1:14' if LoadFallParams(1)>0.95
      if (FaultModel_DW.fParam_bw[0] > 0.95) {
        // '<S189>:1:15' LoadFallParams(1)=0.95;
        fParamTmp[0] = 0.95;
      } else {
        if (FaultModel_DW.fParam_bw[0] < 0.0) {
          // '<S189>:1:16' elseif LoadFallParams(1)<0
          // '<S189>:1:17' LoadFallParams(1)=0;
          fParamTmp[0] = 0.0;
        }
      }

      // '<S189>:1:19' uavlostMass=LoadFallParams(1)*uavMass;
      rtb_uavlostMass = fParamTmp[0] * FaultModel_P.ModelParam_uavMass;

      // '<S189>:1:20' uavlostJ=zeros(3,3);
      std::memset(&rtb_uavlostJ[0], 0, 9U * sizeof(real_T));
    } else if (FaultModel_DW.hFault_c) {
      // '<S189>:1:21' elseif isLoadShift
      // '<S189>:1:22' if LoadShiftParams(1)>0.95
      if (FaultModel_DW.fParam_c[0] > 0.95) {
        // '<S189>:1:23' LoadShiftParams(1)=0.95;
        LoadShiftParams[0] = 0.95;
      } else {
        if (FaultModel_DW.fParam_c[0] < 0.0) {
          // '<S189>:1:24' elseif LoadShiftParams(1)<0
          // '<S189>:1:25' LoadShiftParams(1)=0;
          LoadShiftParams[0] = 0.0;
        }
      }

      // '<S189>:1:28' uavlostMass= 0;
      rtb_uavlostMass = 0.0;

      // '<S189>:1:29' loadMoveMass= LoadShiftParams(1)*uavMass;
      rtb_Saturation_1 = LoadShiftParams[0] * FaultModel_P.ModelParam_uavMass;

      // '<S189>:1:31' X=uavR*LoadShiftParams(2);
      rtb_TmpSignalConversionAtSFun_2 = FaultModel_P.ModelParam_uavR *
        FaultModel_DW.fParam_c[1];

      // '<S189>:1:32' Y=uavR*LoadShiftParams(3);
      Y = FaultModel_P.ModelParam_uavR * FaultModel_DW.fParam_c[2];

      // '<S189>:1:33' Z=uavR*LoadShiftParams(4);
      Z = FaultModel_P.ModelParam_uavR * FaultModel_DW.fParam_c[3];

      // '<S189>:1:35' uavlostJxx= loadMoveMass*(Y^2+Z^2);
      // '<S189>:1:36' uavlostJyy= loadMoveMass*(X^2+Z^2);
      // '<S189>:1:37' uavlostJzz= loadMoveMass*(X^2+Y^2);
      // '<S189>:1:38' uavlostJyz= loadMoveMass*Y*Z;
      uavlostJyz = rtb_Saturation_1 * Y * Z;

      // '<S189>:1:39' uavlostJzx= loadMoveMass*Z*X;
      uavlostJzx = rtb_Saturation_1 * Z * rtb_TmpSignalConversionAtSFun_2;

      // '<S189>:1:40' uavlostJxy= loadMoveMass*X*Y;
      uavlostJxy = rtb_Saturation_1 * rtb_TmpSignalConversionAtSFun_2 * Y;

      // '<S189>:1:41' uavlostJ=-[uavlostJxx,-uavlostJxy,-uavlostJzx;-uavlostJxy,uavlostJyy,-uavlostJyz;-uavlostJzx,-uavlostJyz,uavlostJzz]; 
      VectorConcatenate_n_idx_0 = Z * Z;
      rtb_uavlostJ[0] = -((Y * Y + VectorConcatenate_n_idx_0) * rtb_Saturation_1);
      rtb_uavlostJ[3] = uavlostJxy;
      rtb_uavlostJ[6] = uavlostJzx;
      rtb_uavlostJ[1] = uavlostJxy;
      VectorConcatenate_n_idx_1 = rtb_TmpSignalConversionAtSFun_2 *
        rtb_TmpSignalConversionAtSFun_2;
      rtb_uavlostJ[4] = -((VectorConcatenate_n_idx_1 + VectorConcatenate_n_idx_0)
                          * rtb_Saturation_1);
      rtb_uavlostJ[7] = uavlostJyz;
      rtb_uavlostJ[2] = uavlostJzx;
      rtb_uavlostJ[5] = uavlostJyz;
      rtb_uavlostJ[8] = -((VectorConcatenate_n_idx_1 + Y * Y) * rtb_Saturation_1);

      // '<S189>:1:43' deltaF = dcm*loadMoveMass*[0;0;9.8];
      for (qY_1 = 0; qY_1 < 3; qY_1++) {
        rtb_sincos_o1[qY_1] = VectorConcatenate[qY_1 + 6] * rtb_Saturation_1 *
          9.8 + (VectorConcatenate[qY_1 + 3] * rtb_Saturation_1 * 0.0 +
                 VectorConcatenate[qY_1] * rtb_Saturation_1 * 0.0);
      }

      // '<S189>:1:45' deltaM = cross([X;Y;Z],deltaF);
      FaultModel_B.deltaM[0] = Y * rtb_sincos_o1[2] - Z * rtb_sincos_o1[1];
      FaultModel_B.deltaM[1] = Z * rtb_sincos_o1[0] -
        rtb_TmpSignalConversionAtSFun_2 * rtb_sincos_o1[2];
      FaultModel_B.deltaM[2] = rtb_TmpSignalConversionAtSFun_2 * rtb_sincos_o1[1]
        - Y * rtb_sincos_o1[0];

      //  变化的力矩
    } else if (FaultModel_DW.hFault_i) {
      // '<S189>:1:47' elseif isLoadLeak
      // '<S189>:1:48' uavlostJ=zeros(3,3);
      std::memset(&rtb_uavlostJ[0], 0, 9U * sizeof(real_T));

      // '<S189>:1:49' if LoadLeakParams(1)>0.99
      if (FaultModel_DW.fParam_i[0] > 0.99) {
        // '<S189>:1:50' LoadLeakParams(1)=0.99;
        LoadLeakParams[0] = 0.99;
      } else {
        if (FaultModel_DW.fParam_i[0] < 0.0) {
          // '<S189>:1:51' elseif LoadLeakParams(1)<0
          // '<S189>:1:52' LoadLeakParams(1)=0;
          LoadLeakParams[0] = 0.0;
        }
      }

      // '<S189>:1:54' loadmass0=LoadLeakParams(1)*uavMass;
      // '<S189>:1:56' if tOld<0.01
      if (FaultModel_DW.tOld < 0.01) {
        // '<S189>:1:57' tOld=T;
        FaultModel_DW.tOld = rtb_Clock1_tmp;
      }

      // '<S189>:1:60' dt=T-tOld;
      // '<S189>:1:62' LoadLeakRatio = LoadLeakParams(2)*dt;
      rtb_uavlostMass = (rtb_Clock1_tmp - FaultModel_DW.tOld) *
        FaultModel_DW.fParam_i[1];

      // '<S189>:1:63' if LoadLeakRatio > 0.99
      if (rtb_uavlostMass > 0.99) {
        // '<S189>:1:64' LoadLeakRatio = 0.99;
        rtb_uavlostMass = 0.99;
      }

      // '<S189>:1:66' uavlostMass = LoadLeakRatio*loadmass0;
      rtb_uavlostMass *= LoadLeakParams[0] * FaultModel_P.ModelParam_uavMass;
    } else {
      // '<S189>:1:68' else
      // '<S189>:1:69' uavlostMass=0;
      rtb_uavlostMass = 0.0;

      // '<S189>:1:70' uavlostJ=zeros(3,3);
      std::memset(&rtb_uavlostJ[0], 0, 9U * sizeof(real_T));

      // '<S189>:1:71' tOld=0;
      FaultModel_DW.tOld = 0.0;
    }

    // '<S189>:1:74' if ~isLoadLeak
    if (!FaultModel_DW.hFault_i) {
      // reset
      // '<S189>:1:75' tOld=0;
      FaultModel_DW.tOld = 0.0;
    }

    // End of MATLAB Function: '<S185>/Model Failure'

    // Sum: '<S185>/Add5' incorporates:
    //   Constant: '<S185>/ModelParam.uavMass'

    FaultModel_B.m = FaultModel_P.ModelParam_uavMass - rtb_uavlostMass;

    // UnitConversion: '<S174>/Unit Conversion' incorporates:
    //   Constant: '<S69>/ref_rotation'

    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    uavlostJzx = 0.017453292519943295 * FaultModel_P.FlatEarthtoLLA_psi;

    // Trigonometry: '<S159>/SinCos'
    FaultModel_B.SinCos_o1 = std::sin(uavlostJzx);

    // Trigonometry: '<S159>/SinCos'
    FaultModel_B.SinCos_o2 = std::cos(uavlostJzx);

    // Sum: '<S177>/Sum' incorporates:
    //   Constant: '<S177>/Constant'
    //   Constant: '<S177>/f'

    uavlostJzx = FaultModel_P.f_Value - FaultModel_P.Constant_Value_k;

    // Sqrt: '<S178>/sqrt' incorporates:
    //   Constant: '<S178>/Constant'
    //   Product: '<S178>/Product1'
    //   Sum: '<S178>/Sum1'

    uavlostJzx = std::sqrt(FaultModel_P.Constant_Value_pr - uavlostJzx *
      uavlostJzx);

    // Switch: '<S170>/Switch' incorporates:
    //   Abs: '<S170>/Abs'
    //   Bias: '<S170>/Bias'
    //   Bias: '<S170>/Bias1'
    //   Constant: '<S170>/Constant2'
    //   Constant: '<S171>/Constant'
    //   Constant: '<S69>/ref_position'
    //   Math: '<S170>/Math Function1'
    //   RelationalOperator: '<S171>/Compare'

    if (std::abs(FaultModel_P.ModelParam_GPSLatLong[0]) >
        FaultModel_P.CompareToConstant_const) {
      rtb_uavlostMass = rt_modd_snf(FaultModel_P.ModelParam_GPSLatLong[0] +
        FaultModel_P.Bias_Bias_gu, FaultModel_P.Constant2_Value) +
        FaultModel_P.Bias1_Bias_d;
    } else {
      rtb_uavlostMass = FaultModel_P.ModelParam_GPSLatLong[0];
    }

    // End of Switch: '<S170>/Switch'

    // Abs: '<S167>/Abs1'
    rtb_Saturation_1 = std::abs(rtb_uavlostMass);

    // RelationalOperator: '<S169>/Compare' incorporates:
    //   Constant: '<S169>/Constant'

    hFaultTmp = (rtb_Saturation_1 > FaultModel_P.CompareToConstant_const_n);

    // Switch: '<S167>/Switch'
    if (hFaultTmp) {
      // Signum: '<S167>/Sign1'
      if (rtb_uavlostMass < 0.0) {
        rtb_uavlostMass = -1.0;
      } else if (rtb_uavlostMass > 0.0) {
        rtb_uavlostMass = 1.0;
      } else if (rtb_uavlostMass == 0.0) {
        rtb_uavlostMass = 0.0;
      } else {
        rtb_uavlostMass = (rtNaN);
      }

      // End of Signum: '<S167>/Sign1'

      // Switch: '<S167>/Switch' incorporates:
      //   Bias: '<S167>/Bias'
      //   Bias: '<S167>/Bias1'
      //   Gain: '<S167>/Gain'
      //   Product: '<S167>/Divide1'

      FaultModel_B.Switch = ((rtb_Saturation_1 + FaultModel_P.Bias_Bias_g) *
        FaultModel_P.Gain_Gain_l + FaultModel_P.Bias1_Bias_f) * rtb_uavlostMass;
    } else {
      // Switch: '<S167>/Switch'
      FaultModel_B.Switch = rtb_uavlostMass;
    }

    // End of Switch: '<S167>/Switch'

    // UnitConversion: '<S175>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    uavlostJxy = 0.017453292519943295 * FaultModel_B.Switch;

    // Trigonometry: '<S176>/Trigonometric Function1'
    Z = std::sin(uavlostJxy);

    // Sum: '<S176>/Sum1' incorporates:
    //   Constant: '<S176>/Constant'
    //   Product: '<S176>/Product1'

    Z = FaultModel_P.Constant_Value_b - uavlostJzx * uavlostJzx * Z * Z;

    // Product: '<S173>/Product1' incorporates:
    //   Constant: '<S173>/Constant1'
    //   Sqrt: '<S173>/sqrt'

    Y = FaultModel_P.Constant1_Value_k / std::sqrt(Z);

    // Trigonometry: '<S173>/Trigonometric Function1' incorporates:
    //   Constant: '<S173>/Constant'
    //   Constant: '<S173>/Constant2'
    //   Product: '<S173>/Product2'
    //   Product: '<S173>/Product3'
    //   Sum: '<S173>/Sum1'

    FaultModel_B.TrigonometricFunction1 = rt_atan2d_snf
      (FaultModel_P.Constant2_Value_j, (FaultModel_P.Constant_Value_n3 -
        uavlostJzx * uavlostJzx) * Y / Z);

    // Trigonometry: '<S173>/Trigonometric Function2' incorporates:
    //   Constant: '<S173>/Constant3'
    //   Product: '<S173>/Product4'
    //   Trigonometry: '<S173>/Trigonometric Function'

    FaultModel_B.TrigonometricFunction2 = rt_atan2d_snf
      (FaultModel_P.Constant3_Value, Y * std::cos(uavlostJxy));

    // Switch: '<S158>/Switch1' incorporates:
    //   Constant: '<S158>/Constant'
    //   Constant: '<S158>/Constant1'

    if (hFaultTmp) {
      rtb_wind_idx_0 = FaultModel_P.Constant_Value_e;
    } else {
      rtb_wind_idx_0 = FaultModel_P.Constant1_Value;
    }

    // End of Switch: '<S158>/Switch1'

    // Sum: '<S158>/Sum' incorporates:
    //   Constant: '<S69>/ref_position'

    rtb_uavlostMass = rtb_wind_idx_0 + FaultModel_P.ModelParam_GPSLatLong[1];

    // Switch: '<S168>/Switch' incorporates:
    //   Abs: '<S168>/Abs'
    //   Constant: '<S172>/Constant'
    //   RelationalOperator: '<S172>/Compare'

    if (std::abs(rtb_uavlostMass) > FaultModel_P.CompareToConstant_const_ng) {
      // Switch: '<S168>/Switch' incorporates:
      //   Bias: '<S168>/Bias'
      //   Bias: '<S168>/Bias1'
      //   Constant: '<S168>/Constant2'
      //   Math: '<S168>/Math Function1'

      FaultModel_B.Switch_d = rt_modd_snf(rtb_uavlostMass +
        FaultModel_P.Bias_Bias_p, FaultModel_P.Constant2_Value_o) +
        FaultModel_P.Bias1_Bias_j;
    } else {
      // Switch: '<S168>/Switch'
      FaultModel_B.Switch_d = rtb_uavlostMass;
    }

    // End of Switch: '<S168>/Switch'
  }

  // Saturate: '<S412>/Limit  altitude  to Stratosphere' incorporates:
  //   Integrator: '<S12>/xe,ye,ze'
  //   Product: '<S159>/y*cos'

  rtb_LimitaltitudetoStratosphere = FaultModel_X.xeyeze_CSTATE[1] *
    FaultModel_B.SinCos_o2;

  // Sum: '<S69>/Sum' incorporates:
  //   Integrator: '<S12>/xe,ye,ze'
  //   Product: '<S159>/rad lat'
  //   Product: '<S159>/x*cos'
  //   Product: '<S159>/y*sin'
  //   Sum: '<S159>/Sum'
  //   UnitConversion: '<S160>/Unit Conversion'

  // Unit Conversion - from: rad to: deg
  // Expression: output = (57.2958*input) + (0)
  rtb_Sum_ik[0] = (FaultModel_X.xeyeze_CSTATE[0] * FaultModel_B.SinCos_o2 -
                   FaultModel_X.xeyeze_CSTATE[1] * FaultModel_B.SinCos_o1) *
    FaultModel_B.TrigonometricFunction1 * 57.295779513082323 +
    FaultModel_B.Switch;

  // Switch: '<S164>/Switch' incorporates:
  //   Abs: '<S164>/Abs'
  //   Bias: '<S164>/Bias'
  //   Bias: '<S164>/Bias1'
  //   Constant: '<S164>/Constant2'
  //   Constant: '<S165>/Constant'
  //   Math: '<S164>/Math Function1'
  //   RelationalOperator: '<S165>/Compare'

  if (std::abs(rtb_Sum_ik[0]) > FaultModel_P.CompareToConstant_const_b) {
    rtb_uavlostMass = rt_modd_snf(rtb_Sum_ik[0] + FaultModel_P.Bias_Bias_f,
      FaultModel_P.Constant2_Value_pf) + FaultModel_P.Bias1_Bias_m;
  } else {
    rtb_uavlostMass = rtb_Sum_ik[0];
  }

  // End of Switch: '<S164>/Switch'

  // Abs: '<S161>/Abs1'
  rtb_Saturation_1 = std::abs(rtb_uavlostMass);

  // Switch: '<S161>/Switch' incorporates:
  //   Bias: '<S161>/Bias'
  //   Bias: '<S161>/Bias1'
  //   Constant: '<S157>/Constant'
  //   Constant: '<S157>/Constant1'
  //   Constant: '<S163>/Constant'
  //   Gain: '<S161>/Gain'
  //   Product: '<S161>/Divide1'
  //   RelationalOperator: '<S163>/Compare'
  //   Switch: '<S157>/Switch1'

  if (rtb_Saturation_1 > FaultModel_P.CompareToConstant_const_e) {
    // Signum: '<S161>/Sign1'
    if (rtb_uavlostMass < 0.0) {
      rtb_uavlostMass = -1.0;
    } else if (rtb_uavlostMass > 0.0) {
      rtb_uavlostMass = 1.0;
    } else if (rtb_uavlostMass == 0.0) {
      rtb_uavlostMass = 0.0;
    } else {
      rtb_uavlostMass = (rtNaN);
    }

    // End of Signum: '<S161>/Sign1'
    rtb_uavlostMass *= (rtb_Saturation_1 + FaultModel_P.Bias_Bias) *
      FaultModel_P.Gain_Gain_o + FaultModel_P.Bias1_Bias;
    rtb_jxi = FaultModel_P.Constant_Value_d;
  } else {
    rtb_jxi = FaultModel_P.Constant1_Value_i;
  }

  // End of Switch: '<S161>/Switch'

  // Sum: '<S157>/Sum' incorporates:
  //   Integrator: '<S12>/xe,ye,ze'
  //   Product: '<S159>/rad long '
  //   Product: '<S159>/x*sin'
  //   Sum: '<S159>/Sum1'
  //   Sum: '<S69>/Sum'
  //   UnitConversion: '<S160>/Unit Conversion'

  rtb_TmpSignalConversionAtSFun_2 = ((FaultModel_X.xeyeze_CSTATE[0] *
    FaultModel_B.SinCos_o1 + rtb_LimitaltitudetoStratosphere) *
    FaultModel_B.TrigonometricFunction2 * 57.295779513082323 +
    FaultModel_B.Switch_d) + rtb_jxi;

  // Switch: '<S162>/Switch' incorporates:
  //   Abs: '<S162>/Abs'
  //   Bias: '<S162>/Bias'
  //   Bias: '<S162>/Bias1'
  //   Constant: '<S162>/Constant2'
  //   Constant: '<S166>/Constant'
  //   Math: '<S162>/Math Function1'
  //   RelationalOperator: '<S166>/Compare'

  if (std::abs(rtb_TmpSignalConversionAtSFun_2) >
      FaultModel_P.CompareToConstant_const_i) {
    rtb_TmpSignalConversionAtSFun_2 = rt_modd_snf
      (rtb_TmpSignalConversionAtSFun_2 + FaultModel_P.Bias_Bias_b,
       FaultModel_P.Constant2_Value_e) + FaultModel_P.Bias1_Bias_ms;
  }

  // End of Switch: '<S162>/Switch'

  // Sum: '<S69>/Sum1' incorporates:
  //   Constant: '<S61>/ModelParam.envAltitude'
  //   Integrator: '<S12>/xe,ye,ze'
  //   UnaryMinus: '<S69>/Ze2height'

  rtb_Saturation_1 = -FaultModel_X.xeyeze_CSTATE[2] -
    FaultModel_P.ModelParam_envAltitude;

  // Saturate: '<S61>/Saturation_1'
  if (rtb_Saturation_1 > FaultModel_P.Saturation_1_UpperSat) {
    rtb_Saturation_1 = FaultModel_P.Saturation_1_UpperSat;
  } else {
    if (rtb_Saturation_1 < FaultModel_P.Saturation_1_LowerSat) {
      rtb_Saturation_1 = FaultModel_P.Saturation_1_LowerSat;
    }
  }

  // End of Saturate: '<S61>/Saturation_1'

  // Saturate: '<S412>/Limit  altitude  to Stratosphere' incorporates:
  //   Selector: '<S76>/Selector2'
  //   SignalConversion generated from: '<Root>/MavVehile3DInfo'
  //   UnitConversion: '<S180>/Unit Conversion'

  rtb_LimitaltitudetoStratosphere = rtb_uavlostMass;

  // Unit Conversion - from: deg to: rad
  // Expression: output = (0.0174533*input) + (0)
  rtb_LimitaltitudetoStratosphere *= 0.017453292519943295;

  // Product: '<S294>/Product2' incorporates:
  //   Selector: '<S76>/Selector1'
  //   SignalConversion generated from: '<Root>/MavVehile3DInfo'
  //   UnitConversion: '<S182>/Unit Conversion'

  rtb_Product2_l = rtb_TmpSignalConversionAtSFun_2;

  // Unit Conversion - from: deg to: rad
  // Expression: output = (0.0174533*input) + (0)
  rtb_Product2_l *= 0.017453292519943295;

  // Product: '<S54>/j x i' incorporates:
  //   Selector: '<S76>/Selector'
  //   SignalConversion generated from: '<Root>/MavVehile3DInfo'

  rtb_jxi = rtb_Saturation_1;

  // S-Function (saerogravity2): '<S76>/WGS84 Gravity S-Function' incorporates:
  //   Constant: '<S76>/Julian Date'


  // S-Function Block: <S76>/WGS84 Gravity S-Function
  {
    int_T i;
    real_T GM, opt_m2ft, deg2rad;
    real_T *phi_ptr, *height_ptr;
    boolean_T phi_wrapped = false;
    real_T *phi = (real_T *) &FaultModel_DW.WGS84GravitySFunction_phi;
    real_T *h = (real_T *) &FaultModel_DW.WGS84GravitySFunction_h;
    height_ptr = (real_T *) &rtb_jxi;
    phi_ptr = (real_T *) &rtb_LimitaltitudetoStratosphere;

    // get unit conversion factor
    opt_m2ft = 1.0;
    deg2rad = 1.0;

    // Use Earth's Atmosphere in Gravitational Const?
    GM = ( 1.0 == 0 ) ? WGS84_GM_DEF : WGS84_GM_PRM;

    // WGS84TAYLORSERIES
    {
      for (i = 0; i < 1; i++ ) {
        real_T fphi, pi_2;

        // create short variables for latitude (phi) and height (h)
        phi[i] = phi_ptr[i] * deg2rad;
        h[i] = height_ptr[i] / opt_m2ft;
        if (phi[i] > AERO_PI || phi[i] < -AERO_PI) {
          phi[i] = std::fmod(phi[i]+AERO_PI, 2.0*AERO_PI) - AERO_PI;
        }

        fphi = std::abs(phi[i]);
        pi_2 = AERO_PI/2.0;
        if (fphi > pi_2 ) {
          real_T sign = phi[i]/fphi;
          phi_wrapped = true;
          phi[i] = sign*(pi_2 - (fphi - pi_2));
        } else {
          phi_wrapped = false;
        }
      }

      wgs84_taylor_series(h, phi, opt_m2ft, &FaultModel_B.MatrixConcatenate[2],
                          1);

      // north and east components are zero
      FaultModel_B.MatrixConcatenate[0] =
        FaultModel_DW.WGS84GravitySFunction_gamma_phi;
      FaultModel_B.MatrixConcatenate[1] =
        FaultModel_DW.WGS84GravitySFunction_gamma_phi;
    }
  }

  for (i = 0; i < 3; i++) {
    // Product: '<S7>/Product1'
    Product1[i] = FaultModel_B.m * FaultModel_B.MatrixConcatenate[i];

    // Product: '<S20>/Product' incorporates:
    //   Concatenate: '<S34>/Vector Concatenate'
    //   Integrator: '<S12>/ub,vb,wb'
    //   Math: '<S12>/Transpose'

    FaultModel_B.Product[i] = 0.0;
    FaultModel_B.Product[i] += VectorConcatenate[3 * i] *
      FaultModel_X.ubvbwb_CSTATE[0];
    FaultModel_B.Product[i] += VectorConcatenate[3 * i + 1] *
      FaultModel_X.ubvbwb_CSTATE[1];
    FaultModel_B.Product[i] += VectorConcatenate[3 * i + 2] *
      FaultModel_X.ubvbwb_CSTATE[2];
  }

  // Product: '<S54>/j x i' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'
  //   Product: '<S45>/Product'

  rtb_jxi = FaultModel_X.q0q1q2q3_CSTATE[0] * FaultModel_X.q0q1q2q3_CSTATE[0];

  // Saturate: '<S412>/Limit  altitude  to Stratosphere' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'
  //   Product: '<S45>/Product1'

  rtb_LimitaltitudetoStratosphere = FaultModel_X.q0q1q2q3_CSTATE[1] *
    FaultModel_X.q0q1q2q3_CSTATE[1];

  // Product: '<S294>/Product2' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'
  //   Product: '<S45>/Product2'

  rtb_Product2_l = FaultModel_X.q0q1q2q3_CSTATE[2] *
    FaultModel_X.q0q1q2q3_CSTATE[2];

  // Product: '<S54>/j x i' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'
  //   Product: '<S45>/Product3'
  //   Sqrt: '<S44>/sqrt'
  //   Sum: '<S45>/Sum'

  rtb_jxi = ((rtb_jxi + rtb_LimitaltitudetoStratosphere) + rtb_Product2_l) +
    FaultModel_X.q0q1q2q3_CSTATE[3] * FaultModel_X.q0q1q2q3_CSTATE[3];
  rtb_jxi = std::sqrt(rtb_jxi);

  // Product: '<S39>/Product' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'

  rtb_q3dot = FaultModel_X.q0q1q2q3_CSTATE[0] / rtb_jxi;

  // Saturate: '<S412>/Limit  altitude  to Stratosphere' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'
  //   Product: '<S39>/Product1'

  rtb_LimitaltitudetoStratosphere = FaultModel_X.q0q1q2q3_CSTATE[1] / rtb_jxi;

  // Product: '<S294>/Product2' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'
  //   Product: '<S39>/Product2'

  rtb_Product2_l = FaultModel_X.q0q1q2q3_CSTATE[2] / rtb_jxi;

  // Product: '<S54>/j x i' incorporates:
  //   Integrator: '<S13>/q0 q1 q2 q3'
  //   Product: '<S39>/Product3'

  rtb_jxi = FaultModel_X.q0q1q2q3_CSTATE[3] / rtb_jxi;

  // Fcn: '<S22>/fcn2' incorporates:
  //   Fcn: '<S22>/fcn5'

  VectorConcatenate_n_idx_2 = rtb_q3dot * rtb_q3dot;
  rtb_Add = rtb_LimitaltitudetoStratosphere * rtb_LimitaltitudetoStratosphere;
  massOb = rtb_jxi * rtb_jxi;

  // Trigonometry: '<S38>/Trigonometric Function1' incorporates:
  //   Fcn: '<S22>/fcn1'
  //   Fcn: '<S22>/fcn2'

  VectorConcatenate_n_idx_0 = rt_atan2d_snf((rtb_LimitaltitudetoStratosphere *
    rtb_Product2_l + rtb_q3dot * rtb_jxi) * 2.0, ((VectorConcatenate_n_idx_2 +
    rtb_Add) - rtb_Product2_l * rtb_Product2_l) - massOb);

  // Fcn: '<S22>/fcn3'
  uavlostJyz = (rtb_LimitaltitudetoStratosphere * rtb_jxi - rtb_q3dot *
                rtb_Product2_l) * -2.0;

  // If: '<S40>/If'
  if (rtmIsMajorTimeStep((&FaultModel_M))) {
    if (uavlostJyz > 1.0) {
      rtAction = 0;
    } else if (uavlostJyz < -1.0) {
      rtAction = 1;
    } else {
      rtAction = 2;
    }

    FaultModel_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = FaultModel_DW.If_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    // Outputs for IfAction SubSystem: '<S40>/If Action Subsystem' incorporates:
    //   ActionPort: '<S41>/Action Port'

    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
      // Merge: '<S40>/Merge' incorporates:
      //   Constant: '<S41>/Constant'

      FaultModel_B.Merge_e = FaultModel_P.Constant_Value;
    }

    // End of Outputs for SubSystem: '<S40>/If Action Subsystem'
    break;

   case 1:
    // Outputs for IfAction SubSystem: '<S40>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S42>/Action Port'

    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
      // Merge: '<S40>/Merge' incorporates:
      //   Constant: '<S42>/Constant'

      FaultModel_B.Merge_e = FaultModel_P.Constant_Value_l;
    }

    // End of Outputs for SubSystem: '<S40>/If Action Subsystem1'
    break;

   case 2:
    // Outputs for IfAction SubSystem: '<S40>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S43>/Action Port'

    // Merge: '<S40>/Merge' incorporates:
    //   Inport: '<S43>/In'

    FaultModel_B.Merge_e = uavlostJyz;

    // End of Outputs for SubSystem: '<S40>/If Action Subsystem2'
    break;
  }

  // End of If: '<S40>/If'

  // Trigonometry: '<S38>/trigFcn'
  if (FaultModel_B.Merge_e > 1.0) {
    rtb_wind_idx_0 = 1.0;
  } else if (FaultModel_B.Merge_e < -1.0) {
    rtb_wind_idx_0 = -1.0;
  } else {
    rtb_wind_idx_0 = FaultModel_B.Merge_e;
  }

  VectorConcatenate_n_idx_1 = std::asin(rtb_wind_idx_0);

  // End of Trigonometry: '<S38>/trigFcn'

  // Trigonometry: '<S38>/Trigonometric Function3' incorporates:
  //   Fcn: '<S22>/fcn4'
  //   Fcn: '<S22>/fcn5'

  VectorConcatenate_n_idx_2 = rt_atan2d_snf((rtb_Product2_l * rtb_jxi +
    rtb_q3dot * rtb_LimitaltitudetoStratosphere) * 2.0,
    ((VectorConcatenate_n_idx_2 - rtb_Add) - rtb_Product2_l * rtb_Product2_l) +
    massOb);

  // Trigonometry: '<S193>/sincos' incorporates:
  //   MATLAB Function: '<S7>/OnGroundFaceup'
  //   SignalConversion generated from: '<S195>/ SFunction '

  // MATLAB Function 'Force and Moment Model/OnGroundFaceup': '<S195>:1'
  // '<S195>:1:3' targetRoll = 0;
  //  if cos(EulerAng(1))<0
  //      targetRoll=pi;
  //  end
  // '<S195>:1:8' targetPitch = 0;
  //  if cos(EulerAng(2))<0
  //          targetPitch=pi;
  //  end
  // '<S195>:1:13' y = [targetRoll;targetPitch;EulerAng(3)];
  rtb_Wind[0] = 1.0;
  rtb_Wind[1] = 1.0;
  rtb_Sum1_ki[2] = std::sin(VectorConcatenate_n_idx_0);
  rtb_Wind[2] = std::cos(VectorConcatenate_n_idx_0);

  // Product: '<S276>/u(5)*u(6)'
  VectorConcatenate_p[0] = rtb_Wind[1] * rtb_Wind[2];

  // Sum: '<S279>/Sum' incorporates:
  //   Product: '<S279>/u(3)*u(4)'
  //   Product: '<S279>/u(6)*u(1)*u(2)'

  VectorConcatenate_p[1] = rtb_Wind[2] * 0.0 * 0.0 - rtb_Sum1_ki[2] * rtb_Wind[0];

  // Sum: '<S282>/Sum' incorporates:
  //   Product: '<S282>/u(1)*u(3)'
  //   Product: '<S282>/u(2)*u(4)*u(6)'

  VectorConcatenate_p[2] = 0.0 * rtb_Wind[0] * rtb_Wind[2] + 0.0 * rtb_Sum1_ki[2];

  // Product: '<S277>/u(3)*u(5)'
  VectorConcatenate_p[3] = rtb_Sum1_ki[2] * rtb_Wind[1];

  // Sum: '<S280>/Sum' incorporates:
  //   Product: '<S280>/u(1)*u(2)*u(3)'
  //   Product: '<S280>/u(4)*u(6)'

  VectorConcatenate_p[4] = 0.0 * rtb_Sum1_ki[2] + rtb_Wind[0] * rtb_Wind[2];

  // Sum: '<S283>/Sum' incorporates:
  //   Product: '<S283>/u(1)*u(6)'
  //   Product: '<S283>/u(2)*u(3)*u(4)'

  VectorConcatenate_p[5] = 0.0 * rtb_Sum1_ki[2] * rtb_Wind[0] - 0.0 * rtb_Wind[2];

  // UnaryMinus: '<S278>/Unary Minus'
  VectorConcatenate_p[6] = -0.0;

  // Product: '<S281>/u(1)*u(5)'
  VectorConcatenate_p[7] = 0.0 * rtb_Wind[1];

  // Product: '<S284>/u(4)*u(5)'
  VectorConcatenate_p[8] = rtb_Wind[0] * rtb_Wind[1];

  // Sum: '<S241>/Add'
  rtb_Add = (VectorConcatenate_p[0] + VectorConcatenate_p[4]) +
    VectorConcatenate_p[8];

  // If: '<S192>/If'
  if (rtmIsMajorTimeStep((&FaultModel_M))) {
    rtAction = static_cast<int8_T>(!(rtb_Add > 0.0));
    FaultModel_DW.If_ActiveSubsystem_h = rtAction;
  } else {
    rtAction = FaultModel_DW.If_ActiveSubsystem_h;
  }

  switch (rtAction) {
   case 0:
    // Outputs for IfAction SubSystem: '<S192>/Positive Trace' incorporates:
    //   ActionPort: '<S239>/Action Port'

    FaultModel_PositiveTrace(rtb_Add, VectorConcatenate_p, &FaultModel_B.Merge[0],
      &FaultModel_B.Merge[1], &FaultModel_P.PositiveTrace_d);

    // End of Outputs for SubSystem: '<S192>/Positive Trace'
    break;

   case 1:
    // Outputs for IfAction SubSystem: '<S192>/Negative Trace' incorporates:
    //   ActionPort: '<S238>/Action Port'

    FaultModel_NegativeTrace(VectorConcatenate_p, FaultModel_B.Merge,
      &FaultModel_DW.NegativeTrace_d, &FaultModel_P.NegativeTrace_d);

    // End of Outputs for SubSystem: '<S192>/Negative Trace'
    break;
  }

  // End of If: '<S192>/If'

  // Product: '<S54>/j x i' incorporates:
  //   Product: '<S290>/Product3'

  rtb_jxi = FaultModel_B.Merge[3] * FaultModel_B.Merge[3];

  // Sum: '<S290>/Sum' incorporates:
  //   Product: '<S290>/Product'
  //   Product: '<S290>/Product1'
  //   Product: '<S290>/Product2'

  uavlostJyz = ((FaultModel_B.Merge[0] * FaultModel_B.Merge[0] +
                 FaultModel_B.Merge[1] * FaultModel_B.Merge[1]) +
                FaultModel_B.Merge[2] * FaultModel_B.Merge[2]) + rtb_jxi;

  // Product: '<S198>/Divide'
  rtb_q2dot = FaultModel_B.Merge[0] / uavlostJyz;

  // Sum: '<S203>/Add' incorporates:
  //   Sum: '<S335>/Add'

  rtb_TmpSignalConversionAtSFun_0 = (VectorConcatenate[0] + VectorConcatenate[4])
    + VectorConcatenate[8];

  // If: '<S191>/If' incorporates:
  //   Sum: '<S203>/Add'

  if (rtmIsMajorTimeStep((&FaultModel_M))) {
    rtAction = static_cast<int8_T>(!(rtb_TmpSignalConversionAtSFun_0 > 0.0));
    FaultModel_DW.If_ActiveSubsystem_l = rtAction;
  } else {
    rtAction = FaultModel_DW.If_ActiveSubsystem_l;
  }

  switch (rtAction) {
   case 0:
    // Outputs for IfAction SubSystem: '<S191>/Positive Trace' incorporates:
    //   ActionPort: '<S201>/Action Port'

    FaultModel_PositiveTrace(rtb_TmpSignalConversionAtSFun_0, VectorConcatenate,
      &FaultModel_B.Merge_c[0], &FaultModel_B.Merge_c[1],
      &FaultModel_P.PositiveTrace);

    // End of Outputs for SubSystem: '<S191>/Positive Trace'
    break;

   case 1:
    // Outputs for IfAction SubSystem: '<S191>/Negative Trace' incorporates:
    //   ActionPort: '<S200>/Action Port'

    FaultModel_NegativeTrace(VectorConcatenate, FaultModel_B.Merge_c,
      &FaultModel_DW.NegativeTrace, &FaultModel_P.NegativeTrace);

    // End of Outputs for SubSystem: '<S191>/Negative Trace'
    break;
  }

  // End of If: '<S191>/If'

  // Product: '<S54>/j x i' incorporates:
  //   Product: '<S198>/Divide1'
  //   UnaryMinus: '<S289>/Unary Minus'

  rtb_jxi = -FaultModel_B.Merge[1];
  rtb_jxi /= uavlostJyz;

  // Product: '<S294>/Product2' incorporates:
  //   Product: '<S198>/Divide2'
  //   UnaryMinus: '<S289>/Unary Minus1'

  rtb_Product2_l = -FaultModel_B.Merge[2];
  rtb_Product2_l /= uavlostJyz;

  // Product: '<S198>/Divide3' incorporates:
  //   UnaryMinus: '<S289>/Unary Minus2'

  uavlostJzx = -FaultModel_B.Merge[3] / uavlostJyz;

  // Saturate: '<S412>/Limit  altitude  to Stratosphere' incorporates:
  //   Product: '<S292>/Product3'

  rtb_LimitaltitudetoStratosphere = uavlostJzx * FaultModel_B.Merge_c[2];

  // Sum: '<S292>/Sum' incorporates:
  //   Product: '<S292>/Product'
  //   Product: '<S292>/Product1'
  //   Product: '<S292>/Product2'

  rtb_Add = ((rtb_q2dot * FaultModel_B.Merge_c[1] + rtb_jxi *
              FaultModel_B.Merge_c[0]) + rtb_Product2_l * FaultModel_B.Merge_c[3])
    - rtb_LimitaltitudetoStratosphere;

  // Product: '<S293>/Product'
  uavlostJxy = rtb_q2dot * FaultModel_B.Merge_c[2];

  // Product: '<S293>/Product1'
  uavlostJyz = rtb_jxi * FaultModel_B.Merge_c[3];

  // Product: '<S293>/Product2'
  rtb_q3dot = rtb_Product2_l * FaultModel_B.Merge_c[0];

  // Saturate: '<S412>/Limit  altitude  to Stratosphere' incorporates:
  //   Product: '<S293>/Product3'

  rtb_LimitaltitudetoStratosphere = uavlostJzx * FaultModel_B.Merge_c[1];

  // Product: '<S294>/Product'
  rtb_q2dot *= FaultModel_B.Merge_c[3];

  // Product: '<S54>/j x i' incorporates:
  //   Product: '<S294>/Product1'

  rtb_jxi *= FaultModel_B.Merge_c[2];

  // Product: '<S294>/Product2'
  rtb_Product2_l *= FaultModel_B.Merge_c[1];

  // Product: '<S294>/Product3'
  uavlostJzx *= FaultModel_B.Merge_c[0];
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 20; i++) {
      // DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
      //   Inport: '<Root>/inFloatsCollision'

      FaultModel_B.DataTypeConversion2[i] = FaultModel_U.inFloatsCollision[i];
    }

    // MATLAB Function: '<Root>/CollisionDetection' incorporates:
    //   Concatenate: '<S34>/Vector Concatenate'

    //  vect=[1;1;1;1;1;1;1;1];
    // 是否碰撞标志位
    // MATLAB Function 'CollisionDetection': '<S3>:1'
    // '<S3>:1:6' if isempty(isCol)
    // 输出力和力矩暂存向量
    // '<S3>:1:12' if isempty(fOut)
    // 碰撞冲量矩阵
    // '<S3>:1:18' if isempty(mv0)
    // 碰撞时间
    // '<S3>:1:24' if isempty(tColi)
    // 如果没有发送碰撞
    // '<S3>:1:29' if isCol<0.5
    if ((FaultModel_DW.isCol < 0.5) && (std::abs
         (FaultModel_B.DataTypeConversion2[0] - 12345.0) < 1.0) &&
        (FaultModel_B.DataTypeConversion2[1] > 0.5)) {
      // 如果收到碰撞消息，且被碰撞物体为编号飞机（带CopterID的值大于0）
      // '<S3>:1:31' if abs(uFloats(1)-12345)<1 && uFloats(2)>0.5
      // 如果收到碰撞消息，12345是数据校验位，uFloats(2)是碰撞到飞机的ID
      // '<S3>:1:32' isCol=int8(1);
      FaultModel_DW.isCol = 1;

      // 设置为碰撞模式
      // 被碰撞物体是活动的还是固定的
      // '<S3>:1:34' if uFloats(3)>0
      if (FaultModel_B.DataTypeConversion2[2] > 0.0) {
        // 被碰撞物与本物体的质量比有正值，说明碰撞物也是飞机，需要用冲量定理
        // '<S3>:1:35' massOb=mass*uFloats(3)^2;
        massOb = FaultModel_B.DataTypeConversion2[2] *
          FaultModel_B.DataTypeConversion2[2] * FaultModel_B.m;

        // '<S3>:1:36' veOb = uFloats(7:9);
        // '<S3>:1:37' veNew=(mass*ve+massOb*veOb)/(mass+massOb);
        rtb_wind_idx_0 = FaultModel_B.m + massOb;
        FaultModel_DW.mv0[0] = (FaultModel_B.m * FaultModel_B.Product[0] +
          massOb * FaultModel_B.DataTypeConversion2[6]) / rtb_wind_idx_0;
        FaultModel_DW.mv0[1] = (FaultModel_B.m * FaultModel_B.Product[1] +
          massOb * FaultModel_B.DataTypeConversion2[7]) / rtb_wind_idx_0;
        FaultModel_DW.mv0[2] = (FaultModel_B.m * FaultModel_B.Product[2] +
          massOb * FaultModel_B.DataTypeConversion2[8]) / rtb_wind_idx_0;
      } else {
        // '<S3>:1:38' else
        // 被碰撞物为树、房子等固定物体，质量无穷大，直接反弹回去（1/10的速度）
        // '<S3>:1:39' veNew=-ve/10.0;
        FaultModel_DW.mv0[0] = -FaultModel_B.Product[0] / 10.0;
        FaultModel_DW.mv0[1] = -FaultModel_B.Product[1] / 10.0;
        FaultModel_DW.mv0[2] = -FaultModel_B.Product[2] / 10.0;
      }

      // '<S3>:1:42' mv0=mass*(veNew-ve);
      FaultModel_DW.mv0[0] = (FaultModel_DW.mv0[0] - FaultModel_B.Product[0]) *
        FaultModel_B.m;
      FaultModel_DW.mv0[1] = (FaultModel_DW.mv0[1] - FaultModel_B.Product[1]) *
        FaultModel_B.m;
      FaultModel_DW.mv0[2] = (FaultModel_DW.mv0[2] - FaultModel_B.Product[2]) *
        FaultModel_B.m;

      // '<S3>:1:43' tColi=t;
      FaultModel_DW.tColi = rtb_Clock1_tmp;

      // 记录碰撞时间
    }

    // 如果已经发生碰撞
    // '<S3>:1:48' if isCol>=0.5
    if (FaultModel_DW.isCol >= 0.5) {
      // '<S3>:1:49' if (t-tColi)>0.05
      if (rtb_Clock1_tmp - FaultModel_DW.tColi > 0.05) {
        // '<S3>:1:50' fOut=[0;0;0;0;0;0];
        for (i = 0; i < 6; i++) {
          FaultModel_DW.fOut[i] = 0.0;
        }
      } else {
        // '<S3>:1:51' else
        // 用瞬时的作用力模拟冲量作用（0.05s）
        // '<S3>:1:53' mv=DCM*mv0;
        for (qY_1 = 0; qY_1 < 3; qY_1++) {
          rtb_Sum1_ki[qY_1] = VectorConcatenate[qY_1 + 6] * FaultModel_DW.mv0[2]
            + (VectorConcatenate[qY_1 + 3] * FaultModel_DW.mv0[1] +
               VectorConcatenate[qY_1] * FaultModel_DW.mv0[0]);
        }

        // '<S3>:1:54' mv(1)=mv(1)*(0.7+0.3*rand());
        rtb_Sum1_ki[0] *= 0.3 * FaultModel_rand() + 0.7;

        // '<S3>:1:55' mv(2)=mv(2)*(0.7+0.3*rand());
        rtb_Sum1_ki[1] *= 0.3 * FaultModel_rand() + 0.7;

        // '<S3>:1:56' mv(3)=mv(3)*(0.7+0.3*rand());
        rtb_Sum1_ki[2] *= 0.3 * FaultModel_rand() + 0.7;

        // '<S3>:1:57' fOut(1:3) = mv/0.05;
        FaultModel_DW.fOut[0] = rtb_Sum1_ki[0] / 0.05;
        FaultModel_DW.fOut[1] = rtb_Sum1_ki[1] / 0.05;
        FaultModel_DW.fOut[2] = rtb_Sum1_ki[2] / 0.05;

        // 冲量除以时间得到力
        // '<S3>:1:58' fOut(4:6) = rand(3,1)*mass;
        FaultModel_rand_k(rtb_Sum1_ki);
        FaultModel_DW.fOut[3] = rtb_Sum1_ki[0] * FaultModel_B.m;
        FaultModel_DW.fOut[4] = rtb_Sum1_ki[1] * FaultModel_B.m;
        FaultModel_DW.fOut[5] = rtb_Sum1_ki[2] * FaultModel_B.m;
      }
    }

    // 下面处理飞机与场景固定物体之间的碰撞
    // '<S3>:1:63' fm = fOut;
    // tz分别表示距地面高度和飞机XYZ坐标
    // '<S3>:1:65' tz=[100;0;0;0];
    tz_idx_0 = 100.0;
    tz_idx_3 = 0.0;

    // '<S3>:1:66' ddm=[0;0;0;0;0;0];
    for (i = 0; i < 6; i++) {
      ddm[i] = 0.0;
    }

    // '<S3>:1:67' if abs(uFloats(1)-12345)<1
    if (std::abs(FaultModel_B.DataTypeConversion2[0] - 12345.0) < 1.0) {
      // 如果收到碰撞消息
      // '<S3>:1:68' kRa=40;
      // '<S3>:1:69' kRaVe=5;
      // '<S3>:1:70' if uFloats(2)<0.5
      if (FaultModel_B.DataTypeConversion2[1] < 0.5) {
        // 如果碰撞的是场景固定物体
        // 向下照射射线返回长度
        // '<S3>:1:72' tz(1)=uFloats(15);
        tz_idx_0 = FaultModel_B.DataTypeConversion2[14];

        // 飞机在UE4中的坐标
        // '<S3>:1:74' tz(2:4)=uFloats(4:6);
        tz_idx_3 = FaultModel_B.DataTypeConversion2[5];
      } else {
        // '<S3>:1:75' else
        // '<S3>:1:76' kRa=20;
      }

      // 前后左右是以地面坐标系的北东地为准
      // 前障碍物碰撞反馈力
      // '<S3>:1:80' if uFloats(10)<0
      if (FaultModel_B.DataTypeConversion2[9] < 0.0) {
        // 距前墙面距离，小于0说明已经接触
        // '<S3>:1:81' z=uFloats(10);
        // '<S3>:1:82' if z>-0.01
        if (FaultModel_B.DataTypeConversion2[9] > -0.01) {
          // '<S3>:1:83' ddm(1)=-10*ve(1);
          ddm[0] = -10.0 * FaultModel_B.Product[0];
        } else if (FaultModel_B.DataTypeConversion2[9] > -0.04) {
          // '<S3>:1:84' elseif z>-0.04
          // '<S3>:1:85' ddm(1)=200*z-20*ve(1);
          ddm[0] = 200.0 * FaultModel_B.DataTypeConversion2[9] - 20.0 *
            FaultModel_B.Product[0];
        } else {
          // '<S3>:1:86' else
          // '<S3>:1:87' ddm(1)=500*z-50*ve(1);
          ddm[0] = 500.0 * FaultModel_B.DataTypeConversion2[9] - 50.0 *
            FaultModel_B.Product[0];
        }
      }

      // 后障碍物碰撞反馈力
      // '<S3>:1:91' if uFloats(11)<0
      if (FaultModel_B.DataTypeConversion2[10] < 0.0) {
        //          ddm(1)=-uFloats(11)*mass*kRa;
        //          if ve(1)<0
        //              ddm(1)=ddm(1)-ve(1)*mass*kRaVe;
        //          end
        // '<S3>:1:96' z=uFloats(11);
        // '<S3>:1:97' if z>-0.01
        if (FaultModel_B.DataTypeConversion2[10] > -0.01) {
          // '<S3>:1:98' ddm(1)=-10*ve(1);
          ddm[0] = -10.0 * FaultModel_B.Product[0];
        } else if (FaultModel_B.DataTypeConversion2[10] > -0.04) {
          // '<S3>:1:99' elseif z>-0.04
          // '<S3>:1:100' ddm(1)=-200*z-20*ve(1);
          ddm[0] = -200.0 * FaultModel_B.DataTypeConversion2[10] - 20.0 *
            FaultModel_B.Product[0];
        } else {
          // '<S3>:1:101' else
          // '<S3>:1:102' ddm(1)=-500*z-50*ve(1);
          ddm[0] = -500.0 * FaultModel_B.DataTypeConversion2[10] - 50.0 *
            FaultModel_B.Product[0];
        }
      }

      // 左障碍物碰撞反馈力
      // '<S3>:1:107' if uFloats(12)<0
      if (FaultModel_B.DataTypeConversion2[11] < 0.0) {
        //          ddm(2)=-uFloats(12)*mass*kRa;
        //          if ve(2)<0
        //              ddm(2)=ddm(2)-ve(2)*mass*kRaVe;
        //          end
        // '<S3>:1:112' z=uFloats(12);
        // '<S3>:1:113' if z>-0.01
        if (FaultModel_B.DataTypeConversion2[11] > -0.01) {
          // '<S3>:1:114' ddm(2)=-10*ve(2);
          ddm[1] = -10.0 * FaultModel_B.Product[1];
        } else if (FaultModel_B.DataTypeConversion2[11] > -0.04) {
          // '<S3>:1:115' elseif z>-0.04
          // '<S3>:1:116' ddm(2)=-200*z-20*ve(2);
          ddm[1] = -200.0 * FaultModel_B.DataTypeConversion2[11] - 20.0 *
            FaultModel_B.Product[1];
        } else {
          // '<S3>:1:117' else
          // '<S3>:1:118' ddm(2)=-500*z-50*ve(2);
          ddm[1] = -500.0 * FaultModel_B.DataTypeConversion2[11] - 50.0 *
            FaultModel_B.Product[1];
        }
      }

      // 右障碍物碰撞反馈力
      // '<S3>:1:122' if uFloats(13)<0
      if (FaultModel_B.DataTypeConversion2[12] < 0.0) {
        //          ddm(2)=uFloats(13)*mass*kRa;
        //          if ve(2)>0
        //              ddm(2)=ddm(2)-ve(2)*mass*kRaVe;
        //          end
        // '<S3>:1:127' z=uFloats(13);
        // '<S3>:1:128' if z>-0.01
        if (FaultModel_B.DataTypeConversion2[12] > -0.01) {
          // '<S3>:1:129' ddm(2)=-10*ve(2);
          ddm[1] = -10.0 * FaultModel_B.Product[1];
        } else if (FaultModel_B.DataTypeConversion2[12] > -0.04) {
          // '<S3>:1:130' elseif z>-0.04
          // '<S3>:1:131' ddm(2)=200*z-20*ve(2);
          ddm[1] = 200.0 * FaultModel_B.DataTypeConversion2[12] - 20.0 *
            FaultModel_B.Product[1];
        } else {
          // '<S3>:1:132' else
          // '<S3>:1:133' ddm(2)=500*z-50*ve(2);
          ddm[1] = 500.0 * FaultModel_B.DataTypeConversion2[12] - 50.0 *
            FaultModel_B.Product[1];
        }
      }

      // 上障碍物碰撞反馈力
      // '<S3>:1:138' if uFloats(14)<0
      if (FaultModel_B.DataTypeConversion2[13] < 0.0) {
        //          ddm(3)=-uFloats(14)*mass*kRa;
        //          if ve(3)<0
        //              ddm(3)=ddm(3)-ve(3)*mass*kRaVe;
        //          end
        // '<S3>:1:144' z=uFloats(14);
        // '<S3>:1:145' if z>-0.01
        if (FaultModel_B.DataTypeConversion2[13] > -0.01) {
          // '<S3>:1:146' ddm(3)=-10*ve(3);
          ddm[2] = -10.0 * FaultModel_B.Product[2];
        } else if (FaultModel_B.DataTypeConversion2[13] > -0.04) {
          // '<S3>:1:147' elseif z>-0.04
          // '<S3>:1:148' ddm(3)=-200*z-20*ve(3);
          ddm[2] = -200.0 * FaultModel_B.DataTypeConversion2[13] - 20.0 *
            FaultModel_B.Product[2];
        } else {
          // '<S3>:1:149' else
          // '<S3>:1:150' ddm(3)=-500*z-50*ve(3);
          ddm[2] = -500.0 * FaultModel_B.DataTypeConversion2[13] - 50.0 *
            FaultModel_B.Product[2];
        }
      }
    }

    // 力从地面坐标系映射机体坐标系
    // '<S3>:1:155' ddmm=DCM*ddm(1:3);
    // '<S3>:1:156' fm=fm+[ddmm;0;0;0];
    // '<S3>:1:158' isCrash=isCol;
    for (qY_1 = 0; qY_1 < 3; qY_1++) {
      FaultModel_B.fm[qY_1] = ((VectorConcatenate[qY_1 + 3] * ddm[1] +
        VectorConcatenate[qY_1] * ddm[0]) + VectorConcatenate[qY_1 + 6] * ddm[2])
        + FaultModel_DW.fOut[qY_1];
    }

    FaultModel_B.fm[3] = FaultModel_DW.fOut[3];
    FaultModel_B.fm[4] = FaultModel_DW.fOut[4];
    FaultModel_B.fm[5] = FaultModel_DW.fOut[5];
    FaultModel_B.isCrash = FaultModel_DW.isCol;

    // End of MATLAB Function: '<Root>/CollisionDetection'

    // MATLAB Function: '<Root>/MATLAB Function' incorporates:
    //   Inport: '<Root>/TerrainZ'

    // MATLAB Function 'MATLAB Function': '<S8>:1'
    // '<S8>:1:2' y=TerrainZ;
    FaultModel_B.y_k = FaultModel_U.TerrainZ;

    // '<S8>:1:3' if tz(1)<=99
    if (tz_idx_0 <= 99.0) {
      // '<S8>:1:4' y=tz(4)+tz(1);
      FaultModel_B.y_k = tz_idx_3 + tz_idx_0;
    }

    // End of MATLAB Function: '<Root>/MATLAB Function'

    // MATLAB Function: '<S7>/Ground Model' incorporates:
    //   Integrator: '<S12>/p,q,r '
    //   Integrator: '<S12>/xe,ye,ze'
    //   SignalConversion generated from: '<S194>/ SFunction '
    //   Sum: '<S293>/Sum'
    //   Sum: '<S294>/Sum'

    //  persistent last;
    //  if isempty(last)
    //      last=TerrainZ;
    //  end
    //  y=TerrainZ;
    //  if tz(1)<10
    //      if tz(1)<0
    //          y=last;
    //      else
    //          y=tz(3)+tz(1);
    //      end
    //  end
    //  This is a ground model that can provides reaction force and reaction torque 
    // MATLAB Function 'Force and Moment Model/Ground Model': '<S194>:1'
    //  persistent z0;
    //  if isempty(z0)
    //       z0=0;
    //  end
    // '<S194>:1:10' if isempty(takeoffFlag)
    // '<S194>:1:15' if isempty(landFlag)
    // '<S194>:1:19' z=Xe(3)-terrainZ;
    rtb_TmpSignalConversionAtSFun_1 = FaultModel_X.xeyeze_CSTATE[2] -
      FaultModel_B.y_k;

    // '<S194>:1:21' if (z<-0.3)&&(Ve(3)<-0.1)&&(takeoffFlag<0.5)
    if ((rtb_TmpSignalConversionAtSFun_1 < -0.3) && (FaultModel_B.Product[2] <
         -0.1) && (FaultModel_DW.takeoffFlag < 0.5)) {
      // '<S194>:1:22' takeoffFlag=int8(1);
      FaultModel_DW.takeoffFlag = 1;

      // '<S194>:1:23' landFlag=int8(0);
      FaultModel_DW.landFlag = 0;
    }

    // '<S194>:1:26' if (z>-0.05)&&(Ve(3)>0.1)&&(landFlag<0.5)
    if ((rtb_TmpSignalConversionAtSFun_1 > -0.05) && (FaultModel_B.Product[2] >
         0.1) && (FaultModel_DW.landFlag < 0.5)) {
      // '<S194>:1:27' landFlag=int8(1);
      FaultModel_DW.landFlag = 1;

      // '<S194>:1:28' takeoffFlag=int8(0);
      FaultModel_DW.takeoffFlag = 0;
    }

    // '<S194>:1:31' takeoff = takeoffFlag;
    // '<S194>:1:32' landed = landFlag;
    rtb_landed = FaultModel_DW.landFlag;

    // '<S194>:1:35' F1=[0;0;0];
    // '<S194>:1:36' M1=[0;0;0];
    FaultModel_B.F1[0] = 0.0;
    FaultModel_B.M1[0] = 0.0;
    FaultModel_B.F1[1] = 0.0;
    FaultModel_B.M1[1] = 0.0;
    FaultModel_B.F1[2] = 0.0;
    FaultModel_B.M1[2] = 0.0;

    // '<S194>:1:38' if z>=0
    if (rtb_TmpSignalConversionAtSFun_1 >= 0.0) {
      //      if z>=0.3
      //          if Ve(3)>=5
      //              F1(3)=-mg(3)-1000*Ve(3);
      //          else
      //              F1(3)=-mg(3)-500*z-100*Ve(3);
      //          end
      //      elseif z>=0.1
      //          if Ve(3)>=2
      //              F1(3)=-mg(3)-100*Ve(3);
      //          else
      //              F1(3)=-mg(3)-50*z-100*Ve(3);
      //          end
      //      else
      //           if Ve(3)>=1
      //              F1(3)=-mg(3)-50*Ve(3);
      //          else
      //              F1(3)=-mg(3)-5*z-50*Ve(3);
      //          end
      //      end
      // '<S194>:1:58' if z<0.05
      if (rtb_TmpSignalConversionAtSFun_1 < 0.05) {
        // '<S194>:1:59' F1(3)=-mg(3)-10*Ve(3);
        FaultModel_B.F1[2] = -Product1[2] - 10.0 * FaultModel_B.Product[2];
      } else if (rtb_TmpSignalConversionAtSFun_1 < 0.1) {
        // '<S194>:1:60' elseif z<0.1
        // '<S194>:1:61' F1(3)=-mg(3)-0.5*z-20*Ve(3);
        FaultModel_B.F1[2] = (-Product1[2] - 0.5 *
                              rtb_TmpSignalConversionAtSFun_1) - 20.0 *
          FaultModel_B.Product[2];
      } else {
        // '<S194>:1:62' else
        // '<S194>:1:63' F1(3)=-mg(3)-1*z-50*Ve(3);
        FaultModel_B.F1[2] = (-Product1[2] - rtb_TmpSignalConversionAtSFun_1) -
          50.0 * FaultModel_B.Product[2];
      }

      // '<S194>:1:66' F1(1)=-50*Ve(1);
      FaultModel_B.F1[0] = -50.0 * FaultModel_B.Product[0];

      // '<S194>:1:67' F1(2)=-50*Ve(2);
      FaultModel_B.F1[1] = -50.0 * FaultModel_B.Product[1];

      //      if ~(isnan(Quet(2))||isnan(Quet(3))||isnan(Quet(4)))
      //          M1=-200*[Quet(2);Quet(3);Quet(4)]-10*wb;
      //      end
      // '<S194>:1:73' M1=-20*[Quet(2);Quet(3);Quet(4)]-5*wb;
      // '<S194>:1:74' M1 = M1 * abs(mg(3))*0.0333;
      rtb_TmpSignalConversionAtSFun_1 = std::abs(Product1[2]);
      FaultModel_B.M1[0] = (-20.0 * rtb_Add - 5.0 * FaultModel_X.pqr_CSTATE[0]) *
        rtb_TmpSignalConversionAtSFun_1 * 0.0333;
      FaultModel_B.M1[1] = ((((uavlostJxy - uavlostJyz) + rtb_q3dot) +
        rtb_LimitaltitudetoStratosphere) * -20.0 - 5.0 *
                            FaultModel_X.pqr_CSTATE[1]) *
        rtb_TmpSignalConversionAtSFun_1 * 0.0333;
      FaultModel_B.M1[2] = ((((rtb_q2dot + rtb_jxi) - rtb_Product2_l) +
        uavlostJzx) * -20.0 - 5.0 * FaultModel_X.pqr_CSTATE[2]) *
        rtb_TmpSignalConversionAtSFun_1 * 0.0333;
    }

    // End of MATLAB Function: '<S7>/Ground Model'
  }

  // Product: '<S61>/Product' incorporates:
  //   Sum: '<S7>/Add4'

  rtb_Wind[0] = FaultModel_B.F1[0] + Product1[0];
  rtb_Wind[1] = FaultModel_B.F1[1] + Product1[1];
  rtb_Wind[2] = FaultModel_B.F1[2] + Product1[2];

  // Product: '<S7>/Product' incorporates:
  //   Concatenate: '<S34>/Vector Concatenate'

  for (qY_1 = 0; qY_1 < 3; qY_1++) {
    rtb_Sum1_ki[qY_1] = VectorConcatenate[qY_1 + 6] * rtb_Wind[2] +
      (VectorConcatenate[qY_1 + 3] * rtb_Wind[1] + VectorConcatenate[qY_1] *
       rtb_Wind[0]);
  }

  // End of Product: '<S7>/Product'
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Constant: '<S300>/ModelInit_RPM'
    FaultModel_B.ModelInit_RPM = FaultModel_P.ModelInit_RPM;

    // MATLAB Function: '<S295>/FaultParamsExtract' incorporates:
    //   Constant: '<S295>/FaultID'
    //   Inport: '<Root>/inSILInts'

    // MATLAB Function 'Motor FaultModel/FaultModelTmp/FaultParamsExtract': '<S296>:1' 
    // '<S296>:1:5' if isempty(hFault)
    // '<S296>:1:8' if isempty(fParam)
    // '<S296>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S296>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S296>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S296>:1:15' count = 0;
    rtb_count_m = 0.0;

    // '<S296>:1:16' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S296>:1:17' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID_Value_f) {
        // '<S296>:1:18' hFaultTmp=true;
        hFaultTmp = true;

        // '<S296>:1:19' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S296>:1:20' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S296>:1:21' count = count + 1;
        rtb_count_m++;

        // '<S296>:1:22' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S296>:1:25' if hFaultTmp
    if (hFaultTmp) {
      // '<S296>:1:26' hFault=hFaultTmp;
      FaultModel_DW.hFault_g = true;

      // '<S296>:1:27' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S296>:1:28' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_b[0], &fParamTmp[0], 20U * sizeof(real_T));
    }

    // '<S296>:1:31' hasFault=hFault;
    rtb_hasFault_j = FaultModel_DW.hFault_g;

    // MATLAB Function: '<S295>/FaultParamsExtract1'
    // '<S296>:1:32' FaultParam=fParam;
    // MATLAB Function 'Motor FaultModel/FaultModelTmp/FaultParamsExtract1': '<S297>:1' 
    // '<S297>:1:5' if isempty(hFault)
    // '<S297>:1:8' if isempty(fParam)
    // '<S297>:1:11' count = 0;
    rtb_count = 0.0;

    // '<S297>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S297>:1:13' fParamTmp=zeros(20,1);
    for (i = 0; i < 20; i++) {
      // MATLAB Function: '<S295>/FaultParamsExtract'
      rtb_FaultParam_e5[i] = FaultModel_DW.fParam_b[i];

      // MATLAB Function: '<S295>/FaultParamsExtract1'
      fParamTmp[i] = 0.0;
    }

    // MATLAB Function: '<S295>/FaultParamsExtract1' incorporates:
    //   Constant: '<S295>/FaultID1'
    //   Inport: '<Root>/inSILInts'

    // '<S297>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S297>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S297>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID1_Value_f) {
        // '<S297>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S297>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        b_t = (r + 1) << 1;
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[b_t - 2];

        // '<S297>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] =
          inSILFloats[b_t - 1];

        // '<S297>:1:20' count = count + 1;
        rtb_count++;

        // '<S297>:1:21' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S297>:1:24' if hFaultTmp
    if (hFaultTmp) {
      // '<S297>:1:25' hFault=hFaultTmp;
      FaultModel_DW.hFault_m = true;

      // '<S297>:1:26' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S297>:1:27' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_n[0], &fParamTmp[0], 20U * sizeof(real_T));
    }

    // '<S297>:1:30' hasFault=hFault;
    rtb_hasFault = FaultModel_DW.hFault_m;

    // '<S297>:1:31' FaultParam=fParam;
    std::memcpy(&rtb_FaultParam_g[0], &FaultModel_DW.fParam_n[0], 20U * sizeof
                (real_T));

    // Memory: '<Root>/Memory'
    // MATLAB Function 'Crash_Motor_Fault': '<S4>:1'
    // '<S4>:1:2' y = u;
    std::memcpy(&Memory[0], &FaultModel_DW.Memory_PreviousInput[0], sizeof
                (real_T) << 3U);

    // MATLAB Function: '<Root>/Crash_Motor_Fault' incorporates:
    //   Memory: '<Root>/Memory'

    std::memcpy(&FaultModel_B.y_m[0], &FaultModel_DW.Memory_PreviousInput[0],
                sizeof(real_T) << 3U);

    // 如果飞机相撞则损坏三个电机
    // '<S4>:1:7' if isCrash>0.5
    if (FaultModel_B.isCrash > 0.5) {
      // '<S4>:1:8' y(1)=rand()/2.0;
      FaultModel_B.y_m[0] = FaultModel_rand_n() / 2.0;

      // '<S4>:1:9' y(2)=rand()/5.0;
      FaultModel_B.y_m[1] = FaultModel_rand_n() / 5.0;

      // '<S4>:1:10' y(3)=rand()/10.0+u(3)*0.9;
      FaultModel_B.y_m[2] = FaultModel_rand_n() / 10.0 + Memory[2] * 0.9;
    }

    // End of MATLAB Function: '<Root>/Crash_Motor_Fault'

    // MATLAB Function: '<S55>/FaultParamsExtract' incorporates:
    //   Constant: '<S55>/FaultID'
    //   Inport: '<Root>/inSILInts'

    // MATLAB Function 'Battery FaultModel/FaultModelTmp/FaultParamsExtract': '<S56>:1' 
    // '<S56>:1:5' if isempty(hFault)
    // '<S56>:1:8' if isempty(fParam)
    // '<S56>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S56>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S56>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S56>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S56>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID_Value_i) {
        // '<S56>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S56>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S56>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S56>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S56>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S56>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_j = true;

      // '<S56>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S56>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_h0[0], &fParamTmp[0], 20U * sizeof
                  (real_T));
    }

    // '<S56>:1:29' hasFault_isUseCustomHovTime=hFault;
    FaultModel_B.hasFault_isUseCustomHovTime = FaultModel_DW.hFault_j;

    // '<S56>:1:30' FaultParam=fParam;
    std::memcpy(&FaultModel_B.FaultParam_o[0], &FaultModel_DW.fParam_h0[0], 20U *
                sizeof(real_T));

    // End of MATLAB Function: '<S55>/FaultParamsExtract'

    // MATLAB Function: '<S55>/FaultParamsExtract1' incorporates:
    //   Constant: '<S55>/FaultID1'
    //   Inport: '<Root>/inSILInts'

    // MATLAB Function 'Battery FaultModel/FaultModelTmp/FaultParamsExtract1': '<S57>:1' 
    // '<S57>:1:5' if isempty(hFault)
    // '<S57>:1:8' if isempty(fParam)
    // '<S57>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S57>:1:13' fParamTmp=zeros(20,1);
    // '<S57>:1:14' j=1;
    // '<S57>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S57>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID1_Value_i) {
        // '<S57>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S57>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        // '<S57>:1:19' fParamTmp(2*j)=inFloats(2*i);
        // '<S57>:1:20' j=j+1;
      }
    }

    // '<S57>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S57>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_l1 = true;

      // '<S57>:1:25' fParamTmp(17:20) = inFloats(17:20);
      // '<S57>:1:26' fParam=fParamTmp;
    }

    // '<S57>:1:29' hasFault_isPowOff=hFault;
    FaultModel_B.hasFault_isPowOff = FaultModel_DW.hFault_l1;

    // End of MATLAB Function: '<S55>/FaultParamsExtract1'

    // MATLAB Function: '<S55>/FaultParamsExtract2' incorporates:
    //   Constant: '<S55>/FaultID2'
    //   Inport: '<Root>/inSILInts'

    // '<S57>:1:30' FaultParam=fParam;
    // MATLAB Function 'Battery FaultModel/FaultModelTmp/FaultParamsExtract2': '<S58>:1' 
    // '<S58>:1:5' if isempty(hFault)
    // '<S58>:1:8' if isempty(fParam)
    // '<S58>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S58>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S58>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S58>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S58>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID2_Value_n) {
        // '<S58>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S58>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        b_t = (r + 1) << 1;
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[b_t - 2];

        // '<S58>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] =
          inSILFloats[b_t - 1];

        // '<S58>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S58>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S58>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_hp = true;

      // '<S58>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S58>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_f[0], &fParamTmp[0], 20U * sizeof(real_T));
    }

    // '<S58>:1:29' hasFault_isLowVoltage=hFault;
    FaultModel_B.hasFault_isLowVoltage = FaultModel_DW.hFault_hp;

    // MATLAB Function: '<S55>/FaultParamsExtract3'
    // '<S58>:1:30' FaultParam=fParam;
    // MATLAB Function 'Battery FaultModel/FaultModelTmp/FaultParamsExtract3': '<S59>:1' 
    // '<S59>:1:5' if isempty(hFault)
    // '<S59>:1:8' if isempty(fParam)
    // '<S59>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S59>:1:13' fParamTmp=zeros(20,1);
    for (i = 0; i < 20; i++) {
      // MATLAB Function: '<S55>/FaultParamsExtract2'
      FaultModel_B.FaultParam_ei[i] = FaultModel_DW.fParam_f[i];

      // MATLAB Function: '<S55>/FaultParamsExtract3'
      fParamTmp[i] = 0.0;
    }

    // MATLAB Function: '<S55>/FaultParamsExtract3' incorporates:
    //   Constant: '<S55>/FaultID3'
    //   Inport: '<Root>/inSILInts'

    // '<S59>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S59>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S59>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID3_Value) {
        // '<S59>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S59>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S59>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S59>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S59>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S59>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_n = true;

      // '<S59>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S59>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_j[0], &fParamTmp[0], 20U * sizeof(real_T));
    }

    // '<S59>:1:29' hasFault_islowCapacity=hFault;
    FaultModel_B.hasFault_islowCapacity = FaultModel_DW.hFault_n;

    // '<S59>:1:30' FaultParam=fParam;
    std::memcpy(&FaultModel_B.FaultParam_m[0], &FaultModel_DW.fParam_j[0], 20U *
                sizeof(real_T));
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
    // MATLAB Function: '<S55>/MATLAB Function' incorporates:
    //   Constant: '<S55>/ModelParam.BattHoverMinutes'
    //   Constant: '<S55>/ModelParam.BattHoverThr'
    //   Constant: '<S55>/ModelParam.uavMotNumbs'

    hover_current = FaultModel_P.ModelParam_BattHoverMinutes;
    hFaultTmp = FaultModel_B.hasFault_isUseCustomHovTime;
    std::memcpy(&fParamTmp[0], &FaultModel_B.FaultParam_ei[0], 20U * sizeof
                (real_T));

    //  battery model
    // ================================Constants================================= 
    // MATLAB Function 'Battery FaultModel/FaultModelTmp/MATLAB Function': '<S60>:1' 
    // '<S60>:1:5' delta_t = 0.01;
    // max_current = 5.500;                % maximum current per motor             (A) 
    // aux_current = 0.100;                % current of auxillary components       (A)         
    // capacity = 1.000;                   % LiPo current capacity                 (Ah)                                  
    // cells = 2;                          % LiPo cell count
    // ========================================================================== 
    // '<S60>:1:14' if isempty(discharge)
    // '<S60>:1:19' if isempty(startTime)
    // '<S60>:1:24' if isempty(reset)
    // '<S60>:1:28' discharge_capacity=0;
    discharge_capacity = 0.0;

    //  低电量故障
    // '<S60>:1:31' if islowCapacity
    if (FaultModel_B.hasFault_islowCapacity) {
      // '<S60>:1:32' hover_time = hover_time*remainCapacityRatio(1);
      hover_current = FaultModel_P.ModelParam_BattHoverMinutes *
        FaultModel_B.FaultParam_m[0];

      // '<S60>:1:33' isUseCustomHovTime=false;
      hFaultTmp = false;
    }

    // '<S60>:1:37' if ~isUseCustomHovTime
    if (!hFaultTmp) {
      // '<S60>:1:38' capacity=1;
      // '<S60>:1:40' if hover_time<0.01
      if (hover_current < 0.01) {
        // '<S60>:1:41' hover_time=0.01;
        hover_current = 0.01;
      }

      // '<S60>:1:44' hover_current=1/(hover_time*1.4/60);
      hover_current = 1.0 / (hover_current * 1.4 / 60.0);

      // '<S60>:1:45' current=0;
      // '<S60>:1:46' for i=1:motorNumbs
      for (r = 0; r < FaultModel_P.ModelParam_uavMotNumbs; r++) {
        // '<S60>:1:47' current=current+hover_current*(load(i)/hover_thr)^2;
        rtb_TmpSignalConversionAtSFun_1 = FaultModel_B.y_m[r] /
          FaultModel_P.ModelParam_BattHoverThr;
        discharge_capacity += rtb_TmpSignalConversionAtSFun_1 *
          rtb_TmpSignalConversionAtSFun_1 * hover_current;
      }

      // '<S60>:1:49' aux_current=0.5;
      // current = sum(hover_current .* (load/hover_thr).^2) + aux_current;
      // '<S60>:1:51' current =(current+aux_current)/double(motorNumbs);
      discharge_capacity = (discharge_capacity + 0.5) / static_cast<real_T>
        (FaultModel_P.ModelParam_uavMotNumbs);

      // '<S60>:1:52' discharge = current * (delta_t / 3600) + discharge;
      FaultModel_DW.discharge += discharge_capacity * 2.7777777777777779E-6;

      // '<S60>:1:53' discharge_capacity = discharge / capacity;
      discharge_capacity = FaultModel_DW.discharge;
    }

    // 如果启用电池模型且使用自定义续航时间
    // '<S60>:1:60' if isUseCustomHovTime
    if (hFaultTmp) {
      // '<S60>:1:61' hover_time=CustomHovTime(1)*1.4*60;
      hover_current = FaultModel_B.FaultParam_o[0] * 1.4 * 60.0;

      // '<S60>:1:62' if reset<0.5
      if (FaultModel_DW.reset < 0.5) {
        // '<S60>:1:63' startTime=time;
        FaultModel_DW.startTime = rtb_Clock1_tmp;

        // '<S60>:1:64' reset=1;
        FaultModel_DW.reset = 1.0;
      }

      // '<S60>:1:66' if hover_time<0.01
      if (hover_current < 0.01) {
        // '<S60>:1:67' hover_time=0.01;
        hover_current = 0.01;
      }

      // '<S60>:1:69' discharge_capacity=(time-startTime)/hover_time;
      discharge_capacity = (rtb_Clock1_tmp - FaultModel_DW.startTime) /
        hover_current;
    } else {
      // '<S60>:1:70' else
      // 使用默认的续航算法
      // '<S60>:1:72' reset=0;
      FaultModel_DW.reset = 0.0;
    }

    // '<S60>:1:76' if discharge_capacity<0
    if (discharge_capacity < 0.0) {
      // '<S60>:1:77' discharge_capacity=0;
      discharge_capacity = 0.0;
    }

    // '<S60>:1:79' if discharge_capacity>1
    if (discharge_capacity > 1.0) {
      // '<S60>:1:80' discharge_capacity=1;
      discharge_capacity = 1.0;
    }

    // 电量与电压的曲线
    // '<S60>:1:85' if (0 <= discharge_capacity) && (discharge_capacity <=0.20)
    if ((0.0 <= discharge_capacity) && (discharge_capacity <= 0.2)) {
      // '<S60>:1:86' cell_voltage = -14.029*discharge_capacity^3 + 16.975*discharge_capacity^2 - 5.3339*discharge_capacity + 4.2; 
      hover_current = ((discharge_capacity * discharge_capacity * 16.975 +
                        -14.029 * rt_powd_snf(discharge_capacity, 3.0)) - 5.3339
                       * discharge_capacity) + 4.2;
    } else if ((0.2 < discharge_capacity) && (discharge_capacity < 0.7)) {
      // '<S60>:1:87' elseif (0.20 < discharge_capacity) && (discharge_capacity < 0.70) 
      // '<S60>:1:88' cell_voltage = -0.2*discharge_capacity + 3.74;
      hover_current = -0.2 * discharge_capacity + 3.74;
    } else {
      // '<S60>:1:89' else
      // '<S60>:1:90' cell_voltage = -48*discharge_capacity^3 + 89.6*discharge_capacity^2 - 55.08*discharge_capacity + 14.716; 
      hover_current = ((discharge_capacity * discharge_capacity * 89.6 + -48.0 *
                        rt_powd_snf(discharge_capacity, 3.0)) - 55.08 *
                       discharge_capacity) + 14.716;
    }

    // '<S60>:1:93' if cell_voltage < 0.5
    if (hover_current < 0.5) {
      // '<S60>:1:94' cell_voltage = 0;
      hover_current = 0.0;
    }

    //  电池失效故障
    // '<S60>:1:98' if isPowOff
    if (FaultModel_B.hasFault_isPowOff) {
      // '<S60>:1:99' cell_voltage = 0;
      hover_current = 0.0;
    }

    //  低电压故障
    // '<S60>:1:103' if isLowVoltage
    if (FaultModel_B.hasFault_isLowVoltage) {
      // '<S60>:1:104' if remainVoltageRatio(1)>1
      if (FaultModel_B.FaultParam_ei[0] > 1.0) {
        // '<S60>:1:105' remainVoltageRatio(1)=1;
        fParamTmp[0] = 1.0;
      } else {
        if (FaultModel_B.FaultParam_ei[0] < 0.0) {
          // '<S60>:1:106' elseif remainVoltageRatio(1)<0
          // '<S60>:1:107' remainVoltageRatio(1)=0;
          fParamTmp[0] = 0.0;
        }
      }

      // '<S60>:1:109' cell_voltage = remainVoltageRatio(1)*4.2;
      hover_current = fParamTmp[0] * 4.2;
    }

    // 如果电池模型未启用，续航为无穷久，同时各个全局变量归零
    // '<S60>:1:114' if ~isUseCustomHovTime&&~isPowOff&&~isLowVoltage&&~islowCapacity 
    if ((!hFaultTmp) && (!FaultModel_B.hasFault_isPowOff) &&
        (!FaultModel_B.hasFault_isLowVoltage) &&
        (!FaultModel_B.hasFault_islowCapacity)) {
      // '<S60>:1:115' cell_voltage=4.2;
      hover_current = 4.2;

      // '<S60>:1:116' discharge = 0;
      FaultModel_DW.discharge = 0.0;

      // '<S60>:1:117' startTime = 0;
      FaultModel_DW.startTime = 0.0;

      // '<S60>:1:118' reset = 0;
      FaultModel_DW.reset = 0.0;
    }

    // 效率矩阵
    // '<S60>:1:122' EffRatio=cell_voltage/4.2;
    // '<S60>:1:123' remCapacity=1-discharge_capacity;
    discharge_capacity = 1.0 - discharge_capacity;

    // Gain: '<S55>/MotorFault3' incorporates:
    //   MATLAB Function: '<S55>/MATLAB Function'

    // ========================================================================== 
    FaultModel_B.MotorFault3 = FaultModel_P.MotorFault3_Gain * hover_current;
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    //  本模块需要用到8维FaultParam的输入
    // 因此故障ID的格式应该是：
    // inSILInts=[FaultID FaultID FaultID FaultID ...]
    // inSILInts=[param1 param2 param3 param4 param5 param6 param7 param8 ...] -> FaultParam 
    //  param的每一位表示本电机的健康系数（0到1），实际上就是pwm_out = pwm_in * param 
    //  如果param1=0，则电机1直接坏掉，始终输出0
    // MATLAB Function 'Motor FaultModel/FaultModelTmp/MotorFaultModel': '<S299>:1' 
    // '<S299>:1:9' y=inPWMs;
    for (i = 0; i < 8; i++) {
      // Product: '<S55>/Product'
      uavlostJyz = FaultModel_B.y_m[i] * FaultModel_B.MotorFault3;

      // MATLAB Function: '<S295>/MotorFaultModel'
      rtb_y_c[i] = uavlostJyz;

      // Product: '<S55>/Product'
      Memory[i] = uavlostJyz;
    }

    // MATLAB Function: '<S295>/MotorFaultModel'
    // 默认情况下不注入故障，直接将数据输出
    // '<S299>:1:11' if hasFault
    if (rtb_hasFault_j) {
      // 如果注入了故障
      // '<S299>:1:12' if count == 1
      if (rtb_count_m == 1.0) {
        // '<S299>:1:13' y(1) = sigma2pwm(inPWMs(1)) * FaultParams(1);
        // '<S299>:1:27' pwm_num = 1000 * sigma + 1000;
        rtb_y_c[0] = (1000.0 * Memory[0] + 1000.0) * rtb_FaultParam_e5[0];

        // '<S299>:1:14' y(1) = pwm2sigma(y(1));
        // '<S299>:1:31' sigma = (pwm - 1000) / 1000;
        rtb_y_c[0] = (rtb_y_c[0] - 1000.0) / 1000.0;

        // '<S299>:1:15' y(2) = sigma2pwm(inPWMs(2)) * FaultParams(2);
        // '<S299>:1:27' pwm_num = 1000 * sigma + 1000;
        rtb_y_c[1] = (1000.0 * Memory[1] + 1000.0) * rtb_FaultParam_e5[1];

        // '<S299>:1:16' y(2) = pwm2sigma(y(2));
        // '<S299>:1:31' sigma = (pwm - 1000) / 1000;
        rtb_y_c[1] = (rtb_y_c[1] - 1000.0) / 1000.0;
      } else {
        if (rtb_count_m == 2.0) {
          // '<S299>:1:17' elseif count == 2
          // '<S299>:1:18' for i=1:4
          // '<S299>:1:19' y(i) = sigma2pwm(inPWMs(i)) * FaultParams(i);
          // '<S299>:1:27' pwm_num = 1000 * sigma + 1000;
          // '<S299>:1:20' y(i) = pwm2sigma(y(i));
          // '<S299>:1:31' sigma = (pwm - 1000) / 1000;
          rtb_y_c[0] = ((1000.0 * Memory[0] + 1000.0) * rtb_FaultParam_e5[0] -
                        1000.0) / 1000.0;

          // '<S299>:1:19' y(i) = sigma2pwm(inPWMs(i)) * FaultParams(i);
          // '<S299>:1:27' pwm_num = 1000 * sigma + 1000;
          // '<S299>:1:20' y(i) = pwm2sigma(y(i));
          // '<S299>:1:31' sigma = (pwm - 1000) / 1000;
          rtb_y_c[1] = ((1000.0 * Memory[1] + 1000.0) * rtb_FaultParam_e5[1] -
                        1000.0) / 1000.0;

          // '<S299>:1:19' y(i) = sigma2pwm(inPWMs(i)) * FaultParams(i);
          // '<S299>:1:27' pwm_num = 1000 * sigma + 1000;
          // '<S299>:1:20' y(i) = pwm2sigma(y(i));
          // '<S299>:1:31' sigma = (pwm - 1000) / 1000;
          rtb_y_c[2] = ((1000.0 * Memory[2] + 1000.0) * rtb_FaultParam_e5[2] -
                        1000.0) / 1000.0;

          // '<S299>:1:19' y(i) = sigma2pwm(inPWMs(i)) * FaultParams(i);
          // '<S299>:1:27' pwm_num = 1000 * sigma + 1000;
          // '<S299>:1:20' y(i) = pwm2sigma(y(i));
          // '<S299>:1:31' sigma = (pwm - 1000) / 1000;
          rtb_y_c[3] = ((1000.0 * Memory[3] + 1000.0) * rtb_FaultParam_e5[3] -
                        1000.0) / 1000.0;
        }
      }
    }

    // MATLAB Function: '<S295>/motor_fauilure_protection'
    // MATLAB Function 'Motor FaultModel/FaultModelTmp/motor_fauilure_protection': '<S301>:1' 
    // '<S301>:1:2' y=inPWMs;
    std::memcpy(&rtb_y[0], &Memory[0], sizeof(real_T) << 3U);

    // '<S301>:1:3' if hasFault
    if (rtb_hasFault) {
      // 如果注入了故障(自旋下降处理)
      // '<S301>:1:4' if count == 1
      if (rtb_count == 1.0) {
        // '<S301>:1:5' y(1) = inPWMs(1) * FaultParams(1);
        rtb_y[0] = Memory[0] * rtb_FaultParam_g[0];

        // '<S301>:1:6' y(2) = inPWMs(2) * FaultParams(2);
        rtb_y[1] = Memory[1] * rtb_FaultParam_g[1];

        // '<S301>:1:7' if FaultParams(1)==0
        if (rtb_FaultParam_g[0] == 0.0) {
          // '<S301>:1:8' y(3)=0.835;
          rtb_y[2] = 0.835;

          // '<S301>:1:9' y(4)=0.835;
          rtb_y[3] = 0.835;

          // '<S301>:1:10' y(2)=0;
          rtb_y[1] = 0.0;
        }

        // '<S301>:1:12' if FaultParams(2)==0
        if (rtb_FaultParam_g[1] == 0.0) {
          // '<S301>:1:13' y(1)=0;
          rtb_y[0] = 0.0;

          // '<S301>:1:14' y(3)=0.835;
          rtb_y[2] = 0.835;

          // '<S301>:1:15' y(4)=0.835;
          rtb_y[3] = 0.835;
        }
      } else {
        if (rtb_count == 2.0) {
          // '<S301>:1:17' elseif count == 2
          // '<S301>:1:18' for i=1:4
          // '<S301>:1:19' y(i) = inPWMs(i) * FaultParams(i);
          rtb_y[0] = Memory[0] * rtb_FaultParam_g[0];

          // '<S301>:1:19' y(i) = inPWMs(i) * FaultParams(i);
          rtb_y[1] = Memory[1] * rtb_FaultParam_g[1];

          // '<S301>:1:19' y(i) = inPWMs(i) * FaultParams(i);
          rtb_y[2] = Memory[2] * rtb_FaultParam_g[2];

          // '<S301>:1:19' y(i) = inPWMs(i) * FaultParams(i);
          rtb_y[3] = Memory[3] * rtb_FaultParam_g[3];

          // '<S301>:1:21' if FaultParams(1)==0
          if (rtb_FaultParam_g[0] == 0.0) {
            // '<S301>:1:22' y(3)=0.835;
            rtb_y[2] = 0.835;

            // '<S301>:1:23' y(4)=0.835;
            rtb_y[3] = 0.835;

            // '<S301>:1:24' y(2)=0;
            rtb_y[1] = 0.0;
          }

          // '<S301>:1:26' if FaultParams(2)==0
          if (rtb_FaultParam_g[1] == 0.0) {
            // '<S301>:1:27' y(1)=0;
            rtb_y[0] = 0.0;

            // '<S301>:1:28' y(3)=0.835;
            rtb_y[2] = 0.835;

            // '<S301>:1:29' y(4)=0.835;
            rtb_y[3] = 0.835;
          }

          // '<S301>:1:31' if FaultParams(3)==0
          if (rtb_FaultParam_g[2] == 0.0) {
            // '<S301>:1:32' y(4)=0;
            rtb_y[3] = 0.0;

            // '<S301>:1:33' y(1)=0.835;
            rtb_y[0] = 0.835;

            // '<S301>:1:34' y(2)=0.835;
            rtb_y[1] = 0.835;
          }

          // '<S301>:1:36' if FaultParams(4)==0
          if (rtb_FaultParam_g[3] == 0.0) {
            // '<S301>:1:37' y(3)=0;
            rtb_y[2] = 0.0;

            // '<S301>:1:38' y(1)=0.835;
            rtb_y[0] = 0.835;

            // '<S301>:1:39' y(2)=0.835;
            rtb_y[1] = 0.835;
          }
        }
      }
    }

    // End of MATLAB Function: '<S295>/motor_fauilure_protection'

    // MATLAB Function: '<S295>/MATLAB Function'
    //      if inSILFloats(1)==0
    //          y(2)=y(2)-0.25;
    //      end
    //      if inSILFloats(2)==0
    //          y(1)=y(1)-0.25;
    //      end
    //      if inSILFloats(3)==0
    //          y(4)=y(4)-0.25;
    //      end
    //      if inSILFloats(4)==0
    //          y(3)=y(3)-0.25;
    //      end
    //
    //  if inSILInts(1)==3 %坠机就令PWM为0
    //      y(1)=0;
    //      y(2)=0;
    //      y(3)=0;
    //      y(4)=0;
    //  end
    // MATLAB Function 'Motor FaultModel/FaultModelTmp/MATLAB Function': '<S298>:1' 
    // '<S298>:1:3' y = inPWMs;
    std::memcpy(&rtb_y_h[0], &Memory[0], sizeof(real_T) << 3U);

    // '<S298>:1:4' if isnoMotorProFault
    if (rtb_hasFault_j) {
      // '<S298>:1:5' y =  NoProPWMOut;
      std::memcpy(&rtb_y_h[0], &rtb_y_c[0], sizeof(real_T) << 3U);
    } else {
      if (rtb_hasFault) {
        // '<S298>:1:6' elseif isMotorProFault
        // '<S298>:1:7' y = ProPWMOut;
        std::memcpy(&rtb_y_h[0], &rtb_y[0], sizeof(real_T) << 3U);
      }
    }

    // End of MATLAB Function: '<S295>/MATLAB Function'
  }

  // Outputs for Atomic SubSystem: '<S300>/MotorNonlinearDynamic1'
  // Constant: '<S300>/ModelParam.motorWb' incorporates:
  //   Constant: '<S300>/ModelParam.motorCr'
  //   Constant: '<S300>/ModelParam.motorT'

  FaultMod_MotorNonlinearDynamic1(FaultModel_P.ModelParam_motorWb,
    FaultModel_P.ModelParam_motorCr, FaultModel_P.ModelParam_motorT,
    FaultModel_B.ModelInit_RPM, rtb_y_h[0], &FaultModel_B.MotorNonlinearDynamic1,
    &FaultModel_DW.MotorNonlinearDynamic1, &FaultModel_P.MotorNonlinearDynamic1,
    &FaultModel_P, &FaultModel_X.MotorNonlinearDynamic1);

  // End of Outputs for SubSystem: '<S300>/MotorNonlinearDynamic1'

  // Outputs for Atomic SubSystem: '<S300>/MotorNonlinearDynamic2'
  FaultMod_MotorNonlinearDynamic1(FaultModel_P.ModelParam_motorWb,
    FaultModel_P.ModelParam_motorCr, FaultModel_P.ModelParam_motorT,
    FaultModel_B.ModelInit_RPM, rtb_y_h[1], &FaultModel_B.MotorNonlinearDynamic2,
    &FaultModel_DW.MotorNonlinearDynamic2, &FaultModel_P.MotorNonlinearDynamic2,
    &FaultModel_P, &FaultModel_X.MotorNonlinearDynamic2);

  // End of Outputs for SubSystem: '<S300>/MotorNonlinearDynamic2'

  // Outputs for Atomic SubSystem: '<S300>/MotorNonlinearDynamic3'
  FaultMod_MotorNonlinearDynamic1(FaultModel_P.ModelParam_motorWb,
    FaultModel_P.ModelParam_motorCr, FaultModel_P.ModelParam_motorT,
    FaultModel_B.ModelInit_RPM, rtb_y_h[2], &FaultModel_B.MotorNonlinearDynamic3,
    &FaultModel_DW.MotorNonlinearDynamic3, &FaultModel_P.MotorNonlinearDynamic3,
    &FaultModel_P, &FaultModel_X.MotorNonlinearDynamic3);

  // End of Outputs for SubSystem: '<S300>/MotorNonlinearDynamic3'

  // Outputs for Atomic SubSystem: '<S300>/MotorNonlinearDynamic4'
  FaultMod_MotorNonlinearDynamic1(FaultModel_P.ModelParam_motorWb,
    FaultModel_P.ModelParam_motorCr, FaultModel_P.ModelParam_motorT,
    FaultModel_B.ModelInit_RPM, rtb_y_h[3], &FaultModel_B.MotorNonlinearDynamic4,
    &FaultModel_DW.MotorNonlinearDynamic4, &FaultModel_P.MotorNonlinearDynamic4,
    &FaultModel_P, &FaultModel_X.MotorNonlinearDynamic4);

  // End of Outputs for SubSystem: '<S300>/MotorNonlinearDynamic4'

  // Outputs for Atomic SubSystem: '<S300>/MotorNonlinearDynamic5'
  FaultMod_MotorNonlinearDynamic1(FaultModel_P.ModelParam_motorWb,
    FaultModel_P.ModelParam_motorCr, FaultModel_P.ModelParam_motorT,
    FaultModel_B.ModelInit_RPM, rtb_y_h[4], &FaultModel_B.MotorNonlinearDynamic5,
    &FaultModel_DW.MotorNonlinearDynamic5, &FaultModel_P.MotorNonlinearDynamic5,
    &FaultModel_P, &FaultModel_X.MotorNonlinearDynamic5);

  // End of Outputs for SubSystem: '<S300>/MotorNonlinearDynamic5'

  // Outputs for Atomic SubSystem: '<S300>/MotorNonlinearDynamic6'
  FaultMod_MotorNonlinearDynamic1(FaultModel_P.ModelParam_motorWb,
    FaultModel_P.ModelParam_motorCr, FaultModel_P.ModelParam_motorT,
    FaultModel_B.ModelInit_RPM, rtb_y_h[5], &FaultModel_B.MotorNonlinearDynamic6,
    &FaultModel_DW.MotorNonlinearDynamic6, &FaultModel_P.MotorNonlinearDynamic6,
    &FaultModel_P, &FaultModel_X.MotorNonlinearDynamic6);

  // End of Outputs for SubSystem: '<S300>/MotorNonlinearDynamic6'

  // Outputs for Atomic SubSystem: '<S300>/MotorNonlinearDynamic7'
  FaultMod_MotorNonlinearDynamic1(FaultModel_P.ModelParam_motorWb,
    FaultModel_P.ModelParam_motorCr, FaultModel_P.ModelParam_motorT,
    FaultModel_B.ModelInit_RPM, rtb_y_h[6], &FaultModel_B.MotorNonlinearDynamic7,
    &FaultModel_DW.MotorNonlinearDynamic7, &FaultModel_P.MotorNonlinearDynamic7,
    &FaultModel_P, &FaultModel_X.MotorNonlinearDynamic7);

  // End of Outputs for SubSystem: '<S300>/MotorNonlinearDynamic7'

  // Outputs for Atomic SubSystem: '<S300>/MotorNonlinearDynamic8'
  FaultMod_MotorNonlinearDynamic1(FaultModel_P.ModelParam_motorWb,
    FaultModel_P.ModelParam_motorCr, FaultModel_P.ModelParam_motorT,
    FaultModel_B.ModelInit_RPM, rtb_y_h[7], &FaultModel_B.MotorNonlinearDynamic8,
    &FaultModel_DW.MotorNonlinearDynamic8, &FaultModel_P.MotorNonlinearDynamic8,
    &FaultModel_P, &FaultModel_X.MotorNonlinearDynamic8);

  // End of Outputs for SubSystem: '<S300>/MotorNonlinearDynamic8'
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[2] == 0) {
    // UniformRandomNumber: '<S61>/Uniform Random Number'
    FaultModel_B.UniformRandomNumber[0] =
      FaultModel_DW.UniformRandomNumber_NextOutput[0];
    FaultModel_B.UniformRandomNumber[1] =
      FaultModel_DW.UniformRandomNumber_NextOutput[1];
    FaultModel_B.UniformRandomNumber[2] =
      FaultModel_DW.UniformRandomNumber_NextOutput[2];
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // MATLAB Function: '<S61>/FaultParamsExtract4' incorporates:
    //   Constant: '<S61>/FaultID4'
    //   Inport: '<Root>/inSILInts'

    // MATLAB Function 'Environment FaultModel1/Env FaultWindModel/FaultParamsExtract4': '<S68>:1' 
    // '<S68>:1:5' if isempty(hFault)
    // '<S68>:1:8' if isempty(fParam)
    // '<S68>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S68>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S68>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S68>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S68>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID4_Value) {
        // '<S68>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S68>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S68>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S68>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S68>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S68>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_p = true;

      // '<S68>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S68>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_mm[0], &fParamTmp[0], 20U * sizeof
                  (real_T));
    }

    // '<S68>:1:29' hasFault_WindNoise=hFault;
    rtb_hasFault_j = FaultModel_DW.hFault_p;

    // '<S68>:1:30' FaultParam=fParam;
    std::memcpy(&fParamTmp[0], &FaultModel_DW.fParam_mm[0], 20U * sizeof(real_T));

    // End of MATLAB Function: '<S61>/FaultParamsExtract4'

    // MATLAB Function: '<S61>/noiseUpperWindBodySwitch'
    // MATLAB Function 'Environment FaultModel1/Env FaultWindModel/noiseUpperWindBodySwitch': '<S78>:1' 
    // '<S78>:1:3' y = [0;0;0];
    Product1[0] = 0.0;
    Product1[1] = 0.0;
    Product1[2] = 0.0;

    // '<S78>:1:4' if isNoiseFault
    if (rtb_hasFault_j) {
      // '<S78>:1:5' Param_noiseUpperWindBodyRatio=NoiseParams(1);
      // '<S78>:1:6' Param_GlobalNoiseGainSwitch=NoiseParams(2);
      // '<S78>:1:7' y=Noise* Param_GlobalNoiseGainSwitch*Param_noiseUpperWindBodyRatio; 
      Product1[0] = FaultModel_B.UniformRandomNumber[0] * fParamTmp[1] *
        fParamTmp[0];
      Product1[1] = FaultModel_B.UniformRandomNumber[1] * fParamTmp[1] *
        fParamTmp[0];
      Product1[2] = FaultModel_B.UniformRandomNumber[2] * fParamTmp[1] *
        fParamTmp[0];
    }

    // End of MATLAB Function: '<S61>/noiseUpperWindBodySwitch'

    // Sum: '<S61>/Sum1' incorporates:
    //   Constant: '<S61>/Constant_[1 1 1]'

    FaultModel_B.Sum1[0] = FaultModel_P.Constant_111_Value[0] + Product1[0];
    FaultModel_B.Sum1[1] = FaultModel_P.Constant_111_Value[1] + Product1[1];
    FaultModel_B.Sum1[2] = FaultModel_P.Constant_111_Value[2] + Product1[2];

    // MATLAB Function: '<S61>/FaultParamsExtract' incorporates:
    //   Constant: '<S61>/FaultID'
    //   Inport: '<Root>/inSILInts'

    // MATLAB Function 'Environment FaultModel1/Env FaultWindModel/FaultParamsExtract': '<S64>:1' 
    // '<S64>:1:5' if isempty(hFault)
    // '<S64>:1:8' if isempty(fParam)
    // '<S64>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S64>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S64>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S64>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S64>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID_Value_g) {
        // '<S64>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S64>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S64>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S64>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S64>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S64>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_ff = true;

      // '<S64>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S64>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_g[0], &fParamTmp[0], 20U * sizeof(real_T));
    }

    // '<S64>:1:29' hasFault_ConstWind=hFault;
    FaultModel_B.hasFault_ConstWind = FaultModel_DW.hFault_ff;

    // MATLAB Function: '<S61>/FaultParamsExtract1'
    // '<S64>:1:30' FaultParam=fParam;
    // MATLAB Function 'Environment FaultModel1/Env FaultWindModel/FaultParamsExtract1': '<S65>:1' 
    // '<S65>:1:5' if isempty(hFault)
    // '<S65>:1:8' if isempty(fParam)
    // '<S65>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S65>:1:13' fParamTmp=zeros(20,1);
    for (i = 0; i < 20; i++) {
      // MATLAB Function: '<S61>/FaultParamsExtract'
      FaultModel_B.FaultParam_e[i] = FaultModel_DW.fParam_g[i];

      // MATLAB Function: '<S61>/FaultParamsExtract1'
      fParamTmp[i] = 0.0;
    }

    // MATLAB Function: '<S61>/FaultParamsExtract1' incorporates:
    //   Constant: '<S61>/FaultID1'
    //   Inport: '<Root>/inSILInts'

    // '<S65>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S65>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S65>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID1_Value_m) {
        // '<S65>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S65>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S65>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S65>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S65>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S65>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_b0 = true;

      // '<S65>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S65>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_mg[0], &fParamTmp[0], 20U * sizeof
                  (real_T));
    }

    // '<S65>:1:29' hasFault_GustWind=hFault;
    FaultModel_B.hasFault_GustWind = FaultModel_DW.hFault_b0;

    // MATLAB Function: '<S61>/FaultParamsExtract2'
    // '<S65>:1:30' FaultParam=fParam;
    // MATLAB Function 'Environment FaultModel1/Env FaultWindModel/FaultParamsExtract2': '<S66>:1' 
    // '<S66>:1:5' if isempty(hFault)
    // '<S66>:1:8' if isempty(fParam)
    // '<S66>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S66>:1:13' fParamTmp=zeros(20,1);
    for (i = 0; i < 20; i++) {
      // MATLAB Function: '<S61>/FaultParamsExtract1'
      FaultModel_B.FaultParam_i[i] = FaultModel_DW.fParam_mg[i];

      // MATLAB Function: '<S61>/FaultParamsExtract2'
      fParamTmp[i] = 0.0;
    }

    // MATLAB Function: '<S61>/FaultParamsExtract2' incorporates:
    //   Constant: '<S61>/FaultID2'
    //   Inport: '<Root>/inSILInts'

    // '<S66>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S66>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S66>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID2_Value_g) {
        // '<S66>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S66>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S66>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S66>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S66>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S66>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_f = true;

      // '<S66>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S66>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_bb[0], &fParamTmp[0], 20U * sizeof
                  (real_T));
    }

    // '<S66>:1:29' hasFault_TurbWind=hFault;
    FaultModel_B.hasFault_TurbWind = FaultModel_DW.hFault_f;

    // MATLAB Function: '<S61>/FaultParamsExtract3'
    // '<S66>:1:30' FaultParam=fParam;
    // MATLAB Function 'Environment FaultModel1/Env FaultWindModel/FaultParamsExtract3': '<S67>:1' 
    // '<S67>:1:5' if isempty(hFault)
    // '<S67>:1:8' if isempty(fParam)
    // '<S67>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S67>:1:13' fParamTmp=zeros(20,1);
    for (i = 0; i < 20; i++) {
      // MATLAB Function: '<S61>/FaultParamsExtract2'
      FaultModel_B.FaultParam_k[i] = FaultModel_DW.fParam_bb[i];

      // MATLAB Function: '<S61>/FaultParamsExtract3'
      fParamTmp[i] = 0.0;
    }

    // MATLAB Function: '<S61>/FaultParamsExtract3' incorporates:
    //   Constant: '<S61>/FaultID3'
    //   Inport: '<Root>/inSILInts'

    // '<S67>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S67>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S67>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID3_Value_g) {
        // '<S67>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S67>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S67>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S67>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S67>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S67>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_k = true;

      // '<S67>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S67>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_l[0], &fParamTmp[0], 20U * sizeof(real_T));
    }

    // '<S67>:1:29' hasFault_SheerWind=hFault;
    FaultModel_B.hasFault_SheerWind = FaultModel_DW.hFault_k;

    // '<S67>:1:30' FaultParam=fParam;
    std::memcpy(&FaultModel_B.FaultParam[0], &FaultModel_DW.fParam_l[0], 20U *
                sizeof(real_T));
  }

  // Gain: '<S61>/Gain_-1' incorporates:
  //   Integrator: '<S12>/xe,ye,ze'

  uavlostJzx = FaultModel_P.Gain_1_Gain * FaultModel_X.xeyeze_CSTATE[2];

  // Saturate: '<S61>/Saturation_2'
  if (uavlostJzx > FaultModel_P.Saturation_2_UpperSat) {
    uavlostJzx = FaultModel_P.Saturation_2_UpperSat;
  } else {
    if (uavlostJzx < FaultModel_P.Saturation_2_LowerSat) {
      uavlostJzx = FaultModel_P.Saturation_2_LowerSat;
    }
  }

  // End of Saturate: '<S61>/Saturation_2'

  // UnitConversion: '<S121>/Unit Conversion' incorporates:
  //   UnitConversion: '<S184>/Unit Conversion'
  //   UnitConversion: '<S82>/Unit Conversion'

  // Unit Conversion - from: m to: ft
  // Expression: output = (3.28084*input) + (0)
  massOb = 3.280839895013123 * uavlostJzx;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // UnitConversion: '<S127>/Unit Conversion' incorporates:
    //   Constant: '<S61>/Constant_V'

    // Unit Conversion - from: m/s to: ft/s
    // Expression: output = (3.28084*input) + (0)
    FaultModel_B.UnitConversion = 3.280839895013123 *
      FaultModel_P.Constant_V_Value;
  }

  // Saturate: '<S154>/Limit Function 10ft to 1000ft' incorporates:
  //   UnitConversion: '<S121>/Unit Conversion'

  if (massOb > FaultModel_P.LimitFunction10ftto1000ft_Upper) {
    uavlostJxy = FaultModel_P.LimitFunction10ftto1000ft_Upper;
  } else if (massOb < FaultModel_P.LimitFunction10ftto1000ft_Lower) {
    uavlostJxy = FaultModel_P.LimitFunction10ftto1000ft_Lower;
  } else {
    uavlostJxy = massOb;
  }

  // End of Saturate: '<S154>/Limit Function 10ft to 1000ft'

  // Fcn: '<S154>/Low Altitude Scale Length'
  uavlostJyz = 0.000823 * uavlostJxy + 0.177;
  if (uavlostJyz < 0.0) {
    uavlostJyz = -rt_powd_snf(-uavlostJyz, 1.2);
  } else {
    uavlostJyz = rt_powd_snf(uavlostJyz, 1.2);
  }

  // Fcn: '<S154>/Low Altitude Scale Length'
  rtb_TmpSignalConversionAtSFun_1 = uavlostJxy / uavlostJyz;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // UnitConversion: '<S156>/Unit Conversion' incorporates:
    //   Constant: '<S155>/Medium//High Altitude'

    // Unit Conversion - from: m to: ft
    // Expression: output = (3.28084*input) + (0)
    FaultModel_B.UnitConversion_j = 3.280839895013123 *
      FaultModel_P.DrydenWindTurbulenceModelDiscre;
  }

  // Saturate: '<S137>/Limit Height h<1000ft' incorporates:
  //   UnitConversion: '<S121>/Unit Conversion'

  if (massOb > FaultModel_P.LimitHeighth1000ft_UpperSat) {
    rtb_count_m = FaultModel_P.LimitHeighth1000ft_UpperSat;
  } else if (massOb < FaultModel_P.LimitHeighth1000ft_LowerSat) {
    rtb_count_m = FaultModel_P.LimitHeighth1000ft_LowerSat;
  } else {
    rtb_count_m = massOb;
  }

  // End of Saturate: '<S137>/Limit Height h<1000ft'

  // Fcn: '<S137>/Low Altitude Intensity'
  uavlostJyz = 0.000823 * rtb_count_m + 0.177;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Gain: '<S137>/sigma_wg ' incorporates:
    //   Constant: '<S63>/Windspeed at 20ft (6m)'
    //   UnitConversion: '<S128>/Unit Conversion'

    // Unit Conversion - from: m/s to: ft/s
    // Expression: output = (3.28084*input) + (0)
    FaultModel_B.sigma_wg = 3.280839895013123 *
      FaultModel_P.DrydenWindTurbulenceModelDis_m3 * FaultModel_P.sigma_wg_Gain;
  }

  // Fcn: '<S137>/Low Altitude Intensity'
  if (uavlostJyz < 0.0) {
    uavlostJyz = -rt_powd_snf(-uavlostJyz, 0.4);
  } else {
    uavlostJyz = rt_powd_snf(uavlostJyz, 0.4);
  }

  // Product: '<S137>/sigma_ug, sigma_vg' incorporates:
  //   Fcn: '<S137>/Low Altitude Intensity'

  rtb_Add = 1.0 / uavlostJyz * FaultModel_B.sigma_wg;

  // Interpolation_n-D: '<S136>/Medium//High Altitude Intensity' incorporates:
  //   PreLookup: '<S136>/PreLook-Up Index Search  (altitude)'
  //   UnitConversion: '<S121>/Unit Conversion'

  bpIndex[0] = plook_bincpa(massOb, FaultModel_P.PreLookUpIndexSearchaltitude_Br,
    11U, &uavlostJyz, &FaultModel_DW.PreLookUpIndexSearchaltitude_DW);
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // PreLookup: '<S136>/PreLook-Up Index Search  (prob of exceed)' incorporates:
    //   Constant: '<S136>/Probability of  Exceedance'

    FaultModel_B.PreLookUpIndexSearchprobofex_pz = plook_bincpa
      (FaultModel_P.DrydenWindTurbulenceModelDis_aw,
       FaultModel_P.PreLookUpIndexSearchprobofexcee, 6U,
       &FaultModel_B.PreLookUpIndexSearchprobofexcee,
       &FaultModel_DW.PreLookUpIndexSearchprobofexcee);
  }

  // Interpolation_n-D: '<S136>/Medium//High Altitude Intensity'
  frac[0] = uavlostJyz;
  frac[1] = FaultModel_B.PreLookUpIndexSearchprobofexcee;
  bpIndex[1] = FaultModel_B.PreLookUpIndexSearchprobofex_pz;

  // Interpolation_n-D: '<S136>/Medium//High Altitude Intensity'
  rtb_count = intrp2d_la_pw(bpIndex, frac,
    FaultModel_P.MediumHighAltitudeIntensity_Tab, 12U,
    FaultModel_P.MediumHighAltitudeIntensity_max);
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
    // Sqrt: '<S129>/Sqrt1' incorporates:
    //   Constant: '<S129>/Constant1'

    uavlostJyz = std::sqrt(FaultModel_P.WhiteNoise_Ts);

    // Product: '<S129>/Product' incorporates:
    //   Constant: '<S129>/Constant'
    //   Product: '<S129>/Divide'
    //   RandomNumber: '<S129>/White Noise'
    //   Sqrt: '<S129>/Sqrt'

    FaultModel_B.Product_k[0] = std::sqrt(FaultModel_P.WhiteNoise_pwr[0]) /
      uavlostJyz * FaultModel_DW.NextOutput[0];
    FaultModel_B.Product_k[1] = std::sqrt(FaultModel_P.WhiteNoise_pwr[1]) /
      uavlostJyz * FaultModel_DW.NextOutput[1];
    FaultModel_B.Product_k[2] = std::sqrt(FaultModel_P.WhiteNoise_pwr[2]) /
      uavlostJyz * FaultModel_DW.NextOutput[2];
    FaultModel_B.Product_k[3] = std::sqrt(FaultModel_P.WhiteNoise_pwr[3]) /
      uavlostJyz * FaultModel_DW.NextOutput[3];
  }

  // Outputs for Enabled SubSystem: '<S120>/Hugw(z)'
  // Constant: '<S120>/Constant3'
  FaultModel_Hugwz(FaultModel_P.DrydenWindTurbulenceModelDisc_a,
                   FaultModel_B.UnitConversion, rtb_TmpSignalConversionAtSFun_1,
                   FaultModel_B.UnitConversion_j, rtb_Add, rtb_count,
                   FaultModel_B.Product_k[0], &FaultModel_B.Hugwz_i,
                   &FaultModel_DW.Hugwz_i, &FaultModel_P.Hugwz_i);

  // End of Outputs for SubSystem: '<S120>/Hugw(z)'

  // Gain: '<S126>/Lv'
  rtb_Sum_ik[0] = FaultModel_P.Lv_Gain * rtb_TmpSignalConversionAtSFun_1;
  rtb_Sum_ik[1] = FaultModel_P.Lv_Gain * FaultModel_B.UnitConversion_j;

  // Outputs for Enabled SubSystem: '<S120>/Hvgw(z)'
  // Constant: '<S120>/Constant3'
  FaultModel_Hvgwz(FaultModel_P.DrydenWindTurbulenceModelDisc_a, rtb_Add,
                   rtb_count, rtb_Sum_ik, FaultModel_B.UnitConversion,
                   FaultModel_B.Product_k[1], &FaultModel_B.Hvgwz_p,
                   &FaultModel_DW.Hvgwz_p, &FaultModel_P.Hvgwz_p);

  // End of Outputs for SubSystem: '<S120>/Hvgw(z)'

  // Gain: '<S126>/Lw'
  rtb_Sum_ik[0] = FaultModel_P.Lw_Gain * uavlostJxy;
  rtb_Sum_ik[1] = FaultModel_P.Lw_Gain * FaultModel_B.UnitConversion_j;

  // Outputs for Enabled SubSystem: '<S120>/Hwgw(z)'
  // Constant: '<S120>/Constant3'
  FaultModel_Hwgwz(FaultModel_P.DrydenWindTurbulenceModelDisc_a,
                   FaultModel_B.UnitConversion, rtb_Sum_ik,
                   FaultModel_B.sigma_wg, rtb_count, FaultModel_B.Product_k[2],
                   &FaultModel_B.Hwgwz_a, &FaultModel_DW.Hwgwz_a,
                   &FaultModel_P.Hwgwz_a);

  // End of Outputs for SubSystem: '<S120>/Hwgw(z)'
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // UnitConversion: '<S118>/Unit Conversion' incorporates:
    //   Constant: '<S63>/Wind direction'

    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    FaultModel_B.UnitConversion_h = 0.017453292519943295 *
      FaultModel_P.DrydenWindTurbulenceModelDisc_i;
  }

  // If: '<S125>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' incorporates:
  //   Constant: '<S61>/Constant_DCM'
  //   UnitConversion: '<S121>/Unit Conversion'

  if (rtmIsMajorTimeStep((&FaultModel_M))) {
    if (massOb <= 1000.0) {
      rtAction = 0;
    } else if (massOb >= 2000.0) {
      rtAction = 1;
    } else {
      rtAction = 2;
    }

    FaultModel_DW.ifHeightMaxlowaltitudeelseifHei = rtAction;
  } else {
    rtAction = FaultModel_DW.ifHeightMaxlowaltitudeelseifHei;
  }

  switch (rtAction) {
   case 0:
    // Outputs for IfAction SubSystem: '<S125>/Low altitude  velocities' incorporates:
    //   ActionPort: '<S147>/Action Port'

    FaultMode_Lowaltitudevelocities(FaultModel_P.Constant_DCM_Value,
      FaultModel_B.Hugwz_i.Sum, FaultModel_B.Hvgwz_p.Sum,
      FaultModel_B.Hwgwz_a.Sum, FaultModel_B.UnitConversion_h, rtb_Wind);

    // End of Outputs for SubSystem: '<S125>/Low altitude  velocities'
    break;

   case 1:
    // Outputs for IfAction SubSystem: '<S125>/Medium//High  altitude velocities' incorporates:
    //   ActionPort: '<S148>/Action Port'

    // Product: '<S61>/Product' incorporates:
    //   Gain: '<S148>/Gain'

    rtb_Wind[0] = FaultModel_P.Gain_Gain_n * FaultModel_B.Hugwz_i.Sum[1];
    rtb_Wind[1] = FaultModel_P.Gain_Gain_n * FaultModel_B.Hvgwz_p.Sum[1];
    rtb_Wind[2] = FaultModel_P.Gain_Gain_n * FaultModel_B.Hwgwz_a.Sum[1];

    // End of Outputs for SubSystem: '<S125>/Medium//High  altitude velocities'
    break;

   case 2:
    // Outputs for IfAction SubSystem: '<S125>/Interpolate  velocities' incorporates:
    //   ActionPort: '<S146>/Action Port'

    FaultMode_Interpolatevelocities(FaultModel_B.Hugwz_i.Sum,
      FaultModel_B.Hvgwz_p.Sum, FaultModel_B.Hwgwz_a.Sum,
      FaultModel_P.Constant_DCM_Value, FaultModel_B.UnitConversion_h, massOb,
      rtb_Wind, &FaultModel_B.Interpolatevelocities_p,
      &FaultModel_P.Interpolatevelocities_p);

    // End of Outputs for SubSystem: '<S125>/Interpolate  velocities'
    break;
  }

  // End of If: '<S125>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 
  // Unit Conversion - from: ft/s to: m/s
  // Expression: output = (0.3048*input) + (0)
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // MATLAB Function: '<S61>/MATLAB Function' incorporates:
    //   UnitConversion: '<S63>/Unit Conversion'

    std::memcpy(&rtb_FaultParam_e5[0], &FaultModel_B.FaultParam_i[0], 20U *
                sizeof(real_T));

    // MATLAB Function 'Environment FaultModel1/Env FaultWindModel/MATLAB Function': '<S71>:1' 
    // '<S71>:1:3' if(GustWindParams(2)<1)
    if (FaultModel_B.FaultParam_i[1] < 1.0) {
      // '<S71>:1:4' GustWindParams(2)=1;
      rtb_FaultParam_e5[1] = 1.0;
    }

    // '<S71>:1:6' timeVel=60/GustWindParams(2);
    rtb_TmpSignalConversionAtSFun_1 = 60.0 / rtb_FaultParam_e5[1];

    // '<S71>:1:8' vmax=GustWindParams(1);
    rtb_Add = FaultModel_B.FaultParam_i[0];

    // '<S71>:1:11' if isempty(t0)
    // '<S71>:1:16' if isempty(isInGust)
    // '<S71>:1:21' if isempty(t1)
    // '<S71>:1:26' if isempty(a)
    // '<S71>:1:31' if isempty(ang)
    // '<S71>:1:36' if isempty(wlast)
    if (!FaultModel_DW.wlast_not_empty) {
      // '<S71>:1:37' wlast=vmax*0.5;
      FaultModel_DW.wlast = FaultModel_B.FaultParam_i[0] * 0.5;
      FaultModel_DW.wlast_not_empty = true;
    }

    // '<S71>:1:41' if isempty(wNow)
    if (!FaultModel_DW.wNow_not_empty) {
      // '<S71>:1:42' wNow=1.4*0.8*vmax;
      FaultModel_DW.wNow = 1.1199999999999999 * FaultModel_B.FaultParam_i[0];
      FaultModel_DW.wNow_not_empty = true;
    }

    // '<S71>:1:46' if isGustWind&&isInGust<0.5
    if (FaultModel_B.hasFault_GustWind && (FaultModel_DW.isInGust < 0.5)) {
      // '<S71>:1:47' t0=t;
      FaultModel_DW.t0 = rtb_Clock1_tmp;

      // '<S71>:1:48' t1=timeVel*(3/4+1/2*rand(1));
      FaultModel_DW.t1 = (0.5 * FaultModel_rand_j() + 0.75) *
        rtb_TmpSignalConversionAtSFun_1;

      // '<S71>:1:49' a=1/4+1/2*rand(1);
      FaultModel_DW.a = 0.5 * FaultModel_rand_j() + 0.25;

      // '<S71>:1:50' ang=pi*2*rand(1);
      FaultModel_DW.ang = 6.2831853071795862 * FaultModel_rand_j();

      // '<S71>:1:51' wlast=wNow;
      FaultModel_DW.wlast = FaultModel_DW.wNow;

      // '<S71>:1:52' wNow=1.2*(rand(1)*0.5+0.5)*vmax;
      FaultModel_DW.wNow = (FaultModel_rand_j() * 0.5 + 0.5) * 1.2 * rtb_Add;

      // '<S71>:1:54' isInGust=1;
      FaultModel_DW.isInGust = 1.0;
    }

    // '<S71>:1:57' if ~isGustWind
    if (!FaultModel_B.hasFault_GustWind) {
      // '<S71>:1:58' isInGust=0;
      FaultModel_DW.isInGust = 0.0;
    }

    // '<S71>:1:61' gWind=[0;0;0];
    // '<S71>:1:63' if(t<t0+t1*a)
    rtb_wind_idx_0 = FaultModel_DW.t1 * FaultModel_DW.a;
    if (rtb_Clock1_tmp < rtb_wind_idx_0 + FaultModel_DW.t0) {
      // '<S71>:1:64' gWindMag=(wNow-wlast)/2*(1-cos((t-t0)/(t1*a)*pi))+wlast;
      uavlostJyz = (1.0 - std::cos((rtb_Clock1_tmp - FaultModel_DW.t0) /
        rtb_wind_idx_0 * 3.1415926535897931)) * ((FaultModel_DW.wNow -
        FaultModel_DW.wlast) / 2.0) + FaultModel_DW.wlast;
    } else {
      // '<S71>:1:65' else
      // '<S71>:1:66' gWindMag=wNow;
      uavlostJyz = FaultModel_DW.wNow;
    }

    // '<S71>:1:69' if abs(t-(t0+t1))<0.05
    if (std::abs(rtb_Clock1_tmp - (FaultModel_DW.t0 + FaultModel_DW.t1)) < 0.05)
    {
      // '<S71>:1:70' rng(t*1000);
      rtb_wind_idx_0 = rtb_Clock1_tmp * 1000.0;
      if (rtb_wind_idx_0 < 4.294967296E+9) {
        if (rtb_wind_idx_0 >= 0.0) {
          seed = static_cast<uint32_T>(rtb_wind_idx_0);
        } else {
          seed = 0U;
        }
      } else {
        seed = MAX_uint32_T;
      }

      switch (FaultModel_DW.method) {
       case 7U:
        if (seed == 0U) {
          seed = 5489U;
        }

        if (!FaultModel_DW.state_not_empty) {
          std::memset(&FaultModel_DW.state_d[0], 0, 625U * sizeof(uint32_T));
          b_r = 5489U;
          for (r = 0; r < 623; r++) {
            b_r = ((b_r >> 30U ^ b_r) * 1812433253U + r) + 1U;
            FaultModel_DW.state_d[r + 1] = b_r;
          }

          FaultModel_DW.state_not_empty = true;
        }

        FaultModel_DW.state_d[0] = seed;
        for (r = 0; r < 623; r++) {
          seed = ((seed >> 30U ^ seed) * 1812433253U + r) + 1U;
          FaultModel_DW.state_d[r + 1] = seed;
        }

        FaultModel_DW.state_d[624] = 624U;
        break;

       case 5U:
        FaultModel_DW.state_k[0] = 362436069U;
        FaultModel_DW.state_k[1] = seed;
        if (FaultModel_DW.state_k[1] == 0U) {
          FaultModel_DW.state_k[1] = 521288629U;
        }
        break;

       default:
        r = static_cast<int32_T>(seed >> 16U);
        b_t = static_cast<int32_T>(seed & 32768U);
        seed = ((((seed - (static_cast<uint32_T>(r) << 16U)) - b_t) << 16U) +
                b_t) + r;
        if (seed < 1U) {
          seed = 1144108930U;
        } else {
          if (seed > 2147483646U) {
            seed = 2147483646U;
          }
        }

        FaultModel_DW.state = seed;
        break;
      }

      // '<S71>:1:71' t0=t;
      FaultModel_DW.t0 = rtb_Clock1_tmp;

      // '<S71>:1:72' t1=timeVel*(3/4+1/2*rand(1));
      FaultModel_DW.t1 = (0.5 * FaultModel_rand_j() + 0.75) *
        rtb_TmpSignalConversionAtSFun_1;

      // '<S71>:1:73' a=1/4+1/2*rand(1);
      FaultModel_DW.a = 0.5 * FaultModel_rand_j() + 0.25;

      // '<S71>:1:74' ang=ang+0.1*pi*rand(1);
      FaultModel_DW.ang += 0.31415926535897931 * FaultModel_rand_j();

      // '<S71>:1:75' wlast=wNow;
      FaultModel_DW.wlast = FaultModel_DW.wNow;

      // '<S71>:1:76' wNow=1.2*(rand(1)*0.5+0.5)*vmax;
      FaultModel_DW.wNow = (FaultModel_rand_j() * 0.5 + 0.5) * 1.2 * rtb_Add;
    }

    // '<S71>:1:79' gWind(1)=gWindMag*cos(ang)*0.8+turb(1)*0.4;
    FaultModel_B.gWind[0] = uavlostJyz * std::cos(FaultModel_DW.ang) * 0.8 +
      0.3048 * rtb_Wind[0] * 0.4;

    // '<S71>:1:80' gWind(2)=gWindMag*sin(ang)*0.8+turb(2)*0.4;
    FaultModel_B.gWind[1] = uavlostJyz * std::sin(FaultModel_DW.ang) * 0.8 +
      0.3048 * rtb_Wind[1] * 0.4;

    // '<S71>:1:81' gWind(3)=turb(3)*0.4;
    FaultModel_B.gWind[2] = 0.3048 * rtb_Wind[2] * 0.4;

    // End of MATLAB Function: '<S61>/MATLAB Function'

    // UnitConversion: '<S88>/Unit Conversion' incorporates:
    //   Constant: '<S61>/Constant_V'

    // Unit Conversion - from: m/s to: ft/s
    // Expression: output = (3.28084*input) + (0)
    FaultModel_B.UnitConversion_b = 3.280839895013123 *
      FaultModel_P.Constant_V_Value;
  }

  // Saturate: '<S115>/Limit Function 10ft to 1000ft'
  // Unit Conversion - from: m to: ft
  // Expression: output = (3.28084*input) + (0)
  if (massOb > FaultModel_P.LimitFunction10ftto1000ft_Upp_a) {
    uavlostJxy = FaultModel_P.LimitFunction10ftto1000ft_Upp_a;
  } else if (massOb < FaultModel_P.LimitFunction10ftto1000ft_Low_l) {
    uavlostJxy = FaultModel_P.LimitFunction10ftto1000ft_Low_l;
  } else {
    uavlostJxy = massOb;
  }

  // End of Saturate: '<S115>/Limit Function 10ft to 1000ft'

  // Fcn: '<S115>/Low Altitude Scale Length'
  uavlostJyz = 0.000823 * uavlostJxy + 0.177;
  if (uavlostJyz < 0.0) {
    uavlostJyz = -rt_powd_snf(-uavlostJyz, 1.2);
  } else {
    uavlostJyz = rt_powd_snf(uavlostJyz, 1.2);
  }

  // Fcn: '<S115>/Low Altitude Scale Length'
  rtb_LimitaltitudetoStratosphere = uavlostJxy / uavlostJyz;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // UnitConversion: '<S117>/Unit Conversion' incorporates:
    //   Constant: '<S116>/Medium//High Altitude'

    // Unit Conversion - from: m to: ft
    // Expression: output = (3.28084*input) + (0)
    FaultModel_B.UnitConversion_f = 3.280839895013123 *
      FaultModel_P.DrydenWindTurbulenceModelDisc_j;
  }

  // Saturate: '<S98>/Limit Height h<1000ft'
  if (massOb > FaultModel_P.LimitHeighth1000ft_UpperSat_d) {
    rtb_TmpSignalConversionAtSFun_1 = FaultModel_P.LimitHeighth1000ft_UpperSat_d;
  } else if (massOb < FaultModel_P.LimitHeighth1000ft_LowerSat_k) {
    rtb_TmpSignalConversionAtSFun_1 = FaultModel_P.LimitHeighth1000ft_LowerSat_k;
  } else {
    rtb_TmpSignalConversionAtSFun_1 = massOb;
  }

  // End of Saturate: '<S98>/Limit Height h<1000ft'

  // Fcn: '<S98>/Low Altitude Intensity'
  uavlostJyz = 0.000823 * rtb_TmpSignalConversionAtSFun_1 + 0.177;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Gain: '<S98>/sigma_wg ' incorporates:
    //   Constant: '<S62>/Windspeed at 20ft (6m)'
    //   UnitConversion: '<S89>/Unit Conversion'

    // Unit Conversion - from: m/s to: ft/s
    // Expression: output = (3.28084*input) + (0)
    FaultModel_B.sigma_wg_a = 3.280839895013123 *
      FaultModel_P.DrydenWindTurbulenceModelDis_mb *
      FaultModel_P.sigma_wg_Gain_h;
  }

  // Fcn: '<S98>/Low Altitude Intensity'
  if (uavlostJyz < 0.0) {
    uavlostJyz = -rt_powd_snf(-uavlostJyz, 0.4);
  } else {
    uavlostJyz = rt_powd_snf(uavlostJyz, 0.4);
  }

  // Product: '<S98>/sigma_ug, sigma_vg' incorporates:
  //   Fcn: '<S98>/Low Altitude Intensity'

  rtb_jxi = 1.0 / uavlostJyz * FaultModel_B.sigma_wg_a;

  // Interpolation_n-D: '<S97>/Medium//High Altitude Intensity' incorporates:
  //   PreLookup: '<S97>/PreLook-Up Index Search  (altitude)'

  bpIndex_0[0] = plook_bincpa(massOb,
    FaultModel_P.PreLookUpIndexSearchaltitude__k, 11U, &uavlostJyz,
    &FaultModel_DW.PreLookUpIndexSearchaltitude__e);
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // PreLookup: '<S97>/PreLook-Up Index Search  (prob of exceed)' incorporates:
    //   Constant: '<S97>/Probability of  Exceedance'

    FaultModel_B.PreLookUpIndexSearchprobofexc_o = plook_bincpa
      (FaultModel_P.DrydenWindTurbulenceModelDisc_h,
       FaultModel_P.PreLookUpIndexSearchprobofexc_f, 6U,
       &FaultModel_B.PreLookUpIndexSearchprobofexc_p,
       &FaultModel_DW.PreLookUpIndexSearchprobofexc_j);
  }

  // Interpolation_n-D: '<S97>/Medium//High Altitude Intensity'
  frac_0[0] = uavlostJyz;
  frac_0[1] = FaultModel_B.PreLookUpIndexSearchprobofexc_p;
  bpIndex_0[1] = FaultModel_B.PreLookUpIndexSearchprobofexc_o;

  // Interpolation_n-D: '<S97>/Medium//High Altitude Intensity'
  rtb_Add = intrp2d_la_pw(bpIndex_0, frac_0,
    FaultModel_P.MediumHighAltitudeIntensity_T_c, 12U,
    FaultModel_P.MediumHighAltitudeIntensity_m_o);
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
    // Sqrt: '<S90>/Sqrt1' incorporates:
    //   Constant: '<S90>/Constant1'

    uavlostJyz = std::sqrt(FaultModel_P.WhiteNoise_Ts_p);

    // Product: '<S90>/Product' incorporates:
    //   Constant: '<S90>/Constant'
    //   Product: '<S90>/Divide'
    //   RandomNumber: '<S90>/White Noise'
    //   Sqrt: '<S90>/Sqrt'

    FaultModel_B.Product_n[0] = std::sqrt(FaultModel_P.WhiteNoise_pwr_d[0]) /
      uavlostJyz * FaultModel_DW.NextOutput_j[0];
    FaultModel_B.Product_n[1] = std::sqrt(FaultModel_P.WhiteNoise_pwr_d[1]) /
      uavlostJyz * FaultModel_DW.NextOutput_j[1];
    FaultModel_B.Product_n[2] = std::sqrt(FaultModel_P.WhiteNoise_pwr_d[2]) /
      uavlostJyz * FaultModel_DW.NextOutput_j[2];
    FaultModel_B.Product_n[3] = std::sqrt(FaultModel_P.WhiteNoise_pwr_d[3]) /
      uavlostJyz * FaultModel_DW.NextOutput_j[3];
  }

  // Outputs for Enabled SubSystem: '<S81>/Hugw(z)'
  // Constant: '<S81>/Constant3'
  FaultModel_Hugwz(FaultModel_P.DrydenWindTurbulenceModelDisc_m,
                   FaultModel_B.UnitConversion_b,
                   rtb_LimitaltitudetoStratosphere,
                   FaultModel_B.UnitConversion_f, rtb_jxi, rtb_Add,
                   FaultModel_B.Product_n[0], &FaultModel_B.Hugwz,
                   &FaultModel_DW.Hugwz, &FaultModel_P.Hugwz);

  // End of Outputs for SubSystem: '<S81>/Hugw(z)'

  // Gain: '<S87>/Lv'
  frac_0[0] = FaultModel_P.Lv_Gain_g * rtb_LimitaltitudetoStratosphere;
  frac_0[1] = FaultModel_P.Lv_Gain_g * FaultModel_B.UnitConversion_f;

  // Outputs for Enabled SubSystem: '<S81>/Hvgw(z)'
  // Constant: '<S81>/Constant3'
  FaultModel_Hvgwz(FaultModel_P.DrydenWindTurbulenceModelDisc_m, rtb_jxi,
                   rtb_Add, frac_0, FaultModel_B.UnitConversion_b,
                   FaultModel_B.Product_n[1], &FaultModel_B.Hvgwz,
                   &FaultModel_DW.Hvgwz, &FaultModel_P.Hvgwz);

  // End of Outputs for SubSystem: '<S81>/Hvgw(z)'

  // Gain: '<S87>/Lw'
  frac_0[0] = FaultModel_P.Lw_Gain_g * uavlostJxy;
  frac_0[1] = FaultModel_P.Lw_Gain_g * FaultModel_B.UnitConversion_f;

  // Outputs for Enabled SubSystem: '<S81>/Hwgw(z)'
  // Constant: '<S81>/Constant3'
  FaultModel_Hwgwz(FaultModel_P.DrydenWindTurbulenceModelDisc_m,
                   FaultModel_B.UnitConversion_b, frac_0,
                   FaultModel_B.sigma_wg_a, rtb_Add, FaultModel_B.Product_n[2],
                   &FaultModel_B.Hwgwz, &FaultModel_DW.Hwgwz,
                   &FaultModel_P.Hwgwz);

  // End of Outputs for SubSystem: '<S81>/Hwgw(z)'
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // UnitConversion: '<S79>/Unit Conversion' incorporates:
    //   Constant: '<S62>/Wind direction'

    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    FaultModel_B.UnitConversion_e = 0.017453292519943295 *
      FaultModel_P.DrydenWindTurbulenceModelDisc_o;
  }

  // If: '<S86>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' incorporates:
  //   Constant: '<S61>/Constant_DCM'

  if (rtmIsMajorTimeStep((&FaultModel_M))) {
    if (massOb <= 1000.0) {
      rtAction = 0;
    } else if (massOb >= 2000.0) {
      rtAction = 1;
    } else {
      rtAction = 2;
    }

    FaultModel_DW.ifHeightMaxlowaltitudeelseifH_d = rtAction;
  } else {
    rtAction = FaultModel_DW.ifHeightMaxlowaltitudeelseifH_d;
  }

  switch (rtAction) {
   case 0:
    // Outputs for IfAction SubSystem: '<S86>/Low altitude  velocities' incorporates:
    //   ActionPort: '<S108>/Action Port'

    FaultMode_Lowaltitudevelocities(FaultModel_P.Constant_DCM_Value,
      FaultModel_B.Hugwz.Sum, FaultModel_B.Hvgwz.Sum, FaultModel_B.Hwgwz.Sum,
      FaultModel_B.UnitConversion_e, rtb_Wind);

    // End of Outputs for SubSystem: '<S86>/Low altitude  velocities'
    break;

   case 1:
    // Outputs for IfAction SubSystem: '<S86>/Medium//High  altitude velocities' incorporates:
    //   ActionPort: '<S109>/Action Port'

    // Product: '<S61>/Product' incorporates:
    //   Gain: '<S109>/Gain'

    rtb_Wind[0] = FaultModel_P.Gain_Gain_c * FaultModel_B.Hugwz.Sum[1];
    rtb_Wind[1] = FaultModel_P.Gain_Gain_c * FaultModel_B.Hvgwz.Sum[1];
    rtb_Wind[2] = FaultModel_P.Gain_Gain_c * FaultModel_B.Hwgwz.Sum[1];

    // End of Outputs for SubSystem: '<S86>/Medium//High  altitude velocities'
    break;

   case 2:
    // Outputs for IfAction SubSystem: '<S86>/Interpolate  velocities' incorporates:
    //   ActionPort: '<S107>/Action Port'

    FaultMode_Interpolatevelocities(FaultModel_B.Hugwz.Sum,
      FaultModel_B.Hvgwz.Sum, FaultModel_B.Hwgwz.Sum,
      FaultModel_P.Constant_DCM_Value, FaultModel_B.UnitConversion_e, massOb,
      rtb_Wind, &FaultModel_B.Interpolatevelocities,
      &FaultModel_P.Interpolatevelocities);

    // End of Outputs for SubSystem: '<S86>/Interpolate  velocities'
    break;
  }

  // End of If: '<S86>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 

  // UnitConversion: '<S62>/Unit Conversion'
  // Unit Conversion - from: ft/s to: m/s
  // Expression: output = (0.3048*input) + (0)
  Product1[0] = 0.3048 * rtb_Wind[0];
  Product1[1] = 0.3048 * rtb_Wind[1];
  Product1[2] = 0.3048 * rtb_Wind[2];

  // UnitConversion: '<S184>/Unit Conversion'
  // MATLAB Function 'Environment FaultModel1/Env FaultWindModel/TurbWindStrength_Dec_Switch': '<S75>:1' 
  // '<S75>:1:3' TurbWind=vwind*TurbWindParams(1);
  // Unit Conversion - from: m to: ft
  // Expression: output = (3.28084*input) + (0)
  uavlostJzx = massOb;

  // Saturate: '<S77>/3ft-->inf'
  if (massOb > FaultModel_P.uftinf_UpperSat) {
    uavlostJzx = FaultModel_P.uftinf_UpperSat;
  } else {
    if (massOb < FaultModel_P.uftinf_LowerSat) {
      uavlostJzx = FaultModel_P.uftinf_LowerSat;
    }
  }

  // End of Saturate: '<S77>/3ft-->inf'

  // Gain: '<S77>/h//z0'
  uavlostJzx *= FaultModel_P.hz0_Gain;

  // Math: '<S77>/ln(h//z0)'
  //
  //  About '<S77>/ln(h//z0)':
  //   Operator: log

  uavlostJzx = std::log(uavlostJzx);
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Math: '<S77>/ln(ref_height//z0)' incorporates:
    //   Constant: '<S77>/ref_height//z0'
    //
    //  About '<S77>/ln(ref_height//z0)':
    //   Operator: log

    FaultModel_B.lnref_heightz0 = std::log(FaultModel_P.ref_heightz0_Value);

    // UnitConversion: '<S183>/Unit Conversion' incorporates:
    //   Constant: '<S77>/Wind Direction'

    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    Y = 0.017453292519943295 * FaultModel_P.WindShearModel_Wdeg;

    // Trigonometry: '<S77>/SinCos'
    Z = std::cos(Y);
    Y = std::sin(Y);

    // Gain: '<S77>/Wind speed at reference height' incorporates:
    //   Constant: '<S77>/Wdeg1'
    //   Trigonometry: '<S77>/SinCos'

    FaultModel_B.Windspeedatreferenceheight[0] =
      -FaultModel_P.WindShearModel_W_20 * Z;
    FaultModel_B.Windspeedatreferenceheight[1] =
      -FaultModel_P.WindShearModel_W_20 * Y;
    FaultModel_B.Windspeedatreferenceheight[2] =
      -FaultModel_P.WindShearModel_W_20 * FaultModel_P.Wdeg1_Value;
  }

  // Product: '<S77>/Product'
  uavlostJyz = uavlostJzx / FaultModel_B.lnref_heightz0;

  // Product: '<S61>/Product' incorporates:
  //   Product: '<S77>/Product1'

  // MATLAB Function 'Environment FaultModel1/Env FaultWindModel/SheerWindStrength_Dec_Switch': '<S73>:1' 
  // '<S73>:1:2' SheerWind=vwind*SheerWindParams(1);
  // MATLAB Function 'Environment FaultModel1/Env FaultWindModel/MATLAB Function1': '<S72>:1' 
  // '<S72>:1:2' wind=[0;0;0];
  rtb_Wind[0] = uavlostJyz * FaultModel_B.Windspeedatreferenceheight[0];

  // MATLAB Function: '<S61>/MATLAB Function1'
  rtb_wind_idx_0 = 0.0;

  // Product: '<S61>/Product' incorporates:
  //   Product: '<S77>/Product1'

  rtb_Wind[1] = uavlostJyz * FaultModel_B.Windspeedatreferenceheight[1];

  // MATLAB Function: '<S61>/MATLAB Function1'
  rtb_LimitaltitudetoStratosphere = 0.0;

  // Product: '<S61>/Product' incorporates:
  //   Product: '<S77>/Product1'

  rtb_Wind[2] = uavlostJyz * FaultModel_B.Windspeedatreferenceheight[2];

  // MATLAB Function: '<S61>/MATLAB Function1' incorporates:
  //   MATLAB Function: '<S61>/SheerWindStrength_Dec_Switch'
  //   MATLAB Function: '<S61>/TurbWindStrength_Dec_Switch'
  //   Product: '<S77>/Transform from Inertial to Body axes'

  uavlostJyz = 0.0;

  // '<S72>:1:3' if isConstWind
  if (FaultModel_B.hasFault_ConstWind) {
    // '<S72>:1:4' wind=[ConstWind(1);ConstWind(2);ConstWind(3)];
    rtb_wind_idx_0 = FaultModel_B.FaultParam_e[0];
    rtb_LimitaltitudetoStratosphere = FaultModel_B.FaultParam_e[1];
    uavlostJyz = FaultModel_B.FaultParam_e[2];
  } else if (FaultModel_B.hasFault_GustWind) {
    // '<S72>:1:5' elseif isGustWind
    // '<S72>:1:6' wind=GustWind;
    rtb_wind_idx_0 = FaultModel_B.gWind[0];
    rtb_LimitaltitudetoStratosphere = FaultModel_B.gWind[1];
    uavlostJyz = FaultModel_B.gWind[2];
  } else if (FaultModel_B.hasFault_TurbWind) {
    // '<S72>:1:7' elseif isTurbWind
    // '<S72>:1:8' wind=TurbWind;
    rtb_wind_idx_0 = Product1[0] * FaultModel_B.FaultParam_k[0];
    rtb_LimitaltitudetoStratosphere = Product1[1] * FaultModel_B.FaultParam_k[0];
    uavlostJyz = Product1[2] * FaultModel_B.FaultParam_k[0];
  } else {
    if (FaultModel_B.hasFault_SheerWind) {
      // Product: '<S77>/Transform from Inertial to Body axes' incorporates:
      //   Constant: '<S61>/Constant_DCM'
      //   Product: '<S61>/Product'

      // '<S72>:1:9' elseif isSheerWind
      // '<S72>:1:10' wind=SheerWind;
      for (qY_1 = 0; qY_1 < 3; qY_1++) {
        tmp[qY_1] = FaultModel_P.Constant_DCM_Value[qY_1 + 6] * rtb_Wind[2] +
          (FaultModel_P.Constant_DCM_Value[qY_1 + 3] * rtb_Wind[1] +
           FaultModel_P.Constant_DCM_Value[qY_1] * rtb_Wind[0]);
      }

      rtb_wind_idx_0 = tmp[0] * FaultModel_B.FaultParam[0];
      rtb_LimitaltitudetoStratosphere = tmp[1] * FaultModel_B.FaultParam[0];
      uavlostJyz = tmp[2] * FaultModel_B.FaultParam[0];
    }
  }

  for (i = 0; i < 3; i++) {
    // Product: '<S61>/Product' incorporates:
    //   Concatenate: '<S34>/Vector Concatenate'

    rtb_Wind[i] = 0.0;
    rtb_Wind[i] += VectorConcatenate[i] * rtb_wind_idx_0;
    rtb_Wind[i] += VectorConcatenate[i + 3] * rtb_LimitaltitudetoStratosphere;
    rtb_Wind[i] += VectorConcatenate[i + 6] * uavlostJyz;

    // Product: '<S61>/Product1' incorporates:
    //   Integrator: '<S12>/ub,vb,wb'
    //   Sum: '<S61>/Sum'
    //   Sum: '<S61>/Sum1'

    rtb_Windb[i] = (FaultModel_X.ubvbwb_CSTATE[i] - rtb_Wind[i]) *
      FaultModel_B.Sum1[i];
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Math: '<S7>/Transpose' incorporates:
    //   Constant: '<S7>/ModelParam.uavCd'

    FaultModel_B.Transpose[0] = FaultModel_P.ModelParam_uavCd[0];
    FaultModel_B.Transpose[1] = FaultModel_P.ModelParam_uavCd[1];
    FaultModel_B.Transpose[2] = FaultModel_P.ModelParam_uavCd[2];

    // MATLAB Function: '<S286>/FaultParamsExtract' incorporates:
    //   Constant: '<S286>/FaultID'
    //   Inport: '<Root>/inSILInts'

    // MATLAB Function 'Force and Moment Model/Prop FaultModel/Prop FaultModel/FaultParamsExtract': '<S287>:1' 
    // '<S287>:1:5' if isempty(hFault)
    // '<S287>:1:8' if isempty(fParam)
    // '<S287>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S287>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S287>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S287>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S287>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID_Value_p) {
        // '<S287>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S287>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S287>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S287>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S287>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S287>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_he = true;

      // '<S287>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S287>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_by[0], &fParamTmp[0], 20U * sizeof
                  (real_T));
    }

    // MATLAB Function: '<S286>/PropFaultModel' incorporates:
    //   Constant: '<S286>/rotor_k_ct'
    //   MATLAB Function: '<S286>/FaultParamsExtract'

    // '<S287>:1:29' hasFault=hFault;
    // '<S287>:1:30' FaultParam=fParam;
    //  本模块需要用到8维FaultParam的输入
    // 因此故障ID的格式应该是：
    // inSILInts=[FaultID FaultID FaultID FaultID ...]
    // inSILInts=[param1 param2 param3 param4 param5 param6 param7 param8 ...] -> FaultParam 
    //  param的每一位表示本电机的健康系数（0到1），实际上就是pwm_out = pwm_in * param 
    //  如果param1=0，则电机1直接坏掉，始终输出0
    // MATLAB Function 'Force and Moment Model/Prop FaultModel/Prop FaultModel/PropFaultModel': '<S288>:1' 
    // '<S288>:1:9' y=normal_param;
    std::memcpy(&FaultModel_B.y_j[0], &FaultModel_P.rotor_k_ct_Value[0], sizeof
                (real_T) << 3U);

    // 默认情况下不注入故障，直接将数据输出
    // '<S288>:1:11' if hasFault
    if (FaultModel_DW.hFault_he) {
      // 如果注入了故障
      // '<S288>:1:12' for i=1:8
      for (r = 0; r < 8; r++) {
        // '<S288>:1:13' y(i) = normal_param(i) * FaultParam(i);
        FaultModel_B.y_j[r] = FaultModel_P.rotor_k_ct_Value[r] *
          FaultModel_DW.fParam_by[r];
      }
    }

    // End of MATLAB Function: '<S286>/PropFaultModel'
  }

  // SignalConversion generated from: '<S197>/ SFunction ' incorporates:
  //   MATLAB Function: '<S7>/Propeller Model old Version'

  Memory[0] = FaultModel_B.MotorNonlinearDynamic1.Motor_Dynamics.x;
  Memory[1] = FaultModel_B.MotorNonlinearDynamic2.Motor_Dynamics.x;
  Memory[2] = FaultModel_B.MotorNonlinearDynamic3.Motor_Dynamics.x;
  Memory[3] = FaultModel_B.MotorNonlinearDynamic4.Motor_Dynamics.x;
  Memory[4] = FaultModel_B.MotorNonlinearDynamic5.Motor_Dynamics.x;
  Memory[5] = FaultModel_B.MotorNonlinearDynamic6.Motor_Dynamics.x;
  Memory[6] = FaultModel_B.MotorNonlinearDynamic7.Motor_Dynamics.x;
  Memory[7] = FaultModel_B.MotorNonlinearDynamic8.Motor_Dynamics.x;

  // MATLAB Function: '<S7>/Propeller Model old Version' incorporates:
  //   Constant: '<S185>/ModelParam.uavR'
  //   Constant: '<S7>/ModelParam.motorJm'
  //   Constant: '<S7>/ModelParam.rotorCm'
  //   Constant: '<S7>/ModelParam.rotorCt'
  //   Constant: '<S7>/ModelParam.uavType'
  //   Integrator: '<S12>/p,q,r '
  //   SignalConversion generated from: '<S197>/ SFunction '

  rtAction = FaultModel_P.ModelParam_uavType;

  //  This is control effectiveness model, where Fb is the force produced by motors, Mb is 
  //  the moment produced by motors, and Fd is the resistance produced by the air. 
  //  The gyroscopic torque is not considered here.
  // MATLAB Function 'Force and Moment Model/Propeller Model old Version': '<S197>:1' 
  //  -1: anticlockwise, 1: clockwise
  //  % Tri 3*1 X
  //     % Tri 3*1 +
  //  % Quad 4*1 X
  //  % Quad 4*1 +
  //  % Hex 6*1 X
  //  % Hex 6*1 +
  //  % HexCoa 3*2
  //  % Oct 8*1 X
  //  % Oct 8*1 +
  //  % OctCoa 4*2 X
  // '<S197>:1:7' TypeMotorDirMatrix=[...
  // '<S197>:1:8'     [-1 -1 -1 0 0 0 0 0];... % Tri 3*1 X
  // '<S197>:1:9'     [1 1 1 0 0 0 0 0];...    % Tri 3*1 +
  // '<S197>:1:10'     [-1 -1 1 1 0 0 0 0];... % Quad 4*1 X
  // '<S197>:1:11'     [-1 -1 1 1 0 0 0 0];... % Quad 4*1 +
  // '<S197>:1:12'     [1 -1 1 -1 -1 1 0 0];... % Hex 6*1 X
  // '<S197>:1:13'     [1 -1 1 -1 -1 1 0 0];... % Hex 6*1 +
  // '<S197>:1:14'     [1 -1 1 -1 1 -1 0 0];... % HexCoa 3*2
  // '<S197>:1:15'     [1 1 -1 -1 -1 -1 1 1];... % Oct 8*1 X
  // '<S197>:1:16'     [1 1 -1 -1 -1 -1 1 1];... % Oct 8*1 +
  // '<S197>:1:17'     [1 -1 1 -1 1 -1 1 -1];... % OctCoa 4*2 X
  // '<S197>:1:18' ];
  // '<S197>:1:20' TypeMotorAngMatrix=[...
  // '<S197>:1:21'     [pi/3 pi -pi/3 0 0 0 0 0];...
  // '<S197>:1:22'     [pi/3 pi -pi/3 0 0 0 0 0];...
  // '<S197>:1:23'     [pi/4 pi/4+pi pi/4+3*pi/2 pi/4+pi/2 0 0 0 0];...
  // '<S197>:1:24'     [pi/2 3*pi/2 0 pi 0 0 0 0];...
  // '<S197>:1:25'     [pi/2 3/2*pi 3/2*pi+pi/3 pi/2+pi/3 pi/2-pi/3 3/2*pi-pi/3 0 0];... 
  // '<S197>:1:26'     [0 pi pi+pi/3 pi/3 -pi/3 pi-pi/3 0 0];...
  // '<S197>:1:27'     [pi/3 pi/3 pi pi -pi/3 -pi/3 0 0];...
  // '<S197>:1:28'     [pi/8 pi+pi/8 pi/8+pi/4 pi-pi/8 -pi/8 3/2*pi-pi/8 3/2*pi+pi/8 pi/2+pi/8];... 
  // '<S197>:1:29'     [0 pi pi/4 3/4*pi -pi/4 pi+pi/4 3/2*pi pi/2];...
  // '<S197>:1:30'     [pi/4 -pi/4 pi+pi/4 pi-pi/4 -pi/4 pi/4 pi-pi/4 pi+pi/4];... 
  // '<S197>:1:31' ];
  // '<S197>:1:33' TypeMotorNonVector=int8([3;3;4;4;6;6;6;8;8;8]);
  // '<S197>:1:35' Mb = [0;0;0];
  // '<S197>:1:36' Fb = [0;0;0];
  rtb_Mb_idx_0 = 0.0;
  Product1[0] = 0.0;
  rtb_Mb_idx_1 = 0.0;
  rtb_TmpSignalConversionAtSFun_1 = 0.0;
  Product1[2] = 0.0;

  // '<S197>:1:37' P=wb(1);
  // '<S197>:1:37' Q=wb(2);
  // '<S197>:1:39' if uavType==50
  if (FaultModel_P.ModelParam_uavType == 50) {
    // '<S197>:1:41' Fb(1)=MotorRads(1)+MotorRads(3);
    Product1[0] = FaultModel_B.MotorNonlinearDynamic1.Motor_Dynamics.x +
      FaultModel_B.MotorNonlinearDynamic3.Motor_Dynamics.x;

    // '<S197>:1:42' Mb(3)=MotorRads(1)*0.1-MotorRads(3)*0.1;
    rtb_TmpSignalConversionAtSFun_1 =
      FaultModel_B.MotorNonlinearDynamic1.Motor_Dynamics.x * 0.1 -
      FaultModel_B.MotorNonlinearDynamic3.Motor_Dynamics.x * 0.1;
  } else {
    // '<S197>:1:48' if uavType<0||uavType>length(TypeMotorNonVector)
    if ((FaultModel_P.ModelParam_uavType < 0) ||
        (FaultModel_P.ModelParam_uavType > 10)) {
      // '<S197>:1:49' uavType=int8(1);
      rtAction = 1;
    }

    // '<S197>:1:52' TypeMotorDirVector=TypeMotorDirMatrix(uavType,:);
    // '<S197>:1:53' TypeMotorAngVector=TypeMotorAngMatrix(uavType,:);
    // '<S197>:1:55' for i=1:TypeMotorNonVector(uavType)
    for (r = 1; r - 1 < TypeMotorNonVector[rtAction - 1]; r++) {
      // '<S197>:1:56' propAng = TypeMotorAngVector(i);
      // '<S197>:1:57' propdir = TypeMotorDirVector(i);
      // '<S197>:1:58' PropT = Ct*MotorRads(i)*MotorRads(i)*k_ct(i);
      rtb_count_m = Memory[static_cast<int8_T>(r) - 1];
      rtb_wind_idx_0 = FaultModel_B.y_j[static_cast<int8_T>(r) - 1];
      uavlostJyz = rtb_count_m * FaultModel_P.ModelParam_rotorCt * rtb_count_m *
        rtb_wind_idx_0;

      // '<S197>:1:59' PropM = Cm*MotorRads(i)*MotorRads(i)*k_ct(i);
      // Thrust -> Moment
      // '<S197>:1:62' Mb=Mb+[-R*sin(propAng)*PropT;R*cos(propAng)*PropT;-PropM*propdir]; 
      b_t = ((static_cast<int8_T>(r) - 1) * 10 + rtAction) - 1;
      rtb_LimitaltitudetoStratosphere = TypeMotorAngMatrix[b_t];
      rtb_Mb_idx_0 += std::sin(rtb_LimitaltitudetoStratosphere) *
        -FaultModel_P.ModelParam_uavR * uavlostJyz;
      rtb_Mb_idx_1 += std::cos(rtb_LimitaltitudetoStratosphere) *
        FaultModel_P.ModelParam_uavR * uavlostJyz;
      rtb_LimitaltitudetoStratosphere = TypeMotorDirMatrix[b_t];
      rtb_TmpSignalConversionAtSFun_1 += -(rtb_count_m *
        FaultModel_P.ModelParam_rotorCm * rtb_count_m * rtb_wind_idx_0) *
        rtb_LimitaltitudetoStratosphere;

      // gyroscopic moment
      // '<S197>:1:65' Mb=Mb+[Q*Jm*MotorRads(i)*propdir;-P*Jm*MotorRads(i)*propdir;0]; 
      rtb_Mb_idx_0 += rtb_LimitaltitudetoStratosphere *
        (FaultModel_X.pqr_CSTATE[1] * FaultModel_P.ModelParam_motorJm *
         rtb_count_m);
      rtb_Mb_idx_1 += rtb_LimitaltitudetoStratosphere *
        (-FaultModel_X.pqr_CSTATE[0] * FaultModel_P.ModelParam_motorJm *
         rtb_count_m);

      // '<S197>:1:67' Fb=Fb+[0;0;-PropT];
      rtb_count_m = Product1[2];
      Product1[0] = 0.0;
      Product1[2] = rtb_count_m + -uavlostJyz;
    }
  }

  // MATLAB Function: '<S7>/Body AeroCenter' incorporates:
  //   Math: '<S7>/Transpose'
  //   Product: '<S61>/Product1'

  //  This is control effectiveness model, where Fb is the force produced by motors, Mb is 
  //  the moment produced by motors, and Fd is the resistance produced by the air. 
  //  The gyroscopic torque is not considered here.
  //  uavDearo 机身重心位置，向下为正
  // MATLAB Function 'Force and Moment Model/Body AeroCenter': '<S190>:1'
  // '<S190>:1:7' Fd = -Cd.*Vb.*abs(Vb);
  //
  // '<S190>:1:9' Mfd=[Fd(2)*uavDearo;-Fd(1)*uavDearo;0];
  // '<S190>:1:11' Md=-CCm.*wb.*abs(wb);
  // '<S190>:1:12' Md=Mfd+Md;
  //   CCm=4.72e-3;
  //   Md=-CCm*wb.*abs(wb)*0.5;%0.3
  //   Md= Mfd+Md;
  uavlostJzx = -FaultModel_B.Transpose[0] * rtb_Windb[0] * std::abs(rtb_Windb[0]);

  // Sum: '<S7>/Add2'
  rtb_count_m = (rtb_Sum1_ki[0] + Product1[0]) + uavlostJzx;

  // Product: '<S11>/Divide' incorporates:
  //   Product: '<S400>/Matrix Multiply2'

  rtb_MatrixMultiply2[0] = rtb_count_m / FaultModel_B.m;

  // MATLAB Function: '<S7>/Body AeroCenter'
  rtb_Fd[0] = uavlostJzx;

  // Sum: '<S7>/Add2' incorporates:
  //   Sum: '<S1>/Sum1'

  rtb_Sum1_ki[0] = rtb_count_m;

  // MATLAB Function: '<S7>/Body AeroCenter' incorporates:
  //   Math: '<S7>/Transpose'
  //   Product: '<S61>/Product1'

  uavlostJzx = -FaultModel_B.Transpose[1] * rtb_Windb[1] * std::abs(rtb_Windb[1]);

  // Sum: '<S7>/Add2'
  rtb_count_m = rtb_Sum1_ki[1] + uavlostJzx;

  // Product: '<S11>/Divide' incorporates:
  //   Product: '<S400>/Matrix Multiply2'

  rtb_MatrixMultiply2[1] = rtb_count_m / FaultModel_B.m;

  // Sum: '<S7>/Add2' incorporates:
  //   MATLAB Function: '<S7>/Body AeroCenter'
  //   Math: '<S7>/Transpose'
  //   Product: '<S61>/Product1'
  //   Sum: '<S1>/Sum1'

  rtb_Sum1_ki[1] = rtb_count_m;
  rtb_count_m = -FaultModel_B.Transpose[2] * rtb_Windb[2] * std::abs(rtb_Windb[2])
    + (rtb_Sum1_ki[2] + Product1[2]);

  // Product: '<S11>/Divide' incorporates:
  //   Product: '<S400>/Matrix Multiply2'

  rtb_MatrixMultiply2[2] = rtb_count_m / FaultModel_B.m;

  // Gain: '<S423>/Zero-Order Hold' incorporates:
  //   Integrator: '<S12>/p,q,r '

  Product1[0] = FaultModel_P.ZeroOrderHold_Gain * FaultModel_X.pqr_CSTATE[0];
  Product1[1] = FaultModel_P.ZeroOrderHold_Gain * FaultModel_X.pqr_CSTATE[1];
  Product1[2] = FaultModel_P.ZeroOrderHold_Gain * FaultModel_X.pqr_CSTATE[2];
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Gain: '<S423>/Gain' incorporates:
    //   Constant: '<S400>/center of gravity'
    //   Constant: '<S423>/wl_ins'
    //   Gain: '<S423>/Zero-Order Hold4'
    //   Sum: '<S423>/Sum7'

    FaultModel_B.Gain[0] = (FaultModel_P.ZeroOrderHold4_Gain *
      FaultModel_P.centerofgravity_Value[0] -
      FaultModel_P.ThreeaxisInertialMeasurement_j5[0]) *
      FaultModel_P.Gain_Gain_mp[0];
    FaultModel_B.Gain[1] = (FaultModel_P.ZeroOrderHold4_Gain *
      FaultModel_P.centerofgravity_Value[1] -
      FaultModel_P.ThreeaxisInertialMeasurement_j5[1]) *
      FaultModel_P.Gain_Gain_mp[1];
    FaultModel_B.Gain[2] = (FaultModel_P.ZeroOrderHold4_Gain *
      FaultModel_P.centerofgravity_Value[2] -
      FaultModel_P.ThreeaxisInertialMeasurement_j5[2]) *
      FaultModel_P.Gain_Gain_mp[2];

    // Concatenate: '<S15>/Matrix Concatenation' incorporates:
    //   Constant: '<S185>/uavJ'
    //   Constant: '<S1>/Constant_dI//dt'
    //   Sum: '<S185>/Add6'

    for (qY_1 = 0; qY_1 < 3; qY_1++) {
      rtb_MatrixConcatenation[6 * qY_1] = FaultModel_P.ModelParam_uavJ[3 * qY_1]
        - rtb_uavlostJ[3 * qY_1];

      // Sum: '<S185>/Add6' incorporates:
      //   Concatenate: '<S15>/Matrix Concatenation'
      //   Constant: '<S185>/uavJ'

      r = 3 * qY_1 + 1;
      rtb_MatrixConcatenation[6 * qY_1 + 1] = FaultModel_P.ModelParam_uavJ[r] -
        rtb_uavlostJ[r];

      // Sum: '<S185>/Add6' incorporates:
      //   Concatenate: '<S15>/Matrix Concatenation'
      //   Constant: '<S185>/uavJ'

      r = 3 * qY_1 + 2;
      rtb_MatrixConcatenation[6 * qY_1 + 2] = FaultModel_P.ModelParam_uavJ[r] -
        rtb_uavlostJ[r];
    }

    for (qY_1 = 0; qY_1 < 3; qY_1++) {
      rtb_MatrixConcatenation[6 * qY_1 + 3] = FaultModel_P.Constant_dIdt_Value[3
        * qY_1];
      rtb_MatrixConcatenation[6 * qY_1 + 4] = FaultModel_P.Constant_dIdt_Value[3
        * qY_1 + 1];
      rtb_MatrixConcatenation[6 * qY_1 + 5] = FaultModel_P.Constant_dIdt_Value[3
        * qY_1 + 2];
    }

    // End of Concatenate: '<S15>/Matrix Concatenation'
    for (qY_1 = 0; qY_1 < 3; qY_1++) {
      // Selector: '<S14>/Selector1' incorporates:
      //   Concatenate: '<S15>/Matrix Concatenation'

      FaultModel_B.Selector1[3 * qY_1] = rtb_MatrixConcatenation[6 * qY_1 + 3];

      // Selector: '<S14>/Selector' incorporates:
      //   Concatenate: '<S15>/Matrix Concatenation'

      FaultModel_B.Selector[3 * qY_1] = rtb_MatrixConcatenation[6 * qY_1];

      // Selector: '<S14>/Selector1' incorporates:
      //   Selector: '<S14>/Selector'

      r = 3 * qY_1 + 1;

      // Selector: '<S14>/Selector1' incorporates:
      //   Concatenate: '<S15>/Matrix Concatenation'

      FaultModel_B.Selector1[r] = rtb_MatrixConcatenation[6 * qY_1 + 4];

      // Selector: '<S14>/Selector' incorporates:
      //   Concatenate: '<S15>/Matrix Concatenation'

      FaultModel_B.Selector[r] = rtb_MatrixConcatenation[6 * qY_1 + 1];

      // Selector: '<S14>/Selector1' incorporates:
      //   Selector: '<S14>/Selector'

      r = 3 * qY_1 + 2;

      // Selector: '<S14>/Selector1' incorporates:
      //   Concatenate: '<S15>/Matrix Concatenation'

      FaultModel_B.Selector1[r] = rtb_MatrixConcatenation[6 * qY_1 + 5];

      // Selector: '<S14>/Selector' incorporates:
      //   Concatenate: '<S15>/Matrix Concatenation'

      FaultModel_B.Selector[r] = rtb_MatrixConcatenation[6 * qY_1 + 2];
    }
  }

  // Product: '<S54>/j x i' incorporates:
  //   Product: '<S435>/j x i'

  rtb_jxi = Product1[1] * FaultModel_B.Gain[0];

  // Sum: '<S431>/Sum' incorporates:
  //   Product: '<S434>/i x j'
  //   Product: '<S434>/j x k'
  //   Product: '<S434>/k x i'
  //   Product: '<S435>/i x k'
  //   Product: '<S435>/k x j'

  rtb_wind_idx_0 = Product1[1] * FaultModel_B.Gain[2] - Product1[2] *
    FaultModel_B.Gain[1];
  rtb_LimitaltitudetoStratosphere = Product1[2] * FaultModel_B.Gain[0] -
    Product1[0] * FaultModel_B.Gain[2];
  uavlostJyz = Product1[0] * FaultModel_B.Gain[1] - rtb_jxi;

  // Product: '<S54>/j x i' incorporates:
  //   Product: '<S433>/j x i'

  rtb_jxi = Product1[1] * rtb_wind_idx_0;

  // Sum: '<S430>/Sum' incorporates:
  //   Product: '<S432>/i x j'
  //   Product: '<S432>/j x k'
  //   Product: '<S432>/k x i'
  //   Product: '<S433>/i x k'
  //   Product: '<S433>/k x j'

  uavlostJxy = Product1[2] * rtb_wind_idx_0;
  Z = Product1[0] * rtb_LimitaltitudetoStratosphere;
  rtb_wind_idx_0 = Product1[1] * uavlostJyz - Product1[2] *
    rtb_LimitaltitudetoStratosphere;
  rtb_LimitaltitudetoStratosphere = uavlostJxy - Product1[0] * uavlostJyz;
  uavlostJyz = Z - rtb_jxi;
  for (qY_1 = 0; qY_1 < 3; qY_1++) {
    // Product: '<S47>/Product' incorporates:
    //   Integrator: '<S12>/p,q,r '
    //   Selector: '<S14>/Selector'
    //   Sum: '<S423>/Sum4'

    rtb_sincos_o1[qY_1] = FaultModel_B.Selector[qY_1 + 6] *
      FaultModel_X.pqr_CSTATE[2] + (FaultModel_B.Selector[qY_1 + 3] *
      FaultModel_X.pqr_CSTATE[1] + FaultModel_B.Selector[qY_1] *
      FaultModel_X.pqr_CSTATE[0]);

    // Product: '<S48>/Product' incorporates:
    //   Integrator: '<S12>/p,q,r '
    //   Selector: '<S14>/Selector1'

    tmp[qY_1] = FaultModel_B.Selector1[qY_1 + 6] * FaultModel_X.pqr_CSTATE[2] +
      (FaultModel_B.Selector1[qY_1 + 3] * FaultModel_X.pqr_CSTATE[1] +
       FaultModel_B.Selector1[qY_1] * FaultModel_X.pqr_CSTATE[0]);
  }

  // Product: '<S54>/j x i' incorporates:
  //   Integrator: '<S12>/p,q,r '
  //   Product: '<S50>/j x i'

  rtb_jxi = FaultModel_X.pqr_CSTATE[1] * rtb_sincos_o1[0];

  // Sum: '<S14>/Sum2' incorporates:
  //   Constant: '<S7>/ModelParam.uavCCm'
  //   Constant: '<S7>/ModelParam.uavDearo'
  //   Integrator: '<S12>/p,q,r '
  //   MATLAB Function: '<S7>/Body AeroCenter'
  //   Product: '<S48>/Product'
  //   Product: '<S49>/i x j'
  //   Product: '<S49>/j x k'
  //   Product: '<S49>/k x i'
  //   Product: '<S50>/i x k'
  //   Product: '<S50>/k x j'
  //   Sum: '<S1>/Sum'
  //   Sum: '<S46>/Sum'
  //   Sum: '<S7>/Add3'

  Product1[0] = (((((-FaultModel_P.ModelParam_uavCCm[0] *
                     FaultModel_X.pqr_CSTATE[0] * std::abs
                     (FaultModel_X.pqr_CSTATE[0]) + uavlostJzx *
                     FaultModel_P.ModelParam_uavDearo) + (FaultModel_B.M1[0] +
    rtb_Mb_idx_0)) + FaultModel_B.deltaM[0]) + FaultModel_B.fm[3]) - tmp[0]) -
    (FaultModel_X.pqr_CSTATE[1] * rtb_sincos_o1[2] - FaultModel_X.pqr_CSTATE[2] *
     rtb_sincos_o1[1]);
  Product1[1] = (((((-FaultModel_P.ModelParam_uavCCm[1] *
                     FaultModel_X.pqr_CSTATE[1] * std::abs
                     (FaultModel_X.pqr_CSTATE[1]) + -rtb_Fd[0] *
                     FaultModel_P.ModelParam_uavDearo) + (FaultModel_B.M1[1] +
    rtb_Mb_idx_1)) + FaultModel_B.deltaM[1]) + FaultModel_B.fm[4]) - tmp[1]) -
    (FaultModel_X.pqr_CSTATE[2] * rtb_sincos_o1[0] - FaultModel_X.pqr_CSTATE[0] *
     rtb_sincos_o1[2]);
  Product1[2] = ((((-FaultModel_P.ModelParam_uavCCm[2] *
                    FaultModel_X.pqr_CSTATE[2] * std::abs
                    (FaultModel_X.pqr_CSTATE[2]) + (FaultModel_B.M1[2] +
    rtb_TmpSignalConversionAtSFun_1)) + FaultModel_B.deltaM[2]) +
                  FaultModel_B.fm[5]) - tmp[2]) - (FaultModel_X.pqr_CSTATE[0] *
    rtb_sincos_o1[1] - rtb_jxi);
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    for (qY_1 = 0; qY_1 < 3; qY_1++) {
      // Selector: '<S14>/Selector2' incorporates:
      //   Concatenate: '<S15>/Matrix Concatenation'

      FaultModel_B.Selector2[3 * qY_1] = rtb_MatrixConcatenation[6 * qY_1];
      FaultModel_B.Selector2[3 * qY_1 + 1] = rtb_MatrixConcatenation[6 * qY_1 +
        1];
      FaultModel_B.Selector2[3 * qY_1 + 2] = rtb_MatrixConcatenation[6 * qY_1 +
        2];
    }
  }

  // Product: '<S14>/Product2' incorporates:
  //   SecondOrderIntegrator: '<S440>/Integrator, Second-Order Limited'
  //   Selector: '<S14>/Selector2'

  rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(Product1, FaultModel_B.Selector2,
    FaultModel_B.Product2);

  // Gain: '<S423>/Zero-Order Hold3'
  rtb_sincos_o1[0] = FaultModel_P.ZeroOrderHold3_Gain * FaultModel_B.Product2[0];
  rtb_sincos_o1[1] = FaultModel_P.ZeroOrderHold3_Gain * FaultModel_B.Product2[1];
  rtb_sincos_o1[2] = FaultModel_P.ZeroOrderHold3_Gain * FaultModel_B.Product2[2];

  // Product: '<S54>/j x i' incorporates:
  //   Product: '<S437>/j x i'

  rtb_jxi = rtb_sincos_o1[1] * FaultModel_B.Gain[0];

  // Product: '<S400>/Matrix Multiply1' incorporates:
  //   Concatenate: '<S34>/Vector Concatenate'

  for (qY_1 = 0; qY_1 < 3; qY_1++) {
    Product1[qY_1] = VectorConcatenate[qY_1 + 6] *
      FaultModel_B.MatrixConcatenate[2] + (VectorConcatenate[qY_1 + 3] *
      FaultModel_B.MatrixConcatenate[1] + VectorConcatenate[qY_1] *
      FaultModel_B.MatrixConcatenate[0]);
  }

  // End of Product: '<S400>/Matrix Multiply1'

  // Sum: '<S423>/Sum' incorporates:
  //   Gain: '<S423>/Zero-Order Hold1'
  //   Gain: '<S423>/Zero-Order Hold2'
  //   Product: '<S436>/i x j'
  //   Product: '<S436>/j x k'
  //   Product: '<S436>/k x i'
  //   Product: '<S437>/i x k'
  //   Product: '<S437>/k x j'
  //   Sum: '<S427>/Sum'

  rtb_wind_idx_0 = ((FaultModel_P.ZeroOrderHold1_Gain * rtb_MatrixMultiply2[0] -
                     FaultModel_P.ZeroOrderHold2_Gain * Product1[0]) +
                    rtb_wind_idx_0) + (rtb_sincos_o1[1] * FaultModel_B.Gain[2] -
    rtb_sincos_o1[2] * FaultModel_B.Gain[1]);
  rtb_LimitaltitudetoStratosphere = ((FaultModel_P.ZeroOrderHold1_Gain *
    rtb_MatrixMultiply2[1] - FaultModel_P.ZeroOrderHold2_Gain * Product1[1]) +
    rtb_LimitaltitudetoStratosphere) + (rtb_sincos_o1[2] * FaultModel_B.Gain[0]
    - rtb_sincos_o1[0] * FaultModel_B.Gain[2]);
  uavlostJyz = ((FaultModel_P.ZeroOrderHold1_Gain * rtb_MatrixMultiply2[2] -
                 FaultModel_P.ZeroOrderHold2_Gain * Product1[2]) + uavlostJyz) +
    (rtb_sincos_o1[0] * FaultModel_B.Gain[1] - rtb_jxi);

  // Sum: '<S423>/Sum4' incorporates:
  //   Constant: '<S423>/Measurement bias'
  //   Constant: '<S423>/Scale factors & Cross-coupling  errors'
  //   Product: '<S423>/Product'

  for (qY_1 = 0; qY_1 < 3; qY_1++) {
    rtb_sincos_o1[qY_1] = ((FaultModel_P.ThreeaxisInertialMeasurementU_o[qY_1 +
      3] * rtb_LimitaltitudetoStratosphere +
      FaultModel_P.ThreeaxisInertialMeasurementU_o[qY_1] * rtb_wind_idx_0) +
      FaultModel_P.ThreeaxisInertialMeasurementU_o[qY_1 + 6] * uavlostJyz) +
      FaultModel_P.ThreeaxisInertialMeasurementUni[qY_1];
  }

  // End of Sum: '<S423>/Sum4'

  // Switch: '<S425>/Switch' incorporates:
  //   Constant: '<S425>/Constant'
  //   SecondOrderIntegrator: '<S429>/Integrator, Second-Order Limited'

  if (FaultModel_P.Constant_Value_pl >= FaultModel_P.Switch_Threshold_g) {
    rtb_TmpSignalConversionAtSFun_1 =
      FaultModel_X.IntegratorSecondOrderLimited_CS[0];
  } else {
    rtb_TmpSignalConversionAtSFun_1 = rtb_sincos_o1[0];
  }

  // Saturate: '<S423>/Saturation'
  if (rtb_TmpSignalConversionAtSFun_1 > FaultModel_P.Saturation_UpperSat[0]) {
    rtb_Mb_idx_0 = FaultModel_P.Saturation_UpperSat[0];
  } else if (rtb_TmpSignalConversionAtSFun_1 < FaultModel_P.Saturation_LowerSat
             [0]) {
    rtb_Mb_idx_0 = FaultModel_P.Saturation_LowerSat[0];
  } else {
    rtb_Mb_idx_0 = rtb_TmpSignalConversionAtSFun_1;
  }

  // Switch: '<S425>/Switch' incorporates:
  //   Constant: '<S425>/Constant'
  //   SecondOrderIntegrator: '<S429>/Integrator, Second-Order Limited'

  if (FaultModel_P.Constant_Value_pl >= FaultModel_P.Switch_Threshold_g) {
    rtb_TmpSignalConversionAtSFun_1 =
      FaultModel_X.IntegratorSecondOrderLimited_CS[1];
  } else {
    rtb_TmpSignalConversionAtSFun_1 = rtb_sincos_o1[1];
  }

  // Saturate: '<S423>/Saturation'
  if (rtb_TmpSignalConversionAtSFun_1 > FaultModel_P.Saturation_UpperSat[1]) {
    rtb_Mb_idx_1 = FaultModel_P.Saturation_UpperSat[1];
  } else if (rtb_TmpSignalConversionAtSFun_1 < FaultModel_P.Saturation_LowerSat
             [1]) {
    rtb_Mb_idx_1 = FaultModel_P.Saturation_LowerSat[1];
  } else {
    rtb_Mb_idx_1 = rtb_TmpSignalConversionAtSFun_1;
  }

  // Switch: '<S425>/Switch' incorporates:
  //   Constant: '<S425>/Constant'
  //   SecondOrderIntegrator: '<S429>/Integrator, Second-Order Limited'

  if (FaultModel_P.Constant_Value_pl >= FaultModel_P.Switch_Threshold_g) {
    rtb_TmpSignalConversionAtSFun_1 =
      FaultModel_X.IntegratorSecondOrderLimited_CS[2];
  } else {
    rtb_TmpSignalConversionAtSFun_1 = rtb_sincos_o1[2];
  }

  // Saturate: '<S423>/Saturation'
  if (rtb_TmpSignalConversionAtSFun_1 > FaultModel_P.Saturation_UpperSat[2]) {
    rtb_TmpSignalConversionAtSFun_1 = FaultModel_P.Saturation_UpperSat[2];
  } else {
    if (rtb_TmpSignalConversionAtSFun_1 < FaultModel_P.Saturation_LowerSat[2]) {
      rtb_TmpSignalConversionAtSFun_1 = FaultModel_P.Saturation_LowerSat[2];
    }
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[2] == 0) {
    // Gain: '<S400>/Gain10' incorporates:
    //   UniformRandomNumber: '<S400>/Uniform Random Number5'

    FaultModel_B.Gain10[0] = FaultModel_P.Gain10_Gain *
      FaultModel_DW.UniformRandomNumber5_NextOutput[0];
    FaultModel_B.Gain10[1] = FaultModel_P.Gain10_Gain *
      FaultModel_DW.UniformRandomNumber5_NextOutput[1];
    FaultModel_B.Gain10[2] = FaultModel_P.Gain10_Gain *
      FaultModel_DW.UniformRandomNumber5_NextOutput[2];
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // MATLAB Function: '<S400>/FaultParamsExtract' incorporates:
    //   Constant: '<S400>/FaultID'
    //   Inport: '<Root>/inSILInts'

    // MATLAB Function 'OutputPort1/HILSensorMavModel1/Subsystem/FaultParamsExtract': '<S404>:1' 
    // '<S404>:1:5' if isempty(hFault)
    // '<S404>:1:8' if isempty(fParam)
    // '<S404>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S404>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S404>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S404>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S404>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID_Value_h) {
        // '<S404>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S404>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        b_t = (r + 1) << 1;
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[b_t - 2];

        // '<S404>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] =
          inSILFloats[b_t - 1];

        // '<S404>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S404>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S404>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_h = true;

      // '<S404>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S404>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_k[0], &fParamTmp[0], 20U * sizeof(real_T));
    }

    // '<S404>:1:29' hasFault_acc=hFault;
    // '<S404>:1:30' FaultParam=fParam;
    std::memcpy(&rtb_FaultParam_e5[0], &FaultModel_DW.fParam_k[0], 20U * sizeof
                (real_T));

    // MATLAB Function: '<S401>/Acc Fun' incorporates:
    //   MATLAB Function: '<S400>/FaultParamsExtract'

    FaultModel_AccFun(FaultModel_B.Gain10, FaultModel_DW.hFault_h,
                      rtb_FaultParam_e5, &FaultModel_B.sf_AccFun);
  }

  // UnitConversion: '<S422>/Unit Conversion'
  // Unit Conversion - from: m/s^2 to: gn
  // Expression: output = (0.101972*input) + (0)
  rtb_MatrixMultiply2[0] *= 0.10197162129779282;
  rtb_MatrixMultiply2[1] *= 0.10197162129779282;
  rtb_MatrixMultiply2[2] *= 0.10197162129779282;

  // Sum: '<S424>/Sum4' incorporates:
  //   Constant: '<S424>/Measurement bias'
  //   Constant: '<S424>/Scale factors & Cross-coupling  errors '
  //   Constant: '<S424>/g-sensitive bias'
  //   Gain: '<S424>/Zero-Order Hold'
  //   Gain: '<S424>/Zero-Order Hold1'
  //   Integrator: '<S12>/p,q,r '
  //   Product: '<S424>/Product'
  //   Product: '<S424>/Product1'

  for (qY_1 = 0; qY_1 < 3; qY_1++) {
    rtb_Fd[qY_1] = (((FaultModel_P.ZeroOrderHold_Gain_k *
                      FaultModel_X.pqr_CSTATE[0] *
                      FaultModel_P.ThreeaxisInertialMeasurementU_j[qY_1] +
                      FaultModel_P.ThreeaxisInertialMeasurementU_j[qY_1 + 3] *
                      (FaultModel_P.ZeroOrderHold_Gain_k *
                       FaultModel_X.pqr_CSTATE[1])) +
                     FaultModel_P.ThreeaxisInertialMeasurementU_j[qY_1 + 6] *
                     (FaultModel_P.ZeroOrderHold_Gain_k *
                      FaultModel_X.pqr_CSTATE[2])) +
                    FaultModel_P.ThreeaxisInertialMeasurementU_i[qY_1]) +
      FaultModel_P.ZeroOrderHold1_Gain_n * rtb_MatrixMultiply2[qY_1] *
      FaultModel_P.ThreeaxisInertialMeasurementU_f[qY_1];
  }

  // End of Sum: '<S424>/Sum4'
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[2] == 0) {
    // Gain: '<S400>/Gain6' incorporates:
    //   UniformRandomNumber: '<S400>/Uniform Random Number1'

    FaultModel_B.Gain6[0] = FaultModel_P.Gain6_Gain *
      FaultModel_DW.UniformRandomNumber1_NextOutput[0];
    FaultModel_B.Gain6[1] = FaultModel_P.Gain6_Gain *
      FaultModel_DW.UniformRandomNumber1_NextOutput[1];
    FaultModel_B.Gain6[2] = FaultModel_P.Gain6_Gain *
      FaultModel_DW.UniformRandomNumber1_NextOutput[2];
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // MATLAB Function: '<S400>/FaultParamsExtract1' incorporates:
    //   Constant: '<S400>/FaultID1'
    //   Inport: '<Root>/inSILInts'

    // MATLAB Function 'OutputPort1/HILSensorMavModel1/Subsystem/FaultParamsExtract1': '<S405>:1' 
    // '<S405>:1:5' if isempty(hFault)
    // '<S405>:1:8' if isempty(fParam)
    // '<S405>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S405>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S405>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S405>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S405>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID1_Value_d) {
        // '<S405>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S405>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S405>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S405>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S405>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S405>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_b = true;

      // '<S405>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S405>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_m[0], &fParamTmp[0], 20U * sizeof(real_T));
    }

    // '<S405>:1:29' hasFault_gyro=hFault;
    // '<S405>:1:30' FaultParam=fParam;
    std::memcpy(&rtb_FaultParam_e5[0], &FaultModel_DW.fParam_m[0], 20U * sizeof
                (real_T));

    // MATLAB Function: '<S409>/Gyro Fun' incorporates:
    //   MATLAB Function: '<S400>/FaultParamsExtract1'

    FaultModel_AccFun(FaultModel_B.Gain6, FaultModel_DW.hFault_b,
                      rtb_FaultParam_e5, &FaultModel_B.sf_GyroFun);
  }

  // Switch: '<S438>/Switch' incorporates:
  //   Constant: '<S438>/Constant'
  //   SecondOrderIntegrator: '<S440>/Integrator, Second-Order Limited'

  if (FaultModel_P.Constant_Value_h >= FaultModel_P.Switch_Threshold_p) {
    rtb_wind_idx_0 = FaultModel_X.IntegratorSecondOrderLimited__b[0];
  } else {
    rtb_wind_idx_0 = rtb_Fd[0];
  }

  // Saturate: '<S424>/Saturation'
  if (rtb_wind_idx_0 > FaultModel_P.Saturation_UpperSat_f[0]) {
    y = FaultModel_P.Saturation_UpperSat_f[0];
  } else if (rtb_wind_idx_0 < FaultModel_P.Saturation_LowerSat_d[0]) {
    y = FaultModel_P.Saturation_LowerSat_d[0];
  } else {
    y = rtb_wind_idx_0;
  }

  // Switch: '<S438>/Switch' incorporates:
  //   Constant: '<S438>/Constant'
  //   SecondOrderIntegrator: '<S440>/Integrator, Second-Order Limited'

  if (FaultModel_P.Constant_Value_h >= FaultModel_P.Switch_Threshold_p) {
    rtb_wind_idx_0 = FaultModel_X.IntegratorSecondOrderLimited__b[1];
  } else {
    rtb_wind_idx_0 = rtb_Fd[1];
  }

  // Saturate: '<S424>/Saturation'
  if (rtb_wind_idx_0 > FaultModel_P.Saturation_UpperSat_f[1]) {
    y_0 = FaultModel_P.Saturation_UpperSat_f[1];
  } else if (rtb_wind_idx_0 < FaultModel_P.Saturation_LowerSat_d[1]) {
    y_0 = FaultModel_P.Saturation_LowerSat_d[1];
  } else {
    y_0 = rtb_wind_idx_0;
  }

  // Switch: '<S438>/Switch' incorporates:
  //   Constant: '<S438>/Constant'
  //   SecondOrderIntegrator: '<S440>/Integrator, Second-Order Limited'

  if (FaultModel_P.Constant_Value_h >= FaultModel_P.Switch_Threshold_p) {
    rtb_wind_idx_0 = FaultModel_X.IntegratorSecondOrderLimited__b[2];
  } else {
    rtb_wind_idx_0 = rtb_Fd[2];
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Sum: '<S450>/Sum' incorporates:
    //   Constant: '<S416>/Decimal Year'
    //   Constant: '<S450>/epoch'

    rtb_Sum_os = FaultModel_P.DecimalYear_Value - FaultModel_P.epoch_Value;

    // RelationalOperator: '<S464>/Relational Operator' incorporates:
    //   Constant: '<S416>/Decimal Year'
    //   Memory: '<S464>/otime'

    rtb_RelationalOperator = (FaultModel_P.DecimalYear_Value !=
      FaultModel_DW.otime_PreviousInput);
  }

  // Switch: '<S455>/Switch' incorporates:
  //   Abs: '<S455>/Abs'
  //   Bias: '<S455>/Bias'
  //   Bias: '<S455>/Bias1'
  //   Constant: '<S455>/Constant2'
  //   Constant: '<S456>/Constant'
  //   Math: '<S455>/Math Function1'
  //   RelationalOperator: '<S456>/Compare'

  if (std::abs(rtb_uavlostMass) > FaultModel_P.CompareToConstant_const_k) {
    uavlostJyz = rt_modd_snf(rtb_uavlostMass + FaultModel_P.Bias_Bias_pe,
      FaultModel_P.Constant2_Value_o1) + FaultModel_P.Bias1_Bias_p;
  } else {
    uavlostJyz = rtb_uavlostMass;
  }

  // End of Switch: '<S455>/Switch'

  // Abs: '<S452>/Abs1'
  uavlostJzx = std::abs(uavlostJyz);

  // RelationalOperator: '<S454>/Compare' incorporates:
  //   Constant: '<S454>/Constant'

  hFaultTmp = (uavlostJzx > FaultModel_P.CompareToConstant_const_p);

  // Switch: '<S446>/Switch1' incorporates:
  //   Constant: '<S446>/Constant'
  //   Constant: '<S446>/Constant1'

  if (hFaultTmp) {
    rtb_jxi = FaultModel_P.Constant_Value_bc;
  } else {
    rtb_jxi = FaultModel_P.Constant1_Value_h;
  }

  // End of Switch: '<S446>/Switch1'

  // Sum: '<S446>/Sum'
  uavlostJxy = rtb_jxi + rtb_TmpSignalConversionAtSFun_2;

  // Switch: '<S453>/Switch' incorporates:
  //   Abs: '<S453>/Abs'
  //   Constant: '<S457>/Constant'
  //   RelationalOperator: '<S457>/Compare'

  if (std::abs(uavlostJxy) > FaultModel_P.CompareToConstant_const_o) {
    // Switch: '<S453>/Switch' incorporates:
    //   Bias: '<S453>/Bias'
    //   Bias: '<S453>/Bias1'
    //   Constant: '<S453>/Constant2'
    //   Math: '<S453>/Math Function1'

    FaultModel_B.Switch_f = rt_modd_snf(uavlostJxy + FaultModel_P.Bias_Bias_c,
      FaultModel_P.Constant2_Value_h) + FaultModel_P.Bias1_Bias_a;
  } else {
    // Switch: '<S453>/Switch'
    FaultModel_B.Switch_f = uavlostJxy;
  }

  // End of Switch: '<S453>/Switch'

  // Switch: '<S452>/Switch'
  if (hFaultTmp) {
    // Signum: '<S452>/Sign1'
    if (uavlostJyz < 0.0) {
      uavlostJyz = -1.0;
    } else if (uavlostJyz > 0.0) {
      uavlostJyz = 1.0;
    } else if (uavlostJyz == 0.0) {
      uavlostJyz = 0.0;
    } else {
      uavlostJyz = (rtNaN);
    }

    // End of Signum: '<S452>/Sign1'

    // Switch: '<S452>/Switch' incorporates:
    //   Bias: '<S452>/Bias'
    //   Bias: '<S452>/Bias1'
    //   Gain: '<S452>/Gain'
    //   Product: '<S452>/Divide1'

    FaultModel_B.Switch_e = ((uavlostJzx + FaultModel_P.Bias_Bias_k) *
      FaultModel_P.Gain_Gain_k + FaultModel_P.Bias1_Bias_i) * uavlostJyz;
  } else {
    // Switch: '<S452>/Switch'
    FaultModel_B.Switch_e = uavlostJyz;
  }

  // End of Switch: '<S452>/Switch'

  // UnitConversion: '<S508>/Unit Conversion'
  // Unit Conversion - from: deg to: rad
  // Expression: output = (0.0174533*input) + (0)
  rtb_Product2_l = 0.017453292519943295 * FaultModel_B.Switch_f;
  rtb_sincos_o1_p_idx_1 = 0.017453292519943295 * FaultModel_B.Switch_e;

  // Trigonometry: '<S461>/sincos'
  FaultModel_B.sincos_o1[0] = std::sin(rtb_Product2_l);
  FaultModel_B.sincos_o2[0] = std::cos(rtb_Product2_l);
  FaultModel_B.sincos_o1[1] = std::sin(rtb_sincos_o1_p_idx_1);
  FaultModel_B.sincos_o2[1] = std::cos(rtb_sincos_o1_p_idx_1);
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Outputs for Enabled SubSystem: '<S450>/Convert from geodetic to  spherical coordinates ' incorporates:
    //   EnablePort: '<S460>/Enable'

    if (rtmIsMajorTimeStep((&FaultModel_M))) {
      // RelationalOperator: '<S463>/Relational Operator' incorporates:
      //   Memory: '<S463>/olon'

      FaultModel_DW.Convertfromgeodetictosphericalc = (FaultModel_B.Switch_f !=
        FaultModel_DW.olon_PreviousInput);
    }

    // End of Outputs for SubSystem: '<S450>/Convert from geodetic to  spherical coordinates ' 

    // Memory: '<S462>/olat'
    FaultModel_B.olat = FaultModel_DW.olat_PreviousInput;
  }

  // Outputs for Enabled SubSystem: '<S450>/Convert from geodetic to  spherical coordinates ' incorporates:
  //   EnablePort: '<S460>/Enable'

  if (FaultModel_DW.Convertfromgeodetictosphericalc) {
    // Inport: '<S460>/sp[2]'
    uavlostJyz = FaultModel_B.sincos_o1[0];

    // Inport: '<S460>/cp[2]'
    uavlostJzx = FaultModel_B.sincos_o2[0];
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
      // Outputs for Iterator SubSystem: '<S460>/For Iterator Subsystem' incorporates:
      //   ForIterator: '<S507>/For Iterator'

      for (r = 1; r <= FaultModel_P.ForIterator_IterationLimit; r++) {
        // Switch: '<S507>/cp[m-1] sp[m-1]' incorporates:
        //   UnitDelay: '<S507>/Unit Delay1'

        if (r > FaultModel_P.cpm1spm1_Threshold) {
          rtb_Product2_l = FaultModel_DW.UnitDelay1_DSTATE[0];
          rtb_sincos_o1_p_idx_1 = FaultModel_DW.UnitDelay1_DSTATE[1];
        } else {
          rtb_Product2_l = uavlostJzx;
          rtb_sincos_o1_p_idx_1 = uavlostJyz;
        }

        // End of Switch: '<S507>/cp[m-1] sp[m-1]'

        // Sum: '<S507>/Sum2' incorporates:
        //   Product: '<S507>/Product1'
        //   Product: '<S507>/Product2'

        uavlostJxy = rtb_Product2_l * uavlostJyz + rtb_sincos_o1_p_idx_1 *
          uavlostJzx;

        // Assignment: '<S507>/Assignment' incorporates:
        //   Constant: '<S507>/Constant'

        if (r == 1) {
          std::memcpy(&rtb_Assignment[0], &FaultModel_P.Constant_Value_n[0], 11U
                      * sizeof(real_T));
        }

        rtb_Assignment[r - 1] = uavlostJxy;

        // End of Assignment: '<S507>/Assignment'

        // Sum: '<S507>/Sum1' incorporates:
        //   Product: '<S507>/Product3'
        //   Product: '<S507>/Product8'

        rtb_LimitaltitudetoStratosphere = rtb_Product2_l * uavlostJzx -
          rtb_sincos_o1_p_idx_1 * uavlostJyz;

        // Assignment: '<S507>/Assignment1' incorporates:
        //   Constant: '<S507>/Constant1'

        if (r == 1) {
          std::memcpy(&rtb_Assignment1[0], &FaultModel_P.Constant1_Value_mc[0],
                      11U * sizeof(real_T));
        }

        rtb_Assignment1[r - 1] = rtb_LimitaltitudetoStratosphere;

        // End of Assignment: '<S507>/Assignment1'

        // Update for UnitDelay: '<S507>/Unit Delay1'
        FaultModel_DW.UnitDelay1_DSTATE[0] = rtb_LimitaltitudetoStratosphere;
        FaultModel_DW.UnitDelay1_DSTATE[1] = uavlostJxy;
      }

      // End of Outputs for SubSystem: '<S460>/For Iterator Subsystem'
      for (i = 0; i < 11; i++) {
        // Gain: '<S460>/Gain'
        FaultModel_B.Gain_b[i] = FaultModel_P.Gain_Gain_h * rtb_Assignment1[i];
      }

      for (i = 0; i < 11; i++) {
        // Gain: '<S460>/Gain1'
        FaultModel_B.Gain1[i] = FaultModel_P.Gain1_Gain_k * rtb_Assignment[i];
      }
    }

    // SignalConversion generated from: '<S460>/cp[13]' incorporates:
    //   Constant: '<S460>/cp[1]'
    //   Inport: '<S460>/cp[2]'

    FaultModel_B.OutportBufferForcp13[0] = FaultModel_P.cp1_Value;
    FaultModel_B.OutportBufferForcp13[1] = FaultModel_B.sincos_o2[0];
    std::memcpy(&FaultModel_B.OutportBufferForcp13[2], &FaultModel_B.Gain_b[0],
                11U * sizeof(real_T));

    // SignalConversion generated from: '<S460>/sp[13]' incorporates:
    //   Constant: '<S460>/sp[1]'
    //   Inport: '<S460>/sp[2]'

    FaultModel_B.OutportBufferForsp13[0] = FaultModel_P.sp1_Value;
    FaultModel_B.OutportBufferForsp13[1] = FaultModel_B.sincos_o1[0];
    std::memcpy(&FaultModel_B.OutportBufferForsp13[2], &FaultModel_B.Gain1[0],
                11U * sizeof(real_T));
  }

  // End of Outputs for SubSystem: '<S450>/Convert from geodetic to  spherical coordinates ' 

  // Gain: '<S416>/Gain'
  FaultModel_B.Gain_o = FaultModel_P.Gain_Gain_j * rtb_Saturation_1;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Memory: '<S462>/oalt'
    FaultModel_B.oalt = FaultModel_DW.oalt_PreviousInput;
  }

  // Logic: '<S462>/Logical Operator' incorporates:
  //   RelationalOperator: '<S462>/Relational Operator'
  //   RelationalOperator: '<S462>/Relational Operator1'

  rtb_hasFault_j = ((FaultModel_B.Switch_e != FaultModel_B.olat) ||
                    (FaultModel_B.Gain_o != FaultModel_B.oalt));

  // Product: '<S461>/Product'
  Y = FaultModel_B.sincos_o1[1] * FaultModel_B.sincos_o1[1];

  // Product: '<S461>/Product1'
  Z = FaultModel_B.sincos_o2[1] * FaultModel_B.sincos_o2[1];
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Outputs for Enabled SubSystem: '<S450>/Convert from geodetic to  spherical coordinates' incorporates:
    //   EnablePort: '<S459>/Enable'

    if (rtmIsMajorTimeStep((&FaultModel_M))) {
      // SignalConversion generated from: '<S459>/Enable'
      FaultModel_DW.Convertfromgeodetictospherica_d = rtb_hasFault_j;
    }

    // End of Outputs for SubSystem: '<S450>/Convert from geodetic to  spherical coordinates' 
  }

  // Outputs for Enabled SubSystem: '<S450>/Convert from geodetic to  spherical coordinates' incorporates:
  //   EnablePort: '<S459>/Enable'

  if (FaultModel_DW.Convertfromgeodetictospherica_d) {
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
      // Product: '<S459>/b2' incorporates:
      //   Constant: '<S459>/b'

      FaultModel_B.b2 = FaultModel_P.b_Value * FaultModel_P.b_Value;

      // Product: '<S459>/a2' incorporates:
      //   Constant: '<S459>/a'

      FaultModel_B.a2 = FaultModel_P.a_Value * FaultModel_P.a_Value;

      // Sum: '<S502>/Sum1'
      FaultModel_B.c2 = FaultModel_B.a2 - FaultModel_B.b2;
    }

    // Sqrt: '<S502>/sqrt' incorporates:
    //   Product: '<S502>/Product'
    //   Sum: '<S502>/Sum'

    uavlostJzx = std::sqrt(FaultModel_B.a2 - Y * FaultModel_B.c2);

    // Product: '<S459>/Product1'
    uavlostJxy = uavlostJzx * FaultModel_B.Gain_o;

    // Sqrt: '<S501>/sqrt' incorporates:
    //   Product: '<S501>/Product10'
    //   Product: '<S501>/Product9'
    //   Sum: '<S501>/Sum7'

    uavlostJyz = std::sqrt(Z * FaultModel_B.a2 + FaultModel_B.b2 * Y);
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
      // Product: '<S504>/a4'
      FaultModel_B.a4 = FaultModel_B.a2 * FaultModel_B.a2;

      // Sum: '<S504>/Sum9' incorporates:
      //   Product: '<S504>/b4'

      FaultModel_B.c4 = FaultModel_B.a4 - FaultModel_B.b2 * FaultModel_B.b2;
    }

    // Sqrt: '<S459>/sqrt' incorporates:
    //   Gain: '<S504>/Gain'
    //   Product: '<S504>/Product1'
    //   Product: '<S504>/Product6'
    //   Product: '<S504>/Product7'
    //   Product: '<S504>/Product8'
    //   Sum: '<S504>/Sum5'
    //   Sum: '<S504>/Sum6'

    FaultModel_B.sqrt_c = std::sqrt((FaultModel_B.a4 - FaultModel_B.c4 * Y) /
      (uavlostJzx * uavlostJzx) + (FaultModel_P.Gain_Gain_p * uavlostJxy +
      FaultModel_B.Gain_o * FaultModel_B.Gain_o));

    // Product: '<S499>/Product11' incorporates:
    //   Sum: '<S499>/Sum8'

    FaultModel_B.Product11 = (FaultModel_B.Gain_o + uavlostJyz) /
      FaultModel_B.sqrt_c;

    // Sum: '<S503>/Sum2'
    uavlostJzx = FaultModel_B.a2 + uavlostJxy;

    // Sum: '<S503>/Sum1'
    uavlostJxy += FaultModel_B.b2;

    // Product: '<S500>/Product4' incorporates:
    //   Product: '<S500>/Product3'
    //   Product: '<S503>/Product1'
    //   Product: '<S503>/Product2'
    //   Sqrt: '<S500>/sqrt'
    //   Sum: '<S500>/Sum3'

    FaultModel_B.Product4_d = FaultModel_B.sincos_o1[1] / std::sqrt(uavlostJzx *
      uavlostJzx / (uavlostJxy * uavlostJxy) * Z + Y);

    // Product: '<S505>/Product1'
    uavlostJyz *= FaultModel_B.sqrt_c;
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
      // Sum: '<S505>/Sum1'
      FaultModel_B.c2_e = FaultModel_B.a2 - FaultModel_B.b2;
    }

    // Product: '<S505>/Product12'
    FaultModel_B.Product12 = FaultModel_B.c2_e / uavlostJyz *
      FaultModel_B.sincos_o2[1] * FaultModel_B.sincos_o1[1];

    // Sqrt: '<S506>/sqrt' incorporates:
    //   Constant: '<S506>/Constant'
    //   Product: '<S506>/Product5'
    //   Sum: '<S506>/Sum4'

    FaultModel_B.sqrt_m = std::sqrt(FaultModel_P.Constant_Value_ou -
      FaultModel_B.Product4_d * FaultModel_B.Product4_d);
  }

  // End of Outputs for SubSystem: '<S450>/Convert from geodetic to  spherical coordinates' 

  // Product: '<S450>/aor' incorporates:
  //   Constant: '<S450>/re'

  Z = FaultModel_P.re_Value / FaultModel_B.sqrt_c;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Outputs for Iterator SubSystem: '<S450>/Compute magnetic vector in spherical coordinates' incorporates:
    //   ForIterator: '<S458>/For Iterator'

    // InitializeConditions for UnitDelay: '<S458>/Unit Delay'
    Y = FaultModel_P.UnitDelay_InitialCondition_j;

    // InitializeConditions for UnitDelay: '<S458>/Unit Delay2'
    tz_idx_0 = FaultModel_P.UnitDelay2_InitialCondition_h[0];
    tz_idx_1 = FaultModel_P.UnitDelay2_InitialCondition_h[1];
    tz_idx_2 = FaultModel_P.UnitDelay2_InitialCondition_h[2];
    tz_idx_3 = FaultModel_P.UnitDelay2_InitialCondition_h[3];
    for (r = 1; r <= FaultModel_P.ForIterator_IterationLimit_n; r++) {
      // Switch: '<S458>/ar(n)' incorporates:
      //   Product: '<S450>/ar'

      if (r <= FaultModel_P.arn_Threshold) {
        Y = Z * Z;
      }

      // End of Switch: '<S458>/ar(n)'

      // Product: '<S458>/Product8'
      uavlostJyz = Y * Z;

      // Sum: '<S458>/Sum' incorporates:
      //   Constant: '<S458>/Constant'

      if ((r < 0) && (FaultModel_P.Constant_Value_o2 < MIN_int32_T - r)) {
        b_t = MIN_int32_T;
      } else if ((r > 0) && (FaultModel_P.Constant_Value_o2 > MAX_int32_T - r))
      {
        b_t = MAX_int32_T;
      } else {
        b_t = r + FaultModel_P.Constant_Value_o2;
      }

      // Outputs for Iterator SubSystem: '<S458>/For Iterator Subsystem' incorporates:
      //   ForIterator: '<S466>/For Iterator'

      // InitializeConditions for UnitDelay: '<S467>/Unit Delay1'
      uavlostJzx = FaultModel_P.UnitDelay1_InitialCondition_m;

      // InitializeConditions for UnitDelay: '<S467>/Unit Delay3'
      uavlostJxy = FaultModel_P.UnitDelay3_InitialCondition;

      // InitializeConditions for UnitDelay: '<S467>/Unit Delay2'
      rtb_LimitaltitudetoStratosphere = FaultModel_P.UnitDelay2_InitialCondition;

      // InitializeConditions for UnitDelay: '<S467>/Unit Delay4'
      rtb_jxi = FaultModel_P.UnitDelay4_InitialCondition;
      for (i = 0; i < 6; i++) {
        ForIterator_IterationMarker[i] = 1U;
      }

      // Sum: '<S458>/Sum'
      if (b_t > 2147483646) {
        b_t = 2147483646;
      } else {
        if (b_t < 0) {
          b_t = 0;
        }
      }

      if (1 <= b_t) {
        // Sum: '<S467>/Sum' incorporates:
        //   Constant: '<S467>/Constant'

        if ((r < 0) && (FaultModel_P.Constant_Value_h1y < MIN_int32_T - r)) {
          r_0 = MIN_int32_T;
        } else if ((r > 0) && (FaultModel_P.Constant_Value_h1y > MAX_int32_T - r))
        {
          r_0 = MAX_int32_T;
        } else {
          r_0 = r + FaultModel_P.Constant_Value_h1y;
        }

        // Selector: '<S467>/snorm[n+m*13]' incorporates:
        //   Constant: '<S471>/Constant'
        //   Sum: '<S471>/Sum1'

        if ((FaultModel_P.Constant_Value_aoh < 0) && (r < MIN_int32_T
             - FaultModel_P.Constant_Value_aoh)) {
          qY = MIN_int32_T;
        } else if ((FaultModel_P.Constant_Value_aoh > 0) && (r > MAX_int32_T
                    - FaultModel_P.Constant_Value_aoh)) {
          qY = MAX_int32_T;
        } else {
          qY = FaultModel_P.Constant_Value_aoh + r;
        }

        // Sum: '<S467>/Sum4' incorporates:
        //   Constant: '<S467>/Constant1'

        if ((r < 0) && (FaultModel_P.Constant1_Value_jl < MIN_int32_T - r)) {
          r_1 = MIN_int32_T;
        } else if ((r > 0) && (FaultModel_P.Constant1_Value_jl > MAX_int32_T - r))
        {
          r_1 = MAX_int32_T;
        } else {
          r_1 = r + FaultModel_P.Constant1_Value_jl;
        }
      }

      for (rtb_alt = 1; rtb_alt <= b_t; rtb_alt++) {
        // Sum: '<S466>/Sum1' incorporates:
        //   Constant: '<S466>/Constant'

        if (FaultModel_P.Constant_Value_m < rtb_alt - MAX_int32_T) {
          qY_2 = MAX_int32_T;
        } else {
          qY_2 = rtb_alt - FaultModel_P.Constant_Value_m;
        }

        // Outputs for Enabled SubSystem: '<S466>/Time adjust the gauss coefficients' incorporates:
        //   EnablePort: '<S469>/Enable'

        if (rtb_RelationalOperator) {
          // Outputs for Atomic SubSystem: '<S469>/If Action Subsystem'
          // Sum: '<S495>/Sum1' incorporates:
          //   Constant: '<S495>/Constant1'
          //   Sum: '<S466>/Sum1'

          if ((qY_2 < 0) && (FaultModel_P.Constant1_Value_p < MIN_int32_T - qY_2))
          {
            i = MIN_int32_T;
          } else if ((qY_2 > 0) && (FaultModel_P.Constant1_Value_p > MAX_int32_T
                      - qY_2)) {
            i = MAX_int32_T;
          } else {
            i = qY_2 + FaultModel_P.Constant1_Value_p;
          }

          // Sum: '<S495>/Sum2' incorporates:
          //   Constant: '<S495>/Constant'

          if ((r < 0) && (FaultModel_P.Constant_Value_h3 < MIN_int32_T - r)) {
            qY_1 = MIN_int32_T;
          } else if ((r > 0) && (FaultModel_P.Constant_Value_h3 > MAX_int32_T
                                 - r)) {
            qY_1 = MAX_int32_T;
          } else {
            qY_1 = r + FaultModel_P.Constant_Value_h3;
          }

          // End of Outputs for SubSystem: '<S469>/If Action Subsystem'

          // Assignment: '<S469>/Assignment'
          if (ForIterator_IterationMarker[4] < 2) {
            ForIterator_IterationMarker[4] = 2U;

            // Assignment: '<S469>/Assignment' incorporates:
            //   UnitDelay: '<S469>/Unit Delay'

            std::memcpy(&FaultModel_B.Assignment[0],
                        &FaultModel_DW.UnitDelay_DSTATE_d[0], 169U * sizeof
                        (real_T));
          }

          // Outputs for Atomic SubSystem: '<S469>/If Action Subsystem'
          // Selector: '<S495>/cd[m][n]' incorporates:
          //   Assignment: '<S469>/Assignment'
          //   Constant: '<S469>/c[maxdef][maxdef]'
          //   Constant: '<S469>/cd[maxdef][maxdef]'
          //   Selector: '<S495>/c[m][n]'
          //   Sum: '<S495>/Sum1'
          //   Sum: '<S495>/Sum2'

          i = ((qY_1 - 1) * 13 + i) - 1;

          // Assignment: '<S469>/Assignment' incorporates:
          //   Constant: '<S469>/c[maxdef][maxdef]'
          //   Constant: '<S469>/cd[maxdef][maxdef]'
          //   Product: '<S495>/Product'
          //   Selector: '<S495>/c[m][n]'
          //   Selector: '<S495>/cd[m][n]'
          //   Sum: '<S495>/Sum'

          FaultModel_B.Assignment[i] = FaultModel_P.cdmaxdefmaxdef_Value[i] *
            rtb_Sum_os + FaultModel_P.cmaxdefmaxdef_Value[i];

          // End of Outputs for SubSystem: '<S469>/If Action Subsystem'

          // Switch: '<S496>/tc_old' incorporates:
          //   Constant: '<S496>/zeros(maxdef+1,maxdef+1)'
          //   UnitDelay: '<S496>/Unit Delay'

          if (r > FaultModel_P.tc_old_Threshold) {
            std::memcpy(&rtb_tc_old[0], &FaultModel_DW.UnitDelay_DSTATE_n[0],
                        169U * sizeof(real_T));
          } else {
            std::memcpy(&rtb_tc_old[0], &FaultModel_P.zerosmaxdef1maxdef1_Value
                        [0], 169U * sizeof(real_T));
          }

          // End of Switch: '<S496>/tc_old'

          // If: '<S496>/If' incorporates:
          //   Sum: '<S466>/Sum1'

          if (qY_2 != 0) {
            // Outputs for IfAction SubSystem: '<S496>/If Action Subsystem1' incorporates:
            //   ActionPort: '<S497>/Action Port'

            // Sum: '<S497>/Sum2' incorporates:
            //   Constant: '<S497>/Constant'

            if ((r < 0) && (FaultModel_P.Constant_Value_ex < MIN_int32_T - r)) {
              i = MIN_int32_T;
            } else if ((r > 0) && (FaultModel_P.Constant_Value_ex > MAX_int32_T
                                   - r)) {
              i = MAX_int32_T;
            } else {
              i = r + FaultModel_P.Constant_Value_ex;
            }

            // Assignment: '<S497>/Assignment2'
            if (ForIterator_IterationMarker[5] < 2) {
              ForIterator_IterationMarker[5] = 2U;

              // Assignment: '<S497>/Assignment2' incorporates:
              //   Switch: '<S496>/tc_old'

              std::memcpy(&FaultModel_B.Assignment2[0], &rtb_tc_old[0], 169U *
                          sizeof(real_T));
            }

            // Selector: '<S497>/cd[m][n]' incorporates:
            //   Assignment: '<S497>/Assignment2'
            //   Constant: '<S469>/c[maxdef][maxdef]'
            //   Constant: '<S469>/cd[maxdef][maxdef]'
            //   Selector: '<S497>/c[m][n]'
            //   Sum: '<S497>/Sum2'

            i = ((qY_2 - 1) * 13 + i) - 1;

            // Assignment: '<S497>/Assignment2' incorporates:
            //   Constant: '<S469>/c[maxdef][maxdef]'
            //   Constant: '<S469>/cd[maxdef][maxdef]'
            //   Product: '<S497>/Product'
            //   Selector: '<S497>/c[m][n]'
            //   Selector: '<S497>/cd[m][n]'
            //   Sum: '<S497>/Sum'

            FaultModel_B.Assignment2[i] = FaultModel_P.cdmaxdefmaxdef_Value[i] *
              rtb_Sum_os + FaultModel_P.cmaxdefmaxdef_Value[i];

            // Gain: '<S497>/Gain' incorporates:
            //   Assignment: '<S497>/Assignment2'
            //   Merge: '<S496>/Merge'

            for (i = 0; i < 169; i++) {
              rtb_tc_old[i] = FaultModel_P.Gain_Gain_ng *
                FaultModel_B.Assignment2[i];
            }

            // End of Gain: '<S497>/Gain'
            // End of Outputs for SubSystem: '<S496>/If Action Subsystem1'
          }

          // End of If: '<S496>/If'
          for (i = 0; i < 169; i++) {
            // Sum: '<S469>/Sum2' incorporates:
            //   Merge: '<S496>/Merge'

            rtb_Product2_l = rtb_tc_old[i];

            // Sum: '<S469>/Sum2' incorporates:
            //   Assignment: '<S469>/Assignment'

            FaultModel_B.Sum2_l[i] = FaultModel_B.Assignment[i] + rtb_Product2_l;

            // Update for UnitDelay: '<S469>/Unit Delay' incorporates:
            //   Assignment: '<S469>/Assignment'

            FaultModel_DW.UnitDelay_DSTATE_d[i] = FaultModel_B.Assignment[i];

            // Update for UnitDelay: '<S496>/Unit Delay'
            FaultModel_DW.UnitDelay_DSTATE_n[i] = rtb_Product2_l;
          }
        }

        // End of Outputs for SubSystem: '<S466>/Time adjust the gauss coefficients' 

        // Sum: '<S472>/Sum4' incorporates:
        //   Constant: '<S472>/Constant1'
        //   Sum: '<S466>/Sum1'

        Y = static_cast<real_T>(qY_2) + FaultModel_P.Constant1_Value_m1;

        // If: '<S472>/If' incorporates:
        //   Sum: '<S466>/Sum1'

        if (qY_2 == 0) {
          // Outputs for IfAction SubSystem: '<S472>/If Action Subsystem' incorporates:
          //   ActionPort: '<S478>/Action Port'

          // Sum: '<S478>/Sum' incorporates:
          //   Constant: '<S478>/Constant'

          rtb_Product2_l = static_cast<real_T>(r) +
            FaultModel_P.Constant_Value_p;

          // Selector: '<S478>/Selector'
          rtb_q2dot = rtb_Product2_l;

          // Product: '<S478>/Product' incorporates:
          //   Constant: '<S478>/Constant'
          //   Selector: '<S472>/cp[m+1]'
          //   Selector: '<S478>/Selector'
          //   Sum: '<S469>/Sum2'

          rtb_Product2_l = FaultModel_B.Sum2_l[((static_cast<int32_T>
            (rtb_Product2_l) - 1) * 13 + static_cast<int32_T>
            (FaultModel_P.Constant_Value_p)) - 1] *
            FaultModel_B.OutportBufferForcp13[static_cast<int32_T>(Y) - 1];

          // Merge: '<S472>/Merge' incorporates:
          //   Gain: '<S478>/Gain1'

          rtb_q3dot = FaultModel_P.Gain1_Gain * rtb_Product2_l;

          // Merge: '<S472>/Merge1' incorporates:
          //   Constant: '<S478>/Constant'
          //   Gain: '<S478>/Gain2'
          //   Product: '<S478>/Product'
          //   Selector: '<S472>/cp[m+1]'
          //   Selector: '<S472>/sp[m+1]'
          //   Selector: '<S478>/Selector'
          //   Sum: '<S469>/Sum2'

          rtb_q2dot = FaultModel_B.Sum2_l[((static_cast<int32_T>(rtb_q2dot) - 1)
            * 13 + static_cast<int32_T>(FaultModel_P.Constant_Value_p)) - 1] *
            FaultModel_B.OutportBufferForsp13[static_cast<int32_T>(Y) - 1] *
            FaultModel_P.Gain2_Gain;

          // End of Outputs for SubSystem: '<S472>/If Action Subsystem'
        } else {
          // Outputs for IfAction SubSystem: '<S472>/If Action Subsystem1' incorporates:
          //   ActionPort: '<S479>/Action Port'

          // Sum: '<S480>/Sum' incorporates:
          //   Constant: '<S480>/Constant'

          rtb_Product2_l = static_cast<real_T>(r) +
            FaultModel_P.Constant_Value_o;
          rtb_sincos_o1_p_idx_1 = static_cast<real_T>(qY_2) +
            FaultModel_P.Constant_Value_o;

          // Selector: '<S479>/Selector'
          rtb_q2dot = rtb_Product2_l;

          // Product: '<S479>/Product' incorporates:
          //   Selector: '<S472>/cp[m+1]'
          //   Selector: '<S472>/sp[m+1]'
          //   Selector: '<S479>/Selector'
          //   Sum: '<S469>/Sum2'

          rtb_sincos_o1_p_idx_0_tmp = FaultModel_B.OutportBufferForcp13[
            static_cast<int32_T>(Y) - 1];
          rtb_Product2_l = FaultModel_B.Sum2_l[((static_cast<int32_T>
            (rtb_Product2_l) - 1) * 13 + static_cast<int32_T>
            (rtb_sincos_o1_p_idx_1)) - 1] * rtb_sincos_o1_p_idx_0_tmp;
          Y = FaultModel_B.OutportBufferForsp13[static_cast<int32_T>(Y) - 1];
          rtb_sincos_o1_p_idx_1 = FaultModel_B.Sum2_l[((static_cast<int32_T>
            (rtb_q2dot) - 1) * 13 + static_cast<int32_T>(rtb_sincos_o1_p_idx_1))
            - 1] * Y;

          // Selector: '<S479>/Selector1' incorporates:
          //   Constant: '<S481>/Constant'
          //   Sum: '<S469>/Sum2'
          //   Sum: '<S481>/Sum'

          rtb_q3dot = FaultModel_B.Sum2_l[((qY_2 - 1) * 13 + static_cast<int32_T>
            (static_cast<real_T>(r) + FaultModel_P.Constant_Value_ly)) - 1];

          // Product: '<S479>/Product1'
          frac[0] = rtb_sincos_o1_p_idx_0_tmp * rtb_q3dot;

          // Merge: '<S472>/Merge' incorporates:
          //   Product: '<S479>/Product1'
          //   Sum: '<S479>/Sum'

          rtb_q3dot = Y * rtb_q3dot + rtb_Product2_l;

          // Merge: '<S472>/Merge1' incorporates:
          //   Sum: '<S479>/Sum1'

          rtb_q2dot = rtb_sincos_o1_p_idx_1 - frac[0];

          // End of Outputs for SubSystem: '<S472>/If Action Subsystem1'
        }

        // End of If: '<S472>/If'

        // Outputs for Enabled SubSystem: '<S466>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' incorporates:
        //   EnablePort: '<S468>/Enable'

        // SignalConversion generated from: '<S468>/Enable'
        if (rtb_hasFault_j) {
          // If: '<S468>/if n == m elseif (n==1&m==0) elseif (n>1&m~=n)' incorporates:
          //   Sum: '<S466>/Sum1'

          if (r == qY_2) {
            // Outputs for IfAction SubSystem: '<S468>/If Action Subsystem' incorporates:
            //   ActionPort: '<S482>/Action Port'

            // Sum: '<S486>/Sum2' incorporates:
            //   Constant: '<S486>/Constant'

            if ((qY_2 >= 0) && (FaultModel_P.Constant_Value_c < qY_2 -
                                MAX_int32_T)) {
              i = MAX_int32_T;
            } else if ((qY_2 < 0) && (FaultModel_P.Constant_Value_c > qY_2 -
                        MIN_int32_T)) {
              i = MIN_int32_T;
            } else {
              i = qY_2 - FaultModel_P.Constant_Value_c;
            }

            // End of Sum: '<S486>/Sum2'

            // Gain: '<S486>/Gain'
            rtb_Sum1_kf = mul_s32_sat(FaultModel_P.Gain_Gain_id, i);

            // Selector: '<S482>/Selector' incorporates:
            //   Sum: '<S486>/Sum1'

            if ((r < 0) && (rtb_Sum1_kf < MIN_int32_T - r)) {
              qY_1 = MIN_int32_T;
            } else if ((r > 0) && (rtb_Sum1_kf > MAX_int32_T - r)) {
              qY_1 = MAX_int32_T;
            } else {
              qY_1 = r + rtb_Sum1_kf;
            }

            // Merge: '<S468>/Merge' incorporates:
            //   Product: '<S482>/Product1'
            //   Selector: '<S482>/Selector'
            //   UnitDelay: '<S468>/Unit Delay1'

            FaultModel_B.Merge_m = FaultModel_DW.UnitDelay1_DSTATE_b[qY_1 - 1] *
              FaultModel_B.sqrt_m;

            // Selector: '<S482>/Selector' incorporates:
            //   Sum: '<S486>/Sum1'

            if ((r < 0) && (rtb_Sum1_kf < MIN_int32_T - r)) {
              qY_1 = MIN_int32_T;
            } else if ((r > 0) && (rtb_Sum1_kf > MAX_int32_T - r)) {
              qY_1 = MAX_int32_T;
            } else {
              qY_1 = r + rtb_Sum1_kf;
            }

            // Merge: '<S468>/Merge1' incorporates:
            //   Product: '<S482>/Product'
            //   Product: '<S482>/Product2'
            //   Selector: '<S482>/Selector'
            //   Selector: '<S482>/Selector1'
            //   Sum: '<S482>/Sum'
            //   UnitDelay: '<S468>/Unit Delay'
            //   UnitDelay: '<S468>/Unit Delay1'

            FaultModel_B.Merge1_o = FaultModel_DW.UnitDelay_DSTATE_e[((r - 1) *
              13 + qY_2) - 1] * FaultModel_B.sqrt_m +
              FaultModel_DW.UnitDelay1_DSTATE_b[qY_1 - 1] *
              FaultModel_B.Product4_d;

            // End of Outputs for SubSystem: '<S468>/If Action Subsystem'
          } else if ((r == 1) && (qY_2 == 0)) {
            // Outputs for IfAction SubSystem: '<S468>/If Action Subsystem1' incorporates:
            //   ActionPort: '<S483>/Action Port'

            // Selector: '<S483>/Selector' incorporates:
            //   Gain: '<S488>/Gain'
            //   Sum: '<S488>/Sum1'

            i = mul_s32_sat(FaultModel_P.Gain_Gain_ngk, 0);
            if (i > 2147483646) {
              rtb_Sum1_kf = MAX_int32_T;
            } else {
              rtb_Sum1_kf = i + 1;
            }

            // Merge: '<S468>/Merge' incorporates:
            //   Product: '<S483>/Product3'
            //   Selector: '<S483>/Selector'
            //   UnitDelay: '<S468>/Unit Delay1'

            FaultModel_B.Merge_m = FaultModel_DW.UnitDelay1_DSTATE_b[rtb_Sum1_kf
              - 1] * FaultModel_B.Product4_d;

            // Selector: '<S483>/Selector' incorporates:
            //   Sum: '<S488>/Sum1'

            if (i > 2147483646) {
              rtb_Sum1_kf = MAX_int32_T;
            } else {
              rtb_Sum1_kf = i + 1;
            }

            // Merge: '<S468>/Merge1' incorporates:
            //   Constant: '<S489>/Constant'
            //   Product: '<S483>/Product'
            //   Product: '<S483>/Product2'
            //   Selector: '<S483>/Selector'
            //   Selector: '<S483>/Selector1'
            //   Sum: '<S483>/Sum'
            //   UnitDelay: '<S468>/Unit Delay'
            //   UnitDelay: '<S468>/Unit Delay1'

            FaultModel_B.Merge1_o =
              FaultModel_DW.UnitDelay_DSTATE_e[FaultModel_P.Constant_Value_by -
              1] * FaultModel_B.Product4_d -
              FaultModel_DW.UnitDelay1_DSTATE_b[rtb_Sum1_kf - 1] *
              FaultModel_B.sqrt_m;

            // End of Outputs for SubSystem: '<S468>/If Action Subsystem1'
          } else {
            if ((r > 1) && (r != qY_2)) {
              // Outputs for IfAction SubSystem: '<S468>/If Action Subsystem2' incorporates:
              //   ActionPort: '<S484>/Action Port'

              // Sum: '<S492>/Sum' incorporates:
              //   Constant: '<S492>/Constant'

              if ((qY_2 < 0) && (FaultModel_P.Constant_Value_k4 < MIN_int32_T
                                 - qY_2)) {
                i = MIN_int32_T;
              } else if ((qY_2 > 0) && (FaultModel_P.Constant_Value_k4 >
                          MAX_int32_T - qY_2)) {
                i = MAX_int32_T;
              } else {
                i = qY_2 + FaultModel_P.Constant_Value_k4;
              }

              // Sum: '<S493>/Sum2' incorporates:
              //   Constant: '<S493>/Constant1'

              if (FaultModel_P.Constant1_Value_l < r - MAX_int32_T) {
                qY_1 = MAX_int32_T;
              } else {
                qY_1 = r - FaultModel_P.Constant1_Value_l;
              }

              // End of Sum: '<S493>/Sum2'

              // Switch: '<S484>/Switch' incorporates:
              //   Constant: '<S484>/Constant'
              //   DataTypeConversion: '<S493>/Data Type Conversion'
              //   RelationalOperator: '<S493>/Relational Operator'
              //   Selector: '<S484>/Selector1'
              //   Sum: '<S492>/Sum'
              //   UnitDelay: '<S468>/Unit Delay'

              if (static_cast<real_T>(qY_1 >= qY_2) >
                  FaultModel_P.Switch_Threshold) {
                // Sum: '<S492>/Sum2' incorporates:
                //   Constant: '<S492>/Constant1'

                if (FaultModel_P.Constant1_Value_ob < r - MAX_int32_T) {
                  qY_1 = MAX_int32_T;
                } else {
                  qY_1 = r - FaultModel_P.Constant1_Value_ob;
                }

                // End of Sum: '<S492>/Sum2'
                rtb_Product2_l = FaultModel_DW.UnitDelay_DSTATE_e[((qY_1 - 1) *
                  13 + i) - 1];
              } else {
                rtb_Product2_l = FaultModel_P.Constant_Value_ev;
              }

              // End of Switch: '<S484>/Switch'

              // Sum: '<S491>/Sum' incorporates:
              //   Constant: '<S491>/Constant'

              if (FaultModel_P.Constant_Value_pw > MAX_int32_T - r) {
                qY_1 = MAX_int32_T;
              } else {
                qY_1 = r + FaultModel_P.Constant_Value_pw;
              }

              if ((qY_2 < 0) && (FaultModel_P.Constant_Value_pw < MIN_int32_T
                                 - qY_2)) {
                qY_0 = MIN_int32_T;
              } else if ((qY_2 > 0) && (FaultModel_P.Constant_Value_pw >
                          MAX_int32_T - qY_2)) {
                qY_0 = MAX_int32_T;
              } else {
                qY_0 = qY_2 + FaultModel_P.Constant_Value_pw;
              }

              // Gain: '<S490>/Gain'
              rtb_Sum1_kf = mul_s32_sat(FaultModel_P.Gain_Gain_bi, qY_2);

              // Selector: '<S484>/Selector' incorporates:
              //   Sum: '<S490>/Sum1'

              if (rtb_Sum1_kf > MAX_int32_T - r) {
                rtb_Sum1_pe = MAX_int32_T;
              } else {
                rtb_Sum1_pe = r + rtb_Sum1_kf;
              }

              // Selector: '<S484>/Selector2' incorporates:
              //   Constant: '<S484>/k[13][13]'
              //   Sum: '<S491>/Sum'

              Y = FaultModel_P.k1313_Value_k[((qY_1 - 1) * 13 + qY_0) - 1];

              // Merge: '<S468>/Merge1' incorporates:
              //   Constant: '<S484>/k[13][13]'
              //   Product: '<S484>/Product'
              //   Product: '<S484>/Product1'
              //   Product: '<S484>/Product4'
              //   Selector: '<S484>/Selector'
              //   Selector: '<S484>/Selector1'
              //   Selector: '<S484>/Selector2'
              //   Sum: '<S484>/Sum'
              //   Sum: '<S492>/Sum'
              //   UnitDelay: '<S468>/Unit Delay'
              //   UnitDelay: '<S468>/Unit Delay1'

              FaultModel_B.Merge1_o = (FaultModel_DW.UnitDelay_DSTATE_e[((r - 1)
                * 13 + i) - 1] * FaultModel_B.Product4_d -
                FaultModel_DW.UnitDelay1_DSTATE_b[rtb_Sum1_pe - 1] *
                FaultModel_B.sqrt_m) - Y * rtb_Product2_l;

              // Sum: '<S494>/Sum2' incorporates:
              //   Constant: '<S494>/Constant1'

              if (FaultModel_P.Constant1_Value_lt < r - MAX_int32_T) {
                qY_1 = MAX_int32_T;
              } else {
                qY_1 = r - FaultModel_P.Constant1_Value_lt;
              }

              // End of Sum: '<S494>/Sum2'

              // Switch: '<S484>/Switch1' incorporates:
              //   Constant: '<S484>/Constant1'
              //   DataTypeConversion: '<S494>/Data Type Conversion'
              //   RelationalOperator: '<S494>/Relational Operator'
              //   Selector: '<S484>/Selector'
              //   UnitDelay: '<S468>/Unit Delay1'

              if (static_cast<real_T>(qY_1 >= qY_2) >
                  FaultModel_P.Switch1_Threshold) {
                // Selector: '<S484>/Selector' incorporates:
                //   Constant: '<S490>/Constant1'
                //   Sum: '<S490>/Sum1'
                //   Sum: '<S490>/Sum2'

                if (FaultModel_P.Constant1_Value_f < r - MAX_int32_T) {
                  i = MAX_int32_T;
                } else {
                  i = r - FaultModel_P.Constant1_Value_f;
                }

                if ((i < 0) && (rtb_Sum1_kf < MIN_int32_T - i)) {
                  i = MIN_int32_T;
                } else if ((i > 0) && (rtb_Sum1_kf > MAX_int32_T - i)) {
                  i = MAX_int32_T;
                } else {
                  i += rtb_Sum1_kf;
                }

                rtb_Product2_l = FaultModel_DW.UnitDelay1_DSTATE_b[i - 1];
              } else {
                rtb_Product2_l = FaultModel_P.Constant1_Value_b;
              }

              // End of Switch: '<S484>/Switch1'

              // Selector: '<S484>/Selector' incorporates:
              //   Sum: '<S490>/Sum1'

              if (rtb_Sum1_kf > MAX_int32_T - r) {
                rtb_Sum1_kf = MAX_int32_T;
              } else {
                rtb_Sum1_kf += r;
              }

              // Merge: '<S468>/Merge' incorporates:
              //   Product: '<S484>/Product2'
              //   Product: '<S484>/Product3'
              //   Selector: '<S484>/Selector'
              //   Sum: '<S484>/Sum1'
              //   UnitDelay: '<S468>/Unit Delay1'

              FaultModel_B.Merge_m =
                FaultModel_DW.UnitDelay1_DSTATE_b[rtb_Sum1_kf - 1] *
                FaultModel_B.Product4_d - Y * rtb_Product2_l;

              // End of Outputs for SubSystem: '<S468>/If Action Subsystem2'
            }
          }

          // End of If: '<S468>/if n == m elseif (n==1&m==0) elseif (n>1&m~=n)'

          // Sum: '<S468>/Sum' incorporates:
          //   Constant: '<S468>/Constant'
          //   Sum: '<S466>/Sum1'

          if ((r < 0) && (FaultModel_P.Constant_Value_b2 < MIN_int32_T - r)) {
            i = MIN_int32_T;
          } else if ((r > 0) && (FaultModel_P.Constant_Value_b2 > MAX_int32_T
                                 - r)) {
            i = MAX_int32_T;
          } else {
            i = r + FaultModel_P.Constant_Value_b2;
          }

          if ((qY_2 < 0) && (FaultModel_P.Constant_Value_b2 < MIN_int32_T - qY_2))
          {
            qY_1 = MIN_int32_T;
          } else if ((qY_2 > 0) && (FaultModel_P.Constant_Value_b2 > MAX_int32_T
                      - qY_2)) {
            qY_1 = MAX_int32_T;
          } else {
            qY_1 = qY_2 + FaultModel_P.Constant_Value_b2;
          }

          // Assignment: '<S468>/Assignment' incorporates:
          //   Sum: '<S468>/Sum'
          //   UnitDelay: '<S468>/Unit Delay'

          if (ForIterator_IterationMarker[2] < 2) {
            ForIterator_IterationMarker[2] = 2U;
            std::memcpy(&FaultModel_B.Assignment_k[0],
                        &FaultModel_DW.UnitDelay_DSTATE_e[0], 169U * sizeof
                        (real_T));
          }

          FaultModel_B.Assignment_k[(qY_1 + 13 * (i - 1)) - 1] =
            FaultModel_B.Merge1_o;

          // End of Assignment: '<S468>/Assignment'

          // Assignment: '<S468>/Assignment_snorm' incorporates:
          //   Constant: '<S485>/Constant'
          //   Gain: '<S485>/Gain'
          //   Sum: '<S468>/Sum'
          //   Sum: '<S485>/Sum1'
          //   Sum: '<S485>/Sum2'

          if (ForIterator_IterationMarker[3] < 2) {
            ForIterator_IterationMarker[3] = 2U;

            // Assignment: '<S468>/Assignment_snorm' incorporates:
            //   UnitDelay: '<S468>/Unit Delay1'

            std::memcpy(&FaultModel_B.Assignment_snorm[0],
                        &FaultModel_DW.UnitDelay1_DSTATE_b[0], 169U * sizeof
                        (real_T));
          }

          if ((qY_1 >= 0) && (FaultModel_P.Constant_Value_kp < qY_1 -
                              MAX_int32_T)) {
            qY_1 = MAX_int32_T;
          } else if ((qY_1 < 0) && (FaultModel_P.Constant_Value_kp > qY_1 -
                      MIN_int32_T)) {
            qY_1 = MIN_int32_T;
          } else {
            qY_1 -= FaultModel_P.Constant_Value_kp;
          }

          FaultModel_B.Assignment_snorm[(i + mul_s32_sat
            (FaultModel_P.Gain_Gain_lf, qY_1)) - 1] = FaultModel_B.Merge_m;

          // End of Assignment: '<S468>/Assignment_snorm'

          // Update for UnitDelay: '<S468>/Unit Delay' incorporates:
          //   Assignment: '<S468>/Assignment'

          std::memcpy(&FaultModel_DW.UnitDelay_DSTATE_e[0],
                      &FaultModel_B.Assignment_k[0], 169U * sizeof(real_T));

          // Update for UnitDelay: '<S468>/Unit Delay1'
          std::memcpy(&FaultModel_DW.UnitDelay1_DSTATE_b[0],
                      &FaultModel_B.Assignment_snorm[0], 169U * sizeof(real_T));
        }

        // End of SignalConversion generated from: '<S468>/Enable'
        // End of Outputs for SubSystem: '<S466>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' 

        // Sum: '<S467>/Sum' incorporates:
        //   Constant: '<S467>/Constant'
        //   Sum: '<S466>/Sum1'

        if ((qY_2 < 0) && (FaultModel_P.Constant_Value_h1y < MIN_int32_T - qY_2))
        {
          i = MIN_int32_T;
        } else if ((qY_2 > 0) && (FaultModel_P.Constant_Value_h1y > MAX_int32_T
                    - qY_2)) {
          i = MAX_int32_T;
        } else {
          i = qY_2 + FaultModel_P.Constant_Value_h1y;
        }

        // Product: '<S467>/Product' incorporates:
        //   Assignment: '<S468>/Assignment'
        //   Selector: '<S467>/dp[n][m]'

        rtb_Product2_l = FaultModel_B.Assignment_k[((r_0 - 1) * 13 + i) - 1] *
          rtb_q3dot * uavlostJyz;

        // Selector: '<S467>/snorm[n+m*13]' incorporates:
        //   Gain: '<S471>/Gain'
        //   Sum: '<S466>/Sum1'
        //   Sum: '<S471>/Sum1'

        rtb_Sum1_kf = mul_s32_sat(FaultModel_P.Gain_Gain_a1, qY_2);
        if ((qY < 0) && (rtb_Sum1_kf < MIN_int32_T - qY)) {
          i = MIN_int32_T;
        } else if ((qY > 0) && (rtb_Sum1_kf > MAX_int32_T - qY)) {
          i = MAX_int32_T;
        } else {
          i = qY + rtb_Sum1_kf;
        }

        // Product: '<S467>/par' incorporates:
        //   Selector: '<S467>/snorm[n+m*13]'

        Y = FaultModel_B.Assignment_snorm[i - 1] * uavlostJyz;

        // Outputs for Enabled SubSystem: '<S467>/Special case - North//South Geographic Pole' incorporates:
        //   EnablePort: '<S470>/Enable'

        // Logic: '<S473>/Logical Operator' incorporates:
        //   Constant: '<S473>/Constant'
        //   Constant: '<S473>/Constant1'
        //   RelationalOperator: '<S473>/Relational Operator'
        //   RelationalOperator: '<S473>/Relational Operator1'
        //   Sum: '<S466>/Sum1'

        if ((FaultModel_B.sqrt_m == FaultModel_P.Constant1_Value_g) &&
            (FaultModel_P.Constant_Value_kg == qY_2)) {
          FaultModel_DW.SpecialcaseNorthSouthGeographic = true;

          // If: '<S470>/n ==1' incorporates:
          //   Assignment: '<S475>/Assignment2'

          if (r == 1) {
            // Outputs for IfAction SubSystem: '<S470>/If Action Subsystem1' incorporates:
            //   ActionPort: '<S474>/Action Port'

            // Assignment: '<S474>/Assignment2' incorporates:
            //   Constant: '<S474>/Constant'
            //   Selector: '<S474>/pp[n-1]'
            //   Sum: '<S474>/Sum2'
            //   UnitDelay: '<S470>/Unit Delay1'

            if (ForIterator_IterationMarker[0] < 2) {
              ForIterator_IterationMarker[0] = 2U;

              // Assignment: '<S474>/Assignment2'
              std::memcpy(&FaultModel_B.Assignment2_j[0],
                          &FaultModel_DW.UnitDelay1_DSTATE_o[0], 13U * sizeof
                          (real_T));
            }

            FaultModel_B.Assignment2_j[static_cast<int32_T>
              (FaultModel_P.Constant_Value_ey + 1.0) - 1] =
              FaultModel_DW.UnitDelay1_DSTATE_o[0];

            // End of Assignment: '<S474>/Assignment2'
            // End of Outputs for SubSystem: '<S470>/If Action Subsystem1'
          } else {
            // Outputs for IfAction SubSystem: '<S470>/If Action Subsystem2' incorporates:
            //   ActionPort: '<S475>/Action Port'

            if (ForIterator_IterationMarker[1] < 2) {
              // Assignment: '<S475>/Assignment2'
              ForIterator_IterationMarker[1] = 2U;

              // Assignment: '<S475>/Assignment2' incorporates:
              //   UnitDelay: '<S470>/Unit Delay1'

              std::memcpy(&FaultModel_B.Assignment2_i[0],
                          &FaultModel_DW.UnitDelay1_DSTATE_o[0], 13U * sizeof
                          (real_T));
            }

            // Assignment: '<S475>/Assignment2' incorporates:
            //   Constant: '<S475>/Constant'
            //   Sum: '<S475>/Sum2'

            if ((r < 0) && (FaultModel_P.Constant_Value_dt < MIN_int32_T - r)) {
              qY_1 = MIN_int32_T;
            } else if ((r > 0) && (FaultModel_P.Constant_Value_dt > MAX_int32_T
                                   - r)) {
              qY_1 = MAX_int32_T;
            } else {
              qY_1 = r + FaultModel_P.Constant_Value_dt;
            }

            // Sum: '<S477>/Sum' incorporates:
            //   Constant: '<S477>/Constant'

            if ((qY_2 < 0) && (FaultModel_P.Constant_Value_ao < MIN_int32_T
                               - qY_2)) {
              i = MIN_int32_T;
            } else if ((qY_2 > 0) && (FaultModel_P.Constant_Value_ao >
                        MAX_int32_T - qY_2)) {
              i = MAX_int32_T;
            } else {
              i = qY_2 + FaultModel_P.Constant_Value_ao;
            }

            if ((r < 0) && (FaultModel_P.Constant_Value_ao < MIN_int32_T - r)) {
              rtb_Sum1_kf = MIN_int32_T;
            } else if ((r > 0) && (FaultModel_P.Constant_Value_ao > MAX_int32_T
                                   - r)) {
              rtb_Sum1_kf = MAX_int32_T;
            } else {
              rtb_Sum1_kf = r + FaultModel_P.Constant_Value_ao;
            }

            // End of Sum: '<S477>/Sum'

            // Selector: '<S475>/pp[n-2] pp[n-1]' incorporates:
            //   Constant: '<S476>/Constant1'
            //   Sum: '<S476>/Sum2'

            if ((r >= 0) && (FaultModel_P.Constant1_Value_ir < r - MAX_int32_T))
            {
              qY_0 = MAX_int32_T;
            } else if ((r < 0) && (FaultModel_P.Constant1_Value_ir > r -
                                   MIN_int32_T)) {
              qY_0 = MIN_int32_T;
            } else {
              qY_0 = r - FaultModel_P.Constant1_Value_ir;
            }

            // Assignment: '<S475>/Assignment2' incorporates:
            //   Constant: '<S475>/k[13][13]'
            //   Product: '<S475>/Product1'
            //   Product: '<S475>/Product2'
            //   Selector: '<S475>/Selector2'
            //   Selector: '<S475>/pp[n-2] pp[n-1]'
            //   Sum: '<S475>/Sum1'
            //   UnitDelay: '<S470>/Unit Delay1'

            FaultModel_B.Assignment2_i[qY_1 - 1] =
              FaultModel_DW.UnitDelay1_DSTATE_o[r - 1] * FaultModel_B.Product4_d
              - FaultModel_P.k1313_Value[((rtb_Sum1_kf - 1) * 13 + i) - 1] *
              FaultModel_DW.UnitDelay1_DSTATE_o[qY_0 - 1];

            // End of Outputs for SubSystem: '<S470>/If Action Subsystem2'
          }

          // End of If: '<S470>/n ==1'

          // SignalConversion generated from: '<S470>/pp[n]' incorporates:
          //   UnitDelay: '<S470>/Unit Delay1'

          rtb_TmpSignalConversionAtppnInp[0] =
            FaultModel_DW.UnitDelay1_DSTATE_o[0];
          rtb_TmpSignalConversionAtppnInp[1] = FaultModel_B.Assignment2_j[1];
          std::memcpy(&rtb_TmpSignalConversionAtppnInp[2],
                      &FaultModel_B.Assignment2_i[2], 11U * sizeof(real_T));

          // Product: '<S470>/Product2' incorporates:
          //   Constant: '<S470>/Constant'
          //   Constant: '<S470>/Constant1'
          //   Selector: '<S470>/pp[n]'
          //   Sum: '<S470>/Sum2'

          FaultModel_B.Product2_b = rtb_TmpSignalConversionAtppnInp
            [static_cast<int32_T>(static_cast<real_T>(r) +
            FaultModel_P.Constant1_Value_o) - 1] * uavlostJyz *
            FaultModel_P.Constant_Value_j * rtb_q2dot;

          // Update for UnitDelay: '<S470>/Unit Delay1'
          std::memcpy(&FaultModel_DW.UnitDelay1_DSTATE_o[0],
                      &rtb_TmpSignalConversionAtppnInp[0], 13U * sizeof(real_T));
        } else {
          if (FaultModel_DW.SpecialcaseNorthSouthGeographic) {
            // Disable for Product: '<S470>/Product2' incorporates:
            //   Outport: '<S470>/bpp'

            FaultModel_B.Product2_b = FaultModel_P.bpp_Y0;
            FaultModel_DW.SpecialcaseNorthSouthGeographic = false;
          }
        }

        // End of Logic: '<S473>/Logical Operator'
        // End of Outputs for SubSystem: '<S467>/Special case - North//South Geographic Pole' 

        // Sum: '<S467>/Sum1' incorporates:
        //   UnitDelay: '<S467>/Unit Delay1'

        FaultModel_B.Sum1_b = uavlostJzx - rtb_Product2_l;

        // Sum: '<S467>/Sum4' incorporates:
        //   Constant: '<S467>/Constant1'
        //   Sum: '<S466>/Sum1'

        if ((qY_2 < 0) && (FaultModel_P.Constant1_Value_jl < MIN_int32_T - qY_2))
        {
          qY_2 = MIN_int32_T;
        } else if ((qY_2 > 0) && (FaultModel_P.Constant1_Value_jl > MAX_int32_T
                    - qY_2)) {
          qY_2 = MAX_int32_T;
        } else {
          qY_2 += FaultModel_P.Constant1_Value_jl;
        }

        // Sum: '<S467>/Sum2' incorporates:
        //   Constant: '<S467>/fm'
        //   Product: '<S467>/Product1'
        //   Selector: '<S467>/fm[m]'
        //   UnitDelay: '<S467>/Unit Delay3'

        FaultModel_B.Sum2_a = FaultModel_P.fm_Value[qY_2 - 1] * Y * rtb_q2dot +
          uavlostJxy;

        // Sum: '<S467>/Sum3' incorporates:
        //   Constant: '<S467>/fn'
        //   Product: '<S467>/Product2'
        //   Selector: '<S467>/fn[m]'
        //   UnitDelay: '<S467>/Unit Delay2'

        FaultModel_B.Sum3 = FaultModel_P.fn_Value[r_1 - 1] * Y * rtb_q3dot +
          rtb_LimitaltitudetoStratosphere;

        // Sum: '<S467>/Sum5' incorporates:
        //   UnitDelay: '<S467>/Unit Delay4'

        FaultModel_B.Sum5 = rtb_jxi + FaultModel_B.Product2_b;

        // Update for UnitDelay: '<S467>/Unit Delay1'
        uavlostJzx = FaultModel_B.Sum1_b;

        // Update for UnitDelay: '<S467>/Unit Delay3'
        uavlostJxy = FaultModel_B.Sum2_a;

        // Update for UnitDelay: '<S467>/Unit Delay2'
        rtb_LimitaltitudetoStratosphere = FaultModel_B.Sum3;

        // Update for UnitDelay: '<S467>/Unit Delay4'
        rtb_jxi = FaultModel_B.Sum5;
      }

      // End of Outputs for SubSystem: '<S458>/For Iterator Subsystem'

      // Sum: '<S458>/Sum1' incorporates:
      //   UnitDelay: '<S458>/Unit Delay2'

      FaultModel_B.Sum1_n[0] = tz_idx_0 + FaultModel_B.Sum1_b;
      FaultModel_B.Sum1_n[1] = tz_idx_1 + FaultModel_B.Sum2_a;
      FaultModel_B.Sum1_n[2] = tz_idx_2 + FaultModel_B.Sum3;
      FaultModel_B.Sum1_n[3] = tz_idx_3 + FaultModel_B.Sum5;

      // Update for UnitDelay: '<S458>/Unit Delay'
      Y = uavlostJyz;

      // Update for UnitDelay: '<S458>/Unit Delay2'
      tz_idx_0 = FaultModel_B.Sum1_n[0];
      tz_idx_1 = FaultModel_B.Sum1_n[1];
      tz_idx_2 = FaultModel_B.Sum1_n[2];
      tz_idx_3 = FaultModel_B.Sum1_n[3];
    }

    // End of Outputs for SubSystem: '<S450>/Compute magnetic vector in spherical coordinates' 
  }

  // Switch: '<S510>/Switch' incorporates:
  //   Product: '<S510>/Product'

  if (FaultModel_B.sqrt_m != 0.0) {
    uavlostJzx = FaultModel_B.Sum1_n[1] / FaultModel_B.sqrt_m;
  } else {
    uavlostJzx = FaultModel_B.Sum1_n[3];
  }

  // End of Switch: '<S510>/Switch'

  // Sum: '<S509>/Sum1' incorporates:
  //   Product: '<S509>/Product1'
  //   Product: '<S509>/Product4'

  uavlostJxy = (0.0 - FaultModel_B.Product11 * FaultModel_B.Sum1_n[0]) -
    FaultModel_B.Sum1_n[2] * FaultModel_B.Product12;

  // UnitConversion: '<S514>/Unit Conversion' incorporates:
  //   Trigonometry: '<S512>/Trigonometric Function1'

  // Unit Conversion - from: rad to: deg
  // Expression: output = (57.2958*input) + (0)
  uavlostJyz = 57.295779513082323 * rt_atan2d_snf(uavlostJzx, uavlostJxy);

  // Sum: '<S511>/Sum1' incorporates:
  //   Product: '<S511>/Product1'
  //   Product: '<S511>/Product4'

  rtb_q2dot = FaultModel_B.Product12 * FaultModel_B.Sum1_n[0] -
    FaultModel_B.Sum1_n[2] * FaultModel_B.Product11;

  // Sum: '<S512>/Sum' incorporates:
  //   Product: '<S512>/Product'
  //   Product: '<S512>/Product1'

  uavlostJzx = uavlostJzx * uavlostJzx + uavlostJxy * uavlostJxy;

  // UnitConversion: '<S451>/Unit Conversion' incorporates:
  //   Sqrt: '<S512>/sqrt1'
  //   Trigonometry: '<S512>/Trigonometric Function'
  //   UnitConversion: '<S513>/Unit Conversion'

  // Unit Conversion - from: rad to: deg
  // Expression: output = (57.2958*input) + (0)
  // Unit Conversion - from: deg to: rad
  // Expression: output = (0.0174533*input) + (0)
  rtb_Product2_l = 0.017453292519943295 * uavlostJyz;
  rtb_sincos_o1_p_idx_1 = 57.295779513082323 * rt_atan2d_snf(rtb_q2dot, std::
    sqrt(uavlostJzx)) * 0.017453292519943295;

  // Trigonometry: '<S444>/sincos'
  rtb_LimitaltitudetoStratosphere = std::cos(rtb_Product2_l);
  rtb_Product2_l = std::sin(rtb_Product2_l);

  // Sum: '<S512>/Sum1' incorporates:
  //   Product: '<S512>/Product2'

  uavlostJzx += rtb_q2dot * rtb_q2dot;

  // Sqrt: '<S512>/sqrt'
  uavlostJzx = std::sqrt(uavlostJzx);

  // Product: '<S444>/h1' incorporates:
  //   Trigonometry: '<S444>/sincos'

  uavlostJxy = std::cos(rtb_sincos_o1_p_idx_1) * uavlostJzx;

  // Product: '<S444>/x1'
  rtb_q2dot = rtb_LimitaltitudetoStratosphere * uavlostJxy;

  // Product: '<S444>/y1'
  uavlostJxy *= rtb_Product2_l;

  // Product: '<S444>/z1' incorporates:
  //   Trigonometry: '<S444>/sincos'

  uavlostJzx *= std::sin(rtb_sincos_o1_p_idx_1);
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[2] == 0) {
    // Gain: '<S400>/Gain11' incorporates:
    //   UniformRandomNumber: '<S400>/Uniform Random Number7'

    FaultModel_B.Gain11[0] = FaultModel_P.Gain11_Gain *
      FaultModel_DW.UniformRandomNumber7_NextOutput[0];
    FaultModel_B.Gain11[1] = FaultModel_P.Gain11_Gain *
      FaultModel_DW.UniformRandomNumber7_NextOutput[1];
    FaultModel_B.Gain11[2] = FaultModel_P.Gain11_Gain *
      FaultModel_DW.UniformRandomNumber7_NextOutput[2];
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // MATLAB Function: '<S400>/FaultParamsExtract2' incorporates:
    //   Constant: '<S400>/FaultID2'
    //   Inport: '<Root>/inSILInts'

    // MATLAB Function 'OutputPort1/HILSensorMavModel1/Subsystem/FaultParamsExtract2': '<S406>:1' 
    // '<S406>:1:5' if isempty(hFault)
    // '<S406>:1:8' if isempty(fParam)
    // '<S406>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S406>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S406>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S406>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S406>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID2_Value_ni) {
        // '<S406>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S406>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        b_t = (r + 1) << 1;
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[b_t - 2];

        // '<S406>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] =
          inSILFloats[b_t - 1];

        // '<S406>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S406>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S406>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_l = true;

      // '<S406>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S406>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_e[0], &fParamTmp[0], 20U * sizeof(real_T));
    }

    // MATLAB Function: '<S414>/Mag Fun' incorporates:
    //   MATLAB Function: '<S400>/FaultParamsExtract2'

    // '<S406>:1:29' hasFault_mag=hFault;
    // '<S406>:1:30' FaultParam=fParam;
    // MATLAB Function 'OutputPort1/HILSensorMavModel1/Subsystem/MagNoiseSwitch/Mag Fun': '<S421>:1' 
    // '<S421>:1:4' y = 0.2*u';
    // '<S421>:1:5' y_scale = [1,1,1];
    FaultModel_B.y_d[0] = 0.2 * FaultModel_B.Gain11[0];
    FaultModel_B.y_scale_l[0] = 1.0;
    FaultModel_B.y_d[1] = 0.2 * FaultModel_B.Gain11[1];
    FaultModel_B.y_scale_l[1] = 1.0;
    FaultModel_B.y_d[2] = 0.2 * FaultModel_B.Gain11[2];
    FaultModel_B.y_scale_l[2] = 1.0;

    // '<S421>:1:7' if isAccFault
    if (FaultModel_DW.hFault_l) {
      // '<S421>:1:8' if AccFaultParams(1) == 3
      if (FaultModel_DW.fParam_e[0] == 3.0) {
        // '<S421>:1:9' y = [0.2+0.8*AccFaultParams(3),0.2+0.8*AccFaultParams(5),0.2+0.8*AccFaultParams(7)] .*u' + [AccFaultParams(2),AccFaultParams(4),AccFaultParams(6)]; 
        FaultModel_B.y_d[0] = (0.8 * FaultModel_DW.fParam_e[2] + 0.2) *
          FaultModel_B.Gain11[0] + FaultModel_DW.fParam_e[1];
        FaultModel_B.y_d[1] = (0.8 * FaultModel_DW.fParam_e[4] + 0.2) *
          FaultModel_B.Gain11[1] + FaultModel_DW.fParam_e[3];
        FaultModel_B.y_d[2] = (0.8 * FaultModel_DW.fParam_e[6] + 0.2) *
          FaultModel_B.Gain11[2] + FaultModel_DW.fParam_e[5];

        //  y = (0.2+0.8*AccFaultParams(2))*u;
      } else {
        if (FaultModel_DW.fParam_e[0] == 4.0) {
          // '<S421>:1:11' elseif AccFaultParams(1) == 4
          // '<S421>:1:12' y_scale = [AccFaultParams(2),AccFaultParams(3),AccFaultParams(4)]; 
          FaultModel_B.y_scale_l[0] = FaultModel_DW.fParam_e[1];
          FaultModel_B.y_scale_l[1] = FaultModel_DW.fParam_e[2];
          FaultModel_B.y_scale_l[2] = FaultModel_DW.fParam_e[3];
        }
      }
    }

    // End of MATLAB Function: '<S414>/Mag Fun'
  }

  // Product: '<S400>/Matrix Multiply2' incorporates:
  //   Concatenate: '<S34>/Vector Concatenate'
  //   SignalConversion generated from: '<S400>/Matrix Multiply2'

  for (qY_1 = 0; qY_1 < 3; qY_1++) {
    Product1[qY_1] = VectorConcatenate[qY_1 + 6] * uavlostJzx +
      (VectorConcatenate[qY_1 + 3] * uavlostJxy + VectorConcatenate[qY_1] *
       rtb_q2dot);
  }

  // End of Product: '<S400>/Matrix Multiply2'

  // Saturate: '<S70>/Limit  altitude  to troposhere'
  if (rtb_Saturation_1 > FaultModel_P.Limitaltitudetotroposhere_Upper) {
    rtb_LimitaltitudetoStratosphere =
      FaultModel_P.Limitaltitudetotroposhere_Upper;
  } else if (rtb_Saturation_1 < FaultModel_P.Limitaltitudetotroposhere_Lower) {
    rtb_LimitaltitudetoStratosphere =
      FaultModel_P.Limitaltitudetotroposhere_Lower;
  } else {
    rtb_LimitaltitudetoStratosphere = rtb_Saturation_1;
  }

  // End of Saturate: '<S70>/Limit  altitude  to troposhere'

  // Sum: '<S70>/Sum1' incorporates:
  //   Constant: '<S70>/Sea Level  Temperature'
  //   Gain: '<S70>/Lapse Rate'

  uavlostJzx = FaultModel_P.SeaLevelTemperature_Value_g -
    FaultModel_P.LapseRate_Gain * rtb_LimitaltitudetoStratosphere;

  // Gain: '<S70>/1//T0'
  uavlostJxy = FaultModel_P.uT0_Gain * uavlostJzx;

  // Sum: '<S70>/Sum' incorporates:
  //   Constant: '<S70>/Altitude of Troposphere'

  rtb_LimitaltitudetoStratosphere = FaultModel_P.AltitudeofTroposphere_Value -
    rtb_Saturation_1;

  // Math: '<S70>/(T//T0)^(g//LR) ' incorporates:
  //   Constant: '<S70>/Constant'

  if ((uavlostJxy < 0.0) && (FaultModel_P.Constant_Value_bw > std::floor
       (FaultModel_P.Constant_Value_bw))) {
    rtb_jxi = -rt_powd_snf(-uavlostJxy, FaultModel_P.Constant_Value_bw);
  } else {
    rtb_jxi = rt_powd_snf(uavlostJxy, FaultModel_P.Constant_Value_bw);
  }

  // End of Math: '<S70>/(T//T0)^(g//LR) '

  // Saturate: '<S70>/Limit  altitude  to Stratosphere'
  if (rtb_LimitaltitudetoStratosphere >
      FaultModel_P.LimitaltitudetoStratosphere_Upp) {
    rtb_LimitaltitudetoStratosphere =
      FaultModel_P.LimitaltitudetoStratosphere_Upp;
  } else {
    if (rtb_LimitaltitudetoStratosphere <
        FaultModel_P.LimitaltitudetoStratosphere_Low) {
      rtb_LimitaltitudetoStratosphere =
        FaultModel_P.LimitaltitudetoStratosphere_Low;
    }
  }

  // End of Saturate: '<S70>/Limit  altitude  to Stratosphere'

  // Product: '<S70>/Product3' incorporates:
  //   Gain: '<S70>/g//R'
  //   Gain: '<S70>/rho0'
  //   Math: '<S70>/Stratosphere Model'
  //   Product: '<S70>/Product'
  //   Product: '<S70>/Product1'
  //
  //  About '<S70>/Stratosphere Model':
  //   Operator: exp

  uavlostJxy = rtb_jxi / uavlostJxy * FaultModel_P.rho0_Gain * std::exp(1.0 /
    uavlostJzx * (FaultModel_P.gR_Gain * rtb_LimitaltitudetoStratosphere));

  // Sum: '<S419>/Sum' incorporates:
  //   Product: '<S419>/Product'
  //   Product: '<S419>/Product1'
  //   Product: '<S419>/Product2'
  //   Sum: '<S516>/Sum'
  //   Sum: '<S517>/Sum'

  Z = (rtb_Windb[0] * rtb_Windb[0] + rtb_Windb[1] * rtb_Windb[1]) + rtb_Windb[2]
    * rtb_Windb[2];

  // Gain: '<S403>/1//2rhoV^2' incorporates:
  //   Product: '<S403>/Product2'
  //   Sum: '<S419>/Sum'

  rtb_q2dot = Z * uavlostJxy * FaultModel_P.u2rhoV2_Gain;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
    // Product: '<S410>/Product4' incorporates:
    //   Constant: '<S410>/Constant2'
    //   Gain: '<S400>/Gain5'
    //   UniformRandomNumber: '<S400>/Uniform Random Number'

    FaultModel_B.Product4 = FaultModel_P.Gain5_Gain *
      FaultModel_DW.UniformRandomNumber_NextOutpu_k *
      FaultModel_P.Constant2_Value_c;
  }

  // Sum: '<S400>/Add2' incorporates:
  //   Constant: '<S400>/Constant1'
  //   Product: '<S400>/Product'

  rtb_q3dot = (rtb_q2dot * FaultModel_P.Constant1_Value_j + rtb_Saturation_1) +
    FaultModel_B.Product4;

  // Saturate: '<S412>/Limit  altitude  to troposhere'
  if (rtb_q3dot > FaultModel_P.Limitaltitudetotroposhere_Upp_p) {
    // Product: '<S54>/j x i'
    rtb_jxi = FaultModel_P.Limitaltitudetotroposhere_Upp_p;
  } else if (rtb_q3dot < FaultModel_P.Limitaltitudetotroposhere_Low_f) {
    // Product: '<S54>/j x i'
    rtb_jxi = FaultModel_P.Limitaltitudetotroposhere_Low_f;
  } else {
    // Product: '<S54>/j x i'
    rtb_jxi = rtb_q3dot;
  }

  // End of Saturate: '<S412>/Limit  altitude  to troposhere'

  // Product: '<S54>/j x i' incorporates:
  //   Constant: '<S412>/Sea Level  Temperature'
  //   Gain: '<S412>/Lapse Rate'
  //   Sum: '<S412>/Sum1'

  rtb_jxi = FaultModel_P.SeaLevelTemperature_Value -
    FaultModel_P.LapseRate_Gain_n * rtb_jxi;

  // Saturate: '<S412>/Limit  altitude  to Stratosphere' incorporates:
  //   Gain: '<S412>/1//T0'

  rtb_LimitaltitudetoStratosphere = FaultModel_P.uT0_Gain_a * rtb_jxi;

  // Math: '<S412>/(T//T0)^(g//LR) ' incorporates:
  //   Constant: '<S412>/Constant'

  if ((rtb_LimitaltitudetoStratosphere < 0.0) && (FaultModel_P.Constant_Value_h1
       > std::floor(FaultModel_P.Constant_Value_h1))) {
    // Saturate: '<S412>/Limit  altitude  to Stratosphere'
    rtb_LimitaltitudetoStratosphere = -rt_powd_snf
      (-rtb_LimitaltitudetoStratosphere, FaultModel_P.Constant_Value_h1);
  } else {
    // Saturate: '<S412>/Limit  altitude  to Stratosphere'
    rtb_LimitaltitudetoStratosphere = rt_powd_snf
      (rtb_LimitaltitudetoStratosphere, FaultModel_P.Constant_Value_h1);
  }

  // End of Math: '<S412>/(T//T0)^(g//LR) '

  // Gain: '<S412>/P0'
  Y = FaultModel_P.P0_Gain * rtb_LimitaltitudetoStratosphere;

  // Saturate: '<S412>/Limit  altitude  to Stratosphere' incorporates:
  //   Constant: '<S412>/Altitude of Troposphere'
  //   Sum: '<S412>/Sum'

  rtb_LimitaltitudetoStratosphere = FaultModel_P.AltitudeofTroposphere_Value_k -
    rtb_q3dot;

  // Saturate: '<S412>/Limit  altitude  to Stratosphere'
  if (rtb_LimitaltitudetoStratosphere >
      FaultModel_P.LimitaltitudetoStratosphere_U_k) {
    // Saturate: '<S412>/Limit  altitude  to Stratosphere'
    rtb_LimitaltitudetoStratosphere =
      FaultModel_P.LimitaltitudetoStratosphere_U_k;
  } else {
    if (rtb_LimitaltitudetoStratosphere <
        FaultModel_P.LimitaltitudetoStratosphere_L_m) {
      // Saturate: '<S412>/Limit  altitude  to Stratosphere'
      rtb_LimitaltitudetoStratosphere =
        FaultModel_P.LimitaltitudetoStratosphere_L_m;
    }
  }

  // End of Saturate: '<S412>/Limit  altitude  to Stratosphere'
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[2] == 0) {
    // Gain: '<S400>/Gain7' incorporates:
    //   UniformRandomNumber: '<S400>/Uniform Random Number2'

    FaultModel_B.Gain7 = FaultModel_P.Gain7_Gain *
      FaultModel_DW.UniformRandomNumber2_NextOutput;
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // MATLAB Function: '<S400>/FaultParamsExtract3' incorporates:
    //   Constant: '<S400>/FaultID3'
    //   Inport: '<Root>/inSILInts'

    // MATLAB Function 'OutputPort1/HILSensorMavModel1/Subsystem/FaultParamsExtract3': '<S407>:1' 
    // '<S407>:1:5' if isempty(hFault)
    // '<S407>:1:8' if isempty(fParam)
    // '<S407>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S407>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S407>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S407>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S407>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID3_Value_h) {
        // '<S407>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S407>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S407>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S407>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S407>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S407>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault = true;

      // '<S407>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S407>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam[0], &fParamTmp[0], 20U * sizeof(real_T));
    }

    // MATLAB Function: '<S400>/baro NoiseFun' incorporates:
    //   MATLAB Function: '<S400>/FaultParamsExtract3'

    // '<S407>:1:29' hasFault_baro=hFault;
    // '<S407>:1:30' FaultParam=fParam;
    // MATLAB Function 'OutputPort1/HILSensorMavModel1/Subsystem/baro NoiseFun': '<S417>:1' 
    // '<S417>:1:2' y = 0;
    FaultModel_B.y = 0.0;

    // '<S417>:1:3' y_scale = 1;
    FaultModel_B.y_scale = 1.0;

    // '<S417>:1:5' if isbyroFault
    if (FaultModel_DW.hFault) {
      // '<S417>:1:6' if baroFaultParam(1) == 3
      if (FaultModel_DW.fParam[0] == 3.0) {
        // '<S417>:1:7' y = (0.2+0.8*baroFaultParam(3)) * noise + baroFaultParam(2); 
        FaultModel_B.y = (0.8 * FaultModel_DW.fParam[2] + 0.2) *
          FaultModel_B.Gain7 + FaultModel_DW.fParam[1];
      } else {
        if (FaultModel_DW.fParam[0] == 4.0) {
          // '<S417>:1:8' elseif baroFaultParam(1) == 4
          // '<S417>:1:9' y_scale = baroFaultParam(2);
          FaultModel_B.y_scale = FaultModel_DW.fParam[1];
        }
      }
    }

    // End of MATLAB Function: '<S400>/baro NoiseFun'
  }

  // Product: '<S54>/j x i' incorporates:
  //   Gain: '<S400>/Gain'
  //   Gain: '<S412>/g//R'
  //   Math: '<S412>/Stratosphere Model'
  //   Product: '<S400>/Product4'
  //   Product: '<S412>/Product1'
  //   Product: '<S412>/Product2'
  //   Sum: '<S400>/Sum4'
  //
  //  About '<S412>/Stratosphere Model':
  //   Operator: exp

  rtb_jxi = (std::exp(1.0 / rtb_jxi * (FaultModel_P.gR_Gain_b *
    rtb_LimitaltitudetoStratosphere)) * Y * FaultModel_P.Gain_Gain_nb +
             FaultModel_B.y) * FaultModel_B.y_scale;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
    // Product: '<S411>/Product4' incorporates:
    //   Constant: '<S411>/Constant'
    //   Constant: '<S411>/Constant2'
    //   Gain: '<S400>/Gain9'
    //   Gain: '<S411>/Gain2'
    //   Sum: '<S411>/Sum'
    //   UniformRandomNumber: '<S400>/Uniform Random Number4'

    FaultModel_B.Product4_g = (FaultModel_P.Gain2_Gain_o *
      FaultModel_P.Constant_Value_a + FaultModel_P.Constant2_Value_m) *
      (FaultModel_P.Gain9_Gain * FaultModel_DW.UniformRandomNumber4_NextOutput);
  }

  // UnitConversion: '<S74>/Unit Conversion'
  // Unit Conversion - from: K to: degC
  // Expression: output = (1*input) + (-273.15)
  uavlostJzx += -273.15000000000003;

  // Sum: '<S61>/Sum2' incorporates:
  //   Constant: '<S61>/Constant1'

  uavlostJzx += FaultModel_P.Constant1_Value_gw;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // DataTypeConversion: '<S400>/Data Type Conversion6' incorporates:
    //   Constant: '<S400>/Constant'

    rtb_LimitaltitudetoStratosphere = std::floor(FaultModel_P.Constant_Value_hp);
    if (rtIsNaN(rtb_LimitaltitudetoStratosphere) || rtIsInf
        (rtb_LimitaltitudetoStratosphere)) {
      rtb_LimitaltitudetoStratosphere = 0.0;
    } else {
      rtb_LimitaltitudetoStratosphere = std::fmod
        (rtb_LimitaltitudetoStratosphere, 4.294967296E+9);
    }

    // DataTypeConversion: '<S400>/Data Type Conversion6'
    FaultModel_B.fields_updated = rtb_LimitaltitudetoStratosphere < 0.0 ?
      static_cast<uint32_T>(-static_cast<int32_T>(static_cast<uint32_T>
      (-rtb_LimitaltitudetoStratosphere))) : static_cast<uint32_T>
      (rtb_LimitaltitudetoStratosphere);
  }

  // Outport: '<Root>/MavHILSensor' incorporates:
  //   BusCreator: '<S400>/Bus Creator'
  //   DataTypeConversion: '<S400>/Data Type Conversion2'
  //   DataTypeConversion: '<S400>/Data Type Conversion3'
  //   Product: '<S400>/Product1'
  //   Product: '<S400>/Product2'
  //   Sum: '<S400>/Sum1'
  //   Sum: '<S400>/Sum2'

  FaultModel_Y.MavHILSensor.time_usec = rtb_time_usec;
  FaultModel_Y.MavHILSensor.xacc = static_cast<real32_T>((rtb_Mb_idx_0 +
    FaultModel_B.sf_AccFun.y[0]) * FaultModel_B.sf_AccFun.y_scale[0]);
  FaultModel_Y.MavHILSensor.yacc = static_cast<real32_T>((rtb_Mb_idx_1 +
    FaultModel_B.sf_AccFun.y[1]) * FaultModel_B.sf_AccFun.y_scale[1]);
  FaultModel_Y.MavHILSensor.zacc = static_cast<real32_T>
    ((rtb_TmpSignalConversionAtSFun_1 + FaultModel_B.sf_AccFun.y[2]) *
     FaultModel_B.sf_AccFun.y_scale[2]);
  FaultModel_Y.MavHILSensor.xgyro = static_cast<real32_T>((y +
    FaultModel_B.sf_GyroFun.y[0]) * FaultModel_B.sf_GyroFun.y_scale[0]);
  FaultModel_Y.MavHILSensor.ygyro = static_cast<real32_T>((y_0 +
    FaultModel_B.sf_GyroFun.y[1]) * FaultModel_B.sf_GyroFun.y_scale[1]);

  // Saturate: '<S424>/Saturation'
  if (rtb_wind_idx_0 > FaultModel_P.Saturation_UpperSat_f[2]) {
    rtb_wind_idx_0 = FaultModel_P.Saturation_UpperSat_f[2];
  } else {
    if (rtb_wind_idx_0 < FaultModel_P.Saturation_LowerSat_d[2]) {
      rtb_wind_idx_0 = FaultModel_P.Saturation_LowerSat_d[2];
    }
  }

  // Outport: '<Root>/MavHILSensor' incorporates:
  //   BusCreator: '<S400>/Bus Creator'
  //   DataTypeConversion: '<S400>/Data Type Conversion3'
  //   DataTypeConversion: '<S400>/Data Type Conversion4'
  //   DataTypeConversion: '<S400>/Data Type Conversion5'
  //   Gain: '<S400>/Gain1'
  //   Gain: '<S400>/Gain_Mag'
  //   Gain: '<S400>/nT2Gauss'
  //   Product: '<S400>/Product1'
  //   Product: '<S400>/Product3'
  //   Sum: '<S400>/Sum'
  //   Sum: '<S400>/Sum2'
  //   Sum: '<S400>/Sum3'

  FaultModel_Y.MavHILSensor.zgyro = static_cast<real32_T>((rtb_wind_idx_0 +
    FaultModel_B.sf_GyroFun.y[2]) * FaultModel_B.sf_GyroFun.y_scale[2]);
  FaultModel_Y.MavHILSensor.xmag = static_cast<real32_T>
    ((FaultModel_P.Gain_Mag_Gain * Product1[0] * FaultModel_P.nT2Gauss_Gain +
      FaultModel_B.y_d[0]) * FaultModel_B.y_scale_l[0]);
  FaultModel_Y.MavHILSensor.ymag = static_cast<real32_T>
    ((FaultModel_P.Gain_Mag_Gain * Product1[1] * FaultModel_P.nT2Gauss_Gain +
      FaultModel_B.y_d[1]) * FaultModel_B.y_scale_l[1]);
  FaultModel_Y.MavHILSensor.zmag = static_cast<real32_T>
    ((FaultModel_P.Gain_Mag_Gain * Product1[2] * FaultModel_P.nT2Gauss_Gain +
      FaultModel_B.y_d[2]) * FaultModel_B.y_scale_l[2]);
  FaultModel_Y.MavHILSensor.abs_pressure = static_cast<real32_T>(rtb_jxi);
  FaultModel_Y.MavHILSensor.diff_pressure = static_cast<real32_T>
    (FaultModel_P.Gain1_Gain_p * rtb_q2dot + FaultModel_B.Product4_g);
  FaultModel_Y.MavHILSensor.pressure_alt = static_cast<real32_T>(rtb_q3dot);
  FaultModel_Y.MavHILSensor.temperature = static_cast<real32_T>(uavlostJzx);
  FaultModel_Y.MavHILSensor.fields_updated = FaultModel_B.fields_updated;

  // If: '<S326>/If'
  if (rtmIsMajorTimeStep((&FaultModel_M))) {
    rtAction = static_cast<int8_T>(!(rtb_TmpSignalConversionAtSFun_0 > 0.0));
    FaultModel_DW.If_ActiveSubsystem_m = rtAction;
  } else {
    rtAction = FaultModel_DW.If_ActiveSubsystem_m;
  }

  switch (rtAction) {
   case 0:
    // Outputs for IfAction SubSystem: '<S326>/Positive Trace' incorporates:
    //   ActionPort: '<S333>/Action Port'

    FaultModel_PositiveTrace(rtb_TmpSignalConversionAtSFun_0, VectorConcatenate,
      &FaultModel_B.Merge_f[0], &FaultModel_B.Merge_f[1],
      &FaultModel_P.PositiveTrace_b);

    // End of Outputs for SubSystem: '<S326>/Positive Trace'
    break;

   case 1:
    // Outputs for IfAction SubSystem: '<S326>/Negative Trace' incorporates:
    //   ActionPort: '<S332>/Action Port'

    FaultModel_NegativeTrace(VectorConcatenate, FaultModel_B.Merge_f,
      &FaultModel_DW.NegativeTrace_l, &FaultModel_P.NegativeTrace_l);

    // End of Outputs for SubSystem: '<S326>/Negative Trace'
    break;
  }

  // End of If: '<S326>/If'

  // DataTypeConversion: '<S329>/Data Type Conversion7' incorporates:
  //   Gain: '<S329>/Gain4'

  rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.Gain4_Gain * FaultModel_B.Product
    [0]);
  if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
    rtb_wind_idx_0 = 0.0;
  } else {
    rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 65536.0);
  }

  rtb_LimitaltitudetoStratosphere = rt_roundd_snf(FaultModel_P.Gain4_Gain *
    FaultModel_B.Product[1]);
  if (rtIsNaN(rtb_LimitaltitudetoStratosphere) || rtIsInf
      (rtb_LimitaltitudetoStratosphere)) {
    rtb_LimitaltitudetoStratosphere = 0.0;
  } else {
    rtb_LimitaltitudetoStratosphere = std::fmod(rtb_LimitaltitudetoStratosphere,
      65536.0);
  }

  rtb_TmpSignalConversionAtSFun_0 = rt_roundd_snf(FaultModel_P.Gain4_Gain *
    FaultModel_B.Product[2]);
  if (rtIsNaN(rtb_TmpSignalConversionAtSFun_0) || rtIsInf
      (rtb_TmpSignalConversionAtSFun_0)) {
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_0 = std::fmod(rtb_TmpSignalConversionAtSFun_0,
      65536.0);
  }

  // DataTypeConversion: '<S329>/Data Type Conversion9' incorporates:
  //   Gain: '<S329>/Gain2'
  //   Gain: '<S329>/Gain7'
  //   Gain: '<S515>/1//2rhoV^2'
  //   Product: '<S515>/Product2'
  //   Sqrt: '<S329>/Airspeed1'
  //   Sqrt: '<S329>/Sqrt1'

  uavlostJzx = rt_roundd_snf(std::sqrt(Z * uavlostJxy *
    FaultModel_P.u2rhoV2_Gain_a * FaultModel_P.Gain2_Gain_j) *
    FaultModel_P.Gain7_Gain_a);
  if (rtIsNaN(uavlostJzx) || rtIsInf(uavlostJzx)) {
    uavlostJzx = 0.0;
  } else {
    uavlostJzx = std::fmod(uavlostJzx, 65536.0);
  }

  rtb_jxi = rt_roundd_snf(std::sqrt(Z) * FaultModel_P.Gain7_Gain_a);
  if (rtIsNaN(rtb_jxi) || rtIsInf(rtb_jxi)) {
    rtb_jxi = 0.0;
  } else {
    rtb_jxi = std::fmod(rtb_jxi, 65536.0);
  }

  // Gain: '<S329>/Gain5'
  rtb_Mb_idx_0 *= FaultModel_P.Gain5_Gain_p;
  rtb_Mb_idx_1 *= FaultModel_P.Gain5_Gain_p;

  // DataTypeConversion: '<S329>/Data Type Conversion8' incorporates:
  //   Gain: '<S329>/Gain5'

  rtb_Mb_idx_0 = rt_roundd_snf(rtb_Mb_idx_0);
  if (rtIsNaN(rtb_Mb_idx_0) || rtIsInf(rtb_Mb_idx_0)) {
    rtb_Mb_idx_0 = 0.0;
  } else {
    rtb_Mb_idx_0 = std::fmod(rtb_Mb_idx_0, 65536.0);
  }

  rtb_Mb_idx_1 = rt_roundd_snf(rtb_Mb_idx_1);
  if (rtIsNaN(rtb_Mb_idx_1) || rtIsInf(rtb_Mb_idx_1)) {
    rtb_Mb_idx_1 = 0.0;
  } else {
    rtb_Mb_idx_1 = std::fmod(rtb_Mb_idx_1, 65536.0);
  }

  rtb_TmpSignalConversionAtSFun_1 = rt_roundd_snf(FaultModel_P.Gain5_Gain_p *
    rtb_TmpSignalConversionAtSFun_1);
  if (rtIsNaN(rtb_TmpSignalConversionAtSFun_1) || rtIsInf
      (rtb_TmpSignalConversionAtSFun_1)) {
    rtb_TmpSignalConversionAtSFun_1 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_1 = std::fmod(rtb_TmpSignalConversionAtSFun_1,
      65536.0);
  }

  // Outport: '<Root>/MavHILStateQuat' incorporates:
  //   BusCreator: '<S329>/Bus Creator'
  //   DataTypeConversion: '<S329>/Data Type Conversion2'
  //   DataTypeConversion: '<S329>/Data Type Conversion3'
  //   Integrator: '<S12>/p,q,r '

  FaultModel_Y.MavHILStateQuat.time_usec = rtb_time_usec;
  FaultModel_Y.MavHILStateQuat.attitude_quaternion[0] = static_cast<real32_T>
    (FaultModel_B.Merge_f[0]);
  FaultModel_Y.MavHILStateQuat.attitude_quaternion[1] = static_cast<real32_T>
    (FaultModel_B.Merge_f[1]);
  FaultModel_Y.MavHILStateQuat.attitude_quaternion[2] = static_cast<real32_T>
    (FaultModel_B.Merge_f[2]);
  FaultModel_Y.MavHILStateQuat.attitude_quaternion[3] = static_cast<real32_T>
    (FaultModel_B.Merge_f[3]);
  FaultModel_Y.MavHILStateQuat.rollspeed = static_cast<real32_T>
    (FaultModel_X.pqr_CSTATE[0]);
  FaultModel_Y.MavHILStateQuat.pitchspeed = static_cast<real32_T>
    (FaultModel_X.pqr_CSTATE[1]);
  FaultModel_Y.MavHILStateQuat.yawspeed = static_cast<real32_T>
    (FaultModel_X.pqr_CSTATE[2]);

  // DataTypeConversion: '<S329>/Data Type Conversion4' incorporates:
  //   Gain: '<S329>/Gain'

  uavlostJxy = rt_roundd_snf(FaultModel_P.Gain_Gain_b * rtb_uavlostMass);
  if (rtIsNaN(uavlostJxy) || rtIsInf(uavlostJxy)) {
    uavlostJxy = 0.0;
  } else {
    uavlostJxy = std::fmod(uavlostJxy, 4.294967296E+9);
  }

  // Outport: '<Root>/MavHILStateQuat' incorporates:
  //   DataTypeConversion: '<S329>/Data Type Conversion4'

  FaultModel_Y.MavHILStateQuat.lat = uavlostJxy < 0.0 ? -static_cast<int32_T>(
    static_cast<uint32_T>(-uavlostJxy)) : static_cast<int32_T>
    (static_cast<uint32_T>(uavlostJxy));

  // DataTypeConversion: '<S329>/Data Type Conversion1' incorporates:
  //   Gain: '<S329>/Gain1'

  uavlostJxy = rt_roundd_snf(FaultModel_P.Gain1_Gain_kp *
    rtb_TmpSignalConversionAtSFun_2);
  if (rtIsNaN(uavlostJxy) || rtIsInf(uavlostJxy)) {
    uavlostJxy = 0.0;
  } else {
    uavlostJxy = std::fmod(uavlostJxy, 4.294967296E+9);
  }

  // Outport: '<Root>/MavHILStateQuat' incorporates:
  //   DataTypeConversion: '<S329>/Data Type Conversion1'

  FaultModel_Y.MavHILStateQuat.lon = uavlostJxy < 0.0 ? -static_cast<int32_T>(
    static_cast<uint32_T>(-uavlostJxy)) : static_cast<int32_T>
    (static_cast<uint32_T>(uavlostJxy));

  // DataTypeConversion: '<S329>/Data Type Conversion5' incorporates:
  //   Gain: '<S329>/Gain3'

  uavlostJxy = rt_roundd_snf(FaultModel_P.Gain3_Gain * rtb_Saturation_1);
  if (rtIsNaN(uavlostJxy) || rtIsInf(uavlostJxy)) {
    uavlostJxy = 0.0;
  } else {
    uavlostJxy = std::fmod(uavlostJxy, 4.294967296E+9);
  }

  // Outport: '<Root>/MavHILStateQuat' incorporates:
  //   DataTypeConversion: '<S329>/Data Type Conversion5'
  //   DataTypeConversion: '<S329>/Data Type Conversion7'
  //   DataTypeConversion: '<S329>/Data Type Conversion8'
  //   DataTypeConversion: '<S329>/Data Type Conversion9'

  FaultModel_Y.MavHILStateQuat.alt = uavlostJxy < 0.0 ? -static_cast<int32_T>(
    static_cast<uint32_T>(-uavlostJxy)) : static_cast<int32_T>
    (static_cast<uint32_T>(uavlostJxy));
  FaultModel_Y.MavHILStateQuat.vx = static_cast<int16_T>(rtb_wind_idx_0 < 0.0 ?
    static_cast<int32_T>(static_cast<int16_T>(-static_cast<int16_T>(static_cast<
    uint16_T>(-rtb_wind_idx_0)))) : static_cast<int32_T>(static_cast<int16_T>(
    static_cast<uint16_T>(rtb_wind_idx_0))));
  FaultModel_Y.MavHILStateQuat.vy = static_cast<int16_T>
    (rtb_LimitaltitudetoStratosphere < 0.0 ? static_cast<int32_T>
     (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-rtb_LimitaltitudetoStratosphere)))) : static_cast<int32_T>(
      static_cast<int16_T>(static_cast<uint16_T>(rtb_LimitaltitudetoStratosphere))));
  FaultModel_Y.MavHILStateQuat.vz = static_cast<int16_T>
    (rtb_TmpSignalConversionAtSFun_0 < 0.0 ? static_cast<int32_T>
     (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-rtb_TmpSignalConversionAtSFun_0)))) : static_cast<int32_T>(
      static_cast<int16_T>(static_cast<uint16_T>(rtb_TmpSignalConversionAtSFun_0))));
  FaultModel_Y.MavHILStateQuat.ind_airspeed = static_cast<uint16_T>(uavlostJzx <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-uavlostJzx)))) : static_cast<int32_T>
    (static_cast<uint16_T>(uavlostJzx)));
  FaultModel_Y.MavHILStateQuat.true_airspeed = static_cast<uint16_T>(rtb_jxi <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-rtb_jxi)))) : static_cast<int32_T>
    (static_cast<uint16_T>(rtb_jxi)));
  FaultModel_Y.MavHILStateQuat.xacc = static_cast<int16_T>(rtb_Mb_idx_0 < 0.0 ?
    static_cast<int32_T>(static_cast<int16_T>(-static_cast<int16_T>(static_cast<
    uint16_T>(-rtb_Mb_idx_0)))) : static_cast<int32_T>(static_cast<int16_T>(
    static_cast<uint16_T>(rtb_Mb_idx_0))));
  FaultModel_Y.MavHILStateQuat.yacc = static_cast<int16_T>(rtb_Mb_idx_1 < 0.0 ?
    static_cast<int32_T>(static_cast<int16_T>(-static_cast<int16_T>(static_cast<
    uint16_T>(-rtb_Mb_idx_1)))) : static_cast<int32_T>(static_cast<int16_T>(
    static_cast<uint16_T>(rtb_Mb_idx_1))));
  FaultModel_Y.MavHILStateQuat.zacc = static_cast<int16_T>
    (rtb_TmpSignalConversionAtSFun_1 < 0.0 ? static_cast<int32_T>
     (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-rtb_TmpSignalConversionAtSFun_1)))) : static_cast<int32_T>(
      static_cast<int16_T>(static_cast<uint16_T>(rtb_TmpSignalConversionAtSFun_1))));
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[4] == 0) {
    // Gain: '<S327>/BiasGain2' incorporates:
    //   UniformRandomNumber: '<S327>/Uniform Random Number5'

    FaultModel_B.BiasGain2[0] = FaultModel_P.BiasGain2_Gain *
      FaultModel_DW.UniformRandomNumber5_NextOutp_m[0];
    FaultModel_B.BiasGain2[1] = FaultModel_P.BiasGain2_Gain *
      FaultModel_DW.UniformRandomNumber5_NextOutp_m[1];
    FaultModel_B.BiasGain2[2] = FaultModel_P.BiasGain2_Gain *
      FaultModel_DW.UniformRandomNumber5_NextOutp_m[2];
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // MATLAB Function: '<S327>/FaultParamsExtract' incorporates:
    //   Constant: '<S327>/FaultID'
    //   Inport: '<Root>/inSILInts'

    // MATLAB Function 'OutputPort1/HILGPSModel/FaultParamsExtract': '<S372>:1'
    // '<S372>:1:5' if isempty(hFault)
    // '<S372>:1:8' if isempty(fParam)
    // '<S372>:1:12' hFaultTmp=false;
    hFaultTmp = false;

    // '<S372>:1:13' fParamTmp=zeros(20,1);
    std::memset(&fParamTmp[0], 0, 20U * sizeof(real_T));

    // '<S372>:1:14' j=1;
    rtb_Product2_l = 1.0;

    // '<S372>:1:15' for i=1:8
    for (r = 0; r < 8; r++) {
      // '<S372>:1:16' if inInts(i) == FaultID
      if (FaultModel_U.inSILInts[r] == FaultModel_P.FaultID_Value_k) {
        // '<S372>:1:17' hFaultTmp=true;
        hFaultTmp = true;

        // '<S372>:1:18' fParamTmp(2*j-1)=inFloats(2*i-1);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l - 1.0) - 1] =
          inSILFloats[((r + 1) << 1) - 2];

        // '<S372>:1:19' fParamTmp(2*j)=inFloats(2*i);
        fParamTmp[static_cast<int32_T>(2.0 * rtb_Product2_l) - 1] = inSILFloats
          [((r + 1) << 1) - 1];

        // '<S372>:1:20' j=j+1;
        rtb_Product2_l++;
      }
    }

    // '<S372>:1:23' if hFaultTmp
    if (hFaultTmp) {
      // '<S372>:1:24' hFault=hFaultTmp;
      FaultModel_DW.hFault_a = true;

      // '<S372>:1:25' fParamTmp(17:20) = inFloats(17:20);
      fParamTmp[16] = inSILFloats[16];
      fParamTmp[17] = inSILFloats[17];
      fParamTmp[18] = inSILFloats[18];
      fParamTmp[19] = inSILFloats[19];

      // '<S372>:1:26' fParam=fParamTmp;
      std::memcpy(&FaultModel_DW.fParam_h[0], &fParamTmp[0], 20U * sizeof(real_T));
    }

    // MATLAB Function: '<S371>/Acc NoiseFun' incorporates:
    //   MATLAB Function: '<S327>/FaultParamsExtract'

    // '<S372>:1:29' hasFault_GPS=hFault;
    // '<S372>:1:30' FaultParam=fParam;
    // MATLAB Function 'OutputPort1/HILGPSModel/AccNoiseSwitch1/Acc NoiseFun': '<S377>:1' 
    // '<S377>:1:3' y = 0.3*u';
    // '<S377>:1:4' y_scale = [1,1,1];
    FaultModel_B.y_n[0] = 0.3 * FaultModel_B.BiasGain2[0];
    rtb_TmpSignalConversionAtSFun_0 = 1.0;
    FaultModel_B.y_n[1] = 0.3 * FaultModel_B.BiasGain2[1];
    rtb_wind_idx_0 = 1.0;
    FaultModel_B.y_n[2] = 0.3 * FaultModel_B.BiasGain2[2];
    FaultModel_B.alt_p_param = 1.0;

    // '<S377>:1:6' if isAccFault
    if (FaultModel_DW.hFault_a) {
      // '<S377>:1:7' if AccFaultParams(1) == 3
      if (FaultModel_DW.fParam_h[0] == 3.0) {
        // '<S377>:1:8' y = [0.3+0.7*AccFaultParams(3), 0.3+0.7*AccFaultParams(5),0.3+0.7*AccFaultParams(7)] .*u' + [AccFaultParams(2),AccFaultParams(4),AccFaultParams(6)]; 
        FaultModel_B.y_n[0] = (0.7 * FaultModel_DW.fParam_h[2] + 0.3) *
          FaultModel_B.BiasGain2[0] + FaultModel_DW.fParam_h[1];
        FaultModel_B.y_n[1] = (0.7 * FaultModel_DW.fParam_h[4] + 0.3) *
          FaultModel_B.BiasGain2[1] + FaultModel_DW.fParam_h[3];
        FaultModel_B.y_n[2] = (0.7 * FaultModel_DW.fParam_h[6] + 0.3) *
          FaultModel_B.BiasGain2[2] + FaultModel_DW.fParam_h[5];

        //  y = (0.2+0.8*AccFaultParams(2))*u;
      } else {
        if (FaultModel_DW.fParam_h[0] == 4.0) {
          // '<S377>:1:10' elseif AccFaultParams(1) == 4
          // '<S377>:1:11' y_scale = [AccFaultParams(2), AccFaultParams(3), AccFaultParams(4)]; 
          rtb_TmpSignalConversionAtSFun_0 = FaultModel_DW.fParam_h[1];
          rtb_wind_idx_0 = FaultModel_DW.fParam_h[2];
          FaultModel_B.alt_p_param = FaultModel_DW.fParam_h[3];
        }
      }
    }

    // End of MATLAB Function: '<S371>/Acc NoiseFun'

    // MATLAB Function: '<S327>/FaultParamsExtract1'
    // MATLAB Function 'OutputPort1/HILGPSModel/FaultParamsExtract1': '<S373>:1' 
    // '<S373>:1:2' lat_p_param = 1 + lat_param / 1000000;
    FaultModel_B.lat_p_param = rtb_TmpSignalConversionAtSFun_0 / 1.0E+6 + 1.0;

    // '<S373>:1:3' lon_p_param = 1 + lon_param / 1000000;
    FaultModel_B.lon_p_param = rtb_wind_idx_0 / 1.0E+6 + 1.0;

    // '<S373>:1:4' alt_p_param = alt_param;
  }

  // MATLAB Function: '<S11>/ZLimit' incorporates:
  //   Integrator: '<S12>/xe,ye,ze'

  // MATLAB Function 'OutputPort1/ZLimit': '<S331>:1'
  // '<S331>:1:2' Xee=xe;
  rtb_Mb_idx_1 = FaultModel_X.xeyeze_CSTATE[2];

  // '<S331>:1:3' if Xee(3)>zt
  if (FaultModel_X.xeyeze_CSTATE[2] > FaultModel_B.y_k) {
    // '<S331>:1:4' Xee(3)=zt;
    rtb_Mb_idx_1 = FaultModel_B.y_k;
  }

  // End of MATLAB Function: '<S11>/ZLimit'

  // Sum: '<S327>/Sum' incorporates:
  //   Integrator: '<S12>/xe,ye,ze'
  //   Sum: '<S16>/Sum'

  rtb_TmpSignalConversionAtSFun_0 = FaultModel_X.xeyeze_CSTATE[0] +
    FaultModel_B.y_n[0];
  rtb_TmpSignalConversionAtSFun_1 = FaultModel_X.xeyeze_CSTATE[1] +
    FaultModel_B.y_n[1];
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // UnitConversion: '<S395>/Unit Conversion' incorporates:
    //   Constant: '<S374>/ref_rotation'

    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    Y = 0.017453292519943295 * FaultModel_P.FlatEarthtoLLA_psi_b;

    // Trigonometry: '<S380>/SinCos'
    FaultModel_B.SinCos_o1_a = std::sin(Y);

    // Trigonometry: '<S380>/SinCos'
    FaultModel_B.SinCos_o2_g = std::cos(Y);

    // Sum: '<S398>/Sum' incorporates:
    //   Constant: '<S398>/Constant'
    //   Constant: '<S398>/f'

    Y = FaultModel_P.f_Value_i - FaultModel_P.Constant_Value_f;

    // Sqrt: '<S399>/sqrt' incorporates:
    //   Constant: '<S399>/Constant'
    //   Product: '<S399>/Product1'
    //   Sum: '<S399>/Sum1'

    Y = std::sqrt(FaultModel_P.Constant_Value_n0 - Y * Y);

    // Switch: '<S391>/Switch' incorporates:
    //   Abs: '<S391>/Abs'
    //   Bias: '<S391>/Bias'
    //   Bias: '<S391>/Bias1'
    //   Constant: '<S374>/ref_position'
    //   Constant: '<S391>/Constant2'
    //   Constant: '<S392>/Constant'
    //   Math: '<S391>/Math Function1'
    //   RelationalOperator: '<S392>/Compare'

    if (std::abs(FaultModel_P.ModelParam_GPSLatLong[0]) >
        FaultModel_P.CompareToConstant_const_d) {
      rtb_Mb_idx_0 = rt_modd_snf(FaultModel_P.ModelParam_GPSLatLong[0] +
        FaultModel_P.Bias_Bias_l, FaultModel_P.Constant2_Value_f) +
        FaultModel_P.Bias1_Bias_c;
    } else {
      rtb_Mb_idx_0 = FaultModel_P.ModelParam_GPSLatLong[0];
    }

    // End of Switch: '<S391>/Switch'

    // Abs: '<S388>/Abs1'
    Z = std::abs(rtb_Mb_idx_0);

    // RelationalOperator: '<S390>/Compare' incorporates:
    //   Constant: '<S390>/Constant'

    hFaultTmp = (Z > FaultModel_P.CompareToConstant_const_l);

    // Switch: '<S388>/Switch'
    if (hFaultTmp) {
      // Signum: '<S388>/Sign1'
      if (rtb_Mb_idx_0 < 0.0) {
        rtb_Mb_idx_0 = -1.0;
      } else if (rtb_Mb_idx_0 > 0.0) {
        rtb_Mb_idx_0 = 1.0;
      } else if (rtb_Mb_idx_0 == 0.0) {
        rtb_Mb_idx_0 = 0.0;
      } else {
        rtb_Mb_idx_0 = (rtNaN);
      }

      // End of Signum: '<S388>/Sign1'

      // Switch: '<S388>/Switch' incorporates:
      //   Bias: '<S388>/Bias'
      //   Bias: '<S388>/Bias1'
      //   Gain: '<S388>/Gain'
      //   Product: '<S388>/Divide1'

      FaultModel_B.Switch_o = ((Z + FaultModel_P.Bias_Bias_m) *
        FaultModel_P.Gain_Gain_m + FaultModel_P.Bias1_Bias_dk) * rtb_Mb_idx_0;
    } else {
      // Switch: '<S388>/Switch'
      FaultModel_B.Switch_o = rtb_Mb_idx_0;
    }

    // End of Switch: '<S388>/Switch'

    // UnitConversion: '<S396>/Unit Conversion'
    // Unit Conversion - from: deg to: rad
    // Expression: output = (0.0174533*input) + (0)
    Z = 0.017453292519943295 * FaultModel_B.Switch_o;

    // Trigonometry: '<S397>/Trigonometric Function1'
    uavlostJxy = std::sin(Z);

    // Product: '<S397>/Product1' incorporates:
    //   Product: '<S394>/Product2'

    rtb_wind_idx_0 = Y * Y;

    // Sum: '<S397>/Sum1' incorporates:
    //   Constant: '<S397>/Constant'
    //   Product: '<S397>/Product1'

    uavlostJxy = FaultModel_P.Constant_Value_dm - rtb_wind_idx_0 * uavlostJxy *
      uavlostJxy;

    // Product: '<S394>/Product1' incorporates:
    //   Constant: '<S394>/Constant1'
    //   Sqrt: '<S394>/sqrt'

    uavlostJzx = FaultModel_P.Constant1_Value_iw / std::sqrt(uavlostJxy);

    // Trigonometry: '<S394>/Trigonometric Function1' incorporates:
    //   Constant: '<S394>/Constant'
    //   Constant: '<S394>/Constant2'
    //   Product: '<S394>/Product3'
    //   Sum: '<S394>/Sum1'

    FaultModel_B.TrigonometricFunction1_f = rt_atan2d_snf
      (FaultModel_P.Constant2_Value_cv, (FaultModel_P.Constant_Value_iy -
        rtb_wind_idx_0) * uavlostJzx / uavlostJxy);

    // Trigonometry: '<S394>/Trigonometric Function2' incorporates:
    //   Constant: '<S394>/Constant3'
    //   Product: '<S394>/Product4'
    //   Trigonometry: '<S394>/Trigonometric Function'

    FaultModel_B.TrigonometricFunction2_f = rt_atan2d_snf
      (FaultModel_P.Constant3_Value_b, uavlostJzx * std::cos(Z));

    // Switch: '<S379>/Switch1' incorporates:
    //   Constant: '<S379>/Constant'
    //   Constant: '<S379>/Constant1'

    if (hFaultTmp) {
      rtb_wind_idx_0 = FaultModel_P.Constant_Value_i;
    } else {
      rtb_wind_idx_0 = FaultModel_P.Constant1_Value_m;
    }

    // End of Switch: '<S379>/Switch1'

    // Sum: '<S379>/Sum' incorporates:
    //   Constant: '<S374>/ref_position'

    rtb_Mb_idx_0 = rtb_wind_idx_0 + FaultModel_P.ModelParam_GPSLatLong[1];

    // Switch: '<S389>/Switch' incorporates:
    //   Abs: '<S389>/Abs'
    //   Constant: '<S393>/Constant'
    //   RelationalOperator: '<S393>/Compare'

    if (std::abs(rtb_Mb_idx_0) > FaultModel_P.CompareToConstant_const_a) {
      // Switch: '<S389>/Switch' incorporates:
      //   Bias: '<S389>/Bias'
      //   Bias: '<S389>/Bias1'
      //   Constant: '<S389>/Constant2'
      //   Math: '<S389>/Math Function1'

      FaultModel_B.Switch_d4 = rt_modd_snf(rtb_Mb_idx_0 +
        FaultModel_P.Bias_Bias_e, FaultModel_P.Constant2_Value_p) +
        FaultModel_P.Bias1_Bias_k;
    } else {
      // Switch: '<S389>/Switch'
      FaultModel_B.Switch_d4 = rtb_Mb_idx_0;
    }

    // End of Switch: '<S389>/Switch'
  }

  // Sum: '<S374>/Sum' incorporates:
  //   Product: '<S380>/rad lat'
  //   Product: '<S380>/x*cos'
  //   Product: '<S380>/y*sin'
  //   Sum: '<S380>/Sum'
  //   UnitConversion: '<S381>/Unit Conversion'

  // Unit Conversion - from: rad to: deg
  // Expression: output = (57.2958*input) + (0)
  rtb_Product2_l = (rtb_TmpSignalConversionAtSFun_0 * FaultModel_B.SinCos_o2_g -
                    rtb_TmpSignalConversionAtSFun_1 * FaultModel_B.SinCos_o1_a) *
    FaultModel_B.TrigonometricFunction1_f * 57.295779513082323 +
    FaultModel_B.Switch_o;

  // Switch: '<S385>/Switch' incorporates:
  //   Abs: '<S385>/Abs'
  //   Bias: '<S385>/Bias'
  //   Bias: '<S385>/Bias1'
  //   Constant: '<S385>/Constant2'
  //   Constant: '<S386>/Constant'
  //   Math: '<S385>/Math Function1'
  //   RelationalOperator: '<S386>/Compare'

  if (std::abs(rtb_Product2_l) > FaultModel_P.CompareToConstant_const_k3) {
    uavlostJzx = rt_modd_snf(rtb_Product2_l + FaultModel_P.Bias_Bias_i,
      FaultModel_P.Constant2_Value_a) + FaultModel_P.Bias1_Bias_n;
  } else {
    uavlostJzx = rtb_Product2_l;
  }

  // End of Switch: '<S385>/Switch'

  // Abs: '<S382>/Abs1'
  rtb_Mb_idx_0 = std::abs(uavlostJzx);

  // RelationalOperator: '<S384>/Compare' incorporates:
  //   Constant: '<S384>/Constant'

  hFaultTmp = (rtb_Mb_idx_0 > FaultModel_P.CompareToConstant_const_dl);

  // Switch: '<S382>/Switch' incorporates:
  //   Bias: '<S382>/Bias'
  //   Bias: '<S382>/Bias1'
  //   Gain: '<S382>/Gain'
  //   Product: '<S382>/Divide1'

  if (hFaultTmp) {
    // Signum: '<S382>/Sign1'
    if (uavlostJzx < 0.0) {
      uavlostJzx = -1.0;
    } else if (uavlostJzx > 0.0) {
      uavlostJzx = 1.0;
    } else if (uavlostJzx == 0.0) {
      uavlostJzx = 0.0;
    } else {
      uavlostJzx = (rtNaN);
    }

    // End of Signum: '<S382>/Sign1'
    uavlostJzx *= (rtb_Mb_idx_0 + FaultModel_P.Bias_Bias_a) *
      FaultModel_P.Gain_Gain_i + FaultModel_P.Bias1_Bias_e;
  }

  // End of Switch: '<S382>/Switch'

  // DataTypeConversion: '<S327>/Data Type Conversion4' incorporates:
  //   Gain: '<S327>/latScale'
  //   Product: '<S327>/Product'

  rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.latScale_Gain * uavlostJzx *
    FaultModel_B.lat_p_param);
  if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
    rtb_wind_idx_0 = 0.0;
  } else {
    rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 4.294967296E+9);
  }

  r = rtb_wind_idx_0 < 0.0 ? -static_cast<int32_T>(static_cast<uint32_T>
    (-rtb_wind_idx_0)) : static_cast<int32_T>(static_cast<uint32_T>
    (rtb_wind_idx_0));

  // End of DataTypeConversion: '<S327>/Data Type Conversion4'

  // Switch: '<S378>/Switch1' incorporates:
  //   Constant: '<S378>/Constant'
  //   Constant: '<S378>/Constant1'

  if (hFaultTmp) {
    rtb_jxi = FaultModel_P.Constant_Value_oo;
  } else {
    rtb_jxi = FaultModel_P.Constant1_Value_gi;
  }

  // End of Switch: '<S378>/Switch1'

  // Sum: '<S378>/Sum' incorporates:
  //   Product: '<S380>/rad long '
  //   Product: '<S380>/x*sin'
  //   Product: '<S380>/y*cos'
  //   Sum: '<S374>/Sum'
  //   Sum: '<S380>/Sum1'
  //   UnitConversion: '<S381>/Unit Conversion'

  uavlostJzx = ((rtb_TmpSignalConversionAtSFun_0 * FaultModel_B.SinCos_o1_a +
                 rtb_TmpSignalConversionAtSFun_1 * FaultModel_B.SinCos_o2_g) *
                FaultModel_B.TrigonometricFunction2_f * 57.295779513082323 +
                FaultModel_B.Switch_d4) + rtb_jxi;

  // Switch: '<S383>/Switch' incorporates:
  //   Abs: '<S383>/Abs'
  //   Bias: '<S383>/Bias'
  //   Bias: '<S383>/Bias1'
  //   Constant: '<S383>/Constant2'
  //   Constant: '<S387>/Constant'
  //   Math: '<S383>/Math Function1'
  //   RelationalOperator: '<S387>/Compare'

  if (std::abs(uavlostJzx) > FaultModel_P.CompareToConstant_const_lc) {
    uavlostJzx = rt_modd_snf(uavlostJzx + FaultModel_P.Bias_Bias_gc,
      FaultModel_P.Constant2_Value_ot) + FaultModel_P.Bias1_Bias_jx;
  }

  // End of Switch: '<S383>/Switch'

  // DataTypeConversion: '<S327>/Data Type Conversion5' incorporates:
  //   Gain: '<S327>/lonScale'
  //   Product: '<S327>/Product1'

  rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.lonScale_Gain * uavlostJzx *
    FaultModel_B.lon_p_param);
  if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
    rtb_wind_idx_0 = 0.0;
  } else {
    rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 4.294967296E+9);
  }

  b_t = rtb_wind_idx_0 < 0.0 ? -static_cast<int32_T>(static_cast<uint32_T>
    (-rtb_wind_idx_0)) : static_cast<int32_T>(static_cast<uint32_T>
    (rtb_wind_idx_0));

  // End of DataTypeConversion: '<S327>/Data Type Conversion5'

  // Sum: '<S374>/Sum1' incorporates:
  //   Constant: '<S327>/ModelParam.envAltitude'
  //   Sum: '<S327>/Sum'
  //   UnaryMinus: '<S374>/Ze2height'

  rtb_LimitaltitudetoStratosphere = -(rtb_Mb_idx_1 + FaultModel_B.y_n[2]) -
    FaultModel_P.ModelParam_envAltitude;

  // Saturate: '<S327>/Saturation'
  if (rtb_LimitaltitudetoStratosphere > FaultModel_P.Saturation_UpperSat_d) {
    rtb_LimitaltitudetoStratosphere = FaultModel_P.Saturation_UpperSat_d;
  } else {
    if (rtb_LimitaltitudetoStratosphere < FaultModel_P.Saturation_LowerSat_p) {
      rtb_LimitaltitudetoStratosphere = FaultModel_P.Saturation_LowerSat_p;
    }
  }

  // End of Saturate: '<S327>/Saturation'

  // DataTypeConversion: '<S327>/Data Type Conversion6' incorporates:
  //   Gain: '<S327>/altScale'
  //   Product: '<S327>/Product2'

  rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.altScale_Gain *
    rtb_LimitaltitudetoStratosphere * FaultModel_B.alt_p_param);
  if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
    rtb_wind_idx_0 = 0.0;
  } else {
    rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 4.294967296E+9);
  }

  rtb_alt = rtb_wind_idx_0 < 0.0 ? -static_cast<int32_T>(static_cast<uint32_T>
    (-rtb_wind_idx_0)) : static_cast<int32_T>(static_cast<uint32_T>
    (rtb_wind_idx_0));

  // End of DataTypeConversion: '<S327>/Data Type Conversion6'
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // DataTypeConversion: '<S327>/Data Type Conversion8' incorporates:
    //   Constant: '<S327>/ModelParam.GPSEphFinal'
    //   Gain: '<S327>/Gain6'

    rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.Gain6_Gain_i *
      FaultModel_P.ModelParam_GPSEphFinal);
    if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
      rtb_wind_idx_0 = 0.0;
    } else {
      rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 65536.0);
    }

    // DataTypeConversion: '<S327>/Data Type Conversion8'
    FaultModel_B.eph = static_cast<uint16_T>(rtb_wind_idx_0 < 0.0 ? static_cast<
      int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
      (-rtb_wind_idx_0)))) : static_cast<int32_T>(static_cast<uint16_T>
      (rtb_wind_idx_0)));

    // DataTypeConversion: '<S327>/Data Type Conversion9' incorporates:
    //   Constant: '<S327>/ModelParam.GPSEpvFinal'
    //   Gain: '<S327>/Gain8'

    rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.Gain8_Gain *
      FaultModel_P.ModelParam_GPSEpvFinal);
    if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
      rtb_wind_idx_0 = 0.0;
    } else {
      rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 65536.0);
    }

    // DataTypeConversion: '<S327>/Data Type Conversion9'
    FaultModel_B.epv = static_cast<uint16_T>(rtb_wind_idx_0 < 0.0 ? static_cast<
      int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
      (-rtb_wind_idx_0)))) : static_cast<int32_T>(static_cast<uint16_T>
      (rtb_wind_idx_0)));
  }

  // Sum: '<S327>/Sum3' incorporates:
  //   TransferFcn: '<S376>/Transfer Fcn1'
  //   TransferFcn: '<S376>/Transfer Fcn4'

  rtb_TmpSignalConversionAtSFun_0 = FaultModel_P.TransferFcn4_C *
    FaultModel_X.TransferFcn4_CSTATE + FaultModel_B.Product[0];
  rtb_TmpSignalConversionAtSFun_1 = FaultModel_P.TransferFcn1_C *
    FaultModel_X.TransferFcn1_CSTATE + FaultModel_B.Product[1];

  // MATLAB Function: '<S327>/GenCogVel'
  // MATLAB Function 'OutputPort1/HILGPSModel/GenCogVel': '<S375>:1'
  // '<S375>:1:2' v=norm(u(1:2));
  Y = 3.3121686421112381E-170;
  Z = std::abs(rtb_TmpSignalConversionAtSFun_0);
  if (Z > 3.3121686421112381E-170) {
    rtb_Mb_idx_0 = 1.0;
    Y = Z;
  } else {
    uavlostJzx = Z / 3.3121686421112381E-170;
    rtb_Mb_idx_0 = uavlostJzx * uavlostJzx;
  }

  Z = std::abs(rtb_TmpSignalConversionAtSFun_1);
  if (Z > Y) {
    uavlostJzx = Y / Z;
    rtb_Mb_idx_0 = rtb_Mb_idx_0 * uavlostJzx * uavlostJzx + 1.0;
    Y = Z;
  } else {
    uavlostJzx = Z / Y;
    rtb_Mb_idx_0 += uavlostJzx * uavlostJzx;
  }

  rtb_Mb_idx_0 = Y * std::sqrt(rtb_Mb_idx_0);

  // '<S375>:1:4' if v < 1
  if (rtb_Mb_idx_0 < 1.0) {
    // '<S375>:1:5' cot = 0;
    Y = 0.0;
  } else {
    // '<S375>:1:6' else
    // '<S375>:1:7' cot=atan2d(u(2),u(1));
    Y = 57.295779513082323 * rt_atan2d_snf(rtb_TmpSignalConversionAtSFun_1,
      rtb_TmpSignalConversionAtSFun_0);
  }

  // '<S375>:1:10' if cot<0
  if (Y < 0.0) {
    // '<S375>:1:11' cot=cot+360;
    Y += 360.0;
  }

  // DataTypeConversion: '<S327>/Data Type Conversion3' incorporates:
  //   Gain: '<S327>/VeScale'
  //   Sum: '<S327>/Sum3'
  //   TransferFcn: '<S376>/Transfer Fcn2'

  rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.VeScale_Gain *
    rtb_TmpSignalConversionAtSFun_0);
  if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
    rtb_wind_idx_0 = 0.0;
  } else {
    rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 65536.0);
  }

  rtb_LimitaltitudetoStratosphere = rt_roundd_snf(FaultModel_P.VeScale_Gain *
    rtb_TmpSignalConversionAtSFun_1);
  if (rtIsNaN(rtb_LimitaltitudetoStratosphere) || rtIsInf
      (rtb_LimitaltitudetoStratosphere)) {
    rtb_LimitaltitudetoStratosphere = 0.0;
  } else {
    rtb_LimitaltitudetoStratosphere = std::fmod(rtb_LimitaltitudetoStratosphere,
      65536.0);
  }

  rtb_TmpSignalConversionAtSFun_0 = rt_roundd_snf((FaultModel_P.TransferFcn2_C *
    FaultModel_X.TransferFcn2_CSTATE + FaultModel_B.Product[2]) *
    FaultModel_P.VeScale_Gain);
  if (rtIsNaN(rtb_TmpSignalConversionAtSFun_0) || rtIsInf
      (rtb_TmpSignalConversionAtSFun_0)) {
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_0 = std::fmod(rtb_TmpSignalConversionAtSFun_0,
      65536.0);
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // DataTypeConversion: '<S327>/Data Type Conversion10' incorporates:
    //   Constant: '<S327>/ModelParam_GPSFix3DFix'

    uavlostJzx = rt_roundd_snf(FaultModel_P.ModelParam_GPSFix3DFix);
    if (rtIsNaN(uavlostJzx) || rtIsInf(uavlostJzx)) {
      uavlostJzx = 0.0;
    } else {
      uavlostJzx = std::fmod(uavlostJzx, 256.0);
    }

    // DataTypeConversion: '<S327>/Data Type Conversion10'
    FaultModel_B.fix_type = static_cast<uint8_T>(uavlostJzx < 0.0 ?
      static_cast<int32_T>(static_cast<uint8_T>(-static_cast<int8_T>(
      static_cast<uint8_T>(-uavlostJzx)))) : static_cast<int32_T>
      (static_cast<uint8_T>(uavlostJzx)));

    // DataTypeConversion: '<S327>/Data Type Conversion11' incorporates:
    //   Constant: '<S327>/ModelParam.GPSSatsVisible'

    uavlostJzx = rt_roundd_snf(FaultModel_P.ModelParam_GPSSatsVisible);
    if (rtIsNaN(uavlostJzx) || rtIsInf(uavlostJzx)) {
      uavlostJzx = 0.0;
    } else {
      uavlostJzx = std::fmod(uavlostJzx, 256.0);
    }

    // DataTypeConversion: '<S327>/Data Type Conversion11'
    FaultModel_B.satellites_visible = static_cast<uint8_T>(uavlostJzx < 0.0 ?
      static_cast<int32_T>(static_cast<uint8_T>(-static_cast<int8_T>(
      static_cast<uint8_T>(-uavlostJzx)))) : static_cast<int32_T>(static_cast<
      uint8_T>(uavlostJzx)));
  }

  // Outport: '<Root>/MavHILGPS' incorporates:
  //   BusCreator: '<S327>/Bus Creator'

  FaultModel_Y.MavHILGPS.time_usec = rtb_time_usec;
  FaultModel_Y.MavHILGPS.lat = r;
  FaultModel_Y.MavHILGPS.lon = b_t;
  FaultModel_Y.MavHILGPS.alt = rtb_alt;
  FaultModel_Y.MavHILGPS.eph = FaultModel_B.eph;
  FaultModel_Y.MavHILGPS.epv = FaultModel_B.epv;

  // DataTypeConversion: '<S327>/Data Type Conversion2' incorporates:
  //   Gain: '<S327>/VelScale'
  //   MATLAB Function: '<S327>/GenCogVel'

  uavlostJzx = rt_roundd_snf(FaultModel_P.VelScale_Gain * rtb_Mb_idx_0);
  if (rtIsNaN(uavlostJzx) || rtIsInf(uavlostJzx)) {
    uavlostJzx = 0.0;
  } else {
    uavlostJzx = std::fmod(uavlostJzx, 65536.0);
  }

  // Outport: '<Root>/MavHILGPS' incorporates:
  //   DataTypeConversion: '<S327>/Data Type Conversion2'
  //   DataTypeConversion: '<S327>/Data Type Conversion3'

  FaultModel_Y.MavHILGPS.vel = static_cast<uint16_T>(uavlostJzx < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-uavlostJzx)))) : static_cast<int32_T>
    (static_cast<uint16_T>(uavlostJzx)));
  FaultModel_Y.MavHILGPS.vn = static_cast<int16_T>(rtb_wind_idx_0 < 0.0 ?
    static_cast<int32_T>(static_cast<int16_T>(-static_cast<int16_T>
    (static_cast<uint16_T>(-rtb_wind_idx_0)))) : static_cast<int32_T>(
    static_cast<int16_T>(static_cast<uint16_T>(rtb_wind_idx_0))));
  FaultModel_Y.MavHILGPS.ve = static_cast<int16_T>
    (rtb_LimitaltitudetoStratosphere < 0.0 ? static_cast<int32_T>
     (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-rtb_LimitaltitudetoStratosphere)))) : static_cast<int32_T>(
      static_cast<int16_T>(static_cast<uint16_T>(rtb_LimitaltitudetoStratosphere))));
  FaultModel_Y.MavHILGPS.vd = static_cast<int16_T>
    (rtb_TmpSignalConversionAtSFun_0 < 0.0 ? static_cast<int32_T>
     (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-rtb_TmpSignalConversionAtSFun_0)))) : static_cast<int32_T>(
      static_cast<int16_T>(static_cast<uint16_T>(rtb_TmpSignalConversionAtSFun_0))));

  // DataTypeConversion: '<S327>/Data Type Conversion7' incorporates:
  //   Gain: '<S327>/AngleScale'
  //   MATLAB Function: '<S327>/GenCogVel'

  rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.AngleScale_Gain * Y);
  if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
    rtb_wind_idx_0 = 0.0;
  } else {
    rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 65536.0);
  }

  // Outport: '<Root>/MavHILGPS' incorporates:
  //   BusCreator: '<S327>/Bus Creator'
  //   DataTypeConversion: '<S327>/Data Type Conversion7'

  FaultModel_Y.MavHILGPS.cog = static_cast<uint16_T>(rtb_wind_idx_0 < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-rtb_wind_idx_0)))) : static_cast<int32_T>(
    static_cast<uint16_T>(rtb_wind_idx_0)));
  FaultModel_Y.MavHILGPS.fix_type = FaultModel_B.fix_type;
  FaultModel_Y.MavHILGPS.satellites_visible = FaultModel_B.satellites_visible;
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // DataTypeConversion: '<S327>/Data Type Conversion14' incorporates:
    //   Constant: '<S327>/ModelParam.GPSEphFinal'
    //   Gain: '<S327>/Gain1'

    rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.Gain1_Gain_c *
      FaultModel_P.ModelParam_GPSEphFinal);
    if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
      rtb_wind_idx_0 = 0.0;
    } else {
      rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 4.294967296E+9);
    }

    // DataTypeConversion: '<S327>/Data Type Conversion14'
    FaultModel_B.hAcc = rtb_wind_idx_0 < 0.0 ? static_cast<uint32_T>(-
      static_cast<int32_T>(static_cast<uint32_T>(-rtb_wind_idx_0))) :
      static_cast<uint32_T>(rtb_wind_idx_0);

    // DataTypeConversion: '<S327>/Data Type Conversion15' incorporates:
    //   Constant: '<S327>/ModelParam.GPSEpvFinal'
    //   Gain: '<S327>/Gain3'

    rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.Gain3_Gain_l *
      FaultModel_P.ModelParam_GPSEpvFinal);
    if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
      rtb_wind_idx_0 = 0.0;
    } else {
      rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 4.294967296E+9);
    }

    // DataTypeConversion: '<S327>/Data Type Conversion15'
    FaultModel_B.vAcc = rtb_wind_idx_0 < 0.0 ? static_cast<uint32_T>(-
      static_cast<int32_T>(static_cast<uint32_T>(-rtb_wind_idx_0))) :
      static_cast<uint32_T>(rtb_wind_idx_0);
  }

  // DataTypeConversion: '<S327>/Data Type Conversion1' incorporates:
  //   Gain: '<S327>/VeScale1'

  rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.VeScale1_Gain *
    FaultModel_B.Product[0]);
  if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
    rtb_wind_idx_0 = 0.0;
  } else {
    rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 4.294967296E+9);
  }

  rtb_LimitaltitudetoStratosphere = rt_roundd_snf(FaultModel_P.VeScale1_Gain *
    FaultModel_B.Product[1]);
  if (rtIsNaN(rtb_LimitaltitudetoStratosphere) || rtIsInf
      (rtb_LimitaltitudetoStratosphere)) {
    rtb_LimitaltitudetoStratosphere = 0.0;
  } else {
    rtb_LimitaltitudetoStratosphere = std::fmod(rtb_LimitaltitudetoStratosphere,
      4.294967296E+9);
  }

  rtb_TmpSignalConversionAtSFun_0 = rt_roundd_snf(FaultModel_P.VeScale1_Gain *
    FaultModel_B.Product[2]);
  if (rtIsNaN(rtb_TmpSignalConversionAtSFun_0) || rtIsInf
      (rtb_TmpSignalConversionAtSFun_0)) {
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_0 = std::fmod(rtb_TmpSignalConversionAtSFun_0,
      4.294967296E+9);
  }

  // MATLAB Function: '<S327>/-pi-pi---->0-2pi'
  // //rad
  // MATLAB Function 'OutputPort1/HILGPSModel/-pi-pi---->0-2pi': '<S370>:1'
  // '<S370>:1:3' if yaw180>0
  if (VectorConcatenate_n_idx_0 > 0.0) {
    // '<S370>:1:4' yaw360 = yaw180;
    Z = VectorConcatenate_n_idx_0;
  } else {
    // '<S370>:1:5' else
    // '<S370>:1:6' yaw360 = yaw180 +2*pi;
    Z = VectorConcatenate_n_idx_0 + 6.2831853071795862;
  }

  // End of MATLAB Function: '<S327>/-pi-pi---->0-2pi'

  // Outport: '<Root>/PXIHILGPSData' incorporates:
  //   BusCreator: '<S327>/Bus Creator1'
  //   DataTypeConversion: '<S327>/Data Type Conversion1'

  FaultModel_Y.PXIHILGPSData.fix_type = FaultModel_B.fix_type;
  FaultModel_Y.PXIHILGPSData.satellites_visible =
    FaultModel_B.satellites_visible;
  FaultModel_Y.PXIHILGPSData.lat = r;
  FaultModel_Y.PXIHILGPSData.lon = b_t;
  FaultModel_Y.PXIHILGPSData.alt = rtb_alt;
  FaultModel_Y.PXIHILGPSData.hAcc = FaultModel_B.hAcc;
  FaultModel_Y.PXIHILGPSData.vAcc = FaultModel_B.vAcc;
  FaultModel_Y.PXIHILGPSData.velN = rtb_wind_idx_0 < 0.0 ? -static_cast<int32_T>
    (static_cast<uint32_T>(-rtb_wind_idx_0)) : static_cast<int32_T>
    (static_cast<uint32_T>(rtb_wind_idx_0));
  FaultModel_Y.PXIHILGPSData.velE = rtb_LimitaltitudetoStratosphere < 0.0 ? -
    static_cast<int32_T>(static_cast<uint32_T>(-rtb_LimitaltitudetoStratosphere))
    : static_cast<int32_T>(static_cast<uint32_T>(rtb_LimitaltitudetoStratosphere));
  FaultModel_Y.PXIHILGPSData.velD = rtb_TmpSignalConversionAtSFun_0 < 0.0 ? -
    static_cast<int32_T>(static_cast<uint32_T>(-rtb_TmpSignalConversionAtSFun_0))
    : static_cast<int32_T>(static_cast<uint32_T>(rtb_TmpSignalConversionAtSFun_0));

  // DataTypeConversion: '<S327>/Data Type Conversion12' incorporates:
  //   Gain: '<S327>/VelScale1'
  //   MATLAB Function: '<S327>/GenCogVel'

  rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.VelScale1_Gain * rtb_Mb_idx_0);
  if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
    rtb_wind_idx_0 = 0.0;
  } else {
    rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 4.294967296E+9);
  }

  // Outport: '<Root>/PXIHILGPSData' incorporates:
  //   DataTypeConversion: '<S327>/Data Type Conversion12'

  FaultModel_Y.PXIHILGPSData.gSpeed = rtb_wind_idx_0 < 0.0 ?
    -static_cast<int32_T>(static_cast<uint32_T>(-rtb_wind_idx_0)) : static_cast<
    int32_T>(static_cast<uint32_T>(rtb_wind_idx_0));

  // DataTypeConversion: '<S327>/Data Type Conversion13' incorporates:
  //   Gain: '<S327>/headMotAngle'
  //   MATLAB Function: '<S327>/GenCogVel'

  rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.headMotAngle_Gain * Y);
  if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
    rtb_wind_idx_0 = 0.0;
  } else {
    rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 4.294967296E+9);
  }

  // Outport: '<Root>/PXIHILGPSData' incorporates:
  //   DataTypeConversion: '<S327>/Data Type Conversion13'

  FaultModel_Y.PXIHILGPSData.headMot = rtb_wind_idx_0 < 0.0 ?
    -static_cast<int32_T>(static_cast<uint32_T>(-rtb_wind_idx_0)) : static_cast<
    int32_T>(static_cast<uint32_T>(rtb_wind_idx_0));

  // DataTypeConversion: '<S327>/Data Type Conversion16' incorporates:
  //   Gain: '<S327>/headVehAngleScale'

  rtb_wind_idx_0 = rt_roundd_snf(FaultModel_P.headVehAngleScale_Gain * Z);
  if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
    rtb_wind_idx_0 = 0.0;
  } else {
    rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 4.294967296E+9);
  }

  // Outport: '<Root>/PXIHILGPSData' incorporates:
  //   DataTypeConversion: '<S327>/Data Type Conversion16'

  FaultModel_Y.PXIHILGPSData.headVeh = rtb_wind_idx_0 < 0.0 ? -static_cast<
    int32_T>(static_cast<uint32_T>(-rtb_wind_idx_0)) : static_cast<int32_T>(
    static_cast<uint32_T>(rtb_wind_idx_0));

  // Gain: '<S400>/magDecGain'
  uavlostJyz *= FaultModel_P.magDecGain_Gain;

  // DataTypeConversion: '<S400>/Data Type Conversion1'
  rtb_wind_idx_0 = std::floor(uavlostJyz);
  if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
    rtb_wind_idx_0 = 0.0;
  } else {
    rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 65536.0);
  }

  // Outport: '<Root>/magDec' incorporates:
  //   DataTypeConversion: '<S400>/Data Type Conversion1'

  FaultModel_Y.magDec = static_cast<int16_T>(rtb_wind_idx_0 < 0.0 ? static_cast<
    int32_T>(static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
    (-rtb_wind_idx_0)))) : static_cast<int32_T>(static_cast<int16_T>(
    static_cast<uint16_T>(rtb_wind_idx_0))));

  // Outport: '<Root>/SysTime'
  FaultModel_Y.SysTime = rtb_time_usec;

  // Outport: '<Root>/VelE'
  FaultModel_Y.VelE[0] = FaultModel_B.Product[0];

  // Outport: '<Root>/PosE' incorporates:
  //   Integrator: '<S12>/xe,ye,ze'

  FaultModel_Y.PosE[0] = FaultModel_X.xeyeze_CSTATE[0];

  // Outport: '<Root>/VelE'
  FaultModel_Y.VelE[1] = FaultModel_B.Product[1];

  // Outport: '<Root>/PosE' incorporates:
  //   Integrator: '<S12>/xe,ye,ze'

  FaultModel_Y.PosE[1] = FaultModel_X.xeyeze_CSTATE[1];

  // Outport: '<Root>/VelE'
  FaultModel_Y.VelE[2] = FaultModel_B.Product[2];

  // Outport: '<Root>/PosE'
  FaultModel_Y.PosE[2] = rtb_Mb_idx_1;

  // Outport: '<Root>/AngEuler'
  FaultModel_Y.AngEuler[0] = VectorConcatenate_n_idx_2;
  FaultModel_Y.AngEuler[1] = VectorConcatenate_n_idx_1;
  FaultModel_Y.AngEuler[2] = VectorConcatenate_n_idx_0;

  // Outport: '<Root>/AngQuatern'
  FaultModel_Y.AngQuatern[0] = FaultModel_B.Merge_f[0];
  FaultModel_Y.AngQuatern[1] = FaultModel_B.Merge_f[1];
  FaultModel_Y.AngQuatern[2] = FaultModel_B.Merge_f[2];
  FaultModel_Y.AngQuatern[3] = FaultModel_B.Merge_f[3];

  // Outport: '<Root>/RateB' incorporates:
  //   Integrator: '<S12>/p,q,r '

  FaultModel_Y.RateB[0] = FaultModel_X.pqr_CSTATE[0];

  // Sum: '<S1>/Sum1'
  rtb_Sum1_ki[0] += FaultModel_B.fm[0];

  // Outport: '<Root>/RateB' incorporates:
  //   Integrator: '<S12>/p,q,r '

  FaultModel_Y.RateB[1] = FaultModel_X.pqr_CSTATE[1];

  // Sum: '<S1>/Sum1'
  rtb_Sum1_ki[1] += FaultModel_B.fm[1];

  // Outport: '<Root>/RateB' incorporates:
  //   Integrator: '<S12>/p,q,r '

  FaultModel_Y.RateB[2] = FaultModel_X.pqr_CSTATE[2];
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Outputs for Iterator SubSystem: '<S51>/For Each Subsystem' incorporates:
    //   ForEach: '<S52>/For Each'

    for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
      // ForEachSliceAssignment generated from: '<S52>/F' incorporates:
      //   ForEachSliceSelector generated from: '<S52>/mdot'
      //   Product: '<S52>/Product'
      //   SignalConversion generated from: '<S51>/For Each Subsystem'

      rtb_MatrixMultiply2[0] = 0.0;
      rtb_MatrixMultiply2[1] = 0.0;
      rtb_MatrixMultiply2[2] = 0.0;
    }

    // End of Outputs for SubSystem: '<S51>/For Each Subsystem'

    // Sum: '<S51>/Sum of Elements'
    FaultModel_B.SumofElements[0] = 0.0;
    FaultModel_B.SumofElements[1] = 0.0;
    FaultModel_B.SumofElements[2] = 0.0;
  }

  // Product: '<S54>/j x i' incorporates:
  //   Integrator: '<S12>/p,q,r '
  //   Integrator: '<S12>/ub,vb,wb'

  rtb_jxi = FaultModel_X.ubvbwb_CSTATE[1] * FaultModel_X.pqr_CSTATE[0];

  // Sum: '<S12>/Sum' incorporates:
  //   Integrator: '<S12>/p,q,r '
  //   Integrator: '<S12>/ub,vb,wb'
  //   Product: '<S12>/Product'
  //   Product: '<S53>/i x j'
  //   Product: '<S53>/j x k'
  //   Product: '<S53>/k x i'
  //   Product: '<S54>/i x k'
  //   Product: '<S54>/k x j'
  //   Sum: '<S15>/Sum'
  //   Sum: '<S16>/Sum'
  //   Sum: '<S1>/Sum1'

  FaultModel_B.Sum_p[0] = (rtb_Sum1_ki[0] + FaultModel_B.SumofElements[0]) /
    FaultModel_B.m + (FaultModel_X.ubvbwb_CSTATE[1] * FaultModel_X.pqr_CSTATE[2]
                      - FaultModel_X.ubvbwb_CSTATE[2] * FaultModel_X.pqr_CSTATE
                      [1]);
  FaultModel_B.Sum_p[1] = (rtb_Sum1_ki[1] + FaultModel_B.SumofElements[1]) /
    FaultModel_B.m + (FaultModel_X.ubvbwb_CSTATE[2] * FaultModel_X.pqr_CSTATE[0]
                      - FaultModel_X.ubvbwb_CSTATE[0] * FaultModel_X.pqr_CSTATE
                      [2]);
  FaultModel_B.Sum_p[2] = ((FaultModel_B.fm[2] + rtb_count_m) +
    FaultModel_B.SumofElements[2]) / FaultModel_B.m +
    (FaultModel_X.ubvbwb_CSTATE[0] * FaultModel_X.pqr_CSTATE[1] - rtb_jxi);

  // Outport: '<Root>/AccB'
  FaultModel_Y.AccB[0] = FaultModel_B.Sum_p[0];
  FaultModel_Y.AccB[1] = FaultModel_B.Sum_p[1];
  FaultModel_Y.AccB[2] = FaultModel_B.Sum_p[2];
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // MATLAB Function: '<S11>/Model Fail Assessment' incorporates:
    //   Constant: '<S11>/ModelFailEnable'
    //   Integrator: '<S12>/p,q,r '
    //   Integrator: '<S12>/xe,ye,ze'
    //   SignalConversion generated from: '<S330>/ SFunction '

    // MATLAB Function 'OutputPort1/Model Fail Assessment': '<S330>:1'
    // '<S330>:1:4' if isempty(xTemp)
    // '<S330>:1:9' if isempty(kk)
    // '<S330>:1:14' if isempty(ss)
    // '<S330>:1:18' if ~ModelFailEnable&&(kk<0.5)
    if ((!FaultModel_P.ModelFailEnable) && (FaultModel_DW.kk < 0.5)) {
      // '<S330>:1:19' xTemp=zeros(8,1);
      std::memset(&FaultModel_DW.xTemp[0], 0, sizeof(real_T) << 3U);

      // '<S330>:1:20' kk=0;
      FaultModel_DW.kk = 0.0;

      // '<S330>:1:21' ss=[xe;ang];
      FaultModel_DW.ss[0] = FaultModel_X.xeyeze_CSTATE[0];
      FaultModel_DW.ss[3] = VectorConcatenate_n_idx_2;
      FaultModel_DW.ss[1] = FaultModel_X.xeyeze_CSTATE[1];
      FaultModel_DW.ss[4] = VectorConcatenate_n_idx_1;
      FaultModel_DW.ss[2] = rtb_Mb_idx_1;
      FaultModel_DW.ss[5] = VectorConcatenate_n_idx_0;
    }

    // '<S330>:1:24' if ModelFailEnable&&~landed
    if (FaultModel_P.ModelFailEnable && (rtb_landed == 0)) {
      // '<S330>:1:25' xTemp(1:4,1)=[norm(xe-ss(1:3,1));norm(ve);norm(ang-ss(4:6,1));norm(wb)]; 
      rtb_Sum1_ki[0] = FaultModel_X.xeyeze_CSTATE[0] - FaultModel_DW.ss[0];
      rtb_MatrixMultiply2[0] = VectorConcatenate_n_idx_2 - FaultModel_DW.ss[3];
      rtb_Sum1_ki[1] = FaultModel_X.xeyeze_CSTATE[1] - FaultModel_DW.ss[1];
      rtb_MatrixMultiply2[1] = VectorConcatenate_n_idx_1 - FaultModel_DW.ss[4];
      rtb_Sum1_ki[2] = rtb_Mb_idx_1 - FaultModel_DW.ss[2];
      rtb_MatrixMultiply2[2] = VectorConcatenate_n_idx_0 - FaultModel_DW.ss[5];
      FaultModel_DW.xTemp[0] = FaultModel_norm(rtb_Sum1_ki);
      FaultModel_DW.xTemp[1] = FaultModel_norm(FaultModel_B.Product);
      FaultModel_DW.xTemp[2] = FaultModel_norm(rtb_MatrixMultiply2);
      FaultModel_DW.xTemp[3] = FaultModel_norm(FaultModel_X.pqr_CSTATE);

      // '<S330>:1:26' xTemp(5:8,1)= (xTemp(5:8,1)*kk+xTemp(1:4,1))/(kk+1);
      FaultModel_DW.xTemp[4] = (FaultModel_DW.xTemp[4] * FaultModel_DW.kk +
        FaultModel_DW.xTemp[0]) / (FaultModel_DW.kk + 1.0);
      FaultModel_DW.xTemp[5] = (FaultModel_DW.xTemp[5] * FaultModel_DW.kk +
        FaultModel_DW.xTemp[1]) / (FaultModel_DW.kk + 1.0);
      FaultModel_DW.xTemp[6] = (FaultModel_DW.xTemp[6] * FaultModel_DW.kk +
        FaultModel_DW.xTemp[2]) / (FaultModel_DW.kk + 1.0);
      FaultModel_DW.xTemp[7] = (FaultModel_DW.xTemp[7] * FaultModel_DW.kk +
        FaultModel_DW.xTemp[3]) / (FaultModel_DW.kk + 1.0);

      // '<S330>:1:28' kk=kk+1;
      FaultModel_DW.kk++;
    }

    // Outport: '<Root>/FailInfo' incorporates:
    //   MATLAB Function: '<S11>/Model Fail Assessment'

    // landed = int8(0);
    // '<S330>:1:32' FailInfo=xTemp;
    std::memcpy(&FaultModel_Y.FailInfo[0], &FaultModel_DW.xTemp[0], sizeof
                (real_T) << 3U);

    // Outport: '<Root>/landed'
    FaultModel_Y.landed = rtb_landed;
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
    // Outport: '<Root>/BattCellVoltage'
    FaultModel_Y.BattCellVoltage = hover_current;

    // Outport: '<Root>/BattRemCapacity'
    FaultModel_Y.BattRemCapacity = discharge_capacity;
  }

  // Gain: '<S11>/Gain'
  Memory[0] = FaultModel_P.Gain_Gain_ja *
    FaultModel_B.MotorNonlinearDynamic1.Motor_Dynamics.x;
  Memory[1] = FaultModel_P.Gain_Gain_ja *
    FaultModel_B.MotorNonlinearDynamic2.Motor_Dynamics.x;
  Memory[2] = FaultModel_P.Gain_Gain_ja *
    FaultModel_B.MotorNonlinearDynamic3.Motor_Dynamics.x;
  Memory[3] = FaultModel_P.Gain_Gain_ja *
    FaultModel_B.MotorNonlinearDynamic4.Motor_Dynamics.x;
  Memory[4] = FaultModel_P.Gain_Gain_ja *
    FaultModel_B.MotorNonlinearDynamic5.Motor_Dynamics.x;
  Memory[5] = FaultModel_P.Gain_Gain_ja *
    FaultModel_B.MotorNonlinearDynamic6.Motor_Dynamics.x;
  Memory[6] = FaultModel_P.Gain_Gain_ja *
    FaultModel_B.MotorNonlinearDynamic7.Motor_Dynamics.x;
  Memory[7] = FaultModel_P.Gain_Gain_ja *
    FaultModel_B.MotorNonlinearDynamic8.Motor_Dynamics.x;

  // Outport: '<Root>/MotorRPMS'
  std::memcpy(&FaultModel_Y.MotorRPMS[0], &Memory[0], sizeof(real_T) << 3U);

  // Outport: '<Root>/wind'
  FaultModel_Y.wind[0] = rtb_Wind[0];
  FaultModel_Y.wind[1] = rtb_Wind[1];
  FaultModel_Y.wind[2] = rtb_Wind[2];
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
    //   Constant: '<S11>/CopterID'

    rtb_wind_idx_0 = std::floor(FaultModel_P.CopterID_Value);
    if (rtIsNaN(rtb_wind_idx_0) || rtIsInf(rtb_wind_idx_0)) {
      rtb_wind_idx_0 = 0.0;
    } else {
      rtb_wind_idx_0 = std::fmod(rtb_wind_idx_0, 4.294967296E+9);
    }

    // DataTypeConversion: '<S11>/Data Type Conversion'
    FaultModel_B.copterID = rtb_wind_idx_0 < 0.0 ? -static_cast<int32_T>(
      static_cast<uint32_T>(-rtb_wind_idx_0)) : static_cast<int32_T>(
      static_cast<uint32_T>(rtb_wind_idx_0));

    // DataTypeConversion: '<S11>/Data Type Conversion2' incorporates:
    //   Constant: '<S11>/UAVType'

    FaultModel_B.vehicleType = FaultModel_P.ModelParam_uavType;
  }

  // Outport: '<Root>/MavVehile3DInfo' incorporates:
  //   BusCreator generated from: '<Root>/MavVehile3DInfo'
  //   Clock: '<S11>/Clock1'
  //   DataTypeConversion: '<S11>/Data Type Conversion10'
  //   DataTypeConversion: '<S11>/Data Type Conversion4'
  //   DataTypeConversion: '<S11>/Data Type Conversion5'
  //   DataTypeConversion: '<S11>/Data Type Conversion6'
  //   DataTypeConversion: '<S11>/Data Type Conversion7'
  //   DataTypeConversion: '<S11>/Data Type Conversion8'
  //   DataTypeConversion: '<S11>/Data Type Conversion9'
  //   Integrator: '<S12>/p,q,r '
  //   Integrator: '<S12>/xe,ye,ze'

  FaultModel_Y.MavVehile3DInfo.copterID = FaultModel_B.copterID;
  FaultModel_Y.MavVehile3DInfo.vehicleType = FaultModel_B.vehicleType;
  FaultModel_Y.MavVehile3DInfo.runnedTime = rtb_Clock1_tmp;
  FaultModel_Y.MavVehile3DInfo.VelE[0] = static_cast<real32_T>
    (FaultModel_B.Product[0]);
  FaultModel_Y.MavVehile3DInfo.PosE[0] = static_cast<real32_T>
    (FaultModel_X.xeyeze_CSTATE[0]);
  FaultModel_Y.MavVehile3DInfo.VelE[1] = static_cast<real32_T>
    (FaultModel_B.Product[1]);
  FaultModel_Y.MavVehile3DInfo.PosE[1] = static_cast<real32_T>
    (FaultModel_X.xeyeze_CSTATE[1]);
  FaultModel_Y.MavVehile3DInfo.VelE[2] = static_cast<real32_T>
    (FaultModel_B.Product[2]);
  FaultModel_Y.MavVehile3DInfo.PosE[2] = static_cast<real32_T>(rtb_Mb_idx_1);
  FaultModel_Y.MavVehile3DInfo.AngEuler[0] = static_cast<real32_T>
    (VectorConcatenate_n_idx_2);
  FaultModel_Y.MavVehile3DInfo.AngEuler[1] = static_cast<real32_T>
    (VectorConcatenate_n_idx_1);
  FaultModel_Y.MavVehile3DInfo.AngEuler[2] = static_cast<real32_T>
    (VectorConcatenate_n_idx_0);
  FaultModel_Y.MavVehile3DInfo.AngQuatern[0] = static_cast<real32_T>
    (FaultModel_B.Merge_f[0]);
  FaultModel_Y.MavVehile3DInfo.AngQuatern[1] = static_cast<real32_T>
    (FaultModel_B.Merge_f[1]);
  FaultModel_Y.MavVehile3DInfo.AngQuatern[2] = static_cast<real32_T>
    (FaultModel_B.Merge_f[2]);
  FaultModel_Y.MavVehile3DInfo.AngQuatern[3] = static_cast<real32_T>
    (FaultModel_B.Merge_f[3]);
  for (i = 0; i < 8; i++) {
    FaultModel_Y.MavVehile3DInfo.MotorRPMS[i] = static_cast<real32_T>(Memory[i]);
  }

  FaultModel_Y.MavVehile3DInfo.AccB[0] = static_cast<real32_T>
    (FaultModel_B.Sum_p[0]);
  FaultModel_Y.MavVehile3DInfo.RateB[0] = static_cast<real32_T>
    (FaultModel_X.pqr_CSTATE[0]);
  FaultModel_Y.MavVehile3DInfo.PosGPS[0] = rtb_uavlostMass;
  FaultModel_Y.MavVehile3DInfo.AccB[1] = static_cast<real32_T>
    (FaultModel_B.Sum_p[1]);
  FaultModel_Y.MavVehile3DInfo.RateB[1] = static_cast<real32_T>
    (FaultModel_X.pqr_CSTATE[1]);
  FaultModel_Y.MavVehile3DInfo.PosGPS[1] = rtb_TmpSignalConversionAtSFun_2;
  FaultModel_Y.MavVehile3DInfo.AccB[2] = static_cast<real32_T>
    (FaultModel_B.Sum_p[2]);
  FaultModel_Y.MavVehile3DInfo.RateB[2] = static_cast<real32_T>
    (FaultModel_X.pqr_CSTATE[2]);
  FaultModel_Y.MavVehile3DInfo.PosGPS[2] = rtb_Saturation_1;

  // End of Outport: '<Root>/MavVehile3DInfo'

  // Gain: '<S24>/High Gain Quaternion Normalization' incorporates:
  //   Constant: '<S24>/Constant'
  //   DotProduct: '<S24>/Dot Product'
  //   Integrator: '<S13>/q0 q1 q2 q3'
  //   Sum: '<S24>/Sum'

  uavlostJzx = (FaultModel_P.Constant_Value_hu -
                (((FaultModel_X.q0q1q2q3_CSTATE[0] *
                   FaultModel_X.q0q1q2q3_CSTATE[0] +
                   FaultModel_X.q0q1q2q3_CSTATE[1] *
                   FaultModel_X.q0q1q2q3_CSTATE[1]) +
                  FaultModel_X.q0q1q2q3_CSTATE[2] *
                  FaultModel_X.q0q1q2q3_CSTATE[2]) +
                 FaultModel_X.q0q1q2q3_CSTATE[3] * FaultModel_X.q0q1q2q3_CSTATE
                 [3])) * FaultModel_P.CustomVariableMass6DOFQuaternio;

  // SignalConversion generated from: '<S13>/q0 q1 q2 q3' incorporates:
  //   Fcn: '<S24>/q0dot'
  //   Fcn: '<S24>/q1dot'
  //   Fcn: '<S24>/q2dot'
  //   Fcn: '<S24>/q3dot'
  //   Integrator: '<S12>/p,q,r '
  //   Integrator: '<S13>/q0 q1 q2 q3'

  FaultModel_B.TmpSignalConversionAtq0q1q2q3_c[0] =
    ((FaultModel_X.q0q1q2q3_CSTATE[1] * FaultModel_X.pqr_CSTATE[0] +
      FaultModel_X.q0q1q2q3_CSTATE[2] * FaultModel_X.pqr_CSTATE[1]) +
     FaultModel_X.q0q1q2q3_CSTATE[3] * FaultModel_X.pqr_CSTATE[2]) * -0.5 +
    uavlostJzx * FaultModel_X.q0q1q2q3_CSTATE[0];
  FaultModel_B.TmpSignalConversionAtq0q1q2q3_c[1] =
    ((FaultModel_X.q0q1q2q3_CSTATE[0] * FaultModel_X.pqr_CSTATE[0] +
      FaultModel_X.q0q1q2q3_CSTATE[2] * FaultModel_X.pqr_CSTATE[2]) -
     FaultModel_X.q0q1q2q3_CSTATE[3] * FaultModel_X.pqr_CSTATE[1]) * 0.5 +
    uavlostJzx * FaultModel_X.q0q1q2q3_CSTATE[1];
  FaultModel_B.TmpSignalConversionAtq0q1q2q3_c[2] =
    ((FaultModel_X.q0q1q2q3_CSTATE[0] * FaultModel_X.pqr_CSTATE[1] +
      FaultModel_X.q0q1q2q3_CSTATE[3] * FaultModel_X.pqr_CSTATE[0]) -
     FaultModel_X.q0q1q2q3_CSTATE[1] * FaultModel_X.pqr_CSTATE[2]) * 0.5 +
    uavlostJzx * FaultModel_X.q0q1q2q3_CSTATE[2];
  FaultModel_B.TmpSignalConversionAtq0q1q2q3_c[3] =
    ((FaultModel_X.q0q1q2q3_CSTATE[0] * FaultModel_X.pqr_CSTATE[2] +
      FaultModel_X.q0q1q2q3_CSTATE[1] * FaultModel_X.pqr_CSTATE[1]) -
     FaultModel_X.q0q1q2q3_CSTATE[2] * FaultModel_X.pqr_CSTATE[0]) * 0.5 +
    uavlostJzx * FaultModel_X.q0q1q2q3_CSTATE[3];
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // UnitConversion: '<S83>/Unit Conversion' incorporates:
    //   Constant: '<S62>/Wingspan'

    // Unit Conversion - from: m to: ft
    // Expression: output = (3.28084*input) + (0)
    FaultModel_B.UnitConversion_a = 3.280839895013123 *
      FaultModel_P.DrydenWindTurbulenceModelDisc_f;
  }

  // Outputs for Enabled SubSystem: '<S80>/Hpgw'
  // Constant: '<S80>/Constant1'
  FaultModel_Hpgw(FaultModel_P.DrydenWindTurbulenceModelDisc_m, frac_0,
                  FaultModel_B.sigma_wg_a, rtb_Add, FaultModel_B.Product_n[3],
                  FaultModel_B.UnitConversion_a, &FaultModel_B.Hpgw,
                  &FaultModel_DW.Hpgw, &FaultModel_P.Hpgw);

  // End of Outputs for SubSystem: '<S80>/Hpgw'

  // Outputs for Enabled SubSystem: '<S80>/Hqgw'
  // Constant: '<S80>/Constant2'
  FaultModel_Hqgw(FaultModel_P.DrydenWindTurbulenceModelDisc_m,
                  FaultModel_B.UnitConversion_b, FaultModel_B.Hwgwz.Sum,
                  FaultModel_B.UnitConversion_a, &FaultModel_B.Hqgw,
                  &FaultModel_DW.Hqgw, &FaultModel_P.Hqgw);

  // End of Outputs for SubSystem: '<S80>/Hqgw'

  // Outputs for Enabled SubSystem: '<S80>/Hrgw'
  // Constant: '<S80>/Constant3'
  FaultModel_Hrgw(FaultModel_P.DrydenWindTurbulenceModelDisc_m,
                  FaultModel_B.UnitConversion_b, FaultModel_B.Hvgwz.Sum,
                  FaultModel_B.UnitConversion_a, &FaultModel_B.Hrgw,
                  &FaultModel_DW.Hrgw, &FaultModel_P.Hrgw);

  // End of Outputs for SubSystem: '<S80>/Hrgw'

  // If: '<S85>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' incorporates:
  //   Constant: '<S61>/Constant_DCM'

  if (rtmIsMajorTimeStep((&FaultModel_M))) {
    if (massOb <= 1000.0) {
      rtAction = 0;
    } else if (massOb >= 2000.0) {
      rtAction = 1;
    } else {
      rtAction = 2;
    }

    FaultModel_DW.ifHeightMaxlowaltitudeelseifH_g = rtAction;
  } else {
    rtAction = FaultModel_DW.ifHeightMaxlowaltitudeelseifH_g;
  }

  switch (rtAction) {
   case 0:
    // Outputs for IfAction SubSystem: '<S85>/Low altitude  rates' incorporates:
    //   ActionPort: '<S100>/Action Port'

    FaultModel_Lowaltituderates(FaultModel_P.Constant_DCM_Value,
      FaultModel_B.Hpgw.Sum, FaultModel_B.Hqgw.Sum1, FaultModel_B.Hrgw.Sum1,
      FaultModel_B.UnitConversion_e, rtb_MatrixMultiply2);

    // End of Outputs for SubSystem: '<S85>/Low altitude  rates'
    break;

   case 1:
    break;

   case 2:
    // Outputs for IfAction SubSystem: '<S85>/Interpolate  rates' incorporates:
    //   ActionPort: '<S99>/Action Port'

    FaultModel_Interpolaterates(FaultModel_B.Hpgw.Sum, FaultModel_B.Hqgw.Sum1,
      FaultModel_B.Hrgw.Sum1, FaultModel_P.Constant_DCM_Value,
      FaultModel_B.UnitConversion_e, massOb, rtb_MatrixMultiply2,
      &FaultModel_B.Interpolaterates, &FaultModel_P.Interpolaterates);

    // End of Outputs for SubSystem: '<S85>/Interpolate  rates'
    break;
  }

  // End of If: '<S85>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // UnitConversion: '<S122>/Unit Conversion' incorporates:
    //   Constant: '<S63>/Wingspan'

    // Unit Conversion - from: m to: ft
    // Expression: output = (3.28084*input) + (0)
    FaultModel_B.UnitConversion_ez = 3.280839895013123 *
      FaultModel_P.DrydenWindTurbulenceModelDis_az;
  }

  // Outputs for Enabled SubSystem: '<S119>/Hpgw'
  // Constant: '<S119>/Constant1'
  FaultModel_Hpgw(FaultModel_P.DrydenWindTurbulenceModelDisc_a, rtb_Sum_ik,
                  FaultModel_B.sigma_wg, rtb_count, FaultModel_B.Product_k[3],
                  FaultModel_B.UnitConversion_ez, &FaultModel_B.Hpgw_c,
                  &FaultModel_DW.Hpgw_c, &FaultModel_P.Hpgw_c);

  // End of Outputs for SubSystem: '<S119>/Hpgw'

  // Outputs for Enabled SubSystem: '<S119>/Hqgw'
  // Constant: '<S119>/Constant2'
  FaultModel_Hqgw(FaultModel_P.DrydenWindTurbulenceModelDisc_a,
                  FaultModel_B.UnitConversion, FaultModel_B.Hwgwz_a.Sum,
                  FaultModel_B.UnitConversion_ez, &FaultModel_B.Hqgw_b,
                  &FaultModel_DW.Hqgw_b, &FaultModel_P.Hqgw_b);

  // End of Outputs for SubSystem: '<S119>/Hqgw'

  // Outputs for Enabled SubSystem: '<S119>/Hrgw'
  // Constant: '<S119>/Constant3'
  FaultModel_Hrgw(FaultModel_P.DrydenWindTurbulenceModelDisc_a,
                  FaultModel_B.UnitConversion, FaultModel_B.Hvgwz_p.Sum,
                  FaultModel_B.UnitConversion_ez, &FaultModel_B.Hrgw_g,
                  &FaultModel_DW.Hrgw_g, &FaultModel_P.Hrgw_g);

  // End of Outputs for SubSystem: '<S119>/Hrgw'

  // If: '<S124>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' incorporates:
  //   Constant: '<S61>/Constant_DCM'
  //   UnitConversion: '<S121>/Unit Conversion'

  if (rtmIsMajorTimeStep((&FaultModel_M))) {
    if (massOb <= 1000.0) {
      rtAction = 0;
    } else if (massOb >= 2000.0) {
      rtAction = 1;
    } else {
      rtAction = 2;
    }

    FaultModel_DW.ifHeightMaxlowaltitudeelseifH_i = rtAction;
  } else {
    rtAction = FaultModel_DW.ifHeightMaxlowaltitudeelseifH_i;
  }

  switch (rtAction) {
   case 0:
    // Outputs for IfAction SubSystem: '<S124>/Low altitude  rates' incorporates:
    //   ActionPort: '<S139>/Action Port'

    FaultModel_Lowaltituderates(FaultModel_P.Constant_DCM_Value,
      FaultModel_B.Hpgw_c.Sum, FaultModel_B.Hqgw_b.Sum1,
      FaultModel_B.Hrgw_g.Sum1, FaultModel_B.UnitConversion_h,
      rtb_MatrixMultiply2);

    // End of Outputs for SubSystem: '<S124>/Low altitude  rates'
    break;

   case 1:
    break;

   case 2:
    // Outputs for IfAction SubSystem: '<S124>/Interpolate  rates' incorporates:
    //   ActionPort: '<S138>/Action Port'

    FaultModel_Interpolaterates(FaultModel_B.Hpgw_c.Sum,
      FaultModel_B.Hqgw_b.Sum1, FaultModel_B.Hrgw_g.Sum1,
      FaultModel_P.Constant_DCM_Value, FaultModel_B.UnitConversion_h, massOb,
      rtb_MatrixMultiply2, &FaultModel_B.Interpolaterates_j,
      &FaultModel_P.Interpolaterates_j);

    // End of Outputs for SubSystem: '<S124>/Interpolate  rates'
    break;
  }

  // End of If: '<S124>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // If: '<S202>/If1' incorporates:
    //   Constant: '<S202>/Constant'

    rtAction = -1;
    if (rtmIsMajorTimeStep((&FaultModel_M))) {
      if (FaultModel_P.DirectionCosineMatrixtoQuaterni != 1.0) {
        rtAction = 0;
      }

      FaultModel_DW.If1_ActiveSubsystem = rtAction;
    } else {
      rtAction = FaultModel_DW.If1_ActiveSubsystem;
    }

    if (rtAction == 0) {
      // Outputs for IfAction SubSystem: '<S202>/If Warning//Error' incorporates:
      //   ActionPort: '<S226>/if'

      FaultModel_IfWarningError(VectorConcatenate, &FaultModel_P.IfWarningError,
        FaultModel_P.DirectionCosineMatrixtoQuaterni,
        FaultModel_P.DirectionCosineMatrixtoQuater_i);

      // End of Outputs for SubSystem: '<S202>/If Warning//Error'
    }

    // End of If: '<S202>/If1'

    // If: '<S240>/If1' incorporates:
    //   Constant: '<S240>/Constant'

    rtAction = -1;
    if (rtmIsMajorTimeStep((&FaultModel_M))) {
      if (FaultModel_P.DirectionCosineMatrixtoQuater_p != 1.0) {
        rtAction = 0;
      }

      FaultModel_DW.If1_ActiveSubsystem_o = rtAction;
    } else {
      rtAction = FaultModel_DW.If1_ActiveSubsystem_o;
    }

    if (rtAction == 0) {
      // Outputs for IfAction SubSystem: '<S240>/If Warning//Error' incorporates:
      //   ActionPort: '<S264>/if'

      FaultModel_IfWarningError(VectorConcatenate_p,
        &FaultModel_P.IfWarningError_f,
        FaultModel_P.DirectionCosineMatrixtoQuater_p,
        FaultModel_P.DirectionCosineMatrixtoQuate_i5);

      // End of Outputs for SubSystem: '<S240>/If Warning//Error'
    }

    // End of If: '<S240>/If1'

    // If: '<S334>/If1' incorporates:
    //   Constant: '<S334>/Constant'

    rtAction = -1;
    if (rtmIsMajorTimeStep((&FaultModel_M))) {
      if (FaultModel_P.DirectionCosineMatrixtoQuater_c != 1.0) {
        rtAction = 0;
      }

      FaultModel_DW.If1_ActiveSubsystem_d = rtAction;
    } else {
      rtAction = FaultModel_DW.If1_ActiveSubsystem_d;
    }

    if (rtAction == 0) {
      // Outputs for IfAction SubSystem: '<S334>/If Warning//Error' incorporates:
      //   ActionPort: '<S358>/if'

      FaultModel_IfWarningError(VectorConcatenate,
        &FaultModel_P.IfWarningError_a,
        FaultModel_P.DirectionCosineMatrixtoQuater_c,
        FaultModel_P.DirectionCosineMatrixtoQuater_b);

      // End of Outputs for SubSystem: '<S334>/If Warning//Error'
    }

    // End of If: '<S334>/If1'
  }

  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[4] == 0) {
    // Gain: '<S327>/BiasGain1' incorporates:
    //   UniformRandomNumber: '<S327>/Uniform Random Number4'

    FaultModel_B.BiasGain1[0] = FaultModel_P.BiasGain1_Gain *
      FaultModel_DW.UniformRandomNumber4_NextOutp_p[0];
    FaultModel_B.BiasGain1[1] = FaultModel_P.BiasGain1_Gain *
      FaultModel_DW.UniformRandomNumber4_NextOutp_p[1];
    FaultModel_B.BiasGain1[2] = FaultModel_P.BiasGain1_Gain *
      FaultModel_DW.UniformRandomNumber4_NextOutp_p[2];
  }

  // Gain: '<S429>/2*zeta * wn'
  uavlostJyz = 2.0 * FaultModel_P.ThreeaxisInertialMeasurementU_n *
    FaultModel_P.ThreeaxisInertialMeasurementU_e;

  // Gain: '<S429>/wn^2'
  rtb_Clock1_tmp = FaultModel_P.ThreeaxisInertialMeasurementU_e *
    FaultModel_P.ThreeaxisInertialMeasurementU_e;

  // Sum: '<S429>/Sum2' incorporates:
  //   Gain: '<S429>/2*zeta * wn'
  //   Gain: '<S429>/wn^2'
  //   SecondOrderIntegrator: '<S429>/Integrator, Second-Order Limited'
  //   Sum: '<S429>/Sum3'

  FaultModel_B.Sum2[0] = (rtb_sincos_o1[0] -
    FaultModel_X.IntegratorSecondOrderLimited_CS[0]) * rtb_Clock1_tmp -
    uavlostJyz * FaultModel_X.IntegratorSecondOrderLimited_CS[3];
  FaultModel_B.Sum2[1] = (rtb_sincos_o1[1] -
    FaultModel_X.IntegratorSecondOrderLimited_CS[1]) * rtb_Clock1_tmp -
    uavlostJyz * FaultModel_X.IntegratorSecondOrderLimited_CS[4];
  FaultModel_B.Sum2[2] = (rtb_sincos_o1[2] -
    FaultModel_X.IntegratorSecondOrderLimited_CS[2]) * rtb_Clock1_tmp -
    uavlostJyz * FaultModel_X.IntegratorSecondOrderLimited_CS[5];

  // Gain: '<S440>/2*zeta * wn'
  uavlostJyz = 2.0 * FaultModel_P.ThreeaxisInertialMeasurement_jx *
    FaultModel_P.ThreeaxisInertialMeasurementU_m;

  // Gain: '<S440>/wn^2'
  rtb_Clock1_tmp = FaultModel_P.ThreeaxisInertialMeasurementU_m *
    FaultModel_P.ThreeaxisInertialMeasurementU_m;

  // Sum: '<S440>/Sum2' incorporates:
  //   Gain: '<S440>/2*zeta * wn'
  //   Gain: '<S440>/wn^2'
  //   SecondOrderIntegrator: '<S440>/Integrator, Second-Order Limited'
  //   Sum: '<S440>/Sum3'

  FaultModel_B.Sum2_f[0] = (rtb_Fd[0] -
    FaultModel_X.IntegratorSecondOrderLimited__b[0]) * rtb_Clock1_tmp -
    uavlostJyz * FaultModel_X.IntegratorSecondOrderLimited__b[3];
  FaultModel_B.Sum2_f[1] = (rtb_Fd[1] -
    FaultModel_X.IntegratorSecondOrderLimited__b[1]) * rtb_Clock1_tmp -
    uavlostJyz * FaultModel_X.IntegratorSecondOrderLimited__b[4];
  FaultModel_B.Sum2_f[2] = (rtb_Fd[2] -
    FaultModel_X.IntegratorSecondOrderLimited__b[2]) * rtb_Clock1_tmp -
    uavlostJyz * FaultModel_X.IntegratorSecondOrderLimited__b[5];
  if (rtmIsMajorTimeStep((&FaultModel_M)) &&
      (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
    // Assertion: '<S441>/Assertion' incorporates:
    //   Constant: '<S441>/max_val'
    //   Constant: '<S441>/min_val'
    //   Logic: '<S441>/conjunction'
    //   RelationalOperator: '<S441>/max_relop'
    //   RelationalOperator: '<S441>/min_relop'

    utAssert((FaultModel_P.CheckAltitude_min <= rtb_Saturation_1) &&
             (rtb_Saturation_1 <= FaultModel_P.CheckAltitude_max));

    // Assertion: '<S442>/Assertion' incorporates:
    //   Constant: '<S442>/max_val'
    //   Constant: '<S442>/min_val'
    //   Logic: '<S442>/conjunction'
    //   RelationalOperator: '<S442>/max_relop'
    //   RelationalOperator: '<S442>/min_relop'

    utAssert((FaultModel_P.CheckLatitude_min <= rtb_uavlostMass) &&
             (rtb_uavlostMass <= FaultModel_P.CheckLatitude_max));

    // Assertion: '<S443>/Assertion' incorporates:
    //   Constant: '<S443>/max_val'
    //   Constant: '<S443>/min_val'
    //   Logic: '<S443>/conjunction'
    //   RelationalOperator: '<S443>/max_relop'
    //   RelationalOperator: '<S443>/min_relop'

    utAssert((FaultModel_P.CheckLongitude_min <= rtb_TmpSignalConversionAtSFun_2)
             && (rtb_TmpSignalConversionAtSFun_2 <=
                 FaultModel_P.CheckLongitude_max));

    // Assertion: '<S445>/Assertion' incorporates:
    //   Constant: '<S445>/max_val'
    //   Constant: '<S445>/min_val'
    //   Logic: '<S445>/conjunction'
    //   RelationalOperator: '<S445>/max_relop'
    //   RelationalOperator: '<S445>/min_relop'

    utAssert((FaultModel_P.Istimewithinmodellimits_min <= rtb_Sum_os) &&
             (rtb_Sum_os <= FaultModel_P.Istimewithinmodellimits_max));

    // MATLAB Function 'OutputPort1/HILSensorMavModel1/Subsystem/AccelNoiseGainFunction': '<S402>:1' 
    // '<S402>:1:3' if theta>0.1
    // MATLAB Function 'OutputPort1/HILSensorMavModel1/Subsystem/GyroNoiseGainFunction': '<S408>:1' 
    // '<S408>:1:3' if theta>0.1
    // MATLAB Function 'OutputPort1/HILSensorMavModel1/Subsystem/MagNoiseGainFunction': '<S413>:1' 
    // '<S413>:1:3' if theta>0.1
  }

  // Outport: '<Root>/PosGPS' incorporates:
  //   SignalConversion generated from: '<Root>/MavVehile3DInfo'

  FaultModel_Y.PosGPS[0] = rtb_uavlostMass;
  FaultModel_Y.PosGPS[1] = rtb_TmpSignalConversionAtSFun_2;
  FaultModel_Y.PosGPS[2] = rtb_Saturation_1;
  if (rtmIsMajorTimeStep((&FaultModel_M))) {
    // Update for Integrator: '<S13>/q0 q1 q2 q3'
    FaultModel_DW.q0q1q2q3_IWORK = 0;
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
      // Update for Memory: '<Root>/Memory' incorporates:
      //   Inport: '<Root>/inPWMs'

      std::memcpy(&FaultModel_DW.Memory_PreviousInput[0], &FaultModel_U.inPWMs[0],
                  sizeof(real_T) << 3U);
    }

    // Update for Atomic SubSystem: '<S300>/MotorNonlinearDynamic1'
    F_MotorNonlinearDynamic1_Update(&FaultModel_DW.MotorNonlinearDynamic1);

    // End of Update for SubSystem: '<S300>/MotorNonlinearDynamic1'

    // Update for Atomic SubSystem: '<S300>/MotorNonlinearDynamic2'
    F_MotorNonlinearDynamic1_Update(&FaultModel_DW.MotorNonlinearDynamic2);

    // End of Update for SubSystem: '<S300>/MotorNonlinearDynamic2'

    // Update for Atomic SubSystem: '<S300>/MotorNonlinearDynamic3'
    F_MotorNonlinearDynamic1_Update(&FaultModel_DW.MotorNonlinearDynamic3);

    // End of Update for SubSystem: '<S300>/MotorNonlinearDynamic3'

    // Update for Atomic SubSystem: '<S300>/MotorNonlinearDynamic4'
    F_MotorNonlinearDynamic1_Update(&FaultModel_DW.MotorNonlinearDynamic4);

    // End of Update for SubSystem: '<S300>/MotorNonlinearDynamic4'

    // Update for Atomic SubSystem: '<S300>/MotorNonlinearDynamic5'
    F_MotorNonlinearDynamic1_Update(&FaultModel_DW.MotorNonlinearDynamic5);

    // End of Update for SubSystem: '<S300>/MotorNonlinearDynamic5'

    // Update for Atomic SubSystem: '<S300>/MotorNonlinearDynamic6'
    F_MotorNonlinearDynamic1_Update(&FaultModel_DW.MotorNonlinearDynamic6);

    // End of Update for SubSystem: '<S300>/MotorNonlinearDynamic6'

    // Update for Atomic SubSystem: '<S300>/MotorNonlinearDynamic7'
    F_MotorNonlinearDynamic1_Update(&FaultModel_DW.MotorNonlinearDynamic7);

    // End of Update for SubSystem: '<S300>/MotorNonlinearDynamic7'

    // Update for Atomic SubSystem: '<S300>/MotorNonlinearDynamic8'
    F_MotorNonlinearDynamic1_Update(&FaultModel_DW.MotorNonlinearDynamic8);

    // End of Update for SubSystem: '<S300>/MotorNonlinearDynamic8'
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[2] == 0) {
      // Update for UniformRandomNumber: '<S61>/Uniform Random Number'
      FaultModel_DW.UniformRandomNumber_NextOutput[0] =
        (FaultModel_P.UniformRandomNumber_Maximum[0] -
         FaultModel_P.UniformRandomNumber_Minimum[0]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed[0]) +
        FaultModel_P.UniformRandomNumber_Minimum[0];
      FaultModel_DW.UniformRandomNumber_NextOutput[1] =
        (FaultModel_P.UniformRandomNumber_Maximum[1] -
         FaultModel_P.UniformRandomNumber_Minimum[1]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed[1]) +
        FaultModel_P.UniformRandomNumber_Minimum[1];
      FaultModel_DW.UniformRandomNumber_NextOutput[2] =
        (FaultModel_P.UniformRandomNumber_Maximum[2] -
         FaultModel_P.UniformRandomNumber_Minimum[2]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed[2]) +
        FaultModel_P.UniformRandomNumber_Minimum[2];
    }

    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
      // Update for RandomNumber: '<S129>/White Noise'
      FaultModel_DW.NextOutput[0] = rt_nrand_Upu32_Yd_f_pw_snf
        (&FaultModel_DW.RandSeed_b[0]) * FaultModel_P.WhiteNoise_StdDev +
        FaultModel_P.WhiteNoise_Mean;
      FaultModel_DW.NextOutput[1] = rt_nrand_Upu32_Yd_f_pw_snf
        (&FaultModel_DW.RandSeed_b[1]) * FaultModel_P.WhiteNoise_StdDev +
        FaultModel_P.WhiteNoise_Mean;
      FaultModel_DW.NextOutput[2] = rt_nrand_Upu32_Yd_f_pw_snf
        (&FaultModel_DW.RandSeed_b[2]) * FaultModel_P.WhiteNoise_StdDev +
        FaultModel_P.WhiteNoise_Mean;
      FaultModel_DW.NextOutput[3] = rt_nrand_Upu32_Yd_f_pw_snf
        (&FaultModel_DW.RandSeed_b[3]) * FaultModel_P.WhiteNoise_StdDev +
        FaultModel_P.WhiteNoise_Mean;
    }

    // Update for Enabled SubSystem: '<S120>/Hugw(z)'
    FaultModel_Hugwz_Update(&FaultModel_B.Hugwz_i, &FaultModel_DW.Hugwz_i);

    // End of Update for SubSystem: '<S120>/Hugw(z)'

    // Update for Enabled SubSystem: '<S120>/Hvgw(z)'
    FaultModel_Hvgwz_Update(&FaultModel_B.Hvgwz_p, &FaultModel_DW.Hvgwz_p);

    // End of Update for SubSystem: '<S120>/Hvgw(z)'

    // Update for Enabled SubSystem: '<S120>/Hwgw(z)'
    FaultModel_Hwgwz_Update(&FaultModel_B.Hwgwz_a, &FaultModel_DW.Hwgwz_a);

    // End of Update for SubSystem: '<S120>/Hwgw(z)'
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
      // Update for RandomNumber: '<S90>/White Noise'
      FaultModel_DW.NextOutput_j[0] = rt_nrand_Upu32_Yd_f_pw_snf
        (&FaultModel_DW.RandSeed_j[0]) * FaultModel_P.WhiteNoise_StdDev_h +
        FaultModel_P.WhiteNoise_Mean_m;
      FaultModel_DW.NextOutput_j[1] = rt_nrand_Upu32_Yd_f_pw_snf
        (&FaultModel_DW.RandSeed_j[1]) * FaultModel_P.WhiteNoise_StdDev_h +
        FaultModel_P.WhiteNoise_Mean_m;
      FaultModel_DW.NextOutput_j[2] = rt_nrand_Upu32_Yd_f_pw_snf
        (&FaultModel_DW.RandSeed_j[2]) * FaultModel_P.WhiteNoise_StdDev_h +
        FaultModel_P.WhiteNoise_Mean_m;
      FaultModel_DW.NextOutput_j[3] = rt_nrand_Upu32_Yd_f_pw_snf
        (&FaultModel_DW.RandSeed_j[3]) * FaultModel_P.WhiteNoise_StdDev_h +
        FaultModel_P.WhiteNoise_Mean_m;
    }

    // Update for Enabled SubSystem: '<S81>/Hugw(z)'
    FaultModel_Hugwz_Update(&FaultModel_B.Hugwz, &FaultModel_DW.Hugwz);

    // End of Update for SubSystem: '<S81>/Hugw(z)'

    // Update for Enabled SubSystem: '<S81>/Hvgw(z)'
    FaultModel_Hvgwz_Update(&FaultModel_B.Hvgwz, &FaultModel_DW.Hvgwz);

    // End of Update for SubSystem: '<S81>/Hvgw(z)'

    // Update for Enabled SubSystem: '<S81>/Hwgw(z)'
    FaultModel_Hwgwz_Update(&FaultModel_B.Hwgwz, &FaultModel_DW.Hwgwz);

    // End of Update for SubSystem: '<S81>/Hwgw(z)'
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[2] == 0) {
      // Update for UniformRandomNumber: '<S400>/Uniform Random Number5'
      FaultModel_DW.UniformRandomNumber5_NextOutput[0] =
        (FaultModel_P.UniformRandomNumber5_Maximum[0] -
         FaultModel_P.UniformRandomNumber5_Minimum[0]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_p[0]) +
        FaultModel_P.UniformRandomNumber5_Minimum[0];

      // Update for UniformRandomNumber: '<S400>/Uniform Random Number1'
      FaultModel_DW.UniformRandomNumber1_NextOutput[0] =
        (FaultModel_P.UniformRandomNumber1_Maximum[0] -
         FaultModel_P.UniformRandomNumber1_Minimum[0]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_k[0]) +
        FaultModel_P.UniformRandomNumber1_Minimum[0];

      // Update for UniformRandomNumber: '<S400>/Uniform Random Number5'
      FaultModel_DW.UniformRandomNumber5_NextOutput[1] =
        (FaultModel_P.UniformRandomNumber5_Maximum[1] -
         FaultModel_P.UniformRandomNumber5_Minimum[1]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_p[1]) +
        FaultModel_P.UniformRandomNumber5_Minimum[1];

      // Update for UniformRandomNumber: '<S400>/Uniform Random Number1'
      FaultModel_DW.UniformRandomNumber1_NextOutput[1] =
        (FaultModel_P.UniformRandomNumber1_Maximum[1] -
         FaultModel_P.UniformRandomNumber1_Minimum[1]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_k[1]) +
        FaultModel_P.UniformRandomNumber1_Minimum[1];

      // Update for UniformRandomNumber: '<S400>/Uniform Random Number5'
      FaultModel_DW.UniformRandomNumber5_NextOutput[2] =
        (FaultModel_P.UniformRandomNumber5_Maximum[2] -
         FaultModel_P.UniformRandomNumber5_Minimum[2]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_p[2]) +
        FaultModel_P.UniformRandomNumber5_Minimum[2];

      // Update for UniformRandomNumber: '<S400>/Uniform Random Number1'
      FaultModel_DW.UniformRandomNumber1_NextOutput[2] =
        (FaultModel_P.UniformRandomNumber1_Maximum[2] -
         FaultModel_P.UniformRandomNumber1_Minimum[2]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_k[2]) +
        FaultModel_P.UniformRandomNumber1_Minimum[2];

      // Update for UniformRandomNumber: '<S400>/Uniform Random Number7'
      FaultModel_DW.UniformRandomNumber7_NextOutput[0] =
        (FaultModel_P.UniformRandomNumber7_Maximum[0] -
         FaultModel_P.UniformRandomNumber7_Minimum[0]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_h[0]) +
        FaultModel_P.UniformRandomNumber7_Minimum[0];
      FaultModel_DW.UniformRandomNumber7_NextOutput[1] =
        (FaultModel_P.UniformRandomNumber7_Maximum[1] -
         FaultModel_P.UniformRandomNumber7_Minimum[1]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_h[1]) +
        FaultModel_P.UniformRandomNumber7_Minimum[1];
      FaultModel_DW.UniformRandomNumber7_NextOutput[2] =
        (FaultModel_P.UniformRandomNumber7_Maximum[2] -
         FaultModel_P.UniformRandomNumber7_Minimum[2]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_h[2]) +
        FaultModel_P.UniformRandomNumber7_Minimum[2];
    }

    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[1] == 0) {
      // Update for Memory: '<S464>/otime' incorporates:
      //   Constant: '<S416>/Decimal Year'

      FaultModel_DW.otime_PreviousInput = FaultModel_P.DecimalYear_Value;

      // Update for Memory: '<S463>/olon'
      FaultModel_DW.olon_PreviousInput = FaultModel_B.Switch_f;

      // Update for Memory: '<S462>/olat'
      FaultModel_DW.olat_PreviousInput = FaultModel_B.Switch_e;

      // Update for Memory: '<S462>/oalt'
      FaultModel_DW.oalt_PreviousInput = FaultModel_B.Gain_o;
    }

    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[3] == 0) {
      // Update for UniformRandomNumber: '<S400>/Uniform Random Number'
      FaultModel_DW.UniformRandomNumber_NextOutpu_k =
        (FaultModel_P.UniformRandomNumber_Maximum_j -
         FaultModel_P.UniformRandomNumber_Minimum_h) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_d) +
        FaultModel_P.UniformRandomNumber_Minimum_h;

      // Update for UniformRandomNumber: '<S400>/Uniform Random Number4'
      FaultModel_DW.UniformRandomNumber4_NextOutput =
        (FaultModel_P.UniformRandomNumber4_Maximum -
         FaultModel_P.UniformRandomNumber4_Minimum) * rt_urand_Upu32_Yd_f_pw_snf
        (&FaultModel_DW.RandSeed_a) + FaultModel_P.UniformRandomNumber4_Minimum;
    }

    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[2] == 0) {
      // Update for UniformRandomNumber: '<S400>/Uniform Random Number2'
      FaultModel_DW.UniformRandomNumber2_NextOutput =
        (FaultModel_P.UniformRandomNumber2_Maximum -
         FaultModel_P.UniformRandomNumber2_Minimum) * rt_urand_Upu32_Yd_f_pw_snf
        (&FaultModel_DW.RandSeed_i) + FaultModel_P.UniformRandomNumber2_Minimum;
    }

    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[4] == 0) {
      // Update for UniformRandomNumber: '<S327>/Uniform Random Number5'
      FaultModel_DW.UniformRandomNumber5_NextOutp_m[0] =
        (FaultModel_P.UniformRandomNumber5_Maximum_l[0] -
         FaultModel_P.UniformRandomNumber5_Minimum_o[0]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_e[0]) +
        FaultModel_P.UniformRandomNumber5_Minimum_o[0];
      FaultModel_DW.UniformRandomNumber5_NextOutp_m[1] =
        (FaultModel_P.UniformRandomNumber5_Maximum_l[1] -
         FaultModel_P.UniformRandomNumber5_Minimum_o[1]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_e[1]) +
        FaultModel_P.UniformRandomNumber5_Minimum_o[1];
      FaultModel_DW.UniformRandomNumber5_NextOutp_m[2] =
        (FaultModel_P.UniformRandomNumber5_Maximum_l[2] -
         FaultModel_P.UniformRandomNumber5_Minimum_o[2]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_e[2]) +
        FaultModel_P.UniformRandomNumber5_Minimum_o[2];
    }

    // Update for Enabled SubSystem: '<S80>/Hpgw'
    FaultModel_Hpgw_Update(&FaultModel_B.Hpgw, &FaultModel_DW.Hpgw);

    // End of Update for SubSystem: '<S80>/Hpgw'

    // Update for Enabled SubSystem: '<S80>/Hqgw'
    FaultModel_Hqgw_Update(FaultModel_B.Hwgwz.Sum, &FaultModel_B.Hqgw,
      &FaultModel_DW.Hqgw);

    // End of Update for SubSystem: '<S80>/Hqgw'

    // Update for Enabled SubSystem: '<S80>/Hrgw'
    FaultModel_Hrgw_Update(FaultModel_B.Hvgwz.Sum, &FaultModel_B.Hrgw,
      &FaultModel_DW.Hrgw);

    // End of Update for SubSystem: '<S80>/Hrgw'

    // Update for Enabled SubSystem: '<S119>/Hpgw'
    FaultModel_Hpgw_Update(&FaultModel_B.Hpgw_c, &FaultModel_DW.Hpgw_c);

    // End of Update for SubSystem: '<S119>/Hpgw'

    // Update for Enabled SubSystem: '<S119>/Hqgw'
    FaultModel_Hqgw_Update(FaultModel_B.Hwgwz_a.Sum, &FaultModel_B.Hqgw_b,
      &FaultModel_DW.Hqgw_b);

    // End of Update for SubSystem: '<S119>/Hqgw'

    // Update for Enabled SubSystem: '<S119>/Hrgw'
    FaultModel_Hrgw_Update(FaultModel_B.Hvgwz_p.Sum, &FaultModel_B.Hrgw_g,
      &FaultModel_DW.Hrgw_g);

    // End of Update for SubSystem: '<S119>/Hrgw'
    if (rtmIsMajorTimeStep((&FaultModel_M)) &&
        (&FaultModel_M)->Timing.TaskCounters.TID[4] == 0) {
      // Update for UniformRandomNumber: '<S327>/Uniform Random Number4'
      FaultModel_DW.UniformRandomNumber4_NextOutp_p[0] =
        (FaultModel_P.UniformRandomNumber4_Maximum_c[0] -
         FaultModel_P.UniformRandomNumber4_Minimum_o[0]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_n[0]) +
        FaultModel_P.UniformRandomNumber4_Minimum_o[0];
      FaultModel_DW.UniformRandomNumber4_NextOutp_p[1] =
        (FaultModel_P.UniformRandomNumber4_Maximum_c[1] -
         FaultModel_P.UniformRandomNumber4_Minimum_o[1]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_n[1]) +
        FaultModel_P.UniformRandomNumber4_Minimum_o[1];
      FaultModel_DW.UniformRandomNumber4_NextOutp_p[2] =
        (FaultModel_P.UniformRandomNumber4_Maximum_c[2] -
         FaultModel_P.UniformRandomNumber4_Minimum_o[2]) *
        rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_n[2]) +
        FaultModel_P.UniformRandomNumber4_Minimum_o[2];
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep((&FaultModel_M))) {
    rt_ertODEUpdateContinuousStates(&(&FaultModel_M)->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++(&FaultModel_M)->Timing.clockTick0;
    (&FaultModel_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&FaultModel_M)
      ->solverInfo);

    {
      // Update absolute timer for sample time: [0.001s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.001, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      (&FaultModel_M)->Timing.clockTick1++;
    }

    rate_scheduler((&FaultModel_M));
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void MulticopterModelClass::FaultModel_derivatives()
{
  XDot_FaultModel_T *_rtXdot;
  _rtXdot = ((XDot_FaultModel_T *) (&FaultModel_M)->derivs);

  // Derivatives for SecondOrderIntegrator: '<S429>/Integrator, Second-Order Limited' 
  if (FaultModel_DW.IntegratorSecondOrderLimited_MO[0] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CS[0] =
      FaultModel_X.IntegratorSecondOrderLimited_CS[3];
    _rtXdot->IntegratorSecondOrderLimited_CS[3] = FaultModel_B.Sum2[0];
  }

  if (FaultModel_DW.IntegratorSecondOrderLimited_MO[1] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CS[1] =
      FaultModel_X.IntegratorSecondOrderLimited_CS[4];
    _rtXdot->IntegratorSecondOrderLimited_CS[4] = FaultModel_B.Sum2[1];
  }

  if (FaultModel_DW.IntegratorSecondOrderLimited_MO[2] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CS[2] =
      FaultModel_X.IntegratorSecondOrderLimited_CS[5];
    _rtXdot->IntegratorSecondOrderLimited_CS[5] = FaultModel_B.Sum2[2];
  }

  // End of Derivatives for SecondOrderIntegrator: '<S429>/Integrator, Second-Order Limited' 

  // Derivatives for Integrator: '<S13>/q0 q1 q2 q3'
  _rtXdot->q0q1q2q3_CSTATE[0] = FaultModel_B.TmpSignalConversionAtq0q1q2q3_c[0];
  _rtXdot->q0q1q2q3_CSTATE[1] = FaultModel_B.TmpSignalConversionAtq0q1q2q3_c[1];
  _rtXdot->q0q1q2q3_CSTATE[2] = FaultModel_B.TmpSignalConversionAtq0q1q2q3_c[2];
  _rtXdot->q0q1q2q3_CSTATE[3] = FaultModel_B.TmpSignalConversionAtq0q1q2q3_c[3];

  // Derivatives for Integrator: '<S12>/xe,ye,ze'
  _rtXdot->xeyeze_CSTATE[0] = FaultModel_B.Product[0];

  // Derivatives for Integrator: '<S12>/p,q,r '
  _rtXdot->pqr_CSTATE[0] = FaultModel_B.Product2[0];

  // Derivatives for Integrator: '<S12>/ub,vb,wb'
  _rtXdot->ubvbwb_CSTATE[0] = FaultModel_B.Sum_p[0];

  // Derivatives for Integrator: '<S12>/xe,ye,ze'
  _rtXdot->xeyeze_CSTATE[1] = FaultModel_B.Product[1];

  // Derivatives for Integrator: '<S12>/p,q,r '
  _rtXdot->pqr_CSTATE[1] = FaultModel_B.Product2[1];

  // Derivatives for Integrator: '<S12>/ub,vb,wb'
  _rtXdot->ubvbwb_CSTATE[1] = FaultModel_B.Sum_p[1];

  // Derivatives for Integrator: '<S12>/xe,ye,ze'
  _rtXdot->xeyeze_CSTATE[2] = FaultModel_B.Product[2];

  // Derivatives for Integrator: '<S12>/p,q,r '
  _rtXdot->pqr_CSTATE[2] = FaultModel_B.Product2[2];

  // Derivatives for Integrator: '<S12>/ub,vb,wb'
  _rtXdot->ubvbwb_CSTATE[2] = FaultModel_B.Sum_p[2];

  // Derivatives for Atomic SubSystem: '<S300>/MotorNonlinearDynamic1'
  Fa_MotorNonlinearDynamic1_Deriv(&FaultModel_B.MotorNonlinearDynamic1,
    &_rtXdot->MotorNonlinearDynamic1);

  // End of Derivatives for SubSystem: '<S300>/MotorNonlinearDynamic1'

  // Derivatives for Atomic SubSystem: '<S300>/MotorNonlinearDynamic2'
  Fa_MotorNonlinearDynamic1_Deriv(&FaultModel_B.MotorNonlinearDynamic2,
    &_rtXdot->MotorNonlinearDynamic2);

  // End of Derivatives for SubSystem: '<S300>/MotorNonlinearDynamic2'

  // Derivatives for Atomic SubSystem: '<S300>/MotorNonlinearDynamic3'
  Fa_MotorNonlinearDynamic1_Deriv(&FaultModel_B.MotorNonlinearDynamic3,
    &_rtXdot->MotorNonlinearDynamic3);

  // End of Derivatives for SubSystem: '<S300>/MotorNonlinearDynamic3'

  // Derivatives for Atomic SubSystem: '<S300>/MotorNonlinearDynamic4'
  Fa_MotorNonlinearDynamic1_Deriv(&FaultModel_B.MotorNonlinearDynamic4,
    &_rtXdot->MotorNonlinearDynamic4);

  // End of Derivatives for SubSystem: '<S300>/MotorNonlinearDynamic4'

  // Derivatives for Atomic SubSystem: '<S300>/MotorNonlinearDynamic5'
  Fa_MotorNonlinearDynamic1_Deriv(&FaultModel_B.MotorNonlinearDynamic5,
    &_rtXdot->MotorNonlinearDynamic5);

  // End of Derivatives for SubSystem: '<S300>/MotorNonlinearDynamic5'

  // Derivatives for Atomic SubSystem: '<S300>/MotorNonlinearDynamic6'
  Fa_MotorNonlinearDynamic1_Deriv(&FaultModel_B.MotorNonlinearDynamic6,
    &_rtXdot->MotorNonlinearDynamic6);

  // End of Derivatives for SubSystem: '<S300>/MotorNonlinearDynamic6'

  // Derivatives for Atomic SubSystem: '<S300>/MotorNonlinearDynamic7'
  Fa_MotorNonlinearDynamic1_Deriv(&FaultModel_B.MotorNonlinearDynamic7,
    &_rtXdot->MotorNonlinearDynamic7);

  // End of Derivatives for SubSystem: '<S300>/MotorNonlinearDynamic7'

  // Derivatives for Atomic SubSystem: '<S300>/MotorNonlinearDynamic8'
  Fa_MotorNonlinearDynamic1_Deriv(&FaultModel_B.MotorNonlinearDynamic8,
    &_rtXdot->MotorNonlinearDynamic8);

  // End of Derivatives for SubSystem: '<S300>/MotorNonlinearDynamic8'

  // Derivatives for SecondOrderIntegrator: '<S440>/Integrator, Second-Order Limited' 
  if (FaultModel_DW.IntegratorSecondOrderLimited__l[0] == 0) {
    _rtXdot->IntegratorSecondOrderLimited__b[0] =
      FaultModel_X.IntegratorSecondOrderLimited__b[3];
    _rtXdot->IntegratorSecondOrderLimited__b[3] = FaultModel_B.Sum2_f[0];
  }

  if (FaultModel_DW.IntegratorSecondOrderLimited__l[1] == 0) {
    _rtXdot->IntegratorSecondOrderLimited__b[1] =
      FaultModel_X.IntegratorSecondOrderLimited__b[4];
    _rtXdot->IntegratorSecondOrderLimited__b[4] = FaultModel_B.Sum2_f[1];
  }

  if (FaultModel_DW.IntegratorSecondOrderLimited__l[2] == 0) {
    _rtXdot->IntegratorSecondOrderLimited__b[2] =
      FaultModel_X.IntegratorSecondOrderLimited__b[5];
    _rtXdot->IntegratorSecondOrderLimited__b[5] = FaultModel_B.Sum2_f[2];
  }

  // End of Derivatives for SecondOrderIntegrator: '<S440>/Integrator, Second-Order Limited' 

  // Derivatives for TransferFcn: '<S376>/Transfer Fcn4'
  _rtXdot->TransferFcn4_CSTATE = 0.0;
  _rtXdot->TransferFcn4_CSTATE += FaultModel_P.TransferFcn4_A *
    FaultModel_X.TransferFcn4_CSTATE;
  _rtXdot->TransferFcn4_CSTATE += FaultModel_B.BiasGain1[0];

  // Derivatives for TransferFcn: '<S376>/Transfer Fcn1'
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += FaultModel_P.TransferFcn1_A *
    FaultModel_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += FaultModel_B.BiasGain1[1];

  // Derivatives for TransferFcn: '<S376>/Transfer Fcn2'
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += FaultModel_P.TransferFcn2_A *
    FaultModel_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += FaultModel_B.BiasGain1[2];
}

// Model initialize function
void MulticopterModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  FaultModel_P.uftinf_UpperSat = rtInf;

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&FaultModel_M)->solverInfo, &(&FaultModel_M)
                          ->Timing.simTimeStep);
    rtsiSetTPtr(&(&FaultModel_M)->solverInfo, &rtmGetTPtr((&FaultModel_M)));
    rtsiSetStepSizePtr(&(&FaultModel_M)->solverInfo, &(&FaultModel_M)
                       ->Timing.stepSize0);
    rtsiSetdXPtr(&(&FaultModel_M)->solverInfo, &(&FaultModel_M)->derivs);
    rtsiSetContStatesPtr(&(&FaultModel_M)->solverInfo, (real_T **)
                         &(&FaultModel_M)->contStates);
    rtsiSetNumContStatesPtr(&(&FaultModel_M)->solverInfo, &(&FaultModel_M)
      ->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&FaultModel_M)->solverInfo,
      &(&FaultModel_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&FaultModel_M)->solverInfo,
      &(&FaultModel_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&FaultModel_M)->solverInfo,
      &(&FaultModel_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&FaultModel_M)->solverInfo, (&rtmGetErrorStatus
      ((&FaultModel_M))));
    rtsiSetRTModelPtr(&(&FaultModel_M)->solverInfo, (&FaultModel_M));
  }

  rtsiSetSimTimeStep(&(&FaultModel_M)->solverInfo, MAJOR_TIME_STEP);
  (&FaultModel_M)->intgData.y = (&FaultModel_M)->odeY;
  (&FaultModel_M)->intgData.f[0] = (&FaultModel_M)->odeF[0];
  (&FaultModel_M)->intgData.f[1] = (&FaultModel_M)->odeF[1];
  (&FaultModel_M)->intgData.f[2] = (&FaultModel_M)->odeF[2];
  (&FaultModel_M)->intgData.f[3] = (&FaultModel_M)->odeF[3];
  (&FaultModel_M)->contStates = ((X_FaultModel_T *) &FaultModel_X);
  rtsiSetSolverData(&(&FaultModel_M)->solverInfo, static_cast<void *>
                    (&(&FaultModel_M)->intgData));
  rtsiSetSolverName(&(&FaultModel_M)->solverInfo,"ode4");
  rtmSetTPtr((&FaultModel_M), &(&FaultModel_M)->Timing.tArray[0]);
  (&FaultModel_M)->Timing.stepSize0 = 0.001;
  rtmSetFirstInitCond((&FaultModel_M), 1);

  {
    real_T tmp;
    int32_T i;
    int32_T t;
    uint32_T tseed;

    // Start for If: '<S40>/If'
    FaultModel_DW.If_ActiveSubsystem = -1;

    // Start for If: '<S192>/If'
    FaultModel_DW.If_ActiveSubsystem_h = -1;

    // Start for If: '<S191>/If'
    FaultModel_DW.If_ActiveSubsystem_l = -1;

    // Start for Constant: '<S300>/ModelInit_RPM'
    FaultModel_B.ModelInit_RPM = FaultModel_P.ModelInit_RPM;

    // Start for If: '<S125>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 
    FaultModel_DW.ifHeightMaxlowaltitudeelseifHei = -1;

    // Start for If: '<S86>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 
    FaultModel_DW.ifHeightMaxlowaltitudeelseifH_d = -1;

    // Start for If: '<S326>/If'
    FaultModel_DW.If_ActiveSubsystem_m = -1;

    // Start for If: '<S85>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 
    FaultModel_DW.ifHeightMaxlowaltitudeelseifH_g = -1;

    // Start for If: '<S124>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 
    FaultModel_DW.ifHeightMaxlowaltitudeelseifH_i = -1;

    // Start for If: '<S202>/If1'
    FaultModel_DW.If1_ActiveSubsystem = -1;

    // Start for If: '<S240>/If1'
    FaultModel_DW.If1_ActiveSubsystem_o = -1;

    // Start for If: '<S334>/If1'
    FaultModel_DW.If1_ActiveSubsystem_d = -1;

    // InitializeConditions for SecondOrderIntegrator: '<S429>/Integrator, Second-Order Limited' 
    FaultModel_X.IntegratorSecondOrderLimited_CS[0] =
      FaultModel_P.IntegratorSecondOrderLimited_IC;
    FaultModel_X.IntegratorSecondOrderLimited_CS[1] =
      FaultModel_P.IntegratorSecondOrderLimited_IC;
    FaultModel_X.IntegratorSecondOrderLimited_CS[2] =
      FaultModel_P.IntegratorSecondOrderLimited_IC;
    FaultModel_X.IntegratorSecondOrderLimited_CS[3] =
      FaultModel_P.IntegratorSecondOrderLimited__d;
    FaultModel_X.IntegratorSecondOrderLimited_CS[4] =
      FaultModel_P.IntegratorSecondOrderLimited__d;
    FaultModel_X.IntegratorSecondOrderLimited_CS[5] =
      FaultModel_P.IntegratorSecondOrderLimited__d;

    // InitializeConditions for Integrator: '<S13>/q0 q1 q2 q3'
    if (rtmIsFirstInitCond((&FaultModel_M))) {
      FaultModel_X.q0q1q2q3_CSTATE[0] = 0.0;
      FaultModel_X.q0q1q2q3_CSTATE[1] = 0.0;
      FaultModel_X.q0q1q2q3_CSTATE[2] = 0.0;
      FaultModel_X.q0q1q2q3_CSTATE[3] = 0.0;
    }

    FaultModel_DW.q0q1q2q3_IWORK = 1;

    // End of InitializeConditions for Integrator: '<S13>/q0 q1 q2 q3'

    // InitializeConditions for Integrator: '<S12>/xe,ye,ze'
    FaultModel_X.xeyeze_CSTATE[0] = FaultModel_P.ModelInit_PosE[0];

    // InitializeConditions for Integrator: '<S12>/p,q,r '
    FaultModel_X.pqr_CSTATE[0] = FaultModel_P.ModelInit_RateB[0];

    // InitializeConditions for Integrator: '<S12>/ub,vb,wb'
    FaultModel_X.ubvbwb_CSTATE[0] = FaultModel_P.ModelInit_VelB[0];

    // InitializeConditions for Integrator: '<S12>/xe,ye,ze'
    FaultModel_X.xeyeze_CSTATE[1] = FaultModel_P.ModelInit_PosE[1];

    // InitializeConditions for Integrator: '<S12>/p,q,r '
    FaultModel_X.pqr_CSTATE[1] = FaultModel_P.ModelInit_RateB[1];

    // InitializeConditions for Integrator: '<S12>/ub,vb,wb'
    FaultModel_X.ubvbwb_CSTATE[1] = FaultModel_P.ModelInit_VelB[1];

    // InitializeConditions for Integrator: '<S12>/xe,ye,ze'
    FaultModel_X.xeyeze_CSTATE[2] = FaultModel_P.ModelInit_PosE[2];

    // InitializeConditions for Integrator: '<S12>/p,q,r '
    FaultModel_X.pqr_CSTATE[2] = FaultModel_P.ModelInit_RateB[2];

    // InitializeConditions for Integrator: '<S12>/ub,vb,wb'
    FaultModel_X.ubvbwb_CSTATE[2] = FaultModel_P.ModelInit_VelB[2];

    // InitializeConditions for Memory: '<Root>/Memory'
    for (i = 0; i < 8; i++) {
      FaultModel_DW.Memory_PreviousInput[i] =
        FaultModel_P.Memory_InitialCondition;
    }

    // End of InitializeConditions for Memory: '<Root>/Memory'

    // InitializeConditions for UniformRandomNumber: '<S61>/Uniform Random Number' 
    tmp = std::floor(FaultModel_P.UniformRandomNumber_Seed[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed[0] = tseed;
    FaultModel_DW.UniformRandomNumber_NextOutput[0] =
      (FaultModel_P.UniformRandomNumber_Maximum[0] -
       FaultModel_P.UniformRandomNumber_Minimum[0]) * rt_urand_Upu32_Yd_f_pw_snf
      (&FaultModel_DW.RandSeed[0]) + FaultModel_P.UniformRandomNumber_Minimum[0];
    tmp = std::floor(FaultModel_P.UniformRandomNumber_Seed[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed[1] = tseed;
    FaultModel_DW.UniformRandomNumber_NextOutput[1] =
      (FaultModel_P.UniformRandomNumber_Maximum[1] -
       FaultModel_P.UniformRandomNumber_Minimum[1]) * rt_urand_Upu32_Yd_f_pw_snf
      (&FaultModel_DW.RandSeed[1]) + FaultModel_P.UniformRandomNumber_Minimum[1];
    tmp = std::floor(FaultModel_P.UniformRandomNumber_Seed[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed[2] = tseed;
    FaultModel_DW.UniformRandomNumber_NextOutput[2] =
      (FaultModel_P.UniformRandomNumber_Maximum[2] -
       FaultModel_P.UniformRandomNumber_Minimum[2]) * rt_urand_Upu32_Yd_f_pw_snf
      (&FaultModel_DW.RandSeed[2]) + FaultModel_P.UniformRandomNumber_Minimum[2];

    // End of InitializeConditions for UniformRandomNumber: '<S61>/Uniform Random Number' 

    // InitializeConditions for RandomNumber: '<S129>/White Noise'
    tmp = std::floor(FaultModel_P.DrydenWindTurbulenceModelDisc_k[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_b[0] = tseed;
    FaultModel_DW.NextOutput[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&FaultModel_DW.RandSeed_b[0]) * FaultModel_P.WhiteNoise_StdDev +
      FaultModel_P.WhiteNoise_Mean;
    tmp = std::floor(FaultModel_P.DrydenWindTurbulenceModelDisc_k[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_b[1] = tseed;
    FaultModel_DW.NextOutput[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&FaultModel_DW.RandSeed_b[1]) * FaultModel_P.WhiteNoise_StdDev +
      FaultModel_P.WhiteNoise_Mean;
    tmp = std::floor(FaultModel_P.DrydenWindTurbulenceModelDisc_k[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_b[2] = tseed;
    FaultModel_DW.NextOutput[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&FaultModel_DW.RandSeed_b[2]) * FaultModel_P.WhiteNoise_StdDev +
      FaultModel_P.WhiteNoise_Mean;
    tmp = std::floor(FaultModel_P.DrydenWindTurbulenceModelDisc_k[3]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_b[3] = tseed;
    FaultModel_DW.NextOutput[3] = rt_nrand_Upu32_Yd_f_pw_snf
      (&FaultModel_DW.RandSeed_b[3]) * FaultModel_P.WhiteNoise_StdDev +
      FaultModel_P.WhiteNoise_Mean;

    // End of InitializeConditions for RandomNumber: '<S129>/White Noise'

    // InitializeConditions for RandomNumber: '<S90>/White Noise'
    tmp = std::floor(FaultModel_P.DrydenWindTurbulenceModelDisc_n[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_j[0] = tseed;
    FaultModel_DW.NextOutput_j[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&FaultModel_DW.RandSeed_j[0]) * FaultModel_P.WhiteNoise_StdDev_h +
      FaultModel_P.WhiteNoise_Mean_m;
    tmp = std::floor(FaultModel_P.DrydenWindTurbulenceModelDisc_n[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_j[1] = tseed;
    FaultModel_DW.NextOutput_j[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&FaultModel_DW.RandSeed_j[1]) * FaultModel_P.WhiteNoise_StdDev_h +
      FaultModel_P.WhiteNoise_Mean_m;
    tmp = std::floor(FaultModel_P.DrydenWindTurbulenceModelDisc_n[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_j[2] = tseed;
    FaultModel_DW.NextOutput_j[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&FaultModel_DW.RandSeed_j[2]) * FaultModel_P.WhiteNoise_StdDev_h +
      FaultModel_P.WhiteNoise_Mean_m;
    tmp = std::floor(FaultModel_P.DrydenWindTurbulenceModelDisc_n[3]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_j[3] = tseed;
    FaultModel_DW.NextOutput_j[3] = rt_nrand_Upu32_Yd_f_pw_snf
      (&FaultModel_DW.RandSeed_j[3]) * FaultModel_P.WhiteNoise_StdDev_h +
      FaultModel_P.WhiteNoise_Mean_m;

    // End of InitializeConditions for RandomNumber: '<S90>/White Noise'

    // InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number5' 
    tmp = std::floor(FaultModel_P.UniformRandomNumber5_Seed[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_p[0] = tseed;
    FaultModel_DW.UniformRandomNumber5_NextOutput[0] =
      (FaultModel_P.UniformRandomNumber5_Maximum[0] -
       FaultModel_P.UniformRandomNumber5_Minimum[0]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_p[0]) +
      FaultModel_P.UniformRandomNumber5_Minimum[0];

    // InitializeConditions for SecondOrderIntegrator: '<S440>/Integrator, Second-Order Limited' 
    FaultModel_X.IntegratorSecondOrderLimited__b[0] =
      FaultModel_P.IntegratorSecondOrderLimited__l;

    // InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number5' 
    tmp = std::floor(FaultModel_P.UniformRandomNumber5_Seed[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_p[1] = tseed;
    FaultModel_DW.UniformRandomNumber5_NextOutput[1] =
      (FaultModel_P.UniformRandomNumber5_Maximum[1] -
       FaultModel_P.UniformRandomNumber5_Minimum[1]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_p[1]) +
      FaultModel_P.UniformRandomNumber5_Minimum[1];

    // InitializeConditions for SecondOrderIntegrator: '<S440>/Integrator, Second-Order Limited' 
    FaultModel_X.IntegratorSecondOrderLimited__b[1] =
      FaultModel_P.IntegratorSecondOrderLimited__l;

    // InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number5' 
    tmp = std::floor(FaultModel_P.UniformRandomNumber5_Seed[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_p[2] = tseed;
    FaultModel_DW.UniformRandomNumber5_NextOutput[2] =
      (FaultModel_P.UniformRandomNumber5_Maximum[2] -
       FaultModel_P.UniformRandomNumber5_Minimum[2]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_p[2]) +
      FaultModel_P.UniformRandomNumber5_Minimum[2];

    // InitializeConditions for SecondOrderIntegrator: '<S440>/Integrator, Second-Order Limited' 
    FaultModel_X.IntegratorSecondOrderLimited__b[2] =
      FaultModel_P.IntegratorSecondOrderLimited__l;
    FaultModel_X.IntegratorSecondOrderLimited__b[3] =
      FaultModel_P.IntegratorSecondOrderLimited__f;

    // InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number1' 
    tmp = std::floor(FaultModel_P.UniformRandomNumber1_Seed[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_k[0] = tseed;
    FaultModel_DW.UniformRandomNumber1_NextOutput[0] =
      (FaultModel_P.UniformRandomNumber1_Maximum[0] -
       FaultModel_P.UniformRandomNumber1_Minimum[0]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_k[0]) +
      FaultModel_P.UniformRandomNumber1_Minimum[0];

    // InitializeConditions for SecondOrderIntegrator: '<S440>/Integrator, Second-Order Limited' 
    FaultModel_X.IntegratorSecondOrderLimited__b[4] =
      FaultModel_P.IntegratorSecondOrderLimited__f;

    // InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number1' 
    tmp = std::floor(FaultModel_P.UniformRandomNumber1_Seed[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_k[1] = tseed;
    FaultModel_DW.UniformRandomNumber1_NextOutput[1] =
      (FaultModel_P.UniformRandomNumber1_Maximum[1] -
       FaultModel_P.UniformRandomNumber1_Minimum[1]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_k[1]) +
      FaultModel_P.UniformRandomNumber1_Minimum[1];

    // InitializeConditions for SecondOrderIntegrator: '<S440>/Integrator, Second-Order Limited' 
    FaultModel_X.IntegratorSecondOrderLimited__b[5] =
      FaultModel_P.IntegratorSecondOrderLimited__f;

    // InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number1' 
    tmp = std::floor(FaultModel_P.UniformRandomNumber1_Seed[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_k[2] = tseed;
    FaultModel_DW.UniformRandomNumber1_NextOutput[2] =
      (FaultModel_P.UniformRandomNumber1_Maximum[2] -
       FaultModel_P.UniformRandomNumber1_Minimum[2]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_k[2]) +
      FaultModel_P.UniformRandomNumber1_Minimum[2];

    // InitializeConditions for Memory: '<S464>/otime'
    FaultModel_DW.otime_PreviousInput = FaultModel_P.otime_InitialCondition;

    // InitializeConditions for Memory: '<S463>/olon'
    FaultModel_DW.olon_PreviousInput = FaultModel_P.olon_InitialCondition;

    // InitializeConditions for Memory: '<S462>/olat'
    FaultModel_DW.olat_PreviousInput = FaultModel_P.olat_InitialCondition;

    // InitializeConditions for Memory: '<S462>/oalt'
    FaultModel_DW.oalt_PreviousInput = FaultModel_P.oalt_InitialCondition;

    // InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number7' 
    tmp = std::floor(FaultModel_P.UniformRandomNumber7_Seed[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_h[0] = tseed;
    FaultModel_DW.UniformRandomNumber7_NextOutput[0] =
      (FaultModel_P.UniformRandomNumber7_Maximum[0] -
       FaultModel_P.UniformRandomNumber7_Minimum[0]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_h[0]) +
      FaultModel_P.UniformRandomNumber7_Minimum[0];
    tmp = std::floor(FaultModel_P.UniformRandomNumber7_Seed[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_h[1] = tseed;
    FaultModel_DW.UniformRandomNumber7_NextOutput[1] =
      (FaultModel_P.UniformRandomNumber7_Maximum[1] -
       FaultModel_P.UniformRandomNumber7_Minimum[1]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_h[1]) +
      FaultModel_P.UniformRandomNumber7_Minimum[1];
    tmp = std::floor(FaultModel_P.UniformRandomNumber7_Seed[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_h[2] = tseed;
    FaultModel_DW.UniformRandomNumber7_NextOutput[2] =
      (FaultModel_P.UniformRandomNumber7_Maximum[2] -
       FaultModel_P.UniformRandomNumber7_Minimum[2]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_h[2]) +
      FaultModel_P.UniformRandomNumber7_Minimum[2];

    // End of InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number7' 

    // InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number' 
    tmp = std::floor(FaultModel_P.UniformRandomNumber_Seed_o);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_d = tseed;
    FaultModel_DW.UniformRandomNumber_NextOutpu_k =
      (FaultModel_P.UniformRandomNumber_Maximum_j -
       FaultModel_P.UniformRandomNumber_Minimum_h) * rt_urand_Upu32_Yd_f_pw_snf(
      &FaultModel_DW.RandSeed_d) + FaultModel_P.UniformRandomNumber_Minimum_h;

    // End of InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number' 

    // InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number2' 
    tmp = std::floor(FaultModel_P.UniformRandomNumber2_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_i = tseed;
    FaultModel_DW.UniformRandomNumber2_NextOutput =
      (FaultModel_P.UniformRandomNumber2_Maximum -
       FaultModel_P.UniformRandomNumber2_Minimum) * rt_urand_Upu32_Yd_f_pw_snf
      (&FaultModel_DW.RandSeed_i) + FaultModel_P.UniformRandomNumber2_Minimum;

    // End of InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number2' 

    // InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number4' 
    tmp = std::floor(FaultModel_P.UniformRandomNumber4_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_a = tseed;
    FaultModel_DW.UniformRandomNumber4_NextOutput =
      (FaultModel_P.UniformRandomNumber4_Maximum -
       FaultModel_P.UniformRandomNumber4_Minimum) * rt_urand_Upu32_Yd_f_pw_snf
      (&FaultModel_DW.RandSeed_a) + FaultModel_P.UniformRandomNumber4_Minimum;

    // End of InitializeConditions for UniformRandomNumber: '<S400>/Uniform Random Number4' 

    // InitializeConditions for UniformRandomNumber: '<S327>/Uniform Random Number5' 
    tmp = std::floor(FaultModel_P.UniformRandomNumber5_Seed_j[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_e[0] = tseed;
    FaultModel_DW.UniformRandomNumber5_NextOutp_m[0] =
      (FaultModel_P.UniformRandomNumber5_Maximum_l[0] -
       FaultModel_P.UniformRandomNumber5_Minimum_o[0]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_e[0]) +
      FaultModel_P.UniformRandomNumber5_Minimum_o[0];
    tmp = std::floor(FaultModel_P.UniformRandomNumber5_Seed_j[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_e[1] = tseed;
    FaultModel_DW.UniformRandomNumber5_NextOutp_m[1] =
      (FaultModel_P.UniformRandomNumber5_Maximum_l[1] -
       FaultModel_P.UniformRandomNumber5_Minimum_o[1]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_e[1]) +
      FaultModel_P.UniformRandomNumber5_Minimum_o[1];
    tmp = std::floor(FaultModel_P.UniformRandomNumber5_Seed_j[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_e[2] = tseed;
    FaultModel_DW.UniformRandomNumber5_NextOutp_m[2] =
      (FaultModel_P.UniformRandomNumber5_Maximum_l[2] -
       FaultModel_P.UniformRandomNumber5_Minimum_o[2]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_e[2]) +
      FaultModel_P.UniformRandomNumber5_Minimum_o[2];

    // End of InitializeConditions for UniformRandomNumber: '<S327>/Uniform Random Number5' 

    // InitializeConditions for TransferFcn: '<S376>/Transfer Fcn4'
    FaultModel_X.TransferFcn4_CSTATE = 0.0;

    // InitializeConditions for TransferFcn: '<S376>/Transfer Fcn1'
    FaultModel_X.TransferFcn1_CSTATE = 0.0;

    // InitializeConditions for TransferFcn: '<S376>/Transfer Fcn2'
    FaultModel_X.TransferFcn2_CSTATE = 0.0;

    // InitializeConditions for UniformRandomNumber: '<S327>/Uniform Random Number4' 
    tmp = std::floor(FaultModel_P.UniformRandomNumber4_Seed_e[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_n[0] = tseed;
    FaultModel_DW.UniformRandomNumber4_NextOutp_p[0] =
      (FaultModel_P.UniformRandomNumber4_Maximum_c[0] -
       FaultModel_P.UniformRandomNumber4_Minimum_o[0]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_n[0]) +
      FaultModel_P.UniformRandomNumber4_Minimum_o[0];
    tmp = std::floor(FaultModel_P.UniformRandomNumber4_Seed_e[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_n[1] = tseed;
    FaultModel_DW.UniformRandomNumber4_NextOutp_p[1] =
      (FaultModel_P.UniformRandomNumber4_Maximum_c[1] -
       FaultModel_P.UniformRandomNumber4_Minimum_o[1]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_n[1]) +
      FaultModel_P.UniformRandomNumber4_Minimum_o[1];
    tmp = std::floor(FaultModel_P.UniformRandomNumber4_Seed_e[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    FaultModel_DW.RandSeed_n[2] = tseed;
    FaultModel_DW.UniformRandomNumber4_NextOutp_p[2] =
      (FaultModel_P.UniformRandomNumber4_Maximum_c[2] -
       FaultModel_P.UniformRandomNumber4_Minimum_o[2]) *
      rt_urand_Upu32_Yd_f_pw_snf(&FaultModel_DW.RandSeed_n[2]) +
      FaultModel_P.UniformRandomNumber4_Minimum_o[2];

    // End of InitializeConditions for UniformRandomNumber: '<S327>/Uniform Random Number4' 

    // SystemInitialize for IfAction SubSystem: '<S192>/Negative Trace'
    // '<S188>:1:6' hFault=false;
    // '<S188>:1:9' fParam=zeros(20,1);
    // '<S186>:1:6' hFault=false;
    // '<S186>:1:9' fParam=zeros(20,1);
    // '<S187>:1:6' hFault=false;
    // '<S187>:1:9' fParam=zeros(20,1);
    // '<S189>:1:8' tOld=0;
    FaultModel_NegativeTrace_Init(&FaultModel_DW.NegativeTrace_d);

    // End of SystemInitialize for SubSystem: '<S192>/Negative Trace'

    // SystemInitialize for Merge: '<S192>/Merge'
    FaultModel_B.Merge[0] = FaultModel_P.Merge_InitialOutput_f[0];
    FaultModel_B.Merge[1] = FaultModel_P.Merge_InitialOutput_f[1];
    FaultModel_B.Merge[2] = FaultModel_P.Merge_InitialOutput_f[2];
    FaultModel_B.Merge[3] = FaultModel_P.Merge_InitialOutput_f[3];

    // SystemInitialize for IfAction SubSystem: '<S191>/Negative Trace'
    FaultModel_NegativeTrace_Init(&FaultModel_DW.NegativeTrace);

    // End of SystemInitialize for SubSystem: '<S191>/Negative Trace'

    // SystemInitialize for Merge: '<S191>/Merge'
    FaultModel_B.Merge_c[0] = FaultModel_P.Merge_InitialOutput_h[0];
    FaultModel_B.Merge_c[1] = FaultModel_P.Merge_InitialOutput_h[1];
    FaultModel_B.Merge_c[2] = FaultModel_P.Merge_InitialOutput_h[2];
    FaultModel_B.Merge_c[3] = FaultModel_P.Merge_InitialOutput_h[3];

    // SystemInitialize for MATLAB Function: '<Root>/CollisionDetection'
    FaultModel_DW.method_l = 7U;
    FaultModel_DW.state_m = 1144108930U;
    FaultModel_DW.state_fo[0] = 362436069U;
    FaultModel_DW.state_fo[1] = 521288629U;

    // SystemInitialize for MATLAB Function: '<S7>/Ground Model'
    // '<S3>:1:7' isCol=int8(0);
    // '<S3>:1:13' fOut=[0;0;0;0;0;0];
    // '<S3>:1:19' mv0=[0;0;0];
    // '<S3>:1:25' tColi=0;
    // '<S194>:1:11' takeoffFlag=int8(0);
    // '<S194>:1:16' landFlag=int8(1);
    FaultModel_DW.landFlag = 1;

    // SystemInitialize for MATLAB Function: '<Root>/Crash_Motor_Fault'
    // '<S296>:1:6' hFault=false;
    // '<S296>:1:9' fParam=zeros(20,1);
    // '<S297>:1:6' hFault=false;
    // '<S297>:1:9' fParam=zeros(20,1);
    FaultModel_DW.method_a = 7U;
    FaultModel_DW.state_c = 1144108930U;
    FaultModel_DW.state_f[0] = 362436069U;
    FaultModel_DW.state_f[1] = 521288629U;

    // SystemInitialize for Atomic SubSystem: '<S300>/MotorNonlinearDynamic1'
    // '<S56>:1:6' hFault=false;
    // '<S56>:1:9' fParam=zeros(20,1);
    // '<S57>:1:6' hFault=false;
    // '<S57>:1:9' fParam=zeros(20,1);
    // '<S58>:1:6' hFault=false;
    // '<S58>:1:9' fParam=zeros(20,1);
    // '<S59>:1:6' hFault=false;
    // '<S59>:1:9' fParam=zeros(20,1);
    // '<S60>:1:15' discharge = 0;
    // '<S60>:1:20' startTime = 0;
    // '<S60>:1:25' reset = 0;
    Fau_MotorNonlinearDynamic1_Init(&FaultModel_DW.MotorNonlinearDynamic1,
      &FaultModel_X.MotorNonlinearDynamic1);

    // End of SystemInitialize for SubSystem: '<S300>/MotorNonlinearDynamic1'

    // SystemInitialize for Atomic SubSystem: '<S300>/MotorNonlinearDynamic2'
    Fau_MotorNonlinearDynamic1_Init(&FaultModel_DW.MotorNonlinearDynamic2,
      &FaultModel_X.MotorNonlinearDynamic2);

    // End of SystemInitialize for SubSystem: '<S300>/MotorNonlinearDynamic2'

    // SystemInitialize for Atomic SubSystem: '<S300>/MotorNonlinearDynamic3'
    Fau_MotorNonlinearDynamic1_Init(&FaultModel_DW.MotorNonlinearDynamic3,
      &FaultModel_X.MotorNonlinearDynamic3);

    // End of SystemInitialize for SubSystem: '<S300>/MotorNonlinearDynamic3'

    // SystemInitialize for Atomic SubSystem: '<S300>/MotorNonlinearDynamic4'
    Fau_MotorNonlinearDynamic1_Init(&FaultModel_DW.MotorNonlinearDynamic4,
      &FaultModel_X.MotorNonlinearDynamic4);

    // End of SystemInitialize for SubSystem: '<S300>/MotorNonlinearDynamic4'

    // SystemInitialize for Atomic SubSystem: '<S300>/MotorNonlinearDynamic5'
    Fau_MotorNonlinearDynamic1_Init(&FaultModel_DW.MotorNonlinearDynamic5,
      &FaultModel_X.MotorNonlinearDynamic5);

    // End of SystemInitialize for SubSystem: '<S300>/MotorNonlinearDynamic5'

    // SystemInitialize for Atomic SubSystem: '<S300>/MotorNonlinearDynamic6'
    Fau_MotorNonlinearDynamic1_Init(&FaultModel_DW.MotorNonlinearDynamic6,
      &FaultModel_X.MotorNonlinearDynamic6);

    // End of SystemInitialize for SubSystem: '<S300>/MotorNonlinearDynamic6'

    // SystemInitialize for Atomic SubSystem: '<S300>/MotorNonlinearDynamic7'
    Fau_MotorNonlinearDynamic1_Init(&FaultModel_DW.MotorNonlinearDynamic7,
      &FaultModel_X.MotorNonlinearDynamic7);

    // End of SystemInitialize for SubSystem: '<S300>/MotorNonlinearDynamic7'

    // SystemInitialize for Atomic SubSystem: '<S300>/MotorNonlinearDynamic8'
    Fau_MotorNonlinearDynamic1_Init(&FaultModel_DW.MotorNonlinearDynamic8,
      &FaultModel_X.MotorNonlinearDynamic8);

    // End of SystemInitialize for SubSystem: '<S300>/MotorNonlinearDynamic8'

    // SystemInitialize for Enabled SubSystem: '<S120>/Hugw(z)'
    // '<S68>:1:6' hFault=false;
    // '<S68>:1:9' fParam=zeros(20,1);
    // '<S64>:1:6' hFault=false;
    // '<S64>:1:9' fParam=zeros(20,1);
    // '<S65>:1:6' hFault=false;
    // '<S65>:1:9' fParam=zeros(20,1);
    // '<S66>:1:6' hFault=false;
    // '<S66>:1:9' fParam=zeros(20,1);
    // '<S67>:1:6' hFault=false;
    // '<S67>:1:9' fParam=zeros(20,1);
    FaultModel_Hugwz_Init(&FaultModel_B.Hugwz_i, &FaultModel_DW.Hugwz_i,
                          &FaultModel_P.Hugwz_i);

    // End of SystemInitialize for SubSystem: '<S120>/Hugw(z)'

    // SystemInitialize for Enabled SubSystem: '<S120>/Hvgw(z)'
    FaultModel_Hvgwz_Init(&FaultModel_B.Hvgwz_p, &FaultModel_DW.Hvgwz_p,
                          &FaultModel_P.Hvgwz_p);

    // End of SystemInitialize for SubSystem: '<S120>/Hvgw(z)'

    // SystemInitialize for Enabled SubSystem: '<S120>/Hwgw(z)'
    FaultModel_Hwgwz_Init(&FaultModel_B.Hwgwz_a, &FaultModel_DW.Hwgwz_a,
                          &FaultModel_P.Hwgwz_a);

    // End of SystemInitialize for SubSystem: '<S120>/Hwgw(z)'

    // SystemInitialize for MATLAB Function: '<S61>/MATLAB Function'
    FaultModel_DW.method = 7U;
    FaultModel_DW.state = 1144108930U;
    FaultModel_DW.state_k[0] = 362436069U;
    FaultModel_DW.state_k[1] = 521288629U;

    // '<S71>:1:12' t0=0;
    // '<S71>:1:17' isInGust=0;
    // '<S71>:1:22' t1=2;
    FaultModel_DW.t1 = 2.0;

    // '<S71>:1:27' a=0.5;
    FaultModel_DW.a = 0.5;

    // '<S71>:1:32' ang=pi/2;
    FaultModel_DW.ang = 1.5707963267948966;

    // SystemInitialize for Enabled SubSystem: '<S81>/Hugw(z)'
    FaultModel_Hugwz_Init(&FaultModel_B.Hugwz, &FaultModel_DW.Hugwz,
                          &FaultModel_P.Hugwz);

    // End of SystemInitialize for SubSystem: '<S81>/Hugw(z)'

    // SystemInitialize for Enabled SubSystem: '<S81>/Hvgw(z)'
    FaultModel_Hvgwz_Init(&FaultModel_B.Hvgwz, &FaultModel_DW.Hvgwz,
                          &FaultModel_P.Hvgwz);

    // End of SystemInitialize for SubSystem: '<S81>/Hvgw(z)'

    // SystemInitialize for Enabled SubSystem: '<S81>/Hwgw(z)'
    FaultModel_Hwgwz_Init(&FaultModel_B.Hwgwz, &FaultModel_DW.Hwgwz,
                          &FaultModel_P.Hwgwz);

    // End of SystemInitialize for SubSystem: '<S81>/Hwgw(z)'

    // SystemInitialize for Enabled SubSystem: '<S450>/Convert from geodetic to  spherical coordinates ' 
    // SystemInitialize for Iterator SubSystem: '<S460>/For Iterator Subsystem'
    // InitializeConditions for UnitDelay: '<S507>/Unit Delay1'
    // '<S287>:1:6' hFault=false;
    // '<S287>:1:9' fParam=zeros(20,1);
    // '<S404>:1:6' hFault=false;
    // '<S404>:1:9' fParam=zeros(20,1);
    // '<S405>:1:6' hFault=false;
    // '<S405>:1:9' fParam=zeros(20,1);
    FaultModel_DW.UnitDelay1_DSTATE[0] =
      FaultModel_P.UnitDelay1_InitialCondition_l;
    FaultModel_DW.UnitDelay1_DSTATE[1] =
      FaultModel_P.UnitDelay1_InitialCondition_l;

    // End of SystemInitialize for SubSystem: '<S460>/For Iterator Subsystem'

    // SystemInitialize for SignalConversion generated from: '<S460>/sp[13]' incorporates:
    //   Outport: '<S460>/sp[13]'

    std::memcpy(&FaultModel_B.OutportBufferForsp13[0], &FaultModel_P.sp13_Y0[0],
                13U * sizeof(real_T));

    // SystemInitialize for SignalConversion generated from: '<S460>/cp[13]' incorporates:
    //   Outport: '<S460>/cp[13]'

    std::memcpy(&FaultModel_B.OutportBufferForcp13[0], &FaultModel_P.cp13_Y0[0],
                13U * sizeof(real_T));

    // End of SystemInitialize for SubSystem: '<S450>/Convert from geodetic to  spherical coordinates ' 

    // SystemInitialize for Enabled SubSystem: '<S450>/Convert from geodetic to  spherical coordinates' 
    // SystemInitialize for Sqrt: '<S459>/sqrt' incorporates:
    //   Outport: '<S459>/r'

    FaultModel_B.sqrt_c = FaultModel_P.r_Y0;

    // SystemInitialize for Product: '<S500>/Product4' incorporates:
    //   Outport: '<S459>/ct'

    FaultModel_B.Product4_d = FaultModel_P.ct_Y0;

    // SystemInitialize for Sqrt: '<S506>/sqrt' incorporates:
    //   Outport: '<S459>/st'

    FaultModel_B.sqrt_m = FaultModel_P.st_Y0;

    // SystemInitialize for Product: '<S505>/Product12' incorporates:
    //   Outport: '<S459>/sa'

    FaultModel_B.Product12 = FaultModel_P.sa_Y0;

    // SystemInitialize for Product: '<S499>/Product11' incorporates:
    //   Outport: '<S459>/ca'

    FaultModel_B.Product11 = FaultModel_P.ca_Y0;

    // End of SystemInitialize for SubSystem: '<S450>/Convert from geodetic to  spherical coordinates' 

    // SystemInitialize for Iterator SubSystem: '<S450>/Compute magnetic vector in spherical coordinates' 
    // SystemInitialize for Iterator SubSystem: '<S458>/For Iterator Subsystem'
    // SystemInitialize for Enabled SubSystem: '<S466>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' 
    // SystemInitialize for Merge: '<S468>/Merge1'
    FaultModel_B.Merge1_o = FaultModel_P.Merge1_InitialOutput;

    // SystemInitialize for Merge: '<S468>/Merge'
    FaultModel_B.Merge_m = FaultModel_P.Merge_InitialOutput;

    // End of SystemInitialize for SubSystem: '<S466>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' 

    // SystemInitialize for Enabled SubSystem: '<S466>/Time adjust the gauss coefficients' 
    // InitializeConditions for UnitDelay: '<S469>/Unit Delay'
    std::memcpy(&FaultModel_DW.UnitDelay_DSTATE_d[0],
                &FaultModel_P.UnitDelay_InitialCondition_g[0], 169U * sizeof
                (real_T));

    // InitializeConditions for UnitDelay: '<S496>/Unit Delay'
    std::memcpy(&FaultModel_DW.UnitDelay_DSTATE_n[0],
                &FaultModel_P.UnitDelay_InitialCondition_k[0], 169U * sizeof
                (real_T));

    // SystemInitialize for Sum: '<S469>/Sum2' incorporates:
    //   Outport: '<S469>/tc[13][13]'

    std::memcpy(&FaultModel_B.Sum2_l[0], &FaultModel_P.tc1313_Y0[0], 169U *
                sizeof(real_T));

    // End of SystemInitialize for SubSystem: '<S466>/Time adjust the gauss coefficients' 

    // SystemInitialize for Enabled SubSystem: '<S466>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' 
    // InitializeConditions for UnitDelay: '<S468>/Unit Delay'
    std::memcpy(&FaultModel_DW.UnitDelay_DSTATE_e[0],
                &FaultModel_P.UnitDelay_InitialCondition[0], 169U * sizeof
                (real_T));

    // InitializeConditions for UnitDelay: '<S468>/Unit Delay1'
    std::memcpy(&FaultModel_DW.UnitDelay1_DSTATE_b[0],
                &FaultModel_P.UnitDelay1_InitialCondition_k[0], 169U * sizeof
                (real_T));

    // SystemInitialize for Assignment: '<S468>/Assignment' incorporates:
    //   Outport: '<S468>/dp[13][13]'

    std::memcpy(&FaultModel_B.Assignment_k[0], &FaultModel_P.dp1313_Y0[0], 169U *
                sizeof(real_T));

    // SystemInitialize for Assignment: '<S468>/Assignment_snorm' incorporates:
    //   Outport: '<S468>/snorm[169]'

    std::memcpy(&FaultModel_B.Assignment_snorm[0], &FaultModel_P.snorm169_Y0[0],
                169U * sizeof(real_T));

    // End of SystemInitialize for SubSystem: '<S466>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' 

    // SystemInitialize for Enabled SubSystem: '<S467>/Special case - North//South Geographic Pole' 
    // InitializeConditions for UnitDelay: '<S470>/Unit Delay1'
    std::memcpy(&FaultModel_DW.UnitDelay1_DSTATE_o[0],
                &FaultModel_P.UnitDelay1_InitialCondition[0], 13U * sizeof
                (real_T));

    // SystemInitialize for IfAction SubSystem: '<S470>/If Action Subsystem1'
    // SystemInitialize for Assignment: '<S474>/Assignment2' incorporates:
    //   Outport: '<S474>/pp[13]'

    std::memcpy(&FaultModel_B.Assignment2_j[0], &FaultModel_P.pp13_Y0[0], 13U *
                sizeof(real_T));

    // End of SystemInitialize for SubSystem: '<S470>/If Action Subsystem1'

    // SystemInitialize for IfAction SubSystem: '<S470>/If Action Subsystem2'
    // SystemInitialize for Assignment: '<S475>/Assignment2' incorporates:
    //   Outport: '<S475>/pp[13]'

    std::memcpy(&FaultModel_B.Assignment2_i[0], &FaultModel_P.pp13_Y0_j[0], 13U *
                sizeof(real_T));

    // End of SystemInitialize for SubSystem: '<S470>/If Action Subsystem2'

    // SystemInitialize for Product: '<S470>/Product2' incorporates:
    //   Outport: '<S470>/bpp'

    FaultModel_B.Product2_b = FaultModel_P.bpp_Y0;

    // End of SystemInitialize for SubSystem: '<S467>/Special case - North//South Geographic Pole' 

    // SystemInitialize for Sum: '<S467>/Sum1' incorporates:
    //   Outport: '<S466>/bt'

    FaultModel_B.Sum1_b = FaultModel_P.bt_Y0;

    // SystemInitialize for Sum: '<S467>/Sum2' incorporates:
    //   Outport: '<S466>/bp'

    FaultModel_B.Sum2_a = FaultModel_P.bp_Y0;

    // SystemInitialize for Sum: '<S467>/Sum3' incorporates:
    //   Outport: '<S466>/br'

    FaultModel_B.Sum3 = FaultModel_P.br_Y0;

    // SystemInitialize for Sum: '<S467>/Sum5' incorporates:
    //   Outport: '<S466>/bpp'

    FaultModel_B.Sum5 = FaultModel_P.bpp_Y0_l;

    // End of SystemInitialize for SubSystem: '<S458>/For Iterator Subsystem'

    // SystemInitialize for Sum: '<S458>/Sum1' incorporates:
    //   Outport: '<S458>/bt,bp,br,bpp'

    FaultModel_B.Sum1_n[0] = FaultModel_P.btbpbrbpp_Y0[0];
    FaultModel_B.Sum1_n[1] = FaultModel_P.btbpbrbpp_Y0[1];
    FaultModel_B.Sum1_n[2] = FaultModel_P.btbpbrbpp_Y0[2];
    FaultModel_B.Sum1_n[3] = FaultModel_P.btbpbrbpp_Y0[3];

    // End of SystemInitialize for SubSystem: '<S450>/Compute magnetic vector in spherical coordinates' 

    // SystemInitialize for IfAction SubSystem: '<S326>/Negative Trace'
    // '<S406>:1:6' hFault=false;
    // '<S406>:1:9' fParam=zeros(20,1);
    // '<S407>:1:6' hFault=false;
    // '<S407>:1:9' fParam=zeros(20,1);
    FaultModel_NegativeTrace_Init(&FaultModel_DW.NegativeTrace_l);

    // End of SystemInitialize for SubSystem: '<S326>/Negative Trace'

    // SystemInitialize for Merge: '<S326>/Merge'
    FaultModel_B.Merge_f[0] = FaultModel_P.Merge_InitialOutput_fc[0];
    FaultModel_B.Merge_f[1] = FaultModel_P.Merge_InitialOutput_fc[1];
    FaultModel_B.Merge_f[2] = FaultModel_P.Merge_InitialOutput_fc[2];
    FaultModel_B.Merge_f[3] = FaultModel_P.Merge_InitialOutput_fc[3];

    // SystemInitialize for Enabled SubSystem: '<S80>/Hpgw'
    // '<S372>:1:6' hFault=false;
    // '<S372>:1:9' fParam=zeros(20,1);
    // '<S330>:1:5' xTemp=zeros(8,1);
    // '<S330>:1:10' kk=0;
    // '<S330>:1:15' ss=zeros(6,1);
    FaultModel_Hpgw_Init(&FaultModel_B.Hpgw, &FaultModel_DW.Hpgw,
                         &FaultModel_P.Hpgw);

    // End of SystemInitialize for SubSystem: '<S80>/Hpgw'

    // SystemInitialize for Enabled SubSystem: '<S80>/Hqgw'
    FaultModel_Hqgw_Init(&FaultModel_B.Hqgw, &FaultModel_DW.Hqgw,
                         &FaultModel_P.Hqgw);

    // End of SystemInitialize for SubSystem: '<S80>/Hqgw'

    // SystemInitialize for Enabled SubSystem: '<S80>/Hrgw'
    FaultModel_Hrgw_Init(&FaultModel_B.Hrgw, &FaultModel_DW.Hrgw,
                         &FaultModel_P.Hrgw);

    // End of SystemInitialize for SubSystem: '<S80>/Hrgw'

    // SystemInitialize for Enabled SubSystem: '<S119>/Hpgw'
    FaultModel_Hpgw_Init(&FaultModel_B.Hpgw_c, &FaultModel_DW.Hpgw_c,
                         &FaultModel_P.Hpgw_c);

    // End of SystemInitialize for SubSystem: '<S119>/Hpgw'

    // SystemInitialize for Enabled SubSystem: '<S119>/Hqgw'
    FaultModel_Hqgw_Init(&FaultModel_B.Hqgw_b, &FaultModel_DW.Hqgw_b,
                         &FaultModel_P.Hqgw_b);

    // End of SystemInitialize for SubSystem: '<S119>/Hqgw'

    // SystemInitialize for Enabled SubSystem: '<S119>/Hrgw'
    FaultModel_Hrgw_Init(&FaultModel_B.Hrgw_g, &FaultModel_DW.Hrgw_g,
                         &FaultModel_P.Hrgw_g);

    // End of SystemInitialize for SubSystem: '<S119>/Hrgw'
  }

  // set "at time zero" to false
  if (rtmIsFirstInitCond((&FaultModel_M))) {
    rtmSetFirstInitCond((&FaultModel_M), 0);
  }
}

// Model terminate function
void MulticopterModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
MulticopterModelClass::MulticopterModelClass() :
  FaultModel_U(),
  FaultModel_Y(),
  FaultModel_B(),
  FaultModel_DW(),
  FaultModel_X(),
  FaultModel_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
MulticopterModelClass::~MulticopterModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_FaultModel_T * MulticopterModelClass::getRTM()
{
  return (&FaultModel_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
