/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 03:56:58 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/10 07:21:18 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_show_hexa(const char *s , t_list_printf *next)
{
	char *new;
	
	new = ft_tohexa(next->hexa, s[next->len]);
	/*if ((next->flags == 1 && next->punt != '.')|| (next->flags == '-' && next->punt != '.') || (next->flags == '*' 
		&& next->punt != '.'))
		ft_putspace(new, next);
	else if ((next->flags == '0') || (next->punt == '.' && next->flags != 1))
		ft_putzero(new, next);
	else if ((next->flags == '*' && next->punt == '.') || (next->flags == 1 && next->punt == '.')
			|| (next->flags == '-' && next->punt == '.'))*/
		ft_putspace_zero(new, next);
	/*else
		ft_putstr_fd(new, 1, next);*/
}