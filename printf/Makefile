# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 15:46:47 by sheferna          #+#    #+#              #
#    Updated: 2023/10/22 18:38:13 by sheferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
CC 		= gcc
CFLAGS 	= -Wall -Werror -Wextra
RM		= rm -rf
AR 		= ar rcs
SRCS 	= ft_printf.c ft_printf_utils.c

SRCS_OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRCS_OBJS)
	@$(AR) $(NAME) $(SRCS_OBJS)

all: $(NAME)

clean:
	@$(RM) $(SRCS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re