/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:09:38 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/03 03:45:43 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_octal(t_format *info, t_output *out, va_list ap)
{
	t_u64	arg;
	char	*argstr;
	char	prefix[2];

	// unset flags
	info->flags &= ~(FLAG_PLUS | FLAG_SPACE);
	info->flags &= ~(FLAG_ZERO * info->has_precision);
	if (info->has_precision && info->precision)
		info->flags &= ~FLAG_POUND;
	if (!info->has_precision && !(info->flags & FLAG_POUND))
		info->precision = 1;
	// get argument
	arg = number_argument_unsigned(info->length, ap);
	argstr = base_conversion(arg, 8, info->specifier == spec_hexup, info->precision);

	ft_memset(prefix, 0, 2);
	if (info->flags & FLAG_POUND)
		prefix[0] = '0';

	format_width(info, out, argstr, prefix);
}
