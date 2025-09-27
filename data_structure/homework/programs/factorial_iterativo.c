#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int facTail(int n, int a){
    if (n < 0){
        return 0;
    }else if (n == 0){
        return 1;
    }else if (n == 1){
        return a;
    }else{
        return facTail(n - 1, n * a);
    }
    
}

int main(int argc, char *argv[]){
    int i;
    char *num = argv[1];

    fprintf(stdout, "arg[1] = %s \n", argv[1]);
    for(i = 1; i < strlen(argv[1]); i++){
        fprintf(stdout, "num[%d] = %c \n", i , num[i]);
    }

    int n = atoi(argv[1]);
    int resultado = facTail(n, 1);
    fprintf(stdout, "El factorial de %d es: %d\n", n, resultado);

    return 0;
}
