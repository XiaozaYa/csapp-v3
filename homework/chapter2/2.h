#ifndef __CSAPP_2_H__
#define __CSAPP_2_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define union_x_y(x, y) ((x&0xff)|(y&(~0xff)))
void show_bytes(const unsigned char*, int32_t);
int is_little_endian();
unsigned replace_byte(unsigned, int, unsigned char);
int func_2_61(int);
int int_shifts_are_arithmetic();
unsigned srl(unsigned, int);
int sra(int, int);
int any_odd_one(unsigned);
int odd_ones(unsigned);
int leftmost_one(unsigned);
int bad_int_size_is_32();
int lower_one_mask(int);
unsigned rotate_left(unsigned, int);
int fits_bits(int, int);
int xbyte(unsigned, int);
int saturating_add(int, int);
int tsub_ok(int, int);
int divide_power2(int, int);
int mul3div4(int);
int tfs(int);

#endif
