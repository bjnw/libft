/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:24:23 by diona             #+#    #+#             */
/*   Updated: 2020/02/20 19:22:36 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"

#define ASCII_MAX	127

static void	*getspecfunc(int c)
{
	static const t_specfn	specfuncs[ASCII_MAX] = {
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

	return (specfuncs[c & ASCII_MAX]);
}

int	ft_sprintf(char *buf, const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, fmt);
	ret = ft_vsprintf(buf, fmt, ap);
	va_end(ap);
	return (ret);
}

int	ft_vsprintf(char *buf, const char *fmt, va_list ap)
{
	const char	*init = buf - 1;
	t_specfn	specfn;
	t_flags		flags;

	while (true)
	{
		while (*fmt != '%')
		{
			if ((*buf++ = *fmt++) == '\0')
				return (buf - init);
		}
		fmt++;
		parse_fmt(&fmt, &flags, ap);
		if ((specfn = getspecfunc(*fmt)))
		{
			(*specfn)(&buf, *fmt, &flags, ap);
			fmt++;
		}
	}
}
