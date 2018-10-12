/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:04:59 by dkotov            #+#    #+#             */
/*   Updated: 2018/10/11 19:00:19 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <wchar.h>
# include "../libft/libft.h"
# define FLAGS 7
# define L_MODS 6

typedef struct			s_container
{
	int					position;
	int					flags[FLAGS];
	int					length_mods[L_MODS];
	char				*str_input;
	char				*res;
	char				*width;
	char				*precision;
	char				specifier;
	va_list				*args;
	wchar_t				*wres;
	struct s_container	*next;
}						t_cont;

enum					e_flags
{
	f_Dash,
	f_Plus,
	f_Hash,
	f_Space,
	f_Dot,
	f_Zero,
	f_Aster
};

enum					e_length_mods
{
	l_hh,
	l_h,
	l_ll,
	l_l,
	l_j,
	l_z
};

enum					e_errors
{
	e_ConflictingType,
	e_Missing_value,
	e_UndefinedBehavior
};

int						ft_printf(const char *format, ...);

int						is_flag(char c);
int						is_length(const char *str);
int						is_specifier(char c);
int						is_precision(char c);

void					struct_init(t_cont *info, va_list *args, int *position);
void					parse_string(const char *format, t_cont *info, int \
	*printed_characters);
void					string_interpret(t_cont *info);
void					string_print(t_cont *info);

/*
**	custom functions
*/

char					*ft_straddprefix(char *prefix, char *str);
char					*ft_utoabaselonglong(unsigned long long int n, \
	unsigned long long int base);
char					*ft_itoalonglong(long long n);
char					*ft_straddsuffix(char *suffix, char *str);
int						ft_wchar_len(wchar_t wc);
int						ft_wstrlen(wchar_t *wstr);
wchar_t					*ft_wstraddsuffix(wchar_t *suffix, wchar_t *str);
wchar_t					*ft_wstraddprefix(wchar_t *prefix, wchar_t *str);
wchar_t					*ft_wstrnew(size_t size);
wchar_t					*ft_wstrdup(wchar_t *wstr);
void					ft_wputstr(wchar_t *str);
int						ft_wputchar(wchar_t c);
void					ft_strtoupper(char **str);
void					ft_strtolower(char **str);
int						ft_putwchar(wchar_t wc);

void					handle_int(t_cont *info);
void					handle_str(t_cont *info);
void					handle_pointer(t_cont *info);
void					handle_char(t_cont *info);
void					handle_u(t_cont *info);
void					handle_octal(t_cont *info);
void					handle_x(t_cont *info);
void					handle_percentage(t_cont *info);
void					handle_binary(t_cont *info);
void					error_handle(t_cont *info);
void					error_print(int error_num);

#endif
