NAME        = libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

SRC         = ft_printf.c \
              ft_print_chars.c \
              ft_print_nbrs.c \
              ft_print_hex.c \
              ft_print_ptr.c

OBJ         = $(SRC:.c=.o)

BONUS_SRC   = ft_printf_bonus.c \
              ft_print_chars_bonus.c \
              ft_print_nbrs_bonus.c \
              ft_print_hex_bonus.c \
              ft_print_ptr_bonus.c \
              ft_parser_bonus.c

BONUS_OBJ   = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	@make WITH_BONUS=1 all

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
