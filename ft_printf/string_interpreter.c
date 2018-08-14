/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:07:08 by dkotov            #+#    #+#             */
/*   Updated: 2018/08/03 16:07:11 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void read_conversions(i_cont *info)
// {
//     if (info->specifier == 's' || info->specifier == 'S')
//         handle_string(info);
//     else if (info->specifier == 'p' || info->specifier == 'P')
//         handle_pointer(info);
//     else if (info->specifier == 'x' || info->specifier == 'X')
//         handle_hex_lowercase(info);
//     else if (info->specifier == 'd' || info->specifier == 'D' ||
//             info->specifier == 'i' || info->specifier == 'I')
//         handle_int(info);
//     else if (info->specifier == 'u' || info->specifier == 'U')
//         handle_u(info);
//     else if (info->specifier == 'o' || info->specifier == 'O')
//         handle_octal(info);
//     // else if (info->specifier == 'c' || info->specifier == 'C')
//     //     prepare_char(info);
//     // else if (info->specifier == 'b' || info->specifier == 'B')
//     //     prepare_binary(info);
//     else if (info->specifier == '%')
//         prepare_percentage(info);
// }

// void string_print(i_cont *info)
// {
//     read_conversions();
//     string_width();
//     string_flag();
//     string_precision()
//     string_length();
// }

// void DispatchTable[] =
// {
//     {"s",   handle_string(va_arg(args, char *))},
//     //{"S",   handle_string_wide(va_arg(args, wchar_t *))},
//     {"p",   handle_pointer(va_arg(args, unsigned long))},
//     {"d",   handle_int(va_arg(args, int))},
//     //{"D",   handle_pointer(va_arg(args, unsigned long))},
//     {"i",   handle_int(va_arg(args, int))},
//     {"o",   handle_octal(va_arg(args, unsigned int))},
//     //{"O",   handle_pointer(va_arg(args, unsigned long))},
//     {"u",   handle_u(va_arg(args, unsigned int))},
//     //{"U",   handle_pointer(va_arg(args, unsigned long))},
//     {"x",   handle_hex_lowercase(va_arg(args, unsigned int))},
//     {"X",   handle_hex_uppercase(va_arg(args, unsigned int))},
//     //{"c",   handle_pointer(va_arg(args, unsigned long))},
//     //{"C",   handle_pointer(va_arg(args, unsigned long))},
// }
