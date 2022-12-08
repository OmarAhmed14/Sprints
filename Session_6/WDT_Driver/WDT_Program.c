#include "Std_Types.h"
#include "Bit_Math.h"
#include "WDT_Cfg.h"
#include "WDT_Interface.h"
#include "WDT_Registers.h"


void (*ptr)(void)=0;

void WDT_Init (void)
{
	/*Unlock WDT Registers*/
	WDT0_LOCK= 0x1ACCE551;
	
	/*Load the desired value in timer*/
	u32 ticks = (1*SELECTED_TIME_OUT_VALUE/1000)/(1/12000000);
	WDT0_LOAD = 0xFF;

	/*Select Interrupt Type*/
	u8 Type=INTERRUPT_TYPE;
	if (Type == NMI_INTERRUPT)
		Set_Bit_BitBandingAlias(&WDT0_CTRL,WDT0_CTRL_INTTYPE);
	else
		Clear_Bit_BitBandingAlias(&WDT0_CTRL,WDT0_CTRL_INTTYPE);

	/*Enable Reset*/
	Set_Bit_BitBandingAlias(&WDT0_CTRL,WDT0_CTRL_RESEN);	

	/*Enable timer*/
	Set_Bit_BitBandingAlias(&WDT0_CTRL,WDT0_CTRL_INTEN);	
	
}

void WDT_SetTriggerCondition (void)
{
	/*Refresh WDT*/
	WDT0_ICR=1;
}

void WDT_Stalling (void)
{
	WDT0_STALL=0x100;
}

void CallBackFunc (void (*ptrToFunc)(void))
{
	ptr =ptrToFunc;
}

void NMI_Handler (void)
{
	if (ptr!=0)
		ptr();
}