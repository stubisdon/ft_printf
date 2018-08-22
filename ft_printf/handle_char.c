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

	if (info->specifier == 'c' && info->length_mods[l_l] != 1)
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

static void	print_specialcase(i_cont *info)
{
	int	i;

	i = 0;
	while (info->res[i])
	{
		ft_putchar(info->res[i]);
		i++;
	}
	info->position += i;
	ft_putchar('\0');
	// info->position++;
	info->specifier = '\0';
}

void		handle_char(i_cont *info)
{
	char	res;
	int		flag;

	flag = 0;
	if (info->specifier == 'c' && info->length_mods[l_l] != 1)
	{
		if (!(info->res = ft_strnew(1)))
			error_print(1);
		res = va_arg(info->args[0], int);
		if (res == 0)
			flag = 1;
		info->res[0] = res;
	}
	else
	{
		if (!(info->wres = ft_wstrnew(1)))
			error_print(1);
		info->wres[0] = va_arg(info->args[0], wchar_t);
	}
	if (flag == 1)
		info->width--;
	if (info->width > 0)
		apply_width(info);
	if (flag == 1)
		print_specialcase(info);
}
