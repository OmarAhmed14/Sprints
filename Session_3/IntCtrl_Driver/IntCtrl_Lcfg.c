#include "Std_Types.h"
#include "IntCtrl_Cfg.h"

/*Enter Interrupts What YOu want to Enable Them*/

NVIC_Enabled_Interrupt Enabled_Interrupts_0_31[Number_Enabled_Interrupts]=
{
//Interrupt ---  Group --- Subgroup 
	{GPIO_A         ,1          ,3 },
	{GPIO_B         ,1          ,2 },
	{GPIO_F         ,1          ,1 }	
	// Note: 0xF means dont care
};

/*Select Groupping for All interupts*/
u32 Group_Cfg = Group_xyy;

/*Select Base Priotity (7 Levels priority)*/

/* 
             ..Choices..
0x00 ---> All unmasked								
0x20 ---> All 1 to 7 is masked   
0x40 ---> All 2 to 7 is masked
0x60 ---> All 3 to 7 is masked
0x80 ---> All 4 to 7 is masked
0xA0 ---> All 5 to 7 is masked
0xC0 ---> 6 and 7 is masked
0xE0 ---> only 7 is masked

*/
void IntCtrl_BasePriority()
{
	__asm ("mov R0, #0x00");   // Put Hex Number in this Line
	__asm ("MSR BASEPRI, R0");
}
