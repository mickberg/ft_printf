/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:56:35 by mikaelber         #+#    #+#             */
/*   Updated: 2019/12/18 17:54:42 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
		base_convert(argv[1], 16, 8);
	else if (argc == 3)
		base_convert(argv[1], ft_atoi(argv[2]), 10);
	else if (argc == 4)
		base_convert(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	return (0);
}
