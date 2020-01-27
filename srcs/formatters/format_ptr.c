/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:09:38 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/27 20:47:03 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	output_len(t_format *info, int intlen)
{
	// precision length
	if (intlen > info->precision)
		info->precision = intlen;
	if (info->flags & FLAG_POUND)
		info->precision += 2;

	// width length
	if (info->width < info->precision)
		info->width = info->precision;
}

void		format_ptr(t_format *info, t_output *out, va_list ap)
{
	t_u64	arg;
	int		intlen;
	int		start;
	char	*str;

	// unset flags
	info->flags &= ~(FLAG_PLUS | FLAG_SPACE);
	// set flags
	info->flags |= (FLAG_POUND);
	// set length
	info->length = len_long;
	// get argument
	arg = number_argument_unsigned(info->length, ap);
	str = base_conversion(arg, 16, info->specifier == spec_hexup);

	if (arg == 0)
		info->flags &= ~FLAG_POUND;
	// arg length
	intlen = ft_strlen(str);

	// output length
	output_len(info, intlen);
	out->len = info->width;
	out->string = ft_strnew(info->width);

	// start offset
	start = info->width - info->precision;
	if (info->flags & FLAG_MINUS)
		start = 0;

	// format output
	format_int_width(info, out);
	format_int_precision(info, out->string + start, arg < 0);
	ft_strncpy(out->string + (start + info->precision - intlen), str, intlen);
}
