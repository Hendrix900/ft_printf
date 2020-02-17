/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:18:16 by ccastill          #+#    #+#             */
/*   Updated: 2020/02/17 16:18:16 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_convert_len(int n)
{
	unsigned long int nb;
	int l;

	nb = n;	
	l = 0;
	if (n == 0)
		l++;
	while (n != 0)
	{
		n = n / 16;
		l++;
	}
	return (l);
}

char 	*ft_convert_hexa(int n)
{
	char *s;
	int l;
	int rest;

	l = ft_convert_len(n);
	s = malloc(sizeof(char) * l);
	s[l--] = '\0';
	if (n == 0)
		s[l--] = 48;
	while (n != 0)
	{
		rest = n % 16;
		if (rest < 10)
			s[l--] = (char)(48 + rest);
		else if (rest >= 10)
			s[l--] = (char)(55 + rest);
		n = n / 16;
	}
	return (s);
}

int main()
{
	int b;
	b = 0;
	char *s;

	s = ft_convert_hexa(b);
	
	printf("El número hexadecimal es : %s\n", s);

}