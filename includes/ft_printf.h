/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:10:25 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/03 20:45:57 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf_types.h"
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include <limits.h>
# include <stdio.h>

/*
** Core
*/
int			ft_printf(const char *format, ...);

/*
** Parsing
*/
void		parse_format(t_format *info, const char *format, int *pos, va_list ap);
void		parse_flags(t_format *info, const char *format, int *pos);
void		parse_width(t_format *info, const char *format, int *pos, va_list ap);
void		parse_precision(t_format *info, const char *format, int *pos, va_list ap);
void		parse_length(t_format *info, const char *format, int *pos);
void		parse_specifier(t_format *info, const char *format, int *pos);
void		parse_number(const char *format, int *pos, int *num);
void		format_bin(t_format *info, t_output *out, va_list ap);

/*
** Arguments
*/
t_64	number_argument_signed(t_len lflag, va_list ap);
t_u64	number_argument_unsigned(t_len lflag, va_list ap);
t_f128	float_argument_signed(t_len lflag, va_list ap);

/*
** General Formatting
*/
void	(*format_router(t_format *info))(t_format*, t_output*, va_list);
void	format_width(t_format *info, t_output *out, char *argstr, char *prefix);

/*
** Specifier Formatting
*/
void	format_int(t_format *info, t_output *out, va_list ap);
void	format_uint(t_format *info, t_output *out, va_list ap);
void	format_hex(t_format *info, t_output *out, va_list ap);
void	format_ptr(t_format *info, t_output *out, va_list ap);
void	format_octal(t_format *info, t_output *out, va_list ap);
void	format_float(t_format *info, t_output *out, va_list ap);
void	format_char(t_format *info, t_output *out, va_list ap);
void	format_str(t_format *info, t_output *out, va_list ap);
void	format_perc(t_format *info, t_output *out, va_list ap);

/*
** UTILS
*/
void	ft_itos(long long num, char *dest);
t_u64	ft_iabs(t_64 num);
t_f128	ft_fabs(t_f128 num);
char	*ft_ftoa(t_f128 num, int precision);
char	*base_conversion(t_u64 num, int tobase, int upper, int precision);

#endif
