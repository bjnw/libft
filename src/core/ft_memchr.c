/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 07:13:41 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 14:07:43 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "util_bytes.h"

#if defined(USEAVX2)

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = s;
	__m256i				r0;
	__m256i				r1;
	unsigned int		mask;

	r0 = _mm256_set1_epi8(c);
	while (n >= SIZE)
	{
		r1 = _mm256_lddqu_si256((__m256i *)p);
		r1 = _mm256_cmpeq_epi8(r1, r0);
		mask = _mm256_movemask_epi8(r1);
		if (mask)
			return ((char *)p + __builtin_ctz(mask));
		p += SIZE;
		n -= SIZE;
	}
	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((char *)p);
		p++;
	}
	return (NULL);
}

#else

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = s;
	uintptr_t			w;

	if (n >= SIZE_MIN)
	{
		while ((uintptr_t)p & MASK)
		{
			if (*p++ == (unsigned char)c)
				return ((void *)--p);
			else if (n-- == 0)
				return (NULL);
		}
		w = (unsigned char)c * MASK01;
		while (n >= SIZE && !testchar(*(uintptr_t *)p, w))
		{
			p += SIZE;
			n -= SIZE;
		}
	}
	while (n--)
	{
		if (*p++ == (unsigned char)c)
			return ((void *)--p);
	}
	return (NULL);
}

#endif

#if 0

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = s;

	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}

#endif
