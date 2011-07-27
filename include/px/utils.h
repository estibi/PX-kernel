// include/px/utils.h

#ifndef _UTILS_H
#define _UTILS_H

#include <px/types.h>

void delay(unsigned long);
void machine_halt(void);
void machine_restart(void);

void * memcpy(void * dest, const void * src, size_t n);


#endif
