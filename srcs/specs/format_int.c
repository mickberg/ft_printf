/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:05:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/27 20:45:13 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	output_len(t_format *info, int intlen, int neg)
{
	// precision length
	if (intlen > info->precision)
		info->precision = intlen;
	if(info->flags & FLAG_PLUS || info->flags & FLAG_SPACE || neg)
		info->precision += 1;

	// width length
	if (info->width < info->precision)
		info->width = info->precision;
}

void		format_int(t_format *info, t_output *out, va_list ap)
{
	t_64		arg;
	int			intlen;
	int			start;
	char		*str;

	// unset flags
	info->flags &= ~(FLAG_POUND);
	// get argument
	arg = number_argument_signed(info->length, ap);
	str = base_conversion(ft_iabs(arg), 10, 0);

	// arg length
	intlen = ft_strlen(str);

	// output length
	output_len(info, intlen, arg < 0);
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
