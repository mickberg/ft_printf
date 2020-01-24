/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 09:43:34 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/24 19:25:40 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_int_precision(t_format *info, char *out, t_64 arg)
{
	ft_memset(out, '0', info->precision);

	// add prefix
	if (info->flags & FLAG_POUND)
	{
		if (info->specifier == spec_hex)
			ft_strncpy(out, "0x", 2);
		else if (info->specifier == spec_hexup)
			ft_strncpy(out, "0X", 2);
	}
	else if (info->flags & FLAG_PLUS && arg >= 0)
		*out = '+';
	else if (arg < 0)
		*out = '-';
	else if (info->flags & FLAG_SPACE)
		*out = ' ';
}
