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

SRC = ft_printf.c \
	handle_binary.c \
	handle_char.c \
	handle_int.c \
	handle_octal.c \
	handle_p.c \
	handle_percentage.c \
	handle_string.c \
	handle_u.c \
	handle_x.c \
	char_detectors.c \
	string_parser.c \
	string_interpreter.c \
	errors.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -g -Wall -Wextra -Werror -c *.c
	ar rc $(NAME) $(OBJ) *.o

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean: clean
	rm -f libftprintf.a
	rm -f libft.a

re: fclean
	make all

test:
	gcc -g tests/main.c $(NAME) -fsanitize=address

leaks:
	gcc -g ft_printf/*.c libft/*.c tests/main.c
