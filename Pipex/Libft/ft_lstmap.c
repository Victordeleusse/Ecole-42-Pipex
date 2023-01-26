/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:04:51 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/28 15:46:30 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_l	*ft_lstmap(t_list_l *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list_l	*new_lst;
	t_list_l	*begin_old;
	t_list_l	*begin_new;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew((*f)(lst->data));
	if (!new_lst)
		return (NULL);
	begin_old = lst;
	begin_new = new_lst;
	while (begin_old->next)
	{
		begin_new->next = ft_lstnew((*f)(begin_old->next->data));
		if (!begin_new->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		begin_old = begin_old->next;
		begin_new = begin_new->next;
	}
	return (new_lst);
}
