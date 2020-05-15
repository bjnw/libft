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

#include "memword.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			bytes;

	p = s;
	if (n >= BYTES_MIN)
	{
		while (((size_t)p & WMASK) && n--)
			*p++ = (unsigned char)c;
		bytes = mw_pack(c);
		while (n >= WSIZE)
		{
			*(size_t *)p = bytes;
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
