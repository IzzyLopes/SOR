// Isabela Lopes - 190088940
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Oi mundo, eu sou o processo PID=%d\n", getpid());
    printf("Agora vou dormir 10 segundos.\n");
    sleep(10);
    printf("\nOi mundo, eu sou o processo PID=%d\n", getpid());
    printf("Agora eu acordei e vou terminar.");
    return 0; 
}
