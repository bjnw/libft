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

#include <stddef.h>

#include "libft.h"

#if defined(MEMWORD)

#include "memword.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	size_t		word;

	p = s + ft_strlen(s);
	if (c == '\0')
		return ((char *)p);
	if (s + BYTES_MIN < p)
	{
		while ((size_t)p & WMASK)
			if (*--p == (unsigned char)c)
				return ((char *)p);
		word = (unsigned char)c * MASK01;
		while (!mw_testchar(*(size_t *)(p - WSIZE), word))
			if ((p -= WSIZE) <= s)
				return (NULL);
	}
	while (s < p)
		if (*--p == (unsigned char)c)
			return ((char *)p);
	return (NULL);
}

#else

char	*ft_strrchr(const char *s, int c)
{
	const char *p;

	p = s + ft_strlen(s);
	if (c == '\0')
		return ((char *)p);
	while (s < p)
		if (*--p == (unsigned char)c)
			return ((char *)p);
	return (NULL);
}

#endif
