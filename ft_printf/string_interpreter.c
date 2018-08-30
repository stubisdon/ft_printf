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
    else if (info->specifier == 'b' || info->specifier == 'B')
        handle_binary(info);
    else if (info->specifier == '%')
        handle_percentage(info);
}

void string_print(i_cont *info)
{
    if (ft_strcmp(info->res, "0") == 0 && ft_strcmp(info->precision, "") == 0\
            && info->flags[f_Dot] == 1)
        info->res = "";
    if (info->res)
        ft_putstr(info->res);
    if (info->wres)
        ft_wputstr(info->wres);
}

void struct_free(i_cont *info)
{
    if (ft_strcmp(info->res, "") != 0)
        free(info->res);
    else if (info->wres != NULL)
        free(info->wres);
}

// void map_specifier(i_cont *info)
// {
//     DispatchTable[] =
//     {
//         {'s',   &handle_str},
//         {'S',   &handle_str},
//         {'p',   &handle_pointer},
//         {'d',   &handle_int},
//         {'D',   &handle_int},
//         {'i',   &handle_int},
//         {'o',   &handle_octal},
//         {'O',   &handle_octal},
//         {'u',   &handle_u},
//         {'U',   &handle_u},
//         {'x',   &handle_x},
//         {'X',   &handle_x},
//         {'c',   &handle_char},
//         {'C',   &handle_char},
//     }
//     if (info->specifier == DispatchTable[i])
// }
