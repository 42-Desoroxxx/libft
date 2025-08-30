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
#        )))                    |  $$$$$$/                                    Version 1.6.1  #
#       (((                      \______/                                                    #
#     +-----+                                   __..--''``---....___   _..._    __           #
#     |     |]      /    //    // //  /// //_.-'    .-/";  `        ``<._  ``.''_ `. / // /  #
#     `-----'   //  //  ///  ///     ///_.-' _..--.'_    \                    `( ) ) // //   #
#         /   / // / ///  /      /// / (_..-' // (< _     ;_..__               ; `' / ///    #
#     ///  //  /  /       // ///  /   / // // //  `-._,_)' // / ``--...____..-' /// / //     #
#    / // / /// //  /// / / // //   //  /// //  /  ///  //  // /// / /  ///   /   / ///  //  #
##############################################################################################

.PHONY: all debug clean fclean re re_debug sane re_sane

NAME = libft.a
MAKE_MODE ?= release

# Colors
GREEN = \033[32m
BLUE = \033[34m
RED = \033[31m
RESET = \033[0m

# Compiler
CC = cc
BASE_FLAGS = \
	-Wall -Wextra \
 	-Werror=vla -pedantic-errors -Werror=int-conversion -Werror=incompatible-pointer-types -Werror=implicit-function-declaration -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations \
	-MMD \
	-flto=thin
RELEASE_FLAGS = \
	-Werror \
	-O3 -ffast-math -march=native
DEBUG_FLAGS = \
	-g -O0 -fno-builtin -mno-omit-leaf-frame-pointer -fno-omit-frame-pointer \
	-DDEBUG=true
SANE_FLAGS = \
	-fsanitize=address,pointer-compare,pointer-subtract,leak,undefined,shift,shift-exponent,shift-base,integer-divide-by-zero,unreachable,vla-bound,null,signed-integer-overflow,bounds,alignment,float-divide-by-zero,float-cast-overflow,nonnull-attribute,returns-nonnull-attribute,bool,enum,pointer-overflow,builtin -fsanitize-address-use-after-scope

# Archiver
AR = ar rcs

# Directories
SRC = src
OBJ = obj
INCLUDES = -Iincludes

# Sources
SRC_FILES := \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c \
	ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_tolower.c ft_toupper.c \
	ft_atol.c ft_split.c \
	string/ft_strncpy.c string/ft_strchr.c string/ft_strdup.c string/ft_striteri.c string/ft_strjoin.c string/ft_strlcat.c string/ft_strlcpy.c string/ft_strlen.c string/ft_strmapi.c string/ft_strncmp.c string/ft_strnstr.c string/ft_strrchr.c string/ft_strtrim.c string/ft_substr.c string/ft_strndup.c string/str_utils.c string/ft_str_equal.c string/ft_str_add.c \
	get_next_line.c get_next_line_utils.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	print/ft_printf.c print/ft_print_special.c print/ft_print_basic.c \
	memory/s_alloc.c \
	data/ft_map_lifetime.c data/ft_map.c data/ft_map_print.c
SRCS := $(addprefix $(SRC)/,$(SRC_FILES))
OBJS := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))

ifeq ($(MAKE_MODE),release)
	CFLAGS = $(BASE_FLAGS) $(RELEASE_FLAGS)
else
	ifeq ($(MAKE_MODE),debug)
		CFLAGS = $(BASE_FLAGS) $(DEBUG_FLAGS)
	else
	 ifeq ($(MAKE_MODE),sane)
	 	CFLAGS = $(BASE_FLAGS) $(DEBUG_FLAGS) $(SANE_FLAGS)
	 else
		$(error Unknown mode)
		endif
	endif
endif

ifeq ($(shell expr $(shell $(CC) -v 2>&1 | grep -oP 'version \K\d+') \>= 15), 1)
    DEBUG_FLAGS += -fstrict-flex-arrays=3
endif

all:
	@$(MAKE) -j --no-print-directory $(NAME)

debug:
	@echo "$(GREEN)Building in debug mode$(RESET)"
	@$(MAKE) -j --no-print-directory MAKE_MODE=debug

sane:
	@echo "$(GREEN)Building in sane mode$(RESET)"
	@$(MAKE) -j --no-print-directory MAKE_MODE=sane

$(OBJ):
	@mkdir -p $@ $(dir $(OBJS))

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	@echo "$(BLUE)Compiling$(RESET) $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(OBJS:%.o=%.d)

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

re: fclean
	@$(MAKE) -j --no-print-directory all

re_debug: fclean
	@$(MAKE) -j --no-print-directory debug

re_sane: fclean
	@$(MAKE) -j --no-print-directory sane

bonus: all
