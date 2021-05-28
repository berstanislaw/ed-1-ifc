#include <stdio.h>
#include <stdlib.h>
    
typedef struct sElemento{
    struct sElemento *next;
    struct sElemento *prev;
	int dado; 
} Elemento;

    
typedef struct sLista{
	struct sElemento *head;
	struct sElemento *tail;
	int size;
} Lista;

Lista* criaLista(); 
Elemento* criaElemento(int); 
void insertList(Lista*, Elemento*, int);
int removeList(Lista*, Elemento*);
void showListHead(Lista*);
void showListTail(Lista*);
Elemento* findListHead(Lista*, int valor);
Elemento* findListTail(Lista*,int valor);
void deleteList(Lista*);

int main(){
	int dado=0;
	int aux;
	
    Lista* list;
    list = criaLista();
    
    printf("Inserindo dados\n");
    aux = rand();
    insertList(list,NULL ,aux);
    aux = rand();
    insertList(list,list->tail ,aux);
    aux = rand();
    insertList(list,list->head ,aux);
    aux = rand();
    insertList(list,list->head ,aux);
    
    printf("Lista:\n");
    showListHead(list);
    printf("Lista Inversa:\n");
    showListTail(list);    
    printf("Tamanho da lista:%i\n",list->size);
    printf("Head:%i\n",list->head->dado);
    printf("Tail:%i\n\n",list->tail->dado);   

    dado=removeList(list,NULL);    
    printf("Excluindo dado: %i\n\n",dado);
    printf("Tamanho da lista:%i\n",list->size);
    printf("Lista atualizada:\n");
    showListHead(list);
    
    Elemento *pivo = findListTail(list, aux);
    printf("Buscando %i na lista:%i\n\n", aux, pivo->dado);
    
    printf("Excluindo lista\n");
    deleteList(list);
	
}

Lista* criaLista(){
    Lista* list=(Lista*) malloc(sizeof(Lista));
    list->head = NULL;
    list->tail = NULL;
    list->size =0;
        
    return list;
}

Elemento* criaElemento(int dado){
        Elemento* e;
        e = (Elemento*) malloc(sizeof(Elemento));
        e->next = NULL;
        e->prev=NULL;
        e->dado = dado;
        
        return e;
}

void insertList(Lista* pList, Elemento* pivo, int dado){
    Elemento* novo;
    novo = criaElemento(dado);
   
    if(pivo == NULL && pList->size > 0){
        printf("\n So e possivel inserir o pivo NULL com lista vazia");
	}

	if(pList->size==0){
	 pList->head  = novo;
	 pList->tail = novo;
	}else{
    	novo->next = pivo->next;
		novo->prev = pivo;
		if (pivo->next == NULL){
	 	 pList->tail = novo;
		}else{
		pivo->next->prev = novo;
	}
		pivo->next = novo;
	  }

pList->size++;
}

int removeList(Lista* pList, Elemento* pivo){
    int dado;
    Elemento* aux;

    if(pList->size==0){
        return -1;
    }
     
    if(pivo==NULL){
        aux= pList->head;
        pList->head=pList->head->next;
        
        if(pList->head==NULL){
            pList->tail=NULL;
        }
    }else{
        if(pivo->next ==NULL){
        return -2;
    }
        
        aux=pivo->next;
        pivo->next=pivo->next->next;
    
        if(pivo->next==NULL){
            pList->tail=pivo;
        }
    }

    dado=aux->dado;
    free(aux);
    pList->size--;
    return dado;
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
		printf("Fim da lista\n\n");		
	}
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
		printf("Fim da lista\n\n");		
	}
}

Elemento* findListHead(Lista *pList, int valor){
	Elemento* e;
    e= pList->head;
        
    while(e !=NULL){
        if(e->dado==valor){
            return e;   
        }
        e=e->next;
    }
    return NULL;
}

Elemento* findListTail(Lista *pList, int valor){
	Elemento* e;
    e= pList->tail;
        
    while(e !=NULL){
        if(e->dado == valor){
            return e;   
        }
        e=e->prev;
    }
    return NULL;
}

void deleteList(Lista* pList){
    int dado;
    while(pList->size > 0){
        dado=removeList(pList,NULL);
        printf("\nExcluindo :%i \tTamanho da lista:%i",dado, pList->size);
    }
    free(pList);
}

