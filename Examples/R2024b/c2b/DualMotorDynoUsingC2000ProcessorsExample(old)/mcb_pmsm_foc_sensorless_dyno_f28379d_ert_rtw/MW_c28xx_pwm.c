#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "mcb_pmsm_foc_sensorless_dyno_f28379d.h"
#include "mcb_pmsm_foc_sensorless_dyno_f28379d_private.h"

void config_ePWM_GPIO (void)
{
  EALLOW;
  ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = 0U;

  /*-- Configure pin assignments for ePWM1 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO0 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1U; /* Configure GPIOGPIO0 as EPWM1A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO1 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1U; /* Configure GPIOGPIO1 as EPWM1B*/

  /*-- Configure pin assignments for ePWM2 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO2 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1U; /* Configure GPIOGPIO2 as EPWM2A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO3 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1U; /* Configure GPIOGPIO3 as EPWM2B*/

  /*-- Configure pin assignments for ePWM3 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO4 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1U; /* Configure GPIOGPIO4 as EPWM3A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO5 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1U; /* Configure GPIOGPIO5 as EPWM3B*/

  /*-- Configure pin assignments for ePWM4 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO6 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1U; /* Configure GPIOGPIO6 as EPWM4A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO7 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1U; /* Configure GPIOGPIO7 as EPWM4B*/

  /*-- Configure pin assignments for ePWM5 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO8 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1U; /* Configure GPIOGPIO8 as EPWM5A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO9 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1U; /* Configure GPIOGPIO9 as EPWM5B*/

  /*-- Configure pin assignments for ePWM6 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO10 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1U;/* Configure GPIOGPIO10 as EPWM6A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO11 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1U;/* Configure GPIOGPIO11 as EPWM6B*/
  EDIS;
}

void config_ePWM_TBSync (void)
{
  /* Enable TBCLK within the EPWM*/
  EALLOW;

  /* Enable TBCLK after the ePWM configurations */
  CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1U;
  EDIS;
}

void config_ePWMSyncSource (void)
{
  /* Configuring EXTSYNCOUT source selection */
  EALLOW;
  SyncSocRegs.SYNCSELECT.bit.SYNCOUT = 0U;

  /* Configuring ePWM Sync in source selection */
  SyncSocRegs.SYNCSELECT.bit.EPWM4SYNCIN = 0U;
  SyncSocRegs.SYNCSELECT.bit.EPWM7SYNCIN = 0U;
  SyncSocRegs.SYNCSELECT.bit.EPWM10SYNCIN = 0U;
  EDIS;
}
