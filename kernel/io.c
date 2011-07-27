// kernel/io.c

#include <px/io.h>

inline unsigned char inb(unsigned short port)
{
	unsigned char value;
	__asm__ __volatile__ ("inb	%1, %0\n\t"
        		: "=a"(value)
                        : "d" (port));
	return value;
}

inline void outb(unsigned short value, unsigned short port)
{
	__asm__ __volatile__ ("outb	%0, %1\n\t"
        		:
                        : "a" (value), "d" (port));
}
