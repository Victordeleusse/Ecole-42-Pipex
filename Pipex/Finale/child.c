/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:41:08 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/30 18:03:00 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_command_for_the_pipe(t_pipex *pipex)
{
	char	*temp;
	char	*command;
	int		i;

	if (!pipex->command_args || pipex->command_args[0] == 0)
		return (NULL);
	if (access(pipex->command_args[0], 1) == 0)
		return (pipex->command_args[0]);
	i = 0;
	while (pipex->command_paths[i])
	{
		temp = ft_strjoin(pipex->command_paths[i], "/");
		command = ft_strjoin(temp, pipex->command_args[0]);
		free(temp);
		if (access(command, 1) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	ft_generate_child_process(t_pipex *pipex, char **argv, char **envp)
{
	pipex->pid = fork();
	if (pipex->pid != 0)
	{
		if (pipex->index == 0)
			ft_first_child(pipex);
		else if (pipex->index < pipex->nb_cmds - 2)
			ft_middle_child(pipex);
		else
			ft_last_child(pipex);
		ft_close_pipes(pipex);
		pipex->command_args = ft_split(argv[2 + pipex->index + \
										pipex->is_here_doc], ' ');
		pipex->command = ft_get_command_for_the_pipe(pipex);
		if (!pipex->command)
		{	
			ft_free_child_prog(pipex);
			ft_msg_err(ERR_CMD);
		}
		execve(pipex->command, pipex->command_args, envp);
	}
}
