/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:21:11 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/17 19:28:30 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*void	print_memory(char *new, t_list_printf *next)
{
	char	*null;

	null = "0x";
	ft_putstr_fd(ft_strjoin(null, new), 1, next);
}*/
/*
void	ft_check_prec(size_t p, size_t w, char *new, t_list_printf *next)
{
	int		count;
	size_t	v;

	v = ft_strlen(new);
	count = 0;
	if (next->neg == 1 )
	{
		ft_putchar_fd('-', 1, next);
		count = 1;
	}
	ft_zeros(p, next);
	ft_putstr_fd(new + count, 1, next);
	ft_spaces(w, next);
}
*/
void	ft_check_ast(size_t p, size_t w, char *new, t_list_printf *next)
{
	int		count;
	size_t	v;
	
	v = ft_strlen(new);
	count = 0;
	/*if (next->flags == '-')
		ft_check_prec(p, w, new, next);*/
/*	else
	{*/
		if (next->flags != '-')
		ft_spaces(w, next);
		if (next->neg == 1) /*&& p != 0*/
		{
			ft_putchar_fd('-', 1, next);
			count = 1;
		}
		ft_zeros(p, next);
		ft_putstr_fd(new + count, 1, next);
		if (next->flags == '-')
			ft_spaces(w, next);
	/*}*/
}

void	ft_check_s_z(size_t p, size_t w, char *new, t_list_printf *next)
{
	size_t	variable;

	variable = ft_strlen(new);
	if (next->neg == 1)
	{
		variable--;
		p++;
	}
	if (w == p)
		ft_putzero(new, next);
	else if (w > p)
	{
		if ((variable + next->neg) > p)
			p = 0;
		else
			p = p - (variable + next->neg);
		w = w - (p + (variable + next->neg));
		ft_check_ast(p, w, new, next);
	}
	else if (p > w)
		ft_putzero(new, next);
}

void	ft_putspace_zero(char *new, t_list_printf *next)
{
	size_t	width;
	size_t	precision;

	width = next->width;
	precision = next->precision;
	ft_check_s_z(precision, width, new, next);
}
