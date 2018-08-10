# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkotov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/19 20:27:56 by dkotov            #+#    #+#              #
#    Updated: 2018/06/19 21:28:09 by dkotov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SOURCES = *.c

ROOT = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(HEADER) $(SOURCES)
	ar rcs $(NAME) $(ROOT)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(HEADER).gch a.out

re:	fclean all

main:
	gcc -Wall -Wextra -Werror main.c $(NAME)
