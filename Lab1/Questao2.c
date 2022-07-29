// Isabela Lopes - 190088940
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int id;
	id=fork();
	
	if(id==0) {
		printf("\t filho: (PID = %d) e vou esperar 10 segundos. Meu pai e o bash %d\n", getpid(), getppid());
		sleep(10);
		printf("\t filho: ja esperei o suficiente agora eu vou embora... \n");
	} else {
		printf("\t pai: (PID = %d) e espero MEU FILHO. Meu pai e o bash %d\n ", getpid(), getppid());
		wait(NULL);
		printf("\t pai: meu filho terminou. Vou terminar tambem");
	}
	
	return 0;
}

