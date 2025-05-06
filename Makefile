##############################################################################################
#                                                                                            #
#   /$$$$$$                                      /$$      /$$           /$$                  #
#  /$$__  $$                                    | $$$    /$$$          | $$                  #
# | $$  \__/  /$$$$$$  /$$$$$$$$ /$$   /$$      | $$$$  /$$$$  /$$$$$$ | $$   /$$  /$$$$$$   #
# | $$       /$$__  $$|____ /$$/| $$  | $$      | $$ $$/$$ $$ |____  $$| $$  /$$/ /$$__  $$  #
# | $$      | $$  \ $$   /$$$$/ | $$  | $$      | $$  $$$| $$  /$$$$$$$| $$$$$$/ | $$$$$$$$  #
# | $$    $$| $$  | $$  /$$__/  | $$  | $$      | $$\  $ | $$ /$$__  $$| $$_  $$ | $$_____/  #
# |  $$$$$$/|  $$$$$$/ /$$$$$$$$|  $$$$$$$      | $$ \/  | $$|  $$$$$$$| $$ \  $$|  $$$$$$$  #
#  \______/  \______/ |________/ \____  $$      |__/     |__/ \_______/|__/  \__/ \_______/  #
#                                /$$  | $$                                                   #
#        )))                    |  $$$$$$/                                    Version 1.0    #
#       (((                      \______/                                                    #
#     +-----+                                   __..--''``---....___   _..._    __           #
#     |     |]      /    //    // //  /// //_.-'    .-/";  `        ``<._  ``.''_ `. / // /  #
#     `-----'   //  //  ///  ///     ///_.-' _..--.'_    \                    `( ) ) // //   #
#         /   / // / ///  /      /// / (_..-' // (< _     ;_..__               ; `' / ///    #
#     ///  //  /  /       // ///  /   / // // //  `-._,_)' // / ``--...____..-' /// / //     #
#    / // / /// //  /// / / // //   //  /// //  /  ///  //  // /// / /  ///   /   / ///  //  #
##############################################################################################

.PHONY: all debug clean fclean re re_debug

NAME = libft.a
MODE ?= release

# Colors
GREEN = \033[1;32m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

# Compiler
CC = cc
RELEASE_FLAGS = -Wall -Wextra -Werror -O3 -ffast-math -march=native -flto
DEBUG_FLAGS = -Wall -Wextra -O0 -fno-builtin -g
ifeq ($(MODE),debug)
    CFLAGS = $(DEBUG_FLAGS)
    LIB_TARGET = debug
else
    CFLAGS = $(RELEASE_FLAGS)
    LIB_TARGET = all
endif

# Archiver
AR = ar rcs

# Directories
SRC = src
OBJ = obj
INCLUDES = -Iincludes

# Sources
SRC_FILES := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c \
   	ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_tolower.c ft_toupper.c \
    ft_atol.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
    ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
    get_next_line.c get_next_line_utils.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
    print/ft_printf.c print/ft_print_special.c print/ft_print_basic.c \
    memory/s_alloc.c str_utils.c ft_strncpy.c
SRCS := $(addprefix $(SRC)/,$(SRC_FILES))
OBJS := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))

all: $(NAME)

debug:
	@echo "$(GREEN)Building in debug mode$(RESET)"
	@$(MAKE) --no-print-directory MODE=debug

$(OBJ):
	@mkdir -p $@ $(dir $(OBJS))

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	@echo "$(BLUE)Compiling$(RESET) $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)Archiving$(RESET) $@..."
	@$(AR) $@ $^
	@echo "$(GREEN)Done!$(RESET)"

clean:
	@echo "$(RED)Cleaning$(RESET) $(NAME)'s object files..."
	@rm -rf $(OBJ)
	@for lib in $(LIB_DIRS); do \
		$(MAKE) --no-print-directory -s -C $$lib clean; \
	done

fclean: clean
	@echo "$(RED)Removing$(RESET) $(NAME)..."
	@rm -f $(NAME)
	@for lib in $(LIB_DIRS); do \
		$(MAKE) --no-print-directory -s -C $$lib fclean; \
	done

re: fclean all

re_debug: fclean debug
