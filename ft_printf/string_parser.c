/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:06:20 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/03 16:06:27 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
//
// int	string_parse(const char *format, i_cont *body)
// {
//
// 	while(*format)
// 		{
// 			int i;
// 			i = 1;
// 			char c;
// 			body->str_before = "";
// 			while(ft_isascii(*format) == 1 && *format != '%')
// 			{
// 				body->str_before = ft_strcharjoin(body->str_before, *format);
// 				format++;
// 				i++;
// 			}
// 			if (*format == '%')
// 			{
// 				format++;
// 				if (is_flag(*format) == 1)
// 				{
// 					body->flag = *format;
// 					format++;
// 				}
// 				if (ft_isdigit(*format) == 1)
// 				{
// 					while(ft_isdigit(*format) == 1)
// 					{
// 						c = *format;
// 						body->value = ft_strcharjoin(body->value, c);
// 						format++;
// 						i++;
// 					}
// 				}
// 				if (is_length_mod(*format) == 1)
// 				{
// 					i = 1;
// 					while(is_length_mod(*format) == 1)
// 					{
// 						c = *format;
// 						body->length_mod = ft_strcharjoin(body->length_mod, c);
// 						format++;
// 						i++;
// 					}
// 				}
//
// 			}
// 			format++;
// 		}
// 	return (1);
// }
