// include/debug.h

#ifndef _DEBUG_H
#define _DEBUG_H

unsigned long get_cr0(void);
unsigned long get_cr1(void);			// cr1 jest zarezerwowany
unsigned long get_cr2(void);
unsigned long get_cr3(void);
unsigned long get_cr4(void);

unsigned long get_eax(void);
unsigned long get_ebx(void);
unsigned long get_ecx(void);
unsigned long get_edx(void);
unsigned long get_esi(void);
unsigned long get_edi(void);
unsigned long get_esp(void);
unsigned long get_ebp(void);

void show_eax(void);
void show_ebx(void);
void show_ecx(void);
void show_edx(void);
void show_esi(void);
void show_edi(void);
void show_esp(void);
void show_ebp(void);

void show_cr0(void);
void show_cr1(void);				// cr1 jest zarezerwowany
void show_cr2(void);
void show_cr3(void);
void show_cr4(void);

void show_regs(void);
void show_stack(void);
void show_memory(unsigned long, unsigned short);

#endif
