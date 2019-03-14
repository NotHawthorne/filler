# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alkozma <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 18:06:36 by alkozma           #+#    #+#              #
#    Updated: 2019/03/13 22:14:24 by alkozma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = buttstallion.filler

SRCS = check.c \
	   main.c \
	   read.c \
	   direction.c

OBJECTS = $(patsubst %.c,%.o,$(SRCS))

HEADERS = filler.h \
		  includes/ftgnl.h \
		  includes/ftprintf.h \
		  includes/libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	cp libft/libft.a ./
	gcc $(SRCS) libft.a -Iincludes $(FLAGS) -o $(NAME)

clean:
	make -C libft clean
	rm -rf $(OBJECTS)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
