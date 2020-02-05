/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:56:35 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/05 18:33:48 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_argument(const char *format, t_output *out, int *pos, va_list ap)
{
	t_format	info;

	ft_bzero(&info, sizeof(t_format));
	parse_format(&info, format, pos, ap);
	if (info.specifier == spec_none)
		return ;
	if (info.flags & FLAG_MINUS)
		info.flags &= ~FLAG_ZERO;
	format_router(&info)(&info, out, ap);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		len;

	va_start(ap, format);
	len = ft_vprintf(format, ap);
	va_end(ap);
	return (len);
}

int			ft_vprintf(const char *format, va_list ap)
{
	int			pos;
	t_output	out;
	size_t		out_len;

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
			if (out.string != NULL)
				free(out.string);
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
