/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:50:39 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/28 17:51:17 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory.h"

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;
	int		i;

	if (access(cmd, FILE_OK) == 0)
		return (cmd);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, FILE_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.pipefd[1], STDOUT_FILENO);
	close(pipex.pipefd[0]);
	dup2(pipex.infile, STDIN_FILENO);
	pipex.cmd_args = ft_split(argv[2], ' ');
	if (pipex.cmd_args[0] == 0)
	{	
		free(pipex.cmd_args);
		msg(ERR_CMD_PIPEX);
		exit(EXIT_FAILURE);
	}
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		msg(ERR_CMD);
		exit(EXIT_FAILURE);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

static void	ft_clean_gnl(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (len > 0)
		str[len - 1] = '\0';
}

static void	ft_get_cmd2_empty(t_pipex *pipex)
{
	char	*str_empty_case;

	while (pipex->cmd_args[0] == 0)
	{
		ft_putstr_fd("pipe> ", 2);
		str_empty_case = get_next_line(2);
		ft_clean_gnl(str_empty_case);
		pipex->cmd_args = ft_split(str_empty_case, ' ');
	}
	pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
}

void	second_child(t_pipex pipex, char *argv[], char *envp[])
{
	char	*str_empty_case;

	dup2(pipex.pipefd[0], STDIN_FILENO);
	close(pipex.pipefd[1]);
	dup2(pipex.outfile, STDOUT_FILENO);
	pipex.cmd_args = ft_split(argv[3], ' ');
	if (pipex.cmd_args[0] == 0)
		ft_get_cmd2_empty(&pipex);
	else
		pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		msg(ERR_CMD);
		exit(EXIT_FAILURE);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
