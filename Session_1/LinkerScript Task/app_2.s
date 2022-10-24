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
	.file	"app_2.c"
	.text
	.align	2
	.global	vidFunc
	.thumb
	.thumb_func
	.type	vidFunc, %function
vidFunc:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	str	r0, [r7, #4]
	ldr	r3, [r7, #4]
	ldrh	r3, [r3, #0]
	add	r3, r3, #1
	uxth	r2, r3
	ldr	r3, [r7, #4]
	strh	r2, [r3, #0]	@ movhi
	movw	r3, #:lower16:u8InitGLobalVar
	movt	r3, #:upper16:u8InitGLobalVar
	ldrb	r3, [r3, #0]	@ zero_extendqisi2
	add	r3, r3, #-1
	uxtb	r2, r3
	movw	r3, #:lower16:u8InitGLobalVar
	movt	r3, #:upper16:u8InitGLobalVar
	strb	r2, [r3, #0]
	add	r7, r7, #12
	mov	sp, r7
	pop	{r7}
	bx	lr
	.size	vidFunc, .-vidFunc
	.ident	"GCC: (GNU) 4.7.2"
