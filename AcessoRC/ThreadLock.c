#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define T 40 // quantidades de threads
long comp=0; // memória compartilhada
pthread_mutex_t mx;

void *f1(void *arg) {
    int a, b;
    for(long j=0; j<100000; j++) {
        pthread_mutex_lock(&mx);
        a = comp;
        b = 1;
        comp = a + b;
        pthread_mutex_unlock(&mx);
    }
}

int main() {
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

