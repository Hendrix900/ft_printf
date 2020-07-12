/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 02:19:04 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/12 03:03:02 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_show_memory(const char *s , t_list_printf *next)
{
	char *new;
	
	new = ft_tomemory(next->p);
	if ((next->p == 0 && next->flags == '-' && next->punt == '.') || (next->p == 0 && next->punt == '.'))
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
