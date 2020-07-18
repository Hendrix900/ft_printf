/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tomemory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 02:20:42 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/18 06:12:44 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_tomemory(long int nb)
{
	char				*hex;
	char				*base;
	long int			nbr;
	long int			len;

	base = "0123456789abcdef";
	len = 0; 
	nbr = nb;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	if (nbr == 0)
		len++;
	hex = (char *)malloc(sizeof(char) * len);
	hex[len] = '\0';
	while (nbr != 0 || len > 0)
	{
		hex[--len] = base[nbr % 16];
		nbr = nbr / 16;
	}
	return (hex);
}
