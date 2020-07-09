/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:07:12 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/09 06:49:12 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, t_list_printf  *next)
{
	int l;

	l = 0;
	if (s != 0)
		while (s[l])
		{
			ft_putchar_fd(s[l], fd);
			l++;
			next->br++;
		}
}
