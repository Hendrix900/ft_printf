/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:11:44 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/10 03:18:44 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(const char *s, t_list_printf *next)
{
	if (s[next->len] == 'd' || s[next->len] == 'i')
		return ('d');
	else if (s[next->len] == 'c')
		return ('c');
	else if (s[next->len] == '%')
		return ('%');
	else if (s[next->len] == 's')
		return ('s');
	else if (s[next->len] == 'x' || s[next->len] == 'X')
		return ('x');
	//	else if (s[next->len] == 'c')
	return (0);
}
