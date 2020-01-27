/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:20:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/27 20:48:54 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	decimals_to_str(long double num, char *dest, int ilen, int precision)
{
	int		ix;

	num -= ((long)num % (long)ft_pow(10, ilen));
	ix = 0;
	while (ix < precision)
	{
		num *= 10;
		dest[ix] = (int)num % 10 + '0';
		num -= (int)num % 10;
		++ix;
	}
	if ((int)(num * 10) % 10 > 4)
		dest[--ix] += 1;
	while (ix > 0 && dest[ix] > '9')
	{
		dest[ix] = '0';
		dest[ix - 1] += 1;
		--ix;
	}
	if (dest[ix] > '9')
	{
		dest[ix] = '0';
		return (1);
	}
	return (0);
}

char	*ft_ftoa(long double num, int precision)
{
	int		intlen;
	char	fstr[precision];
	char	*numstr;

	intlen = ft_intlen(num);
	num += decimals_to_str(num, fstr, intlen, precision);
	intlen = ft_intlen(num);
	numstr = ft_strnew(intlen + 1 + precision);
	ft_itos((long)num, numstr);
	if(num < 1 && num > -1)
		numstr[0] = '0';
	numstr[intlen] = '.';
	ft_strncpy(numstr + intlen + 1, fstr, precision);
	return (numstr);
}
