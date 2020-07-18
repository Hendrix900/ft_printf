/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 05:50:04 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/19 01:12:38 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_str(const char *s, int l)
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

void	ft_asterisk(t_list_printf *next)
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
	char	*new;

	next->ar_neg = 0;
	if (next->flags == '-' || next->flags == '0' || next->flags == 1 ||
	next->flags == '*')
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
	return (next->width);
}
