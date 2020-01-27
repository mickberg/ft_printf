/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 09:25:42 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/27 23:05:29 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_precision(t_format *info, const char *format, int *pos)
{
	char	*str;

	str = (char*)format + (*pos);
	if (*str == '.')
	{
		++(*pos);
		info->has_precision = 1;
		parse_number(format, pos, &(info->precision));
	}
}
