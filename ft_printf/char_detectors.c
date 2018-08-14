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

int	is_flag(char c)
{
	// if (c == '#' || c == '+' || c == '-' || c == ' ' ||  c == '0'\
	// || c == '.' || c == '*')
	// 	return (1);
	// return (0);

	if (c == '-')
		return (f_Dash);
	if (c == '+')
		return (f_Plus);
	if (c == '#')
		return (f_Hash);
	if (c == ' ')
		return (f_Space);
	if (c == '0')
		return (f_Zero);
	return (-1);
}

int	is_length(const char *str)
{
	if (*str == 'h' && *(str + 1) == 'h')
		return (l_hh);
	if (*str == 'h' && *(str + 1) != 'h' && *(str - 1) != 'h')
		return (l_h);
	if (*str == 'l' && *(str + 1) == 'l')
		return (l_ll);
	if (*str == 'l' && *(str + 1) != 'l' && *(str - 1) != 'l')
		return (l_l);
	if (*str == 'j')
		return (l_j);
	if (*str == 'z')
		return (l_z);
	return (-1);
}

int is_specifier(char c)
{
	if (c == 'd' || c == 'i' || c == 's' || c == 'S' || c == 'u' || c == 'U' || c == 'p' || c == 'D' || c == 'o' || c == 'O' || c == 'x' || c == 'X')
		return (1);
	if (c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

int	is_precision(char c)
{
	if (c == '.')
		return (1);
	return (0);
}
