/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:14:13 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/28 15:46:43 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_l	*ft_lstnew(void *content)
{
	t_list_l	*new_element;

	new_element = (t_list_l *)malloc(sizeof(t_list_l));
	new_element->data = content;
	new_element->next = NULL;
	return (new_element);
}
