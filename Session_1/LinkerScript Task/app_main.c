#include "app_main.h"


char u8InitGLobalVar = 2;
static long int u32NonInitStaticGlobalVar; 
const short int u16ConstGlobalVar = 3;

short int sprints __attribute__((section(".sprints")))=4;

void main(void)
{
	short int u16LocVar = 4;
	static char u8InitStaticLocVar = 5;

	if(u16ConstGlobalVar == 3)
	{
		u32NonInitStaticGlobalVar = 6;
		vidFunc(&u16LocVar);
	}
	else
	{
		u32NonInitStaticGlobalVar = 7;
	}
	while(1)
	{
	
	}
}
