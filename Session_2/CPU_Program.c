#include "CPU_Interface.h"

void Cpu_EnableAllInterrupts(void)
{
	/*Enable activation All programmable priority Interrupts (clear PriMask) must be in PrivMode*/
	 __asm ("CPSIE i");
}

void Cpu_DisableAllInterrupts(void)
{
	/*Disable activation All  programmable priority Interrupts (Set PriMask) must be in PrivMode*/
	 __asm ("CPSID i");
}

void Cpu_SwitchToUserMode(void)
{
	/*In Control Register put bit0 =1 to switch to unprivMode*/
	__asm ("MOV R1, #0x1");
	__asm ("MSR CONTROL, R1");
}

void Cpu_SwitchToPrivMode(void)
{
	/*In Control Register put bit0 =0 to switch to privMode*/
	__asm ("MOV R1, #0x0");
	__asm ("MSR CONTROL, R1");
}