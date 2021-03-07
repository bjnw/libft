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

#if defined(USEWORD)

# include "util_bytes.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	uintptr_t		w;

	p = s;
	if (n >= SIZE_MIN)
	{
		while (((uintptr_t)p & MASK) && n--)
			*p++ = (unsigned char)c;
		w = (unsigned char)c * MASK01;
		while (n >= SIZE)
		{
			*(uintptr_t *)p = w;
			p += SIZE;
			n -= SIZE;
		}
	}
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

#else

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

#endif
