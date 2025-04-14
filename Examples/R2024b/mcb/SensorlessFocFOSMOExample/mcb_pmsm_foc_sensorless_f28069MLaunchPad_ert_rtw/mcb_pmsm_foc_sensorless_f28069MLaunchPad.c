/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_sensorless_f28069MLaunchPad.c
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_sensorless_f28069MLaunchPad'.
 *
 * Model version                  : 9.18
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Apr  2 15:33:15 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcb_pmsm_foc_sensorless_f28069MLaunchPad.h"
#include "rtwtypes.h"
#include "mcb_pmsm_foc_sensorless_f28069MLaunchPad_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#include <string.h>
#define mcb__IN_TransferToNegClosedLoop (4U)
#define mcb__IN_TransferToPosClosedLoop (5U)
#define mcb_p_IN_TransferToOpenLoop_NEG (5U)
#define mcb_pmsm__IN_PrepareNegCLSwitch (3U)
#define mcb_pmsm__IN_PreparePosCLSwitch (3U)
#define mcb_pmsm__IN_TransferToOpenLoop (4U)
#define mcb_pmsm_f_IN_ClosedLoopRun_NEG (1U)
#define mcb_pmsm_fo_IN_ClosedLoopPosRun (1U)
#define mcb_pmsm_fo_IN_NegativeSpeedRun (2U)
#define mcb_pmsm_fo_IN_PositiveSpeedRun (3U)
#define mcb_pmsm_foc_IN_InitOpenLoopRun (1U)
#define mcb_pmsm_foc_IN_NO_ACTIVE_CHILD (0U)
#define mcb_pmsm_foc__IN_OpenLoopNegRun (2U)
#define mcb_pmsm_foc__IN_OpenLoopPosRun (2U)
#define mcb_pmsm_foc_sensorl_IN_RunMode (2U)
#define mcb_pmsm_foc_sensorless_IN_Halt (1U)

/* Block signals (default storage) */
BlockIO_mcb_pmsm_foc_sensorless mcb_pmsm_foc_sensorless_f2806_B;

/* Block states (default storage) */
D_Work_mcb_pmsm_foc_sensorless_ mcb_pmsm_foc_sensorless_f_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_mcb_pmsm_foc_se mcb_pmsm_foc_sen_PrevZCSigState;

/* Real-time model */
static RT_MODEL_mcb_pmsm_foc_sensorles mcb_pmsm_foc_sensorless_f280_M_;
RT_MODEL_mcb_pmsm_foc_sensorles *const mcb_pmsm_foc_sensorless_f280_M =
  &mcb_pmsm_foc_sensorless_f280_M_;
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcInitFlag = 0;

#endif

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void mcb_pmsm_foc_sensorless_f28069MLaunchPad_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_sensorless_f280_M, 1));
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
  (mcb_pmsm_foc_sensorless_f280_M->Timing.TaskCounters.TID[1])++;
  if ((mcb_pmsm_foc_sensorless_f280_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [0.5s, 0.0s] */
    mcb_pmsm_foc_sensorless_f280_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S23>/Two phase CRL wrap'
 *    '<S393>/Two phase CRL wrap'
 */
void mcb_pmsm_fo_TwophaseCRLwrap(real32_T rtu_a, real32_T rtu_b,
  rtB_TwophaseCRLwrap_mcb_pmsm_fo *localB)
{
  /* Sum: '<S24>/a_plus_2b' */
  localB->a_plus_2b = (rtu_a + rtu_b) + rtu_b;

  /* Gain: '<S24>/one_by_sqrt3' */
  localB->one_by_sqrt3 = 0.577350259F * localB->a_plus_2b;

  /* AlgorithmDescriptorDelegate generated from: '<S24>/a16' */
  localB->algDD_o1 = rtu_a;

  /* AlgorithmDescriptorDelegate generated from: '<S24>/a16' */
  localB->algDD_o2 = localB->one_by_sqrt3;
}

/*
 * Output and update for atomic system:
 *    '<S20>/Two inputs CRL'
 *    '<S390>/Two inputs CRL'
 *    '<S392>/Two inputs CRL'
 */
void mcb_pmsm_foc_s_TwoinputsCRL(real32_T rtu_Alpha, real32_T rtu_Beta, real32_T
  rtu_sine, real32_T rtu_cos, rtB_TwoinputsCRL_mcb_pmsm_foc_s *localB)
{
  /* Product: '<S52>/acos' */
  localB->acos_a = rtu_Alpha * rtu_cos;

  /* Product: '<S52>/bsin' */
  localB->bsin = rtu_Beta * rtu_sine;

  /* Sum: '<S52>/sum_Ds' */
  localB->sum_Ds = localB->acos_a + localB->bsin;

  /* Product: '<S52>/bcos' */
  localB->bcos = rtu_Beta * rtu_cos;

  /* Product: '<S52>/asin' */
  localB->asin_p = rtu_Alpha * rtu_sine;

  /* Sum: '<S52>/sum_Qs' */
  localB->sum_Qs = localB->bcos - localB->asin_p;

  /* Switch: '<S53>/Switch' */
  localB->Switch[0] = localB->sum_Ds;
  localB->Switch[1] = localB->sum_Qs;

  /* AlgorithmDescriptorDelegate generated from: '<S52>/a16' */
  localB->algDD_o1 = localB->Switch[0];

  /* AlgorithmDescriptorDelegate generated from: '<S52>/a16' */
  localB->algDD_o2 = localB->Switch[1];
}

/*
 * Output and update for action system:
 *    '<S56>/If Action Subsystem'
 *    '<S226>/If Action Subsystem'
 *    '<S399>/If Action Subsystem'
 */
void mcb_pmsm__IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem_mcb_pmsm_ *localB)
{
  /* DataTypeConversion: '<S59>/Convert_uint16' */
  localB->Convert_uint16 = (int16_T)(real32_T)floor(rtu_In1);

  /* DataTypeConversion: '<S59>/Convert_back' */
  localB->Convert_back = localB->Convert_uint16;

  /* Sum: '<S59>/Sum' */
  *rty_Out1 = rtu_In1 - localB->Convert_back;
}

/*
 * Output and update for action system:
 *    '<S56>/If Action Subsystem1'
 *    '<S226>/If Action Subsystem1'
 *    '<S399>/If Action Subsystem1'
 */
void mcb_pmsm_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem1_mcb_pmsm *localB)
{
  /* DataTypeConversion: '<S60>/Convert_uint16' */
  localB->Convert_uint16 = (int16_T)rtu_In1;

  /* DataTypeConversion: '<S60>/Convert_back' */
  localB->Convert_back = localB->Convert_uint16;

  /* Sum: '<S60>/Sum' */
  *rty_Out1 = rtu_In1 - localB->Convert_back;
}

/*
 * Output and update for trigger system:
 *    '<S272>/Dir_Sense'
 *    '<S100>/Dir_Sense'
 */
void mcb_pmsm_foc_sens_Dir_Sense(boolean_T rtu_A, boolean_T rtu_B,
  rtB_Dir_Sense_mcb_pmsm_foc_sens *localB, rtZCE_Dir_Sense_mcb_pmsm_foc_se
  *localZCE)
{
  boolean_T zcEvent;

  /* Outputs for Triggered SubSystem: '<S272>/Dir_Sense' incorporates:
   *  TriggerPort: '<S280>/Trigger'
   */
  zcEvent = (rtu_A && (localZCE->Dir_Sense_Trig_ZCE != POS_ZCSIG));
  if (zcEvent) {
    /* Logic: '<S280>/Logical Operator' */
    localB->LogicalOperator = (rtu_A && rtu_B);

    /* Switch: '<S280>/Switch' */
    if (localB->LogicalOperator) {
      /* Switch: '<S280>/Switch' incorporates:
       *  Constant: '<S280>/Constant'
       */
      localB->Switch = -1;
    } else {
      /* Switch: '<S280>/Switch' incorporates:
       *  Constant: '<S280>/Constant1'
       */
      localB->Switch = 1;
    }

    /* End of Switch: '<S280>/Switch' */
  }

  localZCE->Dir_Sense_Trig_ZCE = rtu_A;

  /* End of Outputs for SubSystem: '<S272>/Dir_Sense' */
}

/*
 * Output and update for action system:
 *    '<S272>/Subsystem2'
 *    '<S100>/Subsystem2'
 */
void mcb_pmsm_foc_sen_Subsystem2(real32_T rtu_SigmaAlpha, real32_T rtu_SigmaBeta,
  real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* UnaryMinus: '<S281>/Unary Minus' */
  *rty_Out1 = -rtu_SigmaAlpha;

  /* SignalConversion generated from: '<S281>/SigmaBeta' */
  *rty_Out2 = rtu_SigmaBeta;
}

/* System initialize for function-call system: '<Root>/Current Control' */
void mcb_pms_CurrentControl_Init(void)
{
  /* Start for S-Function (c2802xadc): '<S76>/IA//IB Measurement' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC0_SOC1 ();

  /* Start for S-Function (c280xgpio_do): '<S298>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPBMUX2.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x40000U;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S298>/ePWM1' */
  real32_T tbprdValue1 = (real32_T)EPwm1Regs.TBPRD;

  /*** Initialize ePWM1 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 1U;          -- Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          -- Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x12U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 2250U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm1Regs.TBPHS.half.TBPHS               = 0U;         -- Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm1Regs.CMPA.half.CMPA = 1126U;  // Counter Compare A Register
    EPwm1Regs.CMPB = 1126U;            // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 264U;
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
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x803FU) | 0xBU;
    EPwm1Regs.DBRED = 15U;
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED = 15U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          -- Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCAPRD               = 1U;          -- EPWM1SOCA Period Select
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion B Select
       EPwm1Regs.ETPS.bit.SOCBPRD               = 1U;          -- EPWM1SOCB Period Select
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          -- EPWM1INTn Select
       EPwm1Regs.ETPS.bit.INTPRD                = 1U;          -- EPWM1INTn Period Select
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0FU) | 0x1A01U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303U) | 0x1101U;

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
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 0U;          -- DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x0U;

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
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S298>/ePWM2' */
  real32_T tbprdValue2 = (real32_T)EPwm2Regs.TBPRD;

  /*** Initialize ePWM2 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 2250U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm2Regs.TBPHS.half.TBPHS               = 0U;         -- Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm2Regs.CMPA.half.CMPA = 1126U;  // Counter Compare A Register
    EPwm2Regs.CMPB = 1126U;            // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 264U;
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
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x803FU) | 0xBU;
    EPwm2Regs.DBRED = 15U;
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED = 15U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASEL              = 0U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCAPRD               = 1U;          -- EPWM2SOCA Period Select
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion B Select
       EPwm2Regs.ETPS.bit.SOCBPRD               = 1U;          -- EPWM2SOCB Period Select
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          -- EPWM2INTn Select
       EPwm2Regs.ETPS.bit.INTPRD                = 1U;          -- EPWM2INTn Period Select
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0FU) | 0x1001U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x3303U) | 0x1101U;

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
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S298>/ePWM3' */
  real32_T tbprdValue3 = (real32_T)EPwm3Regs.TBPRD;

  /*** Initialize ePWM3 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL             = 3U;          -- Sync Output Select

       EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm3Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm3Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x2036U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 2250U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm3Regs.TBPHS.half.TBPHS               = 0U;         -- Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm3Regs.CMPA.half.CMPA = 1126U;  // Counter Compare A Register
    EPwm3Regs.CMPB = 1126U;            // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm3Regs.AQCTLB.all = 264U;
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
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x803FU) | 0xBU;
    EPwm3Regs.DBRED = 15U;
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm3Regs.DBFED = 15U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASEL              = 0U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCAPRD               = 1U;          -- EPWM3SOCA Period Select
       EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion B Select
       EPwm3Regs.ETPS.bit.SOCBPRD               = 1U;          -- EPWM3SOCB Period Select
       EPwm3Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          -- EPWM3INTn Select
       EPwm3Regs.ETPS.bit.INTPRD                = 1U;          -- EPWM3INTn Period Select
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF0FU) | 0x1001U;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x3303U) | 0x1101U;

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
    EDIS;
  }

  /* InitializeConditions for Delay: '<S19>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.icLoad = true;

  /* SystemInitialize for MATLAB Function: '<S26>/MATLAB Function' */
  mcb_pmsm_foc_sensorless_f_DWork.integrator_state_a = 0.0F;

  /* SystemInitialize for MATLAB Function: '<S27>/MATLAB Function' */
  mcb_pmsm_foc_sensorless_f_DWork.integrator_state = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S78>/Extended EMF Observer' */
  /* InitializeConditions for Delay: '<S82>/Delay1' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S219>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S151>/Integrator' */
  mcb_pmsm_foc_sensorless_f_DWork.Integrator_PrevResetState = 0;

  /* SystemInitialize for IfAction SubSystem: '<S108>/DifferentiationMethod' */
  /* InitializeConditions for Delay: '<S173>/Delay2' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay2_DSTATE_c = 0.0F;

  /* InitializeConditions for Delay: '<S173>/Delay3' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay3_DSTATE_d = 0.0F;

  /* InitializeConditions for Delay: '<S174>/Delay2' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay2_DSTATE_p = 0.0F;

  /* InitializeConditions for Delay: '<S174>/Delay3' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay3_DSTATE_ds = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S108>/DifferentiationMethod' */

  /* SystemInitialize for IfAction SubSystem: '<S108>/IntegralMethod' */
  /* InitializeConditions for Delay: '<S198>/Delay1' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_o = 0.0F;

  /* InitializeConditions for Delay: '<S198>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_ao = 0.0F;

  /* InitializeConditions for Delay: '<S199>/Delay1' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_n = 0.0F;

  /* InitializeConditions for Delay: '<S199>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_oe = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S108>/IntegralMethod' */

  /* SystemInitialize for IfAction SubSystem: '<S108>/OptimizedDifferentiationMethod' */
  /* InitializeConditions for Delay: '<S206>/Delay2' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay2_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S206>/Delay3' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay3_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S207>/Delay2' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay2_DSTATE_i = 0.0F;

  /* InitializeConditions for Delay: '<S207>/Delay3' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay3_DSTATE_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S108>/OptimizedDifferentiationMethod' */

  /* SystemInitialize for Merge: '<S108>/Merge' */
  mcb_pmsm_foc_sensorless_f2806_B.Merge_i = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S78>/Extended EMF Observer' */

  /* SystemInitialize for IfAction SubSystem: '<S78>/Flux Observer' */
  /* InitializeConditions for Delay: '<S261>/Delay1' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_e = 0.0F;

  /* InitializeConditions for Delay: '<S261>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_m = 0.0F;

  /* InitializeConditions for Delay: '<S253>/Delay1' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_m = 0.0F;

  /* InitializeConditions for Delay: '<S253>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_p = 0.0F;

  /* InitializeConditions for Delay: '<S235>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.CircBufIdx = 0U;

  /* End of SystemInitialize for SubSystem: '<S78>/Flux Observer' */

  /* SystemInitialize for IfAction SubSystem: '<S78>/Sliding Mode Observer' */
  /* InitializeConditions for Delay: '<S273>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_nd = 0.0F;

  /* InitializeConditions for Delay: '<S283>/Delay1' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_l = 0.0F;

  /* InitializeConditions for Delay: '<S274>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_e = 0.0F;

  /* InitializeConditions for Delay: '<S284>/Delay1' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_j = 0.0F;

  /* InitializeConditions for Delay: '<S271>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_nm = 0.0F;

  /* InitializeConditions for Delay: '<S278>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.CircBufIdx_n = 0U;

  /* End of SystemInitialize for SubSystem: '<S78>/Sliding Mode Observer' */

  /* SystemInitialize for IfAction SubSystem: '<S78>/Extended EMF Observer' */
  /* InitializeConditions for Delay: '<S83>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_o[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S78>/Extended EMF Observer' */

  /* SystemInitialize for Merge: '<S78>/Merge' */
  mcb_pmsm_foc_sensorless_f2806_B.Merge_k[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S78>/Extended EMF Observer' */
  /* InitializeConditions for Delay: '<S83>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_o[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S78>/Extended EMF Observer' */

  /* SystemInitialize for Merge: '<S78>/Merge' */
  mcb_pmsm_foc_sensorless_f2806_B.Merge_k[1] = 0.0F;
}

/* System reset for function-call system: '<Root>/Current Control' */
void mcb_pm_CurrentControl_Reset(void)
{
  /* InitializeConditions for Delay: '<S19>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.icLoad = true;

  /* SystemReset for MATLAB Function: '<S27>/MATLAB Function' */
  mcb_pmsm_foc_sensorless_f_DWork.integrator_state = 0.0F;

  /* SystemReset for MATLAB Function: '<S26>/MATLAB Function' */
  mcb_pmsm_foc_sensorless_f_DWork.integrator_state_a = 0.0F;
}

/* Output and update for function-call system: '<Root>/Current Control' */
#pragma CODE_SECTION (mcb_pmsm_foc_CurrentControl, "ramfuncs")

void mcb_pmsm_foc_CurrentControl(void)
{
  int32_T Q17perunitconversion;
  real32_T Product_am;
  real32_T UnitDelay_a;
  real32_T V_q_ref_unsat;
  uint32_T Sum_k;
  int16_T s300_iter;
  uint16_T Data;
  boolean_T zcEvent;

  /* DataStoreRead: '<S77>/Data Store Read' */
  mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead_m =
    mcb_pmsm_foc_sensorless_f_DWork.IaOffset;

  /* DataStoreRead: '<S77>/Data Store Read1' */
  mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1_p =
    mcb_pmsm_foc_sensorless_f_DWork.IbOffset;

  /* S-Function (c2802xadc): '<S76>/IA//IB Measurement' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_sensorless_f2806_B.IAIBMeasurement_k[0] = (AdcResult.ADCRESULT0);
    mcb_pmsm_foc_sensorless_f2806_B.IAIBMeasurement_k[1] = (AdcResult.ADCRESULT1);
  }

  /* DataTypeConversion: '<S77>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_ch[0] =
    mcb_pmsm_foc_sensorless_f2806_B.IAIBMeasurement_k[0];
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_ch[1] =
    mcb_pmsm_foc_sensorless_f2806_B.IAIBMeasurement_k[1];

  /* Sum: '<S77>/Add' */
  mcb_pmsm_foc_sensorless_f2806_B.Add_k[0] =
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_ch[0] -
    mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead_m;
  mcb_pmsm_foc_sensorless_f2806_B.Add_k[1] =
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_ch[1] -
    mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1_p;

  /* ArithShift: '<S77>/Q17 per unit conversion' incorporates:
   *  Sum: '<S77>/Add'
   */
  Q17perunitconversion = mcb_pmsm_foc_sensorless_f2806_B.Add_k[0] << 6U;
  mcb_pmsm_foc_sensorless_f2806_B.Q17perunitconversion[0] = Q17perunitconversion;

  /* DataTypeConversion: '<S77>/Data Type Conversion1' incorporates:
   *  ArithShift: '<S77>/Q17 per unit conversion'
   */
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_p[0] = (real32_T)
    Q17perunitconversion * 7.62939453E-6F;

  /* ArithShift: '<S77>/Q17 per unit conversion' incorporates:
   *  Sum: '<S77>/Add'
   */
  Q17perunitconversion = mcb_pmsm_foc_sensorless_f2806_B.Add_k[1] << 6U;
  mcb_pmsm_foc_sensorless_f2806_B.Q17perunitconversion[1] = Q17perunitconversion;

  /* DataTypeConversion: '<S77>/Data Type Conversion1' incorporates:
   *  ArithShift: '<S77>/Q17 per unit conversion'
   */
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_p[1] = (real32_T)
    Q17perunitconversion * 7.62939453E-6F;

  /* DataStoreWrite: '<S9>/Data Store Write' */
  mcb_pmsm_foc_sensorless_f_DWork.Ia_meas_PU =
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_p[0];

  /* Switch: '<S30>/Switch1' incorporates:
   *  Constant: '<S30>/ChosenMethod'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Switch1_fg = 3U;

  /* Outputs for Atomic SubSystem: '<S23>/Two phase CRL wrap' */
  mcb_pmsm_fo_TwophaseCRLwrap
    (mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_p[0],
     mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_p[1],
     &mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap);

  /* End of Outputs for SubSystem: '<S23>/Two phase CRL wrap' */

  /* Delay: '<S1>/Delay5' */
  mcb_pmsm_foc_sensorless_f2806_B.Delay5[0] =
    mcb_pmsm_foc_sensorless_f_DWork.Delay5_DSTATE[0];
  mcb_pmsm_foc_sensorless_f2806_B.Delay5[1] =
    mcb_pmsm_foc_sensorless_f_DWork.Delay5_DSTATE[1];
  mcb_pmsm_foc_sensorless_f2806_B.Delay5[2] =
    mcb_pmsm_foc_sensorless_f_DWork.Delay5_DSTATE[2];
  mcb_pmsm_foc_sensorless_f2806_B.Delay5[3] =
    mcb_pmsm_foc_sensorless_f_DWork.Delay5_DSTATE[3];

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  Constant: '<S236>/FilterConstant'
   *  Constant: '<S236>/OneMinusFilterConstant'
   *  Product: '<S239>/Product'
   *  Switch: '<S236>/Switch1'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Switch1_dz[0] = 0.0005F;
  mcb_pmsm_foc_sensorless_f2806_B.Switch1_dz[1] = 0.9995F;
  V_q_ref_unsat = mcb_pmsm_foc_sensorless_f2806_B.Delay5[0];
  Product_am = V_q_ref_unsat * 0.0005F;

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* Product: '<S239>/Product' */
  mcb_pmsm_foc_sensorless_f2806_B.Product_am[0] = Product_am;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  UnitDelay: '<S239>/Unit Delay'
   */
  UnitDelay_a = mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_d5[0];

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* UnitDelay: '<S239>/Unit Delay' */
  mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_a[0] = UnitDelay_a;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  Product: '<S239>/Product1'
   */
  UnitDelay_a *= 0.9995F;

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* Product: '<S239>/Product1' */
  mcb_pmsm_foc_sensorless_f2806_B.Product1_j[0] = UnitDelay_a;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  Sum: '<S239>/Add1'
   */
  Product_am += UnitDelay_a;

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* Sum: '<S239>/Add1' */
  mcb_pmsm_foc_sensorless_f2806_B.Add1_jy[0] = Product_am;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  Product: '<S239>/Product'
   *  Sum: '<S238>/Sum'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[0] = V_q_ref_unsat - Product_am;
  V_q_ref_unsat = mcb_pmsm_foc_sensorless_f2806_B.Delay5[1];
  Product_am = V_q_ref_unsat * 0.0005F;

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* Product: '<S239>/Product' */
  mcb_pmsm_foc_sensorless_f2806_B.Product_am[1] = Product_am;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  UnitDelay: '<S239>/Unit Delay'
   */
  UnitDelay_a = mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_d5[1];

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* UnitDelay: '<S239>/Unit Delay' */
  mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_a[1] = UnitDelay_a;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  Product: '<S239>/Product1'
   */
  UnitDelay_a *= 0.9995F;

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* Product: '<S239>/Product1' */
  mcb_pmsm_foc_sensorless_f2806_B.Product1_j[1] = UnitDelay_a;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  Sum: '<S239>/Add1'
   */
  Product_am += UnitDelay_a;

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* Sum: '<S239>/Add1' */
  mcb_pmsm_foc_sensorless_f2806_B.Add1_jy[1] = Product_am;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  Product: '<S239>/Product'
   *  Sum: '<S238>/Sum'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[1] = V_q_ref_unsat - Product_am;
  V_q_ref_unsat = mcb_pmsm_foc_sensorless_f2806_B.Delay5[2];
  Product_am = V_q_ref_unsat * 0.0005F;

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* Product: '<S239>/Product' */
  mcb_pmsm_foc_sensorless_f2806_B.Product_am[2] = Product_am;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  UnitDelay: '<S239>/Unit Delay'
   */
  UnitDelay_a = mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_d5[2];

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* UnitDelay: '<S239>/Unit Delay' */
  mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_a[2] = UnitDelay_a;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  Product: '<S239>/Product1'
   */
  UnitDelay_a *= 0.9995F;

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* Product: '<S239>/Product1' */
  mcb_pmsm_foc_sensorless_f2806_B.Product1_j[2] = UnitDelay_a;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  Sum: '<S239>/Add1'
   */
  Product_am += UnitDelay_a;

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* Sum: '<S239>/Add1' */
  mcb_pmsm_foc_sensorless_f2806_B.Add1_jy[2] = Product_am;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  Product: '<S239>/Product'
   *  Sum: '<S238>/Sum'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[2] = V_q_ref_unsat - Product_am;
  V_q_ref_unsat = mcb_pmsm_foc_sensorless_f2806_B.Delay5[3];
  Product_am = V_q_ref_unsat * 0.0005F;

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* Product: '<S239>/Product' */
  mcb_pmsm_foc_sensorless_f2806_B.Product_am[3] = Product_am;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  UnitDelay: '<S239>/Unit Delay'
   */
  UnitDelay_a = mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_d5[3];

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* UnitDelay: '<S239>/Unit Delay' */
  mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_a[3] = UnitDelay_a;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  Product: '<S239>/Product1'
   */
  UnitDelay_a *= 0.9995F;

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* Product: '<S239>/Product1' */
  mcb_pmsm_foc_sensorless_f2806_B.Product1_j[3] = UnitDelay_a;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  Sum: '<S239>/Add1'
   */
  Product_am += UnitDelay_a;

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* Sum: '<S239>/Add1' */
  mcb_pmsm_foc_sensorless_f2806_B.Add1_jy[3] = Product_am;

  /* Outputs for IfAction SubSystem: '<S78>/Flux Observer' incorporates:
   *  ActionPort: '<S80>/Action Port'
   */
  /* SwitchCase: '<S78>/Switch Case' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S248>/a16'
   *  Constant: '<S234>/FilterConstant'
   *  Constant: '<S234>/OneMinusFilterConstant'
   *  Constant: '<S243>/p1'
   *  Constant: '<S243>/p2'
   *  Constant: '<S243>/p3'
   *  Constant: '<S243>/p4'
   *  Constant: '<S243>/p5'
   *  Constant: '<S252>/One'
   *  Constant: '<S260>/One'
   *  DataStoreRead: '<S80>/Data Store Read1'
   *  DataTypeConversion: '<S270>/DTC'
   *  Delay: '<S235>/Delay'
   *  Delay: '<S253>/Delay'
   *  Delay: '<S253>/Delay1'
   *  Delay: '<S261>/Delay'
   *  Delay: '<S261>/Delay1'
   *  Gain: '<S235>/PositionToCount'
   *  Gain: '<S235>/SpeedGain'
   *  Gain: '<S249>/Gain'
   *  Gain: '<S80>/elect2mech'
   *  Logic: '<S80>/Logical Operator'
   *  Merge: '<S78>/Merge'
   *  Product: '<S253>/Product'
   *  Product: '<S253>/Product1'
   *  Product: '<S254>/Product'
   *  Product: '<S254>/Product2'
   *  Product: '<S257>/Product'
   *  Product: '<S257>/Product1'
   *  Product: '<S261>/Product'
   *  Product: '<S261>/Product1'
   *  Product: '<S262>/Product'
   *  Product: '<S262>/Product2'
   *  Product: '<S265>/Product'
   *  Product: '<S265>/Product1'
   *  Product: '<S268>/Product'
   *  Product: '<S268>/Product1'
   *  SignalConversion generated from: '<S80>/Position//Speed'
   *  Sum: '<S235>/SpeedCount'
   *  Sum: '<S238>/Sum'
   *  Sum: '<S251>/Sum1'
   *  Sum: '<S251>/Sum3'
   *  Sum: '<S252>/Sum'
   *  Sum: '<S253>/Sum'
   *  Sum: '<S253>/Sum1'
   *  Sum: '<S257>/Add1'
   *  Sum: '<S259>/Sum1'
   *  Sum: '<S259>/Sum3'
   *  Sum: '<S260>/Sum'
   *  Sum: '<S261>/Sum'
   *  Sum: '<S261>/Sum1'
   *  Sum: '<S265>/Add1'
   *  Sum: '<S268>/Add1'
   *  Switch: '<S234>/Switch1'
   *  Switch: '<S248>/Switch'
   *  Switch: '<S249>/Switch'
   *  Switch: '<S250>/Switch'
   *  Switch: '<S252>/Switch1'
   *  Switch: '<S258>/Switch'
   *  Switch: '<S260>/Switch1'
   *  Trigonometry: '<S248>/Atan2'
   *  UnitDelay: '<S239>/Unit Delay'
   *  UnitDelay: '<S257>/Unit Delay'
   *  UnitDelay: '<S265>/Unit Delay'
   *  UnitDelay: '<S268>/Unit Delay'
   * */
  mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[3] = V_q_ref_unsat - Product_am;
  mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1_c =
    mcb_pmsm_foc_sensorless_f_DWork.Enable;
  mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed =
    !mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1_c;
  mcb_pmsm_foc_sensorless_f2806_B.Product_c =
    mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[3] * 0.170112133F;
  mcb_pmsm_foc_sensorless_f2806_B.Sum3_k =
    mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[1] -
    mcb_pmsm_foc_sensorless_f2806_B.Product_c;
  zcEvent = (((mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_e == POS_ZCSIG)
              != (int16_T)mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed) &&
             (mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_e !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed) {
    mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_e = 0.0F;
  }

  mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_e =
    mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed;
  mcb_pmsm_foc_sensorless_f2806_B.Delay1_pl =
    mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_e;
  mcb_pmsm_foc_sensorless_f2806_B.Sum_jy =
    mcb_pmsm_foc_sensorless_f2806_B.Sum3_k +
    mcb_pmsm_foc_sensorless_f2806_B.Delay1_pl;
  mcb_pmsm_foc_sensorless_f2806_B.Product_d =
    mcb_pmsm_foc_sensorless_f2806_B.Sum_jy * 2.49998757E-5F;
  zcEvent = (((mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_p == POS_ZCSIG)
              != (int16_T)mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed) &&
             (mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_p !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed) {
    mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_m = 0.0F;
  }

  mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_p =
    mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed;
  mcb_pmsm_foc_sensorless_f2806_B.Delay_p =
    mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_m;
  mcb_pmsm_foc_sensorless_f2806_B.Product1_n5 =
    mcb_pmsm_foc_sensorless_f2806_B.Delay_p * 0.99999F;
  mcb_pmsm_foc_sensorless_f2806_B.Sum1_em =
    mcb_pmsm_foc_sensorless_f2806_B.Product_d +
    mcb_pmsm_foc_sensorless_f2806_B.Product1_n5;
  mcb_pmsm_foc_sensorless_f2806_B.Product2_i =
    mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[3] * 0.000255168212F;
  mcb_pmsm_foc_sensorless_f2806_B.Sum1_p =
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_em -
    mcb_pmsm_foc_sensorless_f2806_B.Product2_i;
  mcb_pmsm_foc_sensorless_f2806_B.Sum_p = 0.999F;
  mcb_pmsm_foc_sensorless_f2806_B.Switch1_eg[0] = 0.0010000047F;
  mcb_pmsm_foc_sensorless_f2806_B.Switch1_eg[1] = 0.999F;
  mcb_pmsm_foc_sensorless_f2806_B.Product_fdo =
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_p * 0.0010000047F;
  mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_dy =
    mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_m;
  mcb_pmsm_foc_sensorless_f2806_B.Product1_k = 0.999F *
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_dy;
  mcb_pmsm_foc_sensorless_f2806_B.Add1_jx =
    mcb_pmsm_foc_sensorless_f2806_B.Product_fdo +
    mcb_pmsm_foc_sensorless_f2806_B.Product1_k;
  if (mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed) {
    /* Switch: '<S258>/Switch' incorporates:
     *  Constant: '<S258>/Constant'
     */
    mcb_pmsm_foc_sensorless_f2806_B.Switch_g = 0.0F;
  } else {
    /* Sum: '<S264>/Sum' */
    mcb_pmsm_foc_sensorless_f2806_B.Sum_dj =
      mcb_pmsm_foc_sensorless_f2806_B.Sum1_p -
      mcb_pmsm_foc_sensorless_f2806_B.Add1_jx;

    /* Switch: '<S258>/Switch' */
    mcb_pmsm_foc_sensorless_f2806_B.Switch_g =
      mcb_pmsm_foc_sensorless_f2806_B.Sum_dj;
  }

  mcb_pmsm_foc_sensorless_f2806_B.Product_iw =
    mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[2] * 0.170112133F;
  mcb_pmsm_foc_sensorless_f2806_B.Sum3_n0 =
    mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[0] -
    mcb_pmsm_foc_sensorless_f2806_B.Product_iw;
  zcEvent = (((mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_l == POS_ZCSIG)
              != (int16_T)mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed) &&
             (mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_l !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed) {
    mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_m = 0.0F;
  }

  mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_l =
    mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed;
  mcb_pmsm_foc_sensorless_f2806_B.Delay1_a =
    mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_m;
  mcb_pmsm_foc_sensorless_f2806_B.Sum_ga =
    mcb_pmsm_foc_sensorless_f2806_B.Sum3_n0 +
    mcb_pmsm_foc_sensorless_f2806_B.Delay1_a;
  mcb_pmsm_foc_sensorless_f2806_B.Product_n3 =
    mcb_pmsm_foc_sensorless_f2806_B.Sum_ga * 2.49998757E-5F;
  zcEvent = (((mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_d == POS_ZCSIG)
              != (int16_T)mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed) &&
             (mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_d !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed) {
    mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_p = 0.0F;
  }

  mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_d =
    mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed;
  mcb_pmsm_foc_sensorless_f2806_B.Delay_b =
    mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_p;
  mcb_pmsm_foc_sensorless_f2806_B.Product1_g =
    mcb_pmsm_foc_sensorless_f2806_B.Delay_b * 0.99999F;
  mcb_pmsm_foc_sensorless_f2806_B.Sum1_mn =
    mcb_pmsm_foc_sensorless_f2806_B.Product_n3 +
    mcb_pmsm_foc_sensorless_f2806_B.Product1_g;
  mcb_pmsm_foc_sensorless_f2806_B.Product2_b =
    mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[2] * 0.000255168212F;
  mcb_pmsm_foc_sensorless_f2806_B.Sum1_as =
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_mn -
    mcb_pmsm_foc_sensorless_f2806_B.Product2_b;
  mcb_pmsm_foc_sensorless_f2806_B.Sum_a = 0.999F;
  mcb_pmsm_foc_sensorless_f2806_B.Switch1_o[0] = 0.0010000047F;
  mcb_pmsm_foc_sensorless_f2806_B.Switch1_o[1] = 0.999F;
  mcb_pmsm_foc_sensorless_f2806_B.Product_lm =
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_as * 0.0010000047F;
  mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_e =
    mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_b;
  mcb_pmsm_foc_sensorless_f2806_B.Product1_ba = 0.999F *
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_e;
  mcb_pmsm_foc_sensorless_f2806_B.Add1_i =
    mcb_pmsm_foc_sensorless_f2806_B.Product_lm +
    mcb_pmsm_foc_sensorless_f2806_B.Product1_ba;
  if (mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_ed) {
    /* Switch: '<S250>/Switch' incorporates:
     *  Constant: '<S250>/Constant'
     */
    mcb_pmsm_foc_sensorless_f2806_B.Switch_h = 1.0E-6F;
  } else {
    /* Sum: '<S256>/Sum' */
    mcb_pmsm_foc_sensorless_f2806_B.Sum_ac =
      mcb_pmsm_foc_sensorless_f2806_B.Sum1_as -
      mcb_pmsm_foc_sensorless_f2806_B.Add1_i;

    /* Switch: '<S250>/Switch' */
    mcb_pmsm_foc_sensorless_f2806_B.Switch_h =
      mcb_pmsm_foc_sensorless_f2806_B.Sum_ac;
  }

  /* Outputs for Atomic SubSystem: '<S247>/atan2' */
  mcb_pmsm_foc_sensorless_f2806_B.Atan2 = atan2f
    (mcb_pmsm_foc_sensorless_f2806_B.Switch_g,
     mcb_pmsm_foc_sensorless_f2806_B.Switch_h);

  /* Outputs for Atomic SubSystem: '<S248>/Per Unit' */
  mcb_pmsm_foc_sensorless_f2806_B.Gain_f = 0.159154937F *
    mcb_pmsm_foc_sensorless_f2806_B.Atan2;
  if (mcb_pmsm_foc_sensorless_f2806_B.Gain_f >= 0.0F) {
    /* Switch: '<S249>/Switch' */
    mcb_pmsm_foc_sensorless_f2806_B.Switch_c =
      mcb_pmsm_foc_sensorless_f2806_B.Gain_f;
  } else {
    /* Bias: '<S249>/Bias' */
    mcb_pmsm_foc_sensorless_f2806_B.Bias =
      mcb_pmsm_foc_sensorless_f2806_B.Gain_f + 1.0F;

    /* Switch: '<S249>/Switch' */
    mcb_pmsm_foc_sensorless_f2806_B.Switch_c =
      mcb_pmsm_foc_sensorless_f2806_B.Bias;
  }

  /* End of Outputs for SubSystem: '<S248>/Per Unit' */
  mcb_pmsm_foc_sensorless_f2806_B.Switch_ds =
    mcb_pmsm_foc_sensorless_f2806_B.Switch_c;
  mcb_pmsm_foc_sensorless_f2806_B.algDD =
    mcb_pmsm_foc_sensorless_f2806_B.Switch_ds;

  /* End of Outputs for SubSystem: '<S247>/atan2' */
  mcb_pmsm_foc_sensorless_f2806_B.PositionToCount = (uint32_T)(4.2949673E+9F *
    mcb_pmsm_foc_sensorless_f2806_B.algDD);
  mcb_pmsm_foc_sensorless_f2806_B.Delay =
    mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_ad[mcb_pmsm_foc_sensorless_f_DWork.CircBufIdx];
  mcb_pmsm_foc_sensorless_f2806_B.SpeedCount = (int32_T)
    mcb_pmsm_foc_sensorless_f2806_B.PositionToCount - (int32_T)
    mcb_pmsm_foc_sensorless_f2806_B.Delay;
  mcb_pmsm_foc_sensorless_f2806_B.DTC = (real32_T)
    mcb_pmsm_foc_sensorless_f2806_B.SpeedCount;
  mcb_pmsm_foc_sensorless_f2806_B.SpeedGain = 5.55019408E-9F *
    mcb_pmsm_foc_sensorless_f2806_B.DTC;
  mcb_pmsm_foc_sensorless_f2806_B.Switch1_bs[0] = 0.01F;
  mcb_pmsm_foc_sensorless_f2806_B.Switch1_bs[1] = 0.99F;
  mcb_pmsm_foc_sensorless_f2806_B.Product_pk =
    mcb_pmsm_foc_sensorless_f2806_B.SpeedGain * 0.01F;
  mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_dk =
    mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_a1;
  mcb_pmsm_foc_sensorless_f2806_B.Product1_al = 0.99F *
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_dk;
  mcb_pmsm_foc_sensorless_f2806_B.Add1_p =
    mcb_pmsm_foc_sensorless_f2806_B.Product_pk +
    mcb_pmsm_foc_sensorless_f2806_B.Product1_al;
  mcb_pmsm_foc_sensorless_f2806_B.elect2mech = 0.25F *
    mcb_pmsm_foc_sensorless_f2806_B.Add1_p;
  mcb_pmsm_foc_sensorless_f2806_B.Merge_k[0] =
    mcb_pmsm_foc_sensorless_f2806_B.algDD;
  mcb_pmsm_foc_sensorless_f2806_B.Merge_k[1] =
    mcb_pmsm_foc_sensorless_f2806_B.elect2mech;
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_d5[0] =
    mcb_pmsm_foc_sensorless_f2806_B.Add1_jy[0];
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_d5[1] =
    mcb_pmsm_foc_sensorless_f2806_B.Add1_jy[1];
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_d5[2] =
    mcb_pmsm_foc_sensorless_f2806_B.Add1_jy[2];
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_d5[3] =
    mcb_pmsm_foc_sensorless_f2806_B.Add1_jy[3];
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_e =
    mcb_pmsm_foc_sensorless_f2806_B.Sum3_k;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_m =
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_em;
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_m =
    mcb_pmsm_foc_sensorless_f2806_B.Add1_jx;
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_m =
    mcb_pmsm_foc_sensorless_f2806_B.Sum3_n0;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_p =
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_mn;
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_b =
    mcb_pmsm_foc_sensorless_f2806_B.Add1_i;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_ad[mcb_pmsm_foc_sensorless_f_DWork.CircBufIdx]
    = mcb_pmsm_foc_sensorless_f2806_B.PositionToCount;
  if (mcb_pmsm_foc_sensorless_f_DWork.CircBufIdx < 9U) {
    mcb_pmsm_foc_sensorless_f_DWork.CircBufIdx++;
  } else {
    mcb_pmsm_foc_sensorless_f_DWork.CircBufIdx = 0U;
  }

  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_a1 =
    mcb_pmsm_foc_sensorless_f2806_B.Add1_p;

  /* End of Outputs for SubSystem: '<S78>/Flux Observer' */

  /* DataStoreRead: '<S19>/Data Store Read1' */
  mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1_n =
    mcb_pmsm_foc_sensorless_f_DWork.EnClosedLoop;

  /* DataStoreRead: '<S19>/Data Store Read' */
  mcb_pmsm_foc_sensorless_f2806_B.Spd_Pos =
    mcb_pmsm_foc_sensorless_f_DWork.SpdCtrlRef;

  /* Gain: '<S19>/Gain' */
  mcb_pmsm_foc_sensorless_f2806_B.Gain = 0.01678F *
    mcb_pmsm_foc_sensorless_f2806_B.Spd_Pos;

  /* Delay: '<S50>/Delay' */
  mcb_pmsm_foc_sensorless_f2806_B.Delay_kh =
    mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_d;

  /* Outputs for Enabled SubSystem: '<S50>/Subsystem' incorporates:
   *  EnablePort: '<S51>/Enable'
   */
  if (mcb_pmsm_foc_sensorless_f2806_B.Delay_kh) {
    /* SignalConversion generated from: '<S51>/Input' */
    mcb_pmsm_foc_sensorless_f2806_B.Input_h =
      mcb_pmsm_foc_sensorless_f2806_B.Gain;
  }

  /* End of Outputs for SubSystem: '<S50>/Subsystem' */

  /* DataStoreRead: '<S19>/Data Store Read2' */
  mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead2_m =
    mcb_pmsm_foc_sensorless_f_DWork.EnClosedLoop;

  /* Delay: '<S19>/Delay' */
  zcEvent = ((!mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead2_m) &&
             (mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE != ZERO_ZCSIG));
  mcb_pmsm_foc_sensorless_f_DWork.icLoad = (zcEvent ||
    mcb_pmsm_foc_sensorless_f_DWork.icLoad);
  mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE =
    mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead2_m;
  if (mcb_pmsm_foc_sensorless_f_DWork.icLoad) {
    mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE =
      mcb_pmsm_foc_sensorless_f2806_B.Merge_k[0];
  }

  /* Delay: '<S19>/Delay' */
  mcb_pmsm_foc_sensorless_f2806_B.Delay_g =
    mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE;

  /* Sum: '<S50>/Add' */
  mcb_pmsm_foc_sensorless_f2806_B.Add_g =
    mcb_pmsm_foc_sensorless_f2806_B.Input_h +
    mcb_pmsm_foc_sensorless_f2806_B.Delay_g;

  /* DataTypeConversion: '<S50>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_ey = (int16_T)(real32_T)
    floor(mcb_pmsm_foc_sensorless_f2806_B.Add_g);

  /* DataTypeConversion: '<S50>/Data Type Conversion1' */
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_d =
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_ey;

  /* Sum: '<S50>/Add1' */
  mcb_pmsm_foc_sensorless_f2806_B.Add1_f = mcb_pmsm_foc_sensorless_f2806_B.Add_g
    - mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_d;

  /* Switch: '<S19>/Switch' */
  if (mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1_n) {
    /* Switch: '<S19>/Switch' */
    mcb_pmsm_foc_sensorless_f2806_B.Switch =
      mcb_pmsm_foc_sensorless_f2806_B.Merge_k[0];
  } else {
    /* Switch: '<S19>/Switch' */
    mcb_pmsm_foc_sensorless_f2806_B.Switch =
      mcb_pmsm_foc_sensorless_f2806_B.Add1_f;
  }

  /* End of Switch: '<S19>/Switch' */

  /* RelationalOperator: '<S58>/Compare' incorporates:
   *  Constant: '<S58>/Constant'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Compare_d =
    (mcb_pmsm_foc_sensorless_f2806_B.Switch < 0.0F);

  /* DataTypeConversion: '<S56>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_e =
    mcb_pmsm_foc_sensorless_f2806_B.Compare_d;

  /* If: '<S56>/If' */
  if (mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_e > 0U) {
    /* Outputs for IfAction SubSystem: '<S56>/If Action Subsystem' incorporates:
     *  ActionPort: '<S59>/Action Port'
     */
    mcb_pmsm__IfActionSubsystem(mcb_pmsm_foc_sensorless_f2806_B.Switch,
      &mcb_pmsm_foc_sensorless_f2806_B.Merge_c,
      &mcb_pmsm_foc_sensorless_f2806_B.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S56>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S56>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S60>/Action Port'
     */
    mcb_pmsm_IfActionSubsystem1(mcb_pmsm_foc_sensorless_f2806_B.Switch,
      &mcb_pmsm_foc_sensorless_f2806_B.Merge_c,
      &mcb_pmsm_foc_sensorless_f2806_B.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S56>/If Action Subsystem1' */
  }

  /* End of If: '<S56>/If' */

  /* Gain: '<S54>/indexing' */
  mcb_pmsm_foc_sensorless_f2806_B.indexing_d = 800.0F *
    mcb_pmsm_foc_sensorless_f2806_B.Merge_c;

  /* DataTypeConversion: '<S54>/Get_Integer' */
  mcb_pmsm_foc_sensorless_f2806_B.Get_Integer_i = (uint16_T)
    mcb_pmsm_foc_sensorless_f2806_B.indexing_d;

  /* Sum: '<S54>/Sum' incorporates:
   *  Constant: '<S54>/offset'
   */
  Sum_k = mcb_pmsm_foc_sensorless_f2806_B.Get_Integer_i + 1UL;
  mcb_pmsm_foc_sensorless_f2806_B.Sum_k[0] = Sum_k;

  /* Selector: '<S54>/Lookup' incorporates:
   *  Constant: '<S54>/sine_table_values'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[0] =
    mcb_pmsm_foc_sensorless__ConstP.pooled31[(int16_T)Sum_k];

  /* Sum: '<S54>/Sum' */
  Sum_k = mcb_pmsm_foc_sensorless_f2806_B.Get_Integer_i;
  mcb_pmsm_foc_sensorless_f2806_B.Sum_k[1] = Sum_k;

  /* Selector: '<S54>/Lookup' incorporates:
   *  Constant: '<S54>/sine_table_values'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[1] =
    mcb_pmsm_foc_sensorless__ConstP.pooled31[(int16_T)Sum_k];

  /* Sum: '<S54>/Sum' incorporates:
   *  Constant: '<S54>/offset'
   */
  Sum_k = mcb_pmsm_foc_sensorless_f2806_B.Get_Integer_i + 201UL;
  mcb_pmsm_foc_sensorless_f2806_B.Sum_k[2] = Sum_k;

  /* Selector: '<S54>/Lookup' incorporates:
   *  Constant: '<S54>/sine_table_values'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[2] =
    mcb_pmsm_foc_sensorless__ConstP.pooled31[(int16_T)Sum_k];

  /* Sum: '<S54>/Sum' incorporates:
   *  Constant: '<S54>/offset'
   */
  Sum_k = mcb_pmsm_foc_sensorless_f2806_B.Get_Integer_i + 200UL;
  mcb_pmsm_foc_sensorless_f2806_B.Sum_k[3] = Sum_k;

  /* Selector: '<S54>/Lookup' incorporates:
   *  Constant: '<S54>/sine_table_values'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[3] =
    mcb_pmsm_foc_sensorless__ConstP.pooled31[(int16_T)Sum_k];

  /* Sum: '<S55>/Sum3' */
  mcb_pmsm_foc_sensorless_f2806_B.Sum3_b =
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[0] -
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[1];

  /* DataTypeConversion: '<S54>/Data Type Conversion1' */
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_c =
    mcb_pmsm_foc_sensorless_f2806_B.Get_Integer_i;

  /* Sum: '<S54>/Sum2' */
  mcb_pmsm_foc_sensorless_f2806_B.Sum2_e =
    mcb_pmsm_foc_sensorless_f2806_B.indexing_d -
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_c;

  /* Product: '<S55>/Product' */
  mcb_pmsm_foc_sensorless_f2806_B.Product_g =
    mcb_pmsm_foc_sensorless_f2806_B.Sum3_b *
    mcb_pmsm_foc_sensorless_f2806_B.Sum2_e;

  /* Sum: '<S55>/Sum4' */
  mcb_pmsm_foc_sensorless_f2806_B.Sum4_h =
    mcb_pmsm_foc_sensorless_f2806_B.Product_g +
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[1];

  /* Sum: '<S55>/Sum5' */
  mcb_pmsm_foc_sensorless_f2806_B.Sum5_l =
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[2] -
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[3];

  /* Product: '<S55>/Product1' */
  mcb_pmsm_foc_sensorless_f2806_B.Product1_e =
    mcb_pmsm_foc_sensorless_f2806_B.Sum5_l *
    mcb_pmsm_foc_sensorless_f2806_B.Sum2_e;

  /* Sum: '<S55>/Sum6' */
  mcb_pmsm_foc_sensorless_f2806_B.Sum6_c =
    mcb_pmsm_foc_sensorless_f2806_B.Product1_e +
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[3];

  /* Outputs for Atomic SubSystem: '<S20>/Two inputs CRL' */
  mcb_pmsm_foc_s_TwoinputsCRL
    (mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap.algDD_o1,
     mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap.algDD_o2,
     mcb_pmsm_foc_sensorless_f2806_B.Sum4_h,
     mcb_pmsm_foc_sensorless_f2806_B.Sum6_c,
     &mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m);

  /* End of Outputs for SubSystem: '<S20>/Two inputs CRL' */

  /* Sum: '<S27>/Sum' */
  mcb_pmsm_foc_sensorless_f2806_B.Sum_m = mcb_pmsm_foc_sensorless_f2806_B.RT2[1]
    - mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.algDD_o2;

  /* DataStoreRead: '<S27>/Data Store Read1' */
  mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1_b =
    mcb_pmsm_foc_sensorless_f_DWork.EnClosedLoop;

  /* Logic: '<S27>/Logical Operator' */
  mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator =
    !mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1_b;

  /* DataStoreRead: '<S27>/Vq_computed1' */
  mcb_pmsm_foc_sensorless_f2806_B.Vq_computed =
    mcb_pmsm_foc_sensorless_f_DWork.Vq_out_initial;

  /* Product: '<S27>/Product' incorporates:
   *  Constant: '<S27>/Kp'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Product_bk =
    mcb_pmsm_foc_sensorless_f2806_B.Sum_m * 3.6F;

  /* Sum: '<S27>/Sum1' */
  mcb_pmsm_foc_sensorless_f2806_B.Sum1 =
    mcb_pmsm_foc_sensorless_f2806_B.Vq_computed -
    mcb_pmsm_foc_sensorless_f2806_B.Product_bk;

  /* MATLAB Function: '<S27>/MATLAB Function' incorporates:
   *  Constant: '<S27>/Ki'
   *  Constant: '<S27>/Kp'
   */
  /* MATLAB Function 'Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/MATLAB Function': '<S47>:1' */
  if (mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator) {
    /* '<S47>:1:21' */
    /* '<S47>:1:22' */
    mcb_pmsm_foc_sensorless_f_DWork.integrator_state =
      mcb_pmsm_foc_sensorless_f2806_B.Sum1;
  }

  /* '<S47>:1:26' */
  /* '<S47>:1:29' */
  mcb_pmsm_foc_sensorless_f_DWork.integrator_state += 0.333333343F *
    mcb_pmsm_foc_sensorless_f2806_B.Sum_m;

  /* '<S47>:1:32' */
  V_q_ref_unsat = 3.6F * mcb_pmsm_foc_sensorless_f2806_B.Sum_m +
    mcb_pmsm_foc_sensorless_f_DWork.integrator_state;

  /* '<S47>:1:35' */
  if (V_q_ref_unsat <= 1.0F) {
    Product_am = V_q_ref_unsat;
  } else {
    Product_am = 1.0F;
  }

  if (Product_am >= -1.0F) {
    mcb_pmsm_foc_sensorless_f2806_B.V_q_ref = Product_am;
  } else {
    mcb_pmsm_foc_sensorless_f2806_B.V_q_ref = -1.0F;
  }

  if (mcb_pmsm_foc_sensorless_f2806_B.V_q_ref != V_q_ref_unsat) {
    /* '<S47>:1:38' */
    /* '<S47>:1:39' */
    mcb_pmsm_foc_sensorless_f_DWork.integrator_state -= 0.333333343F *
      mcb_pmsm_foc_sensorless_f2806_B.Sum_m;
  }

  /* End of MATLAB Function: '<S27>/MATLAB Function' */

  /* Switch: '<S27>/Switch' */
  if (mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1_b) {
    /* Switch: '<S27>/Switch' */
    mcb_pmsm_foc_sensorless_f2806_B.Switch_j =
      mcb_pmsm_foc_sensorless_f2806_B.V_q_ref;
  } else {
    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S27>/Vq_OpenLoop'
     */
    mcb_pmsm_foc_sensorless_f2806_B.Switch_j = 0.0F;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Sum: '<S26>/Sum' */
  mcb_pmsm_foc_sensorless_f2806_B.Sum_g = mcb_pmsm_foc_sensorless_f2806_B.RT2[0]
    - mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.algDD_o1;

  /* DataStoreRead: '<S26>/Data Store Read1' */
  mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1_f =
    mcb_pmsm_foc_sensorless_f_DWork.EnClosedLoop;

  /* Logic: '<S26>/Logical Operator' */
  mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_e =
    !mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1_f;

  /* DataStoreRead: '<S26>/Vd_computed1' */
  mcb_pmsm_foc_sensorless_f2806_B.Vd_computed1 =
    mcb_pmsm_foc_sensorless_f_DWork.Vd_out_initial;

  /* Product: '<S26>/Product' incorporates:
   *  Constant: '<S26>/Kp'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Product_e =
    mcb_pmsm_foc_sensorless_f2806_B.Sum_g * 3.6F;

  /* Sum: '<S26>/Sum1' */
  mcb_pmsm_foc_sensorless_f2806_B.Sum1_a =
    mcb_pmsm_foc_sensorless_f2806_B.Vd_computed1 -
    mcb_pmsm_foc_sensorless_f2806_B.Product_e;

  /* MATLAB Function: '<S26>/MATLAB Function' incorporates:
   *  Constant: '<S26>/Ki'
   *  Constant: '<S26>/Kp'
   */
  /* MATLAB Function 'Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/MATLAB Function': '<S43>:1' */
  if (mcb_pmsm_foc_sensorless_f2806_B.LogicalOperator_e) {
    /* '<S43>:1:21' */
    /* '<S43>:1:22' */
    mcb_pmsm_foc_sensorless_f_DWork.integrator_state_a =
      mcb_pmsm_foc_sensorless_f2806_B.Sum1_a;
  }

  /* '<S43>:1:26' */
  /* '<S43>:1:29' */
  mcb_pmsm_foc_sensorless_f_DWork.integrator_state_a += 0.333333343F *
    mcb_pmsm_foc_sensorless_f2806_B.Sum_g;

  /* '<S43>:1:32' */
  V_q_ref_unsat = 3.6F * mcb_pmsm_foc_sensorless_f2806_B.Sum_g +
    mcb_pmsm_foc_sensorless_f_DWork.integrator_state_a;

  /* '<S43>:1:35' */
  if (V_q_ref_unsat <= 1.0F) {
    Product_am = V_q_ref_unsat;
  } else {
    Product_am = 1.0F;
  }

  if (Product_am >= -1.0F) {
    mcb_pmsm_foc_sensorless_f2806_B.V_d_ref = Product_am;
  } else {
    mcb_pmsm_foc_sensorless_f2806_B.V_d_ref = -1.0F;
  }

  if (mcb_pmsm_foc_sensorless_f2806_B.V_d_ref != V_q_ref_unsat) {
    /* '<S43>:1:38' */
    /* '<S43>:1:39' */
    mcb_pmsm_foc_sensorless_f_DWork.integrator_state_a -= 0.333333343F *
      mcb_pmsm_foc_sensorless_f2806_B.Sum_g;
  }

  /* End of MATLAB Function: '<S26>/MATLAB Function' */

  /* DataStoreRead: '<S26>/Vd_OpenLoop' */
  mcb_pmsm_foc_sensorless_f2806_B.Vd_OpenLoop =
    mcb_pmsm_foc_sensorless_f_DWork.SpdCtrlRef;

  /* Abs: '<S26>/Abs' */
  mcb_pmsm_foc_sensorless_f2806_B.Abs = fabsf
    (mcb_pmsm_foc_sensorless_f2806_B.Vd_OpenLoop);

  /* Switch: '<S42>/Switch1' incorporates:
   *  Constant: '<S42>/FilterConstant'
   *  Constant: '<S42>/OneMinusFilterConstant'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Switch1[0] = 0.1F;
  mcb_pmsm_foc_sensorless_f2806_B.Switch1[1] = 0.9F;

  /* Product: '<S46>/Product' */
  mcb_pmsm_foc_sensorless_f2806_B.Product_bh =
    mcb_pmsm_foc_sensorless_f2806_B.Abs * 0.1F;

  /* UnitDelay: '<S46>/Unit Delay' */
  mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_n =
    mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_g;

  /* Product: '<S46>/Product1' */
  mcb_pmsm_foc_sensorless_f2806_B.Product1_p = 0.9F *
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_n;

  /* Sum: '<S46>/Add1' */
  mcb_pmsm_foc_sensorless_f2806_B.Add1_l =
    mcb_pmsm_foc_sensorless_f2806_B.Product_bh +
    mcb_pmsm_foc_sensorless_f2806_B.Product1_p;

  /* Switch: '<S26>/Switch' */
  if (mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1_f) {
    /* Switch: '<S26>/Switch' */
    mcb_pmsm_foc_sensorless_f2806_B.Switch_d =
      mcb_pmsm_foc_sensorless_f2806_B.V_d_ref;
  } else {
    /* Saturate: '<S26>/Saturation' */
    Product_am = mcb_pmsm_foc_sensorless_f2806_B.Add1_l;
    if (Product_am > 0.6F) {
      /* Saturate: '<S26>/Saturation' */
      mcb_pmsm_foc_sensorless_f2806_B.Saturation = 0.6F;
    } else if (Product_am < 0.15F) {
      /* Saturate: '<S26>/Saturation' */
      mcb_pmsm_foc_sensorless_f2806_B.Saturation = 0.15F;
    } else {
      /* Saturate: '<S26>/Saturation' */
      mcb_pmsm_foc_sensorless_f2806_B.Saturation = Product_am;
    }

    /* End of Saturate: '<S26>/Saturation' */

    /* Switch: '<S26>/Switch' */
    mcb_pmsm_foc_sensorless_f2806_B.Switch_d =
      mcb_pmsm_foc_sensorless_f2806_B.Saturation;
  }

  /* End of Switch: '<S26>/Switch' */

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant3'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Switch_jv = 1.0F;

  /* Product: '<S30>/Product' */
  mcb_pmsm_foc_sensorless_f2806_B.Product_l = 1.0F;

  /* Product: '<S31>/Product' */
  mcb_pmsm_foc_sensorless_f2806_B.Product_o =
    mcb_pmsm_foc_sensorless_f2806_B.Switch_d *
    mcb_pmsm_foc_sensorless_f2806_B.Switch_d;

  /* Product: '<S31>/Product1' */
  mcb_pmsm_foc_sensorless_f2806_B.Product1_ad =
    mcb_pmsm_foc_sensorless_f2806_B.Switch_j *
    mcb_pmsm_foc_sensorless_f2806_B.Switch_j;

  /* Sum: '<S31>/Sum1' */
  mcb_pmsm_foc_sensorless_f2806_B.Sum1_e =
    mcb_pmsm_foc_sensorless_f2806_B.Product_o +
    mcb_pmsm_foc_sensorless_f2806_B.Product1_ad;

  /* Outputs for IfAction SubSystem: '<S25>/D-Q Equivalence' incorporates:
   *  ActionPort: '<S28>/Action Port'
   */
  /* If: '<S25>/If' incorporates:
   *  DataTypeConversion: '<S28>/Data Type Conversion'
   *  RelationalOperator: '<S28>/Relational Operator'
   */
  mcb_pmsm_foc_sensorless_f2806_B.RelationalOperator =
    (mcb_pmsm_foc_sensorless_f2806_B.Sum1_e > 1.0F);
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_k =
    mcb_pmsm_foc_sensorless_f2806_B.RelationalOperator;

  /* If: '<S28>/If' incorporates:
   *  If: '<S25>/If'
   */
  if (mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_k != 0U) {
    /* Outputs for IfAction SubSystem: '<S28>/Limiter' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* Product: '<S32>/Product' */
    mcb_pmsm_foc_sensorless_f2806_B.Product_ch[0] =
      mcb_pmsm_foc_sensorless_f2806_B.Switch_d;
    mcb_pmsm_foc_sensorless_f2806_B.Product_ch[1] =
      mcb_pmsm_foc_sensorless_f2806_B.Switch_j;

    /* Sqrt: '<S32>/Square Root' */
    mcb_pmsm_foc_sensorless_f2806_B.SquareRoot = (real32_T)sqrt
      (mcb_pmsm_foc_sensorless_f2806_B.Sum1_e);

    /* Switch: '<S32>/Switch' */
    if (mcb_pmsm_foc_sensorless_f2806_B.SquareRoot != 0.0F) {
      /* Switch: '<S32>/Switch' */
      mcb_pmsm_foc_sensorless_f2806_B.Switch_o =
        mcb_pmsm_foc_sensorless_f2806_B.SquareRoot;
    } else {
      /* Switch: '<S32>/Switch' incorporates:
       *  Constant: '<S32>/Constant'
       */
      mcb_pmsm_foc_sensorless_f2806_B.Switch_o = 1.0F;
    }

    /* End of Switch: '<S32>/Switch' */

    /* Merge: '<S25>/Merge' incorporates:
     *  Product: '<S32>/Divide'
     */
    mcb_pmsm_foc_sensorless_f2806_B.Merge_m[0] =
      mcb_pmsm_foc_sensorless_f2806_B.Product_ch[0] /
      mcb_pmsm_foc_sensorless_f2806_B.Switch_o;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_m[1] =
      mcb_pmsm_foc_sensorless_f2806_B.Product_ch[1] /
      mcb_pmsm_foc_sensorless_f2806_B.Switch_o;

    /* End of Outputs for SubSystem: '<S28>/Limiter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S28>/Passthrough' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* Merge: '<S25>/Merge' incorporates:
     *  SignalConversion generated from: '<S33>/dqRef'
     */
    mcb_pmsm_foc_sensorless_f2806_B.Merge_m[0] =
      mcb_pmsm_foc_sensorless_f2806_B.Switch_d;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_m[1] =
      mcb_pmsm_foc_sensorless_f2806_B.Switch_j;

    /* End of Outputs for SubSystem: '<S28>/Passthrough' */
  }

  /* End of If: '<S28>/If' */
  /* End of Outputs for SubSystem: '<S25>/D-Q Equivalence' */

  /* Product: '<S17>/Product' incorporates:
   *  Constant: '<S17>/Constant'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Product =
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.algDD_o2 * 0.0 * 0.0006;

  /* Sum: '<S17>/Add' */
  mcb_pmsm_foc_sensorless_f2806_B.Add = mcb_pmsm_foc_sensorless_f2806_B.Merge_m
    [0] + mcb_pmsm_foc_sensorless_f2806_B.Product;

  /* Product: '<S17>/Product1' incorporates:
   *  Constant: '<S17>/Constant1'
   */
  mcb_pmsm_foc_sensorless_f2806_B.Product1 =
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.algDD_o1 * 0.0006 * 0.0;

  /* Sum: '<S17>/Add1' */
  mcb_pmsm_foc_sensorless_f2806_B.Add1 =
    (mcb_pmsm_foc_sensorless_f2806_B.Merge_m[1] +
     mcb_pmsm_foc_sensorless_f2806_B.Product1) +
    mcb_pmsm_foc_sensorless__ConstB.Product2;

  /* Outputs for Atomic SubSystem: '<S18>/Two inputs CRL' */
  /* Product: '<S48>/qcos' */
  mcb_pmsm_foc_sensorless_f2806_B.qcos = mcb_pmsm_foc_sensorless_f2806_B.Add1 *
    mcb_pmsm_foc_sensorless_f2806_B.Sum6_c;

  /* Product: '<S48>/dsin' */
  mcb_pmsm_foc_sensorless_f2806_B.dsin = mcb_pmsm_foc_sensorless_f2806_B.Add *
    mcb_pmsm_foc_sensorless_f2806_B.Sum4_h;

  /* Sum: '<S48>/sum_beta' */
  mcb_pmsm_foc_sensorless_f2806_B.sum_beta =
    mcb_pmsm_foc_sensorless_f2806_B.qcos + mcb_pmsm_foc_sensorless_f2806_B.dsin;

  /* Product: '<S48>/dcos' */
  mcb_pmsm_foc_sensorless_f2806_B.dcos = mcb_pmsm_foc_sensorless_f2806_B.Add *
    mcb_pmsm_foc_sensorless_f2806_B.Sum6_c;

  /* Product: '<S48>/qsin' */
  mcb_pmsm_foc_sensorless_f2806_B.qsin = mcb_pmsm_foc_sensorless_f2806_B.Add1 *
    mcb_pmsm_foc_sensorless_f2806_B.Sum4_h;

  /* Sum: '<S48>/sum_alpha' */
  mcb_pmsm_foc_sensorless_f2806_B.sum_alpha =
    mcb_pmsm_foc_sensorless_f2806_B.dcos - mcb_pmsm_foc_sensorless_f2806_B.qsin;

  /* Switch: '<S49>/Switch' */
  mcb_pmsm_foc_sensorless_f2806_B.Switch_f[0] = (real32_T)
    mcb_pmsm_foc_sensorless_f2806_B.sum_alpha;
  mcb_pmsm_foc_sensorless_f2806_B.Switch_f[1] = (real32_T)
    mcb_pmsm_foc_sensorless_f2806_B.sum_beta;

  /* AlgorithmDescriptorDelegate generated from: '<S48>/a16' */
  mcb_pmsm_foc_sensorless_f2806_B.algDD_o1 =
    mcb_pmsm_foc_sensorless_f2806_B.Switch_f[0];

  /* AlgorithmDescriptorDelegate generated from: '<S48>/a16' */
  mcb_pmsm_foc_sensorless_f2806_B.algDD_o2 =
    mcb_pmsm_foc_sensorless_f2806_B.Switch_f[1];

  /* End of Outputs for SubSystem: '<S18>/Two inputs CRL' */

  /* DataStoreWrite: '<S9>/Data Store Write3' */
  mcb_pmsm_foc_sensorless_f_DWork.V_alpha =
    mcb_pmsm_foc_sensorless_f2806_B.algDD_o1;

  /* DataStoreWrite: '<S9>/Data Store Write4' */
  mcb_pmsm_foc_sensorless_f_DWork.Pos_meas_PU =
    mcb_pmsm_foc_sensorless_f2806_B.Merge_k[0];

  /* DataStoreWrite: '<S9>/Data Store Write5' */
  mcb_pmsm_foc_sensorless_f_DWork.Ib_meas_PU =
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_p[1];

  /* DataStoreWrite: '<S9>/Data Store Write6' */
  mcb_pmsm_foc_sensorless_f_DWork.V_beta =
    mcb_pmsm_foc_sensorless_f2806_B.algDD_o2;

  /* UnitDelay: '<S69>/Output' */
  mcb_pmsm_foc_sensorless_f2806_B.Output =
    mcb_pmsm_foc_sensorless_f_DWork.Output_DSTATE;

  /* DataTypeConversion: '<S71>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_l[0] = (int16_T)
    (mcb_pmsm_foc_sensorless_f2806_B.Merge_k[1] * 4096.0F);
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_l[1] = (int16_T)
    (mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_p[0] * 4096.0F);

  /* DataTypeConversion: '<S71>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S71>/Data Type Conversion'
   */
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion3[0] = (uint16_T)
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_l[0];
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion3[1] = (uint16_T)
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_l[1];

  /* If: '<S10>/If' */
  if (mcb_pmsm_foc_sensorless_f2806_B.Output == 0U) {
    /* Outputs for IfAction SubSystem: '<S10>/Start' incorporates:
     *  ActionPort: '<S73>/Action Port'
     */
    /* Merge: '<S10>/Merge' incorporates:
     *  Constant: '<S73>/End'
     *  SignalConversion generated from: '<S73>/Data_out'
     */
    mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Data[0] = 21331U;

    /* SignalConversion generated from: '<S73>/Data' */
    Data = mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion3[0];

    /* End of Outputs for SubSystem: '<S10>/Start' */
    mcb_pmsm_foc_sensorless_f2806_B.Data_fw[0] = Data;

    /* Outputs for IfAction SubSystem: '<S10>/Start' incorporates:
     *  ActionPort: '<S73>/Action Port'
     */
    /* Merge: '<S10>/Merge' incorporates:
     *  SignalConversion generated from: '<S73>/Data_out'
     */
    mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Data[1] = Data;

    /* SignalConversion generated from: '<S73>/Data' */
    Data = mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion3[1];

    /* End of Outputs for SubSystem: '<S10>/Start' */
    mcb_pmsm_foc_sensorless_f2806_B.Data_fw[1] = Data;

    /* Outputs for IfAction SubSystem: '<S10>/Start' incorporates:
     *  ActionPort: '<S73>/Action Port'
     */
    /* Merge: '<S10>/Merge' incorporates:
     *  SignalConversion generated from: '<S73>/Data_out'
     */
    mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Data[2] = Data;

    /* Merge: '<S10>/Merge1' incorporates:
     *  Bias: '<S73>/Bias'
     */
    mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_sensorless__ConstB.Width + 1U;

    /* End of Outputs for SubSystem: '<S10>/Start' */
  } else if (mcb_pmsm_foc_sensorless_f2806_B.Output == 599U) {
    /* Outputs for IfAction SubSystem: '<S10>/End' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    /* SignalConversion generated from: '<S72>/Data' */
    Data = mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion3[0];

    /* End of Outputs for SubSystem: '<S10>/End' */
    mcb_pmsm_foc_sensorless_f2806_B.Data_f[0] = Data;

    /* Outputs for IfAction SubSystem: '<S10>/End' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    /* Merge: '<S10>/Merge' incorporates:
     *  SignalConversion generated from: '<S72>/Data_out'
     */
    mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Data[0] = Data;

    /* SignalConversion generated from: '<S72>/Data' */
    Data = mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion3[1];

    /* End of Outputs for SubSystem: '<S10>/End' */
    mcb_pmsm_foc_sensorless_f2806_B.Data_f[1] = Data;

    /* Outputs for IfAction SubSystem: '<S10>/End' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    /* Merge: '<S10>/Merge' incorporates:
     *  Constant: '<S72>/Start'
     *  SignalConversion generated from: '<S72>/Data_out'
     */
    mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Data[1] = Data;
    mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Data[2] = 17733U;

    /* Merge: '<S10>/Merge1' incorporates:
     *  Bias: '<S72>/Bias'
     */
    mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_sensorless__ConstB.Width + 1U;

    /* End of Outputs for SubSystem: '<S10>/End' */
  } else {
    /* Outputs for IfAction SubSystem: '<S10>/Data' incorporates:
     *  ActionPort: '<S70>/Action Port'
     */
    /* SignalConversion generated from: '<S70>/Data' */
    Data = mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion3[0];

    /* End of Outputs for SubSystem: '<S10>/Data' */
    mcb_pmsm_foc_sensorless_f2806_B.Data[0] = Data;

    /* Outputs for IfAction SubSystem: '<S10>/Data' incorporates:
     *  ActionPort: '<S70>/Action Port'
     */
    /* Merge: '<S10>/Merge' incorporates:
     *  SignalConversion generated from: '<S70>/Data_out'
     */
    mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Data[0] = Data;

    /* SignalConversion generated from: '<S70>/Data' */
    Data = mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion3[1];

    /* End of Outputs for SubSystem: '<S10>/Data' */
    mcb_pmsm_foc_sensorless_f2806_B.Data[1] = Data;

    /* Outputs for IfAction SubSystem: '<S10>/Data' incorporates:
     *  ActionPort: '<S70>/Action Port'
     */
    /* Merge: '<S10>/Merge' incorporates:
     *  Constant: '<S70>/Start'
     *  SignalConversion generated from: '<S70>/Data_out'
     */
    mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Data[1] = Data;
    mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Data[2] = 0U;

    /* Merge: '<S10>/Merge1' incorporates:
     *  SignalConversion generated from: '<S70>/Data_width'
     */
    mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_sensorless__ConstB.Width;

    /* End of Outputs for SubSystem: '<S10>/Data' */
  }

  /* End of If: '<S10>/If' */

  /* Outputs for Iterator SubSystem: '<S299>/CodeGeneration' incorporates:
   *  WhileIterator: '<S300>/While Iterator'
   */
  s300_iter = 1;
  do {
    mcb_pmsm_foc_sensorless_f2806_B.WhileIterator = s300_iter;
    mcb_pmsm_foc_sensorless_f2806_B.IndexVector =
      mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Data[mcb_pmsm_foc_sensorless_f2806_B.WhileIterator
      - 1];

    {
      if (checkSCITransmitInProgressA != 1U) {
        checkSCITransmitInProgressA = 1U;
        int16_T errFlgHeader = NOERROR;
        int16_T errFlgData = NOERROR;
        int16_T errFlgTail = NOERROR;
        errFlgData = scia_xmit((uchar_T*)
          &mcb_pmsm_foc_sensorless_f2806_B.IndexVector, 2, 2);
        checkSCITransmitInProgressA = 0U;
      }
    }

    mcb_pmsm_foc_sensorless_f2806_B.Add_m =
      mcb_pmsm_foc_sensorless_f2806_B.SCI_Tx_Iteration - (uint16_T)
      mcb_pmsm_foc_sensorless_f2806_B.WhileIterator;
    s300_iter++;
  } while (mcb_pmsm_foc_sensorless_f2806_B.Add_m != 0U);

  /* End of Outputs for SubSystem: '<S299>/CodeGeneration' */

  /* Sum: '<S74>/FixPt Sum1' incorporates:
   *  Constant: '<S74>/FixPt Constant'
   */
  mcb_pmsm_foc_sensorless_f2806_B.FixPtSum1 =
    mcb_pmsm_foc_sensorless_f2806_B.Output + 1U;

  /* Switch: '<S75>/FixPt Switch' */
  if (mcb_pmsm_foc_sensorless_f2806_B.FixPtSum1 > 599U) {
    /* Switch: '<S75>/FixPt Switch' incorporates:
     *  Constant: '<S75>/Constant'
     */
    mcb_pmsm_foc_sensorless_f2806_B.FixPtSwitch = 0U;
  } else {
    /* Switch: '<S75>/FixPt Switch' */
    mcb_pmsm_foc_sensorless_f2806_B.FixPtSwitch =
      mcb_pmsm_foc_sensorless_f2806_B.FixPtSum1;
  }

  /* End of Switch: '<S75>/FixPt Switch' */

  /* DataStoreRead: '<S14>/Enable' */
  mcb_pmsm_foc_sensorless_f2806_B.Enable_l =
    mcb_pmsm_foc_sensorless_f_DWork.Enable;

  /* DataTypeConversion: '<S14>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_c =
    mcb_pmsm_foc_sensorless_f2806_B.Enable_l;

  /* S-Function (c280xgpio_do): '<S298>/Digital Output' */
  {
    if (mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_c) {
      GpioDataRegs.GPBSET.bit.GPIO50 = 1U;
    } else {
      GpioDataRegs.GPBCLEAR.bit.GPIO50 = 1U;
    }
  }

  /* Switch: '<S298>/Switch1' */
  if (mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_c >= 0.5F) {
    /* Gain: '<S68>/sqrt3_by_two' */
    mcb_pmsm_foc_sensorless_f2806_B.sqrt3_by_two = 0.866025388F *
      mcb_pmsm_foc_sensorless_f2806_B.algDD_o2;

    /* Gain: '<S68>/one_by_two' */
    mcb_pmsm_foc_sensorless_f2806_B.one_by_two = 0.5F *
      mcb_pmsm_foc_sensorless_f2806_B.algDD_o1;

    /* Sum: '<S68>/add_c' */
    mcb_pmsm_foc_sensorless_f2806_B.add_c = (0.0F -
      mcb_pmsm_foc_sensorless_f2806_B.one_by_two) -
      mcb_pmsm_foc_sensorless_f2806_B.sqrt3_by_two;

    /* Sum: '<S68>/add_b' */
    mcb_pmsm_foc_sensorless_f2806_B.add_b =
      mcb_pmsm_foc_sensorless_f2806_B.sqrt3_by_two -
      mcb_pmsm_foc_sensorless_f2806_B.one_by_two;

    /* MinMax: '<S65>/Min' */
    Product_am = mcb_pmsm_foc_sensorless_f2806_B.algDD_o1;
    V_q_ref_unsat = mcb_pmsm_foc_sensorless_f2806_B.add_b;
    if ((Product_am <= V_q_ref_unsat) || rtIsNaNF(V_q_ref_unsat)) {
      V_q_ref_unsat = Product_am;
    }

    Product_am = mcb_pmsm_foc_sensorless_f2806_B.add_c;
    if ((!(V_q_ref_unsat <= Product_am)) && (!rtIsNaNF(Product_am))) {
      V_q_ref_unsat = Product_am;
    }

    /* MinMax: '<S65>/Min' */
    mcb_pmsm_foc_sensorless_f2806_B.Min = V_q_ref_unsat;

    /* MinMax: '<S65>/Max' */
    Product_am = mcb_pmsm_foc_sensorless_f2806_B.algDD_o1;
    V_q_ref_unsat = mcb_pmsm_foc_sensorless_f2806_B.add_b;
    if ((Product_am >= V_q_ref_unsat) || rtIsNaNF(V_q_ref_unsat)) {
      V_q_ref_unsat = Product_am;
    }

    Product_am = mcb_pmsm_foc_sensorless_f2806_B.add_c;
    if ((!(V_q_ref_unsat >= Product_am)) && (!rtIsNaNF(Product_am))) {
      V_q_ref_unsat = Product_am;
    }

    /* MinMax: '<S65>/Max' */
    mcb_pmsm_foc_sensorless_f2806_B.Max = V_q_ref_unsat;

    /* Sum: '<S65>/Add' */
    mcb_pmsm_foc_sensorless_f2806_B.Add_i = mcb_pmsm_foc_sensorless_f2806_B.Max
      + mcb_pmsm_foc_sensorless_f2806_B.Min;

    /* Gain: '<S65>/one_by_two' */
    mcb_pmsm_foc_sensorless_f2806_B.one_by_two_d = -0.5F *
      mcb_pmsm_foc_sensorless_f2806_B.Add_i;

    /* Sum: '<S64>/Add3' */
    mcb_pmsm_foc_sensorless_f2806_B.Add3 =
      mcb_pmsm_foc_sensorless_f2806_B.algDD_o1 +
      mcb_pmsm_foc_sensorless_f2806_B.one_by_two_d;

    /* Sum: '<S64>/Add2' */
    mcb_pmsm_foc_sensorless_f2806_B.Add2 =
      mcb_pmsm_foc_sensorless_f2806_B.one_by_two_d +
      mcb_pmsm_foc_sensorless_f2806_B.add_c;

    /* Sum: '<S64>/Add1' */
    mcb_pmsm_foc_sensorless_f2806_B.Add1_b =
      mcb_pmsm_foc_sensorless_f2806_B.add_b +
      mcb_pmsm_foc_sensorless_f2806_B.one_by_two_d;

    /* Gain: '<S64>/Gain' */
    mcb_pmsm_foc_sensorless_f2806_B.Gain_c[0] = 1.15470052F *
      mcb_pmsm_foc_sensorless_f2806_B.Add3;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_c[1] = 1.15470052F *
      mcb_pmsm_foc_sensorless_f2806_B.Add1_b;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_c[2] = 1.15470052F *
      mcb_pmsm_foc_sensorless_f2806_B.Add2;

    /* Gain: '<S14>/Gain' */
    V_q_ref_unsat = 0.5F * mcb_pmsm_foc_sensorless_f2806_B.Gain_c[0];
    mcb_pmsm_foc_sensorless_f2806_B.Gain_c1[0] = V_q_ref_unsat;

    /* Sum: '<S14>/Sum' incorporates:
     *  Constant: '<S14>/Constant'
     */
    V_q_ref_unsat += 0.5F;
    mcb_pmsm_foc_sensorless_f2806_B.PWM_Duty_Cycles[0] = V_q_ref_unsat;

    /* Gain: '<S298>/Scale_to_PWM_Counter_PRD' */
    Data = (uint16_T)(2250.0F * V_q_ref_unsat);
    mcb_pmsm_foc_sensorless_f2806_B.Scale_to_PWM_Counter_PRD[0] = Data;

    /* Switch: '<S298>/Switch1' */
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_c[0] = Data;

    /* Gain: '<S14>/Gain' */
    V_q_ref_unsat = 0.5F * mcb_pmsm_foc_sensorless_f2806_B.Gain_c[1];
    mcb_pmsm_foc_sensorless_f2806_B.Gain_c1[1] = V_q_ref_unsat;

    /* Sum: '<S14>/Sum' incorporates:
     *  Constant: '<S14>/Constant'
     */
    V_q_ref_unsat += 0.5F;
    mcb_pmsm_foc_sensorless_f2806_B.PWM_Duty_Cycles[1] = V_q_ref_unsat;

    /* Gain: '<S298>/Scale_to_PWM_Counter_PRD' */
    Data = (uint16_T)(2250.0F * V_q_ref_unsat);
    mcb_pmsm_foc_sensorless_f2806_B.Scale_to_PWM_Counter_PRD[1] = Data;

    /* Switch: '<S298>/Switch1' */
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_c[1] = Data;

    /* Gain: '<S14>/Gain' */
    V_q_ref_unsat = 0.5F * mcb_pmsm_foc_sensorless_f2806_B.Gain_c[2];
    mcb_pmsm_foc_sensorless_f2806_B.Gain_c1[2] = V_q_ref_unsat;

    /* Sum: '<S14>/Sum' incorporates:
     *  Constant: '<S14>/Constant'
     */
    V_q_ref_unsat += 0.5F;
    mcb_pmsm_foc_sensorless_f2806_B.PWM_Duty_Cycles[2] = V_q_ref_unsat;

    /* Gain: '<S298>/Scale_to_PWM_Counter_PRD' */
    Data = (uint16_T)(2250.0F * V_q_ref_unsat);
    mcb_pmsm_foc_sensorless_f2806_B.Scale_to_PWM_Counter_PRD[2] = Data;

    /* Switch: '<S298>/Switch1' */
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_c[2] = Data;
  } else {
    /* Switch: '<S298>/Switch1' incorporates:
     *  Constant: '<S298>/stop'
     */
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_c[0] = 0U;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_c[1] = 0U;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_c[2] = 0U;
  }

  /* End of Switch: '<S298>/Switch1' */

  /* S-Function (c2802xpwm): '<S298>/ePWM1' */
  uint16_T tbprdValue1Outputs = EPwm1Regs.TBPRD;

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)
      (mcb_pmsm_foc_sensorless_f2806_B.Switch1_c[0]);
  }

  /* S-Function (c2802xpwm): '<S298>/ePWM2' */
  uint16_T tbprdValue2Outputs = EPwm2Regs.TBPRD;

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.half.CMPA = (uint16_T)
      (mcb_pmsm_foc_sensorless_f2806_B.Switch1_c[1]);
  }

  /* S-Function (c2802xpwm): '<S298>/ePWM3' */
  uint16_T tbprdValue3Outputs = EPwm3Regs.TBPRD;

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.half.CMPA = (uint16_T)
      (mcb_pmsm_foc_sensorless_f2806_B.Switch1_c[2]);
  }

  /* SignalConversion generated from: '<S1>/Speed_meas_PU' */
  mcb_pmsm_foc_sensorless_f2806_B.Speed_fb_PU =
    mcb_pmsm_foc_sensorless_f2806_B.Merge_k[1];

  /* SignalConversion generated from: '<S1>/Delay5' */
  mcb_pmsm_foc_sensorless_f2806_B.TmpSignalConversionAtDelay5Inpo[0] =
    mcb_pmsm_foc_sensorless_f2806_B.algDD_o1;
  mcb_pmsm_foc_sensorless_f2806_B.TmpSignalConversionAtDelay5Inpo[1] =
    mcb_pmsm_foc_sensorless_f2806_B.algDD_o2;
  mcb_pmsm_foc_sensorless_f2806_B.TmpSignalConversionAtDelay5Inpo[2] =
    mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap.algDD_o1;
  mcb_pmsm_foc_sensorless_f2806_B.TmpSignalConversionAtDelay5Inpo[3] =
    mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap.algDD_o2;

  /* Update for Delay: '<S1>/Delay5' */
  mcb_pmsm_foc_sensorless_f_DWork.Delay5_DSTATE[0] =
    mcb_pmsm_foc_sensorless_f2806_B.TmpSignalConversionAtDelay5Inpo[0];
  mcb_pmsm_foc_sensorless_f_DWork.Delay5_DSTATE[1] =
    mcb_pmsm_foc_sensorless_f2806_B.TmpSignalConversionAtDelay5Inpo[1];
  mcb_pmsm_foc_sensorless_f_DWork.Delay5_DSTATE[2] =
    mcb_pmsm_foc_sensorless_f2806_B.TmpSignalConversionAtDelay5Inpo[2];
  mcb_pmsm_foc_sensorless_f_DWork.Delay5_DSTATE[3] =
    mcb_pmsm_foc_sensorless_f2806_B.TmpSignalConversionAtDelay5Inpo[3];

  /* Update for Delay: '<S50>/Delay' incorporates:
   *  Constant: '<S50>/Constant'
   */
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_d = true;

  /* Update for Delay: '<S19>/Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.icLoad = false;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE =
    mcb_pmsm_foc_sensorless_f2806_B.Add1_f;

  /* Update for UnitDelay: '<S46>/Unit Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_g =
    mcb_pmsm_foc_sensorless_f2806_B.Add1_l;

  /* Update for UnitDelay: '<S69>/Output' */
  mcb_pmsm_foc_sensorless_f_DWork.Output_DSTATE =
    mcb_pmsm_foc_sensorless_f2806_B.FixPtSwitch;
}

/* System initialize for atomic system: */
void mcb__SPIMasterTransfer_Init(rtDW_SPIMasterTransfer_mcb_pmsm *localDW)
{
  uint32_T SPIPinsLoc;

  /* Start for MATLABSystem: '<S311>/SPI Master Transfer' */
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

  /* MATLABSystem: '<S311>/SPI Master Transfer' */
  MW_SPI_SetSlaveSelect(localDW->obj.MW_SPI_HANDLE, 0U, true);
  status = MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
    MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  if (status == 0U) {
    MW_SPI_MasterWriteRead_8bits(localDW->obj.MW_SPI_HANDLE, &rtu_0, &rdDataRaw,
      1UL);
  }

  /* MATLABSystem: '<S311>/SPI Master Transfer' */
  localB->SPIMasterTransfer = rdDataRaw;
}

/* Termination for atomic system: */
void mcb__SPIMasterTransfer_Term(rtDW_SPIMasterTransfer_mcb_pmsm *localDW)
{
  uint32_T SPIPinsLoc;

  /* Terminate for MATLABSystem: '<S311>/SPI Master Transfer' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, MW_UNDEFINED_VALUE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S311>/SPI Master Transfer' */
}

/* System initialize for atomic system: '<Root>/Speed Control' */
void mcb_pmsm__SpeedControl_Init(rtDW_SpeedControl_mcb_pmsm_foc_ *localDW)
{
  /* InitializeConditions for RateLimiter: '<S326>/Rate Limiter' */
  localDW->PrevY = 0.2F;

  /* InitializeConditions for RateLimiter: '<S326>/Rate Limiter1' */
  localDW->PrevY_f = -0.2F;

  /* SystemInitialize for MATLAB Function: '<S325>/MATLAB Function' */
  localDW->integrator_state = 0.0F;
}

/* Output and update for atomic system: '<Root>/Speed Control' */
void mcb_pmsm_foc_s_SpeedControl(real32_T rtu_Speed_Ref_PU, real32_T
  rtu_Speed_Meas_PU, const boolean_T *rtd_EnClosedLoop, const boolean_T
  *rtd_Enable, const real32_T *rtd_Iq_ref_initial,
  rtB_SpeedControl_mcb_pmsm_foc_s *localB, rtDW_SpeedControl_mcb_pmsm_foc_
  *localDW)
{
  real32_T I_q_ref_unsat;
  real32_T y;

  /* DataStoreRead: '<S325>/Data Store Read1' */
  localB->DataStoreRead1 = *rtd_Enable;

  /* DataStoreRead: '<S325>/Data Store Read2' */
  localB->DataStoreRead2 = *rtd_EnClosedLoop;

  /* Logic: '<S325>/AND' */
  localB->AND = (localB->DataStoreRead1 && localB->DataStoreRead2);

  /* DataStoreRead: '<S325>/Data Store Read3' */
  localB->Iq_switch_mem = *rtd_Iq_ref_initial;

  /* Logic: '<S325>/Logical Operator' */
  localB->LogicalOperator = !localB->AND;

  /* RateLimiter: '<S326>/Rate Limiter' */
  I_q_ref_unsat = rtu_Speed_Ref_PU - localDW->PrevY;
  if (I_q_ref_unsat > 0.000993246F) {
    /* RateLimiter: '<S326>/Rate Limiter' */
    localB->RateLimiter = localDW->PrevY + 0.000993246F;
  } else if (I_q_ref_unsat < -0.000993246F) {
    /* RateLimiter: '<S326>/Rate Limiter' */
    localB->RateLimiter = localDW->PrevY - 0.000993246F;
  } else {
    /* RateLimiter: '<S326>/Rate Limiter' */
    localB->RateLimiter = rtu_Speed_Ref_PU;
  }

  localDW->PrevY = localB->RateLimiter;

  /* End of RateLimiter: '<S326>/Rate Limiter' */

  /* RateLimiter: '<S326>/Rate Limiter1' */
  I_q_ref_unsat = rtu_Speed_Ref_PU - localDW->PrevY_f;
  if (I_q_ref_unsat > 0.000993246F) {
    /* RateLimiter: '<S326>/Rate Limiter1' */
    localB->RateLimiter1 = localDW->PrevY_f + 0.000993246F;
  } else if (I_q_ref_unsat < -0.000993246F) {
    /* RateLimiter: '<S326>/Rate Limiter1' */
    localB->RateLimiter1 = localDW->PrevY_f - 0.000993246F;
  } else {
    /* RateLimiter: '<S326>/Rate Limiter1' */
    localB->RateLimiter1 = rtu_Speed_Ref_PU;
  }

  localDW->PrevY_f = localB->RateLimiter1;

  /* End of RateLimiter: '<S326>/Rate Limiter1' */

  /* Switch: '<S326>/Switch' */
  if (rtu_Speed_Ref_PU >= 0.0F) {
    /* Switch: '<S326>/Switch' */
    localB->Switch = localB->RateLimiter;
  } else {
    /* Switch: '<S326>/Switch' */
    localB->Switch = localB->RateLimiter1;
  }

  /* End of Switch: '<S326>/Switch' */

  /* Switch: '<S329>/Switch1' incorporates:
   *  Constant: '<S329>/FilterConstant'
   *  Constant: '<S329>/OneMinusFilterConstant'
   */
  localB->Switch1[0] = 0.1F;
  localB->Switch1[1] = 0.9F;

  /* Product: '<S386>/Product' */
  localB->Product = localB->Switch * 0.1F;

  /* UnitDelay: '<S386>/Unit Delay' */
  localB->UnitDelay = localDW->UnitDelay_DSTATE;

  /* Product: '<S386>/Product1' */
  localB->Product1 = 0.9F * localB->UnitDelay;

  /* Sum: '<S386>/Add1' */
  localB->Add1 = localB->Product + localB->Product1;

  /* Sum: '<S325>/Sum' */
  localB->Sum = localB->Add1 - rtu_Speed_Meas_PU;

  /* Product: '<S325>/Product' */
  localB->Product_g = 0.0F * localB->Sum;

  /* Sum: '<S325>/Sum1' */
  localB->Sum1 = localB->Iq_switch_mem - localB->Product_g;

  /* MATLAB Function: '<S325>/MATLAB Function' incorporates:
   *  Constant: '<S325>/Ki1'
   *  Constant: '<S325>/Kp1'
   */
  /* MATLAB Function 'Speed Control/PI_Controller_Speed/MATLAB Function': '<S328>:1' */
  if (localB->LogicalOperator) {
    /* '<S328>:1:21' */
    /* '<S328>:1:22' */
    localDW->integrator_state = localB->Sum1;
  }

  /* '<S328>:1:26' */
  /* '<S328>:1:29' */
  localDW->integrator_state += 0.0699827299F * localB->Sum;

  /* '<S328>:1:32' */
  I_q_ref_unsat = 3.27852678F * localB->Sum + localDW->integrator_state;

  /* '<S328>:1:35' */
  if (I_q_ref_unsat <= 1.0F) {
    y = I_q_ref_unsat;
  } else {
    y = 1.0F;
  }

  if (y >= -1.0F) {
    localB->I_q_ref = y;
  } else {
    localB->I_q_ref = -1.0F;
  }

  if (localB->I_q_ref != I_q_ref_unsat) {
    /* '<S328>:1:38' */
    /* '<S328>:1:39' */
    localDW->integrator_state -= 0.0699827299F * localB->Sum;
  }

  /* End of MATLAB Function: '<S325>/MATLAB Function' */

  /* Update for UnitDelay: '<S386>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->Add1;
}

/* Output and update for function-call system: '<S388>/RunMode.ComputeId0' */
void mcb_pmsm__RunModeComputeId0(real32_T rtu_Id0_in, real32_T
  rtu_RAMP_STEP_SIZE, rtB_RunModeComputeId0_mcb_pmsm_ *localB)
{
  /* Sum: '<S407>/Sum' */
  localB->Sum = rtu_Id0_in - rtu_RAMP_STEP_SIZE;

  /* RelationalOperator: '<S408>/Compare' incorporates:
   *  Constant: '<S408>/Constant'
   */
  localB->Compare = (localB->Sum > 0.001F);

  /* Switch: '<S407>/Switch' */
  if (localB->Compare) {
    /* Switch: '<S407>/Switch' */
    localB->Switch = localB->Sum;
  } else {
    /* Switch: '<S407>/Switch' incorporates:
     *  Constant: '<S407>/Constant'
     */
    localB->Switch = 0.0F;
  }

  /* End of Switch: '<S407>/Switch' */
}

/* Model step function for TID0 */
void mcb_pmsm_foc_sensorless_f28069MLaunchPad_step0(void) /* Sample time: [0.0005s, 0.0s] */
{
  uint32_T Sum;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T out;

  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<S8>/RT5' */
  mcb_pmsm_foc_sensorless_f2806_B.RT5 =
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion3_b;

  /* RateTransition: '<S8>/RT6' */
  mcb_pmsm_foc_sensorless_f_DWork.RT6_semaphoreTaken =
    mcb_pmsm_foc_sensorless_f_DWork.RT6_ActiveBufIdx;

  /* RateTransition: '<S8>/RT6' */
  mcb_pmsm_foc_sensorless_f2806_B.SpdCmd =
    mcb_pmsm_foc_sensorless_f_DWork.RT6_Buffer[mcb_pmsm_foc_sensorless_f_DWork.RT6_semaphoreTaken];

  /* UnitDelay: '<S8>/Unit Delay' */
  mcb_pmsm_foc_sensorless_f2806_B.UnitDelay =
    mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE;

  /* Chart: '<S8>/State Machine OL - CL' */
  /* Gateway: State Machine Handler/State Machine OL - CL */
  if (mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 < MAX_uint16_T) {
    mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1++;
  }

  /* During: State Machine Handler/State Machine OL - CL */
  if (mcb_pmsm_foc_sensorless_f_DWork.is_active_c3_mcb_pmsm_foc_senso == 0U) {
    /* Entry: State Machine Handler/State Machine OL - CL */
    mcb_pmsm_foc_sensorless_f_DWork.is_active_c3_mcb_pmsm_foc_senso = 1U;

    /* Entry Internal: State Machine Handler/State Machine OL - CL */
    /* Transition: '<S388>:39' */
    mcb_pmsm_foc_sensorless_f_DWork.is_c3_mcb_pmsm_foc_sensorless_f =
      mcb_pmsm_foc_sensorless_IN_Halt;

    /* Entry 'Halt': '<S388>:25' */
    mcb_pmsm_foc_sensorless_f2806_B.Enable = false;
    mcb_pmsm_foc_sensorless_f2806_B.SpdRef = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = false;
  } else if (mcb_pmsm_foc_sensorless_f_DWork.is_c3_mcb_pmsm_foc_sensorless_f ==
             1U) {
    mcb_pmsm_foc_sensorless_f2806_B.Enable = false;
    mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = false;

    /* During 'Halt': '<S388>:25' */
    out = (mcb_pmsm_foc_sensorless_f2806_B.RT5 &&
           (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd != 0.0F));
    if (out) {
      /* Transition: '<S388>:30' */
      mcb_pmsm_foc_sensorless_f_DWork.is_c3_mcb_pmsm_foc_sensorless_f =
        mcb_pmsm_foc_sensorl_IN_RunMode;

      /* Entry 'RunMode': '<S388>:24' */
      /* Entry Internal 'RunMode': '<S388>:24' */
      /* Transition: '<S388>:37' */
      mcb_pmsm_foc_sensorless_f_DWork.is_RunMode =
        mcb_pmsm_foc_IN_InitOpenLoopRun;

      /* Entry 'InitOpenLoopRun': '<S388>:36' */
      mcb_pmsm_foc_sensorless_f2806_B.Enable = true;
      mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = false;
    }
  } else {
    /* During 'RunMode': '<S388>:24' */
    out = ((!mcb_pmsm_foc_sensorless_f2806_B.RT5) ||
           (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd == 0.0F));
    if (out) {
      /* Transition: '<S388>:31' */
      /* Exit Internal 'RunMode': '<S388>:24' */
      /* Exit Internal 'NegativeSpeedRun': '<S388>:146' */
      mcb_pmsm_foc_sensorless_f_DWork.is_NegativeSpeedRun =
        mcb_pmsm_foc_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'PositiveSpeedRun': '<S388>:156' */
      mcb_pmsm_foc_sensorless_f_DWork.is_PositiveSpeedRun =
        mcb_pmsm_foc_IN_NO_ACTIVE_CHILD;
      mcb_pmsm_foc_sensorless_f_DWork.is_RunMode =
        mcb_pmsm_foc_IN_NO_ACTIVE_CHILD;

      /* Exit 'RunMode': '<S388>:24' */
      mcb_pmsm_foc_sensorless_f_DWork.is_c3_mcb_pmsm_foc_sensorless_f =
        mcb_pmsm_foc_sensorless_IN_Halt;

      /* Entry 'Halt': '<S388>:25' */
      mcb_pmsm_foc_sensorless_f2806_B.Enable = false;
      mcb_pmsm_foc_sensorless_f2806_B.SpdRef = 0.0F;
      mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = false;
    } else {
      guard1 = false;
      guard2 = false;
      switch (mcb_pmsm_foc_sensorless_f_DWork.is_RunMode) {
       case mcb_pmsm_foc_IN_InitOpenLoopRun:
        mcb_pmsm_foc_sensorless_f2806_B.Enable = true;
        mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = false;

        /* During 'InitOpenLoopRun': '<S388>:36' */
        if (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd > 0.0F) {
          /* Transition: '<S388>:83' */
          mcb_pmsm_foc_sensorless_f_DWork.is_RunMode =
            mcb_pmsm_fo_IN_PositiveSpeedRun;
          mcb_pmsm_foc_sensorless_f_DWork.is_PositiveSpeedRun =
            mcb_pmsm_foc__IN_OpenLoopPosRun;

          /* Entry 'OpenLoopPosRun': '<S388>:82' */
        } else if (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd < 0.0F) {
          /* Transition: '<S388>:115' */
          mcb_pmsm_foc_sensorless_f_DWork.is_RunMode =
            mcb_pmsm_fo_IN_NegativeSpeedRun;
          mcb_pmsm_foc_sensorless_f_DWork.is_NegativeSpeedRun =
            mcb_pmsm_foc__IN_OpenLoopNegRun;

          /* Entry 'OpenLoopNegRun': '<S388>:112' */
        } else {
          if (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd > 0.2F) {
            mcb_pmsm_foc_sensorless_f2806_B.SpdRef = 0.2F;
          } else if (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd < -0.2F) {
            mcb_pmsm_foc_sensorless_f2806_B.SpdRef = -0.2F;
          } else {
            mcb_pmsm_foc_sensorless_f2806_B.SpdRef =
              mcb_pmsm_foc_sensorless_f2806_B.SpdCmd;
          }

          mcb_pmsm_foc_sensorless_f2806_B.Id0_out =
            mcb_pmsm_foc_sensorless_f2806_B.UnitDelay;
        }
        break;

       case mcb_pmsm_fo_IN_NegativeSpeedRun:
        /* During 'NegativeSpeedRun': '<S388>:146' */
        switch (mcb_pmsm_foc_sensorless_f_DWork.is_NegativeSpeedRun) {
         case mcb_pmsm_f_IN_ClosedLoopRun_NEG:
          /* During 'ClosedLoopRun_NEG': '<S388>:132' */
          if (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd > -0.15F) {
            /* Transition: '<S388>:141' */
            mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 = 0U;
            mcb_pmsm_foc_sensorless_f_DWork.is_NegativeSpeedRun =
              mcb_p_IN_TransferToOpenLoop_NEG;

            /* Entry 'TransferToOpenLoop_NEG': '<S388>:140' */
            mcb_pmsm_foc_sensorless_f2806_B.SpdRef = -0.206F;
          } else {
            mcb_pmsm_foc_sensorless_f2806_B.SpdRef =
              mcb_pmsm_foc_sensorless_f2806_B.SpdCmd;
          }
          break;

         case mcb_pmsm_foc__IN_OpenLoopNegRun:
          /* During 'OpenLoopNegRun': '<S388>:112' */
          /* Transition: '<S388>:122' */
          if (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd > 0.0F) {
            /* Transition: '<S388>:123' */
            mcb_pmsm_foc_sensorless_f_DWork.is_NegativeSpeedRun =
              mcb_pmsm_foc_IN_NO_ACTIVE_CHILD;
            mcb_pmsm_foc_sensorless_f_DWork.is_RunMode =
              mcb_pmsm_fo_IN_PositiveSpeedRun;
            mcb_pmsm_foc_sensorless_f_DWork.is_PositiveSpeedRun =
              mcb_pmsm_foc__IN_OpenLoopPosRun;

            /* Entry 'OpenLoopPosRun': '<S388>:82' */
          } else if (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd < -0.2F) {
            /* Transition: '<S388>:125' */
            if (mcb_pmsm_foc_sensorless_f2806_B.SpdRef > -0.2F) {
              /* Transition: '<S388>:128' */
              mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 = 0U;
              mcb_pmsm_foc_sensorless_f_DWork.is_NegativeSpeedRun =
                mcb_pmsm__IN_PrepareNegCLSwitch;

              /* Entry 'PrepareNegCLSwitch': '<S388>:127' */
              mcb_pmsm_foc_sensorless_f2806_B.Id0_out =
                mcb_pmsm_foc_sensorless_f2806_B.UnitDelay;
              mcb_pmsm_foc_sensorless_f2806_B.SpdRef = -0.2F;
            } else if (mcb_pmsm_foc_sensorless_f2806_B.SpdRef <= -0.2F) {
              /* Transition: '<S388>:130' */
              mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 = 0U;
              mcb_pmsm_foc_sensorless_f_DWork.is_NegativeSpeedRun =
                mcb__IN_TransferToNegClosedLoop;

              /* Entry 'TransferToNegClosedLoop': '<S388>:129' */
              mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = true;
              mcb_pmsm_foc_sensorless_f2806_B.Id0_out =
                mcb_pmsm_foc_sensorless_f2806_B.UnitDelay;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }
          break;

         case mcb_pmsm__IN_PrepareNegCLSwitch:
          /* During 'PrepareNegCLSwitch': '<S388>:127' */
          if (mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 >= 2000U) {
            /* Transition: '<S388>:131' */
            mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 = 0U;
            mcb_pmsm_foc_sensorless_f_DWork.is_NegativeSpeedRun =
              mcb__IN_TransferToNegClosedLoop;

            /* Entry 'TransferToNegClosedLoop': '<S388>:129' */
            mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = true;
            mcb_pmsm_foc_sensorless_f2806_B.Id0_out =
              mcb_pmsm_foc_sensorless_f2806_B.UnitDelay;
          }
          break;

         case mcb__IN_TransferToNegClosedLoop:
          mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = true;

          /* During 'TransferToNegClosedLoop': '<S388>:129' */
          out = ((mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 >= 4000U) &&
                 (mcb_pmsm_foc_sensorless_f2806_B.Id0_out <= 0.001F));
          if (out) {
            /* Transition: '<S388>:133' */
            mcb_pmsm_foc_sensorless_f_DWork.is_NegativeSpeedRun =
              mcb_pmsm_f_IN_ClosedLoopRun_NEG;

            /* Entry 'ClosedLoopRun_NEG': '<S388>:132' */
            mcb_pmsm_foc_sensorless_f2806_B.SpdRef =
              mcb_pmsm_foc_sensorless_f2806_B.SpdCmd;
            mcb_pmsm_foc_sensorless_f2806_B.Id0_out = 0.0F;
          } else {
            mcb_pmsm_foc_sensorless_f2806_B.Id0_in =
              mcb_pmsm_foc_sensorless_f2806_B.Id0_out;
            mcb_pmsm_foc_sensorless_f2806_B.RAMP_STEP_SIZE = 0.001F;

            /* Outputs for Function Call SubSystem: '<S388>/RunMode.ComputeId0' */
            /* Simulink Function 'ComputeId0': '<S388>:103' */
            mcb_pmsm__RunModeComputeId0(mcb_pmsm_foc_sensorless_f2806_B.Id0_in,
              mcb_pmsm_foc_sensorless_f2806_B.RAMP_STEP_SIZE,
              &mcb_pmsm_foc_sensorless_f2806_B.RunModeComputeId0);

            /* End of Outputs for SubSystem: '<S388>/RunMode.ComputeId0' */
            mcb_pmsm_foc_sensorless_f2806_B.Id0_out =
              mcb_pmsm_foc_sensorless_f2806_B.RunModeComputeId0.Switch;
          }
          break;

         default:
          /* During 'TransferToOpenLoop_NEG': '<S388>:140' */
          if (mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 >= 2000U) {
            /* Transition: '<S388>:142' */
            mcb_pmsm_foc_sensorless_f_DWork.is_NegativeSpeedRun =
              mcb_pmsm_foc_IN_NO_ACTIVE_CHILD;
            mcb_pmsm_foc_sensorless_f_DWork.is_RunMode =
              mcb_pmsm_foc_IN_InitOpenLoopRun;

            /* Entry 'InitOpenLoopRun': '<S388>:36' */
            mcb_pmsm_foc_sensorless_f2806_B.Enable = true;
            mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = false;
          }
          break;
        }
        break;

       default:
        /* During 'PositiveSpeedRun': '<S388>:156' */
        switch (mcb_pmsm_foc_sensorless_f_DWork.is_PositiveSpeedRun) {
         case mcb_pmsm_fo_IN_ClosedLoopPosRun:
          /* During 'ClosedLoopPosRun': '<S388>:55' */
          if (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd < 0.15F) {
            /* Transition: '<S388>:46' */
            mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 = 0U;
            mcb_pmsm_foc_sensorless_f_DWork.is_PositiveSpeedRun =
              mcb_pmsm__IN_TransferToOpenLoop;

            /* Entry 'TransferToOpenLoop': '<S388>:80' */
            mcb_pmsm_foc_sensorless_f2806_B.SpdRef = 0.206F;
          } else {
            mcb_pmsm_foc_sensorless_f2806_B.SpdRef =
              mcb_pmsm_foc_sensorless_f2806_B.SpdCmd;
          }
          break;

         case mcb_pmsm_foc__IN_OpenLoopPosRun:
          /* During 'OpenLoopPosRun': '<S388>:82' */
          /* Transition: '<S388>:119' */
          if (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd > 0.2F) {
            /* Transition: '<S388>:75' */
            if (mcb_pmsm_foc_sensorless_f2806_B.SpdRef >= 0.2F) {
              /* Transition: '<S388>:95' */
              mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 = 0U;
              mcb_pmsm_foc_sensorless_f_DWork.is_PositiveSpeedRun =
                mcb__IN_TransferToPosClosedLoop;

              /* Entry 'TransferToPosClosedLoop': '<S388>:40' */
              mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = true;
              mcb_pmsm_foc_sensorless_f2806_B.Id0_out =
                mcb_pmsm_foc_sensorless_f2806_B.UnitDelay;
            } else if (mcb_pmsm_foc_sensorless_f2806_B.SpdRef < 0.2F) {
              /* Transition: '<S388>:97' */
              mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 = 0U;
              mcb_pmsm_foc_sensorless_f_DWork.is_PositiveSpeedRun =
                mcb_pmsm__IN_PreparePosCLSwitch;

              /* Entry 'PreparePosCLSwitch': '<S388>:96' */
              mcb_pmsm_foc_sensorless_f2806_B.Id0_out =
                mcb_pmsm_foc_sensorless_f2806_B.UnitDelay;
              mcb_pmsm_foc_sensorless_f2806_B.SpdRef = 0.2F;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }
          break;

         case mcb_pmsm__IN_PreparePosCLSwitch:
          /* During 'PreparePosCLSwitch': '<S388>:96' */
          if (mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 >= 2000U) {
            /* Transition: '<S388>:98' */
            mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 = 0U;
            mcb_pmsm_foc_sensorless_f_DWork.is_PositiveSpeedRun =
              mcb__IN_TransferToPosClosedLoop;

            /* Entry 'TransferToPosClosedLoop': '<S388>:40' */
            mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = true;
            mcb_pmsm_foc_sensorless_f2806_B.Id0_out =
              mcb_pmsm_foc_sensorless_f2806_B.UnitDelay;
          }
          break;

         case mcb_pmsm__IN_TransferToOpenLoop:
          /* During 'TransferToOpenLoop': '<S388>:80' */
          if (mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 >= 2000U) {
            /* Transition: '<S388>:81' */
            mcb_pmsm_foc_sensorless_f_DWork.is_PositiveSpeedRun =
              mcb_pmsm_foc_IN_NO_ACTIVE_CHILD;
            mcb_pmsm_foc_sensorless_f_DWork.is_RunMode =
              mcb_pmsm_foc_IN_InitOpenLoopRun;

            /* Entry 'InitOpenLoopRun': '<S388>:36' */
            mcb_pmsm_foc_sensorless_f2806_B.Enable = true;
            mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = false;
          }
          break;

         default:
          mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = true;

          /* During 'TransferToPosClosedLoop': '<S388>:40' */
          out = ((mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 >= 4000U) &&
                 (mcb_pmsm_foc_sensorless_f2806_B.Id0_out <= 0.001F));
          if (out) {
            /* Transition: '<S388>:56' */
            mcb_pmsm_foc_sensorless_f_DWork.is_PositiveSpeedRun =
              mcb_pmsm_fo_IN_ClosedLoopPosRun;

            /* Entry 'ClosedLoopPosRun': '<S388>:55' */
            mcb_pmsm_foc_sensorless_f2806_B.SpdRef =
              mcb_pmsm_foc_sensorless_f2806_B.SpdCmd;
            mcb_pmsm_foc_sensorless_f2806_B.Id0_out = 0.0F;
          } else {
            mcb_pmsm_foc_sensorless_f2806_B.Id0_in =
              mcb_pmsm_foc_sensorless_f2806_B.Id0_out;
            mcb_pmsm_foc_sensorless_f2806_B.RAMP_STEP_SIZE = 0.001F;

            /* Outputs for Function Call SubSystem: '<S388>/RunMode.ComputeId0' */
            /* Simulink Function 'ComputeId0': '<S388>:103' */
            mcb_pmsm__RunModeComputeId0(mcb_pmsm_foc_sensorless_f2806_B.Id0_in,
              mcb_pmsm_foc_sensorless_f2806_B.RAMP_STEP_SIZE,
              &mcb_pmsm_foc_sensorless_f2806_B.RunModeComputeId0);

            /* End of Outputs for SubSystem: '<S388>/RunMode.ComputeId0' */
            mcb_pmsm_foc_sensorless_f2806_B.Id0_out =
              mcb_pmsm_foc_sensorless_f2806_B.RunModeComputeId0.Switch;
          }
          break;
        }
        break;
      }

      if (guard2) {
        if (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd < -0.2F) {
          mcb_pmsm_foc_sensorless_f2806_B.SpdRef = -0.2F;
        } else {
          mcb_pmsm_foc_sensorless_f2806_B.SpdRef =
            mcb_pmsm_foc_sensorless_f2806_B.SpdCmd;
        }
      }

      if (guard1) {
        if (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd < 0.0F) {
          /* Transition: '<S388>:120' */
          mcb_pmsm_foc_sensorless_f_DWork.is_PositiveSpeedRun =
            mcb_pmsm_foc_IN_NO_ACTIVE_CHILD;
          mcb_pmsm_foc_sensorless_f_DWork.is_RunMode =
            mcb_pmsm_fo_IN_NegativeSpeedRun;
          mcb_pmsm_foc_sensorless_f_DWork.is_NegativeSpeedRun =
            mcb_pmsm_foc__IN_OpenLoopNegRun;

          /* Entry 'OpenLoopNegRun': '<S388>:112' */
        } else if (mcb_pmsm_foc_sensorless_f2806_B.SpdCmd > 0.2F) {
          mcb_pmsm_foc_sensorless_f2806_B.SpdRef = 0.2F;
        } else {
          mcb_pmsm_foc_sensorless_f2806_B.SpdRef =
            mcb_pmsm_foc_sensorless_f2806_B.SpdCmd;
        }
      }
    }
  }

  /* End of Chart: '<S8>/State Machine OL - CL' */

  /* DataStoreWrite: '<S8>/Data Store Write' */
  mcb_pmsm_foc_sensorless_f_DWork.Enable =
    mcb_pmsm_foc_sensorless_f2806_B.Enable;

  /* DataStoreWrite: '<S8>/Data Store Write2' */
  mcb_pmsm_foc_sensorless_f_DWork.EnClosedLoop =
    mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop;

  /* DataStoreWrite: '<S8>/Data Store Write3' */
  mcb_pmsm_foc_sensorless_f_DWork.SpdCtrlRef =
    mcb_pmsm_foc_sensorless_f2806_B.SpdRef;

  /* DataStoreWrite: '<S8>/Data Store Write4' */
  mcb_pmsm_foc_sensorless_f_DWork.Id0_out =
    mcb_pmsm_foc_sensorless_f2806_B.Id0_out;

  /* Logic: '<S8>/NOT' */
  mcb_pmsm_foc_sensorless_f2806_B.NOT =
    !mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop;

  /* Outputs for Enabled SubSystem: '<S8>/Compute Control-loop Initial Values' incorporates:
   *  EnablePort: '<S387>/Enable'
   */
  if (mcb_pmsm_foc_sensorless_f2806_B.NOT) {
    /* DataStoreRead: '<S387>/Data Store Read3' */
    mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead3 =
      mcb_pmsm_foc_sensorless_f_DWork.V_alpha;

    /* DataStoreRead: '<S387>/Data Store Read1' */
    mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1 =
      mcb_pmsm_foc_sensorless_f_DWork.V_beta;

    /* DataStoreRead: '<S387>/Data Store Read2' */
    mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead2 =
      mcb_pmsm_foc_sensorless_f_DWork.Pos_meas_PU;

    /* RelationalOperator: '<S401>/Compare' incorporates:
     *  Constant: '<S401>/Constant'
     */
    mcb_pmsm_foc_sensorless_f2806_B.Compare =
      (mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead2 < 0.0F);

    /* DataTypeConversion: '<S399>/Data Type Conversion' */
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_b =
      mcb_pmsm_foc_sensorless_f2806_B.Compare;

    /* If: '<S399>/If' */
    if (mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_b > 0U) {
      /* Outputs for IfAction SubSystem: '<S399>/If Action Subsystem' incorporates:
       *  ActionPort: '<S402>/Action Port'
       */
      mcb_pmsm__IfActionSubsystem(mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead2,
        &mcb_pmsm_foc_sensorless_f2806_B.Merge,
        &mcb_pmsm_foc_sensorless_f2806_B.IfActionSubsystem_ey);

      /* End of Outputs for SubSystem: '<S399>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S399>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S403>/Action Port'
       */
      mcb_pmsm_IfActionSubsystem1(mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead2,
        &mcb_pmsm_foc_sensorless_f2806_B.Merge,
        &mcb_pmsm_foc_sensorless_f2806_B.IfActionSubsystem1_b);

      /* End of Outputs for SubSystem: '<S399>/If Action Subsystem1' */
    }

    /* End of If: '<S399>/If' */

    /* Gain: '<S397>/indexing' */
    mcb_pmsm_foc_sensorless_f2806_B.indexing = 800.0F *
      mcb_pmsm_foc_sensorless_f2806_B.Merge;

    /* DataTypeConversion: '<S397>/Get_Integer' */
    mcb_pmsm_foc_sensorless_f2806_B.Get_Integer = (uint16_T)
      mcb_pmsm_foc_sensorless_f2806_B.indexing;

    /* Sum: '<S397>/Sum' incorporates:
     *  Constant: '<S397>/offset'
     */
    Sum = mcb_pmsm_foc_sensorless_f2806_B.Get_Integer + 1UL;
    mcb_pmsm_foc_sensorless_f2806_B.Sum[0] = Sum;

    /* Selector: '<S397>/Lookup' incorporates:
     *  Constant: '<S397>/sine_table_values'
     */
    mcb_pmsm_foc_sensorless_f2806_B.Lookup[0] =
      mcb_pmsm_foc_sensorless__ConstP.pooled31[(int16_T)Sum];

    /* Sum: '<S397>/Sum' */
    Sum = mcb_pmsm_foc_sensorless_f2806_B.Get_Integer;
    mcb_pmsm_foc_sensorless_f2806_B.Sum[1] = Sum;

    /* Selector: '<S397>/Lookup' incorporates:
     *  Constant: '<S397>/sine_table_values'
     */
    mcb_pmsm_foc_sensorless_f2806_B.Lookup[1] =
      mcb_pmsm_foc_sensorless__ConstP.pooled31[(int16_T)Sum];

    /* Sum: '<S397>/Sum' incorporates:
     *  Constant: '<S397>/offset'
     */
    Sum = mcb_pmsm_foc_sensorless_f2806_B.Get_Integer + 201UL;
    mcb_pmsm_foc_sensorless_f2806_B.Sum[2] = Sum;

    /* Selector: '<S397>/Lookup' incorporates:
     *  Constant: '<S397>/sine_table_values'
     */
    mcb_pmsm_foc_sensorless_f2806_B.Lookup[2] =
      mcb_pmsm_foc_sensorless__ConstP.pooled31[(int16_T)Sum];

    /* Sum: '<S397>/Sum' incorporates:
     *  Constant: '<S397>/offset'
     */
    Sum = mcb_pmsm_foc_sensorless_f2806_B.Get_Integer + 200UL;
    mcb_pmsm_foc_sensorless_f2806_B.Sum[3] = Sum;

    /* Selector: '<S397>/Lookup' incorporates:
     *  Constant: '<S397>/sine_table_values'
     */
    mcb_pmsm_foc_sensorless_f2806_B.Lookup[3] =
      mcb_pmsm_foc_sensorless__ConstP.pooled31[(int16_T)Sum];

    /* Sum: '<S398>/Sum3' */
    mcb_pmsm_foc_sensorless_f2806_B.Sum3 =
      mcb_pmsm_foc_sensorless_f2806_B.Lookup[0] -
      mcb_pmsm_foc_sensorless_f2806_B.Lookup[1];

    /* DataTypeConversion: '<S397>/Data Type Conversion1' */
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1 =
      mcb_pmsm_foc_sensorless_f2806_B.Get_Integer;

    /* Sum: '<S397>/Sum2' */
    mcb_pmsm_foc_sensorless_f2806_B.Sum2 =
      mcb_pmsm_foc_sensorless_f2806_B.indexing -
      mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1;

    /* Product: '<S398>/Product' */
    mcb_pmsm_foc_sensorless_f2806_B.Product_b =
      mcb_pmsm_foc_sensorless_f2806_B.Sum3 *
      mcb_pmsm_foc_sensorless_f2806_B.Sum2;

    /* Sum: '<S398>/Sum4' */
    mcb_pmsm_foc_sensorless_f2806_B.Sum4 =
      mcb_pmsm_foc_sensorless_f2806_B.Product_b +
      mcb_pmsm_foc_sensorless_f2806_B.Lookup[1];

    /* Sum: '<S398>/Sum5' */
    mcb_pmsm_foc_sensorless_f2806_B.Sum5 =
      mcb_pmsm_foc_sensorless_f2806_B.Lookup[2] -
      mcb_pmsm_foc_sensorless_f2806_B.Lookup[3];

    /* Product: '<S398>/Product1' */
    mcb_pmsm_foc_sensorless_f2806_B.Product1_a =
      mcb_pmsm_foc_sensorless_f2806_B.Sum5 *
      mcb_pmsm_foc_sensorless_f2806_B.Sum2;

    /* Sum: '<S398>/Sum6' */
    mcb_pmsm_foc_sensorless_f2806_B.Sum6 =
      mcb_pmsm_foc_sensorless_f2806_B.Product1_a +
      mcb_pmsm_foc_sensorless_f2806_B.Lookup[3];

    /* Outputs for Atomic SubSystem: '<S392>/Two inputs CRL' */
    mcb_pmsm_foc_s_TwoinputsCRL(mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead3,
      mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1,
      mcb_pmsm_foc_sensorless_f2806_B.Sum4, mcb_pmsm_foc_sensorless_f2806_B.Sum6,
      &mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_j);

    /* End of Outputs for SubSystem: '<S392>/Two inputs CRL' */

    /* DataStoreWrite: '<S387>/Data Store Write1' */
    mcb_pmsm_foc_sensorless_f_DWork.Vd_out_initial =
      mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_j.algDD_o1;

    /* DataStoreWrite: '<S387>/Data Store Write2' */
    mcb_pmsm_foc_sensorless_f_DWork.Vq_out_initial =
      mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_j.algDD_o2;

    /* DataStoreRead: '<S387>/Data Store Read' */
    mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead =
      mcb_pmsm_foc_sensorless_f_DWork.Ia_meas_PU;

    /* DataStoreRead: '<S387>/Data Store Read4' */
    mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead4 =
      mcb_pmsm_foc_sensorless_f_DWork.Ib_meas_PU;

    /* Outputs for Atomic SubSystem: '<S393>/Two phase CRL wrap' */
    mcb_pmsm_fo_TwophaseCRLwrap(mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead,
      mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead4,
      &mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap_b);

    /* End of Outputs for SubSystem: '<S393>/Two phase CRL wrap' */

    /* Outputs for Atomic SubSystem: '<S390>/Two inputs CRL' */
    mcb_pmsm_foc_s_TwoinputsCRL
      (mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap_b.algDD_o1,
       mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap_b.algDD_o2,
       mcb_pmsm_foc_sensorless_f2806_B.Sum4,
       mcb_pmsm_foc_sensorless_f2806_B.Sum6,
       &mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_c);

    /* End of Outputs for SubSystem: '<S390>/Two inputs CRL' */

    /* DataStoreWrite: '<S387>/Data Store Write6' */
    mcb_pmsm_foc_sensorless_f_DWork.Iq_ref_initial =
      mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_c.algDD_o2;
  }

  /* End of Outputs for SubSystem: '<S8>/Compute Control-loop Initial Values' */
  /* RateTransition: '<Root>/RT6' */
  mcb_pmsm_foc_sensorless_f2806_B.RT6 = mcb_pmsm_foc_sensorless_f2806_B.SpdRef;

  /* RateTransition: '<Root>/RT4' */
  mcb_pmsm_foc_sensorless_f_DWork.RT4_semaphoreTaken =
    mcb_pmsm_foc_sensorless_f_DWork.RT4_ActiveBufIdx;

  /* RateTransition: '<Root>/RT4' */
  mcb_pmsm_foc_sensorless_f2806_B.RT4 =
    mcb_pmsm_foc_sensorless_f_DWork.RT4_Buffer[mcb_pmsm_foc_sensorless_f_DWork.RT4_semaphoreTaken];

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */
  mcb_pmsm_foc_s_SpeedControl(mcb_pmsm_foc_sensorless_f2806_B.RT6,
    mcb_pmsm_foc_sensorless_f2806_B.RT4,
    &mcb_pmsm_foc_sensorless_f_DWork.EnClosedLoop,
    &mcb_pmsm_foc_sensorless_f_DWork.Enable,
    &mcb_pmsm_foc_sensorless_f_DWork.Iq_ref_initial,
    &mcb_pmsm_foc_sensorless_f2806_B.SpeedControl,
    &mcb_pmsm_foc_sensorless_f_DWork.SpeedControl);

  /* End of Outputs for SubSystem: '<Root>/Speed Control' */

  /* RateTransition: '<Root>/RT2' */
  mcb_pmsm_foc_sensorless_f_DWork.RT2_Buffer
    [(mcb_pmsm_foc_sensorless_f_DWork.RT2_ActiveBufIdx == 0) << 1U] =
    mcb_pmsm_foc_sensorless_f2806_B.Id0_out;
  mcb_pmsm_foc_sensorless_f_DWork.RT2_Buffer[1 +
    ((mcb_pmsm_foc_sensorless_f_DWork.RT2_ActiveBufIdx == 0) << 1U)] =
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.I_q_ref;
  mcb_pmsm_foc_sensorless_f_DWork.RT2_ActiveBufIdx =
    (mcb_pmsm_foc_sensorless_f_DWork.RT2_ActiveBufIdx == 0);

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE =
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_c.algDD_o1;
}

/* Model step function for TID1 */
void mcb_pmsm_foc_sensorless_f28069MLaunchPad_step1(void) /* Sample time: [0.5s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* S-Function (c280xgpio_do): '<S320>/Digital Output1' incorporates:
   *  Constant: '<S4>/RED_LED'
   */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)((1U) != 0);
  }

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void mcb_pmsm_foc_sensorless_f28069MLaunchPad_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mcb_pmsm_foc_sensorless_f280_M, 0,
                sizeof(RT_MODEL_mcb_pmsm_foc_sensorles));

  /* block I/O */
  (void) memset(((void *) &mcb_pmsm_foc_sensorless_f2806_B), 0,
                sizeof(BlockIO_mcb_pmsm_foc_sensorless));

  {
    mcb_pmsm_foc_sensorless_f2806_B.Product = 0.0;
    mcb_pmsm_foc_sensorless_f2806_B.Add = 0.0;
    mcb_pmsm_foc_sensorless_f2806_B.Product1 = 0.0;
    mcb_pmsm_foc_sensorless_f2806_B.Add1 = 0.0;
    mcb_pmsm_foc_sensorless_f2806_B.qcos = 0.0;
    mcb_pmsm_foc_sensorless_f2806_B.dsin = 0.0;
    mcb_pmsm_foc_sensorless_f2806_B.sum_beta = 0.0;
    mcb_pmsm_foc_sensorless_f2806_B.dcos = 0.0;
    mcb_pmsm_foc_sensorless_f2806_B.qsin = 0.0;
    mcb_pmsm_foc_sensorless_f2806_B.sum_alpha = 0.0;
    mcb_pmsm_foc_sensorless_f2806_B.Unary_Minus = 0.0;
    mcb_pmsm_foc_sensorless_f2806_B.SpdCmd = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.RT6 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.RT4 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.RT2[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.RT2[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpdRef = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Id0_out = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Id0_in = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.RAMP_STEP_SIZE = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead3 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.indexing = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Lookup[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Lookup[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Lookup[2] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Lookup[3] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum3 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum4 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum5 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_a = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum6 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataStoreRead4 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_a[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_a[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Speed_Ref = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_p[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_p[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay5[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay5[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay5[2] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay5[3] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_k[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_k[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Spd_Pos = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_d = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_f = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_c = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.indexing_d = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[2] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_f[3] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum3_b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_c = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum2_e = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum4_h = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum5_l = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_e = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum6_c = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Vq_computed = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_bk = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_j = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Vd_computed1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_e = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_a = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Vd_OpenLoop = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Abs = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_bh = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_n = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_l = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_d = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_jv = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_l = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_o = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_ad = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_e = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_m[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_m[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion_c = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Speed_fb_PU = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TmpSignalConversionAtDelay5Inpo[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TmpSignalConversionAtDelay5Inpo[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TmpSignalConversionAtDelay5Inpo[2] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TmpSignalConversionAtDelay5Inpo[3] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.sqrt3_by_two = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.one_by_two = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.add_c = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.add_b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Min = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Max = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.one_by_two_d = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add3 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_c[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_c[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_c[2] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_c1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_c1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_c1[2] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.PWM_Duty_Cycles[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.PWM_Duty_Cycles[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.PWM_Duty_Cycles[2] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay_f[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay_f[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnaryMinus = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_f = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_k = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_n = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_mr = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_ao = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product3 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product3_n = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_o = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product2_c = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product3_n0 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_c = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_h = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnaryMinus_k = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnaryMinus_f = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product2_a = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_gf = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_kc = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnaryMinus_fm = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain1_o = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnaryMinus1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product2_d = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_j = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnaryMinus_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_f = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_e = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_oz = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product3_nb = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_k = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnaryMinus_j = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_n = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product3_c = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnaryMinus1_b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product5 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product2_o = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product4 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnaryMinus_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product2_f = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_kn = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_gf3 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_h = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_d = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product3_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_j = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_l[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_l[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_n[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_n[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain1_c[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain1_c[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum2_o[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum2_o[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain2[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain2[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_j4[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_j4[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_m[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_m[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_g[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_g[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_j[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_j[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_j[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_j[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_ee[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_ee[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_j[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_j[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_k4 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_o[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_o[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_nv = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_n = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_e2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_f = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge1_o = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_n[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_n[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_gh = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_c = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_l = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay_j = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.indexing_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_m[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_m[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_m[2] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Lookup_m[3] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum5_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_d2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum2_eo = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_nl = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum6_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_la = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum3_n = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_a = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum4_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_dd = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.ProportionalGain = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.IntegralGain = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Integrator = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_d = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.speed = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_e[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_e[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_iq = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_ok = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_h = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_l = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_o = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add_gq = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_l = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_k = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Input = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.In1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay3 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_j[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_j[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_ex = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_d = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_dx = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_fb = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_n = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain1_n = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay2_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay3_a = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_f[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_f[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_k3 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_iy = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_c = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_c = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_m4 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_ci = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain1_l = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_kg = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_pv = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_d[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_d[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_fd = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_ju = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_dq = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_d = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay1_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_mt = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain1_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay_d = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain2_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_a0 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_j2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_n2[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_n2[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_id = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_p0 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_c4 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay1_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_mq = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain1_ng = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay_o = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain2_o = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_h = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_ap = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_o = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.MathFunction = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Abs_k = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay2_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay3_d = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_i[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_i[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_ke = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_gx = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_ag = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain1_gr = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay2_e = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay3_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_b[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_b[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_j5 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_br = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_o = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_gp = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_ed = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain1_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay_f1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay1_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_fq = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_a[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_a[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_md = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_pm = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_cn = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_fo = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Square = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Square1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum2_k = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sqrt = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnaryMinus_b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_ji = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sqrt_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Divide = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Divide1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_dz[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_dz[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_am[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_am[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_am[2] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_am[3] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_a[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_a[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_a[2] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_a[3] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_j[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_j[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_j[2] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_j[3] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_jy[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_jy[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_jy[2] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_jy[3] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[2] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_bf[3] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_c = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum3_k = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay1_pl = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_jy = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_d = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_n5 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_em = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product2_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_eg[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_eg[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_fdo = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_dy = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_k = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_jx = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_iw = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum3_n0 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay1_a = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_ga = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_n3 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay_b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_mn = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product2_b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_as = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_a = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_o[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_o[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_lm = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_e = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_ba = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_h = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DTC = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedGain = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_bs[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_bs[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_pk = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_dk = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_al = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.elect2mech = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_dj = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_ac = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Atan2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_ds = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.algDD = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_f = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_c = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Bias = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.a = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay_k = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum2_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum3_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.b_invg = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay1_e = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum4_b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_jq[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_jq[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_c0 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_ab = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_en = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_dd = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay1_k = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_k = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.a_e = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum2_g2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum3_l = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.b_invg_o = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay1_f = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum4_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_m[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_m[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_p3 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_gx = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_k4 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_gu = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_ku = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge1_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Delay_e = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sign = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Eta = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_gf = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.a_a = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_d = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sign_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Eta_n = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_bl = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.b_i = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.a_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.DTC_e = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedGain_k = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_bp[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_bp[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_i2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.UnitDelay_ci = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_ey = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Add1_cr = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_jt = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product2_il = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum1_mc = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product1_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product3_b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum2_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_cx = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Atan2_n = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_gb = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.algDD_a = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_o = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_m = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Bias_f = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Bias_j = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Input_h = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_f[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_f[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.algDD_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.algDD_o2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.V_q_ref = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Saturation = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.V_d_ref = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_ch[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_ch[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SquareRoot = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_o = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_i[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_i[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product_bp = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sum_a3 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Product2_ao = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Merge_e = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_lx = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch_k = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Switch1_h = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Sqrt_n = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Gain_e = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.RunModeComputeId0.Sum = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.RunModeComputeId0.Switch = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_j.acos_a = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_j.bsin = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_j.sum_Ds = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_j.bcos = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_j.asin_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_j.sum_Qs = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_j.Switch[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_j.Switch[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_j.algDD_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_j.algDD_o2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.IfActionSubsystem1_b.Convert_back = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.IfActionSubsystem_ey.Convert_back = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_c.acos_a = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_c.bsin = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_c.sum_Ds = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_c.bcos = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_c.asin_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_c.sum_Qs = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_c.Switch[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_c.Switch[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_c.algDD_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_c.algDD_o2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap_b.a_plus_2b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap_b.one_by_sqrt3 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap_b.algDD_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap_b.algDD_o2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.Iq_switch_mem = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.RateLimiter = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.RateLimiter1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.Switch = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.Switch1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.Switch1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.Product = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.UnitDelay = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.Product1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.Add1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.Sum = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.Product_g = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.Sum1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.SpeedControl.I_q_ref = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.IfActionSubsystem1_o.Convert_back = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.IfActionSubsystem_e.Convert_back = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.IfActionSubsystem1.Convert_back = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.IfActionSubsystem.Convert_back = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.acos_a = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.bsin = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.sum_Ds = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.bcos = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.asin_p = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.sum_Qs = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.Switch[0] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.Switch[1] = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.algDD_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwoinputsCRL_m.algDD_o2 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap.a_plus_2b = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap.one_by_sqrt3 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap.algDD_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.TwophaseCRLwrap.algDD_o2 = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&mcb_pmsm_foc_sensorless_f_DWork, 0,
                sizeof(D_Work_mcb_pmsm_foc_sensorless_));
  mcb_pmsm_foc_sensorless_f_DWork.Add_DWORK1 = 0.0;
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay5_DSTATE[0] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay5_DSTATE[1] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay5_DSTATE[2] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay5_DSTATE[3] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_g = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_o[0] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_o[1] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_a = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Integrator_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay2_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay3_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay2_DSTATE_i = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay3_DSTATE_b = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_o = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_ao = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_n = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_oe = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay2_DSTATE_c = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay3_DSTATE_d = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay2_DSTATE_p = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay3_DSTATE_ds = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_d5[0] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_d5[1] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_d5[2] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_d5[3] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_e = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_m = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_m = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_m = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_p = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_b = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.UnitDelay_DSTATE_a1 = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_nd = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_l = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_e = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay1_DSTATE_j = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Delay_DSTATE_nm = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.RT6_Buffer[0] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.RT6_Buffer[1] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.RT4_Buffer[0] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.RT4_Buffer[1] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.RT2_Buffer[0] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.RT2_Buffer[1] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.RT2_Buffer[2] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.RT2_Buffer[3] = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Iq_ref_initial = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Ia_meas_PU = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Vd_out_initial = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Vq_out_initial = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Id0_out = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.SpdCtrlRef = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.V_alpha = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.V_beta = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Ib_meas_PU = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.Pos_meas_PU = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.integrator_state = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.integrator_state_a = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.SpeedControl.UnitDelay_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.SpeedControl.PrevY = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.SpeedControl.PrevY_f = 0.0F;
  mcb_pmsm_foc_sensorless_f_DWork.SpeedControl.integrator_state = 0.0F;

  {
    uint16_T s313_iter;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory15' */
    mcb_pmsm_foc_sensorless_f_DWork.Id0_out = 0.1F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory16' */
    mcb_pmsm_foc_sensorless_f_DWork.SpdCtrlRef = 0.1F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    mcb_pmsm_foc_sensorless_f_DWork.IaOffset = 2087U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    mcb_pmsm_foc_sensorless_f_DWork.IbOffset = 2082U;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_ld = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_bl = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_n0 = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_e = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay2_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay3_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay2_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay3_Reset_ZCE_c = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_db = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_gg = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay2_Reset_ZCE = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay3_Reset_ZCE = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay2_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay3_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_m = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE = ZERO_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Dir_Sense_m.Dir_Sense_Trig_ZCE = POS_ZCSIG;
    mcb_pmsm_foc_sen_PrevZCSigState.Dir_Sense.Dir_Sense_Trig_ZCE = POS_ZCSIG;

    /* SystemInitialize for Chart: '<S8>/State Machine OL - CL' */
    mcb_pmsm_foc_sensorless_f_DWork.temporalCounter_i1 = 0U;
    mcb_pmsm_foc_sensorless_f2806_B.Enable = false;
    mcb_pmsm_foc_sensorless_f2806_B.EnClosedLoop = false;
    mcb_pmsm_foc_sensorless_f2806_B.SpdRef = 0.0F;
    mcb_pmsm_foc_sensorless_f2806_B.Id0_out = 0.0F;
    mcb_pmsm_foc_sensorless_f_DWork.is_active_c3_mcb_pmsm_foc_senso = 0U;
    mcb_pmsm_foc_sensorless_f_DWork.is_c3_mcb_pmsm_foc_sensorless_f =
      mcb_pmsm_foc_IN_NO_ACTIVE_CHILD;
    mcb_pmsm_foc_sensorless_f_DWork.is_RunMode = mcb_pmsm_foc_IN_NO_ACTIVE_CHILD;
    mcb_pmsm_foc_sensorless_f_DWork.is_NegativeSpeedRun =
      mcb_pmsm_foc_IN_NO_ACTIVE_CHILD;
    mcb_pmsm_foc_sensorless_f_DWork.is_PositiveSpeedRun =
      mcb_pmsm_foc_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S305>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Current Control'
     */
    mcb_pms_CurrentControl_Init();

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S307>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Serial Receive'
     */
    /* System initialize for function-call system: '<Root>/Serial Receive' */

    /* Start for S-Function (c28xsci_rx): '<S324>/SCI Receive' */

    /* Initialize out port */
    {
      mcb_pmsm_foc_sensorless_f2806_B.SCIReceive[0] = (uint16_T)0.0;
      mcb_pmsm_foc_sensorless_f2806_B.SCIReceive[1] = (uint16_T)0.0;
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
    mcb_pmsm__SpeedControl_Init(&mcb_pmsm_foc_sensorless_f_DWork.SpeedControl);

    /* End of SystemInitialize for SubSystem: '<Root>/Speed Control' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
    /* Start for S-Function (c280xgpio_do): '<S320>/Digital Output1' */
    EALLOW;
    GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
    GpioCtrlRegs.GPBDIR.all |= 0x4U;
    EDIS;

    /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Start for S-Function (c280xgpio_do): '<S311>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPBMUX2.all &= 0xFFFFFFCFU;
    GpioCtrlRegs.GPBDIR.all |= 0x40000U;
    EDIS;

    /* SystemInitialize for Enabled SubSystem: '<S309>/Calculate ADC Offset ' */
    /* SystemInitialize for Iterator SubSystem: '<S310>/For Iterator Subsystem' */
    /* Start for S-Function (c2802xadc): '<S313>/IA//IB Measurement' */
    if (MW_adcInitFlag == 0U) {
      InitAdc();
      MW_adcInitFlag = 1U;
    }

    config_ADC_SOC2_SOC3 ();

    /* End of SystemInitialize for SubSystem: '<S310>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S309>/Calculate ADC Offset ' */
    mcb__SPIMasterTransfer_Init
      (&mcb_pmsm_foc_sensorless_f_DWork.SPIMasterTransfer);
    mcb__SPIMasterTransfer_Init
      (&mcb_pmsm_foc_sensorless_f_DWork.SPIMasterTransfer1);

    /* End of SystemInitialize for SubSystem: '<Root>/Hardware Init' */

    /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Constant: '<S3>/6PWM_Mode' */
    mcb_pmsm__SPIMasterTransfer(14870U,
      &mcb_pmsm_foc_sensorless_f2806_B.SPIMasterTransfer,
      &mcb_pmsm_foc_sensorless_f_DWork.SPIMasterTransfer);

    /* Constant: '<S3>/ADC_Gain_Setting' */
    mcb_pmsm__SPIMasterTransfer(20522U,
      &mcb_pmsm_foc_sensorless_f2806_B.SPIMasterTransfer1,
      &mcb_pmsm_foc_sensorless_f_DWork.SPIMasterTransfer1);

    /* S-Function (c280xgpio_do): '<S311>/Digital Output' incorporates:
     *  Constant: '<S311>/DRV830x_Enable'
     */
    {
      if ((1U)) {
        GpioDataRegs.GPBSET.bit.GPIO50 = 1U;
      } else {
        GpioDataRegs.GPBCLEAR.bit.GPIO50 = 1U;
      }
    }

    /* Outputs for Enabled SubSystem: '<S309>/Calculate ADC Offset ' incorporates:
     *  EnablePort: '<S310>/Enable'
     */
    /* Outputs for Iterator SubSystem: '<S310>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S313>/For Iterator'
     */
    for (s313_iter = 1U; s313_iter < 17U; s313_iter++) {
      /* Outputs for Iterator SubSystem: '<S310>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S313>/For Iterator'
       */
      mcb_pmsm_foc_sensorless_f2806_B.ForIterator = s313_iter;

      /* S-Function (c2802xadc): '<S313>/IA//IB Measurement' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdcRegs.ADCSOCFRC1.bit.SOC2 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #70|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        real32_T wait_index;
        for (wait_index= 11; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_pmsm_foc_sensorless_f2806_B.IAIBMeasurement[0] =
          (AdcResult.ADCRESULT2);
        mcb_pmsm_foc_sensorless_f2806_B.IAIBMeasurement[1] =
          (AdcResult.ADCRESULT3);
      }

      /* If: '<S313>/If' */
      if (mcb_pmsm_foc_sensorless_f2806_B.ForIterator > 8U) {
        /* Outputs for IfAction SubSystem: '<S313>/If Action Subsystem' incorporates:
         *  ActionPort: '<S318>/Action Port'
         */
        /* Memory: '<S318>/Memory' */
        mcb_pmsm_foc_sensorless_f2806_B.Memory =
          mcb_pmsm_foc_sensorless_f_DWork.Memory_PreviousInput;

        /* Sum: '<S318>/Sum' */
        mcb_pmsm_foc_sensorless_f2806_B.Sum_dn =
          mcb_pmsm_foc_sensorless_f2806_B.IAIBMeasurement[0] +
          mcb_pmsm_foc_sensorless_f2806_B.Memory;

        /* Memory: '<S318>/Memory1' */
        mcb_pmsm_foc_sensorless_f2806_B.Memory1 =
          mcb_pmsm_foc_sensorless_f_DWork.Memory1_PreviousInput;

        /* Sum: '<S318>/Sum1' */
        mcb_pmsm_foc_sensorless_f2806_B.Sum1_dq =
          mcb_pmsm_foc_sensorless_f2806_B.IAIBMeasurement[1] +
          mcb_pmsm_foc_sensorless_f2806_B.Memory1;

        /* Update for Memory: '<S318>/Memory' */
        mcb_pmsm_foc_sensorless_f_DWork.Memory_PreviousInput =
          mcb_pmsm_foc_sensorless_f2806_B.Sum_dn;

        /* Update for Memory: '<S318>/Memory1' */
        mcb_pmsm_foc_sensorless_f_DWork.Memory1_PreviousInput =
          mcb_pmsm_foc_sensorless_f2806_B.Sum1_dq;

        /* End of Outputs for SubSystem: '<S313>/If Action Subsystem' */
      }

      /* End of If: '<S313>/If' */
    }

    /* End of Outputs for SubSystem: '<S310>/For Iterator Subsystem' */

    /* Product: '<S310>/Divide' incorporates:
     *  Constant: '<S310>/Constant'
     */
    mcb_pmsm_foc_sensorless_f2806_B.Divide_h = (uint16_T)((real_T)
      mcb_pmsm_foc_sensorless_f2806_B.Sum_dn / 8.0);

    /* If: '<S310>/If' incorporates:
     *  Constant: '<S310>/Constant1'
     *  Constant: '<S310>/Constant2'
     */
    if ((mcb_pmsm_foc_sensorless_f2806_B.Divide_h > 1500U) &&
        (mcb_pmsm_foc_sensorless_f2806_B.Divide_h < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S310>/If Action Subsystem' incorporates:
       *  ActionPort: '<S314>/Action Port'
       */
      /* DataStoreWrite: '<S314>/Data Store Write1' */
      mcb_pmsm_foc_sensorless_f_DWork.IaOffset =
        mcb_pmsm_foc_sensorless_f2806_B.Divide_h;

      /* End of Outputs for SubSystem: '<S310>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S310>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S315>/Action Port'
       */
      /* DataStoreWrite: '<S315>/Data Store Write1' incorporates:
       *  Constant: '<S315>/Constant'
       */
      mcb_pmsm_foc_sensorless_f_DWork.IaOffset = 2087U;

      /* End of Outputs for SubSystem: '<S310>/If Action Subsystem1' */
    }

    /* End of If: '<S310>/If' */

    /* Product: '<S310>/Divide1' incorporates:
     *  Constant: '<S310>/Constant'
     */
    mcb_pmsm_foc_sensorless_f2806_B.Divide1_e = (uint16_T)((real_T)
      mcb_pmsm_foc_sensorless_f2806_B.Sum1_dq / 8.0);

    /* If: '<S310>/If1' incorporates:
     *  Constant: '<S310>/Constant1'
     *  Constant: '<S310>/Constant2'
     */
    if ((mcb_pmsm_foc_sensorless_f2806_B.Divide1_e > 1500U) &&
        (mcb_pmsm_foc_sensorless_f2806_B.Divide1_e < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S310>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S316>/Action Port'
       */
      /* DataStoreWrite: '<S316>/Data Store Write2' */
      mcb_pmsm_foc_sensorless_f_DWork.IbOffset =
        mcb_pmsm_foc_sensorless_f2806_B.Divide1_e;

      /* End of Outputs for SubSystem: '<S310>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S310>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S317>/Action Port'
       */
      /* DataStoreWrite: '<S317>/Data Store Write2' incorporates:
       *  Constant: '<S317>/Constant1'
       */
      mcb_pmsm_foc_sensorless_f_DWork.IbOffset = 2082U;

      /* End of Outputs for SubSystem: '<S310>/If Action Subsystem3' */
    }

    /* End of If: '<S310>/If1' */
    /* End of Outputs for SubSystem: '<S309>/Calculate ADC Offset ' */

    /* Logic: '<S309>/NOT' */
    mcb_pmsm_foc_sensorless_f2806_B.NOT_h = false;

    /* Outputs for Enabled SubSystem: '<S309>/Default ADC Offset' incorporates:
     *  EnablePort: '<S312>/Enable'
     */
    if (mcb_pmsm_foc_sensorless_f2806_B.NOT_h) {
      /* DataStoreWrite: '<S312>/Data Store Write1' incorporates:
       *  Constant: '<S312>/Constant'
       */
      mcb_pmsm_foc_sensorless_f_DWork.IaOffset = 2087U;

      /* DataStoreWrite: '<S312>/Data Store Write2' incorporates:
       *  Constant: '<S312>/Constant1'
       */
      mcb_pmsm_foc_sensorless_f_DWork.IbOffset = 2082U;
    }

    /* End of Outputs for SubSystem: '<S309>/Default ADC Offset' */
    /* End of Outputs for SubSystem: '<Root>/Hardware Init' */
  }
}

/* Model terminate function */
void mcb_pmsm_foc_sensorless_f28069MLaunchPad_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Hardware Init' */
  mcb__SPIMasterTransfer_Term(&mcb_pmsm_foc_sensorless_f_DWork.SPIMasterTransfer);
  mcb__SPIMasterTransfer_Term
    (&mcb_pmsm_foc_sensorless_f_DWork.SPIMasterTransfer1);

  /* End of Terminate for SubSystem: '<Root>/Hardware Init' */
}

void mcb_pmsm_foc_sensorless_f28069MLaunchPad_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(32,&ADCINT1,1);
  HWI_TIC28x_EnableIRQ(32);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(96,&SCIRXINTA,0);
  HWI_TIC28x_EnableIRQ(96);
}

/* Hardware Interrupt Block: '<S305>/Hardware Interrupt' */
interrupt void ADCINT1(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      int16_T tmp;

      /* RateTransition: '<Root>/RT2' */
      tmp = mcb_pmsm_foc_sensorless_f_DWork.RT2_ActiveBufIdx << 1U;
      mcb_pmsm_foc_sensorless_f2806_B.RT2[0] =
        mcb_pmsm_foc_sensorless_f_DWork.RT2_Buffer[tmp];
      mcb_pmsm_foc_sensorless_f2806_B.RT2[1] =
        mcb_pmsm_foc_sensorless_f_DWork.RT2_Buffer[tmp + 1];

      /* S-Function (HardwareInterrupt_sfun): '<S305>/Hardware Interrupt' */
      mcb_pmsm_foc_CurrentControl();

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S305>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT4' */
      mcb_pmsm_foc_sensorless_f_DWork.RT4_Buffer[mcb_pmsm_foc_sensorless_f_DWork.RT4_semaphoreTaken
        == 0] = mcb_pmsm_foc_sensorless_f2806_B.Speed_fb_PU;
      mcb_pmsm_foc_sensorless_f_DWork.RT4_ActiveBufIdx =
        (mcb_pmsm_foc_sensorless_f_DWork.RT4_semaphoreTaken == 0);
    }
  }

  /* Clear occurred EOC event event */
  AdcRegs.ADCINTFLGCLR.bit.ADCINT1= 1;

  /* Clear occurred Overflow event event */
  AdcRegs.ADCINTOVFCLR.bit.ADCINT1= 1;
  HWI_TIC28x_AcknowledgeIrq(32);
}

/* Hardware Interrupt Block: '<S307>/Hardware Interrupt' */
interrupt void SCIRXINTA(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  volatile unsigned int PIEIER9_stack_save = PieCtrlRegs.PIEIER9.all;
  PieCtrlRegs.PIEIER1.all &= ~65;
                              /*disable group1 lower/equal priority interrupts*/
  PieCtrlRegs.PIEIER9.all &= ~1;
                              /*disable group9 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~257;    /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 257;
                   /*ACK to allow other interrupts from the same group to fire*/
  IER |= 256;
  EINT;

  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S307>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Serial Receive' */
      {
        int16_T DataTypeConversion2;

        /* S-Function (c28xsci_rx): '<S324>/SCI Receive' */
        {
          int16_T i;
          int16_T errFlg = NOERROR;
          uint16_T isHeadReceived = 1U;

          //get data as uint16 in recBuff
          uint16_T recbuff[2];
          for (i = 0; i < 2; i++) {
            recbuff[i] = 0U;
          }

          errFlg = NOERROR;

          /* Receiving data: For uint32 and uint16, rcvBuff will contain uint16 data */
          if (isHeadReceived) {
            errFlg = scia_rcv(recbuff, 4, 2);
            asm(" NOP");
            if ((errFlg == NOERROR) || (errFlg == PARTIALDATA)) {
              memcpy( &mcb_pmsm_foc_sensorless_f2806_B.SCIReceive[0], recbuff,2);
            }
          }
        }

        /* DataTypeConversion: '<S322>/Data Type Conversion2' */
        DataTypeConversion2 = (int16_T)
          mcb_pmsm_foc_sensorless_f2806_B.SCIReceive[0];
        mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion2[0] =
          DataTypeConversion2;

        /* DataTypeConversion: '<S322>/Data Type Conversion1' incorporates:
         *  DataTypeConversion: '<S322>/Data Type Conversion2'
         */
        mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_a[0] = (real32_T)
          DataTypeConversion2 * 0.000244140625F;

        /* DataTypeConversion: '<S322>/Data Type Conversion2' */
        DataTypeConversion2 = (int16_T)
          mcb_pmsm_foc_sensorless_f2806_B.SCIReceive[1];
        mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion2[1] =
          DataTypeConversion2;

        /* DataTypeConversion: '<S322>/Data Type Conversion1' incorporates:
         *  DataTypeConversion: '<S322>/Data Type Conversion2'
         */
        mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_a[1] = (real32_T)
          DataTypeConversion2 * 0.000244140625F;

        /* DataTypeConversion: '<S6>/Data Type Conversion1' */
        mcb_pmsm_foc_sensorless_f2806_B.Speed_Ref =
          mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_a[0];

        /* DataTypeConversion: '<S6>/Data Type Conversion3' */
        mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion3_b =
          (mcb_pmsm_foc_sensorless_f2806_B.DataTypeConversion1_a[1] != 0.0F);
      }

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S307>/Hardware Interrupt' */

      /* RateTransition: '<S8>/RT6' */
      mcb_pmsm_foc_sensorless_f_DWork.RT6_Buffer[mcb_pmsm_foc_sensorless_f_DWork.RT6_semaphoreTaken
        == 0] = mcb_pmsm_foc_sensorless_f2806_B.Speed_Ref;
      mcb_pmsm_foc_sensorless_f_DWork.RT6_ActiveBufIdx =
        (mcb_pmsm_foc_sensorless_f_DWork.RT6_semaphoreTaken == 0);
    }
  }

  /* Clear occurred Rx event event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFINTCLR= 1;
  EDIS;

  /* Clear occurred Rx FIFO overflow event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFOVRCLR= 1;
  EDIS;
  DINT;
  /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;
                                   /*restore PIEIER register that was modified*/
  PieCtrlRegs.PIEIER9.all = PIEIER9_stack_save;
                                   /*restore PIEIER register that was modified*/
  HWI_TIC28x_AcknowledgeIrq(96);
}

void mcb_pmsm_foc_sensorless_f28069MLaunchPad_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(32);
  HWI_TIC28x_DisableIRQ(96);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
