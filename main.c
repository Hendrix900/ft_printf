/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:48:56 by carlos            #+#    #+#             */
/*   Updated: 2020/07/09 01:41:35 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main ()
{
    int a = 9875;
    
    ft_printf("Hola que tal %*.15d Aquí seguimos escribiendo %7d\n",22, a, a);
    printf("Hola que tal %*.15d Aquí seguimos escribiendo %7d\n",22 , a, a);
    return(0);

}