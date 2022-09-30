//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Angulo_private.h
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
#ifndef RTW_HEADER_Angulo_private_h_
#define RTW_HEADER_Angulo_private_h_
#include "rtwtypes.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern boolean_T findpivotIdx_S(int32_T i, int32_T j, int32_T startIdx, int32_T
  pivot[], uint32_T midxPort[], const real32_T mdataPort[]);
extern int32_T partitionIdx_S(int32_T i, int32_T j, int32_T startIdx, const
  int32_T pivot[], uint32_T midxPort[], const real32_T mdataPort[]);
extern void MDNQSort_S(int32_T i, int32_T j, int32_T startIdx, uint32_T
  midxPort[], const real32_T mdataPort[]);

// private model entry point functions
extern void Angulo_derivatives();

#endif                                 // RTW_HEADER_Angulo_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
