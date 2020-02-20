/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asaco.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 05:58:42 by ccastill          #+#    #+#             */
/*   Updated: 2020/02/20 05:58:42 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	int a;
	char *b = "HOLA";
	a = 123;

//---------------------------Espacios----------------------
	printf("Espacios\n"); 

	printf("%3d\n", a); 
	printf("% 3d\n", a); // Puede haber UN espacio antes de los flags.
	printf("%12d\n", a);
	printf("%120d\n", a);

//--------------------------Zeros------------------------
	printf("Zeros\n"); 

	printf("%04d\n", a); 
	printf("% 05d\n", a); // 
	printf("%012d\n", a);
	printf("%0120d\n", a);

//--------------------------Minus------------------------
	printf("Minus\n"); 

	printf("%-5d", a); // 5 Espacios a la derecha
	printf("%- 5d", a); // 5 espacios a partir del -
	printf("% -5d", a); // Igual que la de arriba.

//--------------------Precision-----------------------------
	printf("Precision\n"); 

	printf("%.3d\n",a); // Es igual AL SIGUEINTE
	printf("%.03d\n", a);  // Es igual AL ANTERIOR
	printf("%.4d\n",a); // Si el número que se da es mayor que la cantidad de digitos de la variable, se añaden zeros a la izq
	printf("%.04d\n", 5, a); // Zeros despues de punto es indiferente.
	printf("%.2s\n", b); //El número indicado será la máxima extensión de la cadena
	printf("%.d\n", 0); // Si se pasa 0 no pasará nada NULL

//---------------------Width-----------------------------
	printf("Width\n"); 

	printf("%*d\n",12, a); 
	printf("% *d\n",12, a); // Puede haber UN espacio antes de los flags.
	
	printf("%*.3d\n",5,a); // Es igual AL SIGUEINTE
	printf("%*.03d\n",5 , a);  // Es igual AL ANTERIOR
	printf("%*.4d\n",5 ,a); // Si el número que se da es mayor que la cantidad de digitos de la variable, se añaden zeros a la izq
	printf("%*.04d\n",5 , a); // Zeros despues de punto es indiferente.
	printf("%*.2s\n",5 , b); //El número indicado será la máxima extensión de la cadena
	printf("%*.d\n",5 , 0); // Si se pasa 0 no pasará nada NULL
 


}