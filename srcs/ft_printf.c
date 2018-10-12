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

#include "../includes/ft_printf.h"

void	struct_init(t_cont *info, va_list *args, int *position)
{
	int	i;

	info->position = *position;
	i = -1;
	while (++i <= FLAGS)
		info->flags[i] = -1;
	i = -1;
	while (++i <= L_MODS)
		info->length_mods[i] = -1;
	info->str_input = "";
	info->res = "";
	if (info->wres != NULL && *position != 0)
		free(info->wres);
	info->wres = NULL;
	info->width = ft_strdup("");
	info->precision = ft_strdup("");
	info->specifier = 0;
	info->args = args;
	info->next = 0;
}

void	info_funcs(t_cont *info)
{
	error_handle(info);
	string_interpret(info);
	string_print(info);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_cont		*info;
	int			printed_characters;
	int			position;

	printed_characters = 0;
	position = 0;
	info = (t_cont *)malloc(sizeof(t_cont));
	va_start(args, format);
	while (format[position] != '\0')
	{
		struct_init(info, &args, &position);
		parse_string(format, info, &printed_characters);
		info_funcs(info);
		printed_characters += ft_strlen(info->res);
		if (info->wres != NULL)
			printed_characters += ft_wstrlen(info->wres);
		position = info->position;
		if (ft_strcmp(info->res, "") != 0)
			free(info->res);
	}
	va_end(args);
	free(info);
	return (printed_characters);
}
