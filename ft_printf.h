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
	int				br; // Conocer cuantas posiciones hay antes del %??? no lo se
	int				flags; // Servirá para comprobar los flags
	int				width; // Servirá para comprobar el ancho
	int				precision; // Servira para comprobar la precisión
	int				type; // Servirá para comprobar los tipos.
	int 			neg; // variable para números negativos

	va_list			args;

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
 int				ft_width(const char *s, int f, t_list_printf *next);
 void				ft_zeros(int n, t_list_printf *next);
 void				ft_spaces(int n, t_list_printf *next);



#endif