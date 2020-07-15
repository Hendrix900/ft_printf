/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:16:52 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/15 19:12:29 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_c(const char *s, t_list_printf *next)
{
	char c;
	char *new;
	c = next->c + '0';
	new = malloc(sizeof(char));
	new[1] = '\0';
	if (next->c == '\0' && next->type != '%')
	{
		next->c = '\0';//ft_putchar_fd(0, 1);
		next->br++;
	}
	else if (next->type == '%')
		new[0] = s[next->len];
	else
		new[0] = next->c;
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
	free(new);
	new = NULL;
}
