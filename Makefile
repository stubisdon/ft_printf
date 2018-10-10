# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkotov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/03 16:09:53 by dkotov            #+#    #+#              #
#    Updated: 2018/10/10 15:50:37 by dkotov           ###   ########.fr        #
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
	rm -f $(OBJ)
	rm -f libft/*.o

fclean: clean
	rm -f libftprintf.a
	rm -f libft/libft.a

re: fclean
	make all

test:
	gcc -g ft_printf/*.c libft/*.c tests/main.c -fsanitize=address
