// include/boot.h

#ifndef _BOOT_H
#define _BOOT_H

// segment, gdzie kopiowany jest obraz jadra z dyskietki
#define __PX_16_SEG 0x1000

// offset, gdzie znajduje sie 32 bitowy kod
// adres 32 kodu __PX_16_SEG:__PX_32_OFF
#define __PX_32_OFF 0x0800



#endif
