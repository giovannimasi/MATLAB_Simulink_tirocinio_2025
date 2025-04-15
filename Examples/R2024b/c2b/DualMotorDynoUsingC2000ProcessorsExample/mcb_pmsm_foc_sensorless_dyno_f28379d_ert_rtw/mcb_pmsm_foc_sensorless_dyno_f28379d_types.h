/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_sensorless_dyno_f28379d_types.h
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

#ifndef mcb_pmsm_foc_sensorless_dyno_f28379d_types_h_
#define mcb_pmsm_foc_sensorless_dyno_f28379d_types_h_
#include "rtwtypes.h"
#include "MW_c2000SPI.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_zFfNK2ERXzHeakTWhyupM_
#define DEFINED_TYPEDEF_FOR_struct_zFfNK2ERXzHeakTWhyupM_

typedef struct {
  real32_T mtr2_VI_debug[6];
  real32_T mtr2_Te_PU;
  real32_T mtr2_Pm_PU;
  real32_T mtr2_Speed_PU;
  real32_T mtr2_Iab_meas_PU[2];
  real32_T mtr2_Pos_PU;
} struct_zFfNK2ERXzHeakTWhyupM;

#endif

/* Custom Type definition for MATLABSystem: '<S466>/SPI Master Transfer' */
#include "MW_c2000SPI.h"
#ifndef struct_tag_X3nhL3sVVdEpin6phQ7ajF
#define struct_tag_X3nhL3sVVdEpin6phQ7ajF

struct tag_X3nhL3sVVdEpin6phQ7ajF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_SPI_HANDLE;
};

#endif                                 /* struct_tag_X3nhL3sVVdEpin6phQ7ajF */

#ifndef typedef_codertarget_tic2000_blocks_SPIM
#define typedef_codertarget_tic2000_blocks_SPIM

typedef struct tag_X3nhL3sVVdEpin6phQ7ajF codertarget_tic2000_blocks_SPIM;

#endif                             /* typedef_codertarget_tic2000_blocks_SPIM */

/* Forward declaration for rtModel */
typedef struct tag_RTM_mcb_pmsm_foc_sensorless RT_MODEL_mcb_pmsm_foc_sensorles;

#endif                       /* mcb_pmsm_foc_sensorless_dyno_f28379d_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
