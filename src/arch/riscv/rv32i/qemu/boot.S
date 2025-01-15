#include "modules.S"

.type bootloader, %object
.section .boot,"a",%progbits
bootloader:
j begios_boot

.section data.kernel.vector_table.irq,"a",%progbits
.type irq_v_table, %object
irq_v_table:
  .word 0

.global begioslogo
.section data.kernel.logo,"aw",%progbits
begioslogo: .string "\n\nRISC-V - RV32I - QEMU VIRT\n▗▄▄▖ ▗▄▄▄▖ ▗▄▄▖ ▗▄▖ ▗▖  ▗▖▗▄▄▄▖ ▗▄▖  ▗▄▄▖    ▗▄▄▄▖ ▗▖ ▗▖ ▗▄▖ ▗▖  ▗▖▗▄▄▄▖▗▖ ▗▖▗▖  ▗▖\n▐▌ ▐▌▐▌   ▐▌   ▐▌ ▐▌▐▛▚▖▐▌  █  ▐▌ ▐▌▐▌       ▐▌ ▐▌ ▐▌ ▐▌▐▌ ▐▌▐▛▚▖▐▌  █  ▐▌ ▐▌▐▛▚▞▜▌\n▐▛▀▚▖▐▛▀▀▘▐▌▝▜▌▐▌ ▐▌▐▌ ▝▜▌  █  ▐▌ ▐▌ ▝▀▚▖    ▐▌ ▐▌ ▐▌ ▐▌▐▛▀▜▌▐▌ ▝▜▌  █  ▐▌ ▐▌▐▌  ▐▌\n▐▙▄▞▘▐▙▄▄▖▝▚▄▞▘▝▚▄▞▘▐▌  ▐▌▗▄█▄▖▝▚▄▞▘▗▄▄▞▘    ▐▙▄▟▙▖▝▚▄▞▘▐▌ ▐▌▐▌  ▐▌  █  ▝▚▄▞▘▐▌  ▐▌ v0.0.1\nTiny for Tinies\n\nBooting..."

.section .text.kernel

# .global add_irq_handler
.type add_irq_handler,@function
add_handler:
  lw a0, 0(sp)
  lw a1, 4(sp)
  la a2, vtable
  slli a0, a0, 0x2
  add a0,a0, a2
  sw a1, (a0)
  addi sp, sp, 0x08 # estudar retorno de pilha
  ret

begios_boot:
  addi sp, sp, -0x04 
  la a0, add_handler
  sw a0, 0(sp)
  call __begios_start
 
# 

# call printlogo      # Print logo

# printlogo:
                      # Config UART
#  la a0, begioslogo   
#  li a1, UART_BASE    
# 1:                    
#  lb t0, 0(a0)        
#  beq zero, t0, 2f    
#  sb t0, (a1)         
#  addi a0, a0, 1      
#  j 1b                
# 2:                    
#  ret




                                                                                   
                                                                                   
                                                                                   
