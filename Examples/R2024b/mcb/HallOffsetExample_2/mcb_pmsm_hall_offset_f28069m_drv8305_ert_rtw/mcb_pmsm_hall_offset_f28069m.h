/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_hall_offset_f28069m.h
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

#ifndef mcb_pmsm_hall_offset_f28069m_h_
#define mcb_pmsm_hall_offset_f28069m_h_
#ifndef mcb_pmsm_hall_offset_f28069m_COMMON_INCLUDES_
#define mcb_pmsm_hall_offset_f28069m_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Gpio.h"
#include "MW_c28xx_cap.h"
#include "DSP28xx_SciUtil.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#endif                       /* mcb_pmsm_hall_offset_f28069m_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "mcb_pmsm_hall_offset_f28069m_types.h"
#include "multiword_types.h"
#include <stddef.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void init_CAP_GPIO(void);
extern void init_CAP1(void);
extern void init_CAP2(void);
extern void init_CAP3(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals for system '<S28>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S30>/Merge' */
  uint16_T Merge1;                     /* '<S30>/Merge1' */
  uint16_T Merge3;                     /* '<S30>/Merge3' */
  int16_T Merge2;                      /* '<S30>/Merge2' */
  boolean_T RelationalOperator;        /* '<S30>/Relational Operator' */
} rtB_ValidHalls_mcb_pmsm_hall_of;

/* Block signals (default storage) */
typedef struct {
  uint32_T ReadGPIODATregister;        /* '<S61>/Read GPIO DAT register' */
  uint32_T Hall_C;                     /* '<S61>/Hall_C' */
  uint32_T ShiftArithmetic;            /* '<S61>/Shift Arithmetic' */
  uint32_T Hall_B;                     /* '<S61>/Hall_B' */
  uint32_T ShiftArithmetic1;           /* '<S61>/Shift Arithmetic1' */
  uint32_T Hall_A;                     /* '<S61>/Hall_A' */
  uint32_T ShiftArithmetic2;           /* '<S61>/Shift Arithmetic2' */
  uint32_T BitwiseOperator2;           /* '<S61>/Bitwise Operator2' */
  uint32_T DataStoreRead;              /* '<S4>/Data Store Read' */
  uint32_T eCAP[2];                    /* '<S4>/eCAP' */
  uint32_T Switch;                     /* '<S4>/Switch' */
  uint32_T ReadGPIODATregister_b;      /* '<S43>/Read GPIO DAT register' */
  uint32_T Hall_C_h;                   /* '<S43>/Hall_C' */
  uint32_T ShiftArithmetic_o;          /* '<S43>/Shift Arithmetic' */
  uint32_T Hall_B_g;                   /* '<S43>/Hall_B' */
  uint32_T ShiftArithmetic1_e;         /* '<S43>/Shift Arithmetic1' */
  uint32_T Hall_A_j;                   /* '<S43>/Hall_A' */
  uint32_T ShiftArithmetic2_n;         /* '<S43>/Shift Arithmetic2' */
  uint32_T BitwiseOperator2_h;         /* '<S43>/Bitwise Operator2' */
  uint32_T DataStoreRead_a;            /* '<S3>/Data Store Read' */
  uint32_T eCAP_i[2];                  /* '<S3>/eCAP' */
  uint32_T Switch_a;                   /* '<S3>/Switch' */
  uint32_T ReadGPIODATregister_g;      /* '<S25>/Read GPIO DAT register' */
  uint32_T Hall_C_g;                   /* '<S25>/Hall_C' */
  uint32_T ShiftArithmetic_b;          /* '<S25>/Shift Arithmetic' */
  uint32_T Hall_B_m;                   /* '<S25>/Hall_B' */
  uint32_T ShiftArithmetic1_i;         /* '<S25>/Shift Arithmetic1' */
  uint32_T Hall_A_k;                   /* '<S25>/Hall_A' */
  uint32_T ShiftArithmetic2_j;         /* '<S25>/Shift Arithmetic2' */
  uint32_T BitwiseOperator2_a;         /* '<S25>/Bitwise Operator2' */
  uint32_T DataStoreRead_k;            /* '<S2>/Data Store Read' */
  uint32_T eCAP_e[2];                  /* '<S2>/eCAP' */
  uint32_T Switch_av;                  /* '<S2>/Switch' */
  uint32_T speedCountDelay;            /* '<S135>/speedCountDelay' */
  uint32_T Sum[4];                     /* '<S108>/Sum' */
  uint32_T Max;                        /* '<S139>/Max' */
  uint32_T ReadGPIODATregister_e;      /* '<S134>/Read GPIO DAT register' */
  uint32_T Hall_C_i;                   /* '<S134>/Hall_C' */
  uint32_T ShiftArithmetic_h;          /* '<S134>/Shift Arithmetic' */
  uint32_T Hall_B_j;                   /* '<S134>/Hall_B' */
  uint32_T ShiftArithmetic1_iq;        /* '<S134>/Shift Arithmetic1' */
  uint32_T Hall_A_b;                   /* '<S134>/Hall_A' */
  uint32_T ShiftArithmetic2_i;         /* '<S134>/Shift Arithmetic2' */
  uint32_T BitwiseOperator2_o;         /* '<S134>/Bitwise Operator2' */
  uint32_T DataStoreRead2;             /* '<S132>/Data Store Read2' */
  uint32_T MemoryCopy;                 /* '<S132>/Memory Copy' */
  uint32_T MemoryCopy1;                /* '<S132>/Memory Copy1' */
  uint32_T MemoryCopy2;                /* '<S132>/Memory Copy2' */
  uint32_T Delay;                      /* '<S102>/Delay' */
  uint32_T Add1;                       /* '<S102>/Add1' */
  real32_T DataTypeConversion1;        /* '<S170>/Data Type Conversion1' */
  real32_T Merge;                      /* '<S133>/Merge' */
  real32_T Merge1;                     /* '<S133>/Merge1' */
  real32_T Switch_m;                   /* '<S6>/Switch' */
  real32_T Merge_l;                    /* '<S110>/Merge' */
  real32_T indexing;                   /* '<S108>/indexing' */
  real32_T Lookup[4];                  /* '<S108>/Lookup' */
  real32_T Sum3;                       /* '<S109>/Sum3' */
  real32_T DataTypeConversion1_p;      /* '<S108>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S108>/Sum2' */
  real32_T Product;                    /* '<S109>/Product' */
  real32_T Sum4;                       /* '<S109>/Sum4' */
  real32_T Sum5;                       /* '<S109>/Sum5' */
  real32_T Product1;                   /* '<S109>/Product1' */
  real32_T Sum6;                       /* '<S109>/Sum6' */
  real32_T currentSpeedData;           /* '<S138>/currentSpeedData' */
  real32_T Divide;                     /* '<S138>/Divide' */
  real32_T SpeedGain;                  /* '<S138>/SpeedGain' */
  real32_T Merge1_f;                   /* '<S151>/Merge1' */
  real32_T Saturation;                 /* '<S151>/Saturation' */
  real32_T Merge_g;                    /* '<S151>/Merge' */
  real32_T currentSpeedData_g;         /* '<S154>/currentSpeedData' */
  real32_T Divide_m;                   /* '<S154>/Divide' */
  real32_T previousSpeedData;          /* '<S155>/previousSpeedData' */
  real32_T Divide_mp;                  /* '<S155>/Divide' */
  real32_T currentSpeedData_n;         /* '<S155>/currentSpeedData' */
  real32_T Divide1;                    /* '<S155>/Divide1' */
  real32_T Sum_b;                      /* '<S155>/Sum' */
  real32_T Gain1;                      /* '<S155>/Gain1' */
  real32_T Sum1;                       /* '<S155>/Sum1' */
  real32_T Product_c;                  /* '<S155>/Product' */
  real32_T Merge1_o;                   /* '<S152>/Merge1' */
  real32_T Merge1_m;                   /* '<S153>/Merge1' */
  real32_T sqrt3_by_two;               /* '<S122>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S122>/one_by_two' */
  real32_T add_c;                      /* '<S122>/add_c' */
  real32_T add_b;                      /* '<S122>/add_b' */
  real32_T Min;                        /* '<S119>/Min' */
  real32_T Max_l;                      /* '<S119>/Max' */
  real32_T Add;                        /* '<S119>/Add' */
  real32_T one_by_two_g;               /* '<S119>/one_by_two' */
  real32_T Add2;                       /* '<S118>/Add2' */
  real32_T Add1_j;                     /* '<S118>/Add1' */
  real32_T Add3;                       /* '<S118>/Add3' */
  real32_T Gain[3];                    /* '<S118>/Gain' */
  real32_T Sum_j[3];                   /* '<S79>/Sum' */
  real32_T Gain_i[3];                  /* '<S79>/Gain' */
  real32_T Input;                      /* '<S88>/Input' */
  real32_T Convert_back;               /* '<S114>/Convert_back' */
  real32_T Convert_back_c;             /* '<S113>/Convert_back' */
  real32_T Merge_o;                    /* '<S101>/Merge' */
  real32_T UnitDelay;                  /* '<S105>/Unit Delay' */
  real32_T scaleOut;                   /* '<S105>/scaleOut' */
  real32_T Add_e;                      /* '<S106>/Add' */
  real32_T DataTypeConversion1_d;      /* '<S106>/Data Type Conversion1' */
  real32_T Add1_m;                     /* '<S106>/Add1' */
  real32_T Input_d;                    /* '<S107>/Input' */
  real32_T Delay_b;                    /* '<S104>/Delay' */
  real32_T Add1_d;                     /* '<S104>/Add1' */
  real32_T SaturatetomotorcalibSpeedRPM;
                               /* '<S104>/Saturate to 'motor.calibSpeed' RPM' */
  real32_T qcos;                       /* '<S96>/qcos' */
  real32_T dsin;                       /* '<S96>/dsin' */
  real32_T sum_beta;                   /* '<S96>/sum_beta' */
  real32_T dcos;                       /* '<S96>/dcos' */
  real32_T qsin;                       /* '<S96>/qsin' */
  real32_T sum_alpha;                  /* '<S96>/sum_alpha' */
  real32_T Switch_f[2];                /* '<S97>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T Delay_o;                    /* '<S83>/Delay' */
  real32_T Switch1[2];                 /* '<S92>/Switch1' */
  real32_T Product_l;                  /* '<S95>/Product' */
  real32_T UnitDelay_d;                /* '<S95>/Unit Delay' */
  real32_T Product1_m;                 /* '<S95>/Product1' */
  real32_T Add1_mi;                    /* '<S95>/Add1' */
  int32_T DataTypeConversion1_m[2];    /* '<S125>/Data Type Conversion1' */
  uint16_T SCIReceive;                 /* '<S7>/SCI Receive' */
  uint16_T DataTypeConversion1_l;      /* '<S60>/Data Type Conversion1' */
  uint16_T DataTypeConversion2;        /* '<S60>/Data Type Conversion2' */
  uint16_T DataTypeConversion;         /* '<S64>/Data Type Conversion' */
  uint16_T Merge_a;                    /* '<S64>/Merge' */
  uint16_T DataTypeConversion1_c;      /* '<S42>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_p;      /* '<S42>/Data Type Conversion2' */
  uint16_T DataTypeConversion_j;       /* '<S46>/Data Type Conversion' */
  uint16_T Merge_on;                   /* '<S46>/Merge' */
  uint16_T DataTypeConversion1_d5;     /* '<S24>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_b;      /* '<S24>/Data Type Conversion2' */
  uint16_T DataTypeConversion_e;       /* '<S28>/Data Type Conversion' */
  uint16_T Merge_e;                    /* '<S28>/Merge' */
  uint16_T Switch_i;                   /* '<S133>/Switch' */
  uint16_T Switch_o;                   /* '<S135>/Switch' */
  uint16_T DelayOneStep;               /* '<S136>/Delay One Step' */
  uint16_T watchdogcheck;              /* '<S139>/watchdog check' */
  uint16_T Sum_a;                      /* '<S136>/Sum' */
  uint16_T Output;                     /* '<S123>/Output' */
  uint16_T DataTypeConversion3[2];     /* '<S125>/Data Type Conversion3' */
  uint16_T Merge_ol[3];                /* '<S78>/Merge' */
  uint16_T Merge1_b;                   /* '<S78>/Merge1' */
  uint16_T FixPtSum1;                  /* '<S129>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S130>/FixPt Switch' */
  uint16_T DataTypeConversion_g;       /* '<S110>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S108>/Get_Integer' */
  uint16_T Switch4[3];                 /* '<S79>/Switch4' */
  uint16_T IAIBMeasurement[2];         /* '<S6>/IA//IB Measurement' */
  uint16_T speedcheck;                 /* '<S139>/speed check' */
  uint16_T DataStoreRead5;             /* '<S132>/Data Store Read5' */
  uint16_T DataStoreRead4;             /* '<S132>/Data Store Read4' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S79>/Scale_to_PWM_Counter_PRD' */
  uint16_T IndexVector;                /* '<S128>/Index Vector' */
  uint16_T Add_d;                      /* '<S128>/Add' */
  uint16_T Data[2];                    /* '<S124>/Data' */
  uint16_T Data_f[2];                  /* '<S126>/Data' */
  uint16_T Data_fw[2];                 /* '<S127>/Data' */
  int16_T DataStoreRead1;              /* '<S4>/Data Store Read1' */
  int16_T Merge1_of;                   /* '<S64>/Merge1' */
  int16_T DataStoreRead1_p;            /* '<S3>/Data Store Read1' */
  int16_T Merge1_bu;                   /* '<S46>/Merge1' */
  int16_T DataStoreRead1_j;            /* '<S2>/Data Store Read1' */
  int16_T Merge1_g;                    /* '<S28>/Merge1' */
  int16_T DataStoreRead3;              /* '<S132>/Data Store Read3' */
  int16_T WhileIterator;               /* '<S128>/While Iterator' */
  int16_T Convert_uint16;              /* '<S114>/Convert_uint16' */
  int16_T Convert_uint16_k;            /* '<S113>/Convert_uint16' */
  int16_T DataTypeConversion_c;        /* '<S106>/Data Type Conversion' */
  boolean_T Switch_aj;                 /* '<S7>/Switch' */
  boolean_T Merge3;                    /* '<S64>/Merge3' */
  boolean_T Merge_gg;                  /* '<S59>/Merge' */
  boolean_T Merge3_f;                  /* '<S46>/Merge3' */
  boolean_T Merge_e3;                  /* '<S41>/Merge' */
  boolean_T Merge3_n;                  /* '<S28>/Merge3' */
  boolean_T Merge_lt;                  /* '<S23>/Merge' */
  boolean_T DataTypeConversion4;       /* '<S133>/Data Type Conversion4' */
  boolean_T DataTypeConversion_k;      /* '<S135>/Data Type Conversion' */
  boolean_T validityDelay;             /* '<S135>/validityDelay' */
  boolean_T DelayOneStep1;             /* '<S136>/Delay One Step1' */
  boolean_T OR;                        /* '<S136>/OR' */
  boolean_T Compare;                   /* '<S140>/Compare' */
  boolean_T DataStoreRead_c;           /* '<S77>/Data Store Read' */
  boolean_T NOT;                       /* '<S77>/NOT' */
  boolean_T Compare_e;                 /* '<S112>/Compare' */
  boolean_T Switch_p;                  /* '<S80>/Switch' */
  boolean_T LogicalOperator;           /* '<S135>/Logical Operator' */
  boolean_T NOT_m;                     /* '<S80>/NOT' */
  boolean_T Compare_a;                 /* '<S98>/Compare' */
  boolean_T NOT_k;                     /* '<S85>/NOT' */
  boolean_T Compare_i;                 /* '<S99>/Compare' */
  boolean_T NOT_g;                     /* '<S105>/NOT' */
  boolean_T Delay_c;                   /* '<S106>/Delay' */
  boolean_T Compare_au;                /* '<S89>/Compare' */
  boolean_T Compare_j;                 /* '<S90>/Compare' */
  boolean_T AND;                       /* '<S83>/AND' */
  rtB_ValidHalls_mcb_pmsm_hall_of ValidHalls_e;/* '<S64>/Valid Halls' */
  rtB_ValidHalls_mcb_pmsm_hall_of ValidHalls_p;/* '<S46>/Valid Halls' */
  rtB_ValidHalls_mcb_pmsm_hall_of ValidHalls;/* '<S28>/Valid Halls' */
} BlockIO_mcb_pmsm_hall_offset_f2;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint64m_T Add1_DWORK1;               /* '<S102>/Add1' */
  real32_T UnitDelay_DSTATE;           /* '<S105>/Unit Delay' */
  real32_T Delay_DSTATE;               /* '<S104>/Delay' */
  real32_T Delay_DSTATE_p;             /* '<S83>/Delay' */
  real32_T UnitDelay_DSTATE_f;         /* '<S95>/Unit Delay' */
  uint32_T Delay_DSTATE_pm;            /* '<S102>/Delay' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S5>/Digital Output' */
  int32_T InverterEnable_FRAC_LEN;     /* '<S80>/Inverter Enable' */
  uint32_T GlobalSpeedCount;           /* '<Root>/Data Store Memory1' */
  uint32_T GlobalHallState;            /* '<Root>/Data Store Memory4' */
  uint32_T Sum_DWORK1[4];              /* '<S108>/Sum' */
  uint16_T DelayOneStep_DSTATE;        /* '<S136>/Delay One Step' */
  uint16_T Output_DSTATE;              /* '<S123>/Output' */
  int16_T GlobalDirection;             /* '<Root>/Data Store Memory3' */
  uint16_T HallStateChangeFlag;        /* '<Root>/Data Store Memory' */
  uint16_T GlobalSpeedValidity;        /* '<Root>/Data Store Memory2' */
  uint16_T Add_DWORK1;                 /* '<S128>/Add' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S136>/Delay One Step1' */
  boolean_T Delay_DSTATE_b;            /* '<S106>/Delay' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T PosGen_MODE;               /* '<S77>/PosGen' */
  boolean_T UpCounter_MODE;            /* '<S85>/Up Counter' */
  boolean_T FindOffset_MODE;           /* '<S77>/Find Offset' */
} D_Work_mcb_pmsm_hall_offset_f28;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S108>/sine_table_values'
   */
  real32_T sine_table_values_Value[1002];
} ConstParam_mcb_pmsm_hall_offset;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_hall_offset_f2 {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern BlockIO_mcb_pmsm_hall_offset_f2 mcb_pmsm_hall_offset_f28069m_B;

/* Block states (default storage) */
extern D_Work_mcb_pmsm_hall_offset_f28 mcb_pmsm_hall_offset_f280_DWork;

/* Constant parameters (default storage) */
extern const ConstParam_mcb_pmsm_hall_offset mcb_pmsm_hall_offset_f28_ConstP;

/* Model entry point functions */
extern void mcb_pmsm_hall_offset_f28069m_initialize(void);
extern void mcb_pmsm_hall_offset_f28069m_step(void);
extern void mcb_pmsm_hall_offset_f28069m_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_hall_offset_f *const mcb_pmsm_hall_offset_f28069m_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void ADCINT1(void);
  interrupt void ECAP1_INT(void);
  interrupt void ECAP2_INT(void);
  interrupt void ECAP3_INT(void);
  interrupt void SCIRXINTA(void);
  void mcb_pmsm_hall_offset_f28069m_configure_interrupts (void);
  void mcb_pmsm_hall_offset_f28069m_unconfigure_interrupts (void);

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
 * '<Root>' : 'mcb_pmsm_hall_offset_f28069m'
 * '<S1>'   : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt'
 * '<S2>'   : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A'
 * '<S3>'   : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B'
 * '<S4>'   : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C'
 * '<S5>'   : 'mcb_pmsm_hall_offset_f28069m/Heartbeat LED'
 * '<S6>'   : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation'
 * '<S7>'   : 'mcb_pmsm_hall_offset_f28069m/Serial Receive'
 * '<S8>'   : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_ADCINT1'
 * '<S9>'   : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_ECAP1_INT'
 * '<S10>'  : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_ECAP2_INT'
 * '<S11>'  : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_ECAP3_INT'
 * '<S12>'  : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_SCIRXINTA'
 * '<S13>'  : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_ADCINT1/ECSoC'
 * '<S14>'  : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_ADCINT1/ECSoC/ECSimCodegen'
 * '<S15>'  : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_ECAP1_INT/ECSoC'
 * '<S16>'  : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_ECAP1_INT/ECSoC/ECSimCodegen'
 * '<S17>'  : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_ECAP2_INT/ECSoC'
 * '<S18>'  : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_ECAP2_INT/ECSoC/ECSimCodegen'
 * '<S19>'  : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_ECAP3_INT/ECSoC'
 * '<S20>'  : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_ECAP3_INT/ECSoC/ECSimCodegen'
 * '<S21>'  : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_SCIRXINTA/ECSoC'
 * '<S22>'  : 'mcb_pmsm_hall_offset_f28069m/HW Interrupt/HWI_SCIRXINTA/ECSoC/ECSimCodegen'
 * '<S23>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Capture Event Selection'
 * '<S24>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity'
 * '<S25>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Read Halls'
 * '<S26>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Capture Event Selection/Output 0'
 * '<S27>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Capture Event Selection/Output 1'
 * '<S28>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity/Subsystem'
 * '<S29>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S30>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls'
 * '<S31>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S32>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S33>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S34>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S35>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S36>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S37>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S38>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S39>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S40>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S41>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Capture Event Selection'
 * '<S42>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity'
 * '<S43>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Read Halls'
 * '<S44>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Capture Event Selection/Output 0'
 * '<S45>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Capture Event Selection/Output 1'
 * '<S46>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity/Subsystem'
 * '<S47>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S48>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls'
 * '<S49>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S50>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S51>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S52>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S53>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S54>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S55>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S56>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S57>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S58>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S59>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Capture Event Selection'
 * '<S60>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity'
 * '<S61>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Read Halls'
 * '<S62>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Capture Event Selection/Output 0'
 * '<S63>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Capture Event Selection/Output 1'
 * '<S64>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity/Subsystem'
 * '<S65>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S66>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls'
 * '<S67>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S68>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S69>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S70>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S71>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S72>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S73>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S74>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S75>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S76>'  : 'mcb_pmsm_hall_offset_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S77>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System'
 * '<S78>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Data Serial Output'
 * '<S79>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Output Scaling'
 * '<S80>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/PWM_Output'
 * '<S81>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Parameters'
 * '<S82>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem'
 * '<S83>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Find Offset'
 * '<S84>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Inverse Park Transform'
 * '<S85>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/PosGen'
 * '<S86>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Sine-Cosine Lookup'
 * '<S87>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Space Vector Generator'
 * '<S88>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Subsystem1'
 * '<S89>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Find Offset/Compare To Constant'
 * '<S90>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Find Offset/Compare To Constant1'
 * '<S91>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Find Offset/Subsystem'
 * '<S92>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Find Offset/Subsystem/IIR Filter'
 * '<S93>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Find Offset/Subsystem/IIR Filter/IIR Filter'
 * '<S94>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass'
 * '<S95>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S96>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Inverse Park Transform/Two inputs CRL'
 * '<S97>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S98>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/PosGen/Disable host after 22 seconds'
 * '<S99>'  : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/PosGen/Enable PWM for 20 seconds'
 * '<S100>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/PosGen/Subsystem'
 * '<S101>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/PosGen/Subsystem1'
 * '<S102>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/PosGen/Up Counter'
 * '<S103>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/PosGen/Subsystem1/If Action Subsystem'
 * '<S104>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/PosGen/Subsystem1/If Action Subsystem2'
 * '<S105>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/PosGen/Subsystem1/Position Generator'
 * '<S106>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/PosGen/Subsystem1/Position Generator/Accumulate'
 * '<S107>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/PosGen/Subsystem1/Position Generator/Accumulate/Subsystem'
 * '<S108>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S109>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S110>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S111>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S112>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S113>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S114>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S115>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S116>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Space Vector Generator/Modulation method'
 * '<S117>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Space Vector Generator/Voltage Input'
 * '<S118>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Space Vector Generator/Modulation method/SVPWM'
 * '<S119>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S120>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S121>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S122>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S123>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Data Serial Output/Counter Limited'
 * '<S124>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Data Serial Output/Data'
 * '<S125>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Data Serial Output/Data_Conditioning'
 * '<S126>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Data Serial Output/End'
 * '<S127>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Data Serial Output/Start'
 * '<S128>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Data Serial Output/While Iterator Subsystem'
 * '<S129>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Data Serial Output/Counter Limited/Increment Real World'
 * '<S130>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Data Serial Output/Counter Limited/Wrap To Zero'
 * '<S131>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall'
 * '<S132>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Atomic Hall Reading'
 * '<S133>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position'
 * '<S134>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Atomic Hall Reading/Read Halls'
 * '<S135>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/ExtrapolationOrder'
 * '<S136>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Software Watchdog Timer'
 * '<S137>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant'
 * '<S138>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position'
 * '<S139>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/VaidityCheck'
 * '<S140>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Software Watchdog Timer/Compare To Zero'
 * '<S141>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction'
 * '<S142>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 1'
 * '<S143>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 2'
 * '<S144>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 3'
 * '<S145>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 4'
 * '<S146>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 5'
 * '<S147>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 6'
 * '<S148>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 7'
 * '<S149>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem'
 * '<S150>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem1'
 * '<S151>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1'
 * '<S152>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction'
 * '<S153>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction'
 * '<S154>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/first_order'
 * '<S155>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/second_order'
 * '<S156>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 1'
 * '<S157>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 2'
 * '<S158>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 3'
 * '<S159>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 4'
 * '<S160>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 5'
 * '<S161>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 6'
 * '<S162>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 7'
 * '<S163>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 1'
 * '<S164>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 2'
 * '<S165>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 3'
 * '<S166>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 4'
 * '<S167>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 5'
 * '<S168>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 6'
 * '<S169>' : 'mcb_pmsm_hall_offset_f28069m/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 7'
 * '<S170>' : 'mcb_pmsm_hall_offset_f28069m/Serial Receive/Data_Conditioning'
 */
#endif                                 /* mcb_pmsm_hall_offset_f28069m_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
