/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 21:37:52 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/27 21:39:33 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hex_uppercase(unsigned int number)
{
	char	*str;

	str = ft_itoa_base(number, 16);
	ft_putstr(str);
}

void	handle_hex_lowercase(unsigned int number)
{
	char	*str;
	int		i;

	str = ft_itoa_base(number, 16);
	i = 0;
	while(str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	ft_putstr(str);
}
