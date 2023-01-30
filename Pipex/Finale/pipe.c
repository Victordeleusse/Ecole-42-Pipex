/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:06:59 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/30 17:28:38 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_generate_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nb_pipes)
	{
		if (pipe(pipex->pipefd + 2 * i) < 0)
		{	
			ft_free_parent_prog(pipex);
			ft_msg_err(ERR_PIPE);
		}	
		i++;
	}
}

void	ft_first_child(t_pipex *pipex)
{
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->pipefd[1], STDOUT_FILENO);
}

void	ft_middle_child(t_pipex *pipex)
{
	dup2(pipex->pipefd[2 * pipex->index - 2], STDIN_FILENO);
	dup2(pipex->pipefd[2 * pipex->index - 1], STDOUT_FILENO);
}

void	ft_last_child(t_pipex *pipex)
{
	dup2(pipex->pipefd[2 * pipex->index - 2], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
}

void	ft_close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < 2 * pipex->nb_pipes)
	{	
		close(pipex->pipefd[i]);
		i++;
	}
}
