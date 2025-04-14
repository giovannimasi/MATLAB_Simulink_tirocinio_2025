/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_sensorless_dyno_f28379d_private.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_sensorless_dyno_f28379d'.
 *
 * Model version                  : 9.4
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Apr 14 11:14:11 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_pmsm_foc_sensorless_dyno_f28379d_private_h_
#define mcb_pmsm_foc_sensorless_dyno_f28379d_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "mcb_pmsm_foc_sensorless_dyno_f28379d.h"
#include "mcb_pmsm_foc_sensorless_dyno_f28379d_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFFFU) ) || ( SCHAR_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
void InitAdcC (void);
void config_ADCC_SOC0 (void);
void InitAdcB (void);
void config_ADCB_SOC0 (void);
void config_ADCC_SOC1 (void);
void config_ADCB_SOC1 (void);
void config_ADCC_SOC2 (void);
void config_ADCB_SOC2 (void);
void config_ADCC_SOC3 (void);
void config_ADCB_SOC3 (void);
extern uint16_T MW_adcCInitFlag;
extern uint16_T MW_adcBInitFlag;
extern void mcb_pmsm_fo_TwophaseCRLwrap(real32_T rtu_a, real32_T rtu_b,
  rtB_TwophaseCRLwrap_mcb_pmsm_fo *localB);
extern void mcb_pmsm_foc_DQAxisPriority(real32_T rtu_dqRef, real32_T rtu_dqRef_k,
  real32_T rtu_satLim, real32_T rtu_satLimSq, uint16_T rtu_satMethod, real32_T
  rty_dqSat[2], rtB_DQAxisPriority_mcb_pmsm_foc *localB);
extern void mcb_pmsm_foc__DQEquivalence(real32_T rtu_dqRef, real32_T rtu_dqRef_l,
  real32_T rtu_magSquare, real32_T rtu_satLim, real32_T rtu_satLimSq, real32_T
  rty_dqSat[2], rtB_DQEquivalence_mcb_pmsm_foc_ *localB);
extern void mcb_pmsm_foc_s_TwoinputsCRL(real32_T rtu_Ds, real32_T rtu_Qs,
  real32_T rtu_sin, real32_T rtu_cos, rtB_TwoinputsCRL_mcb_pmsm_foc_s *localB);
extern void mcb_pmsm_foc_TwoinputsCRL_p(real32_T rtu_Alpha, real32_T rtu_Beta,
  real32_T rtu_sine, real32_T rtu_cos, rtB_TwoinputsCRL_mcb_pmsm_foc_k *localB);
extern void mcb_pmsm__IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem_mcb_pmsm_ *localB);
extern void mcb_pmsm_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem1_mcb_pmsm *localB);
extern void mcb_pmsm_foc_sens_Dir_Sense(boolean_T rtu_A, boolean_T rtu_B,
  rtB_Dir_Sense_mcb_pmsm_foc_sens *localB, rtZCE_Dir_Sense_mcb_pmsm_foc_se
  *localZCE);
extern void mcb_pmsm_foc_sen_Subsystem2(real32_T rtu_SigmaAlpha, real32_T
  rtu_SigmaBeta, real32_T *rty_Out1, real32_T *rty_Out2);
extern void mcb_pmsm__angleCompensation(real32_T rtu_A, real32_T rtu_B, real32_T
  rtu_C, real32_T rtu_D, rtB_angleCompensation_mcb_pmsm_ *localB);
extern void mcb_pmsm__FluxObserver_Init(rtDW_FluxObserver_mcb_pmsm_foc_ *localDW);
extern void mcb_pmsm_foc_s_FluxObserver(const real32_T rtu_InputSignals[4],
  real32_T rty_PositionSpeed[2], const boolean_T *rtd_Enable,
  rtB_FluxObserver_mcb_pmsm_foc_s *localB, rtDW_FluxObserver_mcb_pmsm_foc_
  *localDW, rtZCE_FluxObserver_mcb_pmsm_foc *localZCE);
extern void mcb_pms_IfActionSubsystem_c(uint16_T rtu_In1, uint16_T rtu_In2,
  rtB_IfActionSubsystem_mcb_pms_h *localB, rtDW_IfActionSubsystem_mcb_pm_n
  *localDW);
extern void mcb__SPIMasterTransfer_Init(rtDW_SPIMasterTransfer_mcb_pmsm *localDW);
extern void mcb_pmsm__SPIMasterTransfer(uint16_T rtu_0,
  rtB_SPIMasterTransfer_mcb_pmsm_ *localB, rtDW_SPIMasterTransfer_mcb_pmsm
  *localDW);
extern void mcb_SPIMasterTransfer2_Init(rtDW_SPIMasterTransfer2_mcb_pms *localDW);
extern void mcb_pmsm_SPIMasterTransfer2(uint16_T rtu_0,
  rtB_SPIMasterTransfer2_mcb_pmsm *localB, rtDW_SPIMasterTransfer2_mcb_pms
  *localDW);
extern void mcb_pmsm__SpeedControl_Init(rtB_SpeedControl_mcb_pmsm_foc_s *localB,
  rtDW_SpeedControl_mcb_pmsm_foc_ *localDW);
extern void mcb_pmsm_foc_s_SpeedControl(real_T rtu_EstimatorSelect, real32_T
  rtu_Speed_Ref_PU, real32_T rtu_Speed_Meas_PU, const boolean_T
  *rtd_EnClosedLoop, const boolean_T *rtd_Enable, const real32_T *rtd_SpeedRef,
  rtB_SpeedControl_mcb_pmsm_foc_s *localB, rtDW_SpeedControl_mcb_pmsm_foc_
  *localDW);
extern void mcb_FOCAlgorithmMotor1_Init(void);
extern void mc_FOCAlgorithmMotor1_Reset(void);

#pragma CODE_SECTION (mcb_pmsm_FOCAlgorithmMotor1, "ramfuncs")

extern void mcb_pmsm_FOCAlgorithmMotor1(void);
extern void mcb_FOCAlgorithmMotor2_Init(void);
extern void mc_FOCAlgorithmMotor2_Reset(void);

#pragma CODE_SECTION (FOCAlgorithmMotor2_Disable, "ramfuncs")

extern void FOCAlgorithmMotor2_Disable(void);

#pragma CODE_SECTION (mcb_pmsm_FOCAlgorithmMotor2, "ramfuncs")

extern void mcb_pmsm_FOCAlgorithmMotor2(void);
extern void mcb__SPIMasterTransfer_Term(rtDW_SPIMasterTransfer_mcb_pmsm *localDW);
extern void mcb_SPIMasterTransfer2_Term(rtDW_SPIMasterTransfer2_mcb_pms *localDW);

#endif                     /* mcb_pmsm_foc_sensorless_dyno_f28379d_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
