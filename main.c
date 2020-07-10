/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:48:56 by carlos            #+#    #+#             */
/*   Updated: 2020/07/10 16:59:38 by carlos           ###   ########.fr       */
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

    ft_printf ("%-8.5i\n", 34);
    printf ("%-8.5i\n", 34);

    return(0);

}