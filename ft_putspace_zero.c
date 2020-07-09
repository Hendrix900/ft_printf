/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:21:11 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/09 05:32:54 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_precision_asterisk(char *new, t_list_printf *next)
{
	size_t width;
	size_t precision;

	width = next->width;
	precision = next->precision;

	while (width > 0)
	{
		ft_putchar_fd(' ', 1);
		width--;
	}
	while (precision > 0)
	{
		ft_putchar_fd('0', 1);
		precision--;
	}
	ft_putstr_fd(new, 1);
}

void ft_putspace_zero(char *new, t_list_printf *next)
{
	size_t	width;
	size_t	precision;
	size_t	variable;
	int		total;

	width = next->width;
	precision = next->precision;
	new = ft_itoa(next->i);
	variable = ft_strlen(new);

	if (width == precision)
		ft_putzero(new, next);
	else if (width > precision)
	{
		next->precision = precision - variable;
		next->width = width - (next->precision + variable);
		ft_check_precision_asterisk(new, next);
	}
	else if (precision > width)
		ft_putzero(new, next);
}
