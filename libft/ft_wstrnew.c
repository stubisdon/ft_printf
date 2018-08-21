/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 15:04:53 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/19 15:05:07 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*wstr;
	size_t	i;

	i = 0;
	wstr = (wchar_t*)malloc(sizeof(wchar_t) * size + 1);
	if (!wstr)
		return (NULL);
	while (i <= size)
	{
		wstr[i] = 0;
		i++;
	}
	return (wstr);
}
