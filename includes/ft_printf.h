/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:10:25 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/17 15:46:33 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "ft_printf_types.h"
# include "libft.h"

# include <stdio.h>

/*
** Core 
*/
void		ft_printf(t_format *info, const char *format, ...);

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
** Output
*/
int			output_format(t_format *info, va_list *ap);

#endif
