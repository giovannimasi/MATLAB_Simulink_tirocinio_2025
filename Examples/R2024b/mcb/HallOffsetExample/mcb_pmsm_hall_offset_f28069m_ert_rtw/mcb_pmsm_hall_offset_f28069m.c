/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_hall_offset_f28069m.c
 *
 * Code generated for Simulink model 'mcb_pmsm_hall_offset_f28069m'.
 *
 * Model version                  : 9.3
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Mar 19 17:00:29 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcb_pmsm_hall_offset_f28069m.h"
#include "rtwtypes.h"
#include "mcb_pmsm_hall_offset_f28069m_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "multiword_types.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_mcb_pmsm_hall_offset_f2 mcb_pmsm_hall_offset_f28069m_B;

/* Block states (default storage) */
D_Work_mcb_pmsm_hall_offset_f28 mcb_pmsm_hall_offset_f280_DWork;

/* Real-time model */
static RT_MODEL_mcb_pmsm_hall_offset_f mcb_pmsm_hall_offset_f28069m_M_;
RT_MODEL_mcb_pmsm_hall_offset_f *const mcb_pmsm_hall_offset_f28069m_M =
  &mcb_pmsm_hall_offset_f28069m_M_;

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcInitFlag = 0;

#endif

uint32_T uMultiWord2uLongSat(const uint32_T u1[], int16_T n1)
{
  uint32_T ret;
  uMultiWord2uMultiWordSat(u1, n1, &ret, 1);
  return ret;
}

void uMultiWord2uMultiWordSat(const uint32_T u1[], int16_T n1, uint32_T y[],
  int16_T n)
{
  int16_T i;
  int16_T nc;
  boolean_T doSaturation = false;
  i = n1 - 1;
  while ((!doSaturation) && (i >= n)) {
    doSaturation = (u1[i] != 0UL);
    i--;
  }

  if (doSaturation) {
    for (i = 0; i < n; i++) {
      y[i] = MAX_uint32_T;
    }
  } else {
    nc = n1 < n ? n1 : n;
    for (i = 0; i < nc; i++) {
      y[i] = u1[i];
    }

    while (i < n) {
      y[i] = 0UL;
      i++;
    }
  }
}

void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int16_T n)
{
  uint32_T carry = 0UL;
  uint32_T u1i;
  uint32_T yi;
  int16_T i;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i + u2[i]) + carry;
    y[i] = yi;
    carry = carry != 0UL ? (uint32_T)(yi <= u1i) : (uint32_T)(yi < u1i);
  }
}

void uLong2MultiWord(uint32_T u, uint32_T y[], int16_T n)
{
  int16_T i;
  y[0] = u;
  for (i = 1; i < n; i++) {
    y[i] = 0UL;
  }
}

/*
 * Output and update for action system:
 *    '<S148>/Hall Value of 1'
 *    '<S147>/Hall Value of 2'
 */
void mcb_pmsm_hall_offs_HallValueof1(real32_T *rty_position)
{
  /* SignalConversion generated from: '<S158>/position' incorporates:
   *  Constant: '<S158>/Constant'
   */
  *rty_position = 0.16667F;
}

/*
 * Output and update for action system:
 *    '<S148>/Hall Value of 2'
 *    '<S147>/Hall Value of 3'
 */
void mcb_pmsm_hall_offs_HallValueof2(real32_T *rty_position)
{
  /* SignalConversion generated from: '<S159>/position' incorporates:
   *  Constant: '<S159>/Constant'
   */
  *rty_position = 0.33333F;
}

/*
 * Output and update for action system:
 *    '<S148>/Hall Value of 3'
 *    '<S147>/Hall Value of 4'
 */
void mcb_pmsm_hall_offs_HallValueof3(real32_T *rty_position)
{
  /* SignalConversion generated from: '<S160>/position' incorporates:
   *  Constant: '<S160>/Constant'
   */
  *rty_position = 0.5F;
}

/*
 * Output and update for action system:
 *    '<S148>/Hall Value of 4'
 *    '<S147>/Hall Value of 5'
 */
void mcb_pmsm_hall_offs_HallValueof4(real32_T *rty_position)
{
  /* SignalConversion generated from: '<S161>/position' incorporates:
   *  Constant: '<S161>/Constant'
   */
  *rty_position = 0.66667F;
}

/*
 * Output and update for action system:
 *    '<S148>/Hall Value of 5'
 *    '<S147>/Hall Value of 6'
 */
void mcb_pmsm_hall_offs_HallValueof5(real32_T *rty_position)
{
  /* SignalConversion generated from: '<S162>/position' incorporates:
   *  Constant: '<S162>/Constant'
   */
  *rty_position = 0.83333F;
}

/*
 * Output and update for action system:
 *    '<S148>/Hall Value of 7'
 *    '<S147>/Hall Value of 1'
 *    '<S147>/Hall Value of 7'
 *    '<S136>/Hall Value of 7'
 */
void mcb_pmsm_hall_offs_HallValueof7(real32_T *rty_position)
{
  /* SignalConversion generated from: '<S164>/position' incorporates:
   *  Constant: '<S164>/Constant'
   */
  *rty_position = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S23>/Output 1'
 *    '<S40>/Output 1'
 *    '<S57>/Output 1'
 */
void mcb_pmsm_hall_offset_f2_Output1(boolean_T *rty_Out1)
{
  /* SignalConversion generated from: '<S26>/Out1' incorporates:
   *  Constant: '<S26>/Constant'
   */
  *rty_Out1 = true;
}

/*
 * Output and update for action system:
 *    '<S23>/Output 0'
 *    '<S40>/Output 0'
 *    '<S57>/Output 0'
 */
void mcb_pmsm_hall_offset_f2_Output0(boolean_T *rty_Out1)
{
  /* SignalConversion generated from: '<S25>/Out1' incorporates:
   *  Constant: '<S25>/Constant'
   */
  *rty_Out1 = false;
}

/*
 * System initialize for action system:
 *    '<S27>/Valid Halls'
 *    '<S44>/Valid Halls'
 *    '<S61>/Valid Halls'
 */
void mcb_pmsm_hall_o_ValidHalls_Init(rtB_ValidHalls_mcb_pmsm_hall_of *localB)
{
  /* SystemInitialize for Merge: '<S29>/Merge' */
  localB->Merge = 0U;

  /* SystemInitialize for Merge: '<S29>/Merge1' */
  localB->Merge1 = 0U;

  /* SystemInitialize for Merge: '<S29>/Merge2' */
  localB->Merge2 = 0;

  /* SystemInitialize for Merge: '<S29>/Merge3' */
  localB->Merge3 = 0U;
}

/*
 * Output and update for action system:
 *    '<S27>/Valid Halls'
 *    '<S44>/Valid Halls'
 *    '<S61>/Valid Halls'
 */
void mcb_pmsm_hall_offset_ValidHalls(uint16_T rtu_hallReading, uint16_T
  rtu_previousState, int16_T rtu_previous_direction, boolean_T
  *rty_directional_speed_valid_fla, int16_T *rty_direction, uint16_T
  *rty_inValidHall, rtB_ValidHalls_mcb_pmsm_hall_of *localB)
{
  /* SwitchCase: '<S29>/Switch Case' */
  switch ((int32_T)rtu_hallReading) {
   case 5L:
    /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    /* Merge: '<S29>/Merge' incorporates:
     *  Constant: '<S30>/previous'
     *  SignalConversion generated from: '<S30>/Out1'
     */
    localB->Merge = 1U;

    /* Merge: '<S29>/Merge1' incorporates:
     *  Constant: '<S30>/next'
     *  SignalConversion generated from: '<S30>/Out2'
     */
    localB->Merge1 = 4U;

    /* End of Outputs for SubSystem: '<S29>/If Action Subsystem' */
    break;

   case 4L:
    /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* Merge: '<S29>/Merge' incorporates:
     *  Constant: '<S31>/previous'
     *  SignalConversion generated from: '<S31>/Out1'
     */
    localB->Merge = 5U;

    /* Merge: '<S29>/Merge1' incorporates:
     *  Constant: '<S31>/next'
     *  SignalConversion generated from: '<S31>/Out2'
     */
    localB->Merge1 = 6U;

    /* End of Outputs for SubSystem: '<S29>/If Action Subsystem1' */
    break;

   case 6L:
    /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* Merge: '<S29>/Merge' incorporates:
     *  Constant: '<S32>/previous'
     *  SignalConversion generated from: '<S32>/Out1'
     */
    localB->Merge = 4U;

    /* Merge: '<S29>/Merge1' incorporates:
     *  Constant: '<S32>/next'
     *  SignalConversion generated from: '<S32>/Out2'
     */
    localB->Merge1 = 2U;

    /* End of Outputs for SubSystem: '<S29>/If Action Subsystem2' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* Merge: '<S29>/Merge' incorporates:
     *  Constant: '<S33>/previous'
     *  SignalConversion generated from: '<S33>/Out1'
     */
    localB->Merge = 6U;

    /* Merge: '<S29>/Merge1' incorporates:
     *  Constant: '<S33>/next'
     *  SignalConversion generated from: '<S33>/Out2'
     */
    localB->Merge1 = 3U;

    /* End of Outputs for SubSystem: '<S29>/If Action Subsystem3' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    /* Merge: '<S29>/Merge' incorporates:
     *  Constant: '<S34>/previous'
     *  SignalConversion generated from: '<S34>/Out1'
     */
    localB->Merge = 2U;

    /* Merge: '<S29>/Merge1' incorporates:
     *  Constant: '<S34>/next'
     *  SignalConversion generated from: '<S34>/Out2'
     */
    localB->Merge1 = 1U;

    /* End of Outputs for SubSystem: '<S29>/If Action Subsystem4' */
    break;

   case 1L:
    /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    /* Merge: '<S29>/Merge' incorporates:
     *  Constant: '<S35>/previous'
     *  SignalConversion generated from: '<S35>/Out1'
     */
    localB->Merge = 3U;

    /* Merge: '<S29>/Merge1' incorporates:
     *  Constant: '<S35>/next'
     *  SignalConversion generated from: '<S35>/Out2'
     */
    localB->Merge1 = 5U;

    /* End of Outputs for SubSystem: '<S29>/If Action Subsystem5' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S29>/Switch Case' */

  /* If: '<S29>/If' */
  if (rtu_previousState == localB->Merge) {
    /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    /* Merge: '<S29>/Merge2' incorporates:
     *  Constant: '<S36>/Constant'
     *  SignalConversion generated from: '<S36>/direction'
     */
    localB->Merge2 = 1;

    /* Merge: '<S29>/Merge3' incorporates:
     *  Constant: '<S36>/Constant1'
     *  SignalConversion generated from: '<S36>/sequence_check'
     */
    localB->Merge3 = 0U;

    /* End of Outputs for SubSystem: '<S29>/If Action Subsystem6' */
  } else if (rtu_previousState == localB->Merge1) {
    /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    /* Merge: '<S29>/Merge2' incorporates:
     *  Constant: '<S37>/Constant'
     *  SignalConversion generated from: '<S37>/direction'
     */
    localB->Merge2 = -1;

    /* Merge: '<S29>/Merge3' incorporates:
     *  Constant: '<S37>/Constant1'
     *  SignalConversion generated from: '<S37>/sequence_check'
     */
    localB->Merge3 = 0U;

    /* End of Outputs for SubSystem: '<S29>/If Action Subsystem7' */
  } else {
    /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    /* Merge: '<S29>/Merge3' incorporates:
     *  Constant: '<S38>/Constant'
     *  SignalConversion generated from: '<S38>/sequence_check'
     */
    localB->Merge3 = 1U;

    /* End of Outputs for SubSystem: '<S29>/If Action Subsystem8' */
  }

  /* End of If: '<S29>/If' */

  /* SignalConversion: '<S29>/Signal Conversion' */
  *rty_inValidHall = localB->Merge3;

  /* SignalConversion: '<S29>/Signal Conversion1' */
  *rty_direction = localB->Merge2;

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Constant'
   */
  if (localB->Merge3 != 0U) {
    *rty_directional_speed_valid_fla = false;
  } else {
    /* RelationalOperator: '<S29>/Relational Operator' */
    localB->RelationalOperator = (localB->Merge2 == rtu_previous_direction);
    *rty_directional_speed_valid_fla = localB->RelationalOperator;
  }

  /* End of Switch: '<S29>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S27>/Bad hall (glitch or wrong connection)'
 *    '<S44>/Bad hall (glitch or wrong connection)'
 *    '<S61>/Bad hall (glitch or wrong connection)'
 */
void Badhallglitchorwrongconnection(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla)
{
  /* SignalConversion generated from: '<S28>/inValidHall' incorporates:
   *  Constant: '<S28>/Constant'
   */
  *rty_inValidHall = 1U;

  /* SignalConversion: '<S28>/Signal Conversion' */
  *rty_direction = rtu_previous_direction;

  /* SignalConversion generated from: '<S28>/directional_speed_valid_flag' incorporates:
   *  Constant: '<S28>/Constant1'
   */
  *rty_directional_speed_valid_fla = false;
}

/* Model step function */
void mcb_pmsm_hall_offset_f28069m_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* S-Function (c280xgpio_do): '<S5>/Digital Output' incorporates:
   *  Constant: '<S5>/LED'
   */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = (uint16_T)((1U) != 0);
  }

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void mcb_pmsm_hall_offset_f28069m_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(mcb_pmsm_hall_offset_f28069m_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &mcb_pmsm_hall_offset_f28069m_B), 0,
                sizeof(BlockIO_mcb_pmsm_hall_offset_f2));

  {
    mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Merge = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Merge1 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Switch_m = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Merge_l = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.indexing = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Lookup[0] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Lookup[1] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Lookup[2] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Lookup[3] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Sum3 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_p = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Sum2 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Product = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Sum4 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Sum5 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Product1 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Sum6 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.currentSpeedData = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Divide = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.SpeedGain = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Merge1_f = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Saturation = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Merge_g = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.countData = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.currentSpeedData_g = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Divide_m = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.countData_a = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.previousSpeedData = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Divide_mp = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.currentSpeedData_n = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Divide1 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Sum_b = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Gain1 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Sum1 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Product_c = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Merge1_o = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Merge1_m = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.sqrt3_by_two = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.one_by_two = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.add_c = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.add_b = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Min_f = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Max_l = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Add = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.one_by_two_g = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Add2 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Add1_j = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Add3 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Gain[0] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Gain[1] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Gain[2] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Sum_j[0] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Sum_j[1] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Sum_j[2] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Gain_i[0] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Gain_i[1] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Gain_i[2] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Input = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Convert_back = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Convert_back_c = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Merge_o = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.UnitDelay = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.scaleOut = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Add_e = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_d = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Add1_m = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Input_d = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Delay_b = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Add1_d = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.SaturatetomotorcalibSpeedRPM = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.qcos = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.dsin = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.sum_beta = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.dcos = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.qsin = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.sum_alpha = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Switch_fs[0] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Switch_fs[1] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.algDD_o1 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.algDD_o2 = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Delay_o = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Switch1[0] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Switch1[1] = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Product_l = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.UnitDelay_d = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Product1_m = 0.0F;
    mcb_pmsm_hall_offset_f28069m_B.Add1_mi = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&mcb_pmsm_hall_offset_f280_DWork, 0,
                sizeof(D_Work_mcb_pmsm_hall_offset_f28));
  mcb_pmsm_hall_offset_f280_DWork.UnitDelay_DSTATE = 0.0F;
  mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE = 0.0F;
  mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE_p = 0.0F;
  mcb_pmsm_hall_offset_f280_DWork.UnitDelay_DSTATE_f = 0.0F;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Offset Calculation'
   */

  /* System initialize for function-call system: '<Root>/Offset Calculation' */

  /* Start for Delay: '<S130>/validityDelay' */
  mcb_pmsm_hall_offset_f28069m_B.validityDelay = false;

  /* Start for Delay: '<S130>/speedCountDelay' */
  mcb_pmsm_hall_offset_f28069m_B.speedCountDelay = 0UL;

  /* Start for Delay: '<S131>/Delay One Step' */
  mcb_pmsm_hall_offset_f28069m_B.DelayOneStep = 0U;

  /* Start for S-Function (c2802xpwm): '<S77>/ePWM4' */
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

  /* Start for S-Function (c2802xpwm): '<S77>/ePWM5' */
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

  /* Start for S-Function (c2802xpwm): '<S77>/ePWM6' */
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

  /* Start for S-Function (c280xgpio_do): '<S77>/Inverter Enable' */
  EALLOW;
  GpioCtrlRegs.GPBMUX2.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x40000U;
  EDIS;

  /* Start for S-Function (c2802xadc): '<S6>/IA//IB Measurement' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC0_SOC1 ();

  /* InitializeConditions for Delay: '<S131>/Delay One Step1' */
  mcb_pmsm_hall_offset_f280_DWork.DelayOneStep1_DSTATE = true;

  /* InitializeConditions for Delay: '<S131>/Delay One Step' */
  mcb_pmsm_hall_offset_f280_DWork.DelayOneStep_DSTATE = 2500U;

  /* SystemInitialize for IfAction SubSystem: '<S129>/Speed and direction are valid Use speed to extrapolate position' */
  /* SystemInitialize for Enabled SubSystem: '<S133>/Subsystem1' */
  /* SystemInitialize for Merge: '<S146>/Merge' */
  mcb_pmsm_hall_offset_f28069m_B.Merge_g = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S133>/Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<S129>/Speed and direction are valid Use speed to extrapolate position' */
  /* SystemInitialize for Enabled SubSystem: '<S74>/Find Offset' */
  /* InitializeConditions for Delay: '<S80>/Delay' */
  mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE_p = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S74>/Find Offset' */

  /* SystemInitialize for Enabled SubSystem: '<S74>/PosGen' */
  /* InitializeConditions for UnitDelay: '<S102>/Unit Delay' */
  mcb_pmsm_hall_offset_f280_DWork.UnitDelay_DSTATE = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S82>/Up Counter' */
  /* InitializeConditions for Delay: '<S99>/Delay' */
  mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE_pm = 0UL;

  /* End of SystemInitialize for SubSystem: '<S82>/Up Counter' */
  /* End of SystemInitialize for SubSystem: '<S74>/PosGen' */

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S16>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Hall Sensor A'
   */

  /* System initialize for function-call system: '<Root>/Hall Sensor A' */

  /* SystemInitialize for IfAction SubSystem: '<S27>/Valid Halls' */
  mcb_pmsm_hall_o_ValidHalls_Init(&mcb_pmsm_hall_offset_f28069m_B.ValidHalls);

  /* End of SystemInitialize for SubSystem: '<S27>/Valid Halls' */

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S16>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S18>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Hall Sensor B'
   */

  /* System initialize for function-call system: '<Root>/Hall Sensor B' */

  /* SystemInitialize for IfAction SubSystem: '<S44>/Valid Halls' */
  mcb_pmsm_hall_o_ValidHalls_Init(&mcb_pmsm_hall_offset_f28069m_B.ValidHalls_n);

  /* End of SystemInitialize for SubSystem: '<S44>/Valid Halls' */

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S18>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S20>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Hall Sensor C'
   */

  /* System initialize for function-call system: '<Root>/Hall Sensor C' */

  /* SystemInitialize for IfAction SubSystem: '<S61>/Valid Halls' */
  mcb_pmsm_hall_o_ValidHalls_Init(&mcb_pmsm_hall_offset_f28069m_B.ValidHalls_j);

  /* End of SystemInitialize for SubSystem: '<S61>/Valid Halls' */

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S20>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Serial Receive'
   */

  /* System initialize for function-call system: '<Root>/Serial Receive' */

  /* Start for S-Function (c28xsci_rx): '<S7>/SCI Receive' */

  /* Initialize out port */
  {
    mcb_pmsm_hall_offset_f28069m_B.SCIReceive = (uint16_T)0.0;
  }

  /*Configure Timer2 when blocking mode is enabled and Timeout is not inf*/
  {
    /* InitCpuTimers() - CPU Timers are also initialized in
     * MW_c28xx_board.c in the generated code.
     */
    CpuTimer2Regs.PRD.all = 0xFFFFFFFFU;/* max Period*/
    CpuTimer2Regs.TIM.all = 0xFFFFFFFFU;/* set Ctr*/
    CpuTimer2Regs.TPR.all = 0x00U;     /* no prescaler    */
    StartCpuTimer2();
  }

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* Start for S-Function (c280xgpio_do): '<S5>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;

  /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model terminate function */
void mcb_pmsm_hall_offset_f28069m_terminate(void)
{
  /* (no terminate code required) */
}

void mcb_pmsm_hall_offset_f28069m_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(32,&ADCINT1,1);
  HWI_TIC28x_EnableIRQ(32);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(56,&ECAP1_INT,0);
  HWI_TIC28x_EnableIRQ(56);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(57,&ECAP2_INT,0);
  HWI_TIC28x_EnableIRQ(57);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(58,&ECAP3_INT,0);
  HWI_TIC28x_EnableIRQ(58);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(96,&SCIRXINTA,3);
  HWI_TIC28x_EnableIRQ(96);
}

/* Hardware Interrupt Block: '<S14>/Hardware Interrupt' */
interrupt void ADCINT1(void)
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
  IER |= 1;
  EINT;

  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Offset Calculation' */
      {
        uint64m_T tmp;
        uint64m_T tmp_p;
        real32_T Bias;
        real32_T u0_p;
        uint32_T u0;
        uint32_T u1;
        int16_T s125_iter;
        uint16_T Data;
        boolean_T doReset;
        static const uint64m_T tmp_e = { { 1UL, 0UL }/* chunks */
        };

        /* DataStoreRead: '<S128>/Data Store Read5' */
        mcb_pmsm_hall_offset_f28069m_B.DataStoreRead5 =
          mcb_pmsm_hall_offset_f280_DWork.HallStateChangeFlag;

        /* Switch: '<S129>/Switch' incorporates:
         *  Constant: '<S129>/WatchDog'
         */
        mcb_pmsm_hall_offset_f28069m_B.Switch_i = 0U;

        /* DataStoreWrite: '<S128>/Data Store Write2' */
        mcb_pmsm_hall_offset_f280_DWork.HallStateChangeFlag = 0U;

        /* DataStoreRead: '<S128>/Data Store Read' */
        mcb_pmsm_hall_offset_f28069m_B.DataStoreRead_p =
          mcb_pmsm_hall_offset_f280_DWork.GlobalHallState;

        /* DataStoreRead: '<S128>/Data Store Read2' */
        mcb_pmsm_hall_offset_f28069m_B.DataStoreRead2 =
          mcb_pmsm_hall_offset_f280_DWork.GlobalSpeedCount;

        /* DataStoreRead: '<S128>/Data Store Read3' */
        mcb_pmsm_hall_offset_f28069m_B.DataStoreRead3 =
          mcb_pmsm_hall_offset_f280_DWork.GlobalDirection;

        /* DataStoreRead: '<S128>/Data Store Read4' */
        mcb_pmsm_hall_offset_f28069m_B.DataStoreRead4 =
          mcb_pmsm_hall_offset_f280_DWork.GlobalSpeedValidity;

        /* DataTypeConversion: '<S129>/Data Type Conversion4' */
        mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion4 =
          (mcb_pmsm_hall_offset_f28069m_B.DataStoreRead5 != 0U);

        /* DataTypeConversion: '<S130>/Data Type Conversion' */
        mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion_k =
          (mcb_pmsm_hall_offset_f28069m_B.DataStoreRead4 != 0U);

        /* Switch: '<S130>/Switch' incorporates:
         *  Constant: '<S130>/Order'
         */
        mcb_pmsm_hall_offset_f28069m_B.Switch_o = 0U;

        /* S-Function (memorycopy): '<S128>/Memory Copy3' */
        {
          uint32_T *memindsrc1 = (uint32_T *) (&ECap1Regs.TSCTR);
          uint32_T *meminddst1 = (uint32_T *)
            (&mcb_pmsm_hall_offset_f28069m_B.MemoryCopy3);
          *(uint32_T *) (meminddst1) = *(uint32_T *) (memindsrc1);
        }

        /* S-Function (memorycopy): '<S128>/Memory Copy4' */
        {
          uint32_T *memindsrc2 = (uint32_T *) (&ECap2Regs.TSCTR);
          uint32_T *meminddst2 = (uint32_T *)
            (&mcb_pmsm_hall_offset_f28069m_B.MemoryCopy4);
          *(uint32_T *) (meminddst2) = *(uint32_T *) (memindsrc2);
        }

        /* S-Function (memorycopy): '<S128>/Memory Copy5' */
        {
          uint32_T *memindsrc3 = (uint32_T *) (&ECap3Regs.TSCTR);
          uint32_T *meminddst3 = (uint32_T *)
            (&mcb_pmsm_hall_offset_f28069m_B.MemoryCopy5);
          *(uint32_T *) (meminddst3) = *(uint32_T *) (memindsrc3);
        }

        /* MinMax: '<S128>/Min' */
        u0 = mcb_pmsm_hall_offset_f28069m_B.MemoryCopy3;
        u1 = mcb_pmsm_hall_offset_f28069m_B.MemoryCopy4;
        if (u0 <= u1) {
          u1 = u0;
        }

        u0 = mcb_pmsm_hall_offset_f28069m_B.MemoryCopy5;
        if (u1 > u0) {
          u1 = u0;
        }

        /* MinMax: '<S128>/Min' */
        mcb_pmsm_hall_offset_f28069m_B.Min = u1;

        /* Delay: '<S131>/Delay One Step1' */
        mcb_pmsm_hall_offset_f28069m_B.DelayOneStep1 =
          mcb_pmsm_hall_offset_f280_DWork.DelayOneStep1_DSTATE;

        /* Logic: '<S131>/OR' */
        mcb_pmsm_hall_offset_f28069m_B.OR =
          (mcb_pmsm_hall_offset_f28069m_B.DelayOneStep1 ||
           mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion4);

        /* Delay: '<S131>/Delay One Step' */
        doReset = mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion4;
        if (mcb_pmsm_hall_offset_f28069m_B.OR) {
          if (doReset) {
            mcb_pmsm_hall_offset_f280_DWork.DelayOneStep_DSTATE = 2500U;
          }

          /* Delay: '<S131>/Delay One Step' */
          mcb_pmsm_hall_offset_f28069m_B.DelayOneStep =
            mcb_pmsm_hall_offset_f280_DWork.DelayOneStep_DSTATE;
        }

        /* End of Delay: '<S131>/Delay One Step' */

        /* RelationalOperator: '<S135>/Compare' incorporates:
         *  Constant: '<S135>/Constant'
         */
        mcb_pmsm_hall_offset_f28069m_B.Compare =
          (mcb_pmsm_hall_offset_f28069m_B.DelayOneStep > 0U);

        /* Switch: '<S134>/watchdog check' */
        if (mcb_pmsm_hall_offset_f28069m_B.Compare) {
          /* MinMax: '<S134>/Max' */
          u0 = mcb_pmsm_hall_offset_f28069m_B.DataStoreRead2;
          u1 = mcb_pmsm_hall_offset_f28069m_B.Min;
          if (u0 >= u1) {
            u1 = u0;
          }

          /* MinMax: '<S134>/Max' */
          mcb_pmsm_hall_offset_f28069m_B.Max = u1;

          /* Switch: '<S134>/speed check' */
          if (mcb_pmsm_hall_offset_f28069m_B.Max >= 33750000UL) {
            /* Switch: '<S134>/speed check' incorporates:
             *  Constant: '<S134>/Constant'
             */
            mcb_pmsm_hall_offset_f28069m_B.speedcheck = 0U;
          } else {
            /* Logic: '<S130>/Logical Operator' */
            mcb_pmsm_hall_offset_f28069m_B.LogicalOperator =
              (mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion_k ||
               mcb_pmsm_hall_offset_f28069m_B.validityDelay);

            /* Switch: '<S134>/speed check' */
            mcb_pmsm_hall_offset_f28069m_B.speedcheck =
              mcb_pmsm_hall_offset_f28069m_B.LogicalOperator;
          }

          /* End of Switch: '<S134>/speed check' */

          /* Switch: '<S134>/watchdog check' */
          mcb_pmsm_hall_offset_f28069m_B.watchdogcheck =
            mcb_pmsm_hall_offset_f28069m_B.speedcheck;
        } else {
          /* Switch: '<S134>/watchdog check' incorporates:
           *  Constant: '<S134>/Constant'
           */
          mcb_pmsm_hall_offset_f28069m_B.watchdogcheck = 0U;
        }

        /* End of Switch: '<S134>/watchdog check' */

        /* If: '<S129>/If' */
        if (mcb_pmsm_hall_offset_f28069m_B.watchdogcheck != 0U) {
          /* Outputs for IfAction SubSystem: '<S129>/Speed and direction are valid Use speed to extrapolate position' incorporates:
           *  ActionPort: '<S133>/Action Port'
           */
          /* DataTypeConversion: '<S133>/currentSpeedData' */
          mcb_pmsm_hall_offset_f28069m_B.currentSpeedData = (real32_T)
            mcb_pmsm_hall_offset_f28069m_B.DataStoreRead2;

          /* Product: '<S133>/Divide' */
          mcb_pmsm_hall_offset_f28069m_B.Divide = 3.375E+7F /
            mcb_pmsm_hall_offset_f28069m_B.currentSpeedData;

          /* Gain: '<S133>/SpeedGain' */
          mcb_pmsm_hall_offset_f28069m_B.SpeedGain = 0.00333333341F *
            mcb_pmsm_hall_offset_f28069m_B.Divide;

          /* If: '<S133>/If' */
          if (mcb_pmsm_hall_offset_f28069m_B.DataStoreRead3 > 0) {
            /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem' incorporates:
             *  ActionPort: '<S144>/Action Port'
             */
            /* Merge: '<S129>/Merge' incorporates:
             *  SignalConversion generated from: '<S144>/In1'
             */
            mcb_pmsm_hall_offset_f28069m_B.Merge =
              mcb_pmsm_hall_offset_f28069m_B.SpeedGain;

            /* End of Outputs for SubSystem: '<S133>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S145>/Action Port'
             */
            /* Merge: '<S129>/Merge' incorporates:
             *  UnaryMinus: '<S145>/Unary Minus'
             */
            mcb_pmsm_hall_offset_f28069m_B.Merge =
              -mcb_pmsm_hall_offset_f28069m_B.SpeedGain;

            /* End of Outputs for SubSystem: '<S133>/If Action Subsystem1' */
          }

          /* End of If: '<S133>/If' */

          /* Outputs for Enabled SubSystem: '<S133>/Subsystem1' incorporates:
           *  EnablePort: '<S146>/Enable'
           */
          /* Outputs for IfAction SubSystem: '<S146>/first_order' incorporates:
           *  ActionPort: '<S149>/Action Port'
           */
          /* If: '<S146>/If1' incorporates:
           *  DataTypeConversion: '<S149>/countData'
           *  DataTypeConversion: '<S149>/currentSpeedData'
           *  Gain: '<S149>/Gain'
           *  Merge: '<S146>/Merge1'
           *  Product: '<S149>/Divide'
           */
          mcb_pmsm_hall_offset_f28069m_B.countData = (real32_T)
            mcb_pmsm_hall_offset_f28069m_B.Min;
          mcb_pmsm_hall_offset_f28069m_B.currentSpeedData_g = (real32_T)
            mcb_pmsm_hall_offset_f28069m_B.DataStoreRead2;
          mcb_pmsm_hall_offset_f28069m_B.Divide_m =
            mcb_pmsm_hall_offset_f28069m_B.countData /
            mcb_pmsm_hall_offset_f28069m_B.currentSpeedData_g;
          mcb_pmsm_hall_offset_f28069m_B.Merge1_f = 0.5F *
            mcb_pmsm_hall_offset_f28069m_B.Divide_m;

          /* End of Outputs for SubSystem: '<S146>/first_order' */

          /* Saturate: '<S146>/Saturation' */
          u0_p = mcb_pmsm_hall_offset_f28069m_B.Merge1_f;
          if (u0_p > 0.16667F) {
            /* Saturate: '<S146>/Saturation' */
            mcb_pmsm_hall_offset_f28069m_B.Saturation = 0.16667F;
          } else {
            /* Saturate: '<S146>/Saturation' */
            mcb_pmsm_hall_offset_f28069m_B.Saturation = u0_p;
          }

          /* End of Saturate: '<S146>/Saturation' */

          /* If: '<S146>/If' */
          if (mcb_pmsm_hall_offset_f28069m_B.DataStoreRead3 != 1) {
            /* Outputs for IfAction SubSystem: '<S146>/-ve Direction' incorporates:
             *  ActionPort: '<S148>/Action Port'
             */
            /* SwitchCase: '<S148>/Switch Case' */
            switch ((int32_T)mcb_pmsm_hall_offset_f28069m_B.DataStoreRead_p) {
             case 5L:
              /* Outputs for IfAction SubSystem: '<S148>/Hall Value of 1' incorporates:
               *  ActionPort: '<S158>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof1
                (&mcb_pmsm_hall_offset_f28069m_B.Merge1_m);

              /* End of Outputs for SubSystem: '<S148>/Hall Value of 1' */
              break;

             case 4L:
              /* Outputs for IfAction SubSystem: '<S148>/Hall Value of 2' incorporates:
               *  ActionPort: '<S159>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof2
                (&mcb_pmsm_hall_offset_f28069m_B.Merge1_m);

              /* End of Outputs for SubSystem: '<S148>/Hall Value of 2' */
              break;

             case 6L:
              /* Outputs for IfAction SubSystem: '<S148>/Hall Value of 3' incorporates:
               *  ActionPort: '<S160>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof3
                (&mcb_pmsm_hall_offset_f28069m_B.Merge1_m);

              /* End of Outputs for SubSystem: '<S148>/Hall Value of 3' */
              break;

             case 2L:
              /* Outputs for IfAction SubSystem: '<S148>/Hall Value of 4' incorporates:
               *  ActionPort: '<S161>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof4
                (&mcb_pmsm_hall_offset_f28069m_B.Merge1_m);

              /* End of Outputs for SubSystem: '<S148>/Hall Value of 4' */
              break;

             case 3L:
              /* Outputs for IfAction SubSystem: '<S148>/Hall Value of 5' incorporates:
               *  ActionPort: '<S162>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof5
                (&mcb_pmsm_hall_offset_f28069m_B.Merge1_m);

              /* End of Outputs for SubSystem: '<S148>/Hall Value of 5' */
              break;

             case 1L:
              /* Outputs for IfAction SubSystem: '<S148>/Hall Value of 6' incorporates:
               *  ActionPort: '<S163>/Action Port'
               */
              /* Merge: '<S148>/Merge1' incorporates:
               *  Constant: '<S163>/Constant'
               *  SignalConversion generated from: '<S163>/position'
               */
              mcb_pmsm_hall_offset_f28069m_B.Merge1_m = 1.0F;

              /* End of Outputs for SubSystem: '<S148>/Hall Value of 6' */
              break;

             default:
              /* Outputs for IfAction SubSystem: '<S148>/Hall Value of 7' incorporates:
               *  ActionPort: '<S164>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof7
                (&mcb_pmsm_hall_offset_f28069m_B.Merge1_m);

              /* End of Outputs for SubSystem: '<S148>/Hall Value of 7' */
              break;
            }

            /* End of SwitchCase: '<S148>/Switch Case' */

            /* Merge: '<S146>/Merge' incorporates:
             *  Sum: '<S148>/Sum'
             */
            mcb_pmsm_hall_offset_f28069m_B.Merge_g =
              mcb_pmsm_hall_offset_f28069m_B.Merge1_m -
              mcb_pmsm_hall_offset_f28069m_B.Saturation;

            /* End of Outputs for SubSystem: '<S146>/-ve Direction' */
          } else {
            /* Outputs for IfAction SubSystem: '<S146>/+ve Direction' incorporates:
             *  ActionPort: '<S147>/Action Port'
             */
            /* SwitchCase: '<S147>/Switch Case' */
            switch ((int32_T)mcb_pmsm_hall_offset_f28069m_B.DataStoreRead_p) {
             case 5L:
              /* Outputs for IfAction SubSystem: '<S147>/Hall Value of 1' incorporates:
               *  ActionPort: '<S151>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof7
                (&mcb_pmsm_hall_offset_f28069m_B.Merge1_o);

              /* End of Outputs for SubSystem: '<S147>/Hall Value of 1' */
              break;

             case 4L:
              /* Outputs for IfAction SubSystem: '<S147>/Hall Value of 2' incorporates:
               *  ActionPort: '<S152>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof1
                (&mcb_pmsm_hall_offset_f28069m_B.Merge1_o);

              /* End of Outputs for SubSystem: '<S147>/Hall Value of 2' */
              break;

             case 6L:
              /* Outputs for IfAction SubSystem: '<S147>/Hall Value of 3' incorporates:
               *  ActionPort: '<S153>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof2
                (&mcb_pmsm_hall_offset_f28069m_B.Merge1_o);

              /* End of Outputs for SubSystem: '<S147>/Hall Value of 3' */
              break;

             case 2L:
              /* Outputs for IfAction SubSystem: '<S147>/Hall Value of 4' incorporates:
               *  ActionPort: '<S154>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof3
                (&mcb_pmsm_hall_offset_f28069m_B.Merge1_o);

              /* End of Outputs for SubSystem: '<S147>/Hall Value of 4' */
              break;

             case 3L:
              /* Outputs for IfAction SubSystem: '<S147>/Hall Value of 5' incorporates:
               *  ActionPort: '<S155>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof4
                (&mcb_pmsm_hall_offset_f28069m_B.Merge1_o);

              /* End of Outputs for SubSystem: '<S147>/Hall Value of 5' */
              break;

             case 1L:
              /* Outputs for IfAction SubSystem: '<S147>/Hall Value of 6' incorporates:
               *  ActionPort: '<S156>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof5
                (&mcb_pmsm_hall_offset_f28069m_B.Merge1_o);

              /* End of Outputs for SubSystem: '<S147>/Hall Value of 6' */
              break;

             default:
              /* Outputs for IfAction SubSystem: '<S147>/Hall Value of 7' incorporates:
               *  ActionPort: '<S157>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof7
                (&mcb_pmsm_hall_offset_f28069m_B.Merge1_o);

              /* End of Outputs for SubSystem: '<S147>/Hall Value of 7' */
              break;
            }

            /* End of SwitchCase: '<S147>/Switch Case' */

            /* Merge: '<S146>/Merge' incorporates:
             *  Sum: '<S147>/Sum'
             */
            mcb_pmsm_hall_offset_f28069m_B.Merge_g =
              mcb_pmsm_hall_offset_f28069m_B.Merge1_o +
              mcb_pmsm_hall_offset_f28069m_B.Saturation;

            /* End of Outputs for SubSystem: '<S146>/+ve Direction' */
          }

          /* End of If: '<S146>/If' */
          /* End of Outputs for SubSystem: '<S133>/Subsystem1' */

          /* Merge: '<S129>/Merge1' incorporates:
           *  SignalConversion generated from: '<S133>/rawPosition'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge1 =
            mcb_pmsm_hall_offset_f28069m_B.Merge_g;

          /* End of Outputs for SubSystem: '<S129>/Speed and direction are valid Use speed to extrapolate position' */
        } else {
          /* Outputs for IfAction SubSystem: '<S129>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
           *  ActionPort: '<S132>/Action Port'
           */
          /* SwitchCase: '<S136>/Switch Case' */
          switch ((int32_T)mcb_pmsm_hall_offset_f28069m_B.DataStoreRead_p) {
           case 5L:
            /* Outputs for IfAction SubSystem: '<S136>/Hall Value of 1' incorporates:
             *  ActionPort: '<S137>/Action Port'
             */
            /* Merge: '<S129>/Merge1' incorporates:
             *  Constant: '<S137>/Constant'
             *  SignalConversion generated from: '<S137>/position'
             */
            mcb_pmsm_hall_offset_f28069m_B.Merge1 = 0.083333F;

            /* End of Outputs for SubSystem: '<S136>/Hall Value of 1' */
            break;

           case 4L:
            /* Outputs for IfAction SubSystem: '<S136>/Hall Value of 2' incorporates:
             *  ActionPort: '<S138>/Action Port'
             */
            /* Merge: '<S129>/Merge1' incorporates:
             *  Constant: '<S138>/Constant'
             *  SignalConversion generated from: '<S138>/position'
             */
            mcb_pmsm_hall_offset_f28069m_B.Merge1 = 0.25F;

            /* End of Outputs for SubSystem: '<S136>/Hall Value of 2' */
            break;

           case 6L:
            /* Outputs for IfAction SubSystem: '<S136>/Hall Value of 3' incorporates:
             *  ActionPort: '<S139>/Action Port'
             */
            /* Merge: '<S129>/Merge1' incorporates:
             *  Constant: '<S139>/Constant'
             *  SignalConversion generated from: '<S139>/position'
             */
            mcb_pmsm_hall_offset_f28069m_B.Merge1 = 0.41667F;

            /* End of Outputs for SubSystem: '<S136>/Hall Value of 3' */
            break;

           case 2L:
            /* Outputs for IfAction SubSystem: '<S136>/Hall Value of 4' incorporates:
             *  ActionPort: '<S140>/Action Port'
             */
            /* Merge: '<S129>/Merge1' incorporates:
             *  Constant: '<S140>/Constant'
             *  SignalConversion generated from: '<S140>/position'
             */
            mcb_pmsm_hall_offset_f28069m_B.Merge1 = 0.58333F;

            /* End of Outputs for SubSystem: '<S136>/Hall Value of 4' */
            break;

           case 3L:
            /* Outputs for IfAction SubSystem: '<S136>/Hall Value of 5' incorporates:
             *  ActionPort: '<S141>/Action Port'
             */
            /* Merge: '<S129>/Merge1' incorporates:
             *  Constant: '<S141>/Constant'
             *  SignalConversion generated from: '<S141>/position'
             */
            mcb_pmsm_hall_offset_f28069m_B.Merge1 = 0.75F;

            /* End of Outputs for SubSystem: '<S136>/Hall Value of 5' */
            break;

           case 1L:
            /* Outputs for IfAction SubSystem: '<S136>/Hall Value of 6' incorporates:
             *  ActionPort: '<S142>/Action Port'
             */
            /* Merge: '<S129>/Merge1' incorporates:
             *  Constant: '<S142>/Constant'
             *  SignalConversion generated from: '<S142>/position'
             */
            mcb_pmsm_hall_offset_f28069m_B.Merge1 = 0.91667F;

            /* End of Outputs for SubSystem: '<S136>/Hall Value of 6' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S136>/Hall Value of 7' incorporates:
             *  ActionPort: '<S143>/Action Port'
             */
            mcb_pmsm_hall_offs_HallValueof7
              (&mcb_pmsm_hall_offset_f28069m_B.Merge1);

            /* End of Outputs for SubSystem: '<S136>/Hall Value of 7' */
            break;
          }

          /* End of SwitchCase: '<S136>/Switch Case' */

          /* Merge: '<S129>/Merge' incorporates:
           *  Constant: '<S132>/Constant'
           *  SignalConversion generated from: '<S132>/Speed(r.p.m)'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge = 0.0F;

          /* End of Outputs for SubSystem: '<S129>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
        }

        /* End of If: '<S129>/If' */

        /* Sum: '<S131>/Sum' incorporates:
         *  Constant: '<S131>/Constant2'
         */
        mcb_pmsm_hall_offset_f28069m_B.Sum_a =
          mcb_pmsm_hall_offset_f28069m_B.DelayOneStep - 1U;

        /* UnitDelay: '<S120>/Output' */
        mcb_pmsm_hall_offset_f28069m_B.Output =
          mcb_pmsm_hall_offset_f280_DWork.Output_DSTATE;

        /* DataStoreRead: '<S74>/Data Store Read' */
        mcb_pmsm_hall_offset_f28069m_B.DataStoreRead_c =
          mcb_pmsm_hall_offset_f280_DWork.Enable;

        /* Outputs for Enabled SubSystem: '<S74>/PosGen' incorporates:
         *  EnablePort: '<S82>/Enable'
         */
        if (mcb_pmsm_hall_offset_f28069m_B.DataStoreRead_c) {
          if (!mcb_pmsm_hall_offset_f280_DWork.PosGen_MODE) {
            /* InitializeConditions for UnitDelay: '<S102>/Unit Delay' */
            mcb_pmsm_hall_offset_f280_DWork.UnitDelay_DSTATE = 0.0F;
            mcb_pmsm_hall_offset_f280_DWork.PosGen_MODE = true;
          }

          /* Outputs for Enabled SubSystem: '<S82>/Up Counter' incorporates:
           *  EnablePort: '<S99>/Enable'
           */
          if (!mcb_pmsm_hall_offset_f280_DWork.UpCounter_MODE) {
            /* InitializeConditions for Delay: '<S99>/Delay' */
            mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE_pm = 0UL;
            mcb_pmsm_hall_offset_f280_DWork.UpCounter_MODE = true;
          }

          /* Delay: '<S99>/Delay' */
          mcb_pmsm_hall_offset_f28069m_B.Delay =
            mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE_pm;

          /* Sum: '<S99>/Add1' */
          uLong2MultiWord(mcb_pmsm_hall_offset_f28069m_B.Delay, &tmp_p.chunks[0U],
                          2);
          MultiWordAdd(&tmp_e.chunks[0U], &tmp_p.chunks[0U], &tmp.chunks[0U], 2);

          /* Sum: '<S99>/Add1' */
          mcb_pmsm_hall_offset_f28069m_B.Add1 = uMultiWord2uLongSat(&tmp.chunks
            [0U], 2);

          /* Update for Delay: '<S99>/Delay' */
          mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE_pm =
            mcb_pmsm_hall_offset_f28069m_B.Add1;

          /* End of Outputs for SubSystem: '<S82>/Up Counter' */

          /* RelationalOperator: '<S95>/Compare' incorporates:
           *  Constant: '<S95>/Constant'
           */
          mcb_pmsm_hall_offset_f28069m_B.Compare_a =
            (mcb_pmsm_hall_offset_f28069m_B.Add1 <= 440000UL);

          /* Logic: '<S82>/NOT' */
          mcb_pmsm_hall_offset_f28069m_B.NOT_k =
            !mcb_pmsm_hall_offset_f28069m_B.Compare_a;

          /* Outputs for Enabled SubSystem: '<S82>/Subsystem' incorporates:
           *  EnablePort: '<S97>/Enable'
           */
          if (mcb_pmsm_hall_offset_f28069m_B.NOT_k) {
            /* DataStoreWrite: '<S97>/Data Store Write' incorporates:
             *  Constant: '<S97>/Constant'
             */
            mcb_pmsm_hall_offset_f280_DWork.Enable = false;
          }

          /* End of Outputs for SubSystem: '<S82>/Subsystem' */

          /* RelationalOperator: '<S96>/Compare' incorporates:
           *  Constant: '<S96>/Constant'
           */
          mcb_pmsm_hall_offset_f28069m_B.Compare_i =
            (mcb_pmsm_hall_offset_f28069m_B.Add1 <= 400000UL);

          /* If: '<S98>/If' incorporates:
           *  Constant: '<S98>/Count for 2 sec'
           */
          if (mcb_pmsm_hall_offset_f28069m_B.Add1 < 50000UL) {
            /* Outputs for IfAction SubSystem: '<S98>/If Action Subsystem' incorporates:
             *  ActionPort: '<S100>/Action Port'
             */
            /* Merge: '<S98>/Merge' incorporates:
             *  Constant: '<S100>/Constant'
             *  SignalConversion generated from: '<S100>/Out1'
             */
            mcb_pmsm_hall_offset_f28069m_B.Merge_o = 0.0F;

            /* End of Outputs for SubSystem: '<S98>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S98>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S101>/Action Port'
             */
            /* Delay: '<S101>/Delay' */
            mcb_pmsm_hall_offset_f28069m_B.Delay_b =
              mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE;

            /* Sum: '<S101>/Add1' incorporates:
             *  Constant: '<S101>/Constant1'
             */
            mcb_pmsm_hall_offset_f28069m_B.Add1_d =
              mcb_pmsm_hall_offset_f28069m_B.Delay_b + 0.001F;

            /* Saturate: '<S101>/Saturate to 'motor.calibSpeed' RPM' */
            u0_p = mcb_pmsm_hall_offset_f28069m_B.Add1_d;
            if (u0_p > 4.0F) {
              /* Saturate: '<S101>/Saturate to 'motor.calibSpeed' RPM' */
              mcb_pmsm_hall_offset_f28069m_B.SaturatetomotorcalibSpeedRPM = 4.0F;
            } else if (u0_p < 0.0F) {
              /* Saturate: '<S101>/Saturate to 'motor.calibSpeed' RPM' */
              mcb_pmsm_hall_offset_f28069m_B.SaturatetomotorcalibSpeedRPM = 0.0F;
            } else {
              /* Saturate: '<S101>/Saturate to 'motor.calibSpeed' RPM' */
              mcb_pmsm_hall_offset_f28069m_B.SaturatetomotorcalibSpeedRPM = u0_p;
            }

            /* End of Saturate: '<S101>/Saturate to 'motor.calibSpeed' RPM' */

            /* Merge: '<S98>/Merge' incorporates:
             *  Gain: '<S101>/Multiply'
             */
            mcb_pmsm_hall_offset_f28069m_B.Merge_o = 5.0E-5F *
              mcb_pmsm_hall_offset_f28069m_B.SaturatetomotorcalibSpeedRPM;

            /* Update for Delay: '<S101>/Delay' */
            mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE =
              mcb_pmsm_hall_offset_f28069m_B.SaturatetomotorcalibSpeedRPM;

            /* End of Outputs for SubSystem: '<S98>/If Action Subsystem2' */
          }

          /* End of If: '<S98>/If' */

          /* UnitDelay: '<S102>/Unit Delay' */
          mcb_pmsm_hall_offset_f28069m_B.UnitDelay =
            mcb_pmsm_hall_offset_f280_DWork.UnitDelay_DSTATE;

          /* Logic: '<S102>/NOT' incorporates:
           *  Constant: '<S102>/Constant_Reset'
           */
          mcb_pmsm_hall_offset_f28069m_B.NOT_g = true;

          /* Outputs for Enabled SubSystem: '<S102>/Accumulate' incorporates:
           *  EnablePort: '<S103>/Enable'
           */
          /* Delay: '<S103>/Delay' */
          mcb_pmsm_hall_offset_f28069m_B.Delay_c =
            mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE_b;

          /* Outputs for Enabled SubSystem: '<S103>/Subsystem' incorporates:
           *  EnablePort: '<S104>/Enable'
           */
          if (mcb_pmsm_hall_offset_f28069m_B.Delay_c) {
            /* SignalConversion generated from: '<S104>/Input' */
            mcb_pmsm_hall_offset_f28069m_B.Input_d =
              mcb_pmsm_hall_offset_f28069m_B.Merge_o;
          }

          /* End of Outputs for SubSystem: '<S103>/Subsystem' */

          /* Sum: '<S103>/Add' */
          mcb_pmsm_hall_offset_f28069m_B.Add_e =
            mcb_pmsm_hall_offset_f28069m_B.Input_d +
            mcb_pmsm_hall_offset_f28069m_B.UnitDelay;

          /* DataTypeConversion: '<S103>/Data Type Conversion' */
          mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion_c = (int16_T)
            (real32_T)floor(mcb_pmsm_hall_offset_f28069m_B.Add_e);

          /* DataTypeConversion: '<S103>/Data Type Conversion1' */
          mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_d =
            mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion_c;

          /* Sum: '<S103>/Add1' */
          mcb_pmsm_hall_offset_f28069m_B.Add1_m =
            mcb_pmsm_hall_offset_f28069m_B.Add_e -
            mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_d;

          /* Update for Delay: '<S103>/Delay' incorporates:
           *  Constant: '<S103>/Constant'
           */
          mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE_b = true;

          /* End of Outputs for SubSystem: '<S102>/Accumulate' */

          /* Gain: '<S102>/scaleOut' */
          mcb_pmsm_hall_offset_f28069m_B.scaleOut =
            mcb_pmsm_hall_offset_f28069m_B.Add1_m;

          /* Update for UnitDelay: '<S102>/Unit Delay' */
          mcb_pmsm_hall_offset_f280_DWork.UnitDelay_DSTATE =
            mcb_pmsm_hall_offset_f28069m_B.Add1_m;
        } else if (mcb_pmsm_hall_offset_f280_DWork.PosGen_MODE) {
          /* Disable for Enabled SubSystem: '<S82>/Up Counter' */
          if (mcb_pmsm_hall_offset_f280_DWork.UpCounter_MODE) {
            /* Disable for Sum: '<S99>/Add1' incorporates:
             *  Outport: '<S99>/Count'
             */
            mcb_pmsm_hall_offset_f28069m_B.Add1 = 0UL;
            mcb_pmsm_hall_offset_f280_DWork.UpCounter_MODE = false;
          }

          /* End of Disable for SubSystem: '<S82>/Up Counter' */

          /* Disable for RelationalOperator: '<S96>/Compare' incorporates:
           *  Outport: '<S82>/EnPWM'
           */
          mcb_pmsm_hall_offset_f28069m_B.Compare_i = false;

          /* Disable for RelationalOperator: '<S95>/Compare' incorporates:
           *  Outport: '<S82>/EnableHost'
           */
          mcb_pmsm_hall_offset_f28069m_B.Compare_a = false;
          mcb_pmsm_hall_offset_f280_DWork.PosGen_MODE = false;
        }

        /* End of Outputs for SubSystem: '<S74>/PosGen' */

        /* Switch: '<S6>/Switch' */
        if (mcb_pmsm_hall_offset_f28069m_B.Compare_a) {
          /* Switch: '<S6>/Switch' */
          mcb_pmsm_hall_offset_f28069m_B.Switch_m =
            mcb_pmsm_hall_offset_f28069m_B.Merge1;
        } else {
          /* Switch: '<S6>/Switch' incorporates:
           *  Constant: '<S6>/Constant'
           */
          mcb_pmsm_hall_offset_f28069m_B.Switch_m = -1.0F;
        }

        /* End of Switch: '<S6>/Switch' */

        /* Outputs for Enabled SubSystem: '<S74>/Find Offset' incorporates:
         *  EnablePort: '<S80>/Enable'
         */
        if (mcb_pmsm_hall_offset_f28069m_B.Compare_i) {
          if (!mcb_pmsm_hall_offset_f280_DWork.FindOffset_MODE) {
            /* InitializeConditions for Delay: '<S80>/Delay' */
            mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE_p = 0.0F;
            mcb_pmsm_hall_offset_f280_DWork.FindOffset_MODE = true;
          }

          /* RelationalOperator: '<S86>/Compare' incorporates:
           *  Constant: '<S86>/Constant'
           */
          mcb_pmsm_hall_offset_f28069m_B.Compare_au =
            (mcb_pmsm_hall_offset_f28069m_B.scaleOut <= 0.01F);

          /* Delay: '<S80>/Delay' */
          mcb_pmsm_hall_offset_f28069m_B.Delay_o =
            mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE_p;

          /* RelationalOperator: '<S87>/Compare' incorporates:
           *  Constant: '<S87>/Constant'
           */
          mcb_pmsm_hall_offset_f28069m_B.Compare_j =
            (mcb_pmsm_hall_offset_f28069m_B.Delay_o >= 0.99F);

          /* Logic: '<S80>/AND' */
          mcb_pmsm_hall_offset_f28069m_B.AND =
            (mcb_pmsm_hall_offset_f28069m_B.Compare_au &&
             mcb_pmsm_hall_offset_f28069m_B.Compare_j);

          /* Outputs for Enabled SubSystem: '<S80>/Subsystem' incorporates:
           *  EnablePort: '<S88>/Enable'
           */
          if (mcb_pmsm_hall_offset_f28069m_B.AND) {
            /* Switch: '<S89>/Switch1' incorporates:
             *  Constant: '<S89>/FilterConstant'
             *  Constant: '<S89>/OneMinusFilterConstant'
             */
            mcb_pmsm_hall_offset_f28069m_B.Switch1[0] = 0.5F;
            mcb_pmsm_hall_offset_f28069m_B.Switch1[1] = 0.5F;

            /* Product: '<S92>/Product' */
            mcb_pmsm_hall_offset_f28069m_B.Product_l =
              mcb_pmsm_hall_offset_f28069m_B.Merge1 * 0.5F;

            /* UnitDelay: '<S92>/Unit Delay' */
            mcb_pmsm_hall_offset_f28069m_B.UnitDelay_d =
              mcb_pmsm_hall_offset_f280_DWork.UnitDelay_DSTATE_f;

            /* Product: '<S92>/Product1' */
            mcb_pmsm_hall_offset_f28069m_B.Product1_m = 0.5F *
              mcb_pmsm_hall_offset_f28069m_B.UnitDelay_d;

            /* Sum: '<S92>/Add1' */
            mcb_pmsm_hall_offset_f28069m_B.Add1_mi =
              mcb_pmsm_hall_offset_f28069m_B.Product_l +
              mcb_pmsm_hall_offset_f28069m_B.Product1_m;

            /* Update for UnitDelay: '<S92>/Unit Delay' */
            mcb_pmsm_hall_offset_f280_DWork.UnitDelay_DSTATE_f =
              mcb_pmsm_hall_offset_f28069m_B.Add1_mi;
          }

          /* End of Outputs for SubSystem: '<S80>/Subsystem' */

          /* Update for Delay: '<S80>/Delay' */
          mcb_pmsm_hall_offset_f280_DWork.Delay_DSTATE_p =
            mcb_pmsm_hall_offset_f28069m_B.scaleOut;
        } else {
          mcb_pmsm_hall_offset_f280_DWork.FindOffset_MODE = false;
        }

        /* End of Outputs for SubSystem: '<S74>/Find Offset' */

        /* Logic: '<S74>/NOT' */
        mcb_pmsm_hall_offset_f28069m_B.NOT =
          !mcb_pmsm_hall_offset_f28069m_B.Compare_i;

        /* Outputs for Enabled SubSystem: '<S74>/Subsystem1' incorporates:
         *  EnablePort: '<S85>/Enable'
         */
        if (mcb_pmsm_hall_offset_f28069m_B.NOT) {
          /* SignalConversion generated from: '<S85>/Input' */
          mcb_pmsm_hall_offset_f28069m_B.Input =
            mcb_pmsm_hall_offset_f28069m_B.Add1_mi;
        }

        /* End of Outputs for SubSystem: '<S74>/Subsystem1' */

        /* DataTypeConversion: '<S122>/Data Type Conversion1' */
        mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_m[0] = (int32_T)
          (mcb_pmsm_hall_offset_f28069m_B.Switch_m * 4096.0F);
        mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_m[1] = (int32_T)
          (mcb_pmsm_hall_offset_f28069m_B.Input * 4096.0F);

        /* DataTypeConversion: '<S122>/Data Type Conversion3' incorporates:
         *  DataTypeConversion: '<S122>/Data Type Conversion1'
         */
        mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion3[0] = (uint16_T)
          mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_m[0];
        mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion3[1] = (uint16_T)
          mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_m[1];

        /* If: '<S75>/If' */
        if (mcb_pmsm_hall_offset_f28069m_B.Output == 0U) {
          /* Outputs for IfAction SubSystem: '<S75>/Start' incorporates:
           *  ActionPort: '<S124>/Action Port'
           */
          /* Merge: '<S75>/Merge' incorporates:
           *  Constant: '<S124>/End'
           *  SignalConversion generated from: '<S124>/Data_out'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge_ol[0] = 21331U;

          /* SignalConversion generated from: '<S124>/Data' */
          Data = mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion3[0];

          /* End of Outputs for SubSystem: '<S75>/Start' */
          mcb_pmsm_hall_offset_f28069m_B.Data_fw[0] = Data;

          /* Outputs for IfAction SubSystem: '<S75>/Start' incorporates:
           *  ActionPort: '<S124>/Action Port'
           */
          /* Merge: '<S75>/Merge' incorporates:
           *  SignalConversion generated from: '<S124>/Data_out'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge_ol[1] = Data;

          /* SignalConversion generated from: '<S124>/Data' */
          Data = mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion3[1];

          /* End of Outputs for SubSystem: '<S75>/Start' */
          mcb_pmsm_hall_offset_f28069m_B.Data_fw[1] = Data;

          /* Outputs for IfAction SubSystem: '<S75>/Start' incorporates:
           *  ActionPort: '<S124>/Action Port'
           */
          /* Merge: '<S75>/Merge' incorporates:
           *  SignalConversion generated from: '<S124>/Data_out'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge_ol[2] = Data;

          /* Merge: '<S75>/Merge1' incorporates:
           *  Bias: '<S124>/Bias'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge1_b = 3U;

          /* End of Outputs for SubSystem: '<S75>/Start' */
        } else if (mcb_pmsm_hall_offset_f28069m_B.Output == 599U) {
          /* Outputs for IfAction SubSystem: '<S75>/End' incorporates:
           *  ActionPort: '<S123>/Action Port'
           */
          /* SignalConversion generated from: '<S123>/Data' */
          Data = mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion3[0];

          /* End of Outputs for SubSystem: '<S75>/End' */
          mcb_pmsm_hall_offset_f28069m_B.Data_f[0] = Data;

          /* Outputs for IfAction SubSystem: '<S75>/End' incorporates:
           *  ActionPort: '<S123>/Action Port'
           */
          /* Merge: '<S75>/Merge' incorporates:
           *  SignalConversion generated from: '<S123>/Data_out'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge_ol[0] = Data;

          /* SignalConversion generated from: '<S123>/Data' */
          Data = mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion3[1];

          /* End of Outputs for SubSystem: '<S75>/End' */
          mcb_pmsm_hall_offset_f28069m_B.Data_f[1] = Data;

          /* Outputs for IfAction SubSystem: '<S75>/End' incorporates:
           *  ActionPort: '<S123>/Action Port'
           */
          /* Merge: '<S75>/Merge' incorporates:
           *  Constant: '<S123>/Start'
           *  SignalConversion generated from: '<S123>/Data_out'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge_ol[1] = Data;
          mcb_pmsm_hall_offset_f28069m_B.Merge_ol[2] = 17733U;

          /* Merge: '<S75>/Merge1' incorporates:
           *  Bias: '<S123>/Bias'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge1_b = 3U;

          /* End of Outputs for SubSystem: '<S75>/End' */
        } else {
          /* Outputs for IfAction SubSystem: '<S75>/Data' incorporates:
           *  ActionPort: '<S121>/Action Port'
           */
          /* SignalConversion generated from: '<S121>/Data' */
          Data = mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion3[0];

          /* End of Outputs for SubSystem: '<S75>/Data' */
          mcb_pmsm_hall_offset_f28069m_B.Data[0] = Data;

          /* Outputs for IfAction SubSystem: '<S75>/Data' incorporates:
           *  ActionPort: '<S121>/Action Port'
           */
          /* Merge: '<S75>/Merge' incorporates:
           *  SignalConversion generated from: '<S121>/Data_out'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge_ol[0] = Data;

          /* SignalConversion generated from: '<S121>/Data' */
          Data = mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion3[1];

          /* End of Outputs for SubSystem: '<S75>/Data' */
          mcb_pmsm_hall_offset_f28069m_B.Data[1] = Data;

          /* Outputs for IfAction SubSystem: '<S75>/Data' incorporates:
           *  ActionPort: '<S121>/Action Port'
           */
          /* Merge: '<S75>/Merge' incorporates:
           *  Constant: '<S121>/Start'
           *  SignalConversion generated from: '<S121>/Data_out'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge_ol[1] = Data;
          mcb_pmsm_hall_offset_f28069m_B.Merge_ol[2] = 0U;

          /* Merge: '<S75>/Merge1' incorporates:
           *  SignalConversion generated from: '<S121>/Data_width'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge1_b = 2U;

          /* End of Outputs for SubSystem: '<S75>/Data' */
        }

        /* End of If: '<S75>/If' */

        /* Outputs for Iterator SubSystem: '<S75>/While Iterator Subsystem' incorporates:
         *  WhileIterator: '<S125>/While Iterator'
         */
        s125_iter = 1;
        do {
          mcb_pmsm_hall_offset_f28069m_B.WhileIterator = s125_iter;
          mcb_pmsm_hall_offset_f28069m_B.IndexVector =
            mcb_pmsm_hall_offset_f28069m_B.Merge_ol[mcb_pmsm_hall_offset_f28069m_B.WhileIterator
            - 1];

          {
            if (checkSCITransmitInProgressA != 1U) {
              checkSCITransmitInProgressA = 1U;
              int16_T errFlgHeader = NOERROR;
              int16_T errFlgData = NOERROR;
              int16_T errFlgTail = NOERROR;
              errFlgData = scia_xmit((uchar_T*)
                &mcb_pmsm_hall_offset_f28069m_B.IndexVector, 2, 2);
              checkSCITransmitInProgressA = 0U;
            }
          }

          mcb_pmsm_hall_offset_f28069m_B.Add_d =
            mcb_pmsm_hall_offset_f28069m_B.Merge1_b - (uint16_T)
            mcb_pmsm_hall_offset_f28069m_B.WhileIterator;
          s125_iter++;
        } while (mcb_pmsm_hall_offset_f28069m_B.Add_d != 0U);

        /* End of Outputs for SubSystem: '<S75>/While Iterator Subsystem' */

        /* Sum: '<S126>/FixPt Sum1' incorporates:
         *  Constant: '<S126>/FixPt Constant'
         */
        mcb_pmsm_hall_offset_f28069m_B.FixPtSum1 =
          mcb_pmsm_hall_offset_f28069m_B.Output + 1U;

        /* Switch: '<S127>/FixPt Switch' */
        if (mcb_pmsm_hall_offset_f28069m_B.FixPtSum1 > 599U) {
          /* Switch: '<S127>/FixPt Switch' incorporates:
           *  Constant: '<S127>/Constant'
           */
          mcb_pmsm_hall_offset_f28069m_B.FixPtSwitch = 0U;
        } else {
          /* Switch: '<S127>/FixPt Switch' */
          mcb_pmsm_hall_offset_f28069m_B.FixPtSwitch =
            mcb_pmsm_hall_offset_f28069m_B.FixPtSum1;
        }

        /* End of Switch: '<S127>/FixPt Switch' */

        /* RelationalOperator: '<S109>/Compare' incorporates:
         *  Constant: '<S109>/Constant'
         */
        mcb_pmsm_hall_offset_f28069m_B.Compare_e =
          (mcb_pmsm_hall_offset_f28069m_B.scaleOut < 0.0F);

        /* DataTypeConversion: '<S107>/Data Type Conversion' */
        mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion_g =
          mcb_pmsm_hall_offset_f28069m_B.Compare_e;

        /* If: '<S107>/If' */
        if (mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion_g > 0U) {
          /* Outputs for IfAction SubSystem: '<S107>/If Action Subsystem' incorporates:
           *  ActionPort: '<S110>/Action Port'
           */
          /* DataTypeConversion: '<S110>/Convert_uint16' */
          mcb_pmsm_hall_offset_f28069m_B.Convert_uint16_k = (int16_T)(real32_T)
            floor(mcb_pmsm_hall_offset_f28069m_B.scaleOut);

          /* DataTypeConversion: '<S110>/Convert_back' */
          mcb_pmsm_hall_offset_f28069m_B.Convert_back_c =
            mcb_pmsm_hall_offset_f28069m_B.Convert_uint16_k;

          /* Merge: '<S107>/Merge' incorporates:
           *  Sum: '<S110>/Sum'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge_l =
            mcb_pmsm_hall_offset_f28069m_B.scaleOut -
            mcb_pmsm_hall_offset_f28069m_B.Convert_back_c;

          /* End of Outputs for SubSystem: '<S107>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S107>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S111>/Action Port'
           */
          /* DataTypeConversion: '<S111>/Convert_uint16' */
          mcb_pmsm_hall_offset_f28069m_B.Convert_uint16 = (int16_T)
            mcb_pmsm_hall_offset_f28069m_B.scaleOut;

          /* DataTypeConversion: '<S111>/Convert_back' */
          mcb_pmsm_hall_offset_f28069m_B.Convert_back =
            mcb_pmsm_hall_offset_f28069m_B.Convert_uint16;

          /* Merge: '<S107>/Merge' incorporates:
           *  Sum: '<S111>/Sum'
           */
          mcb_pmsm_hall_offset_f28069m_B.Merge_l =
            mcb_pmsm_hall_offset_f28069m_B.scaleOut -
            mcb_pmsm_hall_offset_f28069m_B.Convert_back;

          /* End of Outputs for SubSystem: '<S107>/If Action Subsystem1' */
        }

        /* End of If: '<S107>/If' */

        /* Gain: '<S105>/indexing' */
        mcb_pmsm_hall_offset_f28069m_B.indexing = 800.0F *
          mcb_pmsm_hall_offset_f28069m_B.Merge_l;

        /* DataTypeConversion: '<S105>/Get_Integer' */
        mcb_pmsm_hall_offset_f28069m_B.Get_Integer = (uint16_T)
          mcb_pmsm_hall_offset_f28069m_B.indexing;

        /* Sum: '<S105>/Sum' incorporates:
         *  Constant: '<S105>/offset'
         */
        u1 = mcb_pmsm_hall_offset_f28069m_B.Get_Integer + 1UL;
        mcb_pmsm_hall_offset_f28069m_B.Sum[0] = u1;

        /* Selector: '<S105>/Lookup' incorporates:
         *  Constant: '<S105>/sine_table_values'
         */
        mcb_pmsm_hall_offset_f28069m_B.Lookup[0] =
          mcb_pmsm_hall_offset_f28_ConstP.sine_table_values_Value[(int16_T)u1];

        /* Sum: '<S105>/Sum' */
        u1 = mcb_pmsm_hall_offset_f28069m_B.Get_Integer;
        mcb_pmsm_hall_offset_f28069m_B.Sum[1] = u1;

        /* Selector: '<S105>/Lookup' incorporates:
         *  Constant: '<S105>/sine_table_values'
         */
        mcb_pmsm_hall_offset_f28069m_B.Lookup[1] =
          mcb_pmsm_hall_offset_f28_ConstP.sine_table_values_Value[(int16_T)u1];

        /* Sum: '<S105>/Sum' incorporates:
         *  Constant: '<S105>/offset'
         */
        u1 = mcb_pmsm_hall_offset_f28069m_B.Get_Integer + 201UL;
        mcb_pmsm_hall_offset_f28069m_B.Sum[2] = u1;

        /* Selector: '<S105>/Lookup' incorporates:
         *  Constant: '<S105>/sine_table_values'
         */
        mcb_pmsm_hall_offset_f28069m_B.Lookup[2] =
          mcb_pmsm_hall_offset_f28_ConstP.sine_table_values_Value[(int16_T)u1];

        /* Sum: '<S105>/Sum' incorporates:
         *  Constant: '<S105>/offset'
         */
        u1 = mcb_pmsm_hall_offset_f28069m_B.Get_Integer + 200UL;
        mcb_pmsm_hall_offset_f28069m_B.Sum[3] = u1;

        /* Selector: '<S105>/Lookup' incorporates:
         *  Constant: '<S105>/sine_table_values'
         */
        mcb_pmsm_hall_offset_f28069m_B.Lookup[3] =
          mcb_pmsm_hall_offset_f28_ConstP.sine_table_values_Value[(int16_T)u1];

        /* Sum: '<S106>/Sum3' */
        mcb_pmsm_hall_offset_f28069m_B.Sum3 =
          mcb_pmsm_hall_offset_f28069m_B.Lookup[0] -
          mcb_pmsm_hall_offset_f28069m_B.Lookup[1];

        /* DataTypeConversion: '<S105>/Data Type Conversion1' */
        mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_p =
          mcb_pmsm_hall_offset_f28069m_B.Get_Integer;

        /* Sum: '<S105>/Sum2' */
        mcb_pmsm_hall_offset_f28069m_B.Sum2 =
          mcb_pmsm_hall_offset_f28069m_B.indexing -
          mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_p;

        /* Product: '<S106>/Product' */
        mcb_pmsm_hall_offset_f28069m_B.Product =
          mcb_pmsm_hall_offset_f28069m_B.Sum3 *
          mcb_pmsm_hall_offset_f28069m_B.Sum2;

        /* Sum: '<S106>/Sum4' */
        mcb_pmsm_hall_offset_f28069m_B.Sum4 =
          mcb_pmsm_hall_offset_f28069m_B.Product +
          mcb_pmsm_hall_offset_f28069m_B.Lookup[1];

        /* Sum: '<S106>/Sum5' */
        mcb_pmsm_hall_offset_f28069m_B.Sum5 =
          mcb_pmsm_hall_offset_f28069m_B.Lookup[2] -
          mcb_pmsm_hall_offset_f28069m_B.Lookup[3];

        /* Product: '<S106>/Product1' */
        mcb_pmsm_hall_offset_f28069m_B.Product1 =
          mcb_pmsm_hall_offset_f28069m_B.Sum5 *
          mcb_pmsm_hall_offset_f28069m_B.Sum2;

        /* Sum: '<S106>/Sum6' */
        mcb_pmsm_hall_offset_f28069m_B.Sum6 =
          mcb_pmsm_hall_offset_f28069m_B.Product1 +
          mcb_pmsm_hall_offset_f28069m_B.Lookup[3];

        /* Outputs for Atomic SubSystem: '<S81>/Two inputs CRL' */
        /* Product: '<S93>/qcos' incorporates:
         *  Constant: '<S74>/Vq'
         */
        mcb_pmsm_hall_offset_f28069m_B.qcos = 0.0F *
          mcb_pmsm_hall_offset_f28069m_B.Sum6;

        /* Product: '<S93>/dsin' incorporates:
         *  Constant: '<S74>/Vd_Ref'
         */
        mcb_pmsm_hall_offset_f28069m_B.dsin = 0.15F *
          mcb_pmsm_hall_offset_f28069m_B.Sum4;

        /* Sum: '<S93>/sum_beta' */
        mcb_pmsm_hall_offset_f28069m_B.sum_beta =
          mcb_pmsm_hall_offset_f28069m_B.qcos +
          mcb_pmsm_hall_offset_f28069m_B.dsin;

        /* Product: '<S93>/dcos' incorporates:
         *  Constant: '<S74>/Vd_Ref'
         */
        mcb_pmsm_hall_offset_f28069m_B.dcos = 0.15F *
          mcb_pmsm_hall_offset_f28069m_B.Sum6;

        /* Product: '<S93>/qsin' incorporates:
         *  Constant: '<S74>/Vq'
         */
        mcb_pmsm_hall_offset_f28069m_B.qsin = 0.0F *
          mcb_pmsm_hall_offset_f28069m_B.Sum4;

        /* Sum: '<S93>/sum_alpha' */
        mcb_pmsm_hall_offset_f28069m_B.sum_alpha =
          mcb_pmsm_hall_offset_f28069m_B.dcos -
          mcb_pmsm_hall_offset_f28069m_B.qsin;

        /* Switch: '<S94>/Switch' */
        mcb_pmsm_hall_offset_f28069m_B.Switch_fs[0] =
          mcb_pmsm_hall_offset_f28069m_B.sum_alpha;
        mcb_pmsm_hall_offset_f28069m_B.Switch_fs[1] =
          mcb_pmsm_hall_offset_f28069m_B.sum_beta;

        /* AlgorithmDescriptorDelegate generated from: '<S93>/a16' */
        mcb_pmsm_hall_offset_f28069m_B.algDD_o1 =
          mcb_pmsm_hall_offset_f28069m_B.Switch_fs[0];

        /* AlgorithmDescriptorDelegate generated from: '<S93>/a16' */
        mcb_pmsm_hall_offset_f28069m_B.algDD_o2 =
          mcb_pmsm_hall_offset_f28069m_B.Switch_fs[1];

        /* End of Outputs for SubSystem: '<S81>/Two inputs CRL' */

        /* Switch: '<S76>/Switch4' */
        if (mcb_pmsm_hall_offset_f28069m_B.Compare_i) {
          /* Gain: '<S119>/sqrt3_by_two' */
          mcb_pmsm_hall_offset_f28069m_B.sqrt3_by_two = 0.866025388F *
            mcb_pmsm_hall_offset_f28069m_B.algDD_o2;

          /* Gain: '<S119>/one_by_two' */
          mcb_pmsm_hall_offset_f28069m_B.one_by_two = 0.5F *
            mcb_pmsm_hall_offset_f28069m_B.algDD_o1;

          /* Sum: '<S119>/add_c' */
          mcb_pmsm_hall_offset_f28069m_B.add_c = (0.0F -
            mcb_pmsm_hall_offset_f28069m_B.one_by_two) -
            mcb_pmsm_hall_offset_f28069m_B.sqrt3_by_two;

          /* Sum: '<S119>/add_b' */
          mcb_pmsm_hall_offset_f28069m_B.add_b =
            mcb_pmsm_hall_offset_f28069m_B.sqrt3_by_two -
            mcb_pmsm_hall_offset_f28069m_B.one_by_two;

          /* MinMax: '<S116>/Min' */
          u0_p = mcb_pmsm_hall_offset_f28069m_B.algDD_o1;
          Bias = mcb_pmsm_hall_offset_f28069m_B.add_b;
          if ((u0_p <= Bias) || rtIsNaNF(Bias)) {
            Bias = u0_p;
          }

          u0_p = mcb_pmsm_hall_offset_f28069m_B.add_c;
          if ((!(Bias <= u0_p)) && (!rtIsNaNF(u0_p))) {
            Bias = u0_p;
          }

          /* MinMax: '<S116>/Min' */
          mcb_pmsm_hall_offset_f28069m_B.Min_f = Bias;

          /* MinMax: '<S116>/Max' */
          u0_p = mcb_pmsm_hall_offset_f28069m_B.algDD_o1;
          Bias = mcb_pmsm_hall_offset_f28069m_B.add_b;
          if ((u0_p >= Bias) || rtIsNaNF(Bias)) {
            Bias = u0_p;
          }

          u0_p = mcb_pmsm_hall_offset_f28069m_B.add_c;
          if ((!(Bias >= u0_p)) && (!rtIsNaNF(u0_p))) {
            Bias = u0_p;
          }

          /* MinMax: '<S116>/Max' */
          mcb_pmsm_hall_offset_f28069m_B.Max_l = Bias;

          /* Sum: '<S116>/Add' */
          mcb_pmsm_hall_offset_f28069m_B.Add =
            mcb_pmsm_hall_offset_f28069m_B.Max_l +
            mcb_pmsm_hall_offset_f28069m_B.Min_f;

          /* Gain: '<S116>/one_by_two' */
          mcb_pmsm_hall_offset_f28069m_B.one_by_two_g = -0.5F *
            mcb_pmsm_hall_offset_f28069m_B.Add;

          /* Sum: '<S115>/Add2' */
          mcb_pmsm_hall_offset_f28069m_B.Add2 =
            mcb_pmsm_hall_offset_f28069m_B.one_by_two_g +
            mcb_pmsm_hall_offset_f28069m_B.add_c;

          /* Sum: '<S115>/Add1' */
          mcb_pmsm_hall_offset_f28069m_B.Add1_j =
            mcb_pmsm_hall_offset_f28069m_B.add_b +
            mcb_pmsm_hall_offset_f28069m_B.one_by_two_g;

          /* Sum: '<S115>/Add3' */
          mcb_pmsm_hall_offset_f28069m_B.Add3 =
            mcb_pmsm_hall_offset_f28069m_B.algDD_o1 +
            mcb_pmsm_hall_offset_f28069m_B.one_by_two_g;

          /* Gain: '<S115>/Gain' */
          mcb_pmsm_hall_offset_f28069m_B.Gain[0] = 1.15470052F *
            mcb_pmsm_hall_offset_f28069m_B.Add3;
          mcb_pmsm_hall_offset_f28069m_B.Gain[1] = 1.15470052F *
            mcb_pmsm_hall_offset_f28069m_B.Add1_j;
          mcb_pmsm_hall_offset_f28069m_B.Gain[2] = 1.15470052F *
            mcb_pmsm_hall_offset_f28069m_B.Add2;

          /* Sum: '<S76>/Sum' incorporates:
           *  Constant: '<S76>/Constant'
           */
          Bias = mcb_pmsm_hall_offset_f28069m_B.Gain[0] + 1.0F;
          mcb_pmsm_hall_offset_f28069m_B.Sum_j[0] = Bias;

          /* Gain: '<S76>/Gain' */
          Bias *= 0.5F;
          mcb_pmsm_hall_offset_f28069m_B.Gain_i[0] = Bias;

          /* Gain: '<S76>/Scale_to_PWM_Counter_PRD' */
          Data = (uint16_T)(2250.0F * Bias);
          mcb_pmsm_hall_offset_f28069m_B.Scale_to_PWM_Counter_PRD[0] = Data;

          /* Switch: '<S76>/Switch4' */
          mcb_pmsm_hall_offset_f28069m_B.Switch4[0] = Data;

          /* Sum: '<S76>/Sum' incorporates:
           *  Constant: '<S76>/Constant'
           */
          Bias = mcb_pmsm_hall_offset_f28069m_B.Gain[1] + 1.0F;
          mcb_pmsm_hall_offset_f28069m_B.Sum_j[1] = Bias;

          /* Gain: '<S76>/Gain' */
          Bias *= 0.5F;
          mcb_pmsm_hall_offset_f28069m_B.Gain_i[1] = Bias;

          /* Gain: '<S76>/Scale_to_PWM_Counter_PRD' */
          Data = (uint16_T)(2250.0F * Bias);
          mcb_pmsm_hall_offset_f28069m_B.Scale_to_PWM_Counter_PRD[1] = Data;

          /* Switch: '<S76>/Switch4' */
          mcb_pmsm_hall_offset_f28069m_B.Switch4[1] = Data;

          /* Sum: '<S76>/Sum' incorporates:
           *  Constant: '<S76>/Constant'
           */
          Bias = mcb_pmsm_hall_offset_f28069m_B.Gain[2] + 1.0F;
          mcb_pmsm_hall_offset_f28069m_B.Sum_j[2] = Bias;

          /* Gain: '<S76>/Gain' */
          Bias *= 0.5F;
          mcb_pmsm_hall_offset_f28069m_B.Gain_i[2] = Bias;

          /* Gain: '<S76>/Scale_to_PWM_Counter_PRD' */
          Data = (uint16_T)(2250.0F * Bias);
          mcb_pmsm_hall_offset_f28069m_B.Scale_to_PWM_Counter_PRD[2] = Data;

          /* Switch: '<S76>/Switch4' */
          mcb_pmsm_hall_offset_f28069m_B.Switch4[2] = Data;
        } else {
          /* Switch: '<S76>/Switch4' incorporates:
           *  Constant: '<S76>/stop'
           */
          mcb_pmsm_hall_offset_f28069m_B.Switch4[0] = 0U;
          mcb_pmsm_hall_offset_f28069m_B.Switch4[1] = 0U;
          mcb_pmsm_hall_offset_f28069m_B.Switch4[2] = 0U;
        }

        /* End of Switch: '<S76>/Switch4' */

        /* S-Function (c2802xpwm): '<S77>/ePWM4' */
        uint16_T tbprdValue1Outputs = EPwm1Regs.TBPRD;

        /*-- Update CMPA value for ePWM1 --*/
        {
          EPwm1Regs.CMPA.half.CMPA = (uint16_T)
            (mcb_pmsm_hall_offset_f28069m_B.Switch4[0]);
        }

        /* S-Function (c2802xpwm): '<S77>/ePWM5' */
        uint16_T tbprdValue2Outputs = EPwm2Regs.TBPRD;

        /*-- Update CMPA value for ePWM2 --*/
        {
          EPwm2Regs.CMPA.half.CMPA = (uint16_T)
            (mcb_pmsm_hall_offset_f28069m_B.Switch4[1]);
        }

        /* S-Function (c2802xpwm): '<S77>/ePWM6' */
        uint16_T tbprdValue3Outputs = EPwm3Regs.TBPRD;

        /*-- Update CMPA value for ePWM3 --*/
        {
          EPwm3Regs.CMPA.half.CMPA = (uint16_T)
            (mcb_pmsm_hall_offset_f28069m_B.Switch4[2]);
        }

        /* S-Function (c280xgpio_do): '<S77>/Inverter Enable' */
        {
          if (mcb_pmsm_hall_offset_f28069m_B.Compare_i) {
            GpioDataRegs.GPBSET.bit.GPIO50 = 1U;
          } else {
            GpioDataRegs.GPBCLEAR.bit.GPIO50 = 1U;
          }
        }

        /* S-Function (c2802xadc): '<S6>/IA//IB Measurement' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          mcb_pmsm_hall_offset_f28069m_B.IAIBMeasurement[0] =
            (AdcResult.ADCRESULT0);
          mcb_pmsm_hall_offset_f28069m_B.IAIBMeasurement[1] =
            (AdcResult.ADCRESULT1);
        }

        /* Update for Delay: '<S131>/Delay One Step1' */
        mcb_pmsm_hall_offset_f280_DWork.DelayOneStep1_DSTATE =
          mcb_pmsm_hall_offset_f28069m_B.Compare;

        /* Update for Delay: '<S131>/Delay One Step' */
        if (mcb_pmsm_hall_offset_f28069m_B.OR) {
          mcb_pmsm_hall_offset_f280_DWork.DelayOneStep_DSTATE =
            mcb_pmsm_hall_offset_f28069m_B.Sum_a;
        }

        /* End of Update for Delay: '<S131>/Delay One Step' */

        /* Update for UnitDelay: '<S120>/Output' */
        mcb_pmsm_hall_offset_f280_DWork.Output_DSTATE =
          mcb_pmsm_hall_offset_f28069m_B.FixPtSwitch;
      }

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' */
    }
  }

  /* Clear occurred EOC event event */
  AdcRegs.ADCINTFLGCLR.bit.ADCINT1= 1;

  /* Clear occurred Overflow event event */
  AdcRegs.ADCINTOVFCLR.bit.ADCINT1= 1;
  DINT;
  /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;
                                   /*restore PIEIER register that was modified*/
  PieCtrlRegs.PIEIER9.all = PIEIER9_stack_save;
                                   /*restore PIEIER register that was modified*/
  HWI_TIC28x_AcknowledgeIrq(32);
}

/* Hardware Interrupt Block: '<S16>/Hardware Interrupt' */
interrupt void ECAP1_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S16>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Hall Sensor A' */

      /* S-Function (memorycopy): '<S2>/Memory Copy1' */
      {
        uint32_T *memindsrc4 = (uint32_T *) (&GpioDataRegs.GPADAT.all);
        uint32_T *meminddst4 = (uint32_T *)
          (&mcb_pmsm_hall_offset_f28069m_B.MemoryCopy1_h);
        *(uint32_T *) (meminddst4) = *(uint32_T *) (memindsrc4);
      }

      /* S-Function (sfix_bitop): '<S2>/Bitwise AND' */
      mcb_pmsm_hall_offset_f28069m_B.BitwiseAND_a3 =
        mcb_pmsm_hall_offset_f28069m_B.MemoryCopy1_h & 117440512UL;

      /* ArithShift: '<S2>/Shift Arithmetic' incorporates:
       *  S-Function (sfix_bitop): '<S2>/Bitwise AND'
       */
      mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic_h =
        mcb_pmsm_hall_offset_f28069m_B.BitwiseAND_a3 >> 24U;

      /* DataTypeConversion: '<S24>/Data Type Conversion1' */
      mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_ph = (uint16_T)
        mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic_h;

      /* DataStoreRead: '<S2>/Data Store Read' */
      mcb_pmsm_hall_offset_f28069m_B.DataStoreRead_ex =
        mcb_pmsm_hall_offset_f280_DWork.GlobalHallState;

      /* DataTypeConversion: '<S24>/Data Type Conversion2' */
      mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion2_e = (uint16_T)
        mcb_pmsm_hall_offset_f28069m_B.DataStoreRead_ex;

      /* DataStoreRead: '<S2>/Data Store Read1' */
      mcb_pmsm_hall_offset_f28069m_B.DataStoreRead1_k =
        mcb_pmsm_hall_offset_f280_DWork.GlobalDirection;

      /* SwitchCase: '<S24>/Detects if the halls reading is valid' */
      switch ((int32_T)mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_ph) {
       case 5L:
       case 4L:
       case 6L:
       case 2L:
       case 3L:
       case 1L:
        /* Outputs for IfAction SubSystem: '<S27>/Valid Halls' incorporates:
         *  ActionPort: '<S29>/Action Port'
         */
        mcb_pmsm_hall_offset_ValidHalls
          (mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_ph,
           mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion2_e,
           mcb_pmsm_hall_offset_f28069m_B.DataStoreRead1_k,
           &mcb_pmsm_hall_offset_f28069m_B.Merge3_p,
           &mcb_pmsm_hall_offset_f28069m_B.Merge1_m3,
           &mcb_pmsm_hall_offset_f28069m_B.Merge_j,
           &mcb_pmsm_hall_offset_f28069m_B.ValidHalls);

        /* End of Outputs for SubSystem: '<S27>/Valid Halls' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S27>/Bad hall (glitch or wrong connection)' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        Badhallglitchorwrongconnection
          (mcb_pmsm_hall_offset_f28069m_B.DataStoreRead1_k,
           &mcb_pmsm_hall_offset_f28069m_B.Merge_j,
           &mcb_pmsm_hall_offset_f28069m_B.Merge1_m3,
           &mcb_pmsm_hall_offset_f28069m_B.Merge3_p);

        /* End of Outputs for SubSystem: '<S27>/Bad hall (glitch or wrong connection)' */
        break;
      }

      /* End of SwitchCase: '<S24>/Detects if the halls reading is valid' */

      /* DataTypeConversion: '<S27>/Data Type Conversion' */
      mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion_b =
        mcb_pmsm_hall_offset_f28069m_B.Merge3_p;

      /* DataStoreWrite: '<S2>/Data Store Write' */
      mcb_pmsm_hall_offset_f280_DWork.GlobalSpeedValidity =
        mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion_b;

      /* DataStoreWrite: '<S2>/Data Store Write1' */
      mcb_pmsm_hall_offset_f280_DWork.GlobalDirection =
        mcb_pmsm_hall_offset_f28069m_B.Merge1_m3;

      /* DataStoreWrite: '<S2>/Data Store Write2' incorporates:
       *  Constant: '<S24>/Constant'
       */
      mcb_pmsm_hall_offset_f280_DWork.HallStateChangeFlag = 1U;

      /* S-Function (c280xcap): '<S2>/eCAP' */
      mcb_pmsm_hall_offset_f28069m_B.eCAP_k[0] = ECap1Regs.CAP1;
      mcb_pmsm_hall_offset_f28069m_B.eCAP_k[1] = ECap1Regs.CAP2;

      /* If: '<S23>/If' */
      if ((mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic_h == 5UL) ||
          (mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic_h == 3UL)) {
        /* Outputs for IfAction SubSystem: '<S23>/Output 1' incorporates:
         *  ActionPort: '<S26>/Action Port'
         */
        mcb_pmsm_hall_offset_f2_Output1(&mcb_pmsm_hall_offset_f28069m_B.Merge_je);

        /* End of Outputs for SubSystem: '<S23>/Output 1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S23>/Output 0' incorporates:
         *  ActionPort: '<S25>/Action Port'
         */
        mcb_pmsm_hall_offset_f2_Output0(&mcb_pmsm_hall_offset_f28069m_B.Merge_je);

        /* End of Outputs for SubSystem: '<S23>/Output 0' */
      }

      /* End of If: '<S23>/If' */

      /* Switch: '<S2>/Switch' */
      if (mcb_pmsm_hall_offset_f28069m_B.Merge_je) {
        /* Switch: '<S2>/Switch' */
        mcb_pmsm_hall_offset_f28069m_B.Switch_a =
          mcb_pmsm_hall_offset_f28069m_B.eCAP_k[0];
      } else {
        /* Switch: '<S2>/Switch' */
        mcb_pmsm_hall_offset_f28069m_B.Switch_a =
          mcb_pmsm_hall_offset_f28069m_B.eCAP_k[1];
      }

      /* End of Switch: '<S2>/Switch' */

      /* DataStoreWrite: '<S2>/Data Store Write3' */
      mcb_pmsm_hall_offset_f280_DWork.GlobalSpeedCount =
        mcb_pmsm_hall_offset_f28069m_B.Switch_a;

      /* DataStoreWrite: '<S2>/Data Store Write4' */
      mcb_pmsm_hall_offset_f280_DWork.GlobalHallState =
        mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic_h;

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S16>/Hardware Interrupt' */
    }
  }

  /* Clear occurred CEVT1 event */
  ECap1Regs.ECCLR.bit.CEVT1= 1;

  /* Clear occurred CEVT2 event */
  ECap1Regs.ECCLR.bit.CEVT2= 1;

  /* Clear occurred CEVT3 event */
  ECap1Regs.ECCLR.bit.CEVT3= 1;

  /* Clear occurred CEVT4 event */
  ECap1Regs.ECCLR.bit.CEVT4= 1;

  /* Clear occurred CTROVF event */
  ECap1Regs.ECCLR.bit.CTROVF= 1;

  /* Clear occurred CTR_PRD event */
  ECap1Regs.ECCLR.bit.CTR_EQ_PRD= 1;

  /* Clear occurred CTR_CMP event */
  ECap1Regs.ECCLR.bit.CTR_EQ_CMP= 1;
  ECap1Regs.ECCLR.bit.INT= 1;
  HWI_TIC28x_AcknowledgeIrq(56);
}

/* Hardware Interrupt Block: '<S18>/Hardware Interrupt' */
interrupt void ECAP2_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S18>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Hall Sensor B' */

      /* S-Function (memorycopy): '<S3>/Memory Copy1' */
      {
        uint32_T *memindsrc5 = (uint32_T *) (&GpioDataRegs.GPADAT.all);
        uint32_T *meminddst5 = (uint32_T *)
          (&mcb_pmsm_hall_offset_f28069m_B.MemoryCopy1_i);
        *(uint32_T *) (meminddst5) = *(uint32_T *) (memindsrc5);
      }

      /* S-Function (sfix_bitop): '<S3>/Bitwise AND' */
      mcb_pmsm_hall_offset_f28069m_B.BitwiseAND_a =
        mcb_pmsm_hall_offset_f28069m_B.MemoryCopy1_i & 117440512UL;

      /* ArithShift: '<S3>/Shift Arithmetic' incorporates:
       *  S-Function (sfix_bitop): '<S3>/Bitwise AND'
       */
      mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic_o =
        mcb_pmsm_hall_offset_f28069m_B.BitwiseAND_a >> 24U;

      /* DataTypeConversion: '<S41>/Data Type Conversion1' */
      mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_j = (uint16_T)
        mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic_o;

      /* DataStoreRead: '<S3>/Data Store Read' */
      mcb_pmsm_hall_offset_f28069m_B.DataStoreRead_e =
        mcb_pmsm_hall_offset_f280_DWork.GlobalHallState;

      /* DataTypeConversion: '<S41>/Data Type Conversion2' */
      mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion2_n = (uint16_T)
        mcb_pmsm_hall_offset_f28069m_B.DataStoreRead_e;

      /* DataStoreRead: '<S3>/Data Store Read1' */
      mcb_pmsm_hall_offset_f28069m_B.DataStoreRead1_c =
        mcb_pmsm_hall_offset_f280_DWork.GlobalDirection;

      /* SwitchCase: '<S41>/Detects if the halls reading is valid' */
      switch ((int32_T)mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_j) {
       case 5L:
       case 4L:
       case 6L:
       case 2L:
       case 3L:
       case 1L:
        /* Outputs for IfAction SubSystem: '<S44>/Valid Halls' incorporates:
         *  ActionPort: '<S46>/Action Port'
         */
        mcb_pmsm_hall_offset_ValidHalls
          (mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_j,
           mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion2_n,
           mcb_pmsm_hall_offset_f28069m_B.DataStoreRead1_c,
           &mcb_pmsm_hall_offset_f28069m_B.Merge3_n,
           &mcb_pmsm_hall_offset_f28069m_B.Merge1_c,
           &mcb_pmsm_hall_offset_f28069m_B.Merge_d,
           &mcb_pmsm_hall_offset_f28069m_B.ValidHalls_n);

        /* End of Outputs for SubSystem: '<S44>/Valid Halls' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S44>/Bad hall (glitch or wrong connection)' incorporates:
         *  ActionPort: '<S45>/Action Port'
         */
        Badhallglitchorwrongconnection
          (mcb_pmsm_hall_offset_f28069m_B.DataStoreRead1_c,
           &mcb_pmsm_hall_offset_f28069m_B.Merge_d,
           &mcb_pmsm_hall_offset_f28069m_B.Merge1_c,
           &mcb_pmsm_hall_offset_f28069m_B.Merge3_n);

        /* End of Outputs for SubSystem: '<S44>/Bad hall (glitch or wrong connection)' */
        break;
      }

      /* End of SwitchCase: '<S41>/Detects if the halls reading is valid' */

      /* DataTypeConversion: '<S44>/Data Type Conversion' */
      mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion_d =
        mcb_pmsm_hall_offset_f28069m_B.Merge3_n;

      /* DataStoreWrite: '<S3>/Data Store Write' */
      mcb_pmsm_hall_offset_f280_DWork.GlobalSpeedValidity =
        mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion_d;

      /* DataStoreWrite: '<S3>/Data Store Write1' */
      mcb_pmsm_hall_offset_f280_DWork.GlobalDirection =
        mcb_pmsm_hall_offset_f28069m_B.Merge1_c;

      /* DataStoreWrite: '<S3>/Data Store Write2' incorporates:
       *  Constant: '<S41>/Constant'
       */
      mcb_pmsm_hall_offset_f280_DWork.HallStateChangeFlag = 1U;

      /* S-Function (c280xcap): '<S3>/eCAP' */
      mcb_pmsm_hall_offset_f28069m_B.eCAP_i[0] = ECap2Regs.CAP1;
      mcb_pmsm_hall_offset_f28069m_B.eCAP_i[1] = ECap2Regs.CAP2;

      /* If: '<S40>/If' */
      if ((mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic_o == 3UL) ||
          (mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic_o == 6UL)) {
        /* Outputs for IfAction SubSystem: '<S40>/Output 1' incorporates:
         *  ActionPort: '<S43>/Action Port'
         */
        mcb_pmsm_hall_offset_f2_Output1(&mcb_pmsm_hall_offset_f28069m_B.Merge_er);

        /* End of Outputs for SubSystem: '<S40>/Output 1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S40>/Output 0' incorporates:
         *  ActionPort: '<S42>/Action Port'
         */
        mcb_pmsm_hall_offset_f2_Output0(&mcb_pmsm_hall_offset_f28069m_B.Merge_er);

        /* End of Outputs for SubSystem: '<S40>/Output 0' */
      }

      /* End of If: '<S40>/If' */

      /* Switch: '<S3>/Switch' */
      if (mcb_pmsm_hall_offset_f28069m_B.Merge_er) {
        /* Switch: '<S3>/Switch' */
        mcb_pmsm_hall_offset_f28069m_B.Switch_f =
          mcb_pmsm_hall_offset_f28069m_B.eCAP_i[0];
      } else {
        /* Switch: '<S3>/Switch' */
        mcb_pmsm_hall_offset_f28069m_B.Switch_f =
          mcb_pmsm_hall_offset_f28069m_B.eCAP_i[1];
      }

      /* End of Switch: '<S3>/Switch' */

      /* DataStoreWrite: '<S3>/Data Store Write3' */
      mcb_pmsm_hall_offset_f280_DWork.GlobalSpeedCount =
        mcb_pmsm_hall_offset_f28069m_B.Switch_f;

      /* DataStoreWrite: '<S3>/Data Store Write4' */
      mcb_pmsm_hall_offset_f280_DWork.GlobalHallState =
        mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic_o;

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S18>/Hardware Interrupt' */
    }
  }

  /* Clear occurred CEVT1 event */
  ECap2Regs.ECCLR.bit.CEVT1= 1;

  /* Clear occurred CEVT2 event */
  ECap2Regs.ECCLR.bit.CEVT2= 1;

  /* Clear occurred CEVT3 event */
  ECap2Regs.ECCLR.bit.CEVT3= 1;

  /* Clear occurred CEVT4 event */
  ECap2Regs.ECCLR.bit.CEVT4= 1;

  /* Clear occurred CTROVF event */
  ECap2Regs.ECCLR.bit.CTROVF= 1;

  /* Clear occurred CTR_PRD event */
  ECap2Regs.ECCLR.bit.CTR_EQ_PRD= 1;

  /* Clear occurred CTR_CMP event */
  ECap2Regs.ECCLR.bit.CTR_EQ_CMP= 1;
  ECap2Regs.ECCLR.bit.INT= 1;
  HWI_TIC28x_AcknowledgeIrq(57);
}

/* Hardware Interrupt Block: '<S20>/Hardware Interrupt' */
interrupt void ECAP3_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S20>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Hall Sensor C' */

      /* S-Function (memorycopy): '<S4>/Memory Copy1' */
      {
        uint32_T *memindsrc6 = (uint32_T *) (&GpioDataRegs.GPADAT.all);
        uint32_T *meminddst6 = (uint32_T *)
          (&mcb_pmsm_hall_offset_f28069m_B.MemoryCopy1);
        *(uint32_T *) (meminddst6) = *(uint32_T *) (memindsrc6);
      }

      /* S-Function (sfix_bitop): '<S4>/Bitwise AND' */
      mcb_pmsm_hall_offset_f28069m_B.BitwiseAND =
        mcb_pmsm_hall_offset_f28069m_B.MemoryCopy1 & 117440512UL;

      /* ArithShift: '<S4>/Shift Arithmetic' incorporates:
       *  S-Function (sfix_bitop): '<S4>/Bitwise AND'
       */
      mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic =
        mcb_pmsm_hall_offset_f28069m_B.BitwiseAND >> 24U;

      /* DataTypeConversion: '<S58>/Data Type Conversion1' */
      mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_db = (uint16_T)
        mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic;

      /* DataStoreRead: '<S4>/Data Store Read' */
      mcb_pmsm_hall_offset_f28069m_B.DataStoreRead =
        mcb_pmsm_hall_offset_f280_DWork.GlobalHallState;

      /* DataTypeConversion: '<S58>/Data Type Conversion2' */
      mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion2 = (uint16_T)
        mcb_pmsm_hall_offset_f28069m_B.DataStoreRead;

      /* DataStoreRead: '<S4>/Data Store Read1' */
      mcb_pmsm_hall_offset_f28069m_B.DataStoreRead1 =
        mcb_pmsm_hall_offset_f280_DWork.GlobalDirection;

      /* SwitchCase: '<S58>/Detects if the halls reading is valid' */
      switch ((int32_T)mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_db) {
       case 5L:
       case 4L:
       case 6L:
       case 2L:
       case 3L:
       case 1L:
        /* Outputs for IfAction SubSystem: '<S61>/Valid Halls' incorporates:
         *  ActionPort: '<S63>/Action Port'
         */
        mcb_pmsm_hall_offset_ValidHalls
          (mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1_db,
           mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion2,
           mcb_pmsm_hall_offset_f28069m_B.DataStoreRead1,
           &mcb_pmsm_hall_offset_f28069m_B.Merge3,
           &mcb_pmsm_hall_offset_f28069m_B.Merge1_e,
           &mcb_pmsm_hall_offset_f28069m_B.Merge_e,
           &mcb_pmsm_hall_offset_f28069m_B.ValidHalls_j);

        /* End of Outputs for SubSystem: '<S61>/Valid Halls' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S61>/Bad hall (glitch or wrong connection)' incorporates:
         *  ActionPort: '<S62>/Action Port'
         */
        Badhallglitchorwrongconnection
          (mcb_pmsm_hall_offset_f28069m_B.DataStoreRead1,
           &mcb_pmsm_hall_offset_f28069m_B.Merge_e,
           &mcb_pmsm_hall_offset_f28069m_B.Merge1_e,
           &mcb_pmsm_hall_offset_f28069m_B.Merge3);

        /* End of Outputs for SubSystem: '<S61>/Bad hall (glitch or wrong connection)' */
        break;
      }

      /* End of SwitchCase: '<S58>/Detects if the halls reading is valid' */

      /* DataTypeConversion: '<S61>/Data Type Conversion' */
      mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion =
        mcb_pmsm_hall_offset_f28069m_B.Merge3;

      /* DataStoreWrite: '<S4>/Data Store Write' */
      mcb_pmsm_hall_offset_f280_DWork.GlobalSpeedValidity =
        mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion;

      /* DataStoreWrite: '<S4>/Data Store Write1' */
      mcb_pmsm_hall_offset_f280_DWork.GlobalDirection =
        mcb_pmsm_hall_offset_f28069m_B.Merge1_e;

      /* DataStoreWrite: '<S4>/Data Store Write2' incorporates:
       *  Constant: '<S58>/Constant'
       */
      mcb_pmsm_hall_offset_f280_DWork.HallStateChangeFlag = 1U;

      /* S-Function (c280xcap): '<S4>/eCAP' */
      mcb_pmsm_hall_offset_f28069m_B.eCAP[0] = ECap3Regs.CAP1;
      mcb_pmsm_hall_offset_f28069m_B.eCAP[1] = ECap3Regs.CAP2;

      /* If: '<S57>/If' */
      if ((mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic == 5UL) ||
          (mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic == 6UL)) {
        /* Outputs for IfAction SubSystem: '<S57>/Output 1' incorporates:
         *  ActionPort: '<S60>/Action Port'
         */
        mcb_pmsm_hall_offset_f2_Output1(&mcb_pmsm_hall_offset_f28069m_B.Merge_k);

        /* End of Outputs for SubSystem: '<S57>/Output 1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S57>/Output 0' incorporates:
         *  ActionPort: '<S59>/Action Port'
         */
        mcb_pmsm_hall_offset_f2_Output0(&mcb_pmsm_hall_offset_f28069m_B.Merge_k);

        /* End of Outputs for SubSystem: '<S57>/Output 0' */
      }

      /* End of If: '<S57>/If' */

      /* Switch: '<S4>/Switch' */
      if (mcb_pmsm_hall_offset_f28069m_B.Merge_k) {
        /* Switch: '<S4>/Switch' */
        mcb_pmsm_hall_offset_f28069m_B.Switch =
          mcb_pmsm_hall_offset_f28069m_B.eCAP[0];
      } else {
        /* Switch: '<S4>/Switch' */
        mcb_pmsm_hall_offset_f28069m_B.Switch =
          mcb_pmsm_hall_offset_f28069m_B.eCAP[1];
      }

      /* End of Switch: '<S4>/Switch' */

      /* DataStoreWrite: '<S4>/Data Store Write3' */
      mcb_pmsm_hall_offset_f280_DWork.GlobalSpeedCount =
        mcb_pmsm_hall_offset_f28069m_B.Switch;

      /* DataStoreWrite: '<S4>/Data Store Write4' */
      mcb_pmsm_hall_offset_f280_DWork.GlobalHallState =
        mcb_pmsm_hall_offset_f28069m_B.ShiftArithmetic;

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S20>/Hardware Interrupt' */
    }
  }

  /* Clear occurred CEVT1 event */
  ECap3Regs.ECCLR.bit.CEVT1= 1;

  /* Clear occurred CEVT2 event */
  ECap3Regs.ECCLR.bit.CEVT2= 1;

  /* Clear occurred CEVT3 event */
  ECap3Regs.ECCLR.bit.CEVT3= 1;

  /* Clear occurred CEVT4 event */
  ECap3Regs.ECCLR.bit.CEVT4= 1;

  /* Clear occurred CTROVF event */
  ECap3Regs.ECCLR.bit.CTROVF= 1;

  /* Clear occurred CTR_PRD event */
  ECap3Regs.ECCLR.bit.CTR_EQ_PRD= 1;

  /* Clear occurred CTR_CMP event */
  ECap3Regs.ECCLR.bit.CTR_EQ_CMP= 1;
  ECap3Regs.ECCLR.bit.INT= 1;
  HWI_TIC28x_AcknowledgeIrq(58);
}

/* Hardware Interrupt Block: '<S22>/Hardware Interrupt' */
interrupt void SCIRXINTA(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Serial Receive' */

      /* S-Function (c28xsci_rx): '<S7>/SCI Receive' */
      {
        int16_T i;
        int16_T errFlg = NOERROR;
        uint16_T isHeadReceived = 1U;

        //get data as uint16 in recBuff
        uint16_T recbuff[1];
        for (i = 0; i < 1; i++) {
          recbuff[i] = 0U;
        }

        errFlg = NOERROR;

        /* Receiving data: For uint32 and uint16, rcvBuff will contain uint16 data */
        if (isHeadReceived) {
          errFlg = scia_rcv(recbuff, 2, 2);
          if ((errFlg != NOERROR) && (errFlg != PARTIALDATA)) {
            mcb_pmsm_hall_offset_f28069m_B.SCIReceive = 0U;
          }

          if ((errFlg == NOERROR) || (errFlg == PARTIALDATA)) {
            memcpy( &mcb_pmsm_hall_offset_f28069m_B.SCIReceive, recbuff,1);
          }
        }
      }

      /* DataTypeConversion: '<S165>/Data Type Conversion1' */
      mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1 =
        mcb_pmsm_hall_offset_f28069m_B.SCIReceive;

      /* Switch: '<S7>/Switch' */
      mcb_pmsm_hall_offset_f28069m_B.Switch_aj =
        (mcb_pmsm_hall_offset_f28069m_B.DataTypeConversion1 > 0.0F);

      /* DataStoreWrite: '<S7>/Data Store Write' */
      mcb_pmsm_hall_offset_f280_DWork.Enable =
        mcb_pmsm_hall_offset_f28069m_B.Switch_aj;

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */
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
  HWI_TIC28x_AcknowledgeIrq(96);
}

void mcb_pmsm_hall_offset_f28069m_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(32);
  HWI_TIC28x_DisableIRQ(56);
  HWI_TIC28x_DisableIRQ(57);
  HWI_TIC28x_DisableIRQ(58);
  HWI_TIC28x_DisableIRQ(96);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
