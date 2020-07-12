/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tomemory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 02:20:42 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/12 02:10:38 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_tomemory(unsigned int nb)
{
	char				*hex;
	char				*base;
	unsigned  int	nbr;
	unsigned  int	len;

	base = "0123456789abcdef";
	len = 4;
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
	hex[2] = '1';
	hex[3] = '0';
	return (hex);
}
