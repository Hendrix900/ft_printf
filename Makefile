# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccastill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 06:55:26 by ccastill          #+#    #+#              #
#    Updated: 2020/07/15 20:14:56 by ccastill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FUN_PRINTF = ft_printf.c ft_flags.c ft_width.c ft_spaces.c ft_zeros.c ft_punt.c ft_type.c ft_show_d.c ft_putspace.c ft_putzero.c \
			 ft_putspace_zero.c ft_show_c.c ft_show_type.c ft_show_str.c ft_tohexa.c ft_show_hexa.c ft_show_memory.c ft_tomemory.c main.c \
			 ft_putstr_fd.c ft_convert.c ft_show_u.c ft_itou.c ft_putchar_fd.c \

OBJS_PRINTF = ft_printf.o ft_flags.o ft_width.o ft_spaces.o ft_zeros.o ft_punt.o ft_type.o ft_show_d.o ft_putspace.o ft_putzero.o \
			  ft_putspace_zero.o ft_show_c.o ft_show_type.o ft_show_str.o ft_tohexa.o ft_show_hexa.o ft_show_memory.o ft_tomemory.o main.o \
			  ft_putstr_fd.o ft_convert.o ft_show_u.o ft_itou.o ft_putchar_fd.o\

FUN_LIBFT = ./libft/ft_atoi.c ./libft/ft_itoa.c ./libft/ft_substr.c ./libft/ft_strlen.c  \
			
OBJS_LIBFT = ./libft/ft_atoi.o ./libft/ft_itoa.o ./libft/ft_substr.o ./libft/ft_strlen.o  \
		
CFLAGS = -c #-I -Wall -Wextra -Werror -g # Quitar la -g

all: $(NAME) 
$(NAME): $(OBJS_PRINTF) $(OBJS_LIBFT) ft_printf.h ./libft/libft.h
	@gcc $(CFLAGS) $(FUN_PRINTF) $(FUN_LIBFT)
	@ar rc $(NAME) $(OBJS_PRINTF) $(OBJS_LIBFT)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS_PRINTF) $(OBJS_LIBFT) *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
