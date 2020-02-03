/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:56:35 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/03 03:20:32 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_argument(const char *format, t_output *out, int *pos, va_list ap)
{
	t_format	info;

	ft_bzero(&info, sizeof(t_format));
	parse_format(&info, format, pos);
	if (info.specifier == spec_none)
		return ;
	if (info.flags & FLAG_MINUS)
		info.flags &= ~FLAG_ZERO;
	format_router(&info)(&info, out, ap);
}

int			ft_printf(const char *format, ...)
{
	int			pos;
	va_list		ap;
	t_output	out;
	size_t		out_len;

	va_start(ap, format);
	pos = 0;
	out_len = 0;
	while (format[pos] != '\0')
	{
		if (format[pos] == '%')
		{
			++pos;
			ft_bzero(&out, sizeof(t_output));
			format_argument(format, &out, &pos, ap);
			write(1, out.string, out.len);
			out_len += out.len;
		}
		else
		{
			write(1, &(format[pos++]), 1);
			++out_len;
		}
	}
	return (out_len);
}
