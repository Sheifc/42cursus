# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 12:40:37 by sheferna          #+#    #+#              #
#    Updated: 2024/05/02 00:43:47 by sheferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR		  = libft/
LIBFT			  = libft.a

MLX42_DIR 		  = ./MLX42

NAME			  = so_long

CC				  = gcc
#CFLAGS			  = -Wall -Werror -Wextra -Iincludes -g -I$(MLX42_DIR)/include -fsanitize=address
#MLX_FLAGS         = -ldl -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
#Compiling at home:
CFLAGS = -Wall -Werror -Wextra -Iincludes -g -I/usr/local/Cellar/glfw/3.4/include -I$(MLX42_DIR)/include -fsanitize=address
MLX_FLAGS = -L$(MLX42_DIR) -lmlx42 -L/usr/local/Cellar/glfw/3.4/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit

RM				  = rm -rf

SRC_DIR			  = src/
OBJ_DIR			  = obj/

FILES_SRC		  = main.c utils.c check_argv.c read_map.c \
					check_map_content.c save_player_position.c \
					check_wall.c init_status.c check_game.c \
					init_game.c key_hook.c loading.c move_player.c \
					game_over.c reloading.c \

SRC 			  = $(addprefix $(SRC_DIR),$(FILES_SRC))
OBJ_SRC 		  = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

vpath %.c $(SRC_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_SRC)
	@$(MAKE) -s all bonus printf gnl -C $(LIBFT_DIR)
	$(CC) $(OBJ_SRC) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -fsanitize=address -o $@
	@$(MAKE) -C $(MLX42_DIR)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX42_DIR) clean

re: fclean all

.PHONY: all clean fclean re
