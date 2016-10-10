#include "calculadora.h"
#include "menu.h"
#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void calculadora(){
	t_pilha* pilha = getPilha(100);
	printf("=======================\n");
	printf("Modo Calculadora\n");
        printf("Pressione enter para continuar\n");
	getchar(); getchar();
	char valor[3];
	while(1){
		system("clear");
		printf("Quantidade de membros da pilha: %d\n", pilha->quantidade);
		printf("Digite 'exit' para sair\n");
		if(pilhaVazia(pilha)){
			printf("Pilha vazia!!\n");
		}else{
			imprimirPilha(pilha);
		}
		printf("->");
		do{
		scanf(" %s", valor);
		}while(validaOpcaoCalculadora(valor, 1) != 1);	
		
		if(valor[0] == '0' || valor[0] == '1' || valor[0] == '2' || valor[0] == '3' || valor[0] == '4' || valor[0] == '5' || valor[0] == '6' || valor[0] == '7' || valor[0] == '8' || valor[0] == '9'){
			push(pilha, atoi(valor));
		}else if(valor[0] == '+'){
			if(validaQuantidade(pilha)){
				int aux1 = pop(pilha);
				int aux2 = pop(pilha);
				push(pilha, aux1+aux2);
			}else{
				printf("Quantidade invalida de numeros para executar a operacao!\n");
				printf("Pressione enter para continuar\n");
				getchar(); getchar();
			}
		}else if(valor[0] == '-'){
			if(validaQuantidade(pilha)){
                                int aux1 = pop(pilha);
                                int aux2 = pop(pilha);
                                push(pilha, aux1-aux2);
                        }else{
                                printf("Quantidade invalida de numeros para executar a operacao!\n");
                                printf("Pressione enter para continuar\n");
                                getchar(); getchar();
                        }
		}else if(valor[0] == '*'){
                        if(validaQuantidade(pilha)){
                                int aux1 = pop(pilha);
                                int aux2 = pop(pilha);
                                push(pilha, aux1*aux2);
                        }else{
                                printf("Quantidade invalida de numeros para executar a operacao!\n");
                                printf("Pressione enter para continuar\n");
                                getchar(); getchar();
                        }
		}else if(valor[0] == '/'){
	                        if(validaQuantidade(pilha)){
                                int aux1 = pop(pilha);
                                int aux2 = pop(pilha);
                                push(pilha, aux1/aux2);
                        }else{
                                printf("Quantidade invalida de numeros para executar a operacao!\n");
                                printf("Pressione enter para continuar\n");
                                getchar(); getchar();
                        }

		}else if(!strcmp(valor, "exit")){
			exit(0);
		}else if(valor[0] == '!'){
			if(valor[1] == '+'){
				do{
					int aux1 = pop(pilha);
					int aux2 = pop(pilha);
					push(pilha, aux1+aux2);
				}while(pilha->quantidade != 1);
			}else if(valor[1] == '-'){
                                do{
                                        int aux1 = pop(pilha);
                                        int aux2 = pop(pilha);
                                        push(pilha, aux1-aux2);
                                }while(pilha->quantidade != 1);
	
			}else if(valor[1] == '*'){
                                do{
                                        int aux1 = pop(pilha);
                                        int aux2 = pop(pilha);
                                        push(pilha, aux1*aux2);
                                }while(pilha->quantidade != 1);
			}else{
				printf("Operador invalido!\n");	
			}
		}else{
			printf("Entrada invalida!\n");
		}
	}
}


int validaOpcaoCalculadora(char* opcao, int sequencia){
	if(opcao[0] != '0'){
		return 1;
	}else{
		printf("Inserção inválida!\n");
		return 0;
	}
	


}

int validaQuantidade(t_pilha* pilha){
//	printf("Quantidade de membros da pilha: %d\n", pilha->quantidade);
	if(pilha->quantidade >= 2){
		return 1;
	}else{
		return 0;
	}

}
