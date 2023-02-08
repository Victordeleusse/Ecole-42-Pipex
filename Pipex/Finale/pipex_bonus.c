/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:19:13 by vde-leus          #+#    #+#             */
/*   Updated: 2023/02/08 15:10:49 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_is_here_doc(t_pipex *pipex, int argc, char **argv)
{
	if (argc < 4)
		return (0);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		pipex->is_here_doc = 1;
	else
		pipex->is_here_doc = 0;
	if (ft_strcmp(argv[1], "here_doc") == 0 && argc < 6)
		return (0);
	if (ft_strcmp(argv[1], "here_doc") != 0 && argc < 5)
		return (0);
	return (1);
}

char	*ft_get_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	return (envp[i] + 5);
}

void	ft_init_pipex_bonus(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->index = 0;
	pipex->nb_cmds = argc - 3;
	pipex->nb_pipes = pipex->nb_cmds - 1;
	ft_get_infile(pipex, argv);
	ft_get_outfile(pipex, argv, argc);
	pipex->pipefd = ft_calloc(sizeof(int), 2 * pipex->nb_pipes);
	if (!pipex->pipefd)
		ft_msg_err(ERR_PIPE);
	if (pipex->is_here_doc == 0)
		pipex->tab_pid = (pid_t *)ft_calloc(sizeof(pid_t), argc - 3);
	else
		pipex->tab_pid = (pid_t *)ft_calloc(sizeof(pid_t), argc - 4);
	if (!pipex->tab_pid)
		ft_msg_err(ERR_CALLOC);
	pipex->env_path = ft_get_env_path(envp);
	pipex->command_paths = ft_split(pipex->env_path, ':');
	if (!pipex->command_paths)
		ft_free_pipes(pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	if (ft_is_here_doc(&pipex, argc, argv) == 0)
		return (ft_msg(ERR_INPUT), 0);
	status = -5;
	ft_init_pipex_bonus(&pipex, argc, argv, envp);
	ft_generate_pipes(&pipex);
	while (pipex.index < pipex.nb_cmds)
	{	
		ft_generate_child_process(&pipex, argv, envp, \
			&pipex.tab_pid[pipex.index]);
		pipex.index++;
	}
	ft_close_pipes(&pipex);
	if (pipex.is_here_doc == 0)
		waitpid(pipex.tab_pid[argc - 4], &status, 0);
	else
		waitpid(pipex.tab_pid[argc - 5], &status, 0);
	waitpid(-1, NULL, 0);
	ft_free_parent_prog(&pipex);
	if (!status)
		return (0);
	return (1);
}
