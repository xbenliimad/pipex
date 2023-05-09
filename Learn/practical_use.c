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

int ft_get_sum(int *arr)
{
    int i;
    int sum;

    i = 0;
    sum = 0;
    while (arr[i])
        sum = sum + arr[i++];
    return (sum);
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int fd[2];
    int pid;
    int start;
    int end;
    int sum;
    int arr_size;
    int part_sum;
    int i;

    if (pipe(fd) == -1)
        ft_error("An error has occured during pipe().");
    pid = fork();
    if (pid == -1)
        ft_error("An error has occured during fork().");
    arr_size = sizeof(arr) / sizeof(int);
    if (pid == 0)
    {
        start = 0;
        end = arr_size / 2;
    }
    else
    {
        start = arr_size / 2;
        end = arr_size;
    }
    sum = 0;
    i = start;
    while (i < end)
        sum = sum + arr[i++];
    printf("Calculated partial sum : %d\n", sum);
    if (pid == 0)
    {
        close(fd[0]);
        printf("Sending the partial sum to the parent process...\n");
        write(fd[1], &sum, sizeof(int));
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        printf("Getting the partial sum from the child process...\n");
        if (read(fd[0], &part_sum, sizeof(int)) == -1)
            ft_error("An error occured while reading.");
        sum += part_sum;
        printf("Total sum is : %d\n", sum);
        close(fd[0]);
    }
    return (0);
}