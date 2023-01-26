/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexmin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:11:36 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/28 15:02:52 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_putnbr_hexmin(unsigned int nbr)
{
	if (nbr / 16)
		return (ft_putnbr_hexmin(nbr / 16) + ft_putnbr_hexmin(nbr % 16));
	else if (!(nbr / 10))
		ft_putchar(nbr + '0');
	else
		ft_putchar(nbr - 10 + 'a');
	return (1);
}

// int	main(void)
// {
// 	int	nbr = -42;
// 	int i;
// 	int test;

// 	i = printf("la fonction affiche %x\n", nbr);
// 	printf("la fonction vaut %d\n", i);
// 	test = ft_putnbr_hexmin(nbr);
// 	printf("\n");
// 	printf("la fonction vaut %d\n", test);
// 	return (0);
// }