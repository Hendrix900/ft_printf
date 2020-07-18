/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:21:11 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/18 03:17:15 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_w_p(size_t p, size_t w, char *new, t_list_printf *next)
{
	int count;

	count = 0;
	if (next->flags != '-')
		ft_spaces(w, next);
	ft_putstr_fd("0x", 1, next);
	ft_zeros(p, next);
	if (new != 0)  //añadido recientemente
		ft_putstr_fd(new, 1, next);
	if (next->flags == '-')
		ft_spaces(w, next);
}

void	ft_check_w_p(size_t p, size_t w, char *new, t_list_printf *next)
{
	size_t	variable;

	variable = ft_strlen(new);
	/*variable -= 2;*/
	p += 2;
	if (w == p)
		ft_putzero(new, next);
	else if (w > p)
	{
		if ((variable + 2) > p)
			p = 0;
		else
			p = p - (variable + 2);
		w = w - (p + (variable + 2));
		ft_put_w_p(p, w, new, next);
	}
	else if (p > w)
	{
		ft_putstr_fd("0x", 1, next);
		ft_putzero(new, next);
	}	
}

void	ft_putspace_memory(char *new, t_list_printf *next)
{
	size_t	width;
	size_t	precision;

	width = next->width;
	precision = next->precision;
	ft_check_w_p(precision, width, new, next);
}
