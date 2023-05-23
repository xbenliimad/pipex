/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:49:19 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/23 21:49:20 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *env[])
{
	int		file[2];
	t_info	main_info;

	main_info = ft_get_info(ac, av, env);
	if (ac != 5)
		ft_error("Error: more or less than 5 args.", NULL);
	ft_child_process(main_info, file);
	return (0);
}
