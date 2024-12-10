CC = cc
CFLAGS = -Werror -Wall -Wextra

SRC = srcs/error_checking.c srcs/main.c srcs/push.c srcs/reverse_rotate.c srcs/rotate.c srcs/stack_utils.c srcs/swap.c srcs/split.c

OBJ = $(SRC:%.c=%.o)

NAME = push_swap
LIBFT_DIR = includes/libft_push_swap
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all