//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdio.h>
#include "diag/Trace.h"
#include "stm32f4xx.h"

// ----------------------------------------------------------------------------
//
// Standalone STM32F4 empty sample (trace via STDOUT).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the STDOUT output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

volatile uint32_t uiSysTicks = 0;

//	1ms tick rate / uiSysTicks increment.
void SysTick_Handler(void){
	NVIC_ClearPendingIRQ(SysTick_IRQn);
	uiSysTicks++;
}

void delayLoop(volatile unsigned int uiloops){
	while(uiloops--){};
}

int
main(int argc, char* argv[])
{
  // At this stage the system clock should have already been configured
  // at high speed.

	//	Enable pot G clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	//	Set G13&14 as GPIO outputs
	GPIOG->MODER |= GPIO_MODER_MODER13_0|GPIO_MODER_MODER14_0;
  // Infinite loop
  while (1)
    {
       // Add your code here.
	  //	toggle both user LEDs
	  GPIOG->ODR ^= 0x6000;
	  //	Delay for visibility
	  delayLoop(10000000);
    }
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
