// include/video.h

#ifndef _VIDEO_H
#define _VIDEO_H

#define _con_fb_base	0x000b8000

#define _con_min_h_pos	1
#define _con_max_h_pos	80

#define _con_min_v_pos	1
#define _con_max_v_pos	25

// deprecated
#define _min_h_pos	1	
#define _max_h_pos	80		
#define _min_v_pos	1
#define _max_v_pos	25


#define _next_line_asc	0x0a
#define _def_char_attr	0x07

unsigned long con_get_h_pos(void);
unsigned long con_get_v_pos(void);

int con_set_pos(unsigned long x, unsigned long y);

int con_set_h_pos(unsigned long x);
int con_set_v_pos(unsigned long y);

int clean_console(void);

int putc(char);
int printk(char * str);

void show_32u(unsigned long value);	// deprecated
void show_hex_8(char ch);

void show_bin_8(char ch);
void show_bin_16(unsigned short us);
void show_bin_32(unsigned long ul);

unsigned long con_get_cur_fb_off(void);

#endif
