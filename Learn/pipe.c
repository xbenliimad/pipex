#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void ft_error(char *message)
{
    printf("%s\n", message);
    exit(1);
}

int main(void)
{
    int fd[2];
    int pid;
    int x;
    int y;

    if (pipe(fd) == -1)
        ft_error("An error occred in pipe().");
    pid = fork();
    if (pid == -1)
        ft_error("An error has occured while forking.");
    if (pid == 0)
    {
        close(fd[0]);
        x = 7101998;
        write(fd[1], &x, sizeof(int));
        printf("Sending x to the parent process...\n");
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        if (read(fd[0], &y, sizeof(int)) == -1)
            ft_error("An error has occured while reading.");
        printf("Got x = %d from the child process.\n", y);
        close(fd[0]);
    }
    return (0);
}