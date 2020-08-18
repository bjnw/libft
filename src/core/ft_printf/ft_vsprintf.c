/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:14:54 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 23:46:58 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"

#define ASCII_MAX	127

static const t_specfn	g_specfuncs[ASCII_MAX] = {
	['%'] = print_percent,
	['d'] = print_signed,
	['i'] = print_signed,
	['D'] = print_signed,
	['b'] = print_unsigned,
	['o'] = print_unsigned,
	['u'] = print_unsigned,
	['x'] = print_unsigned,
	['X'] = print_unsigned,
	['O'] = print_unsigned,
	['U'] = print_unsigned,
	['p'] = print_pointer,
	['f'] = print_float,
	['F'] = print_float,
	['e'] = print_float,
	['E'] = print_float,
	['g'] = print_float,
	['G'] = print_float,
	['s'] = print_string,
	['c'] = print_char
};

int		ft_vsprintf(char *buf, const char *fmt, va_list ap)
{
	t_specfn	specfn;
	t_flag		flags;
	char		*ret;

	ret = buf;
	while (true)
	{
		while (*fmt != '%')
			if ((*buf++ = *fmt++) == '\0')
				return (--buf - ret);
		fmt++;
		parse_fmt(&fmt, &flags, ap);
		if ((specfn = g_specfuncs[(unsigned)*fmt & ASCII_MAX]))
		{
			(*specfn)(&buf, *fmt, &flags, ap);
			fmt++;
		}
	}
}
