#include <stdio.h>
#include <locale.h>

void imprimirTabuleiro(char v1, char v2, char v3, char v4, char v5, char v6,
                       char v7, char v8, char v9) {
  printf(" %c | %c | %c \n", v1, v2, v3);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", v4, v5, v6);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", v7, v8, v9);
}

int verificarVencedor(char v1, char v2, char v3, char v4, char v5, char v6,
                       char v7, char v8, char v9, char jogador_atual) {
  // Confere as linhas
  if (v1 == v2 && v2 == v3) {
    printf("Jogador %c venceu!\n", jogador_atual);
    return 1;
  }
  if (v4 == v5 && v5 == v6) {
    printf("Jogador %c venceu!\n", jogador_atual);
    return 1;
  }
  if (v7 == v8 && v8 == v9) {
    printf("Jogador %c venceu!\n", jogador_atual);
    return 1;
  }
 
  // Confere as colunas
  if (v1 == v4 && v4 == v7) {
    printf("Jogador %c venceu!\n", jogador_atual);
    return 1;
  }
  if (v2 == v5 && v5 == v8) {
    printf("Jogador %c venceu!\n", jogador_atual);
    return 1;
  }
  if (v3 == v6 && v6 == v9) {
    printf("Jogador %c venceu!\n", jogador_atual);
    return 1;
  }
  // Confere as diagonais
  if (v1 == v5 && v5 == v9) {
    printf("Jogador %c venceu!\n", jogador_atual);
    return 1;
  }
  if (v3 == v5 && v5 == v7) {
    printf("Jogador %c venceu!\n", jogador_atual);
    return 1;
  }
  
  return 0;
}

int main(void) {
  setlocale(LC_ALL,"Portuguesa");
  
  char v1 = '1', v2 = '2', v3 = '3', v4 = '4', v5 = '5', v6 = '6', v7 = '7',
       v8 = '8', v9 = '9';
  char jogador_atual = 'X';
  int vencedor=0;
  int opc;

  printf("\n");
  imprimirTabuleiro(v1, v2, v3, v4, v5, v6, v7, v8, v9);
  
  while(!vencedor){
    printf("Jogador %c, escolha uma posi��o (1-9):\n", jogador_atual);
    scanf("%d",&opc);
    if(opc<0 || opc>9 || opc=='0'|| opc== 'X'){
      printf("Op��o inv�lida, tente novamente.\n");
      continue;
    }
    if(opc==1 && v1=='1'){
      v1=jogador_atual;
    }
    if(opc==2 && v1=='2'){
      v2=jogador_atual;
    }
    if(opc==3 && v3=='3'){
      v3=jogador_atual;
    }
    if(opc==4 && v1=='4'){
      v4=jogador_atual;
    }
    if(opc==5 && v5=='5'){
      v5=jogador_atual;
    }
    if(opc==6 && v6=='6'){
      v6=jogador_atual;
    }
    if(opc==7 && v7=='7'){
      v7=jogador_atual;
    }
    if(opc==8 && v8=='8'){
      v8=jogador_atual;
    }
    if(opc==9 && v9=='9'){
      v9=jogador_atual;
    }
    imprimirTabuleiro(v1, v2, v3, v4, v5, v6, v7, v8, v9);

    vencedor=verificarVencedor(v1, v2, v3, v4, v5, v6, v7, v8, v9, jogador_atual);


    jogador_atual = (jogador_atual == 'X') ? '0' : 'X'; //alternancia entre os jogadores
  }


  return 0;
}
