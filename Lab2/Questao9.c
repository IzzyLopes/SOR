#include <stdio.h>
#include <pthread.h>

void *F1(void *str) {
    printf("Filha 1: PID = %d\n", gettid());
}

void *F2(void *str) {
    printf("Filha 2: PID = %d\n", gettid());
}

void *F3(void *str) {
    printf("Filha 3: PID = %d\n", gettid());
}

int main() {
	pthread_t t1, t2, t3;
	pthread_create(&t2, NULL, F2, NULL);
	pthread_create(&t3, NULL, F3, NULL);
	pthread_create(&t1, NULL, F1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t1, NULL);
	
	printf("Mae: PID = %d\n", gettid());	
	return 0;
}
