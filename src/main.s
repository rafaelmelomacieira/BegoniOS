	.globl _start			;

	.text
	
_start:
	lw	a0, .zero	;
	lw	a5, 0(a0)	;
	add	a6, a5, a5	;
	sw	a6, 0(a0)	;
	lui	a5, 0x112	;
	sw	a5, 0(a0)	;
