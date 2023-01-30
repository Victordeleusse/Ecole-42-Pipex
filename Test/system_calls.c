/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_calls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:05:12 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/26 18:46:10 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef CHILD_EXIT_CODE
# define CHILD_EXIT_CODE 42
#endif

#define EXPECTED_CODE 42

void	ft_son_behaviour(pid_t pid)
{
	printf("FILS : Je suis le fils, mon PID est : %d\n", pid);
	printf("FILS : Mon Exit Code est : %d\n", CHILD_EXIT_CODE);
	sleep(3);
	exit(CHILD_EXIT_CODE);
}

void	ft_father_behaviour(pid_t pid)
{
	int	status;
	
	printf("PERE : Je suis le pere, j ai herite du PID %d de mon fils\n", pid);
	printf("PERE : J'attends mon fils [PID %d]\n", pid);
	waitpid(pid, &status, 0);
	printf("PERE : ENFIN !!!\n", pid);
	if (WIFEXITED(status) && WEXITSTATUS(status) == EXPECTED_CODE)
		printf("PERE : On est bon\n", pid);
	else if (WIFEXITED(status) && WEXITSTATUS(status) != EXPECTED_CODE)
		printf("PERE : Pas celui qui j'attendais\n", pid);
}


int	main(void)
{
	pid_t	pid;

	printf("DEBUT DE L EXERCICE\n\n");
	pid = fork();
	if (pid == -1)
		return(EXIT_FAILURE);
	else if (pid == 0)
		ft_son_behaviour(pid);
	else
		ft_father_behaviour(pid);
	return(EXIT_SUCCESS);	
}