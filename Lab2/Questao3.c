#include <stdio.h>
#include <pthread.h>

void *ft(void *arg) {
	*(int *)arg *= 2;
}

int main() {
	int x=10;
	
	pthread_t vt;
	pthread_create(&vt, NULL, &ft, &x);
	pthread_join(vt, NULL);
	
	printf("Valor final de x: %d\n", x);	
	return 0;
}
