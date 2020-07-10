/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:13:24 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/10 03:20:25 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_show_d(t_list_printf *next)
{
	char	*new;

	new = ft_itoa(next->i);
	if ((next->flags == 1 && next->punt != '.')|| (next->flags == '-') || (next->flags == '*' 
		&& next->punt != '.'))
		ft_putspace(new, next);
	else if ((next->flags == '0') || (next->punt == '.' && next->flags != 1))
		ft_putzero(new, next);
	else if ((next->flags == '*' && next->punt == '.') || (next->flags == 1 && next->punt == '.'))
		ft_putspace_zero(new, next);
	else
		ft_putstr_fd(new, 1, next);
}