//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Angulo.cpp
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
#include "Angulo.h"
#include "rtwtypes.h"
#include "Angulo_types.h"

extern "C" {

#include "rt_nonfinite.h"

}
#include "Angulo_private.h"
#include <math.h>
#include "rmw/qos_profiles.h"
#include "rmw/types.h"
#include <stddef.h>

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
void Angulo::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  Angulo_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  Angulo_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  this->step();
  Angulo_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

//
// Output and update for atomic system:
//    '<S1>/MATLAB Function'
//    '<S2>/MATLAB Function'
//
void Angulo::Angulo_MATLABFunction(real_T rtu_u, real_T *rty_y)
{
  *rty_y = rtu_u;
  if (rtIsNaN(rtu_u)) {
    *rty_y = 0.0;
  } else if (rtIsInf(rtu_u)) {
    *rty_y = 0.0;
  }
}

boolean_T findpivotIdx_S(int32_T i, int32_T j, int32_T startIdx, int32_T pivot[],
  uint32_T midxPort[], const real32_T mdataPort[])
{
  int32_T mid;
  real32_T tmp0;
  real32_T tmp1_tmp;
  uint32_T t;
  boolean_T pivotFind;

  // S-Function (sdspmdn2): '<S15>/Median'
  mid = (i + j) >> 1;
  tmp0 = mdataPort[midxPort[i] + startIdx];
  tmp1_tmp = mdataPort[midxPort[mid] + startIdx];
  if (tmp0 > tmp1_tmp) {
    t = midxPort[i];
    midxPort[i] = midxPort[mid];
    midxPort[mid] = t;
  }

  if (tmp0 > mdataPort[midxPort[j] + startIdx]) {
    t = midxPort[i];
    midxPort[i] = midxPort[j];
    midxPort[j] = t;
  }

  if (tmp1_tmp > mdataPort[midxPort[j] + startIdx]) {
    t = midxPort[mid];
    midxPort[mid] = midxPort[j];
    midxPort[j] = t;
  }

  tmp0 = mdataPort[midxPort[i] + startIdx];
  tmp1_tmp = mdataPort[midxPort[mid] + startIdx];
  pivotFind = false;
  if (tmp0 < tmp1_tmp) {
    pivot[0U] = mid;
    pivotFind = true;
  } else if (tmp1_tmp < mdataPort[midxPort[j] + startIdx]) {
    pivot[0U] = j;
    pivotFind = true;
  } else {
    mid = i + 1;
    while ((mid <= j) && (!pivotFind)) {
      tmp1_tmp = mdataPort[midxPort[mid] + startIdx];
      if (tmp1_tmp != tmp0) {
        if (tmp1_tmp < tmp0) {
          pivot[0U] = i;
        } else {
          pivot[0U] = mid;
        }

        pivotFind = true;
        mid = j + 1;
      }

      mid++;
    }
  }

  // End of S-Function (sdspmdn2): '<S15>/Median'
  return pivotFind;
}

int32_T partitionIdx_S(int32_T i, int32_T j, int32_T startIdx, const int32_T
  pivot[], uint32_T midxPort[], const real32_T mdataPort[])
{
  int32_T ctidx;
  real32_T tmp0;

  // S-Function (sdspmdn2): '<S15>/Median'
  tmp0 = mdataPort[midxPort[pivot[0U]] + startIdx];
  ctidx = j - i;
  while ((i <= j) && (ctidx >= 0)) {
    while (mdataPort[midxPort[i] + startIdx] < tmp0) {
      i++;
    }

    while (mdataPort[midxPort[j] + startIdx] >= tmp0) {
      j--;
    }

    if (i < j) {
      uint32_T t;
      t = midxPort[i];
      midxPort[i] = midxPort[j];
      midxPort[j] = t;
      i++;
      j--;
    }

    ctidx--;
  }

  return i;

  // End of S-Function (sdspmdn2): '<S15>/Median'
}

void MDNQSort_S(int32_T i, int32_T j, int32_T startIdx, uint32_T midxPort[],
                const real32_T mdataPort[])
{
  int32_T pivot;

  // S-Function (sdspmdn2): '<S15>/Median'
  if (findpivotIdx_S(i, j, startIdx, &pivot, &midxPort[0U], &mdataPort[0U])) {
    pivot = partitionIdx_S(i, j, startIdx, &pivot, &midxPort[0U], &mdataPort[0U]);
    MDNQSort_S(i, pivot - 1, startIdx, &midxPort[0U], &mdataPort[0U]);
    MDNQSort_S(pivot, j, startIdx, &midxPort[0U], &mdataPort[0U]);
  }

  // End of S-Function (sdspmdn2): '<S15>/Median'
}

void Angulo::Angulo_SystemCore_setup_a1l5(ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[9];
  static const char_T tmp[8] = { '/', 'c', 'o', 'n', 't', 'r', 'o', 'l' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 8; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[8] = '\x00';
  ros2::matlab::create_Sub_Angulo_146(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void Angulo::Angulo_SystemCore_setup_a1l(ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[6];
  static const char_T tmp[5] = { '/', 's', 'c', 'a', 'n' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)10.0, durability, reliability);
  for (int32_T i = 0; i < 5; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[5] = '\x00';
  ros2::matlab::create_Sub_Angulo_1(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void Angulo::Angulo_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[9];
  static const char_T tmp[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 8; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[8] = '\x00';
  ros2::matlab::create_Pub_Angulo_94(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void Angulo::Angulo_SystemCore_setup_a1(ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[13];
  static const char_T tmp[12] = { '/', 'a', 'n', 'g', 'u', 'l', 'o', 'P', 'a',
    'r', 'e', 'd' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 12; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[12] = '\x00';
  ros2::matlab::create_Pub_Angulo_65(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void Angulo::Angulo_SystemCore_setup_a(ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[16];
  static const char_T tmp[15] = { '/', 'd', 'i', 's', 't', 'a', 'n', 'c', 'i',
    'a', 'P', 'a', 'r', 'e', 'd' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 15; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[15] = '\x00';
  ros2::matlab::create_Pub_Angulo_56(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void Angulo::step()
{
  if (rtmIsMajorTimeStep((&Angulo_M))) {
    // set solver stop time
    rtsiSetSolverStopTime(&(&Angulo_M)->solverInfo,(((&Angulo_M)
      ->Timing.clockTick0+1)*(&Angulo_M)->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep((&Angulo_M))) {
    (&Angulo_M)->Timing.t[0] = rtsiGetT(&(&Angulo_M)->solverInfo);
  }

  {
    real_T rtb_Divide1;
    real_T rtb_Saturation;
    real_T rtb_y;
    real_T *lastU;
    real32_T rtb_Tanh;
    boolean_T b_varargout_1;
    if (rtmIsMajorTimeStep((&Angulo_M))) {
      // MATLABSystem: '<S17>/SourceBlock'
      b_varargout_1 = ros2::matlab::getLatestMessage_Sub_Angulo_146
        (&Angulo_B.BusAssignment1_p);

      // Outputs for Enabled SubSystem: '<S5>/Subsystem1' incorporates:
      //   EnablePort: '<S18>/Enable'

      // Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S19>/Enable'

      if (b_varargout_1) {
        // SignalConversion generated from: '<S18>/Bus Selector1'
        Angulo_B.x = Angulo_B.BusAssignment1_p.linear.x;

        // SignalConversion generated from: '<S18>/Bus Selector1'
        Angulo_B.y = Angulo_B.BusAssignment1_p.linear.y;

        // SignalConversion generated from: '<S18>/Bus Selector1'
        Angulo_B.z = Angulo_B.BusAssignment1_p.linear.z;

        // SignalConversion generated from: '<S18>/Bus Selector1'
        Angulo_B.x_c = Angulo_B.BusAssignment1_p.angular.x;

        // SignalConversion generated from: '<S18>/Bus Selector1'
        Angulo_B.y_n = Angulo_B.BusAssignment1_p.angular.y;

        // SignalConversion generated from: '<S18>/Bus Selector1'
        Angulo_B.z_p = Angulo_B.BusAssignment1_p.angular.z;
      }

      // End of MATLABSystem: '<S17>/SourceBlock'
      // End of Outputs for SubSystem: '<S17>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<S5>/Subsystem1'

      // Product: '<S2>/Multiply1' incorporates:
      //   Constant: '<Root>/ref_dn'

      Angulo_B.Multiply1_m = Angulo_B.x * Angulo_P.ref_dn_Value;

      // Product: '<S2>/Multiply3'
      Angulo_B.Multiply3 = Angulo_B.z * Angulo_B.y_n * Angulo_B.Multiply1_m;
    }

    // Derivative: '<S2>/Derivative' incorporates:
    //   Derivative: '<S1>/Derivative'

    rtb_Saturation = (&Angulo_M)->Timing.t[0];
    if ((Angulo_DW.TimeStampA >= rtb_Saturation) && (Angulo_DW.TimeStampB >=
         rtb_Saturation)) {
      Angulo_B.Integrator = 0.0;
    } else {
      Angulo_B.Integrator = Angulo_DW.TimeStampA;
      lastU = &Angulo_DW.LastUAtTimeA;
      if (Angulo_DW.TimeStampA < Angulo_DW.TimeStampB) {
        if (Angulo_DW.TimeStampB < rtb_Saturation) {
          Angulo_B.Integrator = Angulo_DW.TimeStampB;
          lastU = &Angulo_DW.LastUAtTimeB;
        }
      } else if (Angulo_DW.TimeStampA >= rtb_Saturation) {
        Angulo_B.Integrator = Angulo_DW.TimeStampB;
        lastU = &Angulo_DW.LastUAtTimeB;
      }

      Angulo_B.Integrator = (Angulo_B.Multiply3 - *lastU) / (rtb_Saturation -
        Angulo_B.Integrator);
    }

    // End of Derivative: '<S2>/Derivative'
    if (rtmIsMajorTimeStep((&Angulo_M))) {
      // Product: '<S2>/Multiply4'
      Angulo_B.Multiply4 = Angulo_B.Multiply1_m * Angulo_B.x_c;
    }

    // MATLAB Function: '<S2>/MATLAB Function' incorporates:
    //   Integrator: '<S2>/Integrator'
    //   Sum: '<S2>/Sum'

    Angulo_MATLABFunction((Angulo_B.Integrator + Angulo_B.Multiply4) +
                          Angulo_X.Integrator_CSTATE, &rtb_y);
    if (rtmIsMajorTimeStep((&Angulo_M))) {
      // MATLABSystem: '<S14>/SourceBlock'
      b_varargout_1 = ros2::matlab::getLatestMessage_Sub_Angulo_1
        (&Angulo_B.b_varargout_2);

      // Outputs for Enabled SubSystem: '<S4>/Subsystem1' incorporates:
      //   EnablePort: '<S15>/Enable'

      // Outputs for Enabled SubSystem: '<S14>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S16>/Enable'

      if (b_varargout_1) {
        // S-Function (sdspmdn2): '<S15>/Median'
        MDNQSort_S(0, 4, 0, &Angulo_DW.Median_Index[0],
                   &Angulo_B.b_varargout_2.ranges[88]);

        // S-Function (sdspmdn2): '<S15>/Median'
        Angulo_B.Median = Angulo_B.b_varargout_2.ranges[static_cast<int32_T>
          (Angulo_DW.Median_Index[2]) + 88];

        // S-Function (sdspmdn2): '<S15>/Median1'
        MDNQSort_S(0, 4, 0, &Angulo_DW.Median1_Index[0],
                   &Angulo_B.b_varargout_2.ranges[118]);

        // S-Function (sdspmdn2): '<S15>/Median1'
        Angulo_B.Median1 = Angulo_B.b_varargout_2.ranges[static_cast<int32_T>
          (Angulo_DW.Median1_Index[2]) + 118];

        // SignalConversion generated from: '<S15>/Bus Selector2'
        Angulo_B.header = Angulo_B.b_varargout_2.header;
      }

      // End of MATLABSystem: '<S14>/SourceBlock'
      // End of Outputs for SubSystem: '<S14>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<S4>/Subsystem1'

      // Trigonometry: '<S4>/Tanh' incorporates:
      //   Gain: '<S4>/Gain'
      //   Gain: '<S4>/Gain1'
      //   Product: '<S4>/Divide'
      //   Sum: '<S4>/Sum'

      rtb_Tanh = static_cast<real32_T>(atan(static_cast<real_T>((Angulo_B.Median
        - Angulo_P.Gain1_Gain * Angulo_B.Median1) / (Angulo_P.Gain_Gain *
        Angulo_B.Median1))));

      // Product: '<S4>/Divide1' incorporates:
      //   Constant: '<S4>/Constant'
      //   Sum: '<S4>/Sum1'
      //   Trigonometry: '<S4>/Sin'

      rtb_Divide1 = sin(Angulo_P.Constant_Value_o - rtb_Tanh) * Angulo_B.Median;

      // Product: '<S1>/Multiply1'
      Angulo_B.Multiply1 = Angulo_B.x * rtb_Divide1;

      // Product: '<S1>/Multiply3'
      Angulo_B.Multiply3_f = Angulo_B.z * Angulo_B.Multiply1;
    }

    // Derivative: '<S1>/Derivative'
    if ((Angulo_DW.TimeStampA_g >= rtb_Saturation) && (Angulo_DW.TimeStampB_c >=
         rtb_Saturation)) {
      rtb_Saturation = 0.0;
    } else {
      Angulo_B.Integrator = Angulo_DW.TimeStampA_g;
      lastU = &Angulo_DW.LastUAtTimeA_i;
      if (Angulo_DW.TimeStampA_g < Angulo_DW.TimeStampB_c) {
        if (Angulo_DW.TimeStampB_c < rtb_Saturation) {
          Angulo_B.Integrator = Angulo_DW.TimeStampB_c;
          lastU = &Angulo_DW.LastUAtTimeB_o;
        }
      } else if (Angulo_DW.TimeStampA_g >= rtb_Saturation) {
        Angulo_B.Integrator = Angulo_DW.TimeStampB_c;
        lastU = &Angulo_DW.LastUAtTimeB_o;
      }

      rtb_Saturation = (Angulo_B.Multiply3_f - *lastU) / (rtb_Saturation -
        Angulo_B.Integrator);
    }

    // Integrator: '<S1>/Integrator'
    // Limited  Integrator
    if (Angulo_X.Integrator_CSTATE_d >= Angulo_P.Integrator_UpperSat) {
      Angulo_X.Integrator_CSTATE_d = Angulo_P.Integrator_UpperSat;
    } else if (Angulo_X.Integrator_CSTATE_d <= Angulo_P.Integrator_LowerSat) {
      Angulo_X.Integrator_CSTATE_d = Angulo_P.Integrator_LowerSat;
    }

    if (rtmIsMajorTimeStep((&Angulo_M))) {
      // Gain: '<S13>/Gain'
      Angulo_B.Gain = Angulo_P.Gain_Gain_l * rtb_Tanh;
    }

    // BusAssignment: '<S3>/Bus Assignment1' incorporates:
    //   Constant: '<S8>/Constant'

    Angulo_B.BusAssignment1_p = Angulo_P.Constant_Value_l;

    // Product: '<Root>/Multiply1' incorporates:
    //   Integrator: '<S1>/Integrator'
    //   Sum: '<Root>/Sum'
    //   Sum: '<Root>/Sum1'
    //   Sum: '<S1>/Sum'

    rtb_y = ((rtb_y - ((rtb_Saturation + Angulo_B.Multiply1) +
                       Angulo_X.Integrator_CSTATE_d)) - Angulo_B.Gain) *
      Angulo_B.z_p;

    // Saturate: '<Root>/Saturation'
    if (rtb_y > Angulo_P.Saturation_UpperSat) {
      // BusAssignment: '<S3>/Bus Assignment1'
      Angulo_B.BusAssignment1_p.angular.z = Angulo_P.Saturation_UpperSat;
    } else if (rtb_y < Angulo_P.Saturation_LowerSat) {
      // BusAssignment: '<S3>/Bus Assignment1'
      Angulo_B.BusAssignment1_p.angular.z = Angulo_P.Saturation_LowerSat;
    } else {
      // BusAssignment: '<S3>/Bus Assignment1'
      Angulo_B.BusAssignment1_p.angular.z = rtb_y;
    }

    // End of Saturate: '<Root>/Saturation'

    // BusAssignment: '<S3>/Bus Assignment1' incorporates:
    //   Constant: '<S3>/Constant'

    Angulo_B.BusAssignment1_p.linear.x = Angulo_P.Constant_Value_k;

    // MATLABSystem: '<S9>/SinkBlock'
    ros2::matlab::publish_Pub_Angulo_94(&Angulo_B.BusAssignment1_p);
    if (rtmIsMajorTimeStep((&Angulo_M))) {
      // BusAssignment: '<S4>/Bus Assignment2' incorporates:
      //   Constant: '<S10>/Constant'
      //   DataTypeConversion: '<S4>/Cast To Double'

      Angulo_B.BusAssignment2 = Angulo_P.Constant_Value_a;
      Angulo_B.BusAssignment2.temperature = Angulo_B.Gain;
      Angulo_B.BusAssignment2.header = Angulo_B.header;

      // MATLABSystem: '<S12>/SinkBlock'
      ros2::matlab::publish_Pub_Angulo_65(&Angulo_B.BusAssignment2);

      // MATLAB Function: '<S1>/MATLAB Function' incorporates:
      //   Product: '<S1>/Multiply2'

      Angulo_MATLABFunction(Angulo_B.Multiply1 * Angulo_B.y, &Angulo_B.y_d);

      // BusAssignment: '<S4>/Bus Assignment1' incorporates:
      //   Constant: '<S10>/Constant'

      Angulo_B.BusAssignment2 = Angulo_P.Constant_Value_a;
      Angulo_B.BusAssignment2.temperature = rtb_Divide1;
      Angulo_B.BusAssignment2.header = Angulo_B.header;

      // MATLABSystem: '<S11>/SinkBlock'
      ros2::matlab::publish_Pub_Angulo_56(&Angulo_B.BusAssignment2);

      // Product: '<S2>/Multiply22'
      Angulo_B.Multiply22 = Angulo_B.Multiply1_m * Angulo_B.y;
    }
  }

  if (rtmIsMajorTimeStep((&Angulo_M))) {
    real_T *lastU;

    // Update for Derivative: '<S2>/Derivative'
    if (Angulo_DW.TimeStampA == (rtInf)) {
      Angulo_DW.TimeStampA = (&Angulo_M)->Timing.t[0];
      lastU = &Angulo_DW.LastUAtTimeA;
    } else if (Angulo_DW.TimeStampB == (rtInf)) {
      Angulo_DW.TimeStampB = (&Angulo_M)->Timing.t[0];
      lastU = &Angulo_DW.LastUAtTimeB;
    } else if (Angulo_DW.TimeStampA < Angulo_DW.TimeStampB) {
      Angulo_DW.TimeStampA = (&Angulo_M)->Timing.t[0];
      lastU = &Angulo_DW.LastUAtTimeA;
    } else {
      Angulo_DW.TimeStampB = (&Angulo_M)->Timing.t[0];
      lastU = &Angulo_DW.LastUAtTimeB;
    }

    *lastU = Angulo_B.Multiply3;

    // End of Update for Derivative: '<S2>/Derivative'

    // Update for Derivative: '<S1>/Derivative'
    if (Angulo_DW.TimeStampA_g == (rtInf)) {
      Angulo_DW.TimeStampA_g = (&Angulo_M)->Timing.t[0];
      lastU = &Angulo_DW.LastUAtTimeA_i;
    } else if (Angulo_DW.TimeStampB_c == (rtInf)) {
      Angulo_DW.TimeStampB_c = (&Angulo_M)->Timing.t[0];
      lastU = &Angulo_DW.LastUAtTimeB_o;
    } else if (Angulo_DW.TimeStampA_g < Angulo_DW.TimeStampB_c) {
      Angulo_DW.TimeStampA_g = (&Angulo_M)->Timing.t[0];
      lastU = &Angulo_DW.LastUAtTimeA_i;
    } else {
      Angulo_DW.TimeStampB_c = (&Angulo_M)->Timing.t[0];
      lastU = &Angulo_DW.LastUAtTimeB_o;
    }

    *lastU = Angulo_B.Multiply3_f;

    // End of Update for Derivative: '<S1>/Derivative'
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep((&Angulo_M))) {
    rt_ertODEUpdateContinuousStates(&(&Angulo_M)->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++(&Angulo_M)->Timing.clockTick0;
    (&Angulo_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&Angulo_M)->solverInfo);

    {
      // Update absolute timer for sample time: [0.0027777777777777779s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.0027777777777777779, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      (&Angulo_M)->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void Angulo::Angulo_derivatives()
{
  XDot_Angulo_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_Angulo_T *) (&Angulo_M)->derivs);

  // Derivatives for Integrator: '<S2>/Integrator'
  _rtXdot->Integrator_CSTATE = Angulo_B.Multiply22;

  // Derivatives for Integrator: '<S1>/Integrator'
  lsat = (Angulo_X.Integrator_CSTATE_d <= Angulo_P.Integrator_LowerSat);
  usat = (Angulo_X.Integrator_CSTATE_d >= Angulo_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (Angulo_B.y_d > 0.0)) || (usat &&
       (Angulo_B.y_d < 0.0))) {
    _rtXdot->Integrator_CSTATE_d = Angulo_B.y_d;
  } else {
    // in saturation
    _rtXdot->Integrator_CSTATE_d = 0.0;
  }

  // End of Derivatives for Integrator: '<S1>/Integrator'
}

// Model initialize function
void Angulo::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&Angulo_M)->solverInfo, &(&Angulo_M)
                          ->Timing.simTimeStep);
    rtsiSetTPtr(&(&Angulo_M)->solverInfo, &rtmGetTPtr((&Angulo_M)));
    rtsiSetStepSizePtr(&(&Angulo_M)->solverInfo, &(&Angulo_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&Angulo_M)->solverInfo, &(&Angulo_M)->derivs);
    rtsiSetContStatesPtr(&(&Angulo_M)->solverInfo, (real_T **) &(&Angulo_M)
                         ->contStates);
    rtsiSetNumContStatesPtr(&(&Angulo_M)->solverInfo, &(&Angulo_M)
      ->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&Angulo_M)->solverInfo, &(&Angulo_M)
      ->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&Angulo_M)->solverInfo, &(&Angulo_M)
      ->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&Angulo_M)->solverInfo, &(&Angulo_M)
      ->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&Angulo_M)->solverInfo, (&rtmGetErrorStatus
      ((&Angulo_M))));
    rtsiSetRTModelPtr(&(&Angulo_M)->solverInfo, (&Angulo_M));
  }

  rtsiSetSimTimeStep(&(&Angulo_M)->solverInfo, MAJOR_TIME_STEP);
  (&Angulo_M)->intgData.y = (&Angulo_M)->odeY;
  (&Angulo_M)->intgData.f[0] = (&Angulo_M)->odeF[0];
  (&Angulo_M)->intgData.f[1] = (&Angulo_M)->odeF[1];
  (&Angulo_M)->intgData.f[2] = (&Angulo_M)->odeF[2];
  (&Angulo_M)->contStates = ((X_Angulo_T *) &Angulo_X);
  rtsiSetSolverData(&(&Angulo_M)->solverInfo, static_cast<void *>(&(&Angulo_M)
    ->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&(&Angulo_M)->solverInfo, false);
  rtsiSetSolverName(&(&Angulo_M)->solverInfo,"ode3");
  rtmSetTPtr((&Angulo_M), &(&Angulo_M)->Timing.tArray[0]);
  (&Angulo_M)->Timing.stepSize0 = 0.0027777777777777779;

  {
    uint32_T i;
    uint32_T i_0;

    // InitializeConditions for Derivative: '<S2>/Derivative'
    Angulo_DW.TimeStampA = (rtInf);
    Angulo_DW.TimeStampB = (rtInf);

    // InitializeConditions for Integrator: '<S2>/Integrator'
    Angulo_X.Integrator_CSTATE = Angulo_P.Integrator_IC;

    // InitializeConditions for Derivative: '<S1>/Derivative'
    Angulo_DW.TimeStampA_g = (rtInf);
    Angulo_DW.TimeStampB_c = (rtInf);

    // InitializeConditions for Integrator: '<S1>/Integrator'
    Angulo_X.Integrator_CSTATE_d = Angulo_P.Integrator_IC_h;

    // SystemInitialize for Enabled SubSystem: '<S5>/Subsystem1'
    // SystemInitialize for SignalConversion generated from: '<S18>/Bus Selector1' incorporates:
    //   Outport: '<S18>/<x>'

    Angulo_B.x = Angulo_P.x_Y0;

    // SystemInitialize for SignalConversion generated from: '<S18>/Bus Selector1' incorporates:
    //   Outport: '<S18>/<x>1'

    Angulo_B.y = Angulo_P.x1_Y0;

    // SystemInitialize for SignalConversion generated from: '<S18>/Bus Selector1' incorporates:
    //   Outport: '<S18>/<x>2'

    Angulo_B.z = Angulo_P.x2_Y0;

    // SystemInitialize for SignalConversion generated from: '<S18>/Bus Selector1' incorporates:
    //   Outport: '<S18>/<x>3'

    Angulo_B.x_c = Angulo_P.x3_Y0;

    // SystemInitialize for SignalConversion generated from: '<S18>/Bus Selector1' incorporates:
    //   Outport: '<S18>/<x>5'

    Angulo_B.y_n = Angulo_P.x5_Y0;

    // SystemInitialize for SignalConversion generated from: '<S18>/Bus Selector1' incorporates:
    //   Outport: '<S18>/<x>4'

    Angulo_B.z_p = Angulo_P.x4_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/Subsystem1'

    // SystemInitialize for Enabled SubSystem: '<S4>/Subsystem1'
    // InitializeConditions for S-Function (sdspmdn2): '<S15>/Median'
    i = 0U;

    // InitializeConditions for S-Function (sdspmdn2): '<S15>/Median1'
    i_0 = 0U;
    for (int32_T j = 0; j < 5; j++) {
      // InitializeConditions for S-Function (sdspmdn2): '<S15>/Median'
      Angulo_DW.Median_Index[j] = i;
      i++;

      // InitializeConditions for S-Function (sdspmdn2): '<S15>/Median1'
      Angulo_DW.Median1_Index[j] = i_0;
      i_0++;
    }

    // SystemInitialize for S-Function (sdspmdn2): '<S15>/Median' incorporates:
    //   Outport: '<S15>/<d1>'

    Angulo_B.Median = Angulo_P.d1_Y0;

    // SystemInitialize for S-Function (sdspmdn2): '<S15>/Median1' incorporates:
    //   Outport: '<S15>/<d2>'

    Angulo_B.Median1 = Angulo_P.d2_Y0;

    // SystemInitialize for SignalConversion generated from: '<S15>/Bus Selector2' incorporates:
    //   Outport: '<S15>/<header>'

    Angulo_B.header = Angulo_P.header_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Subsystem1'

    // Start for MATLABSystem: '<S17>/SourceBlock'
    Angulo_DW.obj_f.isInitialized = 0;
    Angulo_DW.obj_f.matlabCodegenIsDeleted = false;
    Angulo_SystemCore_setup_a1l5(&Angulo_DW.obj_f);

    // Start for MATLABSystem: '<S14>/SourceBlock'
    Angulo_DW.obj_nf.isInitialized = 0;
    Angulo_DW.obj_nf.matlabCodegenIsDeleted = false;
    Angulo_SystemCore_setup_a1l(&Angulo_DW.obj_nf);

    // Start for MATLABSystem: '<S9>/SinkBlock'
    Angulo_DW.obj_p.isInitialized = 0;
    Angulo_DW.obj_p.matlabCodegenIsDeleted = false;
    Angulo_SystemCore_setup(&Angulo_DW.obj_p);

    // Start for MATLABSystem: '<S12>/SinkBlock'
    Angulo_DW.obj.isInitialized = 0;
    Angulo_DW.obj.matlabCodegenIsDeleted = false;
    Angulo_SystemCore_setup_a1(&Angulo_DW.obj);

    // Start for MATLABSystem: '<S11>/SinkBlock'
    Angulo_DW.obj_n.isInitialized = 0;
    Angulo_DW.obj_n.matlabCodegenIsDeleted = false;
    Angulo_SystemCore_setup_a(&Angulo_DW.obj_n);
  }
}

// Model terminate function
void Angulo::terminate()
{
  // Terminate for MATLABSystem: '<S17>/SourceBlock'
  if (!Angulo_DW.obj_f.matlabCodegenIsDeleted) {
    Angulo_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S17>/SourceBlock'

  // Terminate for MATLABSystem: '<S14>/SourceBlock'
  if (!Angulo_DW.obj_nf.matlabCodegenIsDeleted) {
    Angulo_DW.obj_nf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/SourceBlock'

  // Terminate for MATLABSystem: '<S9>/SinkBlock'
  if (!Angulo_DW.obj_p.matlabCodegenIsDeleted) {
    Angulo_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SinkBlock'

  // Terminate for MATLABSystem: '<S12>/SinkBlock'
  if (!Angulo_DW.obj.matlabCodegenIsDeleted) {
    Angulo_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/SinkBlock'

  // Terminate for MATLABSystem: '<S11>/SinkBlock'
  if (!Angulo_DW.obj_n.matlabCodegenIsDeleted) {
    Angulo_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/SinkBlock'
}

// Constructor
Angulo::Angulo() :
  Angulo_B(),
  Angulo_DW(),
  Angulo_X(),
  Angulo_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
Angulo::~Angulo()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Angulo_T * Angulo::getRTM()
{
  return (&Angulo_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
