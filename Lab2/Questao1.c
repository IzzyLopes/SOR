#include <stdio.h>

void duplicar(int x);

int main() {
	int x = 10;
	
	duplicar(x);
	
	printf("Valor de final de x: %d\n", x);
	return 0;
}

void duplicar(int x){
	x *= 2;
	printf("Valor de x duplicado: %d\n", x);
}
