/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:16:52 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/18 00:55:42 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_c(const char *s, t_list_printf *next)
{
	char c;
	char *new;

	c = next->c + '0';
	new = malloc(sizeof(char)); // añadir 1 espacio para el NULL ??
	new[1] = '\0';
	if (next->c == '\0' && next->type != '%')
		next->c = '\0';
	else if (next->type == '%')
		new[0] = s[next->len];
	else
		new[0] = next->c;
	if (new[0] == '-')
		next->neg = 1;
	if (next->flags >= 1 && next->punt > 1)
		ft_putspace_zero(new, next);
	else if ((next->flags == 1) || (next->flags == '-') || (next->flags == '*'))
		ft_putspace(new, next);
	else if ((next->flags == '0') || (next->punt == '.'))
		ft_putzero(new, next);
	else
		next->type == 'c' && next->c == '\0' ? ft_putchar_fd(0, 1, next) :
		ft_putstr_fd(new, 1, next);
	free(new);
	new = NULL;
}
