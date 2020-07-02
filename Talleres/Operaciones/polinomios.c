#include <stdio.h>
#define TALLA 11
int main (void)
{
	float p[11], q[11];
	int grado;
	int i;
	do {
		printf("Grado de P (entre 0 y %d):", TALLA-1);
		scanf("%d", &grado);
	}while(grado<0 || grado>=TALLA);
	
	for (i=0; i<=grado; i++)
	{
		printf("P %d: ", i); scanf("%f",&p[i]);
	}
	printf("Direccion en P grado %u \n", (unsigned int)&grado);
	printf("Direccion en P i %u \n", (unsigned int)&i);
	printf("Ocupacion de un elemento de P en bytes: %d \n", sizeof(p[0]));
	printf("Ocupacion de P en bytes: %d \n", sizeof(p));
	printf("Direccion de P0: %u \n", (unsigned int)&p[0]);

	do {
		printf("Grado de Q (entre 0 y %d):", TALLA-1);
		scanf("%d", &grado);
	}while(grado<0 || grado>=TALLA);
	
	for (i=0; i<=grado; i++)
	{
		printf("Q %d: ", i); scanf("%f",&p[i]);
	}
	printf("Direccion en Q grado %u \n", (unsigned int) &grado);
	printf("Direccion en Q i %u \n", (unsigned int) &i);
	printf("Ocupacion de un elemento de Q en bytes: %d \n", sizeof(q[0]));
	printf("Ocupacion de Q en bytes: %d \n", sizeof(q));
	printf("Direccion de Q0: %u \n", (unsigned int)&q[0]);

	return 0;
}
