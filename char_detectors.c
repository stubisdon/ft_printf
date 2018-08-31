/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:06:53 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/03 16:06:57 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_for_flags(t_info *info)
{
	while (is_flag(info->str[0][0]))
	{
		if (info->str[0][0] == '-')
			info->flags[Fminus] = 1;
		else if (info->str[0][0] == '+')
			info->flags[Fplus] = 1;
		else if (info->str[0][0] == ' ')
			info->flags[Fspace] = 1;
		else if (info->str[0][0] == '#')
			info->flags[Fhash] = 1;
		else if (info->str[0][0] == '0')
			info->flags[Fzero] = 1;
		(info->str[0])++;
	}
}

void	check_for_width(t_info *info)
{
	while (is_width(info->str[0][0]))
	{
		if (info->str[0][0] >= '0' && info->str[0][0] <= '9')
		{
			info->width = ft_atoi(info->str[0]);
			while (info->str[0][0] >= '0' && info->str[0][0] <= '9')
				(info->str[0])++;
		}
		else if (info->str[0][0] == '*')
		{
			info->width = va_arg(info->args[0], int);
			(info->str[0])++;
		}
	}
}

void	check_for_preci(t_info *info)
{
	while (is_preci(info->str[0][0]))
	{
		(info->str[0])++;
		if (info->str[0][0] >= '0' && info->str[0][0] <= '9')
		{
			info->preci = ft_atoi(info->str[0]);
			while (info->str[0][0] >= '0' && info->str[0][0] <= '9')
				(info->str[0])++;
		}
		else if (info->str[0][0] == '*')
		{
			info->preci = va_arg(info->args[0], int);
			(info->str[0])++;
		}
		else if (info->str[0][0] != '-')
			info->preci = 0;
		else
		{
			(info->str[0])++;
			while (info->str[0][0] >= '0' && info->str[0][0] <= '9')
				(info->str[0])++;
		}
	}
}

void	check_for_lengths(t_info *info)
{
	while (is_length(info->str[0][0]))
	{
		if (info->str[0][0] == 'h' && info->str[0][1] == 'h')
		{
			info->lens[Lhh] = 1;
			(info->str[0])++;
		}
		else if (info->str[0][0] == 'h')
			info->lens[Lh] = 1;
		else if (info->str[0][0] == 'l' && info->str[0][1] == 'l')
		{
			info->lens[Lll] = 1;
			(info->str[0])++;
		}
		else if (info->str[0][0] == 'l')
			info->lens[Ll] = 1;
		else if (info->str[0][0] == 'j')
			info->lens[Lj] = 1;
		else if (info->str[0][0] == 'z')
			info->lens[Lz] = 1;
		(info->str[0])++;
		if (is_length(info->str[0][0]))
			reinit_lengths(info);
	}
}

void	check_for_speci(t_info *info)
{
	if (is_speci(info->str[0][0]))
	{
		info->speci = info->str[0][0];
		(info->str[0])++;
	}
}
