/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:16:05 by vde-leus          #+#    #+#             */
/*   Updated: 2023/02/15 20:02:06 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_pipes(t_pipex *pipex)
{
	if (pipex->infile >= 0)
		close(pipex->infile);
	if (pipex->outfile >= 0)
		close(pipex->outfile);
	if (pipex->is_here_doc)
		unlink("temporary file");
	free(pipex->pipefd);
	if (pipex->tab_pid)
		free(pipex->tab_pid);
	ft_msg(ERR_ENVP);
	exit(1);
}

void	ft_free_parent_prog(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->infile >= 0)
		close(pipex->infile);
	if (pipex->outfile >= 0)
		close(pipex->outfile);
	if (pipex->is_here_doc == 1)
		unlink("temporary file");
	while (pipex->command_paths && pipex->command_paths[i])
	{	
		free(pipex->command_paths[i]);
		i++;
	}
	if (pipex->command_paths)
		free(pipex->command_paths);
	free(pipex->pipefd);
	free(pipex->tab_pid);
}

void	ft_free_child_prog(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->command_args && pipex->command_args[0])
	{
		while (pipex->command_args[i])
		{
			free(pipex->command_args[i]);
			i++;
		}
	}
	free(pipex->command_args);
	ft_free_parent_prog(pipex);
}
