/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
    
    if(i==0) {
        printf("\nEu sou o processo filho 1 de PID %d\n", getpid());
        printf("Meu pai tem PID %d\n", getppid()); 
        x += y;
        printf("x + y = %d\n", x);
    } else {
        wait(NULL);
        j = fork();
        
        if(j==0) {
            printf("\nEu sou o processo filho 2 de PID %d\n", getpid());
            printf("Meu pai tem PID %d\n", getppid());
            x *= y;
            printf("x * y = %d\n", x);
        } else {
            wait(NULL);
            printf("\nEu sou o processo pai de PID %d\n", getpid());
            x -= y;
            printf("x - y = %d\n", x);
        }
    }
}

