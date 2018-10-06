/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 01:44:40 by dkotov            #+#    #+#             */
/*   Updated: 2018/06/24 01:44:41 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcharjoin(char const *s1, char const s2)
{
	char	*str;
	char	*str1;
	char	str2;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char *)s1;
	str2 = (char)s2;
	str = ft_memalloc(ft_strlen(str1) + 2);
	if (!str)
		return (NULL);
	str = ft_strcpy(str, str1);
	str = ft_strcharcat(str, str2);
	ft_strdel(&str1);
	return (str);
}
