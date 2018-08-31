/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstraddprefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 12:48:21 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/19 12:48:35 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wstraddprefix(wchar_t *prefix, wchar_t *str)
{
	int		i;
	int		j;
	wchar_t *res;

	j = 0;
	i = 0;
	while (prefix[i])
		i++;
	while (str[j++])
		i++;
	if (!(res = ft_wstrnew(i)))
		print_error();
	j = -1;
	while (prefix[++j])
		res[j] = prefix[j];
	i = 0;
	while (str[i])
	{
		res[j++] = str[i];
		i++;
	}
	free(str);
	return (res);
}
