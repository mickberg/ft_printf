/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:05:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/03 03:01:20 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_uint(t_format *info, t_output *out, va_list ap)
{
	t_u64		arg;
	char		*argstr;

	info->flags &= ~(FLAG_POUND | FLAG_SPACE | FLAG_PLUS);
	info->flags &= ~(FLAG_ZERO * info->has_precision);
	info->precision += !info->has_precision;
	arg = number_argument_unsigned(info->length, ap);
	argstr = base_conversion(arg, 10, 0, info->precision);
	format_width(info, out, argstr, "");
}
