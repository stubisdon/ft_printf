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

void	handle_string(char *str)
{
	ft_putstr(str);
}

void	handle_string_wide(wchar_t *str)
{
	ft_putstr_wide(str);
}
