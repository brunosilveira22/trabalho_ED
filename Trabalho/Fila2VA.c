#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct node No;
typedef struct node NoPref;

struct node {
	int id;
	char nome[20];
	No *prox;
};

No *inicio, *final;
NoPref *inicioPref, *finalPref;

void iniciarFila();
void iniciarFilaPref();
int estaVazia();
int estaVaziaPref();

No *alocarNovoNo();
NoPref *alocarNovoNoPref();

void inserir();
void inserirPref();
void remover();
void removerPref();
void imprimir();
void imprimirPref();
void menuEscolha();
void executar();
void executarPref();
void movimentarComum();
void movimentarPref();

int main(){
	
	setlocale(LC_ALL,"portuguese");
	
	iniciarFila();
	iniciarFilaPref();
	
	menuEscolha();
	
}

void menuEscolha(){
	int resp=0,r,i=0,j;
	
	while(resp != 6){
		printf("\n======== Fila de Processos ========\n");
		printf("\n1. Inserir processo.");
		printf("\n2. Executar processo.");
		printf("\n3. Remover processo.");
		printf("\n4. Imprimir filas.");
		printf("\n5. Movimentar processo entre filas.");
		printf("\n6. Sair.\n");
		printf("\n Escolha uma opção: ");
		scanf("%d", &resp);
		system("cls");
		
		switch(resp) {
			case 1: 
				i = 0;
				while(i==0){
					printf("\n======== Inserir Processo ========\n");
					printf("\nO processo será colocado na fila comum(1) ou preferencial(2): ");
					scanf("%d",&r);
					
					if(r == 1){
						inserir();
						i = 1;
					}else if(r == 2) {
						inserirPref();
						i = 1;
					} else{
						printf("\nInsira uma opção válida.\n\n");
						i = 0;
						system("pause");
						system("cls");
					}
				}
				printf("\n");
				system("pause");
				system("cls");
					
			break;
			
			case 2:
				if(estaVaziaPref()){
					executar();
				}else{
					executarPref();
				}
				printf("\nProcesso executado.\n");
				system("pause");
				system("cls");
			break;
			
			case 3:
				if(estaVaziaPref()){
					remover();
				} else {
					removerPref();
				}
				printf("\nProcesso removido.\n");
				system("pause");
				system("cls");
			break;
			
			case 4:
				printf("\n======== Imprimir Filas ========\n");
				imprimir();
				imprimirPref();
				printf("\n");
				system("pause");
				system("cls");
			break;
			
			case 5:
				printf("\n======== Movimentar Processo Entre Filas ========\n");
				printf("\nEscolha a fila de origem para mover o processo: \n");
				if(estaVazia()){
					printf("\nA fila comum está vazia.\n\n");
				}
				if(estaVaziaPref()){
					printf("\nA fila preferencial está vazia.\n\n");
				}
				printf("\nFila comum(1), Fila preferencial(2): ");
				scanf("%d", &j);
				if(j==1){
					movimentarComum();
				} else {
					movimentarPref();
				}
				printf("\n");
				system("pause");
				system("cls");
			break;
			
			default: 6;
	    }
	}
}

void iniciarFila(){
	inicio = NULL;
	final = NULL;
}

void iniciarFilaPref(){
	inicioPref = NULL;
	finalPref = NULL;
}

int estaVazia(){
	if(inicio == NULL){
		return 1;
	} else {
		return 0;
	}
}

int estaVaziaPref(){
	if(inicioPref == NULL){
		return 1;
	} else {
		return 0;
	}
}

No *alocarNovoNo(){
	No *novoNo = (No *) malloc(sizeof(No));
	
	printf("\nInforme o ID do produto: ");
	scanf("%d", &novoNo->id);
	
	printf("Informe o nome do produto: ");
	fflush(stdin);
	gets(novoNo->nome);
	
	novoNo->prox = NULL;
	
	return novoNo;
}

NoPref *alocarNovoNoPref(){
	NoPref *novoNoPref = (NoPref *) malloc(sizeof(NoPref));
	
	printf("\nInforme o ID do produto: ");
	scanf("%d", &novoNoPref->id);
	
	printf("Informe o nome do produto: ");
	fflush(stdin);
	gets(novoNoPref->nome);
	
	novoNoPref->prox = NULL;
	
	return novoNoPref;
}

void inserir(){
	
	No *novoNo = alocarNovoNo();
	
	if(estaVazia()){
		inicio = novoNo;
		final = novoNo;
	} else {
		final->prox = novoNo;
		final = novoNo;
	}
}

void inserirPref(){
	
	NoPref *novoNoPref = alocarNovoNoPref();
	
	if(estaVaziaPref()){
		inicioPref = novoNoPref;
		finalPref = novoNoPref;
	} else {
		finalPref->prox = novoNoPref;
		finalPref = novoNoPref;
	}
}

void imprimir(){
	
	No *atual = inicio;
	
	printf("\n======== Fila Comum ========\n");
	
	if(estaVazia()){
		printf("\nA fila está vazia.\n\n");
	} else {
		while(atual != NULL){
			printf("\nID do produto: %d \tNome do produto: %s \n", atual->id, atual->nome);
			atual = atual->prox;
		}
	}
}

void imprimirPref(){
	
	NoPref *atualPref = inicioPref;
	
	printf("\n======== Fila Preferencial ========\n");
	
	if(estaVaziaPref()){
		printf("\nA fila está vazia.\n\n");
	} else {
		while(atualPref != NULL){
			printf("\nID do produto: %d \tNome do produto: %s \n", atualPref->id, atualPref->nome);
			atualPref = atualPref->prox;
		}
	}
}

void remover(){
	if(estaVazia()){
		printf("\nA fila está vazia.\n\n");
	} else {
		No *apagar = inicio;
		inicio = apagar->prox;
		free(apagar);
	}
}

void removerPref(){
	if(estaVaziaPref()){
		printf("\nA fila está vazia.\n\n");
	} else {
		NoPref *apagarPref = inicioPref;
		inicioPref = apagarPref->prox;
		free(apagarPref);
	}
}

void executar(){
	No *apagar;
	if(estaVazia()){
		printf("\nA fila está vazia.\n\n");
	} else {
		apagar = inicio;
		inicio = apagar->prox;
	}
	
	No *novoNo = (No *) malloc(sizeof(No));
	fflush(stdin);
	novoNo->id = apagar->id;
	strcpy(novoNo->nome, apagar->nome);
	
	free(apagar);
		
	novoNo->prox = NULL;
	
	if(estaVazia()){
		inicio = novoNo;
		final = novoNo;
	} else {
		final->prox = novoNo;
		final = novoNo;
	}
}

void executarPref(){
	NoPref *apagarPref;
	if(estaVaziaPref()){
		printf("\nA fila está vazia.\n\n");
	} else {
		apagarPref = inicioPref;
		inicioPref = apagarPref->prox;
	}
	
	No *novoNo = (No *) malloc(sizeof(No));
	fflush(stdin);
	novoNo->id = apagarPref->id;
	strcpy(novoNo->nome, apagarPref->nome);
	
	free(apagarPref);
		
	novoNo->prox = NULL;
	
	if(estaVazia()){
		inicio = novoNo;
		final = novoNo;
	} else {
		final->prox = novoNo;
		final = novoNo;
	}
}

void movimentarComum(){
	No *atual = inicio;
	No *anterior = NULL;
	int id;
	printf("\n======== Fila Comum ========\n");
	
	if(estaVazia()){
		printf("\nA fila está vazia.\n\n");
	} else {
		printf("\nInforme o id do processo que você está querendo mover: ");
		scanf("%d", &id);
		while(atual != NULL){
			if(atual->id == id){
				
				anterior->prox = atual->prox;				
			
				NoPref *novoNoPref = (NoPref *) malloc(sizeof(NoPref));
				
				novoNoPref->id = atual->id;
				strcpy(novoNoPref->nome, atual->nome);
				
				free(atual);
					
				novoNoPref->prox = NULL;
				
				if(estaVaziaPref()){
					inicioPref = novoNoPref;
					finalPref = novoNoPref;
				} else {
					finalPref->prox = novoNoPref;
					finalPref = novoNoPref;
				}
			}
			anterior = atual;
			atual = atual->prox;
		}
	}
}

void movimentarPref(){
	NoPref *atualPref = inicioPref;
	NoPref *anteriorPref = NULL;
	int id;
	printf("\n======== Fila Preferencial ========\n");
	
	if(estaVaziaPref()){
		printf("\nA fila está vazia.\n\n");
	} else {
		printf("\nInforme o id do processo que você está querendo mover: ");
		scanf("%d", &id);
		while(atualPref != NULL){
			if(atualPref->id == id){
				anteriorPref->prox = atualPref->prox;
				
				No *novoNo = (No *) malloc(sizeof(No));
				fflush(stdin);
				novoNo->id = atualPref->id;
				strcpy(novoNo->nome, atualPref->nome);
				
				free(atualPref);
					
				novoNo->prox = NULL;
				
				if(estaVazia()){
					inicio = novoNo;
					final = novoNo;
				} else {
					final->prox = novoNo;
					final = novoNo;
				}
			}
			anteriorPref = atualPref;
			atualPref = atualPref->prox;
		}
	}
}






