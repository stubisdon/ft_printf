/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:38:05 by dkotov            #+#    #+#             */
/*   Updated: 2018/10/11 18:54:36 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		negative_num(t_cont *info)
{
	char	*tmp;

	if (info->res[0] != '-')
		return (0);
	tmp = info->res;
	(info->res)++;
	if (!(info->res = ft_strdup(info->res)))
		error_print(1);
	free(tmp);
	return (1);
}

void	apply_precision(t_cont *info)
{
	int len;

	len = 0;
	if (ft_atoi(info->precision) > (len = ft_strlen(info->res)))
	{
		while (ft_atoi(info->precision) > len)
		{
			info->res = ft_straddprefix("0", info->res);
			len++;
		}
	}
}

void	apply_width(t_cont *info, int isneg)
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
				(info->flags[f_Plus] == 1 || info->flags[f_Space] == 1 ||
				isneg == 1) && ft_strcmp(info->precision, "") == 0)
			len += 1;
		while (info->flags[f_Zero] == 1 && len < ft_atoi(info->width) && \
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

void	apply_flags(t_cont *info, int isneg)
{
	if (isneg == 0)
	{
		if (info->flags[f_Space] == 1 && info->flags[f_Plus] != 1)
			info->res = ft_straddprefix(" ", info->res);
		else if (info->flags[f_Plus] == 1)
			info->res = ft_straddprefix("+", info->res);
	}
	else
		info->res = ft_straddprefix("-", info->res);
}

void	handle_int(t_cont *info)
{
	int		isneg;

	if (info->length_mods[l_l] == 1 || info->specifier == 'D' || \
	info->specifier == 'I')
		info->res = ft_itoalonglong((long long)va_arg(info->args[0],
					long int));
	else if (info->length_mods[l_ll] == 1)
		info->res = ft_itoalonglong(va_arg(info->args[0], long long));
	else if (info->length_mods[l_j] == 1)
		info->res = ft_itoalonglong((long long)va_arg(info->args[0],
					intmax_t));
	else if (info->length_mods[l_z] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], size_t), 10);
	else
		info->res = ft_itoalonglong((long long)va_arg(info->args[0], int));
	isneg = negative_num(info);
	apply_precision(info);
	if (info->flags[f_Zero] != 1 || info->flags[f_Dash] == 1 || \
		ft_strcmp(info->precision, "") != 0)
		apply_flags(info, isneg);
	apply_width(info, isneg);
	if (info->flags[f_Zero] == 1 && info->flags[f_Dash] != 1 && \
		ft_strcmp(info->precision, "") == 0)
		apply_flags(info, isneg);
}
