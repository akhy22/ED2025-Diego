#include <stdio.h>

//Programa: P2E - Descomposicion del numero de cuenta
//Real;ice un programa en C que genere una lista de los primeros 10 numeros pares,  deberia imprimirlos en orden inverso
// posteriormente debera modificar el valor almacenado en el indice correspondiente al ultimo digito de su numero de cuenta por -1

int main(){
    int numeros[10];
    int cont = 2;
    int numeroCuenta;
    for(int i = 0; i < 10; i++){
        numeros[i] = cont;
        cont += 2:
    }

    for(int i = 9; i >= 0; i--){
        printf(" %d |", numeros[i]);
    }

    printf("\n");
    scanf("%d", &numeroCuenta);
    numeros[numeroCuenta % 10] = -1;

    for(int i = 0; i < 10; i++){
        printf("%d |", numeros[i]);
    }

    return 0;
}