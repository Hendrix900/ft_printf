/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:21:11 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/15 20:24:43 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_check_precision_minus(size_t v,size_t p, size_t w, char *new, t_list_printf *next)
{
	int count;

	count = 0;
	w = next->width;
	p = next->precision;

		if (next->neg == '-' && v < w)
			w--;
		if (next->neg == '-' && v > w)
		{
			ft_putchar_fd('-', 1, next);
			p++ ? p > 0 : p--; 
			count = 1;
		}
		else if (next->neg == '-' && w > p)
		{
			ft_putchar_fd('-', 1, next);
			p++ ? p > 0 : p--; 
			count = 1;
		}
		while (p > 0)
		{
			ft_putchar_fd('0', 1, next);
			p--;
		}
		ft_putstr_fd(new + count, 1, next);
		while (w > 0)
		{
			ft_putchar_fd(' ', 1, next);
			w--;
		}
}

void ft_check_precision_asterisk(size_t variable, char *new, t_list_printf *next)
{
	size_t width;
	size_t precision;
	int count;

	count = 0;
	width = next->width;
	precision = next->precision;
	if (next->flags == '-')
		ft_check_precision_minus(variable, precision, width, new, next);
	else
	{
		if (next->neg == '-' && variable < width)
			width--;
		while (width > 0)
		{
			ft_putchar_fd(' ', 1, next);
			width--;
		}
		if (next->neg == '-' && width < precision)
		{
			ft_putchar_fd('-', 1, next);
			precision++;
			count = 1;
		}
		else if (next->neg == '-' && width > precision)
		{
			ft_putchar_fd('-', 1, next);
			precision++;
			count = 1;
		}
		while (precision > 0)
		{
			ft_putchar_fd('0', 1, next);
			precision--;
		}
		ft_putstr_fd(new + count, 1, next);
	}
}

void ft_putspace_zero(char *new, t_list_printf *next)
{
	size_t width;
	size_t precision;
	size_t variable;
	int total;
	int count;

	count = 0;
	width = next->width;
	precision = next->precision;
	variable = ft_strlen(new);
	if (width == precision)
		ft_putzero(new + count, next);
	else if (width > precision)
	{
		next->precision = variable > precision ? precision = 0 : precision - variable;
		next->width = width - (next->precision + variable);
		ft_check_precision_asterisk(variable, new, next);
	}
	else if (precision > width)
		ft_putzero(new, next);
}
