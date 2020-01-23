/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 09:02:41 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/17 12:15:02 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_length(t_format *info, const char *format, int *pos)
{
	char *str;
	
	str = (char*)format + (*pos);
	if (!ft_strcmp(str, "ll"))
		info->length = len_longlong;
	else if (!ft_strcmp(str, "hh"))
		info->length = len_char;
	else if (*str == 'l')
		info->length = len_long;
	else if (*str == 'h')
		info->length = len_short;
	else if (*str == 'L')
		info->length = len_longdouble;
	else
		info->length = len_none;
	if (info->length == len_longlong || info->length == len_char)
		(*pos) += 2;
	else if (info->length != len_none)
		(*pos) += 1;
}
