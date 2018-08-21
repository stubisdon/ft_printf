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

void string_interpret(i_cont *info)
{
    if (info->specifier == 's' || info->specifier == 'S')
        handle_str(info);
    else if (info->specifier == 'p' || info->specifier == 'P')
        handle_pointer(info);
    else if (info->specifier == 'x' || info->specifier == 'X')
        handle_x(info);
    else if (info->specifier == 'd' || info->specifier == 'D' ||
            info->specifier == 'i' || info->specifier == 'I')
        handle_int(info);
    else if (info->specifier == 'u' || info->specifier == 'U')
        handle_u(info);
    else if (info->specifier == 'o' || info->specifier == 'O')
        handle_octal(info);
    else if (info->specifier == 'c' || info->specifier == 'C')
        handle_char(info);
    // else if (info->specifier == 'b' || info->specifier == 'B')
    //     prepare_binary(info);
    else if (info->specifier == '%')
        handle_percentage(info);
    // else if (!info->specifier)
    //     string_print(info);
}

void string_print(i_cont *info)
{
    if (ft_strcmp(info->res, "0") == 0 && ft_strcmp(info->precision, "") == 0\
            && info->flags[f_Dot] == 1)
        info->res = "";
    // if (ft_strcmp(info->res, "0") == 0 && ft_strcmp(info->precision, "") == 0\
    //         && info->flags[f_Hash] == 1)
    //     info->res = "0";
    if (info->str_input)
        ft_putstr(info->str_input);
    if (info->res)
        ft_putstr(info->res);
    if (info->wres)
        ft_wputstr(info->wres);
}

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
