	.syntax unified
	.cpu cortex-m4
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.thumb
	.file	"app_main.c"
	.global	u8InitGLobalVar
	.data
	.type	u8InitGLobalVar, %object
	.size	u8InitGLobalVar, 1
u8InitGLobalVar:
	.byte	2
	.bss
	.align	2
u32NonInitStaticGlobalVar:
	.space	4
	.global	u16ConstGlobalVar
	.section	.rodata
	.align	1
	.type	u16ConstGlobalVar, %object
	.size	u16ConstGlobalVar, 2
u16ConstGlobalVar:
	.short	3
	.global	sprints
	.section	.sprints,"aw",%progbits
	.align	1
	.type	sprints, %object
	.size	sprints, 2
sprints:
	.short	4
	.text
	.align	2
	.global	main
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	mov	r3, #4
	strh	r3, [r7, #6]	@ movhi
	movw	r3, #:lower16:u16ConstGlobalVar
	movt	r3, #:upper16:u16ConstGlobalVar
	ldrh	r3, [r3, #0]
	sxth	r3, r3
	cmp	r3, #3
	bne	.L2
	movw	r3, #:lower16:u32NonInitStaticGlobalVar
	movt	r3, #:upper16:u32NonInitStaticGlobalVar
	mov	r2, #6
	str	r2, [r3, #0]
	add	r3, r7, #6
	mov	r0, r3
	bl	vidFunc
	b	.L3
.L2:
	movw	r3, #:lower16:u32NonInitStaticGlobalVar
	movt	r3, #:upper16:u32NonInitStaticGlobalVar
	mov	r2, #7
	str	r2, [r3, #0]
.L3:
	b	.L3
	.size	main, .-main
	.data
	.type	u8InitStaticLocVar.4060, %object
	.size	u8InitStaticLocVar.4060, 1
u8InitStaticLocVar.4060:
	.byte	5
	.ident	"GCC: (GNU) 4.7.2"
