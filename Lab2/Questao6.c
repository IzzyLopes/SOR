#include <stdio.h>
#include <pthread.h>

int resultado;

struct inteiros {
	int x;
	int y;
};

void *ft(void *arg) {
	struct inteiros aux;
	
	aux = *(struct inteiros *)arg;
	resultado = aux.x + aux.y;
}

int main() {
	struct inteiros inteiro;
	inteiro.x = 10;
	inteiro.y = 5;
	
	pthread_t vt;
	pthread_create(&vt, NULL, &ft, &inteiro);
	pthread_join(vt, NULL);
	
	printf("Valor da soma de x+y = %d\n", resultado);	
	return 0;
}
