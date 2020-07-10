/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 03:43:18 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/10 17:55:03 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_str(t_list_printf *next)
{
	char *new;

	new = next->str;
	if (next->flags > 1 && next->punt > 1)
		ft_putspace_zero(new, next);
	else if ((next->flags == 1) || (next->flags == '-') || (next->flags == '*'))
		ft_putspace(new, next);
	else if ((next->flags == '0') || (next->punt == '.'))
		ft_putzero(new, next);
	else
		ft_putstr_fd(new, 1, next);
}
