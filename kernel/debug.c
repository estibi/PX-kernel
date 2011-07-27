// kernel/debug.c

#include <px/debug.h>
#include <px/video.h>

void show_memory(unsigned long address, unsigned short ile)
{
	unsigned long * ptr_memory = (unsigned long *)address;
	unsigned short i, k;

	printk("memory:\n");

	for(i = 0; i < ile; i++){
		for(k = 0; k < 8; k++){
			show_32u(* ptr_memory);
			printk("  ");
			ptr_memory++;
		}
	}
}



void show_eax()
{
	unsigned long reg;
	printk("    eax 0x");
	reg = get_eax();
	show_32u(reg);
}


void show_ebx()
{
	unsigned long reg;
	printk("    ebx 0x");
	reg = get_ebx();
	show_32u(reg);
}

void show_ecx()
{
	unsigned long reg;
	printk("    ecx 0x");
	reg = get_ecx();
	show_32u(reg);
}

void show_edx()
{
	unsigned long reg;
	printk("    edx 0x");
	reg = get_edx();
	show_32u(reg);
}

void show_esi()
{
	unsigned long reg;
	printk("    esi 0x");
	reg = get_esi();
	show_32u(reg);
}

void show_edi()
{
	unsigned long reg;
	printk("    edi 0x");
	reg = get_edi();
	show_32u(reg);
}


void show_esp()
{
	unsigned long reg;
	printk("    esp 0x");
	reg = get_esp();
	show_32u(reg);
}

void show_ebp()
{
	unsigned long reg;
	printk("    ebp 0x");
	reg = get_ebp();
	show_32u(reg);
}


void show_cr0()
{
	unsigned long reg;
	printk("    cr0 0x");
	reg = get_cr0();
	show_32u(reg);
}


void show_cr1()					// cr1 jest zarezerwowany
{
	unsigned long reg;
	printk("    cr1 0x");
	reg = get_cr1();
	show_32u(reg);
}


void show_cr2()
{
	unsigned long reg;
	printk("    cr2 0x");
	reg = get_cr2();
	show_32u(reg);
}

void show_cr3()
{
	unsigned long reg;
	printk("    cr3 0x");
	reg = get_cr3();
	show_32u(reg);
}


void show_cr4()
{
	unsigned long reg;
	printk("    cr4 0x");
	reg = get_cr4();
	show_32u(reg);
}

void show_stack()
{
	unsigned long * ptr_stack = (unsigned long *) get_esp();
	unsigned short i;

	printk("stack: ");

	for(i = 0; i < 8; i++){
		show_32u(* ptr_stack);
		putc(' ');
		ptr_stack++;
	}
}



void show_regs()
{
	printk("\n");
	show_eax();
	show_ebx();
	show_ecx();
	show_edx();

	printk("\n");
	show_esp();
	show_ebp();
	show_esi();
	show_edi();

	printk("\n");
	show_cr0();
	show_cr2();
	show_cr3();
	show_cr4();

	printk("\n");
}

unsigned long get_cr0()
{
	unsigned long ret;
	__asm__("movl	%%cr0, %0"
                : "=a" (ret));
	return ret;
}

unsigned long get_cr1()				// cr1 jest zarezerwowany
{
	unsigned long ret;
	__asm__("movl	%%cr1, %0"
        	: "=a" (ret));
	return ret;
}

unsigned long get_cr2()
{
	unsigned long ret;
	__asm__("movl	%%cr2, %0"
        	: "=a" (ret));
	return ret;
}

unsigned long get_cr3()
{
	unsigned long ret;
	__asm__("movl	%%cr3, %0"
        	: "=a" (ret));
	return ret;
}

unsigned long get_cr4()
{
	unsigned long ret;
	__asm__("movl	%%cr4, %0"
        	: "=a" (ret));
	return ret;
}







unsigned long get_eax()
{
	unsigned long ret;
	__asm__("nop"
        	: "=a" (ret));
	return ret;
}


unsigned long get_ebx()
{
	unsigned long ret;
	__asm__("movl	%%ebx, %0"
        	: "=a" (ret));
	return ret;
}

unsigned long get_ecx()
{
	unsigned long ret;
	__asm__("movl	%%ecx, %0"
        	: "=a" (ret));
	return ret;
}

unsigned long get_edx()
{
	unsigned long ret;
	__asm__("movl	%%edx, %0"
        	: "=a" (ret));
	return ret;
}

unsigned long get_esi()
{
	unsigned long ret;
	__asm__("movl	%%esi, %0"
        	: "=a" (ret));
	return ret;
}


unsigned long get_edi()
{
	unsigned long ret;
	__asm__("movl	%%edi, %0"
        	: "=a" (ret));
	return ret;
}


unsigned long get_esp()
{
	unsigned long ret;
	__asm__("movl	%%esp, %0"
        	: "=a" (ret));
	return ret;
}


unsigned long get_ebp()
{
	unsigned long ret;
	__asm__("movl	%%ebp, %0"
        	: "=a" (ret));
	return ret;
}
