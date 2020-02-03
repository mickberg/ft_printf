/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:09:38 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/03 03:31:02 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_ptr(t_format *info, t_output *out, va_list ap)
{
	t_u64	arg;
	char	*argstr;

	info->flags &= ~(FLAG_PLUS | FLAG_SPACE);
	info->flags &= ~(FLAG_ZERO * info->has_precision);
	info->flags |= (FLAG_POUND);
	info->precision += !info->has_precision;
	arg = number_argument_unsigned(len_long, ap);
	argstr = base_conversion(arg, 16, 0, info->precision);
	format_width(info, out, argstr, "0x");
}
