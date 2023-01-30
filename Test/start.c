/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:28:03 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/29 17:09:40 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_son(pid_t pid, int *param, char *test)
{
	printf("FILS : Je suis le fils, de PID interne %d\n", pid);
	*param = *param * 2;
	test[0] = 'O';
	test[1] = 'K';
	test[2] = '\0';
	// exit(EXIT_SUCCESS);

}

void	ft_father(pid_t pid, int *param, char *test)
{
	printf("FATHER : Je suis le pere , mon PID herite de mon fils est %d\n", pid);
	*param = *param - 21;
	free(test);
	wait(NULL);
	// exit(EXIT_SUCCESS);
}

void	ft_cut(int crash)
{
	if (crash == 0)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	pid_t	pid;
	int		*param_mem;
	char	*test;

	test = (char *)malloc(sizeof(char) * 3);
	pid = fork();
	param_mem = 42;
	if (pid == -1)
		return(EXIT_FAILURE);
	printf("FORK REUSSI !\n");
	if (pid == 0)
	{
		printf("adresse : %p\n", &param_mem);
		ft_son(pid, &param_mem, test);
		printf("FILS : la valeur du parametre : %d\n", param_mem);
	}
	if (pid > 0)
	{
		printf("adresse : %p\n", &param_mem);
		ft_father(pid, &param_mem, test);
		printf("PERE : NON ! la valeur du parametre : %d\n", param_mem);
	}
	printf("La valeur FINALE du parametre : %d\n", param_mem);
	printf("char test : %s\n", test);
	return(0);
}