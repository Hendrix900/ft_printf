/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_listas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 23:03:00 by ccastill          #+#    #+#             */
/*   Updated: 2020/02/12 23:03:00 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct Libro
{
	int i;
	char c;
	struct Libro *next;

} Libro;

void aff_list(Libro *begin)
{
	while (begin != NULL)
	{
		printf("%d\n", begin->i);
		begin = begin->next;
	}

}

int main ()
{
	Libro elem1;
	Libro elem2;
	Libro elem3;
	Libro *begin;

	begin = &elem1;
	elem1.i = 1;
	elem1.next = &elem2;
	elem2.i = 2;
	elem2.next = &elem3;
	elem3.i = 3;
	elem3.next = NULL;

	aff_list(begin);

	return (0);
}