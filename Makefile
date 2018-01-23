NAME = ft_printf

CC = clang

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

LFLAGS = -Llibft -lft

DIR = srcs

LIB = libft/libft.a

SRCS = main.c			ft_printf.c	ft_putbuf.c	ft_vfprintf.c	ft_flags.c	\
	   ft_fwidth.c		ft_precis.c	ft_length.c	ft_ltoa.c		ft_ident.c	\
	   ft_putwchar.c

SRC = $(addprefix $(DIR)/,$(SRCS))

OBJ = $(SRCS:.c=.o)

HEADERS = includes -I libft/includes

all: $(NAME)
	@true

$(LIB):
	@make -s -C libft

$(NAME): $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LFLAGS) -I $(HEADERS)
	@printf "\r$$(tput setaf 2)$@$$(tput sgr0)\n"

%.o: $(DIR)/%.c Makefile
	@printf "$$(tput setaf 8)$<"
	@$(CC) -c $< -I $(HEADERS) $(CFLAGS) && \
	printf "$$(tput setaf 2)$<$$(tput sgr0)\r$$(tput el)"

clean:
	@rm -rf $(OBJ)
	@make -s -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -s -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re
