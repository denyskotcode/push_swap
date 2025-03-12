# Compiler and Flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Executable Names
PROJECT_NAME = push_swap

# Directories
SRCDIR = src
OBJDIR = obj

LIBFTDIR = libs/libft
FTPRINTF_DIR = libs/libftprintf

# Source Files
PROJECT_SRC = push_swap.c parsing.c check_duplicates.c init_stack.c swap_operations.c push_operations.c rotate_operations.c reverse_rotate_operations.c small_sorting.c big_sorting.c moves.c lst_functions.c

# Object Files
PROJECT_OBJ = $(PROJECT_SRC:%.c=$(OBJDIR)/%.o)

# Libraries
LIBFT = $(LIBFTDIR)/libft.a
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

# Rules for Building
all: $(PROJECT_NAME)

$(PROJECT_NAME): $(PROJECT_OBJ) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) $(PROJECT_OBJ) -L$(LIBFTDIR) -lft -L$(FTPRINTF_DIR) -lftprintf -o $(PROJECT_NAME)


# Rule for Compiling Source Files to Object Files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(FTPRINTF_DIR) -c $< -o $@

# Ensure Object Directory Exists
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Build Libraries
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTF_DIR)

# Clean Up
clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -f $(PROJECT_NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(FTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
