/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:25:25 by vde-leus          #+#    #+#             */
/*   Updated: 2023/02/15 14:10:23 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_msg_infile(char *message)
{
	write(2, message, ft_strlen(message));
}

void	ft_msg(char *message)
{
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
}

void	ft_msg_err_command(char *message)
{
	write(2, ERR_CMD, ft_strlen(ERR_CMD));
	if (message && message != 0)
		write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	// perror(message);
}

void	ft_msg_err(char *message)
{
	perror(message);
	exit(1);
}
