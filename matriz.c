#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    int l = 0, c = 0, tam=0, opc1, opc2;
    int matriz[tam][tam];

    printf("Escolha o tamanho da sua Matriz Quadrada:\n");
    scanf("%d", &tam);

    system("cls");

    printf("A sua matriz será essa:\n");


    for (l = 0; l < tam; l++){
        for (c = 0; c < tam; c++){
            matriz[l][c] = rand() % 100;
        }
    }
    for(l = 0; l < tam; l++){
        for(c = 0; c < tam; c++){
            printf("%d\t", matriz[l][c]);
        }
        printf("\n");
    }
    printf("Escolha qual das Diagonais quer imprimir:\n");
    scanf("%d", &opc1);

    switch(opc1){
        case 1:
            for(l = 0; l < tam; l++){
                for(c = 0; c < tam; c++){
                    if(l==c){
                        printf("%d\t", matriz[l][c]);
                    }else{
                        printf(".\t");
                    }
                }
                printf("\n");
            }
        break;
        case 2:
            for(l = 0; l < tam; l++){
                for(c = 0; c < tam; c++){
                    if(l + c == tam - 1){
                        printf("%d\t", matriz[l][c]);
                    }else{
                        printf(".\t");
                    }
                }
                printf("\n");
            }
        break;

        default:
            printf("A opcao e invalida");
        break;
    }

    


    printf("Escolha o triangulo que deseja imprimir:\n");
    printf("1 - Triangulo Superior entre as Diagonais\n");
    printf("2 - Triangulo Direito entre as Diagonais\n");
    printf("3 - Triangulo Inferior entre as Diagonais\n");
    printf("4 - Triangulo Esquerdo entre as Diagonais\n");
    scanf("%d", &opc2);

    system("cls");
    
    switch (opc2)
    {
        case 1:
            for (l = 0; l < tam; l++){
                for (c = 0; c < tam; c++){
                    if (c>l && l+c<tam-1){
                        printf("%d\t", matriz[l][c]);
                    } else{
                        printf(".\t");
                    }
                
                }
                printf("\n");
            }
        break;
        case 2:
            for (l = 0; l < tam; l++){
                for (c = 0; c < tam; c++){
                    if (c>l && l+c>tam-1){
                        printf("%d\t", matriz[l][c]);
                    } else{
                        printf(".\t");
                    }
                
                }
            printf("\n");
        }
        break;
        case 3:
            for (l = 0; l < tam; l++){
                for (c = 0; c < tam; c++){
                    if (c<l && l+c>tam-1){
                        printf("%d\t", matriz[l][c]);
                    } else{
                        printf(".\t");
                    }
                }
            printf("\n");
            }
        break;
        case 4:
            for (l = 0; l < tam; l++){
                for (c = 0; c < tam; c++){
                    if (c<l && l+c<tam-1){
                        printf("%d\t", matriz[l][c]);
                    } else{
                        printf(".\t");
                    } 
                }
            printf("\n");
        }
        break;
        default:
            printf("A opcao escolhida é invalida\n");
        break;
    }

    return 0;
}