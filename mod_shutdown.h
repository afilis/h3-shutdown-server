/**
 * @file    mod_shutdown.h
 *
 * @brief   shutdown module header
 *
 */

#ifndef _MOD_SHUTDOWN_H
#define _MOD_SHUTDOWN_H

#include "mod_timer.h"


#define WDT_TIMEOUT (TIMER_FREQUENCY * 10)  // 10s


/// messages types
enum
{
    SHUTDOWN_WDT_TOUCH = 0x40,
};


void shutdown_module_init();

void shutdown_module_base_thread();

#endif
