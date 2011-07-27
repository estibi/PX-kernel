// kernel/px_32.c

#include <px/debug.h>
#include <px/io.h>
#include <px/utils.h>
#include <px/video.h>


void main_loop(void);
void init_kernel(void);

// Zostalismy wywolani przez arch/i386/boot/init_32.c
// init_kernel powinien zainicjowac wszystkie podsystemy
void init_kernel()
{
	clean_console();

	if(con_set_pos(_min_h_pos, _min_v_pos)){
		printk("px kernel\n");
	}

        show_regs();

        main_loop();			// z main_loop nie ma powrotu
        machine_halt();
}


void main_loop()
{
	for(;;)
	{
		con_set_pos(_con_min_h_pos, _con_min_v_pos);
        	printk("from port 0x60 = 0x");
		show_hex_8(inb(0x60));
                outb(0xf4, 0x64);
        	printk("\n");

//                delay(0x10000);
        }
}
