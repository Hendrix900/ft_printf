/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:21:11 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/10 22:29:28 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_check_precision_minus(char *new, t_list_printf *next)
{
	size_t width;
	size_t precision;

	width = next->width;
	precision = next->precision;

	while (precision > 0)
	{
		ft_putchar_fd('0', 1);
		precision--;
		next->br++;

	}
	ft_putstr_fd(new, 1, next);
	
	while (width > 0)
	{
		ft_putchar_fd(' ', 1);
		width--;
		next->br++;
	}
}

void	ft_check_precision_asterisk(char *new, t_list_printf *next)
{
	size_t width;
	size_t precision;
	int		count;
	
	count = 0;
	width = next->width;
	precision = next->precision;
	if (next->flags == '-')
		ft_check_precision_minus(new,next);
	else
	{
		if (next->neg == '-')
			width--;

		while (width > 0)
		{
			ft_putchar_fd(' ', 1);
			width--;
			next->br++;
		}
		if (next->neg == '-')
		{
			ft_putchar_fd('-', 1);
			next->br++;
			precision++;
			count = 1;
		}
		while (precision > 0)
		{
			ft_putchar_fd('0', 1);
			precision--;
			next->br++;
		}
		ft_putstr_fd(new + count, 1, next);	
	}
}

void ft_putspace_zero(char *new, t_list_printf *next)
{
	size_t	width;
	size_t	precision;
	size_t	variable;
	int		total;
	int		count;

	count = 0;
	width = next->width;
	precision = next->precision;
	variable = ft_strlen(new);
	if (width == precision)
		ft_putzero(new + count, next);
	else if (width > precision)
	{
		next->precision = variable > precision ? precision = 0 :
		precision - variable;
//		printf("L precision es : %d\n", next->precision);
		next->width = width - (next->precision + variable);
//		printf("el ancho es : %d\n", next->width);
		ft_check_precision_asterisk(new, next);
	}
	else if (precision > width)
		ft_putzero(new, next);
}
