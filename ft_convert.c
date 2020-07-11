/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 04:30:51 by carlos            #+#    #+#             */
/*   Updated: 2020/07/11 23:26:31 by ccastill         ###   ########.fr       */
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
	
	if (s[next->len] >= '0' && s[next->len] <= '9')
	{
		new = ft_substr(s, next->len, (ft_strlen_str(s, next->len)));
		next->len += ft_strlen_str(s, next->len);
		n = ft_atoi(new);
		//printf("lo gordo es %d", n);
		free(new);
		new = NULL;
		return (n);
	}
	else if (!((s[next->len] == '0' && s[next->len] <= '9')))
		return (0);
	else
		return(next->width);
	
}