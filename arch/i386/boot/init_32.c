// arch/i388/boot/init_32.c

// We are in protected mode.
// a20 on
// eip = 0x00100000

void __volatile__ init_32(void);

void __volatile__ init_32()
{
__asm__ __volatile__ (
	".text\n\t"
        ".code32\n\t"
        ".global _start\n\t"
	"_start:\n\t"

	"cli\n\t"
        "jmp	begin\n\t"
	"nop\n\t"

	".long 0x1BADB002\n\t"	// multiboot magic
	".long 0x00010003\n\t"	// flags
	".long 0xe4514ffb\n\t"	// checksum = (not(magic + flags)) + 1

	".long 0x00100004\n\t"	// addr_header
	".long 0x00100000\n\t"	// addr_load
	".long 0x00100000\n\t"	// addr_load_end
	".long 0x00100000\n\t"	// addr_bss_end
	".long 0x00100000\n\t"	// addr_entry

	".long 0x00000000\n\t"	// mode_type
	".long 0x00000000\n\t"	// width
	".long 0x00000000\n\t"	// height
	".long 0x00000000\n\t"	// depth

"begin:\n\t"

// load gdt

	"movl	$gdt, (adr_gdt)\n\t"
	"lgdt	ok_gdt\n\t"

// load null idt

	"lidt	ok_idt\n\t"


// initialize segments

        "movw	$0x18, %ax\n\t"		// __PX_KERNEL_DS
        "movw	%ax, %ds\n\t"
        "movw	%ax, %es\n\t"
        "movw	%ax, %fs\n\t"
        "movw	%ax, %gs\n\t"

        "movw	%ax, %ss\n\t"
        "movl	$0x002ffffe, %esp\n\t"	// __PX_KERNEL_ESP

// jmp to new_cs - update cs

        "movl	$new_cs, (off)\n\t"

	".byte 0xea\n\t"
"off:	.long 0x00000000\n\t"		// place for new_cs's address
	".word 0x0010\n\t"

"new_cs:\n\t"

// jmp to init_kernel(); in kernel/px_32.c

	"jmp	init_kernel\n\t"



// descriptor table
// Remember that cpu reads in reverse mode.
"gdt:\n\t"
// null
	".long	0x00000000, 0x00000000\n\t"
// unused
	".long	0x00000000, 0x00000000\n\t"
// kernel code
	".long	0x0000ffff, 0x00cf9a00\n\t"

//	0xffff	limit 1-4
//	0x0000	base 1-4
//	0x00	base 5-6
//	0x9a	1 0 0 1    1 0 1 0
//		A W E 0    1 DPL P
//		|   TYPE   |

//	0xcf	1 1 0 0    1 1 1 1
//		G B 0 A   |limit 5|
//		      V
//		      L

//	0x00	base 7-8

// kernel data
	".long	0x0000ffff, 0x00cf9200\n\t"

//	0x92	1 0 0 1    0 0 1 0
//		A W E 0    1 DPL P
//		|   TYPE   |


"ok_gdt:\n\t"	".word	0x001f\n\t"	// gdt limit
"adr_gdt:	.long	0x00000000\n\t"	// place for gdt's linear address

"ok_idt:\n\t"	".word	0x0000\n\t"	// idt limit = null
"adr_idt:	.long	0x00000000\n\t"	// null
	);

}
