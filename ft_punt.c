/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:33:28 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/16 04:54:44 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_punt(const char *s, t_list_printf *next)
{
	/*if (next->flags == 1 || next->flags == '-' || next->flags == '0') 
		next->width = ft_convert(s, next);*/
	if (s[next->len] == '.')
	{
		//printf("LA posición es : %c\n", s[next->len]);
		next->len++;

		return ('.');
	}
	return (0);
}
