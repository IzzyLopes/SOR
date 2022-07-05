#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int y = 5;

void *ft(void *A) { //função a ser executada pela thread, qunado a thread for criada
	printf("Thread: eu sou uma thread nova, nasci para modificar o valor de y \n");
	
	int b=50;
	y=b;			// tese para saber se essa variavel global é alterada pela thread
					
	printf("Thread: Terminei minha missão, agora vou finalizar \n");
}

int main() {
	pthread_t t1;
	printf("Main1: vou criar uma nova thread\n");
	pthread_create(&t1, NULL, &ft, NULL);
	pthread_join(t1, NULL);
	printf("Main2: a thread finalizou\n");
	printf("\nMain3: será que a thread conseguiu modificar y? \n");
	printf("Main3: veremos y = %d \n", y);	
	return 0;
}
