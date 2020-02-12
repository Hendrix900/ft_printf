NAME = libftprintf.a

FUN = 

OBJS = 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) libft.h
	@gcc -c -I $(CFLAGS) $(FUN)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS) *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all