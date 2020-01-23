/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:56:35 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/22 19:08:57 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(t_format *info, const char *format, ...)			
{
	int			pos;
	va_list		ap;

	va_start(ap, format);

	pos = 0;
	parse_format(info, format, &pos);
	if (info->specifier == spec_none)
		return ;
}
