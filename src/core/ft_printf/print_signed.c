/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:30:40 by diona             #+#    #+#             */
/*   Updated: 2020/03/10 23:35:19 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "util.h"

static uintmax_t	get_signed(t_flags *flags, va_list ap)
{
	intmax_t	val;

	if (flags->modifier == hh)
		val = (char)va_arg(ap, int);
	else if (flags->modifier == h)
		val = (short)va_arg(ap, int);
	else if (flags->modifier == l)
		val = va_arg(ap, long);
	else if (flags->modifier == ll)
		val = va_arg(ap, long long);
	else if (flags->modifier == j)
		val = va_arg(ap, intmax_t);
	else if (flags->modifier == z)
		val = va_arg(ap, ssize_t);
	else
		val = va_arg(ap, int);
	flags->negative = val < 0;
	if (flags->negative)
		return (-val);
	return (val);
}

void	print_signed(char **buf, char fmt, t_flags *flags, va_list ap)
{
	uintmax_t	val;
	uint8_t		base;

	flags->sign = ON;
	if (flags->precision != UNDEF)
		flags->zero = OFF;
	if (fmt == 'D')
		flags->modifier = l;
	base = 10;
	val = get_signed(flags, ap);
	if (val)
		number(buf, val, base, flags);
	else
		zero(buf, base, flags);
}
