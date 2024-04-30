# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 11:18:19 by sheferna          #+#    #+#              #
#    Updated: 2024/04/14 17:41:40 by sheferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR		= libft/
LIBFT			= libft.a

NAME			= pipex
NAME_BONUS 		= pipex_bonus

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -Iincludes -g
RM				= rm -rf

SRC_DIR			= src/
OBJ_DIR			= obj/

SRC_DIR_BONUS	= src_bonus/
OBJ_DIR_BONUS	= obj_bonus/

FILES_SRC		= main.c utils.c fork.c get_path.c \
				processes.c execute.c \

FILES_BONUS		= main_bonus.c get_path_bonus.c execute_bonus.c \
				fork_bonus.c processes_bonus.c \
				here_doc_bonus.c utils_bonus.c \

SRC 			= $(addprefix $(SRC_DIR),$(FILES_SRC))
OBJ_SRC 		= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

SRC_BONUS 		= $(addprefix $(SRC_DIR_BONUS),$(FILES_BONUS))
OBJ_BONUS 		= $(SRC_BONUS:$(SRC_DIR_BONUS)%.c=$(OBJ_DIR_BONUS)%.o)

vpath %.c $(SRC_DIR) $(SRC_DIR_BONUS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_SRC)
	@$(MAKE) -s all bonus printf gnl -C $(LIBFT_DIR)
	$(CC) $(OBJ_SRC) -L $(LIBFT_DIR) -lft -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@$(MAKE) -s all bonus printf gnl -C $(LIBFT_DIR)
	$(CC) $(OBJ_BONUS) -L $(LIBFT_DIR) -lft -o $@

clean:
	@$(RM) $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus