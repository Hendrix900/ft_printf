/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 03:43:18 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/13 22:28:45 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_check_str(const char *new, t_list_printf *next)
{
	char *conver;

	if (next->width <= next->precision)
	{
		conver = ft_substr(new, 0, (next->precision));
		ft_putstr_fd(conver, 1, next);
	}
	else if (next->width > next->precision)
	{
		conver = ft_substr(new, 0, (next->precision));
		ft_putspace(conver, next);
	}

}
void ft_show_str(const char *s, t_list_printf *next)
{
	char *new;
	char *null;

	null = "(null)";
	new = next->str;
	if (next->str == NULL)
		new = null;
	else
	 	new = next->str;
	if (next->flags >= 0 && next->punt > 1)
		ft_check_str(new, next);
	else if ((next->flags == 1) || (next->flags == '-') || (next->flags == '*'))
		ft_putspace(new, next);
	/*else if ((next->flags == '0') || (next->punt == '.'))
		ft_putzero(new, next);*/
	else
	ft_putstr_fd(new, 1, next);
}
