/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 07:29:05 by ccastill          #+#    #+#             */
/*   Updated: 2020/07/09 05:31:53 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_memory_len(long int n)
{
    long int nb;
    int l;

    nb = n;
    l = 0;
    if (n == 0)
        l++;
    while (n != 0)
    {
        n = n / 16;
        l++;
    }
    return (l);
}

char *ft_convert_hexa_lower(long int n)
{
    char *s;
    int l;
    long int rest;

    l = ft_memory_len(n) + 2;
    s = malloc(sizeof(char) * l);
    s[0] = '0';
    s[1] = 'x';
    s[l--] = '\0';
    if (n == 0)
        s[l--] = 48;
    while (n != 0)
    {
        rest = n % 16;
        if (rest < 10)
            s[l--] = (char)(48 + rest);
        else if (rest >= 10)
            s[l--] = (char)(87 + rest);
        n = n / 16;
    }
    return (s);
}

int main()
{
    //int b;
    //b = 897458;
    char *s;

    int a = 10;
    int *b = &a;

    s = ft_convert_hexa_lower(b);

    printf("El número hexadecimal es : %s\n", s);
    printf("El número hexadecimal es : %p\n", b);
}
