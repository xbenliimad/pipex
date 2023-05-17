#include "pipex.h"

void	ft_child_process(char ac, char *av[], char *env[], int infile, int outfile)
{
	int		pid;
	char	*path;
	char	**cmd;
	int 	tmp;
	int		i;
	int		fd[2];

	i = 2;
	tmp = -1;
	path = NULL;
	while (i < ac - 1)
	{
		if (pipe(fd) == -1)
			ft_error("An error has occured during pipe().\n");
		pid = fork();
		if (pid < 0)
			ft_error("Error during the fork().\n");
		if (pid == 0)
		{
			if (i == 2)
			{
				dup2(infile, 0);
				close(infile);
			}
			if(tmp != -1)
				dup2(tmp, 0);
			dup2(fd[1], 1);
			if (i == ac - 2)
			{
				dup2(outfile, 1);
				close(outfile);
			}
			close(fd[1]);
			close(fd[0]);
			cmd = ft_split(av[i], ' ');
			path = ft_get_final_path(av[i], env);
			if (execve(path, cmd, env) == -1)
			{
				ft_error("An error has occured during execve().\n");
			}
		}
		if(tmp != -1)
			close(tmp);
		tmp = fd[0];
		close(fd[1]);
		i++;
	}
	close(tmp);
}

int main(int ac, char *av[], char *env[])
{
	int	infile;
	int	outfile;
	int	fd[2];

	if (pipe(fd) == -1)
		ft_error("An error has occured during pipe().\n");
	if (ac < 5)
		return (1);
	infile = open(av[1], O_RDONLY, 0666);
	if (infile < 0)
		ft_error("Error opening the fd.\n");
	outfile = open(av[ac - 1], O_RDWR | O_CREAT, 0777);
	if (outfile < 0)
		ft_error("Error opening the fd.\n");
	ft_child_process(ac, av, env, infile, outfile);
	return (0);
}