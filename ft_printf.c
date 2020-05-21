/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 01:09:36 by ccastill          #+#    #+#             */
/*   Updated: 2020/05/21 20:44:11 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_str(const char *s, t_list_printf *next)
{
	next->flags = 0;
	next->width = 0;
	next->punt = 0;
	next->flags = ft_flags(s, next);
	next->punt = ft_punt(s, next);
	next->width = ft_width(s, next);

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
				err = check_str(s, next);
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
	free(next);
	next = NULL;
	return (0);
 }
