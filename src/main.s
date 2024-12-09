	.globl _start			;

	.text
	
_start:
	
	addi a1, a0, 0x10
	addi a2, a0, 0
	sw a1, (a2)
