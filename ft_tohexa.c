/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 08:10:18 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/09 03:59:30 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/
#include "ft_printf.h"


char	*ft_tohexa(unsigned long int nb, char x)
{
	char				*new;
	char				*hexa;
	unsigned long int	nbr;
	unsigned long int	count;

	hexa = (x == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	count = 0;
	nbr = nb;
	while (nb != 0)
	{
		count++;
		nb = nb / 16;
	}
	if (nbr == 0)
		count++;
	new = (char *)malloc(sizeof(char) * (count + 1));
	new[count] = '\0';
	while (nbr != 0 || count > 0)
	{
		new[--count] = hexa[nbr % 16];
		nbr = nbr / 16;
	}
	return (new);
}
/*
int main()
{
	char *s;
	char *memory;

	long int a = 0;
	
	s = ft_tohexa(a, 'X');
	
	printf("El número hexadecimal es : %s\n", s);
	printf("El número hexadecimal es : %lX\n", a);
}
*/