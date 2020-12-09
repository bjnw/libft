/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 21:53:14 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/05 17:16:15 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#if defined(MEMWORD)

# include "memword.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	uintptr_t		word;

	p = s;
	if (n >= BYTES_MIN)
	{
		while (((uintptr_t)p & WMASK) && n--)
			*p++ = (unsigned char)c;
		word = (unsigned char)c * MASK01;
		while (n >= WSIZE)
		{
			*(uintptr_t *)p = word;
			p += WSIZE;
			n -= WSIZE;
		}
	}
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

#else

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *p;

	p = s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

#endif
