/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:06:20 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/03 16:06:27 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void struct_init(i_cont *info)
{
	int	i;

	i = -1;
	while (++i <= FLAGS)
		info->flags[i] = -1;
	i = -1;
	while (++i <= L_MODS)
		info->length_mods[i] = -1;
	info->str_input = "";
	info->str_output = "";
	info->width = "";
	info->precision = "";
	info->specifier = 0;
	info->next = 0;
}

/*
** excluded zero from flags due to false read of "20" => f_Zero == 1
*/

void parse_flag(const char *format, i_cont *info)
{
	int flagnum;

	flagnum = is_flag(*format);
	if (flagnum >= f_Dash && flagnum <= f_Space)
		info->flags[flagnum] = 1;
	if (flagnum == f_Zero && ft_isdigit(*(format - 1)) == 0)
		info->flags[f_Zero] = 1;
}

void parse_width(const char *format, i_cont *info)
{
	if (ft_isdigit(*format) == 1)
	{
		if (*format != '0')
			info->width = ft_strcharjoin(info->width, *format);
		if (*format == '0' && ft_isdigit(*(format - 1)) == 1)
			info->width = ft_strcharjoin(info->width, *format);
	}
}

void parse_precision(const char *format, i_cont *info)
{
	if (is_precision(*format) == 1)
	{
		format++;
		while (ft_isdigit(*format) == 1)
			info->precision = ft_strcharjoin(info->precision, *format);
	}
}

void parse_length(const char *format, i_cont *info)
{
	int	len_num;

	len_num = is_length(format);
	if (len_num >= l_hh && len_num <= l_z)
		info->length_mods[len_num] = 1;
}

void parse_specifier(const char *format, i_cont *info)
{
	if (is_specifier(*format) == 1)
		info->specifier = *format;
}

void parse_string(const char *format, i_cont *info)
{
	int	i;
	i = 0;

	struct_init(info);
	while (*format)
	{
		while (ft_isascii(*format) == 1 && *format != '%')
		{
			info->str_input = ft_strcharjoin(info->str_input, *format);
			format++;
			i++;
		}
		if (*format == '%')
		{
			format++;
			while (is_specifier(*format) == 0)
			{
				parse_flag(format, info);
				parse_width(format, info);
				parse_precision(format, info);
				parse_length(format, info);
				format++;
			}
			parse_specifier(format, info);
		}
		error_handle(info);
		// string_print()
		format++;
	}
}
