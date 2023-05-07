/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 08:33:21 by ibenli            #+#    #+#             */
/*   Updated: 2023/01/22 20:08:43 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_buffer(char *buffer, char **rest)
{
	if (*rest)
		free(*rest);
	*rest = NULL;
	free(buffer);
	return (NULL);
}

int	ft_check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_get_line(char *rest)
{
	int		i;
	char	*line;

	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	line = gnl_substr(rest, 0, i);
	if (!line)
	{
		free(rest);
		return (NULL);
	}
	return (line);
}

char	*ft_get_rest(char *rest)
{
	int		i;
	char	*n_rest;

	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	n_rest = gnl_substr(rest, i, ft_linelen(rest + i));
	free(rest);
	return (n_rest);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*rest;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	count = 1;
	while (count != 0 && ft_check_line(buffer))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			return (ft_free_buffer(buffer, &rest));
		buffer[count] = '\0';
		rest = gnl_strjoin(rest, buffer);
	}
	free(buffer);
	line = ft_get_line(rest);
	rest = ft_get_rest(rest);
	return (line);
}
