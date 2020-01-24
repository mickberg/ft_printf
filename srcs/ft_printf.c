/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:56:35 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/24 13:48:03 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static void	format_argument(const char *format, t_format *info, t_output *out, int *pos, va_list ap)
{


	parse_format(info, format, pos);
	if (info->specifier == spec_none)
		return ;
	format_router(info)(info, out, ap);
}

void		ft_printf(const char *format, ...)
{
	int			pos;
	va_list		ap;
	t_format	info;
	t_output	out;

	va_start(ap, format);
	pos = 0;

	while (format[pos] != '\0')
	{
		if (format[pos] == '%')
		{
			ft_bzero(&out, sizeof(t_output));
			ft_bzero(&info, sizeof(t_format));
			++pos;
			format_argument(format, &info, &out, &pos, ap);
			write(1, out.string, out.len);
		}
		else
		{
			write(1, &(format[pos]), 1);
			++pos;
		}
	}
}
