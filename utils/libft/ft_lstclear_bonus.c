/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:23:42 by ibenli            #+#    #+#             */
/*   Updated: 2022/10/31 23:15:31 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr_lst;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	ptr_lst = *lst;
	while (ptr_lst)
	{
		tmp = ptr_lst->next;
		ft_lstdelone(ptr_lst, del);
		ptr_lst = tmp;
	}
	*lst = NULL;
}
