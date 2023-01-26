/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexmaj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:21:37 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/28 15:02:54 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_hexmaj(unsigned int nbr)
{
	if (nbr / 16)
		return (ft_putnbr_hexmaj(nbr / 16) + ft_putnbr_hexmaj(nbr % 16));
	if (nbr < 10)
		ft_putchar((nbr % 10) + '0');
	if (nbr >= 10 && nbr < 16)
		ft_putchar((nbr % 10) + 'A');
	return (1);
}
