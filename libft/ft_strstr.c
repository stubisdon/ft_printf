/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 23:04:37 by dkotov            #+#    #+#             */
/*   Updated: 2018/06/23 23:04:38 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *sub)
{
	int	i;
	int	j;

	i = 0;
	while (sub[i] == '\0' && str[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == sub[j] && sub[j] != '\0')
			j++;
		if (sub[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
