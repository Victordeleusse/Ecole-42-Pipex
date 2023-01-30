/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:25:25 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/30 16:52:16 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_msg(char *message)
{
	write(1, message, ft_strlen(message));
}

void	ft_msg_err(char *message)
{
	perror(message);
	exit(1);
}
