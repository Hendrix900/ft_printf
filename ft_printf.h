/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:55:45 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/19 02:29:55 by ccastill         ###   ########.fr       */
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
	int				br;
	int				flags;
	int				punt;
	int				width;
	int				precision;
	int				type;
	int				neg;
	int				ar_neg;
	int				memory;
	int				len;
	int				i;
	int				c;
	char			*str;
	long int		hexa;
	long int		p;
	unsigned int	u;

}					t_list_printf;

int					ft_printf(const char *s, ...);
int					ft_flags(const char *s, t_list_printf *next);
int					ft_width(const char *s, t_list_printf *next);
void				ft_zeros(int n, t_list_printf *next);
void				ft_spaces(int n, t_list_printf *next);
int					ft_punt(const char *s, t_list_printf *next);
int					ft_type(const char *s, t_list_printf *next);
void				ft_show_d(t_list_printf *next);
void				ft_putspace(char *new, t_list_printf *next);
void				ft_putzero(char *new, t_list_printf *next);
void				ft_putspace_zero(char *new, t_list_printf *next);
void				ft_show_c(t_list_printf *next);
void				ft_show_type(const char *s, t_list_printf *next);
void				ft_show_str(t_list_printf *next);
void				ft_show_hexa(const char *s, t_list_printf *next);
void				ft_show_memory(t_list_printf *next);
void				ft_show_u(t_list_printf *next);
char				*ft_tomemory(long int nb);
char				*ft_tohexa(unsigned int nb, char x);
void				ft_putstr_fd(char *s, int fd, t_list_printf *next);
char				*ft_itou(unsigned long int n);
void				ft_putchar_fd(char c, int fd, t_list_printf *next);
int					ft_precision(const char *s, t_list_printf *next);
void				ft_putspace_memory(char *new, t_list_printf *next);

#endif
