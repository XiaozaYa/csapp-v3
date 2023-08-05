#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
int func1(unsigned);
int func2(unsigned);
int main()
{
	int i = 0;
	unsigned int a = 0;
	for (;i < 4; i++)
	{
		scanf("%x", &a);
		printf("unsigned int a = %X\nfunc1(a) = %X\nfunc2(a) = %X\n", a, func1(a), func2(a));
	}
	printf("%d %d\n", -5/2, (-5+(1<<1)-1)>>1);
	printf("%d\n", INT_MIN>0||INT_MIN-1<0);
	int j = 0;
	float x = 8.25;
	char *p = (char*)&x;
	printf("%.2f = ", x);
	for (j = 0; j < 4; j++)
	{
		printf("%.2x", *p++);
	}		
	double d = 0xEfE1000000000000;
	if (d*d >= 0.0) printf("\n%lf >= \n", d);
	short sx = -12345;
	unsigned int usx = sx;
	printf("sx = %x; usx = %x\n", sx, usx);	
	int m = INT_MIN;
	int n = -INT_MIN;
	int s = m + n;
	printf("m = %d, n = %d, s = %d\ns - m  = %d, s - n = %d\n", m, n, s, s-m, s-n);
	return 0;
}

int func1(unsigned word) { return (int)((word << 24) >> 24); }
int func2(unsigned word) { return (((int)word << 24) >> 24); }
