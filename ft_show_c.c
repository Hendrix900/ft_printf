/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:16:52 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/11 23:29:49 by ccastill         ###   ########.fr       */
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
	if ((next->i == 0 && next->flags == '-' && next->punt == '.') || (next->i == 0 && next->punt == '.'))
	{
		//printf("Entra\n");
		new[0] = '\0';
	}
	if (new[0] == '-')
		next->neg = '-';
	if (next->flags >= 1 && next->punt > 1)
		ft_putspace_zero(new, next);
	else if ((next->flags == 1) || (next->flags == '-') || (next->flags == '*')) 
		ft_putspace(new, next);
	else if ((next->flags == '0') || (next->punt == '.'))
		ft_putzero(new, next);
	else
		ft_putstr_fd(new, 1, next);
}	