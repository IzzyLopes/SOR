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
	PONT inicio; // Ponteiro do tipo elemento que aponta para o início
};

/* MÉTODOS */
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

// Se eu achar uma chave maior do que a chave procurada (a lista é ordenada) e significa que a chave procurada não existe
// Por isso o while agora verifica se a chave apontada pelo ponteiro ainda é menor que a chave procurada
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

// Função de busca para saber qual o elemento anterior ao inserido, e qual elemento ele apontava para
// poder fazer as devidas alterações de ponteiro squando forinserir um valor novo na Lista
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
		i->prox = ant->prox; // Terá que apontar para o próximo do número que vinha antes dele
		ant->prox = i;		 // E o próximo do anterior deveria apontar para ele
	}
	
	return true;
}

bool excluirLista(Lista *l, Registro reg) {
	tipoChave chave = reg.ch;
	PONT ant, i;
	
	i = buscaForInsert(l, chave, &ant);
	
	if(i != NULL) {
		if(ant == NULL) {
			l->inicio = i->prox; // Se ele não tiver anterior, o início da lista agora aponta para o próximo
		} else {
			ant->prox=i->prox; 	 // O elemento anterior, apontará para o próximo do elemento que está sendo excluído
		}
		free(i); 				// Comando para liberar a memória
		return true;
	} 
	
	return false;
}

void reinicializarLista(Lista *l) {
	PONT end = l->inicio;

	while(end!=NULL) {
		PONT apagar = end;		// Utiliza o ponteiro apagar para conseguir excluir o elemento da lista e permitir que o ponteiro end consiga percorrer a lista inteira
		end = end->prox ;	
		free(apagar);
	}

	l->inicio= NULL;
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
