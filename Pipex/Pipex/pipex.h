/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:20:15 by vde-leus          #+#    #+#             */
/*   Updated: 2023/02/08 14:53:37 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_INFILE "Infile : Invalid folder.\n"
# define ERR_OUTFILE "Outfile : Invalid folder.\n"
# define ERR_HEREDOC "Here_doc : an error as occured.\n"
# define ERR_HEREDOC_READ "Here_doc : an error as occured \
when getting information.\n"
# define ERR_CMD "command error : "
# define ERR_CALLOC "calloc error : "
# define ERR_ENVP "Environment error.\n"
# define ERR_PIPE "pipe : an error as occured.\n"

typedef struct s_pipex
{
	int		nb_cmds;
	int		is_here_doc;
	int		infile;
	int		outfile;
	int		nb_pipes;
	int		*pipefd;
	char	*env_path;
	char	**command_paths;
	char	**command_args;
	char	*command;
	int		index;
	pid_t	pid;
	pid_t	*tab_pid;
}t_pipex;

//////////////////// MSG.C ////////////////////

void	ft_msg(char *message);
void	ft_msg_infile(char *message);
void	ft_msg_err_command(char *message);
void	ft_msg_err(char *message);

//////////////////// GET_FILES.C ////////////////////

void	ft_here_doc_treat(t_pipex *pipex, char *limiter);
void	ft_get_infile(t_pipex *pipex, char **argv);
void	ft_get_outfile(t_pipex *pipex, char **argv, int argc);

//////////////////// FREE.C ////////////////////

void	ft_free_pipes(t_pipex *pipex);
void	ft_free_parent_prog(t_pipex *pipex);
void	ft_free_child_prog(t_pipex *pipex);

//////////////////// PIPE.C ////////////////////

void	ft_generate_pipes(t_pipex *pipex);
void	ft_first_child(t_pipex *pipex);
void	ft_last_child(t_pipex *pipex);
void	ft_middle_child(t_pipex *pipex);
void	ft_close_pipes(t_pipex *pipex);

//////////////////// CHILD.C ////////////////////

char	*ft_get_command_for_the_pipe(t_pipex *pipex);
void	ft_generate_child_process(t_pipex *pipex, char **argv, char **envp, \
	pid_t *tab);

//////////////////// PIPEX.C ////////////////////

int		ft_is_here_doc(t_pipex *pipex, int argc, char **argv);
char	*ft_get_env_path(char **envp);
void	ft_init_pipex(t_pipex *pipex, int argc, char **argv);
void	ft_init_pipex_bonus(t_pipex *pipex, int argc, char **argv, char **envp);

#endif
