/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 02:19:04 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/16 12:26:53 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"


void	ft_memoryzero(char *new, t_list_printf *next, char *null)
{
	size_t	width;
	size_t	variable;
	int		total;
	int		count;

	width = next->precision;
	variable = ft_strlen(new);
	if (variable >= width)
		ft_putstr_fd(ft_strjoin(null, new), 1, next);
	else if (variable < width)
	{
		total = width - variable;
		while (total > 0)
		{
			ft_putchar_fd('0', 1, next);
			total--;
		}
		ft_putstr_fd(ft_strjoin(null, new), 1, next);
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
			ft_putstr_fd(null, 1, next);
		while (total > 0)
		{
			ft_putchar_fd(' ', 1,next);
			total--;
		}
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
	if (new == NULL)
	new = null;
	/*if ((next->p == 0 && next->flags == '-' && next->punt == '.') || 
		(next->p == 0 && next->punt == '.'))
	{
		new[1] = 'x';

	}*/

	if (next->punt > 1)
		ft_memoryzero(new, next, null);
	else if ((next->flags == 1) || (next->flags == '-') || (next->flags == '*'))
		ft_memoryspace(new, next, null);
	else if (new[0] == '-')
		next->neg = '-';
	else if (next->p == '\0')
		ft_putstr_fd(null,1,next);
	/*else if (next->flags >= 1 && next->punt > 1)
		ft_putspace_zero(new, next);
	else if ((next->flags == 1) || (next->flags == '-') || (next->flags == '*')) 
		ft_putspace(new, next);
	else if ((next->flags == '0') || (next->punt == '.'))
		ft_putzero(new, next);*/
	else
		ft_putstr_fd(ft_strjoin(null, new), 1, next);
}
