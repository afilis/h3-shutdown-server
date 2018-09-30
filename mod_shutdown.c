/**
 * @file    mod_shutdown.c
 *
 * @brief   CPU shutdown module
 */

#include "mod_msg.h"
#include "mod_timer.h"
#include "mod_shutdown.h"
#include "shutdown.h"
#include "consts.h"



// private vars

static uint8_t start_watch = 0;
static uint32_t tick = 0;

#ifdef DEBUG
struct debug_data_t
{
    uint32_t counter;		// current ticks count
    uint32_t need_to_stop;	// is set when time limit exceeded
};
#endif


static int8_t volatile shutdown_msg_recv(uint8_t type, uint8_t * msg, uint8_t length);


// public methods

/**
 * @brief   module init
 * @note    call this function only once before shutdown_module_base_thread()
 * @retval  none
 */
void shutdown_module_init()
{
    // start sys timer
    TIMER_START();

    // add message handler
    msg_recv_callback_add(SHUTDOWN_WDT_TOUCH, (msg_recv_func_t) shutdown_msg_recv);
}

/**
 * @brief   module base thread
 * @note    call this function in the main loop
 * @retval  none
 */
void shutdown_module_base_thread()
{
    if (start_watch)
    {
        // check timeout
        tick = TIMER_CNT_GET();
        if (tick > WDT_TIMEOUT)
        {
#ifndef DEBUG
            shutdown();
#endif
            start_watch = 0;
        }
    }
}



// private methods

/**
 * @brief   "message received" callback
 *
 * @note    this function will be called automatically
 *          when a new message will arrive for this module.
 *
 * @param   type    user defined message type (0..0xFF)
 * @param   msg     pointer to the message buffer
 * @param   length  the length of a message (0 .. MSG_LEN)
 *
 * @retval   0 (message read)
 * @retval  -1 (message not read)
 */
static int8_t volatile shutdown_msg_recv(uint8_t type, uint8_t * msg, uint8_t length)
{
#ifdef DEBUG
    struct debug_data_t out;
    out.counter = tick;
    out.need_to_stop = !start_watch;

    msg_send(type, (uint8_t*)&out, sizeof(out));
#endif

    if (!start_watch)
        start_watch = 1;

    TIMER_CNT_SET(0);
    return 0;
}
