/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 04:30:51 by carlos            #+#    #+#             */
/*   Updated: 2020/07/10 04:39:57 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_strlen_str(const char *s, int l)
{
	size_t count;

	count = 0;
	while (s[l] >= '0' && s[l] <= '9')
	{
		count++;
		l++;
	}
	return (count);
}

int	ft_convert(const char *s, t_list_printf *next)
{
	char	*new;
	int		n;
	
	new = ft_substr(s, next->len, (ft_strlen_str(s, next->len)));
	next->len += ft_strlen_str(s, next->len);
	n = ft_atoi(new);
	free(new);
	new = NULL;
	return (n);
}