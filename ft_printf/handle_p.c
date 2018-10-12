/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 13:15:53 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/29 13:18:06 by dkotov           ###   ########.fr       */
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
		if (info->flags[f_Zero] == 1 && info->flags[f_Dash] != 1)
			len += 2;
		while (info->flags[f_Dash] == 1 && len < ft_atoi(info->width))
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

void		handle_pointer(t_cont *info)
{
	void	*arg;

	arg = va_arg(info->args[0], void*);
	if (arg == NULL)
	{
		if (!(info->res = ft_strdup("0")))
			error_print(1);
	}
	else
	{
		if (ft_strcmp(info->res = ft_utoabaselonglong(
						(unsigned long long int)arg, 16), "") == 0)
			error_print(1);
	}
	apply_precision(info);
	if (info->flags[f_Zero] == 1 && info->flags[f_Dash] != 1)
		apply_width(info);
	info->res = ft_straddprefix("0x", info->res);
	apply_width(info);
	if (info->specifier == 'P')
		ft_strtoupper(&info->res);
}
