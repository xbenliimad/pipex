/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:51:52 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/23 21:51:53 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_here_doc_exists(char *av[])
{
	if (!ft_strncmp(av[1], "here_doc", ft_strlen(av[1])))
		return (1);
	return (0);
}

void	ft_handle_here_doc(char *breaker, int fd[2])
{
	char	*line;

	breaker = ft_strjoin(breaker, "\n");
	line = get_next_line(0);
	while (ft_strncmp(line, breaker, ft_strlen(line)))
	{
		ft_putstr_fd(line, fd[1]);
		free(line);
		line = get_next_line(0);
	}
	free(breaker);
	close(fd[1]);
	close(fd[0]);
	exit(0);
}
