/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_sensorless_f28069MLaunchPad.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_sensorless_f28069MLaunchPad'.
 *
 * Model version                  : 9.12
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Mar 25 11:51:51 2025
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

/* Block signals for system '<S26>/MATLAB Function' */
typedef struct {
  real32_T I_q_ref;                    /* '<S26>/MATLAB Function' */
} rtB_MATLABFunction_mcb_pmsm_foc;

/* Block states (default storage) for system '<S26>/MATLAB Function' */
typedef struct {
  real32_T integrator_state;           /* '<S26>/MATLAB Function' */
} rtDW_MATLABFunction_mcb_pmsm_fo;

/* Block signals for system '<S20>/Two inputs CRL' */
typedef struct {
  real32_T acos_a;                     /* '<S107>/acos' */
  real32_T bsin;                       /* '<S107>/bsin' */
  real32_T sum_Ds;                     /* '<S107>/sum_Ds' */
  real32_T bcos;                       /* '<S107>/bcos' */
  real32_T asin_p;                     /* '<S107>/asin' */
  real32_T sum_Qs;                     /* '<S107>/sum_Qs' */
  real32_T Switch[2];                  /* '<S108>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} rtB_TwoinputsCRL_mcb_pmsm_foc_s;

/* Block signals for system '<S111>/If Action Subsystem' */
typedef struct {
  real32_T Convert_back;               /* '<S114>/Convert_back' */
  int16_T Convert_uint16;              /* '<S114>/Convert_uint16' */
} rtB_IfActionSubsystem_mcb_pmsm_;

/* Block signals for system '<S111>/If Action Subsystem1' */
typedef struct {
  real32_T Convert_back;               /* '<S115>/Convert_back' */
  int16_T Convert_uint16;              /* '<S115>/Convert_uint16' */
} rtB_IfActionSubsystem1_mcb_pmsm;

/* Block signals for system '<S327>/Dir_Sense' */
typedef struct {
  int16_T Switch;                      /* '<S335>/Switch' */
  boolean_T LogicalOperator;           /* '<S335>/Logical Operator' */
} rtB_Dir_Sense_mcb_pmsm_foc_sens;

/* Zero-crossing (trigger) state for system '<S327>/Dir_Sense' */
typedef struct {
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S327>/Dir_Sense' */
} rtZCE_Dir_Sense_mcb_pmsm_foc_se;

/* Block signals for system '<S366>/SPI Master Transfer' */
typedef struct {
  uint16_T SPIMasterTransfer;          /* '<S366>/SPI Master Transfer' */
} rtB_SPIMasterTransfer_mcb_pmsm_;

/* Block states (default storage) for system '<S366>/SPI Master Transfer' */
typedef struct {
  codertarget_tic2000_blocks_SPIM obj; /* '<S366>/SPI Master Transfer' */
  boolean_T objisempty;                /* '<S366>/SPI Master Transfer' */
} rtDW_SPIMasterTransfer_mcb_pmsm;

/* Block signals for system '<Root>/Speed Control' */
typedef struct {
  real32_T Iq_switch_mem;              /* '<S380>/Data Store Read3' */
  real32_T RateLimiter;                /* '<S381>/Rate Limiter' */
  real32_T RateLimiter1;               /* '<S381>/Rate Limiter1' */
  real32_T Switch;                     /* '<S381>/Switch' */
  real32_T Switch1[2];                 /* '<S384>/Switch1' */
  real32_T Product;                    /* '<S441>/Product' */
  real32_T UnitDelay;                  /* '<S441>/Unit Delay' */
  real32_T Product1;                   /* '<S441>/Product1' */
  real32_T Add1;                       /* '<S441>/Add1' */
  real32_T Sum;                        /* '<S380>/Sum' */
  real32_T Product_g;                  /* '<S380>/Product' */
  real32_T Sum1;                       /* '<S380>/Sum1' */
  boolean_T DataStoreRead1;            /* '<S380>/Data Store Read1' */
  boolean_T DataStoreRead2;            /* '<S380>/Data Store Read2' */
  boolean_T AND;                       /* '<S380>/AND' */
  boolean_T LogicalOperator;           /* '<S380>/Logical Operator' */
  rtB_MATLABFunction_mcb_pmsm_foc sf_MATLABFunction;/* '<S380>/MATLAB Function' */
} rtB_SpeedControl_mcb_pmsm_foc_s;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S441>/Unit Delay' */
  real32_T PrevY;                      /* '<S381>/Rate Limiter' */
  real32_T PrevY_f;                    /* '<S381>/Rate Limiter1' */
  rtDW_MATLABFunction_mcb_pmsm_fo sf_MATLABFunction;/* '<S380>/MATLAB Function' */
} rtDW_SpeedControl_mcb_pmsm_foc_;

/* Block signals for system '<S443>/RunMode.ComputeId0' */
typedef struct {
  real32_T Sum;                        /* '<S462>/Sum' */
  real32_T Switch;                     /* '<S462>/Switch' */
  boolean_T Compare;                   /* '<S463>/Compare' */
} rtB_RunModeComputeId0_mcb_pmsm_;

/* Block signals (default storage) */
typedef struct {
  uint32_T Sum[4];                     /* '<S452>/Sum' */
  uint32_T Sum_k[4];                   /* '<S109>/Sum' */
  uint32_T DataTypeConversion;         /* '<S164>/Data Type Conversion' */
  uint32_T Sum_j[4];                   /* '<S279>/Sum' */
  uint32_T PositionToCount;            /* '<S290>/PositionToCount' */
  uint32_T Delay;                      /* '<S290>/Delay' */
  uint32_T PositionToCount_i;          /* '<S333>/PositionToCount' */
  uint32_T Delay_l;                    /* '<S333>/Delay' */
  real32_T SpdCmd;                     /* '<S8>/RT6' */
  real32_T UnitDelay;                  /* '<S8>/Unit Delay' */
  real32_T RT6;                        /* '<Root>/RT6' */
  real32_T RT4;                        /* '<Root>/RT4' */
  real32_T RT2[2];                     /* '<Root>/RT2' */
  real32_T SpdRef;                     /* '<S8>/State Machine OL - CL' */
  real32_T Id0_out;                    /* '<S8>/State Machine OL - CL' */
  real32_T Id0_in;                     /* '<S8>/State Machine OL - CL' */
  real32_T RAMP_STEP_SIZE;             /* '<S8>/State Machine OL - CL' */
  real32_T DataStoreRead3;             /* '<S442>/Data Store Read3' */
  real32_T DataStoreRead1;             /* '<S442>/Data Store Read1' */
  real32_T DataStoreRead2;             /* '<S442>/Data Store Read2' */
  real32_T Merge;                      /* '<S454>/Merge' */
  real32_T indexing;                   /* '<S452>/indexing' */
  real32_T Lookup[4];                  /* '<S452>/Lookup' */
  real32_T Sum3;                       /* '<S453>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S452>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S452>/Sum2' */
  real32_T Product;                    /* '<S453>/Product' */
  real32_T Sum4;                       /* '<S453>/Sum4' */
  real32_T Sum5;                       /* '<S453>/Sum5' */
  real32_T Product1;                   /* '<S453>/Product1' */
  real32_T Sum6;                       /* '<S453>/Sum6' */
  real32_T DataStoreRead;              /* '<S442>/Data Store Read' */
  real32_T DataStoreRead4;             /* '<S442>/Data Store Read4' */
  real32_T DataTypeConversion1_a[2];   /* '<S377>/Data Type Conversion1' */
  real32_T Speed_Ref;                  /* '<S6>/Data Type Conversion1' */
  real32_T DataTypeConversion1_p[2];   /* '<S132>/Data Type Conversion1' */
  real32_T Delay5[4];                  /* '<S1>/Delay5' */
  real32_T Merge_k[2];                 /* '<S133>/Merge' */
  real32_T Spd_Pos;                    /* '<S19>/Data Store Read' */
  real32_T Gain;                       /* '<S19>/Gain' */
  real32_T Delay_g;                    /* '<S19>/Delay' */
  real32_T Add;                        /* '<S105>/Add' */
  real32_T DataTypeConversion1_d;      /* '<S105>/Data Type Conversion1' */
  real32_T Add1;                       /* '<S105>/Add1' */
  real32_T Switch;                     /* '<S19>/Switch' */
  real32_T Merge_c;                    /* '<S111>/Merge' */
  real32_T indexing_d;                 /* '<S109>/indexing' */
  real32_T Lookup_f[4];                /* '<S109>/Lookup' */
  real32_T Sum3_b;                     /* '<S110>/Sum3' */
  real32_T DataTypeConversion1_c;      /* '<S109>/Data Type Conversion1' */
  real32_T Sum2_e;                     /* '<S109>/Sum2' */
  real32_T Product_g;                  /* '<S110>/Product' */
  real32_T Sum4_h;                     /* '<S110>/Sum4' */
  real32_T Sum5_l;                     /* '<S110>/Sum5' */
  real32_T Product1_e;                 /* '<S110>/Product1' */
  real32_T Sum6_c;                     /* '<S110>/Sum6' */
  real32_T Sum_m;                      /* '<S27>/Sum' */
  real32_T Vq_computed;                /* '<S27>/Vq_computed1' */
  real32_T Product_b;                  /* '<S27>/Product' */
  real32_T Sum1;                       /* '<S27>/Sum1' */
  real32_T Switch_j;                   /* '<S27>/Switch' */
  real32_T Sum_g;                      /* '<S26>/Sum' */
  real32_T Vd_computed1;               /* '<S26>/Vd_computed1' */
  real32_T Product_e;                  /* '<S26>/Product' */
  real32_T Sum1_a;                     /* '<S26>/Sum1' */
  real32_T Vd_OpenLoop;                /* '<S26>/Vd_OpenLoop' */
  real32_T Abs;                        /* '<S26>/Abs' */
  real32_T Switch1[2];                 /* '<S43>/Switch1' */
  real32_T Product_bh;                 /* '<S101>/Product' */
  real32_T UnitDelay_n;                /* '<S101>/Unit Delay' */
  real32_T Product1_p;                 /* '<S101>/Product1' */
  real32_T Add1_l;                     /* '<S101>/Add1' */
  real32_T Switch_d;                   /* '<S26>/Switch' */
  real32_T Switch_jv;                  /* '<S30>/Switch' */
  real32_T Product_l;                  /* '<S30>/Product' */
  real32_T Product_o;                  /* '<S31>/Product' */
  real32_T Product1_a;                 /* '<S31>/Product1' */
  real32_T Sum1_e;                     /* '<S31>/Sum1' */
  real32_T Merge_m[2];                 /* '<S25>/Merge' */
  real32_T DataTypeConversion_c;       /* '<S14>/Data Type Conversion' */
  real32_T Speed_fb_PU;                /* '<S1>/Input Scaling' */
  real32_T TmpSignalConversionAtDelay5Inpo[4];
  real32_T sqrt3_by_two;               /* '<S123>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S123>/one_by_two' */
  real32_T add_c;                      /* '<S123>/add_c' */
  real32_T add_b;                      /* '<S123>/add_b' */
  real32_T Min;                        /* '<S120>/Min' */
  real32_T Max;                        /* '<S120>/Max' */
  real32_T Add_i;                      /* '<S120>/Add' */
  real32_T one_by_two_d;               /* '<S120>/one_by_two' */
  real32_T Add3;                       /* '<S119>/Add3' */
  real32_T Add2;                       /* '<S119>/Add2' */
  real32_T Add1_b;                     /* '<S119>/Add1' */
  real32_T Gain_c[3];                  /* '<S119>/Gain' */
  real32_T Gain_c1[3];                 /* '<S14>/Gain' */
  real32_T PWM_Duty_Cycles[3];         /* '<S14>/Sum' */
  real32_T Delay1;                     /* '<S137>/Delay1' */
  real32_T Delay_f[2];                 /* '<S138>/Delay' */
  real32_T Gain_m;                     /* '<S143>/Gain' */
  real32_T UnaryMinus;                 /* '<S151>/Unary Minus' */
  real32_T Product1_f;                 /* '<S140>/Product1' */
  real32_T Gain1;                      /* '<S150>/Gain1' */
  real32_T Product2;                   /* '<S151>/Product2' */
  real32_T Product_k;                  /* '<S140>/Product' */
  real32_T Gain_n;                     /* '<S150>/Gain' */
  real32_T Product_i;                  /* '<S151>/Product' */
  real32_T Sum_mr;                     /* '<S151>/Sum' */
  real32_T Product1_ao;                /* '<S151>/Product1' */
  real32_T Product3;                   /* '<S151>/Product3' */
  real32_T Sum1_m;                     /* '<S151>/Sum1' */
  real32_T Product3_n;                 /* '<S140>/Product3' */
  real32_T Product1_o;                 /* '<S147>/Product1' */
  real32_T Product2_c;                 /* '<S140>/Product2' */
  real32_T Gain_g;                     /* '<S142>/Gain' */
  real32_T Product3_n0;                /* '<S147>/Product3' */
  real32_T Sum1_c;                     /* '<S147>/Sum1' */
  real32_T Product1_h;                 /* '<S146>/Product1' */
  real32_T UnaryMinus_k;               /* '<S146>/Unary Minus' */
  real32_T UnaryMinus_f;               /* '<S147>/Unary Minus' */
  real32_T Product2_a;                 /* '<S147>/Product2' */
  real32_T Product_gf;                 /* '<S147>/Product' */
  real32_T Sum_i;                      /* '<S147>/Sum' */
  real32_T Product_kc;                 /* '<S146>/Product' */
  real32_T UnaryMinus_fm;              /* '<S148>/Unary Minus' */
  real32_T Gain1_o;                    /* '<S145>/Gain1' */
  real32_T UnaryMinus1;                /* '<S145>/Unary Minus1' */
  real32_T Product2_d;                 /* '<S148>/Product2' */
  real32_T Gain_j;                     /* '<S145>/Gain' */
  real32_T UnaryMinus_i;               /* '<S145>/Unary Minus' */
  real32_T Product_f;                  /* '<S148>/Product' */
  real32_T Sum_e;                      /* '<S148>/Sum' */
  real32_T Product1_oz;                /* '<S148>/Product1' */
  real32_T Product3_nb;                /* '<S148>/Product3' */
  real32_T Sum1_k;                     /* '<S148>/Sum1' */
  real32_T UnaryMinus_j;               /* '<S149>/Unary Minus' */
  real32_T Product_n;                  /* '<S144>/Product' */
  real32_T Product3_c;                 /* '<S144>/Product3' */
  real32_T UnaryMinus1_b;              /* '<S144>/Unary Minus1' */
  real32_T Product5;                   /* '<S144>/Product5' */
  real32_T Sum1_i;                     /* '<S144>/Sum1' */
  real32_T Product2_o;                 /* '<S149>/Product2' */
  real32_T Product4;                   /* '<S144>/Product4' */
  real32_T Product1_b;                 /* '<S144>/Product1' */
  real32_T UnaryMinus_g;               /* '<S144>/Unary Minus' */
  real32_T Product2_f;                 /* '<S144>/Product2' */
  real32_T Sum_kn;                     /* '<S144>/Sum' */
  real32_T Product_gf3;                /* '<S149>/Product' */
  real32_T Sum_h;                      /* '<S149>/Sum' */
  real32_T Product1_d;                 /* '<S149>/Product1' */
  real32_T Product3_g;                 /* '<S149>/Product3' */
  real32_T Sum1_j;                     /* '<S149>/Sum1' */
  real32_T Sum_l[2];                   /* '<S142>/Sum' */
  real32_T Sum_n[2];                   /* '<S138>/Sum' */
  real32_T Gain1_c[2];                 /* '<S138>/Gain1' */
  real32_T Sum2_o[2];                  /* '<S138>/Sum2' */
  real32_T Gain2[2];                   /* '<S138>/Gain2' */
  real32_T Sum1_j4[2];                 /* '<S138>/Sum1' */
  real32_T Product_m[2];               /* '<S137>/Product' */
  real32_T Switch1_g[2];               /* '<S139>/Switch1' */
  real32_T Product_j[2];               /* '<S154>/Product' */
  real32_T UnitDelay_j[2];             /* '<S154>/Unit Delay' */
  real32_T Product1_ee[2];             /* '<S154>/Product1' */
  real32_T Add1_j[2];                  /* '<S154>/Add1' */
  real32_T Merge_k4;                   /* '<S155>/Merge' */
  real32_T Merge1;                     /* '<S155>/Merge1' */
  real32_T Merge_o[2];                 /* '<S164>/Merge' */
  real32_T Product_nv;                 /* '<S161>/Product' */
  real32_T Product1_n;                 /* '<S161>/Product1' */
  real32_T Sum_e2;                     /* '<S161>/Sum' */
  real32_T Merge_f;                    /* '<S161>/Merge' */
  real32_T Merge1_o;                   /* '<S161>/Merge1' */
  real32_T Merge_i;                    /* '<S163>/Merge' */
  real32_T Switch1_n[2];               /* '<S225>/Switch1' */
  real32_T Product_gh;                 /* '<S250>/Product' */
  real32_T UnitDelay_c;                /* '<S250>/Unit Delay' */
  real32_T Product1_l;                 /* '<S250>/Product1' */
  real32_T Add1_g;                     /* '<S250>/Add1' */
  real32_T Delay_j;                    /* '<S274>/Delay' */
  real32_T Merge_g;                    /* '<S281>/Merge' */
  real32_T indexing_i;                 /* '<S279>/indexing' */
  real32_T Lookup_m[4];                /* '<S279>/Lookup' */
  real32_T Sum5_i;                     /* '<S280>/Sum5' */
  real32_T DataTypeConversion1_d2;     /* '<S279>/Data Type Conversion1' */
  real32_T Sum2_eo;                    /* '<S279>/Sum2' */
  real32_T Product1_nl;                /* '<S280>/Product1' */
  real32_T Sum6_m;                     /* '<S280>/Sum6' */
  real32_T Product_la;                 /* '<S156>/Product' */
  real32_T Sum3_n;                     /* '<S280>/Sum3' */
  real32_T Product_a;                  /* '<S280>/Product' */
  real32_T Sum4_p;                     /* '<S280>/Sum4' */
  real32_T Product1_dd;                /* '<S156>/Product1' */
  real32_T Sum_b;                      /* '<S156>/Sum' */
  real32_T ProportionalGain;           /* '<S211>/Proportional Gain' */
  real32_T IntegralGain;               /* '<S203>/Integral Gain' */
  real32_T Integrator;                 /* '<S206>/Integrator' */
  real32_T Sum_d;                      /* '<S215>/Sum' */
  real32_T speed;                      /* '<S156>/Sum1' */
  real32_T Switch1_e[2];               /* '<S160>/Switch1' */
  real32_T Product_iq;                 /* '<S168>/Product' */
  real32_T UnitDelay_i;                /* '<S168>/Unit Delay' */
  real32_T Product1_ok;                /* '<S168>/Product1' */
  real32_T Add1_h;                     /* '<S168>/Add1' */
  real32_T Gain_l;                     /* '<S274>/Gain' */
  real32_T UnitDelay_o;                /* '<S275>/Unit Delay' */
  real32_T Add_g;                      /* '<S277>/Add' */
  real32_T DataTypeConversion1_l;      /* '<S277>/Data Type Conversion1' */
  real32_T Add1_k;                     /* '<S277>/Add1' */
  real32_T Input;                      /* '<S278>/Input' */
  real32_T In1;                        /* '<S271>/In1' */
  real32_T Delay2;                     /* '<S261>/Delay2' */
  real32_T Delay3;                     /* '<S261>/Delay3' */
  real32_T Switch1_j[2];               /* '<S264>/Switch1' */
  real32_T Product_ex;                 /* '<S270>/Product' */
  real32_T UnitDelay_d;                /* '<S270>/Unit Delay' */
  real32_T Product1_dx;                /* '<S270>/Product1' */
  real32_T Add1_f;                     /* '<S270>/Add1' */
  real32_T Gain_b;                     /* '<S261>/Gain' */
  real32_T Sum1_n;                     /* '<S261>/Sum1' */
  real32_T Gain1_n;                    /* '<S261>/Gain1' */
  real32_T Delay2_i;                   /* '<S262>/Delay2' */
  real32_T Delay3_a;                   /* '<S262>/Delay3' */
  real32_T Switch1_f[2];               /* '<S263>/Switch1' */
  real32_T Product_k3;                 /* '<S267>/Product' */
  real32_T UnitDelay_iy;               /* '<S267>/Unit Delay' */
  real32_T Product1_c;                 /* '<S267>/Product1' */
  real32_T Add1_c;                     /* '<S267>/Add1' */
  real32_T Gain_m4;                    /* '<S262>/Gain' */
  real32_T Sum1_ci;                    /* '<S262>/Sum1' */
  real32_T Gain1_l;                    /* '<S262>/Gain1' */
  real32_T Product_kg;                 /* '<S227>/Product' */
  real32_T Product1_pv;                /* '<S227>/Product1' */
  real32_T Switch1_d[2];               /* '<S252>/Switch1' */
  real32_T Product_fd;                 /* '<S260>/Product' */
  real32_T UnitDelay_ju;               /* '<S260>/Unit Delay' */
  real32_T Product1_dq;                /* '<S260>/Product1' */
  real32_T Add1_d;                     /* '<S260>/Add1' */
  real32_T Delay1_i;                   /* '<S253>/Delay1' */
  real32_T Sum_mt;                     /* '<S253>/Sum' */
  real32_T Gain1_g;                    /* '<S253>/Gain1' */
  real32_T Delay_d;                    /* '<S253>/Delay' */
  real32_T Gain2_i;                    /* '<S253>/Gain2' */
  real32_T Sum1_a0;                    /* '<S253>/Sum1' */
  real32_T Product_j2;                 /* '<S226>/Product' */
  real32_T Switch1_n2[2];              /* '<S251>/Switch1' */
  real32_T Product_p;                  /* '<S257>/Product' */
  real32_T UnitDelay_id;               /* '<S257>/Unit Delay' */
  real32_T Product1_p0;                /* '<S257>/Product1' */
  real32_T Add1_c4;                    /* '<S257>/Add1' */
  real32_T Delay1_p;                   /* '<S254>/Delay1' */
  real32_T Sum_mq;                     /* '<S254>/Sum' */
  real32_T Gain1_ng;                   /* '<S254>/Gain1' */
  real32_T Delay_o;                    /* '<S254>/Delay' */
  real32_T Gain2_o;                    /* '<S254>/Gain2' */
  real32_T Sum1_h;                     /* '<S254>/Sum1' */
  real32_T Product1_ap;                /* '<S226>/Product1' */
  real32_T Sum_o;                      /* '<S226>/Sum' */
  real32_T MathFunction;               /* '<S226>/Math Function' */
  real32_T Abs_k;                      /* '<S226>/Abs' */
  real32_T Delay2_m;                   /* '<S228>/Delay2' */
  real32_T Delay3_d;                   /* '<S228>/Delay3' */
  real32_T Switch1_i[2];               /* '<S232>/Switch1' */
  real32_T Product_ke;                 /* '<S242>/Product' */
  real32_T UnitDelay_p;                /* '<S242>/Unit Delay' */
  real32_T Product1_o1;                /* '<S242>/Product1' */
  real32_T Add1_m;                     /* '<S242>/Add1' */
  real32_T Gain_gx;                    /* '<S228>/Gain' */
  real32_T Sum1_ag;                    /* '<S228>/Sum1' */
  real32_T Gain1_gr;                   /* '<S228>/Gain1' */
  real32_T Delay2_e;                   /* '<S229>/Delay2' */
  real32_T Delay3_m;                   /* '<S229>/Delay3' */
  real32_T Switch1_b[2];               /* '<S230>/Switch1' */
  real32_T Product_j5;                 /* '<S236>/Product' */
  real32_T UnitDelay_m;                /* '<S236>/Unit Delay' */
  real32_T Product1_br;                /* '<S236>/Product1' */
  real32_T Add1_o;                     /* '<S236>/Add1' */
  real32_T Gain_gp;                    /* '<S229>/Gain' */
  real32_T Sum1_ed;                    /* '<S229>/Sum1' */
  real32_T Gain1_p;                    /* '<S229>/Gain1' */
  real32_T Delay_f1;                   /* '<S233>/Delay' */
  real32_T Delay1_m;                   /* '<S233>/Delay1' */
  real32_T Switch1_fq;                 /* '<S233>/Switch1' */
  real32_T Switch1_a[2];               /* '<S231>/Switch1' */
  real32_T Product_md;                 /* '<S239>/Product' */
  real32_T UnitDelay_pm;               /* '<S239>/Unit Delay' */
  real32_T Product1_cn;                /* '<S239>/Product1' */
  real32_T Add1_fo;                    /* '<S239>/Add1' */
  real32_T Square;                     /* '<S224>/Square' */
  real32_T Square1;                    /* '<S224>/Square1' */
  real32_T Sum2_k;                     /* '<S224>/Sum2' */
  real32_T Sqrt;                       /* '<S224>/Sqrt' */
  real32_T UnaryMinus_b;               /* '<S224>/Unary Minus' */
  real32_T Sum_ji;                     /* '<S233>/Sum' */
  real32_T Sqrt_g;                     /* '<S171>/Sqrt' */
  real32_T Divide;                     /* '<S171>/Divide' */
  real32_T Divide1;                    /* '<S171>/Divide1' */
  real32_T Switch1_dz[2];              /* '<S291>/Switch1' */
  real32_T Product_am[4];              /* '<S294>/Product' */
  real32_T UnitDelay_a[4];             /* '<S294>/Unit Delay' */
  real32_T Product1_j[4];              /* '<S294>/Product1' */
  real32_T Add1_jy[4];                 /* '<S294>/Add1' */
  real32_T Sum_bf[4];                  /* '<S293>/Sum' */
  real32_T Product_c;                  /* '<S317>/Product' */
  real32_T Sum3_k;                     /* '<S314>/Sum3' */
  real32_T Delay1_pl;                  /* '<S316>/Delay1' */
  real32_T Sum_jy;                     /* '<S316>/Sum' */
  real32_T Product_d;                  /* '<S316>/Product' */
  real32_T Delay_p;                    /* '<S316>/Delay' */
  real32_T Product1_n5;                /* '<S316>/Product1' */
  real32_T Sum1_em;                    /* '<S316>/Sum1' */
  real32_T Product2_i;                 /* '<S317>/Product2' */
  real32_T Sum1_p;                     /* '<S314>/Sum1' */
  real32_T Sum_p;                      /* '<S315>/Sum' */
  real32_T Switch1_eg[2];              /* '<S315>/Switch1' */
  real32_T Product_fdo;                /* '<S320>/Product' */
  real32_T UnitDelay_dy;               /* '<S320>/Unit Delay' */
  real32_T Product1_k;                 /* '<S320>/Product1' */
  real32_T Add1_jx;                    /* '<S320>/Add1' */
  real32_T Switch_g;                   /* '<S313>/Switch' */
  real32_T Product_iw;                 /* '<S309>/Product' */
  real32_T Sum3_n0;                    /* '<S306>/Sum3' */
  real32_T Delay1_a;                   /* '<S308>/Delay1' */
  real32_T Sum_ga;                     /* '<S308>/Sum' */
  real32_T Product_n3;                 /* '<S308>/Product' */
  real32_T Delay_b;                    /* '<S308>/Delay' */
  real32_T Product1_g;                 /* '<S308>/Product1' */
  real32_T Sum1_mn;                    /* '<S308>/Sum1' */
  real32_T Product2_b;                 /* '<S309>/Product2' */
  real32_T Sum1_as;                    /* '<S306>/Sum1' */
  real32_T Sum_a;                      /* '<S307>/Sum' */
  real32_T Switch1_o[2];               /* '<S307>/Switch1' */
  real32_T Product_lm;                 /* '<S312>/Product' */
  real32_T UnitDelay_e;                /* '<S312>/Unit Delay' */
  real32_T Product1_ba;                /* '<S312>/Product1' */
  real32_T Add1_i;                     /* '<S312>/Add1' */
  real32_T Switch_h;                   /* '<S305>/Switch' */
  real32_T DTC;                        /* '<S325>/DTC' */
  real32_T SpeedGain;                  /* '<S290>/SpeedGain' */
  real32_T Switch1_bs[2];              /* '<S289>/Switch1' */
  real32_T Product_pk;                 /* '<S323>/Product' */
  real32_T UnitDelay_dk;               /* '<S323>/Unit Delay' */
  real32_T Product1_al;                /* '<S323>/Product1' */
  real32_T Add1_p;                     /* '<S323>/Add1' */
  real32_T elect2mech;                 /* '<S135>/elect2mech' */
  real32_T Sum_dj;                     /* '<S319>/Sum' */
  real32_T Sum_ac;                     /* '<S311>/Sum' */
  real32_T Atan2;                      /* '<S303>/Atan2' */
  real32_T Switch_ds;                  /* '<S303>/Switch' */
  real32_T algDD;
  real32_T Gain_f;                     /* '<S304>/Gain' */
  real32_T Switch_c;                   /* '<S304>/Switch' */
  real32_T Bias;                       /* '<S304>/Bias' */
  real32_T UnitDelay1;                 /* '<S338>/Unit Delay1' */
  real32_T UnitDelay_g;                /* '<S338>/Unit Delay' */
  real32_T a;                          /* '<S338>/a' */
  real32_T Delay_k;                    /* '<S328>/Delay' */
  real32_T Sum2_g;                     /* '<S328>/Sum2' */
  real32_T Sum3_m;                     /* '<S338>/Sum3' */
  real32_T b_invg;                     /* '<S338>/b_inv*g' */
  real32_T Delay1_e;                   /* '<S338>/Delay1' */
  real32_T Sum4_b;                     /* '<S338>/Sum4' */
  real32_T Switch1_jq[2];              /* '<S330>/Switch1' */
  real32_T Product_c0;                 /* '<S342>/Product' */
  real32_T UnitDelay_ab;               /* '<S342>/Unit Delay' */
  real32_T Product1_en;                /* '<S342>/Product1' */
  real32_T Add1_dd;                    /* '<S342>/Add1' */
  real32_T UnitDelay1_k;               /* '<S339>/Unit Delay1' */
  real32_T UnitDelay_k;                /* '<S339>/Unit Delay' */
  real32_T a_e;                        /* '<S339>/a' */
  real32_T Delay_i;                    /* '<S329>/Delay' */
  real32_T Sum2_g2;                    /* '<S329>/Sum2' */
  real32_T Sum3_l;                     /* '<S339>/Sum3' */
  real32_T b_invg_o;                   /* '<S339>/b_inv*g' */
  real32_T Delay1_f;                   /* '<S339>/Delay1' */
  real32_T Sum4_m;                     /* '<S339>/Sum4' */
  real32_T Switch1_m[2];               /* '<S331>/Switch1' */
  real32_T Product_p3;                 /* '<S345>/Product' */
  real32_T UnitDelay_gx;               /* '<S345>/Unit Delay' */
  real32_T Product1_k4;                /* '<S345>/Product1' */
  real32_T Add1_gu;                    /* '<S345>/Add1' */
  real32_T Merge_ku;                   /* '<S327>/Merge' */
  real32_T Merge1_i;                   /* '<S327>/Merge1' */
  real32_T Delay_e;                    /* '<S326>/Delay' */
  real32_T Sign;                       /* '<S328>/Sign' */
  real32_T Eta;                        /* '<S328>/Eta' */
  real32_T Sum_gf;                     /* '<S328>/Sum' */
  real32_T b;                          /* '<S328>/b' */
  real32_T a_a;                        /* '<S328>/a' */
  real32_T Sum1_d;                     /* '<S328>/Sum1' */
  real32_T Sign_m;                     /* '<S329>/Sign' */
  real32_T Eta_n;                      /* '<S329>/Eta' */
  real32_T Sum_bl;                     /* '<S329>/Sum' */
  real32_T b_i;                        /* '<S329>/b' */
  real32_T a_p;                        /* '<S329>/a' */
  real32_T Sum1_g;                     /* '<S329>/Sum1' */
  real32_T DTC_e;                      /* '<S350>/DTC' */
  real32_T SpeedGain_k;                /* '<S333>/SpeedGain' */
  real32_T Switch1_bp[2];              /* '<S332>/Switch1' */
  real32_T Product_i2;                 /* '<S348>/Product' */
  real32_T UnitDelay_ci;               /* '<S348>/Unit Delay' */
  real32_T Product1_ey;                /* '<S348>/Product1' */
  real32_T Add1_cr;                    /* '<S348>/Add1' */
  real32_T Product_jt;                 /* '<S334>/Product' */
  real32_T Product2_il;                /* '<S334>/Product2' */
  real32_T Sum1_mc;                    /* '<S334>/Sum1' */
  real32_T Product1_m;                 /* '<S334>/Product1' */
  real32_T Product3_b;                 /* '<S334>/Product3' */
  real32_T Sum2_p;                     /* '<S334>/Sum2' */
  real32_T Switch_cx;                  /* '<S334>/Switch' */
  real32_T Atan2_n;                    /* '<S351>/Atan2' */
  real32_T Switch_gb;                  /* '<S351>/Switch' */
  real32_T algDD_a;
  real32_T Gain_o;                     /* '<S352>/Gain' */
  real32_T Switch_m;                   /* '<S352>/Switch' */
  real32_T Bias_f;                     /* '<S352>/Bias' */
  real32_T Bias_j;                     /* '<S334>/Bias' */
  real32_T Input_h;                    /* '<S106>/Input' */
  real32_T qcos;                       /* '<S103>/qcos' */
  real32_T dsin;                       /* '<S103>/dsin' */
  real32_T sum_beta;                   /* '<S103>/sum_beta' */
  real32_T dcos;                       /* '<S103>/dcos' */
  real32_T qsin;                       /* '<S103>/qsin' */
  real32_T sum_alpha;                  /* '<S103>/sum_alpha' */
  real32_T Switch_f[2];                /* '<S104>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T Saturation;                 /* '<S26>/Saturation' */
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
  int32_T DataTypeConversion_ch[2];    /* '<S132>/Data Type Conversion' */
  int32_T Add_k[2];                    /* '<S132>/Add' */
  int32_T Q17perunitconversion[2];     /* '<S132>/Q17 per unit conversion' */
  int32_T SpeedCount;                  /* '<S290>/SpeedCount' */
  int32_T SpeedCount_c;                /* '<S333>/SpeedCount' */
  uint16_T DataTypeConversion_b;       /* '<S454>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S452>/Get_Integer' */
  uint16_T Divide_h;                   /* '<S365>/Divide' */
  uint16_T Divide1_e;                  /* '<S365>/Divide1' */
  uint16_T ForIterator;                /* '<S368>/For Iterator' */
  uint16_T IAIBMeasurement[2];         /* '<S368>/IA//IB Measurement' */
  uint16_T Memory;                     /* '<S373>/Memory' */
  uint16_T Sum_dn;                     /* '<S373>/Sum' */
  uint16_T Memory1;                    /* '<S373>/Memory1' */
  uint16_T Sum1_dq;                    /* '<S373>/Sum1' */
  uint16_T SCIReceive[2];              /* '<S379>/SCI Receive' */
  uint16_T DataStoreRead_m;            /* '<S132>/Data Store Read' */
  uint16_T DataStoreRead1_p;           /* '<S132>/Data Store Read1' */
  uint16_T IAIBMeasurement_k[2];       /* '<S131>/IA//IB Measurement' */
  uint16_T Switch1_fg;                 /* '<S30>/Switch1' */
  uint16_T DataTypeConversion_e;       /* '<S111>/Data Type Conversion' */
  uint16_T Get_Integer_i;              /* '<S109>/Get_Integer' */
  uint16_T Output;                     /* '<S124>/Output' */
  uint16_T DataTypeConversion3[2];     /* '<S126>/Data Type Conversion3' */
  uint16_T SCI_Tx_Data[3];             /* '<S10>/Merge' */
  uint16_T SCI_Tx_Iteration;           /* '<S10>/Merge1' */
  uint16_T FixPtSum1;                  /* '<S129>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S130>/FixPt Switch' */
  uint16_T Switch1_c[3];               /* '<S353>/Switch1' */
  uint16_T IndexVector;                /* '<S355>/Index Vector' */
  uint16_T Add_m;                      /* '<S355>/Add' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S353>/Scale_to_PWM_Counter_PRD' */
  uint16_T DataTypeConversion_n;       /* '<S281>/Data Type Conversion' */
  uint16_T Get_Integer_m;              /* '<S279>/Get_Integer' */
  uint16_T Data[2];                    /* '<S125>/Data' */
  uint16_T Data_f[2];                  /* '<S127>/Data' */
  uint16_T Data_fw[2];                 /* '<S128>/Data' */
  uint16_T DataTypeConversion_k;       /* '<S28>/Data Type Conversion' */
  uint16_T DataTypeConversion_a;       /* '<S38>/Data Type Conversion' */
  int16_T DataTypeConversion2[2];      /* '<S377>/Data Type Conversion2' */
  int16_T DataTypeConversion_l[2];     /* '<S126>/Data Type Conversion' */
  int16_T DataTypeConversion_ey;       /* '<S105>/Data Type Conversion' */
  int16_T WhileIterator;               /* '<S355>/While Iterator' */
  int16_T DataTypeConversion_h;        /* '<S277>/Data Type Conversion' */
  boolean_T RT5;                       /* '<S8>/RT5' */
  boolean_T NOT;                       /* '<S8>/NOT' */
  boolean_T Enable;                    /* '<S8>/State Machine OL - CL' */
  boolean_T EnClosedLoop;              /* '<S8>/State Machine OL - CL' */
  boolean_T Compare;                   /* '<S456>/Compare' */
  boolean_T NOT_h;                     /* '<S364>/NOT' */
  boolean_T DataTypeConversion3_b;     /* '<S6>/Data Type Conversion3' */
  boolean_T DataStoreRead1_n;          /* '<S19>/Data Store Read1' */
  boolean_T Delay_kh;                  /* '<S105>/Delay' */
  boolean_T DataStoreRead2_m;          /* '<S19>/Data Store Read2' */
  boolean_T Compare_d;                 /* '<S113>/Compare' */
  boolean_T DataStoreRead1_b;          /* '<S27>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S27>/Logical Operator' */
  boolean_T DataStoreRead1_f;          /* '<S26>/Data Store Read1' */
  boolean_T LogicalOperator_e;         /* '<S26>/Logical Operator' */
  boolean_T Enable_l;                  /* '<S14>/Enable' */
  boolean_T DataStoreRead1_g;          /* '<S134>/Data Store Read1' */
  boolean_T LogicalOperator_l;         /* '<S134>/Logical Operator' */
  boolean_T AlphaRelay;                /* '<S155>/AlphaRelay' */
  boolean_T BetaRelay;                 /* '<S155>/BetaRelay' */
  boolean_T Compare_j;                 /* '<S169>/Compare' */
  boolean_T Compare_k;                 /* '<S283>/Compare' */
  boolean_T NOT_hg;                    /* '<S275>/NOT' */
  boolean_T Delay_bv;                  /* '<S277>/Delay' */
  boolean_T Compare_n;                 /* '<S244>/Compare' */
  boolean_T Compare_kj;                /* '<S246>/Compare' */
  boolean_T Compare_o;                 /* '<S243>/Compare' */
  boolean_T LogicalOperator1;          /* '<S233>/Logical Operator1' */
  boolean_T Compare_d4;                /* '<S247>/Compare' */
  boolean_T LogicalOperator2;          /* '<S233>/Logical Operator2' */
  boolean_T AND;                       /* '<S233>/AND' */
  boolean_T UnitDelay_cp;              /* '<S233>/Unit Delay' */
  boolean_T Switch_l;                  /* '<S233>/Switch' */
  boolean_T Compare_c;                 /* '<S245>/Compare' */
  boolean_T LogicalOperator_k;         /* '<S233>/Logical Operator' */
  boolean_T DataStoreRead1_c;          /* '<S135>/Data Store Read1' */
  boolean_T LogicalOperator_ed;        /* '<S135>/Logical Operator' */
  boolean_T DataStoreRead1_i;          /* '<S136>/Data Store Read1' */
  boolean_T LogicalOperator_i;         /* '<S136>/Logical Operator' */
  boolean_T AlphaRelay_p;              /* '<S327>/AlphaRelay' */
  boolean_T BetaRelay_j;               /* '<S327>/BetaRelay' */
  boolean_T RelationalOperator;        /* '<S28>/Relational Operator' */
  boolean_T Compare_n2;                /* '<S34>/Compare' */
  boolean_T Compare_m;                 /* '<S35>/Compare' */
  boolean_T LowerRelop1;               /* '<S39>/LowerRelop1' */
  boolean_T RelationalOperator_c;      /* '<S38>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S39>/UpperRelop' */
  rtB_RunModeComputeId0_mcb_pmsm_ RunModeComputeId0;/* '<S443>/RunMode.ComputeId0' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_s TwoinputsCRL_j;/* '<S447>/Two inputs CRL' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1_b;/* '<S454>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem_ey;/* '<S454>/If Action Subsystem' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_s TwoinputsCRL_c;/* '<S445>/Two inputs CRL' */
  rtB_TwophaseCRLwrap_mcb_pmsm_fo TwophaseCRLwrap_b;/* '<S448>/Two phase CRL wrap' */
  rtB_SpeedControl_mcb_pmsm_foc_s SpeedControl;/* '<Root>/Speed Control' */
  rtB_SPIMasterTransfer_mcb_pmsm_ SPIMasterTransfer1;/* '<S366>/SPI Master Transfer' */
  rtB_SPIMasterTransfer_mcb_pmsm_ SPIMasterTransfer;/* '<S366>/SPI Master Transfer' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1_o;/* '<S281>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem_e;/* '<S281>/If Action Subsystem' */
  rtB_Dir_Sense_mcb_pmsm_foc_sens Dir_Sense_m;/* '<S155>/Dir_Sense' */
  rtB_Dir_Sense_mcb_pmsm_foc_sens Dir_Sense;/* '<S327>/Dir_Sense' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1;/* '<S111>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem;/* '<S111>/If Action Subsystem' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_s TwoinputsCRL_m;/* '<S20>/Two inputs CRL' */
  rtB_MATLABFunction_mcb_pmsm_foc sf_MATLABFunction_d;/* '<S27>/MATLAB Function' */
  rtB_MATLABFunction_mcb_pmsm_foc sf_MATLABFunction;/* '<S26>/MATLAB Function' */
  rtB_TwophaseCRLwrap_mcb_pmsm_fo TwophaseCRLwrap;/* '<S23>/Two phase CRL wrap' */
} BlockIO_mcb_pmsm_foc_sensorless;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S8>/Unit Delay' */
  real32_T Delay5_DSTATE[4];           /* '<S1>/Delay5' */
  real32_T Delay_DSTATE;               /* '<S19>/Delay' */
  real32_T UnitDelay_DSTATE_g;         /* '<S101>/Unit Delay' */
  real32_T Delay1_DSTATE;              /* '<S137>/Delay1' */
  real32_T Delay_DSTATE_o[2];          /* '<S138>/Delay' */
  real32_T Delay_DSTATE_a;             /* '<S274>/Delay' */
  real32_T Integrator_DSTATE;          /* '<S206>/Integrator' */
  real32_T Delay2_DSTATE;              /* '<S261>/Delay2' */
  real32_T Delay3_DSTATE;              /* '<S261>/Delay3' */
  real32_T Delay2_DSTATE_i;            /* '<S262>/Delay2' */
  real32_T Delay3_DSTATE_b;            /* '<S262>/Delay3' */
  real32_T Delay1_DSTATE_o;            /* '<S253>/Delay1' */
  real32_T Delay_DSTATE_ao;            /* '<S253>/Delay' */
  real32_T Delay1_DSTATE_n;            /* '<S254>/Delay1' */
  real32_T Delay_DSTATE_oe;            /* '<S254>/Delay' */
  real32_T Delay2_DSTATE_c;            /* '<S228>/Delay2' */
  real32_T Delay3_DSTATE_d;            /* '<S228>/Delay3' */
  real32_T Delay2_DSTATE_p;            /* '<S229>/Delay2' */
  real32_T Delay3_DSTATE_ds;           /* '<S229>/Delay3' */
  real32_T UnitDelay_DSTATE_d5[4];     /* '<S294>/Unit Delay' */
  real32_T Delay1_DSTATE_e;            /* '<S316>/Delay1' */
  real32_T Delay_DSTATE_m;             /* '<S316>/Delay' */
  real32_T UnitDelay_DSTATE_m;         /* '<S320>/Unit Delay' */
  real32_T Delay1_DSTATE_m;            /* '<S308>/Delay1' */
  real32_T Delay_DSTATE_p;             /* '<S308>/Delay' */
  real32_T UnitDelay_DSTATE_b;         /* '<S312>/Unit Delay' */
  real32_T UnitDelay_DSTATE_a1;        /* '<S323>/Unit Delay' */
  real32_T Delay_DSTATE_nd;            /* '<S328>/Delay' */
  real32_T Delay1_DSTATE_l;            /* '<S338>/Delay1' */
  real32_T Delay_DSTATE_e;             /* '<S329>/Delay' */
  real32_T Delay1_DSTATE_j;            /* '<S339>/Delay1' */
  real32_T Delay_DSTATE_nm;            /* '<S326>/Delay' */
  uint32_T Delay_DSTATE_ad[10];        /* '<S290>/Delay' */
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
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S375>/Digital Output1' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S366>/Digital Output' */
  int32_T Add_DWORK1[2];               /* '<S132>/Add' */
  int32_T DigitalOutput_FRAC_LEN_h;    /* '<S353>/Digital Output' */
  int32_T SpeedCount_DWORK1;           /* '<S290>/SpeedCount' */
  uint32_T Sum_DWORK1[4];              /* '<S452>/Sum' */
  uint32_T Sum_DWORK1_h[4];            /* '<S109>/Sum' */
  uint16_T Output_DSTATE;              /* '<S124>/Output' */
  volatile int16_T RT6_ActiveBufIdx;   /* '<S8>/RT6' */
  volatile int16_T RT6_semaphoreTaken; /* '<S8>/RT6' */
  volatile int16_T RT4_ActiveBufIdx;   /* '<Root>/RT4' */
  volatile int16_T RT4_semaphoreTaken; /* '<Root>/RT4' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory1' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory2' */
  uint16_T temporalCounter_i1;         /* '<S8>/State Machine OL - CL' */
  uint16_T Memory_PreviousInput;       /* '<S373>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S373>/Memory1' */
  uint16_T Add_DWORK1_o;               /* '<S355>/Add' */
  uint16_T CircBufIdx;                 /* '<S290>/Delay' */
  uint16_T CircBufIdx_n;               /* '<S333>/Delay' */
  boolean_T Delay_DSTATE_d;            /* '<S105>/Delay' */
  int16_T Integrator_PrevResetState;   /* '<S206>/Integrator' */
  uint16_T is_active_c3_mcb_pmsm_foc_senso;/* '<S8>/State Machine OL - CL' */
  uint16_T is_c3_mcb_pmsm_foc_sensorless_f;/* '<S8>/State Machine OL - CL' */
  uint16_T is_RunMode;                 /* '<S8>/State Machine OL - CL' */
  uint16_T is_NegativeSpeedRun;        /* '<S8>/State Machine OL - CL' */
  uint16_T is_PositiveSpeedRun;        /* '<S8>/State Machine OL - CL' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T EnClosedLoop;              /* '<Root>/Data Store Memory5' */
  boolean_T icLoad;                    /* '<S19>/Delay' */
  boolean_T AlphaRelay_Mode;           /* '<S155>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S155>/BetaRelay' */
  boolean_T AlphaRelay_Mode_c;         /* '<S327>/AlphaRelay' */
  boolean_T BetaRelay_Mode_j;          /* '<S327>/BetaRelay' */
  rtDW_SpeedControl_mcb_pmsm_foc_ SpeedControl;/* '<Root>/Speed Control' */
  rtDW_SPIMasterTransfer_mcb_pmsm SPIMasterTransfer1;/* '<S366>/SPI Master Transfer' */
  rtDW_SPIMasterTransfer_mcb_pmsm SPIMasterTransfer;/* '<S366>/SPI Master Transfer' */
  rtDW_MATLABFunction_mcb_pmsm_fo sf_MATLABFunction_d;/* '<S27>/MATLAB Function' */
  rtDW_MATLABFunction_mcb_pmsm_fo sf_MATLABFunction;/* '<S26>/MATLAB Function' */
} D_Work_mcb_pmsm_foc_sensorless_;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S19>/Delay' */
  ZCSigState Delay1_Reset_ZCE;         /* '<S137>/Delay1' */
  ZCSigState Delay_Reset_ZCE_g;        /* '<S138>/Delay' */
  ZCSigState Delay_Reset_ZCE_m;        /* '<S274>/Delay' */
  ZCSigState Delay2_Reset_ZCE;         /* '<S261>/Delay2' */
  ZCSigState Delay3_Reset_ZCE;         /* '<S261>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_g;       /* '<S262>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_g;       /* '<S262>/Delay3' */
  ZCSigState Delay1_Reset_ZCE_d;       /* '<S253>/Delay1' */
  ZCSigState Delay_Reset_ZCE_l;        /* '<S253>/Delay' */
  ZCSigState Delay1_Reset_ZCE_db;      /* '<S254>/Delay1' */
  ZCSigState Delay_Reset_ZCE_gg;       /* '<S254>/Delay' */
  ZCSigState Delay2_Reset_ZCE_p;       /* '<S228>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_p;       /* '<S228>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_h;       /* '<S229>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_c;       /* '<S229>/Delay3' */
  rtZCE_Dir_Sense_mcb_pmsm_foc_se Dir_Sense_m;/* '<S155>/Dir_Sense' */
  ZCSigState Delay1_Reset_ZCE_e;       /* '<S316>/Delay1' */
  ZCSigState Delay_Reset_ZCE_p;        /* '<S316>/Delay' */
  ZCSigState Delay1_Reset_ZCE_l;       /* '<S308>/Delay1' */
  ZCSigState Delay_Reset_ZCE_d;        /* '<S308>/Delay' */
  ZCSigState Delay_Reset_ZCE_n;        /* '<S328>/Delay' */
  ZCSigState Delay1_Reset_ZCE_b;       /* '<S338>/Delay1' */
  ZCSigState Delay_Reset_ZCE_ld;       /* '<S329>/Delay' */
  ZCSigState Delay1_Reset_ZCE_bl;      /* '<S339>/Delay1' */
  ZCSigState Delay_Reset_ZCE_n0;       /* '<S326>/Delay' */
  rtZCE_Dir_Sense_mcb_pmsm_foc_se Dir_Sense;/* '<S327>/Dir_Sense' */
} PrevZCSigStates_mcb_pmsm_foc_se;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T Width;                /* '<S10>/Width' */
} ConstBlockIO_mcb_pmsm_foc_senso;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S109>/sine_table_values'
   *   '<S452>/sine_table_values'
   *   '<S279>/sine_table_values'
   */
  real32_T pooled30[1002];
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
 * '<S42>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S43>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/IIR Filter'
 * '<S44>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/MATLAB Function'
 * '<S45>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S46>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S47>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S48>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S49>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S50>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S51>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S52>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S53>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S54>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S55>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S56>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S57>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S58>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S59>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S60>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S61>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S62>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S63>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S64>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S65>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S66>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S67>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S68>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S69>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S70>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S71>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S72>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S73>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S74>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S75>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S76>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S77>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S78>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S79>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S80>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S81>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S82>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S83>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S84>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S85>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S86>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S87>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S88>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S89>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S90>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S91>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S92>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S93>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S94>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S95>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S96>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S97>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S98>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S99>'  : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/IIR Filter/IIR Filter'
 * '<S100>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/IIR Filter/IIR Filter/Low-pass'
 * '<S101>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S102>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/MATLAB Function'
 * '<S103>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Inverse Park Transform/Two inputs CRL'
 * '<S104>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S105>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Open_Loop_Control/Accumulate1'
 * '<S106>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Open_Loop_Control/Accumulate1/Subsystem'
 * '<S107>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Park Transform/Two inputs CRL'
 * '<S108>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S109>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S110>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S111>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S112>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S113>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S114>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S115>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S116>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S117>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Modulation method'
 * '<S118>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Voltage Input'
 * '<S119>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Modulation method/SVPWM'
 * '<S120>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S121>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S122>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S123>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S124>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Counter Limited'
 * '<S125>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Data'
 * '<S126>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Data_Conditioning'
 * '<S127>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/End'
 * '<S128>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Start'
 * '<S129>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Counter Limited/Increment Real World'
 * '<S130>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S131>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/HW Inputs/Sensor Driver Blocks (codegen)'
 * '<S132>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate Phase Currents'
 * '<S133>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed'
 * '<S134>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer'
 * '<S135>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer'
 * '<S136>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer'
 * '<S137>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer'
 * '<S138>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer'
 * '<S139>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter'
 * '<S140>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/PerUnit'
 * '<S141>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer'
 * '<S142>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem'
 * '<S143>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem2'
 * '<S144>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/A11'
 * '<S145>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/A12'
 * '<S146>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/A22'
 * '<S147>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/L'
 * '<S148>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/L1'
 * '<S149>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/L2'
 * '<S150>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem2/B'
 * '<S151>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem2/L'
 * '<S152>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter/IIR Filter'
 * '<S153>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S154>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S155>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch'
 * '<S156>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL'
 * '<S157>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch/Dir_Sense'
 * '<S158>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem2'
 * '<S159>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem3'
 * '<S160>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter'
 * '<S161>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Normalize'
 * '<S162>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller'
 * '<S163>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward'
 * '<S164>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Subsystem'
 * '<S165>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO'
 * '<S166>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter'
 * '<S167>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass'
 * '<S168>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S169>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Normalize/Compare To Zero'
 * '<S170>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Normalize/If Action Subsystem'
 * '<S171>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Normalize/Subsystem'
 * '<S172>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup'
 * '<S173>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain'
 * '<S174>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative'
 * '<S175>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter'
 * '<S176>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs'
 * '<S177>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain'
 * '<S178>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain'
 * '<S179>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S180>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator'
 * '<S181>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs'
 * '<S182>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy'
 * '<S183>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain'
 * '<S184>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy'
 * '<S185>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain'
 * '<S186>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal'
 * '<S187>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation'
 * '<S188>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk'
 * '<S189>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum'
 * '<S190>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk'
 * '<S191>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode'
 * '<S192>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum'
 * '<S193>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral'
 * '<S194>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain'
 * '<S195>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal'
 * '<S196>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal'
 * '<S197>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal'
 * '<S198>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup/Passthrough'
 * '<S199>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain/Disabled'
 * '<S200>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative/Disabled'
 * '<S201>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter/Disabled'
 * '<S202>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs/Disabled'
 * '<S203>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain/Internal Parameters'
 * '<S204>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S205>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S206>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator/Discrete'
 * '<S207>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S208>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S209>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain/Disabled'
 * '<S210>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy/Disabled'
 * '<S211>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S212>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal/External Reset'
 * '<S213>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation/Passthrough'
 * '<S214>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S215>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum/Sum_PI'
 * '<S216>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S217>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S218>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S219>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S220>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S221>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S222>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal/Internal PreInt'
 * '<S223>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S224>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod'
 * '<S225>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter'
 * '<S226>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod'
 * '<S227>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod'
 * '<S228>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Differentiator'
 * '<S229>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Differentiator1'
 * '<S230>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter1'
 * '<S231>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter2'
 * '<S232>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter3'
 * '<S233>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem'
 * '<S234>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S235>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S236>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S237>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter2/IIR Filter'
 * '<S238>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter2/IIR Filter/Low-pass'
 * '<S239>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter2/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S240>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S241>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S242>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S243>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant'
 * '<S244>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant1'
 * '<S245>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant2'
 * '<S246>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant4'
 * '<S247>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant5'
 * '<S248>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter'
 * '<S249>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass'
 * '<S250>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S251>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1'
 * '<S252>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3'
 * '<S253>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator'
 * '<S254>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator1'
 * '<S255>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter'
 * '<S256>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S257>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S258>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter'
 * '<S259>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S260>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S261>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator'
 * '<S262>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator1'
 * '<S263>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1'
 * '<S264>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3'
 * '<S265>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S266>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S267>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S268>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S269>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S270>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S271>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem'
 * '<S272>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem1'
 * '<S273>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem'
 * '<S274>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased'
 * '<S275>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator'
 * '<S276>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup'
 * '<S277>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator/Accumulate'
 * '<S278>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator/Accumulate/Subsystem'
 * '<S279>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S280>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S281>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S282>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S283>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S284>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S285>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S286>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S287>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1'
 * '<S288>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer'
 * '<S289>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter'
 * '<S290>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement'
 * '<S291>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1/IIR Filter'
 * '<S292>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1/IIR Filter/IIR Filter'
 * '<S293>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1/IIR Filter/IIR Filter/High-pass'
 * '<S294>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal1/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S295>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2'
 * '<S296>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Data type Handling'
 * '<S297>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Flux Calculation'
 * '<S298>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/ParamBus'
 * '<S299>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/passthrough'
 * '<S300>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha'
 * '<S301>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta'
 * '<S302>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default'
 * '<S303>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2'
 * '<S304>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2/Per Unit'
 * '<S305>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default'
 * '<S306>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc'
 * '<S307>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter'
 * '<S308>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Integrator'
 * '<S309>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Scaling'
 * '<S310>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S311>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S312>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S313>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default'
 * '<S314>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc'
 * '<S315>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter'
 * '<S316>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Integrator'
 * '<S317>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Scaling'
 * '<S318>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S319>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S320>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S321>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter'
 * '<S322>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S323>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S324>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle'
 * '<S325>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S326>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1'
 * '<S327>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch'
 * '<S328>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ealpha_est'
 * '<S329>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ebeta_est'
 * '<S330>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha'
 * '<S331>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta'
 * '<S332>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter'
 * '<S333>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Speed Measurement'
 * '<S334>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/angleCompensation'
 * '<S335>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch/Dir_Sense'
 * '<S336>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch/Subsystem2'
 * '<S337>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch/Subsystem3'
 * '<S338>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ealpha_est/DisturbanceObserver'
 * '<S339>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ebeta_est/DisturbanceObserver'
 * '<S340>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha/IIR Filter'
 * '<S341>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha/IIR Filter/Low-pass'
 * '<S342>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S343>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta/IIR Filter'
 * '<S344>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta/IIR Filter/Low-pass'
 * '<S345>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S346>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter/IIR Filter'
 * '<S347>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter/IIR Filter/Low-pass'
 * '<S348>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S349>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Speed Measurement/DT_Handle'
 * '<S350>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Speed Measurement/DT_Handle/floating-point'
 * '<S351>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/angleCompensation/atan1'
 * '<S352>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/angleCompensation/atan1/Per Unit'
 * '<S353>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/Inverter/Code Generation'
 * '<S354>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/SCI_Tx/Code Generation'
 * '<S355>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Current Control/SCI_Tx/Code Generation/CodeGeneration'
 * '<S356>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation'
 * '<S357>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_ADCINT1'
 * '<S358>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_SCIRXINTA'
 * '<S359>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_ADCINT1/ECSoC'
 * '<S360>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_ADCINT1/ECSoC/ECSimCodegen'
 * '<S361>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_SCIRXINTA/ECSoC'
 * '<S362>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/HW Interrrupt/Code generation/HWI_SCIRXINTA/ECSoC/ECSimCodegen'
 * '<S363>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem'
 * '<S364>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation'
 * '<S365>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset '
 * '<S366>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/DRV Enable'
 * '<S367>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Default ADC Offset'
 * '<S368>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem'
 * '<S369>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem'
 * '<S370>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem1'
 * '<S371>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem2'
 * '<S372>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem3'
 * '<S373>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S374>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Heartbeat LED/Heartbeat LED'
 * '<S375>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Heartbeat LED/Heartbeat LED/Code generation'
 * '<S376>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Inverter and Motor - Plant Model/Codegeneration'
 * '<S377>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Serial Receive/Data_Conditioning'
 * '<S378>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Serial Receive/SCI_Rx'
 * '<S379>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Serial Receive/SCI_Rx/Code Generation'
 * '<S380>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed'
 * '<S381>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/SlewRate'
 * '<S382>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S383>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/MATLAB Function'
 * '<S384>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S385>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S386>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S387>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S388>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S389>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S390>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S391>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S392>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S393>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S394>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S395>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S396>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S397>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S398>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S399>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S400>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S401>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S402>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S403>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S404>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S405>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S406>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S407>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S408>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S409>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S410>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S411>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S412>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S413>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S414>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S415>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S416>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S417>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S418>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S419>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S420>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S421>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S422>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S423>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S424>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S425>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S426>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S427>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S428>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S429>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S430>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S431>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S432>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S433>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S434>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S435>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S436>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S437>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S438>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S439>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S440>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S441>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S442>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values'
 * '<S443>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/State Machine OL - CL'
 * '<S444>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Clarke Transform'
 * '<S445>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/I Park Transform'
 * '<S446>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup'
 * '<S447>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/V Park Transform'
 * '<S448>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Clarke Transform/Two phase input'
 * '<S449>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S450>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/I Park Transform/Two inputs CRL'
 * '<S451>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/I Park Transform/Two inputs CRL/Switch_Axis'
 * '<S452>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S453>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S454>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S455>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S456>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S457>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S458>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S459>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S460>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/V Park Transform/Two inputs CRL'
 * '<S461>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/Compute Control-loop Initial Values/V Park Transform/Two inputs CRL/Switch_Axis'
 * '<S462>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/State Machine OL - CL/RunMode.ComputeId0'
 * '<S463>' : 'mcb_pmsm_foc_sensorless_f28069MLaunchPad/State Machine Handler/State Machine OL - CL/RunMode.ComputeId0/Compare To Constant'
 */
#endif                         /* mcb_pmsm_foc_sensorless_f28069MLaunchPad_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
