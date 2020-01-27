/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:25:58 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/27 23:02:18 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_format(t_format *info, const char *format, int *pos)
{
	parse_flags(info, format, pos);
	parse_width(info, format, pos);
	parse_precision(info, format, pos);
	parse_length(info, format, pos);
	parse_specifier(info, format, pos);
}
