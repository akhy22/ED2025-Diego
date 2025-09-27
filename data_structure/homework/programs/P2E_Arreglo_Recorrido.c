#include <stdio.h>

int main(){
	int n, m;
	printf("Ingrese n y m : (Maximo 10)\n");
	printf("n: ");
	scanf("%d", &n);
	printf("m: ");
	scanf("%d", &m);
	int arreglo[n][m];
	
	//Inicializando arreglo
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			arreglo[i][j] = i * 10 + j;
		}
	}
	
	printf("1. Recorrido por fila\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%02d ", arreglo[i][j]);
		}
		printf("\n");
	}
	
	printf("2. Recorrido por columnas \n");
	for(int j = m - 1; j >= 0; j--){
		for(int i = n - 1; i >= 0; i--){
			printf("%02d ", arreglo[i][j]);
		}
		printf("\n");
	}
	
	printf("3. Recorrido en diagonal \n");
	if(n <= m){
		for(int i = 0; i < n; i++){
			printf("%02d ", arreglo[i][i]);
		}
	}else if(n > m){
		for(int i = 0; i < m; i++){
			printf("%02d ", arreglo[i][i]);
		}
	}
	
	
	return 0;
}
