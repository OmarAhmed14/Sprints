#include "Std_Types.h"
#include "Bit_Math.h"
#include "IntCtrl_Registers.h"
#include "IntCtrl_Cfg.h"
#include "IntCtrl_Interface.h"

extern NVIC_Enabled_Interrupt Enabled_Interrupts_0_31[Number_Enabled_Interrupts];
extern u32 Group_Cfg;

static u32 Reg_offset,Bit_offset;
static volatile u32* NVIC_PRI=0;

void IntCtrl_Init(void)
{
	IntCtrl_BasePriority(); /*Select Base Priority*/
	
	APINT=0x05FA0000;  /*Key Register*/
	
	for (u8 Counter=0; Counter<=Number_Enabled_Interrupts;Counter++)
	{
	Reg_offset =(Enabled_Interrupts_0_31[Counter].Interrupt)/4;
	Bit_offset= (((Enabled_Interrupts_0_31[Counter].Interrupt)%4)*8)+5;
		
	switch(Group_Cfg)
	{
		case Group_xxx:
		APINT=0x05FA0000;  /*Key Register*/   // Put 0x0 in PRIGROUP Bits (xxx Group)
		NVIC_PRI =(NVIC_PRI0+(Reg_offset));
		(*NVIC_PRI) |=(Enabled_Interrupts_0_31[Counter].Group<<Bit_offset);   
		if (Enabled_Interrupts_0_31[Counter].Interrupt<32)
			NVIC_EN0|=(1<<Enabled_Interrupts_0_31[Counter].Interrupt);
		break;
		
		case Group_xxy:
		APINT=0x05FA0500;  /*Key Register*/    // Put 0x5 in PRIGROUP Bits (xxy Group)
		NVIC_PRI =(NVIC_PRI0+(Reg_offset));
		*NVIC_PRI |=(Enabled_Interrupts_0_31[Counter].SubGroup<<Bit_offset);
		*NVIC_PRI |=(*NVIC_PRI|(Enabled_Interrupts_0_31[Counter].Group<<(Bit_offset+1)));
		if (Enabled_Interrupts_0_31[Counter].Interrupt<32)
			NVIC_EN0|=(1<<Enabled_Interrupts_0_31[Counter].Interrupt);
		break;
		
		case Group_xyy:
		APINT=0x05FA0600;  /*Key Register*/    // Put 0x6 in PRIGROUP Bits (xyy Group)  
		NVIC_PRI =(NVIC_PRI0+(Reg_offset));
		*NVIC_PRI |=(Enabled_Interrupts_0_31[Counter].SubGroup<<Bit_offset);
		*NVIC_PRI |=(*NVIC_PRI|(Enabled_Interrupts_0_31[Counter].Group<<(Bit_offset+2)));
		if (Enabled_Interrupts_0_31[Counter].Interrupt<32)
			NVIC_EN0|=(1<<Enabled_Interrupts_0_31[Counter].Interrupt);
		break;
		
		case Group_yyy:
		APINT=0x05FA0700;  /*Key Register*/    // Put 0x7 in PRIGROUP Bits (yyy Group)  
		NVIC_PRI =(NVIC_PRI0+(Reg_offset));
		*NVIC_PRI |=(Enabled_Interrupts_0_31[Counter].SubGroup<<Bit_offset);
		if (Enabled_Interrupts_0_31[Counter].Interrupt<32)
			NVIC_EN0|=(1<<Enabled_Interrupts_0_31[Counter].Interrupt);
		break;
		
		default:
		break;
	}
	}
		__asm ("CPSIE i");    /*Enable All programmable Interrupts*/
}
