/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_sensorless_dyno_f28379d.c
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_sensorless_dyno_f28379d'.
 *
 * Model version                  : 9.7
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Apr 15 14:21:51 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcb_pmsm_foc_sensorless_dyno_f28379d.h"
#include "rtwtypes.h"
#include "mcb_pmsm_foc_sensorless_dyno_f28379d_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_mcb_pmsm_foc_sensorless mcb_pmsm_foc_sensorless_dyno__B;

/* Block states (default storage) */
D_Work_mcb_pmsm_foc_sensorless_ mcb_pmsm_foc_sensorless_d_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_mcb_pmsm_foc_se mcb_pmsm_foc_sen_PrevZCSigState;

/* Real-time model */
static RT_MODEL_mcb_pmsm_foc_sensorles mcb_pmsm_foc_sensorless_dyno_M_;
RT_MODEL_mcb_pmsm_foc_sensorles *const mcb_pmsm_foc_sensorless_dyno_M =
  &mcb_pmsm_foc_sensorless_dyno_M_;
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
void mcb_pmsm_foc_sensorless_dyno_f28379d_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_sensorless_dyno_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_sensorless_dyno_M, 2));
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
  (mcb_pmsm_foc_sensorless_dyno_M->Timing.TaskCounters.TID[1])++;
  if ((mcb_pmsm_foc_sensorless_dyno_M->Timing.TaskCounters.TID[1]) > 39) {/* Sample time: [0.001s, 0.0s] */
    mcb_pmsm_foc_sensorless_dyno_M->Timing.TaskCounters.TID[1] = 0;
  }

  (mcb_pmsm_foc_sensorless_dyno_M->Timing.TaskCounters.TID[2])++;
  if ((mcb_pmsm_foc_sensorless_dyno_M->Timing.TaskCounters.TID[2]) > 19999) {/* Sample time: [0.5s, 0.0s] */
    mcb_pmsm_foc_sensorless_dyno_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S34>/Two phase CRL wrap'
 *    '<S286>/Two phase CRL wrap'
 */
void mcb_pmsm_fo_TwophaseCRLwrap(real32_T rtu_a, real32_T rtu_b,
  rtB_TwophaseCRLwrap_mcb_pmsm_fo *localB)
{
  /* Sum: '<S35>/a_plus_2b' */
  localB->a_plus_2b = (rtu_a + rtu_b) + rtu_b;

  /* Gain: '<S35>/one_by_sqrt3' */
  localB->one_by_sqrt3 = 0.577350259F * localB->a_plus_2b;

  /* AlgorithmDescriptorDelegate generated from: '<S35>/a16' */
  localB->algDD_o1 = rtu_a;

  /* AlgorithmDescriptorDelegate generated from: '<S35>/a16' */
  localB->algDD_o2 = localB->one_by_sqrt3;
}

/*
 * Output and update for action system:
 *    '<S36>/D//Q Axis Priority'
 *    '<S288>/D//Q Axis Priority'
 */
void mcb_pmsm_foc_DQAxisPriority(real32_T rtu_dqRef, real32_T rtu_dqRef_k,
  real32_T rtu_satLim, real32_T rtu_satLimSq, uint16_T rtu_satMethod, real32_T
  rty_dqSat[2], rtB_DQAxisPriority_mcb_pmsm_foc *localB)
{
  /* RelationalOperator: '<S45>/Compare' incorporates:
   *  Constant: '<S45>/Constant'
   */
  localB->Compare = (rtu_satMethod == 1U);

  /* RelationalOperator: '<S46>/Compare' incorporates:
   *  Constant: '<S46>/Constant'
   */
  localB->Compare_k = (rtu_satMethod == 1U);

  /* Switch: '<S40>/Switch' */
  if (localB->Compare) {
    /* Switch: '<S40>/Switch' */
    localB->Switch[0] = rtu_dqRef;
    localB->Switch[1] = rtu_dqRef_k;
  } else {
    /* Switch: '<S40>/Switch' */
    localB->Switch[0] = rtu_dqRef_k;
    localB->Switch[1] = rtu_dqRef;
  }

  /* End of Switch: '<S40>/Switch' */

  /* RelationalOperator: '<S50>/LowerRelop1' */
  localB->LowerRelop1 = (localB->Switch[0] > rtu_satLim);

  /* Switch: '<S50>/Switch2' */
  if (localB->LowerRelop1) {
    /* Switch: '<S50>/Switch2' */
    localB->Switch2 = rtu_satLim;
  } else {
    /* Gain: '<S49>/Gain' */
    localB->Gain = -rtu_satLim;

    /* RelationalOperator: '<S50>/UpperRelop' */
    localB->UpperRelop = (localB->Switch[0] < localB->Gain);

    /* Switch: '<S50>/Switch' */
    if (localB->UpperRelop) {
      /* Switch: '<S50>/Switch' */
      localB->Switch_a = localB->Gain;
    } else {
      /* Switch: '<S50>/Switch' */
      localB->Switch_a = localB->Switch[0];
    }

    /* End of Switch: '<S50>/Switch' */

    /* Switch: '<S50>/Switch2' */
    localB->Switch2 = localB->Switch_a;
  }

  /* End of Switch: '<S50>/Switch2' */

  /* Product: '<S49>/Product' */
  localB->Product = localB->Switch2 * localB->Switch2;

  /* Sum: '<S49>/Sum' */
  localB->Sum = rtu_satLimSq - localB->Product;

  /* Product: '<S49>/Product2' */
  localB->Product2 = localB->Switch[1] * localB->Switch[1];

  /* RelationalOperator: '<S49>/Relational Operator' */
  localB->RelationalOperator = (localB->Sum >= localB->Product2);

  /* DataTypeConversion: '<S49>/Data Type Conversion' */
  localB->DataTypeConversion = localB->RelationalOperator;

  /* If: '<S49>/If' incorporates:
   *  Switch: '<S51>/Switch1'
   */
  if (localB->DataTypeConversion != 0U) {
    /* Outputs for IfAction SubSystem: '<S49>/passThrough' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    /* Merge: '<S49>/Merge' incorporates:
     *  SignalConversion generated from: '<S52>/ref2'
     */
    localB->Merge = localB->Switch[1];

    /* End of Outputs for SubSystem: '<S49>/passThrough' */
  } else {
    /* Outputs for IfAction SubSystem: '<S49>/limitRef2' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    if (localB->Sum > 0.0F) {
      /* Switch: '<S51>/Switch1' */
      localB->Switch1 = localB->Sum;
    } else {
      /* Switch: '<S51>/Switch1' incorporates:
       *  Constant: '<S51>/Constant'
       */
      localB->Switch1 = 0.0F;
    }

    /* Sqrt: '<S51>/Sqrt' */
    localB->Sqrt = (real32_T)sqrt(localB->Switch1);

    /* Switch: '<S51>/Switch' */
    if (localB->Switch[1] >= 0.0F) {
      /* Merge: '<S49>/Merge' */
      localB->Merge = localB->Sqrt;
    } else {
      /* Gain: '<S51>/Gain' */
      localB->Gain_l = -localB->Sqrt;

      /* Merge: '<S49>/Merge' */
      localB->Merge = localB->Gain_l;
    }

    /* End of Switch: '<S51>/Switch' */
    /* End of Outputs for SubSystem: '<S49>/limitRef2' */
  }

  /* End of If: '<S49>/If' */

  /* Switch: '<S40>/Switch1' */
  if (localB->Compare_k) {
    rty_dqSat[0] = localB->Switch2;
    rty_dqSat[1] = localB->Merge;
  } else {
    rty_dqSat[0] = localB->Merge;
    rty_dqSat[1] = localB->Switch2;
  }

  /* End of Switch: '<S40>/Switch1' */
}

/*
 * Output and update for action system:
 *    '<S36>/D-Q Equivalence'
 *    '<S288>/D-Q Equivalence'
 */
void mcb_pmsm_foc__DQEquivalence(real32_T rtu_dqRef, real32_T rtu_dqRef_l,
  real32_T rtu_magSquare, real32_T rtu_satLim, real32_T rtu_satLimSq, real32_T
  rty_dqSat[2], rtB_DQEquivalence_mcb_pmsm_foc_ *localB)
{
  /* RelationalOperator: '<S39>/Relational Operator' */
  localB->RelationalOperator = (rtu_magSquare > rtu_satLimSq);

  /* DataTypeConversion: '<S39>/Data Type Conversion' */
  localB->DataTypeConversion = localB->RelationalOperator;

  /* If: '<S39>/If' */
  if (localB->DataTypeConversion != 0U) {
    /* Outputs for IfAction SubSystem: '<S39>/Limiter' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    /* Product: '<S43>/Product' */
    localB->Product[0] = rtu_dqRef * rtu_satLim;
    localB->Product[1] = rtu_dqRef_l * rtu_satLim;

    /* Sqrt: '<S43>/Square Root' */
    localB->SquareRoot = (real32_T)sqrt(rtu_magSquare);

    /* Switch: '<S43>/Switch' */
    if (localB->SquareRoot != 0.0F) {
      /* Switch: '<S43>/Switch' */
      localB->Switch = localB->SquareRoot;
    } else {
      /* Switch: '<S43>/Switch' incorporates:
       *  Constant: '<S43>/Constant'
       */
      localB->Switch = 1.0F;
    }

    /* End of Switch: '<S43>/Switch' */

    /* Product: '<S43>/Divide' */
    rty_dqSat[0] = localB->Product[0] / localB->Switch;
    rty_dqSat[1] = localB->Product[1] / localB->Switch;

    /* End of Outputs for SubSystem: '<S39>/Limiter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S39>/Passthrough' incorporates:
     *  ActionPort: '<S44>/Action Port'
     */
    /* SignalConversion generated from: '<S44>/dqRef' */
    rty_dqSat[0] = rtu_dqRef;
    rty_dqSat[1] = rtu_dqRef_l;

    /* End of Outputs for SubSystem: '<S39>/Passthrough' */
  }

  /* End of If: '<S39>/If' */
}

/*
 * Output and update for atomic system:
 *    '<S29>/Two inputs CRL'
 *    '<S282>/Two inputs CRL'
 */
void mcb_pmsm_foc_s_TwoinputsCRL(real32_T rtu_Ds, real32_T rtu_Qs, real32_T
  rtu_sin, real32_T rtu_cos, rtB_TwoinputsCRL_mcb_pmsm_foc_s *localB)
{
  /* Product: '<S165>/qcos' */
  localB->qcos = rtu_Qs * rtu_cos;

  /* Product: '<S165>/dsin' */
  localB->dsin = rtu_Ds * rtu_sin;

  /* Sum: '<S165>/sum_beta' */
  localB->sum_beta = localB->qcos + localB->dsin;

  /* Product: '<S165>/dcos' */
  localB->dcos = rtu_Ds * rtu_cos;

  /* Product: '<S165>/qsin' */
  localB->qsin = rtu_Qs * rtu_sin;

  /* Sum: '<S165>/sum_alpha' */
  localB->sum_alpha = localB->dcos - localB->qsin;

  /* Switch: '<S166>/Switch' */
  localB->Switch[0] = localB->sum_alpha;
  localB->Switch[1] = localB->sum_beta;

  /* AlgorithmDescriptorDelegate generated from: '<S165>/a16' */
  localB->algDD_o1 = localB->Switch[0];

  /* AlgorithmDescriptorDelegate generated from: '<S165>/a16' */
  localB->algDD_o2 = localB->Switch[1];
}

/*
 * Output and update for atomic system:
 *    '<S31>/Two inputs CRL'
 *    '<S283>/Two inputs CRL'
 */
void mcb_pmsm_foc_TwoinputsCRL_p(real32_T rtu_Alpha, real32_T rtu_Beta, real32_T
  rtu_sine, real32_T rtu_cos, rtB_TwoinputsCRL_mcb_pmsm_foc_k *localB)
{
  /* Product: '<S170>/acos' */
  localB->acos_k = rtu_Alpha * rtu_cos;

  /* Product: '<S170>/bsin' */
  localB->bsin = rtu_Beta * rtu_sine;

  /* Sum: '<S170>/sum_Ds' */
  localB->sum_Ds = localB->acos_k + localB->bsin;

  /* Product: '<S170>/bcos' */
  localB->bcos = rtu_Beta * rtu_cos;

  /* Product: '<S170>/asin' */
  localB->asin_m = rtu_Alpha * rtu_sine;

  /* Sum: '<S170>/sum_Qs' */
  localB->sum_Qs = localB->bcos - localB->asin_m;

  /* Switch: '<S171>/Switch' */
  localB->Switch[0] = localB->sum_Ds;
  localB->Switch[1] = localB->sum_Qs;

  /* AlgorithmDescriptorDelegate generated from: '<S170>/a16' */
  localB->algDD_o1 = localB->Switch[0];

  /* AlgorithmDescriptorDelegate generated from: '<S170>/a16' */
  localB->algDD_o2 = localB->Switch[1];
}

/*
 * Output and update for action system:
 *    '<S174>/If Action Subsystem'
 *    '<S368>/If Action Subsystem'
 */
void mcb_pmsm__IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem_mcb_pmsm_ *localB)
{
  /* DataTypeConversion: '<S177>/Convert_uint16' */
  localB->Convert_uint16 = (int16_T)(real32_T)floor(rtu_In1);

  /* DataTypeConversion: '<S177>/Convert_back' */
  localB->Convert_back = localB->Convert_uint16;

  /* Sum: '<S177>/Sum' */
  *rty_Out1 = rtu_In1 - localB->Convert_back;
}

/*
 * Output and update for action system:
 *    '<S174>/If Action Subsystem1'
 *    '<S368>/If Action Subsystem1'
 */
void mcb_pmsm_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem1_mcb_pmsm *localB)
{
  /* DataTypeConversion: '<S178>/Convert_uint16' */
  localB->Convert_uint16 = (int16_T)rtu_In1;

  /* DataTypeConversion: '<S178>/Convert_back' */
  localB->Convert_back = localB->Convert_uint16;

  /* Sum: '<S178>/Sum' */
  *rty_Out1 = rtu_In1 - localB->Convert_back;
}

/*
 * Output and update for trigger system:
 *    '<S234>/Dir_Sense'
 *    '<S432>/Dir_Sense'
 */
void mcb_pmsm_foc_sens_Dir_Sense(boolean_T rtu_A, boolean_T rtu_B,
  rtB_Dir_Sense_mcb_pmsm_foc_sens *localB, rtZCE_Dir_Sense_mcb_pmsm_foc_se
  *localZCE)
{
  boolean_T zcEvent;

  /* Outputs for Triggered SubSystem: '<S234>/Dir_Sense' incorporates:
   *  TriggerPort: '<S242>/Trigger'
   */
  zcEvent = (rtu_A && (localZCE->Dir_Sense_Trig_ZCE != POS_ZCSIG));
  if (zcEvent) {
    /* Logic: '<S242>/Logical Operator' */
    localB->LogicalOperator = (rtu_A && rtu_B);

    /* Switch: '<S242>/Switch' */
    if (localB->LogicalOperator) {
      /* Switch: '<S242>/Switch' incorporates:
       *  Constant: '<S242>/Constant'
       */
      localB->Switch = -1;
    } else {
      /* Switch: '<S242>/Switch' incorporates:
       *  Constant: '<S242>/Constant1'
       */
      localB->Switch = 1;
    }

    /* End of Switch: '<S242>/Switch' */
  }

  localZCE->Dir_Sense_Trig_ZCE = rtu_A;

  /* End of Outputs for SubSystem: '<S234>/Dir_Sense' */
}

/*
 * Output and update for action system:
 *    '<S234>/Subsystem2'
 *    '<S432>/Subsystem2'
 */
void mcb_pmsm_foc_sen_Subsystem2(real32_T rtu_SigmaAlpha, real32_T rtu_SigmaBeta,
  real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* UnaryMinus: '<S243>/Unary Minus' */
  *rty_Out1 = -rtu_SigmaAlpha;

  /* SignalConversion generated from: '<S243>/SigmaBeta' */
  *rty_Out2 = rtu_SigmaBeta;
}

/*
 * Output and update for atomic system:
 *    '<S233>/angleCompensation'
 *    '<S431>/angleCompensation'
 */
void mcb_pmsm__angleCompensation(real32_T rtu_A, real32_T rtu_B, real32_T rtu_C,
  real32_T rtu_D, rtB_angleCompensation_mcb_pmsm_ *localB)
{
  /* Product: '<S241>/Product' */
  localB->Product = rtu_A * rtu_D;

  /* Product: '<S241>/Product2' */
  localB->Product2 = rtu_B * rtu_C;

  /* Sum: '<S241>/Sum1' */
  localB->Sum1 = localB->Product + localB->Product2;

  /* Product: '<S241>/Product1' */
  localB->Product1 = rtu_B * rtu_D;

  /* Product: '<S241>/Product3' */
  localB->Product3 = rtu_A * rtu_C;

  /* Sum: '<S241>/Sum2' */
  localB->Sum2 = localB->Product1 - localB->Product3;

  /* Outputs for Atomic SubSystem: '<S241>/atan1' */
  /* Trigonometry: '<S258>/Atan2' */
  localB->Atan2 = atan2f(localB->Sum1, localB->Sum2);

  /* Switch: '<S258>/Switch' */
  localB->Switch_e = localB->Atan2;

  /* AlgorithmDescriptorDelegate generated from: '<S258>/a16' */
  localB->algDD = localB->Switch_e;

  /* End of Outputs for SubSystem: '<S241>/atan1' */

  /* Switch: '<S241>/Switch' */
  if (localB->algDD > 0.0F) {
    /* Switch: '<S241>/Switch' */
    localB->Switch = localB->algDD;
  } else {
    /* Bias: '<S241>/Bias' */
    localB->Bias_a = localB->algDD + 6.28318548F;

    /* Switch: '<S241>/Switch' */
    localB->Switch = localB->Bias_a;
  }

  /* End of Switch: '<S241>/Switch' */
}

/*
 * System initialize for action system:
 *    '<S189>/Flux Observer'
 *    '<S387>/Flux Observer'
 */
void mcb_pmsm__FluxObserver_Init(rtDW_FluxObserver_mcb_pmsm_foc_ *localDW)
{
  /* InitializeConditions for Delay: '<S223>/Delay1' */
  localDW->Delay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S223>/Delay' */
  localDW->Delay_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S215>/Delay1' */
  localDW->Delay1_DSTATE_c = 0.0F;

  /* InitializeConditions for Delay: '<S215>/Delay' */
  localDW->Delay_DSTATE_c = 0.0F;

  /* InitializeConditions for Delay: '<S197>/Delay' */
  localDW->CircBufIdx = 0U;
}

/*
 * Output and update for action system:
 *    '<S189>/Flux Observer'
 *    '<S387>/Flux Observer'
 */
void mcb_pmsm_foc_s_FluxObserver(const real32_T rtu_InputSignals[4], real32_T
  rty_PositionSpeed[2], const boolean_T *rtd_Enable,
  rtB_FluxObserver_mcb_pmsm_foc_s *localB, rtDW_FluxObserver_mcb_pmsm_foc_
  *localDW, rtZCE_FluxObserver_mcb_pmsm_foc *localZCE)
{
  real32_T Product;
  real32_T UnitDelay;
  real32_T rtu_InputSignals_0;
  ZCSigState Delay1_Reset_ZCE_tmp;
  boolean_T zcEvent;

  /* Switch: '<S198>/Switch1' incorporates:
   *  Constant: '<S198>/FilterConstant'
   *  Constant: '<S198>/OneMinusFilterConstant'
   */
  localB->Switch1[0] = 0.005F;
  localB->Switch1[1] = 0.995F;

  /* Product: '<S201>/Product' */
  rtu_InputSignals_0 = rtu_InputSignals[0];

  /* Product: '<S201>/Product' */
  Product = rtu_InputSignals_0 * 0.005F;
  localB->Product[0] = Product;

  /* UnitDelay: '<S201>/Unit Delay' */
  UnitDelay = localDW->UnitDelay_DSTATE[0];
  localB->UnitDelay[0] = UnitDelay;

  /* Product: '<S201>/Product1' */
  UnitDelay *= 0.995F;
  localB->Product1[0] = UnitDelay;

  /* Sum: '<S201>/Add1' */
  Product += UnitDelay;
  localB->Add1[0] = Product;

  /* Sum: '<S194>/Sum6' */
  localB->Sum6[0] = rtu_InputSignals_0 - Product;

  /* Product: '<S201>/Product' */
  rtu_InputSignals_0 = rtu_InputSignals[1];

  /* Product: '<S201>/Product' */
  Product = rtu_InputSignals_0 * 0.005F;
  localB->Product[1] = Product;

  /* UnitDelay: '<S201>/Unit Delay' */
  UnitDelay = localDW->UnitDelay_DSTATE[1];
  localB->UnitDelay[1] = UnitDelay;

  /* Product: '<S201>/Product1' */
  UnitDelay *= 0.995F;
  localB->Product1[1] = UnitDelay;

  /* Sum: '<S201>/Add1' */
  Product += UnitDelay;
  localB->Add1[1] = Product;

  /* Sum: '<S194>/Sum6' */
  localB->Sum6[1] = rtu_InputSignals_0 - Product;

  /* Product: '<S201>/Product' */
  rtu_InputSignals_0 = rtu_InputSignals[2];

  /* Product: '<S201>/Product' */
  Product = rtu_InputSignals_0 * 0.005F;
  localB->Product[2] = Product;

  /* UnitDelay: '<S201>/Unit Delay' */
  UnitDelay = localDW->UnitDelay_DSTATE[2];
  localB->UnitDelay[2] = UnitDelay;

  /* Product: '<S201>/Product1' */
  UnitDelay *= 0.995F;
  localB->Product1[2] = UnitDelay;

  /* Sum: '<S201>/Add1' */
  Product += UnitDelay;
  localB->Add1[2] = Product;

  /* Sum: '<S194>/Sum6' */
  localB->Sum6[2] = rtu_InputSignals_0 - Product;

  /* Product: '<S201>/Product' */
  rtu_InputSignals_0 = rtu_InputSignals[3];

  /* Product: '<S201>/Product' */
  Product = rtu_InputSignals_0 * 0.005F;
  localB->Product[3] = Product;

  /* UnitDelay: '<S201>/Unit Delay' */
  UnitDelay = localDW->UnitDelay_DSTATE[3];
  localB->UnitDelay[3] = UnitDelay;

  /* Product: '<S201>/Product1' */
  UnitDelay *= 0.995F;
  localB->Product1[3] = UnitDelay;

  /* Sum: '<S201>/Add1' */
  Product += UnitDelay;
  localB->Add1[3] = Product;

  /* Sum: '<S194>/Sum6' */
  localB->Sum6[3] = rtu_InputSignals_0 - Product;

  /* DataStoreRead: '<S192>/Data Store Read1' */
  localB->DataStoreRead1 = *rtd_Enable;

  /* Logic: '<S192>/Logical Operator' */
  localB->LogicalOperator = !localB->DataStoreRead1;

  /* Product: '<S224>/Product' incorporates:
   *  Constant: '<S205>/p1'
   */
  localB->Product_c = localB->Sum6[3] * 0.556730628F;

  /* Sum: '<S221>/Sum3' */
  localB->Sum3 = localB->Sum6[1] - localB->Product_c;

  /* Delay: '<S223>/Delay1' */
  zcEvent = (((localZCE->Delay1_Reset_ZCE == POS_ZCSIG) != (int16_T)
              localB->LogicalOperator) && (localZCE->Delay1_Reset_ZCE !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || localB->LogicalOperator) {
    localDW->Delay1_DSTATE = 0.0F;
  }

  Delay1_Reset_ZCE_tmp = localB->LogicalOperator;
  localZCE->Delay1_Reset_ZCE = Delay1_Reset_ZCE_tmp;

  /* Delay: '<S223>/Delay1' */
  localB->Delay1 = localDW->Delay1_DSTATE;

  /* Sum: '<S223>/Sum' */
  localB->Sum = localB->Sum3 + localB->Delay1;

  /* Product: '<S223>/Product' incorporates:
   *  Constant: '<S205>/p3'
   */
  localB->Product_f = localB->Sum * 2.49998757E-5F;

  /* Delay: '<S223>/Delay' */
  zcEvent = (((localZCE->Delay_Reset_ZCE == POS_ZCSIG) != (int16_T)
              localB->LogicalOperator) && (localZCE->Delay_Reset_ZCE !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || localB->LogicalOperator) {
    localDW->Delay_DSTATE = 0.0F;
  }

  localZCE->Delay_Reset_ZCE = Delay1_Reset_ZCE_tmp;

  /* Delay: '<S223>/Delay' */
  localB->Delay_k = localDW->Delay_DSTATE;

  /* Product: '<S223>/Product1' incorporates:
   *  Constant: '<S205>/p4'
   */
  localB->Product1_b = localB->Delay_k * 0.99999F;

  /* Sum: '<S223>/Sum1' */
  localB->Sum1 = localB->Product_f + localB->Product1_b;

  /* Product: '<S224>/Product2' incorporates:
   *  Constant: '<S205>/p2'
   */
  localB->Product2 = localB->Sum6[3] * 0.000309294788F;

  /* Sum: '<S221>/Sum1' */
  localB->Sum1_c = localB->Sum1 - localB->Product2;

  /* Sum: '<S222>/Sum' incorporates:
   *  Constant: '<S205>/p5'
   *  Constant: '<S222>/One'
   */
  localB->Sum_i = 0.999F;

  /* Switch: '<S222>/Switch1' incorporates:
   *  Constant: '<S205>/p5'
   */
  localB->Switch1_k[0] = 0.0010000047F;
  localB->Switch1_k[1] = 0.999F;

  /* Product: '<S227>/Product' */
  localB->Product_m = localB->Sum1_c * 0.0010000047F;

  /* UnitDelay: '<S227>/Unit Delay' */
  localB->UnitDelay_c = localDW->UnitDelay_DSTATE_b;

  /* Product: '<S227>/Product1' */
  localB->Product1_n = 0.999F * localB->UnitDelay_c;

  /* Sum: '<S227>/Add1' */
  localB->Add1_p = localB->Product_m + localB->Product1_n;

  /* Switch: '<S220>/Switch' */
  if (localB->LogicalOperator) {
    /* Switch: '<S220>/Switch' incorporates:
     *  Constant: '<S220>/Constant'
     */
    localB->Switch = 0.0F;
  } else {
    /* Sum: '<S226>/Sum' */
    localB->Sum_j = localB->Sum1_c - localB->Add1_p;

    /* Switch: '<S220>/Switch' */
    localB->Switch = localB->Sum_j;
  }

  /* End of Switch: '<S220>/Switch' */

  /* Product: '<S216>/Product' incorporates:
   *  Constant: '<S205>/p1'
   */
  localB->Product_n = localB->Sum6[2] * 0.556730628F;

  /* Sum: '<S213>/Sum3' */
  localB->Sum3_a = localB->Sum6[0] - localB->Product_n;

  /* Delay: '<S215>/Delay1' */
  zcEvent = (((localZCE->Delay1_Reset_ZCE_b == POS_ZCSIG) != (int16_T)
              localB->LogicalOperator) && (localZCE->Delay1_Reset_ZCE_b !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || localB->LogicalOperator) {
    localDW->Delay1_DSTATE_c = 0.0F;
  }

  localZCE->Delay1_Reset_ZCE_b = Delay1_Reset_ZCE_tmp;

  /* Delay: '<S215>/Delay1' */
  localB->Delay1_a = localDW->Delay1_DSTATE_c;

  /* Sum: '<S215>/Sum' */
  localB->Sum_e = localB->Sum3_a + localB->Delay1_a;

  /* Product: '<S215>/Product' incorporates:
   *  Constant: '<S205>/p3'
   */
  localB->Product_e = localB->Sum_e * 2.49998757E-5F;

  /* Delay: '<S215>/Delay' */
  zcEvent = (((localZCE->Delay_Reset_ZCE_g == POS_ZCSIG) != (int16_T)
              localB->LogicalOperator) && (localZCE->Delay_Reset_ZCE_g !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || localB->LogicalOperator) {
    localDW->Delay_DSTATE_c = 0.0F;
  }

  localZCE->Delay_Reset_ZCE_g = Delay1_Reset_ZCE_tmp;

  /* Delay: '<S215>/Delay' */
  localB->Delay_f = localDW->Delay_DSTATE_c;

  /* Product: '<S215>/Product1' incorporates:
   *  Constant: '<S205>/p4'
   */
  localB->Product1_i = localB->Delay_f * 0.99999F;

  /* Sum: '<S215>/Sum1' */
  localB->Sum1_cf = localB->Product_e + localB->Product1_i;

  /* Product: '<S216>/Product2' incorporates:
   *  Constant: '<S205>/p2'
   */
  localB->Product2_e = localB->Sum6[2] * 0.000309294788F;

  /* Sum: '<S213>/Sum1' */
  localB->Sum1_n = localB->Sum1_cf - localB->Product2_e;

  /* Sum: '<S214>/Sum' incorporates:
   *  Constant: '<S205>/p5'
   *  Constant: '<S214>/One'
   */
  localB->Sum_iu = 0.999F;

  /* Switch: '<S214>/Switch1' incorporates:
   *  Constant: '<S205>/p5'
   */
  localB->Switch1_p[0] = 0.0010000047F;
  localB->Switch1_p[1] = 0.999F;

  /* Product: '<S219>/Product' */
  localB->Product_nb = localB->Sum1_n * 0.0010000047F;

  /* UnitDelay: '<S219>/Unit Delay' */
  localB->UnitDelay_a = localDW->UnitDelay_DSTATE_c;

  /* Product: '<S219>/Product1' */
  localB->Product1_a = 0.999F * localB->UnitDelay_a;

  /* Sum: '<S219>/Add1' */
  localB->Add1_l = localB->Product_nb + localB->Product1_a;

  /* Switch: '<S212>/Switch' */
  if (localB->LogicalOperator) {
    /* Switch: '<S212>/Switch' incorporates:
     *  Constant: '<S212>/Constant'
     */
    localB->Switch_h = 1.0E-6F;
  } else {
    /* Sum: '<S218>/Sum' */
    localB->Sum_c = localB->Sum1_n - localB->Add1_l;

    /* Switch: '<S212>/Switch' */
    localB->Switch_h = localB->Sum_c;
  }

  /* End of Switch: '<S212>/Switch' */

  /* Outputs for Atomic SubSystem: '<S209>/atan2' */
  /* Trigonometry: '<S210>/Atan2' */
  localB->Atan2 = atan2f(localB->Switch, localB->Switch_h);

  /* Outputs for Atomic SubSystem: '<S210>/Per Unit' */
  /* Gain: '<S211>/Gain' incorporates:
   *  Switch: '<S210>/Switch'
   */
  localB->Gain = 0.159154937F * localB->Atan2;

  /* Switch: '<S211>/Switch' incorporates:
   *  Switch: '<S210>/Switch'
   */
  if (localB->Gain >= 0.0F) {
    /* Switch: '<S211>/Switch' */
    localB->Switch_a = localB->Gain;
  } else {
    /* Bias: '<S211>/Bias' */
    localB->Bias = localB->Gain + 1.0F;

    /* Switch: '<S211>/Switch' */
    localB->Switch_a = localB->Bias;
  }

  /* End of Switch: '<S211>/Switch' */
  /* End of Outputs for SubSystem: '<S210>/Per Unit' */

  /* Switch: '<S210>/Switch' */
  localB->Switch_b = localB->Switch_a;

  /* AlgorithmDescriptorDelegate generated from: '<S210>/a16' */
  localB->algDD = localB->Switch_b;

  /* End of Outputs for SubSystem: '<S209>/atan2' */

  /* Gain: '<S197>/PositionToCount' */
  localB->PositionToCount = (uint32_T)(4.2949673E+9F * localB->algDD);

  /* Delay: '<S197>/Delay' */
  localB->Delay = localDW->Delay_DSTATE_l[localDW->CircBufIdx];

  /* Sum: '<S197>/SpeedCount' */
  localB->SpeedCount = (int32_T)localB->PositionToCount - (int32_T)localB->Delay;

  /* DataTypeConversion: '<S232>/DTC' */
  localB->DTC = (real32_T)localB->SpeedCount;

  /* Gain: '<S197>/SpeedGain' */
  localB->SpeedGain = 6.80294043E-9F * localB->DTC;

  /* Switch: '<S196>/Switch1' incorporates:
   *  Constant: '<S196>/FilterConstant'
   *  Constant: '<S196>/OneMinusFilterConstant'
   */
  localB->Switch1_c[0] = 0.01F;
  localB->Switch1_c[1] = 0.99F;

  /* Product: '<S230>/Product' */
  localB->Product_d = localB->SpeedGain * 0.01F;

  /* UnitDelay: '<S230>/Unit Delay' */
  localB->UnitDelay_m = localDW->UnitDelay_DSTATE_f;

  /* Product: '<S230>/Product1' */
  localB->Product1_d = 0.99F * localB->UnitDelay_m;

  /* Sum: '<S230>/Add1' */
  localB->Add1_h = localB->Product_d + localB->Product1_d;

  /* Gain: '<S192>/elect2mech' */
  localB->elect2mech = 0.25F * localB->Add1_h;

  /* SignalConversion generated from: '<S192>/Position//Speed' */
  rty_PositionSpeed[0] = localB->algDD;
  rty_PositionSpeed[1] = localB->elect2mech;

  /* Update for UnitDelay: '<S201>/Unit Delay' */
  localDW->UnitDelay_DSTATE[0] = localB->Add1[0];
  localDW->UnitDelay_DSTATE[1] = localB->Add1[1];
  localDW->UnitDelay_DSTATE[2] = localB->Add1[2];
  localDW->UnitDelay_DSTATE[3] = localB->Add1[3];

  /* Update for Delay: '<S223>/Delay1' */
  localDW->Delay1_DSTATE = localB->Sum3;

  /* Update for Delay: '<S223>/Delay' */
  localDW->Delay_DSTATE = localB->Sum1;

  /* Update for UnitDelay: '<S227>/Unit Delay' */
  localDW->UnitDelay_DSTATE_b = localB->Add1_p;

  /* Update for Delay: '<S215>/Delay1' */
  localDW->Delay1_DSTATE_c = localB->Sum3_a;

  /* Update for Delay: '<S215>/Delay' */
  localDW->Delay_DSTATE_c = localB->Sum1_cf;

  /* Update for UnitDelay: '<S219>/Unit Delay' */
  localDW->UnitDelay_DSTATE_c = localB->Add1_l;

  /* Update for Delay: '<S197>/Delay' */
  localDW->Delay_DSTATE_l[localDW->CircBufIdx] = localB->PositionToCount;
  if (localDW->CircBufIdx < 9U) {
    localDW->CircBufIdx++;
  } else {
    localDW->CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S197>/Delay' */

  /* Update for UnitDelay: '<S230>/Unit Delay' */
  localDW->UnitDelay_DSTATE_f = localB->Add1_h;
}

/* System initialize for function-call system: '<Root>/FOC Algorithm Motor 1' */
void mcb_FOCAlgorithmMotor1_Init(void)
{
  /* Start for S-Function (c2802xadc): '<S187>/ADC_C_IN2' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S187>/ADC_B_IN2' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c280xgpio_do): '<S22>/DRV830x Enable' */
  EALLOW;
  GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
  GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S22>/ePWM1' */
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
    EPwm1Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
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

  /* Start for S-Function (c2802xpwm): '<S22>/ePWM2' */
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
    EPwm2Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm2Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
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

  /* Start for S-Function (c2802xpwm): '<S22>/ePWM3' */
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
    EPwm3Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm3Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
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

  /* SystemInitialize for MATLAB Function: '<S37>/MATLAB Function' */
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state_j = 0.0F;

  /* SystemInitialize for MATLAB Function: '<S38>/MATLAB Function' */
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state_p = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S189>/Flux Observer' */
  mcb_pmsm__FluxObserver_Init(&mcb_pmsm_foc_sensorless_d_DWork.FluxObserver);

  /* End of SystemInitialize for SubSystem: '<S189>/Flux Observer' */

  /* SystemInitialize for IfAction SubSystem: '<S189>/Sliding Mode Observer' */
  /* InitializeConditions for Delay: '<S235>/Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_l = 0.0F;

  /* InitializeConditions for Delay: '<S245>/Delay1' */
  mcb_pmsm_foc_sensorless_d_DWork.Delay1_DSTATE_f = 0.0F;

  /* InitializeConditions for Delay: '<S236>/Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_nx = 0.0F;

  /* InitializeConditions for Delay: '<S246>/Delay1' */
  mcb_pmsm_foc_sensorless_d_DWork.Delay1_DSTATE_n = 0.0F;

  /* InitializeConditions for Delay: '<S233>/Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_h = 0.0F;

  /* InitializeConditions for Delay: '<S240>/Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.CircBufIdx_g = 0U;

  /* End of SystemInitialize for SubSystem: '<S189>/Sliding Mode Observer' */

  /* SystemInitialize for Merge: '<S189>/Merge' */
  mcb_pmsm_foc_sensorless_dyno__B.Merge_f[0] = 0.0F;
  mcb_pmsm_foc_sensorless_dyno__B.Merge_f[1] = 0.0F;
}

/* System reset for function-call system: '<Root>/FOC Algorithm Motor 1' */
void mc_FOCAlgorithmMotor1_Reset(void)
{
  /* SystemReset for MATLAB Function: '<S38>/MATLAB Function' */
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state_p = 0.0F;

  /* SystemReset for MATLAB Function: '<S37>/MATLAB Function' */
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state_j = 0.0F;
}

/* Output and update for function-call system: '<Root>/FOC Algorithm Motor 1' */
#pragma CODE_SECTION (mcb_pmsm_FOCAlgorithmMotor1, "ramfuncs")

void mcb_pmsm_FOCAlgorithmMotor1(void)
{
  real32_T V_q_ref_unsat;
  real32_T y;
  uint32_T Sum_o;
  int16_T i;
  uint16_T Scale_to_PWM_Counter_PRD_n;

  /* DataStoreRead: '<S30>/Data Store Read' */
  mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead =
    mcb_pmsm_foc_sensorless_d_DWork.SpeedRef;

  /* Abs: '<S30>/Abs' */
  mcb_pmsm_foc_sensorless_dyno__B.Abs = fabsf
    (mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead);

  /* Switch: '<S30>/Switch2' */
  mcb_pmsm_foc_sensorless_dyno__B.Switch2_g = (uint16_T)
    (mcb_pmsm_foc_sensorless_dyno__B.Abs > 0.1F);

  /* DataTypeConversion: '<S30>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_i =
    (mcb_pmsm_foc_sensorless_dyno__B.Switch2_g != 0U);

  /* DataStoreWrite: '<S30>/Data Store Write' */
  mcb_pmsm_foc_sensorless_d_DWork.EnClosedLoop =
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_i;

  /* Gain: '<S30>/Gain' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain_a = 0.01369F *
    mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead;

  /* UnitDelay: '<S167>/Unit Delay' */
  mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_d5 =
    mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_m;

  /* Logic: '<S167>/NOT' incorporates:
   *  Constant: '<S167>/Constant_Reset'
   */
  mcb_pmsm_foc_sensorless_dyno__B.NOT_f = true;

  /* Outputs for Enabled SubSystem: '<S167>/Accumulate' incorporates:
   *  EnablePort: '<S168>/Enable'
   */
  /* Delay: '<S168>/Delay' */
  mcb_pmsm_foc_sensorless_dyno__B.Delay_a =
    mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_hd;

  /* Outputs for Enabled SubSystem: '<S168>/Subsystem' incorporates:
   *  EnablePort: '<S169>/Enable'
   */
  if (mcb_pmsm_foc_sensorless_dyno__B.Delay_a) {
    /* SignalConversion generated from: '<S169>/Input' */
    mcb_pmsm_foc_sensorless_dyno__B.Input =
      mcb_pmsm_foc_sensorless_dyno__B.Gain_a;
  }

  /* End of Outputs for SubSystem: '<S168>/Subsystem' */

  /* Sum: '<S168>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_h0 = mcb_pmsm_foc_sensorless_dyno__B.Input
    + mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_d5;

  /* DataTypeConversion: '<S168>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_g = (int16_T)(real32_T)
    floor(mcb_pmsm_foc_sensorless_dyno__B.Add_h0);

  /* DataTypeConversion: '<S168>/Data Type Conversion1' */
  mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion1_d =
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_g;

  /* Sum: '<S168>/Add1' */
  mcb_pmsm_foc_sensorless_dyno__B.Add1_pp =
    mcb_pmsm_foc_sensorless_dyno__B.Add_h0 -
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion1_d;

  /* Update for Delay: '<S168>/Delay' incorporates:
   *  Constant: '<S168>/Constant'
   */
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_hd = true;

  /* End of Outputs for SubSystem: '<S167>/Accumulate' */

  /* Delay: '<S2>/Delay5' */
  mcb_pmsm_foc_sensorless_dyno__B.Delay5[0] =
    mcb_pmsm_foc_sensorless_d_DWork.Delay5_DSTATE[0];
  mcb_pmsm_foc_sensorless_dyno__B.Delay5[1] =
    mcb_pmsm_foc_sensorless_d_DWork.Delay5_DSTATE[1];
  mcb_pmsm_foc_sensorless_dyno__B.Delay5[2] =
    mcb_pmsm_foc_sensorless_d_DWork.Delay5_DSTATE[2];
  mcb_pmsm_foc_sensorless_dyno__B.Delay5[3] =
    mcb_pmsm_foc_sensorless_d_DWork.Delay5_DSTATE[3];

  /* Outputs for IfAction SubSystem: '<S189>/Flux Observer' incorporates:
   *  ActionPort: '<S192>/Action Port'
   */
  /* SwitchCase: '<S189>/Switch Case' */
  mcb_pmsm_foc_s_FluxObserver(mcb_pmsm_foc_sensorless_dyno__B.Delay5,
    mcb_pmsm_foc_sensorless_dyno__B.Merge_f,
    &mcb_pmsm_foc_sensorless_d_DWork.Enable,
    &mcb_pmsm_foc_sensorless_dyno__B.FluxObserver,
    &mcb_pmsm_foc_sensorless_d_DWork.FluxObserver,
    &mcb_pmsm_foc_sen_PrevZCSigState.FluxObserver);

  /* End of Outputs for SubSystem: '<S189>/Flux Observer' */

  /* Switch: '<S30>/Switch' */
  if (mcb_pmsm_foc_sensorless_dyno__B.Switch2_g != 0U) {
    /* Switch: '<S30>/Switch' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch_a =
      mcb_pmsm_foc_sensorless_dyno__B.Merge_f[0];
  } else {
    /* Switch: '<S30>/Switch' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch_a =
      mcb_pmsm_foc_sensorless_dyno__B.Add1_pp;
  }

  /* End of Switch: '<S30>/Switch' */

  /* DataStoreRead: '<S188>/Data Store Read1' */
  mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_o =
    mcb_pmsm_foc_sensorless_d_DWork.IaOffset_motor1;

  /* DataStoreRead: '<S188>/Data Store Read2' */
  mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead2_m =
    mcb_pmsm_foc_sensorless_d_DWork.IbOffset_motor1;

  /* S-Function (c2802xadc): '<S187>/ADC_C_IN2' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_sensorless_dyno__B.ADC_C_IN2 = (AdccResultRegs.ADCRESULT0);
  }

  /* S-Function (c2802xadc): '<S187>/ADC_B_IN2' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_sensorless_dyno__B.ADC_B_IN2 = (AdcbResultRegs.ADCRESULT0);
  }

  /* DataTypeConversion: '<S188>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_j[0] =
    mcb_pmsm_foc_sensorless_dyno__B.ADC_C_IN2;
  mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_j[1] =
    mcb_pmsm_foc_sensorless_dyno__B.ADC_B_IN2;

  /* Sum: '<S188>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_f[0] =
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_j[0] -
    mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_o;
  mcb_pmsm_foc_sensorless_dyno__B.Add_f[1] =
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_j[1] -
    mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead2_m;

  /* Gain: '<S191>/Get ADC Voltage' */
  V_q_ref_unsat = 0.000732600747F * (real32_T)
    mcb_pmsm_foc_sensorless_dyno__B.Add_f[0];
  mcb_pmsm_foc_sensorless_dyno__B.GetADCVoltage_h[0] = V_q_ref_unsat;

  /* Gain: '<S191>/Get Currents' */
  V_q_ref_unsat *= 14.2857141F;
  mcb_pmsm_foc_sensorless_dyno__B.GetCurrents_g[0] = V_q_ref_unsat;

  /* Gain: '<S191>/PU_Conversion' */
  mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion_f[0] = 0.0466666669F *
    V_q_ref_unsat;

  /* Gain: '<S191>/Get ADC Voltage' */
  V_q_ref_unsat = 0.000732600747F * (real32_T)
    mcb_pmsm_foc_sensorless_dyno__B.Add_f[1];
  mcb_pmsm_foc_sensorless_dyno__B.GetADCVoltage_h[1] = V_q_ref_unsat;

  /* Gain: '<S191>/Get Currents' */
  V_q_ref_unsat *= 14.2857141F;
  mcb_pmsm_foc_sensorless_dyno__B.GetCurrents_g[1] = V_q_ref_unsat;

  /* Gain: '<S191>/PU_Conversion' */
  mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion_f[1] = 0.0466666669F *
    V_q_ref_unsat;

  /* Outputs for Atomic SubSystem: '<S34>/Two phase CRL wrap' */
  mcb_pmsm_fo_TwophaseCRLwrap(mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion_f[0],
    mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion_f[1],
    &mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap);

  /* End of Outputs for SubSystem: '<S34>/Two phase CRL wrap' */

  /* Switch: '<S41>/Switch1' incorporates:
   *  Constant: '<S41>/ChosenMethod'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Switch1_of = 3U;

  /* RelationalOperator: '<S176>/Compare' incorporates:
   *  Constant: '<S176>/Constant'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Compare_eq =
    (mcb_pmsm_foc_sensorless_dyno__B.Switch_a < 0.0F);

  /* DataTypeConversion: '<S174>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_f =
    mcb_pmsm_foc_sensorless_dyno__B.Compare_eq;

  /* If: '<S174>/If' */
  if (mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_f > 0U) {
    /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem' incorporates:
     *  ActionPort: '<S177>/Action Port'
     */
    mcb_pmsm__IfActionSubsystem(mcb_pmsm_foc_sensorless_dyno__B.Switch_a,
      &mcb_pmsm_foc_sensorless_dyno__B.Merge_bb,
      &mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S174>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    mcb_pmsm_IfActionSubsystem1(mcb_pmsm_foc_sensorless_dyno__B.Switch_a,
      &mcb_pmsm_foc_sensorless_dyno__B.Merge_bb,
      &mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S174>/If Action Subsystem1' */
  }

  /* End of If: '<S174>/If' */

  /* Gain: '<S172>/indexing' */
  mcb_pmsm_foc_sensorless_dyno__B.indexing_l = 800.0F *
    mcb_pmsm_foc_sensorless_dyno__B.Merge_bb;

  /* DataTypeConversion: '<S172>/Get_Integer' */
  mcb_pmsm_foc_sensorless_dyno__B.Get_Integer_c = (uint16_T)
    mcb_pmsm_foc_sensorless_dyno__B.indexing_l;

  /* Sum: '<S172>/Sum' incorporates:
   *  Constant: '<S172>/offset'
   */
  Sum_o = mcb_pmsm_foc_sensorless_dyno__B.Get_Integer_c + 1UL;
  mcb_pmsm_foc_sensorless_dyno__B.Sum_o[0] = Sum_o;

  /* Selector: '<S172>/Lookup' incorporates:
   *  Constant: '<S172>/sine_table_values'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[0] =
    mcb_pmsm_foc_sensorless__ConstP.pooled73[(int16_T)Sum_o];

  /* Sum: '<S172>/Sum' */
  Sum_o = mcb_pmsm_foc_sensorless_dyno__B.Get_Integer_c;
  mcb_pmsm_foc_sensorless_dyno__B.Sum_o[1] = Sum_o;

  /* Selector: '<S172>/Lookup' incorporates:
   *  Constant: '<S172>/sine_table_values'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[1] =
    mcb_pmsm_foc_sensorless__ConstP.pooled73[(int16_T)Sum_o];

  /* Sum: '<S172>/Sum' incorporates:
   *  Constant: '<S172>/offset'
   */
  Sum_o = mcb_pmsm_foc_sensorless_dyno__B.Get_Integer_c + 201UL;
  mcb_pmsm_foc_sensorless_dyno__B.Sum_o[2] = Sum_o;

  /* Selector: '<S172>/Lookup' incorporates:
   *  Constant: '<S172>/sine_table_values'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[2] =
    mcb_pmsm_foc_sensorless__ConstP.pooled73[(int16_T)Sum_o];

  /* Sum: '<S172>/Sum' incorporates:
   *  Constant: '<S172>/offset'
   */
  Sum_o = mcb_pmsm_foc_sensorless_dyno__B.Get_Integer_c + 200UL;
  mcb_pmsm_foc_sensorless_dyno__B.Sum_o[3] = Sum_o;

  /* Selector: '<S172>/Lookup' incorporates:
   *  Constant: '<S172>/sine_table_values'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[3] =
    mcb_pmsm_foc_sensorless__ConstP.pooled73[(int16_T)Sum_o];

  /* Sum: '<S173>/Sum3' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum3_m =
    mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[0] -
    mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[1];

  /* DataTypeConversion: '<S172>/Data Type Conversion1' */
  mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion1_f =
    mcb_pmsm_foc_sensorless_dyno__B.Get_Integer_c;

  /* Sum: '<S172>/Sum2' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum2_b =
    mcb_pmsm_foc_sensorless_dyno__B.indexing_l -
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion1_f;

  /* Product: '<S173>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_e4 =
    mcb_pmsm_foc_sensorless_dyno__B.Sum3_m *
    mcb_pmsm_foc_sensorless_dyno__B.Sum2_b;

  /* Sum: '<S173>/Sum4' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum4_b =
    mcb_pmsm_foc_sensorless_dyno__B.Product_e4 +
    mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[1];

  /* Sum: '<S173>/Sum5' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum5_d =
    mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[2] -
    mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[3];

  /* Product: '<S173>/Product1' */
  mcb_pmsm_foc_sensorless_dyno__B.Product1_g1 =
    mcb_pmsm_foc_sensorless_dyno__B.Sum5_d *
    mcb_pmsm_foc_sensorless_dyno__B.Sum2_b;

  /* Sum: '<S173>/Sum6' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum6_c =
    mcb_pmsm_foc_sensorless_dyno__B.Product1_g1 +
    mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[3];

  /* Outputs for Atomic SubSystem: '<S31>/Two inputs CRL' */
  mcb_pmsm_foc_TwoinputsCRL_p
    (mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap.algDD_o1,
     mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap.algDD_o2,
     mcb_pmsm_foc_sensorless_dyno__B.Sum4_b,
     mcb_pmsm_foc_sensorless_dyno__B.Sum6_c,
     &mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p);

  /* End of Outputs for SubSystem: '<S31>/Two inputs CRL' */

  /* Sum: '<S38>/Sum' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum_b = mcb_pmsm_foc_sensorless_dyno__B.RT2[1]
    - mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.algDD_o2;

  /* DataStoreRead: '<S38>/Data Store Read1' */
  mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_j =
    mcb_pmsm_foc_sensorless_d_DWork.EnClosedLoop;

  /* Logic: '<S38>/Logical Operator' */
  mcb_pmsm_foc_sensorless_dyno__B.LogicalOperator_j =
    !mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_j;

  /* UnitDelay: '<S38>/Unit Delay' */
  mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_de =
    mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_bc;

  /* MATLAB Function: '<S38>/MATLAB Function' incorporates:
   *  Constant: '<S38>/Ki'
   *  Constant: '<S38>/Kp'
   */
  /* MATLAB Function 'FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/MATLAB Function': '<S110>:1' */
  if (mcb_pmsm_foc_sensorless_dyno__B.LogicalOperator_j) {
    /* '<S110>:1:21' */
    /* '<S110>:1:22' */
    mcb_pmsm_foc_sensorless_d_DWork.integrator_state_p =
      mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_de;
  }

  /* '<S110>:1:26' */
  /* '<S110>:1:29' */
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state_p += 0.2025F *
    mcb_pmsm_foc_sensorless_dyno__B.Sum_b;

  /* '<S110>:1:32' */
  V_q_ref_unsat = 1.44F * mcb_pmsm_foc_sensorless_dyno__B.Sum_b +
    mcb_pmsm_foc_sensorless_d_DWork.integrator_state_p;

  /* '<S110>:1:35' */
  if (V_q_ref_unsat <= 1.0F) {
    y = V_q_ref_unsat;
  } else {
    y = 1.0F;
  }

  if (y >= -1.0F) {
    mcb_pmsm_foc_sensorless_dyno__B.V_q_ref_m = y;
  } else {
    mcb_pmsm_foc_sensorless_dyno__B.V_q_ref_m = -1.0F;
  }

  if (mcb_pmsm_foc_sensorless_dyno__B.V_q_ref_m != V_q_ref_unsat) {
    /* '<S110>:1:38' */
    /* '<S110>:1:39' */
    mcb_pmsm_foc_sensorless_d_DWork.integrator_state_p -= 0.2025F *
      mcb_pmsm_foc_sensorless_dyno__B.Sum_b;
  }

  /* End of MATLAB Function: '<S38>/MATLAB Function' */

  /* Switch: '<S38>/Switch' */
  if (mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_j) {
    /* Switch: '<S38>/Switch' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch_b =
      mcb_pmsm_foc_sensorless_dyno__B.V_q_ref_m;
  } else {
    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S38>/Vq_OpenLoop'
     */
    mcb_pmsm_foc_sensorless_dyno__B.Switch_b = 0.0F;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Sum: '<S37>/Sum' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum_oh = mcb_pmsm_foc_sensorless_dyno__B.RT2[0]
    - mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.algDD_o1;

  /* DataStoreRead: '<S37>/Data Store Read1' */
  mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_i =
    mcb_pmsm_foc_sensorless_d_DWork.EnClosedLoop;

  /* Logic: '<S37>/Logical Operator' */
  mcb_pmsm_foc_sensorless_dyno__B.LogicalOperator_f =
    !mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_i;

  /* UnitDelay: '<S37>/Unit Delay' */
  mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_p =
    mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_k;

  /* MATLAB Function: '<S37>/MATLAB Function' incorporates:
   *  Constant: '<S37>/Ki'
   *  Constant: '<S37>/Kp'
   */
  /* MATLAB Function 'FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/MATLAB Function': '<S54>:1' */
  if (mcb_pmsm_foc_sensorless_dyno__B.LogicalOperator_f) {
    /* '<S54>:1:21' */
    /* '<S54>:1:22' */
    mcb_pmsm_foc_sensorless_d_DWork.integrator_state_j =
      mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_p;
  }

  /* '<S54>:1:26' */
  /* '<S54>:1:29' */
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state_j += 0.2025F *
    mcb_pmsm_foc_sensorless_dyno__B.Sum_oh;

  /* '<S54>:1:32' */
  V_q_ref_unsat = 1.44F * mcb_pmsm_foc_sensorless_dyno__B.Sum_oh +
    mcb_pmsm_foc_sensorless_d_DWork.integrator_state_j;

  /* '<S54>:1:35' */
  if (V_q_ref_unsat <= 1.0F) {
    y = V_q_ref_unsat;
  } else {
    y = 1.0F;
  }

  if (y >= -1.0F) {
    mcb_pmsm_foc_sensorless_dyno__B.V_d_ref_a = y;
  } else {
    mcb_pmsm_foc_sensorless_dyno__B.V_d_ref_a = -1.0F;
  }

  if (mcb_pmsm_foc_sensorless_dyno__B.V_d_ref_a != V_q_ref_unsat) {
    /* '<S54>:1:38' */
    /* '<S54>:1:39' */
    mcb_pmsm_foc_sensorless_d_DWork.integrator_state_j -= 0.2025F *
      mcb_pmsm_foc_sensorless_dyno__B.Sum_oh;
  }

  /* End of MATLAB Function: '<S37>/MATLAB Function' */

  /* Switch: '<S37>/Switch' */
  if (mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_i) {
    /* Switch: '<S37>/Switch' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch_h =
      mcb_pmsm_foc_sensorless_dyno__B.V_d_ref_a;
  } else {
    /* DataStoreRead: '<S37>/Vd_OpenLoop' */
    mcb_pmsm_foc_sensorless_dyno__B.Vd_OpenLoop =
      mcb_pmsm_foc_sensorless_d_DWork.SpeedRef;

    /* Abs: '<S37>/Abs' */
    mcb_pmsm_foc_sensorless_dyno__B.Abs_k = fabsf
      (mcb_pmsm_foc_sensorless_dyno__B.Vd_OpenLoop);

    /* Saturate: '<S37>/Saturation' */
    y = mcb_pmsm_foc_sensorless_dyno__B.Abs_k;
    if (y > 0.5F) {
      /* Saturate: '<S37>/Saturation' */
      mcb_pmsm_foc_sensorless_dyno__B.Saturation = 0.5F;
    } else if (y < 0.15F) {
      /* Saturate: '<S37>/Saturation' */
      mcb_pmsm_foc_sensorless_dyno__B.Saturation = 0.15F;
    } else {
      /* Saturate: '<S37>/Saturation' */
      mcb_pmsm_foc_sensorless_dyno__B.Saturation = y;
    }

    /* End of Saturate: '<S37>/Saturation' */

    /* Switch: '<S37>/Switch' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch_h =
      mcb_pmsm_foc_sensorless_dyno__B.Saturation;
  }

  /* End of Switch: '<S37>/Switch' */

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Constant3'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Switch_m = 0.95F;

  /* Product: '<S41>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_jb = 0.9025F;

  /* Product: '<S42>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_it =
    mcb_pmsm_foc_sensorless_dyno__B.Switch_h *
    mcb_pmsm_foc_sensorless_dyno__B.Switch_h;

  /* Product: '<S42>/Product1' */
  mcb_pmsm_foc_sensorless_dyno__B.Product1_le =
    mcb_pmsm_foc_sensorless_dyno__B.Switch_b *
    mcb_pmsm_foc_sensorless_dyno__B.Switch_b;

  /* Sum: '<S42>/Sum1' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum1_e =
    mcb_pmsm_foc_sensorless_dyno__B.Product_it +
    mcb_pmsm_foc_sensorless_dyno__B.Product1_le;

  /* Outputs for IfAction SubSystem: '<S36>/D-Q Equivalence' incorporates:
   *  ActionPort: '<S39>/Action Port'
   */
  /* If: '<S36>/If' */
  mcb_pmsm_foc__DQEquivalence(mcb_pmsm_foc_sensorless_dyno__B.Switch_h,
    mcb_pmsm_foc_sensorless_dyno__B.Switch_b,
    mcb_pmsm_foc_sensorless_dyno__B.Sum1_e, 0.95F, 0.9025F,
    mcb_pmsm_foc_sensorless_dyno__B.Merge_a,
    &mcb_pmsm_foc_sensorless_dyno__B.DQEquivalence);

  /* End of Outputs for SubSystem: '<S36>/D-Q Equivalence' */

  /* Outputs for Atomic SubSystem: '<S29>/Two inputs CRL' */
  mcb_pmsm_foc_s_TwoinputsCRL(mcb_pmsm_foc_sensorless_dyno__B.Merge_a[0],
    mcb_pmsm_foc_sensorless_dyno__B.Merge_a[1],
    mcb_pmsm_foc_sensorless_dyno__B.Sum4_b,
    mcb_pmsm_foc_sensorless_dyno__B.Sum6_c,
    &mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL);

  /* End of Outputs for SubSystem: '<S29>/Two inputs CRL' */

  /* UnitDelay: '<S267>/Output' */
  mcb_pmsm_foc_sensorless_dyno__B.Output =
    mcb_pmsm_foc_sensorless_d_DWork.Output_DSTATE;

  /* Product: '<S261>/Product1' */
  mcb_pmsm_foc_sensorless_dyno__B.id_Ld_Lq_p =
    mcb_pmsm_foc_sensorless__ConstB.Ld_Lq_a *
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.algDD_o1;

  /* Sum: '<S261>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_gy =
    mcb_pmsm_foc_sensorless_dyno__B.id_Ld_Lq_p +
    mcb_pmsm_foc_sensorless__ConstB.Switch2_h;

  /* Product: '<S261>/Product3' */
  mcb_pmsm_foc_sensorless_dyno__B.Product3_d =
    mcb_pmsm_foc_sensorless_dyno__B.Add_gy *
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.algDD_o2;

  /* Gain: '<S261>/1_5_Pp' */
  mcb_pmsm_foc_sensorless_dyno__B.u_5_Pp_b = 6.0F *
    mcb_pmsm_foc_sensorless_dyno__B.Product3_d;

  /* Product: '<S261>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_cc =
    mcb_pmsm_foc_sensorless_dyno__B.u_5_Pp_b *
    mcb_pmsm_foc_sensorless_dyno__B.Merge_f[1];

  /* Gain: '<S261>/P_si2pu' */
  mcb_pmsm_foc_sensorless_dyno__B.P_output_l = 0.79402F *
    mcb_pmsm_foc_sensorless_dyno__B.Product_cc;

  /* DataStoreRead: '<S26>/Data Store Read' */
  mcb_pmsm_foc_sensorless_dyno__B.mtr1_speed_ref_PU =
    mcb_pmsm_foc_sensorless_d_DWork.SpeedRef;

  /* SignalConversion generated from: '<S26>/Selector' */
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[0] =
    mcb_pmsm_foc_sensorless_dyno__B.RT2[0];
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[1] =
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.algDD_o1;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[2] =
    mcb_pmsm_foc_sensorless_dyno__B.Merge_a[0];
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[3] =
    mcb_pmsm_foc_sensorless_dyno__B.RT2[1];
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[4] =
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.algDD_o2;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[5] =
    mcb_pmsm_foc_sensorless_dyno__B.Merge_a[1];
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[6] =
    mcb_pmsm_foc_sensorless_dyno__B.u_5_Pp_b;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[7] =
    mcb_pmsm_foc_sensorless_dyno__B.P_output_l;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[8] =
    mcb_pmsm_foc_sensorless_dyno__B.Merge_f[1];
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[9] =
    mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion_f[0];
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[10] =
    mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion_f[1];
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[11] =
    mcb_pmsm_foc_sensorless_dyno__B.Merge_f[0];
  for (i = 0; i < 6; i++) {
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[i + 12] =
      mcb_pmsm_foc_sensorless_dyno__B.mtr2_VI_debug[i];
  }

  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[18] =
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Te_PU;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[19] =
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Pm_PU;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[20] =
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Speed_PU;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[21] =
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Iab_meas_PU[0];
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[22] =
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Iab_meas_PU[1];
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[23] =
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Pos_PU;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[24] =
    mcb_pmsm_foc_sensorless_dyno__B.mtr1_speed_ref_PU;

  /* End of SignalConversion generated from: '<S26>/Selector' */

  /* DataStoreRead: '<S26>/Data Store Read1' */
  mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_a =
    mcb_pmsm_foc_sensorless_d_DWork.Debug_signals;

  /* MultiPortSwitch: '<S26>/Multiport Switch' */
  switch (mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_a) {
   case 0:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor16'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 25U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 21U;
    break;

   case 1:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor1'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 25U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 9U;
    break;

   case 2:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor2'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 1U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 2U;
    break;

   case 3:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor3'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 4U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 5U;
    break;

   case 4:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor4'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 3U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 6U;
    break;

   case 5:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor5'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 10U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 11U;
    break;

   case 6:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor6'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 8U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 7U;
    break;

   case 7:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor7'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 13U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 14U;
    break;

   case 8:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor8'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 16U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 17U;
    break;

   case 9:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor9'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 15U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 18U;
    break;

   case 10:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor10'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 22U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 23U;
    break;

   case 11:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor11'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 20U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 19U;
    break;

   case 12:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor12'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 8U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 20U;
    break;

   case 13:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor13'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 7U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 19U;
    break;

   case 14:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor14'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 12U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 24U;
    break;

   default:
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/speed_motor15'
     */
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] = 10U;
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] = 22U;
    break;
  }

  /* End of MultiPortSwitch: '<S26>/Multiport Switch' */

  /* Selector: '<S26>/Selector' */
  mcb_pmsm_foc_sensorless_dyno__B.Selector[0] =
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[(int16_T)
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[0] - 1];
  mcb_pmsm_foc_sensorless_dyno__B.Selector[1] =
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[(int16_T)
    mcb_pmsm_foc_sensorless_dyno__B.MultiportSwitch[1] - 1];

  /* S-Function (any2byte_svd): '<S266>/Byte Pack' */

  /* Pack: <S266>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0U;
    uint16_T MW_inputPortWidth = 0U;

    /* Packed output data type - uint32_T */
    void* packData = &mcb_pmsm_foc_sensorless_dyno__B.BytePack[0];

    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 2 */
    {
      MW_inputPortWidth = (uint16_T)2 * sizeof(real32_T);
      memcpy((void *)&(((uint16_T *)packData)[MW_outputPortOffset]), (void*)
             &mcb_pmsm_foc_sensorless_dyno__B.Selector[0], MW_inputPortWidth);
    }
  }

  /* If: '<S264>/If' */
  if (mcb_pmsm_foc_sensorless_dyno__B.Output == 0U) {
    /* Outputs for IfAction SubSystem: '<S264>/Start' incorporates:
     *  ActionPort: '<S270>/Action Port'
     */
    /* Merge: '<S264>/Merge' incorporates:
     *  Constant: '<S270>/Start'
     *  SignalConversion generated from: '<S270>/Data_out'
     */
    mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Data[0] = 1397969747UL;

    /* SignalConversion generated from: '<S270>/Data' */
    Sum_o = mcb_pmsm_foc_sensorless_dyno__B.BytePack[0];

    /* End of Outputs for SubSystem: '<S264>/Start' */
    mcb_pmsm_foc_sensorless_dyno__B.Data_fw[0] = Sum_o;

    /* Outputs for IfAction SubSystem: '<S264>/Start' incorporates:
     *  ActionPort: '<S270>/Action Port'
     */
    /* Merge: '<S264>/Merge' incorporates:
     *  SignalConversion generated from: '<S270>/Data_out'
     */
    mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Data[1] = Sum_o;

    /* SignalConversion generated from: '<S270>/Data' */
    Sum_o = mcb_pmsm_foc_sensorless_dyno__B.BytePack[1];

    /* End of Outputs for SubSystem: '<S264>/Start' */
    mcb_pmsm_foc_sensorless_dyno__B.Data_fw[1] = Sum_o;

    /* Outputs for IfAction SubSystem: '<S264>/Start' incorporates:
     *  ActionPort: '<S270>/Action Port'
     */
    /* Merge: '<S264>/Merge' incorporates:
     *  SignalConversion generated from: '<S270>/Data_out'
     */
    mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Data[2] = Sum_o;

    /* Merge: '<S264>/Merge1' incorporates:
     *  Bias: '<S270>/Bias'
     */
    mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Iteration =
      mcb_pmsm_foc_sensorless__ConstB.Width + 1UL;

    /* End of Outputs for SubSystem: '<S264>/Start' */
  } else if (mcb_pmsm_foc_sensorless_dyno__B.Output == 599U) {
    /* Outputs for IfAction SubSystem: '<S264>/End' incorporates:
     *  ActionPort: '<S269>/Action Port'
     */
    /* SignalConversion generated from: '<S269>/Data' */
    Sum_o = mcb_pmsm_foc_sensorless_dyno__B.BytePack[0];

    /* End of Outputs for SubSystem: '<S264>/End' */
    mcb_pmsm_foc_sensorless_dyno__B.Data_f[0] = Sum_o;

    /* Outputs for IfAction SubSystem: '<S264>/End' incorporates:
     *  ActionPort: '<S269>/Action Port'
     */
    /* Merge: '<S264>/Merge' incorporates:
     *  SignalConversion generated from: '<S269>/Data_out'
     */
    mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Data[0] = Sum_o;

    /* SignalConversion generated from: '<S269>/Data' */
    Sum_o = mcb_pmsm_foc_sensorless_dyno__B.BytePack[1];

    /* End of Outputs for SubSystem: '<S264>/End' */
    mcb_pmsm_foc_sensorless_dyno__B.Data_f[1] = Sum_o;

    /* Outputs for IfAction SubSystem: '<S264>/End' incorporates:
     *  ActionPort: '<S269>/Action Port'
     */
    /* Merge: '<S264>/Merge' incorporates:
     *  Constant: '<S269>/End'
     *  SignalConversion generated from: '<S269>/Data_out'
     */
    mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Data[1] = Sum_o;
    mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Data[2] = 1162167621UL;

    /* Merge: '<S264>/Merge1' incorporates:
     *  Bias: '<S269>/Bias'
     */
    mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Iteration =
      mcb_pmsm_foc_sensorless__ConstB.Width + 1UL;

    /* End of Outputs for SubSystem: '<S264>/End' */
  } else {
    /* Outputs for IfAction SubSystem: '<S264>/Data' incorporates:
     *  ActionPort: '<S268>/Action Port'
     */
    /* SignalConversion generated from: '<S268>/Data' */
    Sum_o = mcb_pmsm_foc_sensorless_dyno__B.BytePack[0];

    /* End of Outputs for SubSystem: '<S264>/Data' */
    mcb_pmsm_foc_sensorless_dyno__B.Data[0] = Sum_o;

    /* Outputs for IfAction SubSystem: '<S264>/Data' incorporates:
     *  ActionPort: '<S268>/Action Port'
     */
    /* Merge: '<S264>/Merge' incorporates:
     *  SignalConversion generated from: '<S268>/Data_out'
     */
    mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Data[0] = Sum_o;

    /* SignalConversion generated from: '<S268>/Data' */
    Sum_o = mcb_pmsm_foc_sensorless_dyno__B.BytePack[1];

    /* End of Outputs for SubSystem: '<S264>/Data' */
    mcb_pmsm_foc_sensorless_dyno__B.Data[1] = Sum_o;

    /* Outputs for IfAction SubSystem: '<S264>/Data' incorporates:
     *  ActionPort: '<S268>/Action Port'
     */
    /* Merge: '<S264>/Merge' incorporates:
     *  Constant: '<S268>/Dummy'
     *  SignalConversion generated from: '<S268>/Data_out'
     */
    mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Data[1] = Sum_o;
    mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Data[2] = 0UL;

    /* Merge: '<S264>/Merge1' incorporates:
     *  SignalConversion generated from: '<S268>/Data_width'
     */
    mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Iteration =
      mcb_pmsm_foc_sensorless__ConstB.Width;

    /* End of Outputs for SubSystem: '<S264>/Data' */
  }

  /* End of If: '<S264>/If' */

  /* Outputs for Iterator SubSystem: '<S25>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S265>/While Iterator'
   */
  i = 1;
  do {
    mcb_pmsm_foc_sensorless_dyno__B.WhileIterator = i;
    mcb_pmsm_foc_sensorless_dyno__B.IndexVector =
      mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Data[mcb_pmsm_foc_sensorless_dyno__B.WhileIterator
      - 1];

    {
      if (checkSCITransmitInProgressA != 1U) {
        checkSCITransmitInProgressA = 1U;
        int16_T errFlgHeader = NOERROR;
        int16_T errFlgData = NOERROR;
        int16_T errFlgTail = NOERROR;
        errFlgData = scia_xmit((uchar_T*)
          &mcb_pmsm_foc_sensorless_dyno__B.IndexVector, 4, 4);
        checkSCITransmitInProgressA = 0U;
      }
    }

    mcb_pmsm_foc_sensorless_dyno__B.Add_ci =
      mcb_pmsm_foc_sensorless_dyno__B.SCI_Tx_Iteration - (uint32_T)
      mcb_pmsm_foc_sensorless_dyno__B.WhileIterator;
    i++;
  } while (mcb_pmsm_foc_sensorless_dyno__B.Add_ci != 0UL);

  /* End of Outputs for SubSystem: '<S25>/While Iterator Subsystem' */

  /* Sum: '<S271>/FixPt Sum1' incorporates:
   *  Constant: '<S271>/FixPt Constant'
   */
  mcb_pmsm_foc_sensorless_dyno__B.FixPtSum1 =
    mcb_pmsm_foc_sensorless_dyno__B.Output + 1U;

  /* Switch: '<S272>/FixPt Switch' */
  if (mcb_pmsm_foc_sensorless_dyno__B.FixPtSum1 > 599U) {
    /* Switch: '<S272>/FixPt Switch' incorporates:
     *  Constant: '<S272>/Constant'
     */
    mcb_pmsm_foc_sensorless_dyno__B.FixPtSwitch = 0U;
  } else {
    /* Switch: '<S272>/FixPt Switch' */
    mcb_pmsm_foc_sensorless_dyno__B.FixPtSwitch =
      mcb_pmsm_foc_sensorless_dyno__B.FixPtSum1;
  }

  /* End of Switch: '<S272>/FixPt Switch' */

  /* DataStoreRead: '<S23>/Enable' */
  mcb_pmsm_foc_sensorless_dyno__B.Enable_l =
    mcb_pmsm_foc_sensorless_d_DWork.Enable;

  /* DataTypeConversion: '<S23>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_c =
    mcb_pmsm_foc_sensorless_dyno__B.Enable_l;

  /* Switch: '<S22>/Switch' */
  mcb_pmsm_foc_sensorless_dyno__B.Switch_p =
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_c;

  /* S-Function (c280xgpio_do): '<S22>/DRV830x Enable' */
  {
    if (mcb_pmsm_foc_sensorless_dyno__B.Switch_p) {
      GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
    } else {
      GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
    }
  }

  /* Switch: '<S22>/Switch1' */
  if (mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_c >= 0.5F) {
    /* Gain: '<S186>/sqrt3_by_two' */
    mcb_pmsm_foc_sensorless_dyno__B.sqrt3_by_two_n = 0.866025388F *
      mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.algDD_o2;

    /* Gain: '<S186>/one_by_two' */
    mcb_pmsm_foc_sensorless_dyno__B.one_by_two_g = 0.5F *
      mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.algDD_o1;

    /* Sum: '<S186>/add_c' */
    mcb_pmsm_foc_sensorless_dyno__B.add_c_a = (0.0F -
      mcb_pmsm_foc_sensorless_dyno__B.one_by_two_g) -
      mcb_pmsm_foc_sensorless_dyno__B.sqrt3_by_two_n;

    /* Sum: '<S186>/add_b' */
    mcb_pmsm_foc_sensorless_dyno__B.add_b_o =
      mcb_pmsm_foc_sensorless_dyno__B.sqrt3_by_two_n -
      mcb_pmsm_foc_sensorless_dyno__B.one_by_two_g;

    /* MinMax: '<S183>/Min' */
    y = mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.algDD_o1;
    V_q_ref_unsat = mcb_pmsm_foc_sensorless_dyno__B.add_b_o;
    if ((y <= V_q_ref_unsat) || rtIsNaNF(V_q_ref_unsat)) {
      V_q_ref_unsat = y;
    }

    y = mcb_pmsm_foc_sensorless_dyno__B.add_c_a;
    if ((!(V_q_ref_unsat <= y)) && (!rtIsNaNF(y))) {
      V_q_ref_unsat = y;
    }

    /* MinMax: '<S183>/Min' */
    mcb_pmsm_foc_sensorless_dyno__B.Min_a = V_q_ref_unsat;

    /* MinMax: '<S183>/Max' */
    y = mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.algDD_o1;
    V_q_ref_unsat = mcb_pmsm_foc_sensorless_dyno__B.add_b_o;
    if ((y >= V_q_ref_unsat) || rtIsNaNF(V_q_ref_unsat)) {
      V_q_ref_unsat = y;
    }

    y = mcb_pmsm_foc_sensorless_dyno__B.add_c_a;
    if ((!(V_q_ref_unsat >= y)) && (!rtIsNaNF(y))) {
      V_q_ref_unsat = y;
    }

    /* MinMax: '<S183>/Max' */
    mcb_pmsm_foc_sensorless_dyno__B.Max_n = V_q_ref_unsat;

    /* Sum: '<S183>/Add' */
    mcb_pmsm_foc_sensorless_dyno__B.Add_b0 =
      mcb_pmsm_foc_sensorless_dyno__B.Max_n +
      mcb_pmsm_foc_sensorless_dyno__B.Min_a;

    /* Gain: '<S183>/one_by_two' */
    mcb_pmsm_foc_sensorless_dyno__B.one_by_two_i = -0.5F *
      mcb_pmsm_foc_sensorless_dyno__B.Add_b0;

    /* Sum: '<S182>/Add3' */
    mcb_pmsm_foc_sensorless_dyno__B.Add3_m =
      mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.algDD_o1 +
      mcb_pmsm_foc_sensorless_dyno__B.one_by_two_i;

    /* Sum: '<S182>/Add2' */
    mcb_pmsm_foc_sensorless_dyno__B.Add2_p =
      mcb_pmsm_foc_sensorless_dyno__B.one_by_two_i +
      mcb_pmsm_foc_sensorless_dyno__B.add_c_a;

    /* Sum: '<S182>/Add1' */
    mcb_pmsm_foc_sensorless_dyno__B.Add1_of =
      mcb_pmsm_foc_sensorless_dyno__B.add_b_o +
      mcb_pmsm_foc_sensorless_dyno__B.one_by_two_i;

    /* Gain: '<S182>/Gain' */
    mcb_pmsm_foc_sensorless_dyno__B.Gain_m[0] = 1.15470052F *
      mcb_pmsm_foc_sensorless_dyno__B.Add3_m;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_m[1] = 1.15470052F *
      mcb_pmsm_foc_sensorless_dyno__B.Add1_of;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_m[2] = 1.15470052F *
      mcb_pmsm_foc_sensorless_dyno__B.Add2_p;

    /* Gain: '<S23>/One_by_Two' */
    V_q_ref_unsat = 0.5F * mcb_pmsm_foc_sensorless_dyno__B.Gain_m[0];
    mcb_pmsm_foc_sensorless_dyno__B.One_by_Two[0] = V_q_ref_unsat;

    /* Sum: '<S23>/Sum' incorporates:
     *  Constant: '<S23>/Constant'
     */
    V_q_ref_unsat += 0.5F;
    mcb_pmsm_foc_sensorless_dyno__B.PWM_Duty_Cycles_i[0] = V_q_ref_unsat;

    /* Gain: '<S22>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD_n = (uint16_T)(5000.0F * V_q_ref_unsat);
    mcb_pmsm_foc_sensorless_dyno__B.Scale_to_PWM_Counter_PRD_n[0] =
      Scale_to_PWM_Counter_PRD_n;

    /* Switch: '<S22>/Switch1' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_n[0] = Scale_to_PWM_Counter_PRD_n;

    /* Gain: '<S23>/One_by_Two' */
    V_q_ref_unsat = 0.5F * mcb_pmsm_foc_sensorless_dyno__B.Gain_m[1];
    mcb_pmsm_foc_sensorless_dyno__B.One_by_Two[1] = V_q_ref_unsat;

    /* Sum: '<S23>/Sum' incorporates:
     *  Constant: '<S23>/Constant'
     */
    V_q_ref_unsat += 0.5F;
    mcb_pmsm_foc_sensorless_dyno__B.PWM_Duty_Cycles_i[1] = V_q_ref_unsat;

    /* Gain: '<S22>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD_n = (uint16_T)(5000.0F * V_q_ref_unsat);
    mcb_pmsm_foc_sensorless_dyno__B.Scale_to_PWM_Counter_PRD_n[1] =
      Scale_to_PWM_Counter_PRD_n;

    /* Switch: '<S22>/Switch1' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_n[1] = Scale_to_PWM_Counter_PRD_n;

    /* Gain: '<S23>/One_by_Two' */
    V_q_ref_unsat = 0.5F * mcb_pmsm_foc_sensorless_dyno__B.Gain_m[2];
    mcb_pmsm_foc_sensorless_dyno__B.One_by_Two[2] = V_q_ref_unsat;

    /* Sum: '<S23>/Sum' incorporates:
     *  Constant: '<S23>/Constant'
     */
    V_q_ref_unsat += 0.5F;
    mcb_pmsm_foc_sensorless_dyno__B.PWM_Duty_Cycles_i[2] = V_q_ref_unsat;

    /* Gain: '<S22>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD_n = (uint16_T)(5000.0F * V_q_ref_unsat);
    mcb_pmsm_foc_sensorless_dyno__B.Scale_to_PWM_Counter_PRD_n[2] =
      Scale_to_PWM_Counter_PRD_n;

    /* Switch: '<S22>/Switch1' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_n[2] = Scale_to_PWM_Counter_PRD_n;
  } else {
    /* Switch: '<S22>/Switch1' incorporates:
     *  Constant: '<S22>/stop'
     */
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_n[0] = 0U;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_n[1] = 0U;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_n[2] = 0U;
  }

  /* End of Switch: '<S22>/Switch1' */

  /* S-Function (c2802xpwm): '<S22>/ePWM1' */
  uint16_T tbprdValue1Outputs = EPwm1Regs.TBPRD;

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)
      (mcb_pmsm_foc_sensorless_dyno__B.Switch1_n[0]);
  }

  /* S-Function (c2802xpwm): '<S22>/ePWM2' */
  uint16_T tbprdValue2Outputs = EPwm2Regs.TBPRD;

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)
      (mcb_pmsm_foc_sensorless_dyno__B.Switch1_n[1]);
  }

  /* S-Function (c2802xpwm): '<S22>/ePWM3' */
  uint16_T tbprdValue3Outputs = EPwm3Regs.TBPRD;

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.bit.CMPA = (uint16_T)
      (mcb_pmsm_foc_sensorless_dyno__B.Switch1_n[2]);
  }

  /* SignalConversion generated from: '<S2>/Speed_fb' */
  mcb_pmsm_foc_sensorless_dyno__B.OutportBufferForSpeed_fb =
    mcb_pmsm_foc_sensorless_dyno__B.Merge_f[1];

  /* SignalConversion generated from: '<S2>/Delay5' */
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelay5Inpo[0] =
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.algDD_o1;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelay5Inpo[1] =
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.algDD_o2;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelay5Inpo[2] =
    mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap.algDD_o1;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelay5Inpo[3] =
    mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap.algDD_o2;

  /* Update for UnitDelay: '<S167>/Unit Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_m =
    mcb_pmsm_foc_sensorless_dyno__B.Add1_pp;

  /* Update for Delay: '<S2>/Delay5' */
  mcb_pmsm_foc_sensorless_d_DWork.Delay5_DSTATE[0] =
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelay5Inpo[0];
  mcb_pmsm_foc_sensorless_d_DWork.Delay5_DSTATE[1] =
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelay5Inpo[1];
  mcb_pmsm_foc_sensorless_d_DWork.Delay5_DSTATE[2] =
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelay5Inpo[2];
  mcb_pmsm_foc_sensorless_d_DWork.Delay5_DSTATE[3] =
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelay5Inpo[3];

  /* Update for UnitDelay: '<S38>/Unit Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_bc =
    mcb_pmsm_foc_sensorless_dyno__B.Switch_b;

  /* Update for UnitDelay: '<S37>/Unit Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_k =
    mcb_pmsm_foc_sensorless_dyno__B.Switch_h;

  /* Update for UnitDelay: '<S267>/Output' */
  mcb_pmsm_foc_sensorless_d_DWork.Output_DSTATE =
    mcb_pmsm_foc_sensorless_dyno__B.FixPtSwitch;
}

/* System initialize for function-call system: '<Root>/FOC Algorithm Motor 2' */
void mcb_FOCAlgorithmMotor2_Init(void)
{
  /* Start for S-Function (c2802xadc): '<S385>/ADC_C_IN4' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC1 ();

  /* Start for S-Function (c2802xadc): '<S385>/ADC_B_IN4' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC1 ();

  /* Start for S-Function (c280xgpio_do): '<S458>/Bottom DRV8305 EN' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFCFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x4000000U;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S458>/ePWM4' */
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

  /* Start for S-Function (c2802xpwm): '<S458>/ePWM5' */
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

  /* Start for S-Function (c2802xpwm): '<S458>/ePWM6' */
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

  /* SystemInitialize for Atomic SubSystem: '<S274>/Delay to start motor2 (codegen)' */
  /* SystemInitialize for Enabled SubSystem: '<S381>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  /* InitializeConditions for UnitDelay: '<S383>/Unit Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_gq = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S381>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  /* End of SystemInitialize for SubSystem: '<S274>/Delay to start motor2 (codegen)' */

  /* SystemInitialize for MATLAB Function: '<S289>/MATLAB Function' */
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state_l = 0.0F;

  /* SystemInitialize for MATLAB Function: '<S290>/MATLAB Function' */
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S387>/Flux Observer' */
  mcb_pmsm__FluxObserver_Init(&mcb_pmsm_foc_sensorless_d_DWork.FluxObserver_a);

  /* End of SystemInitialize for SubSystem: '<S387>/Flux Observer' */

  /* SystemInitialize for IfAction SubSystem: '<S387>/Sliding Mode Observer' */
  /* InitializeConditions for Delay: '<S433>/Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_m = 0.0F;

  /* InitializeConditions for Delay: '<S443>/Delay1' */
  mcb_pmsm_foc_sensorless_d_DWork.Delay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S434>/Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_n = 0.0F;

  /* InitializeConditions for Delay: '<S444>/Delay1' */
  mcb_pmsm_foc_sensorless_d_DWork.Delay1_DSTATE_i = 0.0F;

  /* InitializeConditions for Delay: '<S431>/Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_j = 0.0F;

  /* InitializeConditions for Delay: '<S438>/Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.CircBufIdx = 0U;

  /* End of SystemInitialize for SubSystem: '<S387>/Sliding Mode Observer' */

  /* SystemInitialize for Merge: '<S387>/Merge' */
  mcb_pmsm_foc_sensorless_dyno__B.Merge[0] = 0.0F;
  mcb_pmsm_foc_sensorless_dyno__B.Merge[1] = 0.0F;
}

/* System reset for function-call system: '<Root>/FOC Algorithm Motor 2' */
void mc_FOCAlgorithmMotor2_Reset(void)
{
  /* SystemReset for MATLAB Function: '<S290>/MATLAB Function' */
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state = 0.0F;

  /* SystemReset for MATLAB Function: '<S289>/MATLAB Function' */
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state_l = 0.0F;
}

/* Disable for function-call system: '<Root>/FOC Algorithm Motor 2' */
#pragma CODE_SECTION (FOCAlgorithmMotor2_Disable, "ramfuncs")

void FOCAlgorithmMotor2_Disable(void)
{
  /* Disable for Atomic SubSystem: '<S274>/Delay to start motor2 (codegen)' */
  /* Disable for Enabled SubSystem: '<S381>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  mcb_pmsm_foc_sensorless_d_DWork.EnableEnMtr2TrqCtrlafter2secdel = false;

  /* End of Disable for SubSystem: '<S381>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  /* End of Disable for SubSystem: '<S274>/Delay to start motor2 (codegen)' */
}

/* Output and update for function-call system: '<Root>/FOC Algorithm Motor 2' */
#pragma CODE_SECTION (mcb_pmsm_FOCAlgorithmMotor2, "ramfuncs")

void mcb_pmsm_FOCAlgorithmMotor2(void)
{
  real32_T V_q_ref_unsat;
  real32_T y;
  uint32_T Sum;
  uint16_T Scale_to_PWM_Counter_PRD;

  /* Outputs for Atomic SubSystem: '<S274>/Delay to start motor2 (codegen)' */
  /* DataStoreRead: '<S381>/Data Store Read2' */
  mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead2_a =
    mcb_pmsm_foc_sensorless_d_DWork.EnClosedLoop;

  /* DataStoreRead: '<S381>/Data Store Read1' */
  mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_l =
    mcb_pmsm_foc_sensorless_d_DWork.Enable;

  /* Logic: '<S381>/AND' */
  mcb_pmsm_foc_sensorless_dyno__B.AND =
    (mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead2_a &&
     mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_l);

  /* Logic: '<S381>/NOT' */
  mcb_pmsm_foc_sensorless_dyno__B.NOT_d = !mcb_pmsm_foc_sensorless_dyno__B.AND;

  /* Outputs for Enabled SubSystem: '<S381>/Disable EnMtr2TrqCtrl' incorporates:
   *  EnablePort: '<S382>/Enable'
   */
  if (mcb_pmsm_foc_sensorless_dyno__B.NOT_d) {
    /* DataStoreWrite: '<S382>/Data Store Write' incorporates:
     *  Constant: '<S382>/Constant'
     */
    mcb_pmsm_foc_sensorless_d_DWork.EnMtr2TrqCtrl = false;
  }

  /* End of Outputs for SubSystem: '<S381>/Disable EnMtr2TrqCtrl' */

  /* Outputs for Enabled SubSystem: '<S381>/Enable EnMtr2TrqCtrl after 2 sec delay' incorporates:
   *  EnablePort: '<S383>/Enable'
   */
  if (mcb_pmsm_foc_sensorless_dyno__B.AND) {
    if (!mcb_pmsm_foc_sensorless_d_DWork.EnableEnMtr2TrqCtrlafter2secdel) {
      /* InitializeConditions for UnitDelay: '<S383>/Unit Delay' */
      mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_gq = 0.0F;
      mcb_pmsm_foc_sensorless_d_DWork.EnableEnMtr2TrqCtrlafter2secdel = true;
    }

    /* UnitDelay: '<S383>/Unit Delay' */
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_n =
      mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_gq;

    /* Sum: '<S383>/Add' incorporates:
     *  Constant: '<S383>/Constant2'
     */
    mcb_pmsm_foc_sensorless_dyno__B.Add_cd =
      mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_n + 1.0F;

    /* Switch: '<S383>/Switch' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch_ny =
      (mcb_pmsm_foc_sensorless_dyno__B.Add_cd > 40000.0F);

    /* Outputs for Enabled SubSystem: '<S383>/Enable EnMtr2TrqCtrl' incorporates:
     *  EnablePort: '<S384>/Enable'
     */
    if (mcb_pmsm_foc_sensorless_dyno__B.Switch_ny) {
      /* DataStoreWrite: '<S384>/Data Store Write' incorporates:
       *  Constant: '<S384>/Constant'
       */
      mcb_pmsm_foc_sensorless_d_DWork.EnMtr2TrqCtrl = true;
    }

    /* End of Outputs for SubSystem: '<S383>/Enable EnMtr2TrqCtrl' */

    /* Update for UnitDelay: '<S383>/Unit Delay' */
    mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_gq =
      mcb_pmsm_foc_sensorless_dyno__B.Add_cd;
  } else {
    mcb_pmsm_foc_sensorless_d_DWork.EnableEnMtr2TrqCtrlafter2secdel = false;
  }

  /* End of Outputs for SubSystem: '<S381>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  /* End of Outputs for SubSystem: '<S274>/Delay to start motor2 (codegen)' */

  /* DataStoreRead: '<S386>/Data Store Read1' */
  mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1 =
    mcb_pmsm_foc_sensorless_d_DWork.IaOffset_motor2;

  /* DataStoreRead: '<S386>/Data Store Read2' */
  mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead2 =
    mcb_pmsm_foc_sensorless_d_DWork.IbOffset_motor2;

  /* S-Function (c2802xadc): '<S385>/ADC_C_IN4' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_sensorless_dyno__B.ADC_C_IN4 = (AdccResultRegs.ADCRESULT1);
  }

  /* S-Function (c2802xadc): '<S385>/ADC_B_IN4' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_sensorless_dyno__B.ADC_B_IN4 = (AdcbResultRegs.ADCRESULT1);
  }

  /* DataTypeConversion: '<S386>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_n[0] =
    mcb_pmsm_foc_sensorless_dyno__B.ADC_C_IN4;
  mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_n[1] =
    mcb_pmsm_foc_sensorless_dyno__B.ADC_B_IN4;

  /* Sum: '<S386>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_bh[0] =
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_n[0] -
    mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1;
  mcb_pmsm_foc_sensorless_dyno__B.Add_bh[1] =
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_n[1] -
    mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead2;

  /* Gain: '<S389>/Get ADC Voltage' */
  V_q_ref_unsat = 0.000732600747F * (real32_T)
    mcb_pmsm_foc_sensorless_dyno__B.Add_bh[0];
  mcb_pmsm_foc_sensorless_dyno__B.GetADCVoltage[0] = V_q_ref_unsat;

  /* Gain: '<S389>/Get Currents' */
  V_q_ref_unsat *= 14.2857141F;
  mcb_pmsm_foc_sensorless_dyno__B.GetCurrents[0] = V_q_ref_unsat;

  /* Gain: '<S389>/PU_Conversion' */
  mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion[0] = 0.0466666669F *
    V_q_ref_unsat;

  /* Gain: '<S389>/Get ADC Voltage' */
  V_q_ref_unsat = 0.000732600747F * (real32_T)
    mcb_pmsm_foc_sensorless_dyno__B.Add_bh[1];
  mcb_pmsm_foc_sensorless_dyno__B.GetADCVoltage[1] = V_q_ref_unsat;

  /* Gain: '<S389>/Get Currents' */
  V_q_ref_unsat *= 14.2857141F;
  mcb_pmsm_foc_sensorless_dyno__B.GetCurrents[1] = V_q_ref_unsat;

  /* Gain: '<S389>/PU_Conversion' */
  mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion[1] = 0.0466666669F *
    V_q_ref_unsat;

  /* Outputs for Atomic SubSystem: '<S286>/Two phase CRL wrap' */
  mcb_pmsm_fo_TwophaseCRLwrap(mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion[0],
    mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion[1],
    &mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap_g);

  /* End of Outputs for SubSystem: '<S286>/Two phase CRL wrap' */

  /* Delay: '<S3>/Delay' */
  mcb_pmsm_foc_sensorless_dyno__B.Delay_j[0] =
    mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE[0];
  mcb_pmsm_foc_sensorless_dyno__B.Delay_j[1] =
    mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE[1];
  mcb_pmsm_foc_sensorless_dyno__B.Delay_j[2] =
    mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE[2];
  mcb_pmsm_foc_sensorless_dyno__B.Delay_j[3] =
    mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE[3];

  /* Outputs for IfAction SubSystem: '<S387>/Flux Observer' incorporates:
   *  ActionPort: '<S390>/Action Port'
   */
  /* SwitchCase: '<S387>/Switch Case' */
  mcb_pmsm_foc_s_FluxObserver(mcb_pmsm_foc_sensorless_dyno__B.Delay_j,
    mcb_pmsm_foc_sensorless_dyno__B.Merge,
    &mcb_pmsm_foc_sensorless_d_DWork.Enable,
    &mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a,
    &mcb_pmsm_foc_sensorless_d_DWork.FluxObserver_a,
    &mcb_pmsm_foc_sen_PrevZCSigState.FluxObserver_a);

  /* End of Outputs for SubSystem: '<S387>/Flux Observer' */

  /* RelationalOperator: '<S370>/Compare' incorporates:
   *  Constant: '<S370>/Constant'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Compare_i =
    (mcb_pmsm_foc_sensorless_dyno__B.Merge[0] < 0.0F);

  /* DataTypeConversion: '<S368>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_cf =
    mcb_pmsm_foc_sensorless_dyno__B.Compare_i;

  /* If: '<S368>/If' */
  if (mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_cf > 0U) {
    /* Outputs for IfAction SubSystem: '<S368>/If Action Subsystem' incorporates:
     *  ActionPort: '<S371>/Action Port'
     */
    mcb_pmsm__IfActionSubsystem(mcb_pmsm_foc_sensorless_dyno__B.Merge[0],
      &mcb_pmsm_foc_sensorless_dyno__B.Merge_b,
      &mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem_k);

    /* End of Outputs for SubSystem: '<S368>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S368>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S372>/Action Port'
     */
    mcb_pmsm_IfActionSubsystem1(mcb_pmsm_foc_sensorless_dyno__B.Merge[0],
      &mcb_pmsm_foc_sensorless_dyno__B.Merge_b,
      &mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem1_f);

    /* End of Outputs for SubSystem: '<S368>/If Action Subsystem1' */
  }

  /* End of If: '<S368>/If' */

  /* Gain: '<S366>/indexing' */
  mcb_pmsm_foc_sensorless_dyno__B.indexing = 800.0F *
    mcb_pmsm_foc_sensorless_dyno__B.Merge_b;

  /* DataTypeConversion: '<S366>/Get_Integer' */
  mcb_pmsm_foc_sensorless_dyno__B.Get_Integer = (uint16_T)
    mcb_pmsm_foc_sensorless_dyno__B.indexing;

  /* Sum: '<S366>/Sum' incorporates:
   *  Constant: '<S366>/offset'
   */
  Sum = mcb_pmsm_foc_sensorless_dyno__B.Get_Integer + 1UL;
  mcb_pmsm_foc_sensorless_dyno__B.Sum[0] = Sum;

  /* Selector: '<S366>/Lookup' incorporates:
   *  Constant: '<S366>/sine_table_values'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Lookup[0] =
    mcb_pmsm_foc_sensorless__ConstP.pooled73[(int16_T)Sum];

  /* Sum: '<S366>/Sum' */
  Sum = mcb_pmsm_foc_sensorless_dyno__B.Get_Integer;
  mcb_pmsm_foc_sensorless_dyno__B.Sum[1] = Sum;

  /* Selector: '<S366>/Lookup' incorporates:
   *  Constant: '<S366>/sine_table_values'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Lookup[1] =
    mcb_pmsm_foc_sensorless__ConstP.pooled73[(int16_T)Sum];

  /* Sum: '<S366>/Sum' incorporates:
   *  Constant: '<S366>/offset'
   */
  Sum = mcb_pmsm_foc_sensorless_dyno__B.Get_Integer + 201UL;
  mcb_pmsm_foc_sensorless_dyno__B.Sum[2] = Sum;

  /* Selector: '<S366>/Lookup' incorporates:
   *  Constant: '<S366>/sine_table_values'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Lookup[2] =
    mcb_pmsm_foc_sensorless__ConstP.pooled73[(int16_T)Sum];

  /* Sum: '<S366>/Sum' incorporates:
   *  Constant: '<S366>/offset'
   */
  Sum = mcb_pmsm_foc_sensorless_dyno__B.Get_Integer + 200UL;
  mcb_pmsm_foc_sensorless_dyno__B.Sum[3] = Sum;

  /* Selector: '<S366>/Lookup' incorporates:
   *  Constant: '<S366>/sine_table_values'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Lookup[3] =
    mcb_pmsm_foc_sensorless__ConstP.pooled73[(int16_T)Sum];

  /* Sum: '<S367>/Sum3' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum3 = mcb_pmsm_foc_sensorless_dyno__B.Lookup
    [0] - mcb_pmsm_foc_sensorless_dyno__B.Lookup[1];

  /* DataTypeConversion: '<S366>/Data Type Conversion1' */
  mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion1 =
    mcb_pmsm_foc_sensorless_dyno__B.Get_Integer;

  /* Sum: '<S366>/Sum2' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum2 =
    mcb_pmsm_foc_sensorless_dyno__B.indexing -
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion1;

  /* Product: '<S367>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_dx =
    mcb_pmsm_foc_sensorless_dyno__B.Sum3 * mcb_pmsm_foc_sensorless_dyno__B.Sum2;

  /* Sum: '<S367>/Sum4' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum4 =
    mcb_pmsm_foc_sensorless_dyno__B.Product_dx +
    mcb_pmsm_foc_sensorless_dyno__B.Lookup[1];

  /* Sum: '<S367>/Sum5' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum5 = mcb_pmsm_foc_sensorless_dyno__B.Lookup
    [2] - mcb_pmsm_foc_sensorless_dyno__B.Lookup[3];

  /* Product: '<S367>/Product1' */
  mcb_pmsm_foc_sensorless_dyno__B.Product1_f =
    mcb_pmsm_foc_sensorless_dyno__B.Sum5 * mcb_pmsm_foc_sensorless_dyno__B.Sum2;

  /* Sum: '<S367>/Sum6' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum6 =
    mcb_pmsm_foc_sensorless_dyno__B.Product1_f +
    mcb_pmsm_foc_sensorless_dyno__B.Lookup[3];

  /* Outputs for Atomic SubSystem: '<S283>/Two inputs CRL' */
  mcb_pmsm_foc_TwoinputsCRL_p
    (mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap_g.algDD_o1,
     mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap_g.algDD_o2,
     mcb_pmsm_foc_sensorless_dyno__B.Sum4, mcb_pmsm_foc_sensorless_dyno__B.Sum6,
     &mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h);

  /* End of Outputs for SubSystem: '<S283>/Two inputs CRL' */

  /* Product: '<S460>/Product1' */
  mcb_pmsm_foc_sensorless_dyno__B.id_Ld_Lq =
    mcb_pmsm_foc_sensorless__ConstB.Ld_Lq *
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.algDD_o1;

  /* Sum: '<S460>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_gw =
    mcb_pmsm_foc_sensorless_dyno__B.id_Ld_Lq +
    mcb_pmsm_foc_sensorless__ConstB.Switch2;

  /* Product: '<S460>/Product3' */
  mcb_pmsm_foc_sensorless_dyno__B.Product3_e =
    mcb_pmsm_foc_sensorless_dyno__B.Add_gw *
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.algDD_o2;

  /* Gain: '<S460>/1_5_Pp' */
  mcb_pmsm_foc_sensorless_dyno__B.u_5_Pp = 6.0F *
    mcb_pmsm_foc_sensorless_dyno__B.Product3_e;

  /* SignalConversion generated from: '<S3>/mtr2_debug' */
  mcb_pmsm_foc_sensorless_dyno__B.mtr2_Te_PU_i =
    mcb_pmsm_foc_sensorless_dyno__B.u_5_Pp;

  /* Product: '<S460>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_en =
    mcb_pmsm_foc_sensorless_dyno__B.u_5_Pp *
    mcb_pmsm_foc_sensorless_dyno__B.Merge[1];

  /* Gain: '<S460>/P_si2pu' */
  mcb_pmsm_foc_sensorless_dyno__B.P_output = 0.79402F *
    mcb_pmsm_foc_sensorless_dyno__B.Product_en;

  /* SignalConversion generated from: '<S3>/mtr2_debug' */
  mcb_pmsm_foc_sensorless_dyno__B.mtr2_Pm_PU_m =
    mcb_pmsm_foc_sensorless_dyno__B.P_output;

  /* SignalConversion generated from: '<S3>/mtr2_debug' */
  mcb_pmsm_foc_sensorless_dyno__B.mtr2_Speed_PU_h =
    mcb_pmsm_foc_sensorless_dyno__B.Merge[1];

  /* SignalConversion generated from: '<S3>/mtr2_debug' */
  mcb_pmsm_foc_sensorless_dyno__B.mtr2_Iab_meas_PU_j[0] =
    mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion[0];
  mcb_pmsm_foc_sensorless_dyno__B.mtr2_Iab_meas_PU_j[1] =
    mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion[1];

  /* SignalConversion generated from: '<S3>/mtr2_debug' */
  mcb_pmsm_foc_sensorless_dyno__B.mtr2_Pos_PU_d =
    mcb_pmsm_foc_sensorless_dyno__B.Merge[0];

  /* Switch: '<S293>/Switch1' incorporates:
   *  Constant: '<S293>/ChosenMethod'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Switch1_km = 3U;

  /* Sum: '<S290>/Sum' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum_g = mcb_pmsm_foc_sensorless_dyno__B.RT6[1]
    - mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.algDD_o2;

  /* DataStoreRead: '<S3>/Enable' */
  mcb_pmsm_foc_sensorless_dyno__B.Enable =
    mcb_pmsm_foc_sensorless_d_DWork.EnMtr2TrqCtrl;

  /* Logic: '<S290>/Logical Operator' */
  mcb_pmsm_foc_sensorless_dyno__B.LogicalOperator =
    !mcb_pmsm_foc_sensorless_dyno__B.Enable;

  /* MATLAB Function: '<S290>/MATLAB Function' incorporates:
   *  Constant: '<S290>/Ki'
   *  Constant: '<S290>/Kp'
   *  Constant: '<S290>/Kp1'
   */
  /* MATLAB Function 'FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/MATLAB Function': '<S361>:1' */
  if (mcb_pmsm_foc_sensorless_dyno__B.LogicalOperator) {
    /* '<S361>:1:21' */
    /* '<S361>:1:22' */
    mcb_pmsm_foc_sensorless_d_DWork.integrator_state = 0.0F;
  }

  /* '<S361>:1:26' */
  /* '<S361>:1:29' */
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state += 0.2025F *
    mcb_pmsm_foc_sensorless_dyno__B.Sum_g;

  /* '<S361>:1:32' */
  V_q_ref_unsat = 1.44F * mcb_pmsm_foc_sensorless_dyno__B.Sum_g +
    mcb_pmsm_foc_sensorless_d_DWork.integrator_state;

  /* '<S361>:1:35' */
  if (V_q_ref_unsat <= 1.0F) {
    y = V_q_ref_unsat;
  } else {
    y = 1.0F;
  }

  if (y >= -1.0F) {
    mcb_pmsm_foc_sensorless_dyno__B.V_q_ref = y;
  } else {
    mcb_pmsm_foc_sensorless_dyno__B.V_q_ref = -1.0F;
  }

  if (mcb_pmsm_foc_sensorless_dyno__B.V_q_ref != V_q_ref_unsat) {
    /* '<S361>:1:38' */
    /* '<S361>:1:39' */
    mcb_pmsm_foc_sensorless_d_DWork.integrator_state -= 0.2025F *
      mcb_pmsm_foc_sensorless_dyno__B.Sum_g;
  }

  /* End of MATLAB Function: '<S290>/MATLAB Function' */

  /* Sum: '<S289>/Sum' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum_k = mcb_pmsm_foc_sensorless_dyno__B.RT6[0]
    - mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.algDD_o1;

  /* Logic: '<S289>/Logical Operator' */
  mcb_pmsm_foc_sensorless_dyno__B.LogicalOperator_a =
    !mcb_pmsm_foc_sensorless_dyno__B.Enable;

  /* MATLAB Function: '<S289>/MATLAB Function' incorporates:
   *  Constant: '<S289>/Ki'
   *  Constant: '<S289>/Ki1'
   *  Constant: '<S289>/Kp'
   */
  /* MATLAB Function 'FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/MATLAB Function': '<S306>:1' */
  if (mcb_pmsm_foc_sensorless_dyno__B.LogicalOperator_a) {
    /* '<S306>:1:21' */
    /* '<S306>:1:22' */
    mcb_pmsm_foc_sensorless_d_DWork.integrator_state_l = 0.0F;
  }

  /* '<S306>:1:26' */
  /* '<S306>:1:29' */
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state_l += 0.2025F *
    mcb_pmsm_foc_sensorless_dyno__B.Sum_k;

  /* '<S306>:1:32' */
  V_q_ref_unsat = 1.44F * mcb_pmsm_foc_sensorless_dyno__B.Sum_k +
    mcb_pmsm_foc_sensorless_d_DWork.integrator_state_l;

  /* '<S306>:1:35' */
  if (V_q_ref_unsat <= 1.0F) {
    y = V_q_ref_unsat;
  } else {
    y = 1.0F;
  }

  if (y >= -1.0F) {
    mcb_pmsm_foc_sensorless_dyno__B.V_d_ref = y;
  } else {
    mcb_pmsm_foc_sensorless_dyno__B.V_d_ref = -1.0F;
  }

  if (mcb_pmsm_foc_sensorless_dyno__B.V_d_ref != V_q_ref_unsat) {
    /* '<S306>:1:38' */
    /* '<S306>:1:39' */
    mcb_pmsm_foc_sensorless_d_DWork.integrator_state_l -= 0.2025F *
      mcb_pmsm_foc_sensorless_dyno__B.Sum_k;
  }

  /* End of MATLAB Function: '<S289>/MATLAB Function' */

  /* Switch: '<S293>/Switch' incorporates:
   *  Constant: '<S293>/Constant3'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Switch_l = 0.95F;

  /* Product: '<S293>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_de = 0.9025F;

  /* Product: '<S294>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_ii =
    mcb_pmsm_foc_sensorless_dyno__B.V_d_ref *
    mcb_pmsm_foc_sensorless_dyno__B.V_d_ref;

  /* Product: '<S294>/Product1' */
  mcb_pmsm_foc_sensorless_dyno__B.Product1_c =
    mcb_pmsm_foc_sensorless_dyno__B.V_q_ref *
    mcb_pmsm_foc_sensorless_dyno__B.V_q_ref;

  /* Sum: '<S294>/Sum1' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum1_g =
    mcb_pmsm_foc_sensorless_dyno__B.Product_ii +
    mcb_pmsm_foc_sensorless_dyno__B.Product1_c;

  /* Outputs for IfAction SubSystem: '<S288>/D-Q Equivalence' incorporates:
   *  ActionPort: '<S291>/Action Port'
   */
  /* If: '<S288>/If' */
  mcb_pmsm_foc__DQEquivalence(mcb_pmsm_foc_sensorless_dyno__B.V_d_ref,
    mcb_pmsm_foc_sensorless_dyno__B.V_q_ref,
    mcb_pmsm_foc_sensorless_dyno__B.Sum1_g, 0.95F, 0.9025F,
    mcb_pmsm_foc_sensorless_dyno__B.Merge_e,
    &mcb_pmsm_foc_sensorless_dyno__B.DQEquivalence_j);

  /* End of Outputs for SubSystem: '<S288>/D-Q Equivalence' */

  /* SignalConversion generated from: '<S3>/mtr2_debug' */
  mcb_pmsm_foc_sensorless_dyno__B.mtr2_VI_debug_k[0] =
    mcb_pmsm_foc_sensorless_dyno__B.RT6[0];
  mcb_pmsm_foc_sensorless_dyno__B.mtr2_VI_debug_k[1] =
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.algDD_o1;
  mcb_pmsm_foc_sensorless_dyno__B.mtr2_VI_debug_k[2] =
    mcb_pmsm_foc_sensorless_dyno__B.Merge_e[0];
  mcb_pmsm_foc_sensorless_dyno__B.mtr2_VI_debug_k[3] =
    mcb_pmsm_foc_sensorless_dyno__B.RT6[1];
  mcb_pmsm_foc_sensorless_dyno__B.mtr2_VI_debug_k[4] =
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.algDD_o2;
  mcb_pmsm_foc_sensorless_dyno__B.mtr2_VI_debug_k[5] =
    mcb_pmsm_foc_sensorless_dyno__B.Merge_e[1];

  /* Outputs for Atomic SubSystem: '<S282>/Two inputs CRL' */
  mcb_pmsm_foc_s_TwoinputsCRL(mcb_pmsm_foc_sensorless_dyno__B.Merge_e[0],
    mcb_pmsm_foc_sensorless_dyno__B.Merge_e[1],
    mcb_pmsm_foc_sensorless_dyno__B.Sum4, mcb_pmsm_foc_sensorless_dyno__B.Sum6,
    &mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e);

  /* End of Outputs for SubSystem: '<S282>/Two inputs CRL' */

  /* DataStoreRead: '<S278>/Enable' */
  mcb_pmsm_foc_sensorless_dyno__B.Enable_b =
    mcb_pmsm_foc_sensorless_d_DWork.EnMtr2TrqCtrl;

  /* DataTypeConversion: '<S278>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_o =
    mcb_pmsm_foc_sensorless_dyno__B.Enable_b;

  /* Switch: '<S458>/Switch' */
  mcb_pmsm_foc_sensorless_dyno__B.Switch_n =
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_o;

  /* S-Function (c280xgpio_do): '<S458>/Bottom DRV8305 EN' */
  {
    if (mcb_pmsm_foc_sensorless_dyno__B.Switch_n) {
      GpioDataRegs.GPASET.bit.GPIO26 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO26 = 1U;
    }
  }

  /* Switch: '<S458>/Switch1' */
  if (mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_o >= 0.5F) {
    /* Gain: '<S380>/sqrt3_by_two' */
    mcb_pmsm_foc_sensorless_dyno__B.sqrt3_by_two = 0.866025388F *
      mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.algDD_o2;

    /* Gain: '<S380>/one_by_two' */
    mcb_pmsm_foc_sensorless_dyno__B.one_by_two = 0.5F *
      mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.algDD_o1;

    /* Sum: '<S380>/add_c' */
    mcb_pmsm_foc_sensorless_dyno__B.add_c = (0.0F -
      mcb_pmsm_foc_sensorless_dyno__B.one_by_two) -
      mcb_pmsm_foc_sensorless_dyno__B.sqrt3_by_two;

    /* Sum: '<S380>/add_b' */
    mcb_pmsm_foc_sensorless_dyno__B.add_b =
      mcb_pmsm_foc_sensorless_dyno__B.sqrt3_by_two -
      mcb_pmsm_foc_sensorless_dyno__B.one_by_two;

    /* MinMax: '<S377>/Min' */
    y = mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.algDD_o1;
    V_q_ref_unsat = mcb_pmsm_foc_sensorless_dyno__B.add_b;
    if ((y <= V_q_ref_unsat) || rtIsNaNF(V_q_ref_unsat)) {
      V_q_ref_unsat = y;
    }

    y = mcb_pmsm_foc_sensorless_dyno__B.add_c;
    if ((!(V_q_ref_unsat <= y)) && (!rtIsNaNF(y))) {
      V_q_ref_unsat = y;
    }

    /* MinMax: '<S377>/Min' */
    mcb_pmsm_foc_sensorless_dyno__B.Min = V_q_ref_unsat;

    /* MinMax: '<S377>/Max' */
    y = mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.algDD_o1;
    V_q_ref_unsat = mcb_pmsm_foc_sensorless_dyno__B.add_b;
    if ((y >= V_q_ref_unsat) || rtIsNaNF(V_q_ref_unsat)) {
      V_q_ref_unsat = y;
    }

    y = mcb_pmsm_foc_sensorless_dyno__B.add_c;
    if ((!(V_q_ref_unsat >= y)) && (!rtIsNaNF(y))) {
      V_q_ref_unsat = y;
    }

    /* MinMax: '<S377>/Max' */
    mcb_pmsm_foc_sensorless_dyno__B.Max = V_q_ref_unsat;

    /* Sum: '<S377>/Add' */
    mcb_pmsm_foc_sensorless_dyno__B.Add_eb = mcb_pmsm_foc_sensorless_dyno__B.Max
      + mcb_pmsm_foc_sensorless_dyno__B.Min;

    /* Gain: '<S377>/one_by_two' */
    mcb_pmsm_foc_sensorless_dyno__B.one_by_two_j = -0.5F *
      mcb_pmsm_foc_sensorless_dyno__B.Add_eb;

    /* Sum: '<S376>/Add3' */
    mcb_pmsm_foc_sensorless_dyno__B.Add3 =
      mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.algDD_o1 +
      mcb_pmsm_foc_sensorless_dyno__B.one_by_two_j;

    /* Sum: '<S376>/Add2' */
    mcb_pmsm_foc_sensorless_dyno__B.Add2 =
      mcb_pmsm_foc_sensorless_dyno__B.one_by_two_j +
      mcb_pmsm_foc_sensorless_dyno__B.add_c;

    /* Sum: '<S376>/Add1' */
    mcb_pmsm_foc_sensorless_dyno__B.Add1_jx =
      mcb_pmsm_foc_sensorless_dyno__B.add_b +
      mcb_pmsm_foc_sensorless_dyno__B.one_by_two_j;

    /* Gain: '<S376>/Gain' */
    mcb_pmsm_foc_sensorless_dyno__B.Gain_jn[0] = 1.15470052F *
      mcb_pmsm_foc_sensorless_dyno__B.Add3;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_jn[1] = 1.15470052F *
      mcb_pmsm_foc_sensorless_dyno__B.Add1_jx;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_jn[2] = 1.15470052F *
      mcb_pmsm_foc_sensorless_dyno__B.Add2;

    /* Gain: '<S278>/Gain' */
    V_q_ref_unsat = 0.5F * mcb_pmsm_foc_sensorless_dyno__B.Gain_jn[0];
    mcb_pmsm_foc_sensorless_dyno__B.Gain_i[0] = V_q_ref_unsat;

    /* Sum: '<S278>/Sum' incorporates:
     *  Constant: '<S278>/Constant'
     */
    V_q_ref_unsat += 0.5F;
    mcb_pmsm_foc_sensorless_dyno__B.PWM_Duty_Cycles[0] = V_q_ref_unsat;

    /* Gain: '<S458>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD = (uint16_T)(5000.0F * V_q_ref_unsat);
    mcb_pmsm_foc_sensorless_dyno__B.Scale_to_PWM_Counter_PRD[0] =
      Scale_to_PWM_Counter_PRD;

    /* Switch: '<S458>/Switch1' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_i[0] = Scale_to_PWM_Counter_PRD;

    /* Gain: '<S278>/Gain' */
    V_q_ref_unsat = 0.5F * mcb_pmsm_foc_sensorless_dyno__B.Gain_jn[1];
    mcb_pmsm_foc_sensorless_dyno__B.Gain_i[1] = V_q_ref_unsat;

    /* Sum: '<S278>/Sum' incorporates:
     *  Constant: '<S278>/Constant'
     */
    V_q_ref_unsat += 0.5F;
    mcb_pmsm_foc_sensorless_dyno__B.PWM_Duty_Cycles[1] = V_q_ref_unsat;

    /* Gain: '<S458>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD = (uint16_T)(5000.0F * V_q_ref_unsat);
    mcb_pmsm_foc_sensorless_dyno__B.Scale_to_PWM_Counter_PRD[1] =
      Scale_to_PWM_Counter_PRD;

    /* Switch: '<S458>/Switch1' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_i[1] = Scale_to_PWM_Counter_PRD;

    /* Gain: '<S278>/Gain' */
    V_q_ref_unsat = 0.5F * mcb_pmsm_foc_sensorless_dyno__B.Gain_jn[2];
    mcb_pmsm_foc_sensorless_dyno__B.Gain_i[2] = V_q_ref_unsat;

    /* Sum: '<S278>/Sum' incorporates:
     *  Constant: '<S278>/Constant'
     */
    V_q_ref_unsat += 0.5F;
    mcb_pmsm_foc_sensorless_dyno__B.PWM_Duty_Cycles[2] = V_q_ref_unsat;

    /* Gain: '<S458>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD = (uint16_T)(5000.0F * V_q_ref_unsat);
    mcb_pmsm_foc_sensorless_dyno__B.Scale_to_PWM_Counter_PRD[2] =
      Scale_to_PWM_Counter_PRD;

    /* Switch: '<S458>/Switch1' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_i[2] = Scale_to_PWM_Counter_PRD;
  } else {
    /* Switch: '<S458>/Switch1' incorporates:
     *  Constant: '<S458>/stop'
     */
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_i[0] = 0U;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_i[1] = 0U;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_i[2] = 0U;
  }

  /* End of Switch: '<S458>/Switch1' */

  /* S-Function (c2802xpwm): '<S458>/ePWM4' */
  uint16_T tbprdValue4Outputs = EPwm4Regs.TBPRD;

  /*-- Update CMPA value for ePWM4 --*/
  {
    EPwm4Regs.CMPA.bit.CMPA = (uint16_T)
      (mcb_pmsm_foc_sensorless_dyno__B.Switch1_i[0]);
  }

  /* S-Function (c2802xpwm): '<S458>/ePWM5' */
  uint16_T tbprdValue5Outputs = EPwm5Regs.TBPRD;

  /*-- Update CMPA value for ePWM5 --*/
  {
    EPwm5Regs.CMPA.bit.CMPA = (uint16_T)
      (mcb_pmsm_foc_sensorless_dyno__B.Switch1_i[1]);
  }

  /* S-Function (c2802xpwm): '<S458>/ePWM6' */
  uint16_T tbprdValue6Outputs = EPwm6Regs.TBPRD;

  /*-- Update CMPA value for ePWM6 --*/
  {
    EPwm6Regs.CMPA.bit.CMPA = (uint16_T)
      (mcb_pmsm_foc_sensorless_dyno__B.Switch1_i[2]);
  }

  /* SignalConversion generated from: '<S3>/Delay' */
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelayInpor[0] =
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.algDD_o1;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelayInpor[1] =
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.algDD_o2;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelayInpor[2] =
    mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap_g.algDD_o1;
  mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelayInpor[3] =
    mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap_g.algDD_o2;

  /* Update for Delay: '<S3>/Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE[0] =
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelayInpor[0];
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE[1] =
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelayInpor[1];
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE[2] =
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelayInpor[2];
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE[3] =
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelayInpor[3];
}

/*
 * Output and update for action system:
 *    '<S469>/If Action Subsystem'
 *    '<S477>/If Action Subsystem1'
 */
void mcb_pms_IfActionSubsystem_c(uint16_T rtu_In1, uint16_T rtu_In2,
  rtB_IfActionSubsystem_mcb_pms_h *localB, rtDW_IfActionSubsystem_mcb_pm_n
  *localDW)
{
  /* Memory: '<S474>/Memory' */
  localB->Memory = localDW->Memory_PreviousInput;

  /* Sum: '<S474>/Sum' */
  localB->Sum = rtu_In1 + localB->Memory;

  /* Memory: '<S474>/Memory1' */
  localB->Memory1 = localDW->Memory1_PreviousInput;

  /* Sum: '<S474>/Sum1' */
  localB->Sum1 = rtu_In2 + localB->Memory1;

  /* Update for Memory: '<S474>/Memory' */
  localDW->Memory_PreviousInput = localB->Sum;

  /* Update for Memory: '<S474>/Memory1' */
  localDW->Memory1_PreviousInput = localB->Sum1;
}

/* System initialize for atomic system: */
void mcb__SPIMasterTransfer_Init(rtDW_SPIMasterTransfer_mcb_pmsm *localDW)
{
  uint32_T SPIPinsLoc;

  /* Start for MATLABSystem: '<S466>/SPI Master Transfer' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1L;
  SPIPinsLoc = MW_UNDEFINED_VALUE;
  localDW->obj.MW_SPI_HANDLE = MW_SPI_Open(0UL, SPIPinsLoc, SPIPinsLoc,
    SPIPinsLoc, MW_UNDEFINED_VALUE, true, 0U);
  MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
                   MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void mcb_pmsm__SPIMasterTransfer(uint16_T rtu_0, rtB_SPIMasterTransfer_mcb_pmsm_
  *localB, rtDW_SPIMasterTransfer_mcb_pmsm *localDW)
{
  uint16_T rdDataRaw;
  uint16_T status;

  /* MATLABSystem: '<S466>/SPI Master Transfer' */
  MW_SPI_SetSlaveSelect(localDW->obj.MW_SPI_HANDLE, 0U, true);
  status = MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
    MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  if (status == 0U) {
    MW_SPI_MasterWriteRead_8bits(localDW->obj.MW_SPI_HANDLE, &rtu_0, &rdDataRaw,
      1UL);
  }

  /* MATLABSystem: '<S466>/SPI Master Transfer' */
  localB->SPIMasterTransfer = rdDataRaw;
}

/* Termination for atomic system: */
void mcb__SPIMasterTransfer_Term(rtDW_SPIMasterTransfer_mcb_pmsm *localDW)
{
  uint32_T SPIPinsLoc;

  /* Terminate for MATLABSystem: '<S466>/SPI Master Transfer' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, MW_UNDEFINED_VALUE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S466>/SPI Master Transfer' */
}

/* System initialize for atomic system: */
void mcb_SPIMasterTransfer2_Init(rtDW_SPIMasterTransfer2_mcb_pms *localDW)
{
  uint32_T SPIPinsLoc;

  /* Start for MATLABSystem: '<S466>/SPI Master Transfer2' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1L;
  SPIPinsLoc = MW_UNDEFINED_VALUE;
  localDW->obj.MW_SPI_HANDLE = MW_SPI_Open(1UL, SPIPinsLoc, SPIPinsLoc,
    SPIPinsLoc, MW_UNDEFINED_VALUE, true, 0U);
  MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
                   MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void mcb_pmsm_SPIMasterTransfer2(uint16_T rtu_0, rtB_SPIMasterTransfer2_mcb_pmsm
  *localB, rtDW_SPIMasterTransfer2_mcb_pms *localDW)
{
  uint16_T rdDataRaw;
  uint16_T status;

  /* MATLABSystem: '<S466>/SPI Master Transfer2' */
  MW_SPI_SetSlaveSelect(localDW->obj.MW_SPI_HANDLE, 0U, true);
  status = MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
    MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  if (status == 0U) {
    MW_SPI_MasterWriteRead_8bits(localDW->obj.MW_SPI_HANDLE, &rtu_0, &rdDataRaw,
      1UL);
  }

  /* MATLABSystem: '<S466>/SPI Master Transfer2' */
  localB->SPIMasterTransfer2 = rdDataRaw;
}

/* Termination for atomic system: */
void mcb_SPIMasterTransfer2_Term(rtDW_SPIMasterTransfer2_mcb_pms *localDW)
{
  uint32_T SPIPinsLoc;

  /* Terminate for MATLABSystem: '<S466>/SPI Master Transfer2' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, MW_UNDEFINED_VALUE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S466>/SPI Master Transfer2' */
}

/* System initialize for atomic system: '<Root>/Speed Control' */
void mcb_pmsm__SpeedControl_Init(rtB_SpeedControl_mcb_pmsm_foc_s *localB,
  rtDW_SpeedControl_mcb_pmsm_foc_ *localDW)
{
  /* SystemInitialize for IfAction SubSystem: '<S8>/Rate Limiter for SMO' */
  /* InitializeConditions for RateLimiter: '<S557>/Rate Limiter' */
  localDW->PrevY = 0.1F;

  /* InitializeConditions for RateLimiter: '<S557>/Rate Limiter1' */
  localDW->PrevY_a = -0.1F;

  /* End of SystemInitialize for SubSystem: '<S8>/Rate Limiter for SMO' */

  /* SystemInitialize for Merge: '<S8>/Merge' */
  localB->Merge = 0.0F;

  /* SystemInitialize for MATLAB Function: '<S555>/MATLAB Function' */
  localDW->integrator_state = 0.0F;
}

/* Output and update for atomic system: '<Root>/Speed Control' */
void mcb_pmsm_foc_s_SpeedControl(real_T rtu_EstimatorSelect, real32_T
  rtu_Speed_Ref_PU, real32_T rtu_Speed_Meas_PU, const boolean_T
  *rtd_EnClosedLoop, const boolean_T *rtd_Enable, const real32_T *rtd_SpeedRef,
  rtB_SpeedControl_mcb_pmsm_foc_s *localB, rtDW_SpeedControl_mcb_pmsm_foc_
  *localDW)
{
  real32_T Trq_ref_unsat;
  real32_T y;

  /* Constant: '<S8>/Id_Ref' */
  localB->Id_Ref = 0.0F;

  /* SwitchCase: '<S8>/Switch Case' */
  switch ((int32_T)rtu_EstimatorSelect) {
   case 0L:
    /* Outputs for IfAction SubSystem: '<S8>/Rate Limiter for SMO' incorporates:
     *  ActionPort: '<S557>/Action Port'
     */
    /* RateLimiter: '<S557>/Rate Limiter' */
    Trq_ref_unsat = rtu_Speed_Ref_PU - localDW->PrevY;
    if (Trq_ref_unsat > 0.0048697344F) {
      /* RateLimiter: '<S557>/Rate Limiter' */
      localB->RateLimiter = localDW->PrevY + 0.0048697344F;
    } else if (Trq_ref_unsat < -0.0048697344F) {
      /* RateLimiter: '<S557>/Rate Limiter' */
      localB->RateLimiter = localDW->PrevY - 0.0048697344F;
    } else {
      /* RateLimiter: '<S557>/Rate Limiter' */
      localB->RateLimiter = rtu_Speed_Ref_PU;
    }

    localDW->PrevY = localB->RateLimiter;

    /* End of RateLimiter: '<S557>/Rate Limiter' */

    /* RateLimiter: '<S557>/Rate Limiter1' */
    Trq_ref_unsat = rtu_Speed_Ref_PU - localDW->PrevY_a;
    if (Trq_ref_unsat > 0.0048697344F) {
      /* RateLimiter: '<S557>/Rate Limiter1' */
      localB->RateLimiter1 = localDW->PrevY_a + 0.0048697344F;
    } else if (Trq_ref_unsat < -0.0048697344F) {
      /* RateLimiter: '<S557>/Rate Limiter1' */
      localB->RateLimiter1 = localDW->PrevY_a - 0.0048697344F;
    } else {
      /* RateLimiter: '<S557>/Rate Limiter1' */
      localB->RateLimiter1 = rtu_Speed_Ref_PU;
    }

    localDW->PrevY_a = localB->RateLimiter1;

    /* End of RateLimiter: '<S557>/Rate Limiter1' */

    /* Switch: '<S557>/Switch' */
    if (rtu_Speed_Ref_PU >= 0.0F) {
      /* Merge: '<S8>/Merge' */
      localB->Merge = localB->RateLimiter;
    } else {
      /* Merge: '<S8>/Merge' */
      localB->Merge = localB->RateLimiter1;
    }

    /* End of Switch: '<S557>/Switch' */
    /* End of Outputs for SubSystem: '<S8>/Rate Limiter for SMO' */
    break;

   case 1L:
    /* Outputs for IfAction SubSystem: '<S8>/Rate Limiter for FO' incorporates:
     *  ActionPort: '<S556>/Action Port'
     */
    /* Merge: '<S8>/Merge' incorporates:
     *  SignalConversion generated from: '<S556>/Speed_Ref'
     */
    localB->Merge = rtu_Speed_Ref_PU;

    /* End of Outputs for SubSystem: '<S8>/Rate Limiter for FO' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S8>/Switch Case' */

  /* DataStoreRead: '<S555>/Data Store Read1' */
  localB->DataStoreRead1 = *rtd_Enable;

  /* DataStoreRead: '<S555>/Data Store Read2' */
  localB->DataStoreRead2 = *rtd_EnClosedLoop;

  /* Logic: '<S555>/AND' */
  localB->AND = (localB->DataStoreRead1 && localB->DataStoreRead2);

  /* Logic: '<S555>/Logical Operator' */
  localB->LogicalOperator = !localB->AND;

  /* DataStoreRead: '<S558>/Data Store Read1' */
  localB->DataStoreRead1_e = *rtd_EnClosedLoop;

  /* Switch: '<S558>/Switch' */
  if (localB->DataStoreRead1_e) {
    /* Switch: '<S558>/Switch' */
    localB->Speed_Ref = localB->Merge;
  } else {
    /* DataStoreRead: '<S558>/Data Store Read' */
    localB->DataStoreRead = *rtd_SpeedRef;

    /* Switch: '<S558>/Switch1' */
    if (localB->DataStoreRead > 0.0F) {
      /* Switch: '<S558>/Switch1' incorporates:
       *  Constant: '<S558>/Constant'
       */
      localB->Switch1_n = 0.1F;
    } else {
      /* Switch: '<S558>/Switch1' incorporates:
       *  Constant: '<S558>/Constant1'
       */
      localB->Switch1_n = -0.1F;
    }

    /* End of Switch: '<S558>/Switch1' */

    /* Switch: '<S558>/Switch' */
    localB->Speed_Ref = localB->Switch1_n;
  }

  /* End of Switch: '<S558>/Switch' */

  /* Switch: '<S561>/Switch1' incorporates:
   *  Constant: '<S561>/FilterConstant'
   *  Constant: '<S561>/OneMinusFilterConstant'
   */
  localB->Switch1[0] = 0.2F;
  localB->Switch1[1] = 0.8F;

  /* Product: '<S618>/Product' */
  localB->Product = localB->Speed_Ref * 0.2F;

  /* UnitDelay: '<S618>/Unit Delay' */
  localB->UnitDelay = localDW->UnitDelay_DSTATE;

  /* Product: '<S618>/Product1' */
  localB->Product1 = 0.8F * localB->UnitDelay;

  /* Sum: '<S618>/Add1' */
  localB->Add1 = localB->Product + localB->Product1;

  /* Sum: '<S555>/Sum' */
  localB->Sum = localB->Add1 - rtu_Speed_Meas_PU;

  /* MATLAB Function: '<S555>/MATLAB Function' incorporates:
   *  Constant: '<S555>/Ki1'
   *  Constant: '<S555>/Ki2'
   *  Constant: '<S555>/Kp1'
   */
  /* MATLAB Function 'Speed Control/PI_Controller_Speed/MATLAB Function': '<S560>:1' */
  if (localB->LogicalOperator) {
    /* '<S560>:1:21' */
    /* '<S560>:1:22' */
    localDW->integrator_state = 0.0F;
  }

  /* '<S560>:1:26' */
  /* '<S560>:1:29' */
  localDW->integrator_state += 0.0532323F * localB->Sum;

  /* '<S560>:1:32' */
  Trq_ref_unsat = 1.2718488F * localB->Sum + localDW->integrator_state;

  /* '<S560>:1:35' */
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
    /* '<S560>:1:38' */
    /* '<S560>:1:39' */
    localDW->integrator_state -= 0.0532323F * localB->Sum;
  }

  /* End of MATLAB Function: '<S555>/MATLAB Function' */

  /* Update for UnitDelay: '<S618>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->Add1;
}

/* Model step function for TID0 */
void mcb_pmsm_foc_sensorless_dyno_f28379d_step0(void) /* Sample time: [2.5E-5s, 0.0s] */
{
  real_T cosOut;
  real_T currentTime;

  {                                    /* Sample time: [2.5E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* DataStoreRead: '<S6>/Data Store Read1' */
  mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_n =
    mcb_pmsm_foc_sensorless_d_DWork.EnMtr2TrqCtrl;

  /* DataStoreRead: '<S6>/Data Store Read2' */
  mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead2_k =
    mcb_pmsm_foc_sensorless_d_DWork.EnMtr2TrqCtrl;

  /* Step: '<S6>/T_load' */
  currentTime = (((mcb_pmsm_foc_sensorless_dyno_M->Timing.clockTick0+
                   mcb_pmsm_foc_sensorless_dyno_M->Timing.clockTickH0*
                   4294967296.0)) * 2.5E-5);
  if (currentTime < 3.0) {
    /* Step: '<S6>/T_load' */
    mcb_pmsm_foc_sensorless_dyno__B.T_load = 0.013622234348081637;
  } else {
    /* Step: '<S6>/T_load' */
    mcb_pmsm_foc_sensorless_dyno__B.T_load = 0.10897787478465309;
  }

  /* End of Step: '<S6>/T_load' */

  /* DiscreteIntegrator: '<S492>/Discrete-Time Integrator' */
  mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator =
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<S6>/Gain' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain =
    -mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator;

  /* DiscreteIntegrator: '<S539>/Discrete-Time Integrator3' */
  if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_IC_LOAD != 0U) {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTATE =
      mcb_pmsm_foc_sensorless__ConstB.IndexVector_cx;
    if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTATE > 1.0E+7)
    {
      mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTATE = 1.0E+7;
    } else if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTATE <
               -1.0E+7) {
      mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTATE = -1.0E+7;
    }
  }

  /* DiscreteIntegrator: '<S539>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3 =
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* DiscreteIntegrator: '<S540>/Discrete-Time Integrator3' */
  if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_IC_LO_a != 0U) {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_i =
      mcb_pmsm_foc_sensorless__ConstB.IndexVector_bp;
    if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_i > 1.0E+7)
    {
      mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_i = 1.0E+7;
    } else if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_i <
               -1.0E+7) {
      mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_i = -1.0E+7;
    }
  }

  /* DiscreteIntegrator: '<S540>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_a =
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_i;

  /* Switch: '<S6>/Switch2' */
  if (mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead1_n) {
    /* Gain: '<S535>/Gain1' */
    mcb_pmsm_foc_sensorless_dyno__B.Gain1_d = 0.0063954151868927875 *
      mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_a;

    /* Product: '<S535>/Product' */
    mcb_pmsm_foc_sensorless_dyno__B.Product_g =
      mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3 *
      mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_a;

    /* Product: '<S538>/Product' */
    mcb_pmsm_foc_sensorless_dyno__B.Product_m =
      mcb_pmsm_foc_sensorless_dyno__B.Product_g *
      mcb_pmsm_foc_sensorless__ConstB.Add_l;

    /* Sum: '<S535>/Add' */
    mcb_pmsm_foc_sensorless_dyno__B.Add_g =
      mcb_pmsm_foc_sensorless_dyno__B.Product_m +
      mcb_pmsm_foc_sensorless_dyno__B.Gain1_d;

    /* Gain: '<S535>/Gain2' */
    mcb_pmsm_foc_sensorless_dyno__B.Gain2_c = 6.0 *
      mcb_pmsm_foc_sensorless_dyno__B.Add_g;

    /* Switch: '<S6>/Switch2' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch2 =
      mcb_pmsm_foc_sensorless_dyno__B.Gain2_c;
  } else {
    /* DataTypeConversion: '<S6>/Data Type Conversion' */
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion = (real32_T)
      mcb_pmsm_foc_sensorless_dyno__B.T_load;

    /* Switch: '<S6>/Switch2' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch2 =
      mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Switch: '<S484>/Switch1' incorporates:
   *  Constant: '<S484>/FilterConstant'
   *  Constant: '<S484>/OneMinusFilterConstant'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Switch1[0] = 0.0001;
  mcb_pmsm_foc_sensorless_dyno__B.Switch1[1] = 0.9999;

  /* Product: '<S489>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product =
    mcb_pmsm_foc_sensorless_dyno__B.Switch2 *
    mcb_pmsm_foc_sensorless_dyno__B.Switch1[0];

  /* UnitDelay: '<S489>/Unit Delay' */
  mcb_pmsm_foc_sensorless_dyno__B.UnitDelay =
    mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE;

  /* Product: '<S489>/Product1' */
  mcb_pmsm_foc_sensorless_dyno__B.Product1 =
    mcb_pmsm_foc_sensorless_dyno__B.Switch1[1] *
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay;

  /* Sum: '<S489>/Add1' */
  mcb_pmsm_foc_sensorless_dyno__B.Add1 = mcb_pmsm_foc_sensorless_dyno__B.Product
    + mcb_pmsm_foc_sensorless_dyno__B.Product1;

  /* DiscreteIntegrator: '<S510>/Discrete-Time Integrator3' */
  if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_IC_LO_i != 0U) {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_e =
      mcb_pmsm_foc_sensorless__ConstB.IndexVector_l;
    if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_e > 1.0E+7)
    {
      mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_e = 1.0E+7;
    } else if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_e <
               -1.0E+7) {
      mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_e = -1.0E+7;
    }
  }

  /* DiscreteIntegrator: '<S510>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_g =
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_e;

  /* UnitDelay: '<S495>/Unit Delay' */
  mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_b =
    mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_b;

  /* RelationalOperator: '<S497>/Compare' incorporates:
   *  Constant: '<S497>/Constant'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Compare =
    (mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_b >= -3.1415926535897931);

  /* Switch: '<S495>/Switch1' */
  if (mcb_pmsm_foc_sensorless_dyno__B.Compare) {
    /* RelationalOperator: '<S496>/Compare' incorporates:
     *  Constant: '<S496>/Constant'
     */
    mcb_pmsm_foc_sensorless_dyno__B.Compare_j =
      (mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_b <= 3.1415926535897931);

    /* Switch: '<S495>/Switch' */
    if (mcb_pmsm_foc_sensorless_dyno__B.Compare_j) {
      /* Switch: '<S495>/Switch' */
      mcb_pmsm_foc_sensorless_dyno__B.Switch_e =
        mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_b;
    } else {
      /* Sum: '<S495>/Subtract' incorporates:
       *  Constant: '<S495>/Constant3'
       */
      mcb_pmsm_foc_sensorless_dyno__B.Subtract_g =
        mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_b - 6.2831854820251465;

      /* Switch: '<S495>/Switch' */
      mcb_pmsm_foc_sensorless_dyno__B.Switch_e =
        mcb_pmsm_foc_sensorless_dyno__B.Subtract_g;
    }

    /* End of Switch: '<S495>/Switch' */

    /* Switch: '<S495>/Switch1' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_g =
      mcb_pmsm_foc_sensorless_dyno__B.Switch_e;
  } else {
    /* Sum: '<S495>/Add1' incorporates:
     *  Constant: '<S495>/Constant1'
     */
    mcb_pmsm_foc_sensorless_dyno__B.Add1_j =
      mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_b + 6.2831854820251465;

    /* Switch: '<S495>/Switch1' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_g =
      mcb_pmsm_foc_sensorless_dyno__B.Add1_j;
  }

  /* End of Switch: '<S495>/Switch1' */

  /* Gain: '<S492>/Gain4' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain4 = 4.0 *
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_g;

  /* Trigonometry: '<S494>/sine_cosine' */
  cosOut = mcb_pmsm_foc_sensorless_dyno__B.Gain4;
  currentTime = sin(cosOut);
  cosOut = cos(cosOut);

  /* Trigonometry: '<S494>/sine_cosine' */
  mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o1 = currentTime;

  /* Trigonometry: '<S494>/sine_cosine' */
  mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o2 = cosOut;

  /* Product: '<S505>/Product2' */
  mcb_pmsm_foc_sensorless_dyno__B.Product2 =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_g *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o2;

  /* DiscreteIntegrator: '<S511>/Discrete-Time Integrator3' */
  if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_IC_LO_e != 0U) {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_n =
      mcb_pmsm_foc_sensorless__ConstB.IndexVector_bl;
    if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_n > 1.0E+7)
    {
      mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_n = 1.0E+7;
    } else if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_n <
               -1.0E+7) {
      mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_n = -1.0E+7;
    }
  }

  /* DiscreteIntegrator: '<S511>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_b =
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_n;

  /* Product: '<S505>/Product3' */
  mcb_pmsm_foc_sensorless_dyno__B.Product3 =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_b *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o1;

  /* Sum: '<S505>/Add1' */
  mcb_pmsm_foc_sensorless_dyno__B.Add1_c =
    mcb_pmsm_foc_sensorless_dyno__B.Product2 -
    mcb_pmsm_foc_sensorless_dyno__B.Product3;

  /* SignalConversion generated from: '<S491>/Vector Concatenate' incorporates:
   *  Concatenate: '<S491>/Vector Concatenate'
   */
  mcb_pmsm_foc_sensorless_dyno__B.VectorConcatenate[0] =
    mcb_pmsm_foc_sensorless_dyno__B.Add1_c;

  /* Product: '<S506>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_a =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_g *
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_b;

  /* Product: '<S509>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_i =
    mcb_pmsm_foc_sensorless_dyno__B.Product_a *
    mcb_pmsm_foc_sensorless__ConstB.Add;

  /* Gain: '<S506>/Gain1' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain1 = 0.0063954151868927875 *
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_b;

  /* Sum: '<S506>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add =
    mcb_pmsm_foc_sensorless_dyno__B.Product_i +
    mcb_pmsm_foc_sensorless_dyno__B.Gain1;

  /* Gain: '<S506>/Gain2' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain2 = 6.0 *
    mcb_pmsm_foc_sensorless_dyno__B.Add;

  /* Product: '<S492>/Divide2' */
  mcb_pmsm_foc_sensorless_dyno__B.Divide2 =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator *
    mcb_pmsm_foc_sensorless__ConstB.IndexVector2;

  /* Signum: '<S492>/Sign' */
  currentTime = mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator;
  if (rtIsNaN(currentTime)) {
    /* Signum: '<S492>/Sign' */
    mcb_pmsm_foc_sensorless_dyno__B.Sign = (rtNaN);
  } else if (currentTime < 0.0) {
    /* Signum: '<S492>/Sign' */
    mcb_pmsm_foc_sensorless_dyno__B.Sign = -1.0;
  } else {
    /* Signum: '<S492>/Sign' */
    mcb_pmsm_foc_sensorless_dyno__B.Sign = (currentTime > 0.0);
  }

  /* End of Signum: '<S492>/Sign' */

  /* Product: '<S492>/Divide1' */
  mcb_pmsm_foc_sensorless_dyno__B.Divide1 =
    mcb_pmsm_foc_sensorless__ConstB.IndexVector1 *
    mcb_pmsm_foc_sensorless_dyno__B.Sign;

  /* Sum: '<S492>/Sum1' */
  mcb_pmsm_foc_sensorless_dyno__B.Sum1 = ((mcb_pmsm_foc_sensorless_dyno__B.Gain2
    - mcb_pmsm_foc_sensorless_dyno__B.Add1) -
    mcb_pmsm_foc_sensorless_dyno__B.Divide2) -
    mcb_pmsm_foc_sensorless_dyno__B.Divide1;

  /* Product: '<S492>/Divide' */
  mcb_pmsm_foc_sensorless_dyno__B.Divide = mcb_pmsm_foc_sensorless_dyno__B.Sum1 /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector;

  /* Gain: '<S492>/Gain' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain_o = 4.0 *
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator;

  /* Gain: '<S495>/Gain1' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain1_b = 2.5E-5 *
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator;

  /* Sum: '<S495>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_h =
    mcb_pmsm_foc_sensorless_dyno__B.Gain1_b +
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_g;

  /* Gain: '<S503>/Gain' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain_f = 0.0;

  /* Gain: '<S503>/Gain1' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain1_j = -0.0;

  /* Gain: '<S503>/Gain4' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain4_n = -0.0;

  /* Sum: '<S503>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_b =
    (mcb_pmsm_foc_sensorless_dyno__B.Gain_f +
     mcb_pmsm_foc_sensorless_dyno__B.Gain1_j) +
    mcb_pmsm_foc_sensorless_dyno__B.Gain4_n;

  /* Gain: '<S503>/Gain2' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain2_p = 0.0;

  /* Gain: '<S503>/Gain3' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain3 = -0.0;

  /* Sum: '<S503>/Add1' */
  mcb_pmsm_foc_sensorless_dyno__B.Add1_e =
    mcb_pmsm_foc_sensorless_dyno__B.Gain2_p +
    mcb_pmsm_foc_sensorless_dyno__B.Gain3;

  /* Gain: '<S504>/Gain1' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain1_e = -0.5 *
    mcb_pmsm_foc_sensorless_dyno__B.Add1_c;

  /* Gain: '<S504>/Gain2' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain2_k = -0.5 *
    mcb_pmsm_foc_sensorless_dyno__B.Add1_c;

  /* Product: '<S505>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_h =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_g *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o1;

  /* Product: '<S505>/Product1' */
  mcb_pmsm_foc_sensorless_dyno__B.Product1_k =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_b *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o2;

  /* Sum: '<S505>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_c =
    mcb_pmsm_foc_sensorless_dyno__B.Product_h +
    mcb_pmsm_foc_sensorless_dyno__B.Product1_k;

  /* Gain: '<S504>/Gain3' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain3_a = 0.8660254037844386 *
    mcb_pmsm_foc_sensorless_dyno__B.Add_c;

  /* Gain: '<S504>/Gain4' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain4_l = -0.8660254037844386 *
    mcb_pmsm_foc_sensorless_dyno__B.Add_c;

  /* Sum: '<S504>/Subtract1' incorporates:
   *  Concatenate: '<S491>/Vector Concatenate'
   */
  mcb_pmsm_foc_sensorless_dyno__B.VectorConcatenate[1] =
    mcb_pmsm_foc_sensorless_dyno__B.Gain2_k +
    mcb_pmsm_foc_sensorless_dyno__B.Gain3_a;

  /* Sum: '<S504>/Subtract2' incorporates:
   *  Concatenate: '<S491>/Vector Concatenate'
   */
  mcb_pmsm_foc_sensorless_dyno__B.VectorConcatenate[2] =
    mcb_pmsm_foc_sensorless_dyno__B.Gain1_e +
    mcb_pmsm_foc_sensorless_dyno__B.Gain4_l;

  /* Product: '<S508>/Product2' */
  mcb_pmsm_foc_sensorless_dyno__B.Product2_j =
    mcb_pmsm_foc_sensorless_dyno__B.Add_b *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o2;

  /* Product: '<S508>/Product3' */
  mcb_pmsm_foc_sensorless_dyno__B.Product3_o =
    mcb_pmsm_foc_sensorless_dyno__B.Add1_e *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o1;

  /* Sum: '<S508>/Add1' */
  mcb_pmsm_foc_sensorless_dyno__B.Add1_o =
    mcb_pmsm_foc_sensorless_dyno__B.Product2_j +
    mcb_pmsm_foc_sensorless_dyno__B.Product3_o;

  /* Product: '<S512>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_d =
    mcb_pmsm_foc_sensorless_dyno__B.Add1_o /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_k;

  /* Product: '<S510>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_o =
    mcb_pmsm_foc_sensorless_dyno__B.Gain_o *
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_b;

  /* Product: '<S513>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_iz =
    mcb_pmsm_foc_sensorless_dyno__B.Product_o *
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_ko /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector2_g;

  /* Product: '<S514>/Product' incorporates:
   *  Constant: '<S514>/Constant'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Product_hf =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_g * 0.36 /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_b;

  /* Sum: '<S510>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_m =
    (mcb_pmsm_foc_sensorless_dyno__B.Product_d +
     mcb_pmsm_foc_sensorless_dyno__B.Product_iz) -
    mcb_pmsm_foc_sensorless_dyno__B.Product_hf;

  /* Product: '<S508>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_c =
    mcb_pmsm_foc_sensorless_dyno__B.Add_b *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o1;

  /* Product: '<S508>/Product1' */
  mcb_pmsm_foc_sensorless_dyno__B.Product1_j =
    mcb_pmsm_foc_sensorless_dyno__B.Add1_e *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o2;

  /* Sum: '<S508>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_o =
    mcb_pmsm_foc_sensorless_dyno__B.Product1_j -
    mcb_pmsm_foc_sensorless_dyno__B.Product_c;

  /* Product: '<S515>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_e =
    mcb_pmsm_foc_sensorless_dyno__B.Add_o /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_g;

  /* Product: '<S511>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_l =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_g *
    mcb_pmsm_foc_sensorless_dyno__B.Gain_o;

  /* Product: '<S516>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_p =
    mcb_pmsm_foc_sensorless_dyno__B.Product_l *
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_i /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector1_f;

  /* Product: '<S517>/Product' incorporates:
   *  Constant: '<S517>/Constant'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Product_ig =
    mcb_pmsm_foc_sensorless_dyno__B.Gain_o * 0.0063954151868927875 /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_bj;

  /* Product: '<S518>/Product' incorporates:
   *  Constant: '<S518>/Constant'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Product_pc =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_b * 0.36 /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_j;

  /* Sum: '<S511>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_e =
    ((mcb_pmsm_foc_sensorless_dyno__B.Product_e -
      mcb_pmsm_foc_sensorless_dyno__B.Product_p) -
     mcb_pmsm_foc_sensorless_dyno__B.Product_ig) -
    mcb_pmsm_foc_sensorless_dyno__B.Product_pc;

  /* UnitDelay: '<S524>/Unit Delay' */
  mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_bu =
    mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_g;

  /* RelationalOperator: '<S526>/Compare' incorporates:
   *  Constant: '<S526>/Constant'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Compare_e =
    (mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_bu >= -3.1415926535897931);

  /* Switch: '<S524>/Switch1' */
  if (mcb_pmsm_foc_sensorless_dyno__B.Compare_e) {
    /* RelationalOperator: '<S525>/Compare' incorporates:
     *  Constant: '<S525>/Constant'
     */
    mcb_pmsm_foc_sensorless_dyno__B.Compare_d =
      (mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_bu <= 3.1415926535897931);

    /* Switch: '<S524>/Switch' */
    if (mcb_pmsm_foc_sensorless_dyno__B.Compare_d) {
      /* Switch: '<S524>/Switch' */
      mcb_pmsm_foc_sensorless_dyno__B.Switch =
        mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_bu;
    } else {
      /* Sum: '<S524>/Subtract' incorporates:
       *  Constant: '<S524>/Constant3'
       */
      mcb_pmsm_foc_sensorless_dyno__B.Subtract =
        mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_bu - 6.2831854820251465;

      /* Switch: '<S524>/Switch' */
      mcb_pmsm_foc_sensorless_dyno__B.Switch =
        mcb_pmsm_foc_sensorless_dyno__B.Subtract;
    }

    /* End of Switch: '<S524>/Switch' */

    /* Switch: '<S524>/Switch1' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_h =
      mcb_pmsm_foc_sensorless_dyno__B.Switch;
  } else {
    /* Sum: '<S524>/Add1' incorporates:
     *  Constant: '<S524>/Constant1'
     */
    mcb_pmsm_foc_sensorless_dyno__B.Add1_oo =
      mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_bu + 6.2831854820251465;

    /* Switch: '<S524>/Switch1' */
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_h =
      mcb_pmsm_foc_sensorless_dyno__B.Add1_oo;
  }

  /* End of Switch: '<S524>/Switch1' */

  /* Gain: '<S521>/Gain4' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain4_d = 4.0 *
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_h;

  /* Trigonometry: '<S523>/sine_cosine' */
  cosOut = mcb_pmsm_foc_sensorless_dyno__B.Gain4_d;
  currentTime = sin(cosOut);
  cosOut = cos(cosOut);

  /* Trigonometry: '<S523>/sine_cosine' */
  mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o1_m = currentTime;

  /* Trigonometry: '<S523>/sine_cosine' */
  mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o2_h = cosOut;

  /* Product: '<S534>/Product2' */
  mcb_pmsm_foc_sensorless_dyno__B.Product2_i =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3 *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o2_h;

  /* Product: '<S534>/Product3' */
  mcb_pmsm_foc_sensorless_dyno__B.Product3_g =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_a *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o1_m;

  /* Sum: '<S534>/Add1' */
  mcb_pmsm_foc_sensorless_dyno__B.Add1_f =
    mcb_pmsm_foc_sensorless_dyno__B.Product2_i -
    mcb_pmsm_foc_sensorless_dyno__B.Product3_g;

  /* SignalConversion generated from: '<S520>/Vector Concatenate' incorporates:
   *  Concatenate: '<S520>/Vector Concatenate'
   */
  mcb_pmsm_foc_sensorless_dyno__B.VectorConcatenate_i[0] =
    mcb_pmsm_foc_sensorless_dyno__B.Add1_f;

  /* Gain: '<S521>/Gain' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain_b = 4.0 *
    mcb_pmsm_foc_sensorless_dyno__B.Gain;

  /* Gain: '<S524>/Gain1' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain1_h = 2.5E-5 *
    mcb_pmsm_foc_sensorless_dyno__B.Gain;

  /* Sum: '<S524>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_hz =
    mcb_pmsm_foc_sensorless_dyno__B.Gain1_h +
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_h;

  /* Switch: '<S6>/Switch1' */
  mcb_pmsm_foc_sensorless_dyno__B.Switch1_h2[0] = 0.0;
  mcb_pmsm_foc_sensorless_dyno__B.Switch1_h2[1] = 0.0;
  mcb_pmsm_foc_sensorless_dyno__B.Switch1_h2[2] = 0.0;

  /* Gain: '<S532>/Gain' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain_j = 0.66666666666666663 *
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_h2[0];

  /* Gain: '<S532>/Gain1' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain1_o = -0.33333333333333331 *
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_h2[1];

  /* Gain: '<S532>/Gain4' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain4_la = -0.33333333333333331 *
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_h2[2];

  /* Sum: '<S532>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_a =
    (mcb_pmsm_foc_sensorless_dyno__B.Gain_j +
     mcb_pmsm_foc_sensorless_dyno__B.Gain1_o) +
    mcb_pmsm_foc_sensorless_dyno__B.Gain4_la;

  /* Gain: '<S532>/Gain2' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain2_i = 0.57735026918962573 *
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_h2[1];

  /* Gain: '<S532>/Gain3' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain3_f = -0.57735026918962573 *
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_h2[2];

  /* Sum: '<S532>/Add1' */
  mcb_pmsm_foc_sensorless_dyno__B.Add1_n =
    mcb_pmsm_foc_sensorless_dyno__B.Gain2_i +
    mcb_pmsm_foc_sensorless_dyno__B.Gain3_f;

  /* Gain: '<S533>/Gain1' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain1_o0 = -0.5 *
    mcb_pmsm_foc_sensorless_dyno__B.Add1_f;

  /* Gain: '<S533>/Gain2' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain2_m = -0.5 *
    mcb_pmsm_foc_sensorless_dyno__B.Add1_f;

  /* Product: '<S534>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_df =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3 *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o1_m;

  /* Product: '<S534>/Product1' */
  mcb_pmsm_foc_sensorless_dyno__B.Product1_b =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_a *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o2_h;

  /* Sum: '<S534>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_p =
    mcb_pmsm_foc_sensorless_dyno__B.Product_df +
    mcb_pmsm_foc_sensorless_dyno__B.Product1_b;

  /* Gain: '<S533>/Gain3' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain3_fw = 0.8660254037844386 *
    mcb_pmsm_foc_sensorless_dyno__B.Add_p;

  /* Gain: '<S533>/Gain4' */
  mcb_pmsm_foc_sensorless_dyno__B.Gain4_g = -0.8660254037844386 *
    mcb_pmsm_foc_sensorless_dyno__B.Add_p;

  /* Sum: '<S533>/Subtract1' incorporates:
   *  Concatenate: '<S520>/Vector Concatenate'
   */
  mcb_pmsm_foc_sensorless_dyno__B.VectorConcatenate_i[1] =
    mcb_pmsm_foc_sensorless_dyno__B.Gain2_m +
    mcb_pmsm_foc_sensorless_dyno__B.Gain3_fw;

  /* Sum: '<S533>/Subtract2' incorporates:
   *  Concatenate: '<S520>/Vector Concatenate'
   */
  mcb_pmsm_foc_sensorless_dyno__B.VectorConcatenate_i[2] =
    mcb_pmsm_foc_sensorless_dyno__B.Gain1_o0 +
    mcb_pmsm_foc_sensorless_dyno__B.Gain4_g;

  /* Product: '<S537>/Product2' */
  mcb_pmsm_foc_sensorless_dyno__B.Product2_f =
    mcb_pmsm_foc_sensorless_dyno__B.Add_a *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o2_h;

  /* Product: '<S537>/Product3' */
  mcb_pmsm_foc_sensorless_dyno__B.Product3_i =
    mcb_pmsm_foc_sensorless_dyno__B.Add1_n *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o1_m;

  /* Sum: '<S537>/Add1' */
  mcb_pmsm_foc_sensorless_dyno__B.Add1_p =
    mcb_pmsm_foc_sensorless_dyno__B.Product2_f +
    mcb_pmsm_foc_sensorless_dyno__B.Product3_i;

  /* Product: '<S541>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_n =
    mcb_pmsm_foc_sensorless_dyno__B.Add1_p /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_gy;

  /* Product: '<S539>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_f =
    mcb_pmsm_foc_sensorless_dyno__B.Gain_b *
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_a;

  /* Product: '<S542>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_k =
    mcb_pmsm_foc_sensorless_dyno__B.Product_f *
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_h /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector1_mr;

  /* Product: '<S543>/Product' incorporates:
   *  Constant: '<S543>/Constant'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Product_fj =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3 * 0.36 /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_ca;

  /* Sum: '<S539>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_p3 =
    (mcb_pmsm_foc_sensorless_dyno__B.Product_n +
     mcb_pmsm_foc_sensorless_dyno__B.Product_k) -
    mcb_pmsm_foc_sensorless_dyno__B.Product_fj;

  /* Product: '<S537>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_fo =
    mcb_pmsm_foc_sensorless_dyno__B.Add_a *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o1_m;

  /* Product: '<S537>/Product1' */
  mcb_pmsm_foc_sensorless_dyno__B.Product1_n =
    mcb_pmsm_foc_sensorless_dyno__B.Add1_n *
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o2_h;

  /* Sum: '<S537>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_n =
    mcb_pmsm_foc_sensorless_dyno__B.Product1_n -
    mcb_pmsm_foc_sensorless_dyno__B.Product_fo;

  /* Product: '<S544>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_dy =
    mcb_pmsm_foc_sensorless_dyno__B.Add_n /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_d;

  /* Product: '<S540>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_ne =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3 *
    mcb_pmsm_foc_sensorless_dyno__B.Gain_b;

  /* Product: '<S545>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_em =
    mcb_pmsm_foc_sensorless_dyno__B.Product_ne *
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_f /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector1_fl;

  /* Product: '<S546>/Product' incorporates:
   *  Constant: '<S546>/Constant'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Product_b =
    mcb_pmsm_foc_sensorless_dyno__B.Gain_b * 0.0063954151868927875 /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_kue;

  /* Product: '<S547>/Product' incorporates:
   *  Constant: '<S547>/Constant'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Product_lp =
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_a * 0.36 /
    mcb_pmsm_foc_sensorless__ConstB.IndexVector_l0;

  /* Sum: '<S540>/Add' */
  mcb_pmsm_foc_sensorless_dyno__B.Add_l =
    ((mcb_pmsm_foc_sensorless_dyno__B.Product_dy -
      mcb_pmsm_foc_sensorless_dyno__B.Product_em) -
     mcb_pmsm_foc_sensorless_dyno__B.Product_b) -
    mcb_pmsm_foc_sensorless_dyno__B.Product_lp;

  /* Update for DiscreteIntegrator: '<S492>/Discrete-Time Integrator' */
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator_DSTATE += 2.5E-5 *
    mcb_pmsm_foc_sensorless_dyno__B.Divide;
  if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator_DSTATE > 1.0E+7) {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator_DSTATE = 1.0E+7;
  } else if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator_DSTATE <
             -1.0E+7) {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator_DSTATE = -1.0E+7;
  }

  /* End of Update for DiscreteIntegrator: '<S492>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S539>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_IC_LOAD = 0U;
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTATE += 2.5E-5 *
    mcb_pmsm_foc_sensorless_dyno__B.Add_p3;
  if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTATE > 1.0E+7) {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTATE = 1.0E+7;
  } else if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTATE <
             -1.0E+7) {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTATE = -1.0E+7;
  }

  /* End of Update for DiscreteIntegrator: '<S539>/Discrete-Time Integrator3' */

  /* Update for DiscreteIntegrator: '<S540>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_IC_LO_a = 0U;
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_i += 2.5E-5 *
    mcb_pmsm_foc_sensorless_dyno__B.Add_l;
  if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_i > 1.0E+7)
  {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_i = 1.0E+7;
  } else if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_i <
             -1.0E+7) {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_i = -1.0E+7;
  }

  /* End of Update for DiscreteIntegrator: '<S540>/Discrete-Time Integrator3' */

  /* Update for UnitDelay: '<S489>/Unit Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE =
    mcb_pmsm_foc_sensorless_dyno__B.Add1;

  /* Update for DiscreteIntegrator: '<S510>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_IC_LO_i = 0U;
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_e += 2.5E-5 *
    mcb_pmsm_foc_sensorless_dyno__B.Add_m;
  if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_e > 1.0E+7)
  {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_e = 1.0E+7;
  } else if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_e <
             -1.0E+7) {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_e = -1.0E+7;
  }

  /* End of Update for DiscreteIntegrator: '<S510>/Discrete-Time Integrator3' */

  /* Update for UnitDelay: '<S495>/Unit Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_b =
    mcb_pmsm_foc_sensorless_dyno__B.Add_h;

  /* Update for DiscreteIntegrator: '<S511>/Discrete-Time Integrator3' */
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_IC_LO_e = 0U;
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_n += 2.5E-5 *
    mcb_pmsm_foc_sensorless_dyno__B.Add_e;
  if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_n > 1.0E+7)
  {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_n = 1.0E+7;
  } else if (mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_n <
             -1.0E+7) {
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_n = -1.0E+7;
  }

  /* End of Update for DiscreteIntegrator: '<S511>/Discrete-Time Integrator3' */

  /* Update for UnitDelay: '<S524>/Unit Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_g =
    mcb_pmsm_foc_sensorless_dyno__B.Add_hz;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 2.5E-5, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  mcb_pmsm_foc_sensorless_dyno_M->Timing.clockTick0++;
  if (!mcb_pmsm_foc_sensorless_dyno_M->Timing.clockTick0) {
    mcb_pmsm_foc_sensorless_dyno_M->Timing.clockTickH0++;
  }
}

/* Model step function for TID1 */
void mcb_pmsm_foc_sensorless_dyno_f28379d_step1(void) /* Sample time: [0.001s, 0.0s] */
{
  real32_T UnitDelay_f;

  /* RateTransition: '<Root>/RT' */
  mcb_pmsm_foc_sensorless_dyno__B.RT_f =
    mcb_pmsm_foc_sensorless_d_DWork.RT_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RT_ActiveBufIdx];

  /* RateTransition: '<Root>/RT3' */
  mcb_pmsm_foc_sensorless_d_DWork.RT3_semaphoreTaken =
    mcb_pmsm_foc_sensorless_d_DWork.RT3_ActiveBufIdx;

  /* RateTransition: '<Root>/RT3' */
  mcb_pmsm_foc_sensorless_dyno__B.RT3 =
    mcb_pmsm_foc_sensorless_d_DWork.RT3_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RT3_semaphoreTaken];

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */

  /* Constant: '<Root>/EstimatorSelect' */
  mcb_pmsm_foc_s_SpeedControl(1.0, mcb_pmsm_foc_sensorless_dyno__B.RT_f,
    mcb_pmsm_foc_sensorless_dyno__B.RT3,
    &mcb_pmsm_foc_sensorless_d_DWork.EnClosedLoop,
    &mcb_pmsm_foc_sensorless_d_DWork.Enable,
    &mcb_pmsm_foc_sensorless_d_DWork.SpeedRef,
    &mcb_pmsm_foc_sensorless_dyno__B.SpeedControl,
    &mcb_pmsm_foc_sensorless_d_DWork.SpeedControl);

  /* End of Outputs for SubSystem: '<Root>/Speed Control' */

  /* RateTransition: '<Root>/RT2' */
  mcb_pmsm_foc_sensorless_d_DWork.RT2_Buffer
    [(mcb_pmsm_foc_sensorless_d_DWork.RT2_ActiveBufIdx == 0) << 1U] =
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.Id_Ref;
  mcb_pmsm_foc_sensorless_d_DWork.RT2_Buffer[1 +
    ((mcb_pmsm_foc_sensorless_d_DWork.RT2_ActiveBufIdx == 0) << 1U)] =
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.Trq_ref;
  mcb_pmsm_foc_sensorless_d_DWork.RT2_ActiveBufIdx =
    (mcb_pmsm_foc_sensorless_d_DWork.RT2_ActiveBufIdx == 0);

  /* RateTransition: '<Root>/Rate Transition3' */
  mcb_pmsm_foc_sensorless_dyno__B.RateTransition3 =
    mcb_pmsm_foc_sensorless_d_DWork.RateTransition3_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RateTransition3_ActiveBufIdx];

  /* Outputs for Atomic SubSystem: '<Root>/Torque Demand' */
  /* Switch: '<S619>/Switch1' incorporates:
   *  Constant: '<S619>/FilterConstant'
   *  Constant: '<S619>/OneMinusFilterConstant'
   */
  mcb_pmsm_foc_sensorless_dyno__B.Switch1_b[0] = 0.2F;
  mcb_pmsm_foc_sensorless_dyno__B.Switch1_b[1] = 0.8F;

  /* Product: '<S622>/Product' */
  mcb_pmsm_foc_sensorless_dyno__B.Product_i1[0] = 0.0F;
  mcb_pmsm_foc_sensorless_dyno__B.Product_i1[1] =
    mcb_pmsm_foc_sensorless_dyno__B.RateTransition3 * 0.2F;

  /* UnitDelay: '<S622>/Unit Delay' */
  UnitDelay_f = mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_bn[0];

  /* End of Outputs for SubSystem: '<Root>/Torque Demand' */
  mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_f[0] = UnitDelay_f;

  /* Outputs for Atomic SubSystem: '<Root>/Torque Demand' */
  /* Product: '<S622>/Product1' */
  UnitDelay_f *= 0.8F;

  /* End of Outputs for SubSystem: '<Root>/Torque Demand' */
  mcb_pmsm_foc_sensorless_dyno__B.Product1_g[0] = UnitDelay_f;

  /* Sum: '<S622>/Add1' */
  mcb_pmsm_foc_sensorless_dyno__B.Add1_i[0] = UnitDelay_f;

  /* Outputs for Atomic SubSystem: '<Root>/Torque Demand' */
  /* Update for UnitDelay: '<S622>/Unit Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_bn[0] = UnitDelay_f;

  /* UnitDelay: '<S622>/Unit Delay' */
  UnitDelay_f = mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_bn[1];

  /* End of Outputs for SubSystem: '<Root>/Torque Demand' */
  mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_f[1] = UnitDelay_f;

  /* Outputs for Atomic SubSystem: '<Root>/Torque Demand' */
  /* Product: '<S622>/Product1' */
  UnitDelay_f *= 0.8F;

  /* End of Outputs for SubSystem: '<Root>/Torque Demand' */
  mcb_pmsm_foc_sensorless_dyno__B.Product1_g[1] = UnitDelay_f;

  /* Outputs for Atomic SubSystem: '<Root>/Torque Demand' */
  /* Sum: '<S622>/Add1' */
  UnitDelay_f += mcb_pmsm_foc_sensorless_dyno__B.Product_i1[1];

  /* End of Outputs for SubSystem: '<Root>/Torque Demand' */
  mcb_pmsm_foc_sensorless_dyno__B.Add1_i[1] = UnitDelay_f;

  /* Outputs for Atomic SubSystem: '<Root>/Torque Demand' */
  /* Update for UnitDelay: '<S622>/Unit Delay' */
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_bn[1] = UnitDelay_f;

  /* End of Outputs for SubSystem: '<Root>/Torque Demand' */

  /* RateTransition: '<Root>/RT6' */
  mcb_pmsm_foc_sensorless_d_DWork.RT6_Buffer
    [(mcb_pmsm_foc_sensorless_d_DWork.RT6_ActiveBufIdx == 0) << 1U] =
    mcb_pmsm_foc_sensorless_dyno__B.Add1_i[0];
  mcb_pmsm_foc_sensorless_d_DWork.RT6_Buffer[1 +
    ((mcb_pmsm_foc_sensorless_d_DWork.RT6_ActiveBufIdx == 0) << 1U)] =
    mcb_pmsm_foc_sensorless_dyno__B.Add1_i[1];
  mcb_pmsm_foc_sensorless_d_DWork.RT6_ActiveBufIdx =
    (mcb_pmsm_foc_sensorless_d_DWork.RT6_ActiveBufIdx == 0);
}

/* Model step function for TID2 */
void mcb_pmsm_foc_sensorless_dyno_f28379d_step2(void) /* Sample time: [0.5s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* S-Function (c280xgpio_do): '<S483>/Digital Output' incorporates:
   *  Constant: '<S5>/RED_LED'
   */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)((1U) != 0);
  }

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void mcb_pmsm_foc_sensorless_dyno_f28379d_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mcb_pmsm_foc_sensorless_dyno_M, 0,
                sizeof(RT_MODEL_mcb_pmsm_foc_sensorles));

  /* block I/O */
  (void) memset(((void *) &mcb_pmsm_foc_sensorless_dyno__B), 0,
                sizeof(BlockIO_mcb_pmsm_foc_sensorless));

  {
    int16_T i;
    for (i = 0; i < 6; i++) {
      mcb_pmsm_foc_sensorless_dyno__B.mtr2_VI_debug[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      mcb_pmsm_foc_sensorless_dyno__B.mtr2_VI_debug_k[i] = 0.0F;
    }

    for (i = 0; i < 25; i++) {
      mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtSelectorIn[i] = 0.0F;
    }

    mcb_pmsm_foc_sensorless_dyno__B.T_load = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_a = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Switch2 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1[0] = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1[1] = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product1 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add1 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_g = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_b = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_g = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain4 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o1 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o2 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product2 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.DiscreteTimeIntegrator3_b = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product3 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_c = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_a = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_i = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain1 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain2 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Divide2 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Sign = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Divide1 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Sum1 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Divide = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_o = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain1_b = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add_h = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_f = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain1_j = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain4_n = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add_b = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain2_p = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain3 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_e = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain1_e = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain2_k = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_h = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_k = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add_c = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain3_a = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain4_l = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product2_j = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product3_o = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_o = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_d = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_o = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_iz = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_hf = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add_m = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_c = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_j = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add_o = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_e = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_l = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_p = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_ig = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_pc = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add_e = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.VectorConcatenate[0] = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.VectorConcatenate[1] = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.VectorConcatenate[2] = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_bu = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_h = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain4_d = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o1_m = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.sine_cosine_o2_h = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product2_i = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product3_g = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_f = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_b = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain1_h = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add_hz = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_h2[0] = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_h2[1] = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_h2[2] = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_j = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain1_o = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain4_la = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add_a = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain2_i = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain3_f = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_n = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain1_o0 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain2_m = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_df = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_b = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add_p = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain3_fw = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain4_g = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product2_f = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product3_i = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_p = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_n = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_f = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_k = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_fj = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add_p3 = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_fo = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_n = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add_n = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_dy = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_ne = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_em = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_b = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_lp = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add_l = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.VectorConcatenate_i[0] = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.VectorConcatenate_i[1] = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.VectorConcatenate_i[2] = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain1_d = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_g = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Product_m = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add_g = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Gain2_c = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_oo = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Switch = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Subtract = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_j = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Switch_e = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.Subtract_g = 0.0;
    mcb_pmsm_foc_sensorless_dyno__B.RT_f = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.RT3 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.RateTransition3 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.RT2[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.RT2[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Te_PU = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Pm_PU = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Speed_PU = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Iab_meas_PU[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Iab_meas_PU[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Pos_PU = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.RT6[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.RT6[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_b[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_b[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_i1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_i1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_f[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_f[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_g[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_g[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_i[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_i[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SCIReceive[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SCIReceive[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SCIReceive[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.OutportBufferForDesriedIqref = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.GetADCVoltage[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.GetADCVoltage[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.GetCurrents[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.GetCurrents[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay_j[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay_j[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay_j[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay_j[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge_b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.indexing = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Lookup[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Lookup[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Lookup[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Lookup[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum3 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_dx = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum4 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum5 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_f = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum6 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.id_Ld_Lq = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add_gw = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product3_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.u_5_Pp = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Te_PU_i = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_en = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.P_output = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Pm_PU_m = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Speed_PU_h = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Iab_meas_PU_j[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Iab_meas_PU_j[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.mtr2_Pos_PU_d = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum_g = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum_k = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_de = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_ii = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum1_g = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge_e[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge_e[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_o = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch_n = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelayInpor[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelayInpor[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelayInpor[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelayInpor[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.sqrt3_by_two = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.one_by_two = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.add_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.add_b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Min = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Max = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add_eb = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.one_by_two_j = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add3 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_jx = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_jn[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_jn[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_jn[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_i[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_i[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_i[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.PWM_Duty_Cycles[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.PWM_Duty_Cycles[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.PWM_Duty_Cycles[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay_k = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum2_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum3_o = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.b_invg = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum4_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_b4[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_b4[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_af = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_h = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_ih = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay1_b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_fo = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.a_i = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum2_lr = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum3_p = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.b_invg_p = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay1_p = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum4_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_c[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_c[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_j = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_d = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_o = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay_ce = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sign_f = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Eta = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum_h = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.a_f = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum1_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sign_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Eta_b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.b_i = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.a_j = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum1_d = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DTC = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedGain = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_d[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_d[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_md = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_o = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_je = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_jc = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_n = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add_cd = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.V_q_ref = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.V_d_ref = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DataStoreRead = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Abs = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_d5 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay5[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay5[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay5[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay5[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge_f[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge_f[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.GetADCVoltage_h[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.GetADCVoltage_h[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.GetCurrents_g[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.GetCurrents_g[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion_f[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.PU_Conversion_f[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge_bb = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.indexing_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Lookup_n[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum3_m = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion1_f = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum2_b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_e4 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum4_b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum5_d = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_g1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum6_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum_b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_de = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch_b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum_oh = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_p = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch_h = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch_m = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_jb = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_it = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_le = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum1_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge_a[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge_a[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.id_Ld_Lq_p = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add_gy = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product3_d = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.u_5_Pp_b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_cc = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.P_output_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.mtr1_speed_ref_PU = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Selector[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Selector[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch_p = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.OutportBufferForSpeed_fb = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelay5Inpo[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelay5Inpo[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelay5Inpo[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TmpSignalConversionAtDelay5Inpo[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.sqrt3_by_two_n = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.one_by_two_g = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.add_c_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.add_b_o = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Min_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Max_n = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add_b0 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.one_by_two_i = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add3_m = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add2_p = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_of = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_m[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_m[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Gain_m[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.One_by_Two[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.One_by_Two[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.One_by_Two[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.PWM_Duty_Cycles_i[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.PWM_Duty_Cycles_i[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.PWM_Duty_Cycles_i[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay1_f = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_g = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.a_g = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay_jf = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum2_h = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum3_oo = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.b_invg_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay1_h = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum4_g = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_dz[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_dz[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_cx = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_k = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_gj = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_na = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay1_d = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_oi = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.a_h = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay_i = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum2_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum3_j = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.b_invg_k = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay1_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum4_d = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_o[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_o[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_jt = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_ny = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Merge1_g = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Delay_g = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sign_fc = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Eta_j = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum_o2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.b_m = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.a_k = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum1_m = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sign_h = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Eta_h = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum_e3 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.b_g = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.a_p = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Sum1_p = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DTC_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedGain_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_k[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Switch1_k[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product_pcn = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.UnitDelay_os = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Product1_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_cq = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add_h0 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion1_d = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Add1_pp = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Input = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.V_q_ref_m = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Vd_OpenLoop = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Abs_k = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.Saturation = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.V_d_ref_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.Id_Ref = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.Merge = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.Speed_Ref = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.Switch1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.Switch1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.Product = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.UnitDelay = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.Product1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.Add1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.Sum = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.RateLimiter = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.RateLimiter1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.DataStoreRead = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.Switch1_n = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.SpeedControl.Trq_ref = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Switch1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Switch1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.UnitDelay[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.UnitDelay[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.UnitDelay[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.UnitDelay[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product1[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product1[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Add1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Add1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Add1[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Add1[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum6[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum6[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum6[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum6[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum3 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Delay1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product_f = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Delay_k = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product1_b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum1_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum_i = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Switch1_k[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Switch1_k[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product_m = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.UnitDelay_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product1_n = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Add1_p = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Switch = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product_n = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum3_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Delay1_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Delay_f = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product1_i = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum1_cf = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product2_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum1_n = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum_iu = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Switch1_p[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Switch1_p[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product_nb = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.UnitDelay_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product1_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Add1_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Switch_h = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.DTC = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.SpeedGain = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Switch1_c[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Switch1_c[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product_d = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.UnitDelay_m = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Product1_d = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Add1_h = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.elect2mech = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum_j = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Sum_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Atan2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Switch_b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.algDD = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Gain = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Switch_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver_a.Bias = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.Product = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.Product2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.Sum1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.Product1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.Product3 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.Sum2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.Switch = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.Atan2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.Switch_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.algDD = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.Gain = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.Switch_p = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.Bias = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation_p.Bias_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem1_f.Convert_back = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem_k.Convert_back = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.acos_k = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.bsin = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.sum_Ds = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.bcos = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.asin_m = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.sum_Qs = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.Switch[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.Switch[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.algDD_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_h.algDD_o2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.qcos = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.dsin = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.sum_beta = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.dcos = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.qsin = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.sum_alpha = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.Switch[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.Switch[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.algDD_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_e.algDD_o2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQEquivalence_j.Product[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQEquivalence_j.Product[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQEquivalence_j.SquareRoot = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQEquivalence_j.Switch = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority_m.Switch[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority_m.Switch[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority_m.Switch2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority_m.Product = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority_m.Sum = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority_m.Product2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority_m.Merge = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority_m.Gain = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority_m.Switch_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority_m.Switch1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority_m.Sqrt = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority_m.Gain_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap_g.a_plus_2b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap_g.one_by_sqrt3 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap_g.algDD_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap_g.algDD_o2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Switch1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Switch1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.UnitDelay[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.UnitDelay[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.UnitDelay[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.UnitDelay[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product1[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product1[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Add1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Add1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Add1[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Add1[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum6[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum6[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum6[2] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum6[3] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum3 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Delay1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product_f = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Delay_k = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product1_b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum1_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum_i = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Switch1_k[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Switch1_k[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product_m = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.UnitDelay_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product1_n = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Add1_p = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Switch = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product_n = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum3_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Delay1_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Delay_f = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product1_i = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum1_cf = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product2_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum1_n = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum_iu = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Switch1_p[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Switch1_p[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product_nb = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.UnitDelay_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product1_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Add1_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Switch_h = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.DTC = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.SpeedGain = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Switch1_c[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Switch1_c[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product_d = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.UnitDelay_m = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Product1_d = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Add1_h = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.elect2mech = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum_j = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Sum_c = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Atan2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Switch_b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.algDD = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Gain = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Switch_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.FluxObserver.Bias = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.Product = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.Product2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.Sum1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.Product1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.Product3 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.Sum2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.Switch = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.Atan2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.Switch_e = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.algDD = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.Gain = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.Switch_p = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.Bias = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.angleCompensation.Bias_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem1.Convert_back = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem.Convert_back = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.acos_k = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.bsin = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.sum_Ds = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.bcos = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.asin_m = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.sum_Qs = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.Switch[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.Switch[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.algDD_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL_p.algDD_o2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.qcos = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.dsin = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.sum_beta = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.dcos = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.qsin = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.sum_alpha = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.Switch[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.Switch[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.algDD_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwoinputsCRL.algDD_o2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQEquivalence.Product[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQEquivalence.Product[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQEquivalence.SquareRoot = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQEquivalence.Switch = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority.Switch[0] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority.Switch[1] = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority.Switch2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority.Product = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority.Sum = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority.Product2 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority.Merge = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority.Gain = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority.Switch_a = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority.Switch1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority.Sqrt = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.DQAxisPriority.Gain_l = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap.a_plus_2b = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap.one_by_sqrt3 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap.algDD_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_dyno__B.TwophaseCRLwrap.algDD_o2 = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&mcb_pmsm_foc_sensorless_d_DWork, 0,
                sizeof(D_Work_mcb_pmsm_foc_sensorless_));
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator_DSTATE = 0.0;
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTATE = 0.0;
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_i = 0.0;
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE = 0.0;
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_e = 0.0;
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_b = 0.0;
  mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_DSTAT_n = 0.0;
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_g = 0.0;
  mcb_pmsm_foc_sensorless_d_DWork.Add1_DWORK1 = 0.0;
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_bn[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_bn[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE[2] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE[3] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_m = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay1_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_n = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay1_DSTATE_i = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_j = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_gq = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_m = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay5_DSTATE[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay5_DSTATE[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay5_DSTATE[2] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay5_DSTATE[3] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_bc = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.UnitDelay_DSTATE_k = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_l = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay1_DSTATE_f = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_nx = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay1_DSTATE_n = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Delay_DSTATE_h = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT_Buffer[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT_Buffer[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT3_Buffer[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT3_Buffer[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT2_Buffer[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT2_Buffer[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT2_Buffer[2] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT2_Buffer[3] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RateTransition3_Buffer[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RateTransition3_Buffer[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT6_Buffer[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT6_Buffer[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT6_Buffer[2] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT6_Buffer[3] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.SpeedRef = 0.0F;

  {
    int16_T i;
    for (i = 0; i < 12; i++) {
      mcb_pmsm_foc_sensorless_d_DWork.RT8_1_Buffer[i] = 0.0F;
    }
  }

  mcb_pmsm_foc_sensorless_d_DWork.RT8_2_Buffer[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT8_2_Buffer[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT8_3_Buffer[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT8_3_Buffer[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT8_4_Buffer[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT8_4_Buffer[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT8_5_Buffer[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT8_5_Buffer[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT8_5_Buffer[2] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT8_5_Buffer[3] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT8_6_Buffer[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.RT8_6_Buffer[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.Add_DWORK1 = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state_l = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state_p = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.integrator_state_j = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.SpeedControl.UnitDelay_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.SpeedControl.PrevY = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.SpeedControl.PrevY_a = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.SpeedControl.integrator_state = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver_a.UnitDelay_DSTATE[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver_a.UnitDelay_DSTATE[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver_a.UnitDelay_DSTATE[2] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver_a.UnitDelay_DSTATE[3] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver_a.Delay1_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver_a.Delay_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver_a.UnitDelay_DSTATE_b = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver_a.Delay1_DSTATE_c = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver_a.Delay_DSTATE_c = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver_a.UnitDelay_DSTATE_c = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver_a.UnitDelay_DSTATE_f = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver.UnitDelay_DSTATE[0] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver.UnitDelay_DSTATE[1] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver.UnitDelay_DSTATE[2] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver.UnitDelay_DSTATE[3] = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver.Delay1_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver.Delay_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver.UnitDelay_DSTATE_b = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver.Delay1_DSTATE_c = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver.Delay_DSTATE_c = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver.UnitDelay_DSTATE_c = 0.0F;
  mcb_pmsm_foc_sensorless_d_DWork.FluxObserver.UnitDelay_DSTATE_f = 0.0F;

  {
    uint16_T s469_iter;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
    mcb_pmsm_foc_sensorless_d_DWork.SpeedRef = 0.1F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    mcb_pmsm_foc_sensorless_d_DWork.IaOffset_motor1 = 2295U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    mcb_pmsm_foc_sensorless_d_DWork.IbOffset_motor1 = 2286U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    mcb_pmsm_foc_sensorless_d_DWork.Debug_signals = 5U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
    mcb_pmsm_foc_sensorless_d_DWork.IbOffset_motor2 = 2286U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
    mcb_pmsm_foc_sensorless_d_DWork.IaOffset_motor2 = 2286U;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_o = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_lr = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_bs = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_bh = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_j = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_m = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.FluxObserver_a.Delay1_Reset_ZCE =
      UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.FluxObserver_a.Delay_Reset_ZCE =
      UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.FluxObserver_a.Delay1_Reset_ZCE_b =
      UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.FluxObserver_a.Delay_Reset_ZCE_g =
      UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Dir_Sense_o.Dir_Sense_Trig_ZCE = POS_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.FluxObserver.Delay1_Reset_ZCE =
      UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.FluxObserver.Delay_Reset_ZCE =
      UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.FluxObserver.Delay1_Reset_ZCE_b =
      UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.FluxObserver.Delay_Reset_ZCE_g =
      UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Dir_Sense.Dir_Sense_Trig_ZCE = POS_ZCSIG;

    /* InitializeConditions for DiscreteIntegrator: '<S539>/Discrete-Time Integrator3' */
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_IC_LOAD = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S540>/Discrete-Time Integrator3' */
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_IC_LO_a = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S510>/Discrete-Time Integrator3' */
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_IC_LO_i = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S511>/Discrete-Time Integrator3' */
    mcb_pmsm_foc_sensorless_d_DWork.DiscreteTimeIntegrator3_IC_LO_e = 1U;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/FOC Algorithm Motor 1'
     */
    mcb_FOCAlgorithmMotor1_Init();

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S16>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/FOC Algorithm Motor 2'
     */
    mcb_FOCAlgorithmMotor2_Init();

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S18>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Serial Receive'
     */
    /* System initialize for function-call system: '<Root>/Serial Receive' */

    /* Start for S-Function (c28xsci_rx): '<S554>/SCI Receive' */

    /* Initialize out port */
    {
      mcb_pmsm_foc_sensorless_dyno__B.SCIReceive[0] = (real32_T)0.0;
      mcb_pmsm_foc_sensorless_dyno__B.SCIReceive[1] = (real32_T)0.0;
      mcb_pmsm_foc_sensorless_dyno__B.SCIReceive[2] = (real32_T)0.0;
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

    /* SystemInitialize for Atomic SubSystem: '<Root>/Speed Control' */
    mcb_pmsm__SpeedControl_Init(&mcb_pmsm_foc_sensorless_dyno__B.SpeedControl,
      &mcb_pmsm_foc_sensorless_d_DWork.SpeedControl);

    /* End of SystemInitialize for SubSystem: '<Root>/Speed Control' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
    /* Start for S-Function (c280xgpio_do): '<S483>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
    GpioCtrlRegs.GPBDIR.all |= 0x4U;
    EDIS;

    /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Hardware Init' */
    /* SystemInitialize for Atomic SubSystem: '<S463>/Enable DRV8305 for motor 1 and motor 2' */
    /* Start for S-Function (c280xgpio_do): '<S466>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
    GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<S466>/Bottom DRV8305 EN' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFCFFFFFU;
    GpioCtrlRegs.GPADIR.all |= 0x4000000U;
    EDIS;
    mcb__SPIMasterTransfer_Init
      (&mcb_pmsm_foc_sensorless_d_DWork.SPIMasterTransfer);
    mcb_SPIMasterTransfer2_Init
      (&mcb_pmsm_foc_sensorless_d_DWork.SPIMasterTransfer2);
    mcb__SPIMasterTransfer_Init
      (&mcb_pmsm_foc_sensorless_d_DWork.SPIMasterTransfer1);
    mcb_SPIMasterTransfer2_Init
      (&mcb_pmsm_foc_sensorless_d_DWork.SPIMasterTransfer3);

    /* End of SystemInitialize for SubSystem: '<S463>/Enable DRV8305 for motor 1 and motor 2' */

    /* SystemInitialize for Atomic SubSystem: '<S463>/Calibrate ADC offset for motor 1 current sensor' */
    /* SystemInitialize for Enabled SubSystem: '<S464>/Calculate ADC Offset ' */
    /* SystemInitialize for Iterator SubSystem: '<S467>/For Iterator Subsystem' */
    /* Start for S-Function (c2802xadc): '<S469>/ADC_A_IN0' */
    if (MW_adcCInitFlag == 0U) {
      InitAdcC();
      MW_adcCInitFlag = 1U;
    }

    config_ADCC_SOC2 ();

    /* Start for S-Function (c2802xadc): '<S469>/ADC_B_IN0' */
    if (MW_adcBInitFlag == 0U) {
      InitAdcB();
      MW_adcBInitFlag = 1U;
    }

    config_ADCB_SOC2 ();

    /* End of SystemInitialize for SubSystem: '<S467>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S464>/Calculate ADC Offset ' */
    /* End of SystemInitialize for SubSystem: '<S463>/Calibrate ADC offset for motor 1 current sensor' */

    /* SystemInitialize for Atomic SubSystem: '<S463>/Calibrate ADC offset for motor 2 current sensor' */
    /* SystemInitialize for Enabled SubSystem: '<S465>/Calculate ADC Offset' */
    /* SystemInitialize for Iterator SubSystem: '<S475>/For Iterator Subsystem' */
    /* Start for S-Function (c2802xadc): '<S477>/ADC_A_IN1' */
    if (MW_adcCInitFlag == 0U) {
      InitAdcC();
      MW_adcCInitFlag = 1U;
    }

    config_ADCC_SOC3 ();

    /* Start for S-Function (c2802xadc): '<S477>/ADC_B_IN1' */
    if (MW_adcBInitFlag == 0U) {
      InitAdcB();
      MW_adcBInitFlag = 1U;
    }

    config_ADCB_SOC3 ();

    /* End of SystemInitialize for SubSystem: '<S475>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S465>/Calculate ADC Offset' */
    /* End of SystemInitialize for SubSystem: '<S463>/Calibrate ADC offset for motor 2 current sensor' */
    /* End of SystemInitialize for SubSystem: '<Root>/Hardware Init' */

    /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Outputs for Atomic SubSystem: '<S463>/Enable DRV8305 for motor 1 and motor 2' */
    /* S-Function (c280xgpio_do): '<S466>/Digital Output' incorporates:
     *  Constant: '<S466>/DRV830x Enable'
     */
    {
      if ((1U)) {
        GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
      } else {
        GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
      }
    }

    /* Constant: '<S466>/6PWM_Mode' */
    mcb_pmsm__SPIMasterTransfer(14870U,
      &mcb_pmsm_foc_sensorless_dyno__B.SPIMasterTransfer,
      &mcb_pmsm_foc_sensorless_d_DWork.SPIMasterTransfer);

    /* Constant: '<S466>/6PWM_Mode1' */
    mcb_pmsm_SPIMasterTransfer2(14870U,
      &mcb_pmsm_foc_sensorless_dyno__B.SPIMasterTransfer2,
      &mcb_pmsm_foc_sensorless_d_DWork.SPIMasterTransfer2);

    /* Constant: '<S466>/ADC_Gain_Setting' */
    mcb_pmsm__SPIMasterTransfer(20480U,
      &mcb_pmsm_foc_sensorless_dyno__B.SPIMasterTransfer1,
      &mcb_pmsm_foc_sensorless_d_DWork.SPIMasterTransfer1);

    /* Constant: '<S466>/ADC_Gain_Setting1' */
    mcb_pmsm_SPIMasterTransfer2(20480U,
      &mcb_pmsm_foc_sensorless_dyno__B.SPIMasterTransfer3,
      &mcb_pmsm_foc_sensorless_d_DWork.SPIMasterTransfer3);

    /* S-Function (c280xgpio_do): '<S466>/Bottom DRV8305 EN' incorporates:
     *  Constant: '<S466>/DRV830x Enable3'
     */
    {
      if ((1U)) {
        GpioDataRegs.GPASET.bit.GPIO26 = 1U;
      } else {
        GpioDataRegs.GPACLEAR.bit.GPIO26 = 1U;
      }
    }

    /* End of Outputs for SubSystem: '<S463>/Enable DRV8305 for motor 1 and motor 2' */

    /* Outputs for Atomic SubSystem: '<S463>/Calibrate ADC offset for motor 1 current sensor' */
    /* Outputs for Enabled SubSystem: '<S464>/Calculate ADC Offset ' incorporates:
     *  EnablePort: '<S467>/Enable'
     */
    /* Outputs for Iterator SubSystem: '<S467>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S469>/For Iterator'
     */
    for (s469_iter = 1U; s469_iter < 17U; s469_iter++) {
      /* Outputs for Iterator SubSystem: '<S467>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S469>/For Iterator'
       */
      mcb_pmsm_foc_sensorless_dyno__B.ForIterator_p = s469_iter;

      /* S-Function (c2802xadc): '<S469>/ADC_A_IN0' */
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

        mcb_pmsm_foc_sensorless_dyno__B.ADC_A_IN0 = (AdccResultRegs.ADCRESULT2);
      }

      /* S-Function (c2802xadc): '<S469>/ADC_B_IN0' */
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

        mcb_pmsm_foc_sensorless_dyno__B.ADC_B_IN0 = (AdcbResultRegs.ADCRESULT2);
      }

      /* If: '<S469>/If' */
      if (mcb_pmsm_foc_sensorless_dyno__B.ForIterator_p > 8U) {
        /* Outputs for IfAction SubSystem: '<S469>/If Action Subsystem' incorporates:
         *  ActionPort: '<S474>/Action Port'
         */
        mcb_pms_IfActionSubsystem_c(mcb_pmsm_foc_sensorless_dyno__B.ADC_A_IN0,
          mcb_pmsm_foc_sensorless_dyno__B.ADC_B_IN0,
          &mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem_c,
          &mcb_pmsm_foc_sensorless_d_DWork.IfActionSubsystem_c);

        /* End of Outputs for SubSystem: '<S469>/If Action Subsystem' */
      }

      /* End of If: '<S469>/If' */
    }

    /* End of Outputs for SubSystem: '<S467>/For Iterator Subsystem' */

    /* Product: '<S467>/Divide' incorporates:
     *  Constant: '<S467>/Constant'
     */
    mcb_pmsm_foc_sensorless_dyno__B.Divide_f = (uint16_T)((real_T)
      mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem_c.Sum / 8.0);

    /* If: '<S467>/If' incorporates:
     *  Constant: '<S467>/Constant1'
     *  Constant: '<S467>/Constant2'
     */
    if ((mcb_pmsm_foc_sensorless_dyno__B.Divide_f > 1500U) &&
        (mcb_pmsm_foc_sensorless_dyno__B.Divide_f < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S467>/If Action Subsystem' incorporates:
       *  ActionPort: '<S470>/Action Port'
       */
      /* DataStoreWrite: '<S470>/Data Store Write1' */
      mcb_pmsm_foc_sensorless_d_DWork.IaOffset_motor1 =
        mcb_pmsm_foc_sensorless_dyno__B.Divide_f;

      /* End of Outputs for SubSystem: '<S467>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S467>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S471>/Action Port'
       */
      /* DataStoreWrite: '<S471>/Data Store Write1' incorporates:
       *  Constant: '<S471>/Constant'
       */
      mcb_pmsm_foc_sensorless_d_DWork.IaOffset_motor1 = 2295U;

      /* End of Outputs for SubSystem: '<S467>/If Action Subsystem1' */
    }

    /* End of If: '<S467>/If' */

    /* Product: '<S467>/Divide1' incorporates:
     *  Constant: '<S467>/Constant'
     */
    mcb_pmsm_foc_sensorless_dyno__B.Divide1_m = (uint16_T)((real_T)
      mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem_c.Sum1 / 8.0);

    /* If: '<S467>/If1' incorporates:
     *  Constant: '<S467>/Constant1'
     *  Constant: '<S467>/Constant2'
     */
    if ((mcb_pmsm_foc_sensorless_dyno__B.Divide1_m > 1500U) &&
        (mcb_pmsm_foc_sensorless_dyno__B.Divide1_m < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S467>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S472>/Action Port'
       */
      /* DataStoreWrite: '<S472>/Data Store Write2' */
      mcb_pmsm_foc_sensorless_d_DWork.IbOffset_motor1 =
        mcb_pmsm_foc_sensorless_dyno__B.Divide1_m;

      /* End of Outputs for SubSystem: '<S467>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S467>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S473>/Action Port'
       */
      /* DataStoreWrite: '<S473>/Data Store Write2' incorporates:
       *  Constant: '<S473>/Constant1'
       */
      mcb_pmsm_foc_sensorless_d_DWork.IbOffset_motor1 = 2286U;

      /* End of Outputs for SubSystem: '<S467>/If Action Subsystem3' */
    }

    /* End of If: '<S467>/If1' */
    /* End of Outputs for SubSystem: '<S464>/Calculate ADC Offset ' */

    /* Logic: '<S464>/NOT' incorporates:
     *  Constant: '<S464>/ADC Calib Enable'
     */
    mcb_pmsm_foc_sensorless_dyno__B.NOT_i = false;

    /* Outputs for Enabled SubSystem: '<S464>/Default ADC Offset' incorporates:
     *  EnablePort: '<S468>/Enable'
     */
    if (mcb_pmsm_foc_sensorless_dyno__B.NOT_i) {
      /* DataStoreWrite: '<S468>/Data Store Write1' incorporates:
       *  Constant: '<S468>/Constant'
       */
      mcb_pmsm_foc_sensorless_d_DWork.IaOffset_motor1 = 2295U;

      /* DataStoreWrite: '<S468>/Data Store Write2' incorporates:
       *  Constant: '<S468>/Constant1'
       */
      mcb_pmsm_foc_sensorless_d_DWork.IbOffset_motor1 = 2286U;
    }

    /* End of Outputs for SubSystem: '<S464>/Default ADC Offset' */
    /* End of Outputs for SubSystem: '<S463>/Calibrate ADC offset for motor 1 current sensor' */

    /* Outputs for Atomic SubSystem: '<S463>/Calibrate ADC offset for motor 2 current sensor' */
    /* Outputs for Enabled SubSystem: '<S465>/Calculate ADC Offset' incorporates:
     *  EnablePort: '<S475>/Enable'
     */
    /* Outputs for Iterator SubSystem: '<S475>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S477>/For Iterator'
     */
    for (s469_iter = 1U; s469_iter < 17U; s469_iter++) {
      /* Outputs for Iterator SubSystem: '<S475>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S477>/For Iterator'
       */
      mcb_pmsm_foc_sensorless_dyno__B.ForIterator = s469_iter;

      /* S-Function (c2802xadc): '<S477>/ADC_A_IN1' */
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

        mcb_pmsm_foc_sensorless_dyno__B.ADC_A_IN1 = (AdccResultRegs.ADCRESULT3);
      }

      /* S-Function (c2802xadc): '<S477>/ADC_B_IN1' */
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

        mcb_pmsm_foc_sensorless_dyno__B.ADC_B_IN1 = (AdcbResultRegs.ADCRESULT3);
      }

      /* If: '<S477>/If1' */
      if (mcb_pmsm_foc_sensorless_dyno__B.ForIterator > 8U) {
        /* Outputs for IfAction SubSystem: '<S477>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S482>/Action Port'
         */
        mcb_pms_IfActionSubsystem_c(mcb_pmsm_foc_sensorless_dyno__B.ADC_A_IN1,
          mcb_pmsm_foc_sensorless_dyno__B.ADC_B_IN1,
          &mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem1_l,
          &mcb_pmsm_foc_sensorless_d_DWork.IfActionSubsystem1_l);

        /* End of Outputs for SubSystem: '<S477>/If Action Subsystem1' */
      }

      /* End of If: '<S477>/If1' */
    }

    /* End of Outputs for SubSystem: '<S475>/For Iterator Subsystem' */

    /* Product: '<S475>/Divide2' incorporates:
     *  Constant: '<S475>/Constant1'
     */
    mcb_pmsm_foc_sensorless_dyno__B.Divide2_h = (uint16_T)((real_T)
      mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem1_l.Sum / 8.0);

    /* If: '<S475>/If2' incorporates:
     *  Constant: '<S475>/Constant2'
     *  Constant: '<S475>/Constant3'
     */
    if ((mcb_pmsm_foc_sensorless_dyno__B.Divide2_h > 1500U) &&
        (mcb_pmsm_foc_sensorless_dyno__B.Divide2_h < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S475>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S478>/Action Port'
       */
      /* DataStoreWrite: '<S478>/Data Store Write1' */
      mcb_pmsm_foc_sensorless_d_DWork.IaOffset_motor2 =
        mcb_pmsm_foc_sensorless_dyno__B.Divide2_h;

      /* End of Outputs for SubSystem: '<S475>/If Action Subsystem4' */
    } else {
      /* Outputs for IfAction SubSystem: '<S475>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S479>/Action Port'
       */
      /* DataStoreWrite: '<S479>/Data Store Write1' incorporates:
       *  Constant: '<S479>/Constant'
       */
      mcb_pmsm_foc_sensorless_d_DWork.IaOffset_motor2 = 2295U;

      /* End of Outputs for SubSystem: '<S475>/If Action Subsystem5' */
    }

    /* End of If: '<S475>/If2' */

    /* Product: '<S475>/Divide3' incorporates:
     *  Constant: '<S475>/Constant1'
     */
    mcb_pmsm_foc_sensorless_dyno__B.Divide3 = (uint16_T)((real_T)
      mcb_pmsm_foc_sensorless_dyno__B.IfActionSubsystem1_l.Sum1 / 8.0);

    /* If: '<S475>/If3' incorporates:
     *  Constant: '<S475>/Constant2'
     *  Constant: '<S475>/Constant3'
     */
    if ((mcb_pmsm_foc_sensorless_dyno__B.Divide3 > 1500U) &&
        (mcb_pmsm_foc_sensorless_dyno__B.Divide3 < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S475>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S480>/Action Port'
       */
      /* DataStoreWrite: '<S480>/Data Store Write2' */
      mcb_pmsm_foc_sensorless_d_DWork.IbOffset_motor2 =
        mcb_pmsm_foc_sensorless_dyno__B.Divide3;

      /* End of Outputs for SubSystem: '<S475>/If Action Subsystem6' */
    } else {
      /* Outputs for IfAction SubSystem: '<S475>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S481>/Action Port'
       */
      /* DataStoreWrite: '<S481>/Data Store Write2' incorporates:
       *  Constant: '<S481>/Constant1'
       */
      mcb_pmsm_foc_sensorless_d_DWork.IbOffset_motor2 = 2286U;

      /* End of Outputs for SubSystem: '<S475>/If Action Subsystem7' */
    }

    /* End of If: '<S475>/If3' */
    /* End of Outputs for SubSystem: '<S465>/Calculate ADC Offset' */

    /* Logic: '<S465>/NOT' incorporates:
     *  Constant: '<S465>/ADC Calib Enable'
     */
    mcb_pmsm_foc_sensorless_dyno__B.NOT = false;

    /* Outputs for Enabled SubSystem: '<S465>/Default ADC Offset' incorporates:
     *  EnablePort: '<S476>/Enable'
     */
    if (mcb_pmsm_foc_sensorless_dyno__B.NOT) {
      /* DataStoreWrite: '<S476>/Data Store Write3' incorporates:
       *  Constant: '<S476>/Constant2'
       */
      mcb_pmsm_foc_sensorless_d_DWork.IaOffset_motor2 = 2295U;

      /* DataStoreWrite: '<S476>/Data Store Write4' incorporates:
       *  Constant: '<S476>/Constant3'
       */
      mcb_pmsm_foc_sensorless_d_DWork.IbOffset_motor2 = 2286U;
    }

    /* End of Outputs for SubSystem: '<S465>/Default ADC Offset' */
    /* End of Outputs for SubSystem: '<S463>/Calibrate ADC offset for motor 2 current sensor' */
    /* End of Outputs for SubSystem: '<Root>/Hardware Init' */
  }
}

/* Model terminate function */
void mcb_pmsm_foc_sensorless_dyno_f28379d_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Hardware Init' */
  /* Terminate for Atomic SubSystem: '<S463>/Enable DRV8305 for motor 1 and motor 2' */
  mcb__SPIMasterTransfer_Term(&mcb_pmsm_foc_sensorless_d_DWork.SPIMasterTransfer);
  mcb_SPIMasterTransfer2_Term
    (&mcb_pmsm_foc_sensorless_d_DWork.SPIMasterTransfer2);
  mcb__SPIMasterTransfer_Term
    (&mcb_pmsm_foc_sensorless_d_DWork.SPIMasterTransfer1);
  mcb_SPIMasterTransfer2_Term
    (&mcb_pmsm_foc_sensorless_d_DWork.SPIMasterTransfer3);

  /* End of Terminate for SubSystem: '<S463>/Enable DRV8305 for motor 1 and motor 2' */
  /* End of Terminate for SubSystem: '<Root>/Hardware Init' */
}

void mcb_pmsm_foc_sensorless_dyno_f28379d_configure_interrupts(void)
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

/* Hardware Interrupt Block: '<S14>/Hardware Interrupt' */
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
      tmp = mcb_pmsm_foc_sensorless_d_DWork.RT2_ActiveBufIdx << 1U;
      mcb_pmsm_foc_sensorless_dyno__B.RT2[0] =
        mcb_pmsm_foc_sensorless_d_DWork.RT2_Buffer[tmp];
      mcb_pmsm_foc_sensorless_dyno__B.RT2[1] =
        mcb_pmsm_foc_sensorless_d_DWork.RT2_Buffer[tmp + 1];

      /* RateTransition generated from: '<Root>/RT8' */
      tmp = mcb_pmsm_foc_sensorless_d_DWork.RT8_1_ActiveBufIdx * 6;
      for (i = 0; i < 6; i++) {
        mcb_pmsm_foc_sensorless_dyno__B.mtr2_VI_debug[i] =
          mcb_pmsm_foc_sensorless_d_DWork.RT8_1_Buffer[i + tmp];
      }

      /* RateTransition generated from: '<Root>/RT8' */
      mcb_pmsm_foc_sensorless_dyno__B.mtr2_Te_PU =
        mcb_pmsm_foc_sensorless_d_DWork.RT8_2_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RT8_2_ActiveBufIdx];

      /* RateTransition generated from: '<Root>/RT8' */
      mcb_pmsm_foc_sensorless_dyno__B.mtr2_Pm_PU =
        mcb_pmsm_foc_sensorless_d_DWork.RT8_3_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RT8_3_ActiveBufIdx];

      /* RateTransition generated from: '<Root>/RT8' */
      mcb_pmsm_foc_sensorless_dyno__B.mtr2_Speed_PU =
        mcb_pmsm_foc_sensorless_d_DWork.RT8_4_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RT8_4_ActiveBufIdx];

      /* RateTransition generated from: '<Root>/RT8' */
      tmp = mcb_pmsm_foc_sensorless_d_DWork.RT8_5_ActiveBufIdx << 1U;
      mcb_pmsm_foc_sensorless_dyno__B.mtr2_Iab_meas_PU[0] =
        mcb_pmsm_foc_sensorless_d_DWork.RT8_5_Buffer[tmp];
      mcb_pmsm_foc_sensorless_dyno__B.mtr2_Iab_meas_PU[1] =
        mcb_pmsm_foc_sensorless_d_DWork.RT8_5_Buffer[tmp + 1];

      /* RateTransition generated from: '<Root>/RT8' */
      mcb_pmsm_foc_sensorless_dyno__B.mtr2_Pos_PU =
        mcb_pmsm_foc_sensorless_d_DWork.RT8_6_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RT8_6_ActiveBufIdx];

      /* S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' */
      mcb_pmsm_FOCAlgorithmMotor1();

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT3' */
      mcb_pmsm_foc_sensorless_d_DWork.RT3_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RT3_semaphoreTaken
        == 0] = mcb_pmsm_foc_sensorless_dyno__B.OutportBufferForSpeed_fb;
      mcb_pmsm_foc_sensorless_d_DWork.RT3_ActiveBufIdx =
        (mcb_pmsm_foc_sensorless_d_DWork.RT3_semaphoreTaken == 0);
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

/* Hardware Interrupt Block: '<S16>/Hardware Interrupt' */
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

      /* RateTransition: '<Root>/RT6' */
      i = mcb_pmsm_foc_sensorless_d_DWork.RT6_ActiveBufIdx << 1U;
      mcb_pmsm_foc_sensorless_dyno__B.RT6[0] =
        mcb_pmsm_foc_sensorless_d_DWork.RT6_Buffer[i];
      mcb_pmsm_foc_sensorless_dyno__B.RT6[1] =
        mcb_pmsm_foc_sensorless_d_DWork.RT6_Buffer[i + 1];

      /* S-Function (HardwareInterrupt_sfun): '<S16>/Hardware Interrupt' */
      mcb_pmsm_FOCAlgorithmMotor2();

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S16>/Hardware Interrupt' */

      /* RateTransition generated from: '<Root>/RT8' */
      for (i = 0; i < 6; i++) {
        mcb_pmsm_foc_sensorless_d_DWork.RT8_1_Buffer[i +
          (mcb_pmsm_foc_sensorless_d_DWork.RT8_1_ActiveBufIdx == 0) * 6] =
          mcb_pmsm_foc_sensorless_dyno__B.mtr2_VI_debug_k[i];
      }

      mcb_pmsm_foc_sensorless_d_DWork.RT8_1_ActiveBufIdx =
        (mcb_pmsm_foc_sensorless_d_DWork.RT8_1_ActiveBufIdx == 0);

      /* RateTransition generated from: '<Root>/RT8' */
      mcb_pmsm_foc_sensorless_d_DWork.RT8_2_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RT8_2_ActiveBufIdx
        == 0] = mcb_pmsm_foc_sensorless_dyno__B.mtr2_Te_PU_i;
      mcb_pmsm_foc_sensorless_d_DWork.RT8_2_ActiveBufIdx =
        (mcb_pmsm_foc_sensorless_d_DWork.RT8_2_ActiveBufIdx == 0);

      /* RateTransition generated from: '<Root>/RT8' */
      mcb_pmsm_foc_sensorless_d_DWork.RT8_3_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RT8_3_ActiveBufIdx
        == 0] = mcb_pmsm_foc_sensorless_dyno__B.mtr2_Pm_PU_m;
      mcb_pmsm_foc_sensorless_d_DWork.RT8_3_ActiveBufIdx =
        (mcb_pmsm_foc_sensorless_d_DWork.RT8_3_ActiveBufIdx == 0);

      /* RateTransition generated from: '<Root>/RT8' */
      mcb_pmsm_foc_sensorless_d_DWork.RT8_4_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RT8_4_ActiveBufIdx
        == 0] = mcb_pmsm_foc_sensorless_dyno__B.mtr2_Speed_PU_h;
      mcb_pmsm_foc_sensorless_d_DWork.RT8_4_ActiveBufIdx =
        (mcb_pmsm_foc_sensorless_d_DWork.RT8_4_ActiveBufIdx == 0);

      /* RateTransition generated from: '<Root>/RT8' */
      mcb_pmsm_foc_sensorless_d_DWork.RT8_5_Buffer
        [(mcb_pmsm_foc_sensorless_d_DWork.RT8_5_ActiveBufIdx == 0) << 1U] =
        mcb_pmsm_foc_sensorless_dyno__B.mtr2_Iab_meas_PU_j[0];
      mcb_pmsm_foc_sensorless_d_DWork.RT8_5_Buffer[1 +
        ((mcb_pmsm_foc_sensorless_d_DWork.RT8_5_ActiveBufIdx == 0) << 1U)] =
        mcb_pmsm_foc_sensorless_dyno__B.mtr2_Iab_meas_PU_j[1];
      mcb_pmsm_foc_sensorless_d_DWork.RT8_5_ActiveBufIdx =
        (mcb_pmsm_foc_sensorless_d_DWork.RT8_5_ActiveBufIdx == 0);

      /* RateTransition generated from: '<Root>/RT8' */
      mcb_pmsm_foc_sensorless_d_DWork.RT8_6_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RT8_6_ActiveBufIdx
        == 0] = mcb_pmsm_foc_sensorless_dyno__B.mtr2_Pos_PU_d;
      mcb_pmsm_foc_sensorless_d_DWork.RT8_6_ActiveBufIdx =
        (mcb_pmsm_foc_sensorless_d_DWork.RT8_6_ActiveBufIdx == 0);
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

/* Hardware Interrupt Block: '<S18>/Hardware Interrupt' */
interrupt void SCIA_RX_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S18>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Serial Receive' */

      /* S-Function (c28xsci_rx): '<S554>/SCI Receive' */
      {
        int16_T i;
        int16_T errFlg = NOERROR;
        uint16_T isHeadReceived = 1U;

        //get data as uint16 in recBuff
        uint16_T recbuff[6];
        for (i = 0; i < 6; i++) {
          recbuff[i] = 0U;
        }

        errFlg = NOERROR;

        /* Receiving data: For uint32 and uint16, rcvBuff will contain uint16 data */
        if (isHeadReceived) {
          errFlg = scia_rcv(recbuff, 12, 4);
          asm(" NOP");
          if ((errFlg == NOERROR) || (errFlg == PARTIALDATA)) {
            memcpy( &mcb_pmsm_foc_sensorless_dyno__B.SCIReceive[0], recbuff,6);
          }
        }
      }

      /* DataTypeConversion: '<S552>/Data Type Conversion2' */
      mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion2 = (uint16_T)
        mcb_pmsm_foc_sensorless_dyno__B.SCIReceive[1];

      /* S-Function (sfix_bitop): '<S551>/Bitwise Operator' */
      mcb_pmsm_foc_sensorless_dyno__B.BitwiseOperator =
        mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion2 & 1U;

      /* DataTypeConversion: '<S551>/Data Type Conversion3' */
      mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion3 =
        (mcb_pmsm_foc_sensorless_dyno__B.BitwiseOperator != 0U);

      /* DataStoreWrite: '<S548>/Data Store Write' */
      mcb_pmsm_foc_sensorless_d_DWork.Enable =
        mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion3;

      /* DataStoreWrite: '<S548>/Data Store Write1' */
      mcb_pmsm_foc_sensorless_d_DWork.SpeedRef =
        mcb_pmsm_foc_sensorless_dyno__B.SCIReceive[0];

      /* S-Function (sfix_bitop): '<S551>/Bitwise Operator1' */
      mcb_pmsm_foc_sensorless_dyno__B.BitwiseOperator1 =
        mcb_pmsm_foc_sensorless_dyno__B.DataTypeConversion2 & 240U;

      /* ArithShift: '<S551>/Shift Arithmetic1' incorporates:
       *  S-Function (sfix_bitop): '<S551>/Bitwise Operator1'
       */
      mcb_pmsm_foc_sensorless_dyno__B.ShiftArithmetic1 =
        mcb_pmsm_foc_sensorless_dyno__B.BitwiseOperator1 >> 4U;

      /* DataStoreWrite: '<S548>/Data Store Write2' */
      mcb_pmsm_foc_sensorless_d_DWork.Debug_signals =
        mcb_pmsm_foc_sensorless_dyno__B.ShiftArithmetic1;

      /* SignalConversion generated from: '<S7>/Desried Iq ref' */
      mcb_pmsm_foc_sensorless_dyno__B.OutportBufferForDesriedIqref =
        mcb_pmsm_foc_sensorless_dyno__B.SCIReceive[2];

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S18>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT' */
      mcb_pmsm_foc_sensorless_d_DWork.RT_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RT_ActiveBufIdx
        == 0] = mcb_pmsm_foc_sensorless_dyno__B.SCIReceive[0];
      mcb_pmsm_foc_sensorless_d_DWork.RT_ActiveBufIdx =
        (mcb_pmsm_foc_sensorless_d_DWork.RT_ActiveBufIdx == 0);

      /* RateTransition: '<Root>/Rate Transition3' */
      mcb_pmsm_foc_sensorless_d_DWork.RateTransition3_Buffer[mcb_pmsm_foc_sensorless_d_DWork.RateTransition3_ActiveBufIdx
        == 0] = mcb_pmsm_foc_sensorless_dyno__B.OutportBufferForDesriedIqref;
      mcb_pmsm_foc_sensorless_d_DWork.RateTransition3_ActiveBufIdx =
        (mcb_pmsm_foc_sensorless_d_DWork.RateTransition3_ActiveBufIdx == 0);
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

void mcb_pmsm_foc_sensorless_dyno_f28379d_unconfigure_interrupts (void)
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
