/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:11:44 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/08 19:18:01 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type (const char *s, t_list_printf *next)
{
	if (s[next->len] == 'd' || s[next->len] == 'i')
	{
		next->i = va_arg(next->args, int);
		return ('d');
	}
	else //COntinuar añadiendo tipos, este es un ejemplo de prueba sólo.
	{
			return ('q');
	}
	
}
