/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:16:39 by dkotov            #+#    #+#             */
/*   Updated: 2018/05/24 14:16:40 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int i;
	int j;
	int *array;

	array = (int*)(malloc(sizeof(int) * (max - min)));
	i = min;
	j = 0;
	while (i < max)
	{
		array[j] = i;
		i++;
		j++;
	}
	return (array);
}
