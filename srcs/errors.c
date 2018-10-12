/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 15:14:44 by dkotov            #+#    #+#             */
/*   Updated: 2018/10/11 18:45:13 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		undefined_behavior(t_cont *info)
{
	if (info->flags[f_Hash] == 1)
	{
		if (info->specifier != 'o' && info->specifier != 'x' && \
		info->specifier != 'X' && info->specifier != 'O')
			error_print(e_UndefinedBehavior);
	}
	if (info->flags[f_Zero] == 1 && ft_strcmp(info->precision, ".") == 0)
	{
		if (info->specifier != 'd' || info->specifier != 'i' || \
		info->specifier != 'o' || info->specifier != 'u' || \
		info->specifier != 'i' || info->specifier != 'x' || \
		info->specifier != 'X')
			info->flags[f_Zero] = -1;
	}
	if (info->flags[f_Dash] == 1 && info->flags[f_Zero] == 1)
		info->flags[f_Zero] = -1;
	if (info->flags[f_Space] == 1 && info->flags[f_Plus] == 1)
		info->flags[f_Space] = -1;
	return (-1);
}

void	error_print(int error_num)
{
	if (error_num >= e_ConflictingType && error_num <= e_UndefinedBehavior)
	{
		ft_putstr("error: ");
		if (error_num == e_UndefinedBehavior)
			ft_putstr("e_UndefinedBehavior\n");
	}
	exit(error_num);
}

void	error_handle(t_cont *info)
{
	if (undefined_behavior(info) == 1)
		error_print(e_UndefinedBehavior);
}
