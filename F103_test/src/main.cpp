//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

//#include <stdio.h>
//#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f10x_conf.h"

// ----------------------------------------------------------------------------
//
// Standalone STM32F1 empty sample (trace via DEBUG).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
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

int main(int argc, char* argv[])
{
	// At this stage the system clock should have already been configured
	// at high speed.

	trace_puts("Hello, the world of STM32 ARM microcontrollers!");

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitTypeDef GPIOInitStruct;
	GPIOInitStruct.GPIO_Pin = GPIO_Pin_13;          // 13番ピンを
	GPIOInitStruct.GPIO_Speed = GPIO_Speed_50MHz;   // GPIOの速さを50MHzに
	GPIOInitStruct.GPIO_Mode = GPIO_Mode_Out_PP;    // 出力，プッシュプル
	GPIO_Init(GPIOC, &GPIOInitStruct);              // 構造体のポインタを渡してGPIOCの初期化

	TIM_en

	// Infinite loop
	while (1)
    {
       // Add your code here.
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		for(uint8_t i = 0; i < 1000000; i++)
		{
			__NOP();
		}
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		for(uint8_t i = 0; i < 1000000; i++)
		{
			__NOP();
		}
    }
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
