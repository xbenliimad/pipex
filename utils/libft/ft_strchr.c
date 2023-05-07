/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:41:14 by ibenli            #+#    #+#             */
/*   Updated: 2022/10/31 23:26:11 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*n_s;

	n_s = (char *)s;
	i = 0;
	while (n_s[i])
	{
		if (n_s[i] == (char) c)
			return (&(n_s[i]));
		i++;
	}
	if (n_s[i] == (char) c)
		return (&(n_s[i]));
	return (NULL);
}
