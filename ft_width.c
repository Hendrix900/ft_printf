/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 05:50:04 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/17 01:40:13 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_print_f(const char *s, int l)
{
	size_t q;

	q = 0;
	while (s[l] >= '0' && s[l] <= '9')
	{
		q++;
		l++;
	}
	return (q);
}

void	ft_axterix(t_list_printf *next)
{
	next->width = va_arg(next->args, int);
	if (next->width < 0)
	{
		next->width *= -1;
		next->ar_neg = 1;
	}
	next->len++;
}

int		ft_width(const char *s, t_list_printf *next)
{
	char	*substr;
	size_t	q;

	next->ar_neg = 0;
	if (next->flags == '-' || next->flags == '0' || next->flags == 1
		|| next->flags == '*')
	{
		if (s[next->len] >= '0' && s[next->len] <= '9')
		{
			substr = ft_substr(s, next->len,
					(q = ft_strlen_print_f(s, next->len)));
			next->width = ft_atoi(substr);
			free(substr);
			substr = NULL;
			next->len += q;
		}
		else if (s[next->len] == '*')
			ft_axterix(next);
	}
	return (next->width);
}
