/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 09:25:42 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/17 11:43:48 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(t_format *info, const char *format, int *pos)
{
	char	*str;
	
	str = (char*)format + (*pos);
	if (ft_isdigit(*str))
		parse_number(format, pos, &(info->width));
}
