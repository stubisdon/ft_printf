/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:04:59 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/25 21:06:39 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <wchar.h>
# include "../libft/libft.h"

// typedef struct		container
// {
// 	char 			*str_before;
// 	char 			*str_after;
// 	char 			flag;
// 	char			*value;
// 	char			type;
// 	char			*length_mod;
// 	struct container *next;
// }					i_cont;

int		ft_printf(const char *format, ...);

int		is_flag(char c);
int		is_length_mod(char c);
int 	is_type(char c);

// int		string_parse(const char *format, i_cont *body);
//
// char 	*string_interpret(i_cont info);



void	handle_int(int a);
void	handle_char(char c);
void	handle_string(char *str);
void	handle_string_wide(wchar_t *);
void	handle_u(unsigned int number);
void	handle_octal(unsigned int number);
void	handle_hex_uppercase(unsigned int number);
void	handle_hex_lowercase(unsigned int number);
void	handle_pointer(unsigned long address);
void	error();



#endif
