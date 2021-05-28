#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
    
typedef struct sElemento{
    struct sElemento *next;
    struct sElemento *prev;
	int dado; 
} Elemento;

    
typedef struct sListaDupla{
	struct sElemento *head;
	struct sElemento *tail;
	int size;
} Lista;

void startList(Lista *pList){
	pList->head= NULL;
	pList->tail= NULL;
	pList->size= 0;
}

void insertList(Lista *pList, int dado = NULL){
	if(dado == NULL){
		Elemento *novo;
		
		novo = new Elemento;
		
		printf("Digite o valor:");
		scanf("%d", &novo->dado);
		
		novo->next = NULL;
		novo->prev = NULL;
		
		if(pList->head == NULL){
			pList->head = novo;
			pList->tail = novo;
		}else{
			pList->head->prev = novo;
			novo->next = pList->head;
			pList->head = novo;
		}
		
		pList->size++;
	}else{
	
	}
}


void showListHead(Lista *pList){
	Elemento *aux;
	
	if(pList->head == NULL){
		printf("Lista vazia");
	}else{
		aux = pList->head;
		while (aux !=NULL){
			printf("Dado = %d\n", aux->dado);
			aux = aux->next;
		}
		printf("Fim da lista\n");		
	}
	getch();
}

void showListTail(Lista *pList){
	Elemento *aux;
	
	if(pList->tail == NULL){
		printf("Lista vazia");
	}else{
		aux = pList->tail;
		while (aux !=NULL){
			printf("Dado = %d\n", aux->dado);
			aux = aux->prev;
		}
		printf("Fim da lista\n");		
	}
	getch();
}

void findListHead(Lista *pList, int valor){
	Elemento *aux;
	
	if(pList->head == NULL){
		printf("Lista vazia");
	}else{
		aux = pList->head;
		while (aux !=NULL){
			if(aux->dado == valor){
				printf("Encontrado valor %i na lista", valor);
			}
			aux = aux->next;
		}
		printf("Fim da lista\n");		
	}
	getch();
}

void findListTail(Lista *pList, int valor){
	Elemento *aux;
	
	if(pList->tail == NULL){
		printf("Lista vazia");
	}else{
		aux = pList->tail;
		while (aux !=NULL){
			if(aux->dado == valor){
				printf("Encontrado valor %i na lista", valor);
			}
			aux = aux->prev;
		}
		printf("Fim da lista\n");		
	}
	getch();
}

int removeList(Lista *pList, int valor){

}


int main(){
	
	Lista listaDupla;
	startList(&listaDupla);
}

