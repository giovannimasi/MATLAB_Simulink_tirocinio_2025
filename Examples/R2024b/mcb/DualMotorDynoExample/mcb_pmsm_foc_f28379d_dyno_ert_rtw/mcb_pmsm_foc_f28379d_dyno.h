/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_f28379d_dyno.h
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

#ifndef mcb_pmsm_foc_f28379d_dyno_h_
#define mcb_pmsm_foc_f28379d_dyno_h_
#ifndef mcb_pmsm_foc_f28379d_dyno_COMMON_INCLUDES_
#define mcb_pmsm_foc_f28379d_dyno_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "string.h"
#include "DSP28xx_SciUtil.h"
#include "IQmathLib.h"
#endif                          /* mcb_pmsm_foc_f28379d_dyno_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "mcb_pmsm_foc_f28379d_dyno_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>
#include <stddef.h>
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

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals for system '<S27>/Two phase CRL wrap' */
typedef struct {
  real32_T a_plus_2b;                  /* '<S28>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S28>/one_by_sqrt3' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} rtB_TwophaseCRLwrap_mcb_pmsm_fo;

/* Block signals for system '<S43>/limitRef2' */
typedef struct {
  real32_T Switch1;                    /* '<S45>/Switch1' */
  real32_T Sqrt;                       /* '<S45>/Sqrt' */
  real32_T Gain;                       /* '<S45>/Gain' */
} rtB_limitRef2_mcb_pmsm_foc_f283;

/* Block signals for system '<S29>/D//Q Axis Priority' */
typedef struct {
  real32_T Switch[2];                  /* '<S34>/Switch' */
  real32_T Switch2;                    /* '<S44>/Switch2' */
  real32_T Product;                    /* '<S43>/Product' */
  real32_T Sum;                        /* '<S43>/Sum' */
  real32_T Product2;                   /* '<S43>/Product2' */
  real32_T Merge;                      /* '<S43>/Merge' */
  real32_T Gain;                       /* '<S43>/Gain' */
  real32_T Switch_l;                   /* '<S44>/Switch' */
  uint16_T DataTypeConversion;         /* '<S43>/Data Type Conversion' */
  boolean_T Compare;                   /* '<S39>/Compare' */
  boolean_T Compare_n;                 /* '<S40>/Compare' */
  boolean_T LowerRelop1;               /* '<S44>/LowerRelop1' */
  boolean_T RelationalOperator;        /* '<S43>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S44>/UpperRelop' */
  rtB_limitRef2_mcb_pmsm_foc_f283 limitRef2;/* '<S43>/limitRef2' */
} rtB_DQAxisPriority_mcb_pmsm_foc;

/* Block signals for system '<S29>/D-Q Equivalence' */
typedef struct {
  real32_T Product[2];                 /* '<S37>/Product' */
  real32_T SquareRoot;                 /* '<S37>/Square Root' */
  real32_T Switch;                     /* '<S37>/Switch' */
  uint16_T DataTypeConversion;         /* '<S33>/Data Type Conversion' */
  boolean_T RelationalOperator;        /* '<S33>/Relational Operator' */
} rtB_DQEquivalence_mcb_pmsm_foc_;

/* Block signals for system '<S30>/MATLAB Function' */
typedef struct {
  real32_T V_d_ref;                    /* '<S30>/MATLAB Function' */
} rtB_MATLABFunction_mcb_pmsm_foc;

/* Block states (default storage) for system '<S30>/MATLAB Function' */
typedef struct {
  real32_T integrator_state;           /* '<S30>/MATLAB Function' */
} rtDW_MATLABFunction_mcb_pmsm_fo;

/* Block signals for system '<S31>/MATLAB Function' */
typedef struct {
  real32_T V_q_ref;                    /* '<S31>/MATLAB Function' */
} rtB_MATLABFunction_mcb_pmsm_f_o;

/* Block states (default storage) for system '<S31>/MATLAB Function' */
typedef struct {
  real32_T integrator_state;           /* '<S31>/MATLAB Function' */
} rtDW_MATLABFunction_mcb_pmsm__a;

/* Block signals for system '<S22>/Two inputs CRL' */
typedef struct {
  real32_T qcos;                       /* '<S164>/qcos' */
  real32_T dsin;                       /* '<S164>/dsin' */
  real32_T sum_beta;                   /* '<S164>/sum_beta' */
  real32_T dcos;                       /* '<S164>/dcos' */
  real32_T qsin;                       /* '<S164>/qsin' */
  real32_T sum_alpha;                  /* '<S164>/sum_alpha' */
  real32_T Switch[2];                  /* '<S165>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} rtB_TwoinputsCRL_mcb_pmsm_foc_f;

/* Block signals for system '<S24>/Two inputs CRL' */
typedef struct {
  real32_T acos_l;                     /* '<S169>/acos' */
  real32_T bsin;                       /* '<S169>/bsin' */
  real32_T sum_Ds;                     /* '<S169>/sum_Ds' */
  real32_T bcos;                       /* '<S169>/bcos' */
  real32_T asin_d;                     /* '<S169>/asin' */
  real32_T sum_Qs;                     /* '<S169>/sum_Qs' */
  real32_T Switch[2];                  /* '<S170>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} rtB_TwoinputsCRL_mcb_pmsm_foc_i;

/* Block signals for system '<S173>/If Action Subsystem' */
typedef struct {
  real32_T Convert_back;               /* '<S176>/Convert_back' */
  int16_T Convert_uint16;              /* '<S176>/Convert_uint16' */
} rtB_IfActionSubsystem_mcb_pmsm_;

/* Block signals for system '<S173>/If Action Subsystem1' */
typedef struct {
  real32_T Convert_back;               /* '<S177>/Convert_back' */
  int16_T Convert_uint16;              /* '<S177>/Convert_uint16' */
} rtB_IfActionSubsystem1_mcb_pmsm;

/* Block signals for system '<S211>/PositionNoReset' */
typedef struct {
  uint16_T Sum3;                       /* '<S227>/Sum3' */
  uint16_T Sum7;                       /* '<S227>/Sum7' */
} rtB_PositionNoReset_mcb_pmsm_fo;

/* Block signals for system '<S479>/If Action Subsystem' */
typedef struct {
  uint16_T Memory;                     /* '<S484>/Memory' */
  uint16_T Sum;                        /* '<S484>/Sum' */
  uint16_T Memory1;                    /* '<S484>/Memory1' */
  uint16_T Sum1;                       /* '<S484>/Sum1' */
} rtB_IfActionSubsystem_mcb_pms_d;

/* Block states (default storage) for system '<S479>/If Action Subsystem' */
typedef struct {
  uint16_T Memory_PreviousInput;       /* '<S484>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S484>/Memory1' */
} rtDW_IfActionSubsystem_mcb_pm_h;

/* Block signals for system '<S569>/D//Q Axis Priority' */
typedef struct {
  real32_T Switch[2];                  /* '<S573>/Switch' */
  real32_T Switch2;                    /* '<S583>/Switch2' */
  real32_T Product;                    /* '<S582>/Product' */
  real32_T Sum;                        /* '<S582>/Sum' */
  real32_T Product2;                   /* '<S582>/Product2' */
  real32_T Merge;                      /* '<S582>/Merge' */
  real32_T Gain;                       /* '<S582>/Gain' */
  real32_T Switch_m;                   /* '<S583>/Switch' */
  uint16_T DataTypeConversion;         /* '<S582>/Data Type Conversion' */
  boolean_T Compare;                   /* '<S578>/Compare' */
  boolean_T Compare_i;                 /* '<S579>/Compare' */
  boolean_T LowerRelop1;               /* '<S583>/LowerRelop1' */
  boolean_T RelationalOperator;        /* '<S582>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S583>/UpperRelop' */
  rtB_limitRef2_mcb_pmsm_foc_f283 limitRef2;/* '<S582>/limitRef2' */
} rtB_DQAxisPriority_mcb_pmsm_f_a;

/* Block signals for system '<Root>/Speed control for motor1' */
typedef struct {
  real32_T Abs;                        /* '<S563>/Abs' */
  real32_T Switch;                     /* '<S565>/Switch' */
  real32_T Switch1[2];                 /* '<S642>/Switch1' */
  real32_T Product;                    /* '<S645>/Product' */
  real32_T UnitDelay;                  /* '<S645>/Unit Delay' */
  real32_T Product1;                   /* '<S645>/Product1' */
  real32_T Add1;                       /* '<S645>/Add1' */
  real32_T Sum;                        /* '<S564>/Sum' */
  real32_T Imag;                       /* '<S567>/Saturation' */
  real32_T Switch_b;                   /* '<S574>/Switch' */
  real32_T Product_g;                  /* '<S574>/Product' */
  real32_T Merge;                      /* '<S567>/Merge' */
  real32_T Product_p;                  /* '<S575>/Product' */
  real32_T Product1_i;                 /* '<S575>/Product1' */
  real32_T Sum1;                       /* '<S575>/Sum1' */
  real32_T Merge_d[2];                 /* '<S569>/Merge' */
  real32_T Trq_ref;                    /* '<S564>/MATLAB Function' */
  real32_T MathFunction;               /* '<S570>/Math Function' */
  real32_T Gain;                       /* '<S570>/Gain' */
  uint16_T Switch1_i;                  /* '<S574>/Switch1' */
  uint16_T DataTypeConversion;         /* '<S567>/Data Type Conversion' */
  boolean_T Compare;                   /* '<S568>/Compare' */
  boolean_T DataStoreRead;             /* '<S565>/Data Store Read' */
  boolean_T DataStoreRead1;            /* '<S564>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S564>/Logical Operator' */
  rtB_DQEquivalence_mcb_pmsm_foc_ DQEquivalence;/* '<S569>/D-Q Equivalence' */
  rtB_DQAxisPriority_mcb_pmsm_f_a DQAxisPriority;/* '<S569>/D//Q Axis Priority' */
} rtB_Speedcontrolformotor1_mcb_p;

/* Block states (default storage) for system '<Root>/Speed control for motor1' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S645>/Unit Delay' */
  real32_T integrator_state;           /* '<S564>/MATLAB Function' */
} rtDW_Speedcontrolformotor1_mcb_;

/* Block signals for system '<Root>/Torque control for motor2' */
typedef struct {
  uint32_T Sum[4];                     /* '<S670>/Sum' */
  real32_T Convert_PU;                 /* '<S9>/Convert_PU' */
  real32_T Abs1;                       /* '<S647>/Abs1' */
  real32_T Product;                    /* '<S647>/Product' */
  real32_T Abs;                        /* '<S647>/Abs' */
  real32_T derating;                   /* '<S647>/derating' */
  real32_T Sum_c;                      /* '<S647>/Sum' */
  real32_T Merge;                      /* '<S647>/Merge' */
  real32_T Sum2;                       /* '<S647>/Sum2' */
  real32_T Imag_ref;                   /* '<S9>/Product' */
  real32_T Merge_p;                    /* '<S672>/Merge' */
  real32_T indexing;                   /* '<S670>/indexing' */
  real32_T Lookup[4];                  /* '<S670>/Lookup' */
  real32_T Sum3;                       /* '<S671>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S670>/Data Type Conversion1' */
  real32_T Sum2_m;                     /* '<S670>/Sum2' */
  real32_T Product_d;                  /* '<S671>/Product' */
  real32_T Sum4;                       /* '<S671>/Sum4' */
  real32_T Sum5;                       /* '<S671>/Sum5' */
  real32_T Product1;                   /* '<S671>/Product1' */
  real32_T Sum6;                       /* '<S671>/Sum6' */
  real32_T Switch;                     /* '<S651>/Switch' */
  real32_T Product_f;                  /* '<S651>/Product' */
  real32_T Product_k;                  /* '<S652>/Product' */
  real32_T Product1_d;                 /* '<S652>/Product1' */
  real32_T Sum1;                       /* '<S652>/Sum1' */
  real32_T Merge_j[2];                 /* '<S646>/Merge' */
  real32_T Divide1;                    /* '<S665>/Divide1' */
  uint16_T Switch1;                    /* '<S651>/Switch1' */
  uint16_T DataTypeConversion;         /* '<S647>/Data Type Conversion' */
  uint16_T DataTypeConversion_p;       /* '<S672>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S670>/Get_Integer' */
  boolean_T Compare;                   /* '<S663>/Compare' */
  boolean_T Compare_n;                 /* '<S674>/Compare' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1;/* '<S672>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem_o;/* '<S672>/If Action Subsystem' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_f TwoinputsCRL;/* '<S666>/Two inputs CRL' */
  rtB_DQEquivalence_mcb_pmsm_foc_ DQEquivalence;/* '<S646>/D-Q Equivalence' */
  rtB_DQAxisPriority_mcb_pmsm_f_a DQAxisPriority;/* '<S646>/D//Q Axis Priority' */
} rtB_Torquecontrolformotor2_mcb_;

/* Block states (default storage) for system '<Root>/Torque control for motor2' */
typedef struct {
  uint32_T Sum_DWORK1[4];              /* '<S670>/Sum' */
} rtDW_Torquecontrolformotor2_mcb;

/* Block signals (default storage) */
typedef struct {
  real_T DiscreteTimeIntegrator;       /* '<S499>/Discrete-Time Integrator' */
  real_T Gain;                         /* '<S6>/Gain' */
  real_T DiscreteTimeIntegrator3;      /* '<S517>/Discrete-Time Integrator3' */
  real_T UnitDelay;                    /* '<S502>/Unit Delay' */
  real_T Switch1;                      /* '<S502>/Switch1' */
  real_T Gain4;                        /* '<S499>/Gain4' */
  real_T sine_cosine_o1;               /* '<S501>/sine_cosine' */
  real_T sine_cosine_o2;               /* '<S501>/sine_cosine' */
  real_T Product2;                     /* '<S512>/Product2' */
  real_T DiscreteTimeIntegrator3_f;    /* '<S518>/Discrete-Time Integrator3' */
  real_T Product3;                     /* '<S512>/Product3' */
  real_T Add1;                         /* '<S512>/Add1' */
  real_T DiscreteTimeIntegrator3_c;    /* '<S546>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator3_j;    /* '<S547>/Discrete-Time Integrator3' */
  real_T Switch2;                      /* '<S6>/Switch2' */
  real_T Product;                      /* '<S513>/Product' */
  real_T Product_a;                    /* '<S516>/Product' */
  real_T Gain1;                        /* '<S513>/Gain1' */
  real_T Add;                          /* '<S513>/Add' */
  real_T Gain2;                        /* '<S513>/Gain2' */
  real_T Divide2;                      /* '<S499>/Divide2' */
  real_T Sign;                         /* '<S499>/Sign' */
  real_T Divide1;                      /* '<S499>/Divide1' */
  real_T Sum1;                         /* '<S499>/Sum1' */
  real_T Divide;                       /* '<S499>/Divide' */
  real_T Gain_f;                       /* '<S499>/Gain' */
  real_T Gain1_p;                      /* '<S502>/Gain1' */
  real_T Add_b;                        /* '<S502>/Add' */
  real_T Gain_b;                       /* '<S510>/Gain' */
  real_T Gain1_f;                      /* '<S510>/Gain1' */
  real_T Gain4_j;                      /* '<S510>/Gain4' */
  real_T Add_n;                        /* '<S510>/Add' */
  real_T Gain2_j;                      /* '<S510>/Gain2' */
  real_T Gain3;                        /* '<S510>/Gain3' */
  real_T Add1_c;                       /* '<S510>/Add1' */
  real_T Gain1_p0;                     /* '<S511>/Gain1' */
  real_T Gain2_c;                      /* '<S511>/Gain2' */
  real_T Product_f;                    /* '<S512>/Product' */
  real_T Product1;                     /* '<S512>/Product1' */
  real_T Add_e;                        /* '<S512>/Add' */
  real_T Gain3_l;                      /* '<S511>/Gain3' */
  real_T Gain4_h;                      /* '<S511>/Gain4' */
  real_T Product2_e;                   /* '<S515>/Product2' */
  real_T Product3_k;                   /* '<S515>/Product3' */
  real_T Add1_k;                       /* '<S515>/Add1' */
  real_T Product_j;                    /* '<S519>/Product' */
  real_T Product_ju;                   /* '<S517>/Product' */
  real_T Product_l;                    /* '<S520>/Product' */
  real_T Product_fy;                   /* '<S521>/Product' */
  real_T Add_i;                        /* '<S517>/Add' */
  real_T Product_c;                    /* '<S515>/Product' */
  real_T Product1_p;                   /* '<S515>/Product1' */
  real_T Add_p;                        /* '<S515>/Add' */
  real_T Product_p;                    /* '<S522>/Product' */
  real_T Product_i;                    /* '<S518>/Product' */
  real_T Product_b;                    /* '<S523>/Product' */
  real_T Product_d;                    /* '<S524>/Product' */
  real_T Product_ff;                   /* '<S525>/Product' */
  real_T Add_bp;                       /* '<S518>/Add' */
  real_T VectorConcatenate[3];         /* '<S498>/Vector Concatenate' */
  real_T UnitDelay_b;                  /* '<S531>/Unit Delay' */
  real_T Switch1_j;                    /* '<S531>/Switch1' */
  real_T Gain4_n;                      /* '<S528>/Gain4' */
  real_T sine_cosine_o1_l;             /* '<S530>/sine_cosine' */
  real_T sine_cosine_o2_j;             /* '<S530>/sine_cosine' */
  real_T Product2_o;                   /* '<S541>/Product2' */
  real_T Product3_h;                   /* '<S541>/Product3' */
  real_T Add1_m;                       /* '<S541>/Add1' */
  real_T Gain_i;                       /* '<S528>/Gain' */
  real_T Gain1_fb;                     /* '<S531>/Gain1' */
  real_T Add_bd;                       /* '<S531>/Add' */
  real_T Switch1_p[3];                 /* '<S6>/Switch1' */
  real_T Gain_p;                       /* '<S539>/Gain' */
  real_T Gain1_fm;                     /* '<S539>/Gain1' */
  real_T Gain4_i;                      /* '<S539>/Gain4' */
  real_T Add_a;                        /* '<S539>/Add' */
  real_T Gain2_d;                      /* '<S539>/Gain2' */
  real_T Gain3_e;                      /* '<S539>/Gain3' */
  real_T Add1_n;                       /* '<S539>/Add1' */
  real_T Gain1_m;                      /* '<S540>/Gain1' */
  real_T Gain2_b;                      /* '<S540>/Gain2' */
  real_T Product_ld;                   /* '<S541>/Product' */
  real_T Product1_i;                   /* '<S541>/Product1' */
  real_T Add_d;                        /* '<S541>/Add' */
  real_T Gain3_l1;                     /* '<S540>/Gain3' */
  real_T Gain4_e;                      /* '<S540>/Gain4' */
  real_T Product2_f;                   /* '<S544>/Product2' */
  real_T Product3_o;                   /* '<S544>/Product3' */
  real_T Add1_f;                       /* '<S544>/Add1' */
  real_T Product_av;                   /* '<S548>/Product' */
  real_T Product_m;                    /* '<S546>/Product' */
  real_T Product_dj;                   /* '<S549>/Product' */
  real_T Product_bb;                   /* '<S550>/Product' */
  real_T Add_ex;                       /* '<S546>/Add' */
  real_T Product_di;                   /* '<S544>/Product' */
  real_T Product1_ih;                  /* '<S544>/Product1' */
  real_T Add_a4;                       /* '<S544>/Add' */
  real_T Product_n;                    /* '<S551>/Product' */
  real_T Product_e;                    /* '<S547>/Product' */
  real_T Product_f3;                   /* '<S552>/Product' */
  real_T Product_aa;                   /* '<S553>/Product' */
  real_T Product_g;                    /* '<S554>/Product' */
  real_T Add_f;                        /* '<S547>/Add' */
  real_T VectorConcatenate_j[3];       /* '<S527>/Vector Concatenate' */
  real_T Gain1_n;                      /* '<S542>/Gain1' */
  real_T Product_fb;                   /* '<S542>/Product' */
  real_T Product_k;                    /* '<S545>/Product' */
  real_T Add_d1;                       /* '<S542>/Add' */
  real_T Gain2_bo;                     /* '<S542>/Gain2' */
  real_T Add1_h;                       /* '<S531>/Add1' */
  real_T Switch;                       /* '<S531>/Switch' */
  real_T Subtract;                     /* '<S531>/Subtract' */
  real_T Add1_e;                       /* '<S502>/Add1' */
  real_T Switch_a;                     /* '<S502>/Switch' */
  real_T Subtract_m;                   /* '<S502>/Subtract' */
  uint32_T PositionToCount;            /* '<S437>/PositionToCount' */
  uint32_T Delay;                      /* '<S437>/Delay' */
  uint32_T Sum[4];                     /* '<S412>/Sum' */
  uint32_T PositionToCount_n;          /* '<S212>/PositionToCount' */
  uint32_T Delay_o;                    /* '<S212>/Delay' */
  uint32_T BytePack[2];                /* '<S243>/Byte Pack' */
  uint32_T SCI_Tx_Data[3];             /* '<S241>/Merge' */
  uint32_T SCI_Tx_Iteration;           /* '<S241>/Merge1' */
  uint32_T IndexVector;                /* '<S242>/Index Vector' */
  uint32_T Add_fy;                     /* '<S242>/Add' */
  uint32_T Data[2];                    /* '<S245>/Data' */
  uint32_T Data_f[2];                  /* '<S246>/Data' */
  uint32_T Data_fw[2];                 /* '<S247>/Data' */
  uint32_T Sum_f[4];                   /* '<S195>/Sum' */
  uint32_T Sum_j[4];                   /* '<S171>/Sum' */
  real32_T RT1;                        /* '<Root>/RT1' */
  real32_T RT10;                       /* '<Root>/RT10' */
  real32_T RT3;                        /* '<Root>/RT3' */
  real32_T RT9;                        /* '<Root>/RT9' */
  real32_T RT8;                        /* '<Root>/RT8' */
  real32_T RT2[2];                     /* '<Root>/RT2' */
  real32_T mtr2_VI_debug[6];           /* '<Root>/RT6' */
  real32_T mtr2_Te_PU;                 /* '<Root>/RT6' */
  real32_T mtr2_Pm_PU;                 /* '<Root>/RT6' */
  real32_T mtr2_Speed_PU;              /* '<Root>/RT6' */
  real32_T mtr2_Iab_meas_PU[2];        /* '<Root>/RT6' */
  real32_T mtr2_Pos_PU;                /* '<Root>/RT6' */
  real32_T RT7[2];                     /* '<Root>/RT7' */
  real32_T SCIReceive[4];              /* '<S562>/SCI Receive' */
  real32_T OutportBufferForDesiredImagpos;/* '<S7>/Parse SCI Rx' */
  real32_T OutportBufferForDesriedImagref;/* '<S7>/Parse SCI Rx' */
  real32_T GetADCVoltage[2];           /* '<S460>/Get ADC Voltage' */
  real32_T GetCurrents[2];             /* '<S460>/Get Currents' */
  real32_T PU_Conversion[2];           /* '<S460>/PU_Conversion' */
  real32_T InvertingNoninvertingCurrentmea[2];
      /* '<S433>/Inverting // Non-inverting  Current measurement  amplifieer' */
  real32_T DTC;                        /* '<S453>/DTC' */
  real32_T Product_ib;                 /* '<S436>/Product' */
  real32_T DTC_k;                      /* '<S458>/DTC' */
  real32_T SpeedGain;                  /* '<S437>/SpeedGain' */
  real32_T Switch1_pe[2];              /* '<S434>/Switch1' */
  real32_T Product_mq;                 /* '<S440>/Product' */
  real32_T UnitDelay_g;                /* '<S440>/Unit Delay' */
  real32_T Product1_n;                 /* '<S440>/Product1' */
  real32_T Add1_i;                     /* '<S440>/Add1' */
  real32_T Switch_f;                   /* '<S442>/Switch' */
  real32_T Merge;                      /* '<S443>/Merge' */
  real32_T Numberofpolepairs;          /* '<S448>/Number of pole pairs' */
  real32_T Floor;                      /* '<S444>/Floor' */
  real32_T Add_exa;                    /* '<S444>/Add' */
  real32_T mtr2_VI_debug_k[6];
  real32_T mtr2_Te_PU_i;
  real32_T mtr2_Pm_PU_m;
  real32_T mtr2_Speed_PU_h;
                   /* '<S2>/BusConversion_InsertedFor_mtr2_debug_at_inport_0' */
  real32_T mtr2_Iab_meas_PU_j[2];
                   /* '<S2>/BusConversion_InsertedFor_mtr2_debug_at_inport_0' */
  real32_T mtr2_Pos_PU_d;
                   /* '<S2>/BusConversion_InsertedFor_mtr2_debug_at_inport_0' */
  real32_T DataTypeConversion;         /* '<S255>/Data Type Conversion' */
  real32_T Switch_c;                   /* '<S461>/Switch' */
  real32_T Switch_n[3];                /* '<S250>/Switch' */
  real32_T One_by_Two[3];              /* '<S255>/One_by_Two' */
  real32_T Mtr2_PWM_Duty_Cycles[3];    /* '<S255>/Sum' */
  real32_T UnitDelay_m;                /* '<S429>/Unit Delay' */
  real32_T Add_c;                      /* '<S429>/Add' */
  real32_T mtr2_Speed_PU_hk;
                      /* '<S256>/BusConversion_InsertedFor_debug_at_inport_0' */
  real32_T mtr2_Iab_meas_PU_jj[2];
                      /* '<S256>/BusConversion_InsertedFor_debug_at_inport_0' */
  real32_T mtr2_Pos_PU_db;
                      /* '<S256>/BusConversion_InsertedFor_debug_at_inport_0' */
  real32_T Switch1_h[2];               /* '<S259>/Switch1' */
  real32_T Product_cc[2];              /* '<S404>/Product' */
  real32_T UnitDelay_e[2];             /* '<S404>/Unit Delay' */
  real32_T Product1_e[2];              /* '<S404>/Product1' */
  real32_T Add1_ft[2];                 /* '<S404>/Add1' */
  real32_T Merge_l;                    /* '<S414>/Merge' */
  real32_T indexing;                   /* '<S412>/indexing' */
  real32_T Lookup[4];                  /* '<S412>/Lookup' */
  real32_T Sum3;                       /* '<S413>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S412>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S412>/Sum2' */
  real32_T Product_h;                  /* '<S413>/Product' */
  real32_T Sum4;                       /* '<S413>/Sum4' */
  real32_T Sum5;                       /* '<S413>/Sum5' */
  real32_T Product1_ns;                /* '<S413>/Product1' */
  real32_T Sum6;                       /* '<S413>/Sum6' */
  real32_T Sum_jx;                     /* '<S269>/Sum' */
  real32_T we;                         /* '<S398>/wm_pu2si_mech2elec' */
  real32_T Ld_id;                      /* '<S398>/prod3' */
  real32_T fluxD;                      /* '<S398>/add1' */
  real32_T VqFF_unsat;                 /* '<S398>/prod2' */
  real32_T Switch2_j;                  /* '<S401>/Switch2' */
  real32_T Sum1_g;                     /* '<S258>/Sum1' */
  real32_T Sum_o;                      /* '<S268>/Sum' */
  real32_T w_Lq_iq;                    /* '<S398>/prod1' */
  real32_T VdFF_unsat;                 /* '<S398>/NegSign' */
  real32_T Switch2_k;                  /* '<S400>/Switch2' */
  real32_T Sum_m;                      /* '<S258>/Sum' */
  real32_T Switch_o;                   /* '<S273>/Switch' */
  real32_T Product_cg;                 /* '<S273>/Product' */
  real32_T Product_ae;                 /* '<S274>/Product' */
  real32_T Product1_j;                 /* '<S274>/Product1' */
  real32_T Sum1_a;                     /* '<S274>/Sum1' */
  real32_T Merge_d[2];                 /* '<S267>/Merge' */
  real32_T id_Ld_Lq;                   /* '<S408>/Product1' */
  real32_T Add_b3;                     /* '<S408>/Add' */
  real32_T Product3_l;                 /* '<S408>/Product3' */
  real32_T u_5_Pp;                     /* '<S408>/1_5_Pp' */
  real32_T Product_ee;                 /* '<S408>/Product' */
  real32_T P_output;                   /* '<S408>/P_si2pu' */
  real32_T T_output;                   /* '<S408>/T_si2pu' */
  real32_T one_by_two;                 /* '<S426>/one_by_two' */
  real32_T sqrt3_by_two;               /* '<S426>/sqrt3_by_two' */
  real32_T add_b;                      /* '<S426>/add_b' */
  real32_T add_c;                      /* '<S426>/add_c' */
  real32_T Max;                        /* '<S423>/Max' */
  real32_T Min;                        /* '<S423>/Min' */
  real32_T Add_o;                      /* '<S423>/Add' */
  real32_T one_by_two_k;               /* '<S423>/one_by_two' */
  real32_T Add1_kg;                    /* '<S422>/Add1' */
  real32_T Add2;                       /* '<S422>/Add2' */
  real32_T Add3;                       /* '<S422>/Add3' */
  real32_T Gain_d[3];                  /* '<S422>/Gain' */
  real32_T Switch_k;                   /* '<S401>/Switch' */
  real32_T Switch_ns;                  /* '<S400>/Switch' */
  real32_T GetADCVoltage_b[2];         /* '<S237>/Get ADC Voltage' */
  real32_T GetCurrents_n[2];           /* '<S237>/Get Currents' */
  real32_T PU_Conversion_d[2];         /* '<S237>/PU_Conversion' */
  real32_T InvertingNoninvertingCurrentm_h[2];
      /* '<S207>/Inverting // Non-inverting  Current measurement  amplifieer' */
  real32_T DTC_i;                      /* '<S230>/DTC' */
  real32_T Product_ie;                 /* '<S211>/Product' */
  real32_T DTC_a;                      /* '<S235>/DTC' */
  real32_T SpeedGain_f;                /* '<S212>/SpeedGain' */
  real32_T Switch1_i[2];               /* '<S208>/Switch1' */
  real32_T Product_fp;                 /* '<S215>/Product' */
  real32_T UnitDelay_eq;               /* '<S215>/Unit Delay' */
  real32_T Product1_m;                 /* '<S215>/Product1' */
  real32_T Add1_g;                     /* '<S215>/Add1' */
  real32_T Switch_e;                   /* '<S219>/Switch' */
  real32_T Merge_n;                    /* '<S220>/Merge' */
  real32_T Numberofpolepairs_i;        /* '<S225>/Number of pole pairs' */
  real32_T Floor_g;                    /* '<S221>/Floor' */
  real32_T Add_nd;                     /* '<S221>/Add' */
  real32_T mtr1_speed_ref_PU;          /* '<S17>/Data Store Read' */
  real32_T TmpSignalConversionAtSelectorIn[25];
  real32_T Selector[2];                /* '<S17>/Selector' */
  real32_T DataTypeConversion_i;       /* '<S15>/Data Type Conversion' */
  real32_T Switch_k0;                  /* '<S238>/Switch' */
  real32_T Switch_h[3];                /* '<S10>/Switch' */
  real32_T One_by_Two_n[3];            /* '<S15>/One_by_Two' */
  real32_T Mtr1_PWM_Duty_Cycles[3];    /* '<S15>/Sum' */
  real32_T rpm2freq;                   /* '<S19>/rpm2freq' */
  real32_T Eps;                        /* '<S188>/Ramp Generator' */
  real32_T Product_bc;                 /* '<S19>/Product' */
  real32_T Frequency;                  /* '<S19>/Abs' */
  real32_T Vbyf;                       /* '<S19>/V-by-f' */
  real32_T Correction_Factor_sinePWM;  /* '<S19>/Correction_Factor_sinePWM' */
  real32_T Amplitude;                  /* '<S19>/Saturation' */
  real32_T UnaryMinus;                 /* '<S186>/Unary Minus' */
  real32_T position_increment;         /* '<S19>/position_increment' */
  real32_T scaleIn;                    /* '<S187>/scaleIn' */
  real32_T UnitDelay_l;                /* '<S187>/Unit Delay' */
  real32_T scaleOut;                   /* '<S187>/scaleOut' */
  real32_T DataStoreRead;              /* '<S19>/Data Store Read' */
  real32_T Eps_k;                      /* '<S19>/Direction' */
  real32_T convert_pu;                 /* '<S197>/convert_pu' */
  real32_T Merge_h;                    /* '<S197>/Merge' */
  real32_T indexing_h;                 /* '<S195>/indexing' */
  real32_T Lookup_a[4];                /* '<S195>/Lookup' */
  real32_T Sum3_b;                     /* '<S196>/Sum3' */
  real32_T DataTypeConversion1_a;      /* '<S195>/Data Type Conversion1' */
  real32_T Sum2_p;                     /* '<S195>/Sum2' */
  real32_T Product_g4;                 /* '<S196>/Product' */
  real32_T Sum4_i;                     /* '<S196>/Sum4' */
  real32_T Sum5_g;                     /* '<S196>/Sum5' */
  real32_T Product1_m4;                /* '<S196>/Product1' */
  real32_T Sum6_n;                     /* '<S196>/Sum6' */
  real32_T Ka;                         /* '<S192>/Ka' */
  real32_T one_by_two_h;               /* '<S192>/one_by_two' */
  real32_T sqrt3_by_two_d;             /* '<S192>/sqrt3_by_two' */
  real32_T add_b_m;                    /* '<S192>/add_b' */
  real32_T Kb;                         /* '<S192>/Kb' */
  real32_T add_c_o;                    /* '<S192>/add_c' */
  real32_T Kc;                         /* '<S192>/Kc' */
  real32_T Divide_h;                   /* '<S188>/Divide' */
  real32_T Sample_Time;                /* '<S188>/Sample_Time' */
  real32_T Sum_h;                      /* '<S19>/Sum' */
  real32_T Add_f4;                     /* '<S203>/Add' */
  real32_T DataTypeConversion1_i;      /* '<S203>/Data Type Conversion1' */
  real32_T Add1_c5;                    /* '<S203>/Add1' */
  real32_T Input;                      /* '<S204>/Input' */
  real32_T Merge_lj;                   /* '<S173>/Merge' */
  real32_T indexing_l;                 /* '<S171>/indexing' */
  real32_T Lookup_f[4];                /* '<S171>/Lookup' */
  real32_T Sum3_o;                     /* '<S172>/Sum3' */
  real32_T DataTypeConversion1_m;      /* '<S171>/Data Type Conversion1' */
  real32_T Sum2_f;                     /* '<S171>/Sum2' */
  real32_T Product_kl;                 /* '<S172>/Product' */
  real32_T Sum4_b;                     /* '<S172>/Sum4' */
  real32_T Sum5_h;                     /* '<S172>/Sum5' */
  real32_T Product1_iu;                /* '<S172>/Product1' */
  real32_T Sum6_m;                     /* '<S172>/Sum6' */
  real32_T Sum_c;                      /* '<S30>/Sum' */
  real32_T we_n;                       /* '<S160>/wm_pu2si_mech2elec' */
  real32_T w_Lq_iq_b;                  /* '<S160>/prod1' */
  real32_T VdFF_unsat_o;               /* '<S160>/NegSign' */
  real32_T Switch2_o;                  /* '<S162>/Switch2' */
  real32_T Sum_hy;                     /* '<S21>/Sum' */
  real32_T Sum_k;                      /* '<S31>/Sum' */
  real32_T Ld_id_j;                    /* '<S160>/prod3' */
  real32_T fluxD_h;                    /* '<S160>/add1' */
  real32_T VqFF_unsat_b;               /* '<S160>/prod2' */
  real32_T Switch2_e;                  /* '<S163>/Switch2' */
  real32_T Sum1_n;                     /* '<S21>/Sum1' */
  real32_T mtr1_VI_debug[6];
                       /* '<S18>/BusConversion_InsertedFor_debug_at_inport_0' */
  real32_T mtr1_Speed_PU;
                       /* '<S18>/BusConversion_InsertedFor_debug_at_inport_0' */
  real32_T mtr1_Iab_meas_PU[2];
                       /* '<S18>/BusConversion_InsertedFor_debug_at_inport_0' */
  real32_T mtr1_Pos_PU;/* '<S18>/BusConversion_InsertedFor_debug_at_inport_0' */
  real32_T Switch_l;                   /* '<S35>/Switch' */
  real32_T Product_lu;                 /* '<S35>/Product' */
  real32_T Product_p1;                 /* '<S36>/Product' */
  real32_T Product1_m4h;               /* '<S36>/Product1' */
  real32_T Sum1_f;                     /* '<S36>/Sum1' */
  real32_T Merge_f[2];                 /* '<S29>/Merge' */
  real32_T id_Ld_Lq_c;                 /* '<S167>/Product1' */
  real32_T Add_op;                     /* '<S167>/Add' */
  real32_T Product3_o4;                /* '<S167>/Product3' */
  real32_T u_5_Pp_a;                   /* '<S167>/1_5_Pp' */
  real32_T Product_bm;                 /* '<S167>/Product' */
  real32_T P_output_a;                 /* '<S167>/P_si2pu' */
  real32_T T_output_f;                 /* '<S167>/T_si2pu' */
  real32_T one_by_two_m;               /* '<S185>/one_by_two' */
  real32_T sqrt3_by_two_g;             /* '<S185>/sqrt3_by_two' */
  real32_T add_b_b;                    /* '<S185>/add_b' */
  real32_T add_c_m;                    /* '<S185>/add_c' */
  real32_T Max_d;                      /* '<S182>/Max' */
  real32_T Min_n;                      /* '<S182>/Min' */
  real32_T Add_g;                      /* '<S182>/Add' */
  real32_T one_by_two_e;               /* '<S182>/one_by_two' */
  real32_T Add1_o;                     /* '<S181>/Add1' */
  real32_T Add2_l;                     /* '<S181>/Add2' */
  real32_T Add3_b;                     /* '<S181>/Add3' */
  real32_T Gain_db[3];                 /* '<S181>/Gain' */
  real32_T Switch_b;                   /* '<S163>/Switch' */
  real32_T Switch_aa;                  /* '<S162>/Switch' */
  int32_T DataTypeConversion_p[2];     /* '<S433>/Data Type Conversion' */
  int32_T Add_co[2];                   /* '<S433>/Add' */
  int32_T SpeedCount;                  /* '<S437>/SpeedCount' */
  int32_T DataTypeConversion_a[2];     /* '<S207>/Data Type Conversion' */
  int32_T Add_l[2];                    /* '<S207>/Add' */
  int32_T SpeedCount_m;                /* '<S212>/SpeedCount' */
  uint16_T Switch_p;                   /* '<S476>/Switch' */
  uint16_T Switch1_i1;                 /* '<S476>/Switch1' */
  uint16_T Divide2_e;                  /* '<S485>/Divide2' */
  uint16_T Divide3;                    /* '<S485>/Divide3' */
  uint16_T ForIterator;                /* '<S487>/For Iterator' */
  uint16_T ADC_A_IN1;                  /* '<S487>/ADC_A_IN1' */
  uint16_T ADC_B_IN1;                  /* '<S487>/ADC_B_IN1' */
  uint16_T Divide_i;                   /* '<S477>/Divide' */
  uint16_T Divide1_c;                  /* '<S477>/Divide1' */
  uint16_T ForIterator_i;              /* '<S479>/For Iterator' */
  uint16_T ADC_A_IN0;                  /* '<S479>/ADC_A_IN0' */
  uint16_T ADC_B_IN0;                  /* '<S479>/ADC_B_IN0' */
  uint16_T DataTypeConversion2;        /* '<S559>/Data Type Conversion2' */
  uint16_T BitwiseOperator;            /* '<S558>/Bitwise Operator' */
  uint16_T BitwiseOperator1;           /* '<S558>/Bitwise Operator1' */
  uint16_T ShiftArithmetic1;           /* '<S558>/Shift Arithmetic1' */
  uint16_T DataStoreRead1;             /* '<S433>/Data Store Read1' */
  uint16_T DataStoreRead2;             /* '<S433>/Data Store Read2' */
  uint16_T ADC_C_IN4;                  /* '<S431>/ADC_C_IN4' */
  uint16_T ADC_B_IN4;                  /* '<S431>/ADC_B_IN4' */
  uint16_T eQEP_o1;                    /* '<S431>/eQEP' */
  uint16_T eQEP_o2;                    /* '<S431>/eQEP' */
  uint16_T Merge_j;                    /* '<S436>/Merge' */
  uint16_T Switch1_o[3];               /* '<S461>/Switch1' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S461>/Scale_to_PWM_Counter_PRD' */
  uint16_T Switch1_m;                  /* '<S273>/Switch1' */
  uint16_T DataTypeConversion_j;       /* '<S414>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S412>/Get_Integer' */
  uint16_T eQEP_o1_b;                  /* '<S205>/eQEP' */
  uint16_T eQEP_o2_a;                  /* '<S205>/eQEP' */
  uint16_T DataStoreRead1_e;           /* '<S207>/Data Store Read1' */
  uint16_T DataStoreRead2_k;           /* '<S207>/Data Store Read2' */
  uint16_T ADC_C_IN2;                  /* '<S205>/ADC_C_IN2' */
  uint16_T ADC_B_IN2;                  /* '<S205>/ADC_B_IN2' */
  uint16_T Merge_p;                    /* '<S211>/Merge' */
  uint16_T Output;                     /* '<S244>/Output' */
  uint16_T DataStoreRead1_m;           /* '<S17>/Data Store Read1' */
  uint16_T MultiportSwitch[2];         /* '<S17>/Multiport Switch' */
  uint16_T FixPtSum1;                  /* '<S248>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S249>/FixPt Switch' */
  uint16_T Switch1_ic[3];              /* '<S238>/Switch1' */
  uint16_T Scale_to_PWM_Counter_PRD_g[3];/* '<S238>/Scale_to_PWM_Counter_PRD' */
  uint16_T Delay3;                     /* '<S209>/Delay3' */
  uint16_T DataTypeConversion_d;       /* '<S197>/Data Type Conversion' */
  uint16_T Get_Integer_g;              /* '<S195>/Get_Integer' */
  uint16_T DataTypeConversion_b;       /* '<S173>/Data Type Conversion' */
  uint16_T Get_Integer_l;              /* '<S171>/Get_Integer' */
  uint16_T Switch1_e;                  /* '<S35>/Switch1' */
  int16_T WhileIterator;               /* '<S242>/While Iterator' */
  int16_T DataTypeConversion_f;        /* '<S203>/Data Type Conversion' */
  boolean_T DataStoreRead1_i;          /* '<S6>/Data Store Read1' */
  boolean_T DataStoreRead2_d;          /* '<S6>/Data Store Read2' */
  boolean_T Compare;                   /* '<S504>/Compare' */
  boolean_T Compare_h;                 /* '<S533>/Compare' */
  boolean_T Compare_m;                 /* '<S532>/Compare' */
  boolean_T Compare_b;                 /* '<S503>/Compare' */
  boolean_T NOT;                       /* '<S476>/NOT' */
  boolean_T NOT1;                      /* '<S476>/NOT1' */
  boolean_T NOT_d;                     /* '<S475>/NOT' */
  boolean_T NOT_h;                     /* '<S474>/NOT' */
  boolean_T DataTypeConversion3;       /* '<S558>/Data Type Conversion3' */
  boolean_T DataStoreRead1_l;          /* '<S2>/Data Store Read1' */
  boolean_T PWM_En;                    /* '<S255>/Enable' */
  boolean_T Activelowlogicforinverterenable;/* '<S461>/NOT' */
  boolean_T DataStoreRead2_l;          /* '<S427>/Data Store Read2' */
  boolean_T DataStoreRead1_f;          /* '<S427>/Data Store Read1' */
  boolean_T AND;                       /* '<S427>/AND' */
  boolean_T NOT_hf;                    /* '<S427>/NOT' */
  boolean_T Switch_i;                  /* '<S429>/Switch' */
  boolean_T Compare_a;                 /* '<S416>/Compare' */
  boolean_T DataStoreRead1_fz;         /* '<S269>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S269>/Logical Operator' */
  boolean_T LowerRelop1;               /* '<S401>/LowerRelop1' */
  boolean_T DataStoreRead1_lc;         /* '<S268>/Data Store Read1' */
  boolean_T LogicalOperator_f;         /* '<S268>/Logical Operator' */
  boolean_T LowerRelop1_e;             /* '<S400>/LowerRelop1' */
  boolean_T UpperRelop;                /* '<S401>/UpperRelop' */
  boolean_T UpperRelop_j;              /* '<S400>/UpperRelop' */
  boolean_T Delay_f;                   /* '<S206>/Delay' */
  boolean_T NOT_o;                     /* '<S206>/NOT' */
  boolean_T NOT_oi;                    /* '<S10>/NOT' */
  boolean_T DataStoreRead1_n;          /* '<S11>/Data Store Read1' */
  boolean_T DataStoreRead2_f;          /* '<S11>/Data Store Read2' */
  boolean_T AND_o;                     /* '<S11>/AND' */
  boolean_T PWM_En_a;                  /* '<S15>/Enable' */
  boolean_T Activelowlogicforinverterenab_k;/* '<S238>/NOT' */
  boolean_T Compare_mq;                /* '<S216>/Compare' */
  boolean_T Compare_n;                 /* '<S217>/Compare' */
  boolean_T AND_a;                     /* '<S209>/AND' */
  boolean_T DataStoreRead1_p;          /* '<S19>/Data Store Read1' */
  boolean_T NOT_j;                     /* '<S188>/NOT' */
  boolean_T NOT_n;                     /* '<S187>/NOT' */
  boolean_T Compare_f;                 /* '<S199>/Compare' */
  boolean_T Delay_fc;                  /* '<S203>/Delay' */
  boolean_T Compare_a4;                /* '<S175>/Compare' */
  boolean_T DataStoreRead1_iy;         /* '<S30>/Data Store Read1' */
  boolean_T LogicalOperator_m;         /* '<S30>/Logical Operator' */
  boolean_T LowerRelop1_l;             /* '<S162>/LowerRelop1' */
  boolean_T DataStoreRead1_lw;         /* '<S31>/Data Store Read1' */
  boolean_T LogicalOperator_p;         /* '<S31>/Logical Operator' */
  boolean_T LowerRelop1_j;             /* '<S163>/LowerRelop1' */
  boolean_T UpperRelop_f;              /* '<S163>/UpperRelop' */
  boolean_T UpperRelop_n;              /* '<S162>/UpperRelop' */
  rtB_Torquecontrolformotor2_mcb_ Torquecontrolformotor2;/* '<Root>/Torque control for motor2' */
  rtB_Speedcontrolformotor1_mcb_p Speedcontrolformotor1;/* '<Root>/Speed control for motor1' */
  rtB_IfActionSubsystem_mcb_pms_d IfActionSubsystem1_j;/* '<S487>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pms_d IfActionSubsystem_bv;/* '<S479>/If Action Subsystem' */
  rtB_PositionNoReset_mcb_pmsm_fo PositionNoReset_i;/* '<S436>/PositionNoReset' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1_i;/* '<S414>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem_e;/* '<S414>/If Action Subsystem' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_i TwoinputsCRL_i;/* '<S262>/Two inputs CRL' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_f TwoinputsCRL_c;/* '<S260>/Two inputs CRL' */
  rtB_MATLABFunction_mcb_pmsm_f_o sf_MATLABFunction_k;/* '<S269>/MATLAB Function' */
  rtB_MATLABFunction_mcb_pmsm_foc sf_MATLABFunction_i;/* '<S268>/MATLAB Function' */
  rtB_DQEquivalence_mcb_pmsm_foc_ DQEquivalence_f;/* '<S267>/D-Q Equivalence' */
  rtB_DQAxisPriority_mcb_pmsm_foc DQAxisPriority_k;/* '<S267>/D//Q Axis Priority' */
  rtB_TwophaseCRLwrap_mcb_pmsm_fo TwophaseCRLwrap_h;/* '<S265>/Two phase CRL wrap' */
  rtB_PositionNoReset_mcb_pmsm_fo PositionNoReset;/* '<S211>/PositionNoReset' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1_l;/* '<S197>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem_b;/* '<S197>/If Action Subsystem' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_f TwoinputsCRL_a;/* '<S190>/Two inputs CRL' */
  rtB_IfActionSubsystem1_mcb_pmsm IfActionSubsystem1_k;/* '<S173>/If Action Subsystem1' */
  rtB_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem_p;/* '<S173>/If Action Subsystem' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_i TwoinputsCRL_o;/* '<S24>/Two inputs CRL' */
  rtB_TwoinputsCRL_mcb_pmsm_foc_f TwoinputsCRL;/* '<S22>/Two inputs CRL' */
  rtB_MATLABFunction_mcb_pmsm_f_o sf_MATLABFunction_j;/* '<S31>/MATLAB Function' */
  rtB_MATLABFunction_mcb_pmsm_foc sf_MATLABFunction;/* '<S30>/MATLAB Function' */
  rtB_DQEquivalence_mcb_pmsm_foc_ DQEquivalence;/* '<S29>/D-Q Equivalence' */
  rtB_DQAxisPriority_mcb_pmsm_foc DQAxisPriority;/* '<S29>/D//Q Axis Priority' */
  rtB_TwophaseCRLwrap_mcb_pmsm_fo TwophaseCRLwrap;/* '<S27>/Two phase CRL wrap' */
} BlockIO_mcb_pmsm_foc_f28379d_dy;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S499>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S517>/Discrete-Time Integrator3' */
  real_T UnitDelay_DSTATE;             /* '<S502>/Unit Delay' */
  real_T DiscreteTimeIntegrator3_DSTAT_j;/* '<S518>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator3_DSTAT_p;/* '<S546>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator3_DSTAT_h;/* '<S547>/Discrete-Time Integrator3' */
  real_T UnitDelay_DSTATE_b;           /* '<S531>/Unit Delay' */
  real_T Add1_DWORK1;                  /* '<S531>/Add1' */
  real32_T UnitDelay_DSTATE_a;         /* '<S440>/Unit Delay' */
  real32_T UnitDelay_DSTATE_l;         /* '<S429>/Unit Delay' */
  real32_T UnitDelay_DSTATE_e[2];      /* '<S404>/Unit Delay' */
  real32_T UnitDelay_DSTATE_az;        /* '<S215>/Unit Delay' */
  real32_T RampGenerator_DSTATE;       /* '<S188>/Ramp Generator' */
  real32_T UnitDelay_DSTATE_ex;        /* '<S187>/Unit Delay' */
  uint32_T Delay_DSTATE[20];           /* '<S437>/Delay' */
  uint32_T Delay_DSTATE_d[20];         /* '<S212>/Delay' */
  volatile real32_T RT1_Buffer[2];     /* '<Root>/RT1' */
  volatile real32_T RT10_Buffer[2];    /* '<Root>/RT10' */
  volatile real32_T RT3_Buffer[2];     /* '<Root>/RT3' */
  volatile real32_T RT2_Buffer[4];     /* '<Root>/RT2' */
  volatile real32_T RT9_Buffer[2];     /* '<Root>/RT9' */
  volatile real32_T RT8_Buffer[2];     /* '<Root>/RT8' */
  volatile real32_T RT7_Buffer[4];     /* '<Root>/RT7' */
  volatile real32_T RT6_1_Buffer[12];  /* '<Root>/RT6' */
  volatile real32_T RT6_2_Buffer[2];   /* '<Root>/RT6' */
  volatile real32_T RT6_3_Buffer[2];   /* '<Root>/RT6' */
  volatile real32_T RT6_4_Buffer[2];   /* '<Root>/RT6' */
  volatile real32_T RT6_5_Buffer[4];   /* '<Root>/RT6' */
  volatile real32_T RT6_6_Buffer[2];   /* '<Root>/RT6' */
  real32_T SpeedRef;                   /* '<Root>/Data Store Memory4' */
  real32_T Add_DWORK1;                 /* '<S429>/Add' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S494>/Digital Output' */
  int32_T DigitalOutput_FRAC_LEN_a;    /* '<S476>/Digital Output' */
  int32_T BottomDRV8305EN_FRAC_LEN;    /* '<S476>/Bottom DRV8305 EN' */
  int32_T Add_DWORK1_b[2];             /* '<S433>/Add' */
  int32_T SpeedCount_DWORK1;           /* '<S437>/SpeedCount' */
  int32_T Inverterenable_FRAC_LEN;     /* '<S461>/Inverter enable' */
  int32_T GPIO16_FRAC_LEN;             /* '<S430>/GPIO16' */
  int32_T GPIO16_FRAC_LEN_j;           /* '<S428>/GPIO16' */
  int32_T Add_DWORK1_d[2];             /* '<S207>/Add' */
  int32_T SpeedCount_DWORK1_j;         /* '<S212>/SpeedCount' */
  int32_T Inverterenable_FRAC_LEN_m;   /* '<S238>/Inverter enable' */
  uint32_T Sum_DWORK1[4];              /* '<S412>/Sum' */
  uint32_T Add_DWORK1_e;               /* '<S242>/Add' */
  uint32_T Sum_DWORK1_n[4];            /* '<S195>/Sum' */
  uint16_T Output_DSTATE;              /* '<S244>/Output' */
  uint16_T Delay3_DSTATE;              /* '<S209>/Delay3' */
  volatile int16_T RT1_ActiveBufIdx;   /* '<Root>/RT1' */
  volatile int16_T RT1_semaphoreTaken; /* '<Root>/RT1' */
  volatile int16_T RT10_ActiveBufIdx;  /* '<Root>/RT10' */
  volatile int16_T RT3_ActiveBufIdx;   /* '<Root>/RT3' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  volatile int16_T RT9_ActiveBufIdx;   /* '<Root>/RT9' */
  volatile int16_T RT8_ActiveBufIdx;   /* '<Root>/RT8' */
  volatile int16_T RT8_semaphoreTaken; /* '<Root>/RT8' */
  volatile int16_T RT7_ActiveBufIdx;   /* '<Root>/RT7' */
  volatile int16_T RT6_1_ActiveBufIdx; /* '<Root>/RT6' */
  volatile int16_T RT6_2_ActiveBufIdx; /* '<Root>/RT6' */
  volatile int16_T RT6_3_ActiveBufIdx; /* '<Root>/RT6' */
  volatile int16_T RT6_4_ActiveBufIdx; /* '<Root>/RT6' */
  volatile int16_T RT6_5_ActiveBufIdx; /* '<Root>/RT6' */
  volatile int16_T RT6_6_ActiveBufIdx; /* '<Root>/RT6' */
  uint16_T IaOffset_motor1;            /* '<Root>/Data Store Memory1' */
  uint16_T IbOffset_motor1;            /* '<Root>/Data Store Memory2' */
  uint16_T Debug_signals;              /* '<Root>/Data Store Memory6' */
  uint16_T IbOffset_motor2;            /* '<Root>/Data Store Memory7' */
  uint16_T IaOffset_motor2;            /* '<Root>/Data Store Memory8' */
  uint16_T CircBufIdx;                 /* '<S437>/Delay' */
  uint16_T CircBufIdx_l;               /* '<S212>/Delay' */
  boolean_T Delay_DSTATE_c;            /* '<S206>/Delay' */
  boolean_T Delay_DSTATE_o;            /* '<S203>/Delay' */
  uint16_T DiscreteTimeIntegrator3_IC_LOAD;/* '<S517>/Discrete-Time Integrator3' */
  uint16_T DiscreteTimeIntegrator3_IC_LO_f;/* '<S518>/Discrete-Time Integrator3' */
  uint16_T DiscreteTimeIntegrator3_IC_L_f5;/* '<S546>/Discrete-Time Integrator3' */
  uint16_T DiscreteTimeIntegrator3_IC_LO_a;/* '<S547>/Discrete-Time Integrator3' */
  boolean_T EnMtr2TrqCtrl;             /* '<Root>/Data Store Memory5' */
  boolean_T EnMtrCtrl;                 /* '<Root>/Data Store Memory9' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T EnClosedLoop;              /* '<Root>/Data Store Memory3' */
  boolean_T EnableEnMtr2TrqCtrlafter2secdel;
                           /* '<S427>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  boolean_T ClosedLoopControl_MODE;    /* '<S250>/Closed Loop Control' */
  boolean_T OpenLoopStartUp_MODE;      /* '<S10>/Open Loop Start-Up' */
  rtDW_Torquecontrolformotor2_mcb Torquecontrolformotor2;/* '<Root>/Torque control for motor2' */
  rtDW_Speedcontrolformotor1_mcb_ Speedcontrolformotor1;/* '<Root>/Speed control for motor1' */
  rtDW_IfActionSubsystem_mcb_pm_h IfActionSubsystem1_j;/* '<S487>/If Action Subsystem1' */
  rtDW_IfActionSubsystem_mcb_pm_h IfActionSubsystem_bv;/* '<S479>/If Action Subsystem' */
  rtDW_MATLABFunction_mcb_pmsm__a sf_MATLABFunction_k;/* '<S269>/MATLAB Function' */
  rtDW_MATLABFunction_mcb_pmsm_fo sf_MATLABFunction_i;/* '<S268>/MATLAB Function' */
  rtDW_MATLABFunction_mcb_pmsm__a sf_MATLABFunction_j;/* '<S31>/MATLAB Function' */
  rtDW_MATLABFunction_mcb_pmsm_fo sf_MATLABFunction;/* '<S30>/MATLAB Function' */
} D_Work_mcb_pmsm_foc_f28379d_dyn;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T IndexVector;            /* '<S499>/Index Vector' */
  const real_T IndexVector1;           /* '<S499>/Index Vector1' */
  const real_T IndexVector2;           /* '<S499>/Index Vector2' */
  const real_T IndexVector_b;          /* '<S516>/Index Vector' */
  const real_T IndexVector1_a;         /* '<S516>/Index Vector1' */
  const real_T Add;                    /* '<S516>/Add' */
  const real_T IndexVector_l;          /* '<S517>/Index Vector' */
  const real_T IndexVector_j;          /* '<S519>/Index Vector' */
  const real_T IndexVector_lr;         /* '<S520>/Index Vector' */
  const real_T IndexVector2_m;         /* '<S520>/Index Vector2' */
  const real_T IndexVector_i;          /* '<S521>/Index Vector' */
  const real_T IndexVector_h;          /* '<S518>/Index Vector' */
  const real_T IndexVector_e;          /* '<S522>/Index Vector' */
  const real_T IndexVector_n;          /* '<S523>/Index Vector' */
  const real_T IndexVector1_h;         /* '<S523>/Index Vector1' */
  const real_T IndexVector_g;          /* '<S524>/Index Vector' */
  const real_T IndexVector_l1;         /* '<S525>/Index Vector' */
  const real_T IndexVector_k;          /* '<S545>/Index Vector' */
  const real_T IndexVector1_d;         /* '<S545>/Index Vector1' */
  const real_T Add_g;                  /* '<S545>/Add' */
  const real_T IndexVector_ik;         /* '<S546>/Index Vector' */
  const real_T IndexVector_n1;         /* '<S548>/Index Vector' */
  const real_T IndexVector_h1;         /* '<S549>/Index Vector' */
  const real_T IndexVector1_k;         /* '<S549>/Index Vector1' */
  const real_T IndexVector_hp;         /* '<S550>/Index Vector' */
  const real_T IndexVector_nu;         /* '<S547>/Index Vector' */
  const real_T IndexVector_bx;         /* '<S551>/Index Vector' */
  const real_T IndexVector_f;          /* '<S552>/Index Vector' */
  const real_T IndexVector1_o;         /* '<S552>/Index Vector1' */
  const real_T IndexVector_p;          /* '<S553>/Index Vector' */
  const real_T IndexVector_m;          /* '<S554>/Index Vector' */
  const uint32_T Width;                /* '<S241>/Width' */
  const real32_T Ld_Port;              /* '<S399>/Gain' */
  const real32_T Switch;               /* '<S399>/Switch' */
  const real32_T Lq_Port;              /* '<S399>/Gain1' */
  const real32_T Switch1;              /* '<S399>/Switch1' */
  const real32_T FluxPM_Port;          /* '<S399>/Gain2' */
  const real32_T Switch2;              /* '<S399>/Switch2' */
  const real32_T Switch_n;             /* '<S398>/Switch' */
  const real32_T UnaryMinus;           /* '<S398>/Unary Minus' */
  const real32_T Ld_Port_o;            /* '<S409>/Gain' */
  const real32_T Switch_b;             /* '<S409>/Switch' */
  const real32_T Lq_Port_o;            /* '<S409>/Gain1' */
  const real32_T Switch1_j;            /* '<S409>/Switch1' */
  const real32_T FluxPM_Port_l;        /* '<S409>/Gain2' */
  const real32_T Switch2_k;            /* '<S409>/Switch2' */
  const real32_T Ld_Lq;                /* '<S408>/Subtract' */
  const real32_T Ld_Port_a;            /* '<S161>/Gain' */
  const real32_T Switch_a;             /* '<S161>/Switch' */
  const real32_T Lq_Port_i;            /* '<S161>/Gain1' */
  const real32_T Switch1_b;            /* '<S161>/Switch1' */
  const real32_T FluxPM_Port_o;        /* '<S161>/Gain2' */
  const real32_T Switch2_h;            /* '<S161>/Switch2' */
  const real32_T Switch_d;             /* '<S160>/Switch' */
  const real32_T UnaryMinus_h;         /* '<S160>/Unary Minus' */
  const real32_T Ld_Port_p;            /* '<S168>/Gain' */
  const real32_T Switch_nj;            /* '<S168>/Switch' */
  const real32_T Lq_Port_f;            /* '<S168>/Gain1' */
  const real32_T Switch1_n;            /* '<S168>/Switch1' */
  const real32_T FluxPM_Port_d;        /* '<S168>/Gain2' */
  const real32_T Switch2_ks;           /* '<S168>/Switch2' */
  const real32_T Ld_Lq_d;              /* '<S167>/Subtract' */
} ConstBlockIO_mcb_pmsm_foc_f2837;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S670>/sine_table_values'
   *   '<S171>/sine_table_values'
   *   '<S412>/sine_table_values'
   *   '<S195>/sine_table_values'
   */
  real32_T pooled38[1002];
} ConstParam_mcb_pmsm_foc_f28379d;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_foc_f28379d_dy {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern BlockIO_mcb_pmsm_foc_f28379d_dy mcb_pmsm_foc_f28379d_dyno_B;

/* Block states (default storage) */
extern D_Work_mcb_pmsm_foc_f28379d_dyn mcb_pmsm_foc_f28379d_dyno_DWork;
extern const ConstBlockIO_mcb_pmsm_foc_f2837 mcb_pmsm_foc_f28379d_dyn_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_mcb_pmsm_foc_f28379d mcb_pmsm_foc_f28379d_dyn_ConstP;

/* External function called from main */
extern void mcb_pmsm_foc_f28379d_dyno_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void mcb_pmsm_foc_f28379d_dyno_initialize(void);
extern void mcb_pmsm_foc_f28379d_dyno_step0(void);/* Sample time: [2.5E-5s, 0.0s] */
extern void mcb_pmsm_foc_f28379d_dyno_step1(void);/* Sample time: [0.0005s, 0.0s] */
extern void mcb_pmsm_foc_f28379d_dyno_step2(void);/* Sample time: [0.5s, 0.0s] */
extern void mcb_pmsm_foc_f28379d_dyno_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_foc_f28379d_d *const mcb_pmsm_foc_f28379d_dyno_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void ADCB1_INT(void);
  interrupt void ADCC1_INT(void);
  interrupt void SCIA_RX_INT(void);
  void mcb_pmsm_foc_f28379d_dyno_configure_interrupts (void);
  void mcb_pmsm_foc_f28379d_dyno_unconfigure_interrupts (void);

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
 * '<Root>' : 'mcb_pmsm_foc_f28379d_dyno'
 * '<S1>'   : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1'
 * '<S2>'   : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2'
 * '<S3>'   : 'mcb_pmsm_foc_f28379d_dyno/HW Interrupt'
 * '<S4>'   : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init'
 * '<S5>'   : 'mcb_pmsm_foc_f28379d_dyno/Heartbeat LED'
 * '<S6>'   : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled'
 * '<S7>'   : 'mcb_pmsm_foc_f28379d_dyno/Serial Receive'
 * '<S8>'   : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1'
 * '<S9>'   : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2'
 * '<S10>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System'
 * '<S11>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Enable MotorCtrl'
 * '<S12>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/HW_Inputs'
 * '<S13>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling'
 * '<S14>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Inverter'
 * '<S15>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Output Scaling'
 * '<S16>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/SCI_Tx'
 * '<S17>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Subsystem'
 * '<S18>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control'
 * '<S19>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up'
 * '<S20>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Clarke Transform'
 * '<S21>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers'
 * '<S22>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Inverse Park Transform'
 * '<S23>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/PMSM Torque Estimator1'
 * '<S24>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Park Transform'
 * '<S25>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Sine-Cosine Lookup'
 * '<S26>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Space Vector Generator'
 * '<S27>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Clarke Transform/Two phase input'
 * '<S28>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S29>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter'
 * '<S30>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id'
 * '<S31>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq'
 * '<S32>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PMSM Feed Forward Control'
 * '<S33>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S34>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S35>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S36>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S37>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S38>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S39>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S40>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S41>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S42>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S43>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S44>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S45>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S46>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S47>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S48>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/MATLAB Function'
 * '<S49>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S50>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S51>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S52>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S53>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S54>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S55>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S56>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S57>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S58>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S59>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S60>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S61>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S62>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S63>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S64>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S65>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S66>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S67>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S68>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S69>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S70>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S71>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S72>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S73>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S74>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S75>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S76>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S77>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S78>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S79>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S80>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S81>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S82>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S83>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S84>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S85>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S86>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S87>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S88>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S89>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S90>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S91>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S92>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S93>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S94>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S95>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S96>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S97>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S98>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S99>'  : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S100>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S101>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S102>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S103>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S104>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/MATLAB Function'
 * '<S105>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S106>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S107>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S108>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S109>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S110>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S111>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S112>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S113>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S114>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S115>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S116>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S117>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S118>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S119>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S120>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S121>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S122>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S123>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S124>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S125>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S126>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S127>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S128>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S129>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S130>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S131>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S132>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S133>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S134>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S135>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S136>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S137>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S138>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S139>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S140>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S141>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S142>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S143>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S144>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S145>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S146>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S147>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S148>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S149>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S150>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S151>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S152>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S153>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S154>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S155>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S156>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S157>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S158>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S159>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PMSM Feed Forward Control/FeedForward Control Selection'
 * '<S160>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PMSM Feed Forward Control/FeedForward Control Selection/Linear FeedForward_LumpedParameter_InputPort'
 * '<S161>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PMSM Feed Forward Control/FeedForward Control Selection/Linear FeedForward_LumpedParameter_InputPort/LumpedParams_InpurPorts'
 * '<S162>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PMSM Feed Forward Control/FeedForward Control Selection/Linear FeedForward_LumpedParameter_InputPort/Vd_sat'
 * '<S163>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Current_Controllers/PMSM Feed Forward Control/FeedForward Control Selection/Linear FeedForward_LumpedParameter_InputPort/Vq_sat'
 * '<S164>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Inverse Park Transform/Two inputs CRL'
 * '<S165>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S166>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/PMSM Torque Estimator1/Variant Subsystem'
 * '<S167>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/PMSM Torque Estimator1/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort'
 * '<S168>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/PMSM Torque Estimator1/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort/LumpedParams_InputPorts'
 * '<S169>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Park Transform/Two inputs CRL'
 * '<S170>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S171>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S172>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S173>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S174>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S175>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S176>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S177>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S178>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S179>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Space Vector Generator/Modulation method'
 * '<S180>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input'
 * '<S181>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM'
 * '<S182>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S183>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S184>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S185>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S186>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator'
 * '<S187>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/Position Generator1'
 * '<S188>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/Ramp Generator'
 * '<S189>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform'
 * '<S190>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform'
 * '<S191>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup'
 * '<S192>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform/Two phase input'
 * '<S193>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Two inputs CRL'
 * '<S194>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S195>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S196>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S197>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S198>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S199>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S200>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S201>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S202>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S203>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/Position Generator1/Accumulate'
 * '<S204>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Control_System/Open Loop Start-Up/Position Generator1/Accumulate/Subsystem'
 * '<S205>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/HW_Inputs/Sensor Driver Blocks (codegen)'
 * '<S206>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed'
 * '<S207>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/Calculate Phase Currents'
 * '<S208>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/IIR Filter'
 * '<S209>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/IndexFinder'
 * '<S210>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position'
 * '<S211>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Quadrature Decoder'
 * '<S212>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Speed Measurement'
 * '<S213>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter'
 * '<S214>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass'
 * '<S215>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S216>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/IndexFinder/Compare To Constant'
 * '<S217>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/IndexFinder/Compare To Constant1'
 * '<S218>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec'
 * '<S219>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S220>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S221>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S222>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S223>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S224>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S225>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S226>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/DT_Handle'
 * '<S227>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset'
 * '<S228>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionResetAtIndex'
 * '<S229>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem'
 * '<S230>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/DT_Handle/floating-point'
 * '<S231>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S232>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S233>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem/Dialog'
 * '<S234>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Speed Measurement/DT_Handle'
 * '<S235>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/ Calculate Position and Speed/Speed Measurement/DT_Handle/floating-point'
 * '<S236>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/Calculate Phase Currents/Data_Type'
 * '<S237>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Input Scaling/Calculate Phase Currents/Data_Type/Data_Type_Float'
 * '<S238>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/Inverter/Code Generation'
 * '<S239>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/SCI_Tx/Code Generation'
 * '<S240>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/SCI_Tx/Code Generation/Data_Conditioning_Tx'
 * '<S241>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/SCI_Tx/Code Generation/Data_Logging'
 * '<S242>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/SCI_Tx/Code Generation/While Iterator Subsystem'
 * '<S243>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/SCI_Tx/Code Generation/Data_Conditioning_Tx/Data_Type_Float'
 * '<S244>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/SCI_Tx/Code Generation/Data_Logging/Counter Limited'
 * '<S245>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/SCI_Tx/Code Generation/Data_Logging/Data'
 * '<S246>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/SCI_Tx/Code Generation/Data_Logging/End'
 * '<S247>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/SCI_Tx/Code Generation/Data_Logging/Start'
 * '<S248>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/SCI_Tx/Code Generation/Data_Logging/Counter Limited/Increment Real World'
 * '<S249>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor1/SCI_Tx/Code Generation/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S250>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System'
 * '<S251>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Enable Motor2 after a delay'
 * '<S252>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/HW_Inputs'
 * '<S253>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling'
 * '<S254>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Inverter'
 * '<S255>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Output Scaling'
 * '<S256>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control'
 * '<S257>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Clarke Transform'
 * '<S258>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers'
 * '<S259>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/IIR Filter'
 * '<S260>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Inverse Park Transform'
 * '<S261>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/PMSM Torque Estimator1'
 * '<S262>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Park Transform'
 * '<S263>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Sine-Cosine Lookup'
 * '<S264>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Space Vector Generator'
 * '<S265>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Clarke Transform/Two phase input'
 * '<S266>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S267>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter'
 * '<S268>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id'
 * '<S269>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq'
 * '<S270>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PMSM Feed Forward Control'
 * '<S271>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S272>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S273>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S274>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S275>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S276>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S277>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S278>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S279>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S280>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S281>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S282>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S283>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S284>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S285>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S286>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/MATLAB Function'
 * '<S287>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S288>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S289>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S290>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S291>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S292>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S293>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S294>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S295>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S296>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S297>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S298>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S299>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S300>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S301>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S302>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S303>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S304>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S305>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S306>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S307>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S308>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S309>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S310>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S311>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S312>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S313>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S314>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S315>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S316>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S317>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S318>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S319>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S320>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S321>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S322>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S323>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S324>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S325>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S326>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S327>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S328>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S329>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S330>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S331>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S332>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S333>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S334>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S335>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S336>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S337>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S338>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S339>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S340>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S341>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S342>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/MATLAB Function'
 * '<S343>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S344>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S345>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S346>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S347>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S348>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S349>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S350>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S351>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S352>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S353>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S354>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S355>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S356>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S357>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S358>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S359>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S360>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S361>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S362>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S363>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S364>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S365>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S366>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S367>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S368>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S369>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S370>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S371>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S372>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S373>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S374>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S375>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S376>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S377>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S378>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S379>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S380>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S381>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S382>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S383>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S384>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S385>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S386>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S387>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S388>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S389>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S390>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S391>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S392>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S393>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S394>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S395>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S396>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S397>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PMSM Feed Forward Control/FeedForward Control Selection'
 * '<S398>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PMSM Feed Forward Control/FeedForward Control Selection/Linear FeedForward_LumpedParameter_InputPort'
 * '<S399>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PMSM Feed Forward Control/FeedForward Control Selection/Linear FeedForward_LumpedParameter_InputPort/LumpedParams_InpurPorts'
 * '<S400>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PMSM Feed Forward Control/FeedForward Control Selection/Linear FeedForward_LumpedParameter_InputPort/Vd_sat'
 * '<S401>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Current_Controllers/PMSM Feed Forward Control/FeedForward Control Selection/Linear FeedForward_LumpedParameter_InputPort/Vq_sat'
 * '<S402>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/IIR Filter/IIR Filter'
 * '<S403>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/IIR Filter/IIR Filter/Low-pass'
 * '<S404>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S405>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Inverse Park Transform/Two inputs CRL'
 * '<S406>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S407>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/PMSM Torque Estimator1/Variant Subsystem'
 * '<S408>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/PMSM Torque Estimator1/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort'
 * '<S409>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/PMSM Torque Estimator1/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort/LumpedParams_InputPorts'
 * '<S410>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Park Transform/Two inputs CRL'
 * '<S411>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S412>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S413>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S414>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S415>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S416>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S417>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S418>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S419>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S420>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Space Vector Generator/Modulation method'
 * '<S421>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input'
 * '<S422>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM'
 * '<S423>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S424>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S425>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S426>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S427>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Enable Motor2 after a delay/Delay to start motor1 (codegen)'
 * '<S428>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Enable Motor2 after a delay/Delay to start motor1 (codegen)/Disable EnMtr2TrqCtrl'
 * '<S429>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Enable Motor2 after a delay/Delay to start motor1 (codegen)/Enable EnMtr2TrqCtrl after 2 sec delay'
 * '<S430>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Enable Motor2 after a delay/Delay to start motor1 (codegen)/Enable EnMtr2TrqCtrl after 2 sec delay/Enable EnMtr2TrqCtrl'
 * '<S431>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/HW_Inputs/Sensor Driver Blocks (codegen)'
 * '<S432>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed'
 * '<S433>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/Calculate Phase Currents'
 * '<S434>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/IIR Filter'
 * '<S435>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position'
 * '<S436>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Quadrature Decoder'
 * '<S437>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Speed Measurement'
 * '<S438>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter'
 * '<S439>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass'
 * '<S440>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S441>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec'
 * '<S442>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S443>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S444>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S445>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S446>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S447>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S448>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S449>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/DT_Handle'
 * '<S450>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset'
 * '<S451>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionResetAtIndex'
 * '<S452>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem'
 * '<S453>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/DT_Handle/floating-point'
 * '<S454>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S455>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S456>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem/Dialog'
 * '<S457>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Speed Measurement/DT_Handle'
 * '<S458>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/ Calculate Position and Speed/Speed Measurement/DT_Handle/floating-point'
 * '<S459>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/Calculate Phase Currents/Data_Type'
 * '<S460>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Input Scaling/Calculate Phase Currents/Data_Type/Data_Type_Float'
 * '<S461>' : 'mcb_pmsm_foc_f28379d_dyno/Current control for motor2/Inverter/Code Generation'
 * '<S462>' : 'mcb_pmsm_foc_f28379d_dyno/HW Interrupt/Code generation'
 * '<S463>' : 'mcb_pmsm_foc_f28379d_dyno/HW Interrupt/Code generation/HWI_ADCB1_INT'
 * '<S464>' : 'mcb_pmsm_foc_f28379d_dyno/HW Interrupt/Code generation/HWI_ADCC1_INT'
 * '<S465>' : 'mcb_pmsm_foc_f28379d_dyno/HW Interrupt/Code generation/HWI_SCIA_RX_INT'
 * '<S466>' : 'mcb_pmsm_foc_f28379d_dyno/HW Interrupt/Code generation/HWI_ADCB1_INT/ECSoC'
 * '<S467>' : 'mcb_pmsm_foc_f28379d_dyno/HW Interrupt/Code generation/HWI_ADCB1_INT/ECSoC/ECSimCodegen'
 * '<S468>' : 'mcb_pmsm_foc_f28379d_dyno/HW Interrupt/Code generation/HWI_ADCC1_INT/ECSoC'
 * '<S469>' : 'mcb_pmsm_foc_f28379d_dyno/HW Interrupt/Code generation/HWI_ADCC1_INT/ECSoC/ECSimCodegen'
 * '<S470>' : 'mcb_pmsm_foc_f28379d_dyno/HW Interrupt/Code generation/HWI_SCIA_RX_INT/ECSoC'
 * '<S471>' : 'mcb_pmsm_foc_f28379d_dyno/HW Interrupt/Code generation/HWI_SCIA_RX_INT/ECSoC/ECSimCodegen'
 * '<S472>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init'
 * '<S473>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)'
 * '<S474>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor'
 * '<S475>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor'
 * '<S476>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Enable DRV8305 for motor 1 and motor 2'
 * '<S477>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset '
 * '<S478>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Default ADC Offset'
 * '<S479>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset /For Iterator Subsystem'
 * '<S480>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset /If Action Subsystem'
 * '<S481>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset /If Action Subsystem1'
 * '<S482>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset /If Action Subsystem2'
 * '<S483>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset /If Action Subsystem3'
 * '<S484>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 1 current sensor/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S485>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset '
 * '<S486>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Default ADC Offset'
 * '<S487>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset /For Iterator Subsystem'
 * '<S488>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset /If Action Subsystem4'
 * '<S489>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset /If Action Subsystem5'
 * '<S490>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset /If Action Subsystem6'
 * '<S491>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset /If Action Subsystem7'
 * '<S492>' : 'mcb_pmsm_foc_f28379d_dyno/Hardware Init/HW_Init/HW_Init (Codegen)/Calibrate ADC offset for motor 2 current sensor/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem1'
 * '<S493>' : 'mcb_pmsm_foc_f28379d_dyno/Heartbeat LED/Heartbeat LED'
 * '<S494>' : 'mcb_pmsm_foc_f28379d_dyno/Heartbeat LED/Heartbeat LED/Code generation'
 * '<S495>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control'
 * '<S496>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control'
 * '<S497>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete'
 * '<S498>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete'
 * '<S499>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle'
 * '<S500>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1'
 * '<S501>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic'
 * '<S502>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1'
 * '<S503>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1/Compare To Constant'
 * '<S504>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1/Compare To Constant1'
 * '<S505>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/MechToElect'
 * '<S506>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator'
 * '<S507>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrNotTrnsfrd Input'
 * '<S508>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrStored Input'
 * '<S509>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrTrnsfrd Input'
 * '<S510>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Clarke Transform'
 * '<S511>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Inverse Clarke Transform'
 * '<S512>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Inverse Park Transform'
 * '<S513>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Machine Torque'
 * '<S514>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit'
 * '<S515>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Park Transform'
 * '<S516>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Machine Torque/Subsystem'
 * '<S517>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage'
 * '<S518>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage'
 * '<S519>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem'
 * '<S520>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1'
 * '<S521>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2'
 * '<S522>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem'
 * '<S523>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1'
 * '<S524>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2'
 * '<S525>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 1 - Speed control/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3'
 * '<S526>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete'
 * '<S527>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete'
 * '<S528>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Mechanical and Angle'
 * '<S529>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Motor Units1'
 * '<S530>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic'
 * '<S531>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Mechanical and Angle/Int'
 * '<S532>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Mechanical and Angle/Int/Compare To Constant'
 * '<S533>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Mechanical and Angle/Int/Compare To Constant1'
 * '<S534>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Motor Units1/MechToElect'
 * '<S535>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Motor Units1/Power Accounting Bus Creator'
 * '<S536>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrNotTrnsfrd Input'
 * '<S537>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrStored Input'
 * '<S538>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrTrnsfrd Input'
 * '<S539>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/Clarke Transform'
 * '<S540>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/Inverse Clarke Transform'
 * '<S541>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/Inverse Park Transform'
 * '<S542>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/Machine Torque'
 * '<S543>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit'
 * '<S544>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/Park Transform'
 * '<S545>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/Machine Torque/Subsystem'
 * '<S546>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage'
 * '<S547>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage'
 * '<S548>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem'
 * '<S549>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1'
 * '<S550>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2'
 * '<S551>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem'
 * '<S552>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1'
 * '<S553>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2'
 * '<S554>' : 'mcb_pmsm_foc_f28379d_dyno/Motor1 and Motor2 coupled/Motor 2 - Torque control/PMSM Speed Input Exterior Discrete/PMSM Speed Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3'
 * '<S555>' : 'mcb_pmsm_foc_f28379d_dyno/Serial Receive/Parse SCI Rx'
 * '<S556>' : 'mcb_pmsm_foc_f28379d_dyno/Serial Receive/SCI_Rx'
 * '<S557>' : 'mcb_pmsm_foc_f28379d_dyno/Serial Receive/Parse SCI Rx/Data_Conditioning_Rx'
 * '<S558>' : 'mcb_pmsm_foc_f28379d_dyno/Serial Receive/Parse SCI Rx/unParse'
 * '<S559>' : 'mcb_pmsm_foc_f28379d_dyno/Serial Receive/Parse SCI Rx/Data_Conditioning_Rx/Data_Type_Float'
 * '<S560>' : 'mcb_pmsm_foc_f28379d_dyno/Serial Receive/SCI_Rx/Code generation'
 * '<S561>' : 'mcb_pmsm_foc_f28379d_dyno/Serial Receive/SCI_Rx/Code generation/Serial Rx'
 * '<S562>' : 'mcb_pmsm_foc_f28379d_dyno/Serial Receive/SCI_Rx/Code generation/Serial Rx/Data_Type_Float'
 * '<S563>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference'
 * '<S564>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed'
 * '<S565>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/Speed_Ref_Selector'
 * '<S566>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System'
 * '<S567>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM'
 * '<S568>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/Compare To Constant1'
 * '<S569>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter'
 * '<S570>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/FWC with CVCP'
 * '<S571>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/MTPA condition'
 * '<S572>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/D-Q Equivalence'
 * '<S573>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/D//Q Axis Priority'
 * '<S574>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/Inport//Dialog Selection'
 * '<S575>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/Magnitude_calc'
 * '<S576>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S577>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S578>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S579>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S580>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S581>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S582>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S583>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S584>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S585>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/MTPA Control Reference/Motor_System/Surface PMSM/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S586>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S587>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/MATLAB Function'
 * '<S588>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S589>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S590>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S591>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S592>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S593>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S594>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S595>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S596>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S597>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S598>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S599>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S600>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S601>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S602>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S603>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S604>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S605>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S606>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S607>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S608>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S609>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S610>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S611>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S612>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S613>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S614>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S615>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S616>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S617>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S618>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S619>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S620>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S621>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S622>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S623>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S624>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S625>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S626>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S627>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S628>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S629>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S630>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S631>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S632>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S633>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S634>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S635>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S636>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S637>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S638>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S639>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S640>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S641>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S642>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/Speed_Ref_Selector/IIR Filter'
 * '<S643>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/Speed_Ref_Selector/IIR Filter/IIR Filter'
 * '<S644>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/Speed_Ref_Selector/IIR Filter/IIR Filter/Low-pass'
 * '<S645>' : 'mcb_pmsm_foc_f28379d_dyno/Speed control for motor1/Speed_Ref_Selector/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S646>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter'
 * '<S647>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Speed Limiter'
 * '<S648>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Vector Control Reference'
 * '<S649>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/D-Q Equivalence'
 * '<S650>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/D//Q Axis Priority'
 * '<S651>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/Inport//Dialog Selection'
 * '<S652>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/Magnitude_calc'
 * '<S653>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S654>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S655>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S656>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S657>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S658>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S659>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S660>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S661>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S662>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S663>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Speed Limiter/Compare To Constant'
 * '<S664>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Speed Limiter/Handle divide by 0'
 * '<S665>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Speed Limiter/If Action Subsystem'
 * '<S666>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Vector Control Reference/Inverse Park Transform'
 * '<S667>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Vector Control Reference/Sine-Cosine Lookup'
 * '<S668>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Vector Control Reference/Inverse Park Transform/Two inputs CRL'
 * '<S669>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Vector Control Reference/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S670>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Vector Control Reference/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S671>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Vector Control Reference/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S672>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Vector Control Reference/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S673>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Vector Control Reference/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S674>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Vector Control Reference/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S675>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Vector Control Reference/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S676>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Vector Control Reference/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S677>' : 'mcb_pmsm_foc_f28379d_dyno/Torque control for motor2/Vector Control Reference/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 */
#endif                                 /* mcb_pmsm_foc_f28379d_dyno_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
