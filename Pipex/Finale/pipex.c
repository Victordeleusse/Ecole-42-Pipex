/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:18:10 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/30 11:56:10 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_is_here_doc(t_pipex *pipex, int argc, char **argv)
{
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
	while (*envp && ft_strncmp("PATH", *envp, 4) != 0)
		*envp++;
	return(*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	
	t_pipex.index = 0;
	if (ft_is_here_doc(&pipex, argc, argv) == 0)
		return(ft_msg(ERR_INPUT), 0);
	pipex.nb_cmds = argc - 3 - pipex.is_here_doc;
	pipex.infile = ft_get_infile(&pipex, argv);
	pipex.outfile = ft_get_outfile(&pipex, argv, argc);
	pipex.nb_pipes = pipex.nb_cmds - 1;
	pipex.pipefd = ft_calloc(sizeof(int), 2 * pipex.nb_pipes);
	if (!pipex.pipefd)
		ft_free_pipes(pipex);
	pipex.env_path = ft_get_env_path(envp);
	pipex.command_paths = ft_split(pipex.env_path, ':');
	ft_generate_pipes(&pipex);
	while(pipex.index < pipex.nb_cmds)
	{
		ft_generate_child_process(pipex, argv, envp);
		t_pipex.index++;
	}
	ft_close_pipes(pipex);
	waitpid(-1, NULL, 0);
	ft_free_parent_prog(pipex);
	return (0);
}