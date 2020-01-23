/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 09:02:41 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/17 11:39:55 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(t_format *info, const char *format, int *pos)
{
	char *str;
	
	str = (char*)format + (*pos);
	while (*str != '\0')
	{
		if (*str == '-')
			info->flags |= FLAG_MINUS;
		else if (*str == '+')
			info->flags |= FLAG_PLUS;
		else if (*str == '#')
			info->flags |= FLAG_POUND;
		else if (*str == '0')
			info->flags |= FLAG_ZERO;
		else if (*str == ' ')
			info->flags |= FLAG_SPACE;
		else
			break;
		(*pos)++;
		str += *pos;
	}
}
