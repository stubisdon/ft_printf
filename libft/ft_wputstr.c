/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 15:50:23 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/19 15:52:39 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wputstr(wchar_t *str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		ft_putwchar(str[i]);
		i++;
	}
}
