/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:44:09 by mikaelber         #+#    #+#             */
/*   Updated: 2019/12/18 14:56:42 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Convert alphanumeric number to decimal number
*/
char	to_alphnum(int n)
{
	if (n < 10)
		return (n + 48);
	else if (n < 36)
		return (n + 65 - 10);
	else
		return ('@');

}

/*
**  Convert char to alhpanumeric number
*/

static int	to_num(char c)
{
	if (c >= 65)
		return (10 + (c - 65));
	else 
		return (c - 48);
}

void		base_convert(char *num, int frombase, int tobase)
{
	int		dec;
	int		i;
	int		len;

	tobase = 0;

	len = ft_strlen(num);
	dec = 0;
	i = 0;
	while (i++ < len)
		dec += to_num(num[i - 1]) * ft_pow(frombase, len - i);


	printf("%d\n", dec);
}

/*
char		*base_convert(char *num, int frombase, int tobase)
{
	int		base;
	int		res;
	char	*printstr;

	printstr = ft_strnew(100);
	res = 0;
	base = 0;
	while (num > 0)
	{
		res += (num % 10) * ft_pow(frombase, base);
		num /= 10;
		++base;
	}
	
	base = 0;
	while (res > 0)
	{
		int tmp = (res % tobase);
		printf("tmp %d,  ", tmp);
		printstr[base] = get_printchar(tmp);
		printf("str %s\n", printstr);
		res /= 10;
		++base;	
	}

	return (printstr);
}
*/
