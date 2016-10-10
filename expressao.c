#include "expressao.h"
#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int validaEntrada(char* expressao){
	int i = 0;
	int valida = 1;
	for(i=0;i<strlen(expressao);i++){
	if(expressao[i] == 45 || expressao[i] >= 47 && expressao[i] <= 57 || expressao[i] >= 40 && expressao[i] <= 43 || expressao[i] == 91 || expressao[i] == 93 || expressao[i] == 123 || expressao[i] == 125){
			//do nothing
		}else{
			printf("Entrada incorreta!(So sao validos numeros de 0 a 9 e os quatro operandos basicos (+-*/)\n");
			valida = 0;
			break;
		}
	}
	return valida;
}

int validaExpressao(char* expressao){
  int i = 0;
  int valida = 1;
  char c;
  t_pilha* pilha = getPilha(100);
  while( (expressao[i] != '\0') && (valida != 0) ){
      printf("simbolo: %c valor: %d\n", expressao[i], (int) expressao[i]);

      if( (expressao[i] == '(') || (expressao[i] == '[') || (expressao[i] == '{') )
          push(pilha, (int) expressao[i]);

      if( (expressao[i] == ')') || (expressao[i] == ']') || (expressao[i] == '}') ){
          if( pilhaVazia(pilha) )
              valida = 0;
          else{
              c = (char) pop(pilha);

              switch(expressao[i]){
                  case ')':
                      if( c != '(' )
                          valida = 0;
                      break;
                  case ']':
                      if( c != '[' )
                          valida = 0;
                      break;
                  case '}':
                      if( c != '{' )
                          valida = 0;
                      break;
              }

          }
      }

      i++;

  }//end while

  if( !pilhaVazia(pilha) )
      valida = 0;

  printf("\n A expressao: ");

  if(!valida)
      printf(" NAO ");


  printf(" eh valida \n");

    liberaPilha(pilha);

  return valida;
}

char* transformaExpressao(char* expressao){
	t_pilha* pilha = getPilha(100);
	char* expressaoNova = (char*) malloc(strlen(expressao)*sizeof(char));
	char x = '0';
	int i = 0;
	int j = 0;
	int prioridade1 = 0;
	int prioridade2 = 0;
//	push(pilha,'(');	
	for(i=0;i<strlen(expressao);i++)
		printf("%c", expressao[i]);

		printf("\n");

	for(i = 0; i< strlen(expressao);i++){
		if(expressao[i] >= 48 && expressao[i] <= 57){
			expressaoNova[j] = expressao[i];
			j++;
			printf("if de numero\n");
		}else if(expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{'){
			printf("if de abertura\n");
			prioridade2 = 2;
			push(pilha, expressao[i]);
			printf("push abertura = %c\n", expressao[i]);
		}else if(expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}' || expressao[i] == '\0'){
			printf("if de fechamento\n");
			while(x != '(' && x!= '[' && x!= '{'){	
				x = pop(pilha);
				printf("pop fechamento= %c\n", x);
				if(x != '(' && x != '[' && x != '{'){
					expressaoNova[j] = x;
					j++;
				}else{
					//do nothing
				}
				
			}
		
		}else if(expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/'){
				printf("if de operador\n");
			//	printf("Pilha vazia? %d\n", pilhaVazia(pilha));
				printf("operador encontrado = %c\n", expressao[i]);
				//printf("operador pilha = %c\n", topo(pilha));
				if(expressao[i] == '+' || expressao[i] == '-'){
					prioridade1 = 1;
				}else{
					prioridade1 = 2;
				}

				if(topo(pilha) == '+' || topo(pilha) == '-' || topo(pilha) == '\0'){
					prioridade2 = 1;
				}else if(topo(pilha) == '*' || topo(pilha) == '/'){
					prioridade2 = 2;
				}else{
					prioridade2 = 0;
				}
				printf("Pilha vazia? %d\n", pilhaVazia(pilha));		
                printf("******************\n");                				
                printf("Teste de prioridade:\nPrioridade1 = %d\nPrioridade2 = %d\n", prioridade1, prioridade2);				
                    while(!pilhaVazia(pilha) && prioridade2 >= prioridade1){
					
					expressaoNova[j] = pop(pilha);
					printf("pop operador = %c\n", expressaoNova[j]);
					j++;
				
					if(topo(pilha) == '+' || topo(pilha) == '-' || topo(pilha) == '\0'){
						prioridade2 = 1;
					}else if(topo(pilha) == '*' || topo(pilha) == '/'){
						prioridade2 = 2;
					}else{
						prioridade2 = 0;
					}
				}	
				push(pilha, expressao[i]);
				printf("push operador = %c\n", expressao[i]);
			}
	}
		while(!pilhaVazia(pilha)){
			expressaoNova[j] = pop(pilha);
			printf("pop fim = %c\n", expressaoNova[j]);
			j++;
		}
		
	
	

	printf("Expressao:\n");
	for(i = 0; i < j; i++){
		printf(" %c", expressaoNova[i]);
	}
		printf("\n");
	
	return expressaoNova;
}

int resolveExpressao(char* expressao){
	int i = 0;
	int resultado = 0;
	int aux1 = 0;
	int aux2 = 0;
	t_pilha* pilha = getPilha(100);
	for(i=0; i< strlen(expressao); i++){
		if(expressao[i] >= 48 && expressao[i] <= 57){
		push(pilha, (int)expressao[i]-48);
		
		}
		switch(expressao[i]){
			case '+':
				 aux1 = pop(pilha);
				 aux2 = pop(pilha);
			   	 resultado =+ aux1 + aux2;
			 	 push(pilha, resultado);
				break;
			case '-':
				 aux1 = pop(pilha);
                                 aux2 = pop(pilha);
                                 resultado =+ aux2 - aux1; 
				 push(pilha, resultado);
				break;
			case '*':
				 aux1 = pop(pilha);
                                 aux2 = pop(pilha);
                                 resultado =+ aux1 * aux2;
				 push(pilha, resultado); 
				break;
			case '/':
				 aux1 = pop(pilha);
                                 aux2 = pop(pilha);
                                 resultado =+ aux2/aux1;
				printf("valor de aux1 %d\n", aux1);
				printf("valor de aux2 %d\n", aux2); 
				printf("resultado da divisao: %d\n", resultado);
				 push(pilha, resultado);
				break;
		//	default:
				//do nothing
		}
	}
	return resultado;
}
