/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:53:49 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/23 22:11:13 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "common/tuple.h"
#include "libft.h"

// NOTE approx. MAX_RUN_DEPTH is log(SIZE_MAX) - log(ISORT_THRESHOLD)
// FIXME too slooow if sorted

#define ISORT_THRESHOLD	16
#define MAX_RUN_DEPTH	42

static void	*hoare(void *lo, void *hi, size_t es,
				int (*cmp)(const void *, const void *))
{
	void	*piv;
	void	*i;
	void	*j;

	piv = lo;
	i = lo - es;
	j = hi + es;
	while (true)
	{
		i += es;
		while ((*cmp)(i, piv) < 0)
			i += es;
		j -= es;
		while ((*cmp)(j, piv) > 0)
			j -= es;
		if (i >= j)
			return (j);
		swap(i, j, es);
	}
}

static void	isort(void *lo, void *hi, size_t es,
				int (*cmp)(const void *, const void *))
{
	void	*i;
	void	*j;

	i = lo + es;
	while (i <= hi)
	{
		j = i;
		while (j > lo && (*cmp)(j - es, j) > 0)
		{
			swap(j - es, j, es);
			j -= es;
		}
		i += es;
	}
}

/*
** @a:		array pointer
** @n:		number of elements
** @es:		element size
** @cmp:	compare function
*/

void	ft_qsort(void *a, size_t n, size_t es,
			int (*cmp)(const void *, const void *))
{
	t_pair	base[MAX_RUN_DEPTH];
	t_pair	*ctx;
	void	*piv;
	void	*lo;
	void	*hi;

	ctx = base;
	*ctx++ = (t_pair){a, a + (n - 1) * es};
	while (ctx-- > base)
	{
		lo = ctx->a;
		hi = ctx->b;
		while ((hi - lo) / es > ISORT_THRESHOLD)
		{
			piv = hoare(lo, hi, es, cmp);
			*ctx++ = (t_pair){piv + es, hi};
			hi = piv;
		}
		isort(lo, hi, es, cmp);
	}
}
