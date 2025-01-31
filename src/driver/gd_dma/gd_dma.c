#include <gd_dma.h>

begios_drv_typedef* _gd_dma_init(){
    __dma_drv_ref = (begios_drv_typedef*) malloc(sizeof(begios_drv_typedef));
    __dma_drv_ref->open = (void*)() _gd_dma_open;
}

void _gd_dma_open(){
    
}

void _gd_dma_close(){
    
}

void _gd_dma_reset(){

}

void _gd_dma_irq_handler(){

}