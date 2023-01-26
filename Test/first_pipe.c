/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:59:00 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/26 10:46:24 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>			// contient fork()

void	writestr(int fd, char *str)
{
	write(fd, str, strlen(str));		
}

int	main(void)
{
	pid_t	pid;
	int		pipefd[2];
	char	buffer;

	printf("DEBUT DU PROGRAMME\n");
	if (pipe(pipefd) == -1)				// on génère notre pipe et on test si sa création s'est bien faite
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1) 						
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)						// processus fils
	{
		close(pipefd[1]);
		writestr(STDOUT_FILENO, "Fils : Quel est le secret dans ce pipe ?\n");	
		while (read(pipefd[0], &buffer, 1) > 0)
			writestr(STDOUT_FILENO, &buffer);
		close(pipefd[0]);
		writestr(STDOUT_FILENO, "\nFils : Ohlala ! Je vais voir mon pere.\n");
		exit(EXIT_SUCCESS);
	}
	if (pid > 0)
	{
		close(pipefd[0]);
		writestr(STDOUT_FILENO, "Pere : J'ecris le secret dans le pipe ?\n");	
		writestr(pipefd[1], "\n	JE SUIS TON PERE !\n");
		close(pipefd[1]);
		wait(NULL);
		writestr(STDOUT_FILENO, "Pere : Hello mon fils\n");	
		exit(EXIT_SUCCESS);
	}
}
