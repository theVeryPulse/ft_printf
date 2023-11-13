# Makefile

CC = gcc
CFLAGS := -Wall -Wextra -Werror

LIBFT := libft/libft.a
#INC_DIRS := -Ilibft

NAME := libftprintf.a
CFILES := ft_printf.c
OFILES := $(CFILES:.c=.o)

all: $(NAME)

# Compile all codes from libft and libftprintf into libftprintf.a
$(NAME): $(LIBFT) $(OFILES)
	ar rcs $@ $(OFILES) libft/*.o

# Build all object files of libft as well as libft.a
$(LIBFT):
	$(MAKE) -C libft

# Build object files of all required source codes
$(OFILES): $(CFILES)
	#$(CC) $(CFLAGS) $(INC_DIRS) -c -o $@ $<
	$(CC) $(CFLAGS) $(INC_DIRS) -c -o $@ $<

clean:
	$(MAKE) -C libft clean
	rm -f $(OFILES)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
