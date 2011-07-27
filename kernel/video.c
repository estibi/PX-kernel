// kernel/video.c

#include <px/video.h>

static unsigned long _cur_h_pos = _min_h_pos;	// bierzaca pozioma linia
static unsigned long _cur_v_pos = _min_v_pos;	// bierzaca pionowa linia

int printk(char * str)
{
	char zn;
	for(; (zn = *str) != 0x00 ; str++) {
		switch(zn)
		{
			case _next_line_asc:
			{
				unsigned long x = _min_h_pos;
				unsigned long y = con_get_v_pos();
                                if(y >= _max_v_pos) { return -1; }
                                y++;
				con_set_pos(x, y);
				break;
			}
			default:
			{
				putc(zn);
				break;
			}
		}
	}
        return 1;
}


// FIXME
void  show_bin_32(unsigned long ul)
{
	unsigned long tmp_ul = ul;
        ul >>= 16;
        ul &= 0x0000ffff;
        show_bin_16((unsigned short) tmp_ul);
        tmp_ul = ul;
        ul >>= 16;
        show_bin_16((unsigned short) tmp_ul);
}



// FIXME
void  show_bin_16(unsigned short us)
{
	unsigned short tmp_us = us;
        us >>= 8;
        us &= 0x00ff;
        show_bin_8((char) tmp_us);
        tmp_us = us;
        us >>= 8;
        show_bin_8((char) tmp_us);
}



void  show_bin_8(char ch)
{
	char tmp_ch;
        unsigned short shift;
        for(shift = 8; shift > 0; shift--) {
		tmp_ch = ch;
                tmp_ch >>= shift - 1;
                tmp_ch &= 0x01;		// the lowest bit = 1
                if(tmp_ch == 0x01) {
                	putc('1');
                } else putc('0');
	}
}


void  show_hex_8(char value)
{
	char hextbl[] = "0123456789abcdef";

	char * hextbl_off;
	char tmp_value = value;
        tmp_value >>= 4;
        tmp_value &= 0x0f;

	hextbl_off = & hextbl[0] + tmp_value;
        putc(*hextbl_off);

        tmp_value = value;
        tmp_value &= 0x0f;

	hextbl_off = & hextbl[0] + tmp_value;
        putc(*hextbl_off);
}



void  show_32u(unsigned long liczba)
{
	char hextbl[] = "0123456789abcdef";

	unsigned long tmp;
	unsigned long maska = 0x0000000f;
	void * ptr;
	unsigned short ile_przesunac = 28;
	unsigned short i = 0;
	unsigned long * ptr_long;
	unsigned long n;

	for(;i < 8; i++){
		tmp = liczba;
		tmp >>= ile_przesunac;
		tmp &= maska;
		ptr = & hextbl;

		ptr += tmp;
		ptr_long = (long *) ptr;
		n = * ptr_long;
		n &= 0x000000ff;
		char zn = (char) n;
		putc(zn);
		ile_przesunac -= 4;
	}
}


unsigned long con_get_cur_fb_off()
{
	unsigned long current_fb_offset = _con_fb_base;
        current_fb_offset += ((con_get_v_pos() - 1) * (_max_h_pos * 2));
        current_fb_offset += (con_get_h_pos() - 1) * 2;

        return current_fb_offset;
}



int putc(char znak)
{
	unsigned long miejsce, tmp;
	unsigned short * ptr;
	unsigned short lzn = znak;
	lzn |= (_def_char_attr << 8);

	if ((con_get_h_pos() < _max_h_pos) && \
        			(con_get_v_pos() < _max_v_pos)) {
		miejsce = con_get_cur_fb_off();

		ptr = (unsigned short *) miejsce;
		* ptr = lzn;
                tmp = con_get_h_pos();
                tmp++;
                con_set_h_pos(tmp);
	}

	if ((con_get_v_pos() < _max_v_pos) && \
        			(con_get_h_pos() == _max_h_pos)) {
		con_set_h_pos(_min_h_pos);
                tmp = con_get_v_pos();
                tmp++;
                con_set_v_pos(tmp);

                miejsce = con_get_cur_fb_off();

		ptr = (unsigned short *) miejsce;
		* ptr = lzn;
	}
        return 1;
}

unsigned long con_get_v_pos(void)
{
	return _cur_v_pos;
}



unsigned long con_get_h_pos(void)
{
	return _cur_h_pos;
}




int con_set_h_pos(unsigned long value)
{
	if(value > _max_h_pos || value < _min_h_pos) { return -1; }
	_cur_h_pos = value;
        return 1;
}



int con_set_v_pos(unsigned long value)
{
	if(value > _max_v_pos || value < _min_v_pos) { return -1; }
	_cur_v_pos = value;
        return 1;
}






int con_set_pos(unsigned long x, unsigned long y)
{
	if((x > _max_h_pos) || (x < _min_h_pos) || \
	   (y > _max_v_pos) || (y < _min_v_pos)) {
		return -1;
	}

	_cur_h_pos = x;
	_cur_v_pos = y;

	return 1;
}


int clean_console()
{
	unsigned long i = _max_h_pos * _max_v_pos;

        if(con_set_pos(_min_h_pos, _min_v_pos)) {
		for(; i > 0 ; i--) {
			putc(' ');
		}
	} else return -1;
        return 1;
}
