NAME = so_long
CC = cc
CFLAGS = -Werror -Wall -Wextra -g

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = init_map.c img_manager.c gen_map.c check_map.c check_map_helper.c player.c check_path.c exit_free.c so_long.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) -o  $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft $(MLX)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
