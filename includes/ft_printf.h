/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:10:25 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/24 19:38:51 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "ft_printf_types.h"
# include "libft.h"
# include <unistd.h>

# include <limits.h>
# include <stdio.h>

/*
** Core 
*/
void		ft_printf(const char *format, ...);

/*
** Parsing
*/
int			parse_format(t_format *info, const char *format, int *pos);
void		parse_flags(t_format *info, const char *format, int *pos);
void		parse_width(t_format *info, const char *format, int *pos);
void		parse_precision(t_format *info, const char *format, int *pos);
void		parse_length(t_format *info, const char *format, int *pos);
void		parse_specifier(t_format *info, const char *format, int *pos);
void		parse_number(const char *format, int *pos, int *num);

/*
** Arguments
*/
t_64	number_argument_signed(t_len lflag, va_list ap);
t_u64	number_argument_unsigned(t_len lflag, va_list ap);

/*
** Formatting
*/
void	(*format_router(t_format *info))(t_format*, t_output*, va_list);
void	format_int_width(t_format *info, t_output *out);
void	format_int_precision(t_format *info, char *out, t_64 arg);

/*
** Specifiers
*/
void	format_int(t_format *info, t_output *out, va_list ap);
void	format_hex(t_format *info, t_output *out, va_list ap);
void	format_perc(t_format *info, t_output *out, va_list ap);

/*
** UTILS
*/
void	ft_itos(long long num, char *dest);
t_u64	iabs(t_64 num);
char	*base_conversion(t_u64 num, int tobase, int upper);

#endif
