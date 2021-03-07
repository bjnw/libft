/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 07:31:49 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/30 18:45:07 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "util_bytes.h"

#if defined(USEAVX2)

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p[2] = {s1, s2};
	__m256i				r[2];
	unsigned int		m;

	while (n >= SIZE)
	{
		r[0] = _mm256_lddqu_si256(p[0]);
		r[1] = _mm256_lddqu_si256(p[1]);
		if ((m = _mm256_movemask_epi8(r[0] == r[1])))
		{
			m = __builtin_ctz(m);
			return (p[0][m] - p[1][m]);
		}
		p[0] += SIZE;
		p[1] += SIZE;
		n -= SIZE;
	}
	while (n--)
	{
		if (*p[0] != *p[1])
			return (*p[0] - *p[1]);
		p[0]++;
		p[1]++;
	}
	return (0);
}

#else

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p[2] = {s1, s2};
	const uintptr_t		*w[2] = {s1, s2};

	if (n >= SIZE && ((uintptr_t)s1 & ~MASK) && ((uintptr_t)s2 & ~MASK))
	{
		while (n >= SIZE && *w[0]++ == *w[1]++)
			n -= SIZE;
		p[0] = (const unsigned char *)w[0];
		p[1] = (const unsigned char *)w[1];
	}
	while (n--)
	{
		if (*p[0] != *p[1])
			return (*p[0] - *p[1]);
		p[0]++;
		p[1]++;
	}
	return (0);
}

#endif

#if 0

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p[0] = {s1, s2};

	while (n--)
	{
		if (*p[0] != *p[1])
			return (*p[0] - *p[1]);
		p[0]++;
		p[1]++;
	}
	return (0);
}

#endif
