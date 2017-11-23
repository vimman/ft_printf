NAME = ft_printf

CC = clang

CFLAGS = -Wall -Werror -Wextra -g3 #-march=native -flto -fsanitize=address  -std=c99

LFLAGS = -Llibft -lft

DIR = srcs

LIB = lib

SRCS = main.c	ft_printf.c	ft_putbuf.c	ft_vfprintf.c	ft_flags.c		\
	   ft_fwidth.c	ft_precis.c	ft_length.c	ft_ltoa.c

SRC = $(addprefix $(DIR)/,$(SRCS))

OBJ = $(SRCS:.c=.o)

HEADERS = includes -I libft/includes

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME) $(ADDS)

$(LIB):
	@make -C libft

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC) -I $(HEADERS)

clean:
	@rm -rf $(OBJ)
	@rm -f *.gch
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
