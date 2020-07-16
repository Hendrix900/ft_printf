/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 01:09:36 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/16 19:09:24 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_str(const char *s, t_list_printf *next)
{
	next->flags = 0;
	next->width = 0;
	next->punt = 0;
	next->type = 0;
	next->precision = 0;
	next->flags = ft_flags(s, next);
	next->width = ft_width(s, next);
	next->punt = ft_punt(s, next);
	next->precision = ft_precision(s, next);
	next->type = ft_type(s, next);
//	printf("El ancho es : %d\n", next->width);//
//	printf("LA precision es : %d\n", next->precision);//
//	printf("LAs flags son : %d\n", next->flags);//
//	printf("EL punt es: %c\n", next->punt);//
	if (next->ar_neg == 1)
		next->flags = '-';
	if (next->type == 0)
		return (-1);
	else
		ft_show_type(s, next);
	return (0);
}

void str_printf(const char *s, t_list_printf *next)
{
	int err;

	while (s[next->len] != '\0')
	{
		if (s[next->len] != '%')
		{
			write(1, &s[next->len], 1);
			next->br++;
		}
		else
		{
			next->len++;
			while (s[next->len] == ' ')
				next->len++;
			if (s[next->len] == '\0')
				break;
			else
				err = check_str(s, next);
			if (err == -1)
				break;
		}
		next->len++;
	}
}

int ft_printf(const char *s, ...)
{
	t_list_printf *next;
	int				br;

	if (!(next = malloc(sizeof(t_list_printf))))
		return (0);
	va_start(next->args, s);
	next->len = 0;
	next->br = 0;
	br = 0;
	str_printf(s, next);
	br += next->br;
	va_end(next->args);
	free(next);
	next = NULL;
	return (br);
}
