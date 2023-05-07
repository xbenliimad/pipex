/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:35:39 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/04 23:03:36 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*n_s;

	n_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (n_s[i] == (unsigned char) c)
			return (&(n_s[i]));
		i++;
	}
	return (NULL);
}
