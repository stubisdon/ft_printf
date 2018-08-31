/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 10:45:55 by dkotov            #+#    #+#             */
/*   Updated: 2018/06/24 10:45:56 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *str)
{
	char	*start;
	char	*end;
	char	temp;
	int		length;

	start = (char *)str;
	end = start;
	while (*(end + 1))
		end++;
	length = (end - start + 1) / 2;
	while (length--)
	{
		temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
	return ((char *)str);
}
