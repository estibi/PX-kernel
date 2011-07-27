#ifndef _kbd_scancodes_H
#define _kbd_scancodes_H

char _kbd_scan_released_escape	0x81;
char _kbd_scan_released_1	0x82;
char _kbd_scan_released_2	0x83;
char _kbd_scan_released_3	0x84;
char _kbd_scan_released_4	0x85;
char _kbd_scan_released_5	0x86;
char _kbd_scan_released_6	0x87;
char _kbd_scan_released_7	0x88;
char _kbd_scan_released_8	0x89;
char _kbd_scan_released_9	0x8a;
char _kbd_scan_released_0	0x8b;
char _kbd_scan_released_sub	0x8c; // -
char _kbd_scan_released_equal	0x8d; // =
char _kbd_scan_released_bspace	0x8e;
char _kbd_scan_released_tab	0x8f;
char _kbd_scan_released_q	0x90;
char _kbd_scan_released_w	0x91;
char _kbd_scan_released_e	0x92;
char _kbd_scan_released_r	0x93;
char _kbd_scan_released_t	0x94;
char _kbd_scan_released_y	0x95;
char _kbd_scan_released_u	0x96;
char _kbd_scan_released_i	0x97;
char _kbd_scan_released_o	0x98;
char _kbd_scan_released_p	0x99;
char _kbd_scan_released_[	0x9a;
char _kbd_scan_released_]	0x9b;
char _kbd_scan_released_enter	0x9c;
char _kbd_scan_released_ctrl	0x9d;
char _kbd_scan_released_a	0x9e;
char _kbd_scan_released_s	0x9f;
char _kbd_scan_released_d	0xa0;
char _kbd_scan_released_f	0xa1;
char _kbd_scan_released_g	0xa2;
char _kbd_scan_released_h	0xa3;
char _kbd_scan_released_j	0xa4;
char _kbd_scan_released_k	0xa5;
char _kbd_scan_released_l	0xa6;
char _kbd_scan_released_semicolon 0xa7; // ;
char _kbd_scan_released_inverted 0xa8; // '
char _kbd_scan_released_inv_tild 0xa9; // `
char _kbd_scan_released_lshift	0xaa;

char _kbd_scan_released_z	0xac;
char _kbd_scan_released_x	0xad;
char _kbd_scan_released_c	0xae;
char _kbd_scan_released_v	0xaf;
char _kbd_scan_released_b	0xb0;
char _kbd_scan_released_n	0xb1;
char _kbd_scan_released_m	0xb2;
char _kbd_scan_released_coma	0xb3; // ,
char _kbd_scan_released_point	0xb4; // .
char _kbd_scan_released_slash	0xb5; // /
char _kbd_scan_released_rshift	0xb6;
char _kbd_scan_released_prscr	0xb7;
char _kbd_scan_released_lalt	0xb8;
char _kbd_scan_released_space	0xb9;
char _kbd_scan_released_capslock 0xba;
char _kbd_scan_released_F1	0xbb;
char _kbd_scan_released_F2	0xbc;
char _kbd_scan_released_F3	0xbd;
char _kbd_scan_released_F4	0xbe;
char _kbd_scan_released_F5	0xbf;
char _kbd_scan_released_F6	0xc0;
char _kbd_scan_released_F7	0xc1;
char _kbd_scan_released_F8	0xc2;
char _kbd_scan_released_F9	0xc3;
char _kbd_scan_released_F10	0xc4;
char _kbd_scan_released_pause	0xc5;
char _kbd_scan_released_numlock	0xc5;
char _kbd_scan_released_scrlock	0xc6;
char _kbd_scan_released_home	0xc7;
char _kbd_scan_released_up	0xc8;
char _kbd_scan_released_pageup	0xc9;
char _kbd_scan_released_num_sub	0xca;
char _kbd_scan_released_left	0xcb;
char _kbd_scan_released_num_5	0xcc;
char _kbd_scan_released_right	0xcd;
char _kbd_scan_released_num_add	0xce;
char _kbd_scan_released_end	0xcf;
char _kbd_scan_released_down	0xd0;


/* TODO complete this
char _kbd_scan_hold_escape	0x81;
char _kbd_scan_hold_1	0x82;
char _kbd_scan_hold_2	0x83;
char _kbd_scan_hold_3	0x84;
char _kbd_scan_hold_4	0x85;
char _kbd_scan_hold_5	0x86;
char _kbd_scan_hold_6	0x87;
char _kbd_scan_hold_7	0x88;
char _kbd_scan_hold_8	0x89;
char _kbd_scan_hold_9	0x8a;
char _kbd_scan_hold_0	0x8b;
char _kbd_scan_hold_sub	0x8c; // -
char _kbd_scan_hold_equal	0x8d; // =
char _kbd_scan_hold_bspace	0x8e;
char _kbd_scan_hold_tab	0x8f;
char _kbd_scan_hold_q	0x90;
char _kbd_scan_hold_w	0x91;
char _kbd_scan_hold_e	0x92;
char _kbd_scan_hold_r	0x93;
char _kbd_scan_hold_t	0x94;
char _kbd_scan_hold_y	0x95;
char _kbd_scan_hold_u	0x96;
char _kbd_scan_hold_i	0x97;
char _kbd_scan_hold_o	0x98;
char _kbd_scan_hold_p	0x99;
char _kbd_scan_hold_[	0x9a;
char _kbd_scan_hold_]	0x9b;
char _kbd_scan_hold_enter	0x9c;
char _kbd_scan_hold_ctrl	0x9d;
char _kbd_scan_hold_a	0x9e;
char _kbd_scan_hold_s	0x9f;
char _kbd_scan_hold_d	0xa0;
char _kbd_scan_hold_f	0xa1;
char _kbd_scan_hold_g	0xa2;
char _kbd_scan_hold_h	0xa3;
char _kbd_scan_hold_j	0xa4;
char _kbd_scan_hold_k	0xa5;
char _kbd_scan_hold_l	0xa6;
char _kbd_scan_hold_semicolon 0xa7; // ;
char _kbd_scan_hold_inverted 0xa8; // '
char _kbd_scan_hold_inv_tild 0xa9; // `
char _kbd_scan_hold_lshift	0xaa;

char _kbd_scan_hold_z	0xac;
char _kbd_scan_hold_x	0xad;
char _kbd_scan_hold_c	0xae;
char _kbd_scan_hold_v	0xaf;
char _kbd_scan_hold_b	0xb0;
char _kbd_scan_hold_n	0xb1;
char _kbd_scan_hold_m	0xb2;
char _kbd_scan_hold_coma	0xb3; // ,
char _kbd_scan_hold_point	0xb4; // .
char _kbd_scan_hold_slash	0xb5; // /
char _kbd_scan_hold_rshift	0xb6;
char _kbd_scan_hold_prscr	0xb7;
char _kbd_scan_hold_lalt	0xb8;
char _kbd_scan_hold_space	0xb9;
char _kbd_scan_hold_capslock 0xba;
char _kbd_scan_hold_F1	0xbb;
char _kbd_scan_hold_F2	0xbc;
char _kbd_scan_hold_F3	0xbd;
char _kbd_scan_hold_F4	0xbe;
char _kbd_scan_hold_F5	0xbf;
char _kbd_scan_hold_F6	0xc0;
char _kbd_scan_hold_F7	0xc1;
char _kbd_scan_hold_F8	0xc2;
char _kbd_scan_hold_F9	0xc3;
char _kbd_scan_hold_F10	0xc4;

char _kbd_scan_hold_pause	0xc5;
char _kbd_scan_hold_numlock	0xc5;

char _kbd_scan_hold_scrlock	0xc6;
char _kbd_scan_hold_home	0xc7;
char _kbd_scan_hold_up	0xc8;
char _kbd_scan_hold_pageup	0xc9;
char _kbd_scan_hold_num_sub	0xca;
char _kbd_scan_hold_left	0xcb;
char _kbd_scan_hold_num_5	0xcc;
char _kbd_scan_hold_right	0xcd;
char _kbd_scan_hold_num_add	0xce;
char _kbd_scan_hold_end	0xcf;
char _kbd_scan_hold_down	0xd0;

*/

#endif
