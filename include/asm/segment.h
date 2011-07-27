// include/segment.h

#ifndef _SEGMENT_H
#define _SEGMENT_H

//static unsigned char __PX_KERNEL_CS = 0x10;
//static unsigned char __PX_KERNEL_DS = 0x18;
#define __PX_KERNEL_CS  0x10
#define __PX_KERNEL_DS  0x18



// W zalozeniu:	text jadra: od 0x00100000 do 0x001fffff
//		stos jadra: od 0x00200000 do 0x002ffffe

//static unsigned long __PX_KERNEL_ESP	  =   0x002ffffe; // esp = 3MB -2B
//static unsigned long __PX_KERNEL_OFFSET	  =   0x00100000; // 1MB
#define  __PX_KERNEL_ESP	0x002ffffe // esp = 3MB -2B
#define  __PX_KERNEL_OFFSET	0x00100000 // 1MB

#endif
