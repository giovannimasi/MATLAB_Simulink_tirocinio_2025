/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_f28379d_dyno.c
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_f28379d_dyno'.
 *
 * Model version                  : 8.28
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Apr 14 12:20:38 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcb_pmsm_foc_f28379d_dyno.h"
#include "rtwtypes.h"
#include "mcb_pmsm_foc_f28379d_dyno_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_mcb_pmsm_foc_f28379d_dy mcb_pmsm_foc_f28379d_dyno_B;

/* Block states (default storage) */
D_Work_mcb_pmsm_foc_f28379d_dyn mcb_pmsm_foc_f28379d_dyno_DWork;

/* Real-time model */
static RT_MODEL_mcb_pmsm_foc_f28379d_d mcb_pmsm_foc_f28379d_dyno_M_;
RT_MODEL_mcb_pmsm_foc_f28379d_d *const mcb_pmsm_foc_f28379d_dyno_M =
  &mcb_pmsm_foc_f28379d_dyno_M_;
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void mcb_pmsm_foc_f28379d_dyno_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_f28379d_dyno_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_f28379d_dyno_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (mcb_pmsm_foc_f28379d_dyno_M->Timing.TaskCounters.TID[1])++;
  if ((mcb_pmsm_foc_f28379d_dyno_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.0005s, 0.0s] */
    mcb_pmsm_foc_f28379d_dyno_M->Timing.TaskCounters.TID[1] = 0;
  }

  (mcb_pmsm_foc_f28379d_dyno_M->Timing.TaskCounters.TID[2])++;
  if ((mcb_pmsm_foc_f28379d_dyno_M->Timing.TaskCounters.TID[2]) > 19999) {/* Sample time: [0.5s, 0.0s] */
    mcb_pmsm_foc_f28379d_dyno_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S27>/Two phase CRL wrap'
 *    '<S265>/Two phase CRL wrap'
 */
void mcb_pmsm_fo_TwophaseCRLwrap(real32_T rtu_a, real32_T rtu_b,
  rtB_TwophaseCRLwrap_mcb_pmsm_fo *localB)
{
  /* Sum: '<S28>/a_plus_2b' */
  localB->a_plus_2b = (rtu_a + rtu_b) + rtu_b;

  /* Gain: '<S28>/one_by_sqrt3' */
  localB->one_by_sqrt3 = 0.577350259F * localB->a_plus_2b;

  /* AlgorithmDescriptorDelegate generated from: '<S28>/a16' */
  localB->algDD_o1 = rtu_a;

  /* AlgorithmDescriptorDelegate generated from: '<S28>/a16' */
  localB->algDD_o2 = localB->one_by_sqrt3;
}

/*
 * Output and update for action system:
 *    '<S43>/limitRef2'
 *    '<S281>/limitRef2'
 *    '<S582>/limitRef2'
 *    '<S659>/limitRef2'
 */
void mcb_pmsm_foc_f283_limitRef2(real32_T rtu_ref2satsquare, real32_T rtu_ref2,
  real32_T *rty_ref2sat, rtB_limitRef2_mcb_pmsm_foc_f283 *localB)
{
  /* Switch: '<S45>/Switch1' */
  if (rtu_ref2satsquare > 0.0F) {
    /* Switch: '<S45>/Switch1' */
    localB->Switch1 = rtu_ref2satsquare;
  } else {
    /* Switch: '<S45>/Switch1' incorporates:
     *  Constant: '<S45>/Constant'
     */
    localB->Switch1 = 0.0F;
  }

  /* End of Switch: '<S45>/Switch1' */

  /* Sqrt: '<S45>/Sqrt' */
  localB->Sqrt = (real32_T)sqrt(localB->Switch1);

  /* Switch: '<S45>/Switch' */
  if (rtu_ref2 >= 0.0F) {
    *rty_ref2sat = localB->Sqrt;
  } else {
    /* Gain: '<S45>/Gain' */
    localB->Gain = -localB->Sqrt;
    *rty_ref2sat = localB->Gain;
  }

  /* End of Switch: '<S45>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S29>/D//Q Axis Priority'
 *    '<S267>/D//Q Axis Priority'
 */
void mcb_pmsm_foc_DQAxisPriority(real32_T rtu_dqRef, real32_T rtu_dqRef_e,
  real32_T rtu_satLim, real32_T rtu_satLimSq, uint16_T rtu_satMethod, real32_T
  rty_dqSat[2], rtB_DQAxisPriority_mcb_pmsm_foc *localB)
{
  /* RelationalOperator: '<S39>/Compare' incorporates:
   *  Constant: '<S39>/Constant'
   */
  localB->Compare = (rtu_satMethod == 1U);

  /* RelationalOperator: '<S40>/Compare' incorporates:
   *  Constant: '<S40>/Constant'
   */
  localB->Compare_n = (rtu_satMethod == 1U);

  /* Switch: '<S34>/Switch' */
  if (localB->Compare) {
    /* Switch: '<S34>/Switch' */
    localB->Switch[0] = rtu_dqRef;
    localB->Switch[1] = rtu_dqRef_e;
  } else {
    /* Switch: '<S34>/Switch' */
    localB->Switch[0] = rtu_dqRef_e;
    localB->Switch[1] = rtu_dqRef;
  }

  /* End of Switch: '<S34>/Switch' */

  /* RelationalOperator: '<S44>/LowerRelop1' */
  localB->LowerRelop1 = (localB->Switch[0] > rtu_satLim);

  /* Switch: '<S44>/Switch2' */
  if (localB->LowerRelop1) {
    /* Switch: '<S44>/Switch2' */
    localB->Switch2 = rtu_satLim;
  } else {
    /* Gain: '<S43>/Gain' */
    localB->Gain = -rtu_satLim;

    /* RelationalOperator: '<S44>/UpperRelop' */
    localB->UpperRelop = (localB->Switch[0] < localB->Gain);

    /* Switch: '<S44>/Switch' */
    if (localB->UpperRelop) {
      /* Switch: '<S44>/Switch' */
      localB->Switch_l = localB->Gain;
    } else {
      /* Switch: '<S44>/Switch' */
      localB->Switch_l = localB->Switch[0];
    }

    /* End of Switch: '<S44>/Switch' */

    /* Switch: '<S44>/Switch2' */
    localB->Switch2 = localB->Switch_l;
  }

  /* End of Switch: '<S44>/Switch2' */

  /* Product: '<S43>/Product' */
  localB->Product = localB->Switch2 * localB->Switch2;

  /* Sum: '<S43>/Sum' */
  localB->Sum = rtu_satLimSq - localB->Product;

  /* Product: '<S43>/Product2' */
  localB->Product2 = localB->Switch[1] * localB->Switch[1];

  /* RelationalOperator: '<S43>/Relational Operator' */
  localB->RelationalOperator = (localB->Sum >= localB->Product2);

  /* DataTypeConversion: '<S43>/Data Type Conversion' */
  localB->DataTypeConversion = localB->RelationalOperator;

  /* If: '<S43>/If' */
  if (localB->DataTypeConversion != 0U) {
    /* Outputs for IfAction SubSystem: '<S43>/passThrough' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    /* Merge: '<S43>/Merge' incorporates:
     *  SignalConversion generated from: '<S46>/ref2'
     */
    localB->Merge = localB->Switch[1];

    /* End of Outputs for SubSystem: '<S43>/passThrough' */
  } else {
    /* Outputs for IfAction SubSystem: '<S43>/limitRef2' incorporates:
     *  ActionPort: '<S45>/Action Port'
     */
    mcb_pmsm_foc_f283_limitRef2(localB->Sum, localB->Switch[1], &localB->Merge,
      &localB->limitRef2);

    /* End of Outputs for SubSystem: '<S43>/limitRef2' */
  }

  /* End of If: '<S43>/If' */

  /* Switch: '<S34>/Switch1' */
  if (localB->Compare_n) {
    rty_dqSat[0] = localB->Switch2;
    rty_dqSat[1] = localB->Merge;
  } else {
    rty_dqSat[0] = localB->Merge;
    rty_dqSat[1] = localB->Switch2;
  }

  /* End of Switch: '<S34>/Switch1' */
}

/*
 * Output and update for action system:
 *    '<S29>/D-Q Equivalence'
 *    '<S267>/D-Q Equivalence'
 *    '<S569>/D-Q Equivalence'
 *    '<S646>/D-Q Equivalence'
 */
void mcb_pmsm_foc__DQEquivalence(real32_T rtu_dqRef, real32_T rtu_dqRef_d,
  real32_T rtu_magSquare, real32_T rtu_satLim, real32_T rtu_satLimSq, real32_T
  rty_dqSat[2], rtB_DQEquivalence_mcb_pmsm_foc_ *localB)
{
  /* RelationalOperator: '<S33>/Relational Operator' */
  localB->RelationalOperator = (rtu_magSquare > rtu_satLimSq);

  /* DataTypeConversion: '<S33>/Data Type Conversion' */
  localB->DataTypeConversion = localB->RelationalOperator;

  /* If: '<S33>/If' */
  if (localB->DataTypeConversion != 0U) {
    /* Outputs for IfAction SubSystem: '<S33>/Limiter' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    /* Product: '<S37>/Product' */
    localB->Product[0] = rtu_dqRef * rtu_satLim;
    localB->Product[1] = rtu_dqRef_d * rtu_satLim;

    /* Sqrt: '<S37>/Square Root' */
    localB->SquareRoot = (real32_T)sqrt(rtu_magSquare);

    /* Switch: '<S37>/Switch' */
    if (localB->SquareRoot != 0.0F) {
      /* Switch: '<S37>/Switch' */
      localB->Switch = localB->SquareRoot;
    } else {
      /* Switch: '<S37>/Switch' incorporates:
       *  Constant: '<S37>/Constant'
       */
      localB->Switch = 1.0F;
    }

    /* End of Switch: '<S37>/Switch' */

    /* Product: '<S37>/Divide' */
    rty_dqSat[0] = localB->Product[0] / localB->Switch;
    rty_dqSat[1] = localB->Product[1] / localB->Switch;

    /* End of Outputs for SubSystem: '<S33>/Limiter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S33>/Passthrough' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    /* SignalConversion generated from: '<S38>/dqRef' */
    rty_dqSat[0] = rtu_dqRef;
    rty_dqSat[1] = rtu_dqRef_d;

    /* End of Outputs for SubSystem: '<S33>/Passthrough' */
  }

  /* End of If: '<S33>/If' */
}

/*
 * System initialize for atomic system:
 *    '<S30>/MATLAB Function'
 *    '<S268>/MATLAB Function'
 */
void mcb_pms_MATLABFunction_Init(rtDW_MATLABFunction_mcb_pmsm_fo *localDW)
{
  localDW->integrator_state = 0.0F;
}

/*
 * System reset for atomic system:
 *    '<S30>/MATLAB Function'
 *    '<S268>/MATLAB Function'
 */
void mcb_pm_MATLABFunction_Reset(rtDW_MATLABFunction_mcb_pmsm_fo *localDW)
{
  localDW->integrator_state = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S30>/MATLAB Function'
 *    '<S268>/MATLAB Function'
 */
void mcb_pmsm_foc_MATLABFunction(real32_T rtu_e, real32_T rtu_P, real32_T
  rtu_I_Ts_speed, boolean_T rtu_reset, real32_T rtu_Id0, real_T
  rtu_saturation_limit, rtB_MATLABFunction_mcb_pmsm_foc *localB,
  rtDW_MATLABFunction_mcb_pmsm_fo *localDW)
{
  real32_T V_d_ref_unsat;
  real32_T integrator_state_tmp;
  real32_T u1;
  real32_T u1_0;

  /* MATLAB Function 'Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/MATLAB Function': '<S48>:1' */
  if (rtu_reset) {
    /* '<S48>:1:21' */
    /* '<S48>:1:22' */
    localDW->integrator_state = rtu_Id0;
  }

  /* '<S48>:1:26' */
  /* '<S48>:1:29' */
  integrator_state_tmp = rtu_I_Ts_speed * rtu_e;
  localDW->integrator_state += integrator_state_tmp;

  /* '<S48>:1:32' */
  V_d_ref_unsat = rtu_P * rtu_e + localDW->integrator_state;

  /* '<S48>:1:35' */
  u1 = (real32_T)rtu_saturation_limit;
  if ((V_d_ref_unsat <= u1) || rtIsNaNF(u1)) {
    u1 = V_d_ref_unsat;
  }

  u1_0 = (real32_T)-rtu_saturation_limit;
  if ((u1 >= u1_0) || rtIsNaNF(u1_0)) {
    localB->V_d_ref = u1;
  } else {
    localB->V_d_ref = u1_0;
  }

  if (localB->V_d_ref != V_d_ref_unsat) {
    /* '<S48>:1:38' */
    /* '<S48>:1:39' */
    localDW->integrator_state -= integrator_state_tmp;
  }
}

/*
 * System initialize for atomic system:
 *    '<S31>/MATLAB Function'
 *    '<S269>/MATLAB Function'
 */
void mcb_p_MATLABFunction_a_Init(rtDW_MATLABFunction_mcb_pmsm__a *localDW)
{
  localDW->integrator_state = 0.0F;
}

/*
 * System reset for atomic system:
 *    '<S31>/MATLAB Function'
 *    '<S269>/MATLAB Function'
 */
void mcb__MATLABFunction_c_Reset(rtDW_MATLABFunction_mcb_pmsm__a *localDW)
{
  localDW->integrator_state = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S31>/MATLAB Function'
 *    '<S269>/MATLAB Function'
 */
void mcb_pmsm_f_MATLABFunction_j(real32_T rtu_e, real32_T rtu_P, real32_T
  rtu_I_Ts_speed, boolean_T rtu_reset, real32_T rtu_Iq0, real_T
  rtu_saturation_limit, rtB_MATLABFunction_mcb_pmsm_f_o *localB,
  rtDW_MATLABFunction_mcb_pmsm__a *localDW)
{
  real32_T V_q_ref_unsat;
  real32_T integrator_state_tmp;
  real32_T u1;
  real32_T u1_0;

  /* MATLAB Function 'Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/MATLAB Function': '<S104>:1' */
  if (rtu_reset) {
    /* '<S104>:1:21' */
    /* '<S104>:1:22' */
    localDW->integrator_state = rtu_Iq0;
  }

  /* '<S104>:1:26' */
  /* '<S104>:1:29' */
  integrator_state_tmp = rtu_I_Ts_speed * rtu_e;
  localDW->integrator_state += integrator_state_tmp;

  /* '<S104>:1:32' */
  V_q_ref_unsat = rtu_P * rtu_e + localDW->integrator_state;

  /* '<S104>:1:35' */
  u1 = (real32_T)rtu_saturation_limit;
  if ((V_q_ref_unsat <= u1) || rtIsNaNF(u1)) {
    u1 = V_q_ref_unsat;
  }

  u1_0 = (real32_T)-rtu_saturation_limit;
  if ((u1 >= u1_0) || rtIsNaNF(u1_0)) {
    localB->V_q_ref = u1;
  } else {
    localB->V_q_ref = u1_0;
  }

  if (localB->V_q_ref != V_q_ref_unsat) {
    /* '<S104>:1:38' */
    /* '<S104>:1:39' */
    localDW->integrator_state -= integrator_state_tmp;
  }
}

/*
 * Output and update for atomic system:
 *    '<S22>/Two inputs CRL'
 *    '<S190>/Two inputs CRL'
 *    '<S260>/Two inputs CRL'
 *    '<S666>/Two inputs CRL'
 */
void mcb_pmsm_foc_f_TwoinputsCRL(real32_T rtu_Ds, real32_T rtu_Qs, real32_T
  rtu_sin, real32_T rtu_cos, rtB_TwoinputsCRL_mcb_pmsm_foc_f *localB)
{
  /* Product: '<S164>/qcos' */
  localB->qcos = rtu_Qs * rtu_cos;

  /* Product: '<S164>/dsin' */
  localB->dsin = rtu_Ds * rtu_sin;

  /* Sum: '<S164>/sum_beta' */
  localB->sum_beta = localB->qcos + localB->dsin;

  /* Product: '<S164>/dcos' */
  localB->dcos = rtu_Ds * rtu_cos;

  /* Product: '<S164>/qsin' */
  localB->qsin = rtu_Qs * rtu_sin;

  /* Sum: '<S164>/sum_alpha' */
  localB->sum_alpha = localB->dcos - localB->qsin;

  /* Switch: '<S165>/Switch' */
  localB->Switch[0] = localB->sum_alpha;
  localB->Switch[1] = localB->sum_beta;

  /* AlgorithmDescriptorDelegate generated from: '<S164>/a16' */
  localB->algDD_o1 = localB->Switch[0];

  /* AlgorithmDescriptorDelegate generated from: '<S164>/a16' */
  localB->algDD_o2 = localB->Switch[1];
}

/*
 * Output and update for atomic system:
 *    '<S24>/Two inputs CRL'
 *    '<S262>/Two inputs CRL'
 */
void mcb_pmsm_foc_TwoinputsCRL_o(real32_T rtu_Alpha, real32_T rtu_Beta, real32_T
  rtu_sine, real32_T rtu_cos, rtB_TwoinputsCRL_mcb_pmsm_foc_i *localB)
{
  /* Product: '<S169>/acos' */
  localB->acos_l = rtu_Alpha * rtu_cos;

  /* Product: '<S169>/bsin' */
  localB->bsin = rtu_Beta * rtu_sine;

  /* Sum: '<S169>/sum_Ds' */
  localB->sum_Ds = localB->acos_l + localB->bsin;

  /* Product: '<S169>/bcos' */
  localB->bcos = rtu_Beta * rtu_cos;

  /* Product: '<S169>/asin' */
  localB->asin_d = rtu_Alpha * rtu_sine;

  /* Sum: '<S169>/sum_Qs' */
  localB->sum_Qs = localB->bcos - localB->asin_d;

  /* Switch: '<S170>/Switch' */
  localB->Switch[0] = localB->sum_Ds;
  localB->Switch[1] = localB->sum_Qs;

  /* AlgorithmDescriptorDelegate generated from: '<S169>/a16' */
  localB->algDD_o1 = localB->Switch[0];

  /* AlgorithmDescriptorDelegate generated from: '<S169>/a16' */
  localB->algDD_o2 = localB->Switch[1];
}

/*
 * Output and update for action system:
 *    '<S173>/If Action Subsystem'
 *    '<S197>/If Action Subsystem'
 *    '<S414>/If Action Subsystem'
 *    '<S672>/If Action Subsystem'
 */
void mcb_pmsm__IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem_mcb_pmsm_ *localB)
{
  /* DataTypeConversion: '<S176>/Convert_uint16' */
  localB->Convert_uint16 = (int16_T)(real32_T)floor(rtu_In1);

  /* DataTypeConversion: '<S176>/Convert_back' */
  localB->Convert_back = localB->Convert_uint16;

  /* Sum: '<S176>/Sum' */
  *rty_Out1 = rtu_In1 - localB->Convert_back;
}

/*
 * Output and update for action system:
 *    '<S173>/If Action Subsystem1'
 *    '<S197>/If Action Subsystem1'
 *    '<S414>/If Action Subsystem1'
 *    '<S672>/If Action Subsystem1'
 */
void mcb_pmsm_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem1_mcb_pmsm *localB)
{
  /* DataTypeConversion: '<S177>/Convert_uint16' */
  localB->Convert_uint16 = (int16_T)rtu_In1;

  /* DataTypeConversion: '<S177>/Convert_back' */
  localB->Convert_back = localB->Convert_uint16;

  /* Sum: '<S177>/Sum' */
  *rty_Out1 = rtu_In1 - localB->Convert_back;
}

/*
 * Output and update for action system:
 *    '<S220>/If Action Subsystem'
 *    '<S443>/If Action Subsystem'
 */
void mcb_pms_IfActionSubsystem_a(real32_T rtu_m, real32_T rtu_Offset, real32_T
  *rty_m_out)
{
  /* Sum: '<S222>/Add' incorporates:
   *  Constant: '<S222>/Constant'
   */
  *rty_m_out = (rtu_m + 1.0F) - rtu_Offset;
}

/*
 * Output and update for action system:
 *    '<S211>/PositionNoReset'
 *    '<S436>/PositionNoReset'
 */
void mcb_pmsm_fo_PositionNoReset(uint16_T rtu_Index, uint16_T rtu_Count,
  uint16_T *rty_Position, rtB_PositionNoReset_mcb_pmsm_fo *localB)
{
  uint16_T u0;
  uint16_T u1;

  /* Sum: '<S227>/Sum3' */
  localB->Sum3 = rtu_Count - rtu_Index;

  /* Sum: '<S227>/Sum7' incorporates:
   *  Constant: '<S232>/Constant'
   */
  localB->Sum7 = localB->Sum3 + 4000U;

  /* MinMax: '<S227>/MinMax' */
  u0 = localB->Sum3;
  u1 = localB->Sum7;
  if (u0 <= u1) {
    u1 = u0;
  }

  *rty_Position = u1;

  /* End of MinMax: '<S227>/MinMax' */
}

/* System initialize for function-call system: '<Root>/Current control for motor1' */
void Currentcontrolformotor_Init(void)
{
  /* Start for S-Function (c280xqep): '<S205>/eQEP' */
  config_QEP_eQEP1((uint32_T)65535U,(uint32_T)0, (uint32_T)0, (uint32_T)0,
                   (uint16_T)0, (uint16_T)448, (uint16_T)8232, (uint16_T)32768,
                   (uint16_T)119,(uint16_T)0);

  /* Start for S-Function (c2802xadc): '<S205>/ADC_C_IN2' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S205>/ADC_B_IN2' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c280xgpio_do): '<S238>/Inverter enable' */
  EALLOW;
  GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
  GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S238>/ePWM1' */
  real32_T tbprdValue1 = (real32_T)EPwm1Regs.TBPRD;

  /*** Initialize ePWM1 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 1U;          -- Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          -- Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x12U;
    EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm1Regs.CMPA.bit.CMPA = 2500U;   // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 2500U;   // Counter Compare B Register
    EPwm1Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm1Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          -- Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM1SOC Period Select
       EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM1SOCB Period Select
       EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM1INTn Period Select
       EPwm1Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7FU) | 0x1A01U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S238>/ePWM2' */
  real32_T tbprdValue2 = (real32_T)EPwm2Regs.TBPRD;

  /*** Initialize ePWM2 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm2Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm2Regs.TBCTL2.all = (EPwm2Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm2Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm2Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm2Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm2Regs.CMPCTL2.all = (EPwm2Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm2Regs.CMPA.bit.CMPA = 2500U;   // Counter Compare A Register
    EPwm2Regs.CMPB.bit.CMPB = 2500U;   // Counter Compare B Register
    EPwm2Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm2Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm2Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm2Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm2Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm2Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM2SOC Period Select
       EPwm2Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM2SOCB Period Select
       EPwm2Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM2INTn Period Select
       EPwm2Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm2Regs.ETSOCPS.all = (EPwm2Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm2Regs.ETINTPS.all = (EPwm2Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm2Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm2Regs.EPWMXLINK.bit.TBPRDLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPALINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPBLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPCLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPDLINK = 1U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm2Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm2Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm2Regs.HRPCTL.all = (EPwm2Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S238>/ePWM3' */
  real32_T tbprdValue3 = (real32_T)EPwm3Regs.TBPRD;

  /*** Initialize ePWM3 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm3Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm3Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm3Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm3Regs.TBCTL2.all = (EPwm3Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm3Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm3Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm3Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm3Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm3Regs.CMPCTL2.all = (EPwm3Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm3Regs.CMPA.bit.CMPA = 2500U;   // Counter Compare A Register
    EPwm3Regs.CMPB.bit.CMPB = 2500U;   // Counter Compare B Register
    EPwm3Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm3Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm3Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm3Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm3Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm3Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm3Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm3Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm3Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm3Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm3Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm3Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm3Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM3SOC Period Select
       EPwm3Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM3SOCB Period Select
       EPwm3Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM3INTn Period Select
       EPwm3Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm3Regs.ETSOCPS.all = (EPwm3Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm3Regs.ETINTPS.all = (EPwm3Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm3Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm3Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm3Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm3Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm3Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm3Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM3A
       EPwm3Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM3B
       EPwm3Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM3A action on DCAEVT1
       EPwm3Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM3A action on DCAEVT2
       EPwm3Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM3B action on DCBEVT1
       EPwm3Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM3B action on DCBEVT2
     */
    EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm3Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm3Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm3Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm3Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm3Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm3Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm3Regs.DCACTL.all = (EPwm3Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm3Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm3Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm3Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm3Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm3Regs.DCBCTL.all = (EPwm3Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm3Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm3Regs.DCTRIPSEL.all = (EPwm3Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm3Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm3Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm3Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm3Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm3Regs.TZDCSEL.all = (EPwm3Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm3Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm3Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm3Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm3Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm3Regs.DCFCTL.all = (EPwm3Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm3Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm3Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm3Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm3Regs.DCCAPCTL.all = (EPwm3Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm3Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm3Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm3Regs.HRCNFG.all = (EPwm3Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm3Regs.EPWMXLINK.bit.TBPRDLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPALINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPBLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPCLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPDLINK = 2U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm3Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm3Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm3Regs.HRPCTL.all = (EPwm3Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* InitializeConditions for Delay: '<S212>/Delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx_l = 0U;

  /* SystemInitialize for Enabled SubSystem: '<S10>/Closed Loop Control' */

  /* SystemInitialize for MATLAB Function: '<S30>/MATLAB Function' */
  mcb_pms_MATLABFunction_Init(&mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction);

  /* SystemInitialize for MATLAB Function: '<S31>/MATLAB Function' */
  mcb_p_MATLABFunction_a_Init
    (&mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction_j);

  /* End of SystemInitialize for SubSystem: '<S10>/Closed Loop Control' */
}

/* System reset for function-call system: '<Root>/Current control for motor1' */
void Currentcontrolformoto_Reset(void)
{
  /* InitializeConditions for Delay: '<S212>/Delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx_l = 0U;
}

/* Disable for function-call system: '<Root>/Current control for motor1' */
#pragma CODE_SECTION (Currentcontrolformo_Disable, "ramfuncs")

void Currentcontrolformo_Disable(void)
{
  /* Disable for Enabled SubSystem: '<S10>/Open Loop Start-Up' */
  if (mcb_pmsm_foc_f28379d_dyno_DWork.OpenLoopStartUp_MODE) {
    /* Disable for DiscreteIntegrator: '<S188>/Ramp Generator' */
    mcb_pmsm_foc_f28379d_dyno_DWork.RampGenerator_DSTATE =
      mcb_pmsm_foc_f28379d_dyno_B.Eps;
    mcb_pmsm_foc_f28379d_dyno_DWork.OpenLoopStartUp_MODE = false;
  }

  /* End of Disable for SubSystem: '<S10>/Open Loop Start-Up' */
}

/* Output and update for function-call system: '<Root>/Current control for motor1' */
#pragma CODE_SECTION (mcb_Currentcontrolformotor1, "ramfuncs")

void mcb_Currentcontrolformotor1(void)
{
  real32_T Bias;
  real32_T u0;
  uint32_T Sum_j;
  int16_T i;
  uint16_T Scale_to_PWM_Counter_PRD_g;

  /* S-Function (c280xqep): '<S205>/eQEP' */
  {
    mcb_pmsm_foc_f28379d_dyno_B.eQEP_o1_b = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/
    mcb_pmsm_foc_f28379d_dyno_B.eQEP_o2_a = EQep1Regs.QPOSILAT;
         /* The position-counter value is latched into this register on an IEL*/
  }

  /* Delay: '<S206>/Delay' */
  mcb_pmsm_foc_f28379d_dyno_B.Delay_f =
    mcb_pmsm_foc_f28379d_dyno_DWork.Delay_DSTATE_c;

  /* Logic: '<S206>/NOT' */
  mcb_pmsm_foc_f28379d_dyno_B.NOT_o = !mcb_pmsm_foc_f28379d_dyno_B.Delay_f;

  /* Outputs for Enabled SubSystem: '<S206>/IndexFinder' incorporates:
   *  EnablePort: '<S209>/Enable'
   */
  if (mcb_pmsm_foc_f28379d_dyno_B.NOT_o) {
    /* Delay: '<S209>/Delay3' */
    mcb_pmsm_foc_f28379d_dyno_B.Delay3 =
      mcb_pmsm_foc_f28379d_dyno_DWork.Delay3_DSTATE;

    /* RelationalOperator: '<S216>/Compare' incorporates:
     *  Constant: '<S216>/Constant'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Compare_mq = (mcb_pmsm_foc_f28379d_dyno_B.Delay3
      == 0U);

    /* RelationalOperator: '<S217>/Compare' incorporates:
     *  Constant: '<S217>/Constant'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Compare_n =
      (mcb_pmsm_foc_f28379d_dyno_B.eQEP_o2_a > 0U);

    /* Logic: '<S209>/AND' */
    mcb_pmsm_foc_f28379d_dyno_B.AND_a = (mcb_pmsm_foc_f28379d_dyno_B.Compare_mq &&
      mcb_pmsm_foc_f28379d_dyno_B.Compare_n);

    /* Update for Delay: '<S209>/Delay3' */
    mcb_pmsm_foc_f28379d_dyno_DWork.Delay3_DSTATE =
      mcb_pmsm_foc_f28379d_dyno_B.eQEP_o2_a;
  }

  /* End of Outputs for SubSystem: '<S206>/IndexFinder' */

  /* DataStoreWrite: '<S10>/Data Store Write' */
  mcb_pmsm_foc_f28379d_dyno_DWork.EnClosedLoop =
    mcb_pmsm_foc_f28379d_dyno_B.AND_a;

  /* DataStoreRead: '<S207>/Data Store Read1' */
  mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_e =
    mcb_pmsm_foc_f28379d_dyno_DWork.IaOffset_motor1;

  /* DataStoreRead: '<S207>/Data Store Read2' */
  mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead2_k =
    mcb_pmsm_foc_f28379d_dyno_DWork.IbOffset_motor1;

  /* S-Function (c2802xadc): '<S205>/ADC_C_IN2' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_f28379d_dyno_B.ADC_C_IN2 = (AdccResultRegs.ADCRESULT0);
  }

  /* S-Function (c2802xadc): '<S205>/ADC_B_IN2' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_f28379d_dyno_B.ADC_B_IN2 = (AdcbResultRegs.ADCRESULT0);
  }

  /* DataTypeConversion: '<S207>/Data Type Conversion' */
  mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_a[0] =
    mcb_pmsm_foc_f28379d_dyno_B.ADC_C_IN2;
  mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_a[1] =
    mcb_pmsm_foc_f28379d_dyno_B.ADC_B_IN2;

  /* Sum: '<S207>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_l[0] =
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_a[0] -
    mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_e;
  mcb_pmsm_foc_f28379d_dyno_B.Add_l[1] =
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_a[1] -
    mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead2_k;

  /* Gain: '<S237>/Get ADC Voltage' */
  Bias = 0.000732600747F * (real32_T)mcb_pmsm_foc_f28379d_dyno_B.Add_l[0];
  mcb_pmsm_foc_f28379d_dyno_B.GetADCVoltage_b[0] = Bias;

  /* Gain: '<S237>/Get Currents' */
  Bias *= 10.0F;
  mcb_pmsm_foc_f28379d_dyno_B.GetCurrents_n[0] = Bias;

  /* Gain: '<S237>/PU_Conversion' */
  Bias *= 0.0666666701F;
  mcb_pmsm_foc_f28379d_dyno_B.PU_Conversion_d[0] = Bias;

  /* Gain: '<S207>/Inverting // Non-inverting  Current measurement  amplifieer' */
  mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentm_h[0] = -Bias;

  /* Gain: '<S237>/Get ADC Voltage' */
  Bias = 0.000732600747F * (real32_T)mcb_pmsm_foc_f28379d_dyno_B.Add_l[1];
  mcb_pmsm_foc_f28379d_dyno_B.GetADCVoltage_b[1] = Bias;

  /* Gain: '<S237>/Get Currents' */
  Bias *= 10.0F;
  mcb_pmsm_foc_f28379d_dyno_B.GetCurrents_n[1] = Bias;

  /* Gain: '<S237>/PU_Conversion' */
  Bias *= 0.0666666701F;
  mcb_pmsm_foc_f28379d_dyno_B.PU_Conversion_d[1] = Bias;

  /* Gain: '<S207>/Inverting // Non-inverting  Current measurement  amplifieer' */
  mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentm_h[1] = -Bias;

  /* Outputs for IfAction SubSystem: '<S211>/PositionNoReset' incorporates:
   *  ActionPort: '<S227>/Action Port'
   */
  /* If: '<S211>/If1' */
  mcb_pmsm_fo_PositionNoReset(mcb_pmsm_foc_f28379d_dyno_B.eQEP_o2_a,
    mcb_pmsm_foc_f28379d_dyno_B.eQEP_o1_b, &mcb_pmsm_foc_f28379d_dyno_B.Merge_p,
    &mcb_pmsm_foc_f28379d_dyno_B.PositionNoReset);

  /* End of Outputs for SubSystem: '<S211>/PositionNoReset' */

  /* DataTypeConversion: '<S230>/DTC' */
  mcb_pmsm_foc_f28379d_dyno_B.DTC_i = mcb_pmsm_foc_f28379d_dyno_B.Merge_p;

  /* Product: '<S211>/Product' incorporates:
   *  Constant: '<S233>/Constant'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Product_ie = mcb_pmsm_foc_f28379d_dyno_B.DTC_i *
    0.00025F;

  /* Gain: '<S212>/PositionToCount' */
  mcb_pmsm_foc_f28379d_dyno_B.PositionToCount_n = (uint32_T)(4.2949673E+9F *
    mcb_pmsm_foc_f28379d_dyno_B.Product_ie);

  /* Delay: '<S212>/Delay' */
  mcb_pmsm_foc_f28379d_dyno_B.Delay_o =
    mcb_pmsm_foc_f28379d_dyno_DWork.Delay_DSTATE_d[mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx_l];

  /* Sum: '<S212>/SpeedCount' */
  mcb_pmsm_foc_f28379d_dyno_B.SpeedCount_m = (int32_T)
    mcb_pmsm_foc_f28379d_dyno_B.PositionToCount_n - (int32_T)
    mcb_pmsm_foc_f28379d_dyno_B.Delay_o;

  /* DataTypeConversion: '<S235>/DTC' */
  mcb_pmsm_foc_f28379d_dyno_B.DTC_a = (real32_T)
    mcb_pmsm_foc_f28379d_dyno_B.SpeedCount_m;

  /* Gain: '<S212>/SpeedGain' */
  mcb_pmsm_foc_f28379d_dyno_B.SpeedGain_f = 3.43915274E-9F *
    mcb_pmsm_foc_f28379d_dyno_B.DTC_a;

  /* Switch: '<S208>/Switch1' incorporates:
   *  Constant: '<S208>/FilterConstant'
   *  Constant: '<S208>/OneMinusFilterConstant'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Switch1_i[0] = 0.01F;
  mcb_pmsm_foc_f28379d_dyno_B.Switch1_i[1] = 0.99F;

  /* Product: '<S215>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_fp =
    mcb_pmsm_foc_f28379d_dyno_B.SpeedGain_f * 0.01F;

  /* UnitDelay: '<S215>/Unit Delay' */
  mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_eq =
    mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_az;

  /* Product: '<S215>/Product1' */
  mcb_pmsm_foc_f28379d_dyno_B.Product1_m = 0.99F *
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_eq;

  /* Sum: '<S215>/Add1' */
  mcb_pmsm_foc_f28379d_dyno_B.Add1_g = mcb_pmsm_foc_f28379d_dyno_B.Product_fp +
    mcb_pmsm_foc_f28379d_dyno_B.Product1_m;

  /* Switch: '<S219>/Switch' incorporates:
   *  Constant: '<S13>/IndexOffset'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Switch_e = 0.0783F;

  /* If: '<S220>/If' */
  if (mcb_pmsm_foc_f28379d_dyno_B.Product_ie <= 0.0783F) {
    /* Outputs for IfAction SubSystem: '<S220>/If Action Subsystem' incorporates:
     *  ActionPort: '<S222>/Action Port'
     */
    mcb_pms_IfActionSubsystem_a(mcb_pmsm_foc_f28379d_dyno_B.Product_ie, 0.0783F,
      &mcb_pmsm_foc_f28379d_dyno_B.Merge_n);

    /* End of Outputs for SubSystem: '<S220>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S220>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S223>/Action Port'
     */
    /* Merge: '<S220>/Merge' incorporates:
     *  Sum: '<S223>/Add'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Merge_n = mcb_pmsm_foc_f28379d_dyno_B.Product_ie
      - 0.0783F;

    /* End of Outputs for SubSystem: '<S220>/If Action Subsystem1' */
  }

  /* End of If: '<S220>/If' */

  /* Gain: '<S225>/Number of pole pairs' */
  mcb_pmsm_foc_f28379d_dyno_B.Numberofpolepairs_i = 4.0F *
    mcb_pmsm_foc_f28379d_dyno_B.Merge_n;

  /* Rounding: '<S221>/Floor' */
  mcb_pmsm_foc_f28379d_dyno_B.Floor_g = (real32_T)floor
    (mcb_pmsm_foc_f28379d_dyno_B.Numberofpolepairs_i);

  /* Sum: '<S221>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_nd =
    mcb_pmsm_foc_f28379d_dyno_B.Numberofpolepairs_i -
    mcb_pmsm_foc_f28379d_dyno_B.Floor_g;

  /* Outputs for Enabled SubSystem: '<S10>/Closed Loop Control' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (mcb_pmsm_foc_f28379d_dyno_B.AND_a) {
    /* Outputs for Atomic SubSystem: '<S27>/Two phase CRL wrap' */
    mcb_pmsm_fo_TwophaseCRLwrap
      (mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentm_h[0],
       mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentm_h[1],
       &mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap);

    /* End of Outputs for SubSystem: '<S27>/Two phase CRL wrap' */

    /* RelationalOperator: '<S175>/Compare' incorporates:
     *  Constant: '<S175>/Constant'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Compare_a4 = (mcb_pmsm_foc_f28379d_dyno_B.Add_nd
      < 0.0F);

    /* DataTypeConversion: '<S173>/Data Type Conversion' */
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_b =
      mcb_pmsm_foc_f28379d_dyno_B.Compare_a4;

    /* If: '<S173>/If' */
    if (mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_b > 0U) {
      /* Outputs for IfAction SubSystem: '<S173>/If Action Subsystem' incorporates:
       *  ActionPort: '<S176>/Action Port'
       */
      mcb_pmsm__IfActionSubsystem(mcb_pmsm_foc_f28379d_dyno_B.Add_nd,
        &mcb_pmsm_foc_f28379d_dyno_B.Merge_lj,
        &mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem_p);

      /* End of Outputs for SubSystem: '<S173>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S173>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S177>/Action Port'
       */
      mcb_pmsm_IfActionSubsystem1(mcb_pmsm_foc_f28379d_dyno_B.Add_nd,
        &mcb_pmsm_foc_f28379d_dyno_B.Merge_lj,
        &mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem1_k);

      /* End of Outputs for SubSystem: '<S173>/If Action Subsystem1' */
    }

    /* End of If: '<S173>/If' */

    /* Gain: '<S171>/indexing' */
    mcb_pmsm_foc_f28379d_dyno_B.indexing_l = 800.0F *
      mcb_pmsm_foc_f28379d_dyno_B.Merge_lj;

    /* DataTypeConversion: '<S171>/Get_Integer' */
    mcb_pmsm_foc_f28379d_dyno_B.Get_Integer_l = (uint16_T)
      mcb_pmsm_foc_f28379d_dyno_B.indexing_l;

    /* Sum: '<S171>/Sum' incorporates:
     *  Constant: '<S171>/offset'
     */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.Get_Integer_l + 1UL;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_j[0] = Sum_j;

    /* Selector: '<S171>/Lookup' incorporates:
     *  Constant: '<S171>/sine_table_values'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[0] =
      mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum_j];

    /* Sum: '<S171>/Sum' */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.Get_Integer_l;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_j[1] = Sum_j;

    /* Selector: '<S171>/Lookup' incorporates:
     *  Constant: '<S171>/sine_table_values'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[1] =
      mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum_j];

    /* Sum: '<S171>/Sum' incorporates:
     *  Constant: '<S171>/offset'
     */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.Get_Integer_l + 201UL;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_j[2] = Sum_j;

    /* Selector: '<S171>/Lookup' incorporates:
     *  Constant: '<S171>/sine_table_values'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[2] =
      mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum_j];

    /* Sum: '<S171>/Sum' incorporates:
     *  Constant: '<S171>/offset'
     */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.Get_Integer_l + 200UL;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_j[3] = Sum_j;

    /* Selector: '<S171>/Lookup' incorporates:
     *  Constant: '<S171>/sine_table_values'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[3] =
      mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum_j];

    /* Sum: '<S172>/Sum3' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum3_o = mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[0]
      - mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[1];

    /* DataTypeConversion: '<S171>/Data Type Conversion1' */
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion1_m =
      mcb_pmsm_foc_f28379d_dyno_B.Get_Integer_l;

    /* Sum: '<S171>/Sum2' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum2_f = mcb_pmsm_foc_f28379d_dyno_B.indexing_l
      - mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion1_m;

    /* Product: '<S172>/Product' */
    mcb_pmsm_foc_f28379d_dyno_B.Product_kl = mcb_pmsm_foc_f28379d_dyno_B.Sum3_o *
      mcb_pmsm_foc_f28379d_dyno_B.Sum2_f;

    /* Sum: '<S172>/Sum4' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum4_b = mcb_pmsm_foc_f28379d_dyno_B.Product_kl
      + mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[1];

    /* Sum: '<S172>/Sum5' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum5_h = mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[2]
      - mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[3];

    /* Product: '<S172>/Product1' */
    mcb_pmsm_foc_f28379d_dyno_B.Product1_iu = mcb_pmsm_foc_f28379d_dyno_B.Sum5_h
      * mcb_pmsm_foc_f28379d_dyno_B.Sum2_f;

    /* Sum: '<S172>/Sum6' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum6_m = mcb_pmsm_foc_f28379d_dyno_B.Product1_iu
      + mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[3];

    /* Outputs for Atomic SubSystem: '<S24>/Two inputs CRL' */
    mcb_pmsm_foc_TwoinputsCRL_o
      (mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap.algDD_o1,
       mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap.algDD_o2,
       mcb_pmsm_foc_f28379d_dyno_B.Sum4_b, mcb_pmsm_foc_f28379d_dyno_B.Sum6_m,
       &mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o);

    /* End of Outputs for SubSystem: '<S24>/Two inputs CRL' */

    /* Sum: '<S30>/Sum' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum_c = mcb_pmsm_foc_f28379d_dyno_B.RT2[0] -
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.algDD_o1;

    /* DataStoreRead: '<S30>/Data Store Read1' */
    mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_iy =
      mcb_pmsm_foc_f28379d_dyno_DWork.EnMtrCtrl;

    /* Logic: '<S30>/Logical Operator' */
    mcb_pmsm_foc_f28379d_dyno_B.LogicalOperator_m =
      !mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_iy;

    /* MATLAB Function: '<S30>/MATLAB Function' incorporates:
     *  Constant: '<S30>/Constant'
     *  Constant: '<S30>/Ki'
     *  Constant: '<S30>/Ki1'
     *  Constant: '<S30>/Kp'
     */
    mcb_pmsm_foc_MATLABFunction(mcb_pmsm_foc_f28379d_dyno_B.Sum_c, 1.44F,
      0.2025F, mcb_pmsm_foc_f28379d_dyno_B.LogicalOperator_m, 0.0F, 1.0,
      &mcb_pmsm_foc_f28379d_dyno_B.sf_MATLABFunction,
      &mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction);

    /* Gain: '<S160>/wm_pu2si_mech2elec' */
    mcb_pmsm_foc_f28379d_dyno_B.we_n = 4.0F * mcb_pmsm_foc_f28379d_dyno_B.Add1_g;

    /* Product: '<S160>/prod1' */
    mcb_pmsm_foc_f28379d_dyno_B.w_Lq_iq_b =
      mcb_pmsm_foc_f28379d_dyn_ConstB.Switch1_b *
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.algDD_o2 *
      mcb_pmsm_foc_f28379d_dyno_B.we_n;

    /* Gain: '<S160>/NegSign' */
    mcb_pmsm_foc_f28379d_dyno_B.VdFF_unsat_o =
      -mcb_pmsm_foc_f28379d_dyno_B.w_Lq_iq_b;

    /* RelationalOperator: '<S162>/LowerRelop1' */
    mcb_pmsm_foc_f28379d_dyno_B.LowerRelop1_l =
      (mcb_pmsm_foc_f28379d_dyno_B.VdFF_unsat_o >
       mcb_pmsm_foc_f28379d_dyn_ConstB.Switch_d);

    /* Switch: '<S162>/Switch2' */
    if (mcb_pmsm_foc_f28379d_dyno_B.LowerRelop1_l) {
      /* Switch: '<S162>/Switch2' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch2_o =
        mcb_pmsm_foc_f28379d_dyn_ConstB.Switch_d;
    } else {
      /* RelationalOperator: '<S162>/UpperRelop' */
      mcb_pmsm_foc_f28379d_dyno_B.UpperRelop_n =
        (mcb_pmsm_foc_f28379d_dyno_B.VdFF_unsat_o <
         mcb_pmsm_foc_f28379d_dyn_ConstB.UnaryMinus_h);

      /* Switch: '<S162>/Switch' */
      if (mcb_pmsm_foc_f28379d_dyno_B.UpperRelop_n) {
        /* Switch: '<S162>/Switch' */
        mcb_pmsm_foc_f28379d_dyno_B.Switch_aa =
          mcb_pmsm_foc_f28379d_dyn_ConstB.UnaryMinus_h;
      } else {
        /* Switch: '<S162>/Switch' */
        mcb_pmsm_foc_f28379d_dyno_B.Switch_aa =
          mcb_pmsm_foc_f28379d_dyno_B.VdFF_unsat_o;
      }

      /* End of Switch: '<S162>/Switch' */

      /* Switch: '<S162>/Switch2' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch2_o =
        mcb_pmsm_foc_f28379d_dyno_B.Switch_aa;
    }

    /* End of Switch: '<S162>/Switch2' */

    /* Sum: '<S21>/Sum' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum_hy =
      mcb_pmsm_foc_f28379d_dyno_B.sf_MATLABFunction.V_d_ref +
      mcb_pmsm_foc_f28379d_dyno_B.Switch2_o;

    /* Sum: '<S31>/Sum' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum_k = mcb_pmsm_foc_f28379d_dyno_B.RT2[1] -
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.algDD_o2;

    /* DataStoreRead: '<S31>/Data Store Read1' */
    mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_lw =
      mcb_pmsm_foc_f28379d_dyno_DWork.EnMtrCtrl;

    /* Logic: '<S31>/Logical Operator' */
    mcb_pmsm_foc_f28379d_dyno_B.LogicalOperator_p =
      !mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_lw;

    /* MATLAB Function: '<S31>/MATLAB Function' incorporates:
     *  Constant: '<S31>/Constant'
     *  Constant: '<S31>/Ki'
     *  Constant: '<S31>/Kp'
     *  Constant: '<S31>/Kp1'
     */
    mcb_pmsm_f_MATLABFunction_j(mcb_pmsm_foc_f28379d_dyno_B.Sum_k, 1.44F,
      0.2025F, mcb_pmsm_foc_f28379d_dyno_B.LogicalOperator_p, 0.0F, 1.0,
      &mcb_pmsm_foc_f28379d_dyno_B.sf_MATLABFunction_j,
      &mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction_j);

    /* Product: '<S160>/prod3' */
    mcb_pmsm_foc_f28379d_dyno_B.Ld_id_j =
      mcb_pmsm_foc_f28379d_dyn_ConstB.Switch_a *
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.algDD_o1;

    /* Sum: '<S160>/add1' */
    mcb_pmsm_foc_f28379d_dyno_B.fluxD_h =
      mcb_pmsm_foc_f28379d_dyn_ConstB.Switch2_h +
      mcb_pmsm_foc_f28379d_dyno_B.Ld_id_j;

    /* Product: '<S160>/prod2' */
    mcb_pmsm_foc_f28379d_dyno_B.VqFF_unsat_b = mcb_pmsm_foc_f28379d_dyno_B.we_n *
      mcb_pmsm_foc_f28379d_dyno_B.fluxD_h;

    /* RelationalOperator: '<S163>/LowerRelop1' */
    mcb_pmsm_foc_f28379d_dyno_B.LowerRelop1_j =
      (mcb_pmsm_foc_f28379d_dyno_B.VqFF_unsat_b >
       mcb_pmsm_foc_f28379d_dyn_ConstB.Switch_d);

    /* Switch: '<S163>/Switch2' */
    if (mcb_pmsm_foc_f28379d_dyno_B.LowerRelop1_j) {
      /* Switch: '<S163>/Switch2' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch2_e =
        mcb_pmsm_foc_f28379d_dyn_ConstB.Switch_d;
    } else {
      /* RelationalOperator: '<S163>/UpperRelop' */
      mcb_pmsm_foc_f28379d_dyno_B.UpperRelop_f =
        (mcb_pmsm_foc_f28379d_dyno_B.VqFF_unsat_b <
         mcb_pmsm_foc_f28379d_dyn_ConstB.UnaryMinus_h);

      /* Switch: '<S163>/Switch' */
      if (mcb_pmsm_foc_f28379d_dyno_B.UpperRelop_f) {
        /* Switch: '<S163>/Switch' */
        mcb_pmsm_foc_f28379d_dyno_B.Switch_b =
          mcb_pmsm_foc_f28379d_dyn_ConstB.UnaryMinus_h;
      } else {
        /* Switch: '<S163>/Switch' */
        mcb_pmsm_foc_f28379d_dyno_B.Switch_b =
          mcb_pmsm_foc_f28379d_dyno_B.VqFF_unsat_b;
      }

      /* End of Switch: '<S163>/Switch' */

      /* Switch: '<S163>/Switch2' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch2_e =
        mcb_pmsm_foc_f28379d_dyno_B.Switch_b;
    }

    /* End of Switch: '<S163>/Switch2' */

    /* Sum: '<S21>/Sum1' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum1_n =
      mcb_pmsm_foc_f28379d_dyno_B.sf_MATLABFunction_j.V_q_ref +
      mcb_pmsm_foc_f28379d_dyno_B.Switch2_e;

    /* SignalConversion generated from: '<S18>/debug' */
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_VI_debug[0] =
      mcb_pmsm_foc_f28379d_dyno_B.RT2[0];
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_VI_debug[1] =
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.algDD_o1;
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_VI_debug[2] =
      mcb_pmsm_foc_f28379d_dyno_B.Sum_hy;
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_VI_debug[3] =
      mcb_pmsm_foc_f28379d_dyno_B.RT2[1];
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_VI_debug[4] =
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.algDD_o2;
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_VI_debug[5] =
      mcb_pmsm_foc_f28379d_dyno_B.Sum1_n;

    /* SignalConversion generated from: '<S18>/debug' */
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_Speed_PU =
      mcb_pmsm_foc_f28379d_dyno_B.Add1_g;

    /* SignalConversion generated from: '<S18>/debug' */
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_Iab_meas_PU[0] =
      mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentm_h[0];
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_Iab_meas_PU[1] =
      mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentm_h[1];

    /* SignalConversion generated from: '<S18>/debug' */
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_Pos_PU = mcb_pmsm_foc_f28379d_dyno_B.Add_nd;

    /* Switch: '<S35>/Switch1' incorporates:
     *  Constant: '<S35>/ChosenMethod'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_e = 3U;

    /* Switch: '<S35>/Switch' incorporates:
     *  Constant: '<S35>/Constant3'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Switch_l = 0.95F;

    /* Product: '<S35>/Product' */
    mcb_pmsm_foc_f28379d_dyno_B.Product_lu = 0.9025F;

    /* Product: '<S36>/Product' */
    mcb_pmsm_foc_f28379d_dyno_B.Product_p1 = mcb_pmsm_foc_f28379d_dyno_B.Sum_hy *
      mcb_pmsm_foc_f28379d_dyno_B.Sum_hy;

    /* Product: '<S36>/Product1' */
    mcb_pmsm_foc_f28379d_dyno_B.Product1_m4h =
      mcb_pmsm_foc_f28379d_dyno_B.Sum1_n * mcb_pmsm_foc_f28379d_dyno_B.Sum1_n;

    /* Sum: '<S36>/Sum1' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum1_f = mcb_pmsm_foc_f28379d_dyno_B.Product_p1
      + mcb_pmsm_foc_f28379d_dyno_B.Product1_m4h;

    /* Outputs for IfAction SubSystem: '<S29>/D-Q Equivalence' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* If: '<S29>/If' */
    mcb_pmsm_foc__DQEquivalence(mcb_pmsm_foc_f28379d_dyno_B.Sum_hy,
      mcb_pmsm_foc_f28379d_dyno_B.Sum1_n, mcb_pmsm_foc_f28379d_dyno_B.Sum1_f,
      0.95F, 0.9025F, mcb_pmsm_foc_f28379d_dyno_B.Merge_f,
      &mcb_pmsm_foc_f28379d_dyno_B.DQEquivalence);

    /* End of Outputs for SubSystem: '<S29>/D-Q Equivalence' */

    /* Outputs for Atomic SubSystem: '<S22>/Two inputs CRL' */
    mcb_pmsm_foc_f_TwoinputsCRL(mcb_pmsm_foc_f28379d_dyno_B.Merge_f[0],
      mcb_pmsm_foc_f28379d_dyno_B.Merge_f[1], mcb_pmsm_foc_f28379d_dyno_B.Sum4_b,
      mcb_pmsm_foc_f28379d_dyno_B.Sum6_m,
      &mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL);

    /* End of Outputs for SubSystem: '<S22>/Two inputs CRL' */

    /* Product: '<S167>/Product1' */
    mcb_pmsm_foc_f28379d_dyno_B.id_Ld_Lq_c =
      mcb_pmsm_foc_f28379d_dyn_ConstB.Ld_Lq_d *
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.algDD_o1;

    /* Sum: '<S167>/Add' */
    mcb_pmsm_foc_f28379d_dyno_B.Add_op = mcb_pmsm_foc_f28379d_dyno_B.id_Ld_Lq_c
      + mcb_pmsm_foc_f28379d_dyn_ConstB.Switch2_ks;

    /* Product: '<S167>/Product3' */
    mcb_pmsm_foc_f28379d_dyno_B.Product3_o4 = mcb_pmsm_foc_f28379d_dyno_B.Add_op
      * mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.algDD_o2;

    /* Gain: '<S167>/1_5_Pp' */
    mcb_pmsm_foc_f28379d_dyno_B.u_5_Pp_a = 6.0F *
      mcb_pmsm_foc_f28379d_dyno_B.Product3_o4;

    /* Product: '<S167>/Product' */
    mcb_pmsm_foc_f28379d_dyno_B.Product_bm =
      mcb_pmsm_foc_f28379d_dyno_B.u_5_Pp_a * mcb_pmsm_foc_f28379d_dyno_B.Add1_g;

    /* Gain: '<S167>/P_si2pu' */
    mcb_pmsm_foc_f28379d_dyno_B.P_output_a = 0.78532F *
      mcb_pmsm_foc_f28379d_dyno_B.Product_bm;

    /* Gain: '<S167>/T_si2pu' */
    mcb_pmsm_foc_f28379d_dyno_B.T_output_f =
      mcb_pmsm_foc_f28379d_dyno_B.u_5_Pp_a;

    /* Gain: '<S185>/one_by_two' */
    mcb_pmsm_foc_f28379d_dyno_B.one_by_two_m = 0.5F *
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.algDD_o1;

    /* Gain: '<S185>/sqrt3_by_two' */
    mcb_pmsm_foc_f28379d_dyno_B.sqrt3_by_two_g = 0.866025388F *
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.algDD_o2;

    /* Sum: '<S185>/add_b' */
    mcb_pmsm_foc_f28379d_dyno_B.add_b_b =
      mcb_pmsm_foc_f28379d_dyno_B.sqrt3_by_two_g -
      mcb_pmsm_foc_f28379d_dyno_B.one_by_two_m;

    /* Sum: '<S185>/add_c' */
    mcb_pmsm_foc_f28379d_dyno_B.add_c_m = (0.0F -
      mcb_pmsm_foc_f28379d_dyno_B.one_by_two_m) -
      mcb_pmsm_foc_f28379d_dyno_B.sqrt3_by_two_g;

    /* MinMax: '<S182>/Max' */
    u0 = mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.algDD_o1;
    Bias = mcb_pmsm_foc_f28379d_dyno_B.add_b_b;
    if ((u0 >= Bias) || rtIsNaNF(Bias)) {
      Bias = u0;
    }

    u0 = mcb_pmsm_foc_f28379d_dyno_B.add_c_m;
    if ((!(Bias >= u0)) && (!rtIsNaNF(u0))) {
      Bias = u0;
    }

    /* MinMax: '<S182>/Max' */
    mcb_pmsm_foc_f28379d_dyno_B.Max_d = Bias;

    /* MinMax: '<S182>/Min' */
    u0 = mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.algDD_o1;
    Bias = mcb_pmsm_foc_f28379d_dyno_B.add_b_b;
    if ((u0 <= Bias) || rtIsNaNF(Bias)) {
      Bias = u0;
    }

    u0 = mcb_pmsm_foc_f28379d_dyno_B.add_c_m;
    if ((!(Bias <= u0)) && (!rtIsNaNF(u0))) {
      Bias = u0;
    }

    /* MinMax: '<S182>/Min' */
    mcb_pmsm_foc_f28379d_dyno_B.Min_n = Bias;

    /* Sum: '<S182>/Add' */
    mcb_pmsm_foc_f28379d_dyno_B.Add_g = mcb_pmsm_foc_f28379d_dyno_B.Max_d +
      mcb_pmsm_foc_f28379d_dyno_B.Min_n;

    /* Gain: '<S182>/one_by_two' */
    mcb_pmsm_foc_f28379d_dyno_B.one_by_two_e = -0.5F *
      mcb_pmsm_foc_f28379d_dyno_B.Add_g;

    /* Sum: '<S181>/Add1' */
    mcb_pmsm_foc_f28379d_dyno_B.Add1_o = mcb_pmsm_foc_f28379d_dyno_B.add_b_b +
      mcb_pmsm_foc_f28379d_dyno_B.one_by_two_e;

    /* Sum: '<S181>/Add2' */
    mcb_pmsm_foc_f28379d_dyno_B.Add2_l =
      mcb_pmsm_foc_f28379d_dyno_B.one_by_two_e +
      mcb_pmsm_foc_f28379d_dyno_B.add_c_m;

    /* Sum: '<S181>/Add3' */
    mcb_pmsm_foc_f28379d_dyno_B.Add3_b =
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.algDD_o1 +
      mcb_pmsm_foc_f28379d_dyno_B.one_by_two_e;

    /* Gain: '<S181>/Gain' */
    mcb_pmsm_foc_f28379d_dyno_B.Gain_db[0] = 1.15470052F *
      mcb_pmsm_foc_f28379d_dyno_B.Add3_b;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_db[1] = 1.15470052F *
      mcb_pmsm_foc_f28379d_dyno_B.Add1_o;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_db[2] = 1.15470052F *
      mcb_pmsm_foc_f28379d_dyno_B.Add2_l;
  }

  /* End of Outputs for SubSystem: '<S10>/Closed Loop Control' */

  /* Logic: '<S10>/NOT' */
  mcb_pmsm_foc_f28379d_dyno_B.NOT_oi = !mcb_pmsm_foc_f28379d_dyno_B.AND_a;

  /* Outputs for Enabled SubSystem: '<S10>/Open Loop Start-Up' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  if (mcb_pmsm_foc_f28379d_dyno_B.NOT_oi) {
    mcb_pmsm_foc_f28379d_dyno_DWork.OpenLoopStartUp_MODE = true;

    /* Gain: '<S19>/rpm2freq' incorporates:
     *  Constant: '<S19>/Speed_ref(rpm)'
     */
    mcb_pmsm_foc_f28379d_dyno_B.rpm2freq = 27.0800018F;

    /* DataStoreRead: '<S19>/Data Store Read1' */
    mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_p =
      mcb_pmsm_foc_f28379d_dyno_DWork.Enable;

    /* Logic: '<S188>/NOT' */
    mcb_pmsm_foc_f28379d_dyno_B.NOT_j =
      !mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_p;

    /* DiscreteIntegrator: '<S188>/Ramp Generator' */
    if (mcb_pmsm_foc_f28379d_dyno_B.NOT_j) {
      mcb_pmsm_foc_f28379d_dyno_DWork.RampGenerator_DSTATE = 0.0F;
    }

    /* DiscreteIntegrator: '<S188>/Ramp Generator' */
    mcb_pmsm_foc_f28379d_dyno_B.Eps =
      mcb_pmsm_foc_f28379d_dyno_DWork.RampGenerator_DSTATE;

    /* Product: '<S19>/Product' */
    mcb_pmsm_foc_f28379d_dyno_B.Product_bc = 27.0800018F *
      mcb_pmsm_foc_f28379d_dyno_B.Eps;

    /* Abs: '<S19>/Abs' */
    mcb_pmsm_foc_f28379d_dyno_B.Frequency = fabsf
      (mcb_pmsm_foc_f28379d_dyno_B.Product_bc);

    /* Gain: '<S19>/V-by-f' */
    mcb_pmsm_foc_f28379d_dyno_B.Vbyf = 0.00369276223F *
      mcb_pmsm_foc_f28379d_dyno_B.Frequency;

    /* Gain: '<S19>/Correction_Factor_sinePWM' */
    mcb_pmsm_foc_f28379d_dyno_B.Correction_Factor_sinePWM = 1.15470052F *
      mcb_pmsm_foc_f28379d_dyno_B.Vbyf;

    /* Saturate: '<S19>/Saturation' */
    u0 = mcb_pmsm_foc_f28379d_dyno_B.Correction_Factor_sinePWM;
    if (u0 > 0.95F) {
      /* Saturate: '<S19>/Saturation' */
      mcb_pmsm_foc_f28379d_dyno_B.Amplitude = 0.95F;
    } else if (u0 < 0.15F) {
      /* Saturate: '<S19>/Saturation' */
      mcb_pmsm_foc_f28379d_dyno_B.Amplitude = 0.15F;
    } else {
      /* Saturate: '<S19>/Saturation' */
      mcb_pmsm_foc_f28379d_dyno_B.Amplitude = u0;
    }

    /* End of Saturate: '<S19>/Saturation' */

    /* UnaryMinus: '<S186>/Unary Minus' */
    mcb_pmsm_foc_f28379d_dyno_B.UnaryMinus =
      -mcb_pmsm_foc_f28379d_dyno_B.Amplitude;

    /* Gain: '<S19>/position_increment' */
    mcb_pmsm_foc_f28379d_dyno_B.position_increment = 0.000314159261F *
      mcb_pmsm_foc_f28379d_dyno_B.Frequency;

    /* Gain: '<S187>/scaleIn' */
    mcb_pmsm_foc_f28379d_dyno_B.scaleIn = 0.159154937F *
      mcb_pmsm_foc_f28379d_dyno_B.position_increment;

    /* UnitDelay: '<S187>/Unit Delay' */
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_l =
      mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_ex;

    /* Logic: '<S187>/NOT' incorporates:
     *  Constant: '<S187>/Constant_Reset'
     */
    mcb_pmsm_foc_f28379d_dyno_B.NOT_n = true;

    /* Outputs for Enabled SubSystem: '<S187>/Accumulate' incorporates:
     *  EnablePort: '<S203>/Enable'
     */
    /* Delay: '<S203>/Delay' */
    mcb_pmsm_foc_f28379d_dyno_B.Delay_fc =
      mcb_pmsm_foc_f28379d_dyno_DWork.Delay_DSTATE_o;

    /* Outputs for Enabled SubSystem: '<S203>/Subsystem' incorporates:
     *  EnablePort: '<S204>/Enable'
     */
    if (mcb_pmsm_foc_f28379d_dyno_B.Delay_fc) {
      /* SignalConversion generated from: '<S204>/Input' */
      mcb_pmsm_foc_f28379d_dyno_B.Input = mcb_pmsm_foc_f28379d_dyno_B.scaleIn;
    }

    /* End of Outputs for SubSystem: '<S203>/Subsystem' */

    /* Sum: '<S203>/Add' */
    mcb_pmsm_foc_f28379d_dyno_B.Add_f4 = mcb_pmsm_foc_f28379d_dyno_B.Input +
      mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_l;

    /* DataTypeConversion: '<S203>/Data Type Conversion' */
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_f = (int16_T)(real32_T)floor
      (mcb_pmsm_foc_f28379d_dyno_B.Add_f4);

    /* DataTypeConversion: '<S203>/Data Type Conversion1' */
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion1_i =
      mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_f;

    /* Sum: '<S203>/Add1' */
    mcb_pmsm_foc_f28379d_dyno_B.Add1_c5 = mcb_pmsm_foc_f28379d_dyno_B.Add_f4 -
      mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion1_i;

    /* Update for Delay: '<S203>/Delay' incorporates:
     *  Constant: '<S203>/Constant'
     */
    mcb_pmsm_foc_f28379d_dyno_DWork.Delay_DSTATE_o = true;

    /* End of Outputs for SubSystem: '<S187>/Accumulate' */

    /* Gain: '<S187>/scaleOut' */
    mcb_pmsm_foc_f28379d_dyno_B.scaleOut = 6.28318548F *
      mcb_pmsm_foc_f28379d_dyno_B.Add1_c5;

    /* DataStoreRead: '<S19>/Data Store Read' */
    mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead =
      mcb_pmsm_foc_f28379d_dyno_DWork.SpeedRef;

    /* Switch: '<S19>/Direction' */
    if (mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead > 0.0F) {
      /* Switch: '<S19>/Direction' */
      mcb_pmsm_foc_f28379d_dyno_B.Eps_k = mcb_pmsm_foc_f28379d_dyno_B.scaleOut;
    } else {
      /* Sum: '<S19>/Sum' incorporates:
       *  Constant: '<S19>/ '
       */
      mcb_pmsm_foc_f28379d_dyno_B.Sum_h = 6.28318548F -
        mcb_pmsm_foc_f28379d_dyno_B.scaleOut;

      /* Switch: '<S19>/Direction' */
      mcb_pmsm_foc_f28379d_dyno_B.Eps_k = mcb_pmsm_foc_f28379d_dyno_B.Sum_h;
    }

    /* End of Switch: '<S19>/Direction' */

    /* Gain: '<S197>/convert_pu' */
    mcb_pmsm_foc_f28379d_dyno_B.convert_pu = 0.159154937F *
      mcb_pmsm_foc_f28379d_dyno_B.Eps_k;

    /* RelationalOperator: '<S199>/Compare' incorporates:
     *  Constant: '<S199>/Constant'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Compare_f =
      (mcb_pmsm_foc_f28379d_dyno_B.convert_pu < 0.0F);

    /* DataTypeConversion: '<S197>/Data Type Conversion' */
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_d =
      mcb_pmsm_foc_f28379d_dyno_B.Compare_f;

    /* If: '<S197>/If' */
    if (mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_d > 0U) {
      /* Outputs for IfAction SubSystem: '<S197>/If Action Subsystem' incorporates:
       *  ActionPort: '<S200>/Action Port'
       */
      mcb_pmsm__IfActionSubsystem(mcb_pmsm_foc_f28379d_dyno_B.convert_pu,
        &mcb_pmsm_foc_f28379d_dyno_B.Merge_h,
        &mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem_b);

      /* End of Outputs for SubSystem: '<S197>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S197>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S201>/Action Port'
       */
      mcb_pmsm_IfActionSubsystem1(mcb_pmsm_foc_f28379d_dyno_B.convert_pu,
        &mcb_pmsm_foc_f28379d_dyno_B.Merge_h,
        &mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem1_l);

      /* End of Outputs for SubSystem: '<S197>/If Action Subsystem1' */
    }

    /* End of If: '<S197>/If' */

    /* Gain: '<S195>/indexing' */
    mcb_pmsm_foc_f28379d_dyno_B.indexing_h = 800.0F *
      mcb_pmsm_foc_f28379d_dyno_B.Merge_h;

    /* DataTypeConversion: '<S195>/Get_Integer' */
    mcb_pmsm_foc_f28379d_dyno_B.Get_Integer_g = (uint16_T)
      mcb_pmsm_foc_f28379d_dyno_B.indexing_h;

    /* Sum: '<S195>/Sum' incorporates:
     *  Constant: '<S195>/offset'
     */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.Get_Integer_g + 1UL;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_f[0] = Sum_j;

    /* Selector: '<S195>/Lookup' incorporates:
     *  Constant: '<S195>/sine_table_values'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[0] =
      mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum_j];

    /* Sum: '<S195>/Sum' */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.Get_Integer_g;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_f[1] = Sum_j;

    /* Selector: '<S195>/Lookup' incorporates:
     *  Constant: '<S195>/sine_table_values'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[1] =
      mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum_j];

    /* Sum: '<S195>/Sum' incorporates:
     *  Constant: '<S195>/offset'
     */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.Get_Integer_g + 201UL;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_f[2] = Sum_j;

    /* Selector: '<S195>/Lookup' incorporates:
     *  Constant: '<S195>/sine_table_values'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[2] =
      mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum_j];

    /* Sum: '<S195>/Sum' incorporates:
     *  Constant: '<S195>/offset'
     */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.Get_Integer_g + 200UL;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_f[3] = Sum_j;

    /* Selector: '<S195>/Lookup' incorporates:
     *  Constant: '<S195>/sine_table_values'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[3] =
      mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum_j];

    /* Sum: '<S196>/Sum3' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum3_b = mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[0]
      - mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[1];

    /* DataTypeConversion: '<S195>/Data Type Conversion1' */
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion1_a =
      mcb_pmsm_foc_f28379d_dyno_B.Get_Integer_g;

    /* Sum: '<S195>/Sum2' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum2_p = mcb_pmsm_foc_f28379d_dyno_B.indexing_h
      - mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion1_a;

    /* Product: '<S196>/Product' */
    mcb_pmsm_foc_f28379d_dyno_B.Product_g4 = mcb_pmsm_foc_f28379d_dyno_B.Sum3_b *
      mcb_pmsm_foc_f28379d_dyno_B.Sum2_p;

    /* Sum: '<S196>/Sum4' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum4_i = mcb_pmsm_foc_f28379d_dyno_B.Product_g4
      + mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[1];

    /* Sum: '<S196>/Sum5' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum5_g = mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[2]
      - mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[3];

    /* Product: '<S196>/Product1' */
    mcb_pmsm_foc_f28379d_dyno_B.Product1_m4 = mcb_pmsm_foc_f28379d_dyno_B.Sum5_g
      * mcb_pmsm_foc_f28379d_dyno_B.Sum2_p;

    /* Sum: '<S196>/Sum6' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum6_n = mcb_pmsm_foc_f28379d_dyno_B.Product1_m4
      + mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[3];

    /* Outputs for Atomic SubSystem: '<S190>/Two inputs CRL' */
    /* Constant: '<S186>/Constant' */
    mcb_pmsm_foc_f_TwoinputsCRL(0.0F, mcb_pmsm_foc_f28379d_dyno_B.UnaryMinus,
      mcb_pmsm_foc_f28379d_dyno_B.Sum4_i, mcb_pmsm_foc_f28379d_dyno_B.Sum6_n,
      &mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a);

    /* End of Outputs for SubSystem: '<S190>/Two inputs CRL' */

    /* Gain: '<S192>/Ka' */
    mcb_pmsm_foc_f28379d_dyno_B.Ka =
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a.algDD_o1;

    /* Gain: '<S192>/one_by_two' */
    mcb_pmsm_foc_f28379d_dyno_B.one_by_two_h = 0.5F *
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a.algDD_o1;

    /* Gain: '<S192>/sqrt3_by_two' */
    mcb_pmsm_foc_f28379d_dyno_B.sqrt3_by_two_d = 0.866025388F *
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a.algDD_o2;

    /* Sum: '<S192>/add_b' */
    mcb_pmsm_foc_f28379d_dyno_B.add_b_m =
      mcb_pmsm_foc_f28379d_dyno_B.sqrt3_by_two_d -
      mcb_pmsm_foc_f28379d_dyno_B.one_by_two_h;

    /* Gain: '<S192>/Kb' */
    mcb_pmsm_foc_f28379d_dyno_B.Kb = mcb_pmsm_foc_f28379d_dyno_B.add_b_m;

    /* Sum: '<S192>/add_c' */
    mcb_pmsm_foc_f28379d_dyno_B.add_c_o = (0.0F -
      mcb_pmsm_foc_f28379d_dyno_B.one_by_two_h) -
      mcb_pmsm_foc_f28379d_dyno_B.sqrt3_by_two_d;

    /* Gain: '<S192>/Kc' */
    mcb_pmsm_foc_f28379d_dyno_B.Kc = mcb_pmsm_foc_f28379d_dyno_B.add_c_o;

    /* Product: '<S188>/Divide' incorporates:
     *  Constant: '<S188>/One'
     *  Constant: '<S19>/Ramp_Time (sec)'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Divide_h = 0.333333343F;

    /* Gain: '<S188>/Sample_Time' */
    mcb_pmsm_foc_f28379d_dyno_B.Sample_Time = 1.66666669E-5F;

    /* Update for DiscreteIntegrator: '<S188>/Ramp Generator' */
    mcb_pmsm_foc_f28379d_dyno_DWork.RampGenerator_DSTATE += 1.66666669E-5F;
    if (mcb_pmsm_foc_f28379d_dyno_DWork.RampGenerator_DSTATE > 1.0F) {
      mcb_pmsm_foc_f28379d_dyno_DWork.RampGenerator_DSTATE = 1.0F;
    } else if (mcb_pmsm_foc_f28379d_dyno_DWork.RampGenerator_DSTATE < 0.0F) {
      mcb_pmsm_foc_f28379d_dyno_DWork.RampGenerator_DSTATE = 0.0F;
    }

    /* End of Update for DiscreteIntegrator: '<S188>/Ramp Generator' */

    /* Update for UnitDelay: '<S187>/Unit Delay' */
    mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_ex =
      mcb_pmsm_foc_f28379d_dyno_B.Add1_c5;
  } else if (mcb_pmsm_foc_f28379d_dyno_DWork.OpenLoopStartUp_MODE) {
    /* Disable for DiscreteIntegrator: '<S188>/Ramp Generator' */
    mcb_pmsm_foc_f28379d_dyno_DWork.RampGenerator_DSTATE =
      mcb_pmsm_foc_f28379d_dyno_B.Eps;
    mcb_pmsm_foc_f28379d_dyno_DWork.OpenLoopStartUp_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S10>/Open Loop Start-Up' */

  /* DataStoreRead: '<S11>/Data Store Read1' */
  mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_n =
    mcb_pmsm_foc_f28379d_dyno_DWork.Enable;

  /* DataStoreRead: '<S11>/Data Store Read2' */
  mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead2_f =
    mcb_pmsm_foc_f28379d_dyno_DWork.EnClosedLoop;

  /* Logic: '<S11>/AND' */
  mcb_pmsm_foc_f28379d_dyno_B.AND_o =
    (mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_n &&
     mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead2_f);

  /* DataStoreWrite: '<S11>/Data Store Write' */
  mcb_pmsm_foc_f28379d_dyno_DWork.EnMtrCtrl = mcb_pmsm_foc_f28379d_dyno_B.AND_o;

  /* UnitDelay: '<S244>/Output' */
  mcb_pmsm_foc_f28379d_dyno_B.Output =
    mcb_pmsm_foc_f28379d_dyno_DWork.Output_DSTATE;

  /* DataStoreRead: '<S17>/Data Store Read' */
  mcb_pmsm_foc_f28379d_dyno_B.mtr1_speed_ref_PU =
    mcb_pmsm_foc_f28379d_dyno_DWork.SpeedRef;

  /* SignalConversion generated from: '<S17>/Selector' */
  mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[6] =
    mcb_pmsm_foc_f28379d_dyno_B.T_output_f;
  mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[7] =
    mcb_pmsm_foc_f28379d_dyno_B.P_output_a;
  mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[8] =
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_Speed_PU;
  mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[9] =
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_Iab_meas_PU[0];
  mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[10] =
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_Iab_meas_PU[1];
  mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[11] =
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_Pos_PU;
  for (i = 0; i < 6; i++) {
    mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[i] =
      mcb_pmsm_foc_f28379d_dyno_B.mtr1_VI_debug[i];
    mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[i + 12] =
      mcb_pmsm_foc_f28379d_dyno_B.mtr2_VI_debug[i];
  }

  mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[18] =
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Te_PU;
  mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[19] =
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pm_PU;
  mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[20] =
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Speed_PU;
  mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[21] =
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU[0];
  mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[22] =
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU[1];
  mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[23] =
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pos_PU;
  mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[24] =
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_speed_ref_PU;

  /* End of SignalConversion generated from: '<S17>/Selector' */

  /* DataStoreRead: '<S17>/Data Store Read1' */
  mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_m =
    mcb_pmsm_foc_f28379d_dyno_DWork.Debug_signals;

  /* MultiPortSwitch: '<S17>/Multiport Switch' */
  switch (mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_m) {
   case 0:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor16'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 25U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 21U;
    break;

   case 1:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor1'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 25U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 9U;
    break;

   case 2:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor2'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 1U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 2U;
    break;

   case 3:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor3'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 4U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 5U;
    break;

   case 4:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor4'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 3U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 6U;
    break;

   case 5:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor5'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 10U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 11U;
    break;

   case 6:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor6'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 8U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 7U;
    break;

   case 7:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor7'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 13U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 14U;
    break;

   case 8:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor8'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 16U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 17U;
    break;

   case 9:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor9'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 15U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 18U;
    break;

   case 10:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor10'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 22U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 23U;
    break;

   case 11:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor11'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 20U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 19U;
    break;

   case 12:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor12'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 8U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 20U;
    break;

   case 13:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor13'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 7U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 19U;
    break;

   case 14:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor14'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 12U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 24U;
    break;

   default:
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/speed_motor15'
     */
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] = 10U;
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] = 22U;
    break;
  }

  /* End of MultiPortSwitch: '<S17>/Multiport Switch' */

  /* Selector: '<S17>/Selector' */
  mcb_pmsm_foc_f28379d_dyno_B.Selector[0] =
    mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[(int16_T)
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[0] - 1];
  mcb_pmsm_foc_f28379d_dyno_B.Selector[1] =
    mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[(int16_T)
    mcb_pmsm_foc_f28379d_dyno_B.MultiportSwitch[1] - 1];

  /* S-Function (any2byte_svd): '<S243>/Byte Pack' */

  /* Pack: <S243>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0U;
    uint16_T MW_inputPortWidth = 0U;

    /* Packed output data type - uint32_T */
    void* packData = &mcb_pmsm_foc_f28379d_dyno_B.BytePack[0];

    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 2 */
    {
      MW_inputPortWidth = (uint16_T)2 * sizeof(real32_T);
      memcpy((void *)&(((uint16_T *)packData)[MW_outputPortOffset]), (void*)
             &mcb_pmsm_foc_f28379d_dyno_B.Selector[0], MW_inputPortWidth);
    }
  }

  /* If: '<S241>/If' */
  if (mcb_pmsm_foc_f28379d_dyno_B.Output == 0U) {
    /* Outputs for IfAction SubSystem: '<S241>/Start' incorporates:
     *  ActionPort: '<S247>/Action Port'
     */
    /* Merge: '<S241>/Merge' incorporates:
     *  Constant: '<S247>/Start'
     *  SignalConversion generated from: '<S247>/Data_out'
     */
    mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Data[0] = 1397969747UL;

    /* SignalConversion generated from: '<S247>/Data' */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.BytePack[0];

    /* End of Outputs for SubSystem: '<S241>/Start' */
    mcb_pmsm_foc_f28379d_dyno_B.Data_fw[0] = Sum_j;

    /* Outputs for IfAction SubSystem: '<S241>/Start' incorporates:
     *  ActionPort: '<S247>/Action Port'
     */
    /* Merge: '<S241>/Merge' incorporates:
     *  SignalConversion generated from: '<S247>/Data_out'
     */
    mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Data[1] = Sum_j;

    /* SignalConversion generated from: '<S247>/Data' */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.BytePack[1];

    /* End of Outputs for SubSystem: '<S241>/Start' */
    mcb_pmsm_foc_f28379d_dyno_B.Data_fw[1] = Sum_j;

    /* Outputs for IfAction SubSystem: '<S241>/Start' incorporates:
     *  ActionPort: '<S247>/Action Port'
     */
    /* Merge: '<S241>/Merge' incorporates:
     *  SignalConversion generated from: '<S247>/Data_out'
     */
    mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Data[2] = Sum_j;

    /* Merge: '<S241>/Merge1' incorporates:
     *  Bias: '<S247>/Bias'
     */
    mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_f28379d_dyn_ConstB.Width + 1UL;

    /* End of Outputs for SubSystem: '<S241>/Start' */
  } else if (mcb_pmsm_foc_f28379d_dyno_B.Output == 599U) {
    /* Outputs for IfAction SubSystem: '<S241>/End' incorporates:
     *  ActionPort: '<S246>/Action Port'
     */
    /* SignalConversion generated from: '<S246>/Data' */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.BytePack[0];

    /* End of Outputs for SubSystem: '<S241>/End' */
    mcb_pmsm_foc_f28379d_dyno_B.Data_f[0] = Sum_j;

    /* Outputs for IfAction SubSystem: '<S241>/End' incorporates:
     *  ActionPort: '<S246>/Action Port'
     */
    /* Merge: '<S241>/Merge' incorporates:
     *  SignalConversion generated from: '<S246>/Data_out'
     */
    mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Data[0] = Sum_j;

    /* SignalConversion generated from: '<S246>/Data' */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.BytePack[1];

    /* End of Outputs for SubSystem: '<S241>/End' */
    mcb_pmsm_foc_f28379d_dyno_B.Data_f[1] = Sum_j;

    /* Outputs for IfAction SubSystem: '<S241>/End' incorporates:
     *  ActionPort: '<S246>/Action Port'
     */
    /* Merge: '<S241>/Merge' incorporates:
     *  Constant: '<S246>/End'
     *  SignalConversion generated from: '<S246>/Data_out'
     */
    mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Data[1] = Sum_j;
    mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Data[2] = 1162167621UL;

    /* Merge: '<S241>/Merge1' incorporates:
     *  Bias: '<S246>/Bias'
     */
    mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_f28379d_dyn_ConstB.Width + 1UL;

    /* End of Outputs for SubSystem: '<S241>/End' */
  } else {
    /* Outputs for IfAction SubSystem: '<S241>/Data' incorporates:
     *  ActionPort: '<S245>/Action Port'
     */
    /* SignalConversion generated from: '<S245>/Data' */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.BytePack[0];

    /* End of Outputs for SubSystem: '<S241>/Data' */
    mcb_pmsm_foc_f28379d_dyno_B.Data[0] = Sum_j;

    /* Outputs for IfAction SubSystem: '<S241>/Data' incorporates:
     *  ActionPort: '<S245>/Action Port'
     */
    /* Merge: '<S241>/Merge' incorporates:
     *  SignalConversion generated from: '<S245>/Data_out'
     */
    mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Data[0] = Sum_j;

    /* SignalConversion generated from: '<S245>/Data' */
    Sum_j = mcb_pmsm_foc_f28379d_dyno_B.BytePack[1];

    /* End of Outputs for SubSystem: '<S241>/Data' */
    mcb_pmsm_foc_f28379d_dyno_B.Data[1] = Sum_j;

    /* Outputs for IfAction SubSystem: '<S241>/Data' incorporates:
     *  ActionPort: '<S245>/Action Port'
     */
    /* Merge: '<S241>/Merge' incorporates:
     *  Constant: '<S245>/Dummy'
     *  SignalConversion generated from: '<S245>/Data_out'
     */
    mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Data[1] = Sum_j;
    mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Data[2] = 0UL;

    /* Merge: '<S241>/Merge1' incorporates:
     *  SignalConversion generated from: '<S245>/Data_width'
     */
    mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_f28379d_dyn_ConstB.Width;

    /* End of Outputs for SubSystem: '<S241>/Data' */
  }

  /* End of If: '<S241>/If' */

  /* Outputs for Iterator SubSystem: '<S239>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S242>/While Iterator'
   */
  i = 1;
  do {
    mcb_pmsm_foc_f28379d_dyno_B.WhileIterator = i;
    mcb_pmsm_foc_f28379d_dyno_B.IndexVector =
      mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Data[mcb_pmsm_foc_f28379d_dyno_B.WhileIterator
      - 1];

    {
      if (checkSCITransmitInProgressA != 1U) {
        checkSCITransmitInProgressA = 1U;
        int16_T errFlgHeader = NOERROR;
        int16_T errFlgData = NOERROR;
        int16_T errFlgTail = NOERROR;
        errFlgData = scia_xmit((uchar_T*)
          &mcb_pmsm_foc_f28379d_dyno_B.IndexVector, 4, 4);
        checkSCITransmitInProgressA = 0U;
      }
    }

    mcb_pmsm_foc_f28379d_dyno_B.Add_fy =
      mcb_pmsm_foc_f28379d_dyno_B.SCI_Tx_Iteration - (uint32_T)
      mcb_pmsm_foc_f28379d_dyno_B.WhileIterator;
    i++;
  } while (mcb_pmsm_foc_f28379d_dyno_B.Add_fy != 0UL);

  /* End of Outputs for SubSystem: '<S239>/While Iterator Subsystem' */

  /* Sum: '<S248>/FixPt Sum1' incorporates:
   *  Constant: '<S248>/FixPt Constant'
   */
  mcb_pmsm_foc_f28379d_dyno_B.FixPtSum1 = mcb_pmsm_foc_f28379d_dyno_B.Output +
    1U;

  /* Switch: '<S249>/FixPt Switch' */
  if (mcb_pmsm_foc_f28379d_dyno_B.FixPtSum1 > 599U) {
    /* Switch: '<S249>/FixPt Switch' incorporates:
     *  Constant: '<S249>/Constant'
     */
    mcb_pmsm_foc_f28379d_dyno_B.FixPtSwitch = 0U;
  } else {
    /* Switch: '<S249>/FixPt Switch' */
    mcb_pmsm_foc_f28379d_dyno_B.FixPtSwitch =
      mcb_pmsm_foc_f28379d_dyno_B.FixPtSum1;
  }

  /* End of Switch: '<S249>/FixPt Switch' */

  /* DataStoreRead: '<S15>/Enable' */
  mcb_pmsm_foc_f28379d_dyno_B.PWM_En_a = mcb_pmsm_foc_f28379d_dyno_DWork.Enable;

  /* DataTypeConversion: '<S15>/Data Type Conversion' */
  mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_i =
    mcb_pmsm_foc_f28379d_dyno_B.PWM_En_a;

  /* Logic: '<S238>/NOT' incorporates:
   *  Switch: '<S238>/Switch'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Activelowlogicforinverterenab_k =
    !(mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_i != 0.0F);

  /* Switch: '<S238>/Switch' */
  mcb_pmsm_foc_f28379d_dyno_B.Switch_k0 =
    mcb_pmsm_foc_f28379d_dyno_B.Activelowlogicforinverterenab_k;

  /* S-Function (c280xgpio_do): '<S238>/Inverter enable' */
  {
    if (mcb_pmsm_foc_f28379d_dyno_B.Switch_k0) {
      GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
    } else {
      GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
    }
  }

  /* Switch: '<S238>/Switch1' */
  if (mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_i >= 0.5F) {
    /* Switch: '<S10>/Switch' */
    if (mcb_pmsm_foc_f28379d_dyno_B.AND_a) {
      /* Switch: '<S10>/Switch' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch_h[0] =
        mcb_pmsm_foc_f28379d_dyno_B.Gain_db[0];
      mcb_pmsm_foc_f28379d_dyno_B.Switch_h[1] =
        mcb_pmsm_foc_f28379d_dyno_B.Gain_db[1];
      mcb_pmsm_foc_f28379d_dyno_B.Switch_h[2] =
        mcb_pmsm_foc_f28379d_dyno_B.Gain_db[2];
    } else {
      /* Switch: '<S10>/Switch' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch_h[0] = mcb_pmsm_foc_f28379d_dyno_B.Ka;
      mcb_pmsm_foc_f28379d_dyno_B.Switch_h[1] = mcb_pmsm_foc_f28379d_dyno_B.Kb;
      mcb_pmsm_foc_f28379d_dyno_B.Switch_h[2] = mcb_pmsm_foc_f28379d_dyno_B.Kc;
    }

    /* End of Switch: '<S10>/Switch' */

    /* Gain: '<S15>/One_by_Two' */
    Bias = 0.5F * mcb_pmsm_foc_f28379d_dyno_B.Switch_h[0];
    mcb_pmsm_foc_f28379d_dyno_B.One_by_Two_n[0] = Bias;

    /* Sum: '<S15>/Sum' incorporates:
     *  Constant: '<S15>/Constant'
     */
    Bias += 0.5F;
    mcb_pmsm_foc_f28379d_dyno_B.Mtr1_PWM_Duty_Cycles[0] = Bias;

    /* Gain: '<S238>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD_g = (uint16_T)(5000.0F * Bias);
    mcb_pmsm_foc_f28379d_dyno_B.Scale_to_PWM_Counter_PRD_g[0] =
      Scale_to_PWM_Counter_PRD_g;

    /* Switch: '<S238>/Switch1' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_ic[0] = Scale_to_PWM_Counter_PRD_g;

    /* Gain: '<S15>/One_by_Two' */
    Bias = 0.5F * mcb_pmsm_foc_f28379d_dyno_B.Switch_h[1];
    mcb_pmsm_foc_f28379d_dyno_B.One_by_Two_n[1] = Bias;

    /* Sum: '<S15>/Sum' incorporates:
     *  Constant: '<S15>/Constant'
     */
    Bias += 0.5F;
    mcb_pmsm_foc_f28379d_dyno_B.Mtr1_PWM_Duty_Cycles[1] = Bias;

    /* Gain: '<S238>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD_g = (uint16_T)(5000.0F * Bias);
    mcb_pmsm_foc_f28379d_dyno_B.Scale_to_PWM_Counter_PRD_g[1] =
      Scale_to_PWM_Counter_PRD_g;

    /* Switch: '<S238>/Switch1' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_ic[1] = Scale_to_PWM_Counter_PRD_g;

    /* Gain: '<S15>/One_by_Two' */
    Bias = 0.5F * mcb_pmsm_foc_f28379d_dyno_B.Switch_h[2];
    mcb_pmsm_foc_f28379d_dyno_B.One_by_Two_n[2] = Bias;

    /* Sum: '<S15>/Sum' incorporates:
     *  Constant: '<S15>/Constant'
     */
    Bias += 0.5F;
    mcb_pmsm_foc_f28379d_dyno_B.Mtr1_PWM_Duty_Cycles[2] = Bias;

    /* Gain: '<S238>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD_g = (uint16_T)(5000.0F * Bias);
    mcb_pmsm_foc_f28379d_dyno_B.Scale_to_PWM_Counter_PRD_g[2] =
      Scale_to_PWM_Counter_PRD_g;

    /* Switch: '<S238>/Switch1' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_ic[2] = Scale_to_PWM_Counter_PRD_g;
  } else {
    /* Switch: '<S238>/Switch1' incorporates:
     *  Constant: '<S238>/stop'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_ic[0] = 0U;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_ic[1] = 0U;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_ic[2] = 0U;
  }

  /* End of Switch: '<S238>/Switch1' */

  /* S-Function (c2802xpwm): '<S238>/ePWM1' */
  uint16_T tbprdValue1Outputs = EPwm1Regs.TBPRD;

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(mcb_pmsm_foc_f28379d_dyno_B.Switch1_ic
      [0]);
  }

  /* S-Function (c2802xpwm): '<S238>/ePWM2' */
  uint16_T tbprdValue2Outputs = EPwm2Regs.TBPRD;

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)(mcb_pmsm_foc_f28379d_dyno_B.Switch1_ic
      [1]);
  }

  /* S-Function (c2802xpwm): '<S238>/ePWM3' */
  uint16_T tbprdValue3Outputs = EPwm3Regs.TBPRD;

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.bit.CMPA = (uint16_T)(mcb_pmsm_foc_f28379d_dyno_B.Switch1_ic
      [2]);
  }

  /* Update for Delay: '<S206>/Delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.Delay_DSTATE_c =
    mcb_pmsm_foc_f28379d_dyno_B.AND_a;

  /* Update for Delay: '<S212>/Delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.Delay_DSTATE_d[mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx_l]
    = mcb_pmsm_foc_f28379d_dyno_B.PositionToCount_n;
  if (mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx_l < 19U) {
    mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx_l++;
  } else {
    mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx_l = 0U;
  }

  /* End of Update for Delay: '<S212>/Delay' */

  /* Update for UnitDelay: '<S215>/Unit Delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_az =
    mcb_pmsm_foc_f28379d_dyno_B.Add1_g;

  /* Update for UnitDelay: '<S244>/Output' */
  mcb_pmsm_foc_f28379d_dyno_DWork.Output_DSTATE =
    mcb_pmsm_foc_f28379d_dyno_B.FixPtSwitch;
}

/* System initialize for function-call system: '<Root>/Current control for motor2' */
void Currentcontrolformot_p_Init(void)
{
  /* Start for S-Function (c2802xadc): '<S431>/ADC_C_IN4' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC1 ();

  /* Start for S-Function (c2802xadc): '<S431>/ADC_B_IN4' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC1 ();

  /* Start for S-Function (c280xqep): '<S431>/eQEP' */
  config_QEP_eQEP2((uint32_T)65535U,(uint32_T)0, (uint32_T)0, (uint32_T)0,
                   (uint16_T)0, (uint16_T)448, (uint16_T)8232, (uint16_T)32768,
                   (uint16_T)119,(uint16_T)0);

  /* Start for S-Function (c280xgpio_do): '<S461>/Inverter enable' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFCFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x4000000U;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S461>/ePWM4' */
  real32_T tbprdValue4 = (real32_T)EPwm4Regs.TBPRD;

  /*** Initialize ePWM4 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm4Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm4Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm4Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm4Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm4Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm4Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm4Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm4Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm4Regs.TBCTL.all = (EPwm4Regs.TBCTL.all & ~0x3FFFU) | 0x6U;
    EPwm4Regs.TBCTL2.all = (EPwm4Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm4Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm4Regs.TBPHS.bit.TBPHS               = 5000U;          -- Phase offset register
     */
    EPwm4Regs.TBPHS.all = (EPwm4Regs.TBPHS.all & ~0xFFFF0000U) | 0x13880000U;

    // Time Base Counter Register
    EPwm4Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm4Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm4Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm4Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm4Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm4Regs.CMPCTL.all = (EPwm4Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm4Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm4Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm4Regs.CMPCTL2.all = (EPwm4Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm4Regs.CMPA.bit.CMPA = 2500U;   // Counter Compare A Register
    EPwm4Regs.CMPB.bit.CMPB = 2500U;   // Counter Compare B Register
    EPwm4Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm4Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm4Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm4Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm4Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm4Regs.AQSFRC.all = (EPwm4Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm4Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm4Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm4Regs.AQCSFRC.all = (EPwm4Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm4Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm4Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm4Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm4Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm4Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm4Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm4Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm4Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm4Regs.DBCTL.all = (EPwm4Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm4Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm4Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm4Regs.ETSEL.bit.SOCAEN               = 1U;          -- Start of Conversion A Enable
       EPwm4Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm4Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM4SOC Period Select
       EPwm4Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm4Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm4Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm4Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM4SOCB Period Select
       EPwm4Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm4Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM4INTn Enable
       EPwm4Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm4Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM4INTn Period Select
       EPwm4Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm4Regs.ETSEL.all = (EPwm4Regs.ETSEL.all & ~0xFF7FU) | 0x1A01U;
    EPwm4Regs.ETPS.all = (EPwm4Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm4Regs.ETSOCPS.all = (EPwm4Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm4Regs.ETINTPS.all = (EPwm4Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm4Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm4Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm4Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm4Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm4Regs.PCCTL.all = (EPwm4Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm4Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm4Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM4A
       EPwm4Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM4B
       EPwm4Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM4A action on DCAEVT1
       EPwm4Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM4A action on DCAEVT2
       EPwm4Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM4B action on DCBEVT1
       EPwm4Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM4B action on DCBEVT2
     */
    EPwm4Regs.TZCTL.all = (EPwm4Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm4Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm4Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm4Regs.TZEINT.all = (EPwm4Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm4Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm4Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm4Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm4Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm4Regs.DCACTL.all = (EPwm4Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm4Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm4Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm4Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm4Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm4Regs.DCBCTL.all = (EPwm4Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm4Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm4Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm4Regs.DCTRIPSEL.all = (EPwm4Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm4Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm4Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm4Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm4Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm4Regs.TZDCSEL.all = (EPwm4Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm4Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm4Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm4Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm4Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm4Regs.DCFCTL.all = (EPwm4Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm4Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm4Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm4Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm4Regs.DCCAPCTL.all = (EPwm4Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm4Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm4Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm4Regs.HRCNFG.all = (EPwm4Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm4Regs.EPWMXLINK.bit.TBPRDLINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPALINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPBLINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPCLINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPDLINK = 3U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm4Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm4Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm4Regs.HRPCTL.all = (EPwm4Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S461>/ePWM5' */
  real32_T tbprdValue5 = (real32_T)EPwm5Regs.TBPRD;

  /*** Initialize ePWM5 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm5Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm5Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm5Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm5Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm5Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm5Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm5Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm5Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm5Regs.TBCTL.all = (EPwm5Regs.TBCTL.all & ~0x3FFFU) | 0x6U;
    EPwm5Regs.TBCTL2.all = (EPwm5Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm5Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm5Regs.TBPHS.bit.TBPHS               = 5000U;          -- Phase offset register
     */
    EPwm5Regs.TBPHS.all = (EPwm5Regs.TBPHS.all & ~0xFFFF0000U) | 0x13880000U;

    // Time Base Counter Register
    EPwm5Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm5Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm5Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm5Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm5Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm5Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm5Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm5Regs.CMPCTL.all = (EPwm5Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm5Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm5Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm5Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm5Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm5Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm5Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm5Regs.CMPCTL2.all = (EPwm5Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm5Regs.CMPA.bit.CMPA = 2500U;   // Counter Compare A Register
    EPwm5Regs.CMPB.bit.CMPB = 2500U;   // Counter Compare B Register
    EPwm5Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm5Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm5Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm5Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm5Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm5Regs.AQSFRC.all = (EPwm5Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm5Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm5Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm5Regs.AQCSFRC.all = (EPwm5Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm5Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm5Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm5Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm5Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm5Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm5Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm5Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm5Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm5Regs.DBCTL.all = (EPwm5Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm5Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm5Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm5Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm5Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm5Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm5Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM5SOC Period Select
       EPwm5Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm5Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm5Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm5Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm5Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM5SOCB Period Select
       EPwm5Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm5Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM5INTn Enable
       EPwm5Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm5Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm5Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM5INTn Period Select
       EPwm5Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm5Regs.ETSEL.all = (EPwm5Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm5Regs.ETPS.all = (EPwm5Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm5Regs.ETSOCPS.all = (EPwm5Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm5Regs.ETINTPS.all = (EPwm5Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm5Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm5Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm5Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm5Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm5Regs.PCCTL.all = (EPwm5Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm5Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm5Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM5A
       EPwm5Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM5B
       EPwm5Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM5A action on DCAEVT1
       EPwm5Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM5A action on DCAEVT2
       EPwm5Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM5B action on DCBEVT1
       EPwm5Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM5B action on DCBEVT2
     */
    EPwm5Regs.TZCTL.all = (EPwm5Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm5Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm5Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm5Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm5Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm5Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm5Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm5Regs.TZEINT.all = (EPwm5Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm5Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm5Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm5Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm5Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm5Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm5Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm5Regs.DCACTL.all = (EPwm5Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm5Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm5Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm5Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm5Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm5Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm5Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm5Regs.DCBCTL.all = (EPwm5Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm5Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm5Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm5Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm5Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm5Regs.DCTRIPSEL.all = (EPwm5Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm5Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm5Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm5Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm5Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm5Regs.TZDCSEL.all = (EPwm5Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm5Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm5Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm5Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm5Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm5Regs.DCFCTL.all = (EPwm5Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm5Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm5Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm5Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm5Regs.DCCAPCTL.all = (EPwm5Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm5Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm5Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm5Regs.HRCNFG.all = (EPwm5Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm5Regs.EPWMXLINK.bit.TBPRDLINK = 4U;
    EPwm5Regs.EPWMXLINK.bit.CMPALINK = 4U;
    EPwm5Regs.EPWMXLINK.bit.CMPBLINK = 4U;
    EPwm5Regs.EPWMXLINK.bit.CMPCLINK = 4U;
    EPwm5Regs.EPWMXLINK.bit.CMPDLINK = 4U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm5Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm5Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm5Regs.HRPCTL.all = (EPwm5Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S461>/ePWM6' */
  real32_T tbprdValue6 = (real32_T)EPwm6Regs.TBPRD;

  /*** Initialize ePWM6 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm6Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm6Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm6Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm6Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm6Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm6Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm6Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm6Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm6Regs.TBCTL.all = (EPwm6Regs.TBCTL.all & ~0x3FFFU) | 0x6U;
    EPwm6Regs.TBCTL2.all = (EPwm6Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm6Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm6Regs.TBPHS.bit.TBPHS               = 5000U;          -- Phase offset register
     */
    EPwm6Regs.TBPHS.all = (EPwm6Regs.TBPHS.all & ~0xFFFF0000U) | 0x13880000U;

    // Time Base Counter Register
    EPwm6Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm6Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm6Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm6Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm6Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm6Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm6Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm6Regs.CMPCTL.all = (EPwm6Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm6Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm6Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm6Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm6Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm6Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm6Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm6Regs.CMPCTL2.all = (EPwm6Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm6Regs.CMPA.bit.CMPA = 2500U;   // Counter Compare A Register
    EPwm6Regs.CMPB.bit.CMPB = 2500U;   // Counter Compare B Register
    EPwm6Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm6Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm6Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm6Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm6Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm6Regs.AQSFRC.all = (EPwm6Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm6Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm6Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm6Regs.AQCSFRC.all = (EPwm6Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm6Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm6Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm6Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm6Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm6Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm6Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm6Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm6Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm6Regs.DBCTL.all = (EPwm6Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm6Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm6Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm6Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm6Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm6Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm6Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM6SOC Period Select
       EPwm6Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm6Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm6Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm6Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm6Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM6SOCB Period Select
       EPwm6Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm6Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM6INTn Enable
       EPwm6Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm6Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm6Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM6INTn Period Select
       EPwm6Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm6Regs.ETSEL.all = (EPwm6Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm6Regs.ETPS.all = (EPwm6Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm6Regs.ETSOCPS.all = (EPwm6Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm6Regs.ETINTPS.all = (EPwm6Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm6Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm6Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm6Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm6Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm6Regs.PCCTL.all = (EPwm6Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm6Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm6Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM6A
       EPwm6Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM6B
       EPwm6Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM6A action on DCAEVT1
       EPwm6Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM6A action on DCAEVT2
       EPwm6Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM6B action on DCBEVT1
       EPwm6Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM6B action on DCBEVT2
     */
    EPwm6Regs.TZCTL.all = (EPwm6Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm6Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm6Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm6Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm6Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm6Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm6Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm6Regs.TZEINT.all = (EPwm6Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm6Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm6Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm6Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm6Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm6Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm6Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm6Regs.DCACTL.all = (EPwm6Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm6Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm6Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm6Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm6Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm6Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm6Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm6Regs.DCBCTL.all = (EPwm6Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm6Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm6Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm6Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm6Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm6Regs.DCTRIPSEL.all = (EPwm6Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm6Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm6Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm6Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm6Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm6Regs.TZDCSEL.all = (EPwm6Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm6Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm6Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm6Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm6Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm6Regs.DCFCTL.all = (EPwm6Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm6Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm6Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm6Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm6Regs.DCCAPCTL.all = (EPwm6Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm6Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm6Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm6Regs.HRCNFG.all = (EPwm6Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm6Regs.EPWMXLINK.bit.TBPRDLINK = 5U;
    EPwm6Regs.EPWMXLINK.bit.CMPALINK = 5U;
    EPwm6Regs.EPWMXLINK.bit.CMPBLINK = 5U;
    EPwm6Regs.EPWMXLINK.bit.CMPCLINK = 5U;
    EPwm6Regs.EPWMXLINK.bit.CMPDLINK = 5U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm6Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm6Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm6Regs.HRPCTL.all = (EPwm6Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* InitializeConditions for Delay: '<S437>/Delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx = 0U;

  /* SystemInitialize for Atomic SubSystem: '<S251>/Delay to start motor1 (codegen)' */
  /* SystemInitialize for Enabled SubSystem: '<S427>/Disable EnMtr2TrqCtrl' */
  /* Start for S-Function (c280xgpio_do): '<S428>/GPIO16' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFFFFFFCU;
  GpioCtrlRegs.GPADIR.all |= 0x10000U;
  EDIS;

  /* End of SystemInitialize for SubSystem: '<S427>/Disable EnMtr2TrqCtrl' */

  /* SystemInitialize for Enabled SubSystem: '<S427>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  /* InitializeConditions for UnitDelay: '<S429>/Unit Delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_l = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S429>/Enable EnMtr2TrqCtrl' */
  /* Start for S-Function (c280xgpio_do): '<S430>/GPIO16' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFFFFFFCU;
  GpioCtrlRegs.GPADIR.all |= 0x10000U;
  EDIS;

  /* End of SystemInitialize for SubSystem: '<S429>/Enable EnMtr2TrqCtrl' */
  /* End of SystemInitialize for SubSystem: '<S427>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  /* End of SystemInitialize for SubSystem: '<S251>/Delay to start motor1 (codegen)' */

  /* SystemInitialize for Enabled SubSystem: '<S250>/Closed Loop Control' */
  /* InitializeConditions for UnitDelay: '<S404>/Unit Delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_e[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_e[1] = 0.0F;

  /* SystemInitialize for MATLAB Function: '<S268>/MATLAB Function' */
  mcb_pms_MATLABFunction_Init
    (&mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction_i);

  /* SystemInitialize for MATLAB Function: '<S269>/MATLAB Function' */
  mcb_p_MATLABFunction_a_Init
    (&mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction_k);

  /* End of SystemInitialize for SubSystem: '<S250>/Closed Loop Control' */
}

/* System reset for function-call system: '<Root>/Current control for motor2' */
void Currentcontrolformo_a_Reset(void)
{
  /* InitializeConditions for Delay: '<S437>/Delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx = 0U;
}

/* Disable for function-call system: '<Root>/Current control for motor2' */
#pragma CODE_SECTION (Currentcontrolfor_j_Disable, "ramfuncs")

void Currentcontrolfor_j_Disable(void)
{
  /* Disable for Atomic SubSystem: '<S251>/Delay to start motor1 (codegen)' */
  /* Disable for Enabled SubSystem: '<S427>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.EnableEnMtr2TrqCtrlafter2secdel = false;

  /* End of Disable for SubSystem: '<S427>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  /* End of Disable for SubSystem: '<S251>/Delay to start motor1 (codegen)' */

  /* Disable for Enabled SubSystem: '<S250>/Closed Loop Control' */
  mcb_pmsm_foc_f28379d_dyno_DWork.ClosedLoopControl_MODE = false;

  /* End of Disable for SubSystem: '<S250>/Closed Loop Control' */
}

/* Output and update for function-call system: '<Root>/Current control for motor2' */
#pragma CODE_SECTION (mcb_Currentcontrolformotor2, "ramfuncs")

void mcb_Currentcontrolformotor2(void)
{
  real32_T Bias;
  real32_T UnitDelay_e;
  uint32_T Sum;
  uint16_T Scale_to_PWM_Counter_PRD;

  /* Outputs for Atomic SubSystem: '<S251>/Delay to start motor1 (codegen)' */
  /* DataStoreRead: '<S427>/Data Store Read2' */
  mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead2_l =
    mcb_pmsm_foc_f28379d_dyno_DWork.EnClosedLoop;

  /* DataStoreRead: '<S427>/Data Store Read1' */
  mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_f =
    mcb_pmsm_foc_f28379d_dyno_DWork.Enable;

  /* Logic: '<S427>/AND' */
  mcb_pmsm_foc_f28379d_dyno_B.AND =
    (mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead2_l &&
     mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_f);

  /* Logic: '<S427>/NOT' */
  mcb_pmsm_foc_f28379d_dyno_B.NOT_hf = !mcb_pmsm_foc_f28379d_dyno_B.AND;

  /* Outputs for Enabled SubSystem: '<S427>/Disable EnMtr2TrqCtrl' incorporates:
   *  EnablePort: '<S428>/Enable'
   */
  if (mcb_pmsm_foc_f28379d_dyno_B.NOT_hf) {
    /* DataStoreWrite: '<S428>/Data Store Write' incorporates:
     *  Constant: '<S428>/Constant'
     */
    mcb_pmsm_foc_f28379d_dyno_DWork.EnMtr2TrqCtrl = false;

    /* S-Function (c280xgpio_do): '<S428>/GPIO16' incorporates:
     *  Constant: '<S428>/GPIO Trig'
     */
    {
      if ((0U)) {
        GpioDataRegs.GPASET.bit.GPIO16 = 1U;
      } else {
        GpioDataRegs.GPACLEAR.bit.GPIO16 = 1U;
      }
    }
  }

  /* End of Outputs for SubSystem: '<S427>/Disable EnMtr2TrqCtrl' */

  /* Outputs for Enabled SubSystem: '<S427>/Enable EnMtr2TrqCtrl after 2 sec delay' incorporates:
   *  EnablePort: '<S429>/Enable'
   */
  if (mcb_pmsm_foc_f28379d_dyno_B.AND) {
    if (!mcb_pmsm_foc_f28379d_dyno_DWork.EnableEnMtr2TrqCtrlafter2secdel) {
      /* InitializeConditions for UnitDelay: '<S429>/Unit Delay' */
      mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_l = 0.0F;
      mcb_pmsm_foc_f28379d_dyno_DWork.EnableEnMtr2TrqCtrlafter2secdel = true;
    }

    /* UnitDelay: '<S429>/Unit Delay' */
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_m =
      mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_l;

    /* Sum: '<S429>/Add' incorporates:
     *  Constant: '<S429>/Constant2'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Add_c = mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_m
      + 1.0F;

    /* Switch: '<S429>/Switch' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch_i = (mcb_pmsm_foc_f28379d_dyno_B.Add_c >
      40000.0F);

    /* Outputs for Enabled SubSystem: '<S429>/Enable EnMtr2TrqCtrl' incorporates:
     *  EnablePort: '<S430>/Enable'
     */
    if (mcb_pmsm_foc_f28379d_dyno_B.Switch_i) {
      /* DataStoreWrite: '<S430>/Data Store Write' incorporates:
       *  Constant: '<S430>/Constant'
       */
      mcb_pmsm_foc_f28379d_dyno_DWork.EnMtr2TrqCtrl = true;

      /* S-Function (c280xgpio_do): '<S430>/GPIO16' incorporates:
       *  Constant: '<S430>/GPIO Trig'
       */
      {
        if ((1U)) {
          GpioDataRegs.GPASET.bit.GPIO16 = 1U;
        } else {
          GpioDataRegs.GPACLEAR.bit.GPIO16 = 1U;
        }
      }
    }

    /* End of Outputs for SubSystem: '<S429>/Enable EnMtr2TrqCtrl' */

    /* Update for UnitDelay: '<S429>/Unit Delay' */
    mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_l =
      mcb_pmsm_foc_f28379d_dyno_B.Add_c;
  } else {
    mcb_pmsm_foc_f28379d_dyno_DWork.EnableEnMtr2TrqCtrlafter2secdel = false;
  }

  /* End of Outputs for SubSystem: '<S427>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  /* End of Outputs for SubSystem: '<S251>/Delay to start motor1 (codegen)' */

  /* DataStoreRead: '<S433>/Data Store Read1' */
  mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1 =
    mcb_pmsm_foc_f28379d_dyno_DWork.IaOffset_motor2;

  /* DataStoreRead: '<S433>/Data Store Read2' */
  mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead2 =
    mcb_pmsm_foc_f28379d_dyno_DWork.IbOffset_motor2;

  /* S-Function (c2802xadc): '<S431>/ADC_C_IN4' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_f28379d_dyno_B.ADC_C_IN4 = (AdccResultRegs.ADCRESULT1);
  }

  /* S-Function (c2802xadc): '<S431>/ADC_B_IN4' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_f28379d_dyno_B.ADC_B_IN4 = (AdcbResultRegs.ADCRESULT1);
  }

  /* DataTypeConversion: '<S433>/Data Type Conversion' */
  mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_p[0] =
    mcb_pmsm_foc_f28379d_dyno_B.ADC_C_IN4;
  mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_p[1] =
    mcb_pmsm_foc_f28379d_dyno_B.ADC_B_IN4;

  /* Sum: '<S433>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_co[0] =
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_p[0] -
    mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1;
  mcb_pmsm_foc_f28379d_dyno_B.Add_co[1] =
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_p[1] -
    mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead2;

  /* Gain: '<S460>/Get ADC Voltage' */
  Bias = 0.000732600747F * (real32_T)mcb_pmsm_foc_f28379d_dyno_B.Add_co[0];
  mcb_pmsm_foc_f28379d_dyno_B.GetADCVoltage[0] = Bias;

  /* Gain: '<S460>/Get Currents' */
  Bias *= 10.0F;
  mcb_pmsm_foc_f28379d_dyno_B.GetCurrents[0] = Bias;

  /* Gain: '<S460>/PU_Conversion' */
  Bias *= 0.0666666701F;
  mcb_pmsm_foc_f28379d_dyno_B.PU_Conversion[0] = Bias;

  /* Gain: '<S433>/Inverting // Non-inverting  Current measurement  amplifieer' */
  mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentmea[0] = -Bias;

  /* Gain: '<S460>/Get ADC Voltage' */
  Bias = 0.000732600747F * (real32_T)mcb_pmsm_foc_f28379d_dyno_B.Add_co[1];
  mcb_pmsm_foc_f28379d_dyno_B.GetADCVoltage[1] = Bias;

  /* Gain: '<S460>/Get Currents' */
  Bias *= 10.0F;
  mcb_pmsm_foc_f28379d_dyno_B.GetCurrents[1] = Bias;

  /* Gain: '<S460>/PU_Conversion' */
  Bias *= 0.0666666701F;
  mcb_pmsm_foc_f28379d_dyno_B.PU_Conversion[1] = Bias;

  /* Gain: '<S433>/Inverting // Non-inverting  Current measurement  amplifieer' */
  mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentmea[1] = -Bias;

  /* S-Function (c280xqep): '<S431>/eQEP' */
  {
    mcb_pmsm_foc_f28379d_dyno_B.eQEP_o1 = EQep2Regs.QPOSCNT;/*eQEP Position Counter*/
    mcb_pmsm_foc_f28379d_dyno_B.eQEP_o2 = EQep2Regs.QPOSILAT;
         /* The position-counter value is latched into this register on an IEL*/
  }

  /* Outputs for IfAction SubSystem: '<S436>/PositionNoReset' incorporates:
   *  ActionPort: '<S450>/Action Port'
   */
  /* If: '<S436>/If1' */
  mcb_pmsm_fo_PositionNoReset(mcb_pmsm_foc_f28379d_dyno_B.eQEP_o2,
    mcb_pmsm_foc_f28379d_dyno_B.eQEP_o1, &mcb_pmsm_foc_f28379d_dyno_B.Merge_j,
    &mcb_pmsm_foc_f28379d_dyno_B.PositionNoReset_i);

  /* End of Outputs for SubSystem: '<S436>/PositionNoReset' */

  /* DataTypeConversion: '<S453>/DTC' */
  mcb_pmsm_foc_f28379d_dyno_B.DTC = mcb_pmsm_foc_f28379d_dyno_B.Merge_j;

  /* Product: '<S436>/Product' incorporates:
   *  Constant: '<S456>/Constant'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Product_ib = mcb_pmsm_foc_f28379d_dyno_B.DTC *
    0.00025F;

  /* Gain: '<S437>/PositionToCount' */
  mcb_pmsm_foc_f28379d_dyno_B.PositionToCount = (uint32_T)(4.2949673E+9F *
    mcb_pmsm_foc_f28379d_dyno_B.Product_ib);

  /* Delay: '<S437>/Delay' */
  mcb_pmsm_foc_f28379d_dyno_B.Delay =
    mcb_pmsm_foc_f28379d_dyno_DWork.Delay_DSTATE[mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx];

  /* Sum: '<S437>/SpeedCount' */
  mcb_pmsm_foc_f28379d_dyno_B.SpeedCount = (int32_T)
    mcb_pmsm_foc_f28379d_dyno_B.PositionToCount - (int32_T)
    mcb_pmsm_foc_f28379d_dyno_B.Delay;

  /* DataTypeConversion: '<S458>/DTC' */
  mcb_pmsm_foc_f28379d_dyno_B.DTC_k = (real32_T)
    mcb_pmsm_foc_f28379d_dyno_B.SpeedCount;

  /* Gain: '<S437>/SpeedGain' */
  mcb_pmsm_foc_f28379d_dyno_B.SpeedGain = 3.43915274E-9F *
    mcb_pmsm_foc_f28379d_dyno_B.DTC_k;

  /* Switch: '<S434>/Switch1' incorporates:
   *  Constant: '<S434>/FilterConstant'
   *  Constant: '<S434>/OneMinusFilterConstant'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Switch1_pe[0] = 0.01F;
  mcb_pmsm_foc_f28379d_dyno_B.Switch1_pe[1] = 0.99F;

  /* Product: '<S440>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_mq = mcb_pmsm_foc_f28379d_dyno_B.SpeedGain
    * 0.01F;

  /* UnitDelay: '<S440>/Unit Delay' */
  mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_g =
    mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_a;

  /* Product: '<S440>/Product1' */
  mcb_pmsm_foc_f28379d_dyno_B.Product1_n = 0.99F *
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_g;

  /* Sum: '<S440>/Add1' */
  mcb_pmsm_foc_f28379d_dyno_B.Add1_i = mcb_pmsm_foc_f28379d_dyno_B.Product_mq +
    mcb_pmsm_foc_f28379d_dyno_B.Product1_n;

  /* Switch: '<S442>/Switch' incorporates:
   *  Constant: '<S253>/IndexOffset'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Switch_f = 0.225F;

  /* If: '<S443>/If' */
  if (mcb_pmsm_foc_f28379d_dyno_B.Product_ib <= 0.225F) {
    /* Outputs for IfAction SubSystem: '<S443>/If Action Subsystem' incorporates:
     *  ActionPort: '<S445>/Action Port'
     */
    mcb_pms_IfActionSubsystem_a(mcb_pmsm_foc_f28379d_dyno_B.Product_ib, 0.225F,
      &mcb_pmsm_foc_f28379d_dyno_B.Merge);

    /* End of Outputs for SubSystem: '<S443>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S443>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S446>/Action Port'
     */
    /* Merge: '<S443>/Merge' incorporates:
     *  Sum: '<S446>/Add'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Merge = mcb_pmsm_foc_f28379d_dyno_B.Product_ib -
      0.225F;

    /* End of Outputs for SubSystem: '<S443>/If Action Subsystem1' */
  }

  /* End of If: '<S443>/If' */

  /* Gain: '<S448>/Number of pole pairs' */
  mcb_pmsm_foc_f28379d_dyno_B.Numberofpolepairs = 4.0F *
    mcb_pmsm_foc_f28379d_dyno_B.Merge;

  /* Rounding: '<S444>/Floor' */
  mcb_pmsm_foc_f28379d_dyno_B.Floor = (real32_T)floor
    (mcb_pmsm_foc_f28379d_dyno_B.Numberofpolepairs);

  /* Sum: '<S444>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_exa =
    mcb_pmsm_foc_f28379d_dyno_B.Numberofpolepairs -
    mcb_pmsm_foc_f28379d_dyno_B.Floor;

  /* DataStoreRead: '<S2>/Data Store Read1' */
  mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_l =
    mcb_pmsm_foc_f28379d_dyno_DWork.EnMtr2TrqCtrl;

  /* Outputs for Enabled SubSystem: '<S250>/Closed Loop Control' incorporates:
   *  EnablePort: '<S256>/Enable'
   */
  if (mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_l) {
    if (!mcb_pmsm_foc_f28379d_dyno_DWork.ClosedLoopControl_MODE) {
      /* InitializeConditions for UnitDelay: '<S404>/Unit Delay' */
      mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_e[0] = 0.0F;
      mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_e[1] = 0.0F;

      /* SystemReset for MATLAB Function: '<S269>/MATLAB Function' */
      mcb__MATLABFunction_c_Reset
        (&mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction_k);

      /* SystemReset for MATLAB Function: '<S268>/MATLAB Function' */
      mcb_pm_MATLABFunction_Reset
        (&mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction_i);
      mcb_pmsm_foc_f28379d_dyno_DWork.ClosedLoopControl_MODE = true;
    }

    /* SignalConversion generated from: '<S256>/debug' */
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Speed_PU_hk =
      mcb_pmsm_foc_f28379d_dyno_B.Add1_i;

    /* SignalConversion generated from: '<S256>/debug' */
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU_jj[0] =
      mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentmea[0];
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU_jj[1] =
      mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentmea[1];

    /* SignalConversion generated from: '<S256>/debug' */
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pos_PU_db =
      mcb_pmsm_foc_f28379d_dyno_B.Add_exa;

    /* Outputs for Atomic SubSystem: '<S265>/Two phase CRL wrap' */
    mcb_pmsm_fo_TwophaseCRLwrap
      (mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentmea[0],
       mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentmea[1],
       &mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap_h);

    /* End of Outputs for SubSystem: '<S265>/Two phase CRL wrap' */

    /* Switch: '<S273>/Switch1' incorporates:
     *  Constant: '<S273>/ChosenMethod'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_m = 3U;

    /* Switch: '<S259>/Switch1' incorporates:
     *  Constant: '<S259>/FilterConstant'
     *  Constant: '<S259>/OneMinusFilterConstant'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_h[0] = 0.001F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_h[1] = 0.999F;

    /* Product: '<S404>/Product' */
    Bias = mcb_pmsm_foc_f28379d_dyno_B.RT7[0] * 0.001F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_cc[0] = Bias;

    /* UnitDelay: '<S404>/Unit Delay' */
    UnitDelay_e = mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_e[0];
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_e[0] = UnitDelay_e;

    /* Product: '<S404>/Product1' */
    UnitDelay_e *= 0.999F;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_e[0] = UnitDelay_e;

    /* Sum: '<S404>/Add1' */
    mcb_pmsm_foc_f28379d_dyno_B.Add1_ft[0] = Bias + UnitDelay_e;

    /* Product: '<S404>/Product' */
    Bias = mcb_pmsm_foc_f28379d_dyno_B.RT7[1] * 0.001F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_cc[1] = Bias;

    /* UnitDelay: '<S404>/Unit Delay' */
    UnitDelay_e = mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_e[1];
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_e[1] = UnitDelay_e;

    /* Product: '<S404>/Product1' */
    UnitDelay_e *= 0.999F;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_e[1] = UnitDelay_e;

    /* Sum: '<S404>/Add1' */
    mcb_pmsm_foc_f28379d_dyno_B.Add1_ft[1] = Bias + UnitDelay_e;

    /* RelationalOperator: '<S416>/Compare' incorporates:
     *  Constant: '<S416>/Constant'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Compare_a = (mcb_pmsm_foc_f28379d_dyno_B.Add_exa
      < 0.0F);

    /* DataTypeConversion: '<S414>/Data Type Conversion' */
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_j =
      mcb_pmsm_foc_f28379d_dyno_B.Compare_a;

    /* If: '<S414>/If' */
    if (mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_j > 0U) {
      /* Outputs for IfAction SubSystem: '<S414>/If Action Subsystem' incorporates:
       *  ActionPort: '<S417>/Action Port'
       */
      mcb_pmsm__IfActionSubsystem(mcb_pmsm_foc_f28379d_dyno_B.Add_exa,
        &mcb_pmsm_foc_f28379d_dyno_B.Merge_l,
        &mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem_e);

      /* End of Outputs for SubSystem: '<S414>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S414>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S418>/Action Port'
       */
      mcb_pmsm_IfActionSubsystem1(mcb_pmsm_foc_f28379d_dyno_B.Add_exa,
        &mcb_pmsm_foc_f28379d_dyno_B.Merge_l,
        &mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem1_i);

      /* End of Outputs for SubSystem: '<S414>/If Action Subsystem1' */
    }

    /* End of If: '<S414>/If' */

    /* Gain: '<S412>/indexing' */
    mcb_pmsm_foc_f28379d_dyno_B.indexing = 800.0F *
      mcb_pmsm_foc_f28379d_dyno_B.Merge_l;

    /* DataTypeConversion: '<S412>/Get_Integer' */
    mcb_pmsm_foc_f28379d_dyno_B.Get_Integer = (uint16_T)
      mcb_pmsm_foc_f28379d_dyno_B.indexing;

    /* Sum: '<S412>/Sum' incorporates:
     *  Constant: '<S412>/offset'
     */
    Sum = mcb_pmsm_foc_f28379d_dyno_B.Get_Integer + 1UL;
    mcb_pmsm_foc_f28379d_dyno_B.Sum[0] = Sum;

    /* Selector: '<S412>/Lookup' incorporates:
     *  Constant: '<S412>/sine_table_values'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Lookup[0] =
      mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum];

    /* Sum: '<S412>/Sum' */
    Sum = mcb_pmsm_foc_f28379d_dyno_B.Get_Integer;
    mcb_pmsm_foc_f28379d_dyno_B.Sum[1] = Sum;

    /* Selector: '<S412>/Lookup' incorporates:
     *  Constant: '<S412>/sine_table_values'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Lookup[1] =
      mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum];

    /* Sum: '<S412>/Sum' incorporates:
     *  Constant: '<S412>/offset'
     */
    Sum = mcb_pmsm_foc_f28379d_dyno_B.Get_Integer + 201UL;
    mcb_pmsm_foc_f28379d_dyno_B.Sum[2] = Sum;

    /* Selector: '<S412>/Lookup' incorporates:
     *  Constant: '<S412>/sine_table_values'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Lookup[2] =
      mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum];

    /* Sum: '<S412>/Sum' incorporates:
     *  Constant: '<S412>/offset'
     */
    Sum = mcb_pmsm_foc_f28379d_dyno_B.Get_Integer + 200UL;
    mcb_pmsm_foc_f28379d_dyno_B.Sum[3] = Sum;

    /* Selector: '<S412>/Lookup' incorporates:
     *  Constant: '<S412>/sine_table_values'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Lookup[3] =
      mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum];

    /* Sum: '<S413>/Sum3' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum3 = mcb_pmsm_foc_f28379d_dyno_B.Lookup[0] -
      mcb_pmsm_foc_f28379d_dyno_B.Lookup[1];

    /* DataTypeConversion: '<S412>/Data Type Conversion1' */
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion1 =
      mcb_pmsm_foc_f28379d_dyno_B.Get_Integer;

    /* Sum: '<S412>/Sum2' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum2 = mcb_pmsm_foc_f28379d_dyno_B.indexing -
      mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion1;

    /* Product: '<S413>/Product' */
    mcb_pmsm_foc_f28379d_dyno_B.Product_h = mcb_pmsm_foc_f28379d_dyno_B.Sum3 *
      mcb_pmsm_foc_f28379d_dyno_B.Sum2;

    /* Sum: '<S413>/Sum4' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum4 = mcb_pmsm_foc_f28379d_dyno_B.Product_h +
      mcb_pmsm_foc_f28379d_dyno_B.Lookup[1];

    /* Sum: '<S413>/Sum5' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum5 = mcb_pmsm_foc_f28379d_dyno_B.Lookup[2] -
      mcb_pmsm_foc_f28379d_dyno_B.Lookup[3];

    /* Product: '<S413>/Product1' */
    mcb_pmsm_foc_f28379d_dyno_B.Product1_ns = mcb_pmsm_foc_f28379d_dyno_B.Sum5 *
      mcb_pmsm_foc_f28379d_dyno_B.Sum2;

    /* Sum: '<S413>/Sum6' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum6 = mcb_pmsm_foc_f28379d_dyno_B.Product1_ns +
      mcb_pmsm_foc_f28379d_dyno_B.Lookup[3];

    /* Outputs for Atomic SubSystem: '<S262>/Two inputs CRL' */
    mcb_pmsm_foc_TwoinputsCRL_o
      (mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap_h.algDD_o1,
       mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap_h.algDD_o2,
       mcb_pmsm_foc_f28379d_dyno_B.Sum4, mcb_pmsm_foc_f28379d_dyno_B.Sum6,
       &mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i);

    /* End of Outputs for SubSystem: '<S262>/Two inputs CRL' */

    /* Sum: '<S269>/Sum' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum_jx = mcb_pmsm_foc_f28379d_dyno_B.Add1_ft[1]
      - mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.algDD_o2;

    /* DataStoreRead: '<S269>/Data Store Read1' */
    mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_fz =
      mcb_pmsm_foc_f28379d_dyno_DWork.EnMtr2TrqCtrl;

    /* Logic: '<S269>/Logical Operator' */
    mcb_pmsm_foc_f28379d_dyno_B.LogicalOperator =
      !mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_fz;

    /* MATLAB Function: '<S269>/MATLAB Function' incorporates:
     *  Constant: '<S269>/Constant'
     *  Constant: '<S269>/Ki'
     *  Constant: '<S269>/Kp'
     *  Constant: '<S269>/Kp1'
     */
    mcb_pmsm_f_MATLABFunction_j(mcb_pmsm_foc_f28379d_dyno_B.Sum_jx, 1.44F,
      0.2025F, mcb_pmsm_foc_f28379d_dyno_B.LogicalOperator, 0.0F, 1.0,
      &mcb_pmsm_foc_f28379d_dyno_B.sf_MATLABFunction_k,
      &mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction_k);

    /* Gain: '<S398>/wm_pu2si_mech2elec' */
    mcb_pmsm_foc_f28379d_dyno_B.we = 4.0F * mcb_pmsm_foc_f28379d_dyno_B.Add1_i;

    /* Product: '<S398>/prod3' */
    mcb_pmsm_foc_f28379d_dyno_B.Ld_id = mcb_pmsm_foc_f28379d_dyn_ConstB.Switch *
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.algDD_o1;

    /* Sum: '<S398>/add1' */
    mcb_pmsm_foc_f28379d_dyno_B.fluxD = mcb_pmsm_foc_f28379d_dyn_ConstB.Switch2
      + mcb_pmsm_foc_f28379d_dyno_B.Ld_id;

    /* Product: '<S398>/prod2' */
    mcb_pmsm_foc_f28379d_dyno_B.VqFF_unsat = mcb_pmsm_foc_f28379d_dyno_B.we *
      mcb_pmsm_foc_f28379d_dyno_B.fluxD;

    /* RelationalOperator: '<S401>/LowerRelop1' */
    mcb_pmsm_foc_f28379d_dyno_B.LowerRelop1 =
      (mcb_pmsm_foc_f28379d_dyno_B.VqFF_unsat >
       mcb_pmsm_foc_f28379d_dyn_ConstB.Switch_n);

    /* Switch: '<S401>/Switch2' */
    if (mcb_pmsm_foc_f28379d_dyno_B.LowerRelop1) {
      /* Switch: '<S401>/Switch2' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch2_j =
        mcb_pmsm_foc_f28379d_dyn_ConstB.Switch_n;
    } else {
      /* RelationalOperator: '<S401>/UpperRelop' */
      mcb_pmsm_foc_f28379d_dyno_B.UpperRelop =
        (mcb_pmsm_foc_f28379d_dyno_B.VqFF_unsat <
         mcb_pmsm_foc_f28379d_dyn_ConstB.UnaryMinus);

      /* Switch: '<S401>/Switch' */
      if (mcb_pmsm_foc_f28379d_dyno_B.UpperRelop) {
        /* Switch: '<S401>/Switch' */
        mcb_pmsm_foc_f28379d_dyno_B.Switch_k =
          mcb_pmsm_foc_f28379d_dyn_ConstB.UnaryMinus;
      } else {
        /* Switch: '<S401>/Switch' */
        mcb_pmsm_foc_f28379d_dyno_B.Switch_k =
          mcb_pmsm_foc_f28379d_dyno_B.VqFF_unsat;
      }

      /* End of Switch: '<S401>/Switch' */

      /* Switch: '<S401>/Switch2' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch2_j =
        mcb_pmsm_foc_f28379d_dyno_B.Switch_k;
    }

    /* End of Switch: '<S401>/Switch2' */

    /* Sum: '<S258>/Sum1' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum1_g =
      mcb_pmsm_foc_f28379d_dyno_B.sf_MATLABFunction_k.V_q_ref +
      mcb_pmsm_foc_f28379d_dyno_B.Switch2_j;

    /* Sum: '<S268>/Sum' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum_o = mcb_pmsm_foc_f28379d_dyno_B.Add1_ft[0] -
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.algDD_o1;

    /* DataStoreRead: '<S268>/Data Store Read1' */
    mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_lc =
      mcb_pmsm_foc_f28379d_dyno_DWork.EnMtr2TrqCtrl;

    /* Logic: '<S268>/Logical Operator' */
    mcb_pmsm_foc_f28379d_dyno_B.LogicalOperator_f =
      !mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_lc;

    /* MATLAB Function: '<S268>/MATLAB Function' incorporates:
     *  Constant: '<S268>/Constant'
     *  Constant: '<S268>/Ki'
     *  Constant: '<S268>/Ki1'
     *  Constant: '<S268>/Kp'
     */
    mcb_pmsm_foc_MATLABFunction(mcb_pmsm_foc_f28379d_dyno_B.Sum_o, 1.44F,
      0.2025F, mcb_pmsm_foc_f28379d_dyno_B.LogicalOperator_f, 0.0F, 1.0,
      &mcb_pmsm_foc_f28379d_dyno_B.sf_MATLABFunction_i,
      &mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction_i);

    /* Product: '<S398>/prod1' */
    mcb_pmsm_foc_f28379d_dyno_B.w_Lq_iq =
      mcb_pmsm_foc_f28379d_dyn_ConstB.Switch1 *
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.algDD_o2 *
      mcb_pmsm_foc_f28379d_dyno_B.we;

    /* Gain: '<S398>/NegSign' */
    mcb_pmsm_foc_f28379d_dyno_B.VdFF_unsat =
      -mcb_pmsm_foc_f28379d_dyno_B.w_Lq_iq;

    /* RelationalOperator: '<S400>/LowerRelop1' */
    mcb_pmsm_foc_f28379d_dyno_B.LowerRelop1_e =
      (mcb_pmsm_foc_f28379d_dyno_B.VdFF_unsat >
       mcb_pmsm_foc_f28379d_dyn_ConstB.Switch_n);

    /* Switch: '<S400>/Switch2' */
    if (mcb_pmsm_foc_f28379d_dyno_B.LowerRelop1_e) {
      /* Switch: '<S400>/Switch2' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch2_k =
        mcb_pmsm_foc_f28379d_dyn_ConstB.Switch_n;
    } else {
      /* RelationalOperator: '<S400>/UpperRelop' */
      mcb_pmsm_foc_f28379d_dyno_B.UpperRelop_j =
        (mcb_pmsm_foc_f28379d_dyno_B.VdFF_unsat <
         mcb_pmsm_foc_f28379d_dyn_ConstB.UnaryMinus);

      /* Switch: '<S400>/Switch' */
      if (mcb_pmsm_foc_f28379d_dyno_B.UpperRelop_j) {
        /* Switch: '<S400>/Switch' */
        mcb_pmsm_foc_f28379d_dyno_B.Switch_ns =
          mcb_pmsm_foc_f28379d_dyn_ConstB.UnaryMinus;
      } else {
        /* Switch: '<S400>/Switch' */
        mcb_pmsm_foc_f28379d_dyno_B.Switch_ns =
          mcb_pmsm_foc_f28379d_dyno_B.VdFF_unsat;
      }

      /* End of Switch: '<S400>/Switch' */

      /* Switch: '<S400>/Switch2' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch2_k =
        mcb_pmsm_foc_f28379d_dyno_B.Switch_ns;
    }

    /* End of Switch: '<S400>/Switch2' */

    /* Sum: '<S258>/Sum' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum_m =
      mcb_pmsm_foc_f28379d_dyno_B.sf_MATLABFunction_i.V_d_ref +
      mcb_pmsm_foc_f28379d_dyno_B.Switch2_k;

    /* Switch: '<S273>/Switch' incorporates:
     *  Constant: '<S273>/Constant3'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Switch_o = 0.95F;

    /* Product: '<S273>/Product' */
    mcb_pmsm_foc_f28379d_dyno_B.Product_cg = 0.9025F;

    /* Product: '<S274>/Product' */
    mcb_pmsm_foc_f28379d_dyno_B.Product_ae = mcb_pmsm_foc_f28379d_dyno_B.Sum_m *
      mcb_pmsm_foc_f28379d_dyno_B.Sum_m;

    /* Product: '<S274>/Product1' */
    mcb_pmsm_foc_f28379d_dyno_B.Product1_j = mcb_pmsm_foc_f28379d_dyno_B.Sum1_g *
      mcb_pmsm_foc_f28379d_dyno_B.Sum1_g;

    /* Sum: '<S274>/Sum1' */
    mcb_pmsm_foc_f28379d_dyno_B.Sum1_a = mcb_pmsm_foc_f28379d_dyno_B.Product_ae
      + mcb_pmsm_foc_f28379d_dyno_B.Product1_j;

    /* Outputs for IfAction SubSystem: '<S267>/D-Q Equivalence' incorporates:
     *  ActionPort: '<S271>/Action Port'
     */
    /* If: '<S267>/If' */
    mcb_pmsm_foc__DQEquivalence(mcb_pmsm_foc_f28379d_dyno_B.Sum_m,
      mcb_pmsm_foc_f28379d_dyno_B.Sum1_g, mcb_pmsm_foc_f28379d_dyno_B.Sum1_a,
      0.95F, 0.9025F, mcb_pmsm_foc_f28379d_dyno_B.Merge_d,
      &mcb_pmsm_foc_f28379d_dyno_B.DQEquivalence_f);

    /* End of Outputs for SubSystem: '<S267>/D-Q Equivalence' */

    /* Outputs for Atomic SubSystem: '<S260>/Two inputs CRL' */
    mcb_pmsm_foc_f_TwoinputsCRL(mcb_pmsm_foc_f28379d_dyno_B.Merge_d[0],
      mcb_pmsm_foc_f28379d_dyno_B.Merge_d[1], mcb_pmsm_foc_f28379d_dyno_B.Sum4,
      mcb_pmsm_foc_f28379d_dyno_B.Sum6,
      &mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c);

    /* End of Outputs for SubSystem: '<S260>/Two inputs CRL' */

    /* Product: '<S408>/Product1' */
    mcb_pmsm_foc_f28379d_dyno_B.id_Ld_Lq = mcb_pmsm_foc_f28379d_dyn_ConstB.Ld_Lq
      * mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.algDD_o1;

    /* Sum: '<S408>/Add' */
    mcb_pmsm_foc_f28379d_dyno_B.Add_b3 = mcb_pmsm_foc_f28379d_dyno_B.id_Ld_Lq +
      mcb_pmsm_foc_f28379d_dyn_ConstB.Switch2_k;

    /* Product: '<S408>/Product3' */
    mcb_pmsm_foc_f28379d_dyno_B.Product3_l = mcb_pmsm_foc_f28379d_dyno_B.Add_b3 *
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.algDD_o2;

    /* Gain: '<S408>/1_5_Pp' */
    mcb_pmsm_foc_f28379d_dyno_B.u_5_Pp = 6.0F *
      mcb_pmsm_foc_f28379d_dyno_B.Product3_l;

    /* Product: '<S408>/Product' */
    mcb_pmsm_foc_f28379d_dyno_B.Product_ee = mcb_pmsm_foc_f28379d_dyno_B.u_5_Pp *
      mcb_pmsm_foc_f28379d_dyno_B.Add1_i;

    /* Gain: '<S408>/P_si2pu' */
    mcb_pmsm_foc_f28379d_dyno_B.P_output = 0.78532F *
      mcb_pmsm_foc_f28379d_dyno_B.Product_ee;

    /* Gain: '<S408>/T_si2pu' */
    mcb_pmsm_foc_f28379d_dyno_B.T_output = mcb_pmsm_foc_f28379d_dyno_B.u_5_Pp;

    /* Gain: '<S426>/one_by_two' */
    mcb_pmsm_foc_f28379d_dyno_B.one_by_two = 0.5F *
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.algDD_o1;

    /* Gain: '<S426>/sqrt3_by_two' */
    mcb_pmsm_foc_f28379d_dyno_B.sqrt3_by_two = 0.866025388F *
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.algDD_o2;

    /* Sum: '<S426>/add_b' */
    mcb_pmsm_foc_f28379d_dyno_B.add_b = mcb_pmsm_foc_f28379d_dyno_B.sqrt3_by_two
      - mcb_pmsm_foc_f28379d_dyno_B.one_by_two;

    /* Sum: '<S426>/add_c' */
    mcb_pmsm_foc_f28379d_dyno_B.add_c = (0.0F -
      mcb_pmsm_foc_f28379d_dyno_B.one_by_two) -
      mcb_pmsm_foc_f28379d_dyno_B.sqrt3_by_two;

    /* MinMax: '<S423>/Max' */
    UnitDelay_e = mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.algDD_o1;
    Bias = mcb_pmsm_foc_f28379d_dyno_B.add_b;
    if ((UnitDelay_e >= Bias) || rtIsNaNF(Bias)) {
      Bias = UnitDelay_e;
    }

    UnitDelay_e = mcb_pmsm_foc_f28379d_dyno_B.add_c;
    if ((!(Bias >= UnitDelay_e)) && (!rtIsNaNF(UnitDelay_e))) {
      Bias = UnitDelay_e;
    }

    /* MinMax: '<S423>/Max' */
    mcb_pmsm_foc_f28379d_dyno_B.Max = Bias;

    /* MinMax: '<S423>/Min' */
    UnitDelay_e = mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.algDD_o1;
    Bias = mcb_pmsm_foc_f28379d_dyno_B.add_b;
    if ((UnitDelay_e <= Bias) || rtIsNaNF(Bias)) {
      Bias = UnitDelay_e;
    }

    UnitDelay_e = mcb_pmsm_foc_f28379d_dyno_B.add_c;
    if ((!(Bias <= UnitDelay_e)) && (!rtIsNaNF(UnitDelay_e))) {
      Bias = UnitDelay_e;
    }

    /* MinMax: '<S423>/Min' */
    mcb_pmsm_foc_f28379d_dyno_B.Min = Bias;

    /* Sum: '<S423>/Add' */
    mcb_pmsm_foc_f28379d_dyno_B.Add_o = mcb_pmsm_foc_f28379d_dyno_B.Max +
      mcb_pmsm_foc_f28379d_dyno_B.Min;

    /* Gain: '<S423>/one_by_two' */
    mcb_pmsm_foc_f28379d_dyno_B.one_by_two_k = -0.5F *
      mcb_pmsm_foc_f28379d_dyno_B.Add_o;

    /* Sum: '<S422>/Add1' */
    mcb_pmsm_foc_f28379d_dyno_B.Add1_kg = mcb_pmsm_foc_f28379d_dyno_B.add_b +
      mcb_pmsm_foc_f28379d_dyno_B.one_by_two_k;

    /* Sum: '<S422>/Add2' */
    mcb_pmsm_foc_f28379d_dyno_B.Add2 = mcb_pmsm_foc_f28379d_dyno_B.one_by_two_k
      + mcb_pmsm_foc_f28379d_dyno_B.add_c;

    /* Sum: '<S422>/Add3' */
    mcb_pmsm_foc_f28379d_dyno_B.Add3 =
      mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.algDD_o1 +
      mcb_pmsm_foc_f28379d_dyno_B.one_by_two_k;

    /* Gain: '<S422>/Gain' */
    mcb_pmsm_foc_f28379d_dyno_B.Gain_d[0] = 1.15470052F *
      mcb_pmsm_foc_f28379d_dyno_B.Add3;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_d[1] = 1.15470052F *
      mcb_pmsm_foc_f28379d_dyno_B.Add1_kg;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_d[2] = 1.15470052F *
      mcb_pmsm_foc_f28379d_dyno_B.Add2;

    /* Update for UnitDelay: '<S404>/Unit Delay' */
    mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_e[0] =
      mcb_pmsm_foc_f28379d_dyno_B.Add1_ft[0];
    mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_e[1] =
      mcb_pmsm_foc_f28379d_dyno_B.Add1_ft[1];
  } else {
    mcb_pmsm_foc_f28379d_dyno_DWork.ClosedLoopControl_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S250>/Closed Loop Control' */

  /* SignalConversion generated from: '<S2>/mtr2_debug' */
  mcb_pmsm_foc_f28379d_dyno_B.mtr2_VI_debug_k[0] =
    mcb_pmsm_foc_f28379d_dyno_B.Add1_ft[0];
  mcb_pmsm_foc_f28379d_dyno_B.mtr2_VI_debug_k[1] =
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.algDD_o1;
  mcb_pmsm_foc_f28379d_dyno_B.mtr2_VI_debug_k[2] =
    mcb_pmsm_foc_f28379d_dyno_B.Sum_m;
  mcb_pmsm_foc_f28379d_dyno_B.mtr2_VI_debug_k[3] =
    mcb_pmsm_foc_f28379d_dyno_B.Add1_ft[1];
  mcb_pmsm_foc_f28379d_dyno_B.mtr2_VI_debug_k[4] =
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.algDD_o2;
  mcb_pmsm_foc_f28379d_dyno_B.mtr2_VI_debug_k[5] =
    mcb_pmsm_foc_f28379d_dyno_B.Sum1_g;

  /* SignalConversion generated from: '<S2>/mtr2_debug' */
  mcb_pmsm_foc_f28379d_dyno_B.mtr2_Te_PU_i =
    mcb_pmsm_foc_f28379d_dyno_B.T_output;

  /* SignalConversion generated from: '<S2>/mtr2_debug' */
  mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pm_PU_m =
    mcb_pmsm_foc_f28379d_dyno_B.P_output;

  /* SignalConversion generated from: '<S2>/mtr2_debug' */
  mcb_pmsm_foc_f28379d_dyno_B.mtr2_Speed_PU_h =
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Speed_PU_hk;

  /* SignalConversion generated from: '<S2>/mtr2_debug' */
  mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU_j[0] =
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU_jj[0];
  mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU_j[1] =
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU_jj[1];

  /* SignalConversion generated from: '<S2>/mtr2_debug' */
  mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pos_PU_d =
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pos_PU_db;

  /* DataStoreRead: '<S255>/Enable' */
  mcb_pmsm_foc_f28379d_dyno_B.PWM_En =
    mcb_pmsm_foc_f28379d_dyno_DWork.EnMtr2TrqCtrl;

  /* DataTypeConversion: '<S255>/Data Type Conversion' */
  mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion =
    mcb_pmsm_foc_f28379d_dyno_B.PWM_En;

  /* Logic: '<S461>/NOT' incorporates:
   *  Switch: '<S461>/Switch'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Activelowlogicforinverterenable =
    !(mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion != 0.0F);

  /* Switch: '<S461>/Switch' */
  mcb_pmsm_foc_f28379d_dyno_B.Switch_c =
    mcb_pmsm_foc_f28379d_dyno_B.Activelowlogicforinverterenable;

  /* S-Function (c280xgpio_do): '<S461>/Inverter enable' */
  {
    if (mcb_pmsm_foc_f28379d_dyno_B.Switch_c) {
      GpioDataRegs.GPASET.bit.GPIO26 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO26 = 1U;
    }
  }

  /* Switch: '<S461>/Switch1' */
  if (mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion >= 0.5F) {
    /* Switch: '<S250>/Switch' */
    if (mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_l) {
      /* Switch: '<S250>/Switch' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch_n[0] =
        mcb_pmsm_foc_f28379d_dyno_B.Gain_d[0];
      mcb_pmsm_foc_f28379d_dyno_B.Switch_n[1] =
        mcb_pmsm_foc_f28379d_dyno_B.Gain_d[1];
      mcb_pmsm_foc_f28379d_dyno_B.Switch_n[2] =
        mcb_pmsm_foc_f28379d_dyno_B.Gain_d[2];
    } else {
      /* Switch: '<S250>/Switch' incorporates:
       *  Constant: '<S250>/Constant'
       */
      mcb_pmsm_foc_f28379d_dyno_B.Switch_n[0] = 0.0F;
      mcb_pmsm_foc_f28379d_dyno_B.Switch_n[1] = 0.0F;
      mcb_pmsm_foc_f28379d_dyno_B.Switch_n[2] = 0.0F;
    }

    /* End of Switch: '<S250>/Switch' */

    /* Gain: '<S255>/One_by_Two' */
    Bias = 0.5F * mcb_pmsm_foc_f28379d_dyno_B.Switch_n[0];
    mcb_pmsm_foc_f28379d_dyno_B.One_by_Two[0] = Bias;

    /* Sum: '<S255>/Sum' incorporates:
     *  Constant: '<S255>/Constant'
     */
    Bias += 0.5F;
    mcb_pmsm_foc_f28379d_dyno_B.Mtr2_PWM_Duty_Cycles[0] = Bias;

    /* Gain: '<S461>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD = (uint16_T)(5000.0F * Bias);
    mcb_pmsm_foc_f28379d_dyno_B.Scale_to_PWM_Counter_PRD[0] =
      Scale_to_PWM_Counter_PRD;

    /* Switch: '<S461>/Switch1' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_o[0] = Scale_to_PWM_Counter_PRD;

    /* Gain: '<S255>/One_by_Two' */
    Bias = 0.5F * mcb_pmsm_foc_f28379d_dyno_B.Switch_n[1];
    mcb_pmsm_foc_f28379d_dyno_B.One_by_Two[1] = Bias;

    /* Sum: '<S255>/Sum' incorporates:
     *  Constant: '<S255>/Constant'
     */
    Bias += 0.5F;
    mcb_pmsm_foc_f28379d_dyno_B.Mtr2_PWM_Duty_Cycles[1] = Bias;

    /* Gain: '<S461>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD = (uint16_T)(5000.0F * Bias);
    mcb_pmsm_foc_f28379d_dyno_B.Scale_to_PWM_Counter_PRD[1] =
      Scale_to_PWM_Counter_PRD;

    /* Switch: '<S461>/Switch1' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_o[1] = Scale_to_PWM_Counter_PRD;

    /* Gain: '<S255>/One_by_Two' */
    Bias = 0.5F * mcb_pmsm_foc_f28379d_dyno_B.Switch_n[2];
    mcb_pmsm_foc_f28379d_dyno_B.One_by_Two[2] = Bias;

    /* Sum: '<S255>/Sum' incorporates:
     *  Constant: '<S255>/Constant'
     */
    Bias += 0.5F;
    mcb_pmsm_foc_f28379d_dyno_B.Mtr2_PWM_Duty_Cycles[2] = Bias;

    /* Gain: '<S461>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD = (uint16_T)(5000.0F * Bias);
    mcb_pmsm_foc_f28379d_dyno_B.Scale_to_PWM_Counter_PRD[2] =
      Scale_to_PWM_Counter_PRD;

    /* Switch: '<S461>/Switch1' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_o[2] = Scale_to_PWM_Counter_PRD;
  } else {
    /* Switch: '<S461>/Switch1' incorporates:
     *  Constant: '<S461>/stop'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_o[0] = 0U;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_o[1] = 0U;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_o[2] = 0U;
  }

  /* End of Switch: '<S461>/Switch1' */

  /* S-Function (c2802xpwm): '<S461>/ePWM4' */
  uint16_T tbprdValue4Outputs = EPwm4Regs.TBPRD;

  /*-- Update CMPA value for ePWM4 --*/
  {
    EPwm4Regs.CMPA.bit.CMPA = (uint16_T)(mcb_pmsm_foc_f28379d_dyno_B.Switch1_o[0]);
  }

  /* S-Function (c2802xpwm): '<S461>/ePWM5' */
  uint16_T tbprdValue5Outputs = EPwm5Regs.TBPRD;

  /*-- Update CMPA value for ePWM5 --*/
  {
    EPwm5Regs.CMPA.bit.CMPA = (uint16_T)(mcb_pmsm_foc_f28379d_dyno_B.Switch1_o[1]);
  }

  /* S-Function (c2802xpwm): '<S461>/ePWM6' */
  uint16_T tbprdValue6Outputs = EPwm6Regs.TBPRD;

  /*-- Update CMPA value for ePWM6 --*/
  {
    EPwm6Regs.CMPA.bit.CMPA = (uint16_T)(mcb_pmsm_foc_f28379d_dyno_B.Switch1_o[2]);
  }

  /* Update for Delay: '<S437>/Delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.Delay_DSTATE[mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx]
    = mcb_pmsm_foc_f28379d_dyno_B.PositionToCount;
  if (mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx < 19U) {
    mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx++;
  } else {
    mcb_pmsm_foc_f28379d_dyno_DWork.CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S437>/Delay' */

  /* Update for UnitDelay: '<S440>/Unit Delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_a =
    mcb_pmsm_foc_f28379d_dyno_B.Add1_i;
}

/*
 * Output and update for action system:
 *    '<S479>/If Action Subsystem'
 *    '<S487>/If Action Subsystem1'
 */
void mcb_pms_IfActionSubsystem_b(uint16_T rtu_In1, uint16_T rtu_In2,
  rtB_IfActionSubsystem_mcb_pms_d *localB, rtDW_IfActionSubsystem_mcb_pm_h
  *localDW)
{
  /* Memory: '<S484>/Memory' */
  localB->Memory = localDW->Memory_PreviousInput;

  /* Sum: '<S484>/Sum' */
  localB->Sum = rtu_In1 + localB->Memory;

  /* Memory: '<S484>/Memory1' */
  localB->Memory1 = localDW->Memory1_PreviousInput;

  /* Sum: '<S484>/Sum1' */
  localB->Sum1 = rtu_In2 + localB->Memory1;

  /* Update for Memory: '<S484>/Memory' */
  localDW->Memory_PreviousInput = localB->Sum;

  /* Update for Memory: '<S484>/Memory1' */
  localDW->Memory1_PreviousInput = localB->Sum1;
}

/*
 * Output and update for action system:
 *    '<S569>/D//Q Axis Priority'
 *    '<S646>/D//Q Axis Priority'
 */
void mcb_pmsm_f_DQAxisPriority_e(real32_T rtu_dqRef, real32_T rtu_dqRef_j,
  real32_T rtu_satLim, real32_T rtu_satLimSq, uint16_T rtu_satMethod, real32_T
  rty_dqSat[2], rtB_DQAxisPriority_mcb_pmsm_f_a *localB)
{
  /* RelationalOperator: '<S578>/Compare' incorporates:
   *  Constant: '<S578>/Constant'
   */
  localB->Compare = (rtu_satMethod == 1U);

  /* RelationalOperator: '<S579>/Compare' incorporates:
   *  Constant: '<S579>/Constant'
   */
  localB->Compare_i = (rtu_satMethod == 1U);

  /* Switch: '<S573>/Switch' */
  if (localB->Compare) {
    /* Switch: '<S573>/Switch' */
    localB->Switch[0] = rtu_dqRef;
    localB->Switch[1] = rtu_dqRef_j;
  } else {
    /* Switch: '<S573>/Switch' */
    localB->Switch[0] = rtu_dqRef_j;
    localB->Switch[1] = rtu_dqRef;
  }

  /* End of Switch: '<S573>/Switch' */

  /* RelationalOperator: '<S583>/LowerRelop1' */
  localB->LowerRelop1 = (localB->Switch[0] > rtu_satLim);

  /* Switch: '<S583>/Switch2' */
  if (localB->LowerRelop1) {
    /* Switch: '<S583>/Switch2' */
    localB->Switch2 = rtu_satLim;
  } else {
    /* Gain: '<S582>/Gain' */
    localB->Gain = -rtu_satLim;

    /* RelationalOperator: '<S583>/UpperRelop' */
    localB->UpperRelop = (localB->Switch[0] < localB->Gain);

    /* Switch: '<S583>/Switch' */
    if (localB->UpperRelop) {
      /* Switch: '<S583>/Switch' */
      localB->Switch_m = localB->Gain;
    } else {
      /* Switch: '<S583>/Switch' */
      localB->Switch_m = localB->Switch[0];
    }

    /* End of Switch: '<S583>/Switch' */

    /* Switch: '<S583>/Switch2' */
    localB->Switch2 = localB->Switch_m;
  }

  /* End of Switch: '<S583>/Switch2' */

  /* Product: '<S582>/Product' */
  localB->Product = localB->Switch2 * localB->Switch2;

  /* Sum: '<S582>/Sum' */
  localB->Sum = rtu_satLimSq - localB->Product;

  /* Product: '<S582>/Product2' */
  localB->Product2 = localB->Switch[1] * localB->Switch[1];

  /* RelationalOperator: '<S582>/Relational Operator' */
  localB->RelationalOperator = (localB->Sum >= localB->Product2);

  /* DataTypeConversion: '<S582>/Data Type Conversion' */
  localB->DataTypeConversion = localB->RelationalOperator;

  /* If: '<S582>/If' */
  if (localB->DataTypeConversion != 0U) {
    /* Outputs for IfAction SubSystem: '<S582>/passThrough' incorporates:
     *  ActionPort: '<S585>/Action Port'
     */
    /* Merge: '<S582>/Merge' incorporates:
     *  SignalConversion generated from: '<S585>/ref2'
     */
    localB->Merge = localB->Switch[1];

    /* End of Outputs for SubSystem: '<S582>/passThrough' */
  } else {
    /* Outputs for IfAction SubSystem: '<S582>/limitRef2' incorporates:
     *  ActionPort: '<S584>/Action Port'
     */
    mcb_pmsm_foc_f283_limitRef2(localB->Sum, localB->Switch[1], &localB->Merge,
      &localB->limitRef2);

    /* End of Outputs for SubSystem: '<S582>/limitRef2' */
  }

  /* End of If: '<S582>/If' */

  /* Switch: '<S573>/Switch1' */
  if (localB->Compare_i) {
    rty_dqSat[0] = localB->Switch2;
    rty_dqSat[1] = localB->Merge;
  } else {
    rty_dqSat[0] = localB->Merge;
    rty_dqSat[1] = localB->Switch2;
  }

  /* End of Switch: '<S573>/Switch1' */
}

/* System initialize for atomic system: '<Root>/Speed control for motor1' */
void Speedcontrolformotor1_Init(rtDW_Speedcontrolformotor1_mcb_ *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S564>/MATLAB Function' */
  localDW->integrator_state = 0.0F;
}

/* Output and update for atomic system: '<Root>/Speed control for motor1' */
void mcb_p_Speedcontrolformotor1(real32_T rtu_Speed_Ref_PU, real32_T
  rtu_Speed_Meas_PU, const boolean_T *rtd_EnMtrCtrl,
  rtB_Speedcontrolformotor1_mcb_p *localB, rtDW_Speedcontrolformotor1_mcb_
  *localDW)
{
  real32_T Trq_ref_unsat;
  real32_T y;

  /* Abs: '<S563>/Abs' */
  localB->Abs = fabsf(rtu_Speed_Meas_PU);

  /* RelationalOperator: '<S568>/Compare' incorporates:
   *  Constant: '<S568>/Constant'
   */
  localB->Compare = (localB->Abs >= 1.0F);

  /* Switch: '<S574>/Switch1' incorporates:
   *  Constant: '<S574>/ChosenMethod'
   */
  localB->Switch1_i = 1U;

  /* DataStoreRead: '<S565>/Data Store Read' */
  localB->DataStoreRead = *rtd_EnMtrCtrl;

  /* Switch: '<S565>/Switch' */
  if (localB->DataStoreRead) {
    /* Switch: '<S565>/Switch' */
    localB->Switch = rtu_Speed_Ref_PU;
  } else {
    /* Switch: '<S565>/Switch' */
    localB->Switch = rtu_Speed_Meas_PU;
  }

  /* End of Switch: '<S565>/Switch' */

  /* Switch: '<S642>/Switch1' incorporates:
   *  Constant: '<S642>/FilterConstant'
   *  Constant: '<S642>/OneMinusFilterConstant'
   */
  localB->Switch1[0] = 0.01F;
  localB->Switch1[1] = 0.99F;

  /* Product: '<S645>/Product' */
  localB->Product = localB->Switch * 0.01F;

  /* UnitDelay: '<S645>/Unit Delay' */
  localB->UnitDelay = localDW->UnitDelay_DSTATE;

  /* Product: '<S645>/Product1' */
  localB->Product1 = 0.99F * localB->UnitDelay;

  /* Sum: '<S645>/Add1' */
  localB->Add1 = localB->Product + localB->Product1;

  /* Sum: '<S564>/Sum' */
  localB->Sum = localB->Add1 - rtu_Speed_Meas_PU;

  /* DataStoreRead: '<S564>/Data Store Read1' */
  localB->DataStoreRead1 = *rtd_EnMtrCtrl;

  /* Logic: '<S564>/Logical Operator' */
  localB->LogicalOperator = !localB->DataStoreRead1;

  /* MATLAB Function: '<S564>/MATLAB Function' incorporates:
   *  Constant: '<S564>/Ki1'
   *  Constant: '<S564>/Ki2'
   *  Constant: '<S564>/Kp1'
   */
  /* MATLAB Function 'Speed control for motor1/PI_Controller_Speed/MATLAB Function': '<S587>:1' */
  if (localB->LogicalOperator) {
    /* '<S587>:1:21' */
    /* '<S587>:1:22' */
    localDW->integrator_state = 0.0F;
  }

  /* '<S587>:1:26' */
  /* '<S587>:1:29' */
  localDW->integrator_state += 0.0399242267F * localB->Sum;

  /* '<S587>:1:32' */
  Trq_ref_unsat = 1.90777314F * localB->Sum + localDW->integrator_state;

  /* '<S587>:1:35' */
  if (Trq_ref_unsat <= 1.0F) {
    y = Trq_ref_unsat;
  } else {
    y = 1.0F;
  }

  if (y >= -1.0F) {
    localB->Trq_ref = y;
  } else {
    localB->Trq_ref = -1.0F;
  }

  if (localB->Trq_ref != Trq_ref_unsat) {
    /* '<S587>:1:38' */
    /* '<S587>:1:39' */
    localDW->integrator_state -= 0.0399242267F * localB->Sum;
  }

  /* End of MATLAB Function: '<S564>/MATLAB Function' */

  /* Saturate: '<S567>/Saturation' */
  Trq_ref_unsat = localB->Trq_ref;
  if (Trq_ref_unsat > 0.473333329F) {
    /* Saturate: '<S567>/Saturation' */
    localB->Imag = 0.473333329F;
  } else if (Trq_ref_unsat < -0.473333329F) {
    /* Saturate: '<S567>/Saturation' */
    localB->Imag = -0.473333329F;
  } else {
    /* Saturate: '<S567>/Saturation' */
    localB->Imag = Trq_ref_unsat;
  }

  /* End of Saturate: '<S567>/Saturation' */

  /* Switch: '<S574>/Switch' incorporates:
   *  Constant: '<S574>/Constant3'
   */
  localB->Switch_b = 0.473333329F;

  /* Product: '<S574>/Product' */
  localB->Product_g = 0.224044442F;

  /* DataTypeConversion: '<S567>/Data Type Conversion' */
  localB->DataTypeConversion = localB->Compare;

  /* If: '<S567>/If' */
  if (localB->DataTypeConversion == 0U) {
    /* Outputs for IfAction SubSystem: '<S567>/MTPA condition' incorporates:
     *  ActionPort: '<S571>/Action Port'
     */
    /* Merge: '<S567>/Merge' incorporates:
     *  Constant: '<S571>/Constant'
     *  SignalConversion generated from: '<S571>/idref'
     */
    localB->Merge = 0.0F;

    /* End of Outputs for SubSystem: '<S567>/MTPA condition' */
  } else {
    /* Outputs for IfAction SubSystem: '<S567>/FWC with CVCP' incorporates:
     *  ActionPort: '<S570>/Action Port'
     */
    /* Math: '<S570>/Math Function'
     *
     * About '<S570>/Math Function':
     *  Operator: reciprocal
     */
    Trq_ref_unsat = localB->Abs;

    /* Math: '<S570>/Math Function'
     *
     * About '<S570>/Math Function':
     *  Operator: reciprocal
     */
    localB->MathFunction = 1.0F / Trq_ref_unsat;

    /* Gain: '<S570>/Gain' */
    localB->Gain = 2.13180518F * localB->MathFunction;

    /* Merge: '<S567>/Merge' incorporates:
     *  Constant: '<S570>/Constant'
     *  Sum: '<S570>/Add'
     */
    localB->Merge = localB->Gain - 2.13180518F;

    /* End of Outputs for SubSystem: '<S567>/FWC with CVCP' */
  }

  /* End of If: '<S567>/If' */

  /* Product: '<S575>/Product' */
  localB->Product_p = localB->Merge * localB->Merge;

  /* Product: '<S575>/Product1' */
  localB->Product1_i = localB->Imag * localB->Imag;

  /* Sum: '<S575>/Sum1' */
  localB->Sum1 = localB->Product_p + localB->Product1_i;

  /* Outputs for IfAction SubSystem: '<S569>/D//Q Axis Priority' incorporates:
   *  ActionPort: '<S573>/Action Port'
   */
  /* If: '<S569>/If' */
  mcb_pmsm_f_DQAxisPriority_e(localB->Merge, localB->Imag, 0.473333329F,
    0.224044442F, 1U, localB->Merge_d, &localB->DQAxisPriority);

  /* End of Outputs for SubSystem: '<S569>/D//Q Axis Priority' */

  /* Update for UnitDelay: '<S645>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->Add1;
}

/* Output and update for atomic system: '<Root>/Torque control for motor2' */
void mcb__Torquecontrolformotor2(real32_T rtu_Imag_Ref_PU, real32_T
  rtu_Imag_Pos_PU, real32_T rtu_Speed_Meas_PU, rtB_Torquecontrolformotor2_mcb_
  *localB)
{
  real32_T u0;
  uint32_T Sum;

  /* Gain: '<S9>/Convert_PU' incorporates:
   *  Constant: '<S9>/Speed_max (rpm)'
   */
  localB->Convert_PU = 1.0F;

  /* Switch: '<S651>/Switch1' incorporates:
   *  Constant: '<S651>/ChosenMethod'
   */
  localB->Switch1 = 3U;

  /* Abs: '<S647>/Abs1' */
  localB->Abs1 = 1.0F;

  /* Product: '<S647>/Product' */
  localB->Product = 0.1F;

  /* RelationalOperator: '<S663>/Compare' */
  localB->Compare = true;

  /* DataTypeConversion: '<S647>/Data Type Conversion' */
  localB->DataTypeConversion = 1U;

  /* Abs: '<S647>/Abs' */
  localB->Abs = fabsf(rtu_Speed_Meas_PU);

  /* Gain: '<S647>/derating' */
  localB->derating = 0.9F;

  /* Sum: '<S647>/Sum' */
  localB->Sum_c = localB->Abs - 0.9F;

  /* Outputs for IfAction SubSystem: '<S647>/If Action Subsystem' incorporates:
   *  ActionPort: '<S665>/Action Port'
   */
  /* If: '<S647>/If' incorporates:
   *  Product: '<S665>/Divide1'
   *  Saturate: '<S665>/Saturation'
   */
  localB->Divide1 = localB->Sum_c / 0.1F;
  u0 = localB->Divide1;
  if (u0 > 1.0F) {
    /* Merge: '<S647>/Merge' */
    localB->Merge = 1.0F;
  } else if (u0 < 0.0F) {
    /* Merge: '<S647>/Merge' */
    localB->Merge = 0.0F;
  } else {
    /* Merge: '<S647>/Merge' */
    localB->Merge = u0;
  }

  /* End of If: '<S647>/If' */
  /* End of Outputs for SubSystem: '<S647>/If Action Subsystem' */

  /* Sum: '<S647>/Sum2' incorporates:
   *  Constant: '<S647>/One'
   */
  localB->Sum2 = 1.0F - localB->Merge;

  /* Product: '<S9>/Product' */
  localB->Imag_ref = rtu_Imag_Ref_PU * localB->Sum2;

  /* RelationalOperator: '<S674>/Compare' incorporates:
   *  Constant: '<S674>/Constant'
   */
  localB->Compare_n = (rtu_Imag_Pos_PU < 0.0F);

  /* DataTypeConversion: '<S672>/Data Type Conversion' */
  localB->DataTypeConversion_p = localB->Compare_n;

  /* If: '<S672>/If' */
  if (localB->DataTypeConversion_p > 0U) {
    /* Outputs for IfAction SubSystem: '<S672>/If Action Subsystem' incorporates:
     *  ActionPort: '<S675>/Action Port'
     */
    mcb_pmsm__IfActionSubsystem(rtu_Imag_Pos_PU, &localB->Merge_p,
      &localB->IfActionSubsystem_o);

    /* End of Outputs for SubSystem: '<S672>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S672>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S676>/Action Port'
     */
    mcb_pmsm_IfActionSubsystem1(rtu_Imag_Pos_PU, &localB->Merge_p,
      &localB->IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S672>/If Action Subsystem1' */
  }

  /* End of If: '<S672>/If' */

  /* Gain: '<S670>/indexing' */
  localB->indexing = 800.0F * localB->Merge_p;

  /* DataTypeConversion: '<S670>/Get_Integer' */
  localB->Get_Integer = (uint16_T)localB->indexing;

  /* Sum: '<S670>/Sum' incorporates:
   *  Constant: '<S670>/offset'
   */
  Sum = localB->Get_Integer + 1UL;
  localB->Sum[0] = Sum;

  /* Selector: '<S670>/Lookup' incorporates:
   *  Constant: '<S670>/sine_table_values'
   */
  localB->Lookup[0] = mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum];

  /* Sum: '<S670>/Sum' */
  Sum = localB->Get_Integer;
  localB->Sum[1] = Sum;

  /* Selector: '<S670>/Lookup' incorporates:
   *  Constant: '<S670>/sine_table_values'
   */
  localB->Lookup[1] = mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum];

  /* Sum: '<S670>/Sum' incorporates:
   *  Constant: '<S670>/offset'
   */
  Sum = localB->Get_Integer + 201UL;
  localB->Sum[2] = Sum;

  /* Selector: '<S670>/Lookup' incorporates:
   *  Constant: '<S670>/sine_table_values'
   */
  localB->Lookup[2] = mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum];

  /* Sum: '<S670>/Sum' incorporates:
   *  Constant: '<S670>/offset'
   */
  Sum = localB->Get_Integer + 200UL;
  localB->Sum[3] = Sum;

  /* Selector: '<S670>/Lookup' incorporates:
   *  Constant: '<S670>/sine_table_values'
   */
  localB->Lookup[3] = mcb_pmsm_foc_f28379d_dyn_ConstP.pooled38[(int16_T)Sum];

  /* Sum: '<S671>/Sum3' */
  localB->Sum3 = localB->Lookup[0] - localB->Lookup[1];

  /* DataTypeConversion: '<S670>/Data Type Conversion1' */
  localB->DataTypeConversion1 = localB->Get_Integer;

  /* Sum: '<S670>/Sum2' */
  localB->Sum2_m = localB->indexing - localB->DataTypeConversion1;

  /* Product: '<S671>/Product' */
  localB->Product_d = localB->Sum3 * localB->Sum2_m;

  /* Sum: '<S671>/Sum4' */
  localB->Sum4 = localB->Product_d + localB->Lookup[1];

  /* Sum: '<S671>/Sum5' */
  localB->Sum5 = localB->Lookup[2] - localB->Lookup[3];

  /* Product: '<S671>/Product1' */
  localB->Product1 = localB->Sum5 * localB->Sum2_m;

  /* Sum: '<S671>/Sum6' */
  localB->Sum6 = localB->Product1 + localB->Lookup[3];

  /* Outputs for Atomic SubSystem: '<S666>/Two inputs CRL' */
  /* Constant: '<S648>/Constant' */
  mcb_pmsm_foc_f_TwoinputsCRL(localB->Imag_ref, 0.0F, localB->Sum4, localB->Sum6,
    &localB->TwoinputsCRL);

  /* End of Outputs for SubSystem: '<S666>/Two inputs CRL' */

  /* Switch: '<S651>/Switch' incorporates:
   *  Constant: '<S651>/Constant3'
   */
  localB->Switch = 0.473333329F;

  /* Product: '<S651>/Product' */
  localB->Product_f = 0.224044442F;

  /* Product: '<S652>/Product' */
  localB->Product_k = localB->TwoinputsCRL.algDD_o1 *
    localB->TwoinputsCRL.algDD_o1;

  /* Product: '<S652>/Product1' */
  localB->Product1_d = localB->TwoinputsCRL.algDD_o2 *
    localB->TwoinputsCRL.algDD_o2;

  /* Sum: '<S652>/Sum1' */
  localB->Sum1 = localB->Product_k + localB->Product1_d;

  /* Outputs for IfAction SubSystem: '<S646>/D-Q Equivalence' incorporates:
   *  ActionPort: '<S649>/Action Port'
   */
  /* If: '<S646>/If' */
  mcb_pmsm_foc__DQEquivalence(localB->TwoinputsCRL.algDD_o1,
    localB->TwoinputsCRL.algDD_o2, localB->Sum1, 0.473333329F, 0.224044442F,
    localB->Merge_j, &localB->DQEquivalence);

  /* End of Outputs for SubSystem: '<S646>/D-Q Equivalence' */
}

/* Model step function for TID0 */
void mcb_pmsm_foc_f28379d_dyno_step0(void) /* Sample time: [2.5E-5s, 0.0s] */
{
  real_T cosOut;
  real_T sinOut;

  {                                    /* Sample time: [2.5E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* DataStoreRead: '<S6>/Data Store Read1' */
  mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_i =
    mcb_pmsm_foc_f28379d_dyno_DWork.EnMtr2TrqCtrl;

  /* DataStoreRead: '<S6>/Data Store Read2' */
  mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead2_d =
    mcb_pmsm_foc_f28379d_dyno_DWork.EnMtr2TrqCtrl;

  /* DiscreteIntegrator: '<S499>/Discrete-Time Integrator' */
  mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator =
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<S6>/Gain' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain =
    -mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator;

  /* DiscreteIntegrator: '<S517>/Discrete-Time Integrator3' */
  if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_IC_LOAD != 0U) {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTATE =
      mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_l;
    if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTATE > 1.0E+7)
    {
      mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTATE = 1.0E+7;
    } else if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTATE <
               -1.0E+7) {
      mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTATE = -1.0E+7;
    }
  }

  /* DiscreteIntegrator: '<S517>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3 =
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* UnitDelay: '<S502>/Unit Delay' */
  mcb_pmsm_foc_f28379d_dyno_B.UnitDelay =
    mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE;

  /* RelationalOperator: '<S504>/Compare' incorporates:
   *  Constant: '<S504>/Constant'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Compare = (mcb_pmsm_foc_f28379d_dyno_B.UnitDelay >=
    -3.1415926535897931);

  /* Switch: '<S502>/Switch1' */
  if (mcb_pmsm_foc_f28379d_dyno_B.Compare) {
    /* RelationalOperator: '<S503>/Compare' incorporates:
     *  Constant: '<S503>/Constant'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Compare_b =
      (mcb_pmsm_foc_f28379d_dyno_B.UnitDelay <= 3.1415926535897931);

    /* Switch: '<S502>/Switch' */
    if (mcb_pmsm_foc_f28379d_dyno_B.Compare_b) {
      /* Switch: '<S502>/Switch' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch_a =
        mcb_pmsm_foc_f28379d_dyno_B.UnitDelay;
    } else {
      /* Sum: '<S502>/Subtract' incorporates:
       *  Constant: '<S502>/Constant3'
       */
      mcb_pmsm_foc_f28379d_dyno_B.Subtract_m =
        mcb_pmsm_foc_f28379d_dyno_B.UnitDelay - 6.2831854820251465;

      /* Switch: '<S502>/Switch' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch_a =
        mcb_pmsm_foc_f28379d_dyno_B.Subtract_m;
    }

    /* End of Switch: '<S502>/Switch' */

    /* Switch: '<S502>/Switch1' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1 = mcb_pmsm_foc_f28379d_dyno_B.Switch_a;
  } else {
    /* Sum: '<S502>/Add1' incorporates:
     *  Constant: '<S502>/Constant1'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Add1_e = mcb_pmsm_foc_f28379d_dyno_B.UnitDelay +
      6.2831854820251465;

    /* Switch: '<S502>/Switch1' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1 = mcb_pmsm_foc_f28379d_dyno_B.Add1_e;
  }

  /* End of Switch: '<S502>/Switch1' */

  /* Gain: '<S499>/Gain4' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain4 = 4.0 * mcb_pmsm_foc_f28379d_dyno_B.Switch1;

  /* Trigonometry: '<S501>/sine_cosine' */
  cosOut = mcb_pmsm_foc_f28379d_dyno_B.Gain4;
  sinOut = sin(cosOut);
  cosOut = cos(cosOut);

  /* Trigonometry: '<S501>/sine_cosine' */
  mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o1 = sinOut;

  /* Trigonometry: '<S501>/sine_cosine' */
  mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o2 = cosOut;

  /* Product: '<S512>/Product2' */
  mcb_pmsm_foc_f28379d_dyno_B.Product2 =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3 *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o2;

  /* DiscreteIntegrator: '<S518>/Discrete-Time Integrator3' */
  if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_IC_LO_f != 0U) {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_j =
      mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_h;
    if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_j > 1.0E+7)
    {
      mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_j = 1.0E+7;
    } else if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_j <
               -1.0E+7) {
      mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_j = -1.0E+7;
    }
  }

  /* DiscreteIntegrator: '<S518>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_f =
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_j;

  /* Product: '<S512>/Product3' */
  mcb_pmsm_foc_f28379d_dyno_B.Product3 =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_f *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o1;

  /* Sum: '<S512>/Add1' */
  mcb_pmsm_foc_f28379d_dyno_B.Add1 = mcb_pmsm_foc_f28379d_dyno_B.Product2 -
    mcb_pmsm_foc_f28379d_dyno_B.Product3;

  /* SignalConversion generated from: '<S498>/Vector Concatenate' incorporates:
   *  Concatenate: '<S498>/Vector Concatenate'
   */
  mcb_pmsm_foc_f28379d_dyno_B.VectorConcatenate[0] =
    mcb_pmsm_foc_f28379d_dyno_B.Add1;

  /* DiscreteIntegrator: '<S546>/Discrete-Time Integrator3' */
  if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_IC_L_f5 != 0U) {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_p =
      mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_ik;
    if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_p > 1.0E+7)
    {
      mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_p = 1.0E+7;
    } else if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_p <
               -1.0E+7) {
      mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_p = -1.0E+7;
    }
  }

  /* DiscreteIntegrator: '<S546>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_c =
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_p;

  /* DiscreteIntegrator: '<S547>/Discrete-Time Integrator3' */
  if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_IC_LO_a != 0U) {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_h =
      mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_nu;
    if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_h > 1.0E+7)
    {
      mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_h = 1.0E+7;
    } else if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_h <
               -1.0E+7) {
      mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_h = -1.0E+7;
    }
  }

  /* DiscreteIntegrator: '<S547>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_j =
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_h;

  /* Switch: '<S6>/Switch2' */
  if (mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead1_i) {
    /* Gain: '<S542>/Gain1' */
    mcb_pmsm_foc_f28379d_dyno_B.Gain1_n = 0.0063954151868927875 *
      mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_j;

    /* Product: '<S542>/Product' */
    mcb_pmsm_foc_f28379d_dyno_B.Product_fb =
      mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_c *
      mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_j;

    /* Product: '<S545>/Product' */
    mcb_pmsm_foc_f28379d_dyno_B.Product_k =
      mcb_pmsm_foc_f28379d_dyno_B.Product_fb *
      mcb_pmsm_foc_f28379d_dyn_ConstB.Add_g;

    /* Sum: '<S542>/Add' */
    mcb_pmsm_foc_f28379d_dyno_B.Add_d1 = mcb_pmsm_foc_f28379d_dyno_B.Product_k +
      mcb_pmsm_foc_f28379d_dyno_B.Gain1_n;

    /* Gain: '<S542>/Gain2' */
    mcb_pmsm_foc_f28379d_dyno_B.Gain2_bo = 6.0 *
      mcb_pmsm_foc_f28379d_dyno_B.Add_d1;

    /* Switch: '<S6>/Switch2' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch2 = mcb_pmsm_foc_f28379d_dyno_B.Gain2_bo;
  } else {
    /* Switch: '<S6>/Switch2' incorporates:
     *  Constant: '<S6>/Constant2'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Switch2 = 0.0;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Product: '<S513>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3 *
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_f;

  /* Product: '<S516>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_a = mcb_pmsm_foc_f28379d_dyno_B.Product *
    mcb_pmsm_foc_f28379d_dyn_ConstB.Add;

  /* Gain: '<S513>/Gain1' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain1 = 0.0063954151868927875 *
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_f;

  /* Sum: '<S513>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add = mcb_pmsm_foc_f28379d_dyno_B.Product_a +
    mcb_pmsm_foc_f28379d_dyno_B.Gain1;

  /* Gain: '<S513>/Gain2' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain2 = 6.0 * mcb_pmsm_foc_f28379d_dyno_B.Add;

  /* Product: '<S499>/Divide2' */
  mcb_pmsm_foc_f28379d_dyno_B.Divide2 =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator *
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector2;

  /* Signum: '<S499>/Sign' */
  cosOut = mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator;
  if (rtIsNaN(cosOut)) {
    /* Signum: '<S499>/Sign' */
    mcb_pmsm_foc_f28379d_dyno_B.Sign = (rtNaN);
  } else if (cosOut < 0.0) {
    /* Signum: '<S499>/Sign' */
    mcb_pmsm_foc_f28379d_dyno_B.Sign = -1.0;
  } else {
    /* Signum: '<S499>/Sign' */
    mcb_pmsm_foc_f28379d_dyno_B.Sign = (cosOut > 0.0);
  }

  /* End of Signum: '<S499>/Sign' */

  /* Product: '<S499>/Divide1' */
  mcb_pmsm_foc_f28379d_dyno_B.Divide1 =
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector1 *
    mcb_pmsm_foc_f28379d_dyno_B.Sign;

  /* Sum: '<S499>/Sum1' */
  mcb_pmsm_foc_f28379d_dyno_B.Sum1 = ((mcb_pmsm_foc_f28379d_dyno_B.Gain2 -
    mcb_pmsm_foc_f28379d_dyno_B.Switch2) - mcb_pmsm_foc_f28379d_dyno_B.Divide2)
    - mcb_pmsm_foc_f28379d_dyno_B.Divide1;

  /* Product: '<S499>/Divide' */
  mcb_pmsm_foc_f28379d_dyno_B.Divide = mcb_pmsm_foc_f28379d_dyno_B.Sum1 /
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector;

  /* Gain: '<S499>/Gain' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain_f = 4.0 *
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator;

  /* Gain: '<S502>/Gain1' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain1_p = 2.5E-5 *
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator;

  /* Sum: '<S502>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_b = mcb_pmsm_foc_f28379d_dyno_B.Gain1_p +
    mcb_pmsm_foc_f28379d_dyno_B.Switch1;

  /* Gain: '<S510>/Gain' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain_b = 0.0;

  /* Gain: '<S510>/Gain1' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain1_f = -0.0;

  /* Gain: '<S510>/Gain4' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain4_j = -0.0;

  /* Sum: '<S510>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_n = (mcb_pmsm_foc_f28379d_dyno_B.Gain_b +
    mcb_pmsm_foc_f28379d_dyno_B.Gain1_f) + mcb_pmsm_foc_f28379d_dyno_B.Gain4_j;

  /* Gain: '<S510>/Gain2' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain2_j = 0.0;

  /* Gain: '<S510>/Gain3' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain3 = -0.0;

  /* Sum: '<S510>/Add1' */
  mcb_pmsm_foc_f28379d_dyno_B.Add1_c = mcb_pmsm_foc_f28379d_dyno_B.Gain2_j +
    mcb_pmsm_foc_f28379d_dyno_B.Gain3;

  /* Gain: '<S511>/Gain1' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain1_p0 = -0.5 * mcb_pmsm_foc_f28379d_dyno_B.Add1;

  /* Gain: '<S511>/Gain2' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain2_c = -0.5 * mcb_pmsm_foc_f28379d_dyno_B.Add1;

  /* Product: '<S512>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_f =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3 *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o1;

  /* Product: '<S512>/Product1' */
  mcb_pmsm_foc_f28379d_dyno_B.Product1 =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_f *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o2;

  /* Sum: '<S512>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_e = mcb_pmsm_foc_f28379d_dyno_B.Product_f +
    mcb_pmsm_foc_f28379d_dyno_B.Product1;

  /* Gain: '<S511>/Gain3' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain3_l = 0.8660254037844386 *
    mcb_pmsm_foc_f28379d_dyno_B.Add_e;

  /* Gain: '<S511>/Gain4' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain4_h = -0.8660254037844386 *
    mcb_pmsm_foc_f28379d_dyno_B.Add_e;

  /* Sum: '<S511>/Subtract1' incorporates:
   *  Concatenate: '<S498>/Vector Concatenate'
   */
  mcb_pmsm_foc_f28379d_dyno_B.VectorConcatenate[1] =
    mcb_pmsm_foc_f28379d_dyno_B.Gain2_c + mcb_pmsm_foc_f28379d_dyno_B.Gain3_l;

  /* Sum: '<S511>/Subtract2' incorporates:
   *  Concatenate: '<S498>/Vector Concatenate'
   */
  mcb_pmsm_foc_f28379d_dyno_B.VectorConcatenate[2] =
    mcb_pmsm_foc_f28379d_dyno_B.Gain1_p0 + mcb_pmsm_foc_f28379d_dyno_B.Gain4_h;

  /* Product: '<S515>/Product2' */
  mcb_pmsm_foc_f28379d_dyno_B.Product2_e = mcb_pmsm_foc_f28379d_dyno_B.Add_n *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o2;

  /* Product: '<S515>/Product3' */
  mcb_pmsm_foc_f28379d_dyno_B.Product3_k = mcb_pmsm_foc_f28379d_dyno_B.Add1_c *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o1;

  /* Sum: '<S515>/Add1' */
  mcb_pmsm_foc_f28379d_dyno_B.Add1_k = mcb_pmsm_foc_f28379d_dyno_B.Product2_e +
    mcb_pmsm_foc_f28379d_dyno_B.Product3_k;

  /* Product: '<S519>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_j = mcb_pmsm_foc_f28379d_dyno_B.Add1_k /
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_j;

  /* Product: '<S517>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_ju = mcb_pmsm_foc_f28379d_dyno_B.Gain_f *
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_f;

  /* Product: '<S520>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_l = mcb_pmsm_foc_f28379d_dyno_B.Product_ju
    * mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_lr /
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector2_m;

  /* Product: '<S521>/Product' incorporates:
   *  Constant: '<S521>/Constant'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Product_fy =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3 * 0.36 /
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_i;

  /* Sum: '<S517>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_i = (mcb_pmsm_foc_f28379d_dyno_B.Product_j +
    mcb_pmsm_foc_f28379d_dyno_B.Product_l) -
    mcb_pmsm_foc_f28379d_dyno_B.Product_fy;

  /* Product: '<S515>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_c = mcb_pmsm_foc_f28379d_dyno_B.Add_n *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o1;

  /* Product: '<S515>/Product1' */
  mcb_pmsm_foc_f28379d_dyno_B.Product1_p = mcb_pmsm_foc_f28379d_dyno_B.Add1_c *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o2;

  /* Sum: '<S515>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_p = mcb_pmsm_foc_f28379d_dyno_B.Product1_p -
    mcb_pmsm_foc_f28379d_dyno_B.Product_c;

  /* Product: '<S522>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_p = mcb_pmsm_foc_f28379d_dyno_B.Add_p /
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_e;

  /* Product: '<S518>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_i =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3 *
    mcb_pmsm_foc_f28379d_dyno_B.Gain_f;

  /* Product: '<S523>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_b = mcb_pmsm_foc_f28379d_dyno_B.Product_i *
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_n /
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector1_h;

  /* Product: '<S524>/Product' incorporates:
   *  Constant: '<S524>/Constant'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Product_d = mcb_pmsm_foc_f28379d_dyno_B.Gain_f *
    0.0063954151868927875 / mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_g;

  /* Product: '<S525>/Product' incorporates:
   *  Constant: '<S525>/Constant'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Product_ff =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_f * 0.36 /
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_l1;

  /* Sum: '<S518>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_bp = ((mcb_pmsm_foc_f28379d_dyno_B.Product_p -
    mcb_pmsm_foc_f28379d_dyno_B.Product_b) -
    mcb_pmsm_foc_f28379d_dyno_B.Product_d) -
    mcb_pmsm_foc_f28379d_dyno_B.Product_ff;

  /* UnitDelay: '<S531>/Unit Delay' */
  mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_b =
    mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_b;

  /* RelationalOperator: '<S533>/Compare' incorporates:
   *  Constant: '<S533>/Constant'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Compare_h =
    (mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_b >= -3.1415926535897931);

  /* Switch: '<S531>/Switch1' */
  if (mcb_pmsm_foc_f28379d_dyno_B.Compare_h) {
    /* RelationalOperator: '<S532>/Compare' incorporates:
     *  Constant: '<S532>/Constant'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Compare_m =
      (mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_b <= 3.1415926535897931);

    /* Switch: '<S531>/Switch' */
    if (mcb_pmsm_foc_f28379d_dyno_B.Compare_m) {
      /* Switch: '<S531>/Switch' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch =
        mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_b;
    } else {
      /* Sum: '<S531>/Subtract' incorporates:
       *  Constant: '<S531>/Constant3'
       */
      mcb_pmsm_foc_f28379d_dyno_B.Subtract =
        mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_b - 6.2831854820251465;

      /* Switch: '<S531>/Switch' */
      mcb_pmsm_foc_f28379d_dyno_B.Switch = mcb_pmsm_foc_f28379d_dyno_B.Subtract;
    }

    /* End of Switch: '<S531>/Switch' */

    /* Switch: '<S531>/Switch1' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_j = mcb_pmsm_foc_f28379d_dyno_B.Switch;
  } else {
    /* Sum: '<S531>/Add1' incorporates:
     *  Constant: '<S531>/Constant1'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Add1_h = mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_b
      + 6.2831854820251465;

    /* Switch: '<S531>/Switch1' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_j = mcb_pmsm_foc_f28379d_dyno_B.Add1_h;
  }

  /* End of Switch: '<S531>/Switch1' */

  /* Gain: '<S528>/Gain4' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain4_n = 4.0 *
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_j;

  /* Trigonometry: '<S530>/sine_cosine' */
  cosOut = mcb_pmsm_foc_f28379d_dyno_B.Gain4_n;
  sinOut = sin(cosOut);
  cosOut = cos(cosOut);

  /* Trigonometry: '<S530>/sine_cosine' */
  mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o1_l = sinOut;

  /* Trigonometry: '<S530>/sine_cosine' */
  mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o2_j = cosOut;

  /* Product: '<S541>/Product2' */
  mcb_pmsm_foc_f28379d_dyno_B.Product2_o =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_c *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o2_j;

  /* Product: '<S541>/Product3' */
  mcb_pmsm_foc_f28379d_dyno_B.Product3_h =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_j *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o1_l;

  /* Sum: '<S541>/Add1' */
  mcb_pmsm_foc_f28379d_dyno_B.Add1_m = mcb_pmsm_foc_f28379d_dyno_B.Product2_o -
    mcb_pmsm_foc_f28379d_dyno_B.Product3_h;

  /* SignalConversion generated from: '<S527>/Vector Concatenate' incorporates:
   *  Concatenate: '<S527>/Vector Concatenate'
   */
  mcb_pmsm_foc_f28379d_dyno_B.VectorConcatenate_j[0] =
    mcb_pmsm_foc_f28379d_dyno_B.Add1_m;

  /* Gain: '<S528>/Gain' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain_i = 4.0 * mcb_pmsm_foc_f28379d_dyno_B.Gain;

  /* Gain: '<S531>/Gain1' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain1_fb = 2.5E-5 *
    mcb_pmsm_foc_f28379d_dyno_B.Gain;

  /* Sum: '<S531>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_bd = mcb_pmsm_foc_f28379d_dyno_B.Gain1_fb +
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_j;

  /* Switch: '<S6>/Switch1' */
  mcb_pmsm_foc_f28379d_dyno_B.Switch1_p[0] = 0.0;
  mcb_pmsm_foc_f28379d_dyno_B.Switch1_p[1] = 0.0;
  mcb_pmsm_foc_f28379d_dyno_B.Switch1_p[2] = 0.0;

  /* Gain: '<S539>/Gain' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain_p = 0.66666666666666663 *
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_p[0];

  /* Gain: '<S539>/Gain1' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain1_fm = -0.33333333333333331 *
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_p[1];

  /* Gain: '<S539>/Gain4' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain4_i = -0.33333333333333331 *
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_p[2];

  /* Sum: '<S539>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_a = (mcb_pmsm_foc_f28379d_dyno_B.Gain_p +
    mcb_pmsm_foc_f28379d_dyno_B.Gain1_fm) + mcb_pmsm_foc_f28379d_dyno_B.Gain4_i;

  /* Gain: '<S539>/Gain2' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain2_d = 0.57735026918962573 *
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_p[1];

  /* Gain: '<S539>/Gain3' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain3_e = -0.57735026918962573 *
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_p[2];

  /* Sum: '<S539>/Add1' */
  mcb_pmsm_foc_f28379d_dyno_B.Add1_n = mcb_pmsm_foc_f28379d_dyno_B.Gain2_d +
    mcb_pmsm_foc_f28379d_dyno_B.Gain3_e;

  /* Gain: '<S540>/Gain1' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain1_m = -0.5 *
    mcb_pmsm_foc_f28379d_dyno_B.Add1_m;

  /* Gain: '<S540>/Gain2' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain2_b = -0.5 *
    mcb_pmsm_foc_f28379d_dyno_B.Add1_m;

  /* Product: '<S541>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_ld =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_c *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o1_l;

  /* Product: '<S541>/Product1' */
  mcb_pmsm_foc_f28379d_dyno_B.Product1_i =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_j *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o2_j;

  /* Sum: '<S541>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_d = mcb_pmsm_foc_f28379d_dyno_B.Product_ld +
    mcb_pmsm_foc_f28379d_dyno_B.Product1_i;

  /* Gain: '<S540>/Gain3' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain3_l1 = 0.8660254037844386 *
    mcb_pmsm_foc_f28379d_dyno_B.Add_d;

  /* Gain: '<S540>/Gain4' */
  mcb_pmsm_foc_f28379d_dyno_B.Gain4_e = -0.8660254037844386 *
    mcb_pmsm_foc_f28379d_dyno_B.Add_d;

  /* Sum: '<S540>/Subtract1' incorporates:
   *  Concatenate: '<S527>/Vector Concatenate'
   */
  mcb_pmsm_foc_f28379d_dyno_B.VectorConcatenate_j[1] =
    mcb_pmsm_foc_f28379d_dyno_B.Gain2_b + mcb_pmsm_foc_f28379d_dyno_B.Gain3_l1;

  /* Sum: '<S540>/Subtract2' incorporates:
   *  Concatenate: '<S527>/Vector Concatenate'
   */
  mcb_pmsm_foc_f28379d_dyno_B.VectorConcatenate_j[2] =
    mcb_pmsm_foc_f28379d_dyno_B.Gain1_m + mcb_pmsm_foc_f28379d_dyno_B.Gain4_e;

  /* Product: '<S544>/Product2' */
  mcb_pmsm_foc_f28379d_dyno_B.Product2_f = mcb_pmsm_foc_f28379d_dyno_B.Add_a *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o2_j;

  /* Product: '<S544>/Product3' */
  mcb_pmsm_foc_f28379d_dyno_B.Product3_o = mcb_pmsm_foc_f28379d_dyno_B.Add1_n *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o1_l;

  /* Sum: '<S544>/Add1' */
  mcb_pmsm_foc_f28379d_dyno_B.Add1_f = mcb_pmsm_foc_f28379d_dyno_B.Product2_f +
    mcb_pmsm_foc_f28379d_dyno_B.Product3_o;

  /* Product: '<S548>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_av = mcb_pmsm_foc_f28379d_dyno_B.Add1_f /
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_n1;

  /* Product: '<S546>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_m = mcb_pmsm_foc_f28379d_dyno_B.Gain_i *
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_j;

  /* Product: '<S549>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_dj = mcb_pmsm_foc_f28379d_dyno_B.Product_m
    * mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_h1 /
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector1_k;

  /* Product: '<S550>/Product' incorporates:
   *  Constant: '<S550>/Constant'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Product_bb =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_c * 0.36 /
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_hp;

  /* Sum: '<S546>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_ex = (mcb_pmsm_foc_f28379d_dyno_B.Product_av +
    mcb_pmsm_foc_f28379d_dyno_B.Product_dj) -
    mcb_pmsm_foc_f28379d_dyno_B.Product_bb;

  /* Product: '<S544>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_di = mcb_pmsm_foc_f28379d_dyno_B.Add_a *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o1_l;

  /* Product: '<S544>/Product1' */
  mcb_pmsm_foc_f28379d_dyno_B.Product1_ih = mcb_pmsm_foc_f28379d_dyno_B.Add1_n *
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o2_j;

  /* Sum: '<S544>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_a4 = mcb_pmsm_foc_f28379d_dyno_B.Product1_ih -
    mcb_pmsm_foc_f28379d_dyno_B.Product_di;

  /* Product: '<S551>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_n = mcb_pmsm_foc_f28379d_dyno_B.Add_a4 /
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_bx;

  /* Product: '<S547>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_e =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_c *
    mcb_pmsm_foc_f28379d_dyno_B.Gain_i;

  /* Product: '<S552>/Product' */
  mcb_pmsm_foc_f28379d_dyno_B.Product_f3 = mcb_pmsm_foc_f28379d_dyno_B.Product_e
    * mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_f /
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector1_o;

  /* Product: '<S553>/Product' incorporates:
   *  Constant: '<S553>/Constant'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Product_aa = mcb_pmsm_foc_f28379d_dyno_B.Gain_i *
    0.0063954151868927875 / mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_p;

  /* Product: '<S554>/Product' incorporates:
   *  Constant: '<S554>/Constant'
   */
  mcb_pmsm_foc_f28379d_dyno_B.Product_g =
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_j * 0.36 /
    mcb_pmsm_foc_f28379d_dyn_ConstB.IndexVector_m;

  /* Sum: '<S547>/Add' */
  mcb_pmsm_foc_f28379d_dyno_B.Add_f = ((mcb_pmsm_foc_f28379d_dyno_B.Product_n -
    mcb_pmsm_foc_f28379d_dyno_B.Product_f3) -
    mcb_pmsm_foc_f28379d_dyno_B.Product_aa) -
    mcb_pmsm_foc_f28379d_dyno_B.Product_g;

  /* Update for DiscreteIntegrator: '<S499>/Discrete-Time Integrator' */
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator_DSTATE += 2.5E-5 *
    mcb_pmsm_foc_f28379d_dyno_B.Divide;
  if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator_DSTATE > 1.0E+7) {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator_DSTATE = 1.0E+7;
  } else if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator_DSTATE <
             -1.0E+7) {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator_DSTATE = -1.0E+7;
  }

  /* End of Update for DiscreteIntegrator: '<S499>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S517>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_IC_LOAD = 0U;
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTATE += 2.5E-5 *
    mcb_pmsm_foc_f28379d_dyno_B.Add_i;
  if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTATE > 1.0E+7) {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTATE = 1.0E+7;
  } else if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTATE <
             -1.0E+7) {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTATE = -1.0E+7;
  }

  /* End of Update for DiscreteIntegrator: '<S517>/Discrete-Time Integrator3' */

  /* Update for UnitDelay: '<S502>/Unit Delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE =
    mcb_pmsm_foc_f28379d_dyno_B.Add_b;

  /* Update for DiscreteIntegrator: '<S518>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_IC_LO_f = 0U;
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_j += 2.5E-5 *
    mcb_pmsm_foc_f28379d_dyno_B.Add_bp;
  if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_j > 1.0E+7)
  {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_j = 1.0E+7;
  } else if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_j <
             -1.0E+7) {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_j = -1.0E+7;
  }

  /* End of Update for DiscreteIntegrator: '<S518>/Discrete-Time Integrator3' */

  /* Update for DiscreteIntegrator: '<S546>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_IC_L_f5 = 0U;
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_p += 2.5E-5 *
    mcb_pmsm_foc_f28379d_dyno_B.Add_ex;
  if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_p > 1.0E+7)
  {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_p = 1.0E+7;
  } else if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_p <
             -1.0E+7) {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_p = -1.0E+7;
  }

  /* End of Update for DiscreteIntegrator: '<S546>/Discrete-Time Integrator3' */

  /* Update for DiscreteIntegrator: '<S547>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_IC_LO_a = 0U;
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_h += 2.5E-5 *
    mcb_pmsm_foc_f28379d_dyno_B.Add_f;
  if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_h > 1.0E+7)
  {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_h = 1.0E+7;
  } else if (mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_h <
             -1.0E+7) {
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_h = -1.0E+7;
  }

  /* End of Update for DiscreteIntegrator: '<S547>/Discrete-Time Integrator3' */

  /* Update for UnitDelay: '<S531>/Unit Delay' */
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_b =
    mcb_pmsm_foc_f28379d_dyno_B.Add_bd;
}

/* Model step function for TID1 */
void mcb_pmsm_foc_f28379d_dyno_step1(void) /* Sample time: [0.0005s, 0.0s] */
{
  /* RateTransition: '<Root>/RT1' */
  mcb_pmsm_foc_f28379d_dyno_DWork.RT1_semaphoreTaken =
    mcb_pmsm_foc_f28379d_dyno_DWork.RT1_ActiveBufIdx;

  /* RateTransition: '<Root>/RT1' */
  mcb_pmsm_foc_f28379d_dyno_B.RT1 =
    mcb_pmsm_foc_f28379d_dyno_DWork.RT1_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT1_semaphoreTaken];

  /* RateTransition: '<Root>/RT10' */
  mcb_pmsm_foc_f28379d_dyno_B.RT10 =
    mcb_pmsm_foc_f28379d_dyno_DWork.RT10_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT10_ActiveBufIdx];

  /* RateTransition: '<Root>/RT3' */
  mcb_pmsm_foc_f28379d_dyno_B.RT3 =
    mcb_pmsm_foc_f28379d_dyno_DWork.RT3_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT3_ActiveBufIdx];

  /* Outputs for Atomic SubSystem: '<Root>/Speed control for motor1' */
  mcb_p_Speedcontrolformotor1(mcb_pmsm_foc_f28379d_dyno_B.RT3,
    mcb_pmsm_foc_f28379d_dyno_B.RT1, &mcb_pmsm_foc_f28379d_dyno_DWork.EnMtrCtrl,
    &mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1,
    &mcb_pmsm_foc_f28379d_dyno_DWork.Speedcontrolformotor1);

  /* End of Outputs for SubSystem: '<Root>/Speed control for motor1' */

  /* RateTransition: '<Root>/RT2' */
  mcb_pmsm_foc_f28379d_dyno_DWork.RT2_Buffer
    [(mcb_pmsm_foc_f28379d_dyno_DWork.RT2_ActiveBufIdx == 0) << 1U] =
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Merge_d[0];
  mcb_pmsm_foc_f28379d_dyno_DWork.RT2_Buffer[1 +
    ((mcb_pmsm_foc_f28379d_dyno_DWork.RT2_ActiveBufIdx == 0) << 1U)] =
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Merge_d[1];
  mcb_pmsm_foc_f28379d_dyno_DWork.RT2_ActiveBufIdx =
    (mcb_pmsm_foc_f28379d_dyno_DWork.RT2_ActiveBufIdx == 0);

  /* RateTransition: '<Root>/RT9' */
  mcb_pmsm_foc_f28379d_dyno_B.RT9 =
    mcb_pmsm_foc_f28379d_dyno_DWork.RT9_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT9_ActiveBufIdx];

  /* RateTransition: '<Root>/RT8' */
  mcb_pmsm_foc_f28379d_dyno_DWork.RT8_semaphoreTaken =
    mcb_pmsm_foc_f28379d_dyno_DWork.RT8_ActiveBufIdx;

  /* RateTransition: '<Root>/RT8' */
  mcb_pmsm_foc_f28379d_dyno_B.RT8 =
    mcb_pmsm_foc_f28379d_dyno_DWork.RT8_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT8_semaphoreTaken];

  /* Outputs for Atomic SubSystem: '<Root>/Torque control for motor2' */
  mcb__Torquecontrolformotor2(mcb_pmsm_foc_f28379d_dyno_B.RT9,
    mcb_pmsm_foc_f28379d_dyno_B.RT10, mcb_pmsm_foc_f28379d_dyno_B.RT8,
    &mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2);

  /* End of Outputs for SubSystem: '<Root>/Torque control for motor2' */

  /* RateTransition: '<Root>/RT7' */
  mcb_pmsm_foc_f28379d_dyno_DWork.RT7_Buffer
    [(mcb_pmsm_foc_f28379d_dyno_DWork.RT7_ActiveBufIdx == 0) << 1U] =
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Merge_j[0];
  mcb_pmsm_foc_f28379d_dyno_DWork.RT7_Buffer[1 +
    ((mcb_pmsm_foc_f28379d_dyno_DWork.RT7_ActiveBufIdx == 0) << 1U)] =
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Merge_j[1];
  mcb_pmsm_foc_f28379d_dyno_DWork.RT7_ActiveBufIdx =
    (mcb_pmsm_foc_f28379d_dyno_DWork.RT7_ActiveBufIdx == 0);
}

/* Model step function for TID2 */
void mcb_pmsm_foc_f28379d_dyno_step2(void) /* Sample time: [0.5s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* S-Function (c280xgpio_do): '<S494>/Digital Output' incorporates:
   *  Constant: '<S5>/RED_LED'
   */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)((1U) != 0);
  }

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void mcb_pmsm_foc_f28379d_dyno_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mcb_pmsm_foc_f28379d_dyno_M, 0,
                sizeof(RT_MODEL_mcb_pmsm_foc_f28379d_d));

  /* block I/O */
  (void) memset(((void *) &mcb_pmsm_foc_f28379d_dyno_B), 0,
                sizeof(BlockIO_mcb_pmsm_foc_f28379d_dy));

  {
    int16_T i;
    for (i = 0; i < 6; i++) {
      mcb_pmsm_foc_f28379d_dyno_B.mtr2_VI_debug[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      mcb_pmsm_foc_f28379d_dyno_B.mtr2_VI_debug_k[i] = 0.0F;
    }

    for (i = 0; i < 25; i++) {
      mcb_pmsm_foc_f28379d_dyno_B.TmpSignalConversionAtSelectorIn[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      mcb_pmsm_foc_f28379d_dyno_B.mtr1_VI_debug[i] = 0.0F;
    }

    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain4 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o1 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o2 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product2 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_f = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product3 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add1 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_c = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.DiscreteTimeIntegrator3_j = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Switch2 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_a = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain1 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain2 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Divide2 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Sign = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Divide1 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Sum1 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Divide = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_f = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain1_p = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add_b = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_b = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain1_f = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain4_j = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add_n = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain2_j = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain3 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_c = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain1_p0 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain2_c = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_f = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product1 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add_e = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain3_l = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain4_h = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product2_e = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product3_k = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_k = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_j = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_ju = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_l = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_fy = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add_i = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_c = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_p = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add_p = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_p = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_i = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_b = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_d = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_ff = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add_bp = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.VectorConcatenate[0] = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.VectorConcatenate[1] = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.VectorConcatenate[2] = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_b = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_j = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain4_n = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o1_l = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.sine_cosine_o2_j = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product2_o = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product3_h = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_m = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_i = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain1_fb = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add_bd = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_p[0] = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_p[1] = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_p[2] = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_p = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain1_fm = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain4_i = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add_a = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain2_d = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain3_e = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_n = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain1_m = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain2_b = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_ld = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_i = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add_d = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain3_l1 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain4_e = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product2_f = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product3_o = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_f = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_av = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_m = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_dj = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_bb = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add_ex = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_di = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_ih = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add_a4 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_n = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_e = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_f3 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_aa = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_g = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add_f = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.VectorConcatenate_j[0] = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.VectorConcatenate_j[1] = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.VectorConcatenate_j[2] = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain1_n = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_fb = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Product_k = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add_d1 = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Gain2_bo = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_h = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Switch = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Subtract = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_e = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_a = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.Subtract_m = 0.0;
    mcb_pmsm_foc_f28379d_dyno_B.RT1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.RT10 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.RT3 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.RT9 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.RT8 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.RT2[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.RT2[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Te_PU = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pm_PU = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Speed_PU = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pos_PU = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.RT7[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.RT7[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[2] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[3] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.OutportBufferForDesiredImagpos = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.OutportBufferForDesriedImagref = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.GetADCVoltage[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.GetADCVoltage[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.GetCurrents[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.GetCurrents[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.PU_Conversion[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.PU_Conversion[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentmea[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentmea[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DTC = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_ib = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DTC_k = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.SpeedGain = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_pe[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_pe[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_mq = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_g = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_n = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_i = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_f = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Merge = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Numberofpolepairs = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Floor = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add_exa = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Te_PU_i = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pm_PU_m = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Speed_PU_h = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU_j[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU_j[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pos_PU_d = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_c = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_n[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_n[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_n[2] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.One_by_Two[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.One_by_Two[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.One_by_Two[2] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Mtr2_PWM_Duty_Cycles[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Mtr2_PWM_Duty_Cycles[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Mtr2_PWM_Duty_Cycles[2] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_m = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add_c = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Speed_PU_hk = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU_jj[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU_jj[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pos_PU_db = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_h[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_h[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_cc[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_cc[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_e[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_e[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_e[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_e[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_ft[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_ft[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Merge_l = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.indexing = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Lookup[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Lookup[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Lookup[2] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Lookup[3] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum3 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum2 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_h = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum4 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum5 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_ns = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum6 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_jx = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.we = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Ld_id = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.fluxD = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.VqFF_unsat = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch2_j = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum1_g = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_o = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.w_Lq_iq = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.VdFF_unsat = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch2_k = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_m = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_o = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_cg = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_ae = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_j = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum1_a = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Merge_d[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Merge_d[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.id_Ld_Lq = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add_b3 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product3_l = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.u_5_Pp = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_ee = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.P_output = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.T_output = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.one_by_two = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.sqrt3_by_two = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.add_b = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.add_c = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Max = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Min = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add_o = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.one_by_two_k = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_kg = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add2 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add3 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_d[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_d[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_d[2] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_k = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_ns = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.GetADCVoltage_b[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.GetADCVoltage_b[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.GetCurrents_n[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.GetCurrents_n[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.PU_Conversion_d[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.PU_Conversion_d[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentm_h[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.InvertingNoninvertingCurrentm_h[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DTC_i = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_ie = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DTC_a = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.SpeedGain_f = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_i[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_i[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_fp = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_eq = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_m = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_g = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_e = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Merge_n = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Numberofpolepairs_i = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Floor_g = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add_nd = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_speed_ref_PU = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Selector[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Selector[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion_i = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_k0 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_h[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_h[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_h[2] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.One_by_Two_n[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.One_by_Two_n[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.One_by_Two_n[2] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Mtr1_PWM_Duty_Cycles[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Mtr1_PWM_Duty_Cycles[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Mtr1_PWM_Duty_Cycles[2] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.rpm2freq = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Eps = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_bc = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Frequency = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Vbyf = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Correction_Factor_sinePWM = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Amplitude = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.UnaryMinus = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.position_increment = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.scaleIn = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.UnitDelay_l = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.scaleOut = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DataStoreRead = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Eps_k = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.convert_pu = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Merge_h = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.indexing_h = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[2] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_a[3] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum3_b = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion1_a = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum2_p = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_g4 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum4_i = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum5_g = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_m4 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum6_n = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Ka = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.one_by_two_h = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.sqrt3_by_two_d = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.add_b_m = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Kb = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.add_c_o = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Kc = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Divide_h = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sample_Time = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_h = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add_f4 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion1_i = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_c5 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Input = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Merge_lj = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.indexing_l = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[2] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Lookup_f[3] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum3_o = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion1_m = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum2_f = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_kl = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum4_b = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum5_h = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_iu = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum6_m = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_c = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.we_n = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.w_Lq_iq_b = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.VdFF_unsat_o = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch2_o = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_hy = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum_k = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Ld_id_j = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.fluxD_h = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.VqFF_unsat_b = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch2_e = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum1_n = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_Speed_PU = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_Iab_meas_PU[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_Iab_meas_PU[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.mtr1_Pos_PU = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_l = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_lu = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_p1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product1_m4h = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Sum1_f = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Merge_f[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Merge_f[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.id_Ld_Lq_c = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add_op = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product3_o4 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.u_5_Pp_a = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Product_bm = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.P_output_a = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.T_output_f = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.one_by_two_m = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.sqrt3_by_two_g = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.add_b_b = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.add_c_m = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Max_d = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Min_n = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add_g = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.one_by_two_e = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add1_o = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add2_l = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Add3_b = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_db[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_db[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Gain_db[2] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_b = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Switch_aa = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Convert_PU = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Abs1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Product = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Abs = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.derating = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Sum_c = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Merge = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Sum2 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Imag_ref = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Merge_p = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.indexing = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Lookup[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Lookup[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Lookup[2] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Lookup[3] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Sum3 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DataTypeConversion1 =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Sum2_m = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Product_d = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Sum4 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Sum5 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Product1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Sum6 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Switch = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Product_f = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Product_k = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Product1_d = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Sum1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Merge_j[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Merge_j[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.Divide1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.IfActionSubsystem1.Convert_back
      = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.IfActionSubsystem_o.Convert_back
      = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.TwoinputsCRL.qcos = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.TwoinputsCRL.dsin = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.TwoinputsCRL.sum_beta =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.TwoinputsCRL.dcos = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.TwoinputsCRL.qsin = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.TwoinputsCRL.sum_alpha =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.TwoinputsCRL.Switch[0] =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.TwoinputsCRL.Switch[1] =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.TwoinputsCRL.algDD_o1 =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.TwoinputsCRL.algDD_o2 =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQEquivalence.Product[0] =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQEquivalence.Product[1] =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQEquivalence.SquareRoot =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQEquivalence.Switch =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQAxisPriority.Switch[0] =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQAxisPriority.Switch[1] =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQAxisPriority.Switch2 =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQAxisPriority.Product =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQAxisPriority.Sum = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQAxisPriority.Product2 =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQAxisPriority.Merge =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQAxisPriority.Gain =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQAxisPriority.Switch_m =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQAxisPriority.limitRef2.Switch1
      = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQAxisPriority.limitRef2.Sqrt
      = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Torquecontrolformotor2.DQAxisPriority.limitRef2.Gain
      = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Abs = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Switch = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Switch1[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Switch1[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Product = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.UnitDelay = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Product1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Add1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Sum = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Imag = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Switch_b = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Product_g = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Merge = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Product_p = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Product1_i = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Sum1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Merge_d[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Merge_d[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Trq_ref = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.MathFunction = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.Gain = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQEquivalence.Product[0] =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQEquivalence.Product[1] =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQEquivalence.SquareRoot =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQEquivalence.Switch =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQAxisPriority.Switch[0] =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQAxisPriority.Switch[1] =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQAxisPriority.Switch2 =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQAxisPriority.Product =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQAxisPriority.Sum = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQAxisPriority.Product2 =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQAxisPriority.Merge =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQAxisPriority.Gain = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQAxisPriority.Switch_m =
      0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQAxisPriority.limitRef2.Switch1
      = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQAxisPriority.limitRef2.Sqrt
      = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.Speedcontrolformotor1.DQAxisPriority.limitRef2.Gain
      = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem1_i.Convert_back = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem_e.Convert_back = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.acos_l = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.bsin = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.sum_Ds = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.bcos = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.asin_d = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.sum_Qs = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.Switch[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.Switch[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.algDD_o1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_i.algDD_o2 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.qcos = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.dsin = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.sum_beta = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.dcos = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.qsin = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.sum_alpha = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.Switch[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.Switch[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.algDD_o1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_c.algDD_o2 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.sf_MATLABFunction_k.V_q_ref = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.sf_MATLABFunction_i.V_d_ref = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQEquivalence_f.Product[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQEquivalence_f.Product[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQEquivalence_f.SquareRoot = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQEquivalence_f.Switch = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority_k.Switch[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority_k.Switch[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority_k.Switch2 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority_k.Product = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority_k.Sum = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority_k.Product2 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority_k.Merge = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority_k.Gain = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority_k.Switch_l = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority_k.limitRef2.Switch1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority_k.limitRef2.Sqrt = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority_k.limitRef2.Gain = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap_h.a_plus_2b = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap_h.one_by_sqrt3 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap_h.algDD_o1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap_h.algDD_o2 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem1_l.Convert_back = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem_b.Convert_back = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a.qcos = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a.dsin = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a.sum_beta = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a.dcos = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a.qsin = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a.sum_alpha = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a.Switch[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a.Switch[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a.algDD_o1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_a.algDD_o2 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem1_k.Convert_back = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem_p.Convert_back = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.acos_l = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.bsin = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.sum_Ds = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.bcos = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.asin_d = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.sum_Qs = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.Switch[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.Switch[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.algDD_o1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL_o.algDD_o2 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.qcos = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.dsin = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.sum_beta = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.dcos = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.qsin = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.sum_alpha = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.Switch[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.Switch[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.algDD_o1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwoinputsCRL.algDD_o2 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.sf_MATLABFunction_j.V_q_ref = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.sf_MATLABFunction.V_d_ref = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQEquivalence.Product[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQEquivalence.Product[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQEquivalence.SquareRoot = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQEquivalence.Switch = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority.Switch[0] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority.Switch[1] = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority.Switch2 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority.Product = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority.Sum = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority.Product2 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority.Merge = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority.Gain = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority.Switch_l = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority.limitRef2.Switch1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority.limitRef2.Sqrt = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.DQAxisPriority.limitRef2.Gain = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap.a_plus_2b = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap.one_by_sqrt3 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap.algDD_o1 = 0.0F;
    mcb_pmsm_foc_f28379d_dyno_B.TwophaseCRLwrap.algDD_o2 = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&mcb_pmsm_foc_f28379d_dyno_DWork, 0,
                sizeof(D_Work_mcb_pmsm_foc_f28379d_dyn));
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator_DSTATE = 0.0;
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTATE = 0.0;
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE = 0.0;
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_j = 0.0;
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_p = 0.0;
  mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_DSTAT_h = 0.0;
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_b = 0.0;
  mcb_pmsm_foc_f28379d_dyno_DWork.Add1_DWORK1 = 0.0;
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_a = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_l = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_e[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_e[1] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_az = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RampGenerator_DSTATE = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.UnitDelay_DSTATE_ex = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT1_Buffer[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT1_Buffer[1] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT10_Buffer[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT10_Buffer[1] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT3_Buffer[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT3_Buffer[1] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT2_Buffer[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT2_Buffer[1] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT2_Buffer[2] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT2_Buffer[3] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT9_Buffer[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT9_Buffer[1] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT8_Buffer[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT8_Buffer[1] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT7_Buffer[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT7_Buffer[1] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT7_Buffer[2] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT7_Buffer[3] = 0.0F;

  {
    int16_T i;
    for (i = 0; i < 12; i++) {
      mcb_pmsm_foc_f28379d_dyno_DWork.RT6_1_Buffer[i] = 0.0F;
    }
  }

  mcb_pmsm_foc_f28379d_dyno_DWork.RT6_2_Buffer[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT6_2_Buffer[1] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT6_3_Buffer[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT6_3_Buffer[1] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT6_4_Buffer[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT6_4_Buffer[1] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT6_5_Buffer[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT6_5_Buffer[1] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT6_5_Buffer[2] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT6_5_Buffer[3] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT6_6_Buffer[0] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.RT6_6_Buffer[1] = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.SpeedRef = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.Add_DWORK1 = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.Speedcontrolformotor1.UnitDelay_DSTATE = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.Speedcontrolformotor1.integrator_state = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction_k.integrator_state = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction_i.integrator_state = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction_j.integrator_state = 0.0F;
  mcb_pmsm_foc_f28379d_dyno_DWork.sf_MATLABFunction.integrator_state = 0.0F;

  {
    uint16_T s479_iter;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    mcb_pmsm_foc_f28379d_dyno_DWork.IaOffset_motor1 = 2247U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    mcb_pmsm_foc_f28379d_dyno_DWork.IbOffset_motor1 = 2245U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    mcb_pmsm_foc_f28379d_dyno_DWork.Debug_signals = 5U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
    mcb_pmsm_foc_f28379d_dyno_DWork.IbOffset_motor2 = 2245U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
    mcb_pmsm_foc_f28379d_dyno_DWork.IaOffset_motor2 = 2245U;

    /* InitializeConditions for DiscreteIntegrator: '<S517>/Discrete-Time Integrator3' */
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_IC_LOAD = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S518>/Discrete-Time Integrator3' */
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_IC_LO_f = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S546>/Discrete-Time Integrator3' */
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_IC_L_f5 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S547>/Discrete-Time Integrator3' */
    mcb_pmsm_foc_f28379d_dyno_DWork.DiscreteTimeIntegrator3_IC_LO_a = 1U;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S467>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Current control for motor1'
     */
    Currentcontrolformotor_Init();

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S469>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Current control for motor2'
     */
    Currentcontrolformot_p_Init();

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S471>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Serial Receive'
     */
    /* System initialize for function-call system: '<Root>/Serial Receive' */

    /* Start for S-Function (c28xsci_rx): '<S562>/SCI Receive' */

    /* Initialize out port */
    {
      mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[0] = (real32_T)0.0;
      mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[1] = (real32_T)0.0;
      mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[2] = (real32_T)0.0;
      mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[3] = (real32_T)0.0;
    }

    /*Configure Timer2 when blocking mode is enabled and Timeout is not inf*/
    {
      /* InitCpuTimers() - CPU Timers are also initialized in
       * MW_c28xx_board.c in the generated code.
       */
      CpuTimer2Regs.PRD.all = 0xFFFFFFFFU;/* max Period*/
      CpuTimer2Regs.TIM.all = 0xFFFFFFFFU;/* set Ctr*/
      CpuTimer2Regs.TPR.all = 0x00U;   /* no prescaler    */
      StartCpuTimer2();
    }

    /* SystemInitialize for Atomic SubSystem: '<Root>/Speed control for motor1' */
    Speedcontrolformotor1_Init
      (&mcb_pmsm_foc_f28379d_dyno_DWork.Speedcontrolformotor1);

    /* End of SystemInitialize for SubSystem: '<Root>/Speed control for motor1' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
    /* Start for S-Function (c280xgpio_do): '<S494>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
    GpioCtrlRegs.GPBDIR.all |= 0x4U;
    EDIS;

    /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Hardware Init' */
    /* SystemInitialize for Atomic SubSystem: '<S473>/Enable DRV8305 for motor 1 and motor 2' */
    /* Start for S-Function (c280xgpio_do): '<S476>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
    GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<S476>/Bottom DRV8305 EN' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFCFFFFFU;
    GpioCtrlRegs.GPADIR.all |= 0x4000000U;
    EDIS;

    /* End of SystemInitialize for SubSystem: '<S473>/Enable DRV8305 for motor 1 and motor 2' */

    /* SystemInitialize for Atomic SubSystem: '<S473>/Calibrate ADC offset for motor 1 current sensor' */
    /* SystemInitialize for Enabled SubSystem: '<S474>/Calculate ADC Offset ' */
    /* SystemInitialize for Iterator SubSystem: '<S477>/For Iterator Subsystem' */
    /* Start for S-Function (c2802xadc): '<S479>/ADC_A_IN0' */
    if (MW_adcCInitFlag == 0U) {
      InitAdcC();
      MW_adcCInitFlag = 1U;
    }

    config_ADCC_SOC2 ();

    /* Start for S-Function (c2802xadc): '<S479>/ADC_B_IN0' */
    if (MW_adcBInitFlag == 0U) {
      InitAdcB();
      MW_adcBInitFlag = 1U;
    }

    config_ADCB_SOC2 ();

    /* End of SystemInitialize for SubSystem: '<S477>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S474>/Calculate ADC Offset ' */
    /* End of SystemInitialize for SubSystem: '<S473>/Calibrate ADC offset for motor 1 current sensor' */

    /* SystemInitialize for Atomic SubSystem: '<S473>/Calibrate ADC offset for motor 2 current sensor' */
    /* SystemInitialize for Enabled SubSystem: '<S475>/Calculate ADC Offset ' */
    /* SystemInitialize for Iterator SubSystem: '<S485>/For Iterator Subsystem' */
    /* Start for S-Function (c2802xadc): '<S487>/ADC_A_IN1' */
    if (MW_adcCInitFlag == 0U) {
      InitAdcC();
      MW_adcCInitFlag = 1U;
    }

    config_ADCC_SOC3 ();

    /* Start for S-Function (c2802xadc): '<S487>/ADC_B_IN1' */
    if (MW_adcBInitFlag == 0U) {
      InitAdcB();
      MW_adcBInitFlag = 1U;
    }

    config_ADCB_SOC3 ();

    /* End of SystemInitialize for SubSystem: '<S485>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S475>/Calculate ADC Offset ' */
    /* End of SystemInitialize for SubSystem: '<S473>/Calibrate ADC offset for motor 2 current sensor' */
    /* End of SystemInitialize for SubSystem: '<Root>/Hardware Init' */

    /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Outputs for Atomic SubSystem: '<S473>/Enable DRV8305 for motor 1 and motor 2' */
    /* Logic: '<S476>/NOT' */
    mcb_pmsm_foc_f28379d_dyno_B.NOT = false;

    /* Switch: '<S476>/Switch' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch_p = mcb_pmsm_foc_f28379d_dyno_B.NOT;

    /* S-Function (c280xgpio_do): '<S476>/Digital Output' */
    {
      if (mcb_pmsm_foc_f28379d_dyno_B.Switch_p) {
        GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
      } else {
        GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
      }
    }

    /* Logic: '<S476>/NOT1' */
    mcb_pmsm_foc_f28379d_dyno_B.NOT1 = false;

    /* Switch: '<S476>/Switch1' */
    mcb_pmsm_foc_f28379d_dyno_B.Switch1_i1 = mcb_pmsm_foc_f28379d_dyno_B.NOT1;

    /* S-Function (c280xgpio_do): '<S476>/Bottom DRV8305 EN' */
    {
      if (mcb_pmsm_foc_f28379d_dyno_B.Switch1_i1) {
        GpioDataRegs.GPASET.bit.GPIO26 = 1U;
      } else {
        GpioDataRegs.GPACLEAR.bit.GPIO26 = 1U;
      }
    }

    /* End of Outputs for SubSystem: '<S473>/Enable DRV8305 for motor 1 and motor 2' */

    /* Outputs for Atomic SubSystem: '<S473>/Calibrate ADC offset for motor 1 current sensor' */
    /* Outputs for Enabled SubSystem: '<S474>/Calculate ADC Offset ' incorporates:
     *  EnablePort: '<S477>/Enable'
     */
    /* Outputs for Iterator SubSystem: '<S477>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S479>/For Iterator'
     */
    for (s479_iter = 1U; s479_iter < 17U; s479_iter++) {
      /* Outputs for Iterator SubSystem: '<S477>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S479>/For Iterator'
       */
      mcb_pmsm_foc_f28379d_dyno_B.ForIterator_i = s479_iter;

      /* S-Function (c2802xadc): '<S479>/ADC_A_IN0' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdccRegs.ADCSOCFRC1.bit.SOC2 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        real32_T wait_index;
        for (wait_index= 12; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_pmsm_foc_f28379d_dyno_B.ADC_A_IN0 = (AdccResultRegs.ADCRESULT2);
      }

      /* S-Function (c2802xadc): '<S479>/ADC_B_IN0' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdcbRegs.ADCSOCFRC1.bit.SOC2 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        real32_T wait_index;
        for (wait_index= 12; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_pmsm_foc_f28379d_dyno_B.ADC_B_IN0 = (AdcbResultRegs.ADCRESULT2);
      }

      /* If: '<S479>/If' */
      if (mcb_pmsm_foc_f28379d_dyno_B.ForIterator_i > 8U) {
        /* Outputs for IfAction SubSystem: '<S479>/If Action Subsystem' incorporates:
         *  ActionPort: '<S484>/Action Port'
         */
        mcb_pms_IfActionSubsystem_b(mcb_pmsm_foc_f28379d_dyno_B.ADC_A_IN0,
          mcb_pmsm_foc_f28379d_dyno_B.ADC_B_IN0,
          &mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem_bv,
          &mcb_pmsm_foc_f28379d_dyno_DWork.IfActionSubsystem_bv);

        /* End of Outputs for SubSystem: '<S479>/If Action Subsystem' */
      }

      /* End of If: '<S479>/If' */
    }

    /* End of Outputs for SubSystem: '<S477>/For Iterator Subsystem' */

    /* Product: '<S477>/Divide' incorporates:
     *  Constant: '<S477>/Constant'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Divide_i = (uint16_T)((real_T)
      mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem_bv.Sum / 8.0);

    /* If: '<S477>/If' incorporates:
     *  Constant: '<S477>/Constant1'
     *  Constant: '<S477>/Constant2'
     */
    if ((mcb_pmsm_foc_f28379d_dyno_B.Divide_i > 1500U) &&
        (mcb_pmsm_foc_f28379d_dyno_B.Divide_i < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S477>/If Action Subsystem' incorporates:
       *  ActionPort: '<S480>/Action Port'
       */
      /* DataStoreWrite: '<S480>/Data Store Write1' */
      mcb_pmsm_foc_f28379d_dyno_DWork.IaOffset_motor1 =
        mcb_pmsm_foc_f28379d_dyno_B.Divide_i;

      /* End of Outputs for SubSystem: '<S477>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S477>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S481>/Action Port'
       */
      /* DataStoreWrite: '<S481>/Data Store Write1' incorporates:
       *  Constant: '<S481>/Constant'
       */
      mcb_pmsm_foc_f28379d_dyno_DWork.IaOffset_motor1 = 2247U;

      /* End of Outputs for SubSystem: '<S477>/If Action Subsystem1' */
    }

    /* End of If: '<S477>/If' */

    /* Product: '<S477>/Divide1' incorporates:
     *  Constant: '<S477>/Constant'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Divide1_c = (uint16_T)((real_T)
      mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem_bv.Sum1 / 8.0);

    /* If: '<S477>/If1' incorporates:
     *  Constant: '<S477>/Constant1'
     *  Constant: '<S477>/Constant2'
     */
    if ((mcb_pmsm_foc_f28379d_dyno_B.Divide1_c > 1500U) &&
        (mcb_pmsm_foc_f28379d_dyno_B.Divide1_c < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S477>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S482>/Action Port'
       */
      /* DataStoreWrite: '<S482>/Data Store Write2' */
      mcb_pmsm_foc_f28379d_dyno_DWork.IbOffset_motor1 =
        mcb_pmsm_foc_f28379d_dyno_B.Divide1_c;

      /* End of Outputs for SubSystem: '<S477>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S477>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S483>/Action Port'
       */
      /* DataStoreWrite: '<S483>/Data Store Write2' incorporates:
       *  Constant: '<S483>/Constant1'
       */
      mcb_pmsm_foc_f28379d_dyno_DWork.IbOffset_motor1 = 2245U;

      /* End of Outputs for SubSystem: '<S477>/If Action Subsystem3' */
    }

    /* End of If: '<S477>/If1' */
    /* End of Outputs for SubSystem: '<S474>/Calculate ADC Offset ' */

    /* Logic: '<S474>/NOT' incorporates:
     *  Constant: '<S474>/ADC Calib Enable'
     */
    mcb_pmsm_foc_f28379d_dyno_B.NOT_h = false;

    /* Outputs for Enabled SubSystem: '<S474>/Default ADC Offset' incorporates:
     *  EnablePort: '<S478>/Enable'
     */
    if (mcb_pmsm_foc_f28379d_dyno_B.NOT_h) {
      /* DataStoreWrite: '<S478>/Data Store Write1' incorporates:
       *  Constant: '<S478>/Constant'
       */
      mcb_pmsm_foc_f28379d_dyno_DWork.IaOffset_motor1 = 2247U;

      /* DataStoreWrite: '<S478>/Data Store Write2' incorporates:
       *  Constant: '<S478>/Constant1'
       */
      mcb_pmsm_foc_f28379d_dyno_DWork.IbOffset_motor1 = 2245U;
    }

    /* End of Outputs for SubSystem: '<S474>/Default ADC Offset' */
    /* End of Outputs for SubSystem: '<S473>/Calibrate ADC offset for motor 1 current sensor' */

    /* Outputs for Atomic SubSystem: '<S473>/Calibrate ADC offset for motor 2 current sensor' */
    /* Outputs for Enabled SubSystem: '<S475>/Calculate ADC Offset ' incorporates:
     *  EnablePort: '<S485>/Enable'
     */
    /* Outputs for Iterator SubSystem: '<S485>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S487>/For Iterator'
     */
    for (s479_iter = 1U; s479_iter < 17U; s479_iter++) {
      /* Outputs for Iterator SubSystem: '<S485>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S487>/For Iterator'
       */
      mcb_pmsm_foc_f28379d_dyno_B.ForIterator = s479_iter;

      /* S-Function (c2802xadc): '<S487>/ADC_A_IN1' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdccRegs.ADCSOCFRC1.bit.SOC3 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        real32_T wait_index;
        for (wait_index= 12; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_pmsm_foc_f28379d_dyno_B.ADC_A_IN1 = (AdccResultRegs.ADCRESULT3);
      }

      /* S-Function (c2802xadc): '<S487>/ADC_B_IN1' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdcbRegs.ADCSOCFRC1.bit.SOC3 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        real32_T wait_index;
        for (wait_index= 12; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_pmsm_foc_f28379d_dyno_B.ADC_B_IN1 = (AdcbResultRegs.ADCRESULT3);
      }

      /* If: '<S487>/If1' */
      if (mcb_pmsm_foc_f28379d_dyno_B.ForIterator > 8U) {
        /* Outputs for IfAction SubSystem: '<S487>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S492>/Action Port'
         */
        mcb_pms_IfActionSubsystem_b(mcb_pmsm_foc_f28379d_dyno_B.ADC_A_IN1,
          mcb_pmsm_foc_f28379d_dyno_B.ADC_B_IN1,
          &mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem1_j,
          &mcb_pmsm_foc_f28379d_dyno_DWork.IfActionSubsystem1_j);

        /* End of Outputs for SubSystem: '<S487>/If Action Subsystem1' */
      }

      /* End of If: '<S487>/If1' */
    }

    /* End of Outputs for SubSystem: '<S485>/For Iterator Subsystem' */

    /* Product: '<S485>/Divide2' incorporates:
     *  Constant: '<S485>/Constant1'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Divide2_e = (uint16_T)((real_T)
      mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem1_j.Sum / 8.0);

    /* If: '<S485>/If2' incorporates:
     *  Constant: '<S485>/Constant2'
     *  Constant: '<S485>/Constant3'
     */
    if ((mcb_pmsm_foc_f28379d_dyno_B.Divide2_e > 1500U) &&
        (mcb_pmsm_foc_f28379d_dyno_B.Divide2_e < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S485>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S488>/Action Port'
       */
      /* DataStoreWrite: '<S488>/Data Store Write1' */
      mcb_pmsm_foc_f28379d_dyno_DWork.IaOffset_motor2 =
        mcb_pmsm_foc_f28379d_dyno_B.Divide2_e;

      /* End of Outputs for SubSystem: '<S485>/If Action Subsystem4' */
    } else {
      /* Outputs for IfAction SubSystem: '<S485>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S489>/Action Port'
       */
      /* DataStoreWrite: '<S489>/Data Store Write1' incorporates:
       *  Constant: '<S489>/Constant'
       */
      mcb_pmsm_foc_f28379d_dyno_DWork.IaOffset_motor2 = 2247U;

      /* End of Outputs for SubSystem: '<S485>/If Action Subsystem5' */
    }

    /* End of If: '<S485>/If2' */

    /* Product: '<S485>/Divide3' incorporates:
     *  Constant: '<S485>/Constant1'
     */
    mcb_pmsm_foc_f28379d_dyno_B.Divide3 = (uint16_T)((real_T)
      mcb_pmsm_foc_f28379d_dyno_B.IfActionSubsystem1_j.Sum1 / 8.0);

    /* If: '<S485>/If3' incorporates:
     *  Constant: '<S485>/Constant2'
     *  Constant: '<S485>/Constant3'
     */
    if ((mcb_pmsm_foc_f28379d_dyno_B.Divide3 > 1500U) &&
        (mcb_pmsm_foc_f28379d_dyno_B.Divide3 < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S485>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S490>/Action Port'
       */
      /* DataStoreWrite: '<S490>/Data Store Write2' */
      mcb_pmsm_foc_f28379d_dyno_DWork.IbOffset_motor2 =
        mcb_pmsm_foc_f28379d_dyno_B.Divide3;

      /* End of Outputs for SubSystem: '<S485>/If Action Subsystem6' */
    } else {
      /* Outputs for IfAction SubSystem: '<S485>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S491>/Action Port'
       */
      /* DataStoreWrite: '<S491>/Data Store Write2' incorporates:
       *  Constant: '<S491>/Constant1'
       */
      mcb_pmsm_foc_f28379d_dyno_DWork.IbOffset_motor2 = 2245U;

      /* End of Outputs for SubSystem: '<S485>/If Action Subsystem7' */
    }

    /* End of If: '<S485>/If3' */
    /* End of Outputs for SubSystem: '<S475>/Calculate ADC Offset ' */

    /* Logic: '<S475>/NOT' incorporates:
     *  Constant: '<S475>/ADC Calib Enable'
     */
    mcb_pmsm_foc_f28379d_dyno_B.NOT_d = false;

    /* Outputs for Enabled SubSystem: '<S475>/Default ADC Offset' incorporates:
     *  EnablePort: '<S486>/Enable'
     */
    if (mcb_pmsm_foc_f28379d_dyno_B.NOT_d) {
      /* DataStoreWrite: '<S486>/Data Store Write3' incorporates:
       *  Constant: '<S486>/Constant2'
       */
      mcb_pmsm_foc_f28379d_dyno_DWork.IaOffset_motor2 = 2247U;

      /* DataStoreWrite: '<S486>/Data Store Write4' incorporates:
       *  Constant: '<S486>/Constant3'
       */
      mcb_pmsm_foc_f28379d_dyno_DWork.IbOffset_motor2 = 2245U;
    }

    /* End of Outputs for SubSystem: '<S475>/Default ADC Offset' */
    /* End of Outputs for SubSystem: '<S473>/Calibrate ADC offset for motor 2 current sensor' */
    /* End of Outputs for SubSystem: '<Root>/Hardware Init' */
  }
}

/* Model terminate function */
void mcb_pmsm_foc_f28379d_dyno_terminate(void)
{
  /* (no terminate code required) */
}

void mcb_pmsm_foc_f28379d_dyno_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(33,&ADCB1_INT,0);
  HWI_TIC28x_EnableIRQ(33);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(34,&ADCC1_INT,1);
  HWI_TIC28x_EnableIRQ(34);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(96,&SCIA_RX_INT,3);
  HWI_TIC28x_EnableIRQ(96);
}

/* Hardware Interrupt Block: '<S467>/Hardware Interrupt' */
interrupt void ADCB1_INT(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  volatile unsigned int PIEIER9_stack_save = PieCtrlRegs.PIEIER9.all;
  PieCtrlRegs.PIEIER1.all &= ~70;
                              /*disable group1 lower/equal priority interrupts*/
  PieCtrlRegs.PIEIER9.all &= ~1;
                              /*disable group9 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~257;    /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 257;
                   /*ACK to allow other interrupts from the same group to fire*/
  IER |= 1;
  EINT;

  /* Event: Default Event */
  if (1 == runModel) {
    {
      int16_T i;
      int16_T tmp;

      /* RateTransition: '<Root>/RT2' */
      tmp = mcb_pmsm_foc_f28379d_dyno_DWork.RT2_ActiveBufIdx << 1U;
      mcb_pmsm_foc_f28379d_dyno_B.RT2[0] =
        mcb_pmsm_foc_f28379d_dyno_DWork.RT2_Buffer[tmp];
      mcb_pmsm_foc_f28379d_dyno_B.RT2[1] =
        mcb_pmsm_foc_f28379d_dyno_DWork.RT2_Buffer[tmp + 1];

      /* RateTransition generated from: '<Root>/RT6' */
      tmp = mcb_pmsm_foc_f28379d_dyno_DWork.RT6_1_ActiveBufIdx * 6;
      for (i = 0; i < 6; i++) {
        mcb_pmsm_foc_f28379d_dyno_B.mtr2_VI_debug[i] =
          mcb_pmsm_foc_f28379d_dyno_DWork.RT6_1_Buffer[i + tmp];
      }

      /* RateTransition generated from: '<Root>/RT6' */
      mcb_pmsm_foc_f28379d_dyno_B.mtr2_Te_PU =
        mcb_pmsm_foc_f28379d_dyno_DWork.RT6_2_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT6_2_ActiveBufIdx];

      /* RateTransition generated from: '<Root>/RT6' */
      mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pm_PU =
        mcb_pmsm_foc_f28379d_dyno_DWork.RT6_3_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT6_3_ActiveBufIdx];

      /* RateTransition generated from: '<Root>/RT6' */
      mcb_pmsm_foc_f28379d_dyno_B.mtr2_Speed_PU =
        mcb_pmsm_foc_f28379d_dyno_DWork.RT6_4_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT6_4_ActiveBufIdx];

      /* RateTransition generated from: '<Root>/RT6' */
      tmp = mcb_pmsm_foc_f28379d_dyno_DWork.RT6_5_ActiveBufIdx << 1U;
      mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU[0] =
        mcb_pmsm_foc_f28379d_dyno_DWork.RT6_5_Buffer[tmp];
      mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU[1] =
        mcb_pmsm_foc_f28379d_dyno_DWork.RT6_5_Buffer[tmp + 1];

      /* RateTransition generated from: '<Root>/RT6' */
      mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pos_PU =
        mcb_pmsm_foc_f28379d_dyno_DWork.RT6_6_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT6_6_ActiveBufIdx];

      /* S-Function (HardwareInterrupt_sfun): '<S467>/Hardware Interrupt' */
      mcb_Currentcontrolformotor1();

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S467>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT1' */
      mcb_pmsm_foc_f28379d_dyno_DWork.RT1_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT1_semaphoreTaken
        == 0] = mcb_pmsm_foc_f28379d_dyno_B.Add1_g;
      mcb_pmsm_foc_f28379d_dyno_DWork.RT1_ActiveBufIdx =
        (mcb_pmsm_foc_f28379d_dyno_DWork.RT1_semaphoreTaken == 0);
    }
  }

  /* Clear occurred EOC event event */
  AdcbRegs.ADCINTFLGCLR.bit.ADCINT1= 1;

  /* Clear occurred Overflow event event */
  AdcbRegs.ADCINTOVFCLR.bit.ADCINT1= 1;
  DINT;
  /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;
                                   /*restore PIEIER register that was modified*/
  PieCtrlRegs.PIEIER9.all = PIEIER9_stack_save;
                                   /*restore PIEIER register that was modified*/
  HWI_TIC28x_AcknowledgeIrq(33);
}

/* Hardware Interrupt Block: '<S469>/Hardware Interrupt' */
interrupt void ADCC1_INT(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  volatile unsigned int PIEIER9_stack_save = PieCtrlRegs.PIEIER9.all;
  PieCtrlRegs.PIEIER1.all &= ~68;
                              /*disable group1 lower/equal priority interrupts*/
  PieCtrlRegs.PIEIER9.all &= ~1;
                              /*disable group9 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~257;    /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 257;
                   /*ACK to allow other interrupts from the same group to fire*/
  IER |= 1;
  EINT;

  /* Event: Default Event */
  if (1 == runModel) {
    {
      int16_T i;

      /* RateTransition: '<Root>/RT7' */
      i = mcb_pmsm_foc_f28379d_dyno_DWork.RT7_ActiveBufIdx << 1U;
      mcb_pmsm_foc_f28379d_dyno_B.RT7[0] =
        mcb_pmsm_foc_f28379d_dyno_DWork.RT7_Buffer[i];
      mcb_pmsm_foc_f28379d_dyno_B.RT7[1] =
        mcb_pmsm_foc_f28379d_dyno_DWork.RT7_Buffer[i + 1];

      /* S-Function (HardwareInterrupt_sfun): '<S469>/Hardware Interrupt' */
      mcb_Currentcontrolformotor2();

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S469>/Hardware Interrupt' */

      /* RateTransition generated from: '<Root>/RT6' */
      for (i = 0; i < 6; i++) {
        mcb_pmsm_foc_f28379d_dyno_DWork.RT6_1_Buffer[i +
          (mcb_pmsm_foc_f28379d_dyno_DWork.RT6_1_ActiveBufIdx == 0) * 6] =
          mcb_pmsm_foc_f28379d_dyno_B.mtr2_VI_debug_k[i];
      }

      mcb_pmsm_foc_f28379d_dyno_DWork.RT6_1_ActiveBufIdx =
        (mcb_pmsm_foc_f28379d_dyno_DWork.RT6_1_ActiveBufIdx == 0);

      /* RateTransition generated from: '<Root>/RT6' */
      mcb_pmsm_foc_f28379d_dyno_DWork.RT6_2_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT6_2_ActiveBufIdx
        == 0] = mcb_pmsm_foc_f28379d_dyno_B.mtr2_Te_PU_i;
      mcb_pmsm_foc_f28379d_dyno_DWork.RT6_2_ActiveBufIdx =
        (mcb_pmsm_foc_f28379d_dyno_DWork.RT6_2_ActiveBufIdx == 0);

      /* RateTransition generated from: '<Root>/RT6' */
      mcb_pmsm_foc_f28379d_dyno_DWork.RT6_3_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT6_3_ActiveBufIdx
        == 0] = mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pm_PU_m;
      mcb_pmsm_foc_f28379d_dyno_DWork.RT6_3_ActiveBufIdx =
        (mcb_pmsm_foc_f28379d_dyno_DWork.RT6_3_ActiveBufIdx == 0);

      /* RateTransition generated from: '<Root>/RT6' */
      mcb_pmsm_foc_f28379d_dyno_DWork.RT6_4_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT6_4_ActiveBufIdx
        == 0] = mcb_pmsm_foc_f28379d_dyno_B.mtr2_Speed_PU_h;
      mcb_pmsm_foc_f28379d_dyno_DWork.RT6_4_ActiveBufIdx =
        (mcb_pmsm_foc_f28379d_dyno_DWork.RT6_4_ActiveBufIdx == 0);

      /* RateTransition generated from: '<Root>/RT6' */
      mcb_pmsm_foc_f28379d_dyno_DWork.RT6_5_Buffer
        [(mcb_pmsm_foc_f28379d_dyno_DWork.RT6_5_ActiveBufIdx == 0) << 1U] =
        mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU_j[0];
      mcb_pmsm_foc_f28379d_dyno_DWork.RT6_5_Buffer[1 +
        ((mcb_pmsm_foc_f28379d_dyno_DWork.RT6_5_ActiveBufIdx == 0) << 1U)] =
        mcb_pmsm_foc_f28379d_dyno_B.mtr2_Iab_meas_PU_j[1];
      mcb_pmsm_foc_f28379d_dyno_DWork.RT6_5_ActiveBufIdx =
        (mcb_pmsm_foc_f28379d_dyno_DWork.RT6_5_ActiveBufIdx == 0);

      /* RateTransition generated from: '<Root>/RT6' */
      mcb_pmsm_foc_f28379d_dyno_DWork.RT6_6_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT6_6_ActiveBufIdx
        == 0] = mcb_pmsm_foc_f28379d_dyno_B.mtr2_Pos_PU_d;
      mcb_pmsm_foc_f28379d_dyno_DWork.RT6_6_ActiveBufIdx =
        (mcb_pmsm_foc_f28379d_dyno_DWork.RT6_6_ActiveBufIdx == 0);

      /* RateTransition: '<Root>/RT8' */
      mcb_pmsm_foc_f28379d_dyno_DWork.RT8_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT8_semaphoreTaken
        == 0] = mcb_pmsm_foc_f28379d_dyno_B.Add1_i;
      mcb_pmsm_foc_f28379d_dyno_DWork.RT8_ActiveBufIdx =
        (mcb_pmsm_foc_f28379d_dyno_DWork.RT8_semaphoreTaken == 0);
    }
  }

  /* Clear occurred EOC event event */
  AdccRegs.ADCINTFLGCLR.bit.ADCINT1= 1;

  /* Clear occurred Overflow event event */
  AdccRegs.ADCINTOVFCLR.bit.ADCINT1= 1;
  DINT;
  /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;
                                   /*restore PIEIER register that was modified*/
  PieCtrlRegs.PIEIER9.all = PIEIER9_stack_save;
                                   /*restore PIEIER register that was modified*/
  HWI_TIC28x_AcknowledgeIrq(34);
}

/* Hardware Interrupt Block: '<S471>/Hardware Interrupt' */
interrupt void SCIA_RX_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S471>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Serial Receive' */

      /* S-Function (c28xsci_rx): '<S562>/SCI Receive' */
      {
        int16_T i;
        int16_T errFlg = NOERROR;
        uint16_T isHeadReceived = 1U;

        //get data as uint16 in recBuff
        uint16_T recbuff[8];
        for (i = 0; i < 8; i++) {
          recbuff[i] = 0U;
        }

        errFlg = NOERROR;

        /* Receiving data: For uint32 and uint16, rcvBuff will contain uint16 data */
        if (isHeadReceived) {
          errFlg = scia_rcv(recbuff, 16, 4);
          asm(" NOP");
          if ((errFlg == NOERROR) || (errFlg == PARTIALDATA)) {
            memcpy( &mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[0], recbuff,8);
          }
        }
      }

      /* DataTypeConversion: '<S559>/Data Type Conversion2' */
      mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion2 = (uint16_T)
        mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[1];

      /* S-Function (sfix_bitop): '<S558>/Bitwise Operator' */
      mcb_pmsm_foc_f28379d_dyno_B.BitwiseOperator =
        mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion2 & 1U;

      /* DataTypeConversion: '<S558>/Data Type Conversion3' */
      mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion3 =
        (mcb_pmsm_foc_f28379d_dyno_B.BitwiseOperator != 0U);

      /* DataStoreWrite: '<S555>/Data Store Write' */
      mcb_pmsm_foc_f28379d_dyno_DWork.Enable =
        mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion3;

      /* DataStoreWrite: '<S555>/Data Store Write1' */
      mcb_pmsm_foc_f28379d_dyno_DWork.SpeedRef =
        mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[0];

      /* S-Function (sfix_bitop): '<S558>/Bitwise Operator1' */
      mcb_pmsm_foc_f28379d_dyno_B.BitwiseOperator1 =
        mcb_pmsm_foc_f28379d_dyno_B.DataTypeConversion2 & 240U;

      /* ArithShift: '<S558>/Shift Arithmetic1' incorporates:
       *  S-Function (sfix_bitop): '<S558>/Bitwise Operator1'
       */
      mcb_pmsm_foc_f28379d_dyno_B.ShiftArithmetic1 =
        mcb_pmsm_foc_f28379d_dyno_B.BitwiseOperator1 >> 4U;

      /* DataStoreWrite: '<S555>/Data Store Write2' */
      mcb_pmsm_foc_f28379d_dyno_DWork.Debug_signals =
        mcb_pmsm_foc_f28379d_dyno_B.ShiftArithmetic1;

      /* SignalConversion generated from: '<S7>/Desired Imagpos' */
      mcb_pmsm_foc_f28379d_dyno_B.OutportBufferForDesiredImagpos =
        mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[3];

      /* SignalConversion generated from: '<S7>/Desried Imag ref' */
      mcb_pmsm_foc_f28379d_dyno_B.OutportBufferForDesriedImagref =
        mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[2];

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S471>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT10' */
      mcb_pmsm_foc_f28379d_dyno_DWork.RT10_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT10_ActiveBufIdx
        == 0] = mcb_pmsm_foc_f28379d_dyno_B.OutportBufferForDesiredImagpos;
      mcb_pmsm_foc_f28379d_dyno_DWork.RT10_ActiveBufIdx =
        (mcb_pmsm_foc_f28379d_dyno_DWork.RT10_ActiveBufIdx == 0);

      /* RateTransition: '<Root>/RT3' */
      mcb_pmsm_foc_f28379d_dyno_DWork.RT3_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT3_ActiveBufIdx
        == 0] = mcb_pmsm_foc_f28379d_dyno_B.SCIReceive[0];
      mcb_pmsm_foc_f28379d_dyno_DWork.RT3_ActiveBufIdx =
        (mcb_pmsm_foc_f28379d_dyno_DWork.RT3_ActiveBufIdx == 0);

      /* RateTransition: '<Root>/RT9' */
      mcb_pmsm_foc_f28379d_dyno_DWork.RT9_Buffer[mcb_pmsm_foc_f28379d_dyno_DWork.RT9_ActiveBufIdx
        == 0] = mcb_pmsm_foc_f28379d_dyno_B.OutportBufferForDesriedImagref;
      mcb_pmsm_foc_f28379d_dyno_DWork.RT9_ActiveBufIdx =
        (mcb_pmsm_foc_f28379d_dyno_DWork.RT9_ActiveBufIdx == 0);
    }
  }

  /* Clear occurred Rx FIFO complete event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFINTCLR= 1;
  EDIS;

  /* Clear occurred Rx FIFO overflow event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFOVRCLR= 1;
  EDIS;
  HWI_TIC28x_AcknowledgeIrq(96);
}

void mcb_pmsm_foc_f28379d_dyno_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(33);
  HWI_TIC28x_DisableIRQ(34);
  HWI_TIC28x_DisableIRQ(96);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
