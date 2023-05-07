/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:21:40 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/12 17:29:32 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(char c, unsigned long p)
{
	int	n_c;

	n_c = 0;
	n_c += ft_putstr("0x");
	n_c += ft_puthexa(c, p);
	return (n_c);
}
