CC = cc
CFLAGS = -Wall -Wextra -Werror 

NAME = push_swap 

ARC = ./libft/libft.a

SRCS = parse_utils.c parse.c run_cost.c utils.c directions.c pre_sorting.c main.c \
	   instructions_combo.c instructions_push.c instructions_rotate.c instructions_swap.c

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
