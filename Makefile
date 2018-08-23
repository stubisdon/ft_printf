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

LIBFT = libft/libft

HEADER = ft_printf/ft_printf.h

LIB_SRC = libft/*.c

OBJECTS = *.o

all: $(NAME)

$(NAME):
	gcc -g -Wall -Wextra -Werror -c $(HEADER) $(LIBFT).h $(LIB_SRC) \
	ft_printf/ft_printf.c \
	ft_printf/handle_*.c \
	ft_printf/char_detectors.c \
	ft_printf/string_parser.c \
	ft_printf/string_interpreter.c \
	ft_printf/errors.c
	ar rcs $(NAME) $(OBJECTS)
	gcc -g tests/main.c $(NAME)

clean:
	rm -f *.o
	rm -f libft/*.o

fclean: clean
	rm -f a.out
	rm -f $(LIBFT).h.gch
	rm -f libftprintf.a
	rm -f ft_printf/ft_printf.h.gch
	rm -f libft/libft.h.gch
	rm -f libft/libft.a

re: fclean
	make all
