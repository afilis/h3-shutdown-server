#include "shutdown.h"
#include "io.h"
#include "consts.h"


/**
 * @brief   system shutdown
 * @retval  none
 */
void shutdown()
{
        int cpu;

        // shotdown CPU
        for (cpu = 0; cpu < 4; cpu++)
        {
                // reset CPUx
                writel(0, R_CPUCFG_RST_CPU_BASE + 0x40 * cpu);

                // lock CPUx
		clr_bit(cpu, R_CPUCFG_DBG_CTRL1);

                // poweroff CPUx
                set_bit(cpu, R_PRCM_CPU_PWROFF);
                writel(0xff, R_PRCM_CPU_PWR_CLAMP + 0x4 * cpu); // no effect
                                                                // if cpu = 0
                // unlock CPUx
                set_bit(cpu, R_CPUCFG_DBG_CTRL1);
        }

        // shutdown GPU
        set_bit(0, R_PRCM_GPU_PWROFF);

        // shutdown VDD
        writel(0x7, R_PRCM_VDD_SYS_PWROFF);
}
