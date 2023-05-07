/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:23:02 by ibenli            #+#    #+#             */
/*   Updated: 2022/10/31 23:25:45 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_size(char const *s, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			size++;
		i++;
	}
	return (size);
}

static void	free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

static size_t	ft_fill_str(char **strs, char const *s, char c, int pos)
{
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i + size] && s[i + size] != c)
		size++;
	strs[pos] = ft_substr(s, i, size);
	if (!strs[pos])
		return (0);
	i += size;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	tmp;
	char	**strs;

	if (!s)
		return (NULL);
	len = ft_get_size(s, c);
	strs = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		tmp = ft_fill_str(strs, (s + j), c, i++);
		if (!tmp)
		{
			free_strs(strs);
			return (NULL);
		}
		j += tmp;
	}
	return (strs);
}
