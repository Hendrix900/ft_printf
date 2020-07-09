/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:32:15 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/09 05:29:46 by ccastill         ###   ########.fr       */
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
	{
		ft_putstr_fd(new, 1);
	}
	else if (variable < width)
	{
		total = width - variable;
		while (total > 0)
		{
			ft_putchar_fd(' ', 1);
			total--;
		}
		ft_putstr_fd(new, 1);
	}
}

void	ft_putspace_right(char *new, t_list_printf *next)
{
	size_t	width;
	size_t	variable;
	int		total;

	width = next->width;
	variable = ft_strlen(new);
	if (variable >= width)
		ft_putstr_fd(new, 1);
	else if (variable < width)
	{
		total = width - variable;
		ft_putstr_fd(new, 1);
		while (total > 0)
		{
			ft_putchar_fd(' ', 1);
			total--;
		}
	}
}

void	ft_putspace(char *new, t_list_printf *next)
{
	if (next->flags == '-')
		ft_putspace_right(new, next);
	else
		ft_putspace_left(new, next);
}
