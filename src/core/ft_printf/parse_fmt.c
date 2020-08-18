/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:24:23 by diona             #+#    #+#             */
/*   Updated: 2020/03/11 14:41:39 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"

/*
** % [parameter] [flags] [width] [.precision] [length] type
*/

void		parse_fmt(const char **fmt, t_flag *flags, va_list ap)
{
	ft_bzero(flags, sizeof(t_flag));
	flags->width = UNDEF;
	flags->precision = UNDEF;
	while (ft_memchr(VALID_FLAGS, **fmt,
				sizeof(VALID_FLAGS) - 1))
	{
		get_flags(fmt, flags);
		get_width(fmt, flags, ap);
		get_precision(fmt, flags, ap);
		get_modifier(fmt, flags);
	}
	if (flags->left && flags->zero)
		flags->zero = OFF;
	if (flags->plus && flags->space)
		flags->space = OFF;
	if (flags->width < UNDEF)
	{
		flags->left = ON;
		flags->width *= -1;
	}
	if (flags->precision < UNDEF)
		flags->precision = UNDEF;
}
