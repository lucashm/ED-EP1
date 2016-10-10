#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>


//---------------------------------------------
char topo(t_pilha* pilha){

    if(pilhaVazia(pilha)){
        return 0;
    }

    return pilha->item[pilha->topo];
}//end 


//---------------------------------------------
void imprimirPilha(t_pilha* pilha){
    int i;

    if(pilhaVazia(pilha)){
        printf("Pilha Vazia!\n");
        return;
    }

    printf("++++++++++++++++++++++++++\n");
    for(i = pilha->topo; i > VAZIA; i--)
        printf("%d. %d\n", i, pilha->item[i]);
    
}


//---------------------------------------------
void push( t_pilha* pilha, int valor){
	printf("Realizando push\n");
    if( pilhaCheia(pilha) ){
        printf("Ocorreu overflow na pilha!\n");
        liberaPilha(pilha);
        exit(1);
    }  
	pilha->quantidade++;
    pilha->item[++pilha->topo] = valor;

}//end push()

//---------------------------------------------
int  pop(t_pilha* pilha){
    	printf("Realizando pop\n");
    if(pilhaVazia(pilha)){
        printf("Ocorreu underflow na pilha!\n");
        liberaPilha(pilha);
        exit(1);
    }
	pilha->quantidade--;
    return pilha->item[pilha->topo--];
}//end pop()



//---------------------------------------------
int pilhaVazia(t_pilha* pilha){
    return ( pilha->topo == VAZIA );
}//end pilhaVazia()

//---------------------------------------------
int pilhaCheia(t_pilha* pilha){
    return ( pilha->topo == pilha->tamanho );
}//end pilhaCheia()


//---------------------------------------------
t_pilha* getPilha(int tamanho){
    t_pilha* retorno = (t_pilha *) malloc(sizeof(t_pilha));
    retorno->item    = (int *) malloc(tamanho*sizeof(int));
    retorno->tamanho = tamanho;
    retorno->topo    = VAZIA;
	retorno->quantidade = 0;
    return retorno;
}//end getPilha();


//---------------------------------------------
void liberaPilha(t_pilha* pilha){
    free(pilha->item);
    free(pilha);

}//end liberaPilha()
