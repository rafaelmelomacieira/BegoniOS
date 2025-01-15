#pragma once

#include <begonios_module.h>

extern begios_mod_typedef* __ns16550_uart_drv_ref;

typedef struct
{
  volatile uint32_t RHR_THR;
  volatile uint32_t IER;
  volatile uint32_t ISR;
  volatile uint32_t FCR;
  volatile uint32_t LCR;
  volatile uint32_t MCR;
  volatile uint32_t LSR;
  volatile uint32_t MSR;
  volatile uint32_t SPR;
} ns16550_uart_hal_typedef; 

extern ns16550_uart_hal_typedef* __gd_gpio_hal;

void ns16550_uart_init(uint32_t base_address);
void ns16550_uart_open();
void ns16550_uart_close();
void ns16550_uart_reset();
void ns16550_uart_irq_handler(uint32_t irq_id);
uint32_t ns16550_uart_read(uint32_t* reg);
void ns16550_uart_write(uint32_t* reg, uint32_t data);