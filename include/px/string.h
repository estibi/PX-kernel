// include/string.h

#ifndef	_STRING_H
#define	_STRING_H

#include <px/types.h>

void * memcpy(void * dest, const void * src, size_t n);

/* Copy N bytes of SRC to DEST, guaranteeing
   correct behavior for overlapping strings.  */
void * memmove(void * dest, const void * src, size_t n);


/* Copy no more than N bytes of SRC to DEST, stopping when C is found.
   Return the position in DEST one byte past where C was copied,
   or NULL if C was not found in the first N bytes of SRC.  */
void * memccpy(void * dest, const void * src, int c, size_t n);


void * memset(void * s, int c, size_t n);

int memcmp(const void * s1, const void * s2, size_t __n);

void * memchr(const void * s, int c, size_t n);

void * rawmemchr (const void * s, int c);

void * memrchr (const void * s, int c, size_t n);

#endif
