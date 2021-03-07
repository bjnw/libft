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

#include "libft.h"
#include "util_bytes.h"

#if defined(USEAVX2)

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;
	const unsigned char	*ch;

	pd = dst;
	ps = src;
	ch = ft_memchr(src, c, n);
	if (ch != NULL)
		n -= ch - (const unsigned char *)src + 1;
	while (n--)
		*pd++ = *ps++;
	if (ch != NULL)
		return (pd);
	return (NULL);
}

#else

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;
	uintptr_t			*wd;
	const uintptr_t		*ws;
	uintptr_t			w;

	pd = dst;
	ps = src;
	if (n >= SIZE_MIN && ((uintptr_t)pd & ~MASK) && ((uintptr_t)ps & ~MASK))
	{
		wd = dst;
		ws = src;
		w = (unsigned char)c * MASK01;
		while (n >= SIZE && !testchar(*ws, w))
		{
			*wd++ = *ws++;
			n -= SIZE;
		}
		pd = (unsigned char *)wd;
		ps = (const unsigned char *)ws;
	}
	while (n--)
		if ((*pd++ = *ps++) == (char)c)
			return (pd);
	return (NULL);
}

#endif

#if 0

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	pd = dst;
	ps = src;
	while (n--)
	{
		if ((*pd++ = *ps++) == (char)c)
			return (pd);
	}
	return (NULL);
}

#endif
