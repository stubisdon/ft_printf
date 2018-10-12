/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 19:20:18 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/26 19:30:55 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_width(t_cont *info)
{
	int len;

	if (ft_atoi(info->width) > (len = ft_strlen(info->res)))
	{
		while (info->flags[f_Dash] == 1 && len < ft_atoi(info->width))
		{
			info->res = ft_straddsuffix(" ", info->res);
			len++;
		}
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
}

static void	apply_precision(t_cont *info)
{
	int len;

	if (ft_atoi(info->precision) > (len = ft_strlen(info->res)))
	{
		while (ft_atoi(info->precision) > len)
		{
			info->res = ft_straddprefix("0", info->res);
			len++;
		}
	}
}

void		handle_u(t_cont *info)
{
	if (info->length_mods[l_hh] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 10);
	else if (info->length_mods[l_h] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 10);
	else if (info->length_mods[l_l] == 1 || info->specifier == 'U')
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned long int), 10);
	else if (info->length_mods[l_ll] == 1)
		info->res = ft_utoabaselonglong(va_arg(info->args[0],
					unsigned long long int), 10);
	else if (info->length_mods[l_j] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], uintmax_t), 10);
	else if (info->length_mods[l_z] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], size_t), 10);
	else
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 10);
	apply_precision(info);
	apply_width(info);
}
