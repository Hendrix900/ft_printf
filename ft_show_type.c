/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:22:16 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/11 05:21:32 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_show_type(const char *s, t_list_printf *next)
{
	next->neg = 0;
	if (next->type == 'd' || next->type == 'i')
	{
		next->i = va_arg(next->args, int);
		ft_show_d(next);
	}
	else if (next->type == 'c')
	{
		next->c = va_arg(next->args, int);
		ft_show_c(s, next);
	}
	else if (next->type == '%')
		ft_show_c(s, next);
	else if (next->type == 's')
	{
		next->str = va_arg(next->args, char *);
		ft_show_str(next);
	}
	else if (next->type == 'x')
	{
		next->hexa = va_arg(next->args, int);
		ft_show_hexa(s,next);
	}
	else if (next->type == 'p')
	{
		next->p = va_arg(next->args, int);
		ft_show_memory(s,next);
	}
	else if (next->type == 'u')
	{
		next->u = va_arg(next->args, unsigned int);
		ft_show_u(next);
	}	
}
