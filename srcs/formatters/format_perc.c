/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_perc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:56:31 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/24 12:03:27 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_perc(t_format *info, t_output *out, va_list ap)
{
	(void)info;
	(void)ap;
	out->len = 1;
	out->string = ft_strnew(1);
	out->string[0] = '%';
}
