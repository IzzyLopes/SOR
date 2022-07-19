#include <stdio.h>
#include <pthread.h>

int resultado;

void *sonft(void *arg) {
    *(int *)arg += 20;
}

void *ft(void *arg) {
	*(int *)arg *= 2;
	
	pthread_t son;
	pthread_create(&son, NULL, &sonft, &*(int *)arg);
	pthread_join(son, NULL);
}

int main() {
	int x = 10;
	
	pthread_t vt;
	pthread_create(&vt, NULL, &ft, &x);
	pthread_join(vt, NULL);
	
	printf("Valor de x = %d\n", x);	
	return 0;
}
