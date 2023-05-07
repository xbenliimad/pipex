/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:19:54 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/06 04:55:16 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*n_dest;
	unsigned char	*n_src;

	n_src = (unsigned char *)src;
	n_dest = (unsigned char *)dest;
	if (n_src == n_dest)
		return (n_src);
	if (!n_src && !n_dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		n_dest[i] = n_src[i];
		i++;
	}
	return (dest);
}
