/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 03:43:18 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/16 04:40:09 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_check_str(const char *new, t_list_printf *next)
{
	char *conver;
	
	conver = ft_substr(new, 0, (next->precision));
	ft_putspace(conver, next);
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
	if (next->flags >= 0 && next->punt == '.')
		ft_check_str(new, next);
	else if ((next->flags == 1) || (next->flags == '-') || (next->flags == '*'))
		ft_putspace(new, next);
	else if (next->flags == '0')
		ft_putzero(new, next);
	else
	ft_putstr_fd(new, 1, next);
}
