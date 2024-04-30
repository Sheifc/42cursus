# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 16:43:46 by sheferna          #+#    #+#              #
#    Updated: 2024/04/30 21:37:39 by sheferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR 				= libft/
LIBFT					= libft.a

NAME 					= push_swap
NAME_BONUS 				= checker

INCL 					= -I $(LIBFT_DIR) -I $(SRC_DIR) -I $(SRC_DIR_BONUS)

CC 						= gcc
CFLAGS 					= -g -Wall -Werror -Wextra 
RM						= rm -rf

SRC_DIR 				= src/
OBJ_DIR					= obj/

SRC_DIR_BONUS        	= src_bonus/
OBJ_DIR_BONUS        	= obj_bonus/

FILES		      		= main.c parsing.c verifications.c \
						swap.c push.c rotate.c reverse.c \
						size.c costs.c index.c position.c target.c \
						memory_cleaning.c sort_three.c \
						sorting_algorithm.c push_all_b_leave_three.c \
						find_cheapest.c move_cheapest.c move_the_rest.c \

FILES_BONUS        		= checker_main_bonus.c memory_cleaning_bonus.c \
						parsing_bonus.c size_bonus.c \
						push_bonus.c rotate_bonus.c reverse_bonus.c \
						swap_bonus.c swap_aux_bonus.c rotate_aux_bonus.c \
						verifications_bonus.c check_instructions_bonus.c \

SOURCES = $(FILES:%=$(SRC_DIR)/%)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

SOURCES_BONUS = $(FILES_BONUS:%=$(SRC_DIR_BONUS)/%)
OBJS_BONUS = $(patsubst $(SRC_DIR_BONUS)/%.c, $(OBJ_DIR_BONUS)/%.o, $(SOURCES_BONUS))
	
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s all bonus printf -C $(LIBFT_DIR)
	@$(CC) $(OBJS) -L $(LIBFT_DIR) -lft -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@
	
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) -s all bonus printf -C $(LIBFT_DIR)
	$(CC) $(OBJS_BONUS) -L $(LIBFT_DIR) -lft -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

test20:	$(NAME)	
		$(eval ARG = $(shell ruby -e "puts (00..19).to_a.shuffle.join(' ')"))
		./push_swap $(ARG) | ./checker_Mac $(ARG)

test100:	$(NAME)	
		$(eval ARG = $(shell ruby -e "puts (00..99).to_a.shuffle.join(' ')"))
		./push_swap $(ARG) | ./checker_Mac $(ARG)

.PHONY: all clean fclean re bonus