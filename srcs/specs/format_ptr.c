/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:04:30 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/24 12:06:34 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_ptr(t_format *info, t_output *out, va_list ap)
{
	info->length = len_ptr;
	arg = number_argument_signed(info->length, ap);
}
