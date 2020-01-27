/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 09:59:50 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/24 18:48:32 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_int_width(t_format *info, t_output *out)
{
	char	padc;

	padc = ' ';
	if (info->flags & FLAG_ZERO && !(info->flags & FLAG_MINUS))
		padc = '0';
	ft_memset(out->string, padc, out->len);
}
