/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 09:25:42 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/03 16:15:27 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_precision(t_format *info, const char *format, int *pos, va_list ap)
{
	int		arg;

	if (*(format + *pos) == '.')
	{
		++(*pos);
		info->has_precision = 1;
		if (*(format + *pos)  == '*')
		{
			arg = (int)va_arg(ap, int);
			if (arg < 0)
				info->precision = 1;
			info->precision = ft_max(info->precision, arg);

			(*pos)++;
		}
		else
			parse_number(format, pos, &(info->precision));
	}
}
