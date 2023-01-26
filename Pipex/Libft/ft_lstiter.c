/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:00:18 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/28 15:46:17 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list_l *lst, void (*f)(void *))
{
	t_list_l	*begin;

	if (!lst)
		return ;
	begin = lst;
	while (begin)
	{
		(*f)(begin->data);
		begin = begin->next;
	}
}
