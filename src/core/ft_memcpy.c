/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 08:26:20 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/30 17:30:03 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#if defined(MEMWORD)

#include "memword.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;
	size_t				*wd;
	const size_t		*ws;

	if (dst == src)
		return (dst);
	pd = dst;
	ps = src;
	if (n >= WSIZE && ((size_t)dst & ~WMASK) && ((size_t)src & ~WMASK))
	{
		wd = dst;
		ws = src;
		while (n >= WSIZE)
		{
			*wd++ = *ws++;
			n -= WSIZE;
		}
		pd = (unsigned char *)wd;
		ps = (const unsigned char *)ws;
	}
	while (n--)
		*pd++ = *ps++;
	return (dst);
}

#else

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	if (dst == src)
		return (dst);
	pd = dst;
	ps = src;
	while (n--)
		*pd++ = *ps++;
	return (dst);
}

#endif
