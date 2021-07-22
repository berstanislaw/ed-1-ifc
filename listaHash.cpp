#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

typedef struct sElemento{
    char dado[50];
    struct sElemento *next;
    struct sElemento *prev;
} Elemento;

typedef struct sChave{
    struct sChave *prev;
    struct sChave *next;
    int chave;
    
    //lista
    Elemento *head;
    Elemento *tail;
    int size;
} Chave;

typedef struct sLista{
    int size;
    struct sChave *head;
    struct sChave *tail;
} Lista;

int menu(Lista*);
int opcoesMenu();

void espalhaNomes(Lista*);
void insereLista(Lista*, int, Chave*);
void imprimeListas(Lista*);
void imprimeLista(Lista*);
void insereNome(Lista*, char*, int);
void insereNomeManual(Lista*);
void buscarNome(Lista*);
void deletarNome(Lista*);
void ordenaLista(Lista*);

int calculaHash(char*, int);


void quicksort(Elemento*, Elemento*);
void swap(Elemento*, Elemento*);

Lista* criaLista();
Chave* criaChave(int);
Chave* encontraChave(Lista*, int);
Elemento* criaElemento(char*);

int main(void){
	int aux;
	Lista* listaChaves = criaLista();
	
	menu(listaChaves);
}

int menu(Lista* listaChaves){
	setlocale(LC_ALL, "Portuguese");
	int escolha;
	
	while(escolha != 7){
		escolha = opcoesMenu();
		switch(escolha){
			case 0:
				printf("Espalhando nomes\n\n");
				espalhaNomes(listaChaves);
				getch();
				system("cls");
			break;
			case 1:
				printf("Inserindo o nome manualmente\n\n");
				insereNomeManual(listaChaves);
				getch();
				system("cls");
			break;
			case 2:
				printf("Imprimir uma lista\n\n");
				imprimeLista(listaChaves);
				getch();
				system("cls");
			break;
			case 3:
				printf("Buscando um nome\n\n");
				buscarNome(listaChaves);
				getch();
				system("cls");
			break;
			case 4:
				printf("Removendo um dado\n\n");
				deletarNome(listaChaves);
				getch();
				system("cls");
			break;	
			case 5:
				printf("Elementos por chave\n\n");
				imprimeListas(listaChaves);
				getch();
				system("cls");
			break;
			case 6:
				printf("Ordenando lista\n\n");
				ordenaLista(listaChaves);
				getch();
				system("cls");
			break;
		}
	}
}

int opcoesMenu(){
	int escolha = 0;
	
	printf("\t\t\t\t\t\t Tabela Hash\n\n");
	printf("0 - Inserir os dados do arquivo nomes\n");
	printf("1 - Inserir nome manualmente\n");
	printf("2 - Printar uma lista\n");
	printf("3 - Buscar um elemento\n");
	printf("4 - Remover um elemento\n");
	printf("5 - Quantidade de elementos por chaves\n");
	printf("6 - Ordenar elementos via quick sort\n");
	printf("7 - Fechar programa\n");
	printf("\n\n");
	printf("Digite a opção desejada:  ");
	scanf("%i",&escolha);
	
	system("cls");
	
	return escolha;
}

Lista* criaLista(){
	Lista* listaChaves = (Lista*) malloc(sizeof(Lista));
	
	listaChaves->size = 0;
	listaChaves->head = NULL;
	listaChaves->tail = NULL;
}

void espalhaNomes(Lista* listaChaves){
	int tam, i, chave;
	char nome[50];
	char *result;
	
	printf("Qual o tamanho da lista: ");
	scanf("%i", &tam);
	
	for(i = 0; i < tam; i++){
		insereLista(listaChaves, i, NULL);
	}
	
	printf("Adicionando nomes a lista de elementos\n");
    FILE *file = fopen("nomes.txt", "r");
    
    if (file == NULL){
    	printf("Problemas na abertura do arquivo\n");
    	return;
	}
	
	while(!feof(file)){
		result = fgets(nome, 50, file);
		result[strcspn(result, "\n")] = 0;
		
		chave = calculaHash(result, tam);
		insereNome(listaChaves, result, chave);
	}
	
	printf("\nNomes inseridos com sucesso");
}

Chave* criaChave(int id){
    Chave* chave = (Chave*) malloc(sizeof(Chave));
	
	chave->next = NULL;
	chave->next = chave->prev = NULL;
	chave->chave = id;
	
	chave->head = NULL;
	chave->tail = NULL;
	chave->size = 0;
	
	return chave;
}

Elemento* criaElemento(char *nome){
	Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
	
	strcpy(elemento->dado, nome);
	elemento->next = NULL;
	elemento->next = elemento->prev = NULL;
	
	return elemento;
}

void insereLista(Lista* listaChave, int chave, Chave* pivo){
	Chave* nova = criaChave(chave);
	
	if(listaChave->size == 0){
		listaChave->head = nova;
		listaChave->tail = nova;
	} else if(pivo == NULL) {
		listaChave->tail->next = nova;
		nova->prev = listaChave->tail;
		listaChave->tail = nova;
	}
	listaChave->size++;
}

void imprimeListas(Lista* listaChaves){
	int i;
	Chave* aux;
	
	aux = listaChaves->head;
	for(i = 0; i < listaChaves->size; i++){
		printf("\nChave %i | Tamanho : %i",aux->chave, aux->size);
		aux = aux->next;
	}
}

void imprimeLista(Lista* listaChave){
	Chave* chaveLista;
	Elemento* nome;
	int lista, i;
	
	printf("Qual lista deseja imprimir :");
	scanf("%i", &lista);
	
	chaveLista = encontraChave(listaChave, lista);
	
	nome = chaveLista->head;
	for(i = 0; i < chaveLista->size; i++){
		printf("\n %i | %s", i ,nome->dado);
		nome = nome->next;
	}
	
	printf("\n\nElementos da lista %i", chaveLista->chave);
}

void buscarNome(Lista* listaChave){
	Chave* chaveLista;
	Elemento* aux2;
	int hash, i;
	char nome[50];
	
	printf("Qual elemento deseja procurar:");
	scanf("%s", nome);
	
	
	hash = calculaHash(nome, listaChave->size);
	
	chaveLista = encontraChave(listaChave, hash);
	
	aux2 = chaveLista->head;
	for(i = 0; i < chaveLista->size; i++){
		if(strcmp(aux2->dado, nome) == 0 ){
			printf("Nome %s esta na chave %i", aux2->dado, chaveLista->chave);
			break;
		}
		
		if(aux2->next != NULL){
			aux2 = aux2->next;
		}else{
			printf("Elemento não esta na lista");
		}
	}
}

void deletarNome(Lista* listaChave){
	Chave* chaveLista;
	Elemento* elemento;
	int hash, i;
	char nome[50];
	
	printf("Qual elemento deseja remover:");
	scanf("%s", nome);
	
	hash = calculaHash(nome, listaChave->size);
	
	chaveLista = encontraChave(listaChave, hash);
	
	elemento = chaveLista->head;
	if(chaveLista->size == 0){
        printf("Elemento não existe!\n");
    }else{
		while(elemento != NULL){
            if(strcmp(elemento->dado, nome) == 0){	
                if(elemento == chaveLista->head){
                    chaveLista->head = elemento->next;
                    if(chaveLista->head == NULL){
                        chaveLista->tail = NULL;
                    }else{
                        elemento->next->prev = NULL;
                    }
                }else{
                    elemento->prev->next = elemento->next;
                    if(elemento->next == NULL){
                        chaveLista->tail = elemento->prev;
                    }else{
                        elemento->next->prev = elemento->prev;
                    }
                }
                printf("Nome %s foi removido da chave %i \n", nome, chaveLista->chave);
				elemento = NULL;
                chaveLista->size--;
			}else{
            	elemento = elemento->next;
            }
        }
    }
}

void insereNome(Lista* listaChaves, char *nome, int chave){
	Chave* chaveLista;
	Elemento* novo;
	novo = criaElemento(nome);
	
	chaveLista = encontraChave(listaChaves, chave);
	
	if(chaveLista->size == 0){
		chaveLista->head = novo;
		chaveLista->tail = novo;
	} else {
		chaveLista->tail->next = novo;
		novo->prev = chaveLista->tail;
		chaveLista->tail = novo;
	}
	chaveLista->size++;
}

void insereNomeManual(Lista* listaChave){
	char nome[50];
	int chave;
	
	printf("Qual nome deseja inserir: ");
	scanf("%s", nome);
	
	chave = calculaHash(nome, listaChave->size);
	
	insereNome(listaChave, nome, chave); 
	
	printf("%s inserido na lista %i", nome, chave);
}

int calculaHash(char* nome, int tamanho){
	int soma,j;
	soma = 0;
	for (j = 0; j < strlen(nome); j++){
    	soma = (31 * soma + (int) nome[j]) % tamanho;
	}
	return soma;
}

void ordenaLista(Lista* listaChave){
	int chave;
	Chave* chaveLista;
	
	printf("Qual lista deseja ordenar:");
	scanf("%i", &chave);
	
	chaveLista = encontraChave(listaChave, chave);
	
	quicksort(chaveLista->head, chaveLista->tail);
}

Chave* encontraChave(Lista* listaChave, int chave){
	Chave* aux;
	
	aux = listaChave->head;
	while(aux->chave != chave){
		aux = aux->next;
	}
	
	return aux;
}

void swap(Elemento* a, Elemento* b){
	char* aux = (char*) malloc(sizeof(char) * 50);
  	
	strcpy(aux, a->dado);
	strcpy(a->dado, b->dado);
	strcpy(b->dado, aux);
}

void quicksort(Elemento* start, Elemento* end){
  if (end != NULL && start != end && start != end->next){
    Elemento* i = start->prev;
    Elemento* pivo = end;

    for (Elemento *j = start; j != end; j = j->next){
      if (strcmp(j->dado, pivo->dado) < 0){
        i = (i == NULL ? start : i->next);
        swap(i, j);
      }
    }
    
    i = (i == NULL ? start : i->next);
    swap(i, pivo);

    quicksort(start, i->prev);
    quicksort(i->next, end);
  }
}

