/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:32:15 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/17 01:33:56 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putspace(char *new, t_list_printf *next)
{
	size_t	width;
	size_t	variable;
	int		total;

	width = next->width;
	variable = ft_strlen(new);
	if (variable >= width)
		next->type == 'c' && next->c == '\0' ? ft_putchar_fd(0, 1, next) :
		ft_putstr_fd(new, 1, next);
	else if (variable < width)
	{
		total = width - variable;
		if (next->flags == '-')
			next->type == 'c' && next->c == '\0' ? ft_putchar_fd(0, 1, next) :
			ft_putstr_fd(new, 1, next);
		while (total > 0)
		{
			ft_putchar_fd(' ', 1, next);
			total--;
		}
		if (next->flags != '-')
			next->type == 'c' && next->c == '\0' ? ft_putchar_fd(0, 1, next) :
			ft_putstr_fd(new, 1, next);
	}
}
