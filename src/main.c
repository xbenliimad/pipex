#include "pipex.h"

static void ft_free_double_pointer(char **str)
{
	int	i;

	i = 0;
	while(str[i])
		free(str[i++]);
	free(str);
}

int main(int ac, char *av[], char *env[])
{
	int     i;
	char	*path;
	char **paths;
	char *final_path;
	(void) ac;

	i = 0;
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
	i = 0;
	while(paths[i])
	{
		final_path = ft_strjoin(paths[i++], "/");
		if (access(final_path, X_OK))
			execve(final_path, av + 1, env);
		free(final_path);
	}

	ft_free_double_pointer(paths);
	free(path);
	return (0);
}