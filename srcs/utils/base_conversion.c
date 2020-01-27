/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:22:26 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/27 20:36:00 by mikaelber        ###   ########.fr       */
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

static char	to_alphnum(unsigned int num, int upper)
{
	if (num < 10)
		return (num + '0');
	else if (upper)
		return ((num - 10) + 'A');
	else
		return ((num - 10) + 'a');
}

static int	base_len(t_u64 num, int tobase)
{
	int len;

	len = 1;
	while (num /= tobase)
		++len;
	return (len);
}

char	*base_conversion(t_u64 num, int tobase, int upper)
{
	int		declen;
	int		baselen;
	char	*res;

	declen = ft_intlen(num);
	baselen = base_len(num, tobase);
	res = ft_strnew(baselen);
	if (num == 0)
		res[0] = '0';
	while (num != 0)
	{
		char c = to_alphnum(num % tobase, upper);
		num /= tobase;
		res[--baselen] = c;
	}
	return (res);
}
