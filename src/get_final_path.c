/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_final_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:48:54 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/23 21:54:55 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_get_paths(char *env[])
{
	int		i;
	char	*path;
	char	**paths;

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

char	*ft_get_final_path(char *cmd, char *env[])
{
	int		i;
	char	*final_path;
	char	*slash_path;
	char	**paths;

	paths = ft_get_paths(env);
	if (ft_strchr(cmd, '/'))
		return (cmd);
	i = 0;
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		slash_path = ft_strjoin(paths[i], "/");
		final_path = ft_strjoin(slash_path, cmd);
		free(slash_path);
		if (!access(final_path, X_OK))
			break ;
		free(final_path);
		i++;
	}
	ft_free_double_pointer(paths);
	return (final_path);
}
