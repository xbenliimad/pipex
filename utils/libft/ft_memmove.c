/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:53:28 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/06 04:20:45 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*n_src;
	unsigned char	*n_dest;

	n_src = (unsigned char *)src;
	n_dest = (unsigned char *)dest;
	if (dest == src)
		return (n_src);
	if (!n_src && !n_dest)
		return (NULL);
	if (n_dest < n_src)
		ft_memcpy(dest, src, len);
	else
	{
		while (len--)
			n_dest[len] = n_src[len];
	}
	return (dest);
}
