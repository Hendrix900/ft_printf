/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 23:34:09 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/17 16:51:44 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putzero_precision(char *new, t_list_printf *next)
{
	size_t	width;
	size_t	variable;
	int		total;
	int		count;

	width = next->precision;
	variable = ft_strlen(new);
	count = 0;
	if (next->neg == 1 || next->type == 'p')
	{
		next->type == 'p' ? ft_putstr_fd("0x", 1, next) :
		ft_putchar_fd('-', 1, next); 
		variable--;
		count = 1;
	}
	if (variable >= width)
		ft_putstr_fd(new + count, 1, next);
	else if (variable < width)
	{
		total = width - variable;
		ft_zeros(total, next);
		ft_putstr_fd(new + count, 1, next);
	}
}

void	ft_putzero_0(char *new, t_list_printf *next)
{
	size_t	width;
	size_t	variable;
	size_t	precision;
	int		total;
	int		count;
	width = next->width;
	precision = next->precision;
	variable = ft_strlen(new);
	count = 0;
	if (next->neg == 1 || next->type == 'p')
	{
		next->type == 'p' ? ft_putstr_fd("0x", 1, next) : ft_putchar_fd('-', 1, next); 
		count = 1;
	}
	if ((variable >= width) || (variable >= width && precision < variable)) // AÑADIDO RECIENTEMENTE (variable >= width )
		ft_putstr_fd(new + count, 1, next);
	else if ((variable < width) || (precision > variable))
	{
		if (precision > width && precision > variable)
			total = width;
		else
			total = precision > 0 ? precision - variable : width - variable; // precision - variable
		ft_zeros(total, next);
		ft_putstr_fd(new + count, 1, next);
	}
}

void	ft_putzero(char *new, t_list_printf *next)
{
	if (next->flags == '0' && next->punt != '.')
		ft_putzero_0(new, next);
	else
		ft_putzero_precision(new, next);
}
