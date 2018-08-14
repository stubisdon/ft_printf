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
# define FLAGS 5
# define L_MODS 6


typedef struct		container
{
	int 			flags[FLAGS];
	int				length_mods[L_MODS];
	char 			*str_input;
	char 			*str_output;
	char			*width;
	char			*precision;
	char			specifier;
	// void			*d_table[128];

	struct container *next;
}					i_cont;

enum 				flags
{
	f_Dash,
	f_Plus,
	f_Hash,
	f_Space,
	f_Zero
};

enum 				length_mods
{
	l_hh,
	l_h,
	l_ll,
	l_l,
	l_j,
	l_z
};

enum 				errors
{
	e_ConflictingType,
	e_Missing_value,
	e_UndefinedBehavior
};

/*
**	pointer to function = ptof
*/

// typedef	ptof (*void)(void);
//
// typedef	struct	DispatchTable
// {
// 	char	specifier;
// 	ptof	pointer;
// }				DispatchTable;

int		ft_printf(const char *format, ...);

int		is_flag(char c);
int		is_length(const char *str);
int 	is_specifier(char c);
int		is_precision(char c);

void	parse_string(const char *format, i_cont *body);
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
void 	error_handle(i_cont *info);
void	error_print(int error_num);




#endif
