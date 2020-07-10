/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:33:28 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/10 05:18:22 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_punt(const char *s, t_list_printf *next)
{
	if (next->flags == 1)
		next->width = ft_convert(s, next);
	if (s[next->len] == '.')
	{
		next->len++;
		return ('.');
	}
	return (0);
}
