#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include "2.h"

void show_bytes(const unsigned char* p, int32_t len)
{
	int32_t i = 0;
	for (;i < len; i++, p++)
		printf("%.2x ", *p);
	printf("\n");
}

// 2-58
int is_little_endian()
{
	union X {
		int a;
		char ch;
	};
	union X x;
	x.a = 1;
	return (int)x.ch;
}

// 2-60
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
	return ((unsigned int)b<<(i<<3))|(x&~(0xff<<(i<<3)));
}


// 2-61
int func_2_61(int x)
{ return !~x || !x ||  !((x&0xff)^0xff) || !(x>>((sizeof(int)-1)<<3)); }

// 2-62
int int_shifts_are_arithmetic() { return ((1<<(sizeof(int)<<3-1))>>1) < 0; }

// 2-63
unsigned srl(unsigned x, int k)
{
	unsigned xsra = (int)x >> k;
	return xsra & ((1 << (sizeof(int)<<3-k)) - 1);
}

int sra(int x, int k)
{
	int xsrl = (unsigned)x >> k;
	// t = (!!((1 << sizeof(int)*8 - 1) & x)) = 0/1
	// (~((t << (sizeof(int)*8 - k)) - 1))
	return xsrl | (~(((!!((1 << sizeof(int)<<3 - 1) & x)) << (sizeof(int)<<3 - k)) - 1));
}

// 2-64
int any_odd_one(unsigned x)
{
	//10101010 10101010 10101010 10101010
	// sizeof(unsigned) 0xAA 0xAAAA 0xAAAAAA
	return !!(x & 0xAAAAAAAA);
}

// 2-65
int odd_ones(unsigned x)
{
	//10101010 10101010 10101010 10101010
	//this method is right
	
	x ^= x >> 1;
	x ^= x >> 2;
	x ^= x >> 4;
	x ^= x >> 8;
	x ^= x >> 16;
	return x & 1;
	/*
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	return x & 1;
	*/
}

// 2-66
int leftmost_one(unsigned x)
{
	// 00001010 => 00001111 => 00000111 => 11111000 =>
	//00001111 & 
	//11111000 = 00001000
	/*
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	*/
	x |= x >> 16;
	x |= x >> 8;
	x |= x >> 4;
	x |= x >> 2;
	x |= x >> 1;
	//return x;
	return x & ~(x >> 1); 
}

// 2-67
int bad_int_size_is_32()
{
	int set_msb = 1 << 15;
	set_msb <<= 15;
	set_msb <<= 1;
	int beyond_msb = set_msb << 1;
	return set_msb && !beyond_msb;
}

// 2-68
// n [1, w]
int lower_one_mask(int n)
{
	return ~((~((1 << n-1)<<1)) + 1);
}

// 2-69
// n [0, w)
unsigned rotate_left(unsigned x, int n)
{
	// 0x12 34 56 78
	// 0001 0010 0011 0100
	// 0010 0011 0100 0000 |
	// 0000 0000 0000 0001
	return (x << n) | (x >> (sizeof(int)<<3 - n));
}

// 2-70
// n [1, w]
int fits_bits(int x, int n)
{
	// 0x3f 6 
	// 符号扩展
	// 0000 0 [010 0010 0010 0010 0000 0000 0000
	// 1111 111 [1 0010 0010 0010 0000 0000 0000
	//return ((!(!((x>>(sizeof(int)*8-1))+1)))&&(!(~((1<<(n-1))-1)&x)))||((!((x>>(sizeof(int)*8-1))+1))&&(!((((1<<(n-1))-1)|x)^-1)));
	return (!(~((1<<(n-1))-1)&x))||(!((((1<<(n-1))-1)|x)^-1));

}

// 2-71
int xbyte(unsigned word, int n)
{
	return (int)((word>>(n<<3))&0xFF)<<24>>24;
}

// 2-73
int saturating_add(int x, int y)
{
	int s = x + y;
	int n = (sizeof(int) << 3) - 1;
	int x_msb = x >> n;
	int y_msb = y >> n;
	int s_msb = s >> n;
	int pos_overflow = !x_msb && !y_msb && s_msb;
	int neg_overflow = x_msb && y_msb && !s_msb;	
	(pos_overflow && (s = INT_MAX)) || (neg_overflow && (s = INT_MIN));
	return s; 
}

// 2-74
int tsub_ok(int x, int y)
{
	int n = (sizeof(int) << 3) - 1;
	int s = x + y;
	int s_msb = s >> n;
	int x_msb = x >> n;
	int y_msb = !(y >> n);
	return (!x_msb && !y_msb && s_msb) || (x_msb && y_msb && !s_msb); 
}

// 2-78
// k [0, w-1)
int divide_power2(int x, int k)
{
	// x > 0 ==> x >> k
	// x < 0 ==> (x + (1<<k) - 1) >> k
	int sign = (unsigned)x>>((sizeof(int)<<3) - 1);
	int bias = (sign << k) - sign;
	return (x + bias) >> k;
}

// 2-79
int mul3div4(int x)
{
	// x*3/4 ==> x = ((x<<1)+x) k = 2
	return divide_power2(((x<<1)+x), 2);
}

// 2-80
int tfs(int x)
{
	return divide_power2(3, x<<2);
}
