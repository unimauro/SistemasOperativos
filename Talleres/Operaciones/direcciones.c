#include <stdio.h>
#define TALLA 11

int bits(unsigned int num)
{
	int b=0;
	do {
		b++;
		num/2;
	}while (num >0);
	printf("Direccion de una variable local %u \d",(unsigned int)&b);

	return b;
}

int main (void)
{
	float p[11];
	int i;
	
	for (i=0; i<=TALLA; i++)
	{
		printf("Direccion de p[%d] :  %u \n", i, (int)&p[i]);
	}

	//print("Direccion de una variable local %u \n",(unsigned int)&b);
	printf("Direccion de una funcion %u \n",(unsigned int)&bits);
	return 0;
}
