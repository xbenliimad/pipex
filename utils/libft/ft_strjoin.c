/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:24:53 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/09 04:42:01 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		t_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	t_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_calloc(t_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, t_len + 1);
	return (str);
}
