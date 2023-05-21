#include "pipex_bonus.h"

void ft_free_double_pointer(char **str)
{
	int	i;

	i = 0;
	while(str[i])
		free(str[i++]);
	free(str);
}

void ft_error(char *message, char *txt)
{
    write(2, message, ft_strlen(message));
    if (txt)
		write(2, txt, ft_strlen(txt));
    write(2, "\n", 1);
    exit(1);
}

t_info	ft_get_info(int ac, char *av[], char *env[])
{
	t_info main;

	main.ac = ac;
	main.av = av;
	if (env)
		main.env = env;
	return (main);
}

void	ft_open_fd(int *fd, char *file_name, int create)
{
	if (!create)
	{
		*fd = open(file_name, O_RDONLY, 0666);
		if (*fd < 0)
			ft_error("pipex: no such file or directory : ", file_name);
	}
	else
	{
		// if(!*file_name)
		// 	write(2,"haamid\n",7);
		*fd = open(file_name, O_RDWR | O_CREAT, 0777);
		if (*fd < 0)
			ft_error("pipex: no such file or directory : ", file_name);
	}
}