#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 50

typedef int tipoChave;

struct Registro {
	tipoChave ch;
	// outros
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
	
	while(end != NULL) {
		cout << end->reg.ch;
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
PONT buscaOrdenada(Lista *l, tipoChave chave) {
	PONT pos = l -> inicio;
	
	while (pos != NULL && pos->reg.ch < chave) {
		if(pos->reg.ch == chave) {
			return pos;
		}
		
		pos = pos->prox;
	}
	
	return NULL;
}

// Fun��o de busca para saber qual o elemento anterior ao inserido, e qual elemento ele apontava para
// poder fazer as devidas altera��es de ponteiro squando forinserir um valor novo na Lista
PONT buscaForInsert(Lista *l, tipoChave chave, PONT* ant) {
	*ant = NULL;
	PONT atual = l->inicio;
	
	while((atual != NULL) && (*atual->reg.ch < chave)) {
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
	
	i = buscaForInsert(l, ch, &ant);
	
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

/* MAIN */
int main() {
	Lista lista;
	initLista(&lista);
	
	int t;
	t=tamanhoLista(&lista);
	cout << t << endl;
	
	cout << buscaSequencial(&lista, 12) << endl;
	cout << buscaOrdenada(&lista, 12) << endl;
	
	return 0;
}
