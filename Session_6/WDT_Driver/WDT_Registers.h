#ifndef WDT_REGISTERS_H_
#define WDT_REGISTERS_H_

#define WDT0_LOAD        *((volatile u32*)(0x40000000))

#define WDT0_CTRL        *((volatile u32*)(0x40000008))
#define WDT0_CTRL_INTTYPE        2
#define WDT0_CTRL_RESEN          1
#define WDT0_CTRL_INTEN          0

#define WDT0_ICR         *((volatile u32*)(0x4000000C))

#define WDT0_LOCK        *((volatile u32*)(0x40000C00))

#define WDT0_STALL       *((volatile u32*)(0x40000418))


#endif