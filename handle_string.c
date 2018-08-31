/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:47:13 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/26 13:47:45 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_precision(t_info *info)
{
	int len;
	int i;

	len = 0;
	i = 0;
	if (info->speci == 's' && info->lens[Ll] != 1)
	{
		if (info->preci < (int)ft_strlen(info->res))
			info->res[info->preci] = '\0';
	}
	else
	{
		if (info->preci < ft_wstrlen(info->wres))
		{
			while (len <= info->preci)
			{
				len += ft_wchar_len(info->wres[i]);
				i++;
			}
			info->wres[--i] = 0;
		}
	}
}

static void	apply_widthwchar(t_info *info)
{
	int len;

	if (info->width > (len = ft_wstrlen(info->wres)))
	{
		while (info->flags[Fminus] == 1 && info->width > len)
		{
			info->wres = ft_wstraddsuffix(L" ", info->wres);
			len++;
		}
		while (info->flags[Fzero] == 1 && info->width > len)
		{
			info->wres = ft_wstraddprefix(L"0", info->wres);
			len++;
		}
		while (info->width > len)
		{
			info->wres = ft_wstraddprefix(L" ", info->wres);
			len++;
		}
	}
}

static void	apply_width(t_info *info)
{
	int len;

	if (info->speci == 's' && info->lens[Ll] != 1)
	{
		if (info->width > (len = ft_strlen(info->res)))
		{
			while (info->flags[Fminus] == 1 && info->width > len)
			{
				info->res = ft_straddsuffix(" ", info->res);
				len++;
			}
			while (info->flags[Fzero] == 1 && info->width > len)
			{
				info->res = ft_straddprefix("0", info->res);
				len++;
			}
			while (info->width > len)
			{
				info->res = ft_straddprefix(" ", info->res);
				len++;
			}
		}
	}
	else
		apply_widthwchar(info);
}

void		prepare_str(t_info *info)
{
	wchar_t *warg;
	char	*sarg;

	if (info->speci == 's' && info->lens[Ll] != 1)
	{
		if ((sarg = va_arg(info->args[0], char*)))
			info->res = ft_strdup(sarg);
		else
			info->res = ft_strdup("(null)");
		if (!info->res)
			print_error();
	}
	else
	{
		if ((warg = va_arg(info->args[0], wchar_t*)))
			info->wres = ft_wstrdup(warg);
		else
			info->wres = ft_wstrdup(L"(null)");
		if (!info->wres)
			print_error();
	}
	if (info->preci >= 0)
		apply_precision(info);
	if (info->width > 0)
		apply_width(info);
}
