# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkotov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/03 16:09:53 by dkotov            #+#    #+#              #
#    Updated: 2018/08/03 16:12:37 by dkotov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

LIBFT = libft/libft

HEADER = ft_printf/ft_printf.h

LIB_SRC = libft/*.c

OBJECTS = *.o

all:
	gcc -Wall -Wextra -Werror -c $(HEADER) $(LIBFT).h $(LIB_SRC) \
	$(NAME)/ft_printf.c \
	$(NAME)/handle_*.c \
	$(NAME)/char_detectors.c \
	$(NAME)/string_parser.c \
	$(NAME)/string_interpreter.c
	ar rcs libftprintf.a $(OBJECTS)
	gcc -Wall -Wextra -Werror main.c libftprintf.a

clean:
	rm -f *.o

fclean: clean
	rm -f a.out
	rm -f $(LIBFT).h.gch
	rm -f libftprintf.a
	rm -f ft_printf/ft_printf.h.gch
	rm -f libft/libft.h.gch

re: fclean all

debug:
	gcc -Wall -Wextra -Werror $(LIB_SRC) $(NAME)/*.c -g
