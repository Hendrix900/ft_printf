# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccastill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 06:55:26 by ccastill          #+#    #+#              #
#    Updated: 2020/02/19 06:55:26 by ccastill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FUN_PRINTF = ft_printf.c ft_flags.c ft_width.c ft_spaces.c ft_zeros.c

OBJS_PRINTF = ft_printf.o ft_flags.o ft_width.o ft_spaces.o ft_zeros.o

FUN_LIBFT = ./libft/ft_atoi.c ./libft/ft_substr.c ./libft/ft_strlen.c ./libft/ft_putchar_fd.c \
			

OBJS_LIBFT = ./libft/ft_atoi.o ./libft/ft_substr.o ./libft/ft_strlen.o ./libft/ft_putchar_fd.o \
		

CFLAGS = -c -I -Wall -Wextra -Werror

all: $(NAME) # Regla principal. Al ejecutar Make se ejecutará.

$(NAME): $(OBJS_PRINTF) $(OBJS_LIBFT) ft_printf.h ./libft/libft.h
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