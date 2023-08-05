#include <stdio.h>
#include <limits.h>
int main()
{
	int h0, h1, h2, h3, h4, x;
	x = ;
        printf("%X\n", x);
	int x_msb = x >> 31;
        x = (x&(~x_msb)) | (~x&x_msb);
	printf("%X\n", x);
        h0 = (!!(x >> 16)) << 4;
        x >>= h0;
	printf("%d %X\n", h0, x);
        h1 = (!!(x >> 8)) << 3;
        x >>= h1;
	printf("%d %X\n", h1, x);
        h2 = (!!(x >> 4)) << 2;
        x >>= h2;
	printf("%d %X\n", h1, x);
        h3 = (!!(x >> 2)) << 1;
        x >>= h3;
	printf("%d %X\n", h3, x);
        h4 = (!!(x >> 1)) << 1;
        x >>= h4;
	printf("%d %X\n", h4, x);
        printf("%d\n", h0+h1+h2+h3+h4+x+1);
	return 0;
}
