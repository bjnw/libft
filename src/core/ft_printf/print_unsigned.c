/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:30:40 by diona             #+#    #+#             */
/*   Updated: 2020/03/10 23:35:19 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static uintmax_t	get_unsigned(t_length modifier, va_list ap)
{
	if (modifier == hh)
		return ((unsigned char)va_arg(ap, unsigned));
	if (modifier == h)
		return ((unsigned short)va_arg(ap, unsigned));
	if (modifier == l)
		return (va_arg(ap, unsigned long));
	if (modifier == ll)
		return (va_arg(ap, unsigned long long));
	if (modifier == j)
		return (va_arg(ap, uintmax_t));
	if (modifier == z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned));
}

void	print_unsigned(char **buf, char fmt, t_flags *flags, va_list ap)
{
	uintmax_t	val;
	int			base;

	if (flags->precision != UNDEF)
		flags->zero = OFF;
	if (fmt == 'O' || fmt == 'U')
		flags->modifier = l;
	else if (fmt == 'X')
		flags->uppercase = ON;
	fmt |= 040;
	if (fmt == 'b')
		base = 2;
	else if (fmt == 'o')
		base = 8;
	else if (fmt == 'x')
		base = 16;
	else
		base = 10;
	val = get_unsigned(flags->modifier, ap);
	if (val)
		number(buf, val, base, flags);
	else
		zero(buf, base, flags);
}
