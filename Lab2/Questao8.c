#include <stdio.h>
#include <pthread.h>

int x = 10;

void *F1(void *str) {
	for(int i=0; i<500; i++) {
	    x++;
	}
}

void *F2(void *str) {
	for(int i=0; i<500; i++) {
	    x--;
	}
}

int main() {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, F1, NULL);
	pthread_create(&t2, NULL, F2, NULL);
	pthread_join(t1, NULL);
	printf("Valor de x = %d\n", x);	
	
	return 0;
}

