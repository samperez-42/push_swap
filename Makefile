# Compiler to use
CC = cc

# Compiler flags
CFLAGS = -Werror -Wall -Wextra

# Source and object directories
SRCS_FOLDER = srcs
OBJ_FOLDER = objs

# Source files
SRC = 	$(SRCS_FOLDER)/main.c \
		$(SRCS_FOLDER)/error_checking.c \
		$(SRCS_FOLDER)/push_swap_split.c \
		$(SRCS_FOLDER)/push.c \
		$(SRCS_FOLDER)/reverse_rotate.c \
		$(SRCS_FOLDER)/rotate.c \
		$(SRCS_FOLDER)/stack_utils.c \
		$(SRCS_FOLDER)/swap.c

# Object files
OBJ = $(SRC:$(SRCS_FOLDER)/%.c=$(OBJ_FOLDER)/%.o)

# Output executable name
NAME = push_swap

# Header file
LIB = push_swap.h

# Default target
all: $(NAME)

# Rule to create the executable
# We redirect the output with > /dev/null 2>&1 to silence any messages
$(NAME): $(OBJ)
	@make -C includes/libft_push_swap > /dev/null 2>&1
	@make -C includes/ft_printf > /dev/null 2>&1
	@ar rcs $(NAME) $(OBJ)

# Rule to compile .c files to .o files
$(OBJ_FOLDER)/%.o: $(SRCS_FOLDER)/%.c
	@mkdir -p $(OBJ_FOLDER)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_FOLDER) > /dev/null 2>&1 || true
	@make clean -C includes/libft_push_swap > /dev/null 2>&1
	@make clean -C includes/ft_printf > /dev/null 2>&1

# Clean up object files and the executable
override fclean: clean
	@rm -f $(NAME)
	@make fclean -C includes/libft_push_swap > /dev/null 2>&1
	@make fclean -C includes/ft_printf > /dev/null 2>&1

# Rebuild everything
override re: fclean all