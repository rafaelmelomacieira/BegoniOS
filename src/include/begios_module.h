#pragma once

#include <stdint.h>

typedef struct
{
    char* name;
    int32_t addr;
    void (*irq_handler)(uint32_t irq_id);
    void (*open)();
    void (*close)();
    void (*reset)();
    int32_t (*read)(uint32_t* reg);
    void (*write)(uint32_t* reg, uint32_t data);
} begio_mod_typedef;