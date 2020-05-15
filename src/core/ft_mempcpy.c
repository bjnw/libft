/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 08:26:20 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/30 17:30:03 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#if defined(MEMWORD)
#include <stdint.h>

#include "memword.h"

void	*ft_mempcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;
	uintptr_t			*wd;
	const uintptr_t		*ws;

	if (dst == src)
		return (dst);
	pd = dst;
	ps = src;
	if (n >= WSIZE && ((uintptr_t)dst & ~WMASK) && ((uintptr_t)src & ~WMASK))
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
	return (pd);
}
#else
void	*ft_mempcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	if (dst == src)
		return (dst);
	pd = dst;
	ps = src;
	while (n--)
		*pd++ = *ps++;
	return (pd);
}
#endif
