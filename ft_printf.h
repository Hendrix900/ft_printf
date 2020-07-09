/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:55:45 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/09 23:50:31 by carlos           ###   ########.fr       */
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
	int				br; // Conocer cuantas posiciones hay antes del %??? no lo se
	int				flags; // Contendrá un ('0') o (1) o ('-') En caso de haberlo
	int				punt; // Contendrá un ('.') En caso de haberlo
	int				width; // Servirá para comprobar el ancho
	int				precision; // Servira para comprobar la precisión
	int				type; // Servirá para comprobar los tipos.
	int 			neg; // variable para números negativos
	int				len; // Posición de la cadena
	int				i; // %i o %d
	int				c; // %c Caracteres ASCII
	char			*str; // %s Cadena de caracteres
	int				hexa; // %xX hexadecimal
	int				p; // %p puntero (Dirección de memoria)
	unsigned int	u; // %u Entero sin sígno.

}					t_list_printf;

 int				ft_printf(const char *s, ...);
 int				ft_flags(const char *s, t_list_printf *next);
 int				ft_width(const char *s, t_list_printf *next);
 void				ft_zeros(int n);
 void				ft_spaces(int n);
 int				ft_punt(const char *s, t_list_printf *next);
 int				ft_type(const char *s, t_list_printf *next);
 void				ft_show_d(t_list_printf *next);
 void				ft_putspace(char *new, t_list_printf *next);
 void 				ft_putzero(char *new, t_list_printf *next);
 void				ft_putspace_zero(char *new, t_list_printf *next);
 void				ft_show_c(t_list_printf *next);
 void				ft_show_type(const char *s, t_list_printf *next);
 void				ft_show_str(t_list_printf *next);
 void				ft_show_hexa(const char *s, t_list_printf *next);
 char				*ft_tohexa(unsigned int nb, char x);
 void				ft_putstr_fd(char *s, int fd, t_list_printf  *next);








#endif
