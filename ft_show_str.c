/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 03:43:18 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/09 05:34:20 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_show_str(t_list_printf *next)
{
	char *new;
	
	new = next->str;
	if ((next->flags == 1) || (next->flags == '-') || (next->flags == '*' && next->punt != '.'))
		ft_putspace(new, next);
	else if ((next->flags == '0') || (next->punt == '.' && next->flags != '*'))
		ft_putzero(new, next);
	else if ((next->flags == '*' && next->punt == '.'))
		ft_putspace_zero(new, next);
	else
		ft_putstr_fd(new, 1);
}