/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 02:19:04 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/20 10:16:17 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_memoryzero(char *new, t_list_printf *next, char *j)
{
	size_t	width;
	size_t	variable;
	int		total;

	width = next->width;
	variable = ft_strlen(new) + 2;
	if (variable >= width)
		ft_putstr_fd((j = ft_strjoin("0x", new)), 1, next);
	else if (variable < width)
	{
		total = width - variable;
		next->flags != '0' ? ft_putstr_fd((j = ft_strjoin("0x", new)), 1, next)
		: ft_putstr_fd("0x", 1, next);
		ft_zeros(total, next);
		next->flags != '0' ? ft_putstr_fd((j = ft_strjoin("0x", new)), 1, next)
		: ft_putstr_fd(new, 1, next);
	}
	free(j);
	j = NULL;
}

void	ft_memorypunt_ad(int total, t_list_printf *next)
{
	ft_putstr_fd("0x", 1, next);
	ft_zeros(total, next);
}

void	ft_memorypunt(char *new, size_t p, t_list_printf *next, char *j)
{
	size_t	variable;
	int		total;

	variable = ft_strlen(new);
	if (new[0] == '0')
		total = p;
	else
		total = p - variable;
	if (new[0] == '0')
		ft_memorypunt_ad(total, next);
	else
	{
		if (variable >= p)
			ft_putstr_fd((j = ft_strjoin("0x", new)), 1, next);
		else if (variable < p)
		{
			//total = p - variable;
			next->punt == '.' ? ft_putstr_fd((j = ft_strjoin("0x", new))
			, 1, next) : ft_putstr_fd("0x", 1, next);
			ft_zeros(total, next);
			next->punt == '.' ? ft_putstr_fd((j = ft_strjoin("0x", new))
			, 1, next) : ft_putstr_fd(new, 1, next);
		}
		free(j);
		j = NULL;
	}
}

void	ft_memoryspace(char *new, t_list_printf *next, char *j)
{
	size_t	width;
	size_t	variable;
	int		total;

	width = next->width;
	variable = ft_strlen(new) + 2;
	if (variable >= width)
		ft_putstr_fd((j = ft_strjoin("0x", new)), 1, next);
	else if (variable < width)
	{
		total = width - variable;
		if (next->flags == '-')
			ft_putstr_fd((j = ft_strjoin("0x", new)), 1, next);
		ft_spaces(total, next);
		if (next->flags != '-')
			ft_putstr_fd((j = ft_strjoin("0x", new)), 1, next);
	}
	free(j);
	j = NULL;
}

void	ft_show_memory(t_list_printf *next)
{
	char	*new;
	char	*j;
	size_t	precision;

	precision = next->precision;
	new = ft_tomemory(next->p);
	if (next->flags >= 1 && next->punt > 1)
		ft_putspace_memory(new, next);
	else if ((next->flags == 1) || (next->flags == '-') || (next->flags == '*'))
		ft_memoryspace(new, next, j);
	else if (next->punt == '.')
		ft_memorypunt(new, precision, next, j);
	else if (next->flags == '0')
		ft_memoryzero(new, next, j);
	else
	{
		ft_putstr_fd((j = ft_strjoin("0x", new)), 1, next);
		free(j);
		j = NULL;
	}
	free(new);
	new = NULL;
}
