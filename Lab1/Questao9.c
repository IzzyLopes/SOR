// Isabela Lopes - 190088940
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i, j;
    int x, y;
    
    printf("Insira dois numeros inteiros:");
    scanf("%d", &x);
    scanf("%d", &y);
    
    printf("\nx: %d\n", x);
    printf("y: %d\n", y);
    
    i = fork();
    
    if (i==0) {
        printf("\nEu sou o processo filho 1 de PID %d\n", getpid());
        printf("Meu pai tem PID %d\n", getppid());
        x += y;
        printf("x + y = %d\n", x);
    } else {
        printf("\nEu sou o processo pai de PID %d\n", getpid());
        int result = x - y;
        printf("x - y = %d\n", result);
        wait(NULL);
        j = fork();
    }
    
    wait(NULL);
    if (j==0) {
        printf("\nEu sou o processo filho 2 de PID %d\n", getpid());
        printf("Meu pai tem PID %d\n", getppid());
        x *= y;
        printf("x * y = %d\n", x);
    }
    return 0;
}

