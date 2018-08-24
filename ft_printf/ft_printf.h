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
# define FLAGS 6
# define L_MODS 6


typedef struct		container
{
	int				position;
	int 			flags[FLAGS];
	int				length_mods[L_MODS];
	char 			*str_input;
	char 			*res;
	char			*width;
	char			*precision;
	char			specifier;
	va_list			*args;
	wchar_t			*wres;
	// void			*d_table[128];

	struct container *next;
}					i_cont;

enum 				flags
{
	f_Dash,
	f_Plus,
	f_Hash,
	f_Space,
	f_Dot,
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

typedef	void 	(*ptof)(i_cont *);

typedef	struct	DispatchTable
{
	char	specifier;
	ptof	pointer;
}				DispatchTable;

int		ft_printf(const char *format, ...);

int		is_flag(char c);
int		is_length(const char *str);
int 	is_specifier(char c);
int		is_precision(char c);

void 	struct_init(i_cont *info, va_list *args, int *position);
void	parse_string(const char *format, i_cont *info, int *printed_characters);
void	string_interpret(i_cont *info);
void 	string_print(i_cont *info);

/*
**	Juan functions
*/

char	*ft_straddprefix(char *prefix, char *str);
char		*ft_utoabaselonglong(unsigned long long int n, \
	unsigned long long int base);
char		*ft_itoalonglong(long long n);
char	*ft_straddsuffix(char *suffix, char *str);
int		ft_wchar_len(wchar_t wc);
int		ft_wstrlen(wchar_t *wstr);
wchar_t	*ft_wstraddsuffix(wchar_t *suffix, wchar_t *str);
wchar_t	*ft_wstraddprefix(wchar_t *prefix, wchar_t *str);
wchar_t	*ft_wstrnew(size_t size);
wchar_t		*ft_wstrdup(wchar_t *wstr);
void	ft_wputstr(wchar_t *str);
int		ft_wputchar(wchar_t c);
void	ft_strtoupper(char **str);
void	ft_strtolower(char **str);
int		ft_putwchar(wchar_t wc);

void	handle_int(i_cont *info);
void	handle_str(i_cont *info);
void	handle_pointer(i_cont *info);
void	handle_char(i_cont *info);
void	handle_u(i_cont *info);
void	handle_octal(i_cont *info);
void	handle_x(i_cont *info);
void	handle_percentage(i_cont *info);
void	handle_binary(i_cont *info);
void 	error_handle(i_cont *info);
void	error_print(int error_num);




#endif
