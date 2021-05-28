
#include <stdio.h>
#include <stdlib.h>
    
  typedef struct sElement{
    struct sElement *next;
    int dado; 
} Element;

    
  typedef struct sList{
	struct sElement *head;
	struct sElement *tail;
	int size;
} List;

List* createList(); 
Element* createElement(int); 
void insertList(List*, Element*, int);
int removeList(List*, Element*);
void showList(List*);
Element* searchList(List*, int dado);
void deleteList(List*);

int main(){
        int dado=0;
        int aux;
        
        printf("Criando List de numeros inteiros\n");
        List* List_int;
        List_int = createList();
        
        printf("Inserindo Dados na lista de numeros inteiros\n");
		aux = rand();
		insertList(List_int,NULL , aux);
		aux = rand();
        insertList(List_int,List_int->tail ,aux);
        aux = rand();
        insertList(List_int,List_int->head ,aux);
        
        printf("List atual:");
        showList(List_int);
       
        printf("Tamanho da lista: %i\n",List_int->size);
        printf("\t Head: %i\n",List_int->head->dado);
        printf("\t Tail: %i\n",List_int->tail->dado);
        
        printf("Removendo dados\n");
        dado=removeList(List_int,NULL);
        printf("Quem foi excluido %i\n",dado);
        printf("Tamanho da lista: %i\n",List_int->size);
        printf("\t Head: %i\n",List_int->head->dado);
        printf("\t Tail: %i\n",List_int->tail->dado);
        
        printf("List atual:");
        showList(List_int);
        
        Element *pivo = searchList(List_int,aux);
        printf("Buscando %i na List :%i", aux, pivo->dado);
        deleteList(List_int);
}

List* createList(){
        List* l=(List*) malloc(sizeof(List));
        l->head = NULL;
        l->tail = NULL;
        l->size =0;
        
        return l;
}

Element* createElement(int dado){
        Element* e;
        e = (Element*) malloc(sizeof(Element));
        e->next = NULL;
        e->dado = dado;
        
        return e;
}

void insertList(List* List, Element* pivo, int dado){
    Element* novo;
    novo = createElement(dado);

    if(pivo == NULL){
        if(List->size==0){
            List->tail = novo;
        }    
        
        novo->next = List->head;
        List->head =novo;
    } else {
        if(pivo->next==NULL){
            List->tail = novo;
        }
        novo->next=pivo->next;
        pivo->next=novo;
    }
    List->size++;
}

int removeList(List* List, Element* pivo){
    int dado;
    Element* antigo;

    if(List->size==0){
        return -1;
    }
     
    if(pivo==NULL){
        antigo= List->head;
        List->head=List->head->next;
        
        if(List->head==NULL){
            List->tail=NULL;
        }
    }else{
        if(pivo->next ==NULL){
        return -2;
    }
        
        antigo=pivo->next;
        pivo->next=pivo->next->next;
    
        if(pivo->next==NULL){
            List->tail=pivo;
        }
    }

    dado=antigo->dado;
    free(antigo);
    List->size--;
    return dado;
}

void showList(List* List){
    Element* e;
    e= List->head;
        
    while(e !=NULL){
        printf("Element: %i ->",e->dado);
        e=e->next;
    }
    printf("NULL\n");
}

Element* searchList(List* List, int dado){
    Element* e;
    e= List->head;
        
    while(e !=NULL){
        if(e->dado==dado){
            return e;   
        }
        e=e->next;
    }
    return NULL;
}

void deleteList(List* List){
    int dado;
    while(List->size>0){
        dado=removeList(List,NULL);
        printf("\nElement Excluido :%i, Tamanho da List:%i",dado, List->size);
    }
    free(List);
}
