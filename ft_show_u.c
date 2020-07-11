/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 04:27:37 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/11 23:51:58 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_show_u(t_list_printf *next)
{
	char *new;
	new = ft_itou(next->u);
	if ((next->u == 0 && next->flags == '-' && next->punt == '.') || (next->u == 0 && next->punt == '.'))
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