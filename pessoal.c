#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void escrevaNome();//declara a função = Prototipo da função

int main(){
    setlocale(LC_ALL,"");
    escrevaNome();
    return 0;
}

void escrevaNome(){ //defini minha função 
    printf("Bem vindo\n");
}

