#include <stdio.h>

#define TALLA 11

void procedimiento(int *am, int b[])
{
	printf ("%22d %6d\n", *am, b[0]);
	printf ("%22d %6d\n", am[0], *b);
}

int main(void)
{
	int x[TALLA], i, y =10;
	for (i=0; i<TALLA; i++) x[i] = i+1;
	printf("1) procedimiento(   &y,     x):\n");
	procedimiento(&y, x);
	printf("Y Direccion: %u || Direccion: %u \n",(int) &y, (int)&x[0]);

	printf("2) procedimiento(    x,    &y):\n");
	procedimiento(x, &y);
	printf("3) procedimiento(&x[0], &x[1]):\n");
	procedimiento(&x[0], &x[1]);
}



