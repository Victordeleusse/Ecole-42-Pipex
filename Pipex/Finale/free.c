/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:16:05 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/30 12:01:38 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_pipes(t_pipex *pipex)
{
	free(pipex->infile);
	free(pipex->outfile);
	if (pipex->is_here_doc)
		unlink("temporary_file");
	free(pipex->pipefd);
	ft_msg_err(ERR_PIPE);
}

void	ft_free_parent_prog(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->is_here_doc == 1)
		unlink("temporary_file");
	while (pipex->env_args[i])
	{	
		free(pipex->env_args[i]);
		i++;
	}
	free(pipex->env_args);
	free(pipex->pipefd);
}

void	ft_free_child_prog(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->command_args[i])
	{
		free(pipex->command_args[i]);
		i++;		
	}
	free(pipex->command_args);
	free(pipex->command_path);
	ft_msg_err(ERR_PIPE);
}

