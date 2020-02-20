/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 05:50:04 by ccastill          #+#    #+#             */
/*   Updated: 2020/02/19 05:50:04 by ccastill         ###   ########.fr       */
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

int		ft_width(const char *s, int f, t_list_printf *next)
{
	char	*temp;
	size_t	len;

	next->neg = 0;
	if (f == '-' || f == '0' || f == '.' || f == '*')
	next->len++;
	if (f == '-' || f == '0' || f == '.' || f == 1)
	{
		if (s[next->len] >= '0' && s[next->len] <= '9')
		{
			temp = ft_substr(s, next->len,
					(len = ft_strlen_printf(s, next->len)));
			next->width = ft_atoi(temp);
			free(temp);
			temp = NULL;
			next->len += len;
		}
		//else if (f == '*')
		//	ft_axterix(tab); // Indicar que de un salto el len.
	}
	return (next->width);
}