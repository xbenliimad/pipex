#include "pipex.h"

static void	ft_handle_child_process(t_info main_info, int i, int tmp, int file[2])
{
	char	*path;
	char	**cmd;

	if (i == 2)
	{
		dup2(file[0], 0);
		close(file[0]);
	}
	if (tmp != -1)
		dup2(tmp, 0);
	dup2(main_info.fd[1], 1);
	if (i == main_info.ac - 2)
	{
		dup2(file[1], 1);
		close(file[1]);
	}
	close(main_info.fd[1]);
	close(main_info.fd[0]);
	cmd = ft_split(main_info.av[i], ' ');
	path = ft_get_final_path(main_info.av[i], main_info.env);
	execve(path, cmd, main_info.env);
	printf("%s: Command not found.\n", main_info.av[i]);
	exit(1);
}

void	ft_child_process(t_info main_info, int file[2])
{
	int	pid;
	int	tmp;
	int	i;

	i = 2;
	tmp = -1;
	while (i < main_info.ac - 1)
	{
		if (pipe(main_info.fd) == -1)
			ft_error("An error has occured during pipe().\n");
		pid = fork();
		if (pid < 0)
			ft_error("An error has occured during the fork().\n");
		if (pid == 0)
			ft_handle_child_process(main_info, i, tmp, file);
		if (tmp != -1)
			close(tmp);
		tmp = main_info.fd[0];
		close(main_info.fd[1]);
		i++;
	}
	while (wait(NULL) != -1)
		;
	close(tmp);
}