#include <stdio.h>

// Função para limpar a tela
void cleaner () {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Função para imprimir o tabuleiro
void imprimir_tabuleiro(char tabuleiro[]) {
    printf(" %c | %c | %c \n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[6], tabuleiro[7], tabuleiro[8]);
}

// Função para verificar se há um vencedor
int verificar_vencedor(char tabuleiro[], char jogador) {
    // Verificar linhas
    for (int i = 0; i < 7; i += 3) {
        if (tabuleiro[i] == jogador && tabuleiro[i+1] == jogador && tabuleiro[i+2] == jogador)
            return 1;
    }
    // Verificar colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i] == jogador && tabuleiro[i+3] == jogador && tabuleiro[i+6] == jogador)
            return 1;
    }
    // Verificar diagonais
    if ((tabuleiro[0] == jogador && tabuleiro[4] == jogador && tabuleiro[8] == jogador) ||
        (tabuleiro[2] == jogador && tabuleiro[4] == jogador && tabuleiro[6] == jogador))
        return 1;
    return 0;
}

int main() {
    int opcjogo = 1, j1 = 0, j2 = 0;
    do{
        char tabuleiro[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        char jogador_atual = 'X';
        int vencedor = 0;

        cleaner();
        printf("Bem-vindo ao Jogo da Velha!\n");
        imprimir_tabuleiro(tabuleiro);

        while (!vencedor) {
            int jogada;
            printf("Jogador %c, escolha uma posição (1-9): ", jogador_atual);
            scanf("%d", &jogada);
            jogada--;

            if (jogada < 0 || jogada > 8 || tabuleiro[jogada] == 'X' || tabuleiro[jogada] == 'O') {
                printf("Posição inválida. Escolha outra posição.\n");
                continue;
            }
            cleaner();
            tabuleiro[jogada] = jogador_atual;
            imprimir_tabuleiro(tabuleiro);

            if (verificar_vencedor(tabuleiro, jogador_atual)) {
                printf("Parabéns, jogador %c! Você venceu!\n", jogador_atual);
                vencedor = 1;
            } else if (tabuleiro[0] != '1' && tabuleiro[1] != '2' && tabuleiro[2] != '3' &&
                    tabuleiro[3] != '4' && tabuleiro[4] != '5' && tabuleiro[5] != '6' &&
                    tabuleiro[6] != '7' && tabuleiro[7] != '8' && tabuleiro[8] != '9') {
                printf("Empate!\n");
                break;
            }
            //Alterar o contador do Placar
            if(vencedor==1 && jogador_atual== 'X'){
                j1++;
            }
            if(vencedor==1 && jogador_atual== '0'){
                j2++;
            }

            jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
        }
        //Imprime o Placar
        printf("\t\tPlacar: \nJogador X: %d \nJogador 0: %d\n\n", j1,j2);

        printf("Deseja jogar novamente?\n");
        printf("1 - Sim\n");
        printf("2 - Não\n");
        scanf("%d", &opcjogo);

    } while (opcjogo == 1);
    

    return 0;
}