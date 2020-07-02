#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *a= NULL;
	int  i, talla;

	printf("Numero de elementos: "), scanf("%d", &talla);
	a = malloc(talla*sizeof(int));
	for (i =0; i < talla; i++)
		a[i]=i;
	free(a);
	a=NULL;
	return 0;
}

