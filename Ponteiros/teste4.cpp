#include <stdio.h>

int main() {
	int a = 5;
	int *p;
	
	p=&a;
	printf("p vale %p\n", p);
	printf("p vale %d\n", *p);
}
