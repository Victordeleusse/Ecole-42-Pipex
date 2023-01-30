/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:54:31 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/29 16:17:52 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_is_here_doc(char *str, t_bonus_pipex *pipex_b)
{
	if (str && ft_strcmp("here_doc", str) == 0)
	{
		pipex_b->here_doc = 1;
		return (1);
	}
	else
	{
		pipex_b->here_doc = 0;
		return (0);
	}
}
char	*ft_find_path(char **envp)
{
	while (*envp && ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_bonus_pipex	pipex_b;

	pipex_b.index = 0;
	if ((argc < 6 && ft_is_here_doc(argv[1], &pipex_b) == 1) || (argc < 5 && ft_is_here_doc(argv[1], &pipex_b) == 0))
		return (msg(ERR_INPUT), 0);
	ft_get_infile(argv, &pipex_b);
	ft_get_outfile(argc, argv, &pipex_b);
	pipex_b.cmd_nbs = argc - 3 - ft_is_here_doc(argv[1], &pipex_b);
	pipex_b.pipe_nbs = pipex_b.cmd_nbs - 1;
	pipex_b.pipe = ft_calloc(sizeof(int), 2 * pipex_b.pipe_nbs);
	if (!pipex_b.pipe)
		msg_error(ERR_PIPE);
	pipex_b.env_path = ft_find_path(envp);
	pipex_b.cmd_paths = ft_split(pipex_b.env_path, ':');
	ft_generate_pipes(&pipex_b);
	while(pipex_b.index < pipex_b.cmd_nbs)
	{
		ft_generate_child(&pipex_b, argv, envp);
		pipex_b.index++;
	}
	ft_close_pipes(&pipex_b);
	waitpid(-1, NULL, 0);
	ft_parent_free(&pipex_b);
	return (0);
}
