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

void struct_init(i_cont *info, va_list *args, int *position)
{
	int	i;

	info->position = *position;
	i = -1;
	while (++i <= FLAGS)
		info->flags[i] = -1;
	i = -1;
	while (++i <= L_MODS)
		info->length_mods[i] = -1;
	info->str_input = "";
	info->res = "";
	info->wres = NULL;
	info->width = "";
	info->precision = "";
	info->specifier = 0;
	info->args = args;
	info->next = 0;
}

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
	if (ft_isdigit(*format) == 1 && info->flags[f_Dot] != 1)
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
		info->flags[f_Dot] = 1;
		while (ft_isdigit(*(++format)) == 1)
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

	i = info->position;
	while (format[i] != '%' && format[i] != '\0')
	{
		info->str_input = ft_strcharjoin(info->str_input, format[i]);
		i++;
	}
	if (format[i] == '%')
	{
		i++;
		while (is_specifier(format[i]) == 0)
		{
			parse_flag(&format[i], info);
			parse_width(&format[i], info);
			parse_precision(&format[i], info);
			parse_length(&format[i], info);
			i++;
		}
		parse_specifier(&format[i], info);
	}
	if (info->specifier)
		i++;
	info->position = i;
}
