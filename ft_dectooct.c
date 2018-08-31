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

char	*ft_dectooct(unsigned long long int num)
{
	char	arr[32];
	char	*asw;
	int		counter;

	ft_bzero(arr, 32);
	asw = ft_strnew(32);
	counter = 0;
	if (num == 0)
		arr[counter++] = '0';
	while (num)
	{
		arr[counter++] = num % 8 + 48;
		num /= 8;
	}
	asw = ft_strcpy(asw, ft_strrev(arr));
	return (asw);
}
