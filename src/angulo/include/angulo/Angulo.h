//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Angulo.h
//
// Code generated for Simulink model 'Angulo'.
//
// Model version                  : 1.27
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Jun  9 17:14:34 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Angulo_h_
#define RTW_HEADER_Angulo_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Angulo_pubsub_common.h"
#include "Angulo_types.h"

extern "C" {

#include "rtGetInf.h"

}
  extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

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

// Block signals (default storage)
struct B_Angulo_T {
  SL_Bus_sensor_msgs_LaserScan b_varargout_2;
  SL_Bus_sensor_msgs_Temperature BusAssignment2;// '<S4>/Bus Assignment2'
  SL_Bus_std_msgs_Header header;
  SL_Bus_geometry_msgs_Twist BusAssignment1_p;// '<S3>/Bus Assignment1'
  real_T Multiply3;                    // '<S2>/Multiply3'
  real_T Multiply4;                    // '<S2>/Multiply4'
  real_T Multiply1;                    // '<S1>/Multiply1'
  real_T Multiply3_f;                  // '<S1>/Multiply3'
  real_T Multiply22;                   // '<S2>/Multiply22'
  real_T x;
  real_T y;
  real_T z;
  real_T x_c;
  real_T y_n;
  real_T z_p;
  real_T y_d;                          // '<S1>/MATLAB Function'
  real_T Integrator;                   // '<S1>/Integrator'
  real_T Multiply1_m;                  // '<S2>/Multiply1'
  real32_T Gain;                       // '<S13>/Gain'
  real32_T Median;                     // '<S15>/Median'
  real32_T Median1;                    // '<S15>/Median1'
};

// Block states (default storage) for system '<Root>'
struct DW_Angulo_T {
  ros_slros2_internal_block_Pub_T obj; // '<S12>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_n;// '<S11>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_p;// '<S9>/SinkBlock'
  ros_slros2_internal_block_Sub_T obj_f;// '<S17>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_nf;// '<S14>/SourceBlock'
  real_T TimeStampA;                   // '<S2>/Derivative'
  real_T LastUAtTimeA;                 // '<S2>/Derivative'
  real_T TimeStampB;                   // '<S2>/Derivative'
  real_T LastUAtTimeB;                 // '<S2>/Derivative'
  real_T TimeStampA_g;                 // '<S1>/Derivative'
  real_T LastUAtTimeA_i;               // '<S1>/Derivative'
  real_T TimeStampB_c;                 // '<S1>/Derivative'
  real_T LastUAtTimeB_o;               // '<S1>/Derivative'
  uint32_T Median_Index[5];            // '<S15>/Median'
  uint32_T Median1_Index[5];           // '<S15>/Median1'
};

// Continuous states (default storage)
struct X_Angulo_T {
  real_T Integrator_CSTATE;            // '<S2>/Integrator'
  real_T Integrator_CSTATE_d;          // '<S1>/Integrator'
};

// State derivatives (default storage)
struct XDot_Angulo_T {
  real_T Integrator_CSTATE;            // '<S2>/Integrator'
  real_T Integrator_CSTATE_d;          // '<S1>/Integrator'
};

// State disabled
struct XDis_Angulo_T {
  boolean_T Integrator_CSTATE;         // '<S2>/Integrator'
  boolean_T Integrator_CSTATE_d;       // '<S1>/Integrator'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_Angulo_T_ {
  SL_Bus_sensor_msgs_LaserScan Out1_Y0;// Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S16>/Out1'

  SL_Bus_sensor_msgs_LaserScan Constant_Value;// Computed Parameter: Constant_Value
                                                 //  Referenced by: '<S14>/Constant'

  SL_Bus_sensor_msgs_Temperature Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                     //  Referenced by: '<S10>/Constant'

  SL_Bus_std_msgs_Header header_Y0;    // Computed Parameter: header_Y0
                                          //  Referenced by: '<S15>/<header>'

  SL_Bus_geometry_msgs_Twist Out1_Y0_m;// Computed Parameter: Out1_Y0_m
                                          //  Referenced by: '<S19>/Out1'

  SL_Bus_geometry_msgs_Twist Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                 //  Referenced by: '<S8>/Constant'

  SL_Bus_geometry_msgs_Twist Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                 //  Referenced by: '<S17>/Constant'

  real_T x_Y0;                         // Computed Parameter: x_Y0
                                          //  Referenced by: '<S18>/<x>'

  real_T x1_Y0;                        // Computed Parameter: x1_Y0
                                          //  Referenced by: '<S18>/<x>1'

  real_T x2_Y0;                        // Computed Parameter: x2_Y0
                                          //  Referenced by: '<S18>/<x>2'

  real_T x3_Y0;                        // Computed Parameter: x3_Y0
                                          //  Referenced by: '<S18>/<x>3'

  real_T x5_Y0;                        // Computed Parameter: x5_Y0
                                          //  Referenced by: '<S18>/<x>5'

  real_T x4_Y0;                        // Computed Parameter: x4_Y0
                                          //  Referenced by: '<S18>/<x>4'

  real_T ref_dn_Value;                 // Expression: 0.20
                                          //  Referenced by: '<Root>/ref_dn'

  real_T Integrator_IC;                // Expression: 0
                                          //  Referenced by: '<S2>/Integrator'

  real_T Constant_Value_o;             // Expression: pi/2
                                          //  Referenced by: '<S4>/Constant'

  real_T Integrator_IC_h;              // Expression: 0
                                          //  Referenced by: '<S1>/Integrator'

  real_T Integrator_UpperSat;          // Expression: 1000
                                          //  Referenced by: '<S1>/Integrator'

  real_T Integrator_LowerSat;          // Expression: -1000
                                          //  Referenced by: '<S1>/Integrator'

  real_T Saturation_UpperSat;          // Expression: 100
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -100
                                          //  Referenced by: '<Root>/Saturation'

  real_T Constant_Value_k;             // Expression: 25
                                          //  Referenced by: '<S3>/Constant'

  real32_T d1_Y0;                      // Computed Parameter: d1_Y0
                                          //  Referenced by: '<S15>/<d1>'

  real32_T d2_Y0;                      // Computed Parameter: d2_Y0
                                          //  Referenced by: '<S15>/<d2>'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S4>/Gain1'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S4>/Gain'

  real32_T Gain_Gain_l;                // Computed Parameter: Gain_Gain_l
                                          //  Referenced by: '<S13>/Gain'

};

// Real-time Model Data Structure
struct tag_RTM_Angulo_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Angulo_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

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
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Class declaration for model Angulo
class Angulo
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_Angulo_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  Angulo();

  // Destructor
  ~Angulo();

  // private data and function members
 private:
  // Block signals
  B_Angulo_T Angulo_B;

  // Block states
  DW_Angulo_T Angulo_DW;

  // Tunable parameters
  static P_Angulo_T Angulo_P;

  // Block continuous states
  X_Angulo_T Angulo_X;

  // private member function(s) for subsystem '<S1>/MATLAB Function'
  static void Angulo_MATLABFunction(real_T rtu_u, real_T *rty_y);

  // private member function(s) for subsystem '<Root>'
  void Angulo_SystemCore_setup_a1l5(ros_slros2_internal_block_Sub_T *obj);
  void Angulo_SystemCore_setup_a1l(ros_slros2_internal_block_Sub_T *obj);
  void Angulo_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj);
  void Angulo_SystemCore_setup_a1(ros_slros2_internal_block_Pub_T *obj);
  void Angulo_SystemCore_setup_a(ros_slros2_internal_block_Pub_T *obj);

  // Continuous states update member function
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  // Derivatives member function
  void Angulo_derivatives();

  // Real-Time Model
  RT_MODEL_Angulo_T Angulo_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Display' : Unused code path elimination
//  Block '<S1>/Display1' : Unused code path elimination
//  Block '<S1>/Display2' : Unused code path elimination
//  Block '<Root>/Display' : Unused code path elimination
//  Block '<Root>/Display1' : Unused code path elimination
//  Block '<Root>/Display2' : Unused code path elimination
//  Block '<Root>/Display3' : Unused code path elimination
//  Block '<Root>/Display4' : Unused code path elimination
//  Block '<Root>/Scope' : Unused code path elimination


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
//  '<Root>' : 'Angulo'
//  '<S1>'   : 'Angulo/C(s)'
//  '<S2>'   : 'Angulo/Cr(s)'
//  '<S3>'   : 'Angulo/Mandar giro'
//  '<S4>'   : 'Angulo/Medidas'
//  '<S5>'   : 'Angulo/R1'
//  '<S6>'   : 'Angulo/C(s)/MATLAB Function'
//  '<S7>'   : 'Angulo/Cr(s)/MATLAB Function'
//  '<S8>'   : 'Angulo/Mandar giro/Blank Message1'
//  '<S9>'   : 'Angulo/Mandar giro/Publish1'
//  '<S10>'  : 'Angulo/Medidas/Blank Message1'
//  '<S11>'  : 'Angulo/Medidas/Publish1'
//  '<S12>'  : 'Angulo/Medidas/Publish2'
//  '<S13>'  : 'Angulo/Medidas/Radians to Degrees'
//  '<S14>'  : 'Angulo/Medidas/Subscribe'
//  '<S15>'  : 'Angulo/Medidas/Subsystem1'
//  '<S16>'  : 'Angulo/Medidas/Subscribe/Enabled Subsystem'
//  '<S17>'  : 'Angulo/R1/Subscribe2'
//  '<S18>'  : 'Angulo/R1/Subsystem1'
//  '<S19>'  : 'Angulo/R1/Subscribe2/Enabled Subsystem'

#endif                                 // RTW_HEADER_Angulo_h_

//
// File trailer for generated code.
//
// [EOF]
//
