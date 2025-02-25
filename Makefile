CC = cc
CFLAGS = -Wall -Wextra -Werror 

NAME = push_swap 

ARC = ./libft/libft.a

SRCS = parse.c instructions.c main.c 

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE)  -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(ARC)
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

bonus: all 

.PHONY: all clean fclean re bonus
