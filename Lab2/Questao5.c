#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t gettid(void);

void *F1(void *str) {
	printf("Thread 1: meu PID = %d\n", gettid());
	*(int *)str *= 3; // Thread gerada pelo processo filho multiplicando x por 3
	printf("Thread 1: x * 3 = %d\n", *(int *)str);
}

void *F2(void *str){
	printf("Thread 2: meu PID = %d\n", gettid());
	*(int *)str *= 2; // Thread gerada pelo processo pai multiplicando x por 2
	printf("Thread 2: x * 2 = %d\n", *(int *)str);
}

int main() {
	int i,x=10;
	
	i = fork();
	
	pthread_t t1, t2;
	if(i==0) {
		printf("Filho: Sou o processo filho de id = %d e da thread = %d\n", getpid(), gettid());
		pthread_create(&t1, NULL, F1, &x);
		pthread_join(t1, NULL);
		printf("Filho: valor de x=%d\n", x);
		
	} else {
		wait(NULL);
		printf("\nPai: Sou o processo pai de id = %d e da thread = %d\n", getpid(), gettid());
		pthread_create(&t2, NULL, F2, &x);
		pthread_join(t2, NULL);
		printf("Pai: valor de x=%d\n", x);
	}
	
	return 0;
}
