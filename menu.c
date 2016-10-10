#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(){
    int opcao;
	char* aux;
     do{
      printf("*********************************************************\n");
      printf("Bem vindo ao programa de ED! Selecione a opcao que deseja:\n");
      printf("1-Resolucao de expressao\n");
      printf("2-Calculadora\n");

      scanf("%d", &opcao);
      }while(validaOpcao(opcao) != 1);
        if(opcao == 1){
          //fflush(stdin);
          //rewind(stdin);
          char expressao[100];
          do{
          printf("Digite a expressão: \n");
          scanf(" %[^\n]", expressao);
          }while(validaEntrada(expressao) != 1);
              validaExpressao(expressao);
       		aux = (transformaExpressao(expressao));
	//	printf("Tamanho da expressao: %d\n", strlen(aux));
		printf("resultado : %d\n", resolveExpressao(aux));
		int i;
	}else if(opcao == 2){
		calculadora();
	}
}

int validaOpcao(int opcao){
  if(opcao == 1 || opcao == 2){
    return 1;
  }else{
    printf("Opcao incorreta! Selecione entre (1) e (2)!\n");
    return 0;
  }

}
