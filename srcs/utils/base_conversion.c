/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:22:26 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/05 20:12:28 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	len = 0;
	while (num)
	{
		num /= tobase;
		++len;
	}
	return (len);
}

char		*base_conversion(t_u64 num, int tobase, int upper, int precision)
{
	int		baselen;
	char	*res;

	baselen = ft_max(base_len(num, tobase), precision);
	if(!(res = ft_strnew(baselen)))
		return (NULL);
	while (baselen--)
	{
		char c = to_alphnum(num % tobase, upper);
		num /= tobase;
		res[baselen] = c;
	}
	return (res);
}
