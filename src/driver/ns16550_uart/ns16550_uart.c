/**
  ____                         _  ____   _____ 
 |  _ \                       (_)/ __ \ / ____|
 | |_) | ___  __ _  ___  _ __  _| |  | | (___  
 |  _ < / _ \/ _` |/ _ \| '_ \| | |  | |\___ \ 
 | |_) |  __| (_| | (_) | | | | | |__| |____) |
 |____/ \___|\__, |\___/|_| |_|_|\____/|_____/ 
              __/ |                            
             |___/                             
 @file NS16550_uart.c
 @author Rafael Macieira <rfamm01@protonmail.com>
 */

#include <ns16550_uart.h>

begios_drv_typedef* _ns16550_uart_init(char* name, uint32_t base_address){
    __ns16550_uart_typedef = base_address;
    __ns16550_uart_drv_ref = (begios_drv_typedef*) malloc(sizeof(begios_drv_typedef));
    __ns16550_uart_drv_ref->name = name;
    __ns16550_uart_drv_ref->addr = base_address;
    __ns16550_uart_drv_ref->open = ns16550_uart_open;
    __ns16550_uart_drv_ref->close = ns16550_uart_close;
    __ns16550_uart_drv_ref->reset = ns16550_uart_reset;
    __ns16550_uart_drv_ref->irq_handler = ns16550_uart_irq_handler;
    __ns16550_uart_drv_ref->read = ns16550_uart_read;
    __ns16550_uart_drv_ref->read = ns16550_uart_write;
    ns16550_uart_reset();
}

void ns16550_uart_open(){
    
}

void ns16550_uart_close(){
    
}

void ns16550_uart_reset(){
  
}

void ns16550_uart_irq_handler(uint32_t irq_id){

}

uint32_t ns16550_uart_read(uint32_t* reg){
  return *reg;
}

void ns16550_uart_write(uint32_t* reg, uint32_t data){
  *reg = data;
}