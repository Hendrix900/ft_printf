/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prueba_Memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 08:10:18 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/10 00:10:30 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_memory(unsigned long int nb);

int main()
{
	char *s;
	char *memory;

	int a = 325;

	memory = ft_memory(a);
	printf("La dirección de memoria es: %s\n", memory);
	printf("La dirección de memoria es: %p\n", &a);

}

char	*ft_memory(unsigned long int nb)
{
	char				*hex;
	char				*base;
	unsigned long int	nbr;
	unsigned long int	len;

	base = "0123456789abcdef";
	len = 2;
	nbr = nb;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	if (nbr == 0)
		len++;
	hex = (char *)malloc(sizeof(char) * (len + 1));
	hex[len] = '\0';
	while (nbr != 0 || len > 0)
	{
		hex[--len] = base[nbr % 16];
		nbr = nbr / 16;
	}
	hex[0] = '0';
	hex[1] = 'x';
	return (hex);
}
