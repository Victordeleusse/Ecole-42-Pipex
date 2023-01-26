/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:15:02 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/28 15:03:06 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* Recuperation de l adresse et conversion en base hexadecimale */

/* Mon adresse est recuperee comme un void* : je ne connais pas 
le type envoye en parametre : un int* ? un char* ? 
A caster en unsigned long ensuite car valeur trop grande pour etre 
contenue dans un int */

static int	ft_len_nbr_hex(unsigned long nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr = nbr / 16;
		i = i + 1;
	}
	return (i);
}

static char	*ft_putbase_hex_mini(unsigned long adress)
{
	char			*resultat;
	char			*base;
	int				i;

	base = "0123456789abcdef";
	if (adress == 0)
	{	
		resultat = (char *)malloc(sizeof(char) * 2);
		resultat[0] = '0';
		resultat[1] = '\0';
		return (resultat);
	}
	i = ft_len_nbr_hex(adress);
	resultat = (char *)malloc(sizeof(char) * (i + 1));
	if (!resultat)
		return (NULL);
	resultat[i] = '\0';
	i = i - 1;
	while (i >= 0)
	{
		resultat[i] = base[adress % 16];
		adress = adress / 16;
		i--;
	}
	return (resultat);
}

// Recuperation du param d entree void* -> recuperer une adresse sans type 
// et affichage + retour du len (+2 avec le 0x)

size_t	ft_putadress_min_hex(void *entree)
{
	char	*resultat;
	size_t	len;

	resultat = ft_putbase_hex_mini((unsigned long)entree);
	len = ft_strlen(resultat);
	if ((unsigned long)entree == 0)
	{
		ft_putstr("(nil)");
		free(resultat);
		return (len + 4);
	}
	ft_putstr("0x");
	ft_putstr(resultat);
	free(resultat);
	return (len + 2);
}

//0x7ff7bf2b5498
//140702040937624

// int	main(void)
// {
// 	void	*ptr_i;
// 	int		i;
// 	size_t	test;

// 	i = 561;
// 	ptr_i = &i;
// 	printf("test : %ld\n\n", (unsigned long)ptr_i);
// 	test = ft_putadress_min_hex(ptr_i);
// 	printf("\nvs. printf :");
// 	printf("%p\n", ptr_i);
// 	printf("%p\n", (void *)15);
// 	return (0);
// }
