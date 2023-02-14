/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:37:54 by vde-leus          #+#    #+#             */
/*   Updated: 2023/02/14 16:08:11 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_initialise_recep_file_from_here_doc(int *recep_file)
{
	*recep_file = open("temporary file", O_CREAT | O_WRONLY | O_TRUNC, 0000664);
	if (*recep_file < 0)
		ft_msg_err(ERR_HEREDOC);
}

void	ft_infile_from_here_doc(t_pipex *pipex, int *recep_file)
{
	close(*recep_file);
	pipex->infile = open("temporary file", O_RDONLY, 0000664);
	if (pipex->infile < 0)
	{
		unlink("temporary file");
		ft_msg_err(ERR_HEREDOC);
	}
}

void	ft_here_doc_treat(t_pipex *pipex, char *limiter)
{
	int		recep_file;
	int		len;
	char	*temp;

	ft_initialise_recep_file_from_here_doc(&recep_file);
	while (1)
	{
		write(1, "heredoc> ", 9);
		temp = get_next_line(0);
		if (!temp)
			ft_msg_err(ERR_HEREDOC_READ);
		len = ft_strlen(temp);
		temp[len - 1] = '\0';
		if (ft_strcmp(temp, limiter) == 0)
		{	
			free(temp);
			break ;
		}
		write(recep_file, temp, ft_strlen(temp));
		write(recep_file, "\n", 1);
		free (temp);
	}
	ft_infile_from_here_doc(pipex, &recep_file);
}

void	ft_get_infile(t_pipex *pipex, char **argv)
{
	if (pipex->is_here_doc == 0)
		pipex->infile = open(argv[1], O_RDONLY);
	else
		ft_here_doc_treat(pipex, argv[2]);
}

void	ft_get_outfile(t_pipex *pipex, char **argv, int argc)
{
	if (pipex->is_here_doc == 0)
		pipex->outfile = open(argv[argc -1], \
			O_CREAT | O_RDWR | O_TRUNC, 0000664);
	else if (pipex->is_here_doc == 1)
		pipex->outfile = open(argv[argc -1], \
			O_WRONLY | O_CREAT | O_APPEND, 0000664);
	if (pipex->outfile < 0)
	{	
		close(pipex->infile);
		ft_msg_err(ERR_OUTFILE);
	}
}
