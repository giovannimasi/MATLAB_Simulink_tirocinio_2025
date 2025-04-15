/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_f28379d_dyno_private.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_f28379d_dyno'.
 *
 * Model version                  : 8.29
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Apr 15 14:18:18 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_pmsm_foc_f28379d_dyno_private_h_
#define mcb_pmsm_foc_f28379d_dyno_private_h_
#include "rtwtypes.h"
#include "mcb_pmsm_foc_f28379d_dyno.h"
#include "mcb_pmsm_foc_f28379d_dyno_types.h"

void config_QEP_eQEP1(uint32_T pcmaximumvalue, uint32_T pcInitialvalue, uint32_T
                      unittimerperiod, uint32_T comparevalue, uint16_T
                      watchdogtimer, uint16_T qdecctl, uint16_T qepctl, uint16_T
                      qposctl, uint16_T qcapctl, uint16_T qeint);
void config_QEP_eQEP2(uint32_T pcmaximumvalue, uint32_T pcInitialvalue, uint32_T
                      unittimerperiod, uint32_T comparevalue, uint16_T
                      watchdogtimer, uint16_T qdecctl, uint16_T qepctl, uint16_T
                      qposctl, uint16_T qcapctl, uint16_T qeint);

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
extern void mcb_pmsm_foc_f283_limitRef2(real32_T rtu_ref2satsquare, real32_T
  rtu_ref2, real32_T *rty_ref2sat, rtB_limitRef2_mcb_pmsm_foc_f283 *localB);
extern void mcb_pmsm_foc_DQAxisPriority(real32_T rtu_dqRef, real32_T rtu_dqRef_e,
  real32_T rtu_satLim, real32_T rtu_satLimSq, uint16_T rtu_satMethod, real32_T
  rty_dqSat[2], rtB_DQAxisPriority_mcb_pmsm_foc *localB);
extern void mcb_pmsm_foc__DQEquivalence(real32_T rtu_dqRef, real32_T rtu_dqRef_d,
  real32_T rtu_magSquare, real32_T rtu_satLim, real32_T rtu_satLimSq, real32_T
  rty_dqSat[2], rtB_DQEquivalence_mcb_pmsm_foc_ *localB);
extern void mcb_pms_MATLABFunction_Init(rtDW_MATLABFunction_mcb_pmsm_fo *localDW);
extern void mcb_pm_MATLABFunction_Reset(rtDW_MATLABFunction_mcb_pmsm_fo *localDW);
extern void mcb_pmsm_foc_MATLABFunction(real32_T rtu_e, real32_T rtu_P, real32_T
  rtu_I_Ts_speed, boolean_T rtu_reset, real32_T rtu_Id0, real_T
  rtu_saturation_limit, rtB_MATLABFunction_mcb_pmsm_foc *localB,
  rtDW_MATLABFunction_mcb_pmsm_fo *localDW);
extern void mcb_p_MATLABFunction_a_Init(rtDW_MATLABFunction_mcb_pmsm__a *localDW);
extern void mcb__MATLABFunction_c_Reset(rtDW_MATLABFunction_mcb_pmsm__a *localDW);
extern void mcb_pmsm_f_MATLABFunction_j(real32_T rtu_e, real32_T rtu_P, real32_T
  rtu_I_Ts_speed, boolean_T rtu_reset, real32_T rtu_Iq0, real_T
  rtu_saturation_limit, rtB_MATLABFunction_mcb_pmsm_f_o *localB,
  rtDW_MATLABFunction_mcb_pmsm__a *localDW);
extern void mcb_pmsm_foc_f_TwoinputsCRL(real32_T rtu_Ds, real32_T rtu_Qs,
  real32_T rtu_sin, real32_T rtu_cos, rtB_TwoinputsCRL_mcb_pmsm_foc_f *localB);
extern void mcb_pmsm_foc_TwoinputsCRL_o(real32_T rtu_Alpha, real32_T rtu_Beta,
  real32_T rtu_sine, real32_T rtu_cos, rtB_TwoinputsCRL_mcb_pmsm_foc_i *localB);
extern void mcb_pmsm__IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem_mcb_pmsm_ *localB);
extern void mcb_pmsm_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem1_mcb_pmsm *localB);
extern void mcb_pms_IfActionSubsystem_a(real32_T rtu_m, real32_T rtu_Offset,
  real32_T *rty_m_out);
extern void mcb_pmsm_fo_PositionNoReset(uint16_T rtu_Index, uint16_T rtu_Count,
  uint16_T *rty_Position, rtB_PositionNoReset_mcb_pmsm_fo *localB);
extern void mcb_pms_IfActionSubsystem_b(uint16_T rtu_In1, uint16_T rtu_In2,
  rtB_IfActionSubsystem_mcb_pms_d *localB, rtDW_IfActionSubsystem_mcb_pm_h
  *localDW);
extern void mcb_pmsm_f_DQAxisPriority_e(real32_T rtu_dqRef, real32_T rtu_dqRef_j,
  real32_T rtu_satLim, real32_T rtu_satLimSq, uint16_T rtu_satMethod, real32_T
  rty_dqSat[2], rtB_DQAxisPriority_mcb_pmsm_f_a *localB);
extern void Speedcontrolformotor1_Init(rtDW_Speedcontrolformotor1_mcb_ *localDW);
extern void mcb_p_Speedcontrolformotor1(real32_T rtu_Speed_Ref_PU, real32_T
  rtu_Speed_Meas_PU, const boolean_T *rtd_EnMtrCtrl,
  rtB_Speedcontrolformotor1_mcb_p *localB, rtDW_Speedcontrolformotor1_mcb_
  *localDW);
extern void mcb__Torquecontrolformotor2(real32_T rtu_Imag_Ref_PU, real32_T
  rtu_Imag_Pos_PU, real32_T rtu_Speed_Meas_PU, rtB_Torquecontrolformotor2_mcb_
  *localB);
extern void Currentcontrolformotor_Init(void);
extern void Currentcontrolformoto_Reset(void);

#pragma CODE_SECTION (Currentcontrolformo_Disable, "ramfuncs")

extern void Currentcontrolformo_Disable(void);

#pragma CODE_SECTION (mcb_Currentcontrolformotor1, "ramfuncs")

extern void mcb_Currentcontrolformotor1(void);
extern void Currentcontrolformot_p_Init(void);
extern void Currentcontrolformo_a_Reset(void);

#pragma CODE_SECTION (Currentcontrolfor_j_Disable, "ramfuncs")

extern void Currentcontrolfor_j_Disable(void);

#pragma CODE_SECTION (mcb_Currentcontrolformotor2, "ramfuncs")

extern void mcb_Currentcontrolformotor2(void);

#endif                                /* mcb_pmsm_foc_f28379d_dyno_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
