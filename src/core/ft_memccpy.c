/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 08:41:02 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 14:01:08 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#if defined(MEMWORD)

#include "memword.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;
	size_t				*wd;
	const size_t		*ws;
	size_t				word;

	pd = dst;
	ps = src;
	if (n >= BYTES_MIN && ((size_t)pd & ~WMASK) && ((size_t)ps & ~WMASK))
	{
		wd = dst;
		ws = src;
		word = (unsigned char)c * MASK01;
		while (n >= WSIZE && !mw_testchar(*ws, word))
		{
			*wd++ = *ws++;
			n -= WSIZE;
		}
		pd = (unsigned char *)wd;
		ps = (const unsigned char *)ws;
	}
	while (n--)
		if ((*pd++ = *ps++) == (unsigned char)c)
			return (pd);
	return (NULL);
}

#else

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	pd = dst;
	ps = src;
	while (n--)
		if ((*pd++ = *ps++) == (unsigned char)c)
			return (pd);
	return (NULL);
}

#endif
