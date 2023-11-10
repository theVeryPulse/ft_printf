# UNRESOLVED
# How the test would be run? What should libftprintf.a contain?


CC := cc
CFLAGS := -Wall -Wextra -Werror
LIBFT_DIR := ./libft
BUILD_DIR := .
NAME := libftprintf.a
LIBFT := libft.a

# Test main
TEST := test.c

# Source files of ftprintf
CFILES := ft_printf.c
OFILES := $(CFILES:.c=.o)

# Source files of libft
LIBFT_FILES = \
ft_isalpha.c	ft_isdigit.c		ft_isalnum.c	ft_isascii.c	ft_isprint.c \
ft_strlen.c		ft_memset.c			ft_bzero.c		ft_memcpy.c		ft_memmove.c \
ft_strlcpy.c	ft_strlcat.c		ft_toupper.c	ft_tolower.c	ft_strchr.c \
ft_strrchr.c	ft_strncmp.c		ft_memchr.c		ft_memcpy.c		ft_strnstr.c \
ft_atoi.c		ft_calloc.c			ft_strdup.c \
\
ft_substr.c		ft_strjoin.c		ft_strtrim.c	ft_split.c		ft_itoa.c \
ft_strmapi.c	ft_striteri.c		ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	\
ft_putnbr_fd.c \
\
ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c \
ft_lstdelone.c	ft_lstclear.c		ft_lstiter.c	ft_lstmap.c \
LIBFT_OBJ_FILES := $(patsubst $(LIBFT_DIR)/%.c, %.o, $(LIBFT_DIR)/$(LIBFT_FILES))


all: $(NAME)

# Build libftprint.a
$(NAME): $(OFILES)
	ar rcs $@ $(OFILES)

# Build the object files required for libftprint.a
$(OFILES): $(CFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(CFILES) -c

# Build libft and copy it to current directory
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all
	cp $(LIBFT_DIR)/$(LIBFT) $(BUILD_DIR)/$(LIBFT)

clean:
	rm -f $(wildcard *.o)

fclean: clean
	rm -f $(wildcard *.a)

re: fclean all

test: $(CFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(CFILES) -L. -lft -g
	./a.out
