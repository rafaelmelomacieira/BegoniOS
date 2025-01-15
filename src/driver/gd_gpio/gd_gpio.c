/**
  ____                         _  ____   _____ 
 |  _ \                       (_)/ __ \ / ____|
 | |_) | ___  __ _  ___  _ __  _| |  | | (___  
 |  _ < / _ \/ _` |/ _ \| '_ \| | |  | |\___ \ 
 | |_) |  __| (_| | (_) | | | | | |__| |____) |
 |____/ \___|\__, |\___/|_| |_|_|\____/|_____/ 
              __/ |                            
             |___/                             
 @file gd_gpio.c
 @author Rafael Macieira <rfamm01@protonmail.com>
 */

#include <gd_gpio.h>

begios_drv_typedef* _ns16550_uart_init(char* name, uint32_t base_address){
    __gd_gpio_typedef = base_address;
    __gd_gpio_drv_ref = (begios_drv_typedef*) malloc(sizeof(begios_drv_typedef));
    __gd_gpio_drv_ref->name = name;
    __gd_gpio_drv_ref->addr = base_address;
    __gd_gpio_drv_ref->open = gd_dma_open;
    __gd_gpio_drv_ref->close = gd_dma_close;
    __gd_gpio_drv_ref->reset = gd_dma_reset;
    __gd_gpio_drv_ref->irq_handler = ns16550_uart_irq_handler;
    __gd_gpio_drv_ref->read = gd_dma_read;
    __gd_gpio_drv_ref->read = gd_gpio_write;
    gd_gpio_reset();
}

void gd_gpio_open(){
    
}

void gd_gpio_close(){
    
}

void gd_gpio_reset(){
  gd_gpio_write(__gd_gpio_typedef->CTL0,0x44444444);
  gd_gpio_write(__gd_gpio_typedef->CTL1,0x44444444);
  gd_gpio_write(__gd_gpio_typedef->OCTL,0x00000000);
  gd_gpio_write(__gd_gpio_typedef->BC,0x00000000);
  gd_gpio_write(__gd_gpio_typedef->LOCK,0x00000000);
}

void gd_gpio_irq_handler(uint32_t irq_id){

}

uint32_t gd_gpio_read(uint32_t* reg){
  return *reg;
}

void gd_gpio_write(uint32_t* reg, uint32_t data){
  *reg = data;
}