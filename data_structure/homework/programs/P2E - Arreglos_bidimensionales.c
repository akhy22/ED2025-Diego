#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nombre[25];
	int edad;
	int calificacion;
} Alumno;

int main(){
	Alumno *alumnos = NULL;
	int n = 0;
	char op;
	
	do{
		alumnos = (Alumno *) realloc(alumnos, (n+1)* sizeof(Alumno));
		if(alumnos == NULL){
			printf("Error de memoria. \n");
			return 1;
		}
		
		//Captura de datos
		printf("Ingrese el nombre del alumno: ");
		fgets(alumnos[n].nombre, 25, stdin);
		alumnos[n].nombre[strcspn(alumnos[n].nombre,"\n")] = 0;
		
		printf("Ingrese la edad: ");
		scanf("%d", &alumnos[n].edad);
		
		printf("Ingrese la calificacion: ");
		scanf("%d", &alumnos[n].calificacion);
		
		getchar();
		n++; //Numero de alumnos
		
		printf("Desea agregar otro alumno? (s/n): ");
		scanf("%c", &op);
		getchar();
		
	}while(op == 's' || op == 'S');
	
	//Calculando promedios
	int sumaEdad = 0;
	int sumaCal = 0;
	
	for(int i = 0; i < n; i++){
		sumaEdad += alumnos[i].edad;
		sumaCal += alumnos[i].calificacion;
	}
	
	float promedioEdad = (float)sumaEdad / n;
	float promedioCal = (float)sumaCal / n;
	
	printf("\nPromedio de edad: %.2f\n", promedioEdad);
	printf("Promedio de calificaciones: %.2f\n", promedioCal);
	
	//Imprimiendo los nombres en orden inverso
	printf("\nNombres de los alumnos: \n");
	for(int i = n - 1; i >= 0; i--){
		printf("%s\n", alumnos[i].nombre);
	}
	
	free(alumnos);
	
	return 0;
}
