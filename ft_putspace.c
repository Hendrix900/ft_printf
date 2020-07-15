/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:32:15 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/15 19:24:40 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putspace_left(char *new, t_list_printf *next)
{
	size_t	width;
	size_t	variable;
	int		total;

	width = next->width;
	variable = ft_strlen(new);
	if (variable >= width)
		ft_putstr_fd(new, 1, next);
	else if (variable < width)
	{
		total = width - variable;
		if (next->flags == '-')
		ft_putstr_fd(new, 1, next);
		while (total > 0)
		{
			ft_putchar_fd(' ', 1);
			total--;
			next->br++;
		}
		if (next->flags != '-')
		ft_putstr_fd(new, 1, next);
	}
}
/*
void	ft_putspace_right(char *new, t_list_printf *next)
{
	size_t	width;
	size_t	variable;
	int		total;

	width = next->width;
	variable = ft_strlen(new);
	if (variable >= width)
		ft_putstr_fd(new, 1, next);
	else if (variable < width)
	{
		total = width - variable;
		ft_putstr_fd(new, 1, next);
		while (total > 0)
		{
			ft_putchar_fd(' ', 1);
			total--;
			next->br++;
		}
	}
}
*/
void	ft_putspace(char *new, t_list_printf *next)
{
/*	if (next->flags == '-')
		ft_putspace_right(new, next);
	else*/
		ft_putspace_left(new, next);
}
