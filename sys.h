#ifndef _SYS_H
#define _SYS_H

#include <stdint.h>


void enable_caches(void);
void reset(void);
void handle_exception(uint32_t type, uint32_t pc, uint32_t sp);
void clk_set_rate(uint32_t rate);


#endif
