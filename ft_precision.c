/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 05:05:27 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/16 05:06:26 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_print_p(const char *s, int l)
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

int		ft_precision(const char *s, t_list_printf *next)
{
	char	*substr;
	size_t	q;

	if (next->punt == '.')
	{
		if (s[next->len] >= '0' && s[next->len] <= '9')
		{
			substr = ft_substr(s, next->len,
					(q = ft_strlen_print_p(s, next->len)));
			next->precision = ft_atoi(substr);
			free(substr);
			substr = NULL;
			next->len += q;
		}
		else if (s[next->len] == '*')
		{
			next->precision = va_arg(next->args, int);
			if (next->precision < 0)
				next->punt = 0;
			next->len++;
		}
	}
	return (next->precision);
}