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

static void	apply_hash(t_info *info, int flag, int iszero)
{
	if (info->flags[Fhash] == 1 && iszero != 1)
	{
		if (((info->flags[Fzero] != 1 || info->flags[Fminus] == 1) &&
				flag == 0) || (info->flags[Fzero] == 1 && info->preci > 0
					&& flag == 0))
			info->res = ft_straddprefix("0", info->res);
	}
}

static void	apply_width(t_info *info, int iszero)
{
	int len;

	if (info->width > (len = ft_strlen(info->res)))
	{
		while (info->flags[Fminus] == 1 && len < info->width)
		{
			info->res = ft_straddsuffix(" ", info->res);
			len++;
		}
		if (info->flags[Fzero] == 1 && info->flags[Fminus] != 1 &&
				info->flags[Fhash] == 1 && info->preci < 0)
			len += 1;
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
	apply_hash(info, 1, iszero);
}

static void	apply_precision(t_info *info)
{
	int len;
	int iszero;

	iszero = 0;
	if (info->res[0] == '0' && !(info->res[1]))
		iszero = 1;
	apply_hash(info, 0, iszero);
	if (info->preci > (len = ft_strlen(info->res)))
	{
		while (info->preci > len)
		{
			info->res = ft_straddprefix("0", info->res);
			len++;
		}
	}
	if (info->preci == 0 && iszero == 1)
	{
		free(info->res);
		info->res = ft_strdup("");
	}
	apply_width(info, iszero);
}

void		prepare_octal(t_info *info)
{
	if (info->lens[Lhh] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 8);
	else if (info->lens[Lh] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 8);
	else if (info->lens[Ll] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned long int), 8);
	else if (info->lens[Lll] == 1)
		info->res = ft_utoabaselonglong(va_arg(info->args[0],
					unsigned long long int), 8);
	else if (info->lens[Lj] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], uintmax_t), 8);
	else if (info->lens[Lz] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], size_t), 8);
	else
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 8);
	apply_precision(info);
	if (info->speci == 'O')
		ft_strtoupper(&info->res);
}
