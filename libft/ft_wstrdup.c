/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 15:05:46 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/19 15:06:02 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	num_wchars(wchar_t *wstr)
{
	int i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}

wchar_t		*ft_wstrdup(wchar_t *wstr)
{
	wchar_t	*res;
	int		i;

	i = 0;
	if (!(res = (wchar_t *)malloc(sizeof(wchar_t) * (num_wchars(wstr) + 1))))
		return (NULL);
	while (wstr[i])
	{
		res[i] = wstr[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
