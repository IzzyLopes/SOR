#include <stdio.h>
#include <pthread.h>

void *F1(void *str) {
	printf("Sou a thread 1 e meu PID = %d\n", gettid());
}

void *F2(void *str){
	printf("Sou a thread 2 e meu PID = %d\n", gettid());
}

int main() {
	pthread_t t1, t2;
	printf("Mae: vou ter duas filhas\n");
	pthread_create(&t1, NULL, F1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, F2, NULL);
	pthread_join(t2, NULL);
	
	printf("\nMae: Meu PID = %d\n", gettid());	
	return 0;
}
