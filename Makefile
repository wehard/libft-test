# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 15:22:37 by wkorande          #+#    #+#              #
#    Updated: 2019/10/15 22:32:19 by wkorande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_test

SRCS = libft_test.c

INCL = ./

LIBFOLDER = ../libft

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) -I $(INCL) $(SRCS) -L../libft -lft

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
