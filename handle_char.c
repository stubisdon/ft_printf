/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 13:06:38 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/21 13:06:46 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	if (info->speci == 'c' && info->lens[Ll] != 1)
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

static void	print_specialcase(t_info *info)
{
	int	i;

	i = 0;
	while (info->res[i])
	{
		ft_putchar(info->res[i]);
		i++;
	}
	info->count += i;
	ft_putchar('\0');
	info->count++;
	info->speci = '\0';
}

void		prepare_char(t_info *info)
{
	char	res;
	int		flag;

	flag = 0;
	if (info->speci == 'c' && info->lens[Ll] != 1)
	{
		if (!(info->res = ft_strnew(1)))
			print_error();
		res = va_arg(info->args[0], int);
		if (res == 0)
			flag = 1;
		info->res[0] = res;
	}
	else
	{
		if (!(info->wres = ft_wstrnew(1)))
			print_error();
		info->wres[0] = va_arg(info->args[0], wchar_t);
	}
	if (flag == 1)
		info->width--;
	if (info->width > 0)
		apply_width(info);
	if (flag == 1)
		print_specialcase(info);
}
