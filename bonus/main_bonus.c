#include "pipex_bonus.h"

int	main(int ac, char *av[], char *env[])
{
	int		file[2];
	t_info	main_info;

	main_info = ft_get_info(ac, av, env);
	if (ac < 5)
		ft_error("Error: less than 5 args.", NULL);
	ft_child_process(main_info, file);
	//system("leaks pipex");
	return (0);
}
