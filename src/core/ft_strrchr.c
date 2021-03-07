/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 05:06:19 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:52:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util_bytes.h"

#if defined(USEAVX2)

char	*ft_strrchr(const char *s, int c)
{
	const char		*p;
	__m256i			r0;
	__m256i			r1;
	unsigned int	mask;

	p = s + ft_strlen(s);
	if (c == '\0')
		return ((char *)p);
	r0 = _mm256_set1_epi8(c);
	while (s + SIZE <= p)
	{
		p -= SIZE;
		r1 = _mm256_lddqu_si256((__m256i *)p);
		r1 = _mm256_cmpeq_epi8(r1, r0);
		mask = _mm256_movemask_epi8(r1);
		if (mask != 0)
			return ((char *)p + __builtin_ctz(mask));
	}
	while (s < p)
	{
		if (*--p == (unsigned char)c)
			return ((char *)p);
	}
	return (NULL);
}

#else

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	uintptr_t	w;

	p = s + ft_strlen(s);
	if (c == '\0')
		return ((char *)p);
	if (s + SIZE_MIN < p)
	{
		while ((uintptr_t)p & MASK)
			if (*--p == (unsigned char)c)
				return ((char *)p);
		w = (unsigned char)c * MASK01;
		while (!testchar(*(uintptr_t *)(p - SIZE), w))
		{
			p -= SIZE;
			if (p <= s)
				return (NULL);
		}
	}
	while (s < p)
		if (*--p == (unsigned char)c)
			return ((char *)p);
	return (NULL);
}

#endif

#if 0

char	*ft_strrchr(const char *s, int c)
{
	const char	*p = s + ft_strlen(s);

	if (c == '\0')
		return ((char *)p);
	while (s < p)
	{
		if (*--p == (unsigned char)c)
			return ((char *)p);
	}
	return (NULL);
}

#endif
