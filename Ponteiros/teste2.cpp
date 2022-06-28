#include <stdio.h>

void troca (int *x, int *y)  {
	int temp;
	temp = *x;
	*x = *y;
	*y= temp;
	printf ("Função: valores trocados: %d %d \n", *x, *y);
}

int main() {
	int a = 5;
	int b = 10;
	
	printf ("Main: valores no main antes da troca: %d %d \n", a, b);
	troca(&a, &b);
	printf ("Main: valores no main depois da troca: %d %d \n", a, b);
	
	return 0;
}

