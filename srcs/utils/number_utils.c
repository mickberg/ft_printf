/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:08:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/03 22:42:32 by mikaelber        ###   ########.fr       */
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

static int	decimals_to_str(t_f128 num, char *dest, int precision)
{
	t_u64	dnum;
	char	*str;

	dnum = num * ft_pow(10, precision + 1);
	if ((int)(dnum % 10) >= 5)
		dnum += 10;
	dnum /= 10;
	str = base_conversion(dnum % (t_u64)ft_pow(10, precision), 10, 0, precision);
	if (!str)
		return (0);
	ft_strncpy(dest, str, precision);
	free(str);
	return (dnum / (t_u64)ft_pow(10, precision));
}

char	*ft_ftoa(t_f128 num, int precision, int print_p)
{
	int		strlen;
	char	*numstr;

	strlen = ft_intlen(num) + precision;
	if (precision || print_p)
		++strlen;
	if (!(numstr = ft_strnew(strlen)))
		return (NULL);
	num += decimals_to_str(num - (t_u64)num, numstr + (strlen - precision), precision);
	numstr[0] = '0';
	ft_itos((t_u64)num, numstr);
	if (precision || print_p)
		numstr[ft_intlen((t_u64)num)] = '.';
	return (numstr);
}
