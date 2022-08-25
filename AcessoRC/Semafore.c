#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define T 40 // quantidades de threads
long comp=0; // memória compartilhada
sem_t s1;

void *f1(void *arg) {
    int a, b;
    for(long j=0; j<100000; j++) {
        sem_wait(&s1);
        a = comp;
        b = 1;
        comp = a + b;
        sem_post(&s1);
    }
}

int main() {
    sem_init(&s1, 0, 1);
    pthread_t tr[T];
    
    for(int i=0; i<T; i++) {
        pthread_create(&tr[i], NULL, f1, NULL);
    }
    
    for(int i=0; i<T; i++) {
        pthread_join(tr[i], NULL);
    }
    printf("Compartilhadas = %ld\n", comp);

    return 0;
}

