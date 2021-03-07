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

#include "util_bytes.h"

#if defined(USEAVX2)

size_t	ft_strlen(const char *s)
{
	const void		*p = s;
	__m256i			r0;
	__m256i			r1;
	unsigned int	mask;

	r0 = _mm256_setzero_si256();
	while (true)
	{
		r1 = _mm256_lddqu_si256((__m256i *)p);
		r1 = _mm256_cmpeq_epi8(r0, r1);
		mask = _mm256_movemask_epi8(r1);
		if (mask != 0)
			return (p - s + __builtin_ctz(mask));
		p += SIZE;
	}
}

#else

size_t	ft_strlen(const char *s)
{
	const char	*p = s;

	while ((uintptr_t)p & MASK)
	{
		if (*p == '\0')
			return (p - s);
		p++;
	}
	while (!testnull(*(uintptr_t *)p))
		p += SIZE;
	while (*p)
		p++;
	return (p - s);
}

#endif

#if 0

size_t	ft_strlen(const char *s)
{
	const char	*p = s;

	while (*p)
		p++;
	return (p - s);
}

#endif
