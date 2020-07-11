/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 05:50:04 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/11 23:10:59 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_asterisk(t_list_printf *next)
{
	int width;

	width = 0;
	width = va_arg(next->args, int);
	return (width);
}

int	ft_width(const char *s, t_list_printf *next)
{	
//	printf("LA posición es: %c\n", s[next->len]);

	if ((next->flags == '0' && next->punt != '.') || (next->flags == '-' && next->punt != '.'))
		next->width = ft_convert(s, next);
	if (next->flags == '*')
		next->width = ft_asterisk(next);
	if (next->punt == '.')
		next->precision = ft_convert(s, next);
//	printf("el ancho es : %d\n", next->width);
//	printf("La precision es : %d\n", next->precision);
//	printf("LA flag es : %d\n", next->flags);
//	printf("LA PRecision es : %c\n", next->punt);
	
	return (next->width);
}
