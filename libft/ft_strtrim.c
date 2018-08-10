/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 01:59:09 by dkotov            #+#    #+#             */
/*   Updated: 2018/06/24 01:59:10 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*trimmed;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s);
	while (s[start] == '\n' || s[start] == '\t' || s[start] == ' ')
		start++;
	while (s[end - 1] == '\n' || s[end - 1] == '\t' || s[end - 1] == ' ')
		end--;
	if (start >= end)
		start = 0;
	if (!(trimmed = (char*)malloc((end - start) * sizeof(char) + 1)))
		return (NULL);
	while (start < end)
	{
		trimmed[i++] = s[start];
		start++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
