/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:12:48 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/04 23:14:52 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*pos;
	char	*n_s;

	n_s = (char *)s;
	pos = NULL;
	i = 0;
	while (n_s[i])
	{
		if (n_s[i] == (char) c)
			pos = (n_s + i);
		i++;
	}
	if (n_s[i] == (char) c)
		pos = (n_s + i);
	return (pos);
}
