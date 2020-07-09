/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:16:52 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/09 03:47:58 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_c (const char *s, t_list_printf *next)
{
	char new[1];
	new[0] = next->c;
	new[1] = '\0';
	if (next->type == '%')
		ft_putchar_fd('%', 1);
	if (next->flags == 1 || next->flags == '-' || next->flags == '*' && next->punt != '.')
		ft_putspace(new, s, next);
	else if (next->flags == '0' || next->punt == '.' && next->flags != '*')
		ft_putzero(new, s, next);
	else if (next->flags = '*' && next->punt == '.')
		ft_putspace_zero(new, s, next);
	else 
	ft_putstr_fd(new,1);
}