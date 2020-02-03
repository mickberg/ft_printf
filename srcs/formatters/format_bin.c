/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:41:59 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/03 20:45:31 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_bin(t_format *info, t_output *out, va_list ap)
{
	t_u64	arg;
	char	*argstr;

	// unset flags
	info->flags &= ~(FLAG_PLUS | FLAG_SPACE | FLAG_POUND);
	info->flags &= ~(FLAG_ZERO * info->has_precision);
	// get argument
	arg = number_argument_unsigned(info->length, ap);
	if (!(argstr = base_conversion(arg, 2, info->specifier == spec_hexup, info->precision)))
		return ;
	format_width(info, out, argstr, "");
	free(argstr);
}
