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