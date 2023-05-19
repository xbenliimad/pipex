#include "pipex.h"

int	main(int ac, char *av[], char *env[])
{
	int		file[2];
	t_info	main_info;

	main_info = ft_get_info(ac, av, env);
	if (ac != 5)
	{
		printf("More or less than 5 args.\n");
		return (1);
	}
	ft_child_process(main_info, file);
	//system("leaks pipex");
	return (0);
}
