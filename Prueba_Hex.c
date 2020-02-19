/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 08:10:18 by ccastill          #+#    #+#             */
/*   Updated: 2020/02/18 08:10:18 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_putnbr_base_x(unsigned long int nb, char xcase)
{
	char				*hex;
	char				*base;
	unsigned long int	nbr;
	unsigned long int	len;

	base = (xcase == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	len = 0;
	nbr = (nb < 0) ? nb * -1 : nb;
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
	return (hex);
}

int main()
{
	unsigned long int b;
	b = -94235;
	char *s;

	s = ft_putnbr_base_x(b, 'X');
	
	printf("El número hexadecimal es : %s\n", s);
	printf("El número hexadecimal es : %X\n", b);

}