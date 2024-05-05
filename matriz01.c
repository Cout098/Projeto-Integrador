#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherMatriz(int matriz[][100], int linhas, int colunas){
    srand(time(NULL));

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matriz[i][j] = rand() % 100;
        }
    }
}

void imprimirMatriz(int matriz[][100], int linhas , int colunas){
    
    printf("A sua matriz será essa:\n");

    for(int i = 0; i < linhas; i++){
        for( int j = 0; j < colunas; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirPrincipal(int matriz[][100], int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for( int j = 0; j < colunas; j++){
            if(i==j){
                printf("%d\t", matriz[i][j]);
            }else{
                printf(".\t");
            }
        }
        printf("\n");
    }
}

int main(){
    int linhas, colunas;
    int opc1, esc1;

    printf("Escolha o tamanho da sua Matriz Quadrada:\n");
    scanf("%d", &linhas);
    printf("Escolha o tamanho da sua Matriz Quadrada:\n");
    scanf("%d", &colunas);
    

    int matriz[linhas][colunas];
    preencherMatriz(matriz,linhas,colunas);
    imprimirMatriz(matriz,linhas,colunas);

    do
    {
        printf("Escolha qual das Diagonais quer imprimir:\n");
        printf("1 - Diagonal principal\n");
        printf("2 - Diagonal secundaria\n");
        scanf("%d", &opc1);

        system("cls");

        switch(opc1){
            case 1:
                imprimirPrincipal(matriz, linhas,colunas);
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

    return 0;
}


