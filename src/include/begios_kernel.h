
#include <begios_module.h>
#include <begios_scheduler.h>


typedef struct {
    uint32_t DID;
    void *datatype;
} __begios_drivers_entry;

struct __begios_drivers {
    __begios_drivers_entry *entry;
    void *next;
}

void register_module(begios_mod_typedef* __drv_ref);
void unregister_module(begios_mod_typedef* __drv_ref);
void get_modules_lost();
void start();