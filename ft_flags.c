/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:59:24 by ccastill          #+#    #+#             */
/*   Updated: 2020/02/18 11:59:24 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_printf(const char *s, int l)
{
	size_t q;

	q = 0;
	while (s[l] >= '0' && s[l] <= '9')
	{
		q++;
		l++;
	}
	return (q);
}

int		ft_flags(const char *s, t_list_printf *next)
{
	char *temp;
	size_t	q;

	if (s[next->len] >= '1' && s[next->len] <= '9')
	{
		
		temp = ft_substr(s, next->len,
				(q = ft_strlen_printf(s, next->len)));
			next->widht = ft_atoi(temp);
			free(temp);
			temp = NULL;
			ft_spaces(next->widht -q, next);
			return (1);
	}
	else if (s[next->len] == '0')
	{

			next->len++;
	 		temp = ft_substr(s, next->len,
				(q = ft_strlen_printf(s, next->len)));
			next->widht = ft_atoi(temp);
			free(temp);
			temp = NULL;
			ft_zeros(next->widht - q, next);
			return (1);
	}
	else if (s[next->len] == '-')
		return ('-');
	else
		return ('0');
}
