/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:41:11 by ccastill          #+#    #+#             */
/*   Updated: 2020/02/11 18:41:11 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	int a;
	float b;
	char c;
	char *d;
	int e;

	
	a = 1321; // Tipo entero
	b = 85.45825; // Tipo decimal
	c = '*'; // Tipo char 
	d = "casa"; // Tipo cadena
	e = 589647; // Tipo entero
    
	/*--------------------------Parámetro(Bonus)--------------------------------------------------------------------------------------------------*/
 		printf("Parametros (Bonus)\n");
		printf("Prueba de parametro: %2$s y %d\n\n", a, d); // El $ modifica el orden de salida de los parámetros, según el primer número indicado.

	/*--------------------------Flags--------------------------------------------------------------------------------------------------*/
		printf("Flags (obligatorios)\n");
	/*++++++++Obligatorios++++++++++*/
	   	printf("%8i\n", a); // Rellena tantos espacios como se indique a la izquierda del valor pasado. 
		printf("%08i\n", a); // Rellena tantos ceros como se indique a la izquierda del valor pasado. 
		printf("|%-5d\n", 1); // Justifica el campo a la izquierda (Por defecto se justifica a la derecha)

	printf("Flags (Bonus)\n");
	/*++++++++Bonus+++++++++*/
		printf("%+i\n", a); // Imprime el signo de un número 
	   	printf("%#f\n", b); // Ni idea



	printf("\n");

	/*--------------------------Width (Obligatorio)--------------------------------------------------------------------------------------------------*/
	 	printf("Width (Obligatorio)\n"); // Tamaño del ancho del campo donde se imprimirá el valor. Existen dos formas de utilizarlo:
		printf("%*f\n", 10, b); // Introduce tantos espacios a la izquierda como se indique en el primer argumento, menos el número de caracteres del valor que se pase
		printf("%10f\n\n", b); // Introduce tantos espacios a la izquierda como se indique entre el % y el parámetro, menos el número de caracteres del valor que se pase

	/*--------------------------Precision (Obligatorio)--------------------------------------------------------------------------------------------------*/
		printf("Precision (Obligatorio)\n"); // Tamaño de la parte decimal para números reales. Número de caracteres a imprimir para cadenas de texto. Existen dos formas de utilizarlo:
		printf("%.*f\n", 3, b); // Para números flotantes, se indica el total de dígitos impresos después del punto.
		printf("%.3f\n", 1.2348); // Si el número que se pasa en la variable tiene más digitos que el número de caracteres que se quiere mostrar, se rdondeará.
		printf("%.8d\n", a); // Para enteros, si se pide más dígitos que el total del entero, se mostrará con 0 a la izquierda.
		printf("%.0d\n", 0); // Con enteros, si se especifica 0 entonces no se obtendrá ningún dato por salida. 
		printf("%.2s\n\n", d); // Para cadenas de caracteres, el número indicado mostrará la máxima extensión de la cadena.

	/*--------------------------Precision (Bonus)--------------------------------------------------------------------------------------------------*/
		printf("Precision (Bonus)\n");
		printf("Incluir la opción de g y G");


	/*--------------------------Lenght (Bonus)--------------------------------------------------------------------------------------------------*/
		printf("lenght (Bonus)\n");
		printf("Incluir todas las opciones, h, hh, l, ll\n\n");

	/*-------------------------------TIPOS DE DATOS--------------------------------------------------------------------------------------------*/
		printf("Tipo de datos (obligatorios)\n");
	/*++++++++Obligatorios++++++++++*/
		printf("Entero: %i\n", a); // %d e %i son para indicar enteros en base 10 con signo. En printf es indiferente. Difiere en la función scanf.
		printf("Tipo char: %c\n", c); // %c Caracter ASCII correspondiente indicado entre el 0 y el 255 o entre ' '
		printf("Tipo cadena: %s\n", d); // %s Cadena de caracteres (terminada en '\0')
		printf("Tipo Hexadecimal: %x\n", e); // %x o X convierte el número a base 16 (hexadecimal), con letras en minúsculas o mayúsculas respectivamente.
		printf("Tipo Dirección de memoria: %p\n", d); // %p Dirección de memoria (Puntero)
		printf("Entero sin signo: %u\n", e); // %u Entero con base 10 sin signo.
		printf("Imprime el signo: %%\n\n"); // %% Imprime el signo %

	printf("Tipo de datos (Bonus)\n");
	/*++++++++Bonus+++++++++*/
		printf("Número coma flotante con signo, notación científica: %e\n", b); // %e y %E Conversión a coma flotante con signo en notación científica
		printf("Conversión a coma flotante con signo, usando punto decimal: %f\n", b); // %f y %F Conversión a coma flotante con signo, usando punto decimal
		printf("Conversión a coma flotante, usando la notación que requiera menor espacio: %g\n\n", b); // %g y %G Conversión a coma flotante, usando la notación que requiera menor espacio

	return (0);
}