/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 03:56:58 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/18 18:39:30 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_hexa(const char *s, t_list_printf *next)
{
	char *new;

	new = ft_tohexa(next->hexa, s[next->len]);
	if ((next->hexa == 0 && next->flags == '-' && next->punt == '.') ||
		(next->hexa == 0 && next->punt == '.'))
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
}
