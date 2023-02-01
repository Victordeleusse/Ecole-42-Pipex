/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:28:03 by vde-leus          #+#    #+#             */
/*   Updated: 2023/02/01 14:50:23 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void	ft_son1(int *param, pid_t pid)
{
	if (pid == 0)
	{
		printf("FILS : Je suis le fils de PID interne %d || ", pid);
		*param = *param * 2;
		printf("VALEUR -> %d || ADRESSE : %p\n\n", *param, param);
		exit(EXIT_SUCCESS);
	}
	// if (pid_s > 0)
	// {
	// 	wait(NULL);
	// 	printf("FATHER : Je suis le pere , mon PID herite de mon fils est %d\n", pid_s);
	// }
}

void	ft_father(int *param)
{
	printf("FATHER : Je suis le pere\n");
	*param = *param - 21;
	printf("VALEUR -> %d || ADRESSE : %p\n\n", *param, param);
	// exit(EXIT_SUCCESS);
}

int	main(void)
{
	int		param_mem;
	// int		i;
	pid_t	pid_s;
	
	param_mem = 42;
	pid_s = fork();
	if (pid_s == -1)
		return (0);
	printf("FORK REUSSI !\n");
	// i = 0;
	// while (i < 2)
	// {
	if (pid_s == 0)	
		ft_son1(&param_mem, pid_s);
		// i++;
	// }
	else
	{
		wait(NULL);
		ft_father(&param_mem);
	}
	printf("PERE : NON ! la valeur du parametre : %d\n", param_mem);
	printf("La valeur FINALE du parametre : %d\n", param_mem);
	return(0);
}