SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Werror -Wall -Wextra -g

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(SERVER) $(CLIENT): $(SERVER_OBJ) $(CLIENT_OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) -L$(LIBFT_DIR) -lft
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) -L$(LIBFT_DIR) -lft

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
