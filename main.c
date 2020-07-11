/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:48:56 by carlos            #+#    #+#             */
/*   Updated: 2020/07/11 01:53:05 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

 int    ft_printf(const char *s, ...);

int main ()
{
    int a = 34;
    char *c = "EL PEPINO DEL ALBERCHE TIENE SED";
    int f;
    int g;
    
    //f = ft_printf("Hola que tal %-60s Aquí seguimos escribiendo %07d\n",c ,a);
   // g = printf("Hola que tal %-60s Aquí seguimos escribiendo %07d\n",c ,a);


     
	
	//f = ft_printf("El número hexadecimal es : %x\n", a);
	//g = printf("El número hexadecimal es : %x\n", a);

    //printf("%d\n", f);
    //printf("%d\n", g);

    ft_printf ("%15.7d\n", 3267);
    printf ("%15.7d\n", 3267);

    ft_printf ("%10.5d\n", 216);
    printf ("%10.5d\n", 216);
    
    ft_printf ("%.6d\n", -3);
    printf ("%.6d\n", -3);

    ft_printf ("%8.3d\n", -8473);
    printf ("%8.3d\n", -8473);

    ft_printf ("%10.5d\n", -216);
    printf ("%10.5d\n", -216);
  
    ft_printf ("%-10.5d casa\n", -216);
    printf ("%-10.5d casa\n", -216);

    ft_printf ("%0-8.3d casa\n", -8473);
    printf ("%0-8.3d casa\n", -8473);


    ft_printf ("%05d\n",43);
    printf ("%05d\n",43);

    ft_printf ("%03d\n", 634);
    printf ("%03d\n", 634);

    ft_printf ("%04d\n", -4825);
    printf ("%04d\n", -4825);

    ft_printf ("%03.7d\n", -2375);
    printf ("%03.7d\n", -2375);

    ft_printf ("%.d\n", 0);
    printf ("%.d\n", 0);
  
    return(0);
}