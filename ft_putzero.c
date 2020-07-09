/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 23:34:09 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/09 05:14:28 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void ft_putzero_precision (char *new, t_list_printf *next)
{
	size_t width;
	size_t variable;
	//char *new;
	int total;
	
	width = next->precision;
	//new = ft_itoa(next->i);
	variable = ft_strlen(new);
		if (variable >= width)
			ft_putstr_fd(new,1);
		else if (variable < width)
		{
			total = width - variable;
			while (total > 0)
			{
				ft_putchar_fd('0', 1);
				total--;
			}
			ft_putstr_fd(new,1);
		}	
}

void ft_putzero_0 (char *new, t_list_printf *next)
{
	size_t width;
	size_t variable;
	//char *new;
	int total;
	
	width = next->width;
	//new = ft_itoa(next->i);
	variable = ft_strlen(new);
		if (variable >= width)
			ft_putstr_fd(new,1);
		else if (variable < width)
		{
			total = width - variable;
			while (total > 0)
			{
				ft_putchar_fd('0', 1);
				total--;
			}
			ft_putstr_fd(new,1);
		}	
}

void ft_putzero (char *new, t_list_printf *next)
{
	if (next->flags == '0')
		ft_putzero_0(new, next);
	else 
		ft_putzero_precision(new, next);
}
