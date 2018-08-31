/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:38:05 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/26 13:40:53 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	negative_num(t_info *info)
{
	char	*tmp;

	if (info->res[0] != '-')
		return (0);
	tmp = info->res;
	(info->res)++;
	if (!(info->res = ft_strdup(info->res)))
		print_error();
	free(tmp);
	return (1);
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

static void	apply_width(t_info *info, int isneg)
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
				(info->flags[Fplus] == 1 || info->flags[Fspace] == 1 ||
				isneg == 1) && info->preci < 0)
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
}

static void	apply_flags(t_info *info, int isneg)
{
	if (isneg == 0)
	{
		if (info->flags[Fspace] == 1 && info->flags[Fplus] != 1)
			info->res = ft_straddprefix(" ", info->res);
		else if (info->flags[Fplus] == 1)
			info->res = ft_straddprefix("+", info->res);
	}
	else
		info->res = ft_straddprefix("-", info->res);
}

void		prepare_signed(t_info *info)
{
	int		isneg;

	if (info->lens[Ll] == 1 || info->speci == 'D' || info->speci == 'I')
		info->res = ft_itoalonglong((long long)va_arg(info->args[0],
					long int));
	else if (info->lens[Lll] == 1)
		info->res = ft_itoalonglong(va_arg(info->args[0], long long));
	else if (info->lens[Lj] == 1)
		info->res = ft_itoalonglong((long long)va_arg(info->args[0],
					intmax_t));
	else if (info->lens[Lz] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], size_t), 10);
	else
		info->res = ft_itoalonglong((long long)va_arg(info->args[0], int));
	isneg = negative_num(info);
	apply_precision(info);
	if (info->flags[Fzero] != 1 || info->flags[Fminus] == 1 || info->preci > 0)
		apply_flags(info, isneg);
	apply_width(info, isneg);
	if (info->flags[Fzero] == 1 && info->flags[Fminus] != 1 && info->preci < 0)
		apply_flags(info, isneg);
}
