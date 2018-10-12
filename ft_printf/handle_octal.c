/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 21:36:02 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/26 21:42:28 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_hash(t_cont *info, int flag, int iszero)
{
	if (info->flags[f_Hash] == 1 && iszero != 1)
	{
		if (((info->flags[f_Zero] != 1 || info->flags[f_Dash] == 1) &&
				flag == 0) || (info->flags[f_Zero] == 1 && flag == 0 &&
					ft_atoi(info->precision) > 0))
			info->res = ft_straddprefix("0", info->res);
	}
}

static void	apply_width(t_cont *info, int iszero)
{
	int len;

	if (ft_atoi(info->width) > (len = ft_strlen(info->res)))
	{
		while (info->flags[f_Dash] == 1 && len < ft_atoi(info->width))
		{
			info->res = ft_straddsuffix(" ", info->res);
			len++;
		}
		if (info->flags[f_Zero] == 1 && info->flags[f_Dash] != 1 &&
				info->flags[f_Hash] == 1 && ft_strcmp(info->precision, "") == 0)
			len += 1;
		while (info->flags[f_Zero] == 1 && len < ft_atoi(info->width) &&
				ft_strcmp(info->precision, "") == 0)
		{
			info->res = ft_straddprefix("0", info->res);
			len++;
		}
		while (len < ft_atoi(info->width))
		{
			info->res = ft_straddprefix(" ", info->res);
			len++;
		}
	}
	apply_hash(info, 1, iszero);
}

static void	apply_precision(t_cont *info)
{
	int len;
	int iszero;

	iszero = 0;
	if (info->res[0] == '0' && !(info->res[1]))
		iszero = 1;
	apply_hash(info, 0, iszero);
	if (ft_atoi(info->precision) > (len = ft_strlen(info->res)))
	{
		while (ft_atoi(info->precision) > len)
		{
			info->res = ft_straddprefix("0", info->res);
			len++;
		}
	}
	if (info->flags[f_Dot] == 1 && iszero == 1 && info->flags[f_Hash] != 1)
	{
		free(info->res);
		info->res = ft_strdup("");
	}
	apply_width(info, iszero);
}

void		handle_octal(t_cont *info)
{
	if (info->length_mods[l_hh] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 8);
	else if (info->length_mods[l_h] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 8);
	else if (info->length_mods[l_l] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned long int), 8);
	else if (info->length_mods[l_ll] == 1)
		info->res = ft_utoabaselonglong(va_arg(info->args[0],
					unsigned long long int), 8);
	else if (info->length_mods[l_j] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], uintmax_t), 8);
	else if (info->length_mods[l_z] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], size_t), 8);
	else
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 8);
	apply_precision(info);
	if (info->specifier == 'O')
		ft_strtoupper(&info->res);
}
