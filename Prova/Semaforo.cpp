#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define T 100000
long counter = 0;
sem_t s1;

void *f1 (void *ard) {
	for(long j=0; j<T; j++) {
		sem_wait(&s1);
		counter = counter + 1;
		sem_post(&s1);
	}
}

void *f2 (void *ard) {
	for(long j=0; j<T; j++) {
		sem_wait(&s1);
		counter = counter - 1;
		sem_post(&s1);
	}
}

int main() {
	sem_init(&s1, 0, 1);
	
	pthread_t t1,t2;
	pthread_create(&t1, NULL, f1, NULL);
	pthread_create(&t2, NULL, f2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	printf("counter = %ld\n", counter);
	return 0;
}
