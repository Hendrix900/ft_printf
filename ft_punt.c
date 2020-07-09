/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:33:28 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/09 05:32:22 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_punt(const char *s, t_list_printf *next)
{
	if (s[next->len] == '.')
	{
		next->len++;
		return ('.');
	}
	return (0);
}
