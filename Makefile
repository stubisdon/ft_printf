# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkotov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/03 16:09:53 by dkotov            #+#    #+#              #
#    Updated: 2018/08/29 18:27:54 by dkotov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

LIB = libft.a

PRINTF = ft_printf

SRC = *.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c *.c
	ar rc $(NAME) $(OBJ) *.o

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean: clean
	rm -f libftprintf.a
	rm -f libft.a
	rm -f a.out
	

re: fclean
	make all

test:
	gcc -g tests/main.c $(NAME) -fsanitize=address

leaks:
	gcc -g ft_printf/*.c libft/*.c tests/main.c
