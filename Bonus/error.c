/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:06:23 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/29 16:54:14 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	msg_error_cmd(char *err)
{
	write(2, ERR_CMD, ft_strlen(ERR_CMD));
	if (err != 0)
		write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	exit(1);
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}
