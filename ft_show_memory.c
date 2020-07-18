/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 02:19:04 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/18 03:07:02 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_memoryzero(char *new, t_list_printf *next, char *null)
{
	size_t	width;
	size_t	variable;
	int		total;

	width = next->width;
	variable = ft_strlen(new) + ft_strlen(null);
	if (variable >= width)
		ft_putstr_fd(ft_strjoin(null, new), 1, next);
	else if (variable < width)
	{
		total = width - variable;
		next->flags != '0' ? ft_putstr_fd(ft_strjoin(null, new), 1, next) :
		ft_putstr_fd(null, 1, next);
		ft_zeros(total, next);
		next->flags != '0' ? ft_putstr_fd(ft_strjoin(null, new), 1, next) :
		ft_putstr_fd(new, 1, next);
	}
}

void	ft_memorypunt(char *new, t_list_printf *next, char *null)
{
	size_t	precision;
	size_t	variable;
	int		total;
	
	precision = next->precision;
	variable = ft_strlen(new);
	if (variable >= precision)
		ft_putstr_fd(ft_strjoin(null, new), 1, next);
	else if (variable < precision)
	{
		total = precision - variable;
		next->precision == '.' ? ft_putstr_fd(ft_strjoin(null, new), 1, next) :
		ft_putstr_fd(null, 1, next);
		ft_zeros(total, next);
		next->precision == '.' ? ft_putstr_fd(ft_strjoin(null, new), 1, next) :
		ft_putstr_fd(new, 1, next);
	}
}

void	ft_memoryspace(char *new, t_list_printf *next, char *null)
{
	size_t	width;
	size_t	variable;
	int		total;

	width = next->width;
	variable = ft_strlen(new) + ft_strlen(null);
	if (variable >= width)
		ft_putstr_fd(ft_strjoin(null, new), 1, next);
	else if (variable < width)
	{
		total = width - variable;
		if (next->flags == '-')
		ft_putstr_fd(ft_strjoin(null, new), 1, next);
		ft_spaces(total, next);
		if (next->flags != '-')
		ft_putstr_fd(ft_strjoin(null, new), 1, next);
	}
}

void ft_show_memory(const char *s , t_list_printf *next)
{
	char *new;
	char *null;
	
	null = "0x";
	new = ft_tomemory(next->p);
	if (next->flags >= 1 && next->punt > 1)
		ft_putspace_memory(new, next);
	else if ((next->flags == 1) || (next->flags == '-') || (next->flags == '*')) 
		ft_memoryspace(new, next, null);
	else if (next->punt == '.')
		ft_memorypunt(new, next, null);
	else if (next->flags == '0')
		ft_memoryzero(new, next, null);
	else
		ft_putstr_fd(ft_strjoin(null, new), 1, next);
}
