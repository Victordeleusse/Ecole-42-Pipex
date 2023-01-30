/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:53:00 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/29 13:59:37 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_parent_free(t_bonus_pipex *pipex_b)
{
	int	i;

	i = 0;
	close(pipex_b->infile);
	close(pipex_b->outfile);
	if (pipex_b->here_doc)
		unlink("temporary_file");
	while (pipex_b->cmd_paths[i])
	{
		free(pipex_b->cmd_paths[i]);
		i++;
	}
	free(pipex_b->cmd_paths);
	free(pipex_b->pipe);
}

void	ft_child_free(t_bonus_pipex *pipex_b)
{
	int	i;

	i = 0;
	while (pipex_b->cmd_args[i])
	{
		free(pipex_b->cmd_args[i]);
		i++;
	}
	free(pipex_b->cmd_args);
	free(pipex_b->cmd);
}

void	ft_pipe_free(t_bonus_pipex *pipex_b)
{
	close(pipex_b->infile);
	close(pipex_b->outfile);
	if (pipex_b->here_doc)
		unlink("temporary_file");
	free(pipex_b->pipe);
	msg(ERR_ENVP);
	exit(1);
}
