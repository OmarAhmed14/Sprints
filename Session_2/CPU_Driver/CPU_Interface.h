#ifndef CPU_INTERFACE_H_
#define CPU_INTERFACE_H_

void Cpu_EnableAllInterrupts(void);

void Cpu_DisableAllInterrupts(void);

void Cpu_SwitchToUserMode(void);

void Cpu_SwitchToPrivMode(void);

#endif