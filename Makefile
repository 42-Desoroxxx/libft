# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 22:55:02 by llage             #+#    #+#              #
#    Updated: 2025/02/01 05:46:22 by llage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean fclean re

GREEN = \033[1;32m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
AR = ar rcs

DEPS = includes
SRC = src
OBJ = obj

SRCS := src/ft_atoi.c  src/ft_bzero.c  src/ft_calloc.c  src/ft_calloc.c  \
	src/ft_isalnum.c  src/ft_isalpha.c  src/ft_isascii.c  src/ft_isdigit.c \
	src/ft_isprint.c  src/ft_itoa.c  src/ft_lstadd_back.c  \
	src/ft_lstadd_front.c src/ft_lstclear.c  src/ft_lstdelone.c \
	src/ft_lstiter.c  src/ft_lstlast.c  src/ft_lstmap.c  src/ft_lstnew.c \
	src/ft_lstsize.c  src/ft_memchr.c  src/ft_memcmp.c  src/ft_memcpy.c \
	src/ft_memmove.c  src/ft_memset.c  src/ft_print_basic.c \
	src/ft_print_special.c src/ft_printf.c  src/ft_putchar_fd.c \
	src/ft_putendl_fd.c  src/ft_putnbr_fd.c  src/ft_putstr_fd.c \
	src/ft_split.c  src/ft_strdup.c  src/ft_striteri.c  src/ft_strjoin.c \
	src/ft_strlcat.c  src/ft_strlcpy.c  src/ft_strlen.c  src/ft_strmapi.c \
	src/ft_strncmp.c  src/ft_strnstr.c  src/ft_strrchr.c  src/ft_strtrim.c \
	src/ft_substr.c  src/ft_tolower.c  src/ft_toupper.c  src/get_next_line.c \
	src/get_next_line_utils.c
OBJS := $(patsubst $(SRC)/%,$(OBJ)/%,$(SRCS:.c=.o))

all: $(NAME)

$(OBJ)/%.o: $(SRC)/%.c $(DEPS)
	@mkdir -p $(@D)
	@echo "$(BLUE)Compiling$(RESET) $<..."
	@$(CC) $(CFLAGS) -I$(DEPS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)Archiving$(RESET) $@..."
	@$(AR) $@ $^
	@echo "$(GREEN)Done!$(RESET)"

bonus: all

clean:
	@echo "$(RED)Cleaning$(RESET) object files..."
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)Removing$(RESET) $(NAME)..."
	@rm -f $(NAME)

re: fclean
	@$(MAKE) --no-print-directory all


