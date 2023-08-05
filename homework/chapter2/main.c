#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include "2.h"
void test_2_63();
int main(int argc, char** argv)
{
	// 2-55
	//float a = 8.25;
	printf("problem 2.55\n");
	double a255 = 8.25;
	show_bytes((unsigned char*)&a255, sizeof(a255));	
	printf("-------------------------\n");

	// 2-58	
	printf("problem 2.58\n");
	if (is_little_endian()) printf("little endian\n");
	else printf("big endian\n");
	printf("-------------------------\n");	
	
	// 2-59
	printf("problem 2.59\n");
	printf("%X\n", union_x_y(0x89ABCDEF, 0x76543210));
	printf("-------------------------\n");

	// 2-60
	printf("problem 2.60\n");
	printf("%X %X\n", replace_byte(0x12345678, 2, 0xAB), replace_byte(0x12345678, 0, 0xAB));
	printf("-------------------------\n");	

	// 2-61
	printf("problem 2.61\n");
	int a261 = func_2_61(-1);
	int b261 = func_2_61(0);
	int c261 = func_2_61(0x123ff);
	int d261 = func_2_61(0x12);
	int e261 = func_2_61(0x11111111);
	printf("%d %d %d %d %d\n", a261, b261, c261, d261, e261);
	printf("-------------------------\n");	

	// 2-62
	printf("problem 2.62\n");
	printf("%d\n", int_shifts_are_arithmetic());
	printf("-------------------------\n");		

	// 2-63
	printf("problem 2.63\n");
	test_2_63();
	printf("-------------------------\n");

	// 2-64/65
        printf("problem 2.64/65\n");
        int a264 = 1;
	printf("%x: %d %d\n", a264, any_odd_one(a264), odd_ones(a264));
        printf("-------------------------\n");

	// 2-66
	printf("problem 2.66\n");
	int a266 = 0xFF000000, b266 = 0x6600;
	printf("%X -> %X, %X -> %X\n", a266, leftmost_one(a266), b266, leftmost_one(b266));
	printf("-------------------------\n");
	
	// 2-67
	printf("problem 2.67\n");
	printf("%d\n", bad_int_size_is_32());
	printf("-------------------------\n");
	
	// 2-68
	printf("problem 2.68\n");
	printf("n = %d --> %X, n = %d --> %X\n", 6, lower_one_mask(6), 17, lower_one_mask(17));
	printf("n = %d --> %X, n = %d --> %X\n", 1, lower_one_mask(1), 32, lower_one_mask(32));
	printf("-------------------------\n");

	// 2-69
	printf("problem 2.69\n");
	int x269 = 0x12345678;
	printf("x = %X\nn=%d -> %X, n=%d -> %X\n", x269, 4, rotate_left(x269, 4), 20, rotate_left(x269, 20));
	printf("n=%d -> %X, n=%d -> %X\n", 0, rotate_left(x269, 0), 5, rotate_left(x269, 5));
	printf("-------------------------\n");
	
	// 2-70
	printf("problem 2.70\n");
	int x270 = 0x1234;
	int y270 = 0xFF012345; // 1111 111  	1 0000 0001 0010 0011 0100 0101
	printf("%X:%d=%d, %d=%d, %d=%d\n", x270, 14, fits_bits(x270, 14), 13, fits_bits(x270, 13), 12, fits_bits(x270, 12));
	printf("%X:%d=%d, %d=%d, %d=%d\n", y270, 25, fits_bits(y270, 25), 16, fits_bits(y270, 24), 23, fits_bits(y270, 23));
	printf("-------------------------\n");
	
	// 2-71
	printf("problem 2.71\n");
	unsigned n271 = 0xF2A82000;
	printf("%X:%X, %X, %X, %X\n", n271, xbyte(n271, 0), xbyte(n271, 1), xbyte(n271, 2), xbyte(n271, 3));
	printf("-------------------------\n");

	// 2-73
	printf("problem 2.73\n");
	printf("%X %X %X\n", saturating_add(1,1), saturating_add(-1,INT_MIN), saturating_add(1,INT_MAX));
	printf("-------------------------\n");

	// 2-74
	printf("problem 2.74\n");
	printf("%d %d %d %d\n", tsub_ok(2,2), tsub_ok(1,2), tsub_ok(1,INT_MIN), tsub_ok(-1,INT_MAX));	
	printf("-------------------------\n");
	
	// 2-75
	printf("problem 2.75\n");
	printf("Sorry I can't solve it\n");
	printf("-------------------------\n");

	// 2-76
	printf("problem 2.76\n");
	printf("Note the malloc argv2 is size_t so nmemb*size probably overflow\n");
	printf("-------------------------\n");

	// 2-77
	printf("problem 2.77\n");	
	printf("K=17   ==> (x<<4) + (x<<1)\n");
	printf("K=-7   ==> x - (x<<3)\n");
	printf("K=60   ==> (x<<6) - (x<<2)\n");
	printf("k=-112 ==> -((x<<4) + (x<<5) + (x<<6))\n");
	printf("-------------------------\n");

	// 2-78
	printf("problem 2.78\n");
	printf("%d %d\n", divide_power2(-13, 2), divide_power2(128, 4));	
	printf("-------------------------\n");
	
	// 2-79
        printf("problem 2.79\n");
        printf("%d %d\n", mul3div4(-5), mul3div4(5));
        printf("-------------------------\n");

	// 2-80
	printf("problem 2.80 no test\n");
	printf("-------------------------\n");

	// 2-81
	printf("problem 2.81\n");
	/*
	A: ~((1<<k)-1)
	B: (~((1<<j)-1)) & ((1<<(j+k))-1)
	*/
	printf("See the notes for the answer\n");
	printf("A: if k = 8 ==> %X\n",  ~((1<<8)-1));	
	printf("B: if j = k = 8 ==> %X\n",  (~((1<<8)-1)) & ((1<<(8+8))-1));
	printf("-------------------------\n");

	// 2-82
	printf("problem 2.82\n");
	/*
	A:no  if x = TMIN
	B:i think is yes, but i am not sure.becasue 2's complement add is a abelian group 
	C:i think is yes, because:
		-x = ~x+1 ==> ~x = -x-1
		so ~x+~y+1 = -x-1-y-1+1=-x-y-1
		~(x+y) = -(x+y)-1 = -x-y-1
	but it is no, for example: ~(1100) + ~(1100) != ~(11000)
	D:yes, because bit pattern is identical
	E:yes, because arithmetic shift and rounding
	*/
	printf("See the notes for the answer\n");
	printf("-------------------------\n");

	// 2-84
	printf("problem 2.84\n");
	/*
	return 
	!((ux<<1)^0) && !((uy<<1)^0) || // +0 vs -0
	sx&&sy&&(ux<=uy) || // - vs -
	!sx&&!sy&&(ux>=uy) || // + vs +
	!sx&&sy;   // - vs +
	*/
	printf("See the notes for the answer\n");
        printf("-------------------------\n");

	printf("i am sorry, the floating-point questions to be updated soon\n");
	
	return 0;
}

void test_2_63()
{
	int i = 0;
        int x, k, n = 0;
	for (;i < n; i++)
        {
                printf("enter hex x:");
                scanf("%x", &x);
                printf("enter shift k:");
                scanf("%d", &k);
                printf("func: srl %X, sra %X\n", srl(x, k), sra(x, k));
		printf("right: srl %X, sra %X\n", (unsigned)x>>k, (int)x>>k);
        }
}



