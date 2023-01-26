/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:10:32 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/28 15:39:33 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

size_t	ft_put_unsnbr(unsigned int nbr);
size_t	ft_putadress_min_hex(void *entree);
size_t	ft_putchar(char c);
size_t	ft_putnbr_hexmaj(unsigned int nbr);
size_t	ft_putnbr_hexmin(unsigned int nbr);
size_t	ft_putnbr(int nbr);
size_t	ft_putstr(char *str);
// size_t	ft_strlen(char *str);
int		ft_printf(const char *str, ...);

#endif
