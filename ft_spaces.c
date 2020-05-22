/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 08:40:29 by ccastill          #+#    #+#             */
/*   Updated: 2020/05/22 14:04:41 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spaces(int n, t_list_printf *next)
{
	while (n > 0)
	{
		ft_putchar_fd(' ', 1);
		n--;
	}
}
