/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:55:36 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/29 17:43:04 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../Libft/libft.h"

/* write, read, close, access, pipe, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
/* malloc, free, exit */
# include <stdlib.h>
/* open, unlink */
# include <fcntl.h>
/* waitpid, wait */
# include <sys/wait.h>
/* strerror */
# include <string.h>
/* perror*/
# include <stdio.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_ENVP "Environment"
# define ERR_CMD "Command not found: "
# define ERR_HEREDOC "here_doc"
# define ERR_LECTURE "Impossible read"


typedef struct s_bonus_pipex
{
	int		infile;
	int		outfile;
	char	*env_path;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	int		here_doc;
	pid_t	pid;
	int		cmd_nbs;
	int		pipe_nbs;
	int		*pipe;
	int		index;
}t_bonus_pipex;

char	*ft_get_cmd(t_bonus_pipex *pipex_b);
void	ft_generate_child(t_bonus_pipex *pipex_b, char **argv, char **envp);

void	ft_parent_free(t_bonus_pipex *pipex_b);
void	ft_child_free(t_bonus_pipex *pipex_b);
void	ft_pipe_free(t_bonus_pipex *pipex_b);

void	ft_get_data_here_doc(char *limiter, t_bonus_pipex *pipex_b);
void	ft_get_infile(char **argv, t_bonus_pipex *pipex_b);
void	ft_get_outfile(int argc, char **argv, t_bonus_pipex *pipex_b);

void	ft_generate_pipes(t_bonus_pipex *pipex_b);
void	ft_first_child(t_bonus_pipex *pipex_b);
void	ft_middle_child(t_bonus_pipex *pipex_b);
void	ft_last_child(t_bonus_pipex *pipex_b);
void	ft_close_pipes(t_bonus_pipex *pipex_b);

int		msg(char *err);
void	msg_error_cmd(char *err);
void	msg_error(char *err);

int		ft_is_here_doc(char *str, t_bonus_pipex *pipex_b);
char	*ft_find_path(char **envp);


#endif