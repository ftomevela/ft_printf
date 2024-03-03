# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 17:43:56 by ftome-ve          #+#    #+#              #
#    Updated: 2024/02/26 15:59:20 by ftome-ve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
LIBC	= ar rcs
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

NAME	= libftprintf.a
SRCS	= ft_printf.c


OBJS	= $(SRCS:.c=.o)


all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -I ./ -o $@
	
$(NAME): $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)
fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all .c.o clean fclean
