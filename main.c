/**
 * @file        main.c
 *
 * @mainpage    CNC firmware for the Allwinner H3 ARISC co-processor
 *
 * The firmware uses by Orange Pi boards to help the
 *      <a href="http://linuxcnc.org">LinuxCNC</a>
 * and
 *      <a href="http://machinekit.io">Machinekit</a>
 * make a real-time @b GPIO manipulations.
 *
 * http://github.com/orangecnc/h3_arisc_firmware
 *
 */

#include "sys.h"
#include "mod_msg.h"
#include "mod_shutdown.h"
#include "consts.h"




int main(void)
{
    // startup settings
    enable_caches();
    clk_set_rate(CPU_FREQ);

    // modules init
    msg_module_init();
    shutdown_module_init();

    // main loop
    for(;;)
    {
        msg_module_base_thread();
        shutdown_module_base_thread();
    }

    return 0;
}
