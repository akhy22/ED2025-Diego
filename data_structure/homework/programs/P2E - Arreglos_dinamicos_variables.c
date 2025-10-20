#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char cadena[100];
	
	printf("Ingrese una palabra en mayusculas: ");
	scanf("%s", cadena);
	
	int len = strlen(cadena);
	
	char **matriz = (char **) malloc((len + 1)* sizeof(char*));
	if(matriz == NULL){
		printf("No se pudo asignar la memoria.\n");
		return -1;
	}
	
	for(int i = 0; i< len; i++){
		char c = cadena [i];
		
		if(c >= 'A' && c <= 'Z'){
			int repeticiones = (c - 'A') + 1; //Posicion en el abecedario
			matriz[i] = (char *) malloc((repeticiones + 1) * sizeof(char));
			if(matriz[i] == NULL){
				printf("Error: no se pudo asignar memoria para la letra %c. \n", c);
				return -1;
			}
			for(int j = 0; j < repeticiones; j++){
				matriz[i][j] = c;
			}
			matriz[i][repeticiones] = '\0';
		}else{
			matriz[i] = NULL; //No mayuscula -> Null
		}
	}
	matriz[len] = NULL; // Final
	
	//Imprimir palabra con el formato
	for(int i = 0; i < len; i++){
		if(matriz[i] != NULL){
			printf("| ");
			for(int j = 0; matriz[i][j] != '\0'; j++){
				printf("%c | ", matriz[i][j]);
			}
			printf("\n");
		}else{
			printf("NULL\n");
		}
	}
	
	//Liberando memoria
	for(int i = 0; i < len; i++){
		free(matriz[i]);
	}
	free(matriz);
	
	return 0;
	
}
