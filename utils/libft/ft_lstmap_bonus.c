/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:53:12 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/01 02:10:32 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*tmp;
	t_list	*ptr;
	void	*c_content;

	if (!lst || !f || !del)
		return (NULL);
	n_lst = NULL;
	ptr = lst;
	while (ptr)
	{
		c_content = f(ptr->content);
		tmp = ft_lstnew(c_content);
		if (!tmp)
		{
			del(c_content);
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&n_lst, tmp);
		ptr = ptr->next;
	}
	return (n_lst);
}
