/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:55:45 by ccastill          #+#    #+#             */
/*   Updated: 2020/02/12 21:55:45 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h" 

typedef struct		s_list_printf
{
	va_list			args;
	int				len;
	int				i;
	int				c;
	char			*str;
	int				hexa;
	int				p;
	unsigned int	u;
}					t_list_printf;


 int	ft_printf(const char *s, ...);

#endif