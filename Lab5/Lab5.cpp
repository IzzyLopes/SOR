#include <iostream>
#include <cstdlib>
#include <locale.h>
using namespace std;

#define MAX 50

typedef int tipoChave;

struct Registro {
	tipoChave ch;
	float preco;
};

struct Elemento {
	Registro reg;
	Elemento *prox;
};

typedef Elemento * PONT;  // Elemento *p == PONT p;

struct Lista {
	PONT inicio; // Ponteiro do tipo elemento que aponta para o in�cio
};

/* M�TODOS */
void initLista(Lista *l) {
	l->inicio = NULL;
}

int tamanhoLista(Lista *l) {
	PONT end = l->inicio;
	int tam = 0;
	
	while(end != NULL) {
		tam++;
		end=end->prox;
	}
	
	return tam;
}

void exibirElementosLista(Lista *l) {
	PONT end = l->inicio;
	int chave;
	
	if(end == NULL) {
		cout << "Nenhum produto cadastrado" << endl;
	}
	
	while(end != NULL) {
		cout << "Produto " << end->reg.ch << ", pre�o: " << end->reg.preco << endl;
		end = end->prox;
	}
}

PONT buscaSequencial(Lista *l, tipoChave chave) {
	PONT pos = l->inicio;
	
	while (pos != NULL) {
		if(pos->reg.ch == chave) {
			return pos;
		}
		
		pos = pos->prox;
	}
	
	return NULL;
}

// Se eu achar uma chave maior do que a chave procurada (a lista � ordenada) e significa que a chave procurada n�o existe
// Por isso o while agora verifica se a chave apontada pelo ponteiro ainda � menor que a chave procurada
void buscaOrdenada(Lista *l, tipoChave chave) {
	PONT pos = l->inicio;
	
	while ((pos != NULL) && (pos->reg.ch <= chave)) {
		if(pos->reg.ch == chave) {
			cout << "Produto de ID " << pos->reg.ch << ", preco: " << pos->reg.preco << endl;
			return;
		}
		
		pos = pos->prox;
	}
	
	cout << "Produto n�o encontrado." << endl;
}

// Fun��o de busca para saber qual o elemento anterior ao inserido, e qual elemento ele apontava para
// poder fazer as devidas altera��es de ponteiro squando forinserir um valor novo na Lista
PONT buscaForInsert(Lista *l, tipoChave chave, PONT* ant) {
	*ant = NULL;
	PONT atual = l->inicio;
	
	while((atual != NULL) && (atual->reg.ch < chave)) {
		*ant = atual;
		atual = atual->prox;
	}
	
	if((atual != NULL) && (atual->reg.ch == chave)) {
		return atual;
	}
	
	return NULL;
}

bool insertLista(Lista *l, Registro reg) {
	tipoChave chave = reg.ch;
	PONT ant, i;
	
	i = buscaForInsert(l, chave, &ant);
	
	if(i != NULL) {
		return false;
	}
	
	i = (PONT) malloc (sizeof (Elemento));
	i->reg = reg;
	
	if(ant == NULL) {
		l->inicio = i;
		i->prox = NULL;
	} else {
		i->prox = ant->prox; // Ter� que apontar para o pr�ximo do n�mero que vinha antes dele
		ant->prox = i;		 // E o pr�ximo do anterior deveria apontar para ele
	}
	
	return true;
}

bool excluirLista(Lista *l, Registro reg) {
	tipoChave chave = reg.ch;
	PONT ant, i;
	
	i = buscaForInsert(l, chave, &ant);
	
	if(i != NULL) {
		if(ant == NULL) {
			l->inicio = i->prox; // Se ele n�o tiver anterior, o in�cio da lista agora aponta para o pr�ximo
		} else {
			ant->prox=i->prox; 	 // O elemento anterior, apontar� para o pr�ximo do elemento que est� sendo exclu�do
		}
		free(i); 				// Comando para liberar a mem�ria
		return true;
	} 
	
	return false;
}

void apresentarMenu() {
	cout << "MENU" << endl;
	cout << "0 -> Sair" << endl;
	cout << "1 -> Inserir Produto" << endl;
	cout << "2 -> Mostrar quantidade de produtos" << endl;
	cout << "3 -> Procurar produto por id" << endl;
	cout << "4 -> Mostrar todos os produtos" << endl;
	cout << "5 -> Eliminar um produto da lista" << endl;
	
	cout << "\nSelecione sua a��o: ";
}

/* MAIN */
int main() {
	setlocale (LC_ALL, "Portuguese");
	Lista lista;
	initLista(&lista);
	
	Registro reg;
	tipoChave id;
	float valor;
	
	int entrada;
	apresentarMenu();
	cin >> entrada;
	
	while (entrada != 0) {
		cout << "\n";
		switch(entrada) {
			case 1:
				cout << "Insira o id do produto: ";
				cin >> reg.ch;
				cout << "Insira o preco do produto: ";
				cin >> reg.preco;
				
				if(insertLista(&lista, reg) == false) {
					cout << "J� existe um produto com esse ID cadastrado." << endl;
				}
				
				reg.ch = 0;
				reg.preco = 0.0;
				break;
			
			case 2:
				cout << "A lista cont�m " << tamanhoLista(&lista) << " produtos." << endl;
				break;
				
			case 3:
				cout << "Selecione o ID do produto que deseja buscar: ";
				cin >> id;
				buscaOrdenada(&lista, id);
				id=0;
				break;
				
			case 4:
				exibirElementosLista(&lista);
				break;
				
			default:
				cout << "Insira o id do produto: ";
				cin >> reg.ch;
				
				if(excluirLista(&lista, reg) == false) {
					cout << "O produto com ID " << reg.ch << " n�o existe." << endl;
				} else {
					cout << "O produto foi exclu�do com sucesso." << endl;
				}
				break;
		}
		
		cout << "\n";
		system("pause");
		system("cls");
		apresentarMenu();
		cin >> entrada;
	}

	return 0;
}
