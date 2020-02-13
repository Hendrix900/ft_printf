# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccastill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 17:39:53 by ccastill          #+#    #+#              #
#    Updated: 2020/02/12 17:39:53 by ccastill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FUN_PRINTF = 

OBJS_PRINTF =

FUN_LIBFT =

OBJS_LIBFT =

CFLAGS = -c - I -Wall -Wextra -Werror

all: $(NAME) # Regla principal. Al ejecutar Make se ejecutará.

$(NAME): $(OBJS_PRINTF) $(OBJS_LIBFT) printf.h ./libft/libft.h
	@gcc $(CFLAGS) $(FUN_PRINTF) $(FUN_LIBFT)
	@ar rc $(NAME) $(OBJS_PRINTF) $(OBJS_LIBFT)  
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS_PRINTF) $(OBJS_LIBFT) *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

#------------------------@-----------------------------------------------
# El @ nos permite que aquello que la siga no aparezca por pantalla al compilar.
#------------------------@ar rc -----------------------------------------
# ar es un empaquetador similiar a tar. Que sirve para crear librerías estáticas.
# El significado de las opciones que se le dan a ar es el siguiente:
# s construir un índice del contenido.
# c	crear el paquete si no existe.
# r	reemplazar los ficheros si ya existían en el paquete.
# t	lista el contenido de un paquete (o librería).
# x	extrae un fichero de un paquete (o librería).
#------------------------@ranlib-----------------------------------------
# Después de crear o modificar un archivo es necesario indexarlo.
# El compilador usará este índice para acelerar la búsqueda de símbolos dentro de la biblioteca
# El comando para crear o actualizar el índice se llama "ranlib"