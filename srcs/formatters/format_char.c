/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:05:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/27 21:29:22 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_char(t_format *info, t_output *out, va_list ap)
{
	t_64		arg;
	int			intlen;
	int			start;
	char		*str;

	// unset flags
	info->flags &= ~(FLAG_POUND | FLAG_ZERO | FLAG_PLUS | FLAG_SPACE);
	// unset precision
	info->precision = 0;
	info->has_precision = 0;
	// get argument
	arg = number_argument_unsigned(len_char, ap);
	str = ft_strnew(1);
	str[0] = arg;

	// arg length
	intlen = 1;

	// output length
	out->len = ft_max(info->width, 1);
	out->string = ft_strnew(out->len);

	// start offset
	start = info->width - 1;
	if (info->flags & FLAG_MINUS)
		start = 0;

	// format output
	format_int_width(info, out);
	ft_strncpy(out->string + start, str, intlen);
}
