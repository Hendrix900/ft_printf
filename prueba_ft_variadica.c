/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_ft_variadica.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 03:34:43 by ccastill          #+#    #+#             */
/*   Updated: 2020/02/12 03:34:43 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	ft_variadica(int n, ...)
{
	va_list	parametro;
	va_start(parametro, n);


}

void	ft_variadica(int n, ...);

int main (void)
{
	int x;
	x = suma(5, 8, 9, 10);
	
	printf("La suma es %d\n", x);

	return 0;
}


