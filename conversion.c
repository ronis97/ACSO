#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//pasar fracciones a decimal falta
int n, baseo,basef;
char num[1000], num1[1000], numf[1000];
//char delim[] = '.';
void pasar_a_base(nn,bsf){
	//printf("\n%d \n%d", nn, bsf);
	int cociente, residuo;
	char res[1000];
	int i,j = 0;
	cociente = nn;
	while (cociente != 0)
	{
		residuo = cociente % bsf;
		if (residuo < 10){
			res[j++] = 48 + residuo;
		}
		else
		{
			res[j++] = 55 + residuo;
			cociente = cociente/bsf;
			printf("%d",cociente);	
		}
	}
	printf("Valor en base %d de %d es: \n",bsf,nn);
	for(i = j-1;i >= 0;i--){
		printf("%c",res[i]);		
	}	
	}

	

int chartodecimal(char c){
	if (isdigit(c)){
		return c - '0';
	}
	return 10 + (toupper(c) - 'A');
}
double pasar_decimal(int bo, char* numero, int l,int ppos){
	
	
	double decimal = 0, fract = 0;
	int pot = 0,i;
	printf("posicion del indice %d\n",ppos);
	if(ppos == 0){
		ppos = l;
	}
	for(i = ppos-1; i >= 0; i--){
		int valact = chartodecimal(numero[i]);
		double elevar = pow(bo,pot) * valact;
		decimal += elevar;
		pot ++;
	}
	pot = 1;
	//printf("La potencia es %d\n",pot);
	for(i = ppos + 1; i < l; i++){
		int valact = chartodecimal(numero[i]);
		double elevar = pow(bo,-pot) * valact;
		fract += elevar;
		pot ++;
	}
	printf("%f",decimal);
	printf("\n%f",fract);
	return decimal + fract;
	
}

int get_index(char* string, char c){
	char *e = strchr(string,c);
	if (e == NULL){
		return -1;
	}
	return (int)(e-string);
}
int main()
{
	int i,lon;
	printf("numero de datos");
	scanf("%d",&n);
	double dec;
	for(i = 0; i < n; i++)
	{
		printf("\nBase original:");
		scanf("%d",&baseo);
		printf("\nnumero a convertir:");
		scanf("%s",num);
		printf("\nbase final");
		scanf("%d",&basef);
		printf("%d %s %d",baseo,num,basef);
		if (baseo == basef){
			int j,n = 0;	
			while(num[j] == '0'){
				
				n = j;
				j++;		
			}
			if (num[0] != '0'){
				strcpy(num1,&num[n]);	
			}
			else{
				strcpy(num1,&num[n+1]);
			}
			
			printf("%s",num1);
		}
		else if(baseo != basef){
			//printf("%d",basef);
			int index = get_index(num,'.');
			if(index != -1){
				dec = pasar_decimal(baseo,num,strlen(num),index);
				printf("numero convertido");
				printf("\n%f",dec);
				
			}
			else{
				dec = pasar_decimal(baseo,num,strlen(num),0);
				int dec1;
				dec1 = dec;
				printf("numero convertido");
				printf("\n%d",dec1);
				if(basef != 10){
					printf("\nLa base es %d",basef);
					pasar_a_base(dec1,basef);
				}
			}
		}
	} 
	return 0;	
}
