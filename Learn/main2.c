#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *env[])
{
    while(*(env++))
        printf("|%s|\n", *env);
    return (0);
}