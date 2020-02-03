/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:25:58 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/03 15:41:56 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_format(t_format *info, const char *format, int *pos, va_list ap)
{
	parse_flags(info, format, pos);
	parse_width(info, format, pos, ap);
	parse_precision(info, format, pos, ap);
	parse_length(info, format, pos);
	parse_specifier(info, format, pos);
}
