/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:28:03 by vde-leus          #+#    #+#             */
/*   Updated: 2023/02/01 13:10:46 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void	ft_son1(int *param, int i)
{
	pid_t	pid_s;
	
	pid_s = fork();
	if (pid_s == -1)
		return ;
	printf("FORK REUSSI !\n");
	if (pid_s == 0)
	{
		printf("FILS : Je suis le fils %d, de PID interne %d || ", i + 1, pid_s);
		*param = *param * 2;
		printf("VALEUR -> %d\n\n", *param);
		exit(EXIT_SUCCESS);
	}
	if (pid_s > 0)
	{
		wait(NULL);
		printf("FATHER : Je suis le pere , mon PID herite de mon fils est %d\n", pid_s);
	}
}

void	ft_father(int *param)
{
	printf("FATHER : Je suis le pere\n");
	*param = *param - 21;
	// exit(EXIT_SUCCESS);
}

int	main(void)
{
	int		param_mem;
	int		i;

	param_mem = 42;
	i = 0;
	while (i < 2)
	{	
		ft_son1(&param_mem, i);
		i++;
	}
	// wait(NULL);
	ft_father(&param_mem);
	printf("PERE : NON ! la valeur du parametre : %d\n", param_mem);
	printf("La valeur FINALE du parametre : %d\n", param_mem);
	return(0);
}