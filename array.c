#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i=0;
float notas[4];

void imprimirNotas();
int main(){
    setlocale(LC_ALL,"");
    
    for ( i = 0; i < 4; i++)
    {
        printf("Digite as notas\n");
        scanf("%f", &notas[i]);
    }
    
    imprimirNotas();

    return 0;
}

void imprimirNotas(){
    for(i = 0; i < 4; i++){
         printf("%.2f\n", notas[i]);
    }
}

