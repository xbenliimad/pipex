#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
    int pid;

    pid = fork();
    wait(NULL);
    if (pid != 0)
        printf("Parent :\n\n");
    else
        printf("Child :\n\n");
    printf("Current pid : %d\nParent pid : %d\n\n", getpid(), getppid());
    return (0);
}