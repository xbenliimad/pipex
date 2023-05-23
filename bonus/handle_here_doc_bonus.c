#include "pipex_bonus.h"

int	ft_here_doc_exists(char *av[])
{
	if (!ft_strncmp(av[1], "here_doc", ft_strlen(av[1])))
		return (1);
	return (0);
}

int	ft_handle_here_doc(char *breaker)
{
	int gnl_fd[2];
	char *line;

	if (pipe(gnl_fd) == -1)
		exit(1);
	breaker = ft_strjoin(breaker, "\n");
	line = get_next_line(0);
	while (ft_strncmp(line, breaker, ft_strlen(line)))
	{
		ft_putstr_fd(line, gnl_fd[1]);
		free(line);
		line = get_next_line(0);
	}
	free(breaker);
	close(gnl_fd[1]);
	return (gnl_fd[0]);
}