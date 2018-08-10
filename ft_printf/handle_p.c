/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 13:15:53 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/29 13:18:06 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_pointer(unsigned long address)
{
	char *str;
	int		i;
	char *appendix;

	str = ft_itoa_base(address, 16);
	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	appendix = ft_strdup("0x");
	ft_strcat(appendix, str);
	ft_putstr(appendix);
}
