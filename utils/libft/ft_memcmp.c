/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:12:37 by ibenli            #+#    #+#             */
/*   Updated: 2022/10/31 23:18:38 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*n_s1;
	unsigned char	*n_s2;

	n_s1 = (unsigned char *)s1;
	n_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (n_s1[i] != n_s2[i])
			return (n_s1[i] - n_s2[i]);
		i++;
	}
	return (0);
}
