/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:59:12 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/29 18:08:16 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_get_data_here_doc(char *limiter, t_bonus_pipex *pipex_b)
{
	int		file;
	int		len;
	char	*temp_str;

	file = open("temporary_file", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
		msg_error(ERR_HEREDOC);
	while (1)
	{
		write(1, "heredoc> ", 9);
		temp_str = get_next_line(0);
		if (temp_str < 0)
			msg_error(ERR_LECTURE);
		len = ft_strlen(temp_str);
		temp_str[len - 1] = '\0';
		if (ft_strcmp(limiter, temp_str) == 0)
		{	
			free(temp_str);
			break ;
		}
		write(file, temp_str, ft_strlen(temp_str));
		write(file, "\n", 1);
		free(temp_str);
	}
	close(file);
	pipex_b->infile = open("temporary_file", O_RDONLY);
	if (pipex_b->infile < 0)
		msg_error(ERR_HEREDOC);
}

void	ft_get_infile(char **argv, t_bonus_pipex *pipex_b)
{
	if (ft_strcmp("here_doc", argv[1]) == 0)
		ft_get_data_here_doc(argv[2], pipex_b);
	else
	{
		pipex_b->infile = open(argv[1], O_RDONLY);
		if (pipex_b->infile < 0)
			msg_error(ERR_INFILE);
	}
}

void	ft_get_outfile(int argc, char **argv, t_bonus_pipex *pipex_b)
{
	if (pipex_b->here_doc == 1)
		pipex_b->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
		pipex_b->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (pipex_b->outfile < 0)
		msg_error(ERR_OUTFILE);
}
