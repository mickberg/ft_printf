/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:30:19 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/27 20:08:55 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_itos(long long num, char *dest)
{
	int		lix;
	int		i;

	i = 0;
	lix = ft_intlen(num) - 1;
	while (num != 0)
	{
		dest[lix - i] = ft_abs(num % 10) + '0';
		++i;
		num /= 10;
	}
}
