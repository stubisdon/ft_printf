/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstraddsuffix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 12:46:16 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/19 12:47:50 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wstraddsuffix(wchar_t *suffix, wchar_t *str)
{
	int		i;
	int		j;
	wchar_t	*res;

	j = 0;
	i = 0;
	while (suffix[i])
		i++;
	while (str[j++])
		i++;
	if (!(res = ft_wstrnew(i)))
		error_print(1);
	j = -1;
	while (str[++j])
		res[j] = str[j];
	i = 0;
	while (suffix[i])
	{
		res[j++] = suffix[i];
		i++;
	}
	free(str);
	return (res);
}
