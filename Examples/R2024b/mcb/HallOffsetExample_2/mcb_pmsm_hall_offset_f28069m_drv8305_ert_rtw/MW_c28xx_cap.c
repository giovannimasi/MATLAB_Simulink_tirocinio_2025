#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Examples.h"
#include "F2806x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "mcb_pmsm_hall_offset_f28069m.h"
#include "mcb_pmsm_hall_offset_f28069m_private.h"

void init_CAP_GPIO(void)
{
  EALLOW;
  GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0U; /* Enable pull-up on GPIO24 (CAP1)*/
  GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 1U;/* Configure GPIO24 as (CAP1)*/
  GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0U; /* Enable pull-up on GPIO25 (CAP2)*/
  GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 1U;/* Configure GPIO25 as (CAP2)*/
  GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0U; /* Enable pull-up on GPIO26 (CAP3)*/
  GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 1U;/* Configure GPIO26 as (CAP3)*/
  EDIS;
}

#include "MW_c28xx_cap.h"

void init_CAP1(void)
{
  ECap1Regs.ECEINT.all = 0x0000U;      /* Disable all capture interrupts*/
  ECap1Regs.ECCLR.all = 0xFFFFU;       /* Clear all CAP interrupt flags*/
  ECap1Regs.ECCTL1.bit.CAPLDEN = 0U;   /* Disable CAP1-CAP4 register loads*/
  ECap1Regs.ECCTL2.bit.TSCTRSTOP = 0U; /* Make sure the counter is stopped*/
  ECap1Regs.CTRPHS = 0U;               /* Counter Phase Control*/
  ECap1Regs.ECCTL2.bit.SYNCO_SEL = 2U; /* Disable sync out signal*/
  ECap1Regs.ECCTL2.bit.CAP_APWM = 0U;  /* Capture mode*/
  ECap1Regs.ECCTL2.bit.CONT_ONESHT = 0U;/* One-shot*/
  ECap1Regs.ECCTL1.bit.PRESCALE = 0U;  /*Event prescaler*/
  ECap1Regs.ECCTL2.bit.STOP_WRAP = 1U; /* Stop at 4 events*/
  ECap1Regs.ECCTL1.bit.CAP1POL = 0U;   /* Select rising or falling edge*/
  ECap1Regs.ECCTL1.bit.CTRRST1 = 1U;   /* Difference operation        */
  ECap1Regs.ECCTL1.bit.CAP2POL = 1U;   /* Select rising or falling edge*/
  ECap1Regs.ECCTL1.bit.CTRRST2 = 1U;   /* Difference operation        */
  ECap1Regs.ECEINT.bit.CEVT1 = 1U;
  ECap1Regs.ECEINT.bit.CEVT2 = 1U;
  ECap1Regs.ECEINT.bit.CTROVF = 1U;
  ECap1Regs.ECCLR.all = 0x0FFU;        /* Clear pending interrupts*/
  ECap1Regs.ECCTL2.bit.REARM = 1U;     /* arm one-shot*/
  ECap1Regs.ECCTL2.bit.TSCTRSTOP = 1U; /* Start Counter*/
  ECap1Regs.ECCTL1.bit.CAPLDEN = 1U;   /* Enable CAP1-CAP4 register loads*/
}

#include "MW_c28xx_cap.h"

void init_CAP2(void)
{
  ECap2Regs.ECEINT.all = 0x0000U;      /* Disable all capture interrupts*/
  ECap2Regs.ECCLR.all = 0xFFFFU;       /* Clear all CAP interrupt flags*/
  ECap2Regs.ECCTL1.bit.CAPLDEN = 0U;   /* Disable CAP1-CAP4 register loads*/
  ECap2Regs.ECCTL2.bit.TSCTRSTOP = 0U; /* Make sure the counter is stopped*/
  ECap2Regs.CTRPHS = 0U;               /* Counter Phase Control*/
  ECap2Regs.ECCTL2.bit.SYNCO_SEL = 2U; /* Disable sync out signal*/
  ECap2Regs.ECCTL2.bit.CAP_APWM = 0U;  /* Capture mode*/
  ECap2Regs.ECCTL2.bit.CONT_ONESHT = 0U;/* One-shot*/
  ECap2Regs.ECCTL1.bit.PRESCALE = 0U;  /*Event prescaler*/
  ECap2Regs.ECCTL2.bit.STOP_WRAP = 1U; /* Stop at 4 events*/
  ECap2Regs.ECCTL1.bit.CAP1POL = 0U;   /* Select rising or falling edge*/
  ECap2Regs.ECCTL1.bit.CTRRST1 = 1U;   /* Difference operation        */
  ECap2Regs.ECCTL1.bit.CAP2POL = 1U;   /* Select rising or falling edge*/
  ECap2Regs.ECCTL1.bit.CTRRST2 = 1U;   /* Difference operation        */
  ECap2Regs.ECEINT.bit.CEVT1 = 1U;
  ECap2Regs.ECEINT.bit.CEVT2 = 1U;
  ECap2Regs.ECEINT.bit.CTROVF = 1U;
  ECap2Regs.ECCLR.all = 0x0FFU;        /* Clear pending interrupts*/
  ECap2Regs.ECCTL2.bit.REARM = 1U;     /* arm one-shot*/
  ECap2Regs.ECCTL2.bit.TSCTRSTOP = 1U; /* Start Counter*/
  ECap2Regs.ECCTL1.bit.CAPLDEN = 1U;   /* Enable CAP1-CAP4 register loads*/
}

#include "MW_c28xx_cap.h"

void init_CAP3(void)
{
  ECap3Regs.ECEINT.all = 0x0000U;      /* Disable all capture interrupts*/
  ECap3Regs.ECCLR.all = 0xFFFFU;       /* Clear all CAP interrupt flags*/
  ECap3Regs.ECCTL1.bit.CAPLDEN = 0U;   /* Disable CAP1-CAP4 register loads*/
  ECap3Regs.ECCTL2.bit.TSCTRSTOP = 0U; /* Make sure the counter is stopped*/
  ECap3Regs.CTRPHS = 0U;               /* Counter Phase Control*/
  ECap3Regs.ECCTL2.bit.SYNCO_SEL = 2U; /* Disable sync out signal*/
  ECap3Regs.ECCTL2.bit.CAP_APWM = 0U;  /* Capture mode*/
  ECap3Regs.ECCTL2.bit.CONT_ONESHT = 0U;/* One-shot*/
  ECap3Regs.ECCTL1.bit.PRESCALE = 0U;  /*Event prescaler*/
  ECap3Regs.ECCTL2.bit.STOP_WRAP = 1U; /* Stop at 4 events*/
  ECap3Regs.ECCTL1.bit.CAP1POL = 0U;   /* Select rising or falling edge*/
  ECap3Regs.ECCTL1.bit.CTRRST1 = 1U;   /* Difference operation        */
  ECap3Regs.ECCTL1.bit.CAP2POL = 1U;   /* Select rising or falling edge*/
  ECap3Regs.ECCTL1.bit.CTRRST2 = 1U;   /* Difference operation        */
  ECap3Regs.ECEINT.bit.CEVT1 = 1U;
  ECap3Regs.ECEINT.bit.CEVT2 = 1U;
  ECap3Regs.ECEINT.bit.CTROVF = 1U;
  ECap3Regs.ECCLR.all = 0x0FFU;        /* Clear pending interrupts*/
  ECap3Regs.ECCTL2.bit.REARM = 1U;     /* arm one-shot*/
  ECap3Regs.ECCTL2.bit.TSCTRSTOP = 1U; /* Start Counter*/
  ECap3Regs.ECCTL1.bit.CAPLDEN = 1U;   /* Enable CAP1-CAP4 register loads*/
}
