/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 19:22:31 by dkotov            #+#    #+#             */
/*   Updated: 2018/06/22 19:26:40 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*b;

	i = 0;
	b = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (i < n)
	{
		d[i] = b[i];
		if (b[i] == (unsigned char)c)
		{
			return (d + i + 1);
		}
		i++;
	}
	return (NULL);
}
