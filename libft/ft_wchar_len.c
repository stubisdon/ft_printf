/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 15:02:29 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/19 15:02:32 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"

int		ft_wchar_len(wchar_t wc)
{
	int	len;

	len = 0;
	if (wc <= 0xFF)
		return (1);
	else if (wc < 0x0800)
		return (2);
	else if (wc < 0x010000)
		return (3);
	else if (wc < 0x110000)
		return (4);
	return (len);
}
