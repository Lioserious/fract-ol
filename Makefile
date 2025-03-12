# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 15:26:53 by lihrig            #+#    #+#              #
#    Updated: 2025/02/20 16:20:30 by lihrig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#################### PROJEKT KONFIGURATION #####################################
################################################################################
NAME = my_program
CC = cc
RM = rm -rf

################################################################################
#################### VERZEICHNISSE #############################################
################################################################################
OBJ_DIR = _obj
LIBFT_DIR = lib/Libft
MLX42_DIR = lib/MLX42
LIBFT = $(LIBFT_DIR)/libft.a
MLX42 = $(MLX42_DIR)/build/libmlx42.a
INC_DIRS := $(LIBFT_DIR) $(MLX42_DIR)/include

vpath %.h $(INC_DIRS)

################################################################################
#################### QUELL-DATEIEN #############################################
################################################################################
# Alle .c-Dateien im Hauptverzeichnis
SRC_FILES = test.c \


SRC := $(SRC_FILES)

################################################################################
#################### OBJEKT-DATEIEN ############################################
################################################################################
OBJS := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

################################################################################
#################### KOMPILIERUNGS-FLAGS ######################################
################################################################################
CFLAGS := -Wall -Wextra -Werror -g -MMD -MP $(addprefix -I, $(INC_DIRS))

# OS-spezifische Konfiguration
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin) # macOS
	LDFLAGS := -L$(LIBFT_DIR) -lft -L$(MLX42_DIR)/build -lmlx42 -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else ifeq ($(UNAME), Linux) # Linux
	LDFLAGS := -L$(LIBFT_DIR) -lft -L$(MLX42_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm
else # Windows/Default
	LDFLAGS := -L$(LIBFT_DIR) -lft -L$(MLX42_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm
endif

################################################################################
#################### REGELN ###################################################
################################################################################
all: libft mlx42 $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJS)
	@echo "\033[0;32mCompiling $(NAME)...\033[0m"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "\033[0;32mSuccessful Compilation of $(NAME)\033[0m"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@echo "\033[0;32mCompiling $<...\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

libft: $(LIBFT)
$(LIBFT):
	@echo "\033[0;32mCompiling libft..\033[0m"
	@$(MAKE) -C $(LIBFT_DIR)

mlx42: $(MLX42)
$(MLX42):
	@echo "\033[0;32mCompiling MLX42..\033[0m"
	@if [ ! -d $(MLX42_DIR)/build ]; then \
		mkdir -p $(MLX42_DIR)/build; \
		cd $(MLX42_DIR)/build && cmake .. && cmake --build .; \
	fi

clean:
	@echo "\033[0;32mCleaning object files...\033[0m"
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "\033[0;32mRemoving $(NAME)...\033[0m"
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[0;32mRemoved files successfully\033[0m"

re: fclean all

# Debug Test mit Valgrind
debug: CFLAGS += -g
debug: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

# Compiler mit Address Sanitizer
san: CFLAGS += -fsanitize=address -g
san: LDFLAGS += -fsanitize=address
san: re

.PHONY: all clean fclean re libft mlx42 debug san
