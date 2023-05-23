#include "pipex_bonus.h"

static void	ft_handle_open(int *fd, char *av, int state, int dup)
{
	ft_open_fd(fd, av, state);
	dup2(*fd, dup);
	close(*fd);
}

static void	ft_handle_child_process(t_info main_info, int i, int tmp,
		int file[2])
{
	char	*path;
	char	**cmd;
	int		gnl_fd;

	if (i == 4 && ft_here_doc_exists(main_info.av))
	{
		gnl_fd = ft_handle_here_doc(main_info.av[2]);
		dup2(gnl_fd, 0);
		close(gnl_fd);
	}
	if (i == 2)
		ft_handle_open(&file[0], main_info.av[1], 0, 0);
	if (tmp != -1)
		dup2(tmp, 0);
	dup2(main_info.fd[1], 1);
	if (i == main_info.ac - 2 && !ft_here_doc_exists(main_info.av))
		ft_handle_open(&file[1], main_info.av[main_info.ac - 1], 1, 1);
	else if (i == main_info.ac - 2 && ft_here_doc_exists(main_info.av))
		ft_handle_open(&file[1], main_info.av[main_info.ac - 1], 2, 1);
	close(main_info.fd[1]);
	close(main_info.fd[0]);
	cmd = ft_split(main_info.av[i], ' ');
	path = ft_get_final_path(cmd[0], main_info.env);
	execve(path, cmd, main_info.env);
	ft_error("pipex: command not found : ", cmd[0]);
}

void	ft_child_process(t_info main_info, int file[2])
{
	int pid;
	int tmp;
	int i;

	i = 2;
	if (ft_here_doc_exists(main_info.av))
		i += 2;
	tmp = -1;
	while (i < main_info.ac - 1)
	{
		if (pipe(main_info.fd) == -1)
			exit(1);
		pid = fork();
		if (pid < 0)
			exit(1);
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