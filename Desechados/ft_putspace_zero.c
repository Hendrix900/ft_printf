/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:21:11 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/17 16:52:01 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_memory(char *new, t_list_printf *next)
{
	char	*null;

	null = "0x";
	ft_putstr_fd(ft_strjoin(null, new), 1, next);
}

void	ft_check_prec(size_t p, size_t w, char *new, t_list_printf *next)
{
	int		count;
	size_t	v;

	v = ft_strlen(new);
	count = 0;
	if (next->neg == 1 && v < w)
		w--;
	if (next->neg == 1)                             // && v > w || next->neg == '-' && w > p)
	{
		next->type == 'p' ? ft_putstr_fd("0x", 1, next) :
		ft_putchar_fd('-', 1, next); 
		next->memory = 1;
		next->type == 'p' ? p+= 2 : p++;
		next->type == 'p' ? count+= 0 : count++;
		ft_putchar_fd('-', 1, next);
		p++ ? p > 0 : p--;
	}
	ft_zeros(p, next);
	next->type == 'p' ? print_memory(new, next) :
	ft_putstr_fd(new + count, 1, next);
	ft_spaces(w, next);
}

void	ft_check_ast(size_t p, size_t w, char *new, t_list_printf *next)
{
	int		count;
	size_t	v;
	v = ft_strlen(new);
	count = 0;
	if (next->flags == '-')
		ft_check_prec(p, w, new, next);
	else
	{
		if (next->neg == 1 && v < w)
			w--;
		ft_spaces(w, next);
		if (next->neg == 1 && p != 0 || next->type == 'p' && p != 0)
		{
			next->type == 'p' ? ft_putstr_fd("0x", 1, next) :
			ft_putchar_fd('-', 1, next); 
			next->memory = 1;
			next->type == 'p' ? p+= 2 : p++;
			next->type == 'p' ? count+= 0 : count++;
		}
		ft_zeros(p, next);
		next->type == 'p' && next->memory == 0 ? print_memory(new, next) :
		ft_putstr_fd(new + count, 1, next);
	}
}

void	ft_putspace_zero(char *new, t_list_printf *next)
{
	size_t	width;
	size_t	precision;
	size_t	variable;
	int		count;

	count = 0;
	width = next->width;
	precision = next->precision;
	variable = ft_strlen(new);
	if (next->type == 'p')
		variable += 2;
	if (next->type == 'p')
		width -= 2;
	if (width == precision)
		ft_putzero(new + count, next);
	else if (width > precision)
	{
		if (variable > precision)
			precision = 0;
		else
			precision = precision - variable;
		width = width - (precision + variable);
		ft_check_ast(precision, width, new, next);
	}
	else if (precision > width)
		ft_putzero(new, next);
}
