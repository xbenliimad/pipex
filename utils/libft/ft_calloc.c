/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:43:39 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/03 02:17:44 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < count * size)
		str[i++] = '\0';
	return (str);
}
