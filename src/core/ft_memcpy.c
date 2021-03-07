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

#if defined(USEWORD)

# include "util_bytes.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;
	uintptr_t			*wd;
	const uintptr_t		*ws;

	if (dst == src)
		return (dst);
	pd = dst;
	ps = src;
	if (n >= SIZE && ((uintptr_t)dst & ~MASK) && ((uintptr_t)src & ~MASK))
	{
		wd = dst;
		ws = src;
		while (n >= SIZE)
		{
			*wd++ = *ws++;
			n -= SIZE;
		}
		pd = (unsigned char *)wd;
		ps = (const unsigned char *)ws;
	}
	while (n--)
		*pd++ = *ps++;
	return (dst);
}

#else

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
