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

void	parse_flag(const char *format, t_cont *info)
{
	int flagnum;

	flagnum = is_flag(*format);
	if (flagnum >= f_Dash && flagnum <= f_Space)
		info->flags[flagnum] = 1;
	if (flagnum == f_Zero && ft_isdigit(*(format - 1)) == 0)
		info->flags[f_Zero] = 1;
}

void	parse_width(const char *format, t_cont *info)
{
	if (ft_isdigit(*format) == 1 && info->flags[f_Dot] != 1)
	{
		if (*format != '0')
			info->width = ft_strcharjoin(info->width, *format);
		if (*format == '0' && ft_isdigit(*(format - 1)) == 1)
			info->width = ft_strcharjoin(info->width, *format);
	}
	if ((*format) == '*')
		info->flags[f_Aster] = 1;
}

void	parse_length_and_preci(const char *format, t_cont *info)
{
	int	len_num;

	len_num = is_length(format);
	if (len_num >= l_hh && len_num <= l_z)
		info->length_mods[len_num] = 1;
	if (is_precision(*format) == 1)
	{
		info->flags[f_Dot] = 1;
		while (ft_isdigit(*(++format)) == 1)
			info->precision = ft_strcharjoin(info->precision, *format);
	}
}

void	parse_specifier(const char *format, t_cont *info)
{
	if (is_specifier(*format) == 1)
		info->specifier = *format;
}

void	parse_string(const char *format, t_cont *info, int *printed_characters)
{
	int	i;

	i = info->position;
	while (format[i] != '%' && format[i] != '\0')
	{
		ft_putchar(format[i]);
		i++;
		(*printed_characters)++;
	}
	if (format[i] == '%')
	{
		i++;
		while (is_specifier(format[i]) == 0 && format[i] != '\0')
		{
			parse_flag(&format[i], info);
			parse_width(&format[i], info);
			parse_length_and_preci(&format[i], info);
			i++;
		}
		parse_specifier(&format[i], info);
	}
	if (info->specifier)
		i++;
	info->position = i;
}
