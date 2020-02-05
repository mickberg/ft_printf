/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_router.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:47:34 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/05 20:10:05 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	(*format_router(t_format *info))(t_format*, t_output*, va_list ap)
{
	void	(*funcs[256])(t_format*, t_output*, va_list ap);

	funcs[0] = NULL;
	funcs[1] = format_int;
	funcs[2] = format_octal;
	funcs[3] = format_uint;
	funcs[4] = format_hex;
	funcs[5] = format_hex;
	funcs[6] = format_float;
	funcs[7] = format_char;
	funcs[8] = format_str;
	funcs[9] = format_ptr;
	funcs[10] = format_perc;
	funcs[11] = format_bin;
	return (funcs[info->specifier]);
}
