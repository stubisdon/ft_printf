/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:07:58 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/25 21:10:05 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <stdio.h>

int	main()
{
	long long number = 100;
	// int bumber = 2;
	// char *str = "привет!";
	// unsigned int positive = 12312344;

	// wchar_t *newstring = L"Another text 汉字 привет";

/*
** parsing tests
*/

	ft_printf("m:%020lld", number);
	printf("m:%020lld", number);

/*
** basic tests
*/
	// ft_printf("%d %d %s %% %u %o %x %X %p\n", number, bumber, str, positive, positive, positive, positive, str);
	// printf("%d %d %s %% %u %o %x %X %p\n", number, bumber, str, positive, positive, positive, positive, str);
/*
** advanced tests
*/
	// ft_printf("%S\n", newstring);
	// printf("%S\n", newstring);

/*
** flags
*/
	// printf ("Decimals: %5d becimals %ld\n", 1977, 650000L);
	// printf ("Preceding with b:%10d\n", 1977);
	// printf ("Preceding with z:%05d\n", 1977);
	// printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	// // printf ("floats: %.3f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	// printf ("Width trick: %*d %*d\n", 10, 10, bumber, number);
	// printf ("%s \n", "A string");
    //
	// printf("--->Custom test:%0 5d<---\n", number);

/*
**	structure test
*/
	// ft_printf("Test flags: %ls\n", newstring);
	// printf("Test flags: %ls\n", newstring);

	return (0);
}
