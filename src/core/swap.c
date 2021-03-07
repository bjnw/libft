/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:57:21 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/16 17:40:14 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

static void	swapbyte(void *a, void *b, size_t dummy)
{
	unsigned char	buf;

	(void)dummy;
	buf = *(unsigned char *)a;
	*(unsigned char *)a = *(unsigned char *)b;
	*(unsigned char *)b = buf;
}

static void	swapword(void *a, void *b, size_t dummy)
{
	unsigned short	buf;

	(void)dummy;
	buf = *(unsigned short *)a;
	*(unsigned short *)a = *(unsigned short *)b;
	*(unsigned short *)b = buf;
}

static void	swapdword(void *a, void *b, size_t dummy)
{
	unsigned int	buf;

	(void)dummy;
	buf = *(unsigned int *)a;
	*(unsigned int *)a = *(unsigned int *)b;
	*(unsigned int *)b = buf;
}

static void	swapqword(void *a, void *b, size_t dummy)
{
	unsigned long	buf;

	(void)dummy;
	buf = *(unsigned long *)a;
	*(unsigned long *)a = *(unsigned long *)b;
	*(unsigned long *)b = buf;
}

void	swap(void *s1, void *s2, size_t n)
{
	static	void (*fn[])(void *, void *, size_t) = {
		NULL,
		swapbyte, swapword, memswap, swapdword,
		memswap, memswap, memswap, swapqword,
	};

	if (n <= sizeof(long))
		return ((*fn[n & 0b1111])(s1, s2, n));
	memswap(s1, s2, n);
}
