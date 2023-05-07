/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:32:24 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/15 18:52:10 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_printf(char c, va_list ptr)
{
	int	n_c;

	n_c = 0;
	if (c == '%')
		n_c += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		n_c += ft_putnbr(va_arg(ptr, int));
	else if (c == 'c')
		n_c += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		n_c += ft_putstr(va_arg(ptr, char *));
	else if (c == 'u')
		n_c += ft_putnbr_unsigned(va_arg(ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		n_c += ft_puthexa(c, va_arg(ptr, unsigned int));
	else if (c == 'p')
		n_c += ft_putadress('x', va_arg(ptr, unsigned long));
	return (n_c);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		n_c;
	va_list	ptr_arg;

	va_start(ptr_arg, format);
	i = 0;
	n_c = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
				n_c += ft_handle_printf(format[++i], ptr_arg);
		}
		else
			n_c += ft_putchar(format[i]);
		i++;
	}
	va_end(ptr_arg);
	return (n_c);
}
