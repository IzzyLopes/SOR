#include <stdio.h>

int main (int argc, char *argv[]) {
	int valor = 20;
	float valor2 = 5.23;
	
	void *ponteiro; // ponteiro gen�rico
	
	ponteiro = &valor; // aponta para um inteiro
	printf("%d\n", *(int *)ponteiro);
	/* A parte (int *)ponteiro converte o ponteiro gen�rico
	 * em um ponteiro do tipo int e o s�mbolo * serve para desreferenciar
	 */
	 
	ponteiro = &valor2; // aponta para um float
	printf("%0.2f\n", *(float *)ponteiro);
	
	return 0;
}
