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
	/*First Must Enter in handler Mode and switch to privMode*/
	/*this Function Must Call in SVC ISR to be in handler mode*/
	
	/*In Control Register put bit0 =0 to switch to privMode*/
	__asm ("MOV R1, #0x0");
	__asm ("MSR CONTROL, R1");
}

void Cpu_StartCriticalSection(void)
{
	/*To start critical section and to read, modify and write, to avoid interrupts (disable them)*/
	__asm ("CPSID i");
}

void Cpu_EndCriticalSection(void)
{
	/*To End critical section after read, modify and write, Enable Interrupts again*/
	__asm ("CPSIE i");
}