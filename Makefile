# Compiler to use
CC = cc

# Compiler flags
CFLAGS = -Werror -Wall -Wextra

# Source and object directories
SRCS_FOLDER = srcs
OBJ_FOLDER = objs

# Source files
SRC = $(SRCS_FOLDER)/main.c $(SRCS_FOLDER)/operations.c $(SRCS_FOLDER)/error_checking.c

# Object files
OBJ = $(SRC:$(SRCS_FOLDER)/%.c=$(OBJ_FOLDER)/%.o)

# Output executable name
NAME = push_swap

# Header file
LIB = push_swap.h

# Default target
all: $(NAME)

# Rule to create the executable
$(NAME): $(OBJ)
	make -C includes/libft_push_swap/Makefile
	make -C includes/ft_printf/Makefile
	ar rcs $(NAME) $(OBJ)


# Rule to compile .c files to .o files
$(OBJ_FOLDER)/%.o: $(SRCS_FOLDER)/%.c
	@mkdir -p $(OBJ_FOLDER)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_FOLDER)

# Clean up object files and the executable
override fclean: clean
	@rm -f $(NAME)

# Rebuild everything
override re: fclean all