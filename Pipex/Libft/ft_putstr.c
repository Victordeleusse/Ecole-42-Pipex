/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:05:19 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/28 15:25:16 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr(char *str)
{
	int	i;
	int	len;

	if (str == NULL)
	{	
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	len = ft_strlen(str);
	return (len);
}

// int	main(void)
// {
// 	char	test[] = "Hello world !";
// 	size_t		len;

// 	len = ft_putstr(test);
// 	printf("\n%d", len);
// 	return (0);
// }