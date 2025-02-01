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

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
AR = ar rcs

DEPS = includes
SRC = src
OBJ = obj

SRCS := $(shell find $(SRC) -name "*.c")
OBJS := $(patsubst $(SRC)/%,$(OBJ)/%,$(SRCS:.c=.o))

all: $(NAME)

$(OBJ)/%.o: $(SRC)/%.c $(DEPS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(DEPS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

