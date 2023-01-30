/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:41:35 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/29 16:46:52 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	*ft_get_cmd(t_bonus_pipex *pipex_b)
{
	int		i;
	char	*temp;
	char	*command;
	
	i = 0;
	if (pipex_b->cmd_args[0] == 0)
		return (NULL);
	if (access(pipex_b->cmd_args[0], 1) == 0)
		return (pipex_b->cmd_args[0]);
	while(pipex_b->cmd_paths[i])
	{
		temp = ft_strjoin(pipex_b->cmd_paths[i], "/");
		command = ft_strjoin(temp, pipex_b->cmd_args[0]);
		free(temp);
		if (access(command, 1) == 0)
			return (command);
		free(command);		
		i++;
	}
	return (NULL);
}

void	ft_generate_child(t_bonus_pipex *pipex_b, char **argv, char **envp)
{
	pipex_b->pid = fork();
	if (pipex_b->pid != 0)
	{
		if (pipex_b->index == 0)
			ft_first_child(pipex_b);
		else if (pipex_b->index < pipex_b->cmd_nbs - 2)
			ft_middle_child(pipex_b);
		else
			ft_last_child(pipex_b);
		ft_close_pipes(pipex_b);
		pipex_b->cmd_args = ft_split(argv[2 + pipex_b->here_doc + pipex_b->index], ' ');
		pipex_b->cmd = ft_get_cmd(pipex_b);
		if (!pipex_b->cmd)
			msg_error_cmd(pipex_b->cmd_args[0]);
		execve(pipex_b->cmd, pipex_b->cmd_args, envp);
	}
}
