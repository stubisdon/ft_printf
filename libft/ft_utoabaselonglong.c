/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoabaselonglong.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:09:16 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/14 17:09:30 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf/ft_printf.h"

static int	count_digits(unsigned long long int n,
		unsigned long long int base)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

static char	get_char(unsigned long long int n)
{
	char	vals[16];
	int		i;

	i = -1;
	while (++i < 10)
		vals[i] = (char)(i + '0');
	vals[10] = 'a';
	vals[11] = 'b';
	vals[12] = 'c';
	vals[13] = 'd';
	vals[14] = 'e';
	vals[15] = 'f';
	return (vals[n]);
}

char		*is_zero(unsigned long long int n)
{
	char	*res;

	if (n != 0)
		return (NULL);
	if (!(res = ft_strdup("0")))
		error_print(1);
	return (res);
}

char		*ft_utoabaselonglong(unsigned long long int n,
		unsigned long long int base)
{
	char	*res;
	int		i;

	if ((res = is_zero(n)))
		return (res);
	i = count_digits(n, base);
	if (!(res = ft_strnew(i)))
		error_print(1);
	i--;
	while (n != 0)
	{
		res[i] = get_char(n % base);
		i--;
		n /= base;
	}
	return (res);
}
