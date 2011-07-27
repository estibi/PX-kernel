// lib/utils.c

#include <px/io.h>
#include <px/utils.h>

void delay(unsigned long count)
{
	unsigned long i;
        for(i = 0; i < count; i++) {}
}


void machine_restart()
{

        for(;;) {
		inb(0x64);
		inb(0x60);
                outb(0xfe, 0x64);	// reset lini
        }
}

void machine_halt()
{
}
