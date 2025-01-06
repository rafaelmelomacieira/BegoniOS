/**
  _                     _   __ 
 |_)  _   _   _  ._  o / \ (_  
 |_) (/_ (_| (_) | | | \_/ __) 
          _|                   

 @file gd_gpio.c
 @author Rafael Macieira <rfamm01@protonmail.com>
 */

#include <gd_gpio.h>

begios_drv_typedef* _gd_gpio_init(uint32_t base_address){
    __gd_gpio_drv_ref = (begios_drv_typedef*) malloc(sizeof(begios_drv_typedef));
    __gd_gpio_drv_ref->name = "GD32VF103 GPIO Driver";
    __gd_gpio_drv_ref->addr = base_address;
    __gd_gpio_drv_ref->open = _gd_dma_open;
    __gd_gpio_drv_ref->close = _gd_gpio_close;
    __gd_gpio_drv_ref->reset = _gd_gpio_reset;
    __gd_gpio_drv_ref->irq_handler = _gd_gpio_irq_handler;
    __gd_gpio_drv_ref->read = _gd_dma_read;
    __gd_gpio_drv_ref->read = _gd_dma_write;
    _gd_gpio_reset();
}

void _gd_gpio_open(){
    
}

void _gd_gpio_close(){
    
}

void _gd_gpio_reset(){

}

void _gd_gpio_irq_handler(uint32_t irq_id){

}

uint32_t _gd_gpio_read(uint32_t reg){
  volatile uint32_t* data = reg + __gd_gpio_drv_ref->addr;
  return *data;
}

void _gd_gpio_write(uint32_t reg, uint32_t data){
    volatile uint32_t* t_data = reg + __gd_gpio_drv_ref->addr;
    *t_data = data;
}

/**
 * GPIOA->CRL   &= ~( GPIO_CRL_MODE1 | GPIO_CRL_CNF1 |
                     GPIO_CRL_MODE2 | GPIO_CRL_CNF2 );
  GPIOA->CRL   |=  ( ( 0x2 << GPIO_CRL_MODE1_Pos ) |
                     ( 0x2 << GPIO_CRL_MODE2_Pos ) );
  GPIOC->CRH   &= ~( GPIO_CRH_MODE13 | GPIO_CRH_CNF13 );
  GPIOC->CRH   |=  ( 0x2 << GPIO_CRH_MODE13_Pos );
 * 
 */