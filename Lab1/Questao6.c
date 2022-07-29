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
    
    i = fork();
    
    if(i==0) {
        wait(NULL); 
        j = fork();
    }
    
    if(j==0) {
        wait(NULL);
        printf("BEGIN NETO\n");
        printf("Eu sou o processo de PID %d\n", getpid());
        printf("Meu pai tem PID %d\n", getppid());
        printf("END NETO\n");
    } else {
        if(i==0) {
            wait(NULL);
            printf("\nBEGIN FILHO\n");
            printf("Eu sou o processo filho de PID %d\n", getpid());
            printf("Meu pai tem PID %d\n", getppid()); 
            x *= y;
            printf("Produto: %d\n", x);
            printf("END FILHO\n");
        } else {
            wait(NULL);
            printf("\nBEGIN PAI\n");
            printf("Eu sou o processo pai de PID %d\n", getpid());
            x -= y;
            printf("Subtracao: %d\n", x);
            printf("END PAI\n");
        }
    }
    
    return 0;
}
