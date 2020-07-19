/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:13:24 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/19 02:08:49 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_d(t_list_printf *next)
{
	char *new;

	new = ft_itoa(next->i);
	if ((next->i == 0 && next->flags == '-' && next->punt == '.') ||
		(next->i == 0 && next->punt == '.'))
		new[0] = '\0';
	if (new[0] == '-')
		next->neg = 1;
	if (next->flags >= 1 && next->punt > 1)
		ft_putspace_zero(new, next);
	else if ((next->flags == 1) || (next->flags == '-') || (next->flags == '*'))
		ft_putspace(new, next);
	else if ((next->flags == '0') || (next->punt == '.'))
		ft_putzero(new, next);
	else
		ft_putstr_fd(new, 1, next);
	free(new);
	new = NULL;
}
