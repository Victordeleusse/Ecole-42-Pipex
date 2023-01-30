/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:48:46 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/27 09:52:47 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	msg_error(char *err)
{
	perror(err);
	exit (EXIT_FAILURE);
}
