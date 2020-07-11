/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 04:34:30 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/11 04:38:05 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_nb2(unsigned long int nb)
{
	int				count;
	unsigned int	c;

	c = 0;
	count = 0;
	if (nb < 0)
	{
		c = nb * -1;
		count++;
	}
	if (nb > 0)
		c = nb;
	while (c >= 10)
	{
		c = c / 10;
		count++;
	}
	if (c < 10)
		count++;
	return (count);
}

void	ft_putnum2(char *s, unsigned long int n, int l)
{
	unsigned int c;

	c = 0;
	s[l--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		c = n * -1;
	}
	if (n > 0)
		c = n;
	while (c > 10 || (c <= 10 && c != 0))
	{
		s[l--] = c % 10 + 48;
		c = c / 10;
	}
}

char	*ft_itou(unsigned long int n)
{
	char	*new;
	int		l;

	l = ft_count_nb2(n);
	new = (char*)malloc(sizeof(char) * l + 1);
	if (new == 0)
		return (NULL);
	ft_putnum2(new, n, l);
	return (new);
}
