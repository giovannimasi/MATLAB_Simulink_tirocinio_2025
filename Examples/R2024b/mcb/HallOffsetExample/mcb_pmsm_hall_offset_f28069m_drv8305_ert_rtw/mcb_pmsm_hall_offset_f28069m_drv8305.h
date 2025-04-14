/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_hall_offset_f28069m_drv8305.h
 *
 * Code generated for Simulink model 'mcb_pmsm_hall_offset_f28069m_drv8305'.
 *
 * Model version                  : 9.11
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Mar 19 16:49:46 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_pmsm_hall_offset_f28069m_drv8305_h_
#define mcb_pmsm_hall_offset_f28069m_drv8305_h_
#ifndef mcb_pmsm_hall_offset_f28069m_drv8305_COMMON_INCLUDES_
#define mcb_pmsm_hall_offset_f28069m_drv8305_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Gpio.h"
#include "MW_c28xx_cap.h"
#include "DSP28xx_SciUtil.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#endif               /* mcb_pmsm_hall_offset_f28069m_drv8305_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "mcb_pmsm_hall_offset_f28069m_drv8305_types.h"
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

#define mcb_pmsm_hall_offset_f28069m_drv8305_M (mcb_pmsm_hall_offset_f28069m_M)

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void init_CAP_GPIO(void);
extern void init_CAP1(void);
extern void init_CAP2(void);
extern void init_CAP3(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals for system '<S27>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S29>/Merge' */
  uint16_T Merge1;                     /* '<S29>/Merge1' */
  uint16_T Merge3;                     /* '<S29>/Merge3' */
  int16_T Merge2;                      /* '<S29>/Merge2' */
  boolean_T RelationalOperator;        /* '<S29>/Relational Operator' */
} rtB_ValidHalls_mcb_pmsm_hall_of;

/* Block signals (default storage) */
typedef struct {
  uint32_T MemoryCopy1;                /* '<S4>/Memory Copy1' */
  uint32_T BitwiseAND;                 /* '<S4>/Bitwise AND' */
  uint32_T ShiftArithmetic;            /* '<S4>/Shift Arithmetic' */
  uint32_T DataStoreRead;              /* '<S4>/Data Store Read' */
  uint32_T eCAP[2];                    /* '<S4>/eCAP' */
  uint32_T Switch;                     /* '<S4>/Switch' */
  uint32_T MemoryCopy1_i;              /* '<S3>/Memory Copy1' */
  uint32_T BitwiseAND_i;               /* '<S3>/Bitwise AND' */
  uint32_T ShiftArithmetic_b;          /* '<S3>/Shift Arithmetic' */
  uint32_T DataStoreRead_e;            /* '<S3>/Data Store Read' */
  uint32_T eCAP_i[2];                  /* '<S3>/eCAP' */
  uint32_T Switch_f;                   /* '<S3>/Switch' */
  uint32_T MemoryCopy1_f;              /* '<S2>/Memory Copy1' */
  uint32_T BitwiseAND_o;               /* '<S2>/Bitwise AND' */
  uint32_T ShiftArithmetic_a;          /* '<S2>/Shift Arithmetic' */
  uint32_T DataStoreRead_l;            /* '<S2>/Data Store Read' */
  uint32_T eCAP_ii[2];                 /* '<S2>/eCAP' */
  uint32_T Switch_k;                   /* '<S2>/Switch' */
  uint32_T DataStoreRead_n;            /* '<S128>/Data Store Read' */
  uint32_T DataStoreRead2;             /* '<S128>/Data Store Read2' */
  uint32_T speedCountDelay;            /* '<S130>/speedCountDelay' */
  uint32_T MemoryCopy3;                /* '<S128>/Memory Copy3' */
  uint32_T MemoryCopy4;                /* '<S128>/Memory Copy4' */
  uint32_T MemoryCopy5;                /* '<S128>/Memory Copy5' */
  uint32_T Min;                        /* '<S128>/Min' */
  uint32_T Sum[4];                     /* '<S105>/Sum' */
  uint32_T Max;                        /* '<S134>/Max' */
  uint32_T Delay;                      /* '<S99>/Delay' */
  uint32_T Add1;                       /* '<S99>/Add1' */
  real32_T DataTypeConversion1;        /* '<S165>/Data Type Conversion1' */
  real32_T Merge;                      /* '<S129>/Merge' */
  real32_T Merge1;                     /* '<S129>/Merge1' */
  real32_T Switch_m;                   /* '<S6>/Switch' */
  real32_T Merge_l;                    /* '<S107>/Merge' */
  real32_T indexing;                   /* '<S105>/indexing' */
  real32_T Lookup[4];                  /* '<S105>/Lookup' */
  real32_T Sum3;                       /* '<S106>/Sum3' */
  real32_T DataTypeConversion1_p;      /* '<S105>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S105>/Sum2' */
  real32_T Product;                    /* '<S106>/Product' */
  real32_T Sum4;                       /* '<S106>/Sum4' */
  real32_T Sum5;                       /* '<S106>/Sum5' */
  real32_T Product1;                   /* '<S106>/Product1' */
  real32_T Sum6;                       /* '<S106>/Sum6' */
  real32_T currentSpeedData;           /* '<S133>/currentSpeedData' */
  real32_T Divide;                     /* '<S133>/Divide' */
  real32_T SpeedGain;                  /* '<S133>/SpeedGain' */
  real32_T Merge1_f;                   /* '<S146>/Merge1' */
  real32_T Saturation;                 /* '<S146>/Saturation' */
  real32_T Merge_g;                    /* '<S146>/Merge' */
  real32_T countData;                  /* '<S149>/countData' */
  real32_T currentSpeedData_g;         /* '<S149>/currentSpeedData' */
  real32_T Divide_m;                   /* '<S149>/Divide' */
  real32_T countData_a;                /* '<S150>/countData' */
  real32_T previousSpeedData;          /* '<S150>/previousSpeedData' */
  real32_T Divide_mp;                  /* '<S150>/Divide' */
  real32_T currentSpeedData_n;         /* '<S150>/currentSpeedData' */
  real32_T Divide1;                    /* '<S150>/Divide1' */
  real32_T Sum_b;                      /* '<S150>/Sum' */
  real32_T Gain1;                      /* '<S150>/Gain1' */
  real32_T Sum1;                       /* '<S150>/Sum1' */
  real32_T Product_c;                  /* '<S150>/Product' */
  real32_T Merge1_o;                   /* '<S147>/Merge1' */
  real32_T Merge1_m;                   /* '<S148>/Merge1' */
  real32_T sqrt3_by_two;               /* '<S119>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S119>/one_by_two' */
  real32_T add_c;                      /* '<S119>/add_c' */
  real32_T add_b;                      /* '<S119>/add_b' */
  real32_T Min_f;                      /* '<S116>/Min' */
  real32_T Max_l;                      /* '<S116>/Max' */
  real32_T Add;                        /* '<S116>/Add' */
  real32_T one_by_two_g;               /* '<S116>/one_by_two' */
  real32_T Add2;                       /* '<S115>/Add2' */
  real32_T Add1_j;                     /* '<S115>/Add1' */
  real32_T Add3;                       /* '<S115>/Add3' */
  real32_T Gain[3];                    /* '<S115>/Gain' */
  real32_T Sum_j[3];                   /* '<S76>/Sum' */
  real32_T Gain_i[3];                  /* '<S76>/Gain' */
  real32_T Input;                      /* '<S85>/Input' */
  real32_T Convert_back;               /* '<S111>/Convert_back' */
  real32_T Convert_back_c;             /* '<S110>/Convert_back' */
  real32_T Merge_o;                    /* '<S98>/Merge' */
  real32_T UnitDelay;                  /* '<S102>/Unit Delay' */
  real32_T scaleOut;                   /* '<S102>/scaleOut' */
  real32_T Add_e;                      /* '<S103>/Add' */
  real32_T DataTypeConversion1_d;      /* '<S103>/Data Type Conversion1' */
  real32_T Add1_m;                     /* '<S103>/Add1' */
  real32_T Input_d;                    /* '<S104>/Input' */
  real32_T Delay_b;                    /* '<S101>/Delay' */
  real32_T Add1_d;                     /* '<S101>/Add1' */
  real32_T SaturatetomotorcalibSpeedRPM;
                               /* '<S101>/Saturate to 'motor.calibSpeed' RPM' */
  real32_T qcos;                       /* '<S93>/qcos' */
  real32_T dsin;                       /* '<S93>/dsin' */
  real32_T sum_beta;                   /* '<S93>/sum_beta' */
  real32_T dcos;                       /* '<S93>/dcos' */
  real32_T qsin;                       /* '<S93>/qsin' */
  real32_T sum_alpha;                  /* '<S93>/sum_alpha' */
  real32_T Switch_fs[2];               /* '<S94>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T Delay_o;                    /* '<S80>/Delay' */
  real32_T Switch1[2];                 /* '<S89>/Switch1' */
  real32_T Product_l;                  /* '<S92>/Product' */
  real32_T UnitDelay_d;                /* '<S92>/Unit Delay' */
  real32_T Product1_m;                 /* '<S92>/Product1' */
  real32_T Add1_mi;                    /* '<S92>/Add1' */
  int32_T DataTypeConversion1_m[2];    /* '<S122>/Data Type Conversion1' */
  uint16_T SCIReceive;                 /* '<S7>/SCI Receive' */
  uint16_T DataTypeConversion1_k;      /* '<S58>/Data Type Conversion1' */
  uint16_T DataTypeConversion2;        /* '<S58>/Data Type Conversion2' */
  uint16_T DataTypeConversion;         /* '<S61>/Data Type Conversion' */
  uint16_T Merge_c;                    /* '<S61>/Merge' */
  uint16_T DataTypeConversion1_e;      /* '<S41>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_j;      /* '<S41>/Data Type Conversion2' */
  uint16_T DataTypeConversion_o;       /* '<S44>/Data Type Conversion' */
  uint16_T Merge_ly;                   /* '<S44>/Merge' */
  uint16_T DataTypeConversion1_a;      /* '<S24>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_b;      /* '<S24>/Data Type Conversion2' */
  uint16_T DataTypeConversion_od;      /* '<S27>/Data Type Conversion' */
  uint16_T Merge_a;                    /* '<S27>/Merge' */
  uint16_T DataStoreRead5;             /* '<S128>/Data Store Read5' */
  uint16_T Switch_i;                   /* '<S129>/Switch' */
  uint16_T DataStoreRead4;             /* '<S128>/Data Store Read4' */
  uint16_T Switch_o;                   /* '<S130>/Switch' */
  uint16_T DelayOneStep;               /* '<S131>/Delay One Step' */
  uint16_T watchdogcheck;              /* '<S134>/watchdog check' */
  uint16_T Sum_a;                      /* '<S131>/Sum' */
  uint16_T Output;                     /* '<S120>/Output' */
  uint16_T DataTypeConversion3[2];     /* '<S122>/Data Type Conversion3' */
  uint16_T Merge_ol[3];                /* '<S75>/Merge' */
  uint16_T Merge1_b;                   /* '<S75>/Merge1' */
  uint16_T FixPtSum1;                  /* '<S126>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S127>/FixPt Switch' */
  uint16_T DataTypeConversion_g;       /* '<S107>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S105>/Get_Integer' */
  uint16_T Switch4[3];                 /* '<S76>/Switch4' */
  uint16_T IAIBMeasurement[2];         /* '<S6>/IA//IB Measurement' */
  uint16_T speedcheck;                 /* '<S134>/speed check' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S76>/Scale_to_PWM_Counter_PRD' */
  uint16_T IndexVector;                /* '<S125>/Index Vector' */
  uint16_T Add_d;                      /* '<S125>/Add' */
  uint16_T Data[2];                    /* '<S121>/Data' */
  uint16_T Data_f[2];                  /* '<S123>/Data' */
  uint16_T Data_fw[2];                 /* '<S124>/Data' */
  int16_T DataStoreRead1;              /* '<S4>/Data Store Read1' */
  int16_T Merge1_d;                    /* '<S61>/Merge1' */
  int16_T DataStoreRead1_i;            /* '<S3>/Data Store Read1' */
  int16_T Merge1_c;                    /* '<S44>/Merge1' */
  int16_T DataStoreRead1_k;            /* '<S2>/Data Store Read1' */
  int16_T Merge1_cv;                   /* '<S27>/Merge1' */
  int16_T DataStoreRead3;              /* '<S128>/Data Store Read3' */
  int16_T WhileIterator;               /* '<S125>/While Iterator' */
  int16_T Convert_uint16;              /* '<S111>/Convert_uint16' */
  int16_T Convert_uint16_k;            /* '<S110>/Convert_uint16' */
  int16_T DataTypeConversion_c;        /* '<S103>/Data Type Conversion' */
  boolean_T Switch_a;                  /* '<S7>/Switch' */
  boolean_T Merge3;                    /* '<S61>/Merge3' */
  boolean_T Merge_m;                   /* '<S57>/Merge' */
  boolean_T Merge3_d;                  /* '<S44>/Merge3' */
  boolean_T Merge_lg;                  /* '<S40>/Merge' */
  boolean_T Merge3_o;                  /* '<S27>/Merge3' */
  boolean_T Merge_gs;                  /* '<S23>/Merge' */
  boolean_T DataTypeConversion4;       /* '<S129>/Data Type Conversion4' */
  boolean_T DataTypeConversion_k;      /* '<S130>/Data Type Conversion' */
  boolean_T validityDelay;             /* '<S130>/validityDelay' */
  boolean_T DelayOneStep1;             /* '<S131>/Delay One Step1' */
  boolean_T OR;                        /* '<S131>/OR' */
  boolean_T Compare;                   /* '<S135>/Compare' */
  boolean_T DataStoreRead_c;           /* '<S74>/Data Store Read' */
  boolean_T NOT;                       /* '<S74>/NOT' */
  boolean_T Compare_e;                 /* '<S109>/Compare' */
  boolean_T Switch_p;                  /* '<S77>/Switch' */
  boolean_T LogicalOperator;           /* '<S130>/Logical Operator' */
  boolean_T NOT_m;                     /* '<S77>/NOT' */
  boolean_T Compare_a;                 /* '<S95>/Compare' */
  boolean_T NOT_k;                     /* '<S82>/NOT' */
  boolean_T Compare_i;                 /* '<S96>/Compare' */
  boolean_T NOT_g;                     /* '<S102>/NOT' */
  boolean_T Delay_c;                   /* '<S103>/Delay' */
  boolean_T Compare_au;                /* '<S86>/Compare' */
  boolean_T Compare_j;                 /* '<S87>/Compare' */
  boolean_T AND;                       /* '<S80>/AND' */
  rtB_ValidHalls_mcb_pmsm_hall_of ValidHalls_a;/* '<S61>/Valid Halls' */
  rtB_ValidHalls_mcb_pmsm_hall_of ValidHalls_j;/* '<S44>/Valid Halls' */
  rtB_ValidHalls_mcb_pmsm_hall_of ValidHalls;/* '<S27>/Valid Halls' */
} BlockIO_mcb_pmsm_hall_offset_f2;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint64m_T Add1_DWORK1;               /* '<S99>/Add1' */
  real32_T UnitDelay_DSTATE;           /* '<S102>/Unit Delay' */
  real32_T Delay_DSTATE;               /* '<S101>/Delay' */
  real32_T Delay_DSTATE_p;             /* '<S80>/Delay' */
  real32_T UnitDelay_DSTATE_f;         /* '<S92>/Unit Delay' */
  uint32_T Delay_DSTATE_pm;            /* '<S99>/Delay' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S5>/Digital Output' */
  int32_T InverterEnable_FRAC_LEN;     /* '<S77>/Inverter Enable' */
  uint32_T GlobalSpeedCount;           /* '<Root>/Data Store Memory1' */
  uint32_T GlobalHallState;            /* '<Root>/Data Store Memory4' */
  uint32_T Sum_DWORK1[4];              /* '<S105>/Sum' */
  uint16_T DelayOneStep_DSTATE;        /* '<S131>/Delay One Step' */
  uint16_T Output_DSTATE;              /* '<S120>/Output' */
  int16_T GlobalDirection;             /* '<Root>/Data Store Memory3' */
  uint16_T HallStateChangeFlag;        /* '<Root>/Data Store Memory' */
  uint16_T GlobalSpeedValidity;        /* '<Root>/Data Store Memory2' */
  uint16_T Add_DWORK1;                 /* '<S125>/Add' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S131>/Delay One Step1' */
  boolean_T Delay_DSTATE_b;            /* '<S103>/Delay' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T PosGen_MODE;               /* '<S74>/PosGen' */
  boolean_T UpCounter_MODE;            /* '<S82>/Up Counter' */
  boolean_T FindOffset_MODE;           /* '<S74>/Find Offset' */
} D_Work_mcb_pmsm_hall_offset_f28;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S105>/sine_table_values'
   */
  real32_T sine_table_values_Value[1002];
} ConstParam_mcb_pmsm_hall_offset;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_hall_offset_f2 {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern BlockIO_mcb_pmsm_hall_offset_f2 mcb_pmsm_hall_offset_f28069m__B;

/* Block states (default storage) */
extern D_Work_mcb_pmsm_hall_offset_f28 mcb_pmsm_hall_offset_f280_DWork;

/* Constant parameters (default storage) */
extern const ConstParam_mcb_pmsm_hall_offset mcb_pmsm_hall_offset_f28_ConstP;

/* Model entry point functions */
extern void mcb_pmsm_hall_offset_f28069m_drv8305_initialize(void);
extern void mcb_pmsm_hall_offset_f28069m_drv8305_step(void);
extern void mcb_pmsm_hall_offset_f28069m_drv8305_terminate(void);

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
  void mcb_pmsm_hall_offset_f28069m_drv8305_configure_interrupts (void);
  void mcb_pmsm_hall_offset_f28069m_drv8305_unconfigure_interrupts (void);

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
 * '<Root>' : 'mcb_pmsm_hall_offset_f28069m_drv8305'
 * '<S1>'   : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt'
 * '<S2>'   : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A'
 * '<S3>'   : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B'
 * '<S4>'   : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C'
 * '<S5>'   : 'mcb_pmsm_hall_offset_f28069m_drv8305/Heartbeat LED'
 * '<S6>'   : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation'
 * '<S7>'   : 'mcb_pmsm_hall_offset_f28069m_drv8305/Serial Receive'
 * '<S8>'   : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_ADCINT1'
 * '<S9>'   : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_ECAP1_INT'
 * '<S10>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_ECAP2_INT'
 * '<S11>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_ECAP3_INT'
 * '<S12>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_SCIRXINTA'
 * '<S13>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_ADCINT1/ECSoC'
 * '<S14>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_ADCINT1/ECSoC/ECSimCodegen'
 * '<S15>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_ECAP1_INT/ECSoC'
 * '<S16>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_ECAP1_INT/ECSoC/ECSimCodegen'
 * '<S17>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_ECAP2_INT/ECSoC'
 * '<S18>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_ECAP2_INT/ECSoC/ECSimCodegen'
 * '<S19>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_ECAP3_INT/ECSoC'
 * '<S20>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_ECAP3_INT/ECSoC/ECSimCodegen'
 * '<S21>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_SCIRXINTA/ECSoC'
 * '<S22>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/HW Interrupt/HWI_SCIRXINTA/ECSoC/ECSimCodegen'
 * '<S23>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Capture Event Selection'
 * '<S24>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity'
 * '<S25>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Capture Event Selection/Output 0'
 * '<S26>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Capture Event Selection/Output 1'
 * '<S27>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity/Subsystem'
 * '<S28>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S29>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity/Subsystem/Valid Halls'
 * '<S30>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S31>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S32>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S33>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S34>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S35>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S36>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S37>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S38>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S39>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S40>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Capture Event Selection'
 * '<S41>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity'
 * '<S42>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Capture Event Selection/Output 0'
 * '<S43>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Capture Event Selection/Output 1'
 * '<S44>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity/Subsystem'
 * '<S45>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S46>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity/Subsystem/Valid Halls'
 * '<S47>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S48>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S49>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S50>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S51>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S52>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S53>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S54>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S55>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S56>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S57>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Capture Event Selection'
 * '<S58>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity'
 * '<S59>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Capture Event Selection/Output 0'
 * '<S60>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Capture Event Selection/Output 1'
 * '<S61>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity/Subsystem'
 * '<S62>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S63>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity/Subsystem/Valid Halls'
 * '<S64>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S65>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S66>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S67>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S68>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S69>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S70>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S71>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S72>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S73>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S74>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System'
 * '<S75>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Data Serial Output'
 * '<S76>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Output Scaling'
 * '<S77>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/PWM_Output'
 * '<S78>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Parameters'
 * '<S79>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem'
 * '<S80>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Find Offset'
 * '<S81>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Inverse Park Transform'
 * '<S82>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/PosGen'
 * '<S83>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Sine-Cosine Lookup'
 * '<S84>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Space Vector Generator'
 * '<S85>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Subsystem1'
 * '<S86>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Find Offset/Compare To Constant'
 * '<S87>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Find Offset/Compare To Constant1'
 * '<S88>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Find Offset/Subsystem'
 * '<S89>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Find Offset/Subsystem/IIR Filter'
 * '<S90>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Find Offset/Subsystem/IIR Filter/IIR Filter'
 * '<S91>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass'
 * '<S92>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S93>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Inverse Park Transform/Two inputs CRL'
 * '<S94>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S95>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/PosGen/Disable host after 22 seconds'
 * '<S96>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/PosGen/Enable PWM for 20 seconds'
 * '<S97>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/PosGen/Subsystem'
 * '<S98>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/PosGen/Subsystem1'
 * '<S99>'  : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/PosGen/Up Counter'
 * '<S100>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/PosGen/Subsystem1/If Action Subsystem'
 * '<S101>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/PosGen/Subsystem1/If Action Subsystem2'
 * '<S102>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/PosGen/Subsystem1/Position Generator'
 * '<S103>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/PosGen/Subsystem1/Position Generator/Accumulate'
 * '<S104>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/PosGen/Subsystem1/Position Generator/Accumulate/Subsystem'
 * '<S105>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S106>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S107>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S108>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S109>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S110>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S111>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S112>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S113>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Space Vector Generator/Modulation method'
 * '<S114>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Space Vector Generator/Voltage Input'
 * '<S115>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Space Vector Generator/Modulation method/SVPWM'
 * '<S116>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S117>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S118>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S119>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S120>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Data Serial Output/Counter Limited'
 * '<S121>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Data Serial Output/Data'
 * '<S122>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Data Serial Output/Data_Conditioning'
 * '<S123>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Data Serial Output/End'
 * '<S124>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Data Serial Output/Start'
 * '<S125>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Data Serial Output/While Iterator Subsystem'
 * '<S126>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Data Serial Output/Counter Limited/Increment Real World'
 * '<S127>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Data Serial Output/Counter Limited/Wrap To Zero'
 * '<S128>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall'
 * '<S129>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position'
 * '<S130>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/ExtrapolationOrder'
 * '<S131>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Software Watchdog Timer'
 * '<S132>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant'
 * '<S133>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position'
 * '<S134>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/VaidityCheck'
 * '<S135>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Software Watchdog Timer/Compare To Zero'
 * '<S136>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction'
 * '<S137>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 1'
 * '<S138>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 2'
 * '<S139>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 3'
 * '<S140>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 4'
 * '<S141>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 5'
 * '<S142>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 6'
 * '<S143>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 7'
 * '<S144>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem'
 * '<S145>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem1'
 * '<S146>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1'
 * '<S147>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction'
 * '<S148>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction'
 * '<S149>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/first_order'
 * '<S150>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/second_order'
 * '<S151>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 1'
 * '<S152>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 2'
 * '<S153>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 3'
 * '<S154>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 4'
 * '<S155>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 5'
 * '<S156>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 6'
 * '<S157>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 7'
 * '<S158>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 1'
 * '<S159>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 2'
 * '<S160>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 3'
 * '<S161>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 4'
 * '<S162>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 5'
 * '<S163>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 6'
 * '<S164>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Offset Calculation/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 7'
 * '<S165>' : 'mcb_pmsm_hall_offset_f28069m_drv8305/Serial Receive/Data_Conditioning'
 */
#endif                             /* mcb_pmsm_hall_offset_f28069m_drv8305_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
