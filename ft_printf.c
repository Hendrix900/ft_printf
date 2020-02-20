/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 01:09:36 by ccastill          #+#    #+#             */
/*   Updated: 2020/02/12 01:09:36 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flags(const char *s, t_list_printf *next)
{
	next->flags = 0;
	next->width = 0;
	next->precision = 0;
	next->type = 0;
	next->flags = ft_flags(s, next);
	printf("El flag es: %d\n", next->flags);
	next->width = ft_width(s, next->flags, next);
	printf("El ancho es: %d\n", next->width);

	
	//next->widht = ft_width(s, next);
	return (0);
}
  
 void str_printf(const char *s, t_list_printf *next)
 {
	 int	err;

	 while (s[next->len] != '\0')
	{	
	  	if (s[next->len] != '%')
		{	
		  	write(1, &s[next->len], 1);
		}
		else 
		{
			next->len++;
			while (s[next->len] == ' ')
				next->len++;
			if (s[next->len] == '\0')
				break;
			else
				err = check_flags(s, next);
			if (err == -1)
				break;
		}
	next->len++;
	}
 }
  
 int	ft_printf(const char *s, ...)
 {
	t_list_printf	*next;

	if (!(next = malloc(sizeof(t_list_printf))))
		return (0);
	va_start(next->args ,s);
	next->len = 0;
	str_printf(s,next);
	va_end(next->args);
	return (0);
 }

int main()
{
	int a;
	a = 58465;

	ft_printf("%-98\n", 5, a);
	//printf("Hola %-05i  cojo %.18i\n", a, 0);
}

