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

int main(void) {
  cleaner();
  setlocale(LC_ALL,"Portuguese");
  char jogador_atual = 'X';//Declaro com o valor X para ser a primeira jogada.
  int vencedor = 0;
  int opmenu, opjogo=1, opregras, opc, j1=0, j2=0;
  //Já inicializei com o valor por causa da impressão do tabuleiro
  char v1 = '1', v2 = '2', v3 = '3', v4 = '4', v5 = '5', v6 = '6', v7 = '7', v8 = '8', v9 = '9'; 

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
    //Laço para jogar até escolher sair.
    while (opjogo == 1){ 
      //Laço para realizar todos as jogadas até alguém ganhar ou empatar.
      while (!vencedor) { 
        // Imprime o tabuleiro usando variaveis, já que não pode usar vetor, nem matriz.
        cleaner(); 
        printf("\n\n");//Usei só pra criar espaço no meu console.
        printf(" %c | %c | %c \n", v1, v2, v3);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", v4, v5, v6);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", v7, v8, v9);
        printf("\nJogador %c, escolha uma posição (1-9): ", jogador_atual);
        if (scanf("%d", &opc) != 1) {   
          printf("Entrada inválida, tente novamente.\n");
          while (getchar() != '\n'); 
          continue;
        }
        if (opc == 1 && v1 == '1') {
          v1 = jogador_atual;
        }
        if (opc == 2 && v2 == '2') {
          v2 = jogador_atual;
        }
        if (opc == 3 && v3 == '3') {
          v3 = jogador_atual;
        }
        if (opc == 4 && v4 == '4') {
          v4 = jogador_atual;
        }
        if (opc == 5 && v5 == '5') {
          v5 = jogador_atual;
        }
        if (opc == 6 && v6 == '6') {
          v6 = jogador_atual;
        }
        if (opc == 7 && v7 == '7') {
          v7 = jogador_atual;
        }
        if (opc == 8 && v8 == '8') {
          v8 = jogador_atual;
        }
        if (opc == 9 && v9 == '9') {
          v9 = jogador_atual;
        }
  
        //Confere as linhas
        if (v1 == v2 && v2 == v3) {
          printf("Jogador %c venceu!\n", jogador_atual);
          vencedor = 1;
        }
        if (v4 == v5 && v5 == v6) {
          printf("Jogador %c venceu!\n", jogador_atual);
          vencedor = 1;
        }
        if (v7 == v8 && v8 == v9) {
          printf("Jogador %c venceu!\n", jogador_atual);
          vencedor = 1;
        }
        // Confere as colunas
        if (v1 == v4 && v4 == v7) {
          printf("Jogador %c venceu!\n", jogador_atual);
          vencedor = 1;
        }
        if (v2 == v5 && v5 == v8) {
          printf("Jogador %c venceu!\n", jogador_atual);
          vencedor = 1;
        }
        if (v3 == v6 && v6 == v9) {
          printf("Jogador %c venceu!\n", jogador_atual);
          vencedor = 1;
        }
        // Confere as diagonais
        if (v1 == v5 && v5 == v9) {
          printf("Jogador %c venceu!\n", jogador_atual);
          vencedor = 1;
        }
        if (v3 == v5 && v5 == v7) {
          printf("Jogador %c venceu!\n", jogador_atual);
          vencedor = 1;
        } 
        //Confere se deu empate analizando se todas as posições estão preenchidas.
        else if (v1 != '1' && v2 != '2' && v3 != '3' && v4 != '4' && v5 != '5' && v6 != '6' && v7 != '7' && v8 != '8' && v9 != '9') {
          printf("Empate!\n");
          break;
        }
        // Esses IF's são para manter a contagem do placar para cada jogador.
        if(vencedor==1 && jogador_atual== 'X'){
          j1++;
        }
        if(vencedor==1 && jogador_atual== '0'){
          j2++;
        }
        
        //Alterna entre os jogadores X e 0
        jogador_atual = (jogador_atual == 'X') ? '0' : 'X'; //Alterna entre os jogadores X e 0

      }
      printf("Placar: Jogador X: %d, Jogador 0: %d\n\n", j1,j2);

      //Nesse bloco eu retorno as variaveis para o valor inicial para que o jogo possa ser jogado novamente.
      v1= '1'; v2= '2'; v3= '3'; v4= '4'; v5= '5'; v6= '6'; v7= '7'; v8= '8', v9= '9';
      jogador_atual= 'X';
      vencedor = 0;

      //Esse bloco é para perguntar se o jogador quer jogar novamente.
      printf("Deseja jogar novamente?\n");
      printf("1 - Sim\n");
      printf("2 - Não\n");
      scanf("%d", &opjogo);
    }
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