OUTPUT_ARCH( "riscv" )
ENTRY( begios_boot )

SECTIONS
{
    . = 0x80000000;
    .text : {
        *(.text)
		}
    . = ALIGN (CONSTANT (COMMONPAGESIZE));    
    .data : {
        *(.data)
		}
}