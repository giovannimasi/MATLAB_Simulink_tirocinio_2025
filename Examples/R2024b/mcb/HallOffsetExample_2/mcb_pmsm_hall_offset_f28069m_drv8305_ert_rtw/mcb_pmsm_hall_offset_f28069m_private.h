/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_hall_offset_f28069m_private.h
 *
 * Code generated for Simulink model 'mcb_pmsm_hall_offset_f28069m'.
 *
 * Model version                  : 9.10
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Mar 19 15:38:22 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_pmsm_hall_offset_f28069m_private_h_
#define mcb_pmsm_hall_offset_f28069m_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "mcb_pmsm_hall_offset_f28069m.h"
#include "mcb_pmsm_hall_offset_f28069m_types.h"
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

void InitAdc (void);
void config_ADC_SOC0_SOC1 (void);
extern uint16_T MW_adcInitFlag;
extern uint32_T uMultiWord2uLongSat(const uint32_T u1[], int16_T n1);
extern void uMultiWord2uMultiWordSat(const uint32_T u1[], int16_T n1, uint32_T
  y[], int16_T n);
extern void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int16_T n);
extern void uLong2MultiWord(uint32_T u, uint32_T y[], int16_T n);
extern void mcb_pmsm_hall_offs_HallValueof1(real32_T *rty_position);
extern void mcb_pmsm_hall_offs_HallValueof2(real32_T *rty_position);
extern void mcb_pmsm_hall_offs_HallValueof3(real32_T *rty_position);
extern void mcb_pmsm_hall_offs_HallValueof4(real32_T *rty_position);
extern void mcb_pmsm_hall_offs_HallValueof5(real32_T *rty_position);
extern void mcb_pmsm_hall_offs_HallValueof7(real32_T *rty_position);
extern void mcb_pmsm_hall_offset_f2_Output1(boolean_T *rty_Out1);
extern void mcb_pmsm_hall_offset_f2_Output0(boolean_T *rty_Out1);
extern void mcb_pmsm_hall_o_ValidHalls_Init(rtB_ValidHalls_mcb_pmsm_hall_of
  *localB);
extern void mcb_pmsm_hall_offset_ValidHalls(uint16_T rtu_hallReading, uint16_T
  rtu_previousState, int16_T rtu_previous_direction, boolean_T
  *rty_directional_speed_valid_fla, int16_T *rty_direction, uint16_T
  *rty_inValidHall, rtB_ValidHalls_mcb_pmsm_hall_of *localB);
extern void Badhallglitchorwrongconnection(int16_T rtu_previous_direction,
  uint16_T *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla);
extern void mcb_pmsm_hall_AtomicHallReading(void);

#endif                             /* mcb_pmsm_hall_offset_f28069m_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
