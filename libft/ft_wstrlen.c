/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 15:01:53 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/19 15:01:57 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"

int		ft_wstrlen(wchar_t *wstr)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	while (wstr[i])
	{
		len += ft_wchar_len(wstr[i]);
		i++;
	}
	return (len);
}
