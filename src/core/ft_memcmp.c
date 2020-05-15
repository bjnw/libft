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

#if defined(MEMWORD)

#include "memword.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	const size_t		*w1;
	const size_t		*w2;

	if (s1 == s2)
		return (0);
	p1 = s1;
	p2 = s2;
	if (n >= WSIZE && ((size_t)s1 & ~WMASK) && ((size_t)s2 & ~WMASK))
	{
		w1 = s1;
		w2 = s2;
		while (n >= WSIZE && *w1++ == *w2++)
			n -= WSIZE;
		p1 = (const unsigned char *)w1;
		p2 = (const unsigned char *)w2;
	}
	while (n--)
		if (*p1++ != *p2++)
			return (*--p1 - *--p2);
	return (0);
}
#else
int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	if (s1 == s2)
		return (0);
	p1 = s1;
	p2 = s2;
	while (n--)
		if (*p1++ != *p2++)
			return (*--p1 - *--p2);
	return (0);
}
#endif
