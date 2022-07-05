#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *F1(void *str) {
	printf("Filha 1: vou dormir 3 segundos\n");
	sleep(3);
	printf("Filha 1: Ja acordei e agora vou terminar\n");
}

void *F2(void *str) {
	printf("Filha 2: vou dormir 6 segundos\n");
	sleep(6);
	printf("Filha 2: Ja acordei e agora vou terminar\n");
}

int main() {
	void *p1;
	
	pthread_t t1, t2; 		// crando t1 e t2 do tipo thread
	printf("Mae: vou ter duas filhas\n");
	pthread_create(&t1, NULL, F1, NULL);
	pthread_create(&t2, NULL, F2, NULL);
	
	printf("Mae: agora vou esperar minhas filhas\n");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	printf("Mae: The girls are done \n");	
	return 0;
}
