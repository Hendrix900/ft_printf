/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 05:05:27 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/19 01:24:38 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_str_precision(const char *s, int l)
{
	size_t count;

	count = 0;
	while (s[l] >= '0' && s[l] <= '9')
	{
		count++;
		l++;
	}
	return (count);
}

void	ft_asterisk_precision(t_list_printf *next)
{
	next->precision = va_arg(next->args, int);
	if (next->precision < 0)
		next->precision = 0; //quitado punt, puesto precision
	next->len++;
}

int		ft_precision(const char *s, t_list_printf *next)
{
	char	*new;

	if (next->punt == '.')
	{
		if (s[next->len] >= '0' && s[next->len] <= '9')
		{
			new = ft_substr(s, next->len, ft_strlen_str(s, next->len));
			next->width = ft_atoi(new);
			free(new);
			new = NULL;
			next->len += ft_strlen_str(s, next->len);
		}
		else if (s[next->len] == '*')
			ft_asterisk(next);
	}
	return (next->precision);
}
