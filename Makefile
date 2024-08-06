NAME = push_swap

SRCS = 	init_pile.c instructions.c sort.c sort_small.c sort_radix.c utile.c utile2.c utile_pile.c utile_radix1.c utile_radix2.c push_swap.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 
	
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 