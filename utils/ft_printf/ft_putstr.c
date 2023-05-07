/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:44:25 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/12 17:30:25 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	n_c;

	if (!str)
		return (ft_putstr("(null)"));
	n_c = 0;
	i = 0;
	while (str[i])
		n_c += ft_putchar(str[i++]);
	return (n_c);
}
