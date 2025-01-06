#pragma once

#include <begonios_module.h>

extern begios_drv_typedef* __gd_gpio_drv_ref;

typedef struct
{
  uint32_t CRL = 0x00;
  uint32_t CRH = 0x04;
  uint32_t IDR = 0x08;
  uint32_t ODR = 0x0c;
  uint32_t BSRR = 0x10;
  uint32_t BRR = 0x14;
  uint32_t LCKR = 0x18;
} gd_gpio_typedef; 

extern gd_gpio_typedef* __gd_gpio_hal;

void _gd_gpio_init(uint32_t base_address);
void _gd_gpio_open();
void _gd_gpio_close();
void _gd_gpio_reset();
void _gd_gpio_irq_handler(uint32_t irq_id);
uint32_t* _gd_gpio_read(uint32_t reg, uint32_t data);
void _gd_gpio_write(uint32_t reg, uint32_t data);