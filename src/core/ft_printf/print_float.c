/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:21:48 by diona             #+#    #+#             */
/*   Updated: 2020/03/19 20:59:30 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "util.h"

size_t			get_blen(t_bigint *bi)
{
	size_t	blen;

	if (bi == NULL)
		return (0);
	blen = bi->size - 1;
	return (bi->negative + blen * BI_COMP_LEN + ft_intlen(bi->comps[blen]));
}

static t_dbl	get_float(t_flag *flags, va_list ap)
{
	t_dbl	dbl;

	flags->sign = ON;
	if (flags->modifier == L)
		dbl.value = va_arg(ap, long double);
	else
		dbl.value = va_arg(ap, double);
	flags->negative = dbl.bits.negative;
	return (dbl);
}

/*
** you float like a feather
** in a beautiful world
** i wish i was special
** you're so fuckin' special
*/

static bool		float_so_especial(char **buf, t_dbl *dbl, t_flag *flags)
{
	char		*s;
	long double	d;

	s = NULL;
	d = dbl->value;
	if (d != d)
	{
		flags->plus = OFF;
		flags->negative = OFF;
		flags->space = OFF;
		s = flags->uppercase ? "NAN" : "nan";
	}
	else if (d == 1.0 / 0.0)
		s = flags->uppercase ? "INF" : "inf";
	else if (d == -1.0 / 0.0)
	{
		s = flags->uppercase ? "INF" : "inf";
		flags->sign = ON;
		flags->negative = ON;
	}
	if (s)
		buf_special(buf, s, flags);
	return (s != NULL);
}

/*
** i want you to notice
** when i'm not around
*/

static void		round_float(char *first, char **last)
{
	const char	*digits = "1234567890";
	char		*cur;
	char		*dot;

	cur = *last;
	if (*cur < '5')
		return ;
	while (!ft_isdigit(*first))
		first++;
	dot = NULL;
	while (cur-- > first)
		if (*cur == '.')
			dot = cur;
		else if ((*cur = digits[*cur & ~060]) != '0')
			return ;
	*first = '1';
	if (dot)
	{
		*dot++ = '0';
		*dot = '.';
	}
	if (*last != dot)
		**last = '0';
	(*last)++;
}

void			print_float(char **buf, char fmt, t_flag *flags, va_list ap)
{
	t_dbl	dbl;
	t_guts	guts;
	char	*s;
	char	*p;

	(void)fmt;
	if (flags->precision == UNDEF)
		flags->precision = 6;
	dbl = get_float(flags, ap);
	if (float_so_especial(buf, &dbl, flags))
		return ;
	ft_memset(&guts, 0, sizeof(t_guts));
	calc_guts(&dbl, &guts);
	s = xmalloc(get_blen(guts.intpart) +
			ft_imax(guts.fracsize, flags->precision) + 1 + 1);
	p = s;
	buf_guts(&p, &guts, flags);
	if (guts.fracpart)
		round_float(s, &p);
	flags->precision = UNDEF;
	buf_prefix(buf, flags, p - s);
	buf_copy(buf, s, p - s, flags);
	free(guts.intpart);
	free(guts.fracpart);
	free(s);
}
