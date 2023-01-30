/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:11:09 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/29 16:18:06 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_generate_pipes(t_bonus_pipex *pipex_b)
{
	int	i;

	i = 0;
	while (i < pipex_b->pipe_nbs)
	{
		if(pipe(pipex_b->pipe + 2 * i) < 0)
			ft_parent_free(&pipex_b);
		i++;
	}
}

void	ft_first_child(t_bonus_pipex *pipex_b)
{
	dup2(pipex_b->infile, STDIN_FILENO);
	dup2(pipex_b->pipe[1], STDOUT_FILENO);
}

void	ft_middle_child(t_bonus_pipex *pipex_b)
{
	dup2(pipex_b->pipe[2 * pipex_b->index - 2], STDIN_FILENO);
	dup2(pipex_b->pipe[2 * pipex_b->index - 1], STDOUT_FILENO);
}

void	ft_last_child(t_bonus_pipex *pipex_b)
{
	dup2(pipex_b->pipe[2 * pipex_b->index - 2], STDIN_FILENO);
	dup2(pipex_b->outfile, STDOUT_FILENO);
}

void	ft_close_pipes(t_bonus_pipex *pipex_b)
{
	int	i;

	i = 0;
	while (i < 2 * pipex_b->pipe_nbs)
	{
		close(pipex_b->pipe[i]);
		i++;
	}	
}
