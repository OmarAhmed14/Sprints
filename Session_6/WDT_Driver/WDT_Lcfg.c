#include "Std_Types.h"
#include "Bit_Math.h"
#include "WDT_Cfg.h"
#include "DIO_Interface.h"

void (*Notification)(void)= NULL;

void NotificationFun(void)
{
	/*Implemented By User (ISR WDT)*/
	
	/*Turn on red Led*/
	DIO_DirectionChannel(DIO_PORTF,PIN1,OUTPUT_PIN);
	DIO_WriteChannel(DIO_PORTF,PIN1,HIGH);
}

