#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


void cleaner () {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
// Função para imprimir o vetor
void imprimir_matriz(char matriz[]) {
    printf(" %c | %c | %c \n", matriz[0], matriz[1], matriz[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", matriz[3], matriz[4], matriz[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", matriz[6], matriz[7], matriz[8]);
}

// Função para verificar se há um vencedor
int verificar_vencedor(char matriz[], char jgd) {
    // Verificar linhas
    for (int i = 0; i < 7; i += 3) {
        if (matriz[i] == jgd && matriz[i+1] == jgd && matriz[i+2] == jgd)
            return 1;
    }
    // Verificar colunas
    for (int i = 0; i < 3; i++) {
        if (matriz[i] == jgd && matriz[i+3] == jgd && matriz[i+6] == jgd)
            return 1;
    }
    // Verificar diagonais
    if ((matriz[0] == jgd && matriz[4] == jgd && matriz[8] == jgd) ||
        (matriz[2] == jgd && matriz[4] == jgd && matriz[6] == jgd))
        return 1;
    return 0;
}

int main(void) {
    cleaner();
    setlocale(LC_ALL,"Portuguese");
    int opmenu, opcjogo=1, opregras, j1=0, j2=0;

    // Menu mais simples que pensei
    printf("Bem vindo ao jogo da velha!\n");
    printf("Escolha uma opção:\n");
    printf("1 - Jogar\n");
    printf("2 - Regras\n");
    printf("3 - Sair\n");
    scanf("%d", &opmenu);
    cleaner();

    switch (opmenu) {
        case 1:
            do{
                char matriz[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
                char jg_a = 'X';
                int vencedor = 0;

                cleaner();
                printf("Bem-vindo ao Jogo da Velha!\n");
                imprimir_matriz(matriz);

                while (!vencedor) {
                    int jogada;
                    printf("Jogador %c, escolha uma posição (1-9): ", jg_a);
                    scanf("%d", &jogada);
                    jogada--;

                    if (jogada < 0 || jogada > 8 || matriz[jogada] == 'X' || matriz[jogada] == 'O') {
                        printf("Posição inválida. Escolha outra posição.\n");
                        continue;
                    }
                    cleaner();
                    matriz[jogada] = jg_a;
                    imprimir_matriz(matriz);

                    if (verificar_vencedor(matriz, jg_a)) {
                        printf("Parabéns, Jogador %c! Você venceu!\n\n", jg_a);
                        vencedor = 1;
                    } else if (matriz[0] != '1' && matriz[1] != '2' && matriz[2] != '3' &&
                            matriz[3] != '4' && matriz[4] != '5' && matriz[5] != '6' &&
                            matriz[6] != '7' && matriz[7] != '8' && matriz[8] != '9') {
                        printf("Empate!\n");
                        break;
                    }
                    //Alterar o contador do Placar
                    if(vencedor==1){
                        if(jg_a == 'X'){
                            j1++;
                        } else {
                            j2++;
                        }
                    }
                    
                    jg_a = (jg_a == 'X') ? 'O' : 'X';
                }
                //Imprime o Placar
                printf("\t\tPlacar: \nJogador X: %d \nJogador 0: %d\n\n", j1,j2);

                printf("Deseja jogar novamente?\n");
                printf("1 - Sim\n");
                printf("2 - Não\n");
                scanf("%d", &opcjogo);

            } while (opcjogo == 1);
        break;
        case 2:
            printf("Regras do jogo da velha:\n");
            printf("No modo básico do jogo, participam duas pessoas, que jogam alternadamente,\n");
            printf("preenchendo cada um dos espaços vazios. Cada participante deve usar um símbolo (X ou O).\n");
            printf("Vence o jogador que conseguir formar primeiro uma linha com três símbolos iguais,\n");
            printf("seja ela na horizontal, vertical ou diagonal.\n\n");

            printf("Gostaria de retornar ao menu principal? (1 - Sim, 2 - Não)\n");
            scanf("%d", &opregras);
            
            if (opregras == 1){
                main();
            } else{
                printf("Obrigado por jogar!\n");
            }
        break;
        case 3:
            printf("Obrigado por jogar!\n");
        break;
        default:
            printf("Opção inválida.\n");
        break;
    }


  return 0;
}