/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddprefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:08:43 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/14 17:08:58 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_straddprefix(char *prefix, char *str)
{
	int		i;
	int		j;
	char	*res;

	j = -1;
	i = ft_strlen(prefix) + ft_strlen(str);
	if (!(res = ft_strnew(i)))
		error_print(1);
	while (prefix[++j])
		res[j] = prefix[j];
	i = 0;
	while (str[i])
	{
		res[j] = str[i];
		i++;
		j++;
	}
//	free(str);
	return (res);
}
