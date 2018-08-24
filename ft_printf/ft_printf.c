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
	}
	va_end(args);
	free(info);
	return (printed_characters);
}


// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	int 	number_of_printed_characters;
//
// 	number_of_printed_characters = 0;
// 	va_start(args, format);
// 	while(*format)
// 	{
// 		if (*format == '%' && *(format + 1) == '%')
// 		{
// 			ft_putchar('%');
// 			format++;
// 		}
// 		else if (*format == 'd' || *format == 'i')
// 			handle_int(va_arg(args, int));
// 		else if (*format == '\n')
// 			handle_char('\n');
// 		else if (*format == ' ')
// 			handle_char(' ');
// 		else if (*format == 's')
// 			handle_string(va_arg(args, char *));
// 		else if (*format == 'S')
// 			handle_string_wide(va_arg(args, wchar_t *));
// 		else if (*format == 'u')
// 			handle_u(va_arg(args, unsigned int));
// 		else if (*format == 'o')
// 			handle_octal(va_arg(args, unsigned int));
// 		else if (*format == 'x')
// 			handle_hex_lowercase(va_arg(args, unsigned int));
// 		else if (*format == 'X')
// 			handle_hex_uppercase(va_arg(args, unsigned int));
// 		else if (*format == 'p')
// 			handle_pointer(va_arg(args, unsigned long));
// 		format++;
// 		number_of_printed_characters++;
// 	}
// 	va_end(args);
// 	return (number_of_printed_characters);
// }
