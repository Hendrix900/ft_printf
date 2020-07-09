/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:13:24 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/09 05:16:41 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_d (t_list_printf *next)
{
	char *new;
	int d;
	size_t l;

	d = 0;
	new = ft_itoa(next->i);
	l = ft_strlen(new);

	if ((next->flags == 1) || (next->flags == '-') || (next->flags == '*' && next->punt != '.'))
		ft_putspace(new, next);
	else if ((next->flags == '0') || (next->punt == '.' && next->flags != '*'))
		ft_putzero(new, next);
	else if ((next->flags == '*' && next->punt == '.'))
		ft_putspace_zero(new, next);
	else 
	ft_putstr_fd(new,1);
}