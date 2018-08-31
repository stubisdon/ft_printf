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

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <wchar.h>
# include <stdarg.h>

# define NFLAGS 5
# define NLENS 6

typedef struct	s_info
{
	int		flags[NFLAGS];
	int		width;
	int		lens[NLENS];
	int		preci;
	char	speci;
	va_list	*args;
	char	**str;
	int		count;
	char	*res;
	wchar_t	*wres;
}				t_info;

enum			e_flags
{
	Fminus,
	Fplus,
	Fspace,
	Fhash,
	Fzero
};

enum			e_lengths
{
	Lhh,
	Lh,
	Ll,
	Lll,
	Lj,
	Lz
};

/*
** LIBFT
*/
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(char *str);
char			*ft_strnew(size_t size);
int				ft_toupper(int c);

/*
** NEW LIBFT
*/
wchar_t			*ft_wstrdup(wchar_t *wstr);
int				ft_wchar_len(wchar_t wc);
int				ft_wstrlen(wchar_t *wstr);
char			*ft_straddprefix(char *prefix, char *str);
char			*ft_straddsuffix(char *suffix, char *str);
wchar_t			*ft_wstraddsuffix(wchar_t *suffix, wchar_t *str);
wchar_t			*ft_wstraddprefix(wchar_t *prefix, wchar_t *str);
void			print_error(void);
wchar_t			*ft_wstrnew(size_t	size);
int				ft_putwchar(wchar_t wc);
char			*ft_utoabaselonglong(unsigned long long int n,
		unsigned long long int base);
void			ft_strtoupper(char **str);
char			*ft_itoalonglong(long long int n);

/*
** FT_PRINTF
*/
int				ft_printf(char *format, ...);
void			initialize_struct(t_info *info, char **str, va_list *args);
void			check_for_flags(t_info *info);
void			check_for_width(t_info *info);
void			check_for_preci(t_info *info);
void			check_for_lengths(t_info *info);
void			check_for_speci(t_info *info);
void			reinit_structure(t_info *info);
void			reinit_lengths(t_info *info);
int				is_flag(char c);
int				is_width(char c);
int				is_preci(char c);
int				is_length(char c);
int				is_speci(char c);
void			prepare_str(t_info *info);
void			prepare_percentage(t_info *info);
void			prepare_address(t_info *info);
void			prepare_hexadecimal(t_info *info);
void			prepare_undecimal(t_info *info);
void			prepare_octal(t_info *info);
void			prepare_binary(t_info *info);
void			prepare_signed(t_info *info);
void			prepare_char(t_info *info);

#endif
