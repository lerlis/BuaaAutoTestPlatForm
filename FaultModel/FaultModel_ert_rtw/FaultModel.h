//
// File: FaultModel.h
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
#ifndef RTW_HEADER_FaultModel_h_
#define RTW_HEADER_FaultModel_h_
#include "rtwtypes.h"
#include <stddef.h>
#include <cmath>
#include <cfloat>
#include <cstring>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

// Model Code Variants

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Forward declaration for rtModel
typedef struct tag_RTM_FaultModel_T RT_MODEL_FaultModel_T;

#ifndef DEFINED_TYPEDEF_FOR_MavVehileInfo_
#define DEFINED_TYPEDEF_FOR_MavVehileInfo_

typedef struct {
  int32_T copterID;
  int32_T vehicleType;
  real_T runnedTime;
  real32_T VelE[3];
  real32_T PosE[3];
  real32_T AngEuler[3];
  real32_T AngQuatern[4];
  real32_T MotorRPMS[8];
  real32_T AccB[3];
  real32_T RateB[3];
  real_T PosGPS[3];
} MavVehileInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MavLinkGPS_
#define DEFINED_TYPEDEF_FOR_MavLinkGPS_

typedef struct {
  uint32_T time_usec;
  int32_T lat;
  int32_T lon;
  int32_T alt;
  uint16_T eph;
  uint16_T epv;
  uint16_T vel;
  int16_T vn;
  int16_T ve;
  int16_T vd;
  uint16_T cog;
  uint8_T fix_type;
  uint8_T satellites_visible;
} MavLinkGPS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HILGPS_
#define DEFINED_TYPEDEF_FOR_HILGPS_

typedef struct {
  uint8_T fix_type;
  uint8_T satellites_visible;
  int32_T lat;
  int32_T lon;
  int32_T alt;
  uint32_T hAcc;
  uint32_T vAcc;
  int32_T velN;
  int32_T velE;
  int32_T velD;
  int32_T gSpeed;
  int32_T headMot;
  int32_T headVeh;
} HILGPS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MavLinkSensor_
#define DEFINED_TYPEDEF_FOR_MavLinkSensor_

typedef struct {
  uint32_T time_usec;
  real32_T xacc;
  real32_T yacc;
  real32_T zacc;
  real32_T xgyro;
  real32_T ygyro;
  real32_T zgyro;
  real32_T xmag;
  real32_T ymag;
  real32_T zmag;
  real32_T abs_pressure;
  real32_T diff_pressure;
  real32_T pressure_alt;
  real32_T temperature;
  uint32_T fields_updated;
} MavLinkSensor;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MavLinkStateQuat_
#define DEFINED_TYPEDEF_FOR_MavLinkStateQuat_

typedef struct {
  uint32_T time_usec;
  real32_T attitude_quaternion[4];
  real32_T rollspeed;
  real32_T pitchspeed;
  real32_T yawspeed;
  int32_T lat;
  int32_T lon;
  int32_T alt;
  int16_T vx;
  int16_T vy;
  int16_T vz;
  uint16_T ind_airspeed;
  uint16_T true_airspeed;
  int16_T xacc;
  int16_T yacc;
  int16_T zacc;
} MavLinkStateQuat;

#endif

// Block signals for system '<S80>/Hpgw'
typedef struct {
  real_T UnitDelay[2];                 // '<S91>/Unit Delay'
  real_T Sum[2];                       // '<S91>/Sum'
} B_Hpgw_FaultModel_T;

// Block states (default storage) for system '<S80>/Hpgw'
typedef struct {
  real_T UnitDelay_DSTATE[2];          // '<S91>/Unit Delay'
  boolean_T Hpgw_MODE;                 // '<S80>/Hpgw'
} DW_Hpgw_FaultModel_T;

// Block signals for system '<S80>/Hqgw'
typedef struct {
  real_T dt1;                          // '<S92>/dt1'
  real_T Sum2;                         // '<S92>/Sum2'
  real_T LugV2[2];                     // '<S92>/Lug//V2'
  real_T UnitDelay1[2];                // '<S92>/Unit Delay1'
  real_T Sum1[2];                      // '<S92>/Sum1'
} B_Hqgw_FaultModel_T;

// Block states (default storage) for system '<S80>/Hqgw'
typedef struct {
  real_T UnitDelay_DSTATE[2];          // '<S92>/Unit Delay'
  real_T UnitDelay1_DSTATE[2];         // '<S92>/Unit Delay1'
  boolean_T Hqgw_MODE;                 // '<S80>/Hqgw'
} DW_Hqgw_FaultModel_T;

// Block signals for system '<S80>/Hrgw'
typedef struct {
  real_T dt1;                          // '<S93>/dt1'
  real_T Sum2;                         // '<S93>/Sum2'
  real_T LugV2[2];                     // '<S93>/Lug//V2'
  real_T UnitDelay1[2];                // '<S93>/Unit Delay1'
  real_T Sum1[2];                      // '<S93>/Sum1'
} B_Hrgw_FaultModel_T;

// Block states (default storage) for system '<S80>/Hrgw'
typedef struct {
  real_T UnitDelay_DSTATE[2];          // '<S93>/Unit Delay'
  real_T UnitDelay1_DSTATE[2];         // '<S93>/Unit Delay1'
  boolean_T Hrgw_MODE;                 // '<S80>/Hrgw'
} DW_Hrgw_FaultModel_T;

// Block signals for system '<S81>/Hugw(z)'
typedef struct {
  real_T UnitDelay[2];                 // '<S94>/Unit Delay'
  real_T Sum[2];                       // '<S94>/Sum'
} B_Hugwz_FaultModel_T;

// Block states (default storage) for system '<S81>/Hugw(z)'
typedef struct {
  real_T UnitDelay_DSTATE[2];          // '<S94>/Unit Delay'
  boolean_T Hugwz_MODE;                // '<S81>/Hugw(z)'
} DW_Hugwz_FaultModel_T;

// Block signals for system '<S81>/Hvgw(z)'
typedef struct {
  real_T UnitDelay[2];                 // '<S95>/Unit Delay'
  real_T Sum[2];                       // '<S95>/Sum'
} B_Hvgwz_FaultModel_T;

// Block states (default storage) for system '<S81>/Hvgw(z)'
typedef struct {
  real_T UnitDelay_DSTATE[2];          // '<S95>/Unit Delay'
  boolean_T Hvgwz_MODE;                // '<S81>/Hvgw(z)'
} DW_Hvgwz_FaultModel_T;

// Block signals for system '<S81>/Hwgw(z)'
typedef struct {
  real_T UnitDelay[2];                 // '<S96>/Unit Delay'
  real_T Sum[2];                       // '<S96>/Sum'
} B_Hwgwz_FaultModel_T;

// Block states (default storage) for system '<S81>/Hwgw(z)'
typedef struct {
  real_T UnitDelay_DSTATE[2];          // '<S96>/Unit Delay'
  boolean_T Hwgwz_MODE;                // '<S81>/Hwgw(z)'
} DW_Hwgwz_FaultModel_T;

// Block signals for system '<S85>/Interpolate  rates'
typedef struct {
  real_T Sum;                          // '<S99>/Sum'
} B_Interpolaterates_FaultModel_T;

// Block signals for system '<S86>/Interpolate  velocities'
typedef struct {
  real_T Sum;                          // '<S107>/Sum'
} B_Interpolatevelocities_Fault_T;

// Block states (default storage) for system '<S191>/Negative Trace'
typedef struct {
  int8_T FindMaximumDiagonalValue_Active;// '<S200>/Find Maximum Diagonal Value' 
} DW_NegativeTrace_FaultModel_T;

// Block signals for system '<S302>/Motor_Dynamics'
typedef struct {
  real_T x;                            // '<S311>/Integrator'
  real_T dratedt;                      // '<S311>/Divide'
} B_Motor_Dynamics_FaultModel_T;

// Block states (default storage) for system '<S302>/Motor_Dynamics'
typedef struct {
  int_T Integrator_IWORK;              // '<S311>/Integrator'
} DW_Motor_Dynamics_FaultModel_T;

// Continuous states for system '<S302>/Motor_Dynamics'
typedef struct {
  real_T Integrator_CSTATE;            // '<S311>/Integrator'
} X_Motor_Dynamics_FaultModel_T;

// State derivatives for system '<S302>/Motor_Dynamics'
typedef struct {
  real_T Integrator_CSTATE;            // '<S311>/Integrator'
} XDot_Motor_Dynamics_FaultMode_T;

// State Disabled for system '<S302>/Motor_Dynamics'
typedef struct {
  boolean_T Integrator_CSTATE;         // '<S311>/Integrator'
} XDis_Motor_Dynamics_FaultMode_T;

// Block signals for system '<S300>/MotorNonlinearDynamic1'
typedef struct {
  real_T Product;                      // '<S302>/Product'
  B_Motor_Dynamics_FaultModel_T Motor_Dynamics;// '<S302>/Motor_Dynamics'
} B_MotorNonlinearDynamic1_Faul_T;

// Block states (default storage) for system '<S300>/MotorNonlinearDynamic1'
typedef struct {
  DW_Motor_Dynamics_FaultModel_T Motor_Dynamics;// '<S302>/Motor_Dynamics'
} DW_MotorNonlinearDynamic1_Fau_T;

// Continuous states for system '<S300>/MotorNonlinearDynamic1'
typedef struct {
  X_Motor_Dynamics_FaultModel_T Motor_Dynamics;// '<S302>/Motor_Dynamics'
} X_MotorNonlinearDynamic1_Faul_T;

// State derivatives for system '<S300>/MotorNonlinearDynamic1'
typedef struct {
  XDot_Motor_Dynamics_FaultMode_T Motor_Dynamics;// '<S302>/Motor_Dynamics'
} XDot_MotorNonlinearDynamic1_F_T;

// State Disabled for system '<S300>/MotorNonlinearDynamic1'
typedef struct {
  XDis_Motor_Dynamics_FaultMode_T Motor_Dynamics;// '<S302>/Motor_Dynamics'
} XDis_MotorNonlinearDynamic1_F_T;

// Block signals for system '<S401>/Acc Fun'
typedef struct {
  real_T y[3];                         // '<S401>/Acc Fun'
  real_T y_scale[3];                   // '<S401>/Acc Fun'
} B_AccFun_FaultModel_T;

// Block signals (default storage)
typedef struct {
  real_T q0;                           // '<S23>/q0'
  real_T q1;                           // '<S23>/q1'
  real_T q2;                           // '<S23>/q2'
  real_T q3;                           // '<S23>/q3'
  real_T m;                            // '<S185>/Add5'
  real_T SinCos_o1;                    // '<S159>/SinCos'
  real_T SinCos_o2;                    // '<S159>/SinCos'
  real_T Switch;                       // '<S167>/Switch'
  real_T TrigonometricFunction1;       // '<S173>/Trigonometric Function1'
  real_T TrigonometricFunction2;       // '<S173>/Trigonometric Function2'
  real_T Switch_d;                     // '<S168>/Switch'
  real_T MatrixConcatenate[3];         // '<S76>/Matrix Concatenate'
  real_T Product[3];                   // '<S20>/Product'
  real_T Merge[4];                     // '<S192>/Merge'
  real_T Merge_c[4];                   // '<S191>/Merge'
  real_T DataTypeConversion2[20];      // '<Root>/Data Type Conversion2'
  real_T ModelInit_RPM;                // '<S300>/ModelInit_RPM'
  real_T MotorFault3;                  // '<S55>/MotorFault3'
  real_T UniformRandomNumber[3];       // '<S61>/Uniform Random Number'
  real_T Sum1[3];                      // '<S61>/Sum1'
  real_T UnitConversion;               // '<S127>/Unit Conversion'
  real_T UnitConversion_j;             // '<S156>/Unit Conversion'
  real_T sigma_wg;                     // '<S137>/sigma_wg '
  real_T PreLookUpIndexSearchprobofexcee;
                          // '<S136>/PreLook-Up Index Search  (prob of exceed)'
  real_T Product_k[4];                 // '<S129>/Product'
  real_T UnitConversion_h;             // '<S118>/Unit Conversion'
  real_T UnitConversion_b;             // '<S88>/Unit Conversion'
  real_T UnitConversion_f;             // '<S117>/Unit Conversion'
  real_T sigma_wg_a;                   // '<S98>/sigma_wg '
  real_T PreLookUpIndexSearchprobofexc_p;
                           // '<S97>/PreLook-Up Index Search  (prob of exceed)'
  real_T Product_n[4];                 // '<S90>/Product'
  real_T UnitConversion_e;             // '<S79>/Unit Conversion'
  real_T lnref_heightz0;               // '<S77>/ln(ref_height//z0)'
  real_T Windspeedatreferenceheight[3];
                                      // '<S77>/Wind speed at reference height'
  real_T Transpose[3];                 // '<S7>/Transpose'
  real_T Gain[3];                      // '<S423>/Gain'
  real_T Selector1[9];                 // '<S14>/Selector1'
  real_T Selector[9];                  // '<S14>/Selector'
  real_T Selector2[9];                 // '<S14>/Selector2'
  real_T Product2[3];                  // '<S14>/Product2'
  real_T Gain10[3];                    // '<S400>/Gain10'
  real_T Gain6[3];                     // '<S400>/Gain6'
  real_T Switch_f;                     // '<S453>/Switch'
  real_T Switch_e;                     // '<S452>/Switch'
  real_T sincos_o1[2];                 // '<S461>/sincos'
  real_T sincos_o2[2];                 // '<S461>/sincos'
  real_T olat;                         // '<S462>/olat'
  real_T Gain_o;                       // '<S416>/Gain'
  real_T oalt;                         // '<S462>/oalt'
  real_T Gain11[3];                    // '<S400>/Gain11'
  real_T Product4;                     // '<S410>/Product4'
  real_T Gain7;                        // '<S400>/Gain7'
  real_T Product4_g;                   // '<S411>/Product4'
  real_T Merge_f[4];                   // '<S326>/Merge'
  real_T BiasGain2[3];                 // '<S327>/BiasGain2'
  real_T SinCos_o1_a;                  // '<S380>/SinCos'
  real_T SinCos_o2_g;                  // '<S380>/SinCos'
  real_T Switch_o;                     // '<S388>/Switch'
  real_T TrigonometricFunction1_f;     // '<S394>/Trigonometric Function1'
  real_T TrigonometricFunction2_f;     // '<S394>/Trigonometric Function2'
  real_T Switch_d4;                    // '<S389>/Switch'
  real_T SumofElements[3];             // '<S51>/Sum of Elements'
  real_T Sum_p[3];                     // '<S12>/Sum'
  real_T TmpSignalConversionAtq0q1q2q3_c[4];// '<S13>/qdot'
  real_T UnitConversion_a;             // '<S83>/Unit Conversion'
  real_T UnitConversion_ez;            // '<S122>/Unit Conversion'
  real_T BiasGain1[3];                 // '<S327>/BiasGain1'
  real_T Sum2[3];                      // '<S429>/Sum2'
  real_T Sum2_f[3];                    // '<S440>/Sum2'
  real_T y;                            // '<S400>/baro NoiseFun'
  real_T y_scale;                      // '<S400>/baro NoiseFun'
  real_T Gain_b[11];                   // '<S460>/Gain'
  real_T Gain1[11];                    // '<S460>/Gain1'
  real_T OutportBufferForcp13[13];
  real_T OutportBufferForsp13[13];
  real_T b2;                           // '<S459>/b2'
  real_T a2;                           // '<S459>/a2'
  real_T c2;                           // '<S502>/Sum1'
  real_T a4;                           // '<S504>/a4'
  real_T c4;                           // '<S504>/Sum9'
  real_T sqrt_c;                       // '<S459>/sqrt'
  real_T Product11;                    // '<S499>/Product11'
  real_T Product4_d;                   // '<S500>/Product4'
  real_T c2_e;                         // '<S505>/Sum1'
  real_T Product12;                    // '<S505>/Product12'
  real_T sqrt_m;                       // '<S506>/sqrt'
  real_T Sum1_n[4];                    // '<S458>/Sum1'
  real_T Sum1_b;                       // '<S467>/Sum1'
  real_T Sum2_a;                       // '<S467>/Sum2'
  real_T Sum3;                         // '<S467>/Sum3'
  real_T Sum5;                         // '<S467>/Sum5'
  real_T Assignment[169];              // '<S469>/Assignment'
  real_T Sum2_l[169];                  // '<S469>/Sum2'
  real_T Assignment2[169];             // '<S497>/Assignment2'
  real_T Merge1_o;                     // '<S468>/Merge1'
  real_T Assignment_k[169];            // '<S468>/Assignment'
  real_T Merge_m;                      // '<S468>/Merge'
  real_T Assignment_snorm[169];        // '<S468>/Assignment_snorm'
  real_T Product2_b;                   // '<S470>/Product2'
  real_T Assignment2_i[13];            // '<S475>/Assignment2'
  real_T Assignment2_j[13];            // '<S474>/Assignment2'
  real_T y_d[3];                       // '<S414>/Mag Fun'
  real_T y_scale_l[3];                 // '<S414>/Mag Fun'
  real_T lat_p_param;                  // '<S327>/FaultParamsExtract1'
  real_T lon_p_param;                  // '<S327>/FaultParamsExtract1'
  real_T alt_p_param;                  // '<S327>/FaultParamsExtract1'
  real_T y_n[3];                       // '<S371>/Acc NoiseFun'
  real_T y_k;                          // '<Root>/MATLAB Function'
  real_T y_j[8];                       // '<S286>/PropFaultModel'
  real_T F1[3];                        // '<S7>/Ground Model'
  real_T M1[3];                        // '<S7>/Ground Model'
  real_T deltaM[3];                    // '<S185>/Model Failure'
  real_T gWind[3];                     // '<S61>/MATLAB Function'
  real_T FaultParam[20];               // '<S61>/FaultParamsExtract3'
  real_T FaultParam_k[20];             // '<S61>/FaultParamsExtract2'
  real_T FaultParam_i[20];             // '<S61>/FaultParamsExtract1'
  real_T FaultParam_e[20];             // '<S61>/FaultParamsExtract'
  real_T y_m[8];                       // '<Root>/Crash_Motor_Fault'
  real_T fm[6];                        // '<Root>/CollisionDetection'
  real_T FaultParam_m[20];             // '<S55>/FaultParamsExtract3'
  real_T FaultParam_ei[20];            // '<S55>/FaultParamsExtract2'
  real_T FaultParam_o[20];             // '<S55>/FaultParamsExtract'
  real_T Merge_e;                      // '<S40>/Merge'
  uint32_T PreLookUpIndexSearchprobofex_pz;
                          // '<S136>/PreLook-Up Index Search  (prob of exceed)'
  uint32_T PreLookUpIndexSearchprobofexc_o;
                           // '<S97>/PreLook-Up Index Search  (prob of exceed)'
  uint32_T fields_updated;             // '<S400>/Data Type Conversion6'
  uint32_T hAcc;                       // '<S327>/Data Type Conversion14'
  uint32_T vAcc;                       // '<S327>/Data Type Conversion15'
  int32_T copterID;                    // '<S11>/Data Type Conversion'
  int32_T vehicleType;                 // '<S11>/Data Type Conversion2'
  uint16_T eph;                        // '<S327>/Data Type Conversion8'
  uint16_T epv;                        // '<S327>/Data Type Conversion9'
  uint8_T fix_type;                    // '<S327>/Data Type Conversion10'
  uint8_T satellites_visible;          // '<S327>/Data Type Conversion11'
  int8_T isCrash;                      // '<Root>/CollisionDetection'
  boolean_T hasFault_SheerWind;        // '<S61>/FaultParamsExtract3'
  boolean_T hasFault_TurbWind;         // '<S61>/FaultParamsExtract2'
  boolean_T hasFault_GustWind;         // '<S61>/FaultParamsExtract1'
  boolean_T hasFault_ConstWind;        // '<S61>/FaultParamsExtract'
  boolean_T hasFault_islowCapacity;    // '<S55>/FaultParamsExtract3'
  boolean_T hasFault_isLowVoltage;     // '<S55>/FaultParamsExtract2'
  boolean_T hasFault_isPowOff;         // '<S55>/FaultParamsExtract1'
  boolean_T hasFault_isUseCustomHovTime;// '<S55>/FaultParamsExtract'
  B_AccFun_FaultModel_T sf_GyroFun;    // '<S409>/Gyro Fun'
  B_AccFun_FaultModel_T sf_AccFun;     // '<S401>/Acc Fun'
  B_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic8;// '<S300>/MotorNonlinearDynamic8' 
  B_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic7;// '<S300>/MotorNonlinearDynamic7' 
  B_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic6;// '<S300>/MotorNonlinearDynamic6' 
  B_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic5;// '<S300>/MotorNonlinearDynamic5' 
  B_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic4;// '<S300>/MotorNonlinearDynamic4' 
  B_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic3;// '<S300>/MotorNonlinearDynamic3' 
  B_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic2;// '<S300>/MotorNonlinearDynamic2' 
  B_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic1;// '<S300>/MotorNonlinearDynamic1' 
  B_Interpolatevelocities_Fault_T Interpolatevelocities_p;// '<S125>/Interpolate  velocities' 
  B_Interpolaterates_FaultModel_T Interpolaterates_j;// '<S124>/Interpolate  rates' 
  B_Hwgwz_FaultModel_T Hwgwz_a;        // '<S120>/Hwgw(z)'
  B_Hvgwz_FaultModel_T Hvgwz_p;        // '<S120>/Hvgw(z)'
  B_Hugwz_FaultModel_T Hugwz_i;        // '<S120>/Hugw(z)'
  B_Hrgw_FaultModel_T Hrgw_g;          // '<S119>/Hrgw'
  B_Hqgw_FaultModel_T Hqgw_b;          // '<S119>/Hqgw'
  B_Hpgw_FaultModel_T Hpgw_c;          // '<S119>/Hpgw'
  B_Interpolatevelocities_Fault_T Interpolatevelocities;// '<S86>/Interpolate  velocities' 
  B_Interpolaterates_FaultModel_T Interpolaterates;// '<S85>/Interpolate  rates' 
  B_Hwgwz_FaultModel_T Hwgwz;          // '<S81>/Hwgw(z)'
  B_Hvgwz_FaultModel_T Hvgwz;          // '<S81>/Hvgw(z)'
  B_Hugwz_FaultModel_T Hugwz;          // '<S81>/Hugw(z)'
  B_Hrgw_FaultModel_T Hrgw;            // '<S80>/Hrgw'
  B_Hqgw_FaultModel_T Hqgw;            // '<S80>/Hqgw'
  B_Hpgw_FaultModel_T Hpgw;            // '<S80>/Hpgw'
} B_FaultModel_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  real_T UnitDelay1_DSTATE[2];         // '<S507>/Unit Delay1'
  real_T UnitDelay_DSTATE_d[169];      // '<S469>/Unit Delay'
  real_T UnitDelay_DSTATE_n[169];      // '<S496>/Unit Delay'
  real_T UnitDelay_DSTATE_e[169];      // '<S468>/Unit Delay'
  real_T UnitDelay1_DSTATE_b[169];     // '<S468>/Unit Delay1'
  real_T UnitDelay1_DSTATE_o[13];      // '<S470>/Unit Delay1'
  real_T WGS84GravitySFunction_h;      // '<S76>/WGS84 Gravity S-Function'
  real_T WGS84GravitySFunction_phi;    // '<S76>/WGS84 Gravity S-Function'
  real_T WGS84GravitySFunction_lambda; // '<S76>/WGS84 Gravity S-Function'
  real_T WGS84GravitySFunction_gamma_h;// '<S76>/WGS84 Gravity S-Function'
  real_T WGS84GravitySFunction_gamma_phi;// '<S76>/WGS84 Gravity S-Function'
  real_T Memory_PreviousInput[8];      // '<Root>/Memory'
  real_T UniformRandomNumber_NextOutput[3];// '<S61>/Uniform Random Number'
  real_T NextOutput[4];                // '<S129>/White Noise'
  real_T NextOutput_j[4];              // '<S90>/White Noise'
  real_T Product2_DWORK4[9];           // '<S14>/Product2'
  real_T UniformRandomNumber5_NextOutput[3];// '<S400>/Uniform Random Number5'
  real_T UniformRandomNumber1_NextOutput[3];// '<S400>/Uniform Random Number1'
  real_T otime_PreviousInput;          // '<S464>/otime'
  real_T olon_PreviousInput;           // '<S463>/olon'
  real_T olat_PreviousInput;           // '<S462>/olat'
  real_T oalt_PreviousInput;           // '<S462>/oalt'
  real_T UniformRandomNumber7_NextOutput[3];// '<S400>/Uniform Random Number7'
  real_T UniformRandomNumber_NextOutpu_k;// '<S400>/Uniform Random Number'
  real_T UniformRandomNumber2_NextOutput;// '<S400>/Uniform Random Number2'
  real_T UniformRandomNumber4_NextOutput;// '<S400>/Uniform Random Number4'
  real_T UniformRandomNumber5_NextOutp_m[3];// '<S327>/Uniform Random Number5'
  real_T UniformRandomNumber4_NextOutp_p[3];// '<S327>/Uniform Random Number4'
  real_T xTemp[8];                     // '<S11>/Model Fail Assessment'
  real_T kk;                           // '<S11>/Model Fail Assessment'
  real_T ss[6];                        // '<S11>/Model Fail Assessment'
  real_T fParam[20];                   // '<S400>/FaultParamsExtract3'
  real_T fParam_e[20];                 // '<S400>/FaultParamsExtract2'
  real_T fParam_m[20];                 // '<S400>/FaultParamsExtract1'
  real_T fParam_k[20];                 // '<S400>/FaultParamsExtract'
  real_T fParam_h[20];                 // '<S327>/FaultParamsExtract'
  real_T fParam_n[20];                 // '<S295>/FaultParamsExtract1'
  real_T fParam_b[20];                 // '<S295>/FaultParamsExtract'
  real_T fParam_by[20];                // '<S286>/FaultParamsExtract'
  real_T tOld;                         // '<S185>/Model Failure'
  real_T fParam_bw[20];                // '<S185>/FaultParamsExtract3'
  real_T fParam_i[20];                 // '<S185>/FaultParamsExtract2'
  real_T fParam_c[20];                 // '<S185>/FaultParamsExtract1'
  real_T t0;                           // '<S61>/MATLAB Function'
  real_T isInGust;                     // '<S61>/MATLAB Function'
  real_T t1;                           // '<S61>/MATLAB Function'
  real_T a;                            // '<S61>/MATLAB Function'
  real_T ang;                          // '<S61>/MATLAB Function'
  real_T wlast;                        // '<S61>/MATLAB Function'
  real_T wNow;                         // '<S61>/MATLAB Function'
  real_T fParam_mm[20];                // '<S61>/FaultParamsExtract4'
  real_T fParam_l[20];                 // '<S61>/FaultParamsExtract3'
  real_T fParam_bb[20];                // '<S61>/FaultParamsExtract2'
  real_T fParam_mg[20];                // '<S61>/FaultParamsExtract1'
  real_T fParam_g[20];                 // '<S61>/FaultParamsExtract'
  real_T fOut[6];                      // '<Root>/CollisionDetection'
  real_T mv0[3];                       // '<Root>/CollisionDetection'
  real_T tColi;                        // '<Root>/CollisionDetection'
  real_T discharge;                    // '<S55>/MATLAB Function'
  real_T startTime;                    // '<S55>/MATLAB Function'
  real_T reset;                        // '<S55>/MATLAB Function'
  real_T fParam_j[20];                 // '<S55>/FaultParamsExtract3'
  real_T fParam_f[20];                 // '<S55>/FaultParamsExtract2'
  real_T fParam_h0[20];                // '<S55>/FaultParamsExtract'
  uint32_T RandSeed[3];                // '<S61>/Uniform Random Number'
  uint32_T PreLookUpIndexSearchaltitude_DW;
                                // '<S136>/PreLook-Up Index Search  (altitude)'
  uint32_T PreLookUpIndexSearchprobofexcee;
                          // '<S136>/PreLook-Up Index Search  (prob of exceed)'
  uint32_T RandSeed_b[4];              // '<S129>/White Noise'
  uint32_T PreLookUpIndexSearchaltitude__e;
                                 // '<S97>/PreLook-Up Index Search  (altitude)'
  uint32_T PreLookUpIndexSearchprobofexc_j;
                           // '<S97>/PreLook-Up Index Search  (prob of exceed)'
  uint32_T RandSeed_j[4];              // '<S90>/White Noise'
  uint32_T RandSeed_p[3];              // '<S400>/Uniform Random Number5'
  uint32_T RandSeed_k[3];              // '<S400>/Uniform Random Number1'
  uint32_T RandSeed_h[3];              // '<S400>/Uniform Random Number7'
  uint32_T RandSeed_d;                 // '<S400>/Uniform Random Number'
  uint32_T RandSeed_i;                 // '<S400>/Uniform Random Number2'
  uint32_T RandSeed_a;                 // '<S400>/Uniform Random Number4'
  uint32_T RandSeed_e[3];              // '<S327>/Uniform Random Number5'
  uint32_T RandSeed_n[3];              // '<S327>/Uniform Random Number4'
  uint32_T method;                     // '<S61>/MATLAB Function'
  uint32_T state;                      // '<S61>/MATLAB Function'
  uint32_T state_k[2];                 // '<S61>/MATLAB Function'
  uint32_T state_d[625];               // '<S61>/MATLAB Function'
  uint32_T method_a;                   // '<Root>/Crash_Motor_Fault'
  uint32_T state_c;                    // '<Root>/Crash_Motor_Fault'
  uint32_T state_f[2];                 // '<Root>/Crash_Motor_Fault'
  uint32_T state_g[625];               // '<Root>/Crash_Motor_Fault'
  uint32_T method_l;                   // '<Root>/CollisionDetection'
  uint32_T state_m;                    // '<Root>/CollisionDetection'
  uint32_T state_fo[2];                // '<Root>/CollisionDetection'
  uint32_T state_p[625];               // '<Root>/CollisionDetection'
  int_T q0q1q2q3_IWORK;                // '<S13>/q0 q1 q2 q3'
  int_T IntegratorSecondOrderLimited_MO[3];
                                   // '<S429>/Integrator, Second-Order Limited'
  int_T IntegratorSecondOrderLimited__l[3];
                                   // '<S440>/Integrator, Second-Order Limited'
  int8_T If_ActiveSubsystem;           // '<S40>/If'
  int8_T If_ActiveSubsystem_h;         // '<S192>/If'
  int8_T If_ActiveSubsystem_l;         // '<S191>/If'
  int8_T ifHeightMaxlowaltitudeelseifHei;
  // '<S125>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 
  int8_T ifHeightMaxlowaltitudeelseifH_d;
  // '<S86>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 
  int8_T If_ActiveSubsystem_m;         // '<S326>/If'
  int8_T ifHeightMaxlowaltitudeelseifH_g;
  // '<S85>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 
  int8_T ifHeightMaxlowaltitudeelseifH_i;
  // '<S124>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 
  int8_T If1_ActiveSubsystem;          // '<S202>/If1'
  int8_T If1_ActiveSubsystem_o;        // '<S240>/If1'
  int8_T If1_ActiveSubsystem_d;        // '<S334>/If1'
  int8_T takeoffFlag;                  // '<S7>/Ground Model'
  int8_T landFlag;                     // '<S7>/Ground Model'
  int8_T isCol;                        // '<Root>/CollisionDetection'
  boolean_T IntegratorSecondOrderLimited_DW;
                                   // '<S429>/Integrator, Second-Order Limited'
  boolean_T IntegratorSecondOrderLimited__p;
                                   // '<S440>/Integrator, Second-Order Limited'
  boolean_T hFault;                    // '<S400>/FaultParamsExtract3'
  boolean_T hFault_l;                  // '<S400>/FaultParamsExtract2'
  boolean_T hFault_b;                  // '<S400>/FaultParamsExtract1'
  boolean_T hFault_h;                  // '<S400>/FaultParamsExtract'
  boolean_T hFault_a;                  // '<S327>/FaultParamsExtract'
  boolean_T hFault_m;                  // '<S295>/FaultParamsExtract1'
  boolean_T hFault_g;                  // '<S295>/FaultParamsExtract'
  boolean_T hFault_he;                 // '<S286>/FaultParamsExtract'
  boolean_T hFault_br;                 // '<S185>/FaultParamsExtract3'
  boolean_T hFault_i;                  // '<S185>/FaultParamsExtract2'
  boolean_T hFault_c;                  // '<S185>/FaultParamsExtract1'
  boolean_T wlast_not_empty;           // '<S61>/MATLAB Function'
  boolean_T wNow_not_empty;            // '<S61>/MATLAB Function'
  boolean_T state_not_empty;           // '<S61>/MATLAB Function'
  boolean_T hFault_p;                  // '<S61>/FaultParamsExtract4'
  boolean_T hFault_k;                  // '<S61>/FaultParamsExtract3'
  boolean_T hFault_f;                  // '<S61>/FaultParamsExtract2'
  boolean_T hFault_b0;                 // '<S61>/FaultParamsExtract1'
  boolean_T hFault_ff;                 // '<S61>/FaultParamsExtract'
  boolean_T state_not_empty_n;         // '<Root>/Crash_Motor_Fault'
  boolean_T state_not_empty_d;         // '<Root>/CollisionDetection'
  boolean_T hFault_n;                  // '<S55>/FaultParamsExtract3'
  boolean_T hFault_hp;                 // '<S55>/FaultParamsExtract2'
  boolean_T hFault_l1;                 // '<S55>/FaultParamsExtract1'
  boolean_T hFault_j;                  // '<S55>/FaultParamsExtract'
  boolean_T Convertfromgeodetictosphericalc;
                   // '<S450>/Convert from geodetic to  spherical coordinates '
  boolean_T Convertfromgeodetictospherica_d;
                    // '<S450>/Convert from geodetic to  spherical coordinates'
  boolean_T SpecialcaseNorthSouthGeographic;
                        // '<S467>/Special case - North//South Geographic Pole'
  DW_NegativeTrace_FaultModel_T NegativeTrace_l;// '<S326>/Negative Trace'
  DW_MotorNonlinearDynamic1_Fau_T MotorNonlinearDynamic8;// '<S300>/MotorNonlinearDynamic8' 
  DW_MotorNonlinearDynamic1_Fau_T MotorNonlinearDynamic7;// '<S300>/MotorNonlinearDynamic7' 
  DW_MotorNonlinearDynamic1_Fau_T MotorNonlinearDynamic6;// '<S300>/MotorNonlinearDynamic6' 
  DW_MotorNonlinearDynamic1_Fau_T MotorNonlinearDynamic5;// '<S300>/MotorNonlinearDynamic5' 
  DW_MotorNonlinearDynamic1_Fau_T MotorNonlinearDynamic4;// '<S300>/MotorNonlinearDynamic4' 
  DW_MotorNonlinearDynamic1_Fau_T MotorNonlinearDynamic3;// '<S300>/MotorNonlinearDynamic3' 
  DW_MotorNonlinearDynamic1_Fau_T MotorNonlinearDynamic2;// '<S300>/MotorNonlinearDynamic2' 
  DW_MotorNonlinearDynamic1_Fau_T MotorNonlinearDynamic1;// '<S300>/MotorNonlinearDynamic1' 
  DW_NegativeTrace_FaultModel_T NegativeTrace_d;// '<S192>/Negative Trace'
  DW_NegativeTrace_FaultModel_T NegativeTrace;// '<S191>/Negative Trace'
  DW_Hwgwz_FaultModel_T Hwgwz_a;       // '<S120>/Hwgw(z)'
  DW_Hvgwz_FaultModel_T Hvgwz_p;       // '<S120>/Hvgw(z)'
  DW_Hugwz_FaultModel_T Hugwz_i;       // '<S120>/Hugw(z)'
  DW_Hrgw_FaultModel_T Hrgw_g;         // '<S119>/Hrgw'
  DW_Hqgw_FaultModel_T Hqgw_b;         // '<S119>/Hqgw'
  DW_Hpgw_FaultModel_T Hpgw_c;         // '<S119>/Hpgw'
  DW_Hwgwz_FaultModel_T Hwgwz;         // '<S81>/Hwgw(z)'
  DW_Hvgwz_FaultModel_T Hvgwz;         // '<S81>/Hvgw(z)'
  DW_Hugwz_FaultModel_T Hugwz;         // '<S81>/Hugw(z)'
  DW_Hrgw_FaultModel_T Hrgw;           // '<S80>/Hrgw'
  DW_Hqgw_FaultModel_T Hqgw;           // '<S80>/Hqgw'
  DW_Hpgw_FaultModel_T Hpgw;           // '<S80>/Hpgw'
} DW_FaultModel_T;

// Continuous states (default storage)
typedef struct {
  real_T IntegratorSecondOrderLimited_CS[6];
                                   // '<S429>/Integrator, Second-Order Limited'
  real_T q0q1q2q3_CSTATE[4];           // '<S13>/q0 q1 q2 q3'
  real_T xeyeze_CSTATE[3];             // '<S12>/xe,ye,ze'
  real_T pqr_CSTATE[3];                // '<S12>/p,q,r '
  real_T ubvbwb_CSTATE[3];             // '<S12>/ub,vb,wb'
  real_T IntegratorSecondOrderLimited__b[6];
                                   // '<S440>/Integrator, Second-Order Limited'
  real_T TransferFcn4_CSTATE;          // '<S376>/Transfer Fcn4'
  real_T TransferFcn1_CSTATE;          // '<S376>/Transfer Fcn1'
  real_T TransferFcn2_CSTATE;          // '<S376>/Transfer Fcn2'
  X_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic8;// '<S300>/MotorNonlinearDynamic1' 
  X_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic7;// '<S300>/MotorNonlinearDynamic1' 
  X_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic6;// '<S300>/MotorNonlinearDynamic1' 
  X_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic5;// '<S300>/MotorNonlinearDynamic1' 
  X_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic4;// '<S300>/MotorNonlinearDynamic1' 
  X_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic3;// '<S300>/MotorNonlinearDynamic1' 
  X_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic2;// '<S300>/MotorNonlinearDynamic1' 
  X_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic1;// '<S300>/MotorNonlinearDynamic1' 
} X_FaultModel_T;

// State derivatives (default storage)
typedef struct {
  real_T IntegratorSecondOrderLimited_CS[6];
                                   // '<S429>/Integrator, Second-Order Limited'
  real_T q0q1q2q3_CSTATE[4];           // '<S13>/q0 q1 q2 q3'
  real_T xeyeze_CSTATE[3];             // '<S12>/xe,ye,ze'
  real_T pqr_CSTATE[3];                // '<S12>/p,q,r '
  real_T ubvbwb_CSTATE[3];             // '<S12>/ub,vb,wb'
  real_T IntegratorSecondOrderLimited__b[6];
                                   // '<S440>/Integrator, Second-Order Limited'
  real_T TransferFcn4_CSTATE;          // '<S376>/Transfer Fcn4'
  real_T TransferFcn1_CSTATE;          // '<S376>/Transfer Fcn1'
  real_T TransferFcn2_CSTATE;          // '<S376>/Transfer Fcn2'
  XDot_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic8;// '<S300>/MotorNonlinearDynamic1' 
  XDot_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic7;// '<S300>/MotorNonlinearDynamic1' 
  XDot_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic6;// '<S300>/MotorNonlinearDynamic1' 
  XDot_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic5;// '<S300>/MotorNonlinearDynamic1' 
  XDot_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic4;// '<S300>/MotorNonlinearDynamic1' 
  XDot_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic3;// '<S300>/MotorNonlinearDynamic1' 
  XDot_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic2;// '<S300>/MotorNonlinearDynamic1' 
  XDot_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic1;// '<S300>/MotorNonlinearDynamic1' 
} XDot_FaultModel_T;

// State disabled
typedef struct {
  boolean_T IntegratorSecondOrderLimited_CS[6];
                                   // '<S429>/Integrator, Second-Order Limited'
  boolean_T q0q1q2q3_CSTATE[4];        // '<S13>/q0 q1 q2 q3'
  boolean_T xeyeze_CSTATE[3];          // '<S12>/xe,ye,ze'
  boolean_T pqr_CSTATE[3];             // '<S12>/p,q,r '
  boolean_T ubvbwb_CSTATE[3];          // '<S12>/ub,vb,wb'
  boolean_T IntegratorSecondOrderLimited__b[6];
                                   // '<S440>/Integrator, Second-Order Limited'
  boolean_T TransferFcn4_CSTATE;       // '<S376>/Transfer Fcn4'
  boolean_T TransferFcn1_CSTATE;       // '<S376>/Transfer Fcn1'
  boolean_T TransferFcn2_CSTATE;       // '<S376>/Transfer Fcn2'
  XDis_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic8;// '<S300>/MotorNonlinearDynamic1' 
  XDis_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic7;// '<S300>/MotorNonlinearDynamic1' 
  XDis_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic6;// '<S300>/MotorNonlinearDynamic1' 
  XDis_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic5;// '<S300>/MotorNonlinearDynamic1' 
  XDis_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic4;// '<S300>/MotorNonlinearDynamic1' 
  XDis_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic3;// '<S300>/MotorNonlinearDynamic1' 
  XDis_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic2;// '<S300>/MotorNonlinearDynamic1' 
  XDis_MotorNonlinearDynamic1_F_T MotorNonlinearDynamic1;// '<S300>/MotorNonlinearDynamic1' 
} XDis_FaultModel_T;

#ifndef ODE4_INTG
#define ODE4_INTG

// ODE4 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[4];                        // derivatives
} ODE4_IntgData;

#endif

// External inputs (root inport signals with default storage)
typedef struct {
  real_T inPWMs[8];                    // '<Root>/inPWMs'
  real_T TerrainZ;                     // '<Root>/TerrainZ'
  real32_T inFloatsCollision[20];      // '<Root>/inFloatsCollision'
  int32_T inSILInts[8];                // '<Root>/inSILInts'
  real32_T inSILFloats[20];            // '<Root>/inSILFloats'
} ExtU_FaultModel_T;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  MavLinkSensor MavHILSensor;          // '<Root>/MavHILSensor'
  MavLinkStateQuat MavHILStateQuat;    // '<Root>/MavHILStateQuat'
  MavLinkGPS MavHILGPS;                // '<Root>/MavHILGPS'
  HILGPS PXIHILGPSData;                // '<Root>/PXIHILGPSData'
  int16_T magDec;                      // '<Root>/magDec'
  uint32_T SysTime;                    // '<Root>/SysTime'
  real_T VelE[3];                      // '<Root>/VelE'
  real_T PosE[3];                      // '<Root>/PosE'
  real_T AngEuler[3];                  // '<Root>/AngEuler'
  real_T AngQuatern[4];                // '<Root>/AngQuatern'
  real_T PosGPS[3];                    // '<Root>/PosGPS'
  real_T RateB[3];                     // '<Root>/RateB'
  real_T AccB[3];                      // '<Root>/AccB'
  real_T FailInfo[8];                  // '<Root>/FailInfo'
  int8_T landed;                       // '<Root>/landed'
  real_T BattCellVoltage;              // '<Root>/BattCellVoltage'
  real_T BattRemCapacity;              // '<Root>/BattRemCapacity'
  real_T MotorRPMS[8];                 // '<Root>/MotorRPMS'
  real_T wind[3];                      // '<Root>/wind'
  MavVehileInfo MavVehile3DInfo;       // '<Root>/MavVehile3DInfo'
} ExtY_FaultModel_T;

// Parameters for system: '<S80>/Hpgw'
struct P_Hpgw_FaultModel_T_ {
  real_T pgw_Y0;                       // Expression: 0
                                          //  Referenced by: '<S91>/pgw'

  real_T Constant2_Value;              // Expression: 2.6
                                          //  Referenced by: '<S91>/Constant2'

  real_T u_Gain;                       // Expression: 2*dt
                                          //  Referenced by: '<S91>/2'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S91>/Constant'

  real_T Constant1_Value;              // Expression: 0.95
                                          //  Referenced by: '<S91>/Constant1'

  real_T Constant3_Value;              // Expression: 1/3
                                          //  Referenced by: '<S91>/Constant3'

  real_T dt_Gain;                      // Expression: dt
                                          //  Referenced by: '<S91>/dt'

  real_T UnitDelay_InitialCondition;   // Expression: 0
                                          //  Referenced by: '<S91>/Unit Delay'

};

// Parameters for system: '<S80>/Hpgw'
typedef struct P_Hpgw_FaultModel_T_ P_Hpgw_FaultModel_T;

// Parameters for system: '<S80>/Hqgw'
struct P_Hqgw_FaultModel_T_ {
  real_T qgw_Y0;                       // Expression: 0
                                          //  Referenced by: '<S92>/qgw'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S92>/Constant'

  real_T dt1_Gain;                     // Expression: 4/pi
                                          //  Referenced by: '<S92>/dt1'

  real_T dt_Gain;                      // Expression: dt
                                          //  Referenced by: '<S92>/dt'

  real_T UnitDelay_InitialCondition;   // Expression: 0
                                          //  Referenced by: '<S92>/Unit Delay'

  real_T UnitDelay1_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S92>/Unit Delay1'

};

// Parameters for system: '<S80>/Hqgw'
typedef struct P_Hqgw_FaultModel_T_ P_Hqgw_FaultModel_T;

// Parameters for system: '<S80>/Hrgw'
struct P_Hrgw_FaultModel_T_ {
  real_T rgw_Y0;                       // Expression: 0
                                          //  Referenced by: '<S93>/rgw'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S93>/Constant'

  real_T dt1_Gain;                     // Expression: 3/pi
                                          //  Referenced by: '<S93>/dt1'

  real_T dt_Gain;                      // Expression: dt
                                          //  Referenced by: '<S93>/dt'

  real_T UnitDelay_InitialCondition;   // Expression: 0
                                          //  Referenced by: '<S93>/Unit Delay'

  real_T UnitDelay1_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S93>/Unit Delay1'

};

// Parameters for system: '<S80>/Hrgw'
typedef struct P_Hrgw_FaultModel_T_ P_Hrgw_FaultModel_T;

// Parameters for system: '<S81>/Hugw(z)'
struct P_Hugwz_FaultModel_T_ {
  real_T ugw_Y0;                       // Expression: 0
                                          //  Referenced by: '<S94>/ugw'

  real_T u_Gain;                       // Expression: 2*dt
                                          //  Referenced by: '<S94>/2'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S94>/Constant'

  real_T dt_Gain;                      // Expression: dt
                                          //  Referenced by: '<S94>/dt'

  real_T UnitDelay_InitialCondition;   // Expression: 0
                                          //  Referenced by: '<S94>/Unit Delay'

};

// Parameters for system: '<S81>/Hugw(z)'
typedef struct P_Hugwz_FaultModel_T_ P_Hugwz_FaultModel_T;

// Parameters for system: '<S81>/Hvgw(z)'
struct P_Hvgwz_FaultModel_T_ {
  real_T vgw_Y0;                       // Expression: 0
                                          //  Referenced by: '<S95>/vgw'

  real_T u_Gain;                       // Expression: 2*dt
                                          //  Referenced by: '<S95>/2'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S95>/Constant'

  real_T dt_Gain;                      // Expression: dt
                                          //  Referenced by: '<S95>/dt'

  real_T UnitDelay_InitialCondition;   // Expression: 0
                                          //  Referenced by: '<S95>/Unit Delay'

};

// Parameters for system: '<S81>/Hvgw(z)'
typedef struct P_Hvgwz_FaultModel_T_ P_Hvgwz_FaultModel_T;

// Parameters for system: '<S81>/Hwgw(z)'
struct P_Hwgwz_FaultModel_T_ {
  real_T wgw_Y0;                       // Expression: 0
                                          //  Referenced by: '<S96>/wgw'

  real_T u_Gain;                       // Expression: 2*dt
                                          //  Referenced by: '<S96>/2'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S96>/Constant'

  real_T dt_Gain;                      // Expression: dt
                                          //  Referenced by: '<S96>/dt'

  real_T UnitDelay_InitialCondition;   // Expression: 0
                                          //  Referenced by: '<S96>/Unit Delay'

};

// Parameters for system: '<S81>/Hwgw(z)'
typedef struct P_Hwgwz_FaultModel_T_ P_Hwgwz_FaultModel_T;

// Parameters for system: '<S85>/Interpolate  rates'
struct P_Interpolaterates_FaultModel_T_ {
  real_T max_height_low_Value;         // Expression: max_height_low
                                          //  Referenced by: '<S99>/max_height_low'

  real_T min_height_high_Value;        // Expression: min_height_high
                                          //  Referenced by: '<S99>/min_height_high'

};

// Parameters for system: '<S85>/Interpolate  rates'
typedef struct P_Interpolaterates_FaultModel_T_ P_Interpolaterates_FaultModel_T;

// Parameters for system: '<S86>/Interpolate  velocities'
struct P_Interpolatevelocities_Fault_T_ {
  real_T max_height_low_Value;         // Expression: max_height_low
                                          //  Referenced by: '<S107>/max_height_low'

  real_T min_height_high_Value;        // Expression: min_height_high
                                          //  Referenced by: '<S107>/min_height_high'

};

// Parameters for system: '<S86>/Interpolate  velocities'
typedef struct P_Interpolatevelocities_Fault_T_ P_Interpolatevelocities_Fault_T;

// Parameters for system: '<S191>/Positive Trace'
struct P_PositiveTrace_FaultModel_T_ {
  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S201>/Constant'

  real_T Gain_Gain;                    // Expression: 0.5
                                          //  Referenced by: '<S201>/Gain'

  real_T Gain1_Gain;                   // Expression: 2
                                          //  Referenced by: '<S201>/Gain1'

};

// Parameters for system: '<S191>/Positive Trace'
typedef struct P_PositiveTrace_FaultModel_T_ P_PositiveTrace_FaultModel_T;

// Parameters for system: '<S191>/Negative Trace'
struct P_NegativeTrace_FaultModel_T_ {
  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S217>/Constant'

  real_T Gain_Gain;                    // Expression: 0.5
                                          //  Referenced by: '<S205>/Gain'

  real_T Constant1_Value;              // Expression: 0.5
                                          //  Referenced by: '<S216>/Constant1'

  real_T Constant2_Value[2];           // Expression: [0 1]
                                          //  Referenced by: '<S216>/Constant2'

  real_T Gain1_Gain;                   // Expression: 1
                                          //  Referenced by: '<S205>/Gain1'

  real_T Gain3_Gain;                   // Expression: 1
                                          //  Referenced by: '<S205>/Gain3'

  real_T Gain4_Gain;                   // Expression: 1
                                          //  Referenced by: '<S205>/Gain4'

  real_T Constant_Value_n;             // Expression: 1
                                          //  Referenced by: '<S222>/Constant'

  real_T Gain_Gain_c;                  // Expression: 0.5
                                          //  Referenced by: '<S206>/Gain'

  real_T Constant1_Value_a;            // Expression: 0.5
                                          //  Referenced by: '<S221>/Constant1'

  real_T Constant2_Value_c[2];         // Expression: [0 1]
                                          //  Referenced by: '<S221>/Constant2'

  real_T Gain1_Gain_n;                 // Expression: 1
                                          //  Referenced by: '<S206>/Gain1'

  real_T Gain2_Gain;                   // Expression: 1
                                          //  Referenced by: '<S206>/Gain2'

  real_T Gain3_Gain_m;                 // Expression: 1
                                          //  Referenced by: '<S206>/Gain3'

  real_T Constant_Value_m;             // Expression: 1
                                          //  Referenced by: '<S212>/Constant'

  real_T Gain_Gain_l;                  // Expression: 0.5
                                          //  Referenced by: '<S204>/Gain'

  real_T Constant1_Value_i;            // Expression: 0.5
                                          //  Referenced by: '<S211>/Constant1'

  real_T Constant2_Value_b[2];         // Expression: [0 1]
                                          //  Referenced by: '<S211>/Constant2'

  real_T Gain1_Gain_b;                 // Expression: 1
                                          //  Referenced by: '<S204>/Gain1'

  real_T Gain2_Gain_d;                 // Expression: 1
                                          //  Referenced by: '<S204>/Gain2'

  real_T Gain3_Gain_n;                 // Expression: 1
                                          //  Referenced by: '<S204>/Gain3'

};

// Parameters for system: '<S191>/Negative Trace'
typedef struct P_NegativeTrace_FaultModel_T_ P_NegativeTrace_FaultModel_T;

// Parameters for system: '<S202>/If Warning//Error'
struct P_IfWarningError_FaultModel_T_ {
  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S228>/Constant1'

  real_T Constant1_Value_k;            // Expression: 0
                                          //  Referenced by: '<S227>/Constant1'

  real_T Bias_Bias;                    // Expression: -1
                                          //  Referenced by: '<S230>/Bias'

  real_T Bias1_Bias[9];                // Expression: -eye(3)
                                          //  Referenced by: '<S229>/Bias1'

};

// Parameters for system: '<S202>/If Warning//Error'
typedef struct P_IfWarningError_FaultModel_T_ P_IfWarningError_FaultModel_T;

// Parameters for system: '<S300>/MotorNonlinearDynamic1'
struct P_MotorNonlinearDynamic1_Faul_T_ {
  real_T Signal_Saturation_UpperSat;   // Expression: 0.95
                                          //  Referenced by: '<S302>/Signal_Saturation'

  real_T Signal_Saturation_LowerSat;   // Expression: 0
                                          //  Referenced by: '<S302>/Signal_Saturation'

};

// Parameters for system: '<S300>/MotorNonlinearDynamic1'
typedef struct P_MotorNonlinearDynamic1_Faul_T_ P_MotorNonlinearDynamic1_Faul_T;

// Parameters (default storage)
struct P_FaultModel_T_ {
  real_T ModelInit_AngEuler[3];        // Variable: ModelInit_AngEuler
                                          //  Referenced by: '<S13>/Initial Euler Angles'

  real_T ModelInit_PosE[3];            // Variable: ModelInit_PosE
                                          //  Referenced by: '<S12>/xe,ye,ze'

  real_T ModelInit_RPM;                // Variable: ModelInit_RPM
                                          //  Referenced by: '<S300>/ModelInit_RPM'

  real_T ModelInit_RateB[3];           // Variable: ModelInit_RateB
                                          //  Referenced by: '<S12>/p,q,r '

  real_T ModelInit_VelB[3];            // Variable: ModelInit_VelB
                                          //  Referenced by: '<S12>/ub,vb,wb'

  real_T ModelParam_BattHoverMinutes;  // Variable: ModelParam_BattHoverMinutes
                                          //  Referenced by: '<S55>/ModelParam.BattHoverMinutes'

  real_T ModelParam_BattHoverThr;      // Variable: ModelParam_BattHoverThr
                                          //  Referenced by: '<S55>/ModelParam.BattHoverThr'

  real_T ModelParam_GPSEphFinal;       // Variable: ModelParam_GPSEphFinal
                                          //  Referenced by: '<S327>/ModelParam.GPSEphFinal'

  real_T ModelParam_GPSEpvFinal;       // Variable: ModelParam_GPSEpvFinal
                                          //  Referenced by: '<S327>/ModelParam.GPSEpvFinal'

  real_T ModelParam_GPSFix3DFix;       // Variable: ModelParam_GPSFix3DFix
                                          //  Referenced by: '<S327>/ModelParam_GPSFix3DFix'

  real_T ModelParam_GPSLatLong[2];     // Variable: ModelParam_GPSLatLong
                                          //  Referenced by:
                                          //    '<S69>/ref_position'
                                          //    '<S374>/ref_position'

  real_T ModelParam_GPSSatsVisible;    // Variable: ModelParam_GPSSatsVisible
                                          //  Referenced by: '<S327>/ModelParam.GPSSatsVisible'

  real_T ModelParam_envAltitude;       // Variable: ModelParam_envAltitude
                                          //  Referenced by:
                                          //    '<S61>/ModelParam.envAltitude'
                                          //    '<S327>/ModelParam.envAltitude'

  real_T ModelParam_motorCr;           // Variable: ModelParam_motorCr
                                          //  Referenced by: '<S300>/ModelParam.motorCr'

  real_T ModelParam_motorJm;           // Variable: ModelParam_motorJm
                                          //  Referenced by: '<S7>/ModelParam.motorJm'

  real_T ModelParam_motorMinThr;       // Variable: ModelParam_motorMinThr
                                          //  Referenced by:
                                          //    '<S310>/Constant'
                                          //    '<S312>/Constant'
                                          //    '<S314>/Constant'
                                          //    '<S316>/Constant'
                                          //    '<S318>/Constant'
                                          //    '<S320>/Constant'
                                          //    '<S322>/Constant'
                                          //    '<S324>/Constant'

  real_T ModelParam_motorT;            // Variable: ModelParam_motorT
                                          //  Referenced by: '<S300>/ModelParam.motorT'

  real_T ModelParam_motorWb;           // Variable: ModelParam_motorWb
                                          //  Referenced by: '<S300>/ModelParam.motorWb'

  real_T ModelParam_noisePowerOffGainAccel;
                                  // Variable: ModelParam_noisePowerOffGainAccel
                                     //  Referenced by: '<S400>/AccelNoiseGainFunction'

  real_T ModelParam_noisePowerOffGainAccelZ;
                                 // Variable: ModelParam_noisePowerOffGainAccelZ
                                    //  Referenced by: '<S400>/AccelNoiseGainFunction'

  real_T ModelParam_noisePowerOffGainGyro;
                                   // Variable: ModelParam_noisePowerOffGainGyro
                                      //  Referenced by: '<S400>/GyroNoiseGainFunction'

  real_T ModelParam_noisePowerOffGainGyroZ;
                                  // Variable: ModelParam_noisePowerOffGainGyroZ
                                     //  Referenced by: '<S400>/GyroNoiseGainFunction'

  real_T ModelParam_noisePowerOffGainMag;
                                    // Variable: ModelParam_noisePowerOffGainMag
                                       //  Referenced by: '<S400>/MagNoiseGainFunction'

  real_T ModelParam_noisePowerOffGainMagZ;
                                   // Variable: ModelParam_noisePowerOffGainMagZ
                                      //  Referenced by: '<S400>/MagNoiseGainFunction'

  real_T ModelParam_noisePowerOnGainAccel;
                                   // Variable: ModelParam_noisePowerOnGainAccel
                                      //  Referenced by: '<S400>/AccelNoiseGainFunction'

  real_T ModelParam_noisePowerOnGainAccelZ;
                                  // Variable: ModelParam_noisePowerOnGainAccelZ
                                     //  Referenced by: '<S400>/AccelNoiseGainFunction'

  real_T ModelParam_noisePowerOnGainGyro;
                                    // Variable: ModelParam_noisePowerOnGainGyro
                                       //  Referenced by: '<S400>/GyroNoiseGainFunction'

  real_T ModelParam_noisePowerOnGainGyroZ;
                                   // Variable: ModelParam_noisePowerOnGainGyroZ
                                      //  Referenced by: '<S400>/GyroNoiseGainFunction'

  real_T ModelParam_noisePowerOnGainMag;
                                     // Variable: ModelParam_noisePowerOnGainMag
                                        //  Referenced by: '<S400>/MagNoiseGainFunction'

  real_T ModelParam_noisePowerOnGainMagZ;
                                    // Variable: ModelParam_noisePowerOnGainMagZ
                                       //  Referenced by: '<S400>/MagNoiseGainFunction'

  real_T ModelParam_rotorCm;           // Variable: ModelParam_rotorCm
                                          //  Referenced by: '<S7>/ModelParam.rotorCm'

  real_T ModelParam_rotorCt;           // Variable: ModelParam_rotorCt
                                          //  Referenced by: '<S7>/ModelParam.rotorCt'

  real_T ModelParam_uavCCm[3];         // Variable: ModelParam_uavCCm
                                          //  Referenced by: '<S7>/ModelParam.uavCCm'

  real_T ModelParam_uavCd[3];          // Variable: ModelParam_uavCd
                                          //  Referenced by: '<S7>/ModelParam.uavCd'

  real_T ModelParam_uavDearo;          // Variable: ModelParam_uavDearo
                                          //  Referenced by: '<S7>/ModelParam.uavDearo'

  real_T ModelParam_uavJ[9];           // Variable: ModelParam_uavJ
                                          //  Referenced by: '<S185>/uavJ'

  real_T ModelParam_uavMass;           // Variable: ModelParam_uavMass
                                          //  Referenced by: '<S185>/ModelParam.uavMass'

  real_T ModelParam_uavR;              // Variable: ModelParam_uavR
                                          //  Referenced by: '<S185>/ModelParam.uavR'

  boolean_T ModelFailEnable;           // Variable: ModelFailEnable
                                          //  Referenced by: '<S11>/ModelFailEnable'

  int8_T ModelParam_uavMotNumbs;       // Variable: ModelParam_uavMotNumbs
                                          //  Referenced by: '<S55>/ModelParam.uavMotNumbs'

  int8_T ModelParam_uavType;           // Variable: ModelParam_uavType
                                          //  Referenced by:
                                          //    '<S7>/ModelParam.uavType'
                                          //    '<S11>/UAVType'

  real_T DrydenWindTurbulenceModelDiscre;
                              // Mask Parameter: DrydenWindTurbulenceModelDiscre
                                 //  Referenced by: '<S155>/Medium//High Altitude'

  real_T DrydenWindTurbulenceModelDisc_j;
                              // Mask Parameter: DrydenWindTurbulenceModelDisc_j
                                 //  Referenced by: '<S116>/Medium//High Altitude'

  real_T DrydenWindTurbulenceModelDisc_k[4];
                              // Mask Parameter: DrydenWindTurbulenceModelDisc_k
                                 //  Referenced by: '<S129>/White Noise'

  real_T DrydenWindTurbulenceModelDisc_n[4];
                              // Mask Parameter: DrydenWindTurbulenceModelDisc_n
                                 //  Referenced by: '<S90>/White Noise'

  real_T DrydenWindTurbulenceModelDisc_a;
                              // Mask Parameter: DrydenWindTurbulenceModelDisc_a
                                 //  Referenced by:
                                 //    '<S119>/Constant1'
                                 //    '<S119>/Constant2'
                                 //    '<S119>/Constant3'
                                 //    '<S120>/Constant3'

  real_T DrydenWindTurbulenceModelDisc_m;
                              // Mask Parameter: DrydenWindTurbulenceModelDisc_m
                                 //  Referenced by:
                                 //    '<S80>/Constant1'
                                 //    '<S80>/Constant2'
                                 //    '<S80>/Constant3'
                                 //    '<S81>/Constant3'

  real_T WhiteNoise_Ts;                // Mask Parameter: WhiteNoise_Ts
                                          //  Referenced by: '<S129>/Constant1'

  real_T WhiteNoise_Ts_p;              // Mask Parameter: WhiteNoise_Ts_p
                                          //  Referenced by: '<S90>/Constant1'

  real_T DrydenWindTurbulenceModelDis_aw;
                              // Mask Parameter: DrydenWindTurbulenceModelDis_aw
                                 //  Referenced by: '<S136>/Probability of  Exceedance'

  real_T DrydenWindTurbulenceModelDisc_h;
                              // Mask Parameter: DrydenWindTurbulenceModelDisc_h
                                 //  Referenced by: '<S97>/Probability of  Exceedance'

  real_T DrydenWindTurbulenceModelDis_m3;
                              // Mask Parameter: DrydenWindTurbulenceModelDis_m3
                                 //  Referenced by: '<S63>/Windspeed at 20ft (6m)'

  real_T DrydenWindTurbulenceModelDis_mb;
                              // Mask Parameter: DrydenWindTurbulenceModelDis_mb
                                 //  Referenced by: '<S62>/Windspeed at 20ft (6m)'

  real_T WindShearModel_W_20;          // Mask Parameter: WindShearModel_W_20
                                          //  Referenced by: '<S77>/Wind speed at reference height'

  real_T DrydenWindTurbulenceModelDisc_i;
                              // Mask Parameter: DrydenWindTurbulenceModelDisc_i
                                 //  Referenced by: '<S63>/Wind direction'

  real_T DrydenWindTurbulenceModelDisc_o;
                              // Mask Parameter: DrydenWindTurbulenceModelDisc_o
                                 //  Referenced by: '<S62>/Wind direction'

  real_T WindShearModel_Wdeg;          // Mask Parameter: WindShearModel_Wdeg
                                          //  Referenced by: '<S77>/Wind Direction'

  real_T DrydenWindTurbulenceModelDisc_f;
                              // Mask Parameter: DrydenWindTurbulenceModelDisc_f
                                 //  Referenced by: '<S62>/Wingspan'

  real_T DrydenWindTurbulenceModelDis_az;
                              // Mask Parameter: DrydenWindTurbulenceModelDis_az
                                 //  Referenced by: '<S63>/Wingspan'

  real_T ThreeaxisInertialMeasurementUni[3];
                              // Mask Parameter: ThreeaxisInertialMeasurementUni
                                 //  Referenced by: '<S423>/Measurement bias'

  real_T ThreeaxisInertialMeasurementU_o[9];
                              // Mask Parameter: ThreeaxisInertialMeasurementU_o
                                 //  Referenced by: '<S423>/Scale factors & Cross-coupling  errors'

  real_T DirectionCosineMatrixtoQuaterni;
                              // Mask Parameter: DirectionCosineMatrixtoQuaterni
                                 //  Referenced by:
                                 //    '<S202>/If Warning//Error'
                                 //    '<S202>/Constant'

  real_T DirectionCosineMatrixtoQuater_p;
                              // Mask Parameter: DirectionCosineMatrixtoQuater_p
                                 //  Referenced by:
                                 //    '<S240>/If Warning//Error'
                                 //    '<S240>/Constant'

  real_T DirectionCosineMatrixtoQuater_c;
                              // Mask Parameter: DirectionCosineMatrixtoQuater_c
                                 //  Referenced by:
                                 //    '<S334>/If Warning//Error'
                                 //    '<S334>/Constant'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S171>/Constant'

  real_T CompareToConstant_const_n; // Mask Parameter: CompareToConstant_const_n
                                       //  Referenced by: '<S169>/Constant'

  real_T CompareToConstant_const_ng;
                                   // Mask Parameter: CompareToConstant_const_ng
                                      //  Referenced by: '<S172>/Constant'

  real_T CompareToConstant_const_b; // Mask Parameter: CompareToConstant_const_b
                                       //  Referenced by: '<S165>/Constant'

  real_T CompareToConstant_const_e; // Mask Parameter: CompareToConstant_const_e
                                       //  Referenced by: '<S163>/Constant'

  real_T CompareToConstant_const_i; // Mask Parameter: CompareToConstant_const_i
                                       //  Referenced by: '<S166>/Constant'

  real_T CompareToConstant_const_k; // Mask Parameter: CompareToConstant_const_k
                                       //  Referenced by: '<S456>/Constant'

  real_T CompareToConstant_const_p; // Mask Parameter: CompareToConstant_const_p
                                       //  Referenced by: '<S454>/Constant'

  real_T CompareToConstant_const_o; // Mask Parameter: CompareToConstant_const_o
                                       //  Referenced by: '<S457>/Constant'

  real_T CompareToConstant_const_d; // Mask Parameter: CompareToConstant_const_d
                                       //  Referenced by: '<S392>/Constant'

  real_T CompareToConstant_const_l; // Mask Parameter: CompareToConstant_const_l
                                       //  Referenced by: '<S390>/Constant'

  real_T CompareToConstant_const_a; // Mask Parameter: CompareToConstant_const_a
                                       //  Referenced by: '<S393>/Constant'

  real_T CompareToConstant_const_k3;
                                   // Mask Parameter: CompareToConstant_const_k3
                                      //  Referenced by: '<S386>/Constant'

  real_T CompareToConstant_const_dl;
                                   // Mask Parameter: CompareToConstant_const_dl
                                      //  Referenced by: '<S384>/Constant'

  real_T CompareToConstant_const_lc;
                                   // Mask Parameter: CompareToConstant_const_lc
                                      //  Referenced by: '<S387>/Constant'

  real_T ThreeaxisInertialMeasurementU_i[3];
                              // Mask Parameter: ThreeaxisInertialMeasurementU_i
                                 //  Referenced by: '<S424>/Measurement bias'

  real_T ThreeaxisInertialMeasurementU_f[3];
                              // Mask Parameter: ThreeaxisInertialMeasurementU_f
                                 //  Referenced by: '<S424>/g-sensitive bias'

  real_T ThreeaxisInertialMeasurementU_j[9];
                              // Mask Parameter: ThreeaxisInertialMeasurementU_j
                                 //  Referenced by: '<S424>/Scale factors & Cross-coupling  errors '

  real_T ThreeaxisInertialMeasurement_j5[3];
                              // Mask Parameter: ThreeaxisInertialMeasurement_j5
                                 //  Referenced by: '<S423>/wl_ins'

  real_T CustomVariableMass6DOFQuaternio;
                              // Mask Parameter: CustomVariableMass6DOFQuaternio
                                 //  Referenced by: '<S24>/High Gain Quaternion Normalization'

  real_T CheckAltitude_max;            // Mask Parameter: CheckAltitude_max
                                          //  Referenced by: '<S441>/max_val'

  real_T CheckLatitude_max;            // Mask Parameter: CheckLatitude_max
                                          //  Referenced by: '<S442>/max_val'

  real_T CheckLongitude_max;           // Mask Parameter: CheckLongitude_max
                                          //  Referenced by: '<S443>/max_val'

  real_T Istimewithinmodellimits_max;
                                  // Mask Parameter: Istimewithinmodellimits_max
                                     //  Referenced by: '<S445>/max_val'

  real_T CheckAltitude_min;            // Mask Parameter: CheckAltitude_min
                                          //  Referenced by: '<S441>/min_val'

  real_T CheckLatitude_min;            // Mask Parameter: CheckLatitude_min
                                          //  Referenced by: '<S442>/min_val'

  real_T CheckLongitude_min;           // Mask Parameter: CheckLongitude_min
                                          //  Referenced by: '<S443>/min_val'

  real_T Istimewithinmodellimits_min;
                                  // Mask Parameter: Istimewithinmodellimits_min
                                     //  Referenced by: '<S445>/min_val'

  real_T FlatEarthtoLLA_psi;           // Mask Parameter: FlatEarthtoLLA_psi
                                          //  Referenced by: '<S69>/ref_rotation'

  real_T FlatEarthtoLLA_psi_b;         // Mask Parameter: FlatEarthtoLLA_psi_b
                                          //  Referenced by: '<S374>/ref_rotation'

  real_T WhiteNoise_pwr[4];            // Mask Parameter: WhiteNoise_pwr
                                          //  Referenced by: '<S129>/Constant'

  real_T WhiteNoise_pwr_d[4];          // Mask Parameter: WhiteNoise_pwr_d
                                          //  Referenced by: '<S90>/Constant'

  real_T DirectionCosineMatrixtoQuater_i;
                              // Mask Parameter: DirectionCosineMatrixtoQuater_i
                                 //  Referenced by: '<S202>/If Warning//Error'

  real_T DirectionCosineMatrixtoQuate_i5;
                              // Mask Parameter: DirectionCosineMatrixtoQuate_i5
                                 //  Referenced by: '<S240>/If Warning//Error'

  real_T DirectionCosineMatrixtoQuater_b;
                              // Mask Parameter: DirectionCosineMatrixtoQuater_b
                                 //  Referenced by: '<S334>/If Warning//Error'

  real_T ThreeaxisInertialMeasurementU_e;
                              // Mask Parameter: ThreeaxisInertialMeasurementU_e
                                 //  Referenced by:
                                 //    '<S429>/2*zeta * wn'
                                 //    '<S429>/wn^2'

  real_T ThreeaxisInertialMeasurementU_m;
                              // Mask Parameter: ThreeaxisInertialMeasurementU_m
                                 //  Referenced by:
                                 //    '<S440>/2*zeta * wn'
                                 //    '<S440>/wn^2'

  real_T ThreeaxisInertialMeasurementU_n;
                              // Mask Parameter: ThreeaxisInertialMeasurementU_n
                                 //  Referenced by: '<S429>/2*zeta * wn'

  real_T ThreeaxisInertialMeasurement_jx;
                              // Mask Parameter: ThreeaxisInertialMeasurement_jx
                                 //  Referenced by: '<S440>/2*zeta * wn'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S41>/Constant'

  real_T Constant_Value_l;             // Expression: 1
                                          //  Referenced by: '<S42>/Constant'

  real_T Gain_Gain;                    // Expression: 1
                                          //  Referenced by: '<S101>/Gain'

  real_T Gain_Gain_c;                  // Expression: 1
                                          //  Referenced by: '<S109>/Gain'

  real_T Gain_Gain_e;                  // Expression: 1
                                          //  Referenced by: '<S140>/Gain'

  real_T Gain_Gain_n;                  // Expression: 1
                                          //  Referenced by: '<S148>/Gain'

  real_T Bias_Bias;                    // Expression: -90
                                          //  Referenced by: '<S161>/Bias'

  real_T Gain_Gain_o;                  // Expression: -1
                                          //  Referenced by: '<S161>/Gain'

  real_T Bias1_Bias;                   // Expression: +90
                                          //  Referenced by: '<S161>/Bias1'

  real_T Bias_Bias_f;                  // Expression: 180
                                          //  Referenced by: '<S164>/Bias'

  real_T Bias1_Bias_m;                 // Expression: -180
                                          //  Referenced by: '<S164>/Bias1'

  real_T Bias_Bias_b;                  // Expression: 180
                                          //  Referenced by: '<S162>/Bias'

  real_T Bias1_Bias_ms;                // Expression: -180
                                          //  Referenced by: '<S162>/Bias1'

  real_T Bias_Bias_g;                  // Expression: -90
                                          //  Referenced by: '<S167>/Bias'

  real_T Gain_Gain_l;                  // Expression: -1
                                          //  Referenced by: '<S167>/Gain'

  real_T Bias1_Bias_f;                 // Expression: +90
                                          //  Referenced by: '<S167>/Bias1'

  real_T Constant2_Value;              // Expression: 360
                                          //  Referenced by: '<S170>/Constant2'

  real_T Bias_Bias_gu;                 // Expression: 180
                                          //  Referenced by: '<S170>/Bias'

  real_T Bias1_Bias_d;                 // Expression: -180
                                          //  Referenced by: '<S170>/Bias1'

  real_T Constant_Value_e;             // Expression: 180
                                          //  Referenced by: '<S158>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S158>/Constant1'

  real_T Constant2_Value_o;            // Expression: 360
                                          //  Referenced by: '<S168>/Constant2'

  real_T Bias_Bias_p;                  // Expression: 180
                                          //  Referenced by: '<S168>/Bias'

  real_T Bias1_Bias_j;                 // Expression: -180
                                          //  Referenced by: '<S168>/Bias1'

  real_T Bias_Bias_a;                  // Expression: -90
                                          //  Referenced by: '<S382>/Bias'

  real_T Gain_Gain_i;                  // Expression: -1
                                          //  Referenced by: '<S382>/Gain'

  real_T Bias1_Bias_e;                 // Expression: +90
                                          //  Referenced by: '<S382>/Bias1'

  real_T Bias_Bias_i;                  // Expression: 180
                                          //  Referenced by: '<S385>/Bias'

  real_T Bias1_Bias_n;                 // Expression: -180
                                          //  Referenced by: '<S385>/Bias1'

  real_T Bias_Bias_gc;                 // Expression: 180
                                          //  Referenced by: '<S383>/Bias'

  real_T Bias1_Bias_jx;                // Expression: -180
                                          //  Referenced by: '<S383>/Bias1'

  real_T Bias_Bias_m;                  // Expression: -90
                                          //  Referenced by: '<S388>/Bias'

  real_T Gain_Gain_m;                  // Expression: -1
                                          //  Referenced by: '<S388>/Gain'

  real_T Bias1_Bias_dk;                // Expression: +90
                                          //  Referenced by: '<S388>/Bias1'

  real_T Constant2_Value_f;            // Expression: 360
                                          //  Referenced by: '<S391>/Constant2'

  real_T Bias_Bias_l;                  // Expression: 180
                                          //  Referenced by: '<S391>/Bias'

  real_T Bias1_Bias_c;                 // Expression: -180
                                          //  Referenced by: '<S391>/Bias1'

  real_T Constant_Value_i;             // Expression: 180
                                          //  Referenced by: '<S379>/Constant'

  real_T Constant1_Value_m;            // Expression: 0
                                          //  Referenced by: '<S379>/Constant1'

  real_T Constant2_Value_p;            // Expression: 360
                                          //  Referenced by: '<S389>/Constant2'

  real_T Bias_Bias_e;                  // Expression: 180
                                          //  Referenced by: '<S389>/Bias'

  real_T Bias1_Bias_k;                 // Expression: -180
                                          //  Referenced by: '<S389>/Bias1'

  real_T Bias_Bias_k;                  // Expression: -90
                                          //  Referenced by: '<S452>/Bias'

  real_T Gain_Gain_k;                  // Expression: -1
                                          //  Referenced by: '<S452>/Gain'

  real_T Bias1_Bias_i;                 // Expression: +90
                                          //  Referenced by: '<S452>/Bias1'

  real_T Bias_Bias_pe;                 // Expression: 180
                                          //  Referenced by: '<S455>/Bias'

  real_T Bias1_Bias_p;                 // Expression: -180
                                          //  Referenced by: '<S455>/Bias1'

  real_T Bias_Bias_c;                  // Expression: 180
                                          //  Referenced by: '<S453>/Bias'

  real_T Bias1_Bias_a;                 // Expression: -180
                                          //  Referenced by: '<S453>/Bias1'

  real_T pp13_Y0[13];                  // Expression: ones(1,maxdef+1)
                                          //  Referenced by: '<S474>/pp[13]'

  real_T Constant_Value_ey;            // Expression: 1
                                          //  Referenced by: '<S474>/Constant'

  real_T pp13_Y0_j[13];                // Expression: ones(1,maxdef+1)
                                          //  Referenced by: '<S475>/pp[13]'

  real_T k1313_Value[169];             // Expression: k
                                          //  Referenced by: '<S475>/k[13][13]'

  real_T bpp_Y0;                       // Expression: 0
                                          //  Referenced by: '<S470>/bpp'

  real_T Constant_Value_j;             // Expression: fm(2)
                                          //  Referenced by: '<S470>/Constant'

  real_T Constant1_Value_o;            // Expression: 1
                                          //  Referenced by: '<S470>/Constant1'

  real_T UnitDelay1_InitialCondition[13];// Expression: ones(1,maxdef+1)
                                            //  Referenced by: '<S470>/Unit Delay1'

  real_T Constant_Value_p;             // Expression: 1
                                          //  Referenced by: '<S478>/Constant'

  real_T Gain1_Gain;                   // Expression: 1
                                          //  Referenced by: '<S478>/Gain1'

  real_T Gain2_Gain;                   // Expression: 1
                                          //  Referenced by: '<S478>/Gain2'

  real_T Constant_Value_o;             // Expression: 1
                                          //  Referenced by: '<S480>/Constant'

  real_T Constant_Value_ly;            // Expression: 1
                                          //  Referenced by: '<S481>/Constant'

  real_T Constant1_Value_b;            // Expression: 0
                                          //  Referenced by: '<S484>/Constant1'

  real_T Constant_Value_ev;            // Expression: 0
                                          //  Referenced by: '<S484>/Constant'

  real_T Switch_Threshold;             // Expression: 0.5
                                          //  Referenced by: '<S484>/Switch'

  real_T k1313_Value_k[169];           // Expression: k
                                          //  Referenced by: '<S484>/k[13][13]'

  real_T Switch1_Threshold;            // Expression: 0.5
                                          //  Referenced by: '<S484>/Switch1'

  real_T dp1313_Y0[169];               // Expression: zeros(maxdef+1,maxdef+1)
                                          //  Referenced by: '<S468>/dp[13][13]'

  real_T snorm169_Y0[169];             // Expression: snorm
                                          //  Referenced by: '<S468>/snorm[169]'

  real_T UnitDelay_InitialCondition[169];// Expression: zeros(maxdef+1,maxdef+1)
                                            //  Referenced by: '<S468>/Unit Delay'

  real_T UnitDelay1_InitialCondition_k[169];// Expression: snorm
                                               //  Referenced by: '<S468>/Unit Delay1'

  real_T Merge1_InitialOutput;         // Expression: 0
                                          //  Referenced by: '<S468>/Merge1'

  real_T Merge_InitialOutput;          // Expression: 0
                                          //  Referenced by: '<S468>/Merge'

  real_T Gain_Gain_ng;                 // Expression: 1
                                          //  Referenced by: '<S497>/Gain'

  real_T zerosmaxdef1maxdef1_Value[169];// Expression: zeros(maxdef+1,maxdef+1)
                                           //  Referenced by: '<S496>/zeros(maxdef+1,maxdef+1)'

  real_T tc1313_Y0[169];               // Expression: zeros(maxdef+1,maxdef+1)
                                          //  Referenced by: '<S469>/tc[13][13]'

  real_T UnitDelay_InitialCondition_g[169];// Expression: zeros(maxdef+1,maxdef+1)
                                              //  Referenced by: '<S469>/Unit Delay'

  real_T cmaxdefmaxdef_Value[169];     // Expression: c
                                          //  Referenced by: '<S469>/c[maxdef][maxdef]'

  real_T cdmaxdefmaxdef_Value[169];    // Expression: cd
                                          //  Referenced by: '<S469>/cd[maxdef][maxdef]'

  real_T UnitDelay_InitialCondition_k[169];// Expression: zeros(maxdef+1,maxdef+1)
                                              //  Referenced by: '<S496>/Unit Delay'

  real_T bt_Y0;                        // Expression: 0
                                          //  Referenced by: '<S466>/bt'

  real_T bp_Y0;                        // Expression: 0
                                          //  Referenced by: '<S466>/bp'

  real_T br_Y0;                        // Expression: 0
                                          //  Referenced by: '<S466>/br'

  real_T bpp_Y0_l;                     // Expression: 0
                                          //  Referenced by: '<S466>/bpp'

  real_T Constant1_Value_m1;           // Expression: 1
                                          //  Referenced by: '<S472>/Constant1'

  real_T Merge_InitialOutput_p;        // Expression: 0
                                          //  Referenced by: '<S472>/Merge'

  real_T fm_Value[13];                 // Expression: fm
                                          //  Referenced by: '<S467>/fm'

  real_T Merge1_InitialOutput_e;       // Expression: 0
                                          //  Referenced by: '<S472>/Merge1'

  real_T fn_Value[13];                 // Expression: fn
                                          //  Referenced by: '<S467>/fn'

  real_T Constant1_Value_g;            // Expression: 0
                                          //  Referenced by: '<S473>/Constant1'

  real_T UnitDelay1_InitialCondition_m;// Expression: 0
                                          //  Referenced by: '<S467>/Unit Delay1'

  real_T UnitDelay3_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S467>/Unit Delay3'

  real_T UnitDelay2_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S467>/Unit Delay2'

  real_T UnitDelay4_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S467>/Unit Delay4'

  real_T btbpbrbpp_Y0[4];              // Expression: [0 0 0 0]
                                          //  Referenced by: '<S458>/bt,bp,br,bpp'

  real_T UnitDelay_InitialCondition_j; // Expression: 0
                                          //  Referenced by: '<S458>/Unit Delay'

  real_T UnitDelay2_InitialCondition_h[4];// Expression: [0 0 0 0]
                                             //  Referenced by: '<S458>/Unit Delay2'

  real_T r_Y0;                         // Expression: 6378.137
                                          //  Referenced by: '<S459>/r'

  real_T ct_Y0;                        // Expression: 1
                                          //  Referenced by: '<S459>/ct'

  real_T st_Y0;                        // Expression: 0
                                          //  Referenced by: '<S459>/st'

  real_T sa_Y0;                        // Expression: 0
                                          //  Referenced by: '<S459>/sa'

  real_T ca_Y0;                        // Expression: 0
                                          //  Referenced by: '<S459>/ca'

  real_T b_Value;                      // Expression: 6356.7523142
                                          //  Referenced by: '<S459>/b'

  real_T a_Value;                      // Expression: 6378.137
                                          //  Referenced by: '<S459>/a'

  real_T Gain_Gain_p;                  // Expression: 2
                                          //  Referenced by: '<S504>/Gain'

  real_T Constant_Value_ou;            // Expression: 1
                                          //  Referenced by: '<S506>/Constant'

  real_T sp11_Y0[11];                  // Expression: (1:(maxdef-1))
                                          //  Referenced by: '<S507>/sp[11]'

  real_T cp11_Y0[11];                  // Expression: (1:(maxdef-1))
                                          //  Referenced by: '<S507>/cp[11]'

  real_T ForIterator_IterationLimit;   // Expression: maxdef-1
                                          //  Referenced by: '<S507>/For Iterator'

  real_T Constant_Value_n[11];         // Expression: [1:maxdef-1]
                                          //  Referenced by: '<S507>/Constant'

  real_T UnitDelay1_InitialCondition_l;// Expression: 0
                                          //  Referenced by: '<S507>/Unit Delay1'

  real_T cpm1spm1_Threshold;           // Expression: 1
                                          //  Referenced by: '<S507>/cp[m-1] sp[m-1]'

  real_T Constant1_Value_mc[11];       // Expression: [1:maxdef-1]
                                          //  Referenced by: '<S507>/Constant1'

  real_T sp13_Y0[13];                  // Expression: [0 0 (1:(maxdef-1))]
                                          //  Referenced by: '<S460>/sp[13]'

  real_T cp13_Y0[13];                  // Expression: [1 1 (1:(maxdef-1))]
                                          //  Referenced by: '<S460>/cp[13]'

  real_T Gain_Gain_h;                  // Expression: 1
                                          //  Referenced by: '<S460>/Gain'

  real_T Gain1_Gain_k;                 // Expression: 1
                                          //  Referenced by: '<S460>/Gain1'

  real_T cp1_Value;                    // Expression: 1
                                          //  Referenced by: '<S460>/cp[1]'

  real_T sp1_Value;                    // Expression: 0
                                          //  Referenced by: '<S460>/sp[1]'

  real_T Gain_clock_Gain;              // Expression: 1E6
                                          //  Referenced by: '<S11>/Gain_clock'

  real_T IntegratorSecondOrderLimited_IC;// Expression: 0
                                            //  Referenced by: '<S429>/Integrator, Second-Order Limited'

  real_T IntegratorSecondOrderLimited__d;// Expression: 0
                                            //  Referenced by: '<S429>/Integrator, Second-Order Limited'

  real_T Constant_Value_pl;            // Expression: dtype_a
                                          //  Referenced by: '<S425>/Constant'

  real_T u2_Gain;                      // Expression: 0.5
                                          //  Referenced by: '<S23>/1//2'

  real_T Gain_Gain_pu;                 // Expression: 2
                                          //  Referenced by: '<S28>/Gain'

  real_T Gain_Gain_oj;                 // Expression: 2
                                          //  Referenced by: '<S31>/Gain'

  real_T Gain_Gain_n3;                 // Expression: 2
                                          //  Referenced by: '<S26>/Gain'

  real_T Gain_Gain_nd;                 // Expression: 2
                                          //  Referenced by: '<S32>/Gain'

  real_T Gain_Gain_a;                  // Expression: 2
                                          //  Referenced by: '<S27>/Gain'

  real_T Gain_Gain_cm;                 // Expression: 2
                                          //  Referenced by: '<S30>/Gain'

  real_T Constant2_Value_j;            // Expression: 1
                                          //  Referenced by: '<S173>/Constant2'

  real_T Constant1_Value_k;            // Expression: R
                                          //  Referenced by: '<S173>/Constant1'

  real_T Constant_Value_b;             // Expression: 1
                                          //  Referenced by: '<S176>/Constant'

  real_T Constant_Value_pr;            // Expression: 1
                                          //  Referenced by: '<S178>/Constant'

  real_T Constant_Value_k;             // Expression: F
                                          //  Referenced by: '<S177>/Constant'

  real_T f_Value;                      // Expression: 1
                                          //  Referenced by: '<S177>/f'

  real_T Constant_Value_n3;            // Expression: 1
                                          //  Referenced by: '<S173>/Constant'

  real_T Constant3_Value;              // Expression: 1
                                          //  Referenced by: '<S173>/Constant3'

  real_T Constant2_Value_pf;           // Expression: 360
                                          //  Referenced by: '<S164>/Constant2'

  real_T Constant_Value_d;             // Expression: 180
                                          //  Referenced by: '<S157>/Constant'

  real_T Constant1_Value_i;            // Expression: 0
                                          //  Referenced by: '<S157>/Constant1'

  real_T Constant2_Value_e;            // Expression: 360
                                          //  Referenced by: '<S162>/Constant2'

  real_T Saturation_1_UpperSat;        // Expression: 100000
                                          //  Referenced by: '<S61>/Saturation_1'

  real_T Saturation_1_LowerSat;        // Expression: 0
                                          //  Referenced by: '<S61>/Saturation_1'

  real_T JulianDate_Value;             // Expression: juliandate(year,month,day)
                                          //  Referenced by: '<S76>/Julian Date'

  real_T Merge_InitialOutput_f[4];     // Expression: [1 0 0 0]
                                          //  Referenced by: '<S192>/Merge'

  real_T Merge_InitialOutput_h[4];     // Expression: [1 0 0 0]
                                          //  Referenced by: '<S191>/Merge'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<Root>/Memory'

  real_T MotorFault3_Gain;             // Expression: 1/4.2
                                          //  Referenced by: '<S55>/MotorFault3'

  real_T Constant_111_Value[3];        // Expression: [1,1,1]
                                          //  Referenced by: '<S61>/Constant_[1 1 1]'

  real_T UniformRandomNumber_Minimum[3];// Expression: [-1,-1,-0.5]
                                           //  Referenced by: '<S61>/Uniform Random Number'

  real_T UniformRandomNumber_Maximum[3];// Expression: [1,1,0.5]
                                           //  Referenced by: '<S61>/Uniform Random Number'

  real_T UniformRandomNumber_Seed[3];  // Expression: [564565,6846798,46545]
                                          //  Referenced by: '<S61>/Uniform Random Number'

  real_T Gain_1_Gain;                  // Expression: -1
                                          //  Referenced by: '<S61>/Gain_-1'

  real_T Saturation_2_UpperSat;        // Expression: 10000
                                          //  Referenced by: '<S61>/Saturation_2'

  real_T Saturation_2_LowerSat;        // Expression: 0
                                          //  Referenced by: '<S61>/Saturation_2'

  real_T Constant_V_Value;             // Expression: 5
                                          //  Referenced by: '<S61>/Constant_V'

  real_T LimitFunction10ftto1000ft_Upper;// Expression: max_height_low
                                            //  Referenced by: '<S154>/Limit Function 10ft to 1000ft'

  real_T LimitFunction10ftto1000ft_Lower;// Expression: 10
                                            //  Referenced by: '<S154>/Limit Function 10ft to 1000ft'

  real_T LimitHeighth1000ft_UpperSat;  // Expression: max_height_low
                                          //  Referenced by: '<S137>/Limit Height h<1000ft'

  real_T LimitHeighth1000ft_LowerSat;  // Expression: 0
                                          //  Referenced by: '<S137>/Limit Height h<1000ft'

  real_T sigma_wg_Gain;                // Expression: 0.1
                                          //  Referenced by: '<S137>/sigma_wg '

  real_T PreLookUpIndexSearchaltitude_Br[12];// Expression: h_vec
                                                //  Referenced by: '<S136>/PreLook-Up Index Search  (altitude)'

  real_T PreLookUpIndexSearchprobofexcee[7];// Expression: [1:7]
                                               //  Referenced by: '<S136>/PreLook-Up Index Search  (prob of exceed)'

  real_T MediumHighAltitudeIntensity_Tab[84];// Expression: sigma_vec'
                                                //  Referenced by: '<S136>/Medium//High Altitude Intensity'

  real_T WhiteNoise_Mean;              // Expression: 0
                                          //  Referenced by: '<S129>/White Noise'

  real_T WhiteNoise_StdDev;            // Computed Parameter: WhiteNoise_StdDev
                                          //  Referenced by: '<S129>/White Noise'

  real_T Lv_Gain;                      // Expression: 1
                                          //  Referenced by: '<S126>/Lv'

  real_T Lw_Gain;                      // Expression: 1
                                          //  Referenced by: '<S126>/Lw'

  real_T Constant_DCM_Value[9];        // Expression: eye(3)
                                          //  Referenced by: '<S61>/Constant_DCM'

  real_T LimitFunction10ftto1000ft_Upp_a;// Expression: max_height_low
                                            //  Referenced by: '<S115>/Limit Function 10ft to 1000ft'

  real_T LimitFunction10ftto1000ft_Low_l;// Expression: 10
                                            //  Referenced by: '<S115>/Limit Function 10ft to 1000ft'

  real_T LimitHeighth1000ft_UpperSat_d;// Expression: max_height_low
                                          //  Referenced by: '<S98>/Limit Height h<1000ft'

  real_T LimitHeighth1000ft_LowerSat_k;// Expression: 0
                                          //  Referenced by: '<S98>/Limit Height h<1000ft'

  real_T sigma_wg_Gain_h;              // Expression: 0.1
                                          //  Referenced by: '<S98>/sigma_wg '

  real_T PreLookUpIndexSearchaltitude__k[12];// Expression: h_vec
                                                //  Referenced by: '<S97>/PreLook-Up Index Search  (altitude)'

  real_T PreLookUpIndexSearchprobofexc_f[7];// Expression: [1:7]
                                               //  Referenced by: '<S97>/PreLook-Up Index Search  (prob of exceed)'

  real_T MediumHighAltitudeIntensity_T_c[84];// Expression: sigma_vec'
                                                //  Referenced by: '<S97>/Medium//High Altitude Intensity'

  real_T WhiteNoise_Mean_m;            // Expression: 0
                                          //  Referenced by: '<S90>/White Noise'

  real_T WhiteNoise_StdDev_h;         // Computed Parameter: WhiteNoise_StdDev_h
                                         //  Referenced by: '<S90>/White Noise'

  real_T Lv_Gain_g;                    // Expression: 1
                                          //  Referenced by: '<S87>/Lv'

  real_T Lw_Gain_g;                    // Expression: 1
                                          //  Referenced by: '<S87>/Lw'

  real_T uftinf_UpperSat;              // Expression: inf
                                          //  Referenced by: '<S77>/3ft-->inf'

  real_T uftinf_LowerSat;              // Expression: 3
                                          //  Referenced by: '<S77>/3ft-->inf'

  real_T hz0_Gain;                     // Expression: 1/z0
                                          //  Referenced by: '<S77>/h//z0'

  real_T ref_heightz0_Value;           // Expression: 20/z0
                                          //  Referenced by: '<S77>/ref_height//z0'

  real_T Wdeg1_Value;                  // Expression: 0
                                          //  Referenced by: '<S77>/Wdeg1'

  real_T rotor_k_ct_Value[8];          // Expression: [1,1,1,1,1,1,1,1]
                                          //  Referenced by: '<S286>/rotor_k_ct'

  real_T ZeroOrderHold1_Gain;          // Expression: 1
                                          //  Referenced by: '<S423>/Zero-Order Hold1'

  real_T ZeroOrderHold2_Gain;          // Expression: 1
                                          //  Referenced by: '<S423>/Zero-Order Hold2'

  real_T ZeroOrderHold_Gain;           // Expression: 1
                                          //  Referenced by: '<S423>/Zero-Order Hold'

  real_T centerofgravity_Value[3];     // Expression: [0 0 0]
                                          //  Referenced by: '<S400>/center of gravity'

  real_T ZeroOrderHold4_Gain;          // Expression: 1
                                          //  Referenced by: '<S423>/Zero-Order Hold4'

  real_T Gain_Gain_mp[3];              // Expression: [1 -1 1]
                                          //  Referenced by: '<S423>/Gain'

  real_T Constant_dIdt_Value[9];       // Expression: zeros(3,3)
                                          //  Referenced by: '<S1>/Constant_dI//dt'

  real_T ZeroOrderHold3_Gain;          // Expression: 1
                                          //  Referenced by: '<S423>/Zero-Order Hold3'

  real_T Switch_Threshold_g;           // Expression: 0.5
                                          //  Referenced by: '<S425>/Switch'

  real_T Saturation_UpperSat[3];       // Expression: a_sath
                                          //  Referenced by: '<S423>/Saturation'

  real_T Saturation_LowerSat[3];       // Expression: a_satl
                                          //  Referenced by: '<S423>/Saturation'

  real_T UniformRandomNumber5_Minimum[3];// Expression: -[0.1,0.1,0.2]
                                            //  Referenced by: '<S400>/Uniform Random Number5'

  real_T UniformRandomNumber5_Maximum[3];// Expression: [0.1,0.1,0.2]
                                            //  Referenced by: '<S400>/Uniform Random Number5'

  real_T UniformRandomNumber5_Seed[3]; // Expression: [12233,645554,678766]
                                          //  Referenced by: '<S400>/Uniform Random Number5'

  real_T Gain10_Gain;                  // Expression: 5
                                          //  Referenced by: '<S400>/Gain10'

  real_T IntegratorSecondOrderLimited__l;// Expression: 0
                                            //  Referenced by: '<S440>/Integrator, Second-Order Limited'

  real_T IntegratorSecondOrderLimited__f;// Expression: 0
                                            //  Referenced by: '<S440>/Integrator, Second-Order Limited'

  real_T Constant_Value_h;             // Expression: dtype_g
                                          //  Referenced by: '<S438>/Constant'

  real_T ZeroOrderHold_Gain_k;         // Expression: 1
                                          //  Referenced by: '<S424>/Zero-Order Hold'

  real_T ZeroOrderHold1_Gain_n;        // Expression: 1
                                          //  Referenced by: '<S424>/Zero-Order Hold1'

  real_T Switch_Threshold_p;           // Expression: 0.5
                                          //  Referenced by: '<S438>/Switch'

  real_T Saturation_UpperSat_f[3];     // Expression: g_sath
                                          //  Referenced by: '<S424>/Saturation'

  real_T Saturation_LowerSat_d[3];     // Expression: g_satl
                                          //  Referenced by: '<S424>/Saturation'

  real_T UniformRandomNumber1_Minimum[3];// Expression: -[0.01,0.01,0.01]
                                            //  Referenced by: '<S400>/Uniform Random Number1'

  real_T UniformRandomNumber1_Maximum[3];// Expression: [0.01,0.01,0.01]
                                            //  Referenced by: '<S400>/Uniform Random Number1'

  real_T UniformRandomNumber1_Seed[3]; // Expression: [3243,44556,2334343]
                                          //  Referenced by: '<S400>/Uniform Random Number1'

  real_T Gain6_Gain;                   // Expression: 5
                                          //  Referenced by: '<S400>/Gain6'

  real_T epoch_Value;                  // Expression: epoch
                                          //  Referenced by: '<S450>/epoch'

  real_T DecimalYear_Value;            // Expression: dyear
                                          //  Referenced by: '<S416>/Decimal Year'

  real_T otime_InitialCondition;       // Expression: -1000
                                          //  Referenced by: '<S464>/otime'

  real_T Constant_Value_bc;            // Expression: 180
                                          //  Referenced by: '<S446>/Constant'

  real_T Constant2_Value_o1;           // Expression: 360
                                          //  Referenced by: '<S455>/Constant2'

  real_T Constant1_Value_h;            // Expression: 0
                                          //  Referenced by: '<S446>/Constant1'

  real_T Constant2_Value_h;            // Expression: 360
                                          //  Referenced by: '<S453>/Constant2'

  real_T olon_InitialCondition;        // Expression: -1000
                                          //  Referenced by: '<S463>/olon'

  real_T olat_InitialCondition;        // Expression: -1000
                                          //  Referenced by: '<S462>/olat'

  real_T Gain_Gain_j;                  // Expression: 0.001
                                          //  Referenced by: '<S416>/Gain'

  real_T oalt_InitialCondition;        // Expression: -1000
                                          //  Referenced by: '<S462>/oalt'

  real_T re_Value;                     // Expression: 6371.2
                                          //  Referenced by: '<S450>/re'

  real_T Gain_Mag_Gain;                // Expression: 1
                                          //  Referenced by: '<S400>/Gain_Mag'

  real_T nT2Gauss_Gain;                // Expression: 1E-5
                                          //  Referenced by: '<S400>/nT2Gauss'

  real_T UniformRandomNumber7_Minimum[3];// Expression: -[0.01,0.01,0.01]
                                            //  Referenced by: '<S400>/Uniform Random Number7'

  real_T UniformRandomNumber7_Maximum[3];// Expression: [0.01,0.01,0.01]
                                            //  Referenced by: '<S400>/Uniform Random Number7'

  real_T UniformRandomNumber7_Seed[3]; // Expression: [45465,454534,1234232]
                                          //  Referenced by: '<S400>/Uniform Random Number7'

  real_T Gain11_Gain;                  // Expression: 2
                                          //  Referenced by: '<S400>/Gain11'

  real_T SeaLevelTemperature_Value;    // Expression: T0
                                          //  Referenced by: '<S412>/Sea Level  Temperature'

  real_T SeaLevelTemperature_Value_g;  // Expression: T0
                                          //  Referenced by: '<S70>/Sea Level  Temperature'

  real_T Limitaltitudetotroposhere_Upper;// Expression: h_trop
                                            //  Referenced by: '<S70>/Limit  altitude  to troposhere'

  real_T Limitaltitudetotroposhere_Lower;// Expression: h0
                                            //  Referenced by: '<S70>/Limit  altitude  to troposhere'

  real_T LapseRate_Gain;               // Expression: L
                                          //  Referenced by: '<S70>/Lapse Rate'

  real_T uT0_Gain;                     // Expression: 1/T0
                                          //  Referenced by: '<S70>/1//T0'

  real_T Constant_Value_bw;            // Expression: g/(L*R)
                                          //  Referenced by: '<S70>/Constant'

  real_T rho0_Gain;                    // Expression: rho0
                                          //  Referenced by: '<S70>/rho0'

  real_T AltitudeofTroposphere_Value;  // Expression: h_trop
                                          //  Referenced by: '<S70>/Altitude of Troposphere'

  real_T LimitaltitudetoStratosphere_Upp;// Expression: 0
                                            //  Referenced by: '<S70>/Limit  altitude  to Stratosphere'

  real_T LimitaltitudetoStratosphere_Low;// Expression: h_trop-h_strat
                                            //  Referenced by: '<S70>/Limit  altitude  to Stratosphere'

  real_T gR_Gain;                      // Expression: g/R
                                          //  Referenced by: '<S70>/g//R'

  real_T u2rhoV2_Gain;                 // Expression: 1/2
                                          //  Referenced by: '<S403>/1//2rhoV^2'

  real_T Constant1_Value_j;            // Expression: 0
                                          //  Referenced by: '<S400>/Constant1'

  real_T UniformRandomNumber_Minimum_h;// Expression: -2
                                          //  Referenced by: '<S400>/Uniform Random Number'

  real_T UniformRandomNumber_Maximum_j;// Expression: 2
                                          //  Referenced by: '<S400>/Uniform Random Number'

  real_T UniformRandomNumber_Seed_o;   // Expression: 15634
                                          //  Referenced by: '<S400>/Uniform Random Number'

  real_T Gain5_Gain;                   // Expression: 0.2
                                          //  Referenced by: '<S400>/Gain5'

  real_T Constant2_Value_c;            // Expression: 0.3
                                          //  Referenced by: '<S410>/Constant2'

  real_T Limitaltitudetotroposhere_Upp_p;// Expression: h_trop
                                            //  Referenced by: '<S412>/Limit  altitude  to troposhere'

  real_T Limitaltitudetotroposhere_Low_f;// Expression: h0
                                            //  Referenced by: '<S412>/Limit  altitude  to troposhere'

  real_T LapseRate_Gain_n;             // Expression: L
                                          //  Referenced by: '<S412>/Lapse Rate'

  real_T uT0_Gain_a;                   // Expression: 1/T0
                                          //  Referenced by: '<S412>/1//T0'

  real_T Constant_Value_h1;            // Expression: g/(L*R)
                                          //  Referenced by: '<S412>/Constant'

  real_T P0_Gain;                      // Expression: P0
                                          //  Referenced by: '<S412>/P0'

  real_T AltitudeofTroposphere_Value_k;// Expression: h_trop
                                          //  Referenced by: '<S412>/Altitude of Troposphere'

  real_T LimitaltitudetoStratosphere_U_k;// Expression: 0
                                            //  Referenced by: '<S412>/Limit  altitude  to Stratosphere'

  real_T LimitaltitudetoStratosphere_L_m;// Expression: h_trop-h_strat
                                            //  Referenced by: '<S412>/Limit  altitude  to Stratosphere'

  real_T gR_Gain_b;                    // Expression: g/R
                                          //  Referenced by: '<S412>/g//R'

  real_T Gain_Gain_nb;                 // Expression: 0.01
                                          //  Referenced by: '<S400>/Gain'

  real_T UniformRandomNumber2_Minimum; // Expression: -1
                                          //  Referenced by: '<S400>/Uniform Random Number2'

  real_T UniformRandomNumber2_Maximum; // Expression: 1
                                          //  Referenced by: '<S400>/Uniform Random Number2'

  real_T UniformRandomNumber2_Seed;    // Expression: 45465
                                          //  Referenced by: '<S400>/Uniform Random Number2'

  real_T Gain7_Gain;                   // Expression: 10
                                          //  Referenced by: '<S400>/Gain7'

  real_T UniformRandomNumber4_Minimum; // Expression: -1
                                          //  Referenced by: '<S400>/Uniform Random Number4'

  real_T UniformRandomNumber4_Maximum; // Expression: 1
                                          //  Referenced by: '<S400>/Uniform Random Number4'

  real_T UniformRandomNumber4_Seed;    // Expression: 25634
                                          //  Referenced by: '<S400>/Uniform Random Number4'

  real_T Gain9_Gain;                   // Expression: 0.01
                                          //  Referenced by: '<S400>/Gain9'

  real_T Constant_Value_a;             // Expression: 0.5
                                          //  Referenced by: '<S411>/Constant'

  real_T Gain2_Gain_o;                 // Expression: 0.7
                                          //  Referenced by: '<S411>/Gain2'

  real_T Constant2_Value_m;            // Expression: 0.3
                                          //  Referenced by: '<S411>/Constant2'

  real_T Gain1_Gain_p;                 // Expression: 0.01
                                          //  Referenced by: '<S400>/Gain1'

  real_T Constant1_Value_gw;           // Expression: 10
                                          //  Referenced by: '<S61>/Constant1'

  real_T Constant_Value_hp;            // Expression: 8191
                                          //  Referenced by: '<S400>/Constant'

  real_T Merge_InitialOutput_fc[4];    // Expression: [1 0 0 0]
                                          //  Referenced by: '<S326>/Merge'

  real_T Gain_Gain_b;                  // Expression: 1E7
                                          //  Referenced by: '<S329>/Gain'

  real_T Gain1_Gain_kp;                // Expression: 1E7
                                          //  Referenced by: '<S329>/Gain1'

  real_T Gain3_Gain;                   // Expression: 1E3
                                          //  Referenced by: '<S329>/Gain3'

  real_T Gain4_Gain;                   // Expression: 100
                                          //  Referenced by: '<S329>/Gain4'

  real_T u2rhoV2_Gain_a;               // Expression: 1/2
                                          //  Referenced by: '<S515>/1//2rhoV^2'

  real_T Gain2_Gain_j;                 // Expression: 2/1.225
                                          //  Referenced by: '<S329>/Gain2'

  real_T Gain7_Gain_a;                 // Expression: 100
                                          //  Referenced by: '<S329>/Gain7'

  real_T Gain5_Gain_p;                 // Expression: 1000.0/9.80665
                                          //  Referenced by: '<S329>/Gain5'

  real_T UniformRandomNumber5_Minimum_o[3];// Expression: [-1,-1,-2]
                                              //  Referenced by: '<S327>/Uniform Random Number5'

  real_T UniformRandomNumber5_Maximum_l[3];// Expression: [1,1,2]
                                              //  Referenced by: '<S327>/Uniform Random Number5'

  real_T UniformRandomNumber5_Seed_j[3];// Expression: [1452,787,69]
                                           //  Referenced by: '<S327>/Uniform Random Number5'

  real_T BiasGain2_Gain;               // Expression: 0.2
                                          //  Referenced by: '<S327>/BiasGain2'

  real_T Constant2_Value_cv;           // Expression: 1
                                          //  Referenced by: '<S394>/Constant2'

  real_T Constant1_Value_iw;           // Expression: R
                                          //  Referenced by: '<S394>/Constant1'

  real_T Constant_Value_dm;            // Expression: 1
                                          //  Referenced by: '<S397>/Constant'

  real_T Constant_Value_n0;            // Expression: 1
                                          //  Referenced by: '<S399>/Constant'

  real_T Constant_Value_f;             // Expression: F
                                          //  Referenced by: '<S398>/Constant'

  real_T f_Value_i;                    // Expression: 1
                                          //  Referenced by: '<S398>/f'

  real_T Constant_Value_iy;            // Expression: 1
                                          //  Referenced by: '<S394>/Constant'

  real_T Constant3_Value_b;            // Expression: 1
                                          //  Referenced by: '<S394>/Constant3'

  real_T Constant2_Value_a;            // Expression: 360
                                          //  Referenced by: '<S385>/Constant2'

  real_T latScale_Gain;                // Expression: 1E7
                                          //  Referenced by: '<S327>/latScale'

  real_T Constant_Value_oo;            // Expression: 180
                                          //  Referenced by: '<S378>/Constant'

  real_T Constant1_Value_gi;           // Expression: 0
                                          //  Referenced by: '<S378>/Constant1'

  real_T Constant2_Value_ot;           // Expression: 360
                                          //  Referenced by: '<S383>/Constant2'

  real_T lonScale_Gain;                // Expression: 1E7
                                          //  Referenced by: '<S327>/lonScale'

  real_T Saturation_UpperSat_d;        // Expression: 100000
                                          //  Referenced by: '<S327>/Saturation'

  real_T Saturation_LowerSat_p;        // Expression: 0
                                          //  Referenced by: '<S327>/Saturation'

  real_T altScale_Gain;                // Expression: 1E3
                                          //  Referenced by: '<S327>/altScale'

  real_T Gain6_Gain_i;                 // Expression: 100
                                          //  Referenced by: '<S327>/Gain6'

  real_T Gain8_Gain;                   // Expression: 100
                                          //  Referenced by: '<S327>/Gain8'

  real_T TransferFcn4_A;               // Computed Parameter: TransferFcn4_A
                                          //  Referenced by: '<S376>/Transfer Fcn4'

  real_T TransferFcn4_C;               // Computed Parameter: TransferFcn4_C
                                          //  Referenced by: '<S376>/Transfer Fcn4'

  real_T TransferFcn1_A;               // Computed Parameter: TransferFcn1_A
                                          //  Referenced by: '<S376>/Transfer Fcn1'

  real_T TransferFcn1_C;               // Computed Parameter: TransferFcn1_C
                                          //  Referenced by: '<S376>/Transfer Fcn1'

  real_T TransferFcn2_A;               // Computed Parameter: TransferFcn2_A
                                          //  Referenced by: '<S376>/Transfer Fcn2'

  real_T TransferFcn2_C;               // Computed Parameter: TransferFcn2_C
                                          //  Referenced by: '<S376>/Transfer Fcn2'

  real_T VelScale_Gain;                // Expression: 1E2
                                          //  Referenced by: '<S327>/VelScale'

  real_T VeScale_Gain;                 // Expression: 1E2
                                          //  Referenced by: '<S327>/VeScale'

  real_T AngleScale_Gain;              // Expression: 1E2
                                          //  Referenced by: '<S327>/AngleScale'

  real_T Gain1_Gain_c;                 // Expression: 1E3
                                          //  Referenced by: '<S327>/Gain1'

  real_T Gain3_Gain_l;                 // Expression: 1E3
                                          //  Referenced by: '<S327>/Gain3'

  real_T VeScale1_Gain;                // Expression: 1E3
                                          //  Referenced by: '<S327>/VeScale1'

  real_T VelScale1_Gain;               // Expression: 1E3
                                          //  Referenced by: '<S327>/VelScale1'

  real_T headMotAngle_Gain;            // Expression: 1E5
                                          //  Referenced by: '<S327>/headMotAngle'

  real_T headVehAngleScale_Gain;       // Expression: 1E5
                                          //  Referenced by: '<S327>/headVehAngleScale'

  real_T magDecGain_Gain;              // Expression: 100
                                          //  Referenced by: '<S400>/magDecGain'

  real_T Gain_Gain_ja;                 // Expression: 60/2/pi
                                          //  Referenced by: '<S11>/Gain'

  real_T CopterID_Value;               // Expression: 1
                                          //  Referenced by: '<S11>/CopterID'

  real_T Constant_Value_hu;            // Expression: 1
                                          //  Referenced by: '<S24>/Constant'

  real_T UniformRandomNumber4_Minimum_o[3];// Expression: [-1,-1,-2]
                                              //  Referenced by: '<S327>/Uniform Random Number4'

  real_T UniformRandomNumber4_Maximum_c[3];// Expression: [1,1,2]
                                              //  Referenced by: '<S327>/Uniform Random Number4'

  real_T UniformRandomNumber4_Seed_e[3];// Expression: [5445,45433,33433]
                                           //  Referenced by: '<S327>/Uniform Random Number4'

  real_T BiasGain1_Gain;               // Expression: 0.1
                                          //  Referenced by: '<S327>/BiasGain1'

  int32_T Constant1_Value_ir;          // Computed Parameter: Constant1_Value_ir
                                          //  Referenced by: '<S476>/Constant1'

  int32_T Constant_Value_ao;           // Computed Parameter: Constant_Value_ao
                                          //  Referenced by: '<S477>/Constant'

  int32_T Constant_Value_dt;           // Computed Parameter: Constant_Value_dt
                                          //  Referenced by: '<S475>/Constant'

  int32_T Constant_Value_c;            // Computed Parameter: Constant_Value_c
                                          //  Referenced by: '<S486>/Constant'

  int32_T Gain_Gain_id;                // Computed Parameter: Gain_Gain_id
                                          //  Referenced by: '<S486>/Gain'

  int32_T Constant_Value_by;           // Computed Parameter: Constant_Value_by
                                          //  Referenced by: '<S489>/Constant'

  int32_T Gain_Gain_ngk;               // Computed Parameter: Gain_Gain_ngk
                                          //  Referenced by: '<S488>/Gain'

  int32_T Constant_Value_k4;           // Computed Parameter: Constant_Value_k4
                                          //  Referenced by: '<S492>/Constant'

  int32_T Constant1_Value_ob;          // Computed Parameter: Constant1_Value_ob
                                          //  Referenced by: '<S492>/Constant1'

  int32_T Constant1_Value_l;           // Computed Parameter: Constant1_Value_l
                                          //  Referenced by: '<S493>/Constant1'

  int32_T Constant_Value_pw;           // Computed Parameter: Constant_Value_pw
                                          //  Referenced by: '<S491>/Constant'

  int32_T Constant1_Value_f;           // Computed Parameter: Constant1_Value_f
                                          //  Referenced by: '<S490>/Constant1'

  int32_T Gain_Gain_bi;                // Computed Parameter: Gain_Gain_bi
                                          //  Referenced by: '<S490>/Gain'

  int32_T Constant1_Value_lt;          // Computed Parameter: Constant1_Value_lt
                                          //  Referenced by: '<S494>/Constant1'

  int32_T Constant_Value_b2;           // Computed Parameter: Constant_Value_b2
                                          //  Referenced by: '<S468>/Constant'

  int32_T Constant_Value_kp;           // Computed Parameter: Constant_Value_kp
                                          //  Referenced by: '<S485>/Constant'

  int32_T Gain_Gain_lf;                // Computed Parameter: Gain_Gain_lf
                                          //  Referenced by: '<S485>/Gain'

  int32_T Constant_Value_h3;           // Computed Parameter: Constant_Value_h3
                                          //  Referenced by: '<S495>/Constant'

  int32_T Constant1_Value_p;           // Computed Parameter: Constant1_Value_p
                                          //  Referenced by: '<S495>/Constant1'

  int32_T Constant_Value_ex;           // Computed Parameter: Constant_Value_ex
                                          //  Referenced by: '<S497>/Constant'

  int32_T tc_old_Threshold;            // Computed Parameter: tc_old_Threshold
                                          //  Referenced by: '<S496>/tc_old'

  int32_T Constant_Value_h1y;          // Computed Parameter: Constant_Value_h1y
                                          //  Referenced by: '<S467>/Constant'

  int32_T Constant1_Value_jl;          // Computed Parameter: Constant1_Value_jl
                                          //  Referenced by: '<S467>/Constant1'

  int32_T Constant_Value_m;            // Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S466>/Constant'

  int32_T Constant_Value_aoh;          // Computed Parameter: Constant_Value_aoh
                                          //  Referenced by: '<S471>/Constant'

  int32_T Gain_Gain_a1;                // Computed Parameter: Gain_Gain_a1
                                          //  Referenced by: '<S471>/Gain'

  int32_T Constant_Value_kg;           // Computed Parameter: Constant_Value_kg
                                          //  Referenced by: '<S473>/Constant'

  int32_T ForIterator_IterationLimit_n;
                             // Computed Parameter: ForIterator_IterationLimit_n
                                //  Referenced by: '<S458>/For Iterator'

  int32_T Constant_Value_o2;           // Computed Parameter: Constant_Value_o2
                                          //  Referenced by: '<S458>/Constant'

  int32_T arn_Threshold;               // Computed Parameter: arn_Threshold
                                          //  Referenced by: '<S458>/ar(n)'

  int32_T FaultID_Value;               // Computed Parameter: FaultID_Value
                                          //  Referenced by: '<S185>/FaultID'

  int32_T FaultID1_Value;              // Computed Parameter: FaultID1_Value
                                          //  Referenced by: '<S185>/FaultID1'

  int32_T FaultID2_Value;              // Computed Parameter: FaultID2_Value
                                          //  Referenced by: '<S185>/FaultID2'

  int32_T FaultID_Value_f;             // Computed Parameter: FaultID_Value_f
                                          //  Referenced by: '<S295>/FaultID'

  int32_T FaultID1_Value_f;            // Computed Parameter: FaultID1_Value_f
                                          //  Referenced by: '<S295>/FaultID1'

  int32_T FaultID_Value_i;             // Computed Parameter: FaultID_Value_i
                                          //  Referenced by: '<S55>/FaultID'

  int32_T FaultID1_Value_i;            // Computed Parameter: FaultID1_Value_i
                                          //  Referenced by: '<S55>/FaultID1'

  int32_T FaultID2_Value_n;            // Computed Parameter: FaultID2_Value_n
                                          //  Referenced by: '<S55>/FaultID2'

  int32_T FaultID3_Value;              // Computed Parameter: FaultID3_Value
                                          //  Referenced by: '<S55>/FaultID3'

  int32_T FaultID4_Value;              // Computed Parameter: FaultID4_Value
                                          //  Referenced by: '<S61>/FaultID4'

  int32_T FaultID_Value_g;             // Computed Parameter: FaultID_Value_g
                                          //  Referenced by: '<S61>/FaultID'

  int32_T FaultID1_Value_m;            // Computed Parameter: FaultID1_Value_m
                                          //  Referenced by: '<S61>/FaultID1'

  int32_T FaultID2_Value_g;            // Computed Parameter: FaultID2_Value_g
                                          //  Referenced by: '<S61>/FaultID2'

  int32_T FaultID3_Value_g;            // Computed Parameter: FaultID3_Value_g
                                          //  Referenced by: '<S61>/FaultID3'

  int32_T FaultID_Value_p;             // Computed Parameter: FaultID_Value_p
                                          //  Referenced by: '<S286>/FaultID'

  int32_T FaultID_Value_h;             // Computed Parameter: FaultID_Value_h
                                          //  Referenced by: '<S400>/FaultID'

  int32_T FaultID1_Value_d;            // Computed Parameter: FaultID1_Value_d
                                          //  Referenced by: '<S400>/FaultID1'

  int32_T FaultID2_Value_ni;           // Computed Parameter: FaultID2_Value_ni
                                          //  Referenced by: '<S400>/FaultID2'

  int32_T FaultID3_Value_h;            // Computed Parameter: FaultID3_Value_h
                                          //  Referenced by: '<S400>/FaultID3'

  int32_T FaultID_Value_k;             // Computed Parameter: FaultID_Value_k
                                          //  Referenced by: '<S327>/FaultID'

  uint32_T MediumHighAltitudeIntensity_max[2];
                          // Computed Parameter: MediumHighAltitudeIntensity_max
                             //  Referenced by: '<S136>/Medium//High Altitude Intensity'

  uint32_T MediumHighAltitudeIntensity_m_o[2];
                          // Computed Parameter: MediumHighAltitudeIntensity_m_o
                             //  Referenced by: '<S97>/Medium//High Altitude Intensity'

  P_IfWarningError_FaultModel_T IfWarningError_a;// '<S334>/If Warning//Error'
  P_NegativeTrace_FaultModel_T NegativeTrace_l;// '<S326>/Negative Trace'
  P_PositiveTrace_FaultModel_T PositiveTrace_b;// '<S326>/Positive Trace'
  P_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic8;// '<S300>/MotorNonlinearDynamic8' 
  P_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic7;// '<S300>/MotorNonlinearDynamic7' 
  P_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic6;// '<S300>/MotorNonlinearDynamic6' 
  P_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic5;// '<S300>/MotorNonlinearDynamic5' 
  P_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic4;// '<S300>/MotorNonlinearDynamic4' 
  P_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic3;// '<S300>/MotorNonlinearDynamic3' 
  P_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic2;// '<S300>/MotorNonlinearDynamic2' 
  P_MotorNonlinearDynamic1_Faul_T MotorNonlinearDynamic1;// '<S300>/MotorNonlinearDynamic1' 
  P_IfWarningError_FaultModel_T IfWarningError_f;// '<S240>/If Warning//Error'
  P_NegativeTrace_FaultModel_T NegativeTrace_d;// '<S192>/Negative Trace'
  P_PositiveTrace_FaultModel_T PositiveTrace_d;// '<S192>/Positive Trace'
  P_IfWarningError_FaultModel_T IfWarningError;// '<S202>/If Warning//Error'
  P_NegativeTrace_FaultModel_T NegativeTrace;// '<S191>/Negative Trace'
  P_PositiveTrace_FaultModel_T PositiveTrace;// '<S191>/Positive Trace'
  P_Interpolatevelocities_Fault_T Interpolatevelocities_p;// '<S125>/Interpolate  velocities' 
  P_Interpolaterates_FaultModel_T Interpolaterates_j;// '<S124>/Interpolate  rates' 
  P_Hwgwz_FaultModel_T Hwgwz_a;        // '<S120>/Hwgw(z)'
  P_Hvgwz_FaultModel_T Hvgwz_p;        // '<S120>/Hvgw(z)'
  P_Hugwz_FaultModel_T Hugwz_i;        // '<S120>/Hugw(z)'
  P_Hrgw_FaultModel_T Hrgw_g;          // '<S119>/Hrgw'
  P_Hqgw_FaultModel_T Hqgw_b;          // '<S119>/Hqgw'
  P_Hpgw_FaultModel_T Hpgw_c;          // '<S119>/Hpgw'
  P_Interpolatevelocities_Fault_T Interpolatevelocities;// '<S86>/Interpolate  velocities' 
  P_Interpolaterates_FaultModel_T Interpolaterates;// '<S85>/Interpolate  rates' 
  P_Hwgwz_FaultModel_T Hwgwz;          // '<S81>/Hwgw(z)'
  P_Hvgwz_FaultModel_T Hvgwz;          // '<S81>/Hvgw(z)'
  P_Hugwz_FaultModel_T Hugwz;          // '<S81>/Hugw(z)'
  P_Hrgw_FaultModel_T Hrgw;            // '<S80>/Hrgw'
  P_Hqgw_FaultModel_T Hqgw;            // '<S80>/Hqgw'
  P_Hpgw_FaultModel_T Hpgw;            // '<S80>/Hpgw'
};

// Parameters (default storage)
typedef struct P_FaultModel_T_ P_FaultModel_T;

// Real-time Model Data Structure
struct tag_RTM_FaultModel_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_FaultModel_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[36];
  real_T odeF[4][36];
  ODE4_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[5];
    } TaskCounters;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[5];
  } Timing;
};

extern "C" {
  static real_T rtGetInf(void);
  static real32_T rtGetInfF(void);
  static real_T rtGetMinusInf(void);
  static real32_T rtGetMinusInfF(void);
}                                      // extern "C"
  extern "C"
{
  static real_T rtGetNaN(void);
  static real32_T rtGetNaNF(void);
}                                      // extern "C"

extern "C" {
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  static void rt_InitInfAndNaN(size_t realSize);
  static boolean_T rtIsInf(real_T value);
  static boolean_T rtIsInfF(real32_T value);
  static boolean_T rtIsNaN(real_T value);
  static boolean_T rtIsNaNF(real32_T value);
  typedef struct {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  } BigEndianIEEEDouble;

  typedef struct {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  } LittleEndianIEEEDouble;

  typedef struct {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  } IEEESingle;
}                                      // extern "C"
  // Class declaration for model FaultModel
  class MulticopterModelClass
{
  // public data and function members
 public:
  // Tunable parameters
  static P_FaultModel_T FaultModel_P;

  // External inputs
  ExtU_FaultModel_T FaultModel_U;

  // External outputs
  ExtY_FaultModel_T FaultModel_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  MulticopterModelClass();

  // Destructor
  ~MulticopterModelClass();

  // Real-Time Model get method
  RT_MODEL_FaultModel_T * getRTM();

  // private data and function members
 private:
  // Block signals
  B_FaultModel_T FaultModel_B;

  // Block states
  DW_FaultModel_T FaultModel_DW;
  X_FaultModel_T FaultModel_X;         // Block continuous states

  // Real-Time Model
  RT_MODEL_FaultModel_T FaultModel_M;

  // private member function(s) for subsystem '<S80>/Hpgw'
  static void FaultModel_Hpgw_Init(B_Hpgw_FaultModel_T *localB,
    DW_Hpgw_FaultModel_T *localDW, P_Hpgw_FaultModel_T *localP);
  static void FaultModel_Hpgw_Reset(DW_Hpgw_FaultModel_T *localDW,
    P_Hpgw_FaultModel_T *localP);
  static void FaultModel_Hpgw_Disable(B_Hpgw_FaultModel_T *localB,
    DW_Hpgw_FaultModel_T *localDW, P_Hpgw_FaultModel_T *localP);
  void FaultModel_Hpgw_Update(B_Hpgw_FaultModel_T *localB, DW_Hpgw_FaultModel_T *
    localDW);
  void FaultModel_Hpgw(real_T rtu_Enable, const real_T rtu_L_wg[2], real_T
                       rtu_sigma_wg, real_T rtu_sigma_wg_d, real_T rtu_Noise,
                       real_T rtu_wingspan, B_Hpgw_FaultModel_T *localB,
                       DW_Hpgw_FaultModel_T *localDW, P_Hpgw_FaultModel_T
                       *localP);

  // private member function(s) for subsystem '<S80>/Hqgw'
  static void FaultModel_Hqgw_Init(B_Hqgw_FaultModel_T *localB,
    DW_Hqgw_FaultModel_T *localDW, P_Hqgw_FaultModel_T *localP);
  static void FaultModel_Hqgw_Reset(DW_Hqgw_FaultModel_T *localDW,
    P_Hqgw_FaultModel_T *localP);
  static void FaultModel_Hqgw_Disable(B_Hqgw_FaultModel_T *localB,
    DW_Hqgw_FaultModel_T *localDW, P_Hqgw_FaultModel_T *localP);
  void FaultModel_Hqgw_Update(const real_T rtu_wg[2], B_Hqgw_FaultModel_T
    *localB, DW_Hqgw_FaultModel_T *localDW);
  void FaultModel_Hqgw(real_T rtu_Enable, real_T rtu_V, const real_T rtu_wg[2],
                       real_T rtu_wingspan, B_Hqgw_FaultModel_T *localB,
                       DW_Hqgw_FaultModel_T *localDW, P_Hqgw_FaultModel_T
                       *localP);

  // private member function(s) for subsystem '<S80>/Hrgw'
  static void FaultModel_Hrgw_Init(B_Hrgw_FaultModel_T *localB,
    DW_Hrgw_FaultModel_T *localDW, P_Hrgw_FaultModel_T *localP);
  static void FaultModel_Hrgw_Reset(DW_Hrgw_FaultModel_T *localDW,
    P_Hrgw_FaultModel_T *localP);
  static void FaultModel_Hrgw_Disable(B_Hrgw_FaultModel_T *localB,
    DW_Hrgw_FaultModel_T *localDW, P_Hrgw_FaultModel_T *localP);
  void FaultModel_Hrgw_Update(const real_T rtu_vg[2], B_Hrgw_FaultModel_T
    *localB, DW_Hrgw_FaultModel_T *localDW);
  void FaultModel_Hrgw(real_T rtu_Enable, real_T rtu_V, const real_T rtu_vg[2],
                       real_T rtu_wingspan, B_Hrgw_FaultModel_T *localB,
                       DW_Hrgw_FaultModel_T *localDW, P_Hrgw_FaultModel_T
                       *localP);

  // private member function(s) for subsystem '<S81>/Hugw(z)'
  static void FaultModel_Hugwz_Init(B_Hugwz_FaultModel_T *localB,
    DW_Hugwz_FaultModel_T *localDW, P_Hugwz_FaultModel_T *localP);
  static void FaultModel_Hugwz_Reset(DW_Hugwz_FaultModel_T *localDW,
    P_Hugwz_FaultModel_T *localP);
  static void FaultModel_Hugwz_Disable(B_Hugwz_FaultModel_T *localB,
    DW_Hugwz_FaultModel_T *localDW, P_Hugwz_FaultModel_T *localP);
  void FaultModel_Hugwz_Update(B_Hugwz_FaultModel_T *localB,
    DW_Hugwz_FaultModel_T *localDW);
  void FaultModel_Hugwz(real_T rtu_Enable, real_T rtu_V, real_T rtu_L_ug, real_T
                        rtu_L_ug_f, real_T rtu_sigma_ug, real_T rtu_sigma_ug_b,
                        real_T rtu_Noise, B_Hugwz_FaultModel_T *localB,
                        DW_Hugwz_FaultModel_T *localDW, P_Hugwz_FaultModel_T
                        *localP);

  // private member function(s) for subsystem '<S81>/Hvgw(z)'
  static void FaultModel_Hvgwz_Init(B_Hvgwz_FaultModel_T *localB,
    DW_Hvgwz_FaultModel_T *localDW, P_Hvgwz_FaultModel_T *localP);
  static void FaultModel_Hvgwz_Reset(DW_Hvgwz_FaultModel_T *localDW,
    P_Hvgwz_FaultModel_T *localP);
  static void FaultModel_Hvgwz_Disable(B_Hvgwz_FaultModel_T *localB,
    DW_Hvgwz_FaultModel_T *localDW, P_Hvgwz_FaultModel_T *localP);
  void FaultModel_Hvgwz_Update(B_Hvgwz_FaultModel_T *localB,
    DW_Hvgwz_FaultModel_T *localDW);
  void FaultModel_Hvgwz(real_T rtu_Enable, real_T rtu_sigma_vg, real_T
                        rtu_sigma_vg_p, const real_T rtu_L_vg[2], real_T rtu_V,
                        real_T rtu_Noise, B_Hvgwz_FaultModel_T *localB,
                        DW_Hvgwz_FaultModel_T *localDW, P_Hvgwz_FaultModel_T
                        *localP);

  // private member function(s) for subsystem '<S81>/Hwgw(z)'
  static void FaultModel_Hwgwz_Init(B_Hwgwz_FaultModel_T *localB,
    DW_Hwgwz_FaultModel_T *localDW, P_Hwgwz_FaultModel_T *localP);
  static void FaultModel_Hwgwz_Reset(DW_Hwgwz_FaultModel_T *localDW,
    P_Hwgwz_FaultModel_T *localP);
  static void FaultModel_Hwgwz_Disable(B_Hwgwz_FaultModel_T *localB,
    DW_Hwgwz_FaultModel_T *localDW, P_Hwgwz_FaultModel_T *localP);
  void FaultModel_Hwgwz_Update(B_Hwgwz_FaultModel_T *localB,
    DW_Hwgwz_FaultModel_T *localDW);
  void FaultModel_Hwgwz(real_T rtu_Enable, real_T rtu_V, const real_T rtu_L_wg[2],
                        real_T rtu_sigma_wg, real_T rtu_sigma_wg_h, real_T
                        rtu_Noise, B_Hwgwz_FaultModel_T *localB,
                        DW_Hwgwz_FaultModel_T *localDW, P_Hwgwz_FaultModel_T
                        *localP);

  // private member function(s) for subsystem '<S85>/Low altitude  rates'
  static void FaultModel_Lowaltituderates(const real_T rtu_DCM[9], const real_T
    rtu_pgw_hl[2], const real_T rtu_qgw_hl[2], const real_T rtu_rgw_hl[2],
    real_T rtu_Winddirection, real_T rty_pgwqgwrgw[3]);

  // private member function(s) for subsystem '<S85>/Interpolate  rates'
  void FaultModel_Interpolaterates(const real_T rtu_pgw_hl[2], const real_T
    rtu_qgw_hl[2], const real_T rtu_rgw_hl[2], const real_T rtu_DCM[9], real_T
    rtu_Winddirection, real_T rtu_Altitude, real_T rty_pgwqgwrgw[3],
    B_Interpolaterates_FaultModel_T *localB, P_Interpolaterates_FaultModel_T
    *localP);

  // private member function(s) for subsystem '<S86>/Low altitude  velocities'
  static void FaultMode_Lowaltitudevelocities(const real_T rtu_DCM[9], const
    real_T rtu_ugw_hl[2], const real_T rtu_vgw_hl[2], const real_T rtu_wgw_hl[2],
    real_T rtu_Winddirection, real_T rty_ugwvgwwgw[3]);

  // private member function(s) for subsystem '<S86>/Interpolate  velocities'
  void FaultMode_Interpolatevelocities(const real_T rtu_ugw_hl[2], const real_T
    rtu_vgw_hl[2], const real_T rtu_wgw_hl[2], const real_T rtu_DCM[9], real_T
    rtu_Winddirection, real_T rtu_Altitude, real_T rty_ugwvgwwgw[3],
    B_Interpolatevelocities_Fault_T *localB, P_Interpolatevelocities_Fault_T
    *localP);

  // private member function(s) for subsystem '<S191>/Positive Trace'
  static void FaultModel_PositiveTrace(real_T rtu_traceDCM, const real_T
    rtu_DCM[9], real_T *rty_qwqxqyqz, real_T rty_qwqxqyqz_a[3],
    P_PositiveTrace_FaultModel_T *localP);

  // private member function(s) for subsystem '<S191>/Negative Trace'
  static void FaultModel_NegativeTrace_Init(DW_NegativeTrace_FaultModel_T
    *localDW);
  void FaultModel_NegativeTrace(const real_T rtu_DCM[9], real_T rty_qwqxqyqz[4],
    DW_NegativeTrace_FaultModel_T *localDW, P_NegativeTrace_FaultModel_T *localP);

  // private member function(s) for subsystem '<S202>/If Warning//Error'
  static void FaultModel_IfWarningError(const real_T rtu_dcm[9],
    P_IfWarningError_FaultModel_T *localP, real_T rtp_action, real_T
    rtp_tolerance);

  // private member function(s) for subsystem '<S302>/Motor_Dynamics'
  void FaultModel_Motor_Dynamics_Init(DW_Motor_Dynamics_FaultModel_T *localDW,
    X_Motor_Dynamics_FaultModel_T *localX);
  static void FaultModel_Motor_Dynamics_Deriv(B_Motor_Dynamics_FaultModel_T
    *localB, XDot_Motor_Dynamics_FaultMode_T *localXdot);
  static void FaultMode_Motor_Dynamics_Update(DW_Motor_Dynamics_FaultModel_T
    *localDW);
  static void FaultModel_Motor_Dynamics(real_T rtu_motor_rate_d, real_T
    rtu_ModelInit_RPM, real_T rtu_motorT, B_Motor_Dynamics_FaultModel_T *localB,
    DW_Motor_Dynamics_FaultModel_T *localDW, X_Motor_Dynamics_FaultModel_T
    *localX);

  // private member function(s) for subsystem '<S300>/MotorNonlinearDynamic1'
  void Fau_MotorNonlinearDynamic1_Init(DW_MotorNonlinearDynamic1_Fau_T *localDW,
    X_MotorNonlinearDynamic1_Faul_T *localX);
  static void Fa_MotorNonlinearDynamic1_Deriv(B_MotorNonlinearDynamic1_Faul_T
    *localB, XDot_MotorNonlinearDynamic1_F_T *localXdot);
  static void F_MotorNonlinearDynamic1_Update(DW_MotorNonlinearDynamic1_Fau_T
    *localDW);
  void FaultMod_MotorNonlinearDynamic1(real_T rtu_Wb, real_T rtu_Cr, real_T
    rtu_motorT, real_T rtu_ModelInit_RPM, real_T rtu_PWM,
    B_MotorNonlinearDynamic1_Faul_T *localB, DW_MotorNonlinearDynamic1_Fau_T
    *localDW, P_MotorNonlinearDynamic1_Faul_T *localP, P_FaultModel_T
    *FaultModel_P, X_MotorNonlinearDynamic1_Faul_T *localX);

  // private member function(s) for subsystem '<S401>/Acc Fun'
  static void FaultModel_AccFun(const real_T rtu_u[3], boolean_T rtu_isAccFault,
    const real_T rtu_AccFaultParams[20], B_AccFun_FaultModel_T *localB);

  // private member function(s) for subsystem '<Root>'
  real_T FaultModel_eml_rand_mt19937ar(uint32_T state[625]);
  real_T FaultModel_eml_rand_mcg16807(uint32_T *state);
  real_T FaultModel_rand(void);
  void FaultModel_rand_k(real_T r[3]);
  real_T FaultModel_rand_n(void);
  real_T FaultModel_rand_j(void);
  real_T FaultModel_norm(const real_T x[3]);

  // Continuous states update member function
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  // Derivatives member function
  void FaultModel_derivatives();
}

;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S70>/P0' : Unused code path elimination
//  Block '<S70>/Product2' : Unused code path elimination
//  Block '<S70>/a' : Unused code path elimination
//  Block '<S70>/gamma*R' : Unused code path elimination
//  Block '<S412>/Product' : Unused code path elimination
//  Block '<S412>/Product3' : Unused code path elimination
//  Block '<S412>/a' : Unused code path elimination
//  Block '<S412>/gamma*R' : Unused code path elimination
//  Block '<S412>/rho0' : Unused code path elimination
//  Block '<S448>/Unit Conversion' : Unused code path elimination
//  Block '<S449>/Unit Conversion' : Unused code path elimination
//  Block '<S34>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S47>/Reshape1' : Reshape block reduction
//  Block '<S47>/Reshape2' : Reshape block reduction
//  Block '<S48>/Reshape1' : Reshape block reduction
//  Block '<S48>/Reshape2' : Reshape block reduction
//  Block '<S14>/Reshape' : Reshape block reduction
//  Block '<S14>/Reshape1' : Reshape block reduction
//  Block '<S15>/Reshape' : Reshape block reduction
//  Block '<S17>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S18>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S19>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S20>/Reshape1' : Reshape block reduction
//  Block '<S20>/Reshape2' : Reshape block reduction
//  Block '<Root>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S103>/Reshape' : Reshape block reduction
//  Block '<S103>/Reshape1' : Reshape block reduction
//  Block '<S105>/Reshape' : Reshape block reduction
//  Block '<S111>/Reshape' : Reshape block reduction
//  Block '<S111>/Reshape1' : Reshape block reduction
//  Block '<S113>/Reshape' : Reshape block reduction
//  Block '<S142>/Reshape' : Reshape block reduction
//  Block '<S142>/Reshape1' : Reshape block reduction
//  Block '<S144>/Reshape' : Reshape block reduction
//  Block '<S150>/Reshape' : Reshape block reduction
//  Block '<S150>/Reshape1' : Reshape block reduction
//  Block '<S152>/Reshape' : Reshape block reduction
//  Block '<S61>/Reshape' : Reshape block reduction
//  Block '<S179>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S181>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S77>/Reshape' : Reshape block reduction
//  Block '<S77>/Reshape1' : Reshape block reduction
//  Block '<S191>/Reshape 3x3 -> 9' : Reshape block reduction
//  Block '<S229>/Reshape' : Reshape block reduction
//  Block '<S192>/Reshape 3x3 -> 9' : Reshape block reduction
//  Block '<S267>/Reshape' : Reshape block reduction
//  Block '<S285>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S11>/Data Type Conversion11' : Eliminate redundant data type conversion
//  Block '<S11>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S326>/Reshape 3x3 -> 9' : Reshape block reduction
//  Block '<S361>/Reshape' : Reshape block reduction
//  Block '<S423>/Reshape1' : Reshape block reduction
//  Block '<S445>/maxtype' : Eliminate redundant data type conversion
//  Block '<S445>/mintype' : Eliminate redundant data type conversion
//  Block '<S447>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S416>/Unit Conversion2' : Eliminated nontunable gain of 1
//  Block '<S475>/Reshape' : Reshape block reduction
//  Block '<S482>/Reshape' : Reshape block reduction
//  Block '<S483>/Reshape' : Reshape block reduction
//  Block '<S484>/Reshape' : Reshape block reduction
//  Block '<S484>/Reshape1' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'FaultModel'
//  '<S1>'   : 'FaultModel/6DOF'
//  '<S2>'   : 'FaultModel/Battery FaultModel'
//  '<S3>'   : 'FaultModel/CollisionDetection'
//  '<S4>'   : 'FaultModel/Crash_Motor_Fault'
//  '<S5>'   : 'FaultModel/Environment FaultModel1'
//  '<S6>'   : 'FaultModel/Fail Model'
//  '<S7>'   : 'FaultModel/Force and Moment Model'
//  '<S8>'   : 'FaultModel/MATLAB Function'
//  '<S9>'   : 'FaultModel/Model Info'
//  '<S10>'  : 'FaultModel/Motor FaultModel'
//  '<S11>'  : 'FaultModel/OutputPort1'
//  '<S12>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)'
//  '<S13>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles'
//  '<S14>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate omega_dot'
//  '<S15>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Determine Force,  Mass & Inertia'
//  '<S16>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Vbxw'
//  '<S17>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Velocity Conversion'
//  '<S18>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Velocity Conversion1'
//  '<S19>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Velocity Conversion2'
//  '<S20>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/transform to Inertial axes '
//  '<S21>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix'
//  '<S22>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles'
//  '<S23>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Rotation Angles to Quaternions'
//  '<S24>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/qdot'
//  '<S25>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A11'
//  '<S26>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A12'
//  '<S27>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A13'
//  '<S28>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A21'
//  '<S29>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A22'
//  '<S30>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A23'
//  '<S31>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A31'
//  '<S32>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A32'
//  '<S33>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A33'
//  '<S34>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S35>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize'
//  '<S36>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus'
//  '<S37>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S38>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation'
//  '<S39>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S40>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S41>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S42>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S43>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S44>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S45>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S46>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate omega_dot/3x3 Cross Product'
//  '<S47>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate omega_dot/I x w'
//  '<S48>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate omega_dot/I x w1'
//  '<S49>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate omega_dot/3x3 Cross Product/Subsystem'
//  '<S50>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Calculate omega_dot/3x3 Cross Product/Subsystem1'
//  '<S51>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Determine Force,  Mass & Inertia/Mass input//output  momentum'
//  '<S52>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Determine Force,  Mass & Inertia/Mass input//output  momentum/For Each Subsystem'
//  '<S53>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Vbxw/Subsystem'
//  '<S54>'  : 'FaultModel/6DOF/Custom Variable Mass 6DOF (Quaternion)/Vbxw/Subsystem1'
//  '<S55>'  : 'FaultModel/Battery FaultModel/FaultModelTmp'
//  '<S56>'  : 'FaultModel/Battery FaultModel/FaultModelTmp/FaultParamsExtract'
//  '<S57>'  : 'FaultModel/Battery FaultModel/FaultModelTmp/FaultParamsExtract1'
//  '<S58>'  : 'FaultModel/Battery FaultModel/FaultModelTmp/FaultParamsExtract2'
//  '<S59>'  : 'FaultModel/Battery FaultModel/FaultModelTmp/FaultParamsExtract3'
//  '<S60>'  : 'FaultModel/Battery FaultModel/FaultModelTmp/MATLAB Function'
//  '<S61>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel'
//  '<S62>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))'
//  '<S63>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1'
//  '<S64>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/FaultParamsExtract'
//  '<S65>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/FaultParamsExtract1'
//  '<S66>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/FaultParamsExtract2'
//  '<S67>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/FaultParamsExtract3'
//  '<S68>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/FaultParamsExtract4'
//  '<S69>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA'
//  '<S70>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/ISA Atmosphere Model'
//  '<S71>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/MATLAB Function'
//  '<S72>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/MATLAB Function1'
//  '<S73>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/SheerWindStrength_Dec_Switch'
//  '<S74>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Temperature Conversion'
//  '<S75>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/TurbWindStrength_Dec_Switch'
//  '<S76>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/WGS84 Gravity Model '
//  '<S77>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Wind Shear Model'
//  '<S78>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/noiseUpperWindBodySwitch'
//  '<S79>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Angle Conversion'
//  '<S80>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Filters on angular rates'
//  '<S81>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Filters on velocities'
//  '<S82>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Length Conversion'
//  '<S83>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Length Conversion1'
//  '<S84>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/RMS turbulence  intensities'
//  '<S85>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select angular rates'
//  '<S86>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select velocities'
//  '<S87>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Turbulence scale lengths'
//  '<S88>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Velocity Conversion'
//  '<S89>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Velocity Conversion2'
//  '<S90>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/White Noise'
//  '<S91>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Filters on angular rates/Hpgw'
//  '<S92>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Filters on angular rates/Hqgw'
//  '<S93>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Filters on angular rates/Hrgw'
//  '<S94>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Filters on velocities/Hugw(z)'
//  '<S95>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Filters on velocities/Hvgw(z)'
//  '<S96>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Filters on velocities/Hwgw(z)'
//  '<S97>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/RMS turbulence  intensities/High Altitude Intensity'
//  '<S98>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/RMS turbulence  intensities/Low Altitude Intensity'
//  '<S99>'  : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select angular rates/Interpolate  rates'
//  '<S100>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select angular rates/Low altitude  rates'
//  '<S101>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select angular rates/Medium//High  altitude rates'
//  '<S102>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select angular rates/Merge Subsystems'
//  '<S103>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select angular rates/Interpolate  rates/wind to body transformation'
//  '<S104>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select angular rates/Interpolate  rates/wind to body transformation/convert to earth coords'
//  '<S105>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select angular rates/Low altitude  rates/wind to body transformation'
//  '<S106>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select angular rates/Low altitude  rates/wind to body transformation/convert to earth coords'
//  '<S107>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select velocities/Interpolate  velocities'
//  '<S108>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select velocities/Low altitude  velocities'
//  '<S109>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select velocities/Medium//High  altitude velocities'
//  '<S110>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select velocities/Merge Subsystems'
//  '<S111>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select velocities/Interpolate  velocities/wind to body transformation'
//  '<S112>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select velocities/Interpolate  velocities/wind to body transformation/convert to earth coords'
//  '<S113>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select velocities/Low altitude  velocities/wind to body transformation'
//  '<S114>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Select velocities/Low altitude  velocities/wind to body transformation/convert to earth coords'
//  '<S115>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Turbulence scale lengths/Low altitude scale length'
//  '<S116>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Turbulence scale lengths/Medium//High altitude scale length'
//  '<S117>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))/Turbulence scale lengths/Medium//High altitude scale length/Length Conversion'
//  '<S118>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Angle Conversion'
//  '<S119>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Filters on angular rates'
//  '<S120>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Filters on velocities'
//  '<S121>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Length Conversion'
//  '<S122>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Length Conversion1'
//  '<S123>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/RMS turbulence  intensities'
//  '<S124>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select angular rates'
//  '<S125>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select velocities'
//  '<S126>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Turbulence scale lengths'
//  '<S127>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Velocity Conversion'
//  '<S128>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Velocity Conversion2'
//  '<S129>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/White Noise'
//  '<S130>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Filters on angular rates/Hpgw'
//  '<S131>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Filters on angular rates/Hqgw'
//  '<S132>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Filters on angular rates/Hrgw'
//  '<S133>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Filters on velocities/Hugw(z)'
//  '<S134>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Filters on velocities/Hvgw(z)'
//  '<S135>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Filters on velocities/Hwgw(z)'
//  '<S136>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/RMS turbulence  intensities/High Altitude Intensity'
//  '<S137>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/RMS turbulence  intensities/Low Altitude Intensity'
//  '<S138>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select angular rates/Interpolate  rates'
//  '<S139>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select angular rates/Low altitude  rates'
//  '<S140>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select angular rates/Medium//High  altitude rates'
//  '<S141>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select angular rates/Merge Subsystems'
//  '<S142>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select angular rates/Interpolate  rates/wind to body transformation'
//  '<S143>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select angular rates/Interpolate  rates/wind to body transformation/convert to earth coords'
//  '<S144>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select angular rates/Low altitude  rates/wind to body transformation'
//  '<S145>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select angular rates/Low altitude  rates/wind to body transformation/convert to earth coords'
//  '<S146>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select velocities/Interpolate  velocities'
//  '<S147>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select velocities/Low altitude  velocities'
//  '<S148>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select velocities/Medium//High  altitude velocities'
//  '<S149>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select velocities/Merge Subsystems'
//  '<S150>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select velocities/Interpolate  velocities/wind to body transformation'
//  '<S151>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select velocities/Interpolate  velocities/wind to body transformation/convert to earth coords'
//  '<S152>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select velocities/Low altitude  velocities/wind to body transformation'
//  '<S153>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Select velocities/Low altitude  velocities/wind to body transformation/convert to earth coords'
//  '<S154>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Turbulence scale lengths/Low altitude scale length'
//  '<S155>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Turbulence scale lengths/Medium//High altitude scale length'
//  '<S156>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Dryden Wind Turbulence Model  (Discrete (-q +r))1/Turbulence scale lengths/Medium//High altitude scale length/Length Conversion'
//  '<S157>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap'
//  '<S158>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap1'
//  '<S159>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LongLat_offset'
//  '<S160>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/pos_deg'
//  '<S161>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S162>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S163>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S164>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S165>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S166>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S167>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S168>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S169>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S170>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S171>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S172>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S173>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
//  '<S174>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S175>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
//  '<S176>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
//  '<S177>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
//  '<S178>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
//  '<S179>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/WGS84 Gravity Model /Acceleration Conversion'
//  '<S180>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/WGS84 Gravity Model /Angle Conversion'
//  '<S181>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/WGS84 Gravity Model /Length Conversion'
//  '<S182>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/WGS84 Gravity Model /Velocity Conversion2'
//  '<S183>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Wind Shear Model/Angle Conversion'
//  '<S184>' : 'FaultModel/Environment FaultModel1/Env FaultWindModel/Wind Shear Model/Length Conversion'
//  '<S185>' : 'FaultModel/Fail Model/Prop FaultModel'
//  '<S186>' : 'FaultModel/Fail Model/Prop FaultModel/FaultParamsExtract1'
//  '<S187>' : 'FaultModel/Fail Model/Prop FaultModel/FaultParamsExtract2'
//  '<S188>' : 'FaultModel/Fail Model/Prop FaultModel/FaultParamsExtract3'
//  '<S189>' : 'FaultModel/Fail Model/Prop FaultModel/Model Failure'
//  '<S190>' : 'FaultModel/Force and Moment Model/Body AeroCenter'
//  '<S191>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions'
//  '<S192>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1'
//  '<S193>' : 'FaultModel/Force and Moment Model/Euler to DCM'
//  '<S194>' : 'FaultModel/Force and Moment Model/Ground Model'
//  '<S195>' : 'FaultModel/Force and Moment Model/OnGroundFaceup'
//  '<S196>' : 'FaultModel/Force and Moment Model/Prop FaultModel'
//  '<S197>' : 'FaultModel/Force and Moment Model/Propeller Model old Version'
//  '<S198>' : 'FaultModel/Force and Moment Model/Quaternion Inverse'
//  '<S199>' : 'FaultModel/Force and Moment Model/Quaternion Multiplication'
//  '<S200>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace'
//  '<S201>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Positive Trace'
//  '<S202>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Validate DCM'
//  '<S203>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/trace(DCM)'
//  '<S204>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)'
//  '<S205>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)'
//  '<S206>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)'
//  '<S207>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/diag(DCM)'
//  '<S208>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
//  '<S209>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S210>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S211>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
//  '<S212>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
//  '<S213>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
//  '<S214>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S215>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S216>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
//  '<S217>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
//  '<S218>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
//  '<S219>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S220>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S221>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
//  '<S222>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
//  '<S223>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
//  '<S224>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S225>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S226>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error'
//  '<S227>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal'
//  '<S228>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper'
//  '<S229>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal'
//  '<S230>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper'
//  '<S231>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
//  '<S232>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
//  '<S233>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Error'
//  '<S234>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Warning'
//  '<S235>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
//  '<S236>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
//  '<S237>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
//  '<S238>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace'
//  '<S239>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Positive Trace'
//  '<S240>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Validate DCM'
//  '<S241>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/trace(DCM)'
//  '<S242>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(1,1)'
//  '<S243>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(2,2)'
//  '<S244>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(3,3)'
//  '<S245>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/diag(DCM)'
//  '<S246>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
//  '<S247>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S248>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S249>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
//  '<S250>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
//  '<S251>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
//  '<S252>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S253>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S254>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
//  '<S255>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
//  '<S256>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
//  '<S257>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S258>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S259>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
//  '<S260>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
//  '<S261>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
//  '<S262>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S263>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S264>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Validate DCM/If Warning//Error'
//  '<S265>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Validate DCM/If Warning//Error/Else If Not Orthogonal'
//  '<S266>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Validate DCM/If Warning//Error/If Not Proper'
//  '<S267>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Validate DCM/If Warning//Error/isNotOrthogonal'
//  '<S268>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Validate DCM/If Warning//Error/isNotProper'
//  '<S269>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
//  '<S270>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
//  '<S271>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Validate DCM/If Warning//Error/If Not Proper/Error'
//  '<S272>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Validate DCM/If Warning//Error/If Not Proper/Warning'
//  '<S273>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
//  '<S274>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
//  '<S275>' : 'FaultModel/Force and Moment Model/Direction Cosine Matrix  to Quaternions1/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
//  '<S276>' : 'FaultModel/Force and Moment Model/Euler to DCM/A11'
//  '<S277>' : 'FaultModel/Force and Moment Model/Euler to DCM/A12'
//  '<S278>' : 'FaultModel/Force and Moment Model/Euler to DCM/A13'
//  '<S279>' : 'FaultModel/Force and Moment Model/Euler to DCM/A21'
//  '<S280>' : 'FaultModel/Force and Moment Model/Euler to DCM/A22'
//  '<S281>' : 'FaultModel/Force and Moment Model/Euler to DCM/A23'
//  '<S282>' : 'FaultModel/Force and Moment Model/Euler to DCM/A31'
//  '<S283>' : 'FaultModel/Force and Moment Model/Euler to DCM/A32'
//  '<S284>' : 'FaultModel/Force and Moment Model/Euler to DCM/A33'
//  '<S285>' : 'FaultModel/Force and Moment Model/Euler to DCM/Create Transformation Matrix'
//  '<S286>' : 'FaultModel/Force and Moment Model/Prop FaultModel/Prop FaultModel'
//  '<S287>' : 'FaultModel/Force and Moment Model/Prop FaultModel/Prop FaultModel/FaultParamsExtract'
//  '<S288>' : 'FaultModel/Force and Moment Model/Prop FaultModel/Prop FaultModel/PropFaultModel'
//  '<S289>' : 'FaultModel/Force and Moment Model/Quaternion Inverse/Quaternion Conjugate'
//  '<S290>' : 'FaultModel/Force and Moment Model/Quaternion Inverse/Quaternion Norm'
//  '<S291>' : 'FaultModel/Force and Moment Model/Quaternion Multiplication/q0'
//  '<S292>' : 'FaultModel/Force and Moment Model/Quaternion Multiplication/q1'
//  '<S293>' : 'FaultModel/Force and Moment Model/Quaternion Multiplication/q2'
//  '<S294>' : 'FaultModel/Force and Moment Model/Quaternion Multiplication/q3'
//  '<S295>' : 'FaultModel/Motor FaultModel/FaultModelTmp'
//  '<S296>' : 'FaultModel/Motor FaultModel/FaultModelTmp/FaultParamsExtract'
//  '<S297>' : 'FaultModel/Motor FaultModel/FaultModelTmp/FaultParamsExtract1'
//  '<S298>' : 'FaultModel/Motor FaultModel/FaultModelTmp/MATLAB Function'
//  '<S299>' : 'FaultModel/Motor FaultModel/FaultModelTmp/MotorFaultModel'
//  '<S300>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun'
//  '<S301>' : 'FaultModel/Motor FaultModel/FaultModelTmp/motor_fauilure_protection'
//  '<S302>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic1'
//  '<S303>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic2'
//  '<S304>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic3'
//  '<S305>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic4'
//  '<S306>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic5'
//  '<S307>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic6'
//  '<S308>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic7'
//  '<S309>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic8'
//  '<S310>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic1/Minimum Throttle  Cutoff'
//  '<S311>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic1/Motor_Dynamics'
//  '<S312>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic2/Minimum Throttle  Cutoff'
//  '<S313>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic2/Motor_Dynamics'
//  '<S314>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic3/Minimum Throttle  Cutoff'
//  '<S315>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic3/Motor_Dynamics'
//  '<S316>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic4/Minimum Throttle  Cutoff'
//  '<S317>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic4/Motor_Dynamics'
//  '<S318>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic5/Minimum Throttle  Cutoff'
//  '<S319>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic5/Motor_Dynamics'
//  '<S320>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic6/Minimum Throttle  Cutoff'
//  '<S321>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic6/Motor_Dynamics'
//  '<S322>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic7/Minimum Throttle  Cutoff'
//  '<S323>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic7/Motor_Dynamics'
//  '<S324>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic8/Minimum Throttle  Cutoff'
//  '<S325>' : 'FaultModel/Motor FaultModel/FaultModelTmp/Motor_Fun/MotorNonlinearDynamic8/Motor_Dynamics'
//  '<S326>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions'
//  '<S327>' : 'FaultModel/OutputPort1/HILGPSModel'
//  '<S328>' : 'FaultModel/OutputPort1/HILSensorMavModel1'
//  '<S329>' : 'FaultModel/OutputPort1/HILStateMavModel'
//  '<S330>' : 'FaultModel/OutputPort1/Model Fail Assessment'
//  '<S331>' : 'FaultModel/OutputPort1/ZLimit'
//  '<S332>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace'
//  '<S333>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Positive Trace'
//  '<S334>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Validate DCM'
//  '<S335>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/trace(DCM)'
//  '<S336>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)'
//  '<S337>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)'
//  '<S338>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)'
//  '<S339>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/diag(DCM)'
//  '<S340>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
//  '<S341>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S342>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S343>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
//  '<S344>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
//  '<S345>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
//  '<S346>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S347>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S348>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
//  '<S349>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
//  '<S350>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
//  '<S351>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S352>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S353>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
//  '<S354>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
//  '<S355>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
//  '<S356>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S357>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S358>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error'
//  '<S359>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal'
//  '<S360>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper'
//  '<S361>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal'
//  '<S362>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper'
//  '<S363>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
//  '<S364>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
//  '<S365>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Error'
//  '<S366>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Warning'
//  '<S367>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
//  '<S368>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
//  '<S369>' : 'FaultModel/OutputPort1/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
//  '<S370>' : 'FaultModel/OutputPort1/HILGPSModel/-pi-pi---->0-2pi'
//  '<S371>' : 'FaultModel/OutputPort1/HILGPSModel/AccNoiseSwitch1'
//  '<S372>' : 'FaultModel/OutputPort1/HILGPSModel/FaultParamsExtract'
//  '<S373>' : 'FaultModel/OutputPort1/HILGPSModel/FaultParamsExtract1'
//  '<S374>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA'
//  '<S375>' : 'FaultModel/OutputPort1/HILGPSModel/GenCogVel'
//  '<S376>' : 'FaultModel/OutputPort1/HILGPSModel/NoiseFilter1'
//  '<S377>' : 'FaultModel/OutputPort1/HILGPSModel/AccNoiseSwitch1/Acc NoiseFun'
//  '<S378>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap'
//  '<S379>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap1'
//  '<S380>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LongLat_offset'
//  '<S381>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/pos_deg'
//  '<S382>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S383>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S384>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S385>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S386>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S387>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S388>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S389>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S390>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S391>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S392>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S393>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S394>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
//  '<S395>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S396>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
//  '<S397>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
//  '<S398>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
//  '<S399>' : 'FaultModel/OutputPort1/HILGPSModel/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
//  '<S400>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem'
//  '<S401>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/AccNoiseSwitch'
//  '<S402>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/AccelNoiseGainFunction'
//  '<S403>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Dynamic Pressure'
//  '<S404>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/FaultParamsExtract'
//  '<S405>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/FaultParamsExtract1'
//  '<S406>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/FaultParamsExtract2'
//  '<S407>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/FaultParamsExtract3'
//  '<S408>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/GyroNoiseGainFunction'
//  '<S409>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/GyroNoiseSwitch'
//  '<S410>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/GyroNoiseSwitch3'
//  '<S411>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/GyroNoiseSwitch4'
//  '<S412>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/ISA Atmosphere Model'
//  '<S413>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/MagNoiseGainFunction'
//  '<S414>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/MagNoiseSwitch'
//  '<S415>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3'
//  '<S416>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015'
//  '<S417>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/baro NoiseFun'
//  '<S418>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/AccNoiseSwitch/Acc Fun'
//  '<S419>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Dynamic Pressure/dot'
//  '<S420>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/GyroNoiseSwitch/Gyro Fun'
//  '<S421>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/MagNoiseSwitch/Mag Fun'
//  '<S422>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Acceleration Conversion'
//  '<S423>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer'
//  '<S424>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Gyroscope'
//  '<S425>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer/Dynamics'
//  '<S426>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer/w x (w x d)'
//  '<S427>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer/wdot x d'
//  '<S428>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer/Dynamics/No Dynamics'
//  '<S429>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer/Dynamics/Second-order Dynamics'
//  '<S430>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer/w x (w x d)/w x (w x d)'
//  '<S431>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer/w x (w x d)/w x d'
//  '<S432>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer/w x (w x d)/w x (w x d)/Subsystem'
//  '<S433>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer/w x (w x d)/w x (w x d)/Subsystem1'
//  '<S434>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer/w x (w x d)/w x d/Subsystem'
//  '<S435>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer/w x (w x d)/w x d/Subsystem1'
//  '<S436>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer/wdot x d/Subsystem'
//  '<S437>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Accelerometer/wdot x d/Subsystem1'
//  '<S438>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Gyroscope/Dynamics'
//  '<S439>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Gyroscope/Dynamics/No Dynamics'
//  '<S440>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/Three-axis Inertial Measurement Unit3/Three-axis Gyroscope/Dynamics/Second-order Dynamics'
//  '<S441>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/Check Altitude'
//  '<S442>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/Check Latitude'
//  '<S443>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/Check Longitude'
//  '<S444>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/Compute x,y,z, and h components of magnetic field'
//  '<S445>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/Is time within model limits'
//  '<S446>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/LatLong wrap'
//  '<S447>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/Length Conversion'
//  '<S448>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/MagField Conversion'
//  '<S449>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/MagField Conversion1'
//  '<S450>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag'
//  '<S451>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/Compute x,y,z, and h components of magnetic field/Angle Conversion'
//  '<S452>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/LatLong wrap/Latitude Wrap 90'
//  '<S453>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/LatLong wrap/Wrap Longitude'
//  '<S454>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S455>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S456>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S457>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S458>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates'
//  '<S459>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates'
//  '<S460>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates '
//  '<S461>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Get Cosine and Sine  of Latitude and Longitude'
//  '<S462>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Has altitude or latitude changed'
//  '<S463>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Has longitude changed '
//  '<S464>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Has time changed'
//  '<S465>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity'
//  '<S466>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem'
//  '<S467>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion'
//  '<S468>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations'
//  '<S469>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients'
//  '<S470>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole'
//  '<S471>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate  index'
//  '<S472>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values'
//  '<S473>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/special case'
//  '<S474>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem1'
//  '<S475>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2'
//  '<S476>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2/calculate  indices'
//  '<S477>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2/calculate  row and column'
//  '<S478>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem'
//  '<S479>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1'
//  '<S480>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1/m,n'
//  '<S481>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1/n,m-1'
//  '<S482>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem'
//  '<S483>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1'
//  '<S484>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2'
//  '<S485>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/calculate  index'
//  '<S486>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem/calculate  index'
//  '<S487>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem/calculate  row and column'
//  '<S488>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1/calculate  index'
//  '<S489>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1/calculate  row and column'
//  '<S490>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  indices'
//  '<S491>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  row and column1'
//  '<S492>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  row and column2'
//  '<S493>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/m<n-2'
//  '<S494>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/m<n-2 '
//  '<S495>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/If Action Subsystem'
//  '<S496>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)'
//  '<S497>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)/If Action Subsystem1'
//  '<S498>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)/If Action Subsystem2'
//  '<S499>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate ca'
//  '<S500>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate ct'
//  '<S501>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate d'
//  '<S502>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate q'
//  '<S503>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate q2'
//  '<S504>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate r2'
//  '<S505>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate sa'
//  '<S506>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate st'
//  '<S507>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates /For Iterator Subsystem'
//  '<S508>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Get Cosine and Sine  of Latitude and Longitude/Angle Conversion2'
//  '<S509>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate bx'
//  '<S510>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate by'
//  '<S511>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate bz'
//  '<S512>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity'
//  '<S513>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity/Angle Conversion'
//  '<S514>' : 'FaultModel/OutputPort1/HILSensorMavModel1/Subsystem/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity/Angle Conversion1'
//  '<S515>' : 'FaultModel/OutputPort1/HILStateMavModel/Dynamic Pressure'
//  '<S516>' : 'FaultModel/OutputPort1/HILStateMavModel/dot1'
//  '<S517>' : 'FaultModel/OutputPort1/HILStateMavModel/Dynamic Pressure/dot'

#endif                                 // RTW_HEADER_FaultModel_h_

//
// File trailer for generated code.
//
// [EOF]
//
