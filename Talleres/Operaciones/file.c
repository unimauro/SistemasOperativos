#include <stdio.h>

int es_primo(int n)
{
	int i,j,primo;
	primo =1;
	for (j=2;j<=n/2;j++)
		if (n%j==0){
			primo =0;
			break;
		}
	return primo;
}

int main(void)
{
	FILE * fp;
	int i, n;
	
	fp = fopen("primos.txt","w");
	i=1;
	n=0;
	while(n<100000000)
	{
		if(es_primo(i)){
			fprintf(fp, "%d\n",i);
			n++;
		}	
		i++;
	}
	fclose(fp);
	return 0;
}
