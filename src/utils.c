#include "pipex.h"

void ft_free_double_pointer(char **str)
{
	int	i;

	i = 0;
	while(str[i])
		free(str[i++]);
	free(str);
}

void ft_error(char *message)
{
    write(2, message, ft_strlen(message));
    exit(1);
}
