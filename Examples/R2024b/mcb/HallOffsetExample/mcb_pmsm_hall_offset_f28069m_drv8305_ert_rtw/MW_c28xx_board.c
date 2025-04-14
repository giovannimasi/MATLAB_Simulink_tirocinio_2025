#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Examples.h"
#include "F2806x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "mcb_pmsm_hall_offset_f28069m_drv8305.h"
#include "mcb_pmsm_hall_offset_f28069m_drv8305_private.h"

void init_board (void)
{
  DisableDog();
  EALLOW;
  SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1U;/* Enable ADC peripheral clock*/
  (*Device_cal)();
  SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 0U;/* Return ADC clock to original state*/
  EDIS;

  /* Select Internal Oscillator 1 as Clock Source (default), and turn off all unused clocks to
   * conserve power.
   */
  IntOsc1Sel();

  /* Initialize the PLL control: PLLCR and DIVSEL
   * DSP28_PLLCR and DSP28_DIVSEL are defined in DSP2806x_Examples.h
   */
  InitPll(9,3);
  InitPeripheralClocks();
  EALLOW;

  /* Configure low speed peripheral clocks */
  SysCtrlRegs.LOSPCP.all = 0U;
  EDIS;

  /* Disable and clear all CPU interrupts */
  DINT;
  IER = 0x0000U;
  IFR = 0x0000U;
  InitPieCtrl();
  InitPieVectTable();
  InitCpuTimers();

#ifdef CPU1
#endif                                 // #ifdef CPU1

  init_SCI();
  init_SCI_GPIO();
  init_SCIFrame();
  init_CAP_GPIO();
  init_CAP1();
  init_CAP2();
  init_CAP3();

  /* initial ePWM GPIO assignment... */
  config_ePWM_GPIO();

  /* Disable TBCLK within ePWM before module configuration */
  EALLOW;
  SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0U;
  EDIS;

  /* initial GPIO qualification settings.... */
  EALLOW;
  GpioCtrlRegs.GPAQSEL1.all = 0x0U;
  GpioCtrlRegs.GPAQSEL2.all = 0x150000U;
  GpioCtrlRegs.GPBQSEL1.all = 0x0U;
  GpioCtrlRegs.GPBQSEL2.all = 0x0U;

  /* Initialize qualification sampling period */
  // GpioCtrlRegs.GPACTRL.bit.QUALPRD3 = 0;          // GPIO Port A Qualification Control Register Field: Sampling period for pins GPIO24 to GPIO31
  GpioCtrlRegs.GPACTRL.all = (GpioCtrlRegs.GPACTRL.all & ~0xFF000000U) | 0x0U;
  EDIS;
}
