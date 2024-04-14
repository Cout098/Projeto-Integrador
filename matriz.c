#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int l = 0, c = 0, opc1, esc1 = 0, esc2 = 0, esc3 = 0, opc2, opc3, tam;

    srand(time(NULL));

    printf("Escolha o tamanho da sua Matriz Quadrada:\n");
    scanf("%d", &tam);

    int matriz[tam][tam];

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
    printf("\n");

    do
    {
        printf("Escolha qual das Diagonais quer imprimir:\n");
        printf("1 - Diagonal principal\n");
        printf("2 - Diagonal secundaria\n");
        scanf("%d", &opc1);

        system("cls");

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
        
        printf("\nGostaria de retornar ao menu de impressão?\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n");
        scanf("%d", &esc1);
        
        system("cls");

    } while (esc1==1);
    
    do
    {
        printf("\nEscolha o triangulo que deseja imprimir:\n");
        printf("1 - Triangulo Superior da Diagonal Principal\n");
        printf("2 - Triangulo Inferior da Diagonal Principal\n");
        printf("3 - Triangulo Superior da Diagonal Secundaria\n");
        printf("4 - Triangulo Inferior da Diagonal Secundaria\n");
        scanf("%d", &opc2);

        system("cls");

        switch (opc2)
        {
            case 1:
                for (l = 0; l < tam; l++){
                    for (c = 0; c < tam; c++){
                        if (c>l){
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
                        if (c<l){
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
                        if (l+c<tam-1){
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
                        if (l+c>tam-1){
                            printf("%d\t", matriz[l][c]);
                        } else{
                            printf(".\t");
                        }                   
                    }
                    printf("\n");
                }
            break;

            default:
                printf("Opcao invalida\n");
            break;
        }

        printf("\nGostaria de retornar ao menu de impressão?\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n");
        scanf("%d", &esc2);
        
        system("cls");

    } while (esc2==1);

    do
    {
        printf("Escolha o triangulo que deseja imprimir:\n");
        printf("1 - Triangulo Superior entre as Diagonais\n");
        printf("2 - Triangulo Direito entre as Diagonais\n");
        printf("3 - Triangulo Inferior entre as Diagonais\n");
        printf("4 - Triangulo Esquerdo entre as Diagonais\n");
        scanf("%d", &opc3);

        system("cls");
        
        switch (opc3)
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

        printf("\nGostaria de retornar ao menu de impressão?\n");
            printf("1 - Sim\n");
            printf("2 - Nao\n");
            scanf("%d", &esc3);
            
            system("cls");
    } while (esc3==1);
    
    return 0;
}