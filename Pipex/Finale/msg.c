/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:25:25 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/29 17:44:13 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_msg(char *message)
{
	write(1, message, ft_strlen(message));
}

void	ft_msg_err(char *message)
{
	write(1, message, ft_strlen(message));
	exit(1);
}
