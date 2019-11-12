# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 15:22:37 by wkorande          #+#    #+#              #
#    Updated: 2019/11/12 11:03:56 by wkorande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_test

SRCS = libft_test.c

INCL = ./

LIBFOLDER = ../libft

LIBINCL	= includes

all: $(NAME)

$(NAME):
	make -C $(LIBFOLDER)
	make clean -C $(LIBFOLDER)
	gcc -o $(NAME) -I $(INCL) -I $(LIBFOLDER)/$(LIBINCL) $(SRCS) -L$(LIBFOLDER) -lft

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
