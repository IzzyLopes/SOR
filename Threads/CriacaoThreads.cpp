#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *ft(void *arg) {
	printf("Filha: eu sou uma thread filha com ID %d, agora vou dormir um pouco \n", 5);
	sleep(5);
	printf("Filha: Acordei e vou terminar .. \n");
}

int main() {
	pthread_t vt;
	printf("Pai: vou criar uma nova thread\n");
	pthread_create(&vt, NULL, &ft, NULL);
	pthread_join(vt, NULL);
	printf("Pai: vou terminar\n");	
	return 0;
}
