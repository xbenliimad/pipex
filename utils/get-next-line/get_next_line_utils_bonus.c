/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:06:37 by ibenli            #+#    #+#             */
/*   Updated: 2023/01/22 20:19:55 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_linelen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strdup(char *s1)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * (ft_linelen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*sub_str;

	if (!s)
		return (NULL);
	if (start >= ft_linelen(s))
		return (NULL);
	str_len = ft_linelen(s) - start;
	if (str_len > len)
		str_len = len;
	sub_str = malloc((str_len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < str_len && s[start + i])
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

size_t	gnl_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	if (!src)
		return (0);
	src_len = ft_linelen(src);
	if (!dst && !dstsize)
		return (src_len);
	dst_len = ft_linelen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && i < dstsize - dst_len - 1)
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (src_len + dst_len);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		t_len;
	char	*str;

	if (!s2[0])
		return (s1);
	t_len = ft_linelen(s1) + ft_linelen(s2);
	if (!t_len)
	{
		free(s1);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (t_len + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	str[0] = '\0';
	gnl_strlcat(str, s1, ft_linelen(s1) + 1);
	free(s1);
	gnl_strlcat(str, s2, t_len + 1);
	return (str);
}
