/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:16:52 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/10 17:44:26 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_show_c(const char *s, t_list_printf *next)
{
	char new[1];
	
	if (next->type == '%') 
	{
		next->br++;
		new[0] = s[next->len];
		new[1] = '\0';
	}
	else 
	{
		next->br++;
		new[0] = next->c;
		new[1] = '\0';
	}
	if (next->flags > 1 && next->punt > 1)
		ft_putspace_zero(new, next);
	else if ((next->flags == 1) || (next->flags == '-') || (next->flags == '*'))
		ft_putspace(new, next);
	else if ((next->flags == '0') || (next->punt == '.'))
		ft_putzero(new, next);
}