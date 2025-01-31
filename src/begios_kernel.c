/**
  ____                         _  ____   _____ 
 |  _ \                       (_)/ __ \ / ____|
 | |_) | ___  __ _  ___  _ __  _| |  | | (___  
 |  _ < / _ \/ _` |/ _ \| '_ \| | |  | |\___ \ 
 | |_) |  __| (_| | (_) | | | | | |__| |____) |
 |____/ \___|\__, |\___/|_| |_|_|\____/|_____/ 
              __/ |                            
             |___/                             
 @file begios_uart.c
 @author Rafael Macieira <rfamm01@protonmail.com>
 */

#include <begios_kernel.h>



void __begios_start(void (*add_handler)(uint32_t irq_vetor_pos, void (*handler)())){
  while(1);  
}
