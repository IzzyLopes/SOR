#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *PrintHello(void *A) { //função a ser executada pela thread, qunado a thread for criada
	int i=2;
	*(int *)A=i; 			// conversão de void para int
	
	printf("Thread %d: Olá mundo!\n", i);
	
	sleep(2);
}

int main() {
	pthread_t t1, t2; 		// crando t1 e t2 do tipo thread
	int create;				// variavel que recebe o retorno da função pthread_create()
	int num;				// identificador da thread
	
	num = 1;
	printf("Main: criando a thread %d \n", num);
	pthread_create(&t1, NULL, PrintHello, &num);
	pthread_join(t1, NULL);
	
	printf("Main: criando a thread %d \n", num);
	pthread_create(&t2, NULL, PrintHello, &num);
	pthread_join(t2, NULL);
	
	printf("Main: finalizado\n");
	
	return 0;
}
