/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:21:11 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/10 06:28:17 by carlos           ###   ########.fr       */
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
		next->br++;

	}
	while (precision > 0)
	{
		ft_putchar_fd('0', 1);
		precision--;
		next->br++;

	}
	ft_putstr_fd(new, 1, next);
}

void ft_putspace_zero(char *new, t_list_printf *next)
{
	size_t	width;
	size_t	precision;
	size_t	variable;
	int		total;

	width = next->width;
	precision = next->precision;
	variable = ft_strlen(new);

	if (width == precision)
		ft_putzero(new, next);
	else if (width > precision)
	{
		next->precision = variable > precision ? precision = 0 :
		variable - precision;
		next->width = width - (next->precision + variable);
		ft_check_precision_asterisk(new, next);
	}
	else if (precision > width)
		ft_putzero(new, next);
}
