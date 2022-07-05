#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *ft(void *A) { //fun��o a ser executada pela thread, qunado a thread for criada
	printf("Thread: eu sou uma thread nova, nasci para modificar o valor de x \n");
	
	int b=50;
	*(int *)A=b; 	// converte o ponteiro gen�rico A para inteiro 
					// e como A aponta para o endere�o de x, ela coloca b no endere�o do valor de x
					
	printf("Thread: Terminei minha miss�o, agora vou finalizar com B = %d \n", b);
}

int main() {
	int x = 10;
	pthread_t t1;
	printf("Main1: vou criar uma nova thread\n");
	pthread_create(&t1, NULL, &ft, &x);
	pthread_join(t1, NULL);
	printf("Main2: a thread finalizou\n");
	printf("\nMain3: ser� que a thread conseguiu modificar x? \n");
	printf("Main3: veremos x = %d \n", x);	
	return 0;
}
