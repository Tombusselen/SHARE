NAME = push_swap
CC = cc
CFLAGS = -Werror -Wall -Wextra -g

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SRC = brain.c chained.c int_check.c swap.c rotate.c r_rotate.c push.c \
	index.c sort.c radix.c node_outils.c sort_outils.c test_outils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) -o  $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
