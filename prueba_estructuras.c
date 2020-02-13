/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_estructuras.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:03:24 by ccastill          #+#    #+#             */
/*   Updated: 2020/02/12 20:03:24 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

struct alumno
{
	int nota;
	char *nombre;
	int edad;
};

int main ()
{
	struct alumno a1;
	a1.nota = 5;
	a1.nombre = "Paco";
	a1.edad = 15;
	printf("El nombre del alumno es : %s\nSu edad es : %d\nSu nota es : %d\n\n", a1.nombre, a1.edad, a1.nota);

	struct alumno a2;
	a2.nota = 8;
	a2.nombre = "Carlos";
	a2.edad = 18;
	printf("El nombre del alumno es : %s\nSu edad es : %d\nSu nota es : %d\n", a2.nombre, a2.edad, a2.nota);

	return 0;
}