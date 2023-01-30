/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:47:05 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/30 17:35:56 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	r;
	int	i;

	r = 0;
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			r = s1[i] - s2[i];
			break ;
		}
	}
	if (r == 0)
		r = s1[i] - s2[i];
	if (r == 0)
		return (0);
	else if (r > 0)
		return (1);
	else
		return (-1);
}
