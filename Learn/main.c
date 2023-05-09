#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int	n;
	int	id;
	int	i;

	id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
		wait(NULL);
	i = n;
	while (i < n + 5)
	{
		printf("%d ", i++);

	}
	if (id != 0)
		printf("\n");
	return (0);
}