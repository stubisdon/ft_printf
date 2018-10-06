/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:01:03 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/25 21:11:27 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	i_cont		*info;
	int 		printed_characters;
	int			position;

	printed_characters = 0;
	position = 0;
	info = (i_cont *)malloc(sizeof(i_cont));
	va_start(args, format);
	while (format[position] != '\0')
	{
		struct_init(info, &args, &position);
		parse_string(format, info, &printed_characters);
		error_handle(info);
		string_interpret(info);
		string_print(info);
		printed_characters += ft_strlen(info->res);
		if (info->wres != NULL)
			printed_characters += ft_wstrlen(info->wres);
		position = info->position;
		if (ft_strcmp(info->res, "") != 0)
			free(info->res);
		ft_strdel(&info->precision);
		ft_strdel(&info->width);
	}
	va_end(args);
	free(info);
	return (printed_characters);
}
