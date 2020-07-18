/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 23:34:09 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/19 00:52:55 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putzero_precision(size_t w, char *new, t_list_printf *next)
{
	size_t	variable;
	int		total;
	int		count;

	if (next->type == '%')
		next->precision = 0;
	w = next->precision;
	variable = ft_strlen(new);
	count = 0;
	if (next->neg == 1)
	{
		ft_putchar_fd('-', 1, next);
		variable--;
		count = 1;
	}
	if (variable >= w)
		ft_putstr_fd(new + count, 1, next);
	else if (variable < w)
	{
		total = w - variable;
		ft_zeros(total, next);
		ft_putstr_fd(new + count, 1, next);
	}
}

void	ft_putzero_0(size_t p, size_t w, char *new, t_list_printf *next)
{
	size_t	variable;
	int		total;
	int		count;

	variable = ft_strlen(new);
	count = 0;
	if (next->type == '%')
		p = 0;
	if (next->neg == 1)
	{
		ft_putchar_fd('-', 1, next);
		count = 1;
	}
	if ((variable >= w) || (variable >= w && p < variable))
		ft_putstr_fd(new + count, 1, next);
	else if ((variable < w) || (p > variable))
	{
		if (p > w && p > variable)
			total = w;
		else
			total = p > 0 ? p - variable : w - variable;
		ft_zeros(total, next);
		ft_putstr_fd(new + count, 1, next);
	}
}

void	ft_putzero(char *new, t_list_printf *next)
{
	size_t	width;
	size_t	precision;

	width = next->width;
	precision = next->precision;
	if (next->flags == '0' && next->punt != '.')
		ft_putzero_0(precision, width, new, next);
	else
		ft_putzero_precision(width, new, next);
}
