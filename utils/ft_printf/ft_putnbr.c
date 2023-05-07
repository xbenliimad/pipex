/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:37:32 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/12 17:28:08 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	n_c;

	n_c = 0;
	if (n == -2147483648)
	{
		n_c += ft_putnbr(n / 10);
		n_c += ft_putchar('8');
	}
	else if (n < 0)
	{
		n_c += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		n_c += ft_putnbr(n / 10);
		n_c += ft_putnbr(n % 10);
	}
	else if (n >= 0 && n <= 9)
		n_c += ft_putchar(n + '0');
	return (n_c);
}
