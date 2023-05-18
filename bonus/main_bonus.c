#include "pipex_bonus.h"

int	main(int ac, char *av[], char *env[])
{
	int		file[2];
	t_info	main_info;

	main_info = ft_get_info(ac, av, env);
	if (ac < 5)
		return (1);
	file[0] = open(av[1], O_RDONLY, 0666);
	if (file[0] < 0)
		ft_error("Error opening the fd.\n");
	file[1] = open(av[ac - 1], O_RDWR | O_CREAT, 0777);
	if (file[1] < 0)
		ft_error("Error opening the fd.\n");
	ft_child_process(main_info, file);
	return (0);
}
