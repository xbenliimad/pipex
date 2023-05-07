/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:12:46 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/03 21:42:27 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getsize(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_getsize(n);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		nbr[i++] = '-';
		n *= -1;
	}
	nbr[len--] = '\0';
	while (len >= i)
	{
		nbr[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (nbr);
}
