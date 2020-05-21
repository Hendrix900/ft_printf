/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_simplificado.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:52:20 by carlos            #+#    #+#             */
/*   Updated: 2020/05/13 01:05:37 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Programa para convertir un entero en base decimal a una cadena en base decimal, simplificación del itoa para examen*/

#include <stdio.h>
#include <stdlib.h>

char *ft_tohexa_replica(long int nb)
{
    long int     nbr;
    long int     count;
    char    *new;
    char    *deca;
    int     negative;

    negative = 0;
    count = 0;
    deca = "0123456789";
    if (nb < 0)
    {
        nb = nb * -1;
        negative = 1;
        count++;
    }
    nbr = nb;
    while ( nb != 0)
    {
        count++;
        nb = nb / 10;
    }
    if (nbr == 0)
        count++;
    new = (char *)malloc(sizeof(char) * (count + 1));
    new[count] = '\0'; 
    while (nbr != 0 || count > 0)
    {
        new[--count] = deca[nbr % 10];
        nbr = nbr / 10;
    }
    if (negative == 1)
        new[0] = '-';
   return (new);
}

int main()
{
    int a;
    a = 2147483649;
    
    char *str = ft_tohexa_replica(a);
    
    printf("El número en hexadecimal es: %d\n", a);
    printf("MI número en hexadecimal es: %s\n", str);
    
    
}