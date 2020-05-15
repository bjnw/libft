/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 02:49:49 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 14:00:21 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#if defined(MEMWORD)

#include "memword.h"

size_t	ft_strlen(const char *s)
{
	const char *p;

	p = s;
	while ((size_t)p & WMASK)
		if (*p++ == '\0')
			return (--p - s);
	while (!mw_testnull(*(size_t *)p))
		p += WSIZE;
	while (*p)
		p++;
	return (p - s);
}
#else
size_t	ft_strlen(const char *s)
{
	const char *p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}
#endif
