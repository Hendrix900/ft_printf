/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 04:30:51 by carlos            #+#    #+#             */
/*   Updated: 2020/07/16 03:51:10 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_strlen_str(const char *s, int l)
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

int	ft_asterisk_1(t_list_printf *next)
{
	int width;

	width = 0;
	width = va_arg(next->args, int);
	if (width < 0)
	{
		width *= -1;
		next->neg = 1;
	}
	return (width);
}

int	ft_convert(const char *s, t_list_printf *next)
{
	char	*new;
	int		n;
	
	if (s[next->len] >= '0' && s[next->len] <= '9')
	{
		new = ft_substr(s, next->len, (ft_strlen_str(s, next->len)));
		next->len += ft_strlen_str(s, next->len);
		n = ft_atoi(new);
		free(new);
		new = NULL;
		return (n);
	}
	else if (s[next->len] == '*' && next->punt == '.')
	{
		next->len++;
		return(ft_asterisk_1(next));
	}
	else if (s[next->len] == '*' && next->flags == '0')
	{
		next->len++;
		return(ft_asterisk_1(next));
	}
	else if (!((s[next->len] >= '0' && s[next->len] <= '9')))
		return (0);
	else
		return(next->width);
}