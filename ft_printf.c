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

 void str_printf(const char *s, t_list_printf *next)
 {

	 while (s[next->len] != '\0')
	{	
		 write(1, &s[next->len], 1);
	 
	 	if (s[next->len] == '%')
	 	{
			break ;
	 	}
	 	next->len++;
	}
 }
  
 int	ft_printf(const char *s, ...)
 {
	t_list_printf	*next;
	
	va_start(next->args ,s);
	next->len = 0;
	str_printf(s,next);

 }

 int main()
 {

	ft_printf("d4234");
		 
 }