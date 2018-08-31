/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:01:03 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/25 21:11:27 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prepare_bytype(t_info *info)
{
	if (info->speci == 's' || info->speci == 'S')
		prepare_str(info);
	else if (info->speci == 'p' || info->speci == 'P')
		prepare_address(info);
	else if (info->speci == 'x' || info->speci == 'X')
		prepare_hexadecimal(info);
	else if (info->speci == 'd' || info->speci == 'D' ||
			info->speci == 'i' || info->speci == 'I')
		prepare_signed(info);
	else if (info->speci == 'u' || info->speci == 'U')
		prepare_undecimal(info);
	else if (info->speci == 'o' || info->speci == 'O')
		prepare_octal(info);
	else if (info->speci == 'c' || info->speci == 'C')
		prepare_char(info);
	else if (info->speci == 'b' || info->speci == 'B')
		prepare_binary(info);
	else if (info->speci == '%')
		prepare_percentage(info);
}

static void	print_res(t_info *info)
{
	int i;

	i = 0;
	while (info->res[i])
	{
		ft_putchar(info->res[i]);
		i++;
	}
	info->count += i;
}

static void	print_wres(t_info *info)
{
	int i;

	i = 0;
	while (info->wres[i])
	{
		info->count += ft_putwchar(info->wres[i]);
		i++;
	}
}

static void	check_and_print(t_info *info)
{
	(info->str[0])++;
	check_for_flags(info);
	check_for_width(info);
	check_for_preci(info);
	check_for_lengths(info);
	check_for_speci(info);
	if (info->speci)
	{
		prepare_bytype(info);
		if (info->res && info->speci)
			print_res(info);
		else if (info->wres)
			print_wres(info);
	}
	reinit_structure(info);
}

int			ft_printf(char *format, ...)
{
	t_info	*info;
	va_list	args;
	int		count;

	if (!(info = (t_info*)malloc(sizeof(t_info))) || !(format))
		print_error();
	va_start(args, format);
	initialize_struct(info, &format, &args);
	count = info->count;
	while (info->str[0][0])
	{
		if (info->str[0][0] != '%')
		{
			ft_putchar(info->str[0][0]);
			(info->str[0])++;
			info->count++;
		}
		else
			check_and_print(info);
	}
	count = info->count;
	free(info);
	va_end(args);
	return (count);
}
