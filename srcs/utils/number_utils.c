/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:08:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/03 06:23:49 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_u64		ft_iabs(t_64 num)
{
	if (num < 0)
		return ((t_u64)(num * -1));
	return (num);
}

long double		ft_fabs(long double num)
{
	if (num < 0)
		return ((long double)(num * -1));
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

static int	decimals_to_str(long double num, char *dest, int precision)
{
	int		ix;
	int		tmp;

//*
	printf("@%Lf\n", num);
	printf("Long\t\tfloat\t\tint\ti+.01\ttmp\n\n");
//*/

	ix = 0;
	while (ix < precision)
	{
		num *= 10;
		tmp = (int)num;
		if (tmp < 9)
			tmp = (int)(num + 0.01);
		printf(">%Lf\t%f\t%d\t%d\t%d\n", num, (float)num, (int)num, (int)(num + 0.01), tmp);
		dest[ix] = (char)(tmp + 48);
		num -= tmp;
		++ix;
	}
	return (0);
}

char	*ft_ftoa(long double num, int precision)
{
	int			intlen;
	long double	decimals;
	char		fstr[precision];
	char		*numstr;

	intlen = ft_intlen(num);
	decimals = num - ((long)num % (long)ft_pow(10, intlen));
	num += decimals_to_str(decimals, fstr, precision);
	if (precision == 0 && (int)(decimals * 10) % 10 > 4)
		num += 1;
	intlen = ft_intlen(num);
	numstr = ft_strnew(intlen + 1 + precision);
	ft_itos((long)num, numstr);
	if(num < 1 && num > -1)
		numstr[0] = '0';
	if (precision > 0)
		numstr[intlen] = '.';
	ft_strncpy(numstr + intlen + 1, fstr, precision);
	return (numstr);
}
