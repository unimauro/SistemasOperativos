#define <stdio.h>
#define <stdlib.h>

int main(void)
{
	float ** m=NULL;
	int fila, columnas;
	
	printf("FILAS: "); scanf("%d", &filas);
	printf("COLUMNAS: "); scanf("%d", &columnas);	

	/**/
	m = malloc(filas * sizeof(float *));
	for(i=0; i<filas; i++)
		m[i]=malloc(columnas *sizeof(float));

	for(i=0; i<filas;i++)
		free(m[i])

	free(m);
	m=NULL;

	return;
}
