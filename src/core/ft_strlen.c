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
# include "memword.h"
#endif

#if defined(USEAVX)

# include <immintrin.h>
# include <stdbool.h>
# include <stdint.h>

size_t	ft_strlen(const char *s)
{
	const char	*p = s;
	__m128i		r0;
	__m128i		r1;
	int			mask;

	while (((uintptr_t)s & (sizeof(__m128i) - 1)) != 0)
	{
		if (*s == '\0')
			return (s - p);
		s++;
	}
	r0 = _mm_setzero_si128();
	mask = 0;
	while (true)
	{
		r1 = _mm_load_si128((__m128i *)s);
		r1 = _mm_cmpeq_epi8(r1, r0);
		if ((mask = _mm_movemask_epi8(r1)))
			return (s - p + __builtin_ctz(mask));
		s += sizeof(__m128i);
	}
}

#elif defined(MEMWORD)

size_t	ft_strlen(const char *s)
{
	const char *p = s;

	while ((uintptr_t)p & WMASK)
		if (*p++ == '\0')
			return (--p - s);
	while (!mw_testnull(*(uintptr_t *)p))
		p += WSIZE;
	while (*p)
		p++;
	return (p - s);
}

#else

size_t	ft_strlen(const char *s)
{
	const char *p = s;

	while (*p)
		p++;
	return (p - s);
}

#endif
