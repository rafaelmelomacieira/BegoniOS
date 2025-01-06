#pragma once

#include <begonios_module.h>

extern begios_mod_typedef* __gd_gpio_drv_ref;

typedef struct
{
  volatile uint32_t CTL0;
  volatile uint32_t CTL1;
  volatile uint32_t ISTAT;
  volatile uint32_t OCTL;
  volatile uint32_t BOP;
  volatile uint32_t BC;
  volatile uint32_t LOCK;
} gd_gpio_hal_typedef; 

extern gd_gpio_hal_typedef* __gd_gpio_hal;

void _gd_gpio_init(uint32_t base_address);
void gd_gpio_open();
void gd_gpio_close();
void gd_gpio_reset();
void gd_gpio_irq_handler(uint32_t irq_id);
uint32_t gd_gpio_read(uint32_t* reg);
void gd_gpio_write(uint32_t* reg, uint32_t data);