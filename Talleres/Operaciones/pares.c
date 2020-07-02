#include <stdio.h>
#include <stdlib.h>

struct VectorDinamicoEntero{
	int *elementos;
	int talla;
};

void selecciona_pares( struct VectorDinamicoEntero entrada,
struct VectorDinamicoEntero *pares)
{
	int i, j;

	pares->talla =0;
	for(i=0; i < entrada.talla; i++)
		if(entrada.elementos[i]%2==0)
			pares->talla++;

	pares->elementos = malloc(pares->talla*sizeof(int));

	j=0;

	for (i=0; i<entrada.talla;i++)
		if(entrada.elementos[i]%2==0)
			pares->elementos[j++]=entrada.elementos[i];

	free(pares);
}

int main(void)
{
	int i;
	struct VectorDinamicoEntero vector, seleccionados;
	
	vector.talla= 10;
	vector.elementos = malloc(vector.talla *sizeof(int));
	for(i=0; i<vector.talla; i++){
		vector.elementos[i] = rand();
		printf("vector %d:\t %d \t %u\n",i,vector.elementos[i],&vector.elementos[i]);
	}
	selecciona_pares(vector, & seleccionados);
	printf("----------\n");
	for(i=0; i<seleccionados.talla;i++)
		printf("%d \n", seleccionados.elementos[i]);

	free(seleccionados.elementos);
	seleccionados.elementos = NULL;
	seleccionados.talla=0;

	return 0;
}
