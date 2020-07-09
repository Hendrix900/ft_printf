/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:48:56 by carlos            #+#    #+#             */
/*   Updated: 2020/07/09 04:12:38 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main ()
{
    int a = 983215;
    char *c = "EL PEPINO DEL ALBERCHE TIENE SED";
    
    ft_printf("Hola que tal %-60s Aquí seguimos escribiendo %07d\n",c ,a);
    printf("Hola que tal %-60s Aquí seguimos escribiendo %07d\n",c ,a);
	
	ft_printf("El número hexadecimal es : %x\n", a);
	printf("El número hexadecimal es : %x\n", a);
    
    return(0);

}