/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 05:50:04 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/10 03:23:59 by carlos           ###   ########.fr       */
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

int	ft_asterisk(t_list_printf *next)
{
	int width;

	width = 0;
	width = va_arg(next->args, int);
	return (width);
}

int	ft_conver_width(const char *s, t_list_printf *next)
{
	char	*new;
	int		n;
	
	new = ft_substr(s, next->len, (ft_strlen_str(s, next->len)));
	next->len += ft_strlen_str(s, next->len);
	n = ft_atoi(new);
	free(new);
	new = NULL;
	return (n);
}

int	ft_width(const char *s, t_list_printf *next)
{
	int count;
	//printf("len es : %c\n", s[next->len]);

	if (next->flags == '0' || next->flags == 1 || next->flags == '-')
		next->width = ft_conver_width(s, next);
	if (next->flags == '*')
		next->width = ft_asterisk(next);
	if (next->punt == '.' && next->flags == 1)
	{
		next->len++;
		next->precision = ft_conver_width(s, next);
	}
	else if (next->punt == '.')
		next->precision = ft_conver_width(s, next);
	//printf("len es : %c\n", s[next->len]);
	//printf("tiene el :%c\n", next->punt);
	//printf("EL ancho es :%d\n", next->width);
	//printf("La precisión es %d\n", next->precision);

	return (next->width);
}
