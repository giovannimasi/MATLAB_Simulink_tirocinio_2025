/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_sensorless_dyno_f28379d.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_sensorless_dyno_f28379d'.
 *
 * Model version                  : 9.123
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Jun 20 11:21:06 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_pmsm_foc_sensorless_dyno_f28379d_h_
#define mcb_pmsm_foc_sensorless_dyno_f28379d_h_
#ifndef mcb_pmsm_foc_sensorless_dyno_f28379d_COMMON_INCLUDES_
#define mcb_pmsm_foc_sensorless_dyno_f28379d_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "string.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "DSP28xx_SciUtil.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif               /* mcb_pmsm_foc_sensorless_dyno_f28379d_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "mcb_pmsm_foc_sensorless_dyno_f28379d_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>
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

#define mcb_pmsm_foc_sensorless_dyno_f28379d_M (mcb_pmsm_foc_sensorless_dyno_M)

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* user code (top of header file) */
#include "F2837xD_Ipc_drivers.h"

/* Block signals for system '<S34>/Two phase CRL wrap' */
typedef struct {
  real32_T a_plus_2b;                  /* '<S35>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S35>/one_by_sqrt3' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} rtB_TwophaseCRLwrap_mcb_pmsm_fo;

/* Block signals for system '<S36>/D//Q Axis Priority' */
typedef struct {
  real32_T Switch[2];                  /* '<S41>/Switch' */
  real32_T Switch2;                    /* '<S51>/Switch2' */
  real32_T Product;                    /* '<S50>/Product' */
  real32_T Sum;                        /* '<S50>/Sum' */
  real32_T Product2;                   /* '<S50>/Product2' */
  real32_T Merge;                      /* '<S50>/Merge' */
  real32_T Gain;                       /* '<S50>/Gain' */
  real32_T Switch_a;                   /* '<S51>/Switch' */
  real32_T Switch1;                    /* '<S52>/Switch1' */
  real32_T Sqrt;                       /* '<S52>/Sqrt' */
  real32_T Gain_l;                     /* '<S52>/Gain' */
  uint16_T DataTypeConversion;         /* '<S50>/Data Type Conversion' */
  boolean_T Compare;                   /* '<S46>/Compare' */
  boolean_T Compare_k;                 /* '<S47>/Compare' */
  boolean_T LowerRelop1;               /* '<S51>/LowerRelop1' */
  boolean_T RelationalOperator;        /* '<S50>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S51>/UpperRelop' */
} rtB_DQAxisPriority_mcb_pmsm_foc;

/* Block signals for system '<S36>/D-Q Equivalence' */
typedef struct {
  real32_T Product[2];                 /* '<S44>/Product' */
  real32_T SquareRoot;                 /* '<S44>/Square Root' */
  real32_T Switch;                     /* '<S44>/Switch' */
  uint16_T DataTypeConversion;         /* '<S40>/Data Type Conversion' */
  boolean_T RelationalOperator;        /* '<S40>/Relational Operator' */
} rtB_DQEquivalence_mcb_pmsm_foc_;

/* Block signals for system '<S29>/Two inputs CRL' */
typedef struct {
  real32_T qcos;                       /* '<S165>/qcos' */
  real32_T dsin;                       /* '<S165>/dsin' */
  real32_T sum_beta;                   /* '<S165>/sum_beta' */
  real32_T dcos;                       /* '<S165>/dcos' */
  real32_T qsin;                       /* '<S165>/qsin' */
  real32_T sum_alpha;                  /* '<S165>/sum_alpha' */
  real32_T Switch[2];                  /* '<S166>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} rtB_TwoinputsCRL_mcb_pmsm_foc_s;

/* Block signals for system '<S31>/Two inputs CRL' */
typedef struct {
  real32_T acos_k;                     /* '<S170>/acos' */
  real32_T bsin;                       /* '<S170>/bsin' */
  real32_T sum_Ds;                     /* '<S170>/sum_Ds' */
  real32_T bcos;                       /* '<S170>/bcos' */
  real32_T asin_m;                     /* '<S170>/asin' */
  real32_T sum_Qs;                     /* '<S170>/sum_Qs' */
  real32_T Switch[2];                  /* '<S171>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} rtB_TwoinputsCRL_mcb_pmsm_foc_k;

/* Block signals for system '<S174>/If Action Subsystem' */
typedef struct {
  real32_T Convert_back;               /* '<S177>/Convert_back' */
  int16_T Convert_uint16;              /* '<S177>/Convert_uint16' */
} rtB_IfActionSubsystem_mcb_pmsm_;

/* Block signals for system '<S174>/If Action Subsystem1' */
typedef struct {
  real32_T Convert_back;               /* '<S178>/Convert_back' */
  int16_T Convert_uint16;              /* '<S178>/Convert_uint16' */
} rtB_IfActionSubsystem1_mcb_pmsm;

/* Block signals for system '<S234>/Dir_Sense' */
typedef struct {
  int16_T Switch;                      /* '<S242>/Switch' */
  boolean_T LogicalOperator;           /* '<S242>/Logical Operator' */
} rtB_Dir_Sense_mcb_pmsm_foc_sens;

/* Zero-crossing (trigger) state for system '<S234>/Dir_Sense' */
typedef struct {
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S234>/Dir_Sense' */
} rtZCE_Dir_Sense_mcb_pmsm_foc_se;

/* Block signals for system '<S233>/angleCompensation' */
typedef struct {
  real32_T Product;                    /* '<S241>/Product' */
  real32_T Product2;                   /* '<S241>/Product2' */
  real32_T Sum1;                       /* '<S241>/Sum1' */
  real32_T Product1;                   /* '<S241>/Product1' */
  real32_T Product3;                   /* '<S241>/Product3' */
  real32_T Sum2;                       /* '<S241>/Sum2' */
  real32_T Switch;                     /* '<S241>/Switch' */
  real32_T Atan2;                      /* '<S258>/Atan2' */
  real32_T Switch_e;                   /* '<S258>/Switch' */
  real32_T algDD;
  real32_T Gain;                       /* '<S259>/Gain' */
  real32_T Switch_p;                   /* '<S259>/Switch' */
  real32_T Bias;                       /* '<S259>/Bias' */
  real32_T Bias_a;                     /* '<S241>/Bias' */
} rtB_angleCompensation_mcb_pmsm_;

/* Block signals for system '<S189>/Flux Observer' */
typedef struct {
  uint32_T PositionToCount;            /* '<S197>/PositionToCount' */
  uint32_T Delay;                      /* '<S197>/Delay' */
  real32_T Switch1[2];                 /* '<S198>/Switch1' */
  real32_T Product[4];                 /* '<S201>/Product' */
  real32_T UnitDelay[4];               /* '<S201>/Unit Delay' */
  real32_T Product1[4];                /* '<S201>/Product1' */
  real32_T Add1[4];                    /* '<S201>/Add1' */
  real32_T Sum6[4];                    /* '<S194>/Sum6' */
  real32_T Product_c;                  /* '<S224>/Product' */
  real32_T Sum3;                       /* '<S221>/Sum3' */
  real32_T Delay1;                     /* '<S223>/Delay1' */
  real32_T Sum;                        /* '<S223>/Sum' */
  real32_T Product_f;                  /* '<S223>/Product' */
  real32_T Delay_k;                    /* '<S223>/Delay' */
  real32_T Product1_b;                 /* '<S223>/Product1' */
  real32_T Sum1;                       /* '<S223>/Sum1' */
  real32_T Product2;                   /* '<S224>/Product2' */
  real32_T Sum1_c;                     /* '<S221>/Sum1' */
  real32_T Sum_i;                      /* '<S222>/Sum' */
  real32_T Switch1_k[2];               /* '<S222>/Switch1' */
  real32_T Product_m;                  /* '<S227>/Product' */
  real32_T UnitDelay_c;                /* '<S227>/Unit Delay' */
  real32_T Product1_n;                 /* '<S227>/Product1' */
  real32_T Add1_p;                     /* '<S227>/Add1' */
  real32_T Switch;                     /* '<S220>/Switch' */
  real32_T Product_n;                  /* '<S216>/Product' */
  real32_T Sum3_a;                     /* '<S213>/Sum3' */
  real32_T Delay1_a;                   /* '<S215>/Delay1' */
  real32_T Sum_e;                      /* '<S215>/Sum' */
  real32_T Product_e;                  /* '<S215>/Product' */
  real32_T Delay_f;                    /* '<S215>/Delay' */
  real32_T Product1_i;                 /* '<S215>/Product1' */
  real32_T Sum1_cf;                    /* '<S215>/Sum1' */
  real32_T Product2_e;                 /* '<S216>/Product2' */
  real32_T Sum1_n;                     /* '<S213>/Sum1' */
  real32_T Sum_iu;                     /* '<S214>/Sum' */
  real32_T Switch1_p[2];               /* '<S214>/Switch1' */
  real32_T Product_nb;                 /* '<S219>/Product' */
  real32_T UnitDelay_a;                /* '<S219>/Unit Delay' */
  real32_T Product1_a;                 /* '<S219>/Product1' */
  real32_T Add1_l;                     /* '<S219>/Add1' */
  real32_T Switch_h;                   /* '<S212>/Switch' */
  real32_T DTC;                        /* '<S232>/DTC' */
  real32_T SpeedGain;                  /* '<S197>/SpeedGain' */
  real32_T Switch1_c[2];               /* '<S196>/Switch1' */
  real32_T Product_d;                  /* '<S230>/Product' */
  real32_T UnitDelay_m;                /* '<S230>/Unit Delay' */
  real32_T Product1_d;                 /* '<S230>/Product1' */
  real32_T Add1_h;                     /* '<S230>/Add1' */
  real32_T elect2mech;                 /* '<S192>/elect2mech' */
  real32_T Sum_j;                      /* '<S226>/Sum' */
  real32_T Sum_c;                      /* '<S218>/Sum' */
  real32_T Atan2;                      /* '<S210>/Atan2' */
  real32_T Switch_b;                   /* '<S210>/Switch' */
  real32_T algDD;
  real32_T Gain;                       /* '<S211>/Gain' */
  real32_T Switch_a;                   /* '<S211>/Switch' */
  real32_T Bias;                       /* '<S211>/Bias' */
  int32_T SpeedCount;                  /* '<S197>/SpeedCount' */
  boolean_T DataStoreRead1;            /* '<S192>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S192>/Logical Operator' */
} rtB_FluxObserver_mcb_pmsm_foc_s;

/* Block states (default storage) for system '<S189>/Flux Observer' */
typedef struct {
  real32_T UnitDelay_DSTATE[4];        /* '<S201>/Unit Delay' */
  real32_T Delay1_DSTATE;              /* '<S223>/Delay1' */
  real32_T Delay_DSTATE;               /* '<S223>/Delay' */
  real32_T UnitDelay_DSTATE_b;         /* '<S227>/Unit Delay' */
  real32_T Delay1_DSTATE_c;            /* '<S215>/Delay1' */
  real32_T Delay_DSTATE_c;             /* '<S215>/Delay' */
  real32_T UnitDelay_DSTATE_c;         /* '<S219>/Unit Delay' */
  real32_T UnitDelay_DSTATE_f;         /* '<S230>/Unit Delay' */
  uint32_T Delay_DSTATE_l[10];         /* '<S197>/Delay' */
  int32_T SpeedCount_DWORK1;           /* '<S197>/SpeedCount' */
  uint16_T CircBufIdx;                 /* '<S197>/Delay' */
} rtDW_FluxObserver_mcb_pmsm_foc_;

/* Zero-crossing (trigger) state for system '<S189>/Flux Observer' */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S223>/Delay1' */
  ZCSigState Delay_Reset_ZCE;          /* '<S223>/Delay' */
  ZCSigState Delay1_Reset_ZCE_b;       /* '<S215>/Delay1' */
  ZCSigState Delay_Reset_ZCE_g;        /* '<S215>/Delay' */
} rtZCE_FluxObserver_mcb_pmsm_foc;

/* Block signals for system '<S522>/If Action Subsystem' */
typedef struct {
  uint16_T Memory;                     /* '<S527>/Memory' */
  uint16_T Sum;                        /* '<S527>/Sum' */
  uint16_T Memory1;                    /* '<S527>/Memory1' */
  uint16_T Sum1;                       /* '<S527>/Sum1' */
} rtB_IfActionSubsystem_mcb_pms_h;

/* Block states (default storage) for system '<S522>/If Action Subsystem' */
typedef struct {
  uint16_T Memory_PreviousInput;       /* '<S527>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S527>/Memory1' */
} rtDW_IfActionSubsystem_mcb_pm_n;

/* Block signals for system '<S519>/SPI Master Transfer' */
typedef struct {
  uint16_T SPIMasterTransfer;          /* '<S519>/SPI Master Transfer' */
} rtB_SPIMasterTransfer_mcb_pmsm_;

/* Block states (default storage) for system '<S519>/SPI Master Transfer' */
typedef struct {
  codertarget_tic2000_blocks_SPIM obj; /* '<S519>/SPI Master Transfer' */
  boolean_T objisempty;                /* '<S519>/SPI Master Transfer' */
} rtDW_SPIMasterTransfer_mcb_pmsm;

/* Block signals for system '<S519>/SPI Master Transfer2' */
typedef struct {
  uint16_T SPIMasterTransfer2;         /* '<S519>/SPI Master Transfer2' */
} rtB_SPIMasterTransfer2_mcb_pmsm;

/* Block states (default storage) for system '<S519>/SPI Master Transfer2' */
typedef struct {
  codertarget_tic2000_blocks_SPIM obj; /* '<S519>/SPI Master Transfer2' */
  boolean_T objisempty;                /* '<S519>/SPI Master Transfer2' */
} rtDW_SPIMasterTransfer2_mcb_pms;

/* Block signals for system '<Root>/Speed Control' */
typedef struct {
  real_T TmpSignalConversionAtSFunctionI[8];/* '<S612>/MATLAB Function2' */
  real32_T Id_Ref;                     /* '<S8>/Id_Ref' */
  real32_T Merge;                      /* '<S8>/Merge' */
  real32_T Speed_Ref;                  /* '<S611>/Switch' */
  real32_T Switch1[2];                 /* '<S614>/Switch1' */
  real32_T Product;                    /* '<S671>/Product' */
  real32_T UnitDelay;                  /* '<S671>/Unit Delay' */
  real32_T Product1;                   /* '<S671>/Product1' */
  real32_T Add1;                       /* '<S671>/Add1' */
  real32_T Sum;                        /* '<S608>/Sum' */
  real32_T PProdOut;                   /* '<S656>/PProd Out' */
  real32_T Ki2;                        /* '<S608>/Ki2' */
  real32_T Integrator;                 /* '<S651>/Integrator' */
  real32_T Sum_p;                      /* '<S660>/Sum' */
  real32_T ManualSwitch;               /* '<S8>/Manual Switch' */
  real32_T DeadZone;                   /* '<S643>/DeadZone' */
  real32_T IProdOut;                   /* '<S648>/IProd Out' */
  real32_T Switch;                     /* '<S641>/Switch' */
  real32_T Saturation;                 /* '<S658>/Saturation' */
  real32_T RateLimiter;                /* '<S610>/Rate Limiter' */
  real32_T RateLimiter1;               /* '<S610>/Rate Limiter1' */
  real32_T speed_mech_rpm;             /* '<S612>/PU2rpm' */
  real32_T rpm2rad;                    /* '<S612>/rpm2rad' */
  real32_T speed_e;                    /* '<S612>/Gain' */
  real32_T UnitDelay_f;                /* '<S612>/Unit Delay' */
  real32_T UnitDelay1;                 /* '<S612>/Unit Delay1' */
  real32_T speed_ref_rpm;              /* '<S612>/PU2rpm1' */
  real32_T rpm2rad1;                   /* '<S612>/rpm2rad1' */
  real32_T speed_ref;                  /* '<S612>/Gain1' */
  real32_T UnitDelay2;                 /* '<S612>/Unit Delay2' */
  real32_T UnitDelay3;                 /* '<S612>/Unit Delay3' */
  real32_T UnitDelay4;                 /* '<S612>/Unit Delay4' */
  real32_T A2PU;                       /* '<S612>/A2PU' */
  real32_T Iq_ref;                     /* '<S612>/MATLAB Function2' */
  real32_T sw;                         /* '<S612>/MATLAB Function2' */
  real32_T DataStoreRead;              /* '<S611>/Data Store Read' */
  real32_T Switch1_n;                  /* '<S611>/Switch1' */
  int16_T Switch1_h;                   /* '<S641>/Switch1' */
  int16_T Switch2;                     /* '<S641>/Switch2' */
  boolean_T DataStoreRead1;            /* '<S8>/Data Store Read1' */
  boolean_T DataStoreRead2;            /* '<S8>/Data Store Read2' */
  boolean_T AND;                       /* '<S8>/AND' */
  boolean_T DataStoreRead1_e;          /* '<S611>/Data Store Read1' */
  boolean_T DataStoreRead1_g;          /* '<S608>/Data Store Read1' */
  boolean_T DataStoreRead2_n;          /* '<S608>/Data Store Read2' */
  boolean_T AND_j;                     /* '<S608>/AND' */
  boolean_T LogicalOperator;           /* '<S608>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S641>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S641>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S641>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S641>/Equal1' */
  boolean_T AND3;                      /* '<S641>/AND3' */
} rtB_SpeedControl_mcb_pmsm_foc_s;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S671>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S651>/Integrator' */
  real32_T UnitDelay_DSTATE_e;         /* '<S612>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S612>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S612>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE;          /* '<S612>/Unit Delay3' */
  real32_T UnitDelay4_DSTATE;          /* '<S612>/Unit Delay4' */
  real32_T PrevY;                      /* '<S610>/Rate Limiter' */
  real32_T PrevY_a;                    /* '<S610>/Rate Limiter1' */
  int16_T Integrator_PrevResetState;   /* '<S651>/Integrator' */
} rtDW_SpeedControl_mcb_pmsm_foc_;

/* Block signals (default storage) */
typedef struct {
  real_T T_load;                       /* '<S6>/T_load' */
  real_T DiscreteTimeIntegrator;       /* '<S545>/Discrete-Time Integrator' */
  real_T Gain;                         /* '<S6>/Gain' */
  real_T DiscreteTimeIntegrator3;      /* '<S592>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator3_a;    /* '<S593>/Discrete-Time Integrator3' */
  real_T Switch2;                      /* '<S6>/Switch2' */
  real_T Switch1[2];                   /* '<S537>/Switch1' */
  real_T Product;                      /* '<S542>/Product' */
  real_T UnitDelay;                    /* '<S542>/Unit Delay' */
  real_T Product1;                     /* '<S542>/Product1' */
  real_T Add1;                         /* '<S542>/Add1' */
  real_T DiscreteTimeIntegrator3_g;    /* '<S563>/Discrete-Time Integrator3' */
  real_T UnitDelay_b;                  /* '<S548>/Unit Delay' */
  real_T Switch1_g;                    /* '<S548>/Switch1' */
  real_T Gain4;                        /* '<S545>/Gain4' */
  real_T sine_cosine_o1;               /* '<S547>/sine_cosine' */
  real_T sine_cosine_o2;               /* '<S547>/sine_cosine' */
  real_T Product2;                     /* '<S558>/Product2' */
  real_T DiscreteTimeIntegrator3_b;    /* '<S564>/Discrete-Time Integrator3' */
  real_T Product3;                     /* '<S558>/Product3' */
  real_T Add1_c;                       /* '<S558>/Add1' */
  real_T Product_a;                    /* '<S559>/Product' */
  real_T Product_i;                    /* '<S562>/Product' */
  real_T Gain1;                        /* '<S559>/Gain1' */
  real_T Add;                          /* '<S559>/Add' */
  real_T Gain2;                        /* '<S559>/Gain2' */
  real_T Divide2;                      /* '<S545>/Divide2' */
  real_T Sign;                         /* '<S545>/Sign' */
  real_T Divide1;                      /* '<S545>/Divide1' */
  real_T Sum1;                         /* '<S545>/Sum1' */
  real_T Divide;                       /* '<S545>/Divide' */
  real_T Gain_o;                       /* '<S545>/Gain' */
  real_T Gain1_b;                      /* '<S548>/Gain1' */
  real_T Add_h;                        /* '<S548>/Add' */
  real_T Gain_f;                       /* '<S556>/Gain' */
  real_T Gain1_j;                      /* '<S556>/Gain1' */
  real_T Gain4_n;                      /* '<S556>/Gain4' */
  real_T Add_b;                        /* '<S556>/Add' */
  real_T Gain2_p;                      /* '<S556>/Gain2' */
  real_T Gain3;                        /* '<S556>/Gain3' */
  real_T Add1_e;                       /* '<S556>/Add1' */
  real_T Gain1_e;                      /* '<S557>/Gain1' */
  real_T Gain2_k;                      /* '<S557>/Gain2' */
  real_T Product_h;                    /* '<S558>/Product' */
  real_T Product1_k;                   /* '<S558>/Product1' */
  real_T Add_c;                        /* '<S558>/Add' */
  real_T Gain3_a;                      /* '<S557>/Gain3' */
  real_T Gain4_l;                      /* '<S557>/Gain4' */
  real_T Product2_j;                   /* '<S561>/Product2' */
  real_T Product3_o;                   /* '<S561>/Product3' */
  real_T Add1_o;                       /* '<S561>/Add1' */
  real_T Product_d;                    /* '<S565>/Product' */
  real_T Product_o;                    /* '<S563>/Product' */
  real_T Product_iz;                   /* '<S566>/Product' */
  real_T Product_hf;                   /* '<S567>/Product' */
  real_T Add_m;                        /* '<S563>/Add' */
  real_T Product_c;                    /* '<S561>/Product' */
  real_T Product1_j;                   /* '<S561>/Product1' */
  real_T Add_o;                        /* '<S561>/Add' */
  real_T Product_e;                    /* '<S568>/Product' */
  real_T Product_l;                    /* '<S564>/Product' */
  real_T Product_p;                    /* '<S569>/Product' */
  real_T Product_ig;                   /* '<S570>/Product' */
  real_T Product_pc;                   /* '<S571>/Product' */
  real_T Add_e;                        /* '<S564>/Add' */
  real_T VectorConcatenate[3];         /* '<S544>/Vector Concatenate' */
  real_T UnitDelay_bu;                 /* '<S577>/Unit Delay' */
  real_T Switch1_h;                    /* '<S577>/Switch1' */
  real_T Gain4_d;                      /* '<S574>/Gain4' */
  real_T sine_cosine_o1_m;             /* '<S576>/sine_cosine' */
  real_T sine_cosine_o2_h;             /* '<S576>/sine_cosine' */
  real_T Product2_i;                   /* '<S587>/Product2' */
  real_T Product3_g;                   /* '<S587>/Product3' */
  real_T Add1_f;                       /* '<S587>/Add1' */
  real_T Gain_b;                       /* '<S574>/Gain' */
  real_T Gain1_h;                      /* '<S577>/Gain1' */
  real_T Add_hz;                       /* '<S577>/Add' */
  real_T Switch1_h2[3];                /* '<S6>/Switch1' */
  real_T Gain_j;                       /* '<S585>/Gain' */
  real_T Gain1_o;                      /* '<S585>/Gain1' */
  real_T Gain4_la;                     /* '<S585>/Gain4' */
  real_T Add_a;                        /* '<S585>/Add' */
  real_T Gain2_i;                      /* '<S585>/Gain2' */
  real_T Gain3_f;                      /* '<S585>/Gain3' */
  real_T Add1_n;                       /* '<S585>/Add1' */
  real_T Gain1_o0;                     /* '<S586>/Gain1' */
  real_T Gain2_m;                      /* '<S586>/Gain2' */
  real_T Product_df;                   /* '<S587>/Product' */
  real_T Product1_b;                   /* '<S587>/Product1' */
  real_T Add_p;                        /* '<S587>/Add' */
  real_T Gain3_fw;                     /* '<S586>/Gain3' */
  real_T Gain4_g;                      /* '<S586>/Gain4' */
  real_T Product2_f;                   /* '<S590>/Product2' */
  real_T Product3_i;                   /* '<S590>/Product3' */
  real_T Add1_p;                       /* '<S590>/Add1' */
  real_T Product_n;                    /* '<S594>/Product' */
  real_T Product_f;                    /* '<S592>/Product' */
  real_T Product_k;                    /* '<S595>/Product' */
  real_T Product_fj;                   /* '<S596>/Product' */
  real_T Add_p3;                       /* '<S592>/Add' */
  real_T Product_fo;                   /* '<S590>/Product' */
  real_T Product1_n;                   /* '<S590>/Product1' */
  real_T Add_n;                        /* '<S590>/Add' */
  real_T Product_dy;                   /* '<S597>/Product' */
  real_T Product_ne;                   /* '<S593>/Product' */
  real_T Product_em;                   /* '<S598>/Product' */
  real_T Product_b;                    /* '<S599>/Product' */
  real_T Product_lp;                   /* '<S600>/Product' */
  real_T Add_l;                        /* '<S593>/Add' */
  real_T VectorConcatenate_i[3];       /* '<S573>/Vector Concatenate' */
  real_T Gain1_d;                      /* '<S588>/Gain1' */
  real_T Product_g;                    /* '<S588>/Product' */
  real_T Product_m;                    /* '<S591>/Product' */
  real_T Add_g;                        /* '<S588>/Add' */
  real_T Gain2_c;                      /* '<S588>/Gain2' */
  real_T Add1_oo;                      /* '<S577>/Add1' */
  real_T Switch;                       /* '<S577>/Switch' */
  real_T Subtract;                     /* '<S577>/Subtract' */
  real_T Add1_j;                       /* '<S548>/Add1' */
  real_T Switch_e;                     /* '<S548>/Switch' */
  real_T Subtract_g;                   /* '<S548>/Subtract' */
  real_T TmpSignalConversionAtSFunctionI[11];/* '<S39>/MATLAB Function' */
  uint32_T Sum[4];                     /* '<S419>/Sum' */
  uint32_T PositionToCount;            /* '<S491>/PositionToCount' */
  uint32_T Delay;                      /* '<S491>/Delay' */
  uint32_T Sum_o[4];                   /* '<S172>/Sum' */
  uint32_T BytePack[2];                /* '<S266>/Byte Pack' */
  uint32_T SCI_Tx_Data[3];             /* '<S264>/Merge' */
  uint32_T SCI_Tx_Iteration;           /* '<S264>/Merge1' */
  uint32_T IndexVector;                /* '<S265>/Index Vector' */
  uint32_T Add_ci;                     /* '<S265>/Add' */
  uint32_T Data[2];                    /* '<S268>/Data' */
  uint32_T Data_f[2];                  /* '<S269>/Data' */
  uint32_T Data_fw[2];                 /* '<S270>/Data' */
  uint32_T PositionToCount_i;          /* '<S240>/PositionToCount' */
  uint32_T Delay_n;                    /* '<S240>/Delay' */
  real32_T RT_f;                       /* '<Root>/RT' */
  real32_T RT3;                        /* '<Root>/RT3' */
  real32_T RateTransition3;            /* '<Root>/Rate Transition3' */
  real32_T RT2[2];                     /* '<Root>/RT2' */
  real32_T mtr2_VI_debug[6];           /* '<Root>/RT8' */
  real32_T mtr2_Te_PU;                 /* '<Root>/RT8' */
  real32_T mtr2_Pm_PU;                 /* '<Root>/RT8' */
  real32_T mtr2_Speed_PU;              /* '<Root>/RT8' */
  real32_T mtr2_Iab_meas_PU[2];        /* '<Root>/RT8' */
  real32_T mtr2_Pos_PU;                /* '<Root>/RT8' */
  real32_T RT6[2];                     /* '<Root>/RT6' */
  real32_T Switch1_b[2];               /* '<S673>/Switch1' */
  real32_T Product_i1[2];              /* '<S676>/Product' */
  real32_T UnitDelay_f[2];             /* '<S676>/Unit Delay' */
  real32_T Product1_g[2];              /* '<S676>/Product1' */
  real32_T Add1_i[2];                  /* '<S676>/Add1' */
  real32_T DataTypeConversion;         /* '<S6>/Data Type Conversion' */
  real32_T SCIReceive[3];              /* '<S607>/SCI Receive' */
  real32_T OutportBufferForDesriedIqref;/* '<S7>/Parse SCI Rx' */
  real32_T GetADCVoltage[2];           /* '<S442>/Get ADC Voltage' */
  real32_T GetCurrents[2];             /* '<S442>/Get Currents' */
  real32_T PU_Conversion[2];           /* '<S442>/PU_Conversion' */
  real32_T Delay_j[4];                 /* '<S3>/Delay' */
  real32_T Merge[2];                   /* '<S440>/Merge' */
  real32_T Merge_b;                    /* '<S421>/Merge' */
  real32_T indexing;                   /* '<S419>/indexing' */
  real32_T Lookup[4];                  /* '<S419>/Lookup' */
  real32_T Sum3;                       /* '<S420>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S419>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S419>/Sum2' */
  real32_T Product_dx;                 /* '<S420>/Product' */
  real32_T Sum4;                       /* '<S420>/Sum4' */
  real32_T Sum5;                       /* '<S420>/Sum5' */
  real32_T Product1_f;                 /* '<S420>/Product1' */
  real32_T Sum6;                       /* '<S420>/Sum6' */
  real32_T id_Ld_Lq;                   /* '<S513>/Product1' */
  real32_T Add_gw;                     /* '<S513>/Add' */
  real32_T Product3_e;                 /* '<S513>/Product3' */
  real32_T u_5_Pp;                     /* '<S513>/1_5_Pp' */
  real32_T mtr2_Te_PU_i;
  real32_T Product_en;                 /* '<S513>/Product' */
  real32_T P_output;                   /* '<S513>/P_si2pu' */
  real32_T mtr2_Pm_PU_m;
  real32_T mtr2_Speed_PU_h;
  real32_T mtr2_Iab_meas_PU_j[2];
  real32_T mtr2_Pos_PU_d;
  real32_T Sum_g;                      /* '<S290>/Sum' */
  real32_T PProdOut;                   /* '<S402>/PProd Out' */
  real32_T Kp1;                        /* '<S290>/Kp1' */
  real32_T Integrator;                 /* '<S397>/Integrator' */
  real32_T Sum_f;                      /* '<S406>/Sum' */
  real32_T Saturation;                 /* '<S404>/Saturation' */
  real32_T Sum_k;                      /* '<S289>/Sum' */
  real32_T PProdOut_h;                 /* '<S347>/PProd Out' */
  real32_T Ki1;                        /* '<S289>/Ki1' */
  real32_T Integrator_m;               /* '<S342>/Integrator' */
  real32_T Sum_kp;                     /* '<S351>/Sum' */
  real32_T Saturation_j;               /* '<S349>/Saturation' */
  real32_T Switch_l;                   /* '<S293>/Switch' */
  real32_T Product_de;                 /* '<S293>/Product' */
  real32_T Product_ii;                 /* '<S294>/Product' */
  real32_T Product1_c;                 /* '<S294>/Product1' */
  real32_T Sum1_g;                     /* '<S294>/Sum1' */
  real32_T Merge_e[2];                 /* '<S288>/Merge' */
  real32_T mtr2_VI_debug_k[6];
                   /* '<S3>/BusConversion_InsertedFor_mtr2_debug_at_inport_0' */
  real32_T DeadZone;                   /* '<S334>/DeadZone' */
  real32_T IProdOut;                   /* '<S339>/IProd Out' */
  real32_T Switch_d;                   /* '<S332>/Switch' */
  real32_T DeadZone_f;                 /* '<S389>/DeadZone' */
  real32_T IProdOut_m;                 /* '<S394>/IProd Out' */
  real32_T Switch_g;                   /* '<S387>/Switch' */
  real32_T DataTypeConversion_o;       /* '<S278>/Data Type Conversion' */
  real32_T Switch_n;                   /* '<S511>/Switch' */
  real32_T TmpSignalConversionAtDelayInpor[4];
  real32_T sqrt3_by_two;               /* '<S433>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S433>/one_by_two' */
  real32_T add_c;                      /* '<S433>/add_c' */
  real32_T add_b;                      /* '<S433>/add_b' */
  real32_T Min;                        /* '<S430>/Min' */
  real32_T Max;                        /* '<S430>/Max' */
  real32_T Add_eb;                     /* '<S430>/Add' */
  real32_T one_by_two_j;               /* '<S430>/one_by_two' */
  real32_T Add3;                       /* '<S429>/Add3' */
  real32_T Add2;                       /* '<S429>/Add2' */
  real32_T Add1_jx;                    /* '<S429>/Add1' */
  real32_T Gain_jn[3];                 /* '<S429>/Gain' */
  real32_T Gain_i[3];                  /* '<S278>/Gain' */
  real32_T PWM_Duty_Cycles[3];         /* '<S278>/Sum' */
  real32_T UnitDelay1;                 /* '<S496>/Unit Delay1' */
  real32_T UnitDelay_c;                /* '<S496>/Unit Delay' */
  real32_T a;                          /* '<S496>/a' */
  real32_T Delay_k;                    /* '<S486>/Delay' */
  real32_T Sum2_l;                     /* '<S486>/Sum2' */
  real32_T Sum3_o;                     /* '<S496>/Sum3' */
  real32_T b_invg;                     /* '<S496>/b_inv*g' */
  real32_T Delay1;                     /* '<S496>/Delay1' */
  real32_T Sum4_c;                     /* '<S496>/Sum4' */
  real32_T Switch1_b4[2];              /* '<S488>/Switch1' */
  real32_T Product_af;                 /* '<S500>/Product' */
  real32_T UnitDelay_h;                /* '<S500>/Unit Delay' */
  real32_T Product1_l;                 /* '<S500>/Product1' */
  real32_T Add1_ih;                    /* '<S500>/Add1' */
  real32_T UnitDelay1_b;               /* '<S497>/Unit Delay1' */
  real32_T UnitDelay_fo;               /* '<S497>/Unit Delay' */
  real32_T a_i;                        /* '<S497>/a' */
  real32_T Delay_c;                    /* '<S487>/Delay' */
  real32_T Sum2_lr;                    /* '<S487>/Sum2' */
  real32_T Sum3_p;                     /* '<S497>/Sum3' */
  real32_T b_invg_p;                   /* '<S497>/b_inv*g' */
  real32_T Delay1_p;                   /* '<S497>/Delay1' */
  real32_T Sum4_l;                     /* '<S497>/Sum4' */
  real32_T Switch1_c[2];               /* '<S489>/Switch1' */
  real32_T Product_j;                  /* '<S503>/Product' */
  real32_T UnitDelay_d;                /* '<S503>/Unit Delay' */
  real32_T Product1_o;                 /* '<S503>/Product1' */
  real32_T Add1_a;                     /* '<S503>/Add1' */
  real32_T Merge_l;                    /* '<S485>/Merge' */
  real32_T Merge1;                     /* '<S485>/Merge1' */
  real32_T Delay_ce;                   /* '<S484>/Delay' */
  real32_T Sign_f;                     /* '<S486>/Sign' */
  real32_T Eta;                        /* '<S486>/Eta' */
  real32_T Sum_h;                      /* '<S486>/Sum' */
  real32_T b;                          /* '<S486>/b' */
  real32_T a_f;                        /* '<S486>/a' */
  real32_T Sum1_l;                     /* '<S486>/Sum1' */
  real32_T Sign_e;                     /* '<S487>/Sign' */
  real32_T Eta_b;                      /* '<S487>/Eta' */
  real32_T Sum_e;                      /* '<S487>/Sum' */
  real32_T b_i;                        /* '<S487>/b' */
  real32_T a_j;                        /* '<S487>/a' */
  real32_T Sum1_d;                     /* '<S487>/Sum1' */
  real32_T DTC;                        /* '<S508>/DTC' */
  real32_T SpeedGain;                  /* '<S491>/SpeedGain' */
  real32_T Switch1_d[2];               /* '<S490>/Switch1' */
  real32_T Product_md;                 /* '<S506>/Product' */
  real32_T UnitDelay_o;                /* '<S506>/Unit Delay' */
  real32_T Product1_je;                /* '<S506>/Product1' */
  real32_T Add1_jc;                    /* '<S506>/Add1' */
  real32_T UnitDelay_n;                /* '<S436>/Unit Delay' */
  real32_T Add_cd;                     /* '<S436>/Add' */
  real32_T DataStoreRead;              /* '<S30>/Data Store Read' */
  real32_T Abs;                        /* '<S30>/Abs' */
  real32_T Gain_a;                     /* '<S30>/Gain' */
  real32_T UnitDelay_d5;               /* '<S167>/Unit Delay' */
  real32_T Delay5[4];                  /* '<S2>/Delay5' */
  real32_T Merge_f[2];                 /* '<S189>/Merge' */
  real32_T Switch_a;                   /* '<S30>/Switch' */
  real32_T GetADCVoltage_h[2];         /* '<S191>/Get ADC Voltage' */
  real32_T GetCurrents_g[2];           /* '<S191>/Get Currents' */
  real32_T PU_Conversion_f[2];         /* '<S191>/PU_Conversion' */
  real32_T Merge_bb;                   /* '<S174>/Merge' */
  real32_T indexing_l;                 /* '<S172>/indexing' */
  real32_T Lookup_n[4];                /* '<S172>/Lookup' */
  real32_T Sum3_m;                     /* '<S173>/Sum3' */
  real32_T DataTypeConversion1_f;      /* '<S172>/Data Type Conversion1' */
  real32_T Sum2_b;                     /* '<S172>/Sum2' */
  real32_T Product_e4;                 /* '<S173>/Product' */
  real32_T Sum4_b;                     /* '<S173>/Sum4' */
  real32_T Sum5_d;                     /* '<S173>/Sum5' */
  real32_T Product1_g1;                /* '<S173>/Product1' */
  real32_T Sum6_c;                     /* '<S173>/Sum6' */
  real32_T Switch1_hz;                 /* '<S28>/Switch1' */
  real32_T Switch_i;                   /* '<S28>/Switch' */
  real32_T Switch_m;                   /* '<S42>/Switch' */
  real32_T Product_jb;                 /* '<S42>/Product' */
  real32_T Product_it;                 /* '<S43>/Product' */
  real32_T Product1_le;                /* '<S43>/Product1' */
  real32_T Sum1_e;                     /* '<S43>/Sum1' */
  real32_T Merge_a[2];                 /* '<S36>/Merge' */
  real32_T Vd_OpenLoop;                /* '<S37>/Vd_OpenLoop' */
  real32_T id_Ld_Lq_p;                 /* '<S261>/Product1' */
  real32_T Add_gy;                     /* '<S261>/Add' */
  real32_T Product3_d;                 /* '<S261>/Product3' */
  real32_T u_5_Pp_b;                   /* '<S261>/1_5_Pp' */
  real32_T Product_cc;                 /* '<S261>/Product' */
  real32_T P_output_l;                 /* '<S261>/P_si2pu' */
  real32_T mtr1_speed_ref_PU;          /* '<S26>/Data Store Read' */
  real32_T TmpSignalConversionAtSelectorIn[25];
  real32_T Selector[2];                /* '<S26>/Selector' */
  real32_T DataTypeConversion_c;       /* '<S23>/Data Type Conversion' */
  real32_T Switch_p;                   /* '<S22>/Switch' */
  real32_T OutportBufferForSpeed_fb;   /* '<S2>/Input Scaling' */
  real32_T TmpSignalConversionAtDelay5Inpo[4];
  real32_T sqrt3_by_two_n;             /* '<S186>/sqrt3_by_two' */
  real32_T one_by_two_g;               /* '<S186>/one_by_two' */
  real32_T add_c_a;                    /* '<S186>/add_c' */
  real32_T add_b_o;                    /* '<S186>/add_b' */
  real32_T Min_a;                      /* '<S183>/Min' */
  real32_T Max_n;                      /* '<S183>/Max' */
  real32_T Add_b0;                     /* '<S183>/Add' */
  real32_T one_by_two_i;               /* '<S183>/one_by_two' */
  real32_T Add3_m;                     /* '<S182>/Add3' */
  real32_T Add2_p;                     /* '<S182>/Add2' */
  real32_T Add1_of;                    /* '<S182>/Add1' */
  real32_T Gain_m[3];                  /* '<S182>/Gain' */
  real32_T One_by_Two[3];              /* '<S23>/One_by_Two' */
  real32_T PWM_Duty_Cycles_i[3];       /* '<S23>/Sum' */
  real32_T UnitDelay1_f;               /* '<S245>/Unit Delay1' */
  real32_T UnitDelay_g;                /* '<S245>/Unit Delay' */
  real32_T a_g;                        /* '<S245>/a' */
  real32_T Delay_jf;                   /* '<S235>/Delay' */
  real32_T Sum2_h;                     /* '<S235>/Sum2' */
  real32_T Sum3_oo;                    /* '<S245>/Sum3' */
  real32_T b_invg_a;                   /* '<S245>/b_inv*g' */
  real32_T Delay1_h;                   /* '<S245>/Delay1' */
  real32_T Sum4_g;                     /* '<S245>/Sum4' */
  real32_T Switch1_dz[2];              /* '<S237>/Switch1' */
  real32_T Product_cx;                 /* '<S249>/Product' */
  real32_T UnitDelay_k;                /* '<S249>/Unit Delay' */
  real32_T Product1_gj;                /* '<S249>/Product1' */
  real32_T Add1_na;                    /* '<S249>/Add1' */
  real32_T UnitDelay1_d;               /* '<S246>/Unit Delay1' */
  real32_T UnitDelay_oi;               /* '<S246>/Unit Delay' */
  real32_T a_h;                        /* '<S246>/a' */
  real32_T Delay_i;                    /* '<S236>/Delay' */
  real32_T Sum2_a;                     /* '<S236>/Sum2' */
  real32_T Sum3_j;                     /* '<S246>/Sum3' */
  real32_T b_invg_k;                   /* '<S246>/b_inv*g' */
  real32_T Delay1_l;                   /* '<S246>/Delay1' */
  real32_T Sum4_d;                     /* '<S246>/Sum4' */
  real32_T Switch1_o[2];               /* '<S238>/Switch1' */
  real32_T Product_jt;                 /* '<S252>/Product' */
  real32_T UnitDelay_e;                /* '<S252>/Unit Delay' */
  real32_T Product1_ny;                /* '<S252>/Product1' */
  real32_T Add1_l;                     /* '<S252>/Add1' */
  real32_T Merge_c;                    /* '<S234>/Merge' */
  real32_T Merge1_g;                   /* '<S234>/Merge1' */
  real32_T Delay_g;                    /* '<S233>/Delay' */
  real32_T Sign_fc;                    /* '<S235>/Sign' */
  real32_T Eta_j;                      /* '<S235>/Eta' */
  real32_T Sum_o2;                     /* '<S235>/Sum' */
  real32_T b_m;                        /* '<S235>/b' */
  real32_T a_k;                        /* '<S235>/a' */
  real32_T Sum1_m;                     /* '<S235>/Sum1' */
  real32_T Sign_h;                     /* '<S236>/Sign' */
  real32_T Eta_h;                      /* '<S236>/Eta' */
  real32_T Sum_e3;                     /* '<S236>/Sum' */
  real32_T b_g;                        /* '<S236>/b' */
  real32_T a_p;                        /* '<S236>/a' */
  real32_T Sum1_p;                     /* '<S236>/Sum1' */
  real32_T DTC_a;                      /* '<S257>/DTC' */
  real32_T SpeedGain_c;                /* '<S240>/SpeedGain' */
  real32_T Switch1_k[2];               /* '<S239>/Switch1' */
  real32_T Product_pcn;                /* '<S255>/Product' */
  real32_T UnitDelay_os;               /* '<S255>/Unit Delay' */
  real32_T Product1_e;                 /* '<S255>/Product1' */
  real32_T Add1_cq;                    /* '<S255>/Add1' */
  real32_T Add_h0;                     /* '<S168>/Add' */
  real32_T DataTypeConversion1_d;      /* '<S168>/Data Type Conversion1' */
  real32_T Add1_pp;                    /* '<S168>/Add1' */
  real32_T Input;                      /* '<S169>/Input' */
  real32_T PU2rpm;                     /* '<S39>/PU2rpm' */
  real32_T rpm2rad;                    /* '<S39>/rpm2rad' */
  real32_T we;                         /* '<S39>/mech2elect' */
  real32_T id;                         /* '<S39>/PU2A' */
  real32_T iq;                         /* '<S39>/PU2A1' */
  real32_T UnitDelay_cx;               /* '<S39>/Unit Delay' */
  real32_T UnitDelay1_i;               /* '<S39>/Unit Delay1' */
  real32_T id_ref;                     /* '<S39>/PU2A2' */
  real32_T iq_ref;                     /* '<S39>/PU2A3' */
  real32_T UnitDelay3;                 /* '<S39>/Unit Delay3' */
  real32_T UnitDelay2;                 /* '<S39>/Unit Delay2' */
  real32_T V2PU;                       /* '<S39>/V2PU' */
  real32_T Saturation_n;               /* '<S39>/Saturation' */
  real32_T V2PU1;                      /* '<S39>/V2PU1' */
  real32_T Saturation1;                /* '<S39>/Saturation1' */
  real32_T ud;                         /* '<S39>/MATLAB Function' */
  real32_T uq;                         /* '<S39>/MATLAB Function' */
  real32_T s_d;                        /* '<S39>/MATLAB Function' */
  real32_T s_q;                        /* '<S39>/MATLAB Function' */
  int32_T DataTypeConversion_n[2];     /* '<S439>/Data Type Conversion' */
  int32_T Add_bh[2];                   /* '<S439>/Add' */
  int32_T SpeedCount;                  /* '<S491>/SpeedCount' */
  int32_T DataTypeConversion_j[2];     /* '<S188>/Data Type Conversion' */
  int32_T Add_f[2];                    /* '<S188>/Add' */
  int32_T SpeedCount_g;                /* '<S240>/SpeedCount' */
  uint16_T Divide2_h;                  /* '<S528>/Divide2' */
  uint16_T Divide3;                    /* '<S528>/Divide3' */
  uint16_T ForIterator;                /* '<S530>/For Iterator' */
  uint16_T ADC_A_IN1;                  /* '<S530>/ADC_A_IN1' */
  uint16_T ADC_B_IN1;                  /* '<S530>/ADC_B_IN1' */
  uint16_T Divide_f;                   /* '<S520>/Divide' */
  uint16_T Divide1_m;                  /* '<S520>/Divide1' */
  uint16_T ForIterator_p;              /* '<S522>/For Iterator' */
  uint16_T ADC_A_IN0;                  /* '<S522>/ADC_A_IN0' */
  uint16_T ADC_B_IN0;                  /* '<S522>/ADC_B_IN0' */
  uint16_T DataTypeConversion2;        /* '<S605>/Data Type Conversion2' */
  uint16_T BitwiseOperator;            /* '<S604>/Bitwise Operator' */
  uint16_T BitwiseOperator1;           /* '<S604>/Bitwise Operator1' */
  uint16_T ShiftArithmetic1;           /* '<S604>/Shift Arithmetic1' */
  uint16_T DataStoreRead1;             /* '<S439>/Data Store Read1' */
  uint16_T DataStoreRead2;             /* '<S439>/Data Store Read2' */
  uint16_T ADC_C_IN4;                  /* '<S438>/ADC_C_IN4' */
  uint16_T ADC_B_IN4;                  /* '<S438>/ADC_B_IN4' */
  uint16_T DataTypeConversion_cf;      /* '<S421>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S419>/Get_Integer' */
  uint16_T Switch1_km;                 /* '<S293>/Switch1' */
  uint16_T Switch1_i[3];               /* '<S511>/Switch1' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S511>/Scale_to_PWM_Counter_PRD' */
  uint16_T Switch2_g;                  /* '<S30>/Switch2' */
  uint16_T DataStoreRead1_o;           /* '<S188>/Data Store Read1' */
  uint16_T DataStoreRead2_m;           /* '<S188>/Data Store Read2' */
  uint16_T ADC_C_IN2;                  /* '<S187>/ADC_C_IN2' */
  uint16_T ADC_B_IN2;                  /* '<S187>/ADC_B_IN2' */
  uint16_T Switch1_of;                 /* '<S42>/Switch1' */
  uint16_T DataTypeConversion_f;       /* '<S174>/Data Type Conversion' */
  uint16_T Get_Integer_c;              /* '<S172>/Get_Integer' */
  uint16_T Output;                     /* '<S267>/Output' */
  uint16_T DataStoreRead1_a;           /* '<S26>/Data Store Read1' */
  uint16_T MultiportSwitch[2];         /* '<S26>/Multiport Switch' */
  uint16_T FixPtSum1;                  /* '<S271>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S272>/FixPt Switch' */
  uint16_T Switch1_n[3];               /* '<S22>/Switch1' */
  uint16_T Scale_to_PWM_Counter_PRD_n[3];/* '<S22>/Scale_to_PWM_Counter_PRD' */
  int16_T WhileIterator;               /* '<S265>/While Iterator' */
  int16_T DataTypeConversion_g;        /* '<S168>/Data Type Conversion' */
  int16_T Switch1_od;                  /* '<S332>/Switch1' */
  int16_T Switch2_d;                   /* '<S332>/Switch2' */
  int16_T Switch1_nk;                  /* '<S387>/Switch1' */
  int16_T Switch2_p;                   /* '<S387>/Switch2' */
  boolean_T DataStoreRead1_n;          /* '<S6>/Data Store Read1' */
  boolean_T DataStoreRead2_k;          /* '<S6>/Data Store Read2' */
  boolean_T Compare;                   /* '<S550>/Compare' */
  boolean_T Compare_e;                 /* '<S579>/Compare' */
  boolean_T Compare_d;                 /* '<S578>/Compare' */
  boolean_T Compare_j;                 /* '<S549>/Compare' */
  boolean_T NOT;                       /* '<S518>/NOT' */
  boolean_T NOT_i;                     /* '<S517>/NOT' */
  boolean_T DataTypeConversion3;       /* '<S604>/Data Type Conversion3' */
  boolean_T Compare_i;                 /* '<S423>/Compare' */
  boolean_T Enable;                    /* '<S3>/Enable' */
  boolean_T LogicalOperator;           /* '<S290>/Logical Operator' */
  boolean_T LogicalOperator_a;         /* '<S289>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S332>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S332>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S332>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S332>/Equal1' */
  boolean_T AND3;                      /* '<S332>/AND3' */
  boolean_T RelationalOperator_h;      /* '<S387>/Relational Operator' */
  boolean_T fixforDTpropagationissue_c;
                                     /* '<S387>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_k;
                                    /* '<S387>/fix for DT propagation issue1' */
  boolean_T Equal1_b;                  /* '<S387>/Equal1' */
  boolean_T AND3_o;                    /* '<S387>/AND3' */
  boolean_T Enable_b;                  /* '<S278>/Enable' */
  boolean_T DataStoreRead1_p;          /* '<S444>/Data Store Read1' */
  boolean_T LogicalOperator_e;         /* '<S444>/Logical Operator' */
  boolean_T AlphaRelay;                /* '<S485>/AlphaRelay' */
  boolean_T BetaRelay;                 /* '<S485>/BetaRelay' */
  boolean_T DataStoreRead2_a;          /* '<S434>/Data Store Read2' */
  boolean_T DataStoreRead1_l;          /* '<S434>/Data Store Read1' */
  boolean_T AND;                       /* '<S434>/AND' */
  boolean_T NOT_d;                     /* '<S434>/NOT' */
  boolean_T Switch_ny;                 /* '<S436>/Switch' */
  boolean_T DataTypeConversion_i;      /* '<S30>/Data Type Conversion' */
  boolean_T NOT_f;                     /* '<S167>/NOT' */
  boolean_T Compare_eq;                /* '<S176>/Compare' */
  boolean_T DataStoreRead1_n3;         /* '<S28>/Data Store Read1' */
  boolean_T DataStoreRead3;            /* '<S28>/Data Store Read3' */
  boolean_T DataStoreRead2_c;          /* '<S28>/Data Store Read2' */
  boolean_T DataStoreRead1_i;          /* '<S37>/Data Store Read1' */
  boolean_T DataStoreRead1_j;          /* '<S38>/Data Store Read1' */
  boolean_T Enable_l;                  /* '<S23>/Enable' */
  boolean_T DataStoreRead1_nk;         /* '<S193>/Data Store Read1' */
  boolean_T LogicalOperator_p;         /* '<S193>/Logical Operator' */
  boolean_T AlphaRelay_g;              /* '<S234>/AlphaRelay' */
  boolean_T BetaRelay_l;               /* '<S234>/BetaRelay' */
  boolean_T Delay_a;                   /* '<S168>/Delay' */
  rtB_SpeedControl_mcb_pmsm_foc_s SpeedControl;/* '<Root>/Speed Control' */
  rtB_SPIMasterTransfer2_mcb_pmsm SPIMasterTransfer3;/* '<S519>/SPI Master Transfer2' */
  rtB_SPIMasterTransfer2_mcb_pmsm SPIMasterTransfer2;/* '<S519>/SPI Master Transfer2' */
  rtB_SPIMasterTransfer_mcb_pmsm_ SPIMasterTransfer1;/* '<S519>/SPI Master Transfer' */
  rtB_SPIMasterTransfer_mcb_pmsm_ SPIMasterTransfer;/* '<S519>/SPI Master Transfer' */
  rtB_IfActionSubsystem_mcb_pms_h IfActionSubsystem1_l;/* '<S530>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pms_h IfActionSubsystem_c;/* '<S522>/If Action Subsystem' */
  rtB_FluxObserver_mcb_pmsm_foc_s FluxObserver_a;/* '<S440>/Flux Observer' */
  rtB_angleCompensation_mcb_pmsm_ angleCompensation_p;/* '<S484>/angleCompensation' */
  rtB_Dir_Sense_mcb_pmsm_foc_sens Dir_Sense_o;/* '<S485>/Dir_Sense' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1_f;/* '<S421>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem_k;/* '<S421>/If Action Subsystem' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_k TwoinputsCRL_h;/* '<S283>/Two inputs CRL' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_s TwoinputsCRL_e;/* '<S282>/Two inputs CRL' */
  rtB_DQEquivalence_mcb_pmsm_foc_ DQEquivalence_j;/* '<S288>/D-Q Equivalence' */
  rtB_DQAxisPriority_mcb_pmsm_foc DQAxisPriority_m;/* '<S288>/D//Q Axis Priority' */
  rtB_TwophaseCRLwrap_mcb_pmsm_fo TwophaseCRLwrap_g;/* '<S286>/Two phase CRL wrap' */
  rtB_FluxObserver_mcb_pmsm_foc_s FluxObserver;/* '<S189>/Flux Observer' */
  rtB_angleCompensation_mcb_pmsm_ angleCompensation;/* '<S233>/angleCompensation' */
  rtB_Dir_Sense_mcb_pmsm_foc_sens Dir_Sense;/* '<S234>/Dir_Sense' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1;/* '<S174>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem;/* '<S174>/If Action Subsystem' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_k TwoinputsCRL_p;/* '<S31>/Two inputs CRL' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_s TwoinputsCRL;/* '<S29>/Two inputs CRL' */
  rtB_DQEquivalence_mcb_pmsm_foc_ DQEquivalence;/* '<S36>/D-Q Equivalence' */
  rtB_DQAxisPriority_mcb_pmsm_foc DQAxisPriority;/* '<S36>/D//Q Axis Priority' */
  rtB_TwophaseCRLwrap_mcb_pmsm_fo TwophaseCRLwrap;/* '<S34>/Two phase CRL wrap' */
} BlockIO_mcb_pmsm_foc_sensorless;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S545>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S592>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator3_DSTAT_i;/* '<S593>/Discrete-Time Integrator3' */
  real_T UnitDelay_DSTATE;             /* '<S542>/Unit Delay' */
  real_T DiscreteTimeIntegrator3_DSTAT_e;/* '<S563>/Discrete-Time Integrator3' */
  real_T UnitDelay_DSTATE_b;           /* '<S548>/Unit Delay' */
  real_T DiscreteTimeIntegrator3_DSTAT_n;/* '<S564>/Discrete-Time Integrator3' */
  real_T UnitDelay_DSTATE_g;           /* '<S577>/Unit Delay' */
  real_T Add1_DWORK1;                  /* '<S577>/Add1' */
  real32_T UnitDelay_DSTATE_bn[2];     /* '<S676>/Unit Delay' */
  real32_T Delay_DSTATE[4];            /* '<S3>/Delay' */
  real32_T Integrator_DSTATE;          /* '<S397>/Integrator' */
  real32_T Integrator_DSTATE_a;        /* '<S342>/Integrator' */
  real32_T UnitDelay1_DSTATE;          /* '<S496>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_c;         /* '<S496>/Unit Delay' */
  real32_T Delay_DSTATE_m;             /* '<S486>/Delay' */
  real32_T Delay1_DSTATE;              /* '<S496>/Delay1' */
  real32_T UnitDelay_DSTATE_j;         /* '<S500>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_p;        /* '<S497>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_a;         /* '<S497>/Unit Delay' */
  real32_T Delay_DSTATE_n;             /* '<S487>/Delay' */
  real32_T Delay1_DSTATE_i;            /* '<S497>/Delay1' */
  real32_T UnitDelay_DSTATE_i;         /* '<S503>/Unit Delay' */
  real32_T Delay_DSTATE_j;             /* '<S484>/Delay' */
  real32_T UnitDelay_DSTATE_ig;        /* '<S506>/Unit Delay' */
  real32_T UnitDelay_DSTATE_gq;        /* '<S436>/Unit Delay' */
  real32_T UnitDelay_DSTATE_m;         /* '<S167>/Unit Delay' */
  real32_T Delay5_DSTATE[4];           /* '<S2>/Delay5' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S245>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_mi;        /* '<S245>/Unit Delay' */
  real32_T Delay_DSTATE_l;             /* '<S235>/Delay' */
  real32_T Delay1_DSTATE_f;            /* '<S245>/Delay1' */
  real32_T UnitDelay_DSTATE_p;         /* '<S249>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_h;        /* '<S246>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_n;         /* '<S246>/Unit Delay' */
  real32_T Delay_DSTATE_nx;            /* '<S236>/Delay' */
  real32_T Delay1_DSTATE_n;            /* '<S246>/Delay1' */
  real32_T UnitDelay_DSTATE_gg;        /* '<S252>/Unit Delay' */
  real32_T Delay_DSTATE_h;             /* '<S233>/Delay' */
  real32_T UnitDelay_DSTATE_f;         /* '<S255>/Unit Delay' */
  real32_T UnitDelay_DSTATE_h;         /* '<S39>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_c;        /* '<S39>/Unit Delay1' */
  real32_T UnitDelay3_DSTATE;          /* '<S39>/Unit Delay3' */
  real32_T UnitDelay2_DSTATE;          /* '<S39>/Unit Delay2' */
  uint32_T Delay_DSTATE_k[35];         /* '<S491>/Delay' */
  uint32_T Delay_DSTATE_ky[35];        /* '<S240>/Delay' */
  volatile real32_T RT_Buffer[2];      /* '<Root>/RT' */
  volatile real32_T RT3_Buffer[2];     /* '<Root>/RT3' */
  volatile real32_T RT2_Buffer[4];     /* '<Root>/RT2' */
  volatile real32_T RateTransition3_Buffer[2];/* '<Root>/Rate Transition3' */
  volatile real32_T RT6_Buffer[4];     /* '<Root>/RT6' */
  real32_T SpeedRef;                   /* '<Root>/Data Store Memory4' */
  volatile real32_T RT8_1_Buffer[12];  /* '<Root>/RT8' */
  volatile real32_T RT8_2_Buffer[2];   /* '<Root>/RT8' */
  volatile real32_T RT8_3_Buffer[2];   /* '<Root>/RT8' */
  volatile real32_T RT8_4_Buffer[2];   /* '<Root>/RT8' */
  volatile real32_T RT8_5_Buffer[4];   /* '<Root>/RT8' */
  volatile real32_T RT8_6_Buffer[2];   /* '<Root>/RT8' */
  real32_T Add_DWORK1;                 /* '<S436>/Add' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S536>/Digital Output' */
  int32_T DigitalOutput_FRAC_LEN_o;    /* '<S519>/Digital Output' */
  int32_T BottomDRV8305EN_FRAC_LEN;    /* '<S519>/Bottom DRV8305 EN' */
  int32_T Add_DWORK1_d[2];             /* '<S439>/Add' */
  int32_T BottomDRV8305EN_FRAC_LEN_j;  /* '<S511>/Bottom DRV8305 EN' */
  int32_T SpeedCount_DWORK1;           /* '<S491>/SpeedCount' */
  int32_T Add_DWORK1_g[2];             /* '<S188>/Add' */
  int32_T DRV830xEnable_FRAC_LEN;      /* '<S22>/DRV830x Enable' */
  int32_T SpeedCount_DWORK1_f;         /* '<S240>/SpeedCount' */
  uint32_T Sum_DWORK1[4];              /* '<S419>/Sum' */
  uint32_T Sum_DWORK1_o[4];            /* '<S172>/Sum' */
  uint32_T Add_DWORK1_a;               /* '<S265>/Add' */
  uint16_T Output_DSTATE;              /* '<S267>/Output' */
  volatile int16_T RT_ActiveBufIdx;    /* '<Root>/RT' */
  volatile int16_T RT3_ActiveBufIdx;   /* '<Root>/RT3' */
  volatile int16_T RT3_semaphoreTaken; /* '<Root>/RT3' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  volatile int16_T RateTransition3_ActiveBufIdx;/* '<Root>/Rate Transition3' */
  volatile int16_T RT6_ActiveBufIdx;   /* '<Root>/RT6' */
  volatile int16_T RT8_1_ActiveBufIdx; /* '<Root>/RT8' */
  volatile int16_T RT8_2_ActiveBufIdx; /* '<Root>/RT8' */
  volatile int16_T RT8_3_ActiveBufIdx; /* '<Root>/RT8' */
  volatile int16_T RT8_4_ActiveBufIdx; /* '<Root>/RT8' */
  volatile int16_T RT8_5_ActiveBufIdx; /* '<Root>/RT8' */
  volatile int16_T RT8_6_ActiveBufIdx; /* '<Root>/RT8' */
  uint16_T IaOffset_motor1;            /* '<Root>/Data Store Memory1' */
  uint16_T IbOffset_motor1;            /* '<Root>/Data Store Memory2' */
  uint16_T Debug_signals;              /* '<Root>/Data Store Memory6' */
  uint16_T IbOffset_motor2;            /* '<Root>/Data Store Memory7' */
  uint16_T IaOffset_motor2;            /* '<Root>/Data Store Memory8' */
  uint16_T CircBufIdx;                 /* '<S491>/Delay' */
  uint16_T CircBufIdx_g;               /* '<S240>/Delay' */
  boolean_T Delay_DSTATE_hd;           /* '<S168>/Delay' */
  int16_T Integrator_PrevResetState;   /* '<S397>/Integrator' */
  int16_T Integrator_PrevResetState_k; /* '<S342>/Integrator' */
  uint16_T DiscreteTimeIntegrator3_IC_LOAD;/* '<S592>/Discrete-Time Integrator3' */
  uint16_T DiscreteTimeIntegrator3_IC_LO_a;/* '<S593>/Discrete-Time Integrator3' */
  uint16_T DiscreteTimeIntegrator3_IC_LO_i;/* '<S563>/Discrete-Time Integrator3' */
  uint16_T DiscreteTimeIntegrator3_IC_LO_e;/* '<S564>/Discrete-Time Integrator3' */
  boolean_T EnMtr2TrqCtrl;             /* '<Root>/Data Store Memory5' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T EnClosedLoop;              /* '<Root>/Data Store Memory3' */
  boolean_T AlphaRelay_Mode;           /* '<S485>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S485>/BetaRelay' */
  boolean_T AlphaRelay_Mode_g;         /* '<S234>/AlphaRelay' */
  boolean_T BetaRelay_Mode_k;          /* '<S234>/BetaRelay' */
  boolean_T EnableEnMtr2TrqCtrlafter2secdel;
                           /* '<S434>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  rtDW_SpeedControl_mcb_pmsm_foc_ SpeedControl;/* '<Root>/Speed Control' */
  rtDW_SPIMasterTransfer2_mcb_pms SPIMasterTransfer3;/* '<S519>/SPI Master Transfer2' */
  rtDW_SPIMasterTransfer2_mcb_pms SPIMasterTransfer2;/* '<S519>/SPI Master Transfer2' */
  rtDW_SPIMasterTransfer_mcb_pmsm SPIMasterTransfer1;/* '<S519>/SPI Master Transfer' */
  rtDW_SPIMasterTransfer_mcb_pmsm SPIMasterTransfer;/* '<S519>/SPI Master Transfer' */
  rtDW_IfActionSubsystem_mcb_pm_n IfActionSubsystem1_l;/* '<S530>/If Action Subsystem1' */
  rtDW_IfActionSubsystem_mcb_pm_n IfActionSubsystem_c;/* '<S522>/If Action Subsystem' */
  rtDW_FluxObserver_mcb_pmsm_foc_ FluxObserver_a;/* '<S440>/Flux Observer' */
  rtDW_FluxObserver_mcb_pmsm_foc_ FluxObserver;/* '<S189>/Flux Observer' */
} D_Work_mcb_pmsm_foc_sensorless_;

/* Zero-crossing (trigger) state */
typedef struct {
  rtZCE_FluxObserver_mcb_pmsm_foc FluxObserver_a;/* '<S440>/Flux Observer' */
  ZCSigState Delay_Reset_ZCE_b;        /* '<S486>/Delay' */
  ZCSigState Delay1_Reset_ZCE_j;       /* '<S496>/Delay1' */
  ZCSigState Delay_Reset_ZCE_l;        /* '<S487>/Delay' */
  ZCSigState Delay1_Reset_ZCE_d;       /* '<S497>/Delay1' */
  ZCSigState Delay_Reset_ZCE_m;        /* '<S484>/Delay' */
  rtZCE_Dir_Sense_mcb_pmsm_foc_se Dir_Sense_o;/* '<S485>/Dir_Sense' */
  rtZCE_FluxObserver_mcb_pmsm_foc FluxObserver;/* '<S189>/Flux Observer' */
  ZCSigState Delay_Reset_ZCE_o;        /* '<S235>/Delay' */
  ZCSigState Delay1_Reset_ZCE_l;       /* '<S245>/Delay1' */
  ZCSigState Delay_Reset_ZCE_lr;       /* '<S236>/Delay' */
  ZCSigState Delay1_Reset_ZCE_bs;      /* '<S246>/Delay1' */
  ZCSigState Delay_Reset_ZCE_bh;       /* '<S233>/Delay' */
  rtZCE_Dir_Sense_mcb_pmsm_foc_se Dir_Sense;/* '<S234>/Dir_Sense' */
} PrevZCSigStates_mcb_pmsm_foc_se;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T IndexVector;            /* '<S545>/Index Vector' */
  const real_T IndexVector1;           /* '<S545>/Index Vector1' */
  const real_T IndexVector2;           /* '<S545>/Index Vector2' */
  const real_T IndexVector_c;          /* '<S562>/Index Vector' */
  const real_T IndexVector1_m;         /* '<S562>/Index Vector1' */
  const real_T Add;                    /* '<S562>/Add' */
  const real_T IndexVector_l;          /* '<S563>/Index Vector' */
  const real_T IndexVector_k;          /* '<S565>/Index Vector' */
  const real_T IndexVector_ko;         /* '<S566>/Index Vector' */
  const real_T IndexVector2_g;         /* '<S566>/Index Vector2' */
  const real_T IndexVector_b;          /* '<S567>/Index Vector' */
  const real_T IndexVector_bl;         /* '<S564>/Index Vector' */
  const real_T IndexVector_g;          /* '<S568>/Index Vector' */
  const real_T IndexVector_i;          /* '<S569>/Index Vector' */
  const real_T IndexVector1_f;         /* '<S569>/Index Vector1' */
  const real_T IndexVector_bj;         /* '<S570>/Index Vector' */
  const real_T IndexVector_j;          /* '<S571>/Index Vector' */
  const real_T IndexVector_ku;         /* '<S591>/Index Vector' */
  const real_T IndexVector1_n;         /* '<S591>/Index Vector1' */
  const real_T Add_l;                  /* '<S591>/Add' */
  const real_T IndexVector_cx;         /* '<S592>/Index Vector' */
  const real_T IndexVector_gy;         /* '<S594>/Index Vector' */
  const real_T IndexVector_h;          /* '<S595>/Index Vector' */
  const real_T IndexVector1_mr;        /* '<S595>/Index Vector1' */
  const real_T IndexVector_ca;         /* '<S596>/Index Vector' */
  const real_T IndexVector_bp;         /* '<S593>/Index Vector' */
  const real_T IndexVector_d;          /* '<S597>/Index Vector' */
  const real_T IndexVector_f;          /* '<S598>/Index Vector' */
  const real_T IndexVector1_fl;        /* '<S598>/Index Vector1' */
  const real_T IndexVector_kue;        /* '<S599>/Index Vector' */
  const real_T IndexVector_l0;         /* '<S600>/Index Vector' */
  const uint32_T Width;                /* '<S264>/Width' */
  const real32_T Ld_Port;              /* '<S514>/Gain' */
  const real32_T Switch;               /* '<S514>/Switch' */
  const real32_T Lq_Port;              /* '<S514>/Gain1' */
  const real32_T Switch1;              /* '<S514>/Switch1' */
  const real32_T FluxPM_Port;          /* '<S514>/Gain2' */
  const real32_T Switch2;              /* '<S514>/Switch2' */
  const real32_T Ld_Lq;                /* '<S513>/Subtract' */
  const real32_T Ld_Port_b;            /* '<S262>/Gain' */
  const real32_T Switch_g;             /* '<S262>/Switch' */
  const real32_T Lq_Port_c;            /* '<S262>/Gain1' */
  const real32_T Switch1_d;            /* '<S262>/Switch1' */
  const real32_T FluxPM_Port_d;        /* '<S262>/Gain2' */
  const real32_T Switch2_h;            /* '<S262>/Switch2' */
  const real32_T Ld_Lq_a;              /* '<S261>/Subtract' */
} ConstBlockIO_mcb_pmsm_foc_senso;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S172>/sine_table_values'
   *   '<S419>/sine_table_values'
   */
  real32_T pooled82[1002];
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
    uint32_T clockTick0;
    uint32_T clockTickH0;
    struct {
      uint16_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern BlockIO_mcb_pmsm_foc_sensorless mcb_pmsm_foc_sensorless_dyno__B;

/* Block states (default storage) */
extern D_Work_mcb_pmsm_foc_sensorless_ mcb_pmsm_foc_sensorless_d_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_mcb_pmsm_foc_se mcb_pmsm_foc_sen_PrevZCSigState;
extern const ConstBlockIO_mcb_pmsm_foc_senso mcb_pmsm_foc_sensorless__ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_mcb_pmsm_foc_sensorl mcb_pmsm_foc_sensorless__ConstP;

/* External function called from main */
extern void mcb_pmsm_foc_sensorless_dyno_f28379d_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void mcb_pmsm_foc_sensorless_dyno_f28379d_initialize(void);
extern void mcb_pmsm_foc_sensorless_dyno_f28379d_step0(void);/* Sample time: [2.5E-5s, 0.0s] */
extern void mcb_pmsm_foc_sensorless_dyno_f28379d_step1(void);/* Sample time: [0.001s, 0.0s] */
extern void mcb_pmsm_foc_sensorless_dyno_f28379d_step2(void);/* Sample time: [0.5s, 0.0s] */
extern void mcb_pmsm_foc_sensorless_dyno_f28379d_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_foc_sensorles *const mcb_pmsm_foc_sensorless_dyno_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void ADCB1_INT(void);
  interrupt void ADCC1_INT(void);
  interrupt void SCIA_RX_INT(void);
  void mcb_pmsm_foc_sensorless_dyno_f28379d_configure_interrupts (void);
  void mcb_pmsm_foc_sensorless_dyno_f28379d_unconfigure_interrupts (void);

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
 * '<Root>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d'
 * '<S1>'   : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Code generation'
 * '<S2>'   : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1'
 * '<S3>'   : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2'
 * '<S4>'   : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init'
 * '<S5>'   : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Heartbeat LED'
 * '<S6>'   : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled'
 * '<S7>'   : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Serial Receive'
 * '<S8>'   : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control'
 * '<S9>'   : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Torque Demand'
 * '<S10>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Code generation/HWI_ADCB1_INT'
 * '<S11>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Code generation/HWI_ADCC1_INT'
 * '<S12>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Code generation/HWI_SCIA_RX_INT'
 * '<S13>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Code generation/HWI_ADCB1_INT/ECSoC'
 * '<S14>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Code generation/HWI_ADCB1_INT/ECSoC/ECSimCodegen'
 * '<S15>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Code generation/HWI_ADCC1_INT/ECSoC'
 * '<S16>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Code generation/HWI_ADCC1_INT/ECSoC/ECSimCodegen'
 * '<S17>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Code generation/HWI_SCIA_RX_INT/ECSoC'
 * '<S18>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Code generation/HWI_SCIA_RX_INT/ECSoC/ECSimCodegen'
 * '<S19>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop'
 * '<S20>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/HW_Inputs'
 * '<S21>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling'
 * '<S22>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Inverter (Code Generation)'
 * '<S23>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Output Scaling'
 * '<S24>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/PMSM Torque Estimator1'
 * '<S25>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/SCI (Code Generation)'
 * '<S26>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Subsystem'
 * '<S27>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Clarke Transform'
 * '<S28>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers'
 * '<S29>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Inverse Park Transform'
 * '<S30>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Open_Loop_Control'
 * '<S31>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Park Transform'
 * '<S32>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Sine-Cosine Lookup'
 * '<S33>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Space Vector Generator'
 * '<S34>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Clarke Transform/Two phase input'
 * '<S35>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S36>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter'
 * '<S37>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id'
 * '<S38>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq'
 * '<S39>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/Subsystem'
 * '<S40>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S41>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S42>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S43>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S44>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S45>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S46>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S47>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S48>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S49>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S50>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S51>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S52>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S53>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S54>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S55>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S56>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S57>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S58>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S59>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S60>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S61>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S62>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S63>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S64>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S65>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S66>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S67>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S68>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S69>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S70>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S71>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S72>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S73>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S74>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S75>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S76>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S77>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S78>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S79>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S80>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S81>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S82>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S83>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S84>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S85>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S86>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S87>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S88>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S89>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S90>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S91>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S92>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S93>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S94>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S95>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S96>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S97>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S98>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S99>'  : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S100>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S101>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S102>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S103>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S104>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S105>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S106>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S107>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S108>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S109>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S110>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S111>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S112>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S113>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S114>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S115>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S116>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S117>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S118>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S119>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S120>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S121>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S122>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S123>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S124>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S125>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S126>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S127>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S128>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S129>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S130>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S131>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S132>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S133>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S134>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S135>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S136>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S137>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S138>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S139>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S140>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S141>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S142>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S143>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S144>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S145>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S146>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S147>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S148>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S149>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S150>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S151>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S152>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S153>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S154>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S155>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S156>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S157>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S158>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S159>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S160>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S161>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S162>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S163>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S164>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Current_Controllers/Subsystem/MATLAB Function'
 * '<S165>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Inverse Park Transform/Two inputs CRL'
 * '<S166>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S167>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Open_Loop_Control/Position Generator'
 * '<S168>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Open_Loop_Control/Position Generator/Accumulate'
 * '<S169>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Open_Loop_Control/Position Generator/Accumulate/Subsystem'
 * '<S170>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Park Transform/Two inputs CRL'
 * '<S171>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S172>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S173>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S174>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S175>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S176>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S177>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S178>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S179>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S180>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Space Vector Generator/Modulation method'
 * '<S181>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Space Vector Generator/Voltage Input'
 * '<S182>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Space Vector Generator/Modulation method/SVPWM'
 * '<S183>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S184>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S185>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S186>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S187>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/HW_Inputs/Sensor Driver Blocks (codegen)'
 * '<S188>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate Phase Currents'
 * '<S189>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed'
 * '<S190>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate Phase Currents/Data_Type'
 * '<S191>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate Phase Currents/Data_Type/Data_Type_Float'
 * '<S192>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer'
 * '<S193>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer'
 * '<S194>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/DC component removal'
 * '<S195>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer'
 * '<S196>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter'
 * '<S197>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement'
 * '<S198>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/DC component removal/IIR Filter'
 * '<S199>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter'
 * '<S200>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter/Low-pass'
 * '<S201>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S202>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2'
 * '<S203>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Data type Handling'
 * '<S204>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Flux Calculation'
 * '<S205>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/ParamBus'
 * '<S206>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/passthrough'
 * '<S207>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha'
 * '<S208>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta'
 * '<S209>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default'
 * '<S210>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2'
 * '<S211>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2/Per Unit'
 * '<S212>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default'
 * '<S213>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc'
 * '<S214>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter'
 * '<S215>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Integrator'
 * '<S216>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Scaling'
 * '<S217>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S218>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S219>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S220>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default'
 * '<S221>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc'
 * '<S222>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter'
 * '<S223>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Integrator'
 * '<S224>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Scaling'
 * '<S225>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S226>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S227>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S228>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter'
 * '<S229>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S230>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S231>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle'
 * '<S232>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S233>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer'
 * '<S234>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch'
 * '<S235>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ealpha_est'
 * '<S236>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ebeta_est'
 * '<S237>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha'
 * '<S238>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta'
 * '<S239>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter'
 * '<S240>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement'
 * '<S241>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation'
 * '<S242>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Dir_Sense'
 * '<S243>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Subsystem2'
 * '<S244>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Subsystem3'
 * '<S245>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ealpha_est/DisturbanceObserver'
 * '<S246>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ebeta_est/DisturbanceObserver'
 * '<S247>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter'
 * '<S248>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass'
 * '<S249>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S250>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter'
 * '<S251>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass'
 * '<S252>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S253>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter'
 * '<S254>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S255>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S256>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement/DT_Handle'
 * '<S257>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S258>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation/atan1'
 * '<S259>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation/atan1/Per Unit'
 * '<S260>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/PMSM Torque Estimator1/Variant Subsystem'
 * '<S261>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/PMSM Torque Estimator1/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort'
 * '<S262>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/PMSM Torque Estimator1/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort/LumpedParams_InputPorts'
 * '<S263>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/SCI (Code Generation)/Data_Conditioning_Tx'
 * '<S264>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/SCI (Code Generation)/Data_Logging'
 * '<S265>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/SCI (Code Generation)/While Iterator Subsystem'
 * '<S266>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/SCI (Code Generation)/Data_Conditioning_Tx/Data_Type_Float'
 * '<S267>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/SCI (Code Generation)/Data_Logging/Counter Limited'
 * '<S268>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/SCI (Code Generation)/Data_Logging/Data'
 * '<S269>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/SCI (Code Generation)/Data_Logging/End'
 * '<S270>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/SCI (Code Generation)/Data_Logging/Start'
 * '<S271>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/SCI (Code Generation)/Data_Logging/Counter Limited/Increment Real World'
 * '<S272>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 1/SCI (Code Generation)/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S273>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop'
 * '<S274>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Enable Motor2 after a delay'
 * '<S275>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/HW_Inputs'
 * '<S276>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling'
 * '<S277>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Inverter Driver Peripherals'
 * '<S278>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Output Scaling'
 * '<S279>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/PMSM Torque Estimator1'
 * '<S280>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Clarke Transform'
 * '<S281>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers'
 * '<S282>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Inverse Park Transform'
 * '<S283>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Park Transform'
 * '<S284>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Sine-Cosine Lookup'
 * '<S285>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Space Vector Generator'
 * '<S286>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Clarke Transform/Two phase input'
 * '<S287>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S288>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter'
 * '<S289>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id'
 * '<S290>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq'
 * '<S291>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S292>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S293>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S294>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S295>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S296>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S297>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S298>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S299>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S300>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S301>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S302>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S303>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S304>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S305>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S306>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S307>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S308>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S309>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S310>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S311>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S312>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S313>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S314>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S315>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S316>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S317>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S318>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S319>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S320>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S321>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S322>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S323>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S324>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S325>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S326>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S327>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S328>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S329>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S330>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S331>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S332>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S333>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S334>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S335>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S336>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S337>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S338>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S339>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S340>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S341>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S342>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S343>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S344>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S345>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S346>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S347>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S348>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S349>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S350>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S351>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S352>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S353>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S354>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S355>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S356>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S357>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S358>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S359>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S360>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S361>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S362>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S363>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S364>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S365>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S366>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S367>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S368>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S369>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S370>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S371>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S372>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S373>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S374>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S375>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S376>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S377>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S378>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S379>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S380>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S381>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S382>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S383>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S384>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S385>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S386>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S387>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S388>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S389>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S390>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S391>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S392>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S393>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S394>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S395>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S396>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S397>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S398>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S399>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S400>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S401>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S402>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S403>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S404>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S405>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S406>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S407>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S408>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S409>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S410>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S411>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S412>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S413>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S414>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S415>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Inverse Park Transform/Two inputs CRL'
 * '<S416>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S417>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Park Transform/Two inputs CRL'
 * '<S418>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S419>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S420>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S421>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S422>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S423>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S424>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S425>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S426>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S427>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Space Vector Generator/Modulation method'
 * '<S428>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Space Vector Generator/Voltage Input'
 * '<S429>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Space Vector Generator/Modulation method/SVPWM'
 * '<S430>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S431>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S432>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S433>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Closed loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S434>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Enable Motor2 after a delay/Delay to start motor2 (codegen)'
 * '<S435>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Enable Motor2 after a delay/Delay to start motor2 (codegen)/Disable EnMtr2TrqCtrl'
 * '<S436>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Enable Motor2 after a delay/Delay to start motor2 (codegen)/Enable EnMtr2TrqCtrl after 2 sec delay'
 * '<S437>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Enable Motor2 after a delay/Delay to start motor2 (codegen)/Enable EnMtr2TrqCtrl after 2 sec delay/Enable EnMtr2TrqCtrl'
 * '<S438>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/HW_Inputs/Sensor Driver Blocks (codegen)'
 * '<S439>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate Phase Currents'
 * '<S440>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed'
 * '<S441>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate Phase Currents/Data_Type'
 * '<S442>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate Phase Currents/Data_Type/Data_Type_Float'
 * '<S443>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer'
 * '<S444>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer'
 * '<S445>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/DC component removal'
 * '<S446>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer'
 * '<S447>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter'
 * '<S448>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement'
 * '<S449>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/DC component removal/IIR Filter'
 * '<S450>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter'
 * '<S451>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter/Low-pass'
 * '<S452>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S453>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2'
 * '<S454>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Data type Handling'
 * '<S455>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Flux Calculation'
 * '<S456>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/ParamBus'
 * '<S457>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/passthrough'
 * '<S458>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha'
 * '<S459>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta'
 * '<S460>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default'
 * '<S461>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2'
 * '<S462>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2/Per Unit'
 * '<S463>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default'
 * '<S464>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc'
 * '<S465>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter'
 * '<S466>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Integrator'
 * '<S467>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Scaling'
 * '<S468>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S469>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S470>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S471>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default'
 * '<S472>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc'
 * '<S473>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter'
 * '<S474>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Integrator'
 * '<S475>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Scaling'
 * '<S476>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S477>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S478>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S479>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter'
 * '<S480>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S481>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S482>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle'
 * '<S483>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S484>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer'
 * '<S485>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch'
 * '<S486>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ealpha_est'
 * '<S487>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ebeta_est'
 * '<S488>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha'
 * '<S489>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta'
 * '<S490>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter'
 * '<S491>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement'
 * '<S492>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation'
 * '<S493>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Dir_Sense'
 * '<S494>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Subsystem2'
 * '<S495>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Subsystem3'
 * '<S496>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ealpha_est/DisturbanceObserver'
 * '<S497>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ebeta_est/DisturbanceObserver'
 * '<S498>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter'
 * '<S499>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass'
 * '<S500>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S501>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter'
 * '<S502>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass'
 * '<S503>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S504>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter'
 * '<S505>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S506>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S507>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement/DT_Handle'
 * '<S508>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S509>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation/atan1'
 * '<S510>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation/atan1/Per Unit'
 * '<S511>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/Inverter Driver Peripherals/Inverter (Code Generation)'
 * '<S512>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/PMSM Torque Estimator1/Variant Subsystem'
 * '<S513>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/PMSM Torque Estimator1/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort'
 * '<S514>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/FOC Algorithm Motor 2/PMSM Torque Estimator1/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort/LumpedParams_InputPorts'
 * '<S515>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init'
 * '<S516>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)'
 * '<S517>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor'
 * '<S518>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor'
 * '<S519>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Enable DRV8305 for motor 1 and motor 2'
 * '<S520>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset '
 * '<S521>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Default ADC Offset'
 * '<S522>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset /For Iterator Subsystem'
 * '<S523>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset /If Action Subsystem'
 * '<S524>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset /If Action Subsystem1'
 * '<S525>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset /If Action Subsystem2'
 * '<S526>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset /If Action Subsystem3'
 * '<S527>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S528>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset'
 * '<S529>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Default ADC Offset'
 * '<S530>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset/For Iterator Subsystem'
 * '<S531>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset/If Action Subsystem4'
 * '<S532>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset/If Action Subsystem5'
 * '<S533>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset/If Action Subsystem6'
 * '<S534>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset/If Action Subsystem7'
 * '<S535>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset/For Iterator Subsystem/If Action Subsystem1'
 * '<S536>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Heartbeat LED/Code generation'
 * '<S537>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/IIR Filter'
 * '<S538>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control'
 * '<S539>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control'
 * '<S540>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/IIR Filter/IIR Filter'
 * '<S541>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/IIR Filter/IIR Filter/Low-pass'
 * '<S542>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S543>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete'
 * '<S544>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete'
 * '<S545>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle'
 * '<S546>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1'
 * '<S547>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic'
 * '<S548>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1'
 * '<S549>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1/Compare To Constant'
 * '<S550>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1/Compare To Constant1'
 * '<S551>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/MechToElect'
 * '<S552>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator'
 * '<S553>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrNotTrnsfrd Input'
 * '<S554>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrStored Input'
 * '<S555>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrTrnsfrd Input'
 * '<S556>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Clarke Transform'
 * '<S557>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Inverse Clarke Transform'
 * '<S558>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Inverse Park Transform'
 * '<S559>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Machine Torque'
 * '<S560>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit'
 * '<S561>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Park Transform'
 * '<S562>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Machine Torque/Subsystem'
 * '<S563>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage'
 * '<S564>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage'
 * '<S565>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem'
 * '<S566>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1'
 * '<S567>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2'
 * '<S568>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem'
 * '<S569>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1'
 * '<S570>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2'
 * '<S571>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3'
 * '<S572>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete'
 * '<S573>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete'
 * '<S574>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Mechanical and Angle'
 * '<S575>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Motor Units1'
 * '<S576>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic'
 * '<S577>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Mechanical and Angle/Int'
 * '<S578>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Mechanical and Angle/Int/Compare To Constant'
 * '<S579>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Mechanical and Angle/Int/Compare To Constant1'
 * '<S580>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Motor Units1/MechToElect'
 * '<S581>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Motor Units1/Power Accounting Bus Creator'
 * '<S582>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrNotTrnsfrd Input'
 * '<S583>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrStored Input'
 * '<S584>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrTrnsfrd Input'
 * '<S585>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/Clarke Transform'
 * '<S586>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/Inverse Clarke Transform'
 * '<S587>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/Inverse Park Transform'
 * '<S588>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/Machine Torque'
 * '<S589>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit'
 * '<S590>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/Park Transform'
 * '<S591>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/Machine Torque/Subsystem'
 * '<S592>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage'
 * '<S593>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage'
 * '<S594>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem'
 * '<S595>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1'
 * '<S596>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2'
 * '<S597>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem'
 * '<S598>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1'
 * '<S599>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2'
 * '<S600>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3'
 * '<S601>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Serial Receive/Parse SCI Rx'
 * '<S602>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Serial Receive/Serial Receive'
 * '<S603>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Serial Receive/Parse SCI Rx/Data_Conditioning_Rx'
 * '<S604>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Serial Receive/Parse SCI Rx/unParse'
 * '<S605>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Serial Receive/Parse SCI Rx/Data_Conditioning_Rx/Data_Type_Float'
 * '<S606>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Serial Receive/Serial Receive/Serial Rx'
 * '<S607>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Serial Receive/Serial Receive/Serial Rx/Data_Type_Float'
 * '<S608>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed'
 * '<S609>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/Rate Limiter for FO'
 * '<S610>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/Rate Limiter for SMO'
 * '<S611>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/Speed_Ref_Selector'
 * '<S612>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/Subsystem'
 * '<S613>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S614>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S615>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S616>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S617>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S618>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S619>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S620>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S621>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S622>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S623>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S624>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S625>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S626>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S627>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S628>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S629>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S630>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S631>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S632>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S633>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S634>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S635>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S636>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S637>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S638>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S639>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S640>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S641>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S642>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S643>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S644>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S645>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S646>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S647>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S648>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S649>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S650>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S651>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S652>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S653>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S654>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S655>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S656>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S657>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S658>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S659>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S660>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S661>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S662>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S663>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S664>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S665>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S666>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S667>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S668>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S669>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S670>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S671>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S672>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Speed Control/Subsystem/MATLAB Function2'
 * '<S673>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Torque Demand/IIR Filter'
 * '<S674>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Torque Demand/IIR Filter/IIR Filter'
 * '<S675>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Torque Demand/IIR Filter/IIR Filter/Low-pass'
 * '<S676>' : 'mcb_pmsm_foc_sensorless_dyno_f28379d/Torque Demand/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                             /* mcb_pmsm_foc_sensorless_dyno_f28379d_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
