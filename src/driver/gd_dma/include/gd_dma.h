#include <begonios_module.h>

typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
} gd_dma_hal_typeDef;

typedef struct
{
  volatile uint32_t CCR;
  volatile uint32_t CNDTR;
  volatile uint32_t CPAR;
  volatile uint32_t CMAR;
} gd_dma_channel_hal_typedef;

begios_drv_typedef* __dma_drv_ref;

void _gd_dma_init();
void _gd_dma_open();
void _gd_dma_close();
void _gd_dma_reset();
void _gd_dma_irq_handler();