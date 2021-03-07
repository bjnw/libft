/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoimax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:42:49 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/25 11:09:50 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "libft.h"

/*
** TODO err, cutoff, etc.
*/

static intmax_t	getval(const char *s, char **endptr, int base)
{
	intmax_t	val;
	int			c;

	val = 0;
	while ((c = ft_tolower(*s)))
	{
		if (ft_isdigit(c))
			c -= '0';
		else if (ft_islower(c))
			c -= 'a' - 10;
		else
			break ;
		if (c >= base)
			break ;
		s++;
		val = val * base + c;
	}
	*endptr = (char *)s;
	return (val);
}

intmax_t	ft_strtoimax(const char *s, char **endptr, int base)
{
	intmax_t	val;
	bool		neg;

	while (ft_isspace(*s))
		s++;
	neg = (*s == '-' || *s == '+') && *s++ == '-';
	if ((base == 0 || base == 16) && *s == '0'
		&& ft_tolower(s[1]) == 'x' && ft_isxdigit(s[2]))
	{
		s += 2;
		base = 16;
	}
	if (base == 0)
		base = (int []){10, 8}[*s == '0'];
	else if (base < 2 || base > 36)
		return (0);
	val = getval(s, (char **)&s, base);
	if (endptr)
		*endptr = (char *)s;
	if (neg)
		return (-val);
	return (val);
}
