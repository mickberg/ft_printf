/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:44:50 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/23 19:55:40 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_64		number_argument_signed(t_len lflag, va_list ap)
{
	t_64	 num;

	if (lflag == len_char)
		num = (char)va_arg(ap, int);
	else if (lflag == len_short)
		num = (short)va_arg(ap, int);
	else if (lflag == len_long)
		num = (long)va_arg(ap, long);
	else if (lflag == len_longlong)
		num = (t_64)va_arg(ap, long long);
	else if (lflag == len_ptr)
		num = (t_64)va_arg(ap, void*);
	else
		num = (int)va_arg(ap, int);
	return (num);
}

t_u64		number_argument_unsigned(t_len lflag, va_list ap)
{
	t_u64 num;

	if (lflag == len_char)
		num = (unsigned char)va_arg(ap, unsigned int);
	else if (lflag == len_short)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (lflag == len_long)
		num = (unsigned long)va_arg(ap, unsigned long);
	else if (lflag == len_longlong)
		num = (t_u64)va_arg(ap, unsigned long long);
	else if (lflag == len_ptr)
		num = (t_u64)va_arg(ap, void*);
	else
		num = (unsigned int)va_arg(ap, unsigned int);
	return (num);

}
