/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_sensorless_f28069MLaunchPad.h
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
  real32_T acos_a;                     /* '<S52>/acos' */
  real32_T bsin;                       /* '<S52>/bsin' */
  real32_T sum_Ds;                     /* '<S52>/sum_Ds' */
  real32_T bcos;                       /* '<S52>/bcos' */
  real32_T asin_p;                     /* '<S52>/asin' */
  real32_T sum_Qs;                     /* '<S52>/sum_Qs' */
  real32_T Switch[2];                  /* '<S53>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} rtB_TwoinputsCRL_mcb_pmsm_foc_s;

/* Block signals for system '<S56>/If Action Subsystem' */
typedef struct {
  real32_T Convert_back;               /* '<S59>/Convert_back' */
  int16_T Convert_uint16;              /* '<S59>/Convert_uint16' */
} rtB_IfActionSubsystem_mcb_pmsm_;

/* Block signals for system '<S56>/If Action Subsystem1' */
typedef struct {
  real32_T Convert_back;               /* '<S60>/Convert_back' */
  int16_T Convert_uint16;              /* '<S60>/Convert_uint16' */
} rtB_IfActionSubsystem1_mcb_pmsm;

/* Block signals for system '<S272>/Dir_Sense' */
typedef struct {
  int16_T Switch;                      /* '<S280>/Switch' */
  boolean_T LogicalOperator;           /* '<S280>/Logical Operator' */
} rtB_Dir_Sense_mcb_pmsm_foc_sens;

/* Zero-crossing (trigger) state for system '<S272>/Dir_Sense' */
typedef struct {
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S272>/Dir_Sense' */
} rtZCE_Dir_Sense_mcb_pmsm_foc_se;

/* Block signals for system '<S311>/SPI Master Transfer' */
typedef struct {
  uint16_T SPIMasterTransfer;          /* '<S311>/SPI Master Transfer' */
} rtB_SPIMasterTransfer_mcb_pmsm_;

/* Block states (default storage) for system '<S311>/SPI Master Transfer' */
typedef struct {
  codertarget_tic2000_blocks_SPIM obj; /* '<S311>/SPI Master Transfer' */
  boolean_T objisempty;                /* '<S311>/SPI Master Transfer' */
} rtDW_SPIMasterTransfer_mcb_pmsm;

/* Block signals for system '<Root>/Speed Control' */
typedef struct {
  real32_T Iq_switch_mem;              /* '<S325>/Data Store Read3' */
  real32_T RateLimiter;                /* '<S326>/Rate Limiter' */
  real32_T RateLimiter1;               /* '<S326>/Rate Limiter1' */
  real32_T Switch;                     /* '<S326>/Switch' */
  real32_T Switch1[2];                 /* '<S329>/Switch1' */
  real32_T Product;                    /* '<S386>/Product' */
  real32_T UnitDelay;                  /* '<S386>/Unit Delay' */
  real32_T Product1;                   /* '<S386>/Product1' */
  real32_T Add1;                       /* '<S386>/Add1' */
  real32_T Sum;                        /* '<S325>/Sum' */
  real32_T Product_g;                  /* '<S325>/Product' */
  real32_T Sum1;                       /* '<S325>/Sum1' */
  real32_T I_q_ref;                    /* '<S325>/MATLAB Function' */
  boolean_T DataStoreRead1;            /* '<S325>/Data Store Read1' */
  boolean_T DataStoreRead2;            /* '<S325>/Data Store Read2' */
  boolean_T AND;                       /* '<S325>/AND' */
  boolean_T LogicalOperator;           /* '<S325>/Logical Operator' */
} rtB_SpeedControl_mcb_pmsm_foc_s;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S386>/Unit Delay' */
  real32_T PrevY;                      /* '<S326>/Rate Limiter' */
  real32_T PrevY_f;                    /* '<S326>/Rate Limiter1' */
  real32_T integrator_state;           /* '<S325>/MATLAB Function' */
} rtDW_SpeedControl_mcb_pmsm_foc_;

/* Block signals for system '<S388>/RunMode.ComputeId0' */
typedef struct {
  real32_T Sum;                        /* '<S407>/Sum' */
  real32_T Switch;                     /* '<S407>/Switch' */
  boolean_T Compare;                   /* '<S408>/Compare' */
} rtB_RunModeComputeId0_mcb_pmsm_;

/* Block signals (default storage) */
typedef struct {
  real_T Product;                      /* '<S17>/Product' */
  real_T Add;                          /* '<S17>/Add' */
  real_T Product1;                     /* '<S17>/Product1' */
  real_T Add1;                         /* '<S17>/Add1' */
  real_T qcos;                         /* '<S48>/qcos' */
  real_T dsin;                         /* '<S48>/dsin' */
  real_T sum_beta;                     /* '<S48>/sum_beta' */
  real_T dcos;                         /* '<S48>/dcos' */
  real_T qsin;                         /* '<S48>/qsin' */
  real_T sum_alpha;                    /* '<S48>/sum_alpha' */
  real_T Unary_Minus;                  /* '<S49>/Unary_Minus' */
  uint32_T Sum[4];                     /* '<S397>/Sum' */
  uint32_T Sum_k[4];                   /* '<S54>/Sum' */
  uint32_T DataTypeConversion;         /* '<S109>/Data Type Conversion' */
  uint32_T Sum_j[4];                   /* '<S224>/Sum' */
  uint32_T PositionToCount;            /* '<S235>/PositionToCount' */
  uint32_T Delay;                      /* '<S235>/Delay' */
  uint32_T PositionToCount_i;          /* '<S278>/PositionToCount' */
  uint32_T Delay_l;                    /* '<S278>/Delay' */
  real32_T SpdCmd;                     /* '<S8>/RT6' */
  real32_T UnitDelay;                  /* '<S8>/Unit Delay' */
  real32_T RT6;                        /* '<Root>/RT6' */
  real32_T RT4;                        /* '<Root>/RT4' */
  real32_T RT2[2];                     /* '<Root>/RT2' */
  real32_T SpdRef;                     /* '<S8>/State Machine OL - CL' */
  real32_T Id0_out;                    /* '<S8>/State Machine OL - CL' */
  real32_T Id0_in;                     /* '<S8>/State Machine OL - CL' */
  real32_T RAMP_STEP_SIZE;             /* '<S8>/State Machine OL - CL' */
  real32_T DataStoreRead3;             /* '<S387>/Data Store Read3' */
  real32_T DataStoreRead1;             /* '<S387>/Data Store Read1' */
  real32_T DataStoreRead2;             /* '<S387>/Data Store Read2' */
  real32_T Merge;                      /* '<S399>/Merge' */
  real32_T indexing;                   /* '<S397>/indexing' */
  real32_T Lookup[4];                  /* '<S397>/Lookup' */
  real32_T Sum3;                       /* '<S398>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S397>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S397>/Sum2' */
  real32_T Product_b;                  /* '<S398>/Product' */
  real32_T Sum4;                       /* '<S398>/Sum4' */
  real32_T Sum5;                       /* '<S398>/Sum5' */
  real32_T Product1_a;                 /* '<S398>/Product1' */
  real32_T Sum6;                       /* '<S398>/Sum6' */
  real32_T DataStoreRead;              /* '<S387>/Data Store Read' */
  real32_T DataStoreRead4;             /* '<S387>/Data Store Read4' */
  real32_T DataTypeConversion1_a[2];   /* '<S322>/Data Type Conversion1' */
  real32_T Speed_Ref;                  /* '<S6>/Data Type Conversion1' */
  real32_T DataTypeConversion1_p[2];   /* '<S77>/Data Type Conversion1' */
  real32_T Delay5[4];                  /* '<S1>/Delay5' */
  real32_T Merge_k[2];                 /* '<S78>/Merge' */
  real32_T Spd_Pos;                    /* '<S19>/Data Store Read' */
  real32_T Gain;                       /* '<S19>/Gain' */
  real32_T Delay_g;                    /* '<S19>/Delay' */
  real32_T Add_g;                      /* '<S50>/Add' */
  real32_T DataTypeConversion1_d;      /* '<S50>/Data Type Conversion1' */
  real32_T Add1_f;                     /* '<S50>/Add1' */
  real32_T Switch;                     /* '<S19>/Switch' */
  real32_T Merge_c;                    /* '<S56>/Merge' */
  real32_T indexing_d;                 /* '<S54>/indexing' */
  real32_T Lookup_f[4];                /* '<S54>/Lookup' */
  real32_T Sum3_b;                     /* '<S55>/Sum3' */
  real32_T DataTypeConversion1_c;      /* '<S54>/Data Type Conversion1' */
  real32_T Sum2_e;                     /* '<S54>/Sum2' */
  real32_T Product_g;                  /* '<S55>/Product' */
  real32_T Sum4_h;                     /* '<S55>/Sum4' */
  real32_T Sum5_l;                     /* '<S55>/Sum5' */
  real32_T Product1_e;                 /* '<S55>/Product1' */
  real32_T Sum6_c;                     /* '<S55>/Sum6' */
  real32_T Sum_m;                      /* '<S27>/Sum' */
  real32_T Vq_computed;                /* '<S27>/Vq_computed1' */
  real32_T Product_bk;                 /* '<S27>/Product' */
  real32_T Sum1;                       /* '<S27>/Sum1' */
  real32_T Switch_j;                   /* '<S27>/Switch' */
  real32_T Sum_g;                      /* '<S26>/Sum' */
  real32_T Vd_computed1;               /* '<S26>/Vd_computed1' */
  real32_T Product_e;                  /* '<S26>/Product' */
  real32_T Sum1_a;                     /* '<S26>/Sum1' */
  real32_T Vd_OpenLoop;                /* '<S26>/Vd_OpenLoop' */
  real32_T Abs;                        /* '<S26>/Abs' */
  real32_T Switch1[2];                 /* '<S42>/Switch1' */
  real32_T Product_bh;                 /* '<S46>/Product' */
  real32_T UnitDelay_n;                /* '<S46>/Unit Delay' */
  real32_T Product1_p;                 /* '<S46>/Product1' */
  real32_T Add1_l;                     /* '<S46>/Add1' */
  real32_T Switch_d;                   /* '<S26>/Switch' */
  real32_T Switch_jv;                  /* '<S30>/Switch' */
  real32_T Product_l;                  /* '<S30>/Product' */
  real32_T Product_o;                  /* '<S31>/Product' */
  real32_T Product1_ad;                /* '<S31>/Product1' */
  real32_T Sum1_e;                     /* '<S31>/Sum1' */
  real32_T Merge_m[2];                 /* '<S25>/Merge' */
  real32_T DataTypeConversion_c;       /* '<S14>/Data Type Conversion' */
  real32_T Speed_fb_PU;                /* '<S1>/Input Scaling' */
  real32_T TmpSignalConversionAtDelay5Inpo[4];
  real32_T sqrt3_by_two;               /* '<S68>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S68>/one_by_two' */
  real32_T add_c;                      /* '<S68>/add_c' */
  real32_T add_b;                      /* '<S68>/add_b' */
  real32_T Min;                        /* '<S65>/Min' */
  real32_T Max;                        /* '<S65>/Max' */
  real32_T Add_i;                      /* '<S65>/Add' */
  real32_T one_by_two_d;               /* '<S65>/one_by_two' */
  real32_T Add3;                       /* '<S64>/Add3' */
  real32_T Add2;                       /* '<S64>/Add2' */
  real32_T Add1_b;                     /* '<S64>/Add1' */
  real32_T Gain_c[3];                  /* '<S64>/Gain' */
  real32_T Gain_c1[3];                 /* '<S14>/Gain' */
  real32_T PWM_Duty_Cycles[3];         /* '<S14>/Sum' */
  real32_T Delay1;                     /* '<S82>/Delay1' */
  real32_T Delay_f[2];                 /* '<S83>/Delay' */
  real32_T Gain_m;                     /* '<S88>/Gain' */
  real32_T UnaryMinus;                 /* '<S96>/Unary Minus' */
  real32_T Product1_f;                 /* '<S85>/Product1' */
  real32_T Gain1;                      /* '<S95>/Gain1' */
  real32_T Product2;                   /* '<S96>/Product2' */
  real32_T Product_k;                  /* '<S85>/Product' */
  real32_T Gain_n;                     /* '<S95>/Gain' */
  real32_T Product_i;                  /* '<S96>/Product' */
  real32_T Sum_mr;                     /* '<S96>/Sum' */
  real32_T Product1_ao;                /* '<S96>/Product1' */
  real32_T Product3;                   /* '<S96>/Product3' */
  real32_T Sum1_m;                     /* '<S96>/Sum1' */
  real32_T Product3_n;                 /* '<S85>/Product3' */
  real32_T Product1_o;                 /* '<S92>/Product1' */
  real32_T Product2_c;                 /* '<S85>/Product2' */
  real32_T Gain_g;                     /* '<S87>/Gain' */
  real32_T Product3_n0;                /* '<S92>/Product3' */
  real32_T Sum1_c;                     /* '<S92>/Sum1' */
  real32_T Product1_h;                 /* '<S91>/Product1' */
  real32_T UnaryMinus_k;               /* '<S91>/Unary Minus' */
  real32_T UnaryMinus_f;               /* '<S92>/Unary Minus' */
  real32_T Product2_a;                 /* '<S92>/Product2' */
  real32_T Product_gf;                 /* '<S92>/Product' */
  real32_T Sum_i;                      /* '<S92>/Sum' */
  real32_T Product_kc;                 /* '<S91>/Product' */
  real32_T UnaryMinus_fm;              /* '<S93>/Unary Minus' */
  real32_T Gain1_o;                    /* '<S90>/Gain1' */
  real32_T UnaryMinus1;                /* '<S90>/Unary Minus1' */
  real32_T Product2_d;                 /* '<S93>/Product2' */
  real32_T Gain_j;                     /* '<S90>/Gain' */
  real32_T UnaryMinus_i;               /* '<S90>/Unary Minus' */
  real32_T Product_f;                  /* '<S93>/Product' */
  real32_T Sum_e;                      /* '<S93>/Sum' */
  real32_T Product1_oz;                /* '<S93>/Product1' */
  real32_T Product3_nb;                /* '<S93>/Product3' */
  real32_T Sum1_k;                     /* '<S93>/Sum1' */
  real32_T UnaryMinus_j;               /* '<S94>/Unary Minus' */
  real32_T Product_n;                  /* '<S89>/Product' */
  real32_T Product3_c;                 /* '<S89>/Product3' */
  real32_T UnaryMinus1_b;              /* '<S89>/Unary Minus1' */
  real32_T Product5;                   /* '<S89>/Product5' */
  real32_T Sum1_i;                     /* '<S89>/Sum1' */
  real32_T Product2_o;                 /* '<S94>/Product2' */
  real32_T Product4;                   /* '<S89>/Product4' */
  real32_T Product1_b;                 /* '<S89>/Product1' */
  real32_T UnaryMinus_g;               /* '<S89>/Unary Minus' */
  real32_T Product2_f;                 /* '<S89>/Product2' */
  real32_T Sum_kn;                     /* '<S89>/Sum' */
  real32_T Product_gf3;                /* '<S94>/Product' */
  real32_T Sum_h;                      /* '<S94>/Sum' */
  real32_T Product1_d;                 /* '<S94>/Product1' */
  real32_T Product3_g;                 /* '<S94>/Product3' */
  real32_T Sum1_j;                     /* '<S94>/Sum1' */
  real32_T Sum_l[2];                   /* '<S87>/Sum' */
  real32_T Sum_n[2];                   /* '<S83>/Sum' */
  real32_T Gain1_c[2];                 /* '<S83>/Gain1' */
  real32_T Sum2_o[2];                  /* '<S83>/Sum2' */
  real32_T Gain2[2];                   /* '<S83>/Gain2' */
  real32_T Sum1_j4[2];                 /* '<S83>/Sum1' */
  real32_T Product_m[2];               /* '<S82>/Product' */
  real32_T Switch1_g[2];               /* '<S84>/Switch1' */
  real32_T Product_j[2];               /* '<S99>/Product' */
  real32_T UnitDelay_j[2];             /* '<S99>/Unit Delay' */
  real32_T Product1_ee[2];             /* '<S99>/Product1' */
  real32_T Add1_j[2];                  /* '<S99>/Add1' */
  real32_T Merge_k4;                   /* '<S100>/Merge' */
  real32_T Merge1;                     /* '<S100>/Merge1' */
  real32_T Merge_o[2];                 /* '<S109>/Merge' */
  real32_T Product_nv;                 /* '<S106>/Product' */
  real32_T Product1_n;                 /* '<S106>/Product1' */
  real32_T Sum_e2;                     /* '<S106>/Sum' */
  real32_T Merge_f;                    /* '<S106>/Merge' */
  real32_T Merge1_o;                   /* '<S106>/Merge1' */
  real32_T Merge_i;                    /* '<S108>/Merge' */
  real32_T Switch1_n[2];               /* '<S170>/Switch1' */
  real32_T Product_gh;                 /* '<S195>/Product' */
  real32_T UnitDelay_c;                /* '<S195>/Unit Delay' */
  real32_T Product1_l;                 /* '<S195>/Product1' */
  real32_T Add1_g;                     /* '<S195>/Add1' */
  real32_T Delay_j;                    /* '<S219>/Delay' */
  real32_T Merge_g;                    /* '<S226>/Merge' */
  real32_T indexing_i;                 /* '<S224>/indexing' */
  real32_T Lookup_m[4];                /* '<S224>/Lookup' */
  real32_T Sum5_i;                     /* '<S225>/Sum5' */
  real32_T DataTypeConversion1_d2;     /* '<S224>/Data Type Conversion1' */
  real32_T Sum2_eo;                    /* '<S224>/Sum2' */
  real32_T Product1_nl;                /* '<S225>/Product1' */
  real32_T Sum6_m;                     /* '<S225>/Sum6' */
  real32_T Product_la;                 /* '<S101>/Product' */
  real32_T Sum3_n;                     /* '<S225>/Sum3' */
  real32_T Product_a;                  /* '<S225>/Product' */
  real32_T Sum4_p;                     /* '<S225>/Sum4' */
  real32_T Product1_dd;                /* '<S101>/Product1' */
  real32_T Sum_b;                      /* '<S101>/Sum' */
  real32_T ProportionalGain;           /* '<S156>/Proportional Gain' */
  real32_T IntegralGain;               /* '<S148>/Integral Gain' */
  real32_T Integrator;                 /* '<S151>/Integrator' */
  real32_T Sum_d;                      /* '<S160>/Sum' */
  real32_T speed;                      /* '<S101>/Sum1' */
  real32_T Switch1_e[2];               /* '<S105>/Switch1' */
  real32_T Product_iq;                 /* '<S113>/Product' */
  real32_T UnitDelay_i;                /* '<S113>/Unit Delay' */
  real32_T Product1_ok;                /* '<S113>/Product1' */
  real32_T Add1_h;                     /* '<S113>/Add1' */
  real32_T Gain_l;                     /* '<S219>/Gain' */
  real32_T UnitDelay_o;                /* '<S220>/Unit Delay' */
  real32_T Add_gq;                     /* '<S222>/Add' */
  real32_T DataTypeConversion1_l;      /* '<S222>/Data Type Conversion1' */
  real32_T Add1_k;                     /* '<S222>/Add1' */
  real32_T Input;                      /* '<S223>/Input' */
  real32_T In1;                        /* '<S216>/In1' */
  real32_T Delay2;                     /* '<S206>/Delay2' */
  real32_T Delay3;                     /* '<S206>/Delay3' */
  real32_T Switch1_j[2];               /* '<S209>/Switch1' */
  real32_T Product_ex;                 /* '<S215>/Product' */
  real32_T UnitDelay_d;                /* '<S215>/Unit Delay' */
  real32_T Product1_dx;                /* '<S215>/Product1' */
  real32_T Add1_fb;                    /* '<S215>/Add1' */
  real32_T Gain_b;                     /* '<S206>/Gain' */
  real32_T Sum1_n;                     /* '<S206>/Sum1' */
  real32_T Gain1_n;                    /* '<S206>/Gain1' */
  real32_T Delay2_i;                   /* '<S207>/Delay2' */
  real32_T Delay3_a;                   /* '<S207>/Delay3' */
  real32_T Switch1_f[2];               /* '<S208>/Switch1' */
  real32_T Product_k3;                 /* '<S212>/Product' */
  real32_T UnitDelay_iy;               /* '<S212>/Unit Delay' */
  real32_T Product1_c;                 /* '<S212>/Product1' */
  real32_T Add1_c;                     /* '<S212>/Add1' */
  real32_T Gain_m4;                    /* '<S207>/Gain' */
  real32_T Sum1_ci;                    /* '<S207>/Sum1' */
  real32_T Gain1_l;                    /* '<S207>/Gain1' */
  real32_T Product_kg;                 /* '<S172>/Product' */
  real32_T Product1_pv;                /* '<S172>/Product1' */
  real32_T Switch1_d[2];               /* '<S197>/Switch1' */
  real32_T Product_fd;                 /* '<S205>/Product' */
  real32_T UnitDelay_ju;               /* '<S205>/Unit Delay' */
  real32_T Product1_dq;                /* '<S205>/Product1' */
  real32_T Add1_d;                     /* '<S205>/Add1' */
  real32_T Delay1_i;                   /* '<S198>/Delay1' */
  real32_T Sum_mt;                     /* '<S198>/Sum' */
  real32_T Gain1_g;                    /* '<S198>/Gain1' */
  real32_T Delay_d;                    /* '<S198>/Delay' */
  real32_T Gain2_i;                    /* '<S198>/Gain2' */
  real32_T Sum1_a0;                    /* '<S198>/Sum1' */
  real32_T Product_j2;                 /* '<S171>/Product' */
  real32_T Switch1_n2[2];              /* '<S196>/Switch1' */
  real32_T Product_p;                  /* '<S202>/Product' */
  real32_T UnitDelay_id;               /* '<S202>/Unit Delay' */
  real32_T Product1_p0;                /* '<S202>/Product1' */
  real32_T Add1_c4;                    /* '<S202>/Add1' */
  real32_T Delay1_p;                   /* '<S199>/Delay1' */
  real32_T Sum_mq;                     /* '<S199>/Sum' */
  real32_T Gain1_ng;                   /* '<S199>/Gain1' */
  real32_T Delay_o;                    /* '<S199>/Delay' */
  real32_T Gain2_o;                    /* '<S199>/Gain2' */
  real32_T Sum1_h;                     /* '<S199>/Sum1' */
  real32_T Product1_ap;                /* '<S171>/Product1' */
  real32_T Sum_o;                      /* '<S171>/Sum' */
  real32_T MathFunction;               /* '<S171>/Math Function' */
  real32_T Abs_k;                      /* '<S171>/Abs' */
  real32_T Delay2_m;                   /* '<S173>/Delay2' */
  real32_T Delay3_d;                   /* '<S173>/Delay3' */
  real32_T Switch1_i[2];               /* '<S177>/Switch1' */
  real32_T Product_ke;                 /* '<S187>/Product' */
  real32_T UnitDelay_p;                /* '<S187>/Unit Delay' */
  real32_T Product1_o1;                /* '<S187>/Product1' */
  real32_T Add1_m;                     /* '<S187>/Add1' */
  real32_T Gain_gx;                    /* '<S173>/Gain' */
  real32_T Sum1_ag;                    /* '<S173>/Sum1' */
  real32_T Gain1_gr;                   /* '<S173>/Gain1' */
  real32_T Delay2_e;                   /* '<S174>/Delay2' */
  real32_T Delay3_m;                   /* '<S174>/Delay3' */
  real32_T Switch1_b[2];               /* '<S175>/Switch1' */
  real32_T Product_j5;                 /* '<S181>/Product' */
  real32_T UnitDelay_m;                /* '<S181>/Unit Delay' */
  real32_T Product1_br;                /* '<S181>/Product1' */
  real32_T Add1_o;                     /* '<S181>/Add1' */
  real32_T Gain_gp;                    /* '<S174>/Gain' */
  real32_T Sum1_ed;                    /* '<S174>/Sum1' */
  real32_T Gain1_p;                    /* '<S174>/Gain1' */
  real32_T Delay_f1;                   /* '<S178>/Delay' */
  real32_T Delay1_m;                   /* '<S178>/Delay1' */
  real32_T Switch1_fq;                 /* '<S178>/Switch1' */
  real32_T Switch1_a[2];               /* '<S176>/Switch1' */
  real32_T Product_md;                 /* '<S184>/Product' */
  real32_T UnitDelay_pm;               /* '<S184>/Unit Delay' */
  real32_T Product1_cn;                /* '<S184>/Product1' */
  real32_T Add1_fo;                    /* '<S184>/Add1' */
  real32_T Square;                     /* '<S169>/Square' */
  real32_T Square1;                    /* '<S169>/Square1' */
  real32_T Sum2_k;                     /* '<S169>/Sum2' */
  real32_T Sqrt;                       /* '<S169>/Sqrt' */
  real32_T UnaryMinus_b;               /* '<S169>/Unary Minus' */
  real32_T Sum_ji;                     /* '<S178>/Sum' */
  real32_T Sqrt_g;                     /* '<S116>/Sqrt' */
  real32_T Divide;                     /* '<S116>/Divide' */
  real32_T Divide1;                    /* '<S116>/Divide1' */
  real32_T Switch1_dz[2];              /* '<S236>/Switch1' */
  real32_T Product_am[4];              /* '<S239>/Product' */
  real32_T UnitDelay_a[4];             /* '<S239>/Unit Delay' */
  real32_T Product1_j[4];              /* '<S239>/Product1' */
  real32_T Add1_jy[4];                 /* '<S239>/Add1' */
  real32_T Sum_bf[4];                  /* '<S238>/Sum' */
  real32_T Product_c;                  /* '<S262>/Product' */
  real32_T Sum3_k;                     /* '<S259>/Sum3' */
  real32_T Delay1_pl;                  /* '<S261>/Delay1' */
  real32_T Sum_jy;                     /* '<S261>/Sum' */
  real32_T Product_d;                  /* '<S261>/Product' */
  real32_T Delay_p;                    /* '<S261>/Delay' */
  real32_T Product1_n5;                /* '<S261>/Product1' */
  real32_T Sum1_em;                    /* '<S261>/Sum1' */
  real32_T Product2_i;                 /* '<S262>/Product2' */
  real32_T Sum1_p;                     /* '<S259>/Sum1' */
  real32_T Sum_p;                      /* '<S260>/Sum' */
  real32_T Switch1_eg[2];              /* '<S260>/Switch1' */
  real32_T Product_fdo;                /* '<S265>/Product' */
  real32_T UnitDelay_dy;               /* '<S265>/Unit Delay' */
  real32_T Product1_k;                 /* '<S265>/Product1' */
  real32_T Add1_jx;                    /* '<S265>/Add1' */
  real32_T Switch_g;                   /* '<S258>/Switch' */
  real32_T Product_iw;                 /* '<S254>/Product' */
  real32_T Sum3_n0;                    /* '<S251>/Sum3' */
  real32_T Delay1_a;                   /* '<S253>/Delay1' */
  real32_T Sum_ga;                     /* '<S253>/Sum' */
  real32_T Product_n3;                 /* '<S253>/Product' */
  real32_T Delay_b;                    /* '<S253>/Delay' */
  real32_T Product1_g;                 /* '<S253>/Product1' */
  real32_T Sum1_mn;                    /* '<S253>/Sum1' */
  real32_T Product2_b;                 /* '<S254>/Product2' */
  real32_T Sum1_as;                    /* '<S251>/Sum1' */
  real32_T Sum_a;                      /* '<S252>/Sum' */
  real32_T Switch1_o[2];               /* '<S252>/Switch1' */
  real32_T Product_lm;                 /* '<S257>/Product' */
  real32_T UnitDelay_e;                /* '<S257>/Unit Delay' */
  real32_T Product1_ba;                /* '<S257>/Product1' */
  real32_T Add1_i;                     /* '<S257>/Add1' */
  real32_T Switch_h;                   /* '<S250>/Switch' */
  real32_T DTC;                        /* '<S270>/DTC' */
  real32_T SpeedGain;                  /* '<S235>/SpeedGain' */
  real32_T Switch1_bs[2];              /* '<S234>/Switch1' */
  real32_T Product_pk;                 /* '<S268>/Product' */
  real32_T UnitDelay_dk;               /* '<S268>/Unit Delay' */
  real32_T Product1_al;                /* '<S268>/Product1' */
  real32_T Add1_p;                     /* '<S268>/Add1' */
  real32_T elect2mech;                 /* '<S80>/elect2mech' */
  real32_T Sum_dj;                     /* '<S264>/Sum' */
  real32_T Sum_ac;                     /* '<S256>/Sum' */
  real32_T Atan2;                      /* '<S248>/Atan2' */
  real32_T Switch_ds;                  /* '<S248>/Switch' */
  real32_T algDD;
  real32_T Gain_f;                     /* '<S249>/Gain' */
  real32_T Switch_c;                   /* '<S249>/Switch' */
  real32_T Bias;                       /* '<S249>/Bias' */
  real32_T UnitDelay1;                 /* '<S283>/Unit Delay1' */
  real32_T UnitDelay_g;                /* '<S283>/Unit Delay' */
  real32_T a;                          /* '<S283>/a' */
  real32_T Delay_k;                    /* '<S273>/Delay' */
  real32_T Sum2_g;                     /* '<S273>/Sum2' */
  real32_T Sum3_m;                     /* '<S283>/Sum3' */
  real32_T b_invg;                     /* '<S283>/b_inv*g' */
  real32_T Delay1_e;                   /* '<S283>/Delay1' */
  real32_T Sum4_b;                     /* '<S283>/Sum4' */
  real32_T Switch1_jq[2];              /* '<S275>/Switch1' */
  real32_T Product_c0;                 /* '<S287>/Product' */
  real32_T UnitDelay_ab;               /* '<S287>/Unit Delay' */
  real32_T Product1_en;                /* '<S287>/Product1' */
  real32_T Add1_dd;                    /* '<S287>/Add1' */
  real32_T UnitDelay1_k;               /* '<S284>/Unit Delay1' */
  real32_T UnitDelay_k;                /* '<S284>/Unit Delay' */
  real32_T a_e;                        /* '<S284>/a' */
  real32_T Delay_i;                    /* '<S274>/Delay' */
  real32_T Sum2_g2;                    /* '<S274>/Sum2' */
  real32_T Sum3_l;                     /* '<S284>/Sum3' */
  real32_T b_invg_o;                   /* '<S284>/b_inv*g' */
  real32_T Delay1_f;                   /* '<S284>/Delay1' */
  real32_T Sum4_m;                     /* '<S284>/Sum4' */
  real32_T Switch1_m[2];               /* '<S276>/Switch1' */
  real32_T Product_p3;                 /* '<S290>/Product' */
  real32_T UnitDelay_gx;               /* '<S290>/Unit Delay' */
  real32_T Product1_k4;                /* '<S290>/Product1' */
  real32_T Add1_gu;                    /* '<S290>/Add1' */
  real32_T Merge_ku;                   /* '<S272>/Merge' */
  real32_T Merge1_i;                   /* '<S272>/Merge1' */
  real32_T Delay_e;                    /* '<S271>/Delay' */
  real32_T Sign;                       /* '<S273>/Sign' */
  real32_T Eta;                        /* '<S273>/Eta' */
  real32_T Sum_gf;                     /* '<S273>/Sum' */
  real32_T b;                          /* '<S273>/b' */
  real32_T a_a;                        /* '<S273>/a' */
  real32_T Sum1_d;                     /* '<S273>/Sum1' */
  real32_T Sign_m;                     /* '<S274>/Sign' */
  real32_T Eta_n;                      /* '<S274>/Eta' */
  real32_T Sum_bl;                     /* '<S274>/Sum' */
  real32_T b_i;                        /* '<S274>/b' */
  real32_T a_p;                        /* '<S274>/a' */
  real32_T Sum1_g;                     /* '<S274>/Sum1' */
  real32_T DTC_e;                      /* '<S295>/DTC' */
  real32_T SpeedGain_k;                /* '<S278>/SpeedGain' */
  real32_T Switch1_bp[2];              /* '<S277>/Switch1' */
  real32_T Product_i2;                 /* '<S293>/Product' */
  real32_T UnitDelay_ci;               /* '<S293>/Unit Delay' */
  real32_T Product1_ey;                /* '<S293>/Product1' */
  real32_T Add1_cr;                    /* '<S293>/Add1' */
  real32_T Product_jt;                 /* '<S279>/Product' */
  real32_T Product2_il;                /* '<S279>/Product2' */
  real32_T Sum1_mc;                    /* '<S279>/Sum1' */
  real32_T Product1_m;                 /* '<S279>/Product1' */
  real32_T Product3_b;                 /* '<S279>/Product3' */
  real32_T Sum2_p;                     /* '<S279>/Sum2' */
  real32_T Switch_cx;                  /* '<S279>/Switch' */
  real32_T Atan2_n;                    /* '<S296>/Atan2' */
  real32_T Switch_gb;                  /* '<S296>/Switch' */
  real32_T algDD_a;
  real32_T Gain_o;                     /* '<S297>/Gain' */
  real32_T Switch_m;                   /* '<S297>/Switch' */
  real32_T Bias_f;                     /* '<S297>/Bias' */
  real32_T Bias_j;                     /* '<S279>/Bias' */
  real32_T Input_h;                    /* '<S51>/Input' */
  real32_T Switch_f[2];                /* '<S49>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T V_q_ref;                    /* '<S27>/MATLAB Function' */
  real32_T Saturation;                 /* '<S26>/Saturation' */
  real32_T V_d_ref;                    /* '<S26>/MATLAB Function' */
  real32_T Product_ch[2];              /* '<S32>/Product' */
  real32_T SquareRoot;                 /* '<S32>/Square Root' */
  real32_T Switch_o;                   /* '<S32>/Switch' */
  real32_T Switch_i[2];                /* '<S29>/Switch' */
  real32_T Switch2;                    /* '<S39>/Switch2' */
  real32_T Product_bp;                 /* '<S38>/Product' */
  real32_T Sum_a3;                     /* '<S38>/Sum' */
  real32_T Product2_ao;                /* '<S38>/Product2' */
  real32_T Merge_e;                    /* '<S38>/Merge' */
  real32_T Gain_lx;                    /* '<S38>/Gain' */
  real32_T Switch_k;                   /* '<S39>/Switch' */
  real32_T Switch1_h;                  /* '<S40>/Switch1' */
  real32_T Sqrt_n;                     /* '<S40>/Sqrt' */
  real32_T Gain_e;                     /* '<S40>/Gain' */
  int32_T DataTypeConversion_ch[2];    /* '<S77>/Data Type Conversion' */
  int32_T Add_k[2];                    /* '<S77>/Add' */
  int32_T Q17perunitconversion[2];     /* '<S77>/Q17 per unit conversion' */
  int32_T SpeedCount;                  /* '<S235>/SpeedCount' */
  int32_T SpeedCount_c;                /* '<S278>/SpeedCount' */
  uint16_T DataTypeConversion_b;       /* '<S399>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S397>/Get_Integer' */
  uint16_T Divide_h;                   /* '<S310>/Divide' */
  uint16_T Divide1_e;                  /* '<S310>/Divide1' */
  uint16_T ForIterator;                /* '<S313>/For Iterator' */
  uint16_T IAIBMeasurement[2];         /* '<S313>/IA//IB Measurement' */
  uint16_T Memory;                     /* '<S318>/Memory' */
  uint16_T Sum_dn;                     /* '<S318>/Sum' */
  uint16_T Memory1;                    /* '<S318>/Memory1' */
  uint16_T Sum1_dq;                    /* '<S318>/Sum1' */
  uint16_T SCIReceive[2];              /* '<S324>/SCI Receive' */
  uint16_T DataStoreRead_m;            /* '<S77>/Data Store Read' */
  uint16_T DataStoreRead1_p;           /* '<S77>/Data Store Read1' */
  uint16_T IAIBMeasurement_k[2];       /* '<S76>/IA//IB Measurement' */
  uint16_T Switch1_fg;                 /* '<S30>/Switch1' */
  uint16_T DataTypeConversion_e;       /* '<S56>/Data Type Conversion' */
  uint16_T Get_Integer_i;              /* '<S54>/Get_Integer' */
  uint16_T Output;                     /* '<S69>/Output' */
  uint16_T DataTypeConversion3[2];     /* '<S71>/Data Type Conversion3' */
  uint16_T SCI_Tx_Data[3];             /* '<S10>/Merge' */
  uint16_T SCI_Tx_Iteration;           /* '<S10>/Merge1' */
  uint16_T FixPtSum1;                  /* '<S74>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S75>/FixPt Switch' */
  uint16_T Switch1_c[3];               /* '<S298>/Switch1' */
  uint16_T IndexVector;                /* '<S300>/Index Vector' */
  uint16_T Add_m;                      /* '<S300>/Add' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S298>/Scale_to_PWM_Counter_PRD' */
  uint16_T DataTypeConversion_n;       /* '<S226>/Data Type Conversion' */
  uint16_T Get_Integer_m;              /* '<S224>/Get_Integer' */
  uint16_T Data[2];                    /* '<S70>/Data' */
  uint16_T Data_f[2];                  /* '<S72>/Data' */
  uint16_T Data_fw[2];                 /* '<S73>/Data' */
  uint16_T DataTypeConversion_k;       /* '<S28>/Data Type Conversion' */
  uint16_T DataTypeConversion_a;       /* '<S38>/Data Type Conversion' */
  int16_T DataTypeConversion2[2];      /* '<S322>/Data Type Conversion2' */
  int16_T DataTypeConversion_l[2];     /* '<S71>/Data Type Conversion' */
  int16_T DataTypeConversion_ey;       /* '<S50>/Data Type Conversion' */
  int16_T WhileIterator;               /* '<S300>/While Iterator' */
  int16_T DataTypeConversion_h;        /* '<S222>/Data Type Conversion' */
  boolean_T RT5;                       /* '<S8>/RT5' */
  boolean_T NOT;                       /* '<S8>/NOT' */
  boolean_T Enable;                    /* '<S8>/State Machine OL - CL' */
  boolean_T EnClosedLoop;              /* '<S8>/State Machine OL - CL' */
  boolean_T Compare;                   /* '<S401>/Compare' */
  boolean_T NOT_h;                     /* '<S309>/NOT' */
  boolean_T DataTypeConversion3_b;     /* '<S6>/Data Type Conversion3' */
  boolean_T DataStoreRead1_n;          /* '<S19>/Data Store Read1' */
  boolean_T Delay_kh;                  /* '<S50>/Delay' */
  boolean_T DataStoreRead2_m;          /* '<S19>/Data Store Read2' */
  boolean_T Compare_d;                 /* '<S58>/Compare' */
  boolean_T DataStoreRead1_b;          /* '<S27>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S27>/Logical Operator' */
  boolean_T DataStoreRead1_f;          /* '<S26>/Data Store Read1' */
  boolean_T LogicalOperator_e;         /* '<S26>/Logical Operator' */
  boolean_T Enable_l;                  /* '<S14>/Enable' */
  boolean_T DataStoreRead1_g;          /* '<S79>/Data Store Read1' */
  boolean_T LogicalOperator_l;         /* '<S79>/Logical Operator' */
  boolean_T AlphaRelay;                /* '<S100>/AlphaRelay' */
  boolean_T BetaRelay;                 /* '<S100>/BetaRelay' */
  boolean_T Compare_j;                 /* '<S114>/Compare' */
  boolean_T Compare_k;                 /* '<S228>/Compare' */
  boolean_T NOT_hg;                    /* '<S220>/NOT' */
  boolean_T Delay_bv;                  /* '<S222>/Delay' */
  boolean_T Compare_n;                 /* '<S189>/Compare' */
  boolean_T Compare_kj;                /* '<S191>/Compare' */
  boolean_T Compare_o;                 /* '<S188>/Compare' */
  boolean_T LogicalOperator1;          /* '<S178>/Logical Operator1' */
  boolean_T Compare_d4;                /* '<S192>/Compare' */
  boolean_T LogicalOperator2;          /* '<S178>/Logical Operator2' */
  boolean_T AND;                       /* '<S178>/AND' */
  boolean_T UnitDelay_cp;              /* '<S178>/Unit Delay' */
  boolean_T Switch_l;                  /* '<S178>/Switch' */
  boolean_T Compare_c;                 /* '<S190>/Compare' */
  boolean_T LogicalOperator_k;         /* '<S178>/Logical Operator' */
  boolean_T DataStoreRead1_c;          /* '<S80>/Data Store Read1' */
  boolean_T LogicalOperator_ed;        /* '<S80>/Logical Operator' */
  boolean_T DataStoreRead1_i;          /* '<S81>/Data Store Read1' */
  boolean_T LogicalOperator_i;         /* '<S81>/Logical Operator' */
  boolean_T AlphaRelay_p;              /* '<S272>/AlphaRelay' */
  boolean_T BetaRelay_j;               /* '<S272>/BetaRelay' */
  boolean_T RelationalOperator;        /* '<S28>/Relational Operator' */
  boolean_T Compare_n2;                /* '<S34>/Compare' */
  boolean_T Compare_m;                 /* '<S35>/Compare' */
  boolean_T LowerRelop1;               /* '<S39>/LowerRelop1' */
  boolean_T RelationalOperator_c;      /* '<S38>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S39>/UpperRelop' */
  rtB_RunModeComputeId0_mcb_pmsm_ RunModeComputeId0;/* '<S388>/RunMode.ComputeId0' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_s TwoinputsCRL_j;/* '<S392>/Two inputs CRL' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1_b;/* '<S399>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem_ey;/* '<S399>/If Action Subsystem' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_s TwoinputsCRL_c;/* '<S390>/Two inputs CRL' */
  rtB_TwophaseCRLwrap_mcb_pmsm_fo TwophaseCRLwrap_b;/* '<S393>/Two phase CRL wrap' */
  rtB_SpeedControl_mcb_pmsm_foc_s SpeedControl;/* '<Root>/Speed Control' */
  rtB_SPIMasterTransfer_mcb_pmsm_ SPIMasterTransfer1;/* '<S311>/SPI Master Transfer' */
  rtB_SPIMasterTransfer_mcb_pmsm_ SPIMasterTransfer;/* '<S311>/SPI Master Transfer' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1_o;/* '<S226>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem_e;/* '<S226>/If Action Subsystem' */
  rtB_Dir_Sense_mcb_pmsm_foc_sens Dir_Sense_m;/* '<S100>/Dir_Sense' */
  rtB_Dir_Sense_mcb_pmsm_foc_sens Dir_Sense;/* '<S272>/Dir_Sense' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1;/* '<S56>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem;/* '<S56>/If Action Subsystem' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_s TwoinputsCRL_m;/* '<S20>/Two inputs CRL' */
  rtB_TwophaseCRLwrap_mcb_pmsm_fo TwophaseCRLwrap;/* '<S23>/Two phase CRL wrap' */
} BlockIO_mcb_pmsm_foc_sensorless;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Add_DWORK1;                   /* '<S17>/Add' */
  real32_T UnitDelay_DSTATE;           /* '<S8>/Unit Delay' */
  real32_T Delay5_DSTATE[4];           /* '<S1>/Delay5' */
  real32_T Delay_DSTATE;               /* '<S19>/Delay' */
  real32_T UnitDelay_DSTATE_g;         /* '<S46>/Unit Delay' */
  real32_T Delay1_DSTATE;              /* '<S82>/Delay1' */
  real32_T Delay_DSTATE_o[2];          /* '<S83>/Delay' */
  real32_T Delay_DSTATE_a;             /* '<S219>/Delay' */
  real32_T Integrator_DSTATE;          /* '<S151>/Integrator' */
  real32_T Delay2_DSTATE;              /* '<S206>/Delay2' */
  real32_T Delay3_DSTATE;              /* '<S206>/Delay3' */
  real32_T Delay2_DSTATE_i;            /* '<S207>/Delay2' */
  real32_T Delay3_DSTATE_b;            /* '<S207>/Delay3' */
  real32_T Delay1_DSTATE_o;            /* '<S198>/Delay1' */
  real32_T Delay_DSTATE_ao;            /* '<S198>/Delay' */
  real32_T Delay1_DSTATE_n;            /* '<S199>/Delay1' */
  real32_T Delay_DSTATE_oe;            /* '<S199>/Delay' */
  real32_T Delay2_DSTATE_c;            /* '<S173>/Delay2' */
  real32_T Delay3_DSTATE_d;            /* '<S173>/Delay3' */
  real32_T Delay2_DSTATE_p;            /* '<S174>/Delay2' */
  real32_T Delay3_DSTATE_ds;           /* '<S174>/Delay3' */
  real32_T UnitDelay_DSTATE_d5[4];     /* '<S239>/Unit Delay' */
  real32_T Delay1_DSTATE_e;            /* '<S261>/Delay1' */
  real32_T Delay_DSTATE_m;             /* '<S261>/Delay' */
  real32_T UnitDelay_DSTATE_m;         /* '<S265>/Unit Delay' */
  real32_T Delay1_DSTATE_m;            /* '<S253>/Delay1' */
  real32_T Delay_DSTATE_p;             /* '<S253>/Delay' */
  real32_T UnitDelay_DSTATE_b;         /* '<S257>/Unit Delay' */
  real32_T UnitDelay_DSTATE_a1;        /* '<S268>/Unit Delay' */
  real32_T Delay_DSTATE_nd;            /* '<S273>/Delay' */
  real32_T Delay1_DSTATE_l;            /* '<S283>/Delay1' */
  real32_T Delay_DSTATE_e;             /* '<S274>/Delay' */
  real32_T Delay1_DSTATE_j;            /* '<S284>/Delay1' */
  real32_T Delay_DSTATE_nm;            /* '<S271>/Delay' */
  uint32_T Delay_DSTATE_ad[10];        /* '<S235>/Delay' */
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
  real32_T integrator_state;           /* '<S27>/MATLAB Function' */
  real32_T integrator_state_a;         /* '<S26>/MATLAB Function' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S320>/Digital Output1' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S311>/Digital Output' */
  int32_T Add_DWORK1_o[2];             /* '<S77>/Add' */
  int32_T DigitalOutput_FRAC_LEN_h;    /* '<S298>/Digital Output' */
  int32_T SpeedCount_DWORK1;           /* '<S235>/SpeedCount' */
  uint32_T Sum_DWORK1[4];              /* '<S397>/Sum' */
  uint32_T Sum_DWORK1_h[4];            /* '<S54>/Sum' */
  uint16_T Output_DSTATE;              /* '<S69>/Output' */
  volatile int16_T RT6_ActiveBufIdx;   /* '<S8>/RT6' */
  volatile int16_T RT6_semaphoreTaken; /* '<S8>/RT6' */
  volatile int16_T RT4_ActiveBufIdx;   /* '<Root>/RT4' */
  volatile int16_T RT4_semaphoreTaken; /* '<Root>/RT4' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory1' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory2' */
  uint16_T temporalCounter_i1;         /* '<S8>/State Machine OL - CL' */
  uint16_T Memory_PreviousInput;       /* '<S318>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S318>/Memory1' */
  uint16_T Add_DWORK1_oy;              /* '<S300>/Add' */
  uint16_T CircBufIdx;                 /* '<S235>/Delay' */
  uint16_T CircBufIdx_n;               /* '<S278>/Delay' */
  boolean_T Delay_DSTATE_d;            /* '<S50>/Delay' */
  int16_T Integrator_PrevResetState;   /* '<S151>/Integrator' */
  uint16_T is_active_c3_mcb_pmsm_foc_senso;/* '<S8>/State Machine OL - CL' */
  uint16_T is_c3_mcb_pmsm_foc_sensorless_f;/* '<S8>/State Machine OL - CL' */
  uint16_T is_RunMode;                 /* '<S8>/State Machine OL - CL' */
  uint16_T is_NegativeSpeedRun;        /* '<S8>/State Machine OL - CL' */
  uint16_T is_PositiveSpeedRun;        /* '<S8>/State Machine OL - CL' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T EnClosedLoop;              /* '<Root>/Data Store Memory5' */
  boolean_T icLoad;                    /* '<S19>/Delay' */
  boolean_T AlphaRelay_Mode;           /* '<S100>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S100>/BetaRelay' */
  boolean_T AlphaRelay_Mode_c;         /* '<S272>/AlphaRelay' */
  boolean_T BetaRelay_Mode_j;          /* '<S272>/BetaRelay' */
  rtDW_SpeedControl_mcb_pmsm_foc_ SpeedControl;/* '<Root>/Speed Control' */
  rtDW_SPIMasterTransfer_mcb_pmsm SPIMasterTransfer1;/* '<S311>/SPI Master Transfer' */
  rtDW_SPIMasterTransfer_mcb_pmsm SPIMasterTransfer;/* '<S311>/SPI Master Transfer' */
} D_Work_mcb_pmsm_foc_sensorless_;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S19>/Delay' */
  ZCSigState Delay1_Reset_ZCE;         /* '<S82>/Delay1' */
  ZCSigState Delay_Reset_ZCE_g;        /* '<S83>/Delay' */
  ZCSigState Delay_Reset_ZCE_m;        /* '<S219>/Delay' */
  ZCSigState Delay2_Reset_ZCE;         /* '<S206>/Delay2' */
  ZCSigState Delay3_Reset_ZCE;         /* '<S206>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_g;       /* '<S207>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_g;       /* '<S207>/Delay3' */
  ZCSigState Delay1_Reset_ZCE_d;       /* '<S198>/Delay1' */
  ZCSigState Delay_Reset_ZCE_l;        /* '<S198>/Delay' */
  ZCSigState Delay1_Reset_ZCE_db;      /* '<S199>/Delay1' */
  ZCSigState Delay_Reset_ZCE_gg;       /* '<S199>/Delay' */
  ZCSigState Delay2_Reset_ZCE_p;       /* '<S173>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_p;       /* '<S173>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_h;       /* '<S174>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_c;       /* '<S174>/Delay3' */
  rtZCE_Dir_Sense_mcb_pmsm_foc_se Dir_Sense_m;/* '<S100>/Dir_Sense' */
  ZCSigState Delay1_Reset_ZCE_e;       /* '<S261>/Delay1' */
  ZCSigState Delay_Reset_ZCE_p;        /* '<S261>/Delay' */
  ZCSigState Delay1_Reset_ZCE_l;       /* '<S253>/Delay1' */
  ZCSigState Delay_Reset_ZCE_d;        /* '<S253>/Delay' */
  ZCSigState Delay_Reset_ZCE_n;        /* '<S273>/Delay' */
  ZCSigState Delay1_Reset_ZCE_b;       /* '<S283>/Delay1' */
  ZCSigState Delay_Reset_ZCE_ld;       /* '<S274>/Delay' */
  ZCSigState Delay1_Reset_ZCE_bl;      /* '<S284>/Delay1' */
  ZCSigState Delay_Reset_ZCE_n0;       /* '<S271>/Delay' */
  rtZCE_Dir_Sense_mcb_pmsm_foc_se Dir_Sense;/* '<S272>/Dir_Sense' */
} PrevZCSigStates_mcb_pmsm_foc_se;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Product2;               /* '<S17>/Product2' */
  const uint16_T Width;                /* '<S10>/Width' */
} ConstBlockIO_mcb_pmsm_foc_senso;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S54>/sine_table_values'
   *   '<S397>/sine_table_values'
   *   '<S224>/sine_table_values'
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
 * '<S26>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id'
 * '<S27>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq'
 * '<S28>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S29>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S30>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S31>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S32>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S33>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S34>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S35>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S36>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S37>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S38>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S39>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S40>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S41>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S42>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/IIR Filter'
 * '<S43>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/MATLAB Function'
 * '<S44>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/IIR Filter/IIR Filter'
 * '<S45>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/IIR Filter/IIR Filter/Low-pass'
 * '<S46>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S47>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/MATLAB Function'
 * '<S48>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Inverse Park Transform/Two inputs CRL'
 * '<S49>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S50>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Open_Loop_Control/Accumulate1'
 * '<S51>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Open_Loop_Control/Accumulate1/Subsystem'
 * '<S52>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Park Transform/Two inputs CRL'
 * '<S53>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S54>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S55>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S56>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S57>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S58>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S59>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S60>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S61>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S62>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Modulation method'
 * '<S63>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Voltage Input'
 * '<S64>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Modulation method/SVPWM'
 * '<S65>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S66>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S67>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S68>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S69>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Counter Limited'
 * '<S70>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Data'
 * '<S71>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Data_Conditioning'
 * '<S72>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/End'
 * '<S73>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Start'
 * '<S74>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Counter Limited/Increment Real World'
 * '<S75>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S76>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/HW Inputs/Sensor Driver Blocks (codegen)'
 * '<S77>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate Phase Currents'
 * '<S78>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed'
 * '<S79>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer'
 * '<S80>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer'
 * '<S81>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer'
 * '<S82>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer'
 * '<S83>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer'
 * '<S84>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter'
 * '<S85>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/PerUnit'
 * '<S86>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer'
 * '<S87>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem'
 * '<S88>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem2'
 * '<S89>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/A11'
 * '<S90>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/A12'
 * '<S91>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/A22'
 * '<S92>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/L'
 * '<S93>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/L1'
 * '<S94>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/L2'
 * '<S95>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem2/B'
 * '<S96>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem2/L'
 * '<S97>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter/IIR Filter'
 * '<S98>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S99>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S100>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch'
 * '<S101>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL'
 * '<S102>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch/Dir_Sense'
 * '<S103>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem2'
 * '<S104>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem3'
 * '<S105>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter'
 * '<S106>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Normalize'
 * '<S107>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller'
 * '<S108>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward'
 * '<S109>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Subsystem'
 * '<S110>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO'
 * '<S111>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter'
 * '<S112>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass'
 * '<S113>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S114>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Normalize/Compare To Zero'
 * '<S115>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Normalize/If Action Subsystem'
 * '<S116>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Normalize/Subsystem'
 * '<S117>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup'
 * '<S118>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain'
 * '<S119>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative'
 * '<S120>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter'
 * '<S121>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs'
 * '<S122>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain'
 * '<S123>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain'
 * '<S124>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S125>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator'
 * '<S126>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs'
 * '<S127>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy'
 * '<S128>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain'
 * '<S129>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy'
 * '<S130>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain'
 * '<S131>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal'
 * '<S132>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation'
 * '<S133>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk'
 * '<S134>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum'
 * '<S135>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk'
 * '<S136>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode'
 * '<S137>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum'
 * '<S138>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral'
 * '<S139>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain'
 * '<S140>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal'
 * '<S141>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal'
 * '<S142>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal'
 * '<S143>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup/Passthrough'
 * '<S144>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain/Disabled'
 * '<S145>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative/Disabled'
 * '<S146>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter/Disabled'
 * '<S147>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs/Disabled'
 * '<S148>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain/Internal Parameters'
 * '<S149>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S150>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S151>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator/Discrete'
 * '<S152>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S153>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S154>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain/Disabled'
 * '<S155>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy/Disabled'
 * '<S156>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S157>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal/External Reset'
 * '<S158>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation/Passthrough'
 * '<S159>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S160>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum/Sum_PI'
 * '<S161>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S162>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S163>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S164>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S165>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S166>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S167>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal/Internal PreInt'
 * '<S168>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S169>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod'
 * '<S170>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter'
 * '<S171>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod'
 * '<S172>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod'
 * '<S173>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Differentiator'
 * '<S174>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Differentiator1'
 * '<S175>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter1'
 * '<S176>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter2'
 * '<S177>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter3'
 * '<S178>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem'
 * '<S179>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S180>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S181>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S182>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter2/IIR Filter'
 * '<S183>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter2/IIR Filter/Low-pass'
 * '<S184>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter2/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S185>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S186>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S187>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S188>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant'
 * '<S189>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant1'
 * '<S190>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant2'
 * '<S191>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant4'
 * '<S192>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant5'
 * '<S193>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter'
 * '<S194>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass'
 * '<S195>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S196>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1'
 * '<S197>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3'
 * '<S198>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator'
 * '<S199>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator1'
 * '<S200>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter'
 * '<S201>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S202>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S203>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter'
 * '<S204>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S205>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S206>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator'
 * '<S207>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator1'
 * '<S208>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1'
 * '<S209>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3'
 * '<S210>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S211>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S212>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S213>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S214>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S215>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S216>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem'
 * '<S217>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem1'
 * '<S218>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem'
 * '<S219>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased'
 * '<S220>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator'
 * '<S221>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup'
 * '<S222>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator/Accumulate'
 * '<S223>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator/Accumulate/Subsystem'
 * '<S224>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S225>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S226>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S227>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S228>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S229>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S230>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S231>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S232>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1'
 * '<S233>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer'
 * '<S234>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter'
 * '<S235>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement'
 * '<S236>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1/IIR Filter'
 * '<S237>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1/IIR Filter/IIR Filter'
 * '<S238>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1/IIR Filter/IIR Filter/High-pass'
 * '<S239>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S240>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2'
 * '<S241>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Data type Handling'
 * '<S242>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Flux Calculation'
 * '<S243>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/ParamBus'
 * '<S244>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/passthrough'
 * '<S245>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha'
 * '<S246>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta'
 * '<S247>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default'
 * '<S248>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2'
 * '<S249>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2/Per Unit'
 * '<S250>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default'
 * '<S251>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc'
 * '<S252>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter'
 * '<S253>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Integrator'
 * '<S254>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Scaling'
 * '<S255>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S256>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S257>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S258>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default'
 * '<S259>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc'
 * '<S260>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter'
 * '<S261>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Integrator'
 * '<S262>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Scaling'
 * '<S263>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S264>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S265>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S266>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter'
 * '<S267>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S268>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S269>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle'
 * '<S270>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S271>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1'
 * '<S272>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch'
 * '<S273>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ealpha_est'
 * '<S274>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ebeta_est'
 * '<S275>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha'
 * '<S276>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta'
 * '<S277>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter'
 * '<S278>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Speed Measurement'
 * '<S279>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/angleCompensation'
 * '<S280>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch/Dir_Sense'
 * '<S281>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch/Subsystem2'
 * '<S282>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch/Subsystem3'
 * '<S283>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ealpha_est/DisturbanceObserver'
 * '<S284>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ebeta_est/DisturbanceObserver'
 * '<S285>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha/IIR Filter'
 * '<S286>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha/IIR Filter/Low-pass'
 * '<S287>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S288>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta/IIR Filter'
 * '<S289>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta/IIR Filter/Low-pass'
 * '<S290>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S291>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter/IIR Filter'
 * '<S292>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter/IIR Filter/Low-pass'
 * '<S293>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S294>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Speed Measurement/DT_Handle'
 * '<S295>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Speed Measurement/DT_Handle/floating-point'
 * '<S296>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/angleCompensation/atan1'
 * '<S297>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/angleCompensation/atan1/Per Unit'
 * '<S298>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Inverter/Code Generation'
 * '<S299>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/SCI_Tx/Code Generation'
 * '<S300>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/SCI_Tx/Code Generation/CodeGeneration'
 * '<S301>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation'
 * '<S302>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_ADCINT1'
 * '<S303>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_SCIRXINTA'
 * '<S304>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_ADCINT1/ECSoC'
 * '<S305>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_ADCINT1/ECSoC/ECSimCodegen'
 * '<S306>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_SCIRXINTA/ECSoC'
 * '<S307>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_SCIRXINTA/ECSoC/ECSimCodegen'
 * '<S308>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem'
 * '<S309>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation'
 * '<S310>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset '
 * '<S311>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/DRV Enable'
 * '<S312>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Default ADC Offset'
 * '<S313>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem'
 * '<S314>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem'
 * '<S315>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem1'
 * '<S316>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem2'
 * '<S317>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem3'
 * '<S318>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S319>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Heartbeat LED/Heartbeat LED'
 * '<S320>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Heartbeat LED/Heartbeat LED/Code generation'
 * '<S321>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Inverter and Motor - Plant Model/Codegeneration'
 * '<S322>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Serial Receive/Data_Conditioning'
 * '<S323>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Serial Receive/SCI_Rx'
 * '<S324>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Serial Receive/SCI_Rx/Code Generation'
 * '<S325>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed'
 * '<S326>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/SlewRate'
 * '<S327>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S328>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/MATLAB Function'
 * '<S329>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S330>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S331>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S332>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S333>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S334>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S335>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S336>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S337>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S338>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S339>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S340>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S341>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S342>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S343>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S344>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S345>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S346>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S347>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S348>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S349>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S350>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S351>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S352>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S353>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S354>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S355>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S356>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S357>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S358>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S359>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S360>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S361>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S362>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S363>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S364>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S365>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S366>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S367>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S368>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S369>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S370>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S371>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S372>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S373>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S374>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S375>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S376>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S377>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S378>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S379>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S380>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S381>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S382>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S383>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S384>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S385>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S386>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S387>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values'
 * '<S388>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/State Machine OL - CL'
 * '<S389>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Clarke Transform'
 * '<S390>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/I Park Transform'
 * '<S391>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup'
 * '<S392>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/V Park Transform'
 * '<S393>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Clarke Transform/Two phase input'
 * '<S394>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S395>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/I Park Transform/Two inputs CRL'
 * '<S396>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/I Park Transform/Two inputs CRL/Switch_Axis'
 * '<S397>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S398>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S399>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S400>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S401>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S402>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S403>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S404>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S405>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/V Park Transform/Two inputs CRL'
 * '<S406>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/V Park Transform/Two inputs CRL/Switch_Axis'
 * '<S407>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/State Machine OL - CL/RunMode.ComputeId0'
 * '<S408>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/State Machine OL - CL/RunMode.ComputeId0/Compare To Constant'
 */
#endif                         /* mcb_pmsm_foc_sensorless_f28069MLaunchPad_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
