#include <stdio.h>
#include <limits.h>
int bis(int x, int m);
int bic(int x, int m);
int bool_or(int, int);
int bool_xor(int, int);
int func1(unsigned);
int func2(unsigned);
int is_equal(int, int);
int uadd_ok(unsigned, unsigned);
int div16(int);
int main()
{
	
	// 2-12
	/*
	int x;
	scanf("%x", &x);
	int x0 = x & 0xff;
	int x1 = ~(x | 0xff) | x & 0xff;
	int x2 = x | 0xff; 
	printf("x = %X\nx0 = %X\nx1 = %X\nx2 = %X\n", x, x0, x1, x2);
	*/
	
	// 2-13
	/*
	int x = 123513;
	int y = 6549813;
	printf("x = %x, y = %x\nx | y = %x\nx ^ y = %x\n", x, y, bool_or(x, y), bool_xor(x, y));
	printf("x | y = %x\nx ^ y = %x\n", x | y, x ^ y);
	*/
	
	// 2-15
	//printf("%d %d\n", is_equal(1, 1), is_equal(1, 0));
	
	// 2-23
	int i = 0;
	int x;
	for (;i < 4; i++)
	{
		scanf("%x", &x);
		printf("x = %x, func1(x) = %x, func2(x) = %x\n", x, func1(x), func2(x));
	}

	// 2-27
	//printf("uadd is ok? %d\n", uadd_ok(0x80000000, 0x80000000));
	
	// 2-42
	/*
	int i;
	for (i = INT_MIN; i < INT_MAX; i++)
		if (div16(i) != i/16)
			printf("Error\n");
	printf("Over\n");
	*/
	return 0;
}

int bis(int x, int m) { return x | m; }
int bic(int x, int m) { return x & ~m; }

int bool_or(int x, int y) { return bis(x, y); }
int bool_xor(int x, int y) 
{ 
	// ~x == bic(-1, x)
	// x | y == bis(x, y)
	// x^y == ~(x|~y) | ~(~x|y) = x&~y | ~x&y
	 return bis(bic(x, y), bic(y, x));
	//return bis(bic(-1, bis(x, bic(-1, y))), bic(-1, bis(bic(-1, x), y)));
}

int is_equal(int x, int y) { return !(x ^ y); }
int func1(unsigned word) { return (int)((word << 24) >> 24); }
int func2(unsigned word) { return (((int)word << 24) >> 24); }
int uadd_ok(unsigned x, unsigned y) { return x + y >= x; }
int div16(int x) 
{
	return (x + (int)((unsigned)(x & (1 << 31)) >> 31 << 4) - (int)((unsigned)(x & (1 << 31)) >> 31)) >> 4;
}
