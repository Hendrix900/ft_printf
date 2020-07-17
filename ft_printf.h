/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:55:45 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/17 23:15:34 by ccastill         ###   ########.fr       */
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
	int				br; // Conocer cuantas posiciones se han contado para devolver el valor.
	int				flags; // Contendrá un ('0') o (1) o ('-') En caso de haberlo
	int				punt; // Contendrá un ('.') En caso de haberlo
	int				width; // Servirá para comprobar el ancho
	int				precision; // Servira para comprobar la precisión
	int				type; // Servirá para comprobar los tipos.
	int 			neg; // variable para números negativos
	int				ar_neg;
	int				memory;
	int				len; // Posición de la cadena
	int				i; // %i o %d
	int				c; // %c Caracteres ASCII
	char			*str; // %s Cadena de caracteres
	long int		hexa; // %xX hexadecimal
	long int		p; // %p puntero (Dirección de memoria)
	unsigned int	u; // %u Entero sin sígno.

}					t_list_printf;

 int				ft_printf(const char *s, ...);
 int				ft_flags(const char *s, t_list_printf *next);
 int				ft_width(const char *s, t_list_printf *next);
 void				ft_zeros(int n, t_list_printf  *next);
 void				ft_spaces(int n, t_list_printf  *next);
 int				ft_punt(const char *s, t_list_printf *next);
 int				ft_type(const char *s, t_list_printf *next);
 void				ft_show_d(t_list_printf *next);
 void				ft_putspace(char *new, t_list_printf *next);
 void 				ft_putzero(char *new, t_list_printf *next);
 void				ft_putspace_zero(char *new, t_list_printf *next);
 void				ft_show_c(const char *s, t_list_printf *next);
 void				ft_show_type(const char *s, t_list_printf *next);
 void				ft_show_str(const char *s, t_list_printf *next);
 void				ft_show_hexa(const char *s, t_list_printf *next);
 void				ft_show_memory(const char *s , t_list_printf *next);
 void				ft_show_u(t_list_printf *next);
 char				*ft_tomemory(long int nb);
 char				*ft_tohexa(unsigned int nb, char x);
 void				ft_putstr_fd(char *s, int fd, t_list_printf  *next);
 int				ft_convert(const char *s, t_list_printf *next);
 char				*ft_itou(unsigned long int n);
 void				ft_putchar_fd(char c, int fd, t_list_printf *next);
 int				ft_precision(const char *s, t_list_printf *next);
 void				ft_putspace_memory(char *new, t_list_printf *next);

#endif
