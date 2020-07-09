/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:32:15 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/09 03:26:15 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putspace_left (char *new, const char *s, t_list_printf *next)
{
		size_t width;
		size_t variable;
		//char *new;
		int total;
	
		width = next->width;
		//new = ft_itoa(next->i);
		variable = ft_strlen(new);
			if (variable >= width)
			{
				ft_putstr_fd(new,1);
			}
			else if (variable < width)
			{
				total = width - variable;
				while (total > 0)
				{
					ft_putchar_fd(' ', 1);
					total--;
				}
			ft_putstr_fd(new,1);
			}
}

void ft_putspace_right (char *new, const char *s, t_list_printf *next)
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
			ft_putstr_fd(new,1);
			while (total > 0)
			{
				ft_putchar_fd(' ', 1);
				total--;
			}
		}	
}

void ft_putspace (char *new, const char *s, t_list_printf *next)
{
	if (next->flags == '-')
		ft_putspace_right(new, s, next);
	else
		ft_putspace_left(new, s,next);
}