/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_typdefstruct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:30:08 by ccastill          #+#    #+#             */
/*   Updated: 2020/02/12 20:30:08 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*typdef te permite cambair el nombre para que sea más facil de manipular.
En el ejemplo de abajo podemos ver como la estructura typdef struct s_contacto
se transforma en t_contacto*/

typedef struct s_contacto	
{
	char *nombre;
	char *dir;
	int edad;
	int telefono;
}t_contacto;

int main ()
{

t_contacto c1;
c1.dir = "Calle Sebastían izquerdo";
c1.nombre = "Juan";
c1.telefono = 67985462;

printf("%s, %s, %d\n", c1.dir, c1.nombre, c1.telefono);
return 0;
}