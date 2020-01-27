/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:05:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/27 21:53:35 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_str(t_format *info, t_output *out, va_list ap)
{
	char		*arg;
	int			strlen;
	int			start;
	char		*str;

	// unset flags
	info->flags &= ~(FLAG_POUND | FLAG_ZERO | FLAG_PLUS | FLAG_SPACE);
	// get argument
	arg = (char*)va_arg(ap, char*);

	strlen = ft_strlen(arg);
	if (info->has_precision)
		strlen = info->precision;
	else
		info->precision = strlen;

	str = ft_strndup(arg, ft_min(strlen, info->precision));

	// output length
	out->len = ft_max(info->width, strlen);
	out->string = ft_strnew(out->len);

	// start offset
	start = out->len - strlen;
	if (info->flags & FLAG_MINUS)
		start = 0;

	// format output
	format_int_width(info, out);
	ft_strncpy(out->string + start, str, strlen);
}
