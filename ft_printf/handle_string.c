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

static void	apply_precision(i_cont *info)
{
	int len;
	int i;

	len = 0;
	i = 0;
	// if (info->flags[f_Dot] == 1)
	// 	info->precision = "0";
	if (info->specifier == 's' && info->length_mods[l_l] != 1)
	{
		if (ft_strlen(info->precision) > 0)
			if (ft_atoi(info->precision) < (int)ft_strlen(info->res))
				info->res[ft_atoi(info->precision)] = '\0';
	}
	else
	{
		if (ft_atoi(info->precision) < ft_wstrlen(info->wres))
		{
			while (len <= ft_atoi(info->precision))
			{
				len += ft_wchar_len(info->wres[i]);
				i++;
			}
		//	info->wres[--i] = 0;
		}
	}
}

static void	apply_widthwchar(i_cont *info)
{
	int len;

	if (ft_atoi(info->width) > (len = ft_wstrlen(info->wres)))
	{
		while (info->flags[f_Dash] == 1 && ft_atoi(info->width) > len)
		{
			info->wres = ft_wstraddsuffix(L" ", info->wres);
			len++;
		}
		while (info->flags[f_Zero] == 1 && ft_atoi(info->width) > len)
		{
			info->wres = ft_wstraddprefix(L"0", info->wres);
			len++;
		}
		while (ft_atoi(info->width) > len)
		{
			info->wres = ft_wstraddprefix(L" ", info->wres);
			len++;
		}
	}
}

static void	apply_width(i_cont *info)
{
	int len;

	if (info->specifier == 's' && info->length_mods[l_l] != 1)
	{
		if (ft_atoi(info->width) > (len = ft_strlen(info->res)))
		{
			while (info->flags[f_Dash] == 1 && ft_atoi(info->width) > len)
			{
				info->res = ft_straddsuffix(" ", info->res);
				len++;
			}
			while (info->flags[f_Zero] == 1 && ft_atoi(info->width) > len)
			{
				info->res = ft_straddprefix("0", info->res);
				len++;
			}
			while (ft_atoi(info->width) > len)
			{
				info->res = ft_straddprefix(" ", info->res);
				len++;
			}
		}
	}
	else
		apply_widthwchar(info);
}

void		handle_str(i_cont *info)
{
	wchar_t *warg;
	char	*sarg;

	if (info->specifier == 's' && info->length_mods[l_l] != 1)
	{
		if ((sarg = va_arg(info->args[0], char*)))
			info->res = ft_strdup(sarg);
		else
			info->res = ft_strdup("(null)");
		// if (ft_strcmp(info->res, "") == 0)
		// 	error_print(1);
	}
	else
	{
		if ((warg = va_arg(info->args[0], wchar_t*)))
			info->wres = ft_wstrdup(warg);
		else
			info->wres = ft_wstrdup(L"(null)");
		if (!info->wres)
			error_print(1);
	}
	if (ft_atoi(info->precision) >= 0)
		apply_precision(info);
	if (ft_atoi(info->width) > 0)
		apply_width(info);
}
