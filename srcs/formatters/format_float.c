/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:05:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/03 20:06:46 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_float(t_format *info, t_output *out, va_list ap)
{
	t_f128	arg;
	char	*argstr;
	char	prefix[2];

	info->flags &= ~(FLAG_POUND);
	if (!info->has_precision)
		info->precision = 6;
	arg = float_argument_signed(info->length, ap);
	if (!(argstr = ft_ftoa(ft_fabs(arg), info->precision)))
		return ;
	ft_memset(prefix, 0, 2);
	if (info->flags & FLAG_SPACE)
		prefix[0] = ' ';
	if (arg < 0)
		prefix[0] = '-';
	else if (info->flags & FLAG_PLUS)
		prefix[0] = '+';
	format_width(info, out, argstr, prefix);
	free(argstr);
}
