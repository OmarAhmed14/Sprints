#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#define NMI_INTERRUPT       1
#define STANDARD_INTERRUPT  0


void WDT_Init (void);

void WDT_SetTriggerCondition (void); 

void CallBackFunc (void (*ptrToFunc)(void));

void WDT_Stalling (void);

void NMI_Handler (void);

#endif