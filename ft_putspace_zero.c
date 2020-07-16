/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:21:11 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/17 01:15:20 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_prec(size_t v, size_t p, size_t w, char *new, t_list_printf *next)
{
	int count;

	count = 0;
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
	ft_zeros(p, next);
	ft_putstr_fd(new + count, 1, next);
	ft_spaces(w, next);
}

void	ft_check_ast(size_t v, size_t p, size_t w, char *new, t_list_printf *next)
{
	int count;

	count = 0;
	if (next->flags == '-')
		ft_check_prec(v, p, w, new, next);
	else
	{
		if (next->neg == '-' && v < w)
			w--;
		ft_spaces(w, next);
		if (next->neg == '-' && w < p && p != 0)
		{
			ft_putchar_fd('-', 1, next);
			p++;
			count = 1;
		}
		else if (next->neg == '-' && w > p && p != 0)
		{
			ft_putchar_fd('-', 1, next);
			p++;
			count = 1;
		}
		ft_zeros(p, next);
		ft_putstr_fd(new + count, 1, next);
	}
}

void	ft_putspace_zero(char *new, t_list_printf *next)
{
	size_t width;
	size_t precision;
	size_t variable;
	int count;

	count = 0;
	width = next->width;
	precision = next->precision;
	variable = ft_strlen(new);
	if (width == precision)
		ft_putzero(new + count, next);
	else if (width > precision)
	{
		precision = variable > precision ? precision = 0 : precision - variable;
		width = width - (precision + variable);
		ft_check_ast(variable, precision, width, new, next);
	}
	else if (precision > width)
		ft_putzero(new, next);
}
