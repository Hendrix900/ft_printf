
NAME = libft.a

FUN = ft_atoi.c ft_itoa.c ft_strjoin.c ft_strlen.c ft_substr.c \

OBJS = ft_atoi.o ft_itoa.o ft_strjoin.o ft_strlen.o ft_substr.o \

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) libft.h
	@gcc -c -I $(CFLAGS) $(FUN)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus: $(OBJS_BONUS) libft.h
	@gcc -c -I $(CFLAGS) $(FUN_BONUS)
	@ar rc $(NAME) $(OBJS_BONUS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all