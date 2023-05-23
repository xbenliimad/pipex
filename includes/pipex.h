/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:56:17 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/23 21:56:20 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <sys/wait.h>

typedef struct s_info
{
	int		ac;
	int		fd[2];
	char	**av;
	char	**env;
}			t_info;

// Main
char		*ft_get_final_path(char *cmd, char *env[]);
void		ft_child_process(t_info main_info, int file[2]);

// Utils
void		ft_free_double_pointer(char **str);
void		ft_error(char *message, char *txt);
t_info		ft_get_info(int ac, char *av[], char *env[]);
void		ft_open_fd(int *fd, char *file_name, int create);

#endif