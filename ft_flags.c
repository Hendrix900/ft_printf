/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:59:24 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/10 06:32:15 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags(const char *s, t_list_printf *next)
{
	if (s[next->len] == '-')
	{
		next->len++;
		return ('-');
	}
	else if (s[next->len] == '0')
	{
		next->len++;
		return ('0');
	}
	else if (s[next->len] == '*')
	{
		next->len++;
		return ('*');
	}
	else if (s[next->len] >= '1' && s[next->len] <= '9')
			return(1);
	return(0);
}
