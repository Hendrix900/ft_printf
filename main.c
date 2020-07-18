/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:48:56 by carlos            #+#    #+#             */
/*   Updated: 2020/07/18 06:42:13 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

 int    ft_printf(const char *s, ...);

int main ()
{
 
 int f, g;

 unsigned long int a = 4509102520;   
/*
    ft_printf("%05u\n", 43);
	printf("%05u\n", 43);

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


    char *s;
	char *memory;

	int a=0; //Declaración de variable entera de tipo entero
	int *puntero; //Declaración de variable puntero de tipo entero
	puntero = &a; //Asignación de la dirección memoria de a

    int z = -5841474;

    
    ft_printf("El número int es %d  y el %u\n", z, z);
    printf("El número int es %d  y el %u\n", z, z);

    ft_printf("%.d\n", 0);
    printf("%.d\n", 0);

    ft_printf("this %i number\n", 0);
    printf("this %i number", 0);



    ft_printf("%-3d\n", 0);
    printf("%-3d\n", 0);
*/

    f = ft_printf("%.p\n", NULL);
    g = printf("%.p\n", NULL);

    printf("%d\n", f);
    printf("%d\n", g);

    f = ft_printf("%5.p\n", NULL); //PASA
    g = printf("%5.p\n", NULL);

    printf("%d\n", f);
    printf("%d\n", g);
    
    f = ft_printf("%2.p\n", NULL); //PASA
    g = printf("%2.p\n", NULL);

    printf("%d\n", f);
    printf("%d\n", g);


    f = ft_printf("%.5p\n", 0);
    g = printf("%.5p\n", 0);

    printf("%d\n", f);
    printf("%d\n", g);
    
    f = ft_printf("%.0p", 0);
    g = printf("%.0p", 0);

    printf("%d\n", f);
    printf("%d\n", g);

/*
    f = ft_printf("%-*.*s", 7, 3, "yolo");
    g = printf("%-*.*s", 7, 3, "yolo");
    
    printf("%d\n", f);
    printf("%d\n", g);
*/
    return(0);
}