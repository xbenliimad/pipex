/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:31:17 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/03 21:24:38 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getstart(char const *s1, char const *set)
{
	int	i;
	int	start_pos;

	start_pos = 0;
	while (s1[start_pos])
	{
		i = 0;
		while (set[i] && set[i] != s1[start_pos])
			i++;
		if (!set[i])
			break ;
		start_pos++;
	}
	return (start_pos);
}

static int	ft_getend(char const *s1, char const *set)
{
	int	i;
	int	end_pos;

	end_pos = ft_strlen(s1) - 1;
	while (s1[end_pos])
	{
		i = 0;
		while (set[i] && set[i] != s1[end_pos])
			i++;
		if (!set[i])
			break ;
		end_pos--;
	}
	return (end_pos);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start_pos;
	int	end_pos;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start_pos = ft_getstart(s1, set);
	end_pos = ft_getend(s1, set) + 1;
	return (ft_substr(s1, start_pos, end_pos - start_pos));
}
