/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:18:05 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/28 15:03:19 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_transfo(va_list arg_ptr, char s)
{
	size_t	taille;

	taille = 0;
	if (s == 'd' || s == 'i')
		taille = ft_putnbr(va_arg(arg_ptr, int));
	if (s == 's')
		taille = ft_putstr(va_arg(arg_ptr, char *));
	if (s == 'c')
		taille = ft_putchar(va_arg(arg_ptr, int));
	if (s == 'p')
		taille = ft_putadress_min_hex(va_arg(arg_ptr, void *));
	if (s == 'x')
		taille = ft_putnbr_hexmin(va_arg(arg_ptr, int));
	if (s == 'X')
		taille = ft_putnbr_hexmaj(va_arg(arg_ptr, int));
	if (s == 'u')
		taille = ft_put_unsnbr(va_arg(arg_ptr, unsigned int));
	if (s == '%')
		taille = ft_putchar('%');
	return (taille);
}

static int	ft_check(const char c)
{
	if (c == 'd' || c == 's' || c == 'c' || c == 'p' || c == 'x' || c == 'X'
		|| c == 'i' || c == '%' || c == 'u')
		return (1);
	else if (c != '\0')
		return (2);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int		count;
	int		i;

	if (!str)
		return (-1);
	i = -1;
	count = 0;
	va_start(arg_ptr, str);
	while (str[++i])
	{
		if (str[i] == '%' && ft_check(str[i + 1]) == 1)
			count += ft_transfo(arg_ptr, str[++i]);
		else if (str[i] == '%' && ft_check(str[i + 1]) == 2)
			count += ft_transfo(arg_ptr, str[i]);
		else if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		else
		{
			if (str[i] != '%')
				count += ft_putchar(str[i]);
		}
	}
	va_end(arg_ptr);
	return (count);
}
