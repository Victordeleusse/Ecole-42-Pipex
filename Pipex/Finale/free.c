/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:16:05 by vde-leus          #+#    #+#             */
/*   Updated: 2023/02/01 09:12:32 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_pipes(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->is_here_doc)
		unlink("temporary_file");
	free(pipex->pipefd);
	ft_msg(ERR_ENVP);
	exit(1);
}

void	ft_free_parent_prog(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->is_here_doc == 1)
		unlink("temporary_file");
	while (pipex->command_paths[i])
	{	
		free(pipex->command_paths[i]);
		i++;
	}
	free(pipex->command_paths);
	free(pipex->pipefd);
}

void	ft_free_child_prog(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->command_args[0] != 0)
	{
		while (pipex->command_args[i])
		{
			free(pipex->command_args[i]);
			i++;
		}
	}
	free(pipex->command_args);
	if (pipex->command)
		free(pipex->command);
	// ft_free_parent_prog(pipex);
}
