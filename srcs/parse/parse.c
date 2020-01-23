/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:25:58 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/22 17:55:45 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdio.h>

int		parse_format(t_format *info, const char *format, int *pos)
{
	parse_flags(info, format, pos);
	parse_width(info, format, pos);
	parse_precision(info, format, pos);
	parse_length(info, format, pos);
	parse_specifier(info, format, pos);

	if (info->specifier == spec_none)
		return (0);
	return (0);
}
