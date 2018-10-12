/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddsuffix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:48:45 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/14 17:48:52 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/ft_printf.h"

char	*ft_straddsuffix(char *suffix, char *str)
{
	char	*res;
	int		i;
	int		j;

	i = ft_strlen(suffix) + ft_strlen(str);
	if (!(res = ft_strnew(i)))
		error_print(1);
	j = -1;
	i = 0;
	while (str[++j])
		res[j] = str[j];
	while (suffix[i])
	{
		res[j] = suffix[i];
		i++;
	}
	free(str);
	return (res);
}
