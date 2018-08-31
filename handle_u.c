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

static void	apply_width(t_info *info)
{
	int len;

	if (info->width > (len = ft_strlen(info->res)))
	{
		while (info->flags[Fminus] == 1 && len < info->width)
		{
			info->res = ft_straddsuffix(" ", info->res);
			len++;
		}
		while (info->flags[Fzero] == 1 && len < info->width &&
				info->preci < 0)
		{
			info->res = ft_straddprefix("0", info->res);
			len++;
		}
		while (len < info->width)
		{
			info->res = ft_straddprefix(" ", info->res);
			len++;
		}
	}
}

static void	apply_precision(t_info *info)
{
	int len;

	if (info->preci > (len = ft_strlen(info->res)))
	{
		while (info->preci > len)
		{
			info->res = ft_straddprefix("0", info->res);
			len++;
		}
	}
}

void		prepare_undecimal(t_info *info)
{
	if (info->lens[Lhh] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 10);
	else if (info->lens[Lh] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 10);
	else if (info->lens[Ll] == 1 || info->speci == 'U')
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned long int), 10);
	else if (info->lens[Lll] == 1)
		info->res = ft_utoabaselonglong(va_arg(info->args[0],
					unsigned long long int), 10);
	else if (info->lens[Lj] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], uintmax_t), 10);
	else if (info->lens[Lz] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], size_t), 10);
	else
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 10);
	apply_precision(info);
	apply_width(info);
}
