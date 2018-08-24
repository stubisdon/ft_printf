# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkotov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/03 16:09:53 by dkotov            #+#    #+#              #
#    Updated: 2018/08/21 13:18:14 by dkotov           ###   ########.fr        #
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
	make -C libft
	gcc -Wall -Wextra -Werror -c ft_printf/*.c -I libft
	ar rcs $(NAME) $(OBJ) $(LIBFT)/*.o
	ranlib $(NAME)

clean:
	rm -f *.o
	rm -f libft/*.o

fclean: clean
	rm -f a.out
	rm -f libftprintf.a
	rm -f ft_printf/ft_printf.h.gch
	rm -f libft/libft.h.gch
	rm -f libft/libft.a

re: fclean
	make all

test:
	gcc -g tests/main.c $(NAME)

leaks:
	gcc -g ft_printf/*.c libft/*.c tests/main.c
