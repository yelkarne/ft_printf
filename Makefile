NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes

SRCS		=	$(SRC_DIR)/ft_printf.c \
				$(SRC_DIR)/ft_printf_utils.c \
				$(SRC_DIR)/ft_printf_convert.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ---- Bonus sources (only compiled with "make bonus") ----
BONUS_SRCS	=	$(SRC_DIR)/ft_printf_bonus.c

BONUS_OBJS	= $(BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ---- Libft (optional, remove this block if you don't use libft) ----
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(NAME) created."

bonus: CFLAGS += -DBONUS=1
bonus: $(LIBFT) $(OBJS) $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(NAME) (with bonus) created."

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
