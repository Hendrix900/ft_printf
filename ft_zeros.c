/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeros.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 08:37:17 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/17 12:15:47 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zeros(int n, t_list_printf  *next)
{
	while (n > 0)
	{
		ft_putchar_fd('0', 1, next);
		n--;
	}
}
