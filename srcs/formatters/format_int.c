/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:05:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/03 20:05:38 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_int(t_format *info, t_output *out, va_list ap)
{
	t_64		arg;
	char		*argstr;
	char		prefix[2];

	// UNSET / SET FLAGS
	info->flags &= ~(FLAG_POUND);
	info->flags &= ~(FLAG_ZERO * info->has_precision);
	info->precision += !info->has_precision;

	// FETCH ARGUMENT
	arg = number_argument_signed(info->length, ap);
	if (!(argstr = base_conversion(ft_iabs(arg), 10, 0, info->precision)))
		return ;
	// define prefix
	ft_memset(prefix, 0, 2);
	if (info->flags & FLAG_SPACE)
		prefix[0] = ' ';
	if (arg < 0)
		prefix[0] = '-';
	else if (info->flags & FLAG_PLUS)
		prefix[0] = '+';
	// format width
	format_width(info, out, argstr, prefix);
	free(argstr);
}
