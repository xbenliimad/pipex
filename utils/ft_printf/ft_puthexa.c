/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:47:04 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/12 17:27:57 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_puthexa(char c, unsigned long n)
{
	char	*t_hex;
	int		n_c;

	n_c = 0;
	if (c == 'X')
		t_hex = "0123456789ABCDEF";
	else
		t_hex = "0123456789abcdef";
	if (n / 16 > 0)
		n_c += ft_puthexa(c, n / 16);
	n_c += ft_putchar(t_hex[n % 16]);
	return (n_c);
}
