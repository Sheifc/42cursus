# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 14:54:02 by sheferna          #+#    #+#              #
#    Updated: 2024/07/31 18:33:50 by sheferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -pthread -Iincludes -g #-fsanitize=thread
RM				= rm -rf

SRC_DIR			= src/
OBJ_DIR			= obj/

FILES_SRC		= main.c checker.c init.c utils.c philo_routine.c monitor_routine.c \
				threads.c clear.c thread_utils.c one_philo.c error.c

SRC 			= $(addprefix $(SRC_DIR),$(FILES_SRC))
OBJ_SRC 		= $(addprefix $(OBJ_DIR), $(FILES_SRC:.c=.o))

vpath %.c $(SRC_DIR)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
