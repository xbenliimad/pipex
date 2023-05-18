#include "pipex.h"

static char    **ft_get_paths(char *env[])
{
	int		i;
	char    *path;
	char    **paths;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			path = ft_strdup(env[i] + 5);
			break ;
		}
		i++;
	}
	paths = ft_split(path, ':');
	free(path);
	return (paths);
}

char    *ft_get_final_path(char *av, char *env[])
{
	int		i;
	char	*final_path;
	char	**paths;
	char	**cmd;

	paths = ft_get_paths(env);
	cmd = ft_split(av, ' ');
	i = 0;
	while(paths[i])
	{
		final_path = ft_strjoin(paths[i], "/");
		final_path = ft_strjoin(final_path, cmd[0]);
		if (!access(final_path, X_OK))
			break ;
		free(final_path);
		i++;
	}
	ft_free_double_pointer(paths);
	return (final_path);
}