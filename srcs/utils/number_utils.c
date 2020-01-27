/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:08:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/27 23:13:10 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_u64		ft_iabs(t_64 num)
{
	if (num < 0)
		return ((t_u64)(num * -1));
	return (num);
}

t_f128		ft_fabs(t_f128 num)
{
	if (num < 0)
		return ((t_f128)(num * -1));
	return (num);
}

void		ft_itos(long long num, char *dest)
{
	int		lix;
	int		i;

	i = 0;
	lix = ft_intlen(num) - 1;
	while (num != 0)
	{
		dest[lix - i] = ft_abs(num % 10) + '0';
		++i;
		num /= 10;
	}
}

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
