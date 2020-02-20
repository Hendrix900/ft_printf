/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 05:50:04 by ccastill          #+#    #+#             */
/*   Updated: 2020/02/19 05:50:04 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_printf(const char *s, int l)
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
		next->neg = 1;
	}
	next->len++;
}

int		ft_width(const char *s, int f, t_list_printf *next)
{
	char	*temp;
	size_t	len;

	next->neg = 0;
	if (f == '-' || f == '0' || f == '.' || f == 1 || f == '*')
	{
		if (s[next->len] >= '0' && s[next->len] <= '9')
		{
			temp = ft_substr(s, next->len,
					(len = ft_strlen_printf(s, next->len)));
			next->width = ft_atoi(temp);
			free(temp);
			temp = NULL;
			next->len += len;
		}
		else if (f == '*')
			ft_axterix(next); 
	}
	return (next->width);
}