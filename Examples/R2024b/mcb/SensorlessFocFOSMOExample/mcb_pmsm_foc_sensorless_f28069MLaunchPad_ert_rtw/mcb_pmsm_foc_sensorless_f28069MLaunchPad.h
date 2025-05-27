/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_sensorless_f28069MLaunchPad.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_sensorless_f28069MLaunchPad'.
 *
 * Model version                  : 9.20
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue May 27 12:41:05 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_pmsm_foc_sensorless_f28069MLaunchPad_h_
#define mcb_pmsm_foc_sensorless_f28069MLaunchPad_h_
#ifndef mcb_pmsm_foc_sensorless_f28069MLaunchPad_COMMON_INCLUDES_
#define mcb_pmsm_foc_sensorless_f28069MLaunchPad_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Gpio.h"
#include "DSP28xx_SciUtil.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif           /* mcb_pmsm_foc_sensorless_f28069MLaunchPad_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "mcb_pmsm_foc_sensorless_f28069MLaunchPad_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "zero_crossing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define mcb_pmsm_foc_sensorless_f28069MLaunchPad_M (mcb_pmsm_foc_sensorless_f280_M)

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals for system '<S23>/Two phase CRL wrap' */
typedef struct {
  real32_T a_plus_2b;                  /* '<S24>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S24>/one_by_sqrt3' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} rtB_TwophaseCRLwrap_mcb_pmsm_fo;

/* Block signals for system '<S20>/Two inputs CRL' */
typedef struct {
  real32_T acos_a;                     /* '<S53>/acos' */
  real32_T bsin;                       /* '<S53>/bsin' */
  real32_T sum_Ds;                     /* '<S53>/sum_Ds' */
  real32_T bcos;                       /* '<S53>/bcos' */
  real32_T asin_p;                     /* '<S53>/asin' */
  real32_T sum_Qs;                     /* '<S53>/sum_Qs' */
  real32_T Switch[2];                  /* '<S54>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} rtB_TwoinputsCRL_mcb_pmsm_foc_s;

/* Block signals for system '<S57>/If Action Subsystem' */
typedef struct {
  real32_T Convert_back;               /* '<S60>/Convert_back' */
  int16_T Convert_uint16;              /* '<S60>/Convert_uint16' */
} rtB_IfActionSubsystem_mcb_pmsm_;

/* Block signals for system '<S57>/If Action Subsystem1' */
typedef struct {
  real32_T Convert_back;               /* '<S61>/Convert_back' */
  int16_T Convert_uint16;              /* '<S61>/Convert_uint16' */
} rtB_IfActionSubsystem1_mcb_pmsm;

/* Block signals for system '<S273>/Dir_Sense' */
typedef struct {
  int16_T Switch;                      /* '<S281>/Switch' */
  boolean_T LogicalOperator;           /* '<S281>/Logical Operator' */
} rtB_Dir_Sense_mcb_pmsm_foc_sens;

/* Zero-crossing (trigger) state for system '<S273>/Dir_Sense' */
typedef struct {
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S273>/Dir_Sense' */
} rtZCE_Dir_Sense_mcb_pmsm_foc_se;

/* Block signals for system '<S312>/SPI Master Transfer' */
typedef struct {
  uint16_T SPIMasterTransfer;          /* '<S312>/SPI Master Transfer' */
} rtB_SPIMasterTransfer_mcb_pmsm_;

/* Block states (default storage) for system '<S312>/SPI Master Transfer' */
typedef struct {
  codertarget_tic2000_blocks_SPIM obj; /* '<S312>/SPI Master Transfer' */
  boolean_T objisempty;                /* '<S312>/SPI Master Transfer' */
} rtDW_SPIMasterTransfer_mcb_pmsm;

/* Block signals for system '<Root>/Speed Control' */
typedef struct {
  real32_T Iq_switch_mem;              /* '<S326>/Data Store Read3' */
  real32_T RateLimiter;                /* '<S327>/Rate Limiter' */
  real32_T RateLimiter1;               /* '<S327>/Rate Limiter1' */
  real32_T Switch;                     /* '<S327>/Switch' */
  real32_T Switch1[2];                 /* '<S330>/Switch1' */
  real32_T Product;                    /* '<S387>/Product' */
  real32_T UnitDelay;                  /* '<S387>/Unit Delay' */
  real32_T Product1;                   /* '<S387>/Product1' */
  real32_T Add1;                       /* '<S387>/Add1' */
  real32_T Sum;                        /* '<S326>/Sum' */
  real32_T Product_g;                  /* '<S326>/Product' */
  real32_T Sum1;                       /* '<S326>/Sum1' */
  real32_T I_q_ref;                    /* '<S326>/MATLAB Function' */
  boolean_T DataStoreRead1;            /* '<S326>/Data Store Read1' */
  boolean_T DataStoreRead2;            /* '<S326>/Data Store Read2' */
  boolean_T AND;                       /* '<S326>/AND' */
  boolean_T LogicalOperator;           /* '<S326>/Logical Operator' */
} rtB_SpeedControl_mcb_pmsm_foc_s;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S387>/Unit Delay' */
  real32_T PrevY;                      /* '<S327>/Rate Limiter' */
  real32_T PrevY_f;                    /* '<S327>/Rate Limiter1' */
  real32_T integrator_state;           /* '<S326>/MATLAB Function' */
} rtDW_SpeedControl_mcb_pmsm_foc_;

/* Block signals for system '<S389>/RunMode.ComputeId0' */
typedef struct {
  real32_T Sum;                        /* '<S408>/Sum' */
  real32_T Switch;                     /* '<S408>/Switch' */
  boolean_T Compare;                   /* '<S409>/Compare' */
} rtB_RunModeComputeId0_mcb_pmsm_;

/* Block signals (default storage) */
typedef struct {
  real_T Product;                      /* '<S26>/Product' */
  real_T Add;                          /* '<S26>/Add' */
  real_T Product1;                     /* '<S26>/Product1' */
  real_T Add1;                         /* '<S26>/Add1' */
  uint32_T Sum[4];                     /* '<S398>/Sum' */
  uint32_T Sum_k[4];                   /* '<S55>/Sum' */
  uint32_T DataTypeConversion;         /* '<S110>/Data Type Conversion' */
  uint32_T Sum_j[4];                   /* '<S225>/Sum' */
  uint32_T PositionToCount;            /* '<S236>/PositionToCount' */
  uint32_T Delay;                      /* '<S236>/Delay' */
  uint32_T PositionToCount_i;          /* '<S279>/PositionToCount' */
  uint32_T Delay_l;                    /* '<S279>/Delay' */
  real32_T SpdCmd;                     /* '<S8>/RT6' */
  real32_T UnitDelay;                  /* '<S8>/Unit Delay' */
  real32_T RT6;                        /* '<Root>/RT6' */
  real32_T RT4;                        /* '<Root>/RT4' */
  real32_T RT2[2];                     /* '<Root>/RT2' */
  real32_T SpdRef;                     /* '<S8>/State Machine OL - CL' */
  real32_T Id0_out;                    /* '<S8>/State Machine OL - CL' */
  real32_T Id0_in;                     /* '<S8>/State Machine OL - CL' */
  real32_T RAMP_STEP_SIZE;             /* '<S8>/State Machine OL - CL' */
  real32_T DataStoreRead3;             /* '<S388>/Data Store Read3' */
  real32_T DataStoreRead1;             /* '<S388>/Data Store Read1' */
  real32_T DataStoreRead2;             /* '<S388>/Data Store Read2' */
  real32_T Merge;                      /* '<S400>/Merge' */
  real32_T indexing;                   /* '<S398>/indexing' */
  real32_T Lookup[4];                  /* '<S398>/Lookup' */
  real32_T Sum3;                       /* '<S399>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S398>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S398>/Sum2' */
  real32_T Product_b;                  /* '<S399>/Product' */
  real32_T Sum4;                       /* '<S399>/Sum4' */
  real32_T Sum5;                       /* '<S399>/Sum5' */
  real32_T Product1_a;                 /* '<S399>/Product1' */
  real32_T Sum6;                       /* '<S399>/Sum6' */
  real32_T DataStoreRead;              /* '<S388>/Data Store Read' */
  real32_T DataStoreRead4;             /* '<S388>/Data Store Read4' */
  real32_T DataTypeConversion1_a[2];   /* '<S323>/Data Type Conversion1' */
  real32_T Speed_Ref;                  /* '<S6>/Data Type Conversion1' */
  real32_T DataTypeConversion1_p[2];   /* '<S78>/Data Type Conversion1' */
  real32_T Delay5[4];                  /* '<S1>/Delay5' */
  real32_T Merge_k[2];                 /* '<S79>/Merge' */
  real32_T Spd_Pos;                    /* '<S19>/Data Store Read' */
  real32_T Gain;                       /* '<S19>/Gain' */
  real32_T Delay_g;                    /* '<S19>/Delay' */
  real32_T Add_g;                      /* '<S51>/Add' */
  real32_T DataTypeConversion1_d;      /* '<S51>/Data Type Conversion1' */
  real32_T Add1_f;                     /* '<S51>/Add1' */
  real32_T Switch;                     /* '<S19>/Switch' */
  real32_T Merge_c;                    /* '<S57>/Merge' */
  real32_T indexing_d;                 /* '<S55>/indexing' */
  real32_T Lookup_f[4];                /* '<S55>/Lookup' */
  real32_T Sum3_b;                     /* '<S56>/Sum3' */
  real32_T DataTypeConversion1_c;      /* '<S55>/Data Type Conversion1' */
  real32_T Sum2_e;                     /* '<S55>/Sum2' */
  real32_T Product_g;                  /* '<S56>/Product' */
  real32_T Sum4_h;                     /* '<S56>/Sum4' */
  real32_T Sum5_l;                     /* '<S56>/Sum5' */
  real32_T Product1_e;                 /* '<S56>/Product1' */
  real32_T Sum6_c;                     /* '<S56>/Sum6' */
  real32_T Sum_m;                      /* '<S28>/Sum' */
  real32_T Vq_computed;                /* '<S28>/Vq_computed1' */
  real32_T Product_bk;                 /* '<S28>/Product' */
  real32_T Sum1;                       /* '<S28>/Sum1' */
  real32_T Switch_j;                   /* '<S28>/Switch' */
  real32_T Sum_g;                      /* '<S27>/Sum' */
  real32_T Vd_computed1;               /* '<S27>/Vd_computed1' */
  real32_T Product_e;                  /* '<S27>/Product' */
  real32_T Sum1_a;                     /* '<S27>/Sum1' */
  real32_T Vd_OpenLoop;                /* '<S27>/Vd_OpenLoop' */
  real32_T Abs;                        /* '<S27>/Abs' */
  real32_T Switch1[2];                 /* '<S43>/Switch1' */
  real32_T Product_bh;                 /* '<S47>/Product' */
  real32_T UnitDelay_n;                /* '<S47>/Unit Delay' */
  real32_T Product1_p;                 /* '<S47>/Product1' */
  real32_T Add1_l;                     /* '<S47>/Add1' */
  real32_T Switch_d;                   /* '<S27>/Switch' */
  real32_T Switch_jv;                  /* '<S31>/Switch' */
  real32_T Product_l;                  /* '<S31>/Product' */
  real32_T Product_o;                  /* '<S32>/Product' */
  real32_T Product1_ad;                /* '<S32>/Product1' */
  real32_T Sum1_e;                     /* '<S32>/Sum1' */
  real32_T Merge_m[2];                 /* '<S25>/Merge' */
  real32_T CastToSingle1;              /* '<S26>/Cast To Single1' */
  real32_T CastToSingle;               /* '<S26>/Cast To Single' */
  real32_T DataTypeConversion_c;       /* '<S14>/Data Type Conversion' */
  real32_T Speed_fb_PU;                /* '<S1>/Input Scaling' */
  real32_T TmpSignalConversionAtDelay5Inpo[4];
  real32_T sqrt3_by_two;               /* '<S69>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S69>/one_by_two' */
  real32_T add_c;                      /* '<S69>/add_c' */
  real32_T add_b;                      /* '<S69>/add_b' */
  real32_T Min;                        /* '<S66>/Min' */
  real32_T Max;                        /* '<S66>/Max' */
  real32_T Add_i;                      /* '<S66>/Add' */
  real32_T one_by_two_d;               /* '<S66>/one_by_two' */
  real32_T Add3;                       /* '<S65>/Add3' */
  real32_T Add2;                       /* '<S65>/Add2' */
  real32_T Add1_b;                     /* '<S65>/Add1' */
  real32_T Gain_c[3];                  /* '<S65>/Gain' */
  real32_T Gain_c1[3];                 /* '<S14>/Gain' */
  real32_T PWM_Duty_Cycles[3];         /* '<S14>/Sum' */
  real32_T Delay1;                     /* '<S83>/Delay1' */
  real32_T Delay_f[2];                 /* '<S84>/Delay' */
  real32_T Gain_m;                     /* '<S89>/Gain' */
  real32_T UnaryMinus;                 /* '<S97>/Unary Minus' */
  real32_T Product1_f;                 /* '<S86>/Product1' */
  real32_T Gain1;                      /* '<S96>/Gain1' */
  real32_T Product2;                   /* '<S97>/Product2' */
  real32_T Product_k;                  /* '<S86>/Product' */
  real32_T Gain_n;                     /* '<S96>/Gain' */
  real32_T Product_i;                  /* '<S97>/Product' */
  real32_T Sum_mr;                     /* '<S97>/Sum' */
  real32_T Product1_ao;                /* '<S97>/Product1' */
  real32_T Product3;                   /* '<S97>/Product3' */
  real32_T Sum1_m;                     /* '<S97>/Sum1' */
  real32_T Product3_n;                 /* '<S86>/Product3' */
  real32_T Product1_o;                 /* '<S93>/Product1' */
  real32_T Product2_c;                 /* '<S86>/Product2' */
  real32_T Gain_g;                     /* '<S88>/Gain' */
  real32_T Product3_n0;                /* '<S93>/Product3' */
  real32_T Sum1_c;                     /* '<S93>/Sum1' */
  real32_T Product1_h;                 /* '<S92>/Product1' */
  real32_T UnaryMinus_k;               /* '<S92>/Unary Minus' */
  real32_T UnaryMinus_f;               /* '<S93>/Unary Minus' */
  real32_T Product2_a;                 /* '<S93>/Product2' */
  real32_T Product_gf;                 /* '<S93>/Product' */
  real32_T Sum_i;                      /* '<S93>/Sum' */
  real32_T Product_kc;                 /* '<S92>/Product' */
  real32_T UnaryMinus_fm;              /* '<S94>/Unary Minus' */
  real32_T Gain1_o;                    /* '<S91>/Gain1' */
  real32_T UnaryMinus1;                /* '<S91>/Unary Minus1' */
  real32_T Product2_d;                 /* '<S94>/Product2' */
  real32_T Gain_j;                     /* '<S91>/Gain' */
  real32_T UnaryMinus_i;               /* '<S91>/Unary Minus' */
  real32_T Product_f;                  /* '<S94>/Product' */
  real32_T Sum_e;                      /* '<S94>/Sum' */
  real32_T Product1_oz;                /* '<S94>/Product1' */
  real32_T Product3_nb;                /* '<S94>/Product3' */
  real32_T Sum1_k;                     /* '<S94>/Sum1' */
  real32_T UnaryMinus_j;               /* '<S95>/Unary Minus' */
  real32_T Product_n;                  /* '<S90>/Product' */
  real32_T Product3_c;                 /* '<S90>/Product3' */
  real32_T UnaryMinus1_b;              /* '<S90>/Unary Minus1' */
  real32_T Product5;                   /* '<S90>/Product5' */
  real32_T Sum1_i;                     /* '<S90>/Sum1' */
  real32_T Product2_o;                 /* '<S95>/Product2' */
  real32_T Product4;                   /* '<S90>/Product4' */
  real32_T Product1_b;                 /* '<S90>/Product1' */
  real32_T UnaryMinus_g;               /* '<S90>/Unary Minus' */
  real32_T Product2_f;                 /* '<S90>/Product2' */
  real32_T Sum_kn;                     /* '<S90>/Sum' */
  real32_T Product_gf3;                /* '<S95>/Product' */
  real32_T Sum_h;                      /* '<S95>/Sum' */
  real32_T Product1_d;                 /* '<S95>/Product1' */
  real32_T Product3_g;                 /* '<S95>/Product3' */
  real32_T Sum1_j;                     /* '<S95>/Sum1' */
  real32_T Sum_l[2];                   /* '<S88>/Sum' */
  real32_T Sum_n[2];                   /* '<S84>/Sum' */
  real32_T Gain1_c[2];                 /* '<S84>/Gain1' */
  real32_T Sum2_o[2];                  /* '<S84>/Sum2' */
  real32_T Gain2[2];                   /* '<S84>/Gain2' */
  real32_T Sum1_j4[2];                 /* '<S84>/Sum1' */
  real32_T Product_m[2];               /* '<S83>/Product' */
  real32_T Switch1_g[2];               /* '<S85>/Switch1' */
  real32_T Product_j[2];               /* '<S100>/Product' */
  real32_T UnitDelay_j[2];             /* '<S100>/Unit Delay' */
  real32_T Product1_ee[2];             /* '<S100>/Product1' */
  real32_T Add1_j[2];                  /* '<S100>/Add1' */
  real32_T Merge_k4;                   /* '<S101>/Merge' */
  real32_T Merge1;                     /* '<S101>/Merge1' */
  real32_T Merge_o[2];                 /* '<S110>/Merge' */
  real32_T Product_nv;                 /* '<S107>/Product' */
  real32_T Product1_n;                 /* '<S107>/Product1' */
  real32_T Sum_e2;                     /* '<S107>/Sum' */
  real32_T Merge_f;                    /* '<S107>/Merge' */
  real32_T Merge1_o;                   /* '<S107>/Merge1' */
  real32_T Merge_i;                    /* '<S109>/Merge' */
  real32_T Switch1_n[2];               /* '<S171>/Switch1' */
  real32_T Product_gh;                 /* '<S196>/Product' */
  real32_T UnitDelay_c;                /* '<S196>/Unit Delay' */
  real32_T Product1_l;                 /* '<S196>/Product1' */
  real32_T Add1_g;                     /* '<S196>/Add1' */
  real32_T Delay_j;                    /* '<S220>/Delay' */
  real32_T Merge_g;                    /* '<S227>/Merge' */
  real32_T indexing_i;                 /* '<S225>/indexing' */
  real32_T Lookup_m[4];                /* '<S225>/Lookup' */
  real32_T Sum5_i;                     /* '<S226>/Sum5' */
  real32_T DataTypeConversion1_d2;     /* '<S225>/Data Type Conversion1' */
  real32_T Sum2_eo;                    /* '<S225>/Sum2' */
  real32_T Product1_nl;                /* '<S226>/Product1' */
  real32_T Sum6_m;                     /* '<S226>/Sum6' */
  real32_T Product_la;                 /* '<S102>/Product' */
  real32_T Sum3_n;                     /* '<S226>/Sum3' */
  real32_T Product_a;                  /* '<S226>/Product' */
  real32_T Sum4_p;                     /* '<S226>/Sum4' */
  real32_T Product1_dd;                /* '<S102>/Product1' */
  real32_T Sum_b;                      /* '<S102>/Sum' */
  real32_T ProportionalGain;           /* '<S157>/Proportional Gain' */
  real32_T IntegralGain;               /* '<S149>/Integral Gain' */
  real32_T Integrator;                 /* '<S152>/Integrator' */
  real32_T Sum_d;                      /* '<S161>/Sum' */
  real32_T speed;                      /* '<S102>/Sum1' */
  real32_T Switch1_e[2];               /* '<S106>/Switch1' */
  real32_T Product_iq;                 /* '<S114>/Product' */
  real32_T UnitDelay_i;                /* '<S114>/Unit Delay' */
  real32_T Product1_ok;                /* '<S114>/Product1' */
  real32_T Add1_h;                     /* '<S114>/Add1' */
  real32_T Gain_l;                     /* '<S220>/Gain' */
  real32_T UnitDelay_o;                /* '<S221>/Unit Delay' */
  real32_T Add_gq;                     /* '<S223>/Add' */
  real32_T DataTypeConversion1_l;      /* '<S223>/Data Type Conversion1' */
  real32_T Add1_k;                     /* '<S223>/Add1' */
  real32_T Input;                      /* '<S224>/Input' */
  real32_T In1;                        /* '<S217>/In1' */
  real32_T Delay2;                     /* '<S207>/Delay2' */
  real32_T Delay3;                     /* '<S207>/Delay3' */
  real32_T Switch1_j[2];               /* '<S210>/Switch1' */
  real32_T Product_ex;                 /* '<S216>/Product' */
  real32_T UnitDelay_d;                /* '<S216>/Unit Delay' */
  real32_T Product1_dx;                /* '<S216>/Product1' */
  real32_T Add1_fb;                    /* '<S216>/Add1' */
  real32_T Gain_b;                     /* '<S207>/Gain' */
  real32_T Sum1_n;                     /* '<S207>/Sum1' */
  real32_T Gain1_n;                    /* '<S207>/Gain1' */
  real32_T Delay2_i;                   /* '<S208>/Delay2' */
  real32_T Delay3_a;                   /* '<S208>/Delay3' */
  real32_T Switch1_f[2];               /* '<S209>/Switch1' */
  real32_T Product_k3;                 /* '<S213>/Product' */
  real32_T UnitDelay_iy;               /* '<S213>/Unit Delay' */
  real32_T Product1_c;                 /* '<S213>/Product1' */
  real32_T Add1_c;                     /* '<S213>/Add1' */
  real32_T Gain_m4;                    /* '<S208>/Gain' */
  real32_T Sum1_ci;                    /* '<S208>/Sum1' */
  real32_T Gain1_l;                    /* '<S208>/Gain1' */
  real32_T Product_kg;                 /* '<S173>/Product' */
  real32_T Product1_pv;                /* '<S173>/Product1' */
  real32_T Switch1_d[2];               /* '<S198>/Switch1' */
  real32_T Product_fd;                 /* '<S206>/Product' */
  real32_T UnitDelay_ju;               /* '<S206>/Unit Delay' */
  real32_T Product1_dq;                /* '<S206>/Product1' */
  real32_T Add1_d;                     /* '<S206>/Add1' */
  real32_T Delay1_i;                   /* '<S199>/Delay1' */
  real32_T Sum_mt;                     /* '<S199>/Sum' */
  real32_T Gain1_g;                    /* '<S199>/Gain1' */
  real32_T Delay_d;                    /* '<S199>/Delay' */
  real32_T Gain2_i;                    /* '<S199>/Gain2' */
  real32_T Sum1_a0;                    /* '<S199>/Sum1' */
  real32_T Product_j2;                 /* '<S172>/Product' */
  real32_T Switch1_n2[2];              /* '<S197>/Switch1' */
  real32_T Product_p;                  /* '<S203>/Product' */
  real32_T UnitDelay_id;               /* '<S203>/Unit Delay' */
  real32_T Product1_p0;                /* '<S203>/Product1' */
  real32_T Add1_c4;                    /* '<S203>/Add1' */
  real32_T Delay1_p;                   /* '<S200>/Delay1' */
  real32_T Sum_mq;                     /* '<S200>/Sum' */
  real32_T Gain1_ng;                   /* '<S200>/Gain1' */
  real32_T Delay_o;                    /* '<S200>/Delay' */
  real32_T Gain2_o;                    /* '<S200>/Gain2' */
  real32_T Sum1_h;                     /* '<S200>/Sum1' */
  real32_T Product1_ap;                /* '<S172>/Product1' */
  real32_T Sum_o;                      /* '<S172>/Sum' */
  real32_T MathFunction;               /* '<S172>/Math Function' */
  real32_T Abs_k;                      /* '<S172>/Abs' */
  real32_T Delay2_m;                   /* '<S174>/Delay2' */
  real32_T Delay3_d;                   /* '<S174>/Delay3' */
  real32_T Switch1_i[2];               /* '<S178>/Switch1' */
  real32_T Product_ke;                 /* '<S188>/Product' */
  real32_T UnitDelay_p;                /* '<S188>/Unit Delay' */
  real32_T Product1_o1;                /* '<S188>/Product1' */
  real32_T Add1_m;                     /* '<S188>/Add1' */
  real32_T Gain_gx;                    /* '<S174>/Gain' */
  real32_T Sum1_ag;                    /* '<S174>/Sum1' */
  real32_T Gain1_gr;                   /* '<S174>/Gain1' */
  real32_T Delay2_e;                   /* '<S175>/Delay2' */
  real32_T Delay3_m;                   /* '<S175>/Delay3' */
  real32_T Switch1_b[2];               /* '<S176>/Switch1' */
  real32_T Product_j5;                 /* '<S182>/Product' */
  real32_T UnitDelay_m;                /* '<S182>/Unit Delay' */
  real32_T Product1_br;                /* '<S182>/Product1' */
  real32_T Add1_o;                     /* '<S182>/Add1' */
  real32_T Gain_gp;                    /* '<S175>/Gain' */
  real32_T Sum1_ed;                    /* '<S175>/Sum1' */
  real32_T Gain1_p;                    /* '<S175>/Gain1' */
  real32_T Delay_f1;                   /* '<S179>/Delay' */
  real32_T Delay1_m;                   /* '<S179>/Delay1' */
  real32_T Switch1_fq;                 /* '<S179>/Switch1' */
  real32_T Switch1_a[2];               /* '<S177>/Switch1' */
  real32_T Product_md;                 /* '<S185>/Product' */
  real32_T UnitDelay_pm;               /* '<S185>/Unit Delay' */
  real32_T Product1_cn;                /* '<S185>/Product1' */
  real32_T Add1_fo;                    /* '<S185>/Add1' */
  real32_T Square;                     /* '<S170>/Square' */
  real32_T Square1;                    /* '<S170>/Square1' */
  real32_T Sum2_k;                     /* '<S170>/Sum2' */
  real32_T Sqrt;                       /* '<S170>/Sqrt' */
  real32_T UnaryMinus_b;               /* '<S170>/Unary Minus' */
  real32_T Sum_ji;                     /* '<S179>/Sum' */
  real32_T Sqrt_g;                     /* '<S117>/Sqrt' */
  real32_T Divide;                     /* '<S117>/Divide' */
  real32_T Divide1;                    /* '<S117>/Divide1' */
  real32_T Switch1_dz[2];              /* '<S237>/Switch1' */
  real32_T Product_am[4];              /* '<S240>/Product' */
  real32_T UnitDelay_a[4];             /* '<S240>/Unit Delay' */
  real32_T Product1_j[4];              /* '<S240>/Product1' */
  real32_T Add1_jy[4];                 /* '<S240>/Add1' */
  real32_T Sum_bf[4];                  /* '<S239>/Sum' */
  real32_T Product_c;                  /* '<S263>/Product' */
  real32_T Sum3_k;                     /* '<S260>/Sum3' */
  real32_T Delay1_pl;                  /* '<S262>/Delay1' */
  real32_T Sum_jy;                     /* '<S262>/Sum' */
  real32_T Product_d;                  /* '<S262>/Product' */
  real32_T Delay_p;                    /* '<S262>/Delay' */
  real32_T Product1_n5;                /* '<S262>/Product1' */
  real32_T Sum1_em;                    /* '<S262>/Sum1' */
  real32_T Product2_i;                 /* '<S263>/Product2' */
  real32_T Sum1_p;                     /* '<S260>/Sum1' */
  real32_T Sum_p;                      /* '<S261>/Sum' */
  real32_T Switch1_eg[2];              /* '<S261>/Switch1' */
  real32_T Product_fdo;                /* '<S266>/Product' */
  real32_T UnitDelay_dy;               /* '<S266>/Unit Delay' */
  real32_T Product1_k;                 /* '<S266>/Product1' */
  real32_T Add1_jx;                    /* '<S266>/Add1' */
  real32_T Switch_g;                   /* '<S259>/Switch' */
  real32_T Product_iw;                 /* '<S255>/Product' */
  real32_T Sum3_n0;                    /* '<S252>/Sum3' */
  real32_T Delay1_a;                   /* '<S254>/Delay1' */
  real32_T Sum_ga;                     /* '<S254>/Sum' */
  real32_T Product_n3;                 /* '<S254>/Product' */
  real32_T Delay_b;                    /* '<S254>/Delay' */
  real32_T Product1_g;                 /* '<S254>/Product1' */
  real32_T Sum1_mn;                    /* '<S254>/Sum1' */
  real32_T Product2_b;                 /* '<S255>/Product2' */
  real32_T Sum1_as;                    /* '<S252>/Sum1' */
  real32_T Sum_a;                      /* '<S253>/Sum' */
  real32_T Switch1_o[2];               /* '<S253>/Switch1' */
  real32_T Product_lm;                 /* '<S258>/Product' */
  real32_T UnitDelay_e;                /* '<S258>/Unit Delay' */
  real32_T Product1_ba;                /* '<S258>/Product1' */
  real32_T Add1_i;                     /* '<S258>/Add1' */
  real32_T Switch_h;                   /* '<S251>/Switch' */
  real32_T DTC;                        /* '<S271>/DTC' */
  real32_T SpeedGain;                  /* '<S236>/SpeedGain' */
  real32_T Switch1_bs[2];              /* '<S235>/Switch1' */
  real32_T Product_pk;                 /* '<S269>/Product' */
  real32_T UnitDelay_dk;               /* '<S269>/Unit Delay' */
  real32_T Product1_al;                /* '<S269>/Product1' */
  real32_T Add1_p;                     /* '<S269>/Add1' */
  real32_T elect2mech;                 /* '<S81>/elect2mech' */
  real32_T Sum_dj;                     /* '<S265>/Sum' */
  real32_T Sum_ac;                     /* '<S257>/Sum' */
  real32_T Atan2;                      /* '<S249>/Atan2' */
  real32_T Switch_ds;                  /* '<S249>/Switch' */
  real32_T algDD;
  real32_T Gain_f;                     /* '<S250>/Gain' */
  real32_T Switch_c;                   /* '<S250>/Switch' */
  real32_T Bias;                       /* '<S250>/Bias' */
  real32_T UnitDelay1;                 /* '<S284>/Unit Delay1' */
  real32_T UnitDelay_g;                /* '<S284>/Unit Delay' */
  real32_T a;                          /* '<S284>/a' */
  real32_T Delay_k;                    /* '<S274>/Delay' */
  real32_T Sum2_g;                     /* '<S274>/Sum2' */
  real32_T Sum3_m;                     /* '<S284>/Sum3' */
  real32_T b_invg;                     /* '<S284>/b_inv*g' */
  real32_T Delay1_e;                   /* '<S284>/Delay1' */
  real32_T Sum4_b;                     /* '<S284>/Sum4' */
  real32_T Switch1_jq[2];              /* '<S276>/Switch1' */
  real32_T Product_c0;                 /* '<S288>/Product' */
  real32_T UnitDelay_ab;               /* '<S288>/Unit Delay' */
  real32_T Product1_en;                /* '<S288>/Product1' */
  real32_T Add1_dd;                    /* '<S288>/Add1' */
  real32_T UnitDelay1_k;               /* '<S285>/Unit Delay1' */
  real32_T UnitDelay_k;                /* '<S285>/Unit Delay' */
  real32_T a_e;                        /* '<S285>/a' */
  real32_T Delay_i;                    /* '<S275>/Delay' */
  real32_T Sum2_g2;                    /* '<S275>/Sum2' */
  real32_T Sum3_l;                     /* '<S285>/Sum3' */
  real32_T b_invg_o;                   /* '<S285>/b_inv*g' */
  real32_T Delay1_f;                   /* '<S285>/Delay1' */
  real32_T Sum4_m;                     /* '<S285>/Sum4' */
  real32_T Switch1_m[2];               /* '<S277>/Switch1' */
  real32_T Product_p3;                 /* '<S291>/Product' */
  real32_T UnitDelay_gx;               /* '<S291>/Unit Delay' */
  real32_T Product1_k4;                /* '<S291>/Product1' */
  real32_T Add1_gu;                    /* '<S291>/Add1' */
  real32_T Merge_ku;                   /* '<S273>/Merge' */
  real32_T Merge1_i;                   /* '<S273>/Merge1' */
  real32_T Delay_e;                    /* '<S272>/Delay' */
  real32_T Sign;                       /* '<S274>/Sign' */
  real32_T Eta;                        /* '<S274>/Eta' */
  real32_T Sum_gf;                     /* '<S274>/Sum' */
  real32_T b;                          /* '<S274>/b' */
  real32_T a_a;                        /* '<S274>/a' */
  real32_T Sum1_d;                     /* '<S274>/Sum1' */
  real32_T Sign_m;                     /* '<S275>/Sign' */
  real32_T Eta_n;                      /* '<S275>/Eta' */
  real32_T Sum_bl;                     /* '<S275>/Sum' */
  real32_T b_i;                        /* '<S275>/b' */
  real32_T a_p;                        /* '<S275>/a' */
  real32_T Sum1_g;                     /* '<S275>/Sum1' */
  real32_T DTC_e;                      /* '<S296>/DTC' */
  real32_T SpeedGain_k;                /* '<S279>/SpeedGain' */
  real32_T Switch1_bp[2];              /* '<S278>/Switch1' */
  real32_T Product_i2;                 /* '<S294>/Product' */
  real32_T UnitDelay_ci;               /* '<S294>/Unit Delay' */
  real32_T Product1_ey;                /* '<S294>/Product1' */
  real32_T Add1_cr;                    /* '<S294>/Add1' */
  real32_T Product_jt;                 /* '<S280>/Product' */
  real32_T Product2_il;                /* '<S280>/Product2' */
  real32_T Sum1_mc;                    /* '<S280>/Sum1' */
  real32_T Product1_m;                 /* '<S280>/Product1' */
  real32_T Product3_b;                 /* '<S280>/Product3' */
  real32_T Sum2_p;                     /* '<S280>/Sum2' */
  real32_T Switch_cx;                  /* '<S280>/Switch' */
  real32_T Atan2_n;                    /* '<S297>/Atan2' */
  real32_T Switch_gb;                  /* '<S297>/Switch' */
  real32_T algDD_a;
  real32_T Gain_o;                     /* '<S298>/Gain' */
  real32_T Switch_m;                   /* '<S298>/Switch' */
  real32_T Bias_f;                     /* '<S298>/Bias' */
  real32_T Bias_j;                     /* '<S280>/Bias' */
  real32_T Input_h;                    /* '<S52>/Input' */
  real32_T qcos;                       /* '<S49>/qcos' */
  real32_T dsin;                       /* '<S49>/dsin' */
  real32_T sum_beta;                   /* '<S49>/sum_beta' */
  real32_T dcos;                       /* '<S49>/dcos' */
  real32_T qsin;                       /* '<S49>/qsin' */
  real32_T sum_alpha;                  /* '<S49>/sum_alpha' */
  real32_T Switch_f[2];                /* '<S50>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T V_q_ref;                    /* '<S28>/MATLAB Function' */
  real32_T Saturation;                 /* '<S27>/Saturation' */
  real32_T V_d_ref;                    /* '<S27>/MATLAB Function' */
  real32_T Product_ch[2];              /* '<S33>/Product' */
  real32_T SquareRoot;                 /* '<S33>/Square Root' */
  real32_T Switch_o;                   /* '<S33>/Switch' */
  real32_T Switch_i[2];                /* '<S30>/Switch' */
  real32_T Switch2;                    /* '<S40>/Switch2' */
  real32_T Product_bp;                 /* '<S39>/Product' */
  real32_T Sum_a3;                     /* '<S39>/Sum' */
  real32_T Product2_ao;                /* '<S39>/Product2' */
  real32_T Merge_e;                    /* '<S39>/Merge' */
  real32_T Gain_lx;                    /* '<S39>/Gain' */
  real32_T Switch_k;                   /* '<S40>/Switch' */
  real32_T Switch1_h;                  /* '<S41>/Switch1' */
  real32_T Sqrt_n;                     /* '<S41>/Sqrt' */
  real32_T Gain_e;                     /* '<S41>/Gain' */
  int32_T DataTypeConversion_ch[2];    /* '<S78>/Data Type Conversion' */
  int32_T Add_k[2];                    /* '<S78>/Add' */
  int32_T Q17perunitconversion[2];     /* '<S78>/Q17 per unit conversion' */
  int32_T SpeedCount;                  /* '<S236>/SpeedCount' */
  int32_T SpeedCount_c;                /* '<S279>/SpeedCount' */
  uint16_T DataTypeConversion_b;       /* '<S400>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S398>/Get_Integer' */
  uint16_T Divide_h;                   /* '<S311>/Divide' */
  uint16_T Divide1_e;                  /* '<S311>/Divide1' */
  uint16_T ForIterator;                /* '<S314>/For Iterator' */
  uint16_T IAIBMeasurement[2];         /* '<S314>/IA//IB Measurement' */
  uint16_T Memory;                     /* '<S319>/Memory' */
  uint16_T Sum_dn;                     /* '<S319>/Sum' */
  uint16_T Memory1;                    /* '<S319>/Memory1' */
  uint16_T Sum1_dq;                    /* '<S319>/Sum1' */
  uint16_T SCIReceive[2];              /* '<S325>/SCI Receive' */
  uint16_T DataStoreRead_m;            /* '<S78>/Data Store Read' */
  uint16_T DataStoreRead1_p;           /* '<S78>/Data Store Read1' */
  uint16_T IAIBMeasurement_k[2];       /* '<S77>/IA//IB Measurement' */
  uint16_T Switch1_fg;                 /* '<S31>/Switch1' */
  uint16_T DataTypeConversion_e;       /* '<S57>/Data Type Conversion' */
  uint16_T Get_Integer_i;              /* '<S55>/Get_Integer' */
  uint16_T Output;                     /* '<S70>/Output' */
  uint16_T DataTypeConversion3[2];     /* '<S72>/Data Type Conversion3' */
  uint16_T SCI_Tx_Data[3];             /* '<S10>/Merge' */
  uint16_T SCI_Tx_Iteration;           /* '<S10>/Merge1' */
  uint16_T FixPtSum1;                  /* '<S75>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S76>/FixPt Switch' */
  uint16_T Switch1_c[3];               /* '<S299>/Switch1' */
  uint16_T IndexVector;                /* '<S301>/Index Vector' */
  uint16_T Add_m;                      /* '<S301>/Add' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S299>/Scale_to_PWM_Counter_PRD' */
  uint16_T DataTypeConversion_n;       /* '<S227>/Data Type Conversion' */
  uint16_T Get_Integer_m;              /* '<S225>/Get_Integer' */
  uint16_T Data[2];                    /* '<S71>/Data' */
  uint16_T Data_f[2];                  /* '<S73>/Data' */
  uint16_T Data_fw[2];                 /* '<S74>/Data' */
  uint16_T DataTypeConversion_k;       /* '<S29>/Data Type Conversion' */
  uint16_T DataTypeConversion_a;       /* '<S39>/Data Type Conversion' */
  int16_T DataTypeConversion2[2];      /* '<S323>/Data Type Conversion2' */
  int16_T DataTypeConversion_l[2];     /* '<S72>/Data Type Conversion' */
  int16_T DataTypeConversion_ey;       /* '<S51>/Data Type Conversion' */
  int16_T WhileIterator;               /* '<S301>/While Iterator' */
  int16_T DataTypeConversion_h;        /* '<S223>/Data Type Conversion' */
  boolean_T RT5;                       /* '<S8>/RT5' */
  boolean_T NOT;                       /* '<S8>/NOT' */
  boolean_T Enable;                    /* '<S8>/State Machine OL - CL' */
  boolean_T EnClosedLoop;              /* '<S8>/State Machine OL - CL' */
  boolean_T Compare;                   /* '<S402>/Compare' */
  boolean_T NOT_h;                     /* '<S310>/NOT' */
  boolean_T DataTypeConversion3_b;     /* '<S6>/Data Type Conversion3' */
  boolean_T DataStoreRead1_n;          /* '<S19>/Data Store Read1' */
  boolean_T Delay_kh;                  /* '<S51>/Delay' */
  boolean_T DataStoreRead2_m;          /* '<S19>/Data Store Read2' */
  boolean_T Compare_d;                 /* '<S59>/Compare' */
  boolean_T DataStoreRead1_b;          /* '<S28>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S28>/Logical Operator' */
  boolean_T DataStoreRead1_f;          /* '<S27>/Data Store Read1' */
  boolean_T LogicalOperator_e;         /* '<S27>/Logical Operator' */
  boolean_T Enable_l;                  /* '<S14>/Enable' */
  boolean_T DataStoreRead1_g;          /* '<S80>/Data Store Read1' */
  boolean_T LogicalOperator_l;         /* '<S80>/Logical Operator' */
  boolean_T AlphaRelay;                /* '<S101>/AlphaRelay' */
  boolean_T BetaRelay;                 /* '<S101>/BetaRelay' */
  boolean_T Compare_j;                 /* '<S115>/Compare' */
  boolean_T Compare_k;                 /* '<S229>/Compare' */
  boolean_T NOT_hg;                    /* '<S221>/NOT' */
  boolean_T Delay_bv;                  /* '<S223>/Delay' */
  boolean_T Compare_n;                 /* '<S190>/Compare' */
  boolean_T Compare_kj;                /* '<S192>/Compare' */
  boolean_T Compare_o;                 /* '<S189>/Compare' */
  boolean_T LogicalOperator1;          /* '<S179>/Logical Operator1' */
  boolean_T Compare_d4;                /* '<S193>/Compare' */
  boolean_T LogicalOperator2;          /* '<S179>/Logical Operator2' */
  boolean_T AND;                       /* '<S179>/AND' */
  boolean_T UnitDelay_cp;              /* '<S179>/Unit Delay' */
  boolean_T Switch_l;                  /* '<S179>/Switch' */
  boolean_T Compare_c;                 /* '<S191>/Compare' */
  boolean_T LogicalOperator_k;         /* '<S179>/Logical Operator' */
  boolean_T DataStoreRead1_c;          /* '<S81>/Data Store Read1' */
  boolean_T LogicalOperator_ed;        /* '<S81>/Logical Operator' */
  boolean_T DataStoreRead1_i;          /* '<S82>/Data Store Read1' */
  boolean_T LogicalOperator_i;         /* '<S82>/Logical Operator' */
  boolean_T AlphaRelay_p;              /* '<S273>/AlphaRelay' */
  boolean_T BetaRelay_j;               /* '<S273>/BetaRelay' */
  boolean_T RelationalOperator;        /* '<S29>/Relational Operator' */
  boolean_T Compare_n2;                /* '<S35>/Compare' */
  boolean_T Compare_m;                 /* '<S36>/Compare' */
  boolean_T LowerRelop1;               /* '<S40>/LowerRelop1' */
  boolean_T RelationalOperator_c;      /* '<S39>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S40>/UpperRelop' */
  rtB_RunModeComputeId0_mcb_pmsm_ RunModeComputeId0;/* '<S389>/RunMode.ComputeId0' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_s TwoinputsCRL_j;/* '<S393>/Two inputs CRL' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1_b;/* '<S400>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem_ey;/* '<S400>/If Action Subsystem' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_s TwoinputsCRL_c;/* '<S391>/Two inputs CRL' */
  rtB_TwophaseCRLwrap_mcb_pmsm_fo TwophaseCRLwrap_b;/* '<S394>/Two phase CRL wrap' */
  rtB_SpeedControl_mcb_pmsm_foc_s SpeedControl;/* '<Root>/Speed Control' */
  rtB_SPIMasterTransfer_mcb_pmsm_ SPIMasterTransfer1;/* '<S312>/SPI Master Transfer' */
  rtB_SPIMasterTransfer_mcb_pmsm_ SPIMasterTransfer;/* '<S312>/SPI Master Transfer' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1_o;/* '<S227>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem_e;/* '<S227>/If Action Subsystem' */
  rtB_Dir_Sense_mcb_pmsm_foc_sens Dir_Sense_m;/* '<S101>/Dir_Sense' */
  rtB_Dir_Sense_mcb_pmsm_foc_sens Dir_Sense;/* '<S273>/Dir_Sense' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1;/* '<S57>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem;/* '<S57>/If Action Subsystem' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_s TwoinputsCRL_m;/* '<S20>/Two inputs CRL' */
  rtB_TwophaseCRLwrap_mcb_pmsm_fo TwophaseCRLwrap;/* '<S23>/Two phase CRL wrap' */
} BlockIO_mcb_pmsm_foc_sensorless;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Add_DWORK1;                   /* '<S26>/Add' */
  real32_T UnitDelay_DSTATE;           /* '<S8>/Unit Delay' */
  real32_T Delay5_DSTATE[4];           /* '<S1>/Delay5' */
  real32_T Delay_DSTATE;               /* '<S19>/Delay' */
  real32_T UnitDelay_DSTATE_g;         /* '<S47>/Unit Delay' */
  real32_T Delay1_DSTATE;              /* '<S83>/Delay1' */
  real32_T Delay_DSTATE_o[2];          /* '<S84>/Delay' */
  real32_T Delay_DSTATE_a;             /* '<S220>/Delay' */
  real32_T Integrator_DSTATE;          /* '<S152>/Integrator' */
  real32_T Delay2_DSTATE;              /* '<S207>/Delay2' */
  real32_T Delay3_DSTATE;              /* '<S207>/Delay3' */
  real32_T Delay2_DSTATE_i;            /* '<S208>/Delay2' */
  real32_T Delay3_DSTATE_b;            /* '<S208>/Delay3' */
  real32_T Delay1_DSTATE_o;            /* '<S199>/Delay1' */
  real32_T Delay_DSTATE_ao;            /* '<S199>/Delay' */
  real32_T Delay1_DSTATE_n;            /* '<S200>/Delay1' */
  real32_T Delay_DSTATE_oe;            /* '<S200>/Delay' */
  real32_T Delay2_DSTATE_c;            /* '<S174>/Delay2' */
  real32_T Delay3_DSTATE_d;            /* '<S174>/Delay3' */
  real32_T Delay2_DSTATE_p;            /* '<S175>/Delay2' */
  real32_T Delay3_DSTATE_ds;           /* '<S175>/Delay3' */
  real32_T UnitDelay_DSTATE_d5[4];     /* '<S240>/Unit Delay' */
  real32_T Delay1_DSTATE_e;            /* '<S262>/Delay1' */
  real32_T Delay_DSTATE_m;             /* '<S262>/Delay' */
  real32_T UnitDelay_DSTATE_m;         /* '<S266>/Unit Delay' */
  real32_T Delay1_DSTATE_m;            /* '<S254>/Delay1' */
  real32_T Delay_DSTATE_p;             /* '<S254>/Delay' */
  real32_T UnitDelay_DSTATE_b;         /* '<S258>/Unit Delay' */
  real32_T UnitDelay_DSTATE_a1;        /* '<S269>/Unit Delay' */
  real32_T Delay_DSTATE_nd;            /* '<S274>/Delay' */
  real32_T Delay1_DSTATE_l;            /* '<S284>/Delay1' */
  real32_T Delay_DSTATE_e;             /* '<S275>/Delay' */
  real32_T Delay1_DSTATE_j;            /* '<S285>/Delay1' */
  real32_T Delay_DSTATE_nm;            /* '<S272>/Delay' */
  uint32_T Delay_DSTATE_ad[10];        /* '<S236>/Delay' */
  volatile real32_T RT6_Buffer[2];     /* '<S8>/RT6' */
  volatile real32_T RT4_Buffer[2];     /* '<Root>/RT4' */
  volatile real32_T RT2_Buffer[4];     /* '<Root>/RT2' */
  real32_T Iq_ref_initial;             /* '<Root>/Data Store Memory' */
  real32_T Ia_meas_PU;                 /* '<Root>/Data Store Memory11' */
  real32_T Vd_out_initial;             /* '<Root>/Data Store Memory12' */
  real32_T Vq_out_initial;             /* '<Root>/Data Store Memory13' */
  real32_T Id0_out;                    /* '<Root>/Data Store Memory15' */
  real32_T SpdCtrlRef;                 /* '<Root>/Data Store Memory16' */
  real32_T V_alpha;                    /* '<Root>/Data Store Memory17' */
  real32_T V_beta;                     /* '<Root>/Data Store Memory18' */
  real32_T Ib_meas_PU;                 /* '<Root>/Data Store Memory8' */
  real32_T Pos_meas_PU;                /* '<Root>/Data Store Memory9' */
  real32_T integrator_state;           /* '<S28>/MATLAB Function' */
  real32_T integrator_state_a;         /* '<S27>/MATLAB Function' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S321>/Digital Output1' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S312>/Digital Output' */
  int32_T Add_DWORK1_o[2];             /* '<S78>/Add' */
  int32_T DigitalOutput_FRAC_LEN_h;    /* '<S299>/Digital Output' */
  int32_T SpeedCount_DWORK1;           /* '<S236>/SpeedCount' */
  uint32_T Sum_DWORK1[4];              /* '<S398>/Sum' */
  uint32_T Sum_DWORK1_h[4];            /* '<S55>/Sum' */
  uint16_T Output_DSTATE;              /* '<S70>/Output' */
  volatile int16_T RT6_ActiveBufIdx;   /* '<S8>/RT6' */
  volatile int16_T RT6_semaphoreTaken; /* '<S8>/RT6' */
  volatile int16_T RT4_ActiveBufIdx;   /* '<Root>/RT4' */
  volatile int16_T RT4_semaphoreTaken; /* '<Root>/RT4' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory1' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory2' */
  uint16_T temporalCounter_i1;         /* '<S8>/State Machine OL - CL' */
  uint16_T Memory_PreviousInput;       /* '<S319>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S319>/Memory1' */
  uint16_T Add_DWORK1_oy;              /* '<S301>/Add' */
  uint16_T CircBufIdx;                 /* '<S236>/Delay' */
  uint16_T CircBufIdx_n;               /* '<S279>/Delay' */
  boolean_T Delay_DSTATE_d;            /* '<S51>/Delay' */
  int16_T Integrator_PrevResetState;   /* '<S152>/Integrator' */
  uint16_T is_active_c3_mcb_pmsm_foc_senso;/* '<S8>/State Machine OL - CL' */
  uint16_T is_c3_mcb_pmsm_foc_sensorless_f;/* '<S8>/State Machine OL - CL' */
  uint16_T is_RunMode;                 /* '<S8>/State Machine OL - CL' */
  uint16_T is_NegativeSpeedRun;        /* '<S8>/State Machine OL - CL' */
  uint16_T is_PositiveSpeedRun;        /* '<S8>/State Machine OL - CL' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T EnClosedLoop;              /* '<Root>/Data Store Memory5' */
  boolean_T icLoad;                    /* '<S19>/Delay' */
  boolean_T AlphaRelay_Mode;           /* '<S101>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S101>/BetaRelay' */
  boolean_T AlphaRelay_Mode_c;         /* '<S273>/AlphaRelay' */
  boolean_T BetaRelay_Mode_j;          /* '<S273>/BetaRelay' */
  rtDW_SpeedControl_mcb_pmsm_foc_ SpeedControl;/* '<Root>/Speed Control' */
  rtDW_SPIMasterTransfer_mcb_pmsm SPIMasterTransfer1;/* '<S312>/SPI Master Transfer' */
  rtDW_SPIMasterTransfer_mcb_pmsm SPIMasterTransfer;/* '<S312>/SPI Master Transfer' */
} D_Work_mcb_pmsm_foc_sensorless_;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S19>/Delay' */
  ZCSigState Delay1_Reset_ZCE;         /* '<S83>/Delay1' */
  ZCSigState Delay_Reset_ZCE_g;        /* '<S84>/Delay' */
  ZCSigState Delay_Reset_ZCE_m;        /* '<S220>/Delay' */
  ZCSigState Delay2_Reset_ZCE;         /* '<S207>/Delay2' */
  ZCSigState Delay3_Reset_ZCE;         /* '<S207>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_g;       /* '<S208>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_g;       /* '<S208>/Delay3' */
  ZCSigState Delay1_Reset_ZCE_d;       /* '<S199>/Delay1' */
  ZCSigState Delay_Reset_ZCE_l;        /* '<S199>/Delay' */
  ZCSigState Delay1_Reset_ZCE_db;      /* '<S200>/Delay1' */
  ZCSigState Delay_Reset_ZCE_gg;       /* '<S200>/Delay' */
  ZCSigState Delay2_Reset_ZCE_p;       /* '<S174>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_p;       /* '<S174>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_h;       /* '<S175>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_c;       /* '<S175>/Delay3' */
  rtZCE_Dir_Sense_mcb_pmsm_foc_se Dir_Sense_m;/* '<S101>/Dir_Sense' */
  ZCSigState Delay1_Reset_ZCE_e;       /* '<S262>/Delay1' */
  ZCSigState Delay_Reset_ZCE_p;        /* '<S262>/Delay' */
  ZCSigState Delay1_Reset_ZCE_l;       /* '<S254>/Delay1' */
  ZCSigState Delay_Reset_ZCE_d;        /* '<S254>/Delay' */
  ZCSigState Delay_Reset_ZCE_n;        /* '<S274>/Delay' */
  ZCSigState Delay1_Reset_ZCE_b;       /* '<S284>/Delay1' */
  ZCSigState Delay_Reset_ZCE_ld;       /* '<S275>/Delay' */
  ZCSigState Delay1_Reset_ZCE_bl;      /* '<S285>/Delay1' */
  ZCSigState Delay_Reset_ZCE_n0;       /* '<S272>/Delay' */
  rtZCE_Dir_Sense_mcb_pmsm_foc_se Dir_Sense;/* '<S273>/Dir_Sense' */
} PrevZCSigStates_mcb_pmsm_foc_se;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Product2;               /* '<S26>/Product2' */
  const uint16_T Width;                /* '<S10>/Width' */
} ConstBlockIO_mcb_pmsm_foc_senso;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S55>/sine_table_values'
   *   '<S398>/sine_table_values'
   *   '<S225>/sine_table_values'
   */
  real32_T pooled31[1002];
} ConstParam_mcb_pmsm_foc_sensorl;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_foc_sensorless {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern BlockIO_mcb_pmsm_foc_sensorless mcb_pmsm_foc_sensorless_f2806_B;

/* Block states (default storage) */
extern D_Work_mcb_pmsm_foc_sensorless_ mcb_pmsm_foc_sensorless_f_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_mcb_pmsm_foc_se mcb_pmsm_foc_sen_PrevZCSigState;
extern const ConstBlockIO_mcb_pmsm_foc_senso mcb_pmsm_foc_sensorless__ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_mcb_pmsm_foc_sensorl mcb_pmsm_foc_sensorless__ConstP;

/* External function called from main */
extern void mcb_pmsm_foc_sensorless_f28069MLaunchPad_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void mcb_pmsm_foc_sensorless_f28069MLaunchPad_initialize(void);
extern void mcb_pmsm_foc_sensorless_f28069MLaunchPad_step0(void);/* Sample time: [0.0005s, 0.0s] */
extern void mcb_pmsm_foc_sensorless_f28069MLaunchPad_step1(void);/* Sample time: [0.5s, 0.0s] */
extern void mcb_pmsm_foc_sensorless_f28069MLaunchPad_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_foc_sensorles *const mcb_pmsm_foc_sensorless_f280_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void SCIRXINTA(void);
  interrupt void ADCINT1(void);
  void mcb_pmsm_foc_sensorless_f28069MLaunchPad_configure_interrupts (void);
  void mcb_pmsm_foc_sensorless_f28069MLaunchPad_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad'
 * '<S1>'   : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control'
 * '<S2>'   : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt'
 * '<S3>'   : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init'
 * '<S4>'   : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Heartbeat LED'
 * '<S5>'   : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Inverter and Motor - Plant Model'
 * '<S6>'   : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Serial Receive'
 * '<S7>'   : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control'
 * '<S8>'   : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler'
 * '<S9>'   : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop'
 * '<S10>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging'
 * '<S11>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/HW Inputs'
 * '<S12>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling'
 * '<S13>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Inverter'
 * '<S14>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Output Scaling'
 * '<S15>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/SCI_Tx'
 * '<S16>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Clarke Transform'
 * '<S17>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers'
 * '<S18>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Inverse Park Transform'
 * '<S19>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Open_Loop_Control'
 * '<S20>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Park Transform'
 * '<S21>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup'
 * '<S22>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator'
 * '<S23>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Clarke Transform/Two phase input'
 * '<S24>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S25>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter'
 * '<S26>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/Non-linear compensation'
 * '<S27>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id'
 * '<S28>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq'
 * '<S29>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S30>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S31>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S32>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S33>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S34>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S35>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S36>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S37>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S38>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S39>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S40>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S41>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S42>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S43>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/IIR Filter'
 * '<S44>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/MATLAB Function'
 * '<S45>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/IIR Filter/IIR Filter'
 * '<S46>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/IIR Filter/IIR Filter/Low-pass'
 * '<S47>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S48>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/MATLAB Function'
 * '<S49>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Inverse Park Transform/Two inputs CRL'
 * '<S50>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S51>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Open_Loop_Control/Accumulate1'
 * '<S52>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Open_Loop_Control/Accumulate1/Subsystem'
 * '<S53>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Park Transform/Two inputs CRL'
 * '<S54>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S55>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S56>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S57>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S58>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S59>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S60>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S61>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S62>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S63>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Modulation method'
 * '<S64>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Voltage Input'
 * '<S65>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Modulation method/SVPWM'
 * '<S66>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S67>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S68>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S69>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S70>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Counter Limited'
 * '<S71>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Data'
 * '<S72>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Data_Conditioning'
 * '<S73>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/End'
 * '<S74>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Start'
 * '<S75>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Counter Limited/Increment Real World'
 * '<S76>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S77>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/HW Inputs/Sensor Driver Blocks (codegen)'
 * '<S78>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate Phase Currents'
 * '<S79>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed'
 * '<S80>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer'
 * '<S81>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer'
 * '<S82>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer'
 * '<S83>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer'
 * '<S84>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer'
 * '<S85>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter'
 * '<S86>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/PerUnit'
 * '<S87>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer'
 * '<S88>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem'
 * '<S89>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem2'
 * '<S90>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/A11'
 * '<S91>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/A12'
 * '<S92>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/A22'
 * '<S93>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/L'
 * '<S94>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/L1'
 * '<S95>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/L2'
 * '<S96>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem2/B'
 * '<S97>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem2/L'
 * '<S98>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter/IIR Filter'
 * '<S99>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S100>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S101>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch'
 * '<S102>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL'
 * '<S103>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch/Dir_Sense'
 * '<S104>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem2'
 * '<S105>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem3'
 * '<S106>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter'
 * '<S107>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Normalize'
 * '<S108>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller'
 * '<S109>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward'
 * '<S110>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Subsystem'
 * '<S111>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO'
 * '<S112>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter'
 * '<S113>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass'
 * '<S114>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S115>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Normalize/Compare To Zero'
 * '<S116>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Normalize/If Action Subsystem'
 * '<S117>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Normalize/Subsystem'
 * '<S118>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup'
 * '<S119>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain'
 * '<S120>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative'
 * '<S121>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter'
 * '<S122>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs'
 * '<S123>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain'
 * '<S124>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain'
 * '<S125>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S126>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator'
 * '<S127>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs'
 * '<S128>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy'
 * '<S129>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain'
 * '<S130>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy'
 * '<S131>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain'
 * '<S132>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal'
 * '<S133>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation'
 * '<S134>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk'
 * '<S135>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum'
 * '<S136>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk'
 * '<S137>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode'
 * '<S138>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum'
 * '<S139>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral'
 * '<S140>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain'
 * '<S141>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal'
 * '<S142>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal'
 * '<S143>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal'
 * '<S144>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup/Passthrough'
 * '<S145>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain/Disabled'
 * '<S146>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative/Disabled'
 * '<S147>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter/Disabled'
 * '<S148>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs/Disabled'
 * '<S149>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain/Internal Parameters'
 * '<S150>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S151>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S152>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator/Discrete'
 * '<S153>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S154>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S155>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain/Disabled'
 * '<S156>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy/Disabled'
 * '<S157>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S158>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal/External Reset'
 * '<S159>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation/Passthrough'
 * '<S160>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S161>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum/Sum_PI'
 * '<S162>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S163>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S164>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S165>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S166>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S167>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S168>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal/Internal PreInt'
 * '<S169>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S170>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod'
 * '<S171>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter'
 * '<S172>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod'
 * '<S173>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod'
 * '<S174>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Differentiator'
 * '<S175>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Differentiator1'
 * '<S176>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter1'
 * '<S177>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter2'
 * '<S178>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter3'
 * '<S179>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem'
 * '<S180>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S181>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S182>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S183>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter2/IIR Filter'
 * '<S184>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter2/IIR Filter/Low-pass'
 * '<S185>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter2/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S186>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S187>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S188>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S189>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant'
 * '<S190>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant1'
 * '<S191>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant2'
 * '<S192>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant4'
 * '<S193>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant5'
 * '<S194>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter'
 * '<S195>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass'
 * '<S196>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S197>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1'
 * '<S198>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3'
 * '<S199>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator'
 * '<S200>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator1'
 * '<S201>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter'
 * '<S202>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S203>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S204>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter'
 * '<S205>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S206>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S207>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator'
 * '<S208>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator1'
 * '<S209>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1'
 * '<S210>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3'
 * '<S211>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S212>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S213>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S214>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S215>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S216>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S217>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem'
 * '<S218>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem1'
 * '<S219>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem'
 * '<S220>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased'
 * '<S221>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator'
 * '<S222>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup'
 * '<S223>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator/Accumulate'
 * '<S224>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator/Accumulate/Subsystem'
 * '<S225>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S226>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S227>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S228>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S229>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S230>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S231>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S232>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S233>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1'
 * '<S234>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer'
 * '<S235>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter'
 * '<S236>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement'
 * '<S237>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1/IIR Filter'
 * '<S238>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1/IIR Filter/IIR Filter'
 * '<S239>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1/IIR Filter/IIR Filter/High-pass'
 * '<S240>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S241>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2'
 * '<S242>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Data type Handling'
 * '<S243>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Flux Calculation'
 * '<S244>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/ParamBus'
 * '<S245>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/passthrough'
 * '<S246>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha'
 * '<S247>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta'
 * '<S248>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default'
 * '<S249>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2'
 * '<S250>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2/Per Unit'
 * '<S251>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default'
 * '<S252>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc'
 * '<S253>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter'
 * '<S254>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Integrator'
 * '<S255>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Scaling'
 * '<S256>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S257>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S258>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S259>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default'
 * '<S260>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc'
 * '<S261>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter'
 * '<S262>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Integrator'
 * '<S263>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Scaling'
 * '<S264>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S265>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S266>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S267>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter'
 * '<S268>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S269>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S270>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle'
 * '<S271>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S272>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1'
 * '<S273>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch'
 * '<S274>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ealpha_est'
 * '<S275>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ebeta_est'
 * '<S276>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha'
 * '<S277>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta'
 * '<S278>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter'
 * '<S279>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Speed Measurement'
 * '<S280>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/angleCompensation'
 * '<S281>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch/Dir_Sense'
 * '<S282>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch/Subsystem2'
 * '<S283>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch/Subsystem3'
 * '<S284>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ealpha_est/DisturbanceObserver'
 * '<S285>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ebeta_est/DisturbanceObserver'
 * '<S286>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha/IIR Filter'
 * '<S287>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha/IIR Filter/Low-pass'
 * '<S288>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S289>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta/IIR Filter'
 * '<S290>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta/IIR Filter/Low-pass'
 * '<S291>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S292>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter/IIR Filter'
 * '<S293>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter/IIR Filter/Low-pass'
 * '<S294>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S295>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Speed Measurement/DT_Handle'
 * '<S296>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Speed Measurement/DT_Handle/floating-point'
 * '<S297>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/angleCompensation/atan1'
 * '<S298>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/angleCompensation/atan1/Per Unit'
 * '<S299>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Inverter/Code Generation'
 * '<S300>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/SCI_Tx/Code Generation'
 * '<S301>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/SCI_Tx/Code Generation/CodeGeneration'
 * '<S302>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation'
 * '<S303>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_ADCINT1'
 * '<S304>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_SCIRXINTA'
 * '<S305>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_ADCINT1/ECSoC'
 * '<S306>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_ADCINT1/ECSoC/ECSimCodegen'
 * '<S307>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_SCIRXINTA/ECSoC'
 * '<S308>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_SCIRXINTA/ECSoC/ECSimCodegen'
 * '<S309>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem'
 * '<S310>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation'
 * '<S311>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset '
 * '<S312>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/DRV Enable'
 * '<S313>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Default ADC Offset'
 * '<S314>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem'
 * '<S315>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem'
 * '<S316>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem1'
 * '<S317>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem2'
 * '<S318>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem3'
 * '<S319>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S320>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Heartbeat LED/Heartbeat LED'
 * '<S321>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Heartbeat LED/Heartbeat LED/Code generation'
 * '<S322>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Inverter and Motor - Plant Model/Codegeneration'
 * '<S323>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Serial Receive/Data_Conditioning'
 * '<S324>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Serial Receive/SCI_Rx'
 * '<S325>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Serial Receive/SCI_Rx/Code Generation'
 * '<S326>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed'
 * '<S327>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/SlewRate'
 * '<S328>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S329>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/MATLAB Function'
 * '<S330>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S331>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S332>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S333>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S334>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S335>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S336>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S337>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S338>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S339>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S340>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S341>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S342>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S343>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S344>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S345>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S346>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S347>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S348>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S349>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S350>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S351>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S352>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S353>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S354>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S355>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S356>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S357>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S358>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S359>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S360>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S361>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S362>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S363>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S364>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S365>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S366>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S367>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S368>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S369>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S370>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S371>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S372>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S373>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S374>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S375>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S376>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S377>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S378>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S379>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S380>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S381>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S382>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S383>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S384>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S385>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S386>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S387>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S388>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values'
 * '<S389>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/State Machine OL - CL'
 * '<S390>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Clarke Transform'
 * '<S391>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/I Park Transform'
 * '<S392>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup'
 * '<S393>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/V Park Transform'
 * '<S394>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Clarke Transform/Two phase input'
 * '<S395>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S396>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/I Park Transform/Two inputs CRL'
 * '<S397>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/I Park Transform/Two inputs CRL/Switch_Axis'
 * '<S398>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S399>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S400>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S401>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S402>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S403>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S404>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S405>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S406>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/V Park Transform/Two inputs CRL'
 * '<S407>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/V Park Transform/Two inputs CRL/Switch_Axis'
 * '<S408>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/State Machine OL - CL/RunMode.ComputeId0'
 * '<S409>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/State Machine OL - CL/RunMode.ComputeId0/Compare To Constant'
 */
#endif                         /* mcb_pmsm_foc_sensorless_f28069MLaunchPad_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
