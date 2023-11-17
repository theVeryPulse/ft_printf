# Makefile

CC = gcc
CFLAGS := -Wall -Wextra -Werror

LIBFT := libft/libft.a

NAME := libftprintf.a
CFILES := \
	ft_printf.c \
	ft_printf_all.c \
	ft_printf_c.c \
	ft_printf_s.c \
	ft_printf_p.c \
	ft_printf_d.c \
	ft_printf_u.c \
	ft_printf_x.c \
	ft_abs.c
OFILES := $(CFILES:.c=.o)

# Default target
all: $(NAME)

# Compile all codes from libft and libftprintf into libftprintf.a
$(NAME): $(LIBFT) $(OFILES)
	ar rcs $@ $(OFILES) libft/*.o

# Build all object files of libft as well as libft.a
$(LIBFT):
	$(MAKE) -C libft

# Build object files of all required source codes
$(OFILES): $(CFILES)
	$(CC) $(CFLAGS) -c $^  

clean:
	$(MAKE) -C libft clean
	rm -f $(OFILES) $(CFILES:.c=.o)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
