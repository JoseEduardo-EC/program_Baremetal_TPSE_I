#include "soc_AM335x.h"
#include "hw_types.h"
#include "wdt.h"
#include "cm_per.h"
#include "pinmux.h"
#include "dir.h"
#include "button.h"

void _main(){
    disable_watchdog();

    set_cmp();

    set_PINMUX_GPIO();

    set_dir_OU(1, 21);
    set_dir_OU(1, 22);
    set_dir_OU(1, 23);
    set_dir_OU(1, 24);
    set_dir_OU(2, 7);

    set_dir_IN(1, 17);
    set_dir_IN(1, 13);


    while(1){
        if(flag_ordem == 0) GPIO_ordem0();
        if(flag_ordem == 1) GPIO_ordem1();
    }
}