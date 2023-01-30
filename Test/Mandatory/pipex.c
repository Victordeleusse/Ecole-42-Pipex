/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:11:01 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/29 14:03:48 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory.h"

char	*find_path(char **envp)
{
	while (*envp && ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	close_pipes(t_pipex *pipex)
{
	if (pipex->pipefd[0])
		close(pipex->pipefd[0]);
	if (pipex->pipefd[0])
		close(pipex->pipefd[1]);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	t_pipex	pipex;

// 	if (argc != 5)
// 		return (msg(ERR_INPUT));
// 	pipex.infile = open(argv[1], O_RDONLY);
// 	if (pipex.infile < 0)
// 		msg_error(ERR_INFILE);
// 	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
// 	if (pipex.outfile < 0)
// 		msg_error(ERR_OUTFILE);
// 	if (pipe(pipex.pipefd) < 0)
// 		msg_error(ERR_PIPE);
// 	pipex.paths = find_path(envp);
// 	pipex.cmd_paths = ft_split(pipex.paths, ':');
// 	pipex.pid1 = fork();
// 	if (pipex.pid1 == 0)
// 		first_child(pipex, argv, envp);
// 	pipex.pid2 = fork();
// 	if (pipex.pid2 == 0)
// 		second_child(pipex, argv, envp);
// 	close_pipes(&pipex);
// 	waitpid(pipex.pid1, NULL, 0);
// 	waitpid(pipex.pid2, NULL, 0);
// 	parent_free(&pipex);
// 	return (0);
// }
