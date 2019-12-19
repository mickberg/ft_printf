/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:44:09 by mikaelber         #+#    #+#             */
/*   Updated: 2019/12/19 16:26:34 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Convert alphanumeric number to decimal number
*/
static char	to_alphnum(int n)
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

static int	num_len(unsigned long num, int base)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num > 0)
	{
		++len;
		num = num / base;
	}
	return (len);
}

void		base_convert(char *numstr, int frombase, int tobase)
{
	unsigned long	num;
	int				i;
	int				len;
	char			*conv_str;

	len = ft_strlen(numstr);
	num = 0;
	i = 0;
	while (i++ < len)
		num += to_num(numstr[i - 1]) * ft_pow(frombase, len - i);
	len = num_len(num, tobase);
	conv_str = ft_strnew(len);
	if (num == 0)
		conv_str[0] = '0';
	i = 0;
	while (num > 0)
	{
		char c = to_alphnum(num % tobase);
		conv_str[len - 1] = c;
		--len;
		num /= tobase;
	}

	printf("%s", conv_str);
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
