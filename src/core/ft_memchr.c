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

#if defined(MEMWORD)

#include "memword.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				bytes;

	p = s;
	if (n >= BYTES_MIN)
	{
		while ((size_t)p & WMASK)
			if (*p++ == (unsigned char)c)
				return ((void *)--p);
			else if (n-- == 0)
				return (NULL);
		bytes = mw_pack(c);
		while (n >= WSIZE && !mw_testchar(*(size_t *)p, bytes))
		{
			p += WSIZE;
			n -= WSIZE;
		}
	}
	while (n--)
		if (*p++ == (unsigned char)c)
			return ((void *)--p);
	return (NULL);
}
#else
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	while (n--)
		if (*p++ == (unsigned char)c)
			return ((void *)--p);
	return (NULL);
}
#endif
