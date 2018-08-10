/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 23:27:24 by dkotov            #+#    #+#             */
/*   Updated: 2018/06/23 23:27:26 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len && str[i] != '\0')
	{
		j = 0;
		while (i + j < len && str[i + j] == sub[j] && sub[j] != '\0')
			j++;
		if (sub[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
