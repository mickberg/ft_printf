/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 07:54:13 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/17 18:00:05 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPES_H
# define FT_PRINTF_TYPES_H

typedef struct s_format		t_format;
typedef struct s_output		t_output;
typedef enum e_length		t_len;
typedef enum e_spec			t_spec;

/*
** Flags, defined in bits because not all flags are exlusive
*/
# define FLAG_MINUS			0x01
# define FLAG_PLUS			0x02
# define FLAG_POUND			0x08
# define FLAG_ZERO			0x10
# define FLAG_SPACE			0x20

/*
** length
*/
enum						e_length
{
	len_none,
	len_char,
	len_short,
	len_long,
	len_longlong,
	len_longdouble
};

/*
** specifiers
*/ 
enum						e_spec
{
	spec_none,
	spec_int,
	spec_octal,
	spec_uint,
	spec_hex,
	spec_hexup,
	spec_float,
	spec_char,
	spec_str,
	spec_ptr,
	spec_perc
};

/*
** Format structure, holds format structure
*/
struct						s_format
{
	char		flags;
	int			width;
	int			precision;
	t_len		length;
	t_spec		specifier;
};

struct						s_output
{
	void		*arg;
	char		*string;
	size_t		size;
};

#endif