#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *a;
	int talla, i;

	printf("Numero de elementos: "), scanf("%d", &talla);
	a = malloc(talla*sizeof(int));
	for (i =0; i < talla; i++)
		a[i]=i;
	free(a);
	a=NULL;
	return 0;
}


Fragmentación de la memoria
Ya hemos dicho que malloc puede fracasar si se solicita más memoria de la disponible en
el ordenador. Parece lógico pensar que en un ordenador con 64 megabytes, de los que el
sistema operativo y los programas en ejecución han consumido, digamos, 16 megabytes,
podamos solicitar un bloque de hasta 48 megabytes. Pero eso no está garantizado.
Imagina que los 16 megabytes ya ocupados no están dispuestos contiguamente en la
memoria sino que, por ejemplo, se alternan con fragmentos de memoria libre de modo
que, de cada cuatro megabytes, uno está ocupado y tres están libres, como muestra esta


En tal caso, el bloque de memoria más grande que podemos obtener con malloc es de
¡sólo tres megabytes!
Decimos que la memoria está fragme
