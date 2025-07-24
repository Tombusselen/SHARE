NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRC = ft_atoi.c     ft_isprint.c  ft_putchar_fd.c  ft_striteri.c  ft_strnstr.c \
	ft_bzero.c    ft_itoa.c     ft_putendl_fd.c  ft_strjoin.c   ft_strrchr.c \
	ft_calloc.c   ft_memchr.c   ft_putnbr_fd.c   ft_strlcat.c   ft_strtrim.c \
	ft_isalnum.c  ft_memcmp.c   ft_putstr_fd.c   ft_strlcpy.c   ft_substr.c \
	ft_isalpha.c  ft_memcpy.c   ft_split.c	     ft_strlen.c    ft_tolower.c \
	ft_isascii.c  ft_memmove.c  ft_strchr.c      ft_strmapi.c   ft_toupper.c \
	ft_isdigit.c  ft_memset.c   ft_strdup.c      ft_strncmp.c	ft_printf/ft_printf.c \
	ft_printf/outils/ft_putchar.c	ft_printf/outils/ft_puthexlow.c	ft_printf/outils/ft_puthexup.c	ft_printf/outils/ft_putnbr.c \
      	ft_printf/outils/ft_putunsign.c	ft_printf/outils/ft_putptr.c	ft_printf/outils/ft_puthexptr.c	 ft_printf/outils/ft_putstr.c \
      	ft_printf/outils/ft_type.c	GNL/get_next_line.c		GNL/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
